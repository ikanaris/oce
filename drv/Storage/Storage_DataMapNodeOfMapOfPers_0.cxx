// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#include <Storage_DataMapNodeOfMapOfPers.hxx>

#ifndef _Standard_Type_HeaderFile
#include <Standard_Type.hxx>
#endif

#ifndef _Storage_Root_HeaderFile
#include <Storage_Root.hxx>
#endif
#ifndef _TCollection_AsciiString_HeaderFile
#include <TCollection_AsciiString.hxx>
#endif
#ifndef _Storage_MapOfPers_HeaderFile
#include <Storage_MapOfPers.hxx>
#endif
#ifndef _Storage_DataMapIteratorOfMapOfPers_HeaderFile
#include <Storage_DataMapIteratorOfMapOfPers.hxx>
#endif

 


IMPLEMENT_STANDARD_TYPE(Storage_DataMapNodeOfMapOfPers)
IMPLEMENT_STANDARD_SUPERTYPE_ARRAY()
  STANDARD_TYPE(TCollection_MapNode),
  STANDARD_TYPE(MMgt_TShared),
  STANDARD_TYPE(Standard_Transient),

IMPLEMENT_STANDARD_SUPERTYPE_ARRAY_END()
IMPLEMENT_STANDARD_TYPE_END(Storage_DataMapNodeOfMapOfPers)


IMPLEMENT_DOWNCAST(Storage_DataMapNodeOfMapOfPers,Standard_Transient)
IMPLEMENT_STANDARD_RTTI(Storage_DataMapNodeOfMapOfPers)


#define TheKey TCollection_AsciiString
#define TheKey_hxx <TCollection_AsciiString.hxx>
#define TheItem Handle_Storage_Root
#define TheItem_hxx <Storage_Root.hxx>
#define Hasher TCollection_AsciiString
#define Hasher_hxx <TCollection_AsciiString.hxx>
#define TCollection_DataMapNode Storage_DataMapNodeOfMapOfPers
#define TCollection_DataMapNode_hxx <Storage_DataMapNodeOfMapOfPers.hxx>
#define TCollection_DataMapIterator Storage_DataMapIteratorOfMapOfPers
#define TCollection_DataMapIterator_hxx <Storage_DataMapIteratorOfMapOfPers.hxx>
#define Handle_TCollection_DataMapNode Handle_Storage_DataMapNodeOfMapOfPers
#define TCollection_DataMapNode_Type_() Storage_DataMapNodeOfMapOfPers_Type_()
#define TCollection_DataMap Storage_MapOfPers
#define TCollection_DataMap_hxx <Storage_MapOfPers.hxx>
#include <TCollection_DataMapNode.gxx>

