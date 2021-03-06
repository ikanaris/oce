// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepAlgoAPI_Fuse_HeaderFile
#define _BRepAlgoAPI_Fuse_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _BRepAlgoAPI_BooleanOperation_HeaderFile
#include <BRepAlgoAPI_BooleanOperation.hxx>
#endif
class TopoDS_Shape;
class BOPTools_DSFiller;


//!  The class Fuse provides a <br>
//! Boolean fusion operation on a pair of arguments (Boolean Union). <br>
//! The class Fuse provides a framework for: <br>
//!   -       Defining the construction of a fused shape; <br>
//!   -       Implementing the building algorithm <br>
//!   -       Consulting the result. <br>
class BRepAlgoAPI_Fuse  : public BRepAlgoAPI_BooleanOperation {
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

  //! Constructs a fuse of shapes aS1 and aS2. <br>
  Standard_EXPORT   BRepAlgoAPI_Fuse(const TopoDS_Shape& S1,const TopoDS_Shape& S2);
  //! Constructs a new shape that is a fuse of shapes aS1 and aS2 using aDSFiller. <br>
  Standard_EXPORT   BRepAlgoAPI_Fuse(const TopoDS_Shape& S1,const TopoDS_Shape& S2,const BOPTools_DSFiller& aDSF);





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
