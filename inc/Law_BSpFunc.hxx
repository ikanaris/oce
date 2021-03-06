// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Law_BSpFunc_HeaderFile
#define _Law_BSpFunc_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Law_BSpFunc_HeaderFile
#include <Handle_Law_BSpFunc.hxx>
#endif

#ifndef _Handle_Law_BSpline_HeaderFile
#include <Handle_Law_BSpline.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Law_Function_HeaderFile
#include <Law_Function.hxx>
#endif
#ifndef _GeomAbs_Shape_HeaderFile
#include <GeomAbs_Shape.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_Law_Function_HeaderFile
#include <Handle_Law_Function.hxx>
#endif
class Law_BSpline;
class Standard_OutOfRange;
class TColStd_Array1OfReal;
class Law_Function;


//! Law Function based on a BSpline curve 1d.  Package <br>
//!          methods and classes are implemented in package Law <br>
//!          to    construct  the  basis    curve with  several <br>
//!          constraints. <br>
class Law_BSpFunc : public Law_Function {

public:

  
  Standard_EXPORT   Law_BSpFunc();
  
  Standard_EXPORT   Law_BSpFunc(const Handle(Law_BSpline)& C,const Standard_Real First,const Standard_Real Last);
  
  Standard_EXPORT     GeomAbs_Shape Continuity() const;
  //! Returns  the number  of  intervals for  continuity <br>
//!          <S>. May be one if Continuity(me) >= <S> <br>
  Standard_EXPORT     Standard_Integer NbIntervals(const GeomAbs_Shape S) const;
  //! Stores in <T> the  parameters bounding the intervals <br>
//!          of continuity <S>. <br>
//! <br>
//!          The array must provide  enough room to  accomodate <br>
//!          for the parameters. i.e. T.Length() > NbIntervals() <br>
  Standard_EXPORT     void Intervals(TColStd_Array1OfReal& T,const GeomAbs_Shape S) const;
  
  Standard_EXPORT     Standard_Real Value(const Standard_Real X) ;
  
  Standard_EXPORT     void D1(const Standard_Real X,Standard_Real& F,Standard_Real& D) ;
  
  Standard_EXPORT     void D2(const Standard_Real X,Standard_Real& F,Standard_Real& D,Standard_Real& D2) ;
  //!   Returns a  law equivalent of  <me>  between <br>
//!        parameters <First>  and <Last>. <Tol>  is used  to <br>
//!        test for 3d points confusion. <br>
//!        It is usfule to determines the derivatives <br>
//!        in these values <First> and <Last> if <br>
//!        the Law is not Cn. <br>
  Standard_EXPORT     Handle_Law_Function Trim(const Standard_Real PFirst,const Standard_Real PLast,const Standard_Real Tol) const;
  
  Standard_EXPORT     void Bounds(Standard_Real& PFirst,Standard_Real& PLast) ;
  
  Standard_EXPORT     Handle_Law_BSpline Curve() const;
  
  Standard_EXPORT     void SetCurve(const Handle(Law_BSpline)& C) ;




  DEFINE_STANDARD_RTTI(Law_BSpFunc)

protected:




private: 


Handle_Law_BSpline curv;
Standard_Real first;
Standard_Real last;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
