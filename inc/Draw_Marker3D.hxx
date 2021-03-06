// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Draw_Marker3D_HeaderFile
#define _Draw_Marker3D_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Draw_Marker3D_HeaderFile
#include <Handle_Draw_Marker3D.hxx>
#endif

#ifndef _gp_Pnt_HeaderFile
#include <gp_Pnt.hxx>
#endif
#ifndef _Draw_Color_HeaderFile
#include <Draw_Color.hxx>
#endif
#ifndef _Draw_MarkerShape_HeaderFile
#include <Draw_MarkerShape.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Draw_Drawable3D_HeaderFile
#include <Draw_Drawable3D.hxx>
#endif
class gp_Pnt;
class Draw_Color;
class Draw_Display;



class Draw_Marker3D : public Draw_Drawable3D {

public:

  
  Standard_EXPORT   Draw_Marker3D(const gp_Pnt& P,const Draw_MarkerShape T,const Draw_Color& C,const Standard_Integer ISize = 5);
  
  Standard_EXPORT   Draw_Marker3D(const gp_Pnt& P,const Draw_MarkerShape T,const Draw_Color& C,const Standard_Real RSize);
  //! myPos field <br>
  Standard_EXPORT     gp_Pnt& ChangePos() ;
  
  Standard_EXPORT     void DrawOn(Draw_Display& dis) const;
  //! Returs always false <br>
  Standard_EXPORT   virtual  Standard_Boolean PickReject(const Standard_Real X,const Standard_Real Y,const Standard_Real Prec) const;




  DEFINE_STANDARD_RTTI(Draw_Marker3D)

protected:




private: 


gp_Pnt myPos;
Draw_Color myCol;
Draw_MarkerShape myTyp;
Standard_Integer mySiz;
Standard_Real myRSiz;
Standard_Boolean myIsRSiz;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
