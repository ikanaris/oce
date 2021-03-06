// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _STEPConstruct_ContextTool_HeaderFile
#define _STEPConstruct_ContextTool_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TColStd_SequenceOfInteger_HeaderFile
#include <TColStd_SequenceOfInteger.hxx>
#endif
#ifndef _Handle_StepBasic_ApplicationProtocolDefinition_HeaderFile
#include <Handle_StepBasic_ApplicationProtocolDefinition.hxx>
#endif
#ifndef _STEPConstruct_AP203Context_HeaderFile
#include <STEPConstruct_AP203Context.hxx>
#endif
#ifndef _Handle_StepGeom_Axis2Placement3d_HeaderFile
#include <Handle_StepGeom_Axis2Placement3d.hxx>
#endif
#ifndef _Handle_StepData_StepModel_HeaderFile
#include <Handle_StepData_StepModel.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_TCollection_HAsciiString_HeaderFile
#include <Handle_TCollection_HAsciiString.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_TColStd_HSequenceOfTransient_HeaderFile
#include <Handle_TColStd_HSequenceOfTransient.hxx>
#endif
class StepBasic_ApplicationProtocolDefinition;
class StepGeom_Axis2Placement3d;
class StepData_StepModel;
class TCollection_HAsciiString;
class STEPConstruct_AP203Context;
class TColStd_HSequenceOfTransient;
class STEPConstruct_Part;
class STEPConstruct_Assembly;


//! Gives access to Product Definition Context (one per Model) <br>
//!           Maintains ApplicationProtocolDefinition entity (common for all <br>
//!           products) <br>
//!           Also maintains context specific for AP203 and provides set of <br>
//!           methods to work with various STEP constructs as required <br>
//!           by Actor <br>
class STEPConstruct_ContextTool  {
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

  
  Standard_EXPORT   STEPConstruct_ContextTool();
  
  Standard_EXPORT   STEPConstruct_ContextTool(const Handle(StepData_StepModel)& aStepModel);
  //! Initialize ApplicationProtocolDefinition by the first <br>
//!          entity of that type found in the model <br>
  Standard_EXPORT     void SetModel(const Handle(StepData_StepModel)& aStepModel) ;
  
  Standard_EXPORT     Handle_StepBasic_ApplicationProtocolDefinition GetAPD() ;
  
  Standard_EXPORT     void AddAPD(const Standard_Boolean enforce = Standard_False) ;
  //! Returns True if APD.schema_name is config_control_design <br>
  Standard_EXPORT     Standard_Boolean IsAP203() const;
  //! Returns True if APD.schema_name is automotive_design <br>
  Standard_EXPORT     Standard_Boolean IsAP214() const;
  
  Standard_EXPORT     Handle_TCollection_HAsciiString GetACstatus() ;
  
  Standard_EXPORT     Handle_TCollection_HAsciiString GetACschemaName() ;
  
  Standard_EXPORT     Standard_Integer GetACyear() ;
  
  Standard_EXPORT     Handle_TCollection_HAsciiString GetACname() ;
  
  Standard_EXPORT     void SetACstatus(const Handle(TCollection_HAsciiString)& status) ;
  
  Standard_EXPORT     void SetACschemaName(const Handle(TCollection_HAsciiString)& schemaName) ;
  
  Standard_EXPORT     void SetACyear(const Standard_Integer year) ;
  
  Standard_EXPORT     void SetACname(const Handle(TCollection_HAsciiString)& name) ;
  //! Returns a default axis placement <br>
  Standard_EXPORT     Handle_StepGeom_Axis2Placement3d GetDefaultAxis() ;
  //! Returns tool which maintains context specific for AP203 <br>
  Standard_EXPORT     STEPConstruct_AP203Context& AP203Context() ;
  //! Returns current assembly level <br>
  Standard_EXPORT     Standard_Integer Level() const;
  
  Standard_EXPORT     void NextLevel() ;
  
  Standard_EXPORT     void PrevLevel() ;
  //! Changes current assembly level <br>
  Standard_EXPORT     void SetLevel(const Standard_Integer lev) ;
  //! Returns current index of assembly component on current level <br>
  Standard_EXPORT     Standard_Integer Index() const;
  
  Standard_EXPORT     void NextIndex() ;
  
  Standard_EXPORT     void PrevIndex() ;
  //! Changes current index of assembly component on current level <br>
  Standard_EXPORT     void SetIndex(const Standard_Integer ind) ;
  //! Generates a product name basing on write.step.product.name <br>
//!          parameter and current position in the assembly structure <br>
  Standard_EXPORT     Handle_TCollection_HAsciiString GetProductName() const;
  //! Produces and returns a full list of root entities required <br>
//!          for part identified by SDRTool (including SDR itself) <br>
  Standard_EXPORT     Handle_TColStd_HSequenceOfTransient GetRootsForPart(const STEPConstruct_Part& SDRTool) ;
  //! Produces and returns a full list of root entities required <br>
//!          for assembly link identified by assembly (including NAUO and CDSR) <br>
  Standard_EXPORT     Handle_TColStd_HSequenceOfTransient GetRootsForAssemblyLink(const STEPConstruct_Assembly& assembly) ;





protected:





private:



TColStd_SequenceOfInteger myLevel;
Handle_StepBasic_ApplicationProtocolDefinition theAPD;
STEPConstruct_AP203Context theAP203;
Handle_StepGeom_Axis2Placement3d myAxis;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
