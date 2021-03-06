// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Interface_DataMapNodeOfDataMapOfTransientInteger_HeaderFile
#define _Interface_DataMapNodeOfDataMapOfTransientInteger_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Interface_DataMapNodeOfDataMapOfTransientInteger_HeaderFile
#include <Handle_Interface_DataMapNodeOfDataMapOfTransientInteger.hxx>
#endif

#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _TCollection_MapNode_HeaderFile
#include <TCollection_MapNode.hxx>
#endif
#ifndef _TCollection_MapNodePtr_HeaderFile
#include <TCollection_MapNodePtr.hxx>
#endif
class Standard_Transient;
class TColStd_MapTransientHasher;
class Interface_DataMapOfTransientInteger;
class Interface_DataMapIteratorOfDataMapOfTransientInteger;



class Interface_DataMapNodeOfDataMapOfTransientInteger : public TCollection_MapNode {

public:

  
      Interface_DataMapNodeOfDataMapOfTransientInteger(const Handle(Standard_Transient)& K,const Standard_Integer& I,const TCollection_MapNodePtr& n);
  
        Handle_Standard_Transient& Key() const;
  
        Standard_Integer& Value() const;




  DEFINE_STANDARD_RTTI(Interface_DataMapNodeOfDataMapOfTransientInteger)

protected:




private: 


Handle_Standard_Transient myKey;
Standard_Integer myValue;


};

#define TheKey Handle_Standard_Transient
#define TheKey_hxx <Standard_Transient.hxx>
#define TheItem Standard_Integer
#define TheItem_hxx <Standard_Integer.hxx>
#define Hasher TColStd_MapTransientHasher
#define Hasher_hxx <TColStd_MapTransientHasher.hxx>
#define TCollection_DataMapNode Interface_DataMapNodeOfDataMapOfTransientInteger
#define TCollection_DataMapNode_hxx <Interface_DataMapNodeOfDataMapOfTransientInteger.hxx>
#define TCollection_DataMapIterator Interface_DataMapIteratorOfDataMapOfTransientInteger
#define TCollection_DataMapIterator_hxx <Interface_DataMapIteratorOfDataMapOfTransientInteger.hxx>
#define Handle_TCollection_DataMapNode Handle_Interface_DataMapNodeOfDataMapOfTransientInteger
#define TCollection_DataMapNode_Type_() Interface_DataMapNodeOfDataMapOfTransientInteger_Type_()
#define TCollection_DataMap Interface_DataMapOfTransientInteger
#define TCollection_DataMap_hxx <Interface_DataMapOfTransientInteger.hxx>

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
