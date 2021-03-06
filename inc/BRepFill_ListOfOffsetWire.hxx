// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepFill_ListOfOffsetWire_HeaderFile
#define _BRepFill_ListOfOffsetWire_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Handle_BRepFill_ListNodeOfListOfOffsetWire_HeaderFile
#include <Handle_BRepFill_ListNodeOfListOfOffsetWire.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_NoSuchObject;
class BRepFill_ListIteratorOfListOfOffsetWire;
class BRepFill_OffsetWire;
class BRepFill_ListNodeOfListOfOffsetWire;



class BRepFill_ListOfOffsetWire  {
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

  
  Standard_EXPORT   BRepFill_ListOfOffsetWire();
  
  Standard_EXPORT     void Assign(const BRepFill_ListOfOffsetWire& Other) ;
    void operator=(const BRepFill_ListOfOffsetWire& Other) 
{
  Assign(Other);
}
  
  Standard_EXPORT     Standard_Integer Extent() const;
  
  Standard_EXPORT     void Clear() ;
~BRepFill_ListOfOffsetWire()
{
  Clear();
}
  
        Standard_Boolean IsEmpty() const;
  
  Standard_EXPORT     void Prepend(const BRepFill_OffsetWire& I) ;
  
  Standard_EXPORT     void Prepend(const BRepFill_OffsetWire& I,BRepFill_ListIteratorOfListOfOffsetWire& theIt) ;
  
  Standard_EXPORT     void Prepend(BRepFill_ListOfOffsetWire& Other) ;
  
  Standard_EXPORT     void Append(const BRepFill_OffsetWire& I) ;
  
  Standard_EXPORT     void Append(const BRepFill_OffsetWire& I,BRepFill_ListIteratorOfListOfOffsetWire& theIt) ;
  
  Standard_EXPORT     void Append(BRepFill_ListOfOffsetWire& Other) ;
  
  Standard_EXPORT     BRepFill_OffsetWire& First() const;
  
  Standard_EXPORT     BRepFill_OffsetWire& Last() const;
  
  Standard_EXPORT     void RemoveFirst() ;
  
  Standard_EXPORT     void Remove(BRepFill_ListIteratorOfListOfOffsetWire& It) ;
  
  Standard_EXPORT     void InsertBefore(const BRepFill_OffsetWire& I,BRepFill_ListIteratorOfListOfOffsetWire& It) ;
  
  Standard_EXPORT     void InsertBefore(BRepFill_ListOfOffsetWire& Other,BRepFill_ListIteratorOfListOfOffsetWire& It) ;
  
  Standard_EXPORT     void InsertAfter(const BRepFill_OffsetWire& I,BRepFill_ListIteratorOfListOfOffsetWire& It) ;
  
  Standard_EXPORT     void InsertAfter(BRepFill_ListOfOffsetWire& Other,BRepFill_ListIteratorOfListOfOffsetWire& It) ;


friend class BRepFill_ListIteratorOfListOfOffsetWire;



protected:





private:

  
  Standard_EXPORT   BRepFill_ListOfOffsetWire(const BRepFill_ListOfOffsetWire& Other);


Standard_Address myFirst;
Standard_Address myLast;


};

#define Item BRepFill_OffsetWire
#define Item_hxx <BRepFill_OffsetWire.hxx>
#define TCollection_ListNode BRepFill_ListNodeOfListOfOffsetWire
#define TCollection_ListNode_hxx <BRepFill_ListNodeOfListOfOffsetWire.hxx>
#define TCollection_ListIterator BRepFill_ListIteratorOfListOfOffsetWire
#define TCollection_ListIterator_hxx <BRepFill_ListIteratorOfListOfOffsetWire.hxx>
#define Handle_TCollection_ListNode Handle_BRepFill_ListNodeOfListOfOffsetWire
#define TCollection_ListNode_Type_() BRepFill_ListNodeOfListOfOffsetWire_Type_()
#define TCollection_List BRepFill_ListOfOffsetWire
#define TCollection_List_hxx <BRepFill_ListOfOffsetWire.hxx>

#include <TCollection_List.lxx>

#undef Item
#undef Item_hxx
#undef TCollection_ListNode
#undef TCollection_ListNode_hxx
#undef TCollection_ListIterator
#undef TCollection_ListIterator_hxx
#undef Handle_TCollection_ListNode
#undef TCollection_ListNode_Type_
#undef TCollection_List
#undef TCollection_List_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif
