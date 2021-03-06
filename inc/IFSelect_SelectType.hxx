// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IFSelect_SelectType_HeaderFile
#define _IFSelect_SelectType_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_IFSelect_SelectType_HeaderFile
#include <Handle_IFSelect_SelectType.hxx>
#endif

#ifndef _Handle_Standard_Type_HeaderFile
#include <Handle_Standard_Type.hxx>
#endif
#ifndef _IFSelect_SelectAnyType_HeaderFile
#include <IFSelect_SelectAnyType.hxx>
#endif
class Standard_Type;
class TCollection_AsciiString;


//! A SelectType keeps or rejects Entities of which the Type <br>
//!           is Kind of a given Cdl Type <br>
class IFSelect_SelectType : public IFSelect_SelectAnyType {

public:

  //! Creates a SelectType. Default is no filter <br>
  Standard_EXPORT   IFSelect_SelectType();
  //! Creates a SelectType for a given Type <br>
  Standard_EXPORT   IFSelect_SelectType(const Handle(Standard_Type)& atype);
  //! Sets a TYpe for filter <br>
  Standard_EXPORT     void SetType(const Handle(Standard_Type)& atype) ;
  //! Returns the Type to be matched for select : this is the type <br>
//!           given at instantiation time <br>
  Standard_EXPORT     Handle_Standard_Type TypeForMatch() const;
  //! Returns a text defining the criterium. <br>
//!           (should by gotten from Type of Entity used for instantiation) <br>
  Standard_EXPORT     TCollection_AsciiString ExtractLabel() const;




  DEFINE_STANDARD_RTTI(IFSelect_SelectType)

protected:




private: 


Handle_Standard_Type thetype;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
