// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Bisector_Inter_HeaderFile
#define _Bisector_Inter_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _IntRes2d_Intersection_HeaderFile
#include <IntRes2d_Intersection.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_Geom2d_Curve_HeaderFile
#include <Handle_Geom2d_Curve.hxx>
#endif
#ifndef _Handle_Bisector_BisecCC_HeaderFile
#include <Handle_Bisector_BisecCC.hxx>
#endif
#ifndef _Handle_Geom2d_Line_HeaderFile
#include <Handle_Geom2d_Line.hxx>
#endif
class Standard_ConstructionError;
class Bisector_Bisec;
class IntRes2d_Domain;
class Geom2d_Curve;
class Bisector_BisecCC;
class Geom2d_Line;


//! Intersection between two <Bisec> from Bisector. <br>
class Bisector_Inter  : public IntRes2d_Intersection {
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

  
  Standard_EXPORT   Bisector_Inter();
  //! Intersection between 2 curves. <br>
//!          C1 separates the element A and B. <br>
//!          C2 separates the elements C et D. <br>
//!          If B an C have the same geometry. <ComunElement> <br>
//!          Has to be True. <br>
//!          It Permits an optimiztion of the computation. <br>
  Standard_EXPORT   Bisector_Inter(const Bisector_Bisec& C1,const IntRes2d_Domain& D1,const Bisector_Bisec& C2,const IntRes2d_Domain& D2,const Standard_Real TolConf,const Standard_Real Tol,const Standard_Boolean ComunElement);
  //! Intersection between 2 curves. <br>
//!          C1 separates the element A and B. <br>
//!          C2 separates the elements C et D. <br>
//!          If B an C have the same geometry. <ComunElement> <br>
//!          Has to be True. <br>
//!          It Permits an optimiztion of the computation. <br>
  Standard_EXPORT     void Perform(const Bisector_Bisec& C1,const IntRes2d_Domain& D1,const Bisector_Bisec& C2,const IntRes2d_Domain& D2,const Standard_Real TolConf,const Standard_Real Tol,const Standard_Boolean ComunElement) ;





protected:





private:

  //! Intersection between 2 curves. <br>
  Standard_EXPORT     void SinglePerform(const Handle(Geom2d_Curve)& C1,const IntRes2d_Domain& D1,const Handle(Geom2d_Curve)& C2,const IntRes2d_Domain& D2,const Standard_Real TolConf,const Standard_Real Tol,const Standard_Boolean ComunElement) ;
  
  Standard_EXPORT     void NeighbourPerform(const Handle(Bisector_BisecCC)& C1,const IntRes2d_Domain& D1,const Handle(Bisector_BisecCC)& C2,const IntRes2d_Domain& D2,const Standard_Real Tol) ;
  
  Standard_EXPORT     void TestBound(const Handle(Geom2d_Line)& C1,const IntRes2d_Domain& D1,const Handle(Geom2d_Curve)& C2,const IntRes2d_Domain& D2,const Standard_Real Tol,const Standard_Boolean Reverse) ;




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
