// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepAP214_AutoDesignSecurityClassificationAssignment_HeaderFile
#define _StepAP214_AutoDesignSecurityClassificationAssignment_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepAP214_AutoDesignSecurityClassificationAssignment_HeaderFile
#include <Handle_StepAP214_AutoDesignSecurityClassificationAssignment.hxx>
#endif

#ifndef _Handle_StepBasic_HArray1OfApproval_HeaderFile
#include <Handle_StepBasic_HArray1OfApproval.hxx>
#endif
#ifndef _StepBasic_SecurityClassificationAssignment_HeaderFile
#include <StepBasic_SecurityClassificationAssignment.hxx>
#endif
#ifndef _Handle_StepBasic_SecurityClassification_HeaderFile
#include <Handle_StepBasic_SecurityClassification.hxx>
#endif
#ifndef _Handle_StepBasic_Approval_HeaderFile
#include <Handle_StepBasic_Approval.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class StepBasic_HArray1OfApproval;
class StepBasic_SecurityClassification;
class StepBasic_Approval;



class StepAP214_AutoDesignSecurityClassificationAssignment : public StepBasic_SecurityClassificationAssignment {

public:

  //! Returns a AutoDesignSecurityClassificationAssignment <br>
  Standard_EXPORT   StepAP214_AutoDesignSecurityClassificationAssignment();
  
  Standard_EXPORT   virtual  void Init(const Handle(StepBasic_SecurityClassification)& aAssignedSecurityClassification) ;
  
  Standard_EXPORT   virtual  void Init(const Handle(StepBasic_SecurityClassification)& aAssignedSecurityClassification,const Handle(StepBasic_HArray1OfApproval)& aItems) ;
  
  Standard_EXPORT     void SetItems(const Handle(StepBasic_HArray1OfApproval)& aItems) ;
  
  Standard_EXPORT     Handle_StepBasic_HArray1OfApproval Items() const;
  
  Standard_EXPORT     Handle_StepBasic_Approval ItemsValue(const Standard_Integer num) const;
  
  Standard_EXPORT     Standard_Integer NbItems() const;




  DEFINE_STANDARD_RTTI(StepAP214_AutoDesignSecurityClassificationAssignment)

protected:




private: 


Handle_StepBasic_HArray1OfApproval items;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
