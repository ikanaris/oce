// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ExprIntrp_StackIteratorOfStackOfGeneralFunction_HeaderFile
#define _ExprIntrp_StackIteratorOfStackOfGeneralFunction_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Handle_Expr_GeneralFunction_HeaderFile
#include <Handle_Expr_GeneralFunction.hxx>
#endif
#ifndef _Handle_ExprIntrp_StackNodeOfStackOfGeneralFunction_HeaderFile
#include <Handle_ExprIntrp_StackNodeOfStackOfGeneralFunction.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_NoSuchObject;
class Expr_GeneralFunction;
class ExprIntrp_StackOfGeneralFunction;
class ExprIntrp_StackNodeOfStackOfGeneralFunction;



class ExprIntrp_StackIteratorOfStackOfGeneralFunction  {
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

  
  Standard_EXPORT   ExprIntrp_StackIteratorOfStackOfGeneralFunction();
  
  Standard_EXPORT   ExprIntrp_StackIteratorOfStackOfGeneralFunction(const ExprIntrp_StackOfGeneralFunction& S);
  
  Standard_EXPORT     void Initialize(const ExprIntrp_StackOfGeneralFunction& S) ;
  
        Standard_Boolean More() const;
  
  Standard_EXPORT     void Next() ;
  
  Standard_EXPORT    const Handle_Expr_GeneralFunction& Value() const;





protected:





private:



Standard_Address current;


};

#define Item Handle_Expr_GeneralFunction
#define Item_hxx <Expr_GeneralFunction.hxx>
#define TCollection_StackNode ExprIntrp_StackNodeOfStackOfGeneralFunction
#define TCollection_StackNode_hxx <ExprIntrp_StackNodeOfStackOfGeneralFunction.hxx>
#define TCollection_StackIterator ExprIntrp_StackIteratorOfStackOfGeneralFunction
#define TCollection_StackIterator_hxx <ExprIntrp_StackIteratorOfStackOfGeneralFunction.hxx>
#define Handle_TCollection_StackNode Handle_ExprIntrp_StackNodeOfStackOfGeneralFunction
#define TCollection_StackNode_Type_() ExprIntrp_StackNodeOfStackOfGeneralFunction_Type_()
#define TCollection_Stack ExprIntrp_StackOfGeneralFunction
#define TCollection_Stack_hxx <ExprIntrp_StackOfGeneralFunction.hxx>

#include <TCollection_StackIterator.lxx>

#undef Item
#undef Item_hxx
#undef TCollection_StackNode
#undef TCollection_StackNode_hxx
#undef TCollection_StackIterator
#undef TCollection_StackIterator_hxx
#undef Handle_TCollection_StackNode
#undef TCollection_StackNode_Type_
#undef TCollection_Stack
#undef TCollection_Stack_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif