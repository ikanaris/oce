// Created on: 1993-10-15
// Created by: Remi LEQUETTE
// Copyright (c) 1993-1999 Matra Datavision
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


#include <BRepAlgoAPI_Common.ixx>

#include <BRepAlgoAPI_BooleanOperation.hxx>
#include <BOP_Operation.hxx>

//=======================================================================
//function : BRepAlgoAPI_Common
//purpose  : 
//=======================================================================
BRepAlgoAPI_Common::BRepAlgoAPI_Common(const TopoDS_Shape& S1, 
					 const TopoDS_Shape& S2)
: BRepAlgoAPI_BooleanOperation(S1, S2, BOP_COMMON)
{
  BRepAlgoAPI_BooleanOperation* pBO=
    (BRepAlgoAPI_BooleanOperation*) (void*) this;
  pBO->Build();
}
//=======================================================================
//function : BRepAlgoAPI_Common
//purpose  : 
//=======================================================================
  BRepAlgoAPI_Common::BRepAlgoAPI_Common(const TopoDS_Shape& S1, 
					 const TopoDS_Shape& S2,
					 const BOPTools_DSFiller& aDSF)
: BRepAlgoAPI_BooleanOperation(S1, S2, aDSF, BOP_COMMON)
{
  BRepAlgoAPI_BooleanOperation* pBO=
    (BRepAlgoAPI_BooleanOperation*) (void*) this;
  pBO->Build();
}



