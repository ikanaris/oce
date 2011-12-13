// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepMesh_DataMapIteratorOfDataMapOfIntegerListOfInteger_HeaderFile
#define _BRepMesh_DataMapIteratorOfDataMapOfIntegerListOfInteger_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BasicMapIterator_HeaderFile
#include <TCollection_BasicMapIterator.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _BRepMesh_ListOfInteger_HeaderFile
#include <BRepMesh_ListOfInteger.hxx>
#endif
#ifndef _Handle_BRepMesh_DataMapNodeOfDataMapOfIntegerListOfInteger_HeaderFile
#include <Handle_BRepMesh_DataMapNodeOfDataMapOfIntegerListOfInteger.hxx>
#endif
class Standard_NoSuchObject;
class TColStd_MapIntegerHasher;
class BRepMesh_DataMapOfIntegerListOfInteger;
class BRepMesh_DataMapNodeOfDataMapOfIntegerListOfInteger;



class BRepMesh_DataMapIteratorOfDataMapOfIntegerListOfInteger  : public TCollection_BasicMapIterator {
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

  
  Standard_EXPORT   BRepMesh_DataMapIteratorOfDataMapOfIntegerListOfInteger();
  
  Standard_EXPORT   BRepMesh_DataMapIteratorOfDataMapOfIntegerListOfInteger(const BRepMesh_DataMapOfIntegerListOfInteger& aMap);
  
  Standard_EXPORT     void Initialize(const BRepMesh_DataMapOfIntegerListOfInteger& aMap) ;
  
  Standard_EXPORT    const Standard_Integer& Key() const;
  
  Standard_EXPORT    const BRepMesh_ListOfInteger& Value() const;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
