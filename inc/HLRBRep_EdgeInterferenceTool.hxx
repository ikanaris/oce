// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _HLRBRep_EdgeInterferenceTool_HeaderFile
#define _HLRBRep_EdgeInterferenceTool_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Handle_HLRBRep_Data_HeaderFile
#include <Handle_HLRBRep_Data.hxx>
#endif
#ifndef _HLRAlgo_Intersection_HeaderFile
#include <HLRAlgo_Intersection.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _TopAbs_Orientation_HeaderFile
#include <TopAbs_Orientation.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
class HLRBRep_Data;
class HLRAlgo_Intersection;
class gp_Dir;
class HLRAlgo_Interference;


//! Implements the  methods required  to  instantiates <br>
//!          the EdgeInterferenceList from HLRAlgo. <br>
class HLRBRep_EdgeInterferenceTool  {
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

  
  Standard_EXPORT   HLRBRep_EdgeInterferenceTool(const Handle(HLRBRep_Data)& DS);
  
  Standard_EXPORT     void LoadEdge() ;
  
        void InitVertices() ;
  
        Standard_Boolean MoreVertices() const;
  
        void NextVertex() ;
  
       const HLRAlgo_Intersection& CurrentVertex() const;
  
        TopAbs_Orientation CurrentOrientation() const;
  
        Standard_Real CurrentParameter() const;
  
        Standard_Boolean IsPeriodic() const;
  //! Returns local geometric description of the Edge at <br>
//!          parameter   <Para>.  See  method  Reset  of  class <br>
//!          EdgeFaceTransition from TopCnx for other arguments. <br>
  Standard_EXPORT     void EdgeGeometry(const Standard_Real Param,gp_Dir& Tgt,gp_Dir& Nrm,Standard_Real& Curv) const;
  
        Standard_Real ParameterOfInterference(const HLRAlgo_Interference& I) const;
  //! True if   the  two interferences are on   the same <br>
//!          geometric locus. <br>
  Standard_EXPORT     Standard_Boolean SameInterferences(const HLRAlgo_Interference& I1,const HLRAlgo_Interference& I2) const;
  //! True if the  Interference and the  current  Vertex <br>
//!          are on the same geometric locus. <br>
  Standard_EXPORT     Standard_Boolean SameVertexAndInterference(const HLRAlgo_Interference& I) const;
  //! Returns   the  geometry of  the   boundary  at the <br>
//!          interference  <I>.  See the AddInterference method <br>
//!          of the class  EdgeFaceTransition  from  TopCnx for <br>
//!          the other arguments. <br>
  Standard_EXPORT     void InterferenceBoundaryGeometry(const HLRAlgo_Interference& I,gp_Dir& Tang,gp_Dir& Norm,Standard_Real& Curv) const;





protected:





private:



Handle_HLRBRep_Data myDS;
HLRAlgo_Intersection inter[2];
Standard_Integer cur;


};


#include <HLRBRep_EdgeInterferenceTool.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
