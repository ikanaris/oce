// Created on: 1997-12-10
// Created by: Denis PASCAL
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


#include <PDataStd_Relation.ixx>

//=======================================================================
//function : PDataStd_Relation
//purpose  : 
//=======================================================================

PDataStd_Relation::PDataStd_Relation()
{
}

//=======================================================================
//function : PDataStd_Relation
//purpose  : 
//=======================================================================

PDataStd_Relation::PDataStd_Relation(const Handle(PCollection_HExtendedString)& name)
{
  SetName(name);
}

//=======================================================================
//function : GetName
//purpose  : 
//=======================================================================

Handle(PCollection_HExtendedString) PDataStd_Relation::GetName() const
{
  return myName;
}

//=======================================================================
//function : SetName
//purpose  : 
//=======================================================================

void PDataStd_Relation::SetName(const Handle(PCollection_HExtendedString)& name)
{
  myName = name;
}


//=======================================================================
//function : GetVariables
//purpose  : 
//=======================================================================

Handle(PDF_HAttributeArray1) PDataStd_Relation::GetVariables() const
{ 
  return myVariables; 
}


//=======================================================================
//function : SetVariables
//purpose  : 
//=======================================================================

void PDataStd_Relation::SetVariables(const Handle(PDF_HAttributeArray1)& vars) 
{ 
  myVariables = vars; 
}
