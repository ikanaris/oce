// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _VrmlConverter_Drawer_HeaderFile
#define _VrmlConverter_Drawer_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_VrmlConverter_Drawer_HeaderFile
#include <Handle_VrmlConverter_Drawer.hxx>
#endif

#ifndef _Handle_VrmlConverter_IsoAspect_HeaderFile
#include <Handle_VrmlConverter_IsoAspect.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_VrmlConverter_LineAspect_HeaderFile
#include <Handle_VrmlConverter_LineAspect.hxx>
#endif
#ifndef _Handle_VrmlConverter_ShadingAspect_HeaderFile
#include <Handle_VrmlConverter_ShadingAspect.hxx>
#endif
#ifndef _Quantity_Length_HeaderFile
#include <Quantity_Length.hxx>
#endif
#ifndef _Aspect_TypeOfDeflection_HeaderFile
#include <Aspect_TypeOfDeflection.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Handle_VrmlConverter_PointAspect_HeaderFile
#include <Handle_VrmlConverter_PointAspect.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
class VrmlConverter_IsoAspect;
class VrmlConverter_LineAspect;
class VrmlConverter_ShadingAspect;
class VrmlConverter_PointAspect;


//! qualifies the aspect properties for <br>
//!          the VRML conversation of a specific kind of object. <br>
//!          This includes for example color, maximal chordial deviation, etc... <br>
class VrmlConverter_Drawer : public MMgt_TShared {

public:

  
  Standard_EXPORT   VrmlConverter_Drawer();
  //! by default: TOD_Relative; however, except for the shapes, <br>
//!          the drawing  will be made using the absolute deviation. <br>
//! <br>
  Standard_EXPORT     void SetTypeOfDeflection(const Aspect_TypeOfDeflection aTypeOfDeflection) ;
  
  Standard_EXPORT     Aspect_TypeOfDeflection TypeOfDeflection() const;
  //! Defines the maximal chordial deviation when drawing any curve; <br>
//!          If this  value is  one  of  the  obvious  parameters  of  methods, <br>
//!          current  value  from  Drawer won't be used. <br>
//!          This value is used by: <br>
//! <br>
//!                   VrmlConverter_DeflectionCurve <br>
//!                   VrmlConverter_WFDeflectionRestrictedFace <br>
//!                   VrmlConverter_WFDeflectionShape <br>
  Standard_EXPORT     void SetMaximalChordialDeviation(const Quantity_Length aChordialDeviation) ;
  //! returns the maximal chordial deviation. <br>
//!          Default value: 0.1 <br>
  Standard_EXPORT     Quantity_Length MaximalChordialDeviation() const;
  //! default 0.001 <br>
  Standard_EXPORT     void SetDeviationCoefficient(const Standard_Real aCoefficient) ;
  
  Standard_EXPORT     Standard_Real DeviationCoefficient() const;
  //! default: 17 points. <br>
//!          Defines the Discretisation  (myNbPoints) when drawing any curve; <br>
//!          If this  value is  one  of  the  obvious  parameters  of  methods, <br>
//!          current  value  from  Drawer won't be used. <br>
//!          This value is used by: <br>
//! <br>
//!                   VrmlConverter_Curve <br>
//!                   VrmlConverter_WFRestrictedFace <br>
//!                   VrmlConverter_WFShape <br>
  Standard_EXPORT     void SetDiscretisation(const Standard_Integer d) ;
  
  Standard_EXPORT     Standard_Integer Discretisation() const;
  //! defines the maximum value allowed  for the first and last <br>
//!          parameters of an infinite curve. <br>
//!          Default value: 500. <br>
//!                   VrmlConverter_Curve <br>
//!                   VrmlConverter_WFRestrictedFace <br>
//!                   VrmlConverter_WFShape <br>
  Standard_EXPORT     void SetMaximalParameterValue(const Standard_Real Value) ;
  
  Standard_EXPORT     Standard_Real MaximalParameterValue() const;
  //! enables the drawing of isos on planes. <br>
//!          By default there are no isos on planes. <br>
  Standard_EXPORT     void SetIsoOnPlane(const Standard_Boolean OnOff) ;
  //! returns True if the drawing of isos on planes is enabled. <br>
  Standard_EXPORT     Standard_Boolean IsoOnPlane() const;
  //! Defines the attributes which are used when drawing an <br>
//!          U isoparametric curve of a face. Defines the number <br>
//!          of U isoparametric curves to be drawn for a single face. <br>
//!          The default values are the same default values from Vrml package. <br>
//! <br>
//!          These attributes are used by the following algorithms: <br>
//!          VrmlConverter_WFRestrictedFace <br>
//!          VrmlConverter_WFDeflectionRestrictedFace <br>
  Standard_EXPORT     Handle_VrmlConverter_IsoAspect UIsoAspect() ;
  
  Standard_EXPORT     void SetUIsoAspect(const Handle(VrmlConverter_IsoAspect)& anAspect) ;
  //! Defines the attributes which are used when drawing an <br>
//!          V isoparametric curve of a face. Defines the number <br>
//!          of V isoparametric curves to be drawn for a single face. <br>
//!          The default values are the same default values from Vrml package. <br>
//! <br>
//!          These attributes are used by the following algorithms: <br>
//!          VrmlConverter_WFRestrictedFace <br>
//!          VrmlConverter_WFDeflectionRestrictedFace <br>
  Standard_EXPORT     Handle_VrmlConverter_IsoAspect VIsoAspect() ;
  
  Standard_EXPORT     void SetVIsoAspect(const Handle(VrmlConverter_IsoAspect)& anAspect) ;
  
//!          The default values are the same default values from Vrml package. <br>
//!          These attributes are used by the following algorithms: <br>
//!          VrmlConverter_WFShape <br>
//!          VrmlConverter_WFDeflectionShape <br>
  Standard_EXPORT     Handle_VrmlConverter_LineAspect FreeBoundaryAspect() ;
  
  Standard_EXPORT     void SetFreeBoundaryAspect(const Handle(VrmlConverter_LineAspect)& anAspect) ;
  //! enables the drawing the free boundaries <br>
//!          By default the free boundaries  are drawn. <br>
  Standard_EXPORT     void SetFreeBoundaryDraw(const Standard_Boolean OnOff) ;
  //! returns True if the drawing of the free boundaries is enabled. <br>
  Standard_EXPORT     Standard_Boolean FreeBoundaryDraw() const;
  
//!          The default values are the same default values from Vrml package. <br>
//!          These attributes are used by the following algorithms: <br>
//!          VrmlConverter_WFShape <br>
//!          VrmlConverter_WFDeflectionShape <br>
  Standard_EXPORT     Handle_VrmlConverter_LineAspect WireAspect() ;
  
  Standard_EXPORT     void SetWireAspect(const Handle(VrmlConverter_LineAspect)& anAspect) ;
  //! enables the drawing the wire <br>
//!          By default the wire  are drawn. <br>
  Standard_EXPORT     void SetWireDraw(const Standard_Boolean OnOff) ;
  //! returns True if the drawing of the wire is enabled. <br>
  Standard_EXPORT     Standard_Boolean WireDraw() const;
  
//!          The default values are the same default values from Vrml package. <br>
//!          These attributes are used by the following algorithms: <br>
//!          VrmlConverter_WFShape <br>
//!          VrmlConverter_WFDeflectionShape <br>
  Standard_EXPORT     Handle_VrmlConverter_LineAspect UnFreeBoundaryAspect() ;
  
  Standard_EXPORT     void SetUnFreeBoundaryAspect(const Handle(VrmlConverter_LineAspect)& anAspect) ;
  //! enables the drawing the unfree boundaries <br>
//!          By default the unfree boundaries  are drawn. <br>
  Standard_EXPORT     void SetUnFreeBoundaryDraw(const Standard_Boolean OnOff) ;
  //! returns True if the drawing of the unfree boundaries is enabled. <br>
  Standard_EXPORT     Standard_Boolean UnFreeBoundaryDraw() const;
  
//!          The default values are the same default values from Vrml package. <br>
  Standard_EXPORT     Handle_VrmlConverter_LineAspect LineAspect() ;
  
  Standard_EXPORT     void SetLineAspect(const Handle(VrmlConverter_LineAspect)& anAspect) ;
  
  Standard_EXPORT     Handle_VrmlConverter_PointAspect PointAspect() ;
  
  Standard_EXPORT     void SetPointAspect(const Handle(VrmlConverter_PointAspect)& anAspect) ;
  
//!          The default values are the same default values from Vrml package. <br>
  Standard_EXPORT     Handle_VrmlConverter_ShadingAspect ShadingAspect() ;
  
  Standard_EXPORT     void SetShadingAspect(const Handle(VrmlConverter_ShadingAspect)& anAspect) ;
  //! returns Standard_True if the hidden lines are to be drawn. <br>
//!          By default the hidden lines are not drawn. <br>
  Standard_EXPORT     Standard_Boolean DrawHiddenLine() const;
  //! sets DrawHiddenLine  =  Standard_True  -  the hidden lines are drawn. <br>
  Standard_EXPORT     void EnableDrawHiddenLine() ;
  //! sets DrawHiddenLine  =  Standard_False  -  the hidden lines are not drawn. <br>
  Standard_EXPORT     void DisableDrawHiddenLine() ;
  //! returns LineAspect  for  the hidden lines. <br>
//!          The default values are the same default values from Vrml package. <br>
  Standard_EXPORT     Handle_VrmlConverter_LineAspect HiddenLineAspect() ;
  //! sets LineAspect  for  the hidden lines. <br>
  Standard_EXPORT     void SetHiddenLineAspect(const Handle(VrmlConverter_LineAspect)& anAspect) ;
  //! returns LineAspect  for  the seen lines. <br>
//!          The default values are the same default values from Vrml package. <br>
  Standard_EXPORT     Handle_VrmlConverter_LineAspect SeenLineAspect() ;
  //! sets LineAspect  for  the seen lines. <br>
  Standard_EXPORT     void SetSeenLineAspect(const Handle(VrmlConverter_LineAspect)& anAspect) ;




  DEFINE_STANDARD_RTTI(VrmlConverter_Drawer)

protected:




private: 


Handle_VrmlConverter_IsoAspect myUIsoAspect;
Handle_VrmlConverter_IsoAspect myVIsoAspect;
Standard_Integer myNbPoints;
Standard_Boolean myIsoOnPlane;
Handle_VrmlConverter_LineAspect myFreeBoundaryAspect;
Standard_Boolean myFreeBoundaryDraw;
Handle_VrmlConverter_LineAspect myUnFreeBoundaryAspect;
Standard_Boolean myUnFreeBoundaryDraw;
Handle_VrmlConverter_LineAspect myWireAspect;
Standard_Boolean myWireDraw;
Handle_VrmlConverter_LineAspect myLineAspect;
Handle_VrmlConverter_ShadingAspect myShadingAspect;
Quantity_Length myChordialDeviation;
Aspect_TypeOfDeflection myTypeOfDeflection;
Standard_Real myMaximalParameterValue;
Standard_Real myDeviationCoefficient;
Handle_VrmlConverter_PointAspect myPointAspect;
Standard_Boolean myDrawHiddenLine;
Handle_VrmlConverter_LineAspect myHiddenLineAspect;
Handle_VrmlConverter_LineAspect mySeenLineAspect;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif