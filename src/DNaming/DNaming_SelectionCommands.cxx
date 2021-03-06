// Created on: 1997-10-20
// Created by: Yves FRICAUD
// Copyright (c) 1997-1999 Matra Datavision
// Copyright (c) 1999-2012 OPEN CASCADE SAS
//
// The content of this file is subject to the Open CASCADE Technology Public
// License Version 6.5 (the "License"). You may not use the content of this file
// except in compliance with the License. Please obtain a copy of the License
// at http://www.opencascade.org and read it completely before using this file.
//
// The Initial Developer of the Original Code is Open CASCADE S.A.S., having its
// main offices at: 1, place des Freres Montgolfier, 78280 Guyancourt, France.
//
// The Original Code and all software distributed under the License is
// distributed on an "AS IS" basis, without warranty of any kind, and the
// Initial Developer hereby disclaims all such warranties, including without
// limitation, any warranties of merchantability, fitness for a particular
// purpose or non-infringement. Please see the License for the specific terms
// and conditions governing the rights and limitations under the License.



#include <DNaming.hxx>

#include <DDF.hxx>

#include <TNaming_NamedShape.hxx>
#include <TNaming_ListOfNamedShape.hxx>
#include <TNaming_ListIteratorOfListOfNamedShape.hxx>
#include <TNaming_Tool.hxx>
#include <TDF_Label.hxx>
#include <TDF_AttributeMap.hxx>
#include <TDF_MapIteratorOfAttributeMap.hxx>
#include <TDF_ChildIterator.hxx>
#include <TDF_Tool.hxx>
#include <TNaming_Name.hxx>
#include <TNaming.hxx>
#include <TNaming_Naming.hxx>
#include <TNaming_MapOfNamedShape.hxx>
#include <TNaming_MapIteratorOfMapOfNamedShape.hxx>
#include <TDF_ChildIterator.hxx>
#include <TNaming_Selector.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs.hxx>
#include <TCollection_AsciiString.hxx>
#include <TDF_LabelMap.hxx>

#include <DBRep.hxx>
#include <Draw_Appli.hxx>
#include <Draw.hxx>
#include <Draw_Interpretor.hxx>
#include <Draw_Drawable3D.hxx>
#include <DBRep.hxx>
#include <DBRep_DrawableShape.hxx>
#include <stdio.h>

//=======================================================================
//function : Display
//purpose  : 
//=======================================================================

static void Display (const Standard_CString Name, const TopoDS_Shape& S)
{  
  //char* name = Name;
  static Standard_Integer nbIsos  = 2;
  static Standard_Real size    = 100.;
  static Standard_Integer discret = 30;

  Handle(DBRep_DrawableShape) D = new DBRep_DrawableShape(S,
							  Draw_jaune,
							  Draw_vert,
							  Draw_bleu,
							  Draw_rouge,
							  size,
							  nbIsos,
							  discret);
  Draw::Set(Name,D);
}

//=======================================================================
//function : DumpNaming
//purpose  : 
//=======================================================================

//static void DumpNaming (const Handle(TNaming_Naming)& naming) 
static void DumpNaming (const Handle(TNaming_Naming)& naming, Draw_Interpretor& di) 
{
  TCollection_AsciiString Entry;
  const TNaming_Name& AName = naming->GetName();
  //TNaming::Print(AName.Type(),cout);
  Standard_SStream aStream1;
  TNaming::Print(AName.Type(),aStream1);
  di << aStream1;
  di << " ";
  //TopAbs::Print(AName.ShapeType(),cout);
  Standard_SStream aStream2;
  TopAbs::Print(AName.ShapeType(),aStream2);
  di << aStream2;
  const TNaming_ListOfNamedShape& NSS = AName.Arguments();
  for (TNaming_ListIteratorOfListOfNamedShape it(NSS); it.More(); it.Next()) {
    TDF_Tool::Entry(it.Value()->Label(),Entry); 
    di << " " << Entry.ToCString();
  }
  if(!AName.StopNamedShape().IsNull()) {
    TDF_Tool::Entry(AName.StopNamedShape()->Label(),Entry); 
    di << " Stop " << Entry.ToCString();
  }
}

//=======================================================================
//function : SelectShape ou SelectGeometry
//purpose  : "Select DF entry shape [context [orient]]", 
//=======================================================================

static Standard_Integer DNaming_Select (Draw_Interpretor& di, Standard_Integer n, const char** a)
{
  if (n > 3) {
    Standard_Boolean geometry = (strcmp(a[0],"SelectGeometry")); 
    Handle(TDF_Data) DF;
    if(!DDF::GetDF(a[1], DF))  return 1;
    TDF_Label L;
    DDF::AddLabel(DF,a[2],L);
    TNaming_Selector SL (L);
    if (n == 4) {
      TopoDS_Shape S = DBRep::Get(a[3], TopAbs_SHAPE);  
      SL.Select (S, geometry); 
    }
    if (n > 4) {  
      Standard_Boolean Orient(Standard_False);
      if(n == 6) Orient = (Standard_Boolean)atoi(a[5]);
      TopoDS_Shape S = DBRep::Get(a[3], TopAbs_SHAPE);
      TopoDS_Shape C = DBRep::Get(a[4], TopAbs_SHAPE);
      SL.Select (S, C, geometry, Orient);       
    }
    return 0;  
  }
  di << "DNaming_Select : Error" << "\n";
  return 1;
}


//=======================================================================
//function : SolveSelection
//purpose  : "SolveSelection DF entry", 
//=======================================================================

static Standard_Integer DNaming_SolveSelection (Draw_Interpretor& di, Standard_Integer n, const char** a)
{
  if (n == 3) {
    char name[100];
    Handle(TDF_Data) DF;
    if(!DDF::GetDF(a[1], DF))  return 1;
    TDF_Label L;
    DDF::AddLabel(DF,a[2],L);   
    //Handle(TNaming_Naming) naming;    
    //if (!L.FindAttribute(TNaming_Naming::GetID(),naming)) {  
    //  cout <<"DNaming_DumpSelection : not a selection" << endl;
    //  return 1;
    //}
    //naming->Solve();
    //Handle(TNaming_NamedShape) NS;
    //if  (!L.FindAttribute(TNaming_NamedShape::GetID(),NS)) {  
    //  cout <<"DNaming_DumpSelection : not done" << endl;
    //  return 1;
    //}
    TNaming_Selector SL (L);
    TDF_LabelMap dummy;
    SL.Solve(dummy);
    TopoDS_Shape Res = TNaming_Tool::CurrentShape(SL.NamedShape());
    //TopoDS_Shape Res = TNaming_Tool::CurrentShape(NS);
    sprintf (name,"%s_%s","new",a[2]);
    Display (name,Res);
    return 0;
  }
  di << "DNaming_SolveSelection : Error" << "\n";
  return 1;
}


//=======================================================================
//function : DumpSelection
//purpose  : DumpSelection DF entry (R)"
//=======================================================================
static Standard_Integer DNaming_DumpSelection (Draw_Interpretor& di, 
					      Standard_Integer n, const char** a)
{
  if (n == 3 || n == 4) { 
    Handle(TDF_Data) DF;
    if (!DDF::GetDF(a[1],DF)) return 1;  
    TDF_Label L;
    if (!DDF::FindLabel(DF,a[2],L)) return 1;
    Handle(TNaming_Naming) naming;
    if (!L.FindAttribute(TNaming_Naming::GetID(),naming)) {  
      di <<"DNaming_DumpSelection : not a selection" << "\n";
      return 1;
    }
    DumpNaming(naming, di);
    di << "\n";
    if (n == 4) { 
      Standard_Integer depth = L.Depth();  
      Standard_Integer curdepth = 0;
      TCollection_AsciiString Entry;
      TDF_ChildIterator it (naming->Label(),Standard_True);
      for (;it.More();it.Next()) {
	if (it.Value().FindAttribute(TNaming_Naming::GetID(),naming)) { 
	  curdepth = (naming->Label().Depth()- depth);
	  for (Standard_Integer i = 1; i <= curdepth; i++) di << " ";    
	  TDF_Tool::Entry (naming->Label(),Entry); 
	  di << Entry.ToCString() << " "; 
	  DumpNaming(naming, di);
	  di << "\n";
	}
      }
    }
    return 0;
  }
  di << "DNaming_DumpSelection : Error" << "\n";
  return 1;  
}


//=======================================================================
//function : ArgsSelection
//purpose  : ArgsSelection DF entry"
//=======================================================================
static Standard_Integer DNaming_ArgsSelection (Draw_Interpretor& di, 
					      Standard_Integer n, const char** a)
{
  if (n == 3) { 
    Handle(TDF_Data) DF;
    if (!DDF::GetDF(a[1],DF)) return 1;  
    TDF_Label L;
    if (!DDF::FindLabel(DF,a[2],L)) return 1;
    Handle(TNaming_Naming) naming;
    if (!L.FindAttribute(TNaming_Naming::GetID(),naming)) {  
      di <<"DNaming_DumpSelection : not a selection" << "\n";
      return 1;
    }  
    TCollection_AsciiString Entry;
    TNaming_Selector SL (L);
    di <<" Selection Arguments : ";
    TDF_AttributeMap args;
    SL.Arguments(args);
    for (TDF_MapIteratorOfAttributeMap it(args); it.More(); it.Next()) {
      TDF_Tool::Entry(it.Key()->Label(),Entry); 
      di << Entry.ToCString() << " ";
    }
    di << "\n";
    return 0;
  }
  di << "DNaming_ArgsSelection : Error" << "\n";
  return 1;  
}


//=======================================================================
//function : CollectAttachment
//purpose  : 
//=======================================================================

static void CollectAttachment (const TDF_Label& root,
			       const Handle(TNaming_Naming)& naming, 
			       TNaming_MapOfNamedShape& attachment)
{
  TNaming_ListIteratorOfListOfNamedShape itarg;
  const TNaming_ListOfNamedShape& args = naming->GetName().Arguments();
  for (itarg.Initialize(args);itarg.More();itarg.Next()) {
    if (!itarg.Value()->Label().IsDescendant(root)) attachment.Add(itarg.Value());
  }  
  Handle(TNaming_Naming) subnaming; 
  for (TDF_ChildIterator it(naming->Label(),Standard_True);it.More();it.Next()) {
    if (it.Value().FindAttribute(TNaming_Naming::GetID(),subnaming)) {   
      const TNaming_ListOfNamedShape& subargs = subnaming->GetName().Arguments();
      for (itarg.Initialize(subargs);itarg.More();itarg.Next()) {
	if (!itarg.Value()->Label().IsDescendant(root)) attachment.Add(itarg.Value());
      }
    }
  }
}  



//=======================================================================
//function : Attachment
//purpose  : Attachment DF entry"
//=======================================================================

static Standard_Integer DNaming_Attachment (Draw_Interpretor& di, 
					    Standard_Integer n, 
					    const char** a)
{
  if (n == 3) { 
    Handle(TDF_Data) DF;
    if (!DDF::GetDF(a[1],DF)) return 1;  
    TDF_Label L;
    if (!DDF::FindLabel(DF,a[2],L)) return 1;  
    Handle(TNaming_Naming) naming; 
    TNaming_MapOfNamedShape attachment;
    if (L.FindAttribute(TNaming_Naming::GetID(),naming)) {
      CollectAttachment (L,naming,attachment);
    }
    else {
      for (TDF_ChildIterator it (L,Standard_True); it.More();it.Next()) {
	if (it.Value().FindAttribute(TNaming_Naming::GetID(),naming)) {
	  CollectAttachment (L,naming,attachment);
	  it.NextBrother();
	}
      }
    }
    TCollection_AsciiString Entry;   
    TDF_Tool::Entry(L,Entry); 
    di << " Attachment of " << Entry.ToCString();
    di << "\n";
    for (TNaming_MapIteratorOfMapOfNamedShape ita (attachment); ita.More(); ita.Next()) {
      TDF_Tool::Entry (ita.Key()->Label(),Entry); 
      di << Entry.ToCString() << " ";
    }
    di << "\n";
    return 0;
  }
  di << "DNaming_Attachment : Error" << "\n";
  return 1;  
}

//=======================================================================
//function : SelectionCommands
//purpose  : 
//=======================================================================

void DNaming::SelectionCommands(Draw_Interpretor& theCommands) 
{
  
  static Standard_Boolean done = Standard_False;
  if (done) return;
  done = Standard_True;
  
  const char* g = "Naming data commands";

  theCommands.Add("SelectShape",
		  "SelectShape DF entry shape [context [Orient]]", 
		  __FILE__, DNaming_Select, g);
  
  theCommands.Add("SelectGeometry",
		  "SelectGeometry DF entry shape [context]", 
		  __FILE__, DNaming_Select, g);
  
  theCommands.Add("DumpSelection",         
		  "DumpSelected DF entry", 
		  __FILE__, DNaming_DumpSelection, g);    

  theCommands.Add("ArgsSelection",         
		  "ArgsSelection DF entry", 
		  __FILE__, DNaming_ArgsSelection, g);  

  theCommands.Add("SolveSelection",         
		  "DumpSelection DF entry", 
		  __FILE__, DNaming_SolveSelection, g);  

  theCommands.Add("Attachment",         
		  "Attachment DF entry", 
		  __FILE__, DNaming_Attachment, g);
}
