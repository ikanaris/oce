// Created on: 2002-12-12
// Created by: data exchange team
// Copyright (c) 2002-2012 OPEN CASCADE SAS
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

// Generator:	ExpToCas (EXPRESS -> CASCADE/XSTEP Translator) V1.2

#include <RWStepFEA_RWCurveElementLocation.ixx>

//=======================================================================
//function : RWStepFEA_RWCurveElementLocation
//purpose  : 
//=======================================================================

RWStepFEA_RWCurveElementLocation::RWStepFEA_RWCurveElementLocation ()
{
}

//=======================================================================
//function : ReadStep
//purpose  : 
//=======================================================================

void RWStepFEA_RWCurveElementLocation::ReadStep (const Handle(StepData_StepReaderData)& data,
                                                 const Standard_Integer num,
                                                 Handle(Interface_Check)& ach,
                                                 const Handle(StepFEA_CurveElementLocation) &ent) const
{
  // Check number of parameters
  if ( ! data->CheckNbParams(num,1,ach,"curve_element_location") ) return;

  // Own fields of CurveElementLocation

  Handle(StepFEA_FeaParametricPoint) aCoordinate;
  data->ReadEntity (num, 1, "coordinate", ach, STANDARD_TYPE(StepFEA_FeaParametricPoint), aCoordinate);

  // Initialize entity
  ent->Init(aCoordinate);
}

//=======================================================================
//function : WriteStep
//purpose  : 
//=======================================================================

void RWStepFEA_RWCurveElementLocation::WriteStep (StepData_StepWriter& SW,
                                                  const Handle(StepFEA_CurveElementLocation) &ent) const
{

  // Own fields of CurveElementLocation

  SW.Send (ent->Coordinate());
}

//=======================================================================
//function : Share
//purpose  : 
//=======================================================================

void RWStepFEA_RWCurveElementLocation::Share (const Handle(StepFEA_CurveElementLocation) &ent,
                                              Interface_EntityIterator& iter) const
{

  // Own fields of CurveElementLocation

  iter.AddItem (ent->Coordinate());
}
