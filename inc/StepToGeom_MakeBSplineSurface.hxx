// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepToGeom_MakeBSplineSurface_HeaderFile
#define _StepToGeom_MakeBSplineSurface_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_StepGeom_BSplineSurface_HeaderFile
#include <Handle_StepGeom_BSplineSurface.hxx>
#endif
#ifndef _Handle_Geom_BSplineSurface_HeaderFile
#include <Handle_Geom_BSplineSurface.hxx>
#endif
class StepGeom_BSplineSurface;
class Geom_BSplineSurface;


//! This class implements the mapping between classes <br>
//!          BSplineSurface from StepGeom <br>
//!          and class BSplineSurface from Geom <br>
class StepToGeom_MakeBSplineSurface  {
public:

  void* operator new(size_t,void* anAddress) 
  {
    return anAddress;
  }
  void* operator new(size_t size) 
  {
    return Standard::Allocate(size); 
  }
  void  operator delete(void *anAddress) 
  {
    if (anAddress) Standard::Free((Standard_Address&)anAddress); 
  }

  
  Standard_EXPORT   static  Standard_Boolean Convert(const Handle(StepGeom_BSplineSurface)& SS,Handle(Geom_BSplineSurface)& CS) ;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
