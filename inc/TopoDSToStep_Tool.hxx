// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TopoDSToStep_Tool_HeaderFile
#define _TopoDSToStep_Tool_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _MoniTool_DataMapOfShapeTransient_HeaderFile
#include <MoniTool_DataMapOfShapeTransient.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _TopoDS_Shell_HeaderFile
#include <TopoDS_Shell.hxx>
#endif
#ifndef _TopoDS_Face_HeaderFile
#include <TopoDS_Face.hxx>
#endif
#ifndef _TopoDS_Wire_HeaderFile
#include <TopoDS_Wire.hxx>
#endif
#ifndef _TopoDS_Edge_HeaderFile
#include <TopoDS_Edge.hxx>
#endif
#ifndef _TopoDS_Vertex_HeaderFile
#include <TopoDS_Vertex.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_StepShape_TopologicalRepresentationItem_HeaderFile
#include <Handle_StepShape_TopologicalRepresentationItem.hxx>
#endif
class MoniTool_DataMapOfShapeTransient;
class TopoDS_Shape;
class StepShape_TopologicalRepresentationItem;
class TopoDS_Shell;
class TopoDS_Face;
class TopoDS_Wire;
class TopoDS_Edge;
class TopoDS_Vertex;


//! This Tool Class provides Information to build <br>
//!          a ProSTEP Shape model from a Cas.Cad BRep. <br>
class TopoDSToStep_Tool  {
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

  
  Standard_EXPORT   TopoDSToStep_Tool();
  
  Standard_EXPORT   TopoDSToStep_Tool(const MoniTool_DataMapOfShapeTransient& M,const Standard_Boolean FacetedContext);
  
  Standard_EXPORT     void Init(const MoniTool_DataMapOfShapeTransient& M,const Standard_Boolean FacetedContext) ;
  
  Standard_EXPORT     Standard_Boolean IsBound(const TopoDS_Shape& S) ;
  
  Standard_EXPORT     void Bind(const TopoDS_Shape& S,const Handle(StepShape_TopologicalRepresentationItem)& T) ;
  
  Standard_EXPORT     Handle_StepShape_TopologicalRepresentationItem Find(const TopoDS_Shape& S) ;
  
  Standard_EXPORT     Standard_Boolean Faceted() const;
  
  Standard_EXPORT     void SetCurrentShell(const TopoDS_Shell& S) ;
  
  Standard_EXPORT    const TopoDS_Shell& CurrentShell() const;
  
  Standard_EXPORT     void SetCurrentFace(const TopoDS_Face& F) ;
  
  Standard_EXPORT    const TopoDS_Face& CurrentFace() const;
  
  Standard_EXPORT     void SetCurrentWire(const TopoDS_Wire& W) ;
  
  Standard_EXPORT    const TopoDS_Wire& CurrentWire() const;
  
  Standard_EXPORT     void SetCurrentEdge(const TopoDS_Edge& E) ;
  
  Standard_EXPORT    const TopoDS_Edge& CurrentEdge() const;
  
  Standard_EXPORT     void SetCurrentVertex(const TopoDS_Vertex& V) ;
  
  Standard_EXPORT    const TopoDS_Vertex& CurrentVertex() const;
  
  Standard_EXPORT     Standard_Real Lowest3DTolerance() const;
  
  Standard_EXPORT     void SetSurfaceReversed(const Standard_Boolean B) ;
  
  Standard_EXPORT     Standard_Boolean SurfaceReversed() const;
  
  Standard_EXPORT    const MoniTool_DataMapOfShapeTransient& Map() const;
  //! Returns mode for writing pcurves <br>
//!          (initialized by parameter write.surfacecurve.mode) <br>
  Standard_EXPORT     Standard_Integer PCurveMode() const;





protected:





private:



MoniTool_DataMapOfShapeTransient myDataMap;
Standard_Boolean myFacetedContext;
Standard_Real myLowestTol;
TopoDS_Shell myCurrentShell;
TopoDS_Face myCurrentFace;
TopoDS_Wire myCurrentWire;
TopoDS_Edge myCurrentEdge;
TopoDS_Vertex myCurrentVertex;
Standard_Boolean myReversedSurface;
Standard_Integer myPCurveMode;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
