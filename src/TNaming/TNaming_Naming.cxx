// Created on: 1997-09-03
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



#include <TNaming_Naming.ixx>

#include <TNaming_Builder.hxx>
#include <TNaming_Tool.hxx>
#include <TNaming_ListIteratorOfListOfNamedShape.hxx>
#include <TNaming_Iterator.hxx>
#include <TNaming_Scope.hxx>
#include <TNaming_NamingTool.hxx>
#include <TNaming_Name.hxx>
#include <TNaming_Identifier.hxx>
#include <TNaming_Localizer.hxx>
#include <TNaming_NewShapeIterator.hxx>
#include <TNaming_OldShapeIterator.hxx>
#include <TNaming_Selector.hxx>
#include <TNaming.hxx>
#include <TDF_ChildIterator.hxx>
#include <TDF_LabelList.hxx>
#include <TDF_Data.hxx>
#include <TDF_LabelMap.hxx>
#include <TDF_TagSource.hxx>
#include <TopoDS_Iterator.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>
#include <TopTools_MapIteratorOfMapOfShape.hxx>
#include <Standard_DomainError.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_ListIteratorOfListOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <TColStd_MapIteratorOfMapOfInteger.hxx>
#include <TopTools_MapIteratorOfMapOfOrientedShape.hxx>
#include <TopTools_HArray1OfShape.hxx>
#include <BRep_Tool.hxx>
#include <TopoDS.hxx>
// #include <TNaming_NCollections.hxx>
#include <NCollection_Map.hxx>   
#include <NCollection_DataMap.hxx>
typedef NCollection_Map<TopoDS_Shape> TNaming_MapOfShape; 
typedef TNaming_MapOfShape::Iterator TNaming_MapIteratorOfMapOfShape;
typedef NCollection_DataMap<TopoDS_Shape, TNaming_MapOfShape> TNaming_DataMapOfShapeMapOfShape; 
typedef TNaming_DataMapOfShapeMapOfShape::Iterator TNaming_DataMapIteratorOfDataMapOfShapeMapOfShape; 
// The bug concerns access to a null object in the method Filter():
#define BUC60847

#define OCC273
#define OCC350
#define OCC352
#define ALLOW_CHILD_NBS
//#define MDTV_DEB_CC
//#define MDTV_DEB_OR
//#define MDTV_DEB_MOD
//#define MDTV_OR
//#define MDTV_DEB_INNS
//#define MDTV_DEB_NBS
//#define MDTV_DEB_71
//#define MDTV_DEB_WIN
#ifdef MDTV_DEB
#include <TDF_MapIteratorOfLabelMap.hxx> 
#include <TCollection_AsciiString.hxx>
#include <TDF_Tool.hxx>
#include <BRepTools.hxx>
#include <TNaming_Tool.hxx>
#include <DbgTools.hxx>
#endif
#ifdef DEB
#include <TDF_Tool.hxx>
#include <TDF_MapIteratorOfLabelMap.hxx>

#include <TCollection_AsciiString.hxx>
#include <BRepTools.hxx>
void Print_Entry(const TDF_Label&       label)
{
  TCollection_AsciiString entry;
  TDF_Tool::Entry(label, entry);
  cout << "LabelEntry = "<< entry << endl;
}
static void Write(const TopoDS_Shape& shape,
		      const Standard_CString filename) 
{
  char buf[256];
  if(strlen(filename) > 256) return;
  strcpy (buf, filename);
  char* p = buf;
  while (*p) {
    if(*p == ':')
      *p = '-';
    p++;
  }
  ofstream save (buf);
  if(!save) 
    cout << "File " << buf << " was not created: rdstate = " << save.rdstate() << endl;
  save << "DBRep_DrawableShape" << endl << endl;
  if(!shape.IsNull()) BRepTools::Write(shape, save);
  save.close();
}
void WriteNSOnLabel(const Handle(TNaming_NamedShape) & NS, const TCollection_AsciiString& Nam)
{
  if (!NS.IsNull()) {
    TCollection_AsciiString entry;
    TDF_Tool::Entry(NS->Label(), entry);
    TopoDS_Shape Sh = TNaming_Tool::GetShape (NS);
    if(!Sh.IsNull()) {
      TCollection_AsciiString Entry = Nam + entry + ".brep";
      Write(Sh, Entry.ToCString());
    }
    else
      cout << "WriteNSOnLabel>>> TopoDS_Shape IS NULL on Entry = "<< entry << endl;
  }
  else
    cout << "WriteNSOnLabel >>>  NamedShape IS NULL" << endl;
}
//=======================================================================
static void Write(const TopTools_MapOfShape& MS,  const Standard_CString filename) 
{
  if (!MS.IsEmpty ()) {
    TCollection_AsciiString aNam (filename);
    Standard_Integer i(0);
    TopTools_MapIteratorOfMapOfShape it(MS);
    for(;it.More();it.Next(),i++) {
      TCollection_AsciiString aName = aNam + "_" + i + ".brep";
      Write ( it.Key(), aName.ToCString());
    }
  }
}
#endif

//==========================================================================================
static Handle(TNaming_NamedShape) BuildName (const  TDF_Label&   F,
					     TNaming_Scope&                    MDF,
					     const TopoDS_Shape&               S,
					     const TopoDS_Shape&               Context, 
					     const Handle(TNaming_NamedShape)& Stop,
					     const Standard_Boolean            Geometry);

//=======================================================================
static Standard_Integer RepeatabilityInContext(const TopoDS_Shape& Selection, 
					       const TopoDS_Shape& Context);
//=======================================================================
extern Standard_Boolean IsEqual (const TopoDS_Shape& S1, const TopoDS_Shape& S2);

//=======================================================================
//function : Solve
//purpose  : voir avec YFR comment retrouver le bon resulat et le mettre 
//         : dans le NamedShape de L
//=======================================================================
Standard_Boolean  TNaming_Naming::Solve (TDF_LabelMap& Valid) 
{ 
  Handle(TNaming_Naming) subname;
  for (TDF_ChildIterator it (Label(),Standard_False); it.More(); it.Next()) {
#ifdef MDTV_DEB_NBS
    TCollection_AsciiString anEntry;
    TDF_Tool::Entry(it.Value(), anEntry);
    cout << "TNaming_Naming::Solve: Label to be solved = " << anEntry << endl;
#endif
    if (it.Value().FindAttribute(TNaming_Naming::GetID(),subname)) {
      if (!subname->Solve (Valid)) {
	return Standard_False; // not necessary to continue
      }
    }
  }
#ifdef MDTV_DEB_CC
  TDF_MapIteratorOfLabelMap anItr(Valid);
  cout << "TNaming_Naming::Solve:: Valid label Map" << endl;
  for (; anItr.More(); anItr.Next()) {
    const TDF_Label& aLabel = anItr.Key();
    TCollection_AsciiString anEntry;
    TDF_Tool::Entry(aLabel, anEntry);
    cout << "Label = " << anEntry << endl;
  }
#endif
  if (Regenerate(Valid)) {
    if (!Valid.IsEmpty()) Valid.Add(Label());
    return Standard_True;
  }
  return Standard_False; 
}
 
 
//=======================================================================
//function : GetID
//purpose  : 
//=======================================================================

const Standard_GUID& TNaming_Naming::GetID () 
{
  static Standard_GUID TNaming_NamingID("c0a19201-5b78-11d1-8940-080009dc3333");
  return TNaming_NamingID; 
}

//=======================================================================
//function : Insert
//purpose  : 
//=======================================================================

Handle(TNaming_Naming) TNaming_Naming::Insert (const TDF_Label& under) 
{
  Handle(TNaming_Naming) N;  
  TDF_Label child = TDF_TagSource::NewChild(under);
  N = new TNaming_Naming ();  
  child.AddAttribute (N);
  return N;
}  
  
//=======================================================================
//function : BuildNS
//purpose  : returns a new NamedShape, which is built as selection: 
//         : TNaming_Builder::Select("S","S") at the new child label of the label <F>. 
//=======================================================================

static Handle(TNaming_NamedShape)  BuildNS (const TDF_Label&        F,
					    const TopoDS_Shape&     S,
					    const TNaming_NameType& Name)
{
  Handle (TNaming_Naming) Naming = TNaming_Naming::Insert (F);
  
  TNaming_Name& theName = Naming->ChangeName();
  theName.ShapeType(S.ShapeType());
  theName.Shape(S); 
  theName.Type(Name);
  TNaming_Builder B(Naming->Label());
  B.Select(S,S);
  return B.NamedShape();
}

//=======================================================================
//function : FindIndex
//purpose  : 
//=======================================================================

static Standard_Integer FindIndex(const Handle(TNaming_NamedShape)& NS,
				  const TopoDS_Shape&               S)
{
  TDF_LabelList Labels;
  TopoDS_Shape IS = TNaming_Tool::InitialShape(S,NS->Label(),Labels);
  Standard_Integer Index = 1;
  for (TNaming_Iterator itNS(NS); itNS.More(); itNS.Next(),Index++) {
    if (IS.IsSame(itNS.NewShape())) break;
  }
  return Index;
}


//=======================================================================
//function : CompareInGeneration
//purpose  : returns true, only if the specified NS contains only <S> in 
//         : the "new shapes" set.
//=======================================================================

static Standard_Boolean CompareInGeneration (const Handle(TNaming_NamedShape)& NS,
					     const TopoDS_Shape&               S)
{
  for (TNaming_Iterator it(NS); it.More(); it.Next()) {
    if (!it.NewShape().IsSame(S)) return 0;
  }
  return 1;
}

#ifdef OCC350

//=======================================================================
//function : GetShapeEvolutions
//purpose  : returns Standard_True, if target has parent in source; list contains inheritance chain
//=======================================================================
static Standard_Boolean GetShapeEvolutions(const TopoDS_Shape&               theTarget, // this is changed in recursion
					   const Handle(TNaming_NamedShape)& theSource,
					   TopTools_ListOfShape&             aList)     // returns list in the backward order
{
  Handle(TNaming_NamedShape) aTarget = TNaming_Tool::NamedShape(theTarget,theSource->Label());
  if (!aTarget.IsNull()) {
#ifdef MDTV_DEB_71
    cout <<"GetShapeEvolutions: target NS = ";
    Print_Entry(aTarget->Label());
    cout <<"GetShapeEvolutions: Source NS = ";
    Print_Entry(theSource->Label());
    TCollection_AsciiString aNam("GetShapeEvolutions");
    WriteNSOnLabel(aTarget,aNam);
#endif
    if (aTarget->Label() == theSource->Label()) return Standard_True; // check if target is in the source
  } else return Standard_False;

  TNaming_Iterator anIter(aTarget);
  for(;anIter.More();anIter.Next()) { // check all appropriate old shapes of target
#ifdef MDTV_DEB_71
    if(!anIter.OldShape().IsNull()) {
      Write(anIter.OldShape(), "Target_OldS.brep");
      cout <<"Target OldS TS =" <<anIter.OldShape().TShape()->This() <<endl;
    }
    if(!anIter.NewShape().IsNull()) {
      Write(anIter.NewShape(), "Target_NewS.brep");
      cout <<"Target NewS TS =" <<anIter.NewShape().TShape()->This() <<endl;
    }  
#endif
    if (anIter.OldShape().IsNull() || anIter.NewShape().IsNull()) continue;
    if (!anIter.NewShape().IsSame(theTarget)) continue;
    if (GetShapeEvolutions(anIter.OldShape(),theSource,aList)) { // recursion: now target is old shape
      aList.Append(theTarget); // if oldshape has the source as parent (or belongs to it) , fill the list
      return Standard_True;
    }
  }
  return Standard_False;
}

//=======================================================================
//function : CompareInModification
//purpose  : returns empty named shape if naming is already done
//=======================================================================

static Handle(TNaming_NamedShape) CompareInModification (const Handle(TNaming_NamedShape)& NS, // parent
							 const TopoDS_Shape&               S)  // target
{
  Handle(TNaming_NamedShape) aResult;
  if (S.IsNull() || NS.IsNull()) return aResult;
#ifdef MDTV_DEB_71
  cout <<"CompareInModification: parent NS = ";
  Print_Entry(NS->Label());
  Write(S, "CompareInM_S.brep");
  TCollection_AsciiString aNam("CompareInM");
  WriteNSOnLabel(NS,aNam);
#endif
  Handle(TNaming_NamedShape) aSource; // parent NamedShape, which can be found by TopoDS shape
  TNaming_Iterator anIt(NS);
  for(;anIt.More() && aSource.IsNull();anIt.Next()) {
    if (!anIt.NewShape().IsNull()) {
      aSource = TNaming_Tool::NamedShape(anIt.NewShape(),NS->Label());
#ifdef MDTV_DEB_71
      TCollection_AsciiString aNam("CompareInM_Source");
      WriteNSOnLabel(aSource,aNam);
#endif
    }
  }
  // searching for 1:n to the same label modifications (in this case current naming is insufficient)
  TopTools_ListOfShape aList;
  if (GetShapeEvolutions(S,aSource,aList) && aList.Extent() > 0) {
    TopTools_ListIteratorOfListOfShape anIter(aList);
    for(;anIter.More();anIter.Next()) {
      aResult = TNaming_Tool::NamedShape(anIter.Value(),NS->Label());
      if (aResult->Evolution()!=TNaming_MODIFY) { // evolution must be modify, otherwise everything is OK
	aResult.Nullify();
	return aResult;
      }
      TopTools_MapOfShape aMap; // collection of the old shapes of the shape from list
      TNaming_Iterator aNIter1(aResult);

      for(;aNIter1.More();aNIter1.Next()) {
	if (aNIter1.NewShape().IsSame(anIter.Value()))  {// if isSame 
	  aMap.Add(aNIter1.OldShape());
	}
      }
      TNaming_Iterator aNIter2(aResult); // if some another shapes has oldshape from map, return namedshape with this oldshape

      for(;aNIter2.More();aNIter2.Next()) {
	if (aNIter2.NewShape().IsSame(anIter.Value())) continue;
	if (aMap.Contains(aNIter2.OldShape())) { // if one shape was modified to the two at the shared label, return this one
	  aResult = TNaming_Tool::NamedShape(aNIter2.OldShape(),NS->Label());
	  if (!aResult.IsNull()) return aResult;
	}
      }
    }
    aResult.Nullify();
  }
  return aResult;
}
#endif

//=======================================================================
static Standard_Boolean FillSMap(const TopoDS_Shape& S, TopTools_MapOfShape& MS)
{   
  if(S.IsNull()) return Standard_False; 
  Standard_Boolean isHomogen(Standard_True);
  TopAbs_ShapeEnum aPrevType(TopAbs_SHAPE);
  TopoDS_Iterator it(S);
  for (; it.More(); it.Next()) {
    const TopAbs_ShapeEnum aType = it.Value().ShapeType();      
#ifdef MDTV_DEB_CC
    cout <<"TestSolution_FillMap: S_Type = :" << it.Value().ShapeType() <<" TShape = " << it.Value().TShape()->This() <<endl;
#endif
    if(aType > TopAbs_COMPSOLID) {
      MS.Add(it.Value());
      if(aPrevType == TopAbs_SHAPE)
	aPrevType = aType;
      else if(aPrevType != aType) 
	isHomogen = Standard_False;       
    }
    else 
      if(!FillSMap(it.Value(), MS))
	isHomogen = Standard_False;  
  }
  return isHomogen;
}
//=======================================================================
//function : Compare
//purpose  : checks naming of the shape <S> in the NamedShape <NS>. 
//         : Returns true, if it's correct. Details ==>
//         : The method takes all modifications of the "NS" (see CurrentShape method), 
//         : which are in the "MDF" (if it's not empty) before <Stop> shape and check them.
//         : whether these modifications contain only "S". If yes then the method 
//         : returns true, otherwise it returns false.
//=======================================================================

static Standard_Boolean Compare (const Handle(TNaming_NamedShape)& NS,
				 const TNaming_Scope&              MDF,
				 const Handle(TNaming_NamedShape)& Stop,
				 const TopoDS_Shape&               S)
{
  TDF_LabelMap Forbiden;
  TopTools_MapOfShape MS;
  if (!Stop.IsNull()) TNaming_NamingTool::BuildDescendants(Stop,Forbiden);
  TNaming_NamingTool::CurrentShape(MDF.GetValid(),Forbiden,NS,MS);
#ifdef MDTV_DEB_NBS
  Write(S, "Compare_S.brep");
  cout <<  "S: TShape = " <<S.TShape()->This() <<endl;
  Standard_Integer i =1;
  TopTools_MapIteratorOfMapOfShape it(MS);
  TCollection_AsciiString aNam("Compare_MS_");
  TCollection_AsciiString ext(".brep");
  for(;it.More();it.Next(), i++) {
    TCollection_AsciiString aName = aNam + i + ext;
    Write(it.Key(), aName.ToCString()) ;
    cout << aName.ToCString()<< ": TShape = " <<it.Key().TShape()->This() <<endl;
  }
#endif
  return (MS.Contains(S) && MS.Extent() == 1);
}
//=======================================================================
//function : TestSolution
//purpose  : returns true, if last modification of shape from "NS" is equal to "S":
//         : If shape "S" has atomic type (TopAbs_FACE, TopAbs_EDGE, TopAbs_VERTEX), 
//         : then returns S.IsSame(shape from "NS"). 
//         : Otherwise the result of exploration of these shapes must be same.
//=======================================================================

static Standard_Boolean TestSolution(const TNaming_Scope&      MDF,
				     const Handle(TNaming_NamedShape)& NS,
				     const TopoDS_Shape&               S)
{ 

  if (NS.IsNull()) return Standard_False;
  TopoDS_Shape Res = MDF.CurrentShape(NS);// last modification of NS taken into account Valid map
  if(S.IsNull() || Res.IsNull()) return Standard_False;
#ifdef MDTV_DEB_CC
  Write(S, "TSol_S.brep");
  Write(Res, "TSol_Res.brep");
#endif  
#ifdef OCC352

  if ((S.ShapeType() == TopAbs_FACE  ||
      S.ShapeType() == TopAbs_EDGE  ||
      S.ShapeType() == TopAbs_VERTEX ) && 
      Res.ShapeType() != TopAbs_COMPOUND) { 
    return (Res.IsSame(S));
  } else if (S.ShapeType() == TopAbs_SOLID ||
	S.ShapeType() == TopAbs_COMPSOLID) {
    TopTools_MapOfShape aMS;
    TopExp_Explorer exp;
    for (exp.Init(S,TopAbs_FACE) ; exp.More(); exp.Next()) {
      aMS.Add(exp.Current());
    }
    for (exp.Init(Res,TopAbs_FACE) ; exp.More(); exp.Next()) { //content of MS and Res should be the same 
      if (aMS.Contains(exp.Current())) {
	aMS.Remove(exp.Current());
      }
      else return 0;
    }
    return aMS.IsEmpty();
  } else {

#else

  if (S.ShapeType() == TopAbs_SOLID ||
      S.ShapeType() == TopAbs_FACE  ||
      S.ShapeType() == TopAbs_EDGE  ||
      S.ShapeType() == TopAbs_VERTEX ) { 
    return (Res.IsSame(S));
  }
  else {

#endif

    TopTools_MapOfShape MS;
    Standard_Boolean isHom = FillSMap(S, MS);
    TopAbs_ShapeEnum aType(TopAbs_SHAPE); 
    TColStd_MapOfInteger aView;
    TopTools_MapIteratorOfMapOfShape itm(MS);
    for(;itm.More();itm.Next()) {
      aType = itm.Key().ShapeType();
      if(isHom) 
	break;
       else 
	aView.Add(itm.Key().ShapeType());      
    }
    
    if (MS.Contains(Res)) {
      MS.Remove(Res);
      if (MS.IsEmpty()) return 1;
    }
    if (Res.ShapeType() == TopAbs_SOLID ||
 	Res.ShapeType() == TopAbs_COMPSOLID || 
	Res.ShapeType() == TopAbs_COMPOUND) 
      {
	TopExp_Explorer exp;
	if(isHom)
	  for (exp.Init(Res,aType) ; exp.More(); exp.Next()) {
	    if (MS.Contains(exp.Current())) {
	      MS.Remove(exp.Current());
	    }
	  } else {
	    TColStd_MapIteratorOfMapOfInteger itm(aView);
	    for(;itm.More();itm.Next()) {
	      TopAbs_ShapeEnum aType = (TopAbs_ShapeEnum)itm.Key();
	      for (exp.Init(Res,aType) ; exp.More(); exp.Next()) {
		if (MS.Contains(exp.Current())) {
		  MS.Remove(exp.Current());
		}
	      }
	    }
	  }
      } else {
	if(S.IsSame(Res))
	  return Standard_True;
	TopoDS_Iterator it(Res);
	for (; it.More(); it.Next()) { //content of MS and Res should be the same 
	  if (MS.Contains(it.Value())) {
	    MS.Remove(it.Value());
	  }
	  else return 0; 
	}
      }
    return MS.IsEmpty();
  }
}

//=======================================================================
//function : FindNewShapeInFather
//purpose  :
//=======================================================================

static void FindNewShapeInFather (const Handle(TNaming_NamedShape)& NS,
				  TopoDS_Shape&                     SC)
{  
  TDF_Label         Father  = NS->Label().Father(); 
  TNaming_Iterator  itLab(Father);
  if(itLab.More()) {
    SC= itLab.NewShape();
  }
}

//=======================================================================
//function : NextModif
//purpose  : 
//=======================================================================

static Handle(TNaming_NamedShape) NextModif(const Handle(TNaming_NamedShape)& NS)
{
  Handle (TNaming_NamedShape) Next;
  if (!NS.IsNull()) {
    TNaming_NewShapeIterator it(NS); 
    if (it.More()&& it.IsModification()) Next = it.NamedShape();
  }
  return Next;
}
//=======================================================================
// C1 - cand shape of the father, C2 - shape of rebuild child Naming attr.
//      (to be Compound of elementary shapes)
//=======================================================================
static Standard_Boolean IsContSame(const TopoDS_Shape& C1, const TopoDS_Shape& C2)
{
  Standard_Boolean aRes(Standard_False);
  if(!C1.IsNull() && !C2.IsNull()) {
    TopTools_MapOfShape aMap;
    if(FillSMap(C1, aMap)) {
      aRes = Standard_True;
      TopoDS_Iterator it(C2);
      for(;it.More();it.Next()) {
	if(!aMap.Contains(it.Value())) {
	  aRes = Standard_False;
	  break;
	}
      }
    }
  }
  return aRes;
}

//=======================================================================
// Identifies the case when Filter haven't sense because of multiplicity
//=======================================================================
static Standard_Boolean IsMultipleCase(const TopoDS_Shape&        S,
				 const TopoDS_Shape&        Context,
				 const TopTools_MapOfShape& Neighbourgs) {
  
  TopTools_IndexedDataMapOfShapeListOfShape aDM;
  TNaming_MapOfShape aM;
  TopTools_MapOfShape aNbs;
  aNbs.Assign(Neighbourgs);
  aNbs.Add(S);
  TNaming_DataMapOfShapeMapOfShape aDMM;
  TopExp::MapShapesAndAncestors (Context, TopAbs_EDGE, TopAbs_FACE, aDM);
  TopTools_MapIteratorOfMapOfShape it(aNbs);
  for(;it.More();it.Next()) {
    if(aDM.Contains(it.Key())) {
      TNaming_MapOfShape aMS;
      const TopTools_ListOfShape& aL = aDM.FindFromKey(it.Key());      
      TopTools_ListIteratorOfListOfShape lit(aL);
      for(;lit.More();lit.Next()) {
	aM.Add(lit.Value());
	aMS.Add(lit.Value());
      }
      if(aMS.Extent())
	aDMM.Bind(it.Key(), aMS);
    } else {
#ifdef DEB
      cout << "Key is not BOUND!" <<endl;
#endif
      return Standard_False;
    }
  }
  
  Standard_Boolean isCommon(Standard_True);
  TNaming_MapIteratorOfMapOfShape itm(aM);
  for(;itm.More();itm.Next()) {
    isCommon = Standard_True; // statement: this shape (itm.Key()) is common (to be checked below)
    TNaming_DataMapIteratorOfDataMapOfShapeMapOfShape itdm(aDMM);
    for (;itdm.More();itdm.Next()) {
      const TNaming_MapOfShape& aMap = itdm.Value();
      if(!aMap.Contains(itm.Key())) {
	isCommon = Standard_False;
	break;
      }
    }
    if(isCommon) break; // common single face found
  }
  if(isCommon && aM.Extent() < aNbs.Extent()) {// number of unique faces (to have single solution) 
                                               //should be at least no less than (Nb of Neighbourgs) +1
    return Standard_True;
  }
  return Standard_False;
}
//=======================================================================
//function : Filter
//purpose  : sets the name with type "FILTERBYNEIGHBOURGS" and returns true, 
//         : if it was correctly done.
//         : 
//         :
//=======================================================================

static Standard_Boolean Filter (const TDF_Label&                  F,
				TNaming_Scope&                    MDF,
				const TopoDS_Shape&               S,
				const TopoDS_Shape&               Context,
				TNaming_Localizer&                Localizer,
				Handle(TNaming_NamedShape)&       NS,
				const Standard_Integer            Lev)
{ 
  // 1. Localizer.FindNeighbourg("Context", "S", "Neighbourg") - looks for neighbourgs of  "S" with the same shape type in the "Context" 
  //    shape and adds them to the "Neighbourg" map;
  // 2. If "Neighbourg" map is empty, tries to do the same with the new context shape: shape from the father label of the "S" named shape;
  // 3. If "Neighbourg" map is still empty, returns false;
  // 4. Adds to the new child of label "L" new TNaming_Naming attribute with the next properties name: shape type is shape type of the "S",
  //     type is TNaming_FILTERBYNEIGHBOURGS, stop shape ( "Until" ) is "Context" of corresponding NamedShape; 
  //     first argument of name is "NS" NamedShape.
  // 5. Adds to the Name all shapes from "Neighbourg" map: build it with the BuildName( new generated TNaming_Naming attribute, MDF, 
  //    argument shape from "Neighbourg", "Context", NextModif( "Until" ), true ) method.
  // 6. Creates resulting NamedShape with the "Regenerate" ( it just calls TName::Solve method ) method from TNaming_Naming class.
  // 7. If Compare( result NamedShape, MDF, stop, "S" ) returns true, "Filter" method returns true, else returns false.

  //------------------------------
  // Construction des voisins ==> of neighbors.
  //------------------------------
  Standard_Integer aLev(Lev);
  TopTools_MapOfShape Neighbourg;
  Localizer.FindNeighbourg (Context,S,Neighbourg);
#ifdef MDTV_DEB_NBS
  //DbgTools::DisplayShape(Context, F, Quantity_NOC_GREEN);
  //DbgTools::DisplayShape(S, F, Quantity_NOC_BLUE1);  
  Write(Context, "FNBS_Context.brep");
  Write(S, "FNBS_S.brep");
#endif
#ifdef OCC273
  // mpv : NS and shape must be the same
  Standard_Boolean isIn = Standard_False;
  TNaming_Iterator anIter(NS);
  for(;anIter.More();anIter.Next()) {
#ifdef MDTV_DEB
	  //DbgTools::DisplayShape(anIter.NewShape(), F, Quantity_NOC_RED);
#endif
    if (anIter.NewShape().IsSame(S)) {
      isIn = Standard_True;
      break;
    }
  }
  if (!isIn) if (!TNaming_Tool::NamedShape(S,F).IsNull()) NS = TNaming_Tool::NamedShape(S,F);
//  if (!TNaming_Tool::NamedShape(S,F).IsNull()) NS = TNaming_Tool::NamedShape(S,F);
#endif
  
  if (Neighbourg.IsEmpty()) {
    // Recherche du vrai context. (Research of context truth)
    Handle(TNaming_NamedShape) GenS = TNaming_Tool::NamedShape(S,NS->Label());
#ifdef BUC60847
    if (GenS.IsNull()) return Standard_False;
#endif
    TDF_Label Father = (GenS->Label()).Father();
    Father.FindAttribute(TNaming_NamedShape::GetID(),GenS);
    TopoDS_Shape GoodContext = TNaming_Tool::GetShape(GenS);
    Localizer.FindNeighbourg (GoodContext,S,Neighbourg);
  }
  

  if (Neighbourg.IsEmpty()) {
#ifdef DEB
    cout <<"FindNeighbourg: impossible"<<endl;
#endif
    return 0;  
  } else {
#ifdef MDTV_DEB_NBS
    Write(Neighbourg, "Neighbourgs");
#endif
    aLev++;
    //cout <<"Filter: Lev = " << aLev << endl;
  }
  if(aLev > 3) return 0; 
#ifdef ALLOW_CHILD_NBS	 
  Handle(TNaming_Naming) aFNaming;
  TopoDS_Shape aFatherCandSh;
  F.FindAttribute(TNaming_Naming::GetID(), aFNaming);
  if(!aFNaming.IsNull()) {
    const TNaming_Name& aName = aFNaming->GetName();
    if (aName.Type() == TNaming_FILTERBYNEIGHBOURGS) {
      aFatherCandSh = aName.Arguments().First()->Get();
    }
  } 
  if(S.ShapeType() == TopAbs_EDGE && aFatherCandSh.IsNull()) {
    //check the applicability
    if(!NS.IsNull() && !NS->Get().IsNull() && NS->Get().ShapeType() == TopAbs_COMPOUND)
      if(IsMultipleCase(S, Context, Neighbourg)) {
	//cout << "Filter: ==> MultipleCase!" << endl;
	NS->Label().FindAttribute(TNaming_Naming::GetID(), aFNaming);
	if(!aFNaming.IsNull()) {
	  TNaming_Name& aName = aFNaming->ChangeName();
	  if (aName.Type() == TNaming_INTERSECTION) {
	    Standard_Integer ij(1);
	    TNaming_ListIteratorOfListOfNamedShape itA(aName.Arguments()); 
	    for (; itA.More(); itA.Next(), ij++) {
	      const TopoDS_Shape& aFace = TNaming_Tool::CurrentShape(itA.Value());
#ifdef MDTV_DEB_MOD
	      Write(aFace, "First_Face.brep");
	      cout <<"Selection TS = " << S.TShape()->This() <<endl;
#endif
	      Standard_Integer i(1), indxW(0),indxE(0),nbW(0),nbE(0), indxF(0);
	      Standard_Boolean isFound(Standard_False);
	      TopoDS_Iterator it(aFace);
	      for (;it.More();it.Next(),i++) {
		nbW++;
#ifdef MDTV_DEB_MOD
		Write(it.Value(), "First_Wire.brep");
#endif
		if(!isFound) {
		  Standard_Integer j(1);
		  TopoDS_Iterator it2(it.Value());
		  for (;it2.More();it2.Next(),j++) {
		    nbE++;
#ifdef MDTV_DEB_MOD
		    Write(it2.Value(), "First_Wire.brep");
		    cout <<"Edge TS = " << it2.Value().TShape()->This() <<endl;
#endif
		    if(S.IsEqual(it2.Value())) {
		      indxE = j;
		      indxW = i;
		      indxF = ij;
		      isFound = Standard_True;		    
		    }
		  }
		}	      
	      }
	      if(isFound) {
		Standard_Integer Index = indxE & 0x000000FF;
		Index = Index | (nbE   << 8);
		Index = Index | (indxW << 16);
		Index = Index | (nbW   << 20);
		Index = Index | (indxF << 24);
		aName.Index(Index);	      
		//------------------------------
		// Compute the TNaming_NamedShape
		//------------------------------
		aFNaming->Regenerate(MDF.ChangeValid());
		aFNaming->Label().FindAttribute(TNaming_NamedShape::GetID(),NS);
		Handle (TNaming_NamedShape) Until = TNaming_Tool::NamedShape(Context,NS->Label());
		Handle (TNaming_NamedShape) Stop  = NextModif(Until); 
		if (Compare (NS,MDF,Stop,S)) return 1;
		break; 
	      }	   
	    }
	  } 
	} 	
	return 0;
      }
  }
#endif

  //-----------------------------------------------------
  // Construction function de naming. et insertion sous F
  //-----------------------------------------------------
  Handle (TNaming_Naming) NF = TNaming_Naming::Insert (F);
  
  Handle (TNaming_NamedShape) Until = TNaming_Tool::NamedShape(Context,NS->Label());
  Handle (TNaming_NamedShape) Stop  = NextModif(Until); 
  TNaming_Name& theName = NF->ChangeName();
  theName.ShapeType(S.ShapeType());
  theName.Shape(S);
  theName.Type(TNaming_FILTERBYNEIGHBOURGS);
  theName.Append(NS);
  theName.StopNamedShape (Until);
#ifdef MDTV_DEB_NBS
  cout << "FilterByNBS: ";
  Print_Entry(NF->Label());
#endif
  //---------------------
  // Naming des voisins.
  //---------------------

  TopTools_MapIteratorOfMapOfShape itN(Neighbourg);
  for (; itN.More(); itN.Next()) {
#ifdef ALLOW_CHILD_NBS	  
    const TopoDS_Shape& aS = itN.Key();	  
    Handle (TNaming_NamedShape) aNS = 
      BuildName(NF->Label(), MDF, aS, Context, Stop, 1);	  
#ifdef MDTV_DEB_NBS
    const TopoDS_Shape& aS2 = aNS->Get(); 
    if(!aS.IsNull())
      cout << "Shape arg type = " << aS.ShapeType() <<" TSH = " << aS.TShape()->This()<<endl;
    if(!aS2.IsNull())
      cout << "Build shape type = " << aS2.ShapeType() <<" TSH = " << aS2.TShape()->This()<<endl;
#endif
		  
    const TopoDS_Shape aSNS = aNS->Get();  //allow child level
    Standard_Boolean allowChild(Standard_True);
    if(!aSNS.IsNull() && aSNS.ShapeType() == TopAbs_COMPOUND && !aFatherCandSh.IsNull()) 
      allowChild = !IsContSame(aFatherCandSh, aSNS);
    if(allowChild && !aSNS.IsNull() && aS.ShapeType() != aSNS.ShapeType() && 
       aSNS.ShapeType() == TopAbs_COMPOUND)
      { // aLev < 3 
#ifdef MDTV_DEB_NBS
	cout <<"Father label = ";
	Print_Entry(aNS->Label().Father());
	Write(aS,"SelectionS.brep");
	Write(aSNS,"SelectionSNS.brep");
#endif
	Handle(TNaming_Naming) aNaming;
	Standard_Boolean StandardFilter(Standard_True);
	aNS->FindAttribute(TNaming_Naming::GetID(), aNaming);
	if(!aNaming.IsNull()) {
	  const TNaming_Name& aName = aNaming->GetName();
	  if (aName.Type() == TNaming_GENERATION) 
	    StandardFilter = Standard_False;
	  if(StandardFilter)
	    if (!Compare (aNS,MDF,Stop,aS)) {
	      TNaming_Localizer aLocalizer;
	      Filter (NF->Label(), MDF,aS,Context, aLocalizer,aNS, aLev);
	    }
	}
      }    
    theName.Append(aNS);
#else 
    theName.Append(BuildName(NF->Label(), MDF, itN.Key(), Context, Stop, 1));
#endif
  }
  //------------------------------
  // Compute the TNaming_NamedShape
  //------------------------------
  NF->Regenerate(MDF.ChangeValid());
  NF->Label().FindAttribute(TNaming_NamedShape::GetID(),NS);

  //-----------------
  // Check du filtre.
  //-----------------
  if (Compare (NS,MDF,Stop,S)) return 1;
#ifdef MDTV_DEB
  cout <<"TNaming_Naming::Name Filter insufficient"<<endl;
#endif
  return 0;
}


//=======================================================================
//function : BuildNameInNS
//purpose  : Calls BuildName method, but with new context and new stop shape.  
//         : Context is searched at the father label of the "Context" label : 
//         : old shapes from the NamedShape at the defined father label.
//         : If it's impossible, then "S" set as context. 
//         : If "S" is in new context, then stop shape is named shape, 
//         : which belongs to the father label of the "Context" named shape.
//         : For example, face (F2) of prism (P) is generated from the edge (E) 
//         : of primitive face (F1) of box (B). F2 is named as GENERATION from E.
//         : Naming of E is done with help BuildNameInNS function:   
//         : with context B and stop shape P. 
//=======================================================================
static Handle(TNaming_NamedShape) BuildNameInNS (const TDF_Label&                  F,
						 TNaming_Scope&                    MDF,
						 const TopoDS_Shape&               S,
						 const Handle(TNaming_NamedShape)& Context,
						 const Handle(TNaming_NamedShape)& Stop,
						 const Standard_Boolean            Geometry)

{
  // il faut determiner un nouveau context et un nouveau Stop.
  // it is necessary to determine new a context and a new Stop
  TopoDS_Shape SC;
  Handle(TNaming_NamedShape) NewStop = Stop;
  
  TNaming_Localizer::FindShapeContext (Context,S,SC);

  if(!SC.IsNull()){
// <Context> is Ident.NamedShapeOfGeneration() ==
    TDF_Label Father = Context->Label().Father();
    Father.FindAttribute(TNaming_NamedShape::GetID(),NewStop);
#ifdef MDTV_DEB_INNS
    if(!Stop.IsNull())
      {cout <<" Stop NS : "; Print_Entry( Stop->Label());}
    if(!NewStop.IsNull())
      {cout <<" NewStop : ";  Print_Entry( NewStop->Label());}
    cout <<"ContextLabel: "; Print_Entry( Context->Label());
    cout <<"Father      : "; Print_Entry( Father);
#endif
  }
#ifdef MDTV_DEB_INNS
  if(NewStop.IsNull())
    cout <<"BuildNameInNS:: NewStop shape is  NULL" << endl;  
#endif 
  return BuildName (F,MDF,S,SC,NewStop,Geometry);
}

//=======================================================================
//function : 
//purpose  : 
//=======================================================================

static Handle(TNaming_NamedShape) BuildName (const TDF_Label&                  F,
					     TNaming_Scope&               MDF,
					     const TopoDS_Shape&               Selection,
					     const TopoDS_Shape&               Context,
					     const Handle(TNaming_NamedShape)& Stop,
					     const Standard_Boolean            Geom)
{

 
  
  // Create an identifier
  Standard_Boolean OnlyOne      = !Geom;
  Standard_Boolean IsGeneration = Standard_False;
#ifdef MDTV_DEB_MOD
  cout <<"BuildName: F =>  ";
  Print_Entry(F);
  cout <<" Selection type = " << Selection.ShapeType() << " TS = " << Selection.TShape()->This() << endl;
  Write(Selection, "BName_Selection.brep");
  Write(Context, "BName_Context.brep");
#endif
  TNaming_Identifier Ident(F, Selection, Context,OnlyOne);

  Handle (TNaming_Naming)  Naming;
  Handle (TNaming_NamedShape) NS;

  if (!Ident.IsDone()) {
    return BuildNS (F,Selection, TNaming_UNKNOWN);
  }
  if (Ident.IsFeature() && Stop.IsNull()) {
    //-------------
    // Deja Nomme
    //-------------
    if   (!OnlyOne) return Ident.FeatureArg();
    else            NS =   Ident.FeatureArg();
  }
  else {  
    //---------------------------------------------
    // Construction de la fonction d identification.
    //---------------------------------------------
    //Standard_Boolean NotOnlyOne = 0;

    Naming = TNaming_Naming::Insert(F);
   
    TNaming_Name& theName = Naming->ChangeName();
    theName.ShapeType(Selection.ShapeType());
    theName.Shape(Selection);
    theName.Type(Ident.Type());
#ifdef MDTV_DEB_MOD
    cout <<"BuildName: Inserted Naming Att at ";
    Print_Entry(Naming->Label());
    cout <<" NameType = " << theName.Type() <<endl;		
#endif
    if (Ident.IsFeature()) {
      theName.Append(Ident.FeatureArg());
    }
    if (theName.Type() == TNaming_GENERATION) { 
      theName.Append(Ident.NamedShapeOfGeneration());
      IsGeneration = Standard_True;
    } 
    if (theName.Type() == TNaming_CONSTSHAPE) {
      theName.Index(FindIndex(Ident.FeatureArg(),Selection));
    } 
    //------------------------------------
    // Renseignement du NamedShape d arret.
    //------------------------------------
    theName.StopNamedShape (Stop);
#ifdef MDTV_DEB_MOD
    if(!Stop.IsNull()) {
        TCollection_AsciiString Es;
      TDF_Tool::Entry(Stop->Label(), Es);
      cout <<"StopNS at Label = "<< Es << endl;
    }
#endif 
    //---------------------------------
    // Identification des arguments. 
    //---------------------------------

    for (Ident.InitArgs(); Ident.MoreArgs(); Ident.NextArg()) {
      if (Ident.ArgIsFeature()) {
	theName.Append(Ident.FeatureArg());
#ifdef MDTV_DEB_MOD
	if(!Ident.FeatureArg().IsNull()) {
	  TCollection_AsciiString E;
	  TDF_Tool::Entry(Ident.FeatureArg()->Label(), E);
	  cout <<"Added argument NS from Label = "<< E << endl;
	}
#endif 
      }
      else {
#ifdef MDTV_DEB_MOD
	  cout <<"BuildName: NameType = " <<theName.Type() << " NS ";
	  Print_Entry(Naming->Label());
	  cout <<"Ident.ShapeArg() type = " << Ident.ShapeArg().ShapeType() << " TS = " << Ident.ShapeArg().TShape()->This() << endl;	
	   Write(Ident.ShapeArg(), "BName_ShapeArg.brep");
#endif	
	  if (theName.Type() == TNaming_GENERATION)
	  theName.Append(BuildNameInNS(Naming->Label(),MDF,Ident.ShapeArg(),Ident.NamedShapeOfGeneration(),Stop,Geom));
	else 
	  theName.Append(BuildName(Naming->Label(),MDF,Ident.ShapeArg(),Context,Stop,Geom));
      }
    }

    //------------------------
    // Reconstruction of Name
    //------------------------
    Naming->Regenerate(MDF.ChangeValid()); 
#ifdef MDTV_DEB_MOD
    TCollection_AsciiString E2;
    TDF_Tool::Entry(Naming->Label(), E2);
    cout <<"Regenerated Naming Att at Label = "<< E2 << endl;
#endif 
    Naming->Label().FindAttribute(TNaming_NamedShape::GetID(),NS);
    if(NS.IsNull()) return NS; 
    if (MDF.WithValid()) MDF.Valid(NS->Label());
#ifdef MDTV_DEB_MOD
    if(!NS.IsNull()) {
      TCollection_AsciiString E;
      TDF_Tool::Entry(NS->Label(), E);
      cout <<"Regenerated NS at Label = "<< E << endl;
    }
#endif 
  }

  if (OnlyOne) {
    //-------------------------------------------------
    // Filtre par les voisins
    // pour construire le nom correspondant a S.
    //------------------------------------------------- 

#ifdef OCC273
   if(NS.IsNull()) return NS; 
#endif

    TNaming_Localizer Localizer;
    TNaming_Iterator itNS(NS); 
    if (itNS.More()) {
      //----------------
      // Check + Filtre
      //----------------

#ifdef OCC350

      Standard_Boolean StandardFilter = !IsGeneration;
      if (IsGeneration) {
	if (!CompareInGeneration (NS,Selection)) {

	  TopoDS_Shape               NewContext;
	  Handle(TNaming_NamedShape) NewStop;
	  FindNewShapeInFather (Ident.NamedShapeOfGeneration(),NewContext);
	  Filter (F,MDF,Selection,NewContext,Localizer,NS,0);
	}
      } else if (Ident.Type() == TNaming_MODIFUNTIL ||
		 (Ident.Type() == TNaming_INTERSECTION && Naming->ChangeName().Arguments().Extent() == 1)) {
#ifdef MDTV_DEB_MOD
	cout <<"BuildName(CompareInModification): NameType = " <<Ident.Type() << " NS ";
	Print_Entry(Ident.Type() == TNaming_MODIFUNTIL ? NS->Label() : Naming->ChangeName().Arguments().First()->Label());
	cout <<"Selection type = " << Selection.ShapeType() << " TS = " << Selection.TShape()->This() << endl;	
#endif
	Handle(TNaming_NamedShape) NewNS =
	  CompareInModification(Ident.Type() == TNaming_MODIFUNTIL ? NS : Naming->ChangeName().Arguments().First(), Selection);
	if (!NewNS.IsNull()) { // there is need to describe name in detail: modification with type 1:n in the same label
	  StandardFilter = Standard_False;
	  if (Ident.IsFeature()) { // for MODIFUNTIL: change it to the GENERATION
	    Naming = TNaming_Naming::Insert(F);
	    TNaming_Name& theName = Naming->ChangeName();
	    theName.ShapeType(Selection.ShapeType());
	    theName.Shape(Selection); //szy 21.10.03
	    theName.Type(TNaming_GENERATION);
	    theName.Append(TNaming_Tool::NamedShape(Selection,F));
	    theName.Append(NewNS);
	    Naming->Regenerate(MDF.ChangeValid());
	    Naming->Label().FindAttribute(TNaming_NamedShape::GetID(),NS);

	  }
	  Filter (F,MDF,Selection,Context,Localizer,NS,0);
	}
      }
      if (StandardFilter) if (!Compare (NS,MDF,Stop,Selection)) {
	Filter (F,MDF,Selection,Context,Localizer,NS,0);
      }

#else

      if (IsGeneration) {
	if (!CompareInGeneration (NS,Selection)) {
	  TopoDS_Shape               NewContext;
	  Handle(TNaming_NamedShape) NewStop;
	  FindNewShapeInFather (Ident.NamedShapeOfGeneration(),NewContext);
	  Filter (F,MDF,Selection,NewContext,Localizer,NS,0);
	}
      }
      else {
	if (!Compare (NS,MDF,Stop,Selection))
	  Filter (F,MDF,Selection,Context,Localizer,NS,0);
      }

#endif

    }
  }
  if (MDF.WithValid()) MDF.Valid(NS->Label());
#ifdef MDTV_DEB_MOD
    if(!NS.IsNull()) {
      TCollection_AsciiString E;
      TDF_Tool::Entry(NS->Label(), E);
      cout <<"Returned NS from Label = "<< E << endl;
    }
#endif 
  return NS;
}

//=======================================================================
//function : Validate
//purpose  : 
//=======================================================================

static void Validate(TNaming_Scope&    MDF,
		     TNaming_OldShapeIterator& it)
{
  MDF.Valid(it.Label()); 
  MDF.ValidChildren(it.Label());

  TNaming_OldShapeIterator it2(it);
  for (; it2.More(); it2.Next()) {
    Validate (MDF,it2);
  }
}

//=======================================================================
//function : UnValidate
//purpose  : 
//=======================================================================

static void UnValidate(TNaming_Scope&    MDF,
		       TNaming_NewShapeIterator& it)
{
  MDF.Unvalid(it.Label()); 
  MDF.UnvalidChildren(it.Label());

  TNaming_NewShapeIterator it2(it);
  for (; it2.More(); it2.Next()) {
    UnValidate (MDF,it2);
  }
}

//=======================================================================
//function : BuildScope
//purpose  : adds to the MDF the label of <Context> NamedShape, 
//         : its children, all its oldShapes and its children.
//         : unvalidates all newShapes and it's children.
//         : If <Context> is null or next modification has an empty newShape 
//         : ( this shape was deleted ), then MDF.WithValid(Standard_False) 
//         : and nothing is added to the scope.
//=======================================================================

static void BuildScope (TNaming_Scope&    MDF,
			     const TopoDS_Shape&    Context,
			     const TDF_Label&       Acces) 
{
  if (Context.IsNull()) {
    MDF.WithValid(Standard_False);
    return;
  }

  //----------------------------------------------------
  // Is context the current state
  //----------------------------------------------------
  Handle(TNaming_NamedShape) NS   = TNaming_Tool::NamedShape(Context,Acces);
  Handle(TNaming_NamedShape) Next = NextModif(NS); // if NS has subsequent evolution = MODIFY, return it
  if (Next.IsNull()) {  
    MDF.WithValid(Standard_False);
    return;
  }
  //----------------------------- 
  // a posteriori naming
  //-----------------------------  
  MDF.WithValid(Standard_True);
  MDF.Valid(NS->Label());
  MDF.ValidChildren(NS->Label());
  TNaming_OldShapeIterator it(Context,Acces);

  for (; it.More(); it.Next()) {
    Validate(MDF,it);
  }

  TNaming_NewShapeIterator it2(Context,Acces);
  for (;it2.More(); it2.Next()) {
    UnValidate (MDF,it2);
  }
}

//=======================================================================
static Standard_Boolean HasAncFace(const TopoDS_Shape& Context, 
				   const TopoDS_Shape& W, TopoDS_Shape& Face)
{ 
  Standard_Boolean hasFace(Standard_False);
  if(W.ShapeType() != TopAbs_WIRE)
    return hasFace;
  TopExp_Explorer exp(Context, TopAbs_FACE);
  for(;exp.More(); exp.Next()) {
    for (TopoDS_Iterator it(exp.Current()) ; it.More(); it.Next()) {
      if(it.Value().IsEqual(W)) {// is the Wire ?
	Face = exp.Current();
	if(!Face.IsNull()) {
	  hasFace = Standard_True;
	  //	  cout << "HasAncFace: TS = " <<theFace.TShape()->This() <<endl;
	  break;
	}	
      }
    }
    if(hasFace) break;
  }
  return hasFace;
}

//=======================================================================
//function : BuildNameWire
//purpose  : Names Wire
//=======================================================================

static Handle(TNaming_NamedShape) BuildNameWire (const TDF_Label&                  F,
						 TNaming_Scope&                    MDF,
						 const TopoDS_Shape&               Selection,
						 const TopoDS_Shape&               Context,
						 const Handle(TNaming_NamedShape)& Stop,
						 const Standard_Boolean            Geom)
{  
  Handle (TNaming_NamedShape) NS;
  Standard_Boolean found(Standard_False);
  Handle (TNaming_Naming)  Naming;
  if(!F.FindAttribute(TNaming_Naming::GetID(), Naming)) {
    Naming = new TNaming_Naming ();
    F.AddAttribute (Naming);
    TNaming_Name& theName = Naming->ChangeName();
    theName.ShapeType(Selection.ShapeType());
    theName.Shape(Selection); 
  } 

  TNaming_Name& theName = Naming->ChangeName();  
  TopoDS_Shape aFace;
  Standard_Boolean hasFace = HasAncFace(Context, Selection, aFace);
  if(Selection.ShapeType() == TopAbs_WIRE && Context.ShapeType() < Selection.ShapeType() && hasFace) {	
    theName.Type(TNaming_WIREIN);
    if(Context.ShapeType() == TopAbs_FACE) {
      for (TopoDS_Iterator it(Context) ; it.More(); it.Next()) {
	if(it.Value().IsEqual(Selection)) {
	  if (TNaming_Selector::IsIdentified (F, Context, NS, Geom)) {		
	    theName.Append(NS);
	    found = Standard_True;
	    break;
	  }
	}
      }
      if(!found)
	return BuildNS (F,Selection, TNaming_UNKNOWN);
    } else {
        Standard_Integer indx(0), i(0);
	for (TopoDS_Iterator it(aFace); it.More(); it.Next()) {
	  i++;
	  if(it.Value().IsEqual(Selection)) {
	    found = Standard_True;
	    theName.Append(BuildName (Naming->Label(),MDF,aFace,Context,Stop,Geom));
	    indx = i;
	  }
	}
	if(found) {
	  const Standard_Integer num(i);
	  indx = indx | num << 8;
	  //cout << " final Index = " << indx <<endl;
	  theName.Index(indx);
	} else
	  return BuildNS (F,Selection, TNaming_UNKNOWN);
      }
  }
  else {
    theName.Type(TNaming_UNION);
    for (TopExp_Explorer exp(Selection,TopAbs_EDGE) ; exp.More(); exp.Next()) {
      if(exp.Current().IsNull()) continue;
      if (BRep_Tool::Degenerated(TopoDS::Edge(exp.Current()))) continue;//03.03.2010
      theName.Append(BuildName (Naming->Label(),MDF,exp.Current(),Context,Stop,Geom));
    }
  }
  //Naming->GetName().Solve(Naming->Label(),MDF.GetValid());
  Naming->Label().FindAttribute(TNaming_NamedShape::GetID(),NS);  
  return NS;
}

//=======================================================================
static Standard_Boolean IsOneIn (const TopoDS_Shape& S, const TopoDS_Shape& Context)
{
  Standard_Boolean found(Standard_False);
  if(S.IsNull() || Context.IsNull()) return found;
  for (TopExp_Explorer exp(Context,S.ShapeType()); exp.More(); exp.Next()) {
    if (exp.Current().IsEqual(S)) {
      found = Standard_True;
      break;
    }
  }
  return found;
}

//=======================================================================
static Standard_Boolean IsAllIn (const TopoDS_Shape& S, const TopoDS_Shape& Context)
{
#ifdef MDTV_DEB_CC
  Write(S, "IsAllIn_Sel.brep");
#endif
  Standard_Boolean found(Standard_False);
  if(S.IsNull() || Context.IsNull()) return found;
  Standard_Integer num1(0), num2(0);
  for(TopoDS_Iterator it(S);it.More();it.Next(),num1++) {
#ifdef MDTV_DEB_CC
  cout <<"S sub-shape type = " << it.Value().ShapeType() <<endl;
  Write (it.Value(), "Sel_ItValue.brep");
#endif
  if(it.Value().ShapeType() != TopAbs_COMPOUND)
    for (TopExp_Explorer exp(Context,it.Value().ShapeType()); exp.More(); exp.Next()) {
#ifdef MDTV_DEB_CC
  cout <<"Context sub-shape type = " << exp.Current().ShapeType() <<endl;
  Write(exp.Current(), "Contex_Curnt.brep");
#endif
      if (exp.Current().IsEqual(it.Value())) { 
	num2++;
	break;
      }
    } else {
      Standard_Boolean isAll = IsAllIn(it.Value(), Context);
      if(isAll) 
	num2++;
    }
  }
  if(num1 == num2)
    found = Standard_True;
#ifdef MDTV_DEB_CC
  else
    cout <<"Compound case : selected num1 = " << num1 << " context contains num2 = " << num2 << endl;
#endif
  return found;
}
//=======================================================================
//function : RepeatabilityInContext
//purpose  : 
//=======================================================================
static Standard_Integer RepeatabilityInContext(const TopoDS_Shape& Selection, 
					       const TopoDS_Shape& Context)
{
  Standard_Integer aNum(0);
  if (!Context.IsNull() && !Selection.IsNull()) {
//    Write(Selection, "Repeat_Selection.brep");
//    Write(Context, "Repeat_Context.brep");
    if (Context.ShapeType() < Selection.ShapeType()) {
      for (TopExp_Explorer exp(Context,Selection.ShapeType()); exp.More(); exp.Next()) {
	if (exp.Current().IsSame(Selection)) 
	  aNum++;
      }
    } 
    else if(Selection.ShapeType() == TopAbs_COMPOUND) {
      TopoDS_Iterator it(Selection);
      for(;it.More();it.Next()) {
	Standard_Integer n(0);
	for (TopExp_Explorer exp(Context,it.Value().ShapeType()); exp.More(); exp.Next()) {
	  if (exp.Current().IsSame(it.Value())) {
	    n++;
	  }
	}
	if(n > aNum) aNum = n;
      }
    } 
  }
#ifdef MDTV_DEB_OR
      cout <<"RepeatabilityInContext: = " <<aNum <<endl;
#endif 
  return aNum;
}
//=======================================================================
//function : BuildAggregationNam
//purpose  : 
//=======================================================================
static void BuildAggregationName (const TDF_Label&                  F,
				  TNaming_Scope&                    MDF,
				  const TopoDS_Shape&               S,
				  const TopoDS_Shape&               Context,
				  const Handle(TNaming_NamedShape)& Stop,
				  const Standard_Boolean            Geom)
{
  const Standard_Boolean found2 = IsAllIn(S, Context); 
  Handle (TNaming_Naming)  Naming;
  if(!F.FindAttribute(TNaming_Naming::GetID(), Naming)) {
    Naming = new TNaming_Naming ();
    F.AddAttribute (Naming);
    TNaming_Name& theName = Naming->ChangeName();
    theName.ShapeType(S.ShapeType());
    theName.Shape(S); 
  } 
#ifdef MDTV_DEB_CC
  cout <<"BuildAggregationName ==> ";
  Print_Entry(Naming->Label());
#endif
  TNaming_Name& theName = Naming->ChangeName();  
  for (TopoDS_Iterator itc(S) ; itc.More(); itc.Next()) {
    const TopoDS_Shape& aS = itc.Value();
    if ((aS.ShapeType() == TopAbs_SOLID && !TNaming_Tool::NamedShape(aS,Naming->Label()).IsNull()) ||
	aS.ShapeType() == TopAbs_FACE  ||
	aS.ShapeType() == TopAbs_EDGE  ||
	aS.ShapeType() == TopAbs_VERTEX ) {
      theName.Append(BuildName (F, MDF, aS,Context,Stop,Geom));
    } else { // ==> union of union || union of wires
      TopAbs_ShapeEnum atomTyp; 
      switch (aS.ShapeType()) 
	{
	case TopAbs_SOLID:
	case TopAbs_SHELL:
	  atomTyp = TopAbs_FACE;
	  break;
	case TopAbs_WIRE:
	  atomTyp = TopAbs_EDGE;
	  break;
	default: 
	  atomTyp = TopAbs_SHAPE;
	}
      
      Handle(TNaming_NamedShape) aNS;
      Handle (TNaming_Naming)  aNaming = TNaming_Naming::Insert(F); 
      TNaming_Name&               aName = aNaming->ChangeName();	  
      aName.ShapeType(aS.ShapeType());
      aName.Shape(aS); 
      aName.Type(TNaming_UNION);
      
      if (atomTyp != TopAbs_SHAPE) {
	if(aS.ShapeType() == TopAbs_WIRE) {
	  aNS = BuildNameWire (aNaming->Label(), MDF, aS, Context,Stop,Geom);
	}
	else {
	  for (TopExp_Explorer exp(aS,atomTyp) ; exp.More(); exp.Next()) {
	    aName.Append(BuildName (aNaming->Label(),MDF,exp.Current(),Context,Stop,Geom));
	  }
	}
      } else {
#ifdef MDTV_DEB_CC
	cout << "atomic type is NOT defined ... ==> Aggregation" <<endl;
#endif
	BuildAggregationName(aNaming->Label(),MDF, aS, Context,Stop,Geom);
      }
      if(found2) {
	aNS = TNaming_Tool::NamedShape(Context, F);
	if(!aNS.IsNull()) 
	  aNaming->ChangeName().ContextLabel(aNS->Label());
      }
      
      aNaming->GetName().Solve(aNaming->Label(),MDF.GetValid());
      if(aNaming->Label().FindAttribute(TNaming_NamedShape::GetID(),aNS))
	if (!Geom && TestSolution(MDF,aNS,aS)) {
	  theName.Append(aNS);
	}
    }
  }
}


//=======================================================================
//function : Name
//purpose  : 
//=======================================================================

Handle(TNaming_NamedShape) TNaming_Naming::Name (const TDF_Label&       F,
						 const TopoDS_Shape&    S,
						 const TopoDS_Shape&    Context,
						 const Standard_Boolean Geom,
						 const Standard_Boolean KeepOrientation,
						 const Standard_Boolean BNProblem)

{
  Handle(TNaming_NamedShape) NS;
  if (KeepOrientation) {
#ifdef MDTV_DEB_INNS
    cout <<"KeepOR = 1: "; Print_Entry(F);
#endif
    Standard_Integer aNum = RepeatabilityInContext(S, Context);

    Standard_Boolean aBNproblem = (BNProblem) ? (aNum /*== 1*/ && S != Context) : Standard_False;

    if (aNum > 1 || aBNproblem) {
      TopoDS_Shape UC = TNaming::FindUniqueContext(S, Context);
      Handle(TopTools_HArray1OfShape) Arr;
      if (UC.IsNull() && S.ShapeType() == TopAbs_COMPOUND) {
	UC = TNaming::FindUniqueContextSet(S, Context, Arr);
#ifdef MDTV_DEB_CC
	Write(UC, "UniqueContextSet.brep");
	Write(S,  "InitialSelection.brep");
	if(S.ShapeType()==TopAbs_COMPOUND) {
	  TCollection_AsciiString aNam("S_");
	  TopoDS_Iterator it(S);
	  for(int i=1;it.More();it.Next(),i++) {	   
	    TCollection_AsciiString aName = aNam + i + ".brep";     
	    Write(it.Value(), aName.ToCString());
	  }
	}
#endif	
      }
      if(!UC.IsNull()) {
	Handle (TNaming_Naming)  Naming = TNaming_Naming::Insert(F);
	TNaming_Name&           theName = Naming->ChangeName();
	theName.ShapeType(S.ShapeType());
	theName.Shape(S); 
	theName.Type(TNaming_ORIENTATION);

	if (!TNaming_Selector::IsIdentified (F, S, NS, Geom)) 
	  NS = TNaming_Naming::Name(Naming->Label(),S,Context,Geom,0);
	theName.Append (NS);
#ifdef MDTV_OR
	cout << " Sel Label ==> "; Print_Entry(NS->Label());
#endif
//szy 21.10.2009	
	if(S.ShapeType() == TopAbs_EDGE && UC.ShapeType() == TopAbs_FACE) {
	  if(RepeatabilityInContext(S, UC) == 2) { //sim. edge
	    TopoDS_Iterator itw(UC);
	    for(;itw.More();itw.Next()) {
	      Standard_Boolean found(Standard_False);
	      TopoDS_Iterator it(itw.Value());
	      for(int i=1;it.More();it.Next(),i++) {
		if(it.Value().IsEqual(S)) {
		  theName.Index(i);
		  found = Standard_True;
#ifdef MDTV_OR
		  cout << "ORDER = " << i <<endl;
#endif
		  break;
		}
	      }
	      if(found) break;
	    }
	  }
	}
//	
	if(S.ShapeType() == TopAbs_COMPOUND && Arr->Length() > 1) {
	  // N arguments: to be optimized to avoid duplication of the same Context shape
	  for(Standard_Integer i = Arr->Lower(); i <= Arr->Upper(); i++) {
	    NS = TNaming_Naming::Name(Naming->Label(), Arr->Value(i), Context, Geom, 1, aBNproblem);
	    theName.Append (NS);
	  }
	} else {	  
	  NS = TNaming_Naming::Name(Naming->Label(),UC,Context, Geom, 1, aBNproblem);
	  theName.Append (NS);
#ifdef MDTV_OR
	cout << " Cont Label ==> "; Print_Entry(NS->Label());
#endif
	}
      //Naming->Update();
	TNaming_Scope MDF;
	BuildScope (MDF,Context,F);
	Naming->GetName().Solve(Naming->Label(),MDF.GetValid());
	Naming->Label().FindAttribute(TNaming_NamedShape::GetID(),NS);
	theName.ContextLabel(NS->Label());
	if (Geom) return NS;
	if(NS.IsNull()) {
	cout <<" %%% WARNING: TNaming_Naming::Name:  FAILED"<<endl;
	return BuildNS (F,S, TNaming_UNKNOWN);
      }

        if (!Geom && TestSolution(MDF,NS,S)) return NS;      
	cout <<" %%% WARNING: TNaming_Naming::Name:  FAILED"<<endl;

	// Naming n is  unsatisfactory
	return BuildNS (F,S, TNaming_UNKNOWN);
      }
    } else
      if (TNaming_Selector::IsIdentified (F, S, NS, Geom))
	return NS;
  }

  //------------------------------------------------------------
  // Construction du MDF tel que <Context> soit le dernier etat
  // valide,
  // Ceci pour les localisation a posteriori par exemple. 
  //------------------------------------------------------------  

  TNaming_Scope MDF;
  BuildScope (MDF,Context,F);
  Handle(TNaming_NamedShape) Stop;

#ifdef OCC352

  if ((S.ShapeType() == TopAbs_SOLID && !TNaming_Tool::NamedShape(S,F).IsNull()) ||

#else

  if (S.ShapeType() == TopAbs_SOLID ||

#endif

      S.ShapeType() == TopAbs_FACE  ||
      S.ShapeType() == TopAbs_EDGE  ||
      S.ShapeType() == TopAbs_VERTEX ) {
    //---------------------------------------
    // Localisation de S comme element simple.
    //---------------------------------------
    Handle(TNaming_NamedShape) NS = BuildName (F,MDF,S,Context,Stop,Geom);
    if (Geom) return NS; 
    if (!Geom && TestSolution(MDF,NS,S)) return NS; 
  }
  else {
    //----------------------------------------------------
    // Localisation de S comme ensemble d elements simples.
    //-----------------------------------------------------
    Handle(TNaming_NamedShape) NS;
    Handle (TNaming_Naming)  Naming = TNaming_Naming::Insert(F); 
    TNaming_Name&           theName = Naming->ChangeName();

    theName.ShapeType(S.ShapeType());// modified by vro 05.09.00
    theName.Shape(S); 
    if(S.ShapeType() != TopAbs_WIRE) 
      theName.Type(TNaming_UNION);

#ifdef OCC352
    TopAbs_ShapeEnum atomType;
    switch (S.ShapeType()) {
    case TopAbs_COMPSOLID:
    case TopAbs_SOLID:
    case TopAbs_SHELL:
      atomType = TopAbs_FACE;
      break;
    case TopAbs_WIRE:
      atomType = TopAbs_EDGE;
      break;
    default:
      atomType = TopAbs_SHAPE;
    }
    Standard_Boolean found(Standard_False);
    if (!Context.IsNull()) {
      if (Context.ShapeType() < S.ShapeType()) 
	found = IsOneIn(S, Context);
      if(found) {
	NS = TNaming_Tool::NamedShape(Context, F);
	if(!NS.IsNull()) 
	  theName.ContextLabel(NS->Label());
      }
    }
    if (atomType == TopAbs_SHAPE) {
      if(S.ShapeType() == TopAbs_COMPOUND) {
	BuildAggregationName(Naming->Label(),MDF, S, Context,Stop,Geom);
      } else { 
	for (TopoDS_Iterator it(S) ; it.More(); it.Next()) {
	  theName.Append(BuildName (Naming->Label(),MDF,it.Value(),Context,Stop,Geom));
	}
      }
    } else {
      if(S.ShapeType() == TopAbs_WIRE)
	NS = BuildNameWire (Naming->Label(), MDF, S, Context,Stop,Geom);
      else {
	theName.Type(TNaming_UNION);
	for (TopExp_Explorer exp(S,atomType) ; exp.More(); exp.Next()) {
	  theName.Append(BuildName (Naming->Label(),MDF,exp.Current(),Context,Stop,Geom));
	}
      }
    }
#else    
    for (TopoDS_Iterator it(S) ; it.More(); it.Next()) {
      theName.Append(BuildName (Naming->Label(),MDF,it.Value(),Context,Stop,Geom));
    }
#endif

    //Naming->Update(); 
    Naming->GetName().Solve(Naming->Label(),MDF.GetValid());
    Naming->Label().FindAttribute(TNaming_NamedShape::GetID(),NS);
    if (Geom) return NS; 

#ifdef OCC273
    if(NS.IsNull()) return BuildNS (F,S, TNaming_UNKNOWN); 
#endif

    if (!Geom && TestSolution(MDF,NS,S)) return NS; 
  }
  
      cout <<" %%% WARNING: TNaming_Naming::Name:  FAILED"<<endl;

  // Naming n is not satisfactory
  return BuildNS (F,S, TNaming_UNKNOWN); 
}


//=======================================================================
//function : TNaming_Naming
//purpose  : 
//=======================================================================

TNaming_Naming::TNaming_Naming() {}

//=======================================================================
//function : ID
//purpose  : 
//=======================================================================

const Standard_GUID& TNaming_Naming::ID () const
{
  return GetID(); 
}


//=======================================================================
//function : IsDefined
//purpose  : 
//=======================================================================

Standard_Boolean TNaming_Naming::IsDefined() const
{
  return (myName.Type() != TNaming_UNKNOWN);
}

//=======================================================================
//function : GetName
//purpose  : 
//=======================================================================

const TNaming_Name& TNaming_Naming::GetName() const
{
  return myName;
}

//=======================================================================
//function : ChangeName
//purpose  : 
//=======================================================================

TNaming_Name& TNaming_Naming::ChangeName()
{
  return myName;
}

//=======================================================================
//function : Regenerate
//purpose  : idem designer
//=======================================================================

Standard_Boolean TNaming_Naming::Regenerate (TDF_LabelMap& MDF)  

{
  return myName.Solve(Label(),MDF);
}


//=======================================================================
//function : NewEmpty
//purpose  : 
//=======================================================================

Handle(TDF_Attribute) TNaming_Naming::NewEmpty () const
{  
  return new TNaming_Naming (); 
}


//=======================================================================
//function : Restore
//purpose  : 
//=======================================================================

void TNaming_Naming::Restore(const Handle(TDF_Attribute)& other) 
{
  Handle(TNaming_Naming) OtherNaming = Handle(TNaming_Naming)::DownCast(other);
  myName = OtherNaming->ChangeName();
}

//=======================================================================
//function : Paste
//purpose  : 
//=======================================================================

void TNaming_Naming::Paste (const Handle(TDF_Attribute)& into,
			       const Handle(TDF_RelocationTable)& RT) const
{
  Handle(TNaming_Naming) NewNaming = Handle(TNaming_Naming)::DownCast(into);
  myName.Paste(NewNaming->ChangeName(),RT);
}
  
//=======================================================================
//function : References
//purpose  : Redefined from TDF_Attribute
//=======================================================================

void TNaming_Naming::References(const Handle(TDF_DataSet)& DataSet) const
{
  // Iteration on NamedShape of the name
  TNaming_ListIteratorOfListOfNamedShape it(myName.Arguments());
  for (;it.More();it.Next()) DataSet->AddAttribute(it.Value());
  if (!myName.StopNamedShape().IsNull()) DataSet->AddAttribute(myName.StopNamedShape());
}
//=======================================================================
//function : Dump
//purpose  : 
//=======================================================================

Standard_OStream& TNaming_Naming::Dump (Standard_OStream& anOS) const
{  
  anOS << "TNaming_Naming";
  return anOS;
}


//=======================================================================
//function :ExtendedDump
//purpose  : 
//=======================================================================

void TNaming_Naming::ExtendedDump(Standard_OStream& anOS,
                                  const TDF_IDFilter& /*aFilter*/,
                                  TDF_AttributeIndexedMap& /*aMap*/) const
{
  anOS << "TNaming_Naming ExtendedDump  ";
  //anOS<<"myContext: #" <<aMap.Add(myContext)<<endl; 
}

