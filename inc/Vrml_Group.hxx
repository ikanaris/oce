// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Vrml_Group_HeaderFile
#define _Vrml_Group_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_OStream_HeaderFile
#include <Standard_OStream.hxx>
#endif


//! defines a Group node of VRML specifying group properties. <br>
//!  This node defines the base class for all group nodes. Group is a node that <br>
//!  contains an ordered list of child nodes. This node is simply a container for <br>
//!  the child nodes and does not alter the traversal state in any way. <br>
//!  During traversal, state accumulated for a child is passed on to each successive <br>
//!  child and then to the parents of the group (Group does not push or pop traversal <br>
//!  state as separator does). <br>
class Vrml_Group  {
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

  
  Standard_EXPORT   Vrml_Group();
  
  Standard_EXPORT     Standard_OStream& Print(Standard_OStream& anOStream) ;





protected:





private:



Standard_Boolean myFlagPrint;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
