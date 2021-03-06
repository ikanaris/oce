// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _DsgPrs_LengthPresentation_HeaderFile
#define _DsgPrs_LengthPresentation_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Handle_Prs3d_Presentation_HeaderFile
#include <Handle_Prs3d_Presentation.hxx>
#endif
#ifndef _Handle_Prs3d_Drawer_HeaderFile
#include <Handle_Prs3d_Drawer.hxx>
#endif
#ifndef _DsgPrs_ArrowSide_HeaderFile
#include <DsgPrs_ArrowSide.hxx>
#endif
#ifndef _Handle_Geom_Surface_HeaderFile
#include <Handle_Geom_Surface.hxx>
#endif
class Prs3d_Presentation;
class Prs3d_Drawer;
class TCollection_ExtendedString;
class gp_Pnt;
class gp_Dir;
class gp_Pln;
class Geom_Surface;


//! Framework for displaying lengths. <br>
//! The length displayed is indicated by line segments <br>
//! and text alone or by a combination of line segment, <br>
//! text and   arrows at either or both of its ends. <br>
class DsgPrs_LengthPresentation  {
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

  //! Draws a line segment representing a length in the <br>
//! display aPresentation. <br>
//! This segment joins the points AttachmentPoint1 and <br>
//! AttachmentPoint2, along the direction aDirection. <br>
//! The text aText will be displayed at the offset point OffsetPoint. <br>
//! The line and text attributes are specified by the <br>
//! attribute manager aDrawer. <br>
  Standard_EXPORT   static  void Add(const Handle(Prs3d_Presentation)& aPresentation,const Handle(Prs3d_Drawer)& aDrawer,const TCollection_ExtendedString& aText,const gp_Pnt& AttachmentPoint1,const gp_Pnt& AttachmentPoint2,const gp_Dir& aDirection,const gp_Pnt& OffsetPoint) ;
  //! Draws a line segment representing a length in the <br>
//! display aPresentation. <br>
//! This segment joins the points AttachmentPoint1 and <br>
//! AttachmentPoint2, along the direction aDirection. <br>
//! The text aText will be displayed at the offset point <br>
//! OffsetPoint. The value of the enumeration ArrowSide <br>
//! controls whether arrows will be displayed at either or <br>
//! both ends of the length. <br>
//! The line, text and arrow attributes are specified by the <br>
//! attribute manager aDrawer. <br>
  Standard_EXPORT   static  void Add(const Handle(Prs3d_Presentation)& aPresentation,const Handle(Prs3d_Drawer)& aDrawer,const TCollection_ExtendedString& aText,const gp_Pnt& AttachmentPoint1,const gp_Pnt& AttachmentPoint2,const gp_Dir& aDirection,const gp_Pnt& OffsetPoint,const DsgPrs_ArrowSide ArrowSide) ;
  //! Draws a line segment representing a length in the <br>
//! display aPresentation. <br>
//! This segment joins the points AttachmentPoint1 and <br>
//! AttachmentPoint2, along the direction aDirection. <br>
//! The text aText will be displayed at the offset point <br>
//! OffsetPoint. The value of the enumeration ArrowSide <br>
//! controls whether arrows will be displayed at either or <br>
//! both ends of the length. <br>
//! The plane PlaneOfFaces is used if length is null. <br>
//! The line, text and arrow attributes are specified by the <br>
//! attribute manager aDrawer. <br>
  Standard_EXPORT   static  void Add(const Handle(Prs3d_Presentation)& aPresentation,const Handle(Prs3d_Drawer)& aDrawer,const TCollection_ExtendedString& aText,const gp_Pnt& AttachmentPoint1,const gp_Pnt& AttachmentPoint2,const gp_Pln& PlaneOfFaces,const gp_Dir& aDirection,const gp_Pnt& OffsetPoint,const DsgPrs_ArrowSide ArrowSide) ;
  //! Draws a line segment representing a length in the <br>
//! display aPresentation. <br>
//! This segment joins the points AttachmentPoint1 and <br>
//! AttachmentPoint2, along the direction <br>
//! aDirection.   AttachmentPoint2 lies on the curvilinear <br>
//! faces SecondSurf. The text aText will be displayed at <br>
//! the offset point OffsetPoint. The value of the <br>
//! enumeration ArrowSide controls whether arrows will <br>
//! be displayed at either or both ends of the length. <br>
//! The line, text and arrow attributes are specified by the <br>
//! attribute manager aDrawer. <br>
  Standard_EXPORT   static  void Add(const Handle(Prs3d_Presentation)& aPresentation,const Handle(Prs3d_Drawer)& aDrawer,const TCollection_ExtendedString& aText,const Handle(Geom_Surface)& SecondSurf,const gp_Pnt& AttachmentPoint1,const gp_Pnt& AttachmentPoint2,const gp_Dir& aDirection,const gp_Pnt& OffsetPoint,const DsgPrs_ArrowSide ArrowSide) ;
  //! Draws a line segment representing a length in the <br>
//! display aPresentation. <br>
//! This segment joins the points AttachmentPoint1 and <br>
//! AttachmentPoint2, along the direction aDirection. <br>
//! The value of the enumeration ArrowSide controls <br>
//! whether arrows will be displayed at either or both ends of the length. <br>
//! The line and arrow attributes are specified by the attribute manager aDrawer. <br>
  Standard_EXPORT   static  void Add(const Handle(Prs3d_Presentation)& aPresentation,const Handle(Prs3d_Drawer)& aDrawer,const gp_Pnt& Pt1,const gp_Pnt& Pt2,const DsgPrs_ArrowSide ArrowSide) ;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
