// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IntPolyh_Edge_HeaderFile
#define _IntPolyh_Edge_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif



class IntPolyh_Edge  {
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

  
  Standard_EXPORT   IntPolyh_Edge();
  
  Standard_EXPORT   IntPolyh_Edge(const Standard_Integer i1,const Standard_Integer i2,const Standard_Integer i3,const Standard_Integer i4);
  
  Standard_EXPORT     Standard_Integer FirstPoint() const;
  
  Standard_EXPORT     Standard_Integer SecondPoint() const;
  
  Standard_EXPORT     Standard_Integer FirstTriangle() const;
  
  Standard_EXPORT     Standard_Integer SecondTriangle() const;
  
  Standard_EXPORT     Standard_Integer AnalysisFlag() const;
  
  Standard_EXPORT     void SetFirstPoint(const Standard_Integer v) ;
  
  Standard_EXPORT     void SetSecondPoint(const Standard_Integer v) ;
  
  Standard_EXPORT     void SetFirstTriangle(const Standard_Integer v) ;
  
  Standard_EXPORT     void SetSecondTriangle(const Standard_Integer v) ;
  
  Standard_EXPORT     void SetAnalysisFlag(const Standard_Integer v) ;
  
  Standard_EXPORT     void Dump(const Standard_Integer v) const;





protected:





private:



Standard_Integer p1;
Standard_Integer p2;
Standard_Integer t1;
Standard_Integer t2;
Standard_Integer ia;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
