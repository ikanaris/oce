// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Graphic3d_ListNodeOfSetListOfSetOfGroup_HeaderFile
#define _Graphic3d_ListNodeOfSetListOfSetOfGroup_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Graphic3d_ListNodeOfSetListOfSetOfGroup_HeaderFile
#include <Handle_Graphic3d_ListNodeOfSetListOfSetOfGroup.hxx>
#endif

#ifndef _Handle_Graphic3d_Group_HeaderFile
#include <Handle_Graphic3d_Group.hxx>
#endif
#ifndef _TCollection_MapNode_HeaderFile
#include <TCollection_MapNode.hxx>
#endif
#ifndef _TCollection_MapNodePtr_HeaderFile
#include <TCollection_MapNodePtr.hxx>
#endif
class Graphic3d_Group;
class Graphic3d_SetListOfSetOfGroup;
class Graphic3d_ListIteratorOfSetListOfSetOfGroup;



class Graphic3d_ListNodeOfSetListOfSetOfGroup : public TCollection_MapNode {

public:

  
      Graphic3d_ListNodeOfSetListOfSetOfGroup(const Handle(Graphic3d_Group)& I,const TCollection_MapNodePtr& n);
  
        Handle_Graphic3d_Group& Value() const;




  DEFINE_STANDARD_RTTI(Graphic3d_ListNodeOfSetListOfSetOfGroup)

protected:




private: 


Handle_Graphic3d_Group myValue;


};

#define Item Handle_Graphic3d_Group
#define Item_hxx <Graphic3d_Group.hxx>
#define TCollection_ListNode Graphic3d_ListNodeOfSetListOfSetOfGroup
#define TCollection_ListNode_hxx <Graphic3d_ListNodeOfSetListOfSetOfGroup.hxx>
#define TCollection_ListIterator Graphic3d_ListIteratorOfSetListOfSetOfGroup
#define TCollection_ListIterator_hxx <Graphic3d_ListIteratorOfSetListOfSetOfGroup.hxx>
#define Handle_TCollection_ListNode Handle_Graphic3d_ListNodeOfSetListOfSetOfGroup
#define TCollection_ListNode_Type_() Graphic3d_ListNodeOfSetListOfSetOfGroup_Type_()
#define TCollection_List Graphic3d_SetListOfSetOfGroup
#define TCollection_List_hxx <Graphic3d_SetListOfSetOfGroup.hxx>

#include <TCollection_ListNode.lxx>

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
