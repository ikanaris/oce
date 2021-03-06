// Created on: 2008-01-20
// Created by: Alexander A. BORODIN
// Copyright (c) 2008-2012 OPEN CASCADE SAS
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


// Updated:

#include <OSD_SystemFont.ixx>
#include <OSD_Path.hxx>
#include <TCollection_HAsciiString.hxx>

#include <stdio.h>

OSD_SystemFont::OSD_SystemFont():
MyFontName(),
MyFontAspect(OSD_FA_Undefined),
MyFaceSize(-1),
MyVerification(Standard_False)
{
}

OSD_SystemFont::OSD_SystemFont( const Handle(TCollection_HAsciiString)& FontName,
                                const OSD_FontAspect FontAspect,
                                const Handle(TCollection_HAsciiString)& FilePath ):
MyFontName(FontName),
MyFontAspect(FontAspect),
MyFaceSize(-1),
MyFilePath(FilePath),
MyVerification(Standard_True)
{

}

OSD_SystemFont::OSD_SystemFont( const Handle(TCollection_HAsciiString)& XLFD,
                                const Handle(TCollection_HAsciiString)& FilePath) :
MyFontAspect(OSD_FA_Undefined),
MyFilePath(FilePath)
{
  MyVerification = Standard_True;
  if ( XLFD.IsNull() )
  {
    MyVerification=Standard_False;
    printf("NULL XLFD handler \n");
  }
  if ( XLFD->IsEmpty() )
  {
    MyVerification=Standard_False;
    printf("EMPTY XLFD handler \n");
  }

  if(MyVerification)
  {
    MyFontName = XLFD->Token( "-", 2 );
    TCollection_AsciiString str( XLFD->ToCString() );

    if ( str.Search( "-0-0-0-0-" ) >=0 )
      MyFaceSize = -1;
    else
      //TODO catch exeption
      MyFaceSize = Standard_Integer (str.Token( "-", 7 ).RealValue());

    //detect aspect
    if ( str.Token("-", 3).IsEqual( "bold" ) )
      MyFontAspect = OSD_FA_Bold;
    else if ( str.Token("-", 3).IsEqual( "medium" ) ||
      str.Token("-", 3).IsEqual( "normal" ) )
      MyFontAspect = OSD_FA_Regular;

    if ( MyFontAspect != OSD_FA_Undefined && 
      ( str.Token("-",4 ).IsEqual( "i" ) || str.Token("-",4 ).IsEqual( "o" ) ) ) 
    {
      if ( MyFontAspect == OSD_FA_Bold )
        MyFontAspect = OSD_FA_BoldItalic;
      else
        MyFontAspect = OSD_FA_Italic;
    }
  }
}

Standard_Boolean OSD_SystemFont::IsValid() const{
  if ( !MyVerification)
    return Standard_False;

  if ( MyFontAspect == OSD_FA_Undefined )
    return Standard_False;

  if ( MyFontName->IsEmpty() || !MyFontName->IsAscii() )
    return Standard_False;

  OSD_Path path;  
  return path.IsValid( MyFilePath->String() );
}

Handle(TCollection_HAsciiString) OSD_SystemFont::FontPath() const{
  return MyFilePath;
}

Handle(TCollection_HAsciiString) OSD_SystemFont::FontName() const{
  return MyFontName;
}

OSD_FontAspect OSD_SystemFont::FontAspect() const{
  return MyFontAspect;
}

Standard_Integer OSD_SystemFont::FontHeight() const {
  return MyFaceSize;
}
