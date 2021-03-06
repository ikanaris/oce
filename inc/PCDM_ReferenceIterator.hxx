// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _PCDM_ReferenceIterator_HeaderFile
#define _PCDM_ReferenceIterator_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_PCDM_ReferenceIterator_HeaderFile
#include <Handle_PCDM_ReferenceIterator.hxx>
#endif

#ifndef _PCDM_SequenceOfReference_HeaderFile
#include <PCDM_SequenceOfReference.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_CDM_MessageDriver_HeaderFile
#include <Handle_CDM_MessageDriver.hxx>
#endif
#ifndef _Standard_Transient_HeaderFile
#include <Standard_Transient.hxx>
#endif
#ifndef _Handle_CDM_Document_HeaderFile
#include <Handle_CDM_Document.hxx>
#endif
#ifndef _Handle_CDM_MetaData_HeaderFile
#include <Handle_CDM_MetaData.hxx>
#endif
#ifndef _Handle_CDM_Application_HeaderFile
#include <Handle_CDM_Application.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class CDM_MessageDriver;
class CDM_Document;
class CDM_MetaData;
class CDM_Application;



class PCDM_ReferenceIterator : public Standard_Transient {

public:

  //!  Warning! The constructor does not initialization. <br>
  Standard_EXPORT   PCDM_ReferenceIterator(const Handle(CDM_MessageDriver)& theMessageDriver);
  
  Standard_EXPORT     void LoadReferences(const Handle(CDM_Document)& aDocument,const Handle(CDM_MetaData)& aMetaData,const Handle(CDM_Application)& anApplication,const Standard_Boolean UseStorageConfiguration) ;
  
  Standard_EXPORT   virtual  void Init(const Handle(CDM_MetaData)& aMetaData) ;




  DEFINE_STANDARD_RTTI(PCDM_ReferenceIterator)

protected:




private: 

  
  Standard_EXPORT   virtual  Standard_Boolean More() const;
  
  Standard_EXPORT   virtual  void Next() ;
  
  Standard_EXPORT   virtual  Handle_CDM_MetaData MetaData(const Standard_Boolean UseStorageConfiguration) const;
  
  Standard_EXPORT   virtual  Standard_Integer ReferenceIdentifier() const;
  //! returns the version of the document in the reference <br>
  Standard_EXPORT   virtual  Standard_Integer DocumentVersion() const;

PCDM_SequenceOfReference myReferences;
Standard_Integer myIterator;
Handle_CDM_MessageDriver myMessageDriver;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
