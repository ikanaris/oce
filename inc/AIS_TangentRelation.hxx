// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _AIS_TangentRelation_HeaderFile
#define _AIS_TangentRelation_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_AIS_TangentRelation_HeaderFile
#include <Handle_AIS_TangentRelation.hxx>
#endif

#ifndef _gp_Pnt_HeaderFile
#include <gp_Pnt.hxx>
#endif
#ifndef _gp_Dir_HeaderFile
#include <gp_Dir.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _AIS_Relation_HeaderFile
#include <AIS_Relation.hxx>
#endif
#ifndef _Handle_Geom_Plane_HeaderFile
#include <Handle_Geom_Plane.hxx>
#endif
#ifndef _Handle_PrsMgr_PresentationManager3d_HeaderFile
#include <Handle_PrsMgr_PresentationManager3d.hxx>
#endif
#ifndef _Handle_Prs3d_Presentation_HeaderFile
#include <Handle_Prs3d_Presentation.hxx>
#endif
#ifndef _Handle_Prs3d_Projector_HeaderFile
#include <Handle_Prs3d_Projector.hxx>
#endif
#ifndef _Handle_PrsMgr_PresentationManager2d_HeaderFile
#include <Handle_PrsMgr_PresentationManager2d.hxx>
#endif
#ifndef _Handle_Graphic2d_GraphicObject_HeaderFile
#include <Handle_Graphic2d_GraphicObject.hxx>
#endif
#ifndef _Handle_Geom_Transformation_HeaderFile
#include <Handle_Geom_Transformation.hxx>
#endif
#ifndef _Handle_SelectMgr_Selection_HeaderFile
#include <Handle_SelectMgr_Selection.hxx>
#endif
class TopoDS_Shape;
class Geom_Plane;
class PrsMgr_PresentationManager3d;
class Prs3d_Presentation;
class Prs3d_Projector;
class PrsMgr_PresentationManager2d;
class Graphic2d_GraphicObject;
class Geom_Transformation;
class SelectMgr_Selection;


//! A framework to display tangency constraints between <br>
//! two or more Interactive Objects of the datum type. <br>
//! The datums are normally faces or edges. <br>
class AIS_TangentRelation : public AIS_Relation {

public:

  //!  TwoFacesTangent or TwoEdgesTangent relation <br>//! Constructs an object to display tangency constraints. <br>
//! This object is defined by the first shape aFShape, the <br>
//! second shape aSShape, the plane aPlane and the index anExternRef. <br>
//! aPlane serves as an optional axis. <br>
//! anExternRef set to 0 indicates that there is no relation. <br>
  Standard_EXPORT   AIS_TangentRelation(const TopoDS_Shape& aFShape,const TopoDS_Shape& aSShape,const Handle(Geom_Plane)& aPlane,const Standard_Integer anExternRef = 0);
  //! Returns the external reference for tangency. <br>
//! The values are as follows: <br>
//! -   0 - there is no connection; <br>
//! -   1 - there is a connection to the first shape; <br>
//! -   2 - there is a connection to the second shape. <br>
//!   This reference is defined at construction time. <br>
  Standard_EXPORT     Standard_Integer ExternRef() ;
  //! Sets the external reference for tangency, aRef. <br>
//! The values are as follows: <br>
//! -   0 - there is no connection; <br>
//! -   1 - there is a connection to the first shape; <br>
//! -   2 - there is a connection to the second shape. <br>
//! This reference is initially defined at construction time. <br>
  Standard_EXPORT     void SetExternRef(const Standard_Integer aRef) ;
  //! computes the presentation according to a point of view <br>
//!          given by <aProjector>. <br>
//!          To be Used when the associated degenerated Presentations <br>
//!          have been transformed by <aTrsf> which is not a Pure <br>
//!          Translation. The HLR Prs can't be deducted automatically <br>
//!          WARNING :<aTrsf> must be applied <br>
//!           to the object to display before computation  !!! <br>
  Standard_EXPORT   virtual  void Compute(const Handle(Prs3d_Projector)& aProjector,const Handle(Geom_Transformation)& aTrsf,const Handle(Prs3d_Presentation)& aPresentation) ;




  DEFINE_STANDARD_RTTI(AIS_TangentRelation)

protected:




private: 

  
  Standard_EXPORT     void Compute(const Handle(PrsMgr_PresentationManager3d)& aPresentationManager,const Handle(Prs3d_Presentation)& aPresentation,const Standard_Integer aMode = 0) ;
  
  Standard_EXPORT     void Compute(const Handle(Prs3d_Projector)& aProjector,const Handle(Prs3d_Presentation)& aPresentation) ;
  
  Standard_EXPORT     void Compute(const Handle(PrsMgr_PresentationManager2d)& aPresentationManager,const Handle(Graphic2d_GraphicObject)& aPresentation,const Standard_Integer aMode = 0) ;
  
  Standard_EXPORT     void ComputeSelection(const Handle(SelectMgr_Selection)& aSelection,const Standard_Integer aMode) ;
  
  Standard_EXPORT     void ComputeTwoFacesTangent(const Handle(Prs3d_Presentation)& aPresentation) ;
  
  Standard_EXPORT     void ComputeTwoEdgesTangent(const Handle(Prs3d_Presentation)& aPresentation) ;

gp_Pnt myAttach;
gp_Dir myDir;
Standard_Real myLength;
Standard_Integer myExternRef;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
