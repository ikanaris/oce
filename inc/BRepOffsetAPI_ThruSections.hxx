// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepOffsetAPI_ThruSections_HeaderFile
#define _BRepOffsetAPI_ThruSections_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TopTools_SequenceOfShape_HeaderFile
#include <TopTools_SequenceOfShape.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _TopoDS_Face_HeaderFile
#include <TopoDS_Face.hxx>
#endif
#ifndef _TopTools_DataMapOfShapeShape_HeaderFile
#include <TopTools_DataMapOfShapeShape.hxx>
#endif
#ifndef _GeomAbs_Shape_HeaderFile
#include <GeomAbs_Shape.hxx>
#endif
#ifndef _Approx_ParametrizationType_HeaderFile
#include <Approx_ParametrizationType.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _BRepBuilderAPI_MakeShape_HeaderFile
#include <BRepBuilderAPI_MakeShape.hxx>
#endif
#ifndef _Handle_Geom_BSplineSurface_HeaderFile
#include <Handle_Geom_BSplineSurface.hxx>
#endif
class Standard_DomainError;
class TopoDS_Wire;
class TopoDS_Vertex;
class TopoDS_Shape;
class Geom_BSplineSurface;
class TopTools_Array1OfShape;


//! Describes functions to build a loft. This is a shell or a <br>
//! solid passing through a set of sections in a given <br>
//! sequence. Usually sections are wires, but the first and <br>
//! the last sections may be vertices (punctual sections). <br>
class BRepOffsetAPI_ThruSections  : public BRepBuilderAPI_MakeShape {
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

  //! Initializes an algorithm for building a shell or a solid <br>
//! passing through a set of sections, where: <br>
//! -          isSolid is set to true if the construction algorithm is <br>
//!   required to build a solid or to false if it is required to build <br>
//!   a shell (the default value), <br>
//! -          ruled is set to true if the faces generated between <br>
//!   the edges of two consecutive wires are ruled surfaces or to <br>
//!   false (the default value) if they are smoothed out by approximation, <br>
//! -          pres3d defines the precision criterion used by the <br>
//!   approximation algorithm; the default value is 1.0e-6. <br>
//!   Use AddWire and AddVertex to define the <br>
//! successive sections of the shell or solid to be built. <br>
  Standard_EXPORT   BRepOffsetAPI_ThruSections(const Standard_Boolean isSolid = Standard_False,const Standard_Boolean ruled = Standard_False,const Standard_Real pres3d = 1.0e-06);
  //! Initializes this algorithm for building a shell or a solid <br>
//! passing through a set of sections, where: <br>
//! - isSolid is set to true if this construction algorithm is <br>
//!   required to build a solid or to false if it is required to <br>
//!   build a shell. false is the default value; <br>
//! - ruled is set to true if the faces generated between the <br>
//!   edges of two consecutive wires are ruled surfaces or <br>
//! to false (the default value) if they are smoothed out by approximation, <br>
//! - pres3d defines the precision criterion used by the <br>
//!   approximation algorithm; the default value is 1.0e-6. <br>
//!   Use AddWire and AddVertex to define the successive <br>
//! sections of the shell or solid to be built. <br>
  Standard_EXPORT     void Init(const Standard_Boolean isSolid = Standard_False,const Standard_Boolean ruled = Standard_False,const Standard_Real pres3d = 1.0e-06) ;
  //! Adds the wire wire to the set of <br>
//! sections through which the shell or solid is built. <br>
//! Use the Build function to construct the shape. <br>
  Standard_EXPORT     void AddWire(const TopoDS_Wire& wire) ;
  //! Adds the vertex Vertex (punctual section) to the set of sections <br>
//! through which the shell or solid is built. A vertex may be added to the <br>
//! set of sections only as first or last section. At least one wire <br>
//! must be added to the set of sections by the method AddWire. <br>
//! Use the Build function to construct the shape. <br>
  Standard_EXPORT     void AddVertex(const TopoDS_Vertex& aVertex) ;
  
  Standard_EXPORT     void CheckCompatibility(const Standard_Boolean check = Standard_True) ;
  //! Define the approximation algorithm <br>
  Standard_EXPORT     void SetSmoothing(const Standard_Boolean UseSmoothing) ;
  //! Define the type of parametrization   used in the approximation <br>
  Standard_EXPORT     void SetParType(const Approx_ParametrizationType ParType) ;
  //! Define the Continuity used in the approximation <br>
  Standard_EXPORT     void SetContinuity(const GeomAbs_Shape C) ;
  //! define the Weights  associed to the criterium used in <br>
//!          the  optimization. <br>
//! <br>
//! if Wi <= 0 <br>
  Standard_EXPORT     void SetCriteriumWeight(const Standard_Real W1,const Standard_Real W2,const Standard_Real W3) ;
  //! Define the maximal U degree of result surface <br>
  Standard_EXPORT     void SetMaxDegree(const Standard_Integer MaxDeg) ;
  //! returns the type of parametrization used in the approximation <br>
  Standard_EXPORT     Approx_ParametrizationType ParType() const;
  //! returns the Continuity used in the approximation <br>
  Standard_EXPORT     GeomAbs_Shape Continuity() const;
  //! returns the maximal U degree of result surface <br>
  Standard_EXPORT     Standard_Integer MaxDegree() const;
  //! Define the approximation algorithm <br>
  Standard_EXPORT     Standard_Boolean UseSmoothing() const;
  //! returns the Weights associed  to the criterium used in <br>
//!          the  optimization. <br>
  Standard_EXPORT     void CriteriumWeight(Standard_Real& W1,Standard_Real& W2,Standard_Real& W3) const;
  
  Standard_EXPORT   virtual  void Build() ;
  //! Returns the TopoDS Shape of the bottom of the loft if solid <br>
  Standard_EXPORT    const TopoDS_Shape& FirstShape() const;
  //! Returns the TopoDS Shape of the top of the loft if solid <br>
  Standard_EXPORT    const TopoDS_Shape& LastShape() const;
  //! if Ruled <br>
//!            Returns the Face generated by each edge <br>
//!            except the last wire <br>
//!          if smoothed <br>
//!            Returns the Face generated by each edge of the first wire <br>
  Standard_EXPORT     TopoDS_Shape GeneratedFace(const TopoDS_Shape& Edge) const;





protected:





private:

  
  Standard_EXPORT     void CreateRuled() ;
  
  Standard_EXPORT     void CreateSmoothed() ;
  
  Standard_EXPORT     Handle_Geom_BSplineSurface TotalSurf(const TopTools_Array1OfShape& shapes,const Standard_Integer NbSect,const Standard_Integer NbEdges,const Standard_Boolean w1Point,const Standard_Boolean w2Point,const Standard_Boolean vClosed) const;


TopTools_SequenceOfShape myWires;
Standard_Boolean myIsSolid;
Standard_Boolean myIsRuled;
Standard_Boolean myWCheck;
Standard_Real myPres3d;
TopoDS_Face myFirst;
TopoDS_Face myLast;
TopTools_DataMapOfShapeShape myGenerated;
GeomAbs_Shape myContinuity;
Approx_ParametrizationType myParamType;
Standard_Integer myDegMax;
Standard_Real myCritWeights[3];
Standard_Boolean myUseSmoothing;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
