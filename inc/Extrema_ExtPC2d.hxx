// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Extrema_ExtPC2d_HeaderFile
#define _Extrema_ExtPC2d_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _gp_Pnt2d_HeaderFile
#include <gp_Pnt2d.hxx>
#endif
#ifndef _Extrema_ExtPElC2d_HeaderFile
#include <Extrema_ExtPElC2d.hxx>
#endif
#ifndef _Extrema_SequenceOfPOnCurv2d_HeaderFile
#include <Extrema_SequenceOfPOnCurv2d.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Extrema_EPCOfExtPC2d_HeaderFile
#include <Extrema_EPCOfExtPC2d.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _GeomAbs_CurveType_HeaderFile
#include <GeomAbs_CurveType.hxx>
#endif
#ifndef _TColStd_SequenceOfBoolean_HeaderFile
#include <TColStd_SequenceOfBoolean.hxx>
#endif
#ifndef _TColStd_SequenceOfReal_HeaderFile
#include <TColStd_SequenceOfReal.hxx>
#endif
class StdFail_NotDone;
class Standard_OutOfRange;
class Standard_TypeMismatch;
class Adaptor2d_Curve2d;
class Extrema_Curve2dTool;
class Extrema_ExtPElC2d;
class gp_Pnt2d;
class gp_Vec2d;
class Extrema_POnCurv2d;
class Extrema_SequenceOfPOnCurv2d;
class Extrema_EPCOfExtPC2d;
class Extrema_PCFOfEPCOfExtPC2d;



class Extrema_ExtPC2d  {
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

  
  Standard_EXPORT   Extrema_ExtPC2d();
  
  Standard_EXPORT   Extrema_ExtPC2d(const gp_Pnt2d& P,const Adaptor2d_Curve2d& C,const Standard_Real Uinf,const Standard_Real Usup,const Standard_Real TolF = 1.0e-10);
  
  Standard_EXPORT   Extrema_ExtPC2d(const gp_Pnt2d& P,const Adaptor2d_Curve2d& C,const Standard_Real TolF = 1.0e-10);
  
  Standard_EXPORT     void Initialize(const Adaptor2d_Curve2d& C,const Standard_Real Uinf,const Standard_Real Usup,const Standard_Real TolF = 1.0e-10) ;
  
  Standard_EXPORT     void Perform(const gp_Pnt2d& P) ;
  
  Standard_EXPORT     Standard_Boolean IsDone() const;
  
  Standard_EXPORT     Standard_Real SquareDistance(const Standard_Integer N) const;
  
  Standard_EXPORT     Standard_Integer NbExt() const;
  
  Standard_EXPORT     Standard_Boolean IsMin(const Standard_Integer N) const;
  
  Standard_EXPORT     Extrema_POnCurv2d Point(const Standard_Integer N) const;
  
  Standard_EXPORT     void TrimmedSquareDistances(Standard_Real& dist1,Standard_Real& dist2,gp_Pnt2d& P1,gp_Pnt2d& P2) const;





protected:

  
  Standard_EXPORT     void IntervalPerform(const gp_Pnt2d& P) ;




private:



Standard_Address myC;
gp_Pnt2d Pf;
gp_Pnt2d Pl;
Extrema_ExtPElC2d myExtPElC;
Extrema_SequenceOfPOnCurv2d mypoint;
Standard_Boolean mydone;
Standard_Real mydist1;
Standard_Real mydist2;
Extrema_EPCOfExtPC2d myExtPC;
Standard_Real mytolu;
Standard_Real mytolf;
Standard_Integer mysample;
Standard_Real myintuinf;
Standard_Real myintusup;
Standard_Real myuinf;
Standard_Real myusup;
GeomAbs_CurveType type;
TColStd_SequenceOfBoolean myismin;
TColStd_SequenceOfReal mySqDist;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
