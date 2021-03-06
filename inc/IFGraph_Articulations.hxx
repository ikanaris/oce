// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IFGraph_Articulations_HeaderFile
#define _IFGraph_Articulations_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Interface_Graph_HeaderFile
#include <Interface_Graph.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_TColStd_HSequenceOfInteger_HeaderFile
#include <Handle_TColStd_HSequenceOfInteger.hxx>
#endif
#ifndef _Interface_GraphContent_HeaderFile
#include <Interface_GraphContent.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
class TColStd_HSequenceOfInteger;
class Interface_Graph;
class Standard_Transient;
class Interface_EntityIterator;


//! this class gives entities which are Articulation points <br>
//!           in a whole Model or in a sub-part <br>
//!           An Articulation Point divides the graph in two (or more) <br>
//!           disconnected sub-graphs <br>
//!           Identifying Articulation Points allows improving <br>
//!           efficiency of spliting a set of Entities into sub-sets <br>
class IFGraph_Articulations  : public Interface_GraphContent {
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

  //! creates Articulations to evaluate a Graph <br>
//!           whole True : works on the whole Model <br>
//!           whole False : remains empty, ready to work on a sub-part <br>
  Standard_EXPORT   IFGraph_Articulations(const Interface_Graph& agraph,const Standard_Boolean whole);
  //! adds an entity and its shared ones to the list <br>
  Standard_EXPORT     void GetFromEntity(const Handle(Standard_Transient)& ent) ;
  //! adds a list of entities (as an iterator) <br>
  Standard_EXPORT     void GetFromIter(const Interface_EntityIterator& iter) ;
  //! Allows to restart on a new data set <br>
  Standard_EXPORT     void ResetData() ;
  //! Evaluates the list of Articulation points <br>
  Standard_EXPORT   virtual  void Evaluate() ;





protected:





private:

  //! basic routine of computation <br>
//!           (see book Sedgewick "Algorithms", p 392) <br>
  Standard_EXPORT     Standard_Integer Visit(const Standard_Integer num) ;


Interface_Graph thegraph;
Standard_Integer thenow;
Handle_TColStd_HSequenceOfInteger thelist;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
