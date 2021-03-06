// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _XmlMDF_DataMapNodeOfTypeADriverMap_HeaderFile
#define _XmlMDF_DataMapNodeOfTypeADriverMap_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_XmlMDF_DataMapNodeOfTypeADriverMap_HeaderFile
#include <Handle_XmlMDF_DataMapNodeOfTypeADriverMap.hxx>
#endif

#ifndef _Handle_Standard_Type_HeaderFile
#include <Handle_Standard_Type.hxx>
#endif
#ifndef _Handle_XmlMDF_ADriver_HeaderFile
#include <Handle_XmlMDF_ADriver.hxx>
#endif
#ifndef _TCollection_MapNode_HeaderFile
#include <TCollection_MapNode.hxx>
#endif
#ifndef _TCollection_MapNodePtr_HeaderFile
#include <TCollection_MapNodePtr.hxx>
#endif
class Standard_Type;
class XmlMDF_ADriver;
class TColStd_MapTransientHasher;
class XmlMDF_TypeADriverMap;
class XmlMDF_DataMapIteratorOfTypeADriverMap;



class XmlMDF_DataMapNodeOfTypeADriverMap : public TCollection_MapNode {

public:

  
      XmlMDF_DataMapNodeOfTypeADriverMap(const Handle(Standard_Type)& K,const Handle(XmlMDF_ADriver)& I,const TCollection_MapNodePtr& n);
  
        Handle_Standard_Type& Key() const;
  
        Handle_XmlMDF_ADriver& Value() const;




  DEFINE_STANDARD_RTTI(XmlMDF_DataMapNodeOfTypeADriverMap)

protected:




private: 


Handle_Standard_Type myKey;
Handle_XmlMDF_ADriver myValue;


};

#define TheKey Handle_Standard_Type
#define TheKey_hxx <Standard_Type.hxx>
#define TheItem Handle_XmlMDF_ADriver
#define TheItem_hxx <XmlMDF_ADriver.hxx>
#define Hasher TColStd_MapTransientHasher
#define Hasher_hxx <TColStd_MapTransientHasher.hxx>
#define TCollection_DataMapNode XmlMDF_DataMapNodeOfTypeADriverMap
#define TCollection_DataMapNode_hxx <XmlMDF_DataMapNodeOfTypeADriverMap.hxx>
#define TCollection_DataMapIterator XmlMDF_DataMapIteratorOfTypeADriverMap
#define TCollection_DataMapIterator_hxx <XmlMDF_DataMapIteratorOfTypeADriverMap.hxx>
#define Handle_TCollection_DataMapNode Handle_XmlMDF_DataMapNodeOfTypeADriverMap
#define TCollection_DataMapNode_Type_() XmlMDF_DataMapNodeOfTypeADriverMap_Type_()
#define TCollection_DataMap XmlMDF_TypeADriverMap
#define TCollection_DataMap_hxx <XmlMDF_TypeADriverMap.hxx>

#include <TCollection_DataMapNode.lxx>

#undef TheKey
#undef TheKey_hxx
#undef TheItem
#undef TheItem_hxx
#undef Hasher
#undef Hasher_hxx
#undef TCollection_DataMapNode
#undef TCollection_DataMapNode_hxx
#undef TCollection_DataMapIterator
#undef TCollection_DataMapIterator_hxx
#undef Handle_TCollection_DataMapNode
#undef TCollection_DataMapNode_Type_
#undef TCollection_DataMap
#undef TCollection_DataMap_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif
