// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _STEPConstruct_DataMapNodeOfDataMapOfPointTransient_HeaderFile
#define _STEPConstruct_DataMapNodeOfDataMapOfPointTransient_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_STEPConstruct_DataMapNodeOfDataMapOfPointTransient_HeaderFile
#include <Handle_STEPConstruct_DataMapNodeOfDataMapOfPointTransient.hxx>
#endif

#ifndef _gp_Pnt_HeaderFile
#include <gp_Pnt.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _TCollection_MapNode_HeaderFile
#include <TCollection_MapNode.hxx>
#endif
#ifndef _TCollection_MapNodePtr_HeaderFile
#include <TCollection_MapNodePtr.hxx>
#endif
class Standard_Transient;
class gp_Pnt;
class STEPConstruct_PointHasher;
class STEPConstruct_DataMapOfPointTransient;
class STEPConstruct_DataMapIteratorOfDataMapOfPointTransient;



class STEPConstruct_DataMapNodeOfDataMapOfPointTransient : public TCollection_MapNode {

public:

  
      STEPConstruct_DataMapNodeOfDataMapOfPointTransient(const gp_Pnt& K,const Handle(Standard_Transient)& I,const TCollection_MapNodePtr& n);
  
        gp_Pnt& Key() const;
  
        Handle_Standard_Transient& Value() const;




  DEFINE_STANDARD_RTTI(STEPConstruct_DataMapNodeOfDataMapOfPointTransient)

protected:




private: 


gp_Pnt myKey;
Handle_Standard_Transient myValue;


};

#define TheKey gp_Pnt
#define TheKey_hxx <gp_Pnt.hxx>
#define TheItem Handle_Standard_Transient
#define TheItem_hxx <Standard_Transient.hxx>
#define Hasher STEPConstruct_PointHasher
#define Hasher_hxx <STEPConstruct_PointHasher.hxx>
#define TCollection_DataMapNode STEPConstruct_DataMapNodeOfDataMapOfPointTransient
#define TCollection_DataMapNode_hxx <STEPConstruct_DataMapNodeOfDataMapOfPointTransient.hxx>
#define TCollection_DataMapIterator STEPConstruct_DataMapIteratorOfDataMapOfPointTransient
#define TCollection_DataMapIterator_hxx <STEPConstruct_DataMapIteratorOfDataMapOfPointTransient.hxx>
#define Handle_TCollection_DataMapNode Handle_STEPConstruct_DataMapNodeOfDataMapOfPointTransient
#define TCollection_DataMapNode_Type_() STEPConstruct_DataMapNodeOfDataMapOfPointTransient_Type_()
#define TCollection_DataMap STEPConstruct_DataMapOfPointTransient
#define TCollection_DataMap_hxx <STEPConstruct_DataMapOfPointTransient.hxx>

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
