// Created on: 1993-06-17
// Created by: Martine LANGLOIS
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


#include <GeomToStep_MakeSphericalSurface.ixx>
#include <GeomToStep_MakeAxis2Placement3d.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <StdFail_NotDone.hxx>
#include <Geom_SphericalSurface.hxx>
#include <StepGeom_SphericalSurface.hxx>
#include <TCollection_HAsciiString.hxx>
#include <UnitsMethods.hxx>

//=============================================================================
// Creation d' une conical_surface de prostep a partir d' une SphericalSurface
// de Geom
//=============================================================================

GeomToStep_MakeSphericalSurface::GeomToStep_MakeSphericalSurface
  ( const Handle(Geom_SphericalSurface)& S )
	
{
  Handle(StepGeom_SphericalSurface) Surf;
  Handle(StepGeom_Axis2Placement3d) aPosition;
  Standard_Real aRadius;
  
  GeomToStep_MakeAxis2Placement3d MkAxis2(S->Position());
  aPosition = MkAxis2.Value();
  aRadius = S->Radius();
  Surf = new StepGeom_SphericalSurface;
  Handle(TCollection_HAsciiString) name = new TCollection_HAsciiString("");
  Surf->Init(name, aPosition, aRadius/UnitsMethods::LengthFactor());
  theSphericalSurface = Surf;
  done = Standard_True;
}

//=============================================================================
// renvoi des valeurs
//=============================================================================

const Handle(StepGeom_SphericalSurface) &
      GeomToStep_MakeSphericalSurface::Value() const
{
  StdFail_NotDone_Raise_if(!done == Standard_True,"");
  return theSphericalSurface;
}
