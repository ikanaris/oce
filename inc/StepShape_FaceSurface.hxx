// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepShape_FaceSurface_HeaderFile
#define _StepShape_FaceSurface_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepShape_FaceSurface_HeaderFile
#include <Handle_StepShape_FaceSurface.hxx>
#endif

#ifndef _Handle_StepGeom_Surface_HeaderFile
#include <Handle_StepGeom_Surface.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _StepShape_Face_HeaderFile
#include <StepShape_Face.hxx>
#endif
#ifndef _Handle_TCollection_HAsciiString_HeaderFile
#include <Handle_TCollection_HAsciiString.hxx>
#endif
#ifndef _Handle_StepShape_HArray1OfFaceBound_HeaderFile
#include <Handle_StepShape_HArray1OfFaceBound.hxx>
#endif
class StepGeom_Surface;
class TCollection_HAsciiString;
class StepShape_HArray1OfFaceBound;



class StepShape_FaceSurface : public StepShape_Face {

public:

  //! Returns a FaceSurface <br>
  Standard_EXPORT   StepShape_FaceSurface();
  
  Standard_EXPORT   virtual  void Init(const Handle(TCollection_HAsciiString)& aName,const Handle(StepShape_HArray1OfFaceBound)& aBounds) ;
  
  Standard_EXPORT   virtual  void Init(const Handle(TCollection_HAsciiString)& aName,const Handle(StepShape_HArray1OfFaceBound)& aBounds,const Handle(StepGeom_Surface)& aFaceGeometry,const Standard_Boolean aSameSense) ;
  
  Standard_EXPORT     void SetFaceGeometry(const Handle(StepGeom_Surface)& aFaceGeometry) ;
  
  Standard_EXPORT     Handle_StepGeom_Surface FaceGeometry() const;
  
  Standard_EXPORT     void SetSameSense(const Standard_Boolean aSameSense) ;
  
  Standard_EXPORT     Standard_Boolean SameSense() const;




  DEFINE_STANDARD_RTTI(StepShape_FaceSurface)

protected:




private: 


Handle_StepGeom_Surface faceGeometry;
Standard_Boolean sameSense;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
