// Created on: 2011-03-18
// Created by: Anton POLETAEV
// Copyright (c) 2011-2012 OPEN CASCADE SAS
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


#include <OpenGl_GlCore11.hxx>
#include <OpenGl_ResourceTexture.hxx>

IMPLEMENT_STANDARD_HANDLE (OpenGl_ResourceTexture, OpenGl_Resource)
IMPLEMENT_STANDARD_RTTIEXT(OpenGl_ResourceTexture, OpenGl_Resource)

//=======================================================================
//function : Clean
//purpose  : free OpenGl memory allocated for texture resource
//=======================================================================
void OpenGl_ResourceTexture::Clean (const Handle(OpenGl_Context)& theGlContext)
{
  glDeleteTextures (1, &myId);
}
