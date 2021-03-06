// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TColGeom_HSequenceOfSurface_HeaderFile
#define _TColGeom_HSequenceOfSurface_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_TColGeom_HSequenceOfSurface_HeaderFile
#include <Handle_TColGeom_HSequenceOfSurface.hxx>
#endif

#ifndef _TColGeom_SequenceOfSurface_HeaderFile
#include <TColGeom_SequenceOfSurface.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Handle_Geom_Surface_HeaderFile
#include <Handle_Geom_Surface.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class Standard_NoSuchObject;
class Standard_OutOfRange;
class Geom_Surface;
class TColGeom_SequenceOfSurface;



class TColGeom_HSequenceOfSurface : public MMgt_TShared {

public:

  
      TColGeom_HSequenceOfSurface();
  
        Standard_Boolean IsEmpty() const;
  
        Standard_Integer Length() const;
  
  Standard_EXPORT     void Clear() ;
  
  Standard_EXPORT     void Append(const Handle(Geom_Surface)& anItem) ;
  
  Standard_EXPORT     void Append(const Handle(TColGeom_HSequenceOfSurface)& aSequence) ;
  
  Standard_EXPORT     void Prepend(const Handle(Geom_Surface)& anItem) ;
  
  Standard_EXPORT     void Prepend(const Handle(TColGeom_HSequenceOfSurface)& aSequence) ;
  
  Standard_EXPORT     void Reverse() ;
  
  Standard_EXPORT     void InsertBefore(const Standard_Integer anIndex,const Handle(Geom_Surface)& anItem) ;
  
  Standard_EXPORT     void InsertBefore(const Standard_Integer anIndex,const Handle(TColGeom_HSequenceOfSurface)& aSequence) ;
  
  Standard_EXPORT     void InsertAfter(const Standard_Integer anIndex,const Handle(Geom_Surface)& anItem) ;
  
  Standard_EXPORT     void InsertAfter(const Standard_Integer anIndex,const Handle(TColGeom_HSequenceOfSurface)& aSequence) ;
  
  Standard_EXPORT     void Exchange(const Standard_Integer anIndex,const Standard_Integer anOtherIndex) ;
  
  Standard_EXPORT     Handle_TColGeom_HSequenceOfSurface Split(const Standard_Integer anIndex) ;
  
  Standard_EXPORT     void SetValue(const Standard_Integer anIndex,const Handle(Geom_Surface)& anItem) ;
  
  Standard_EXPORT    const Handle_Geom_Surface& Value(const Standard_Integer anIndex) const;
  
  Standard_EXPORT     Handle_Geom_Surface& ChangeValue(const Standard_Integer anIndex) ;
  
  Standard_EXPORT     void Remove(const Standard_Integer anIndex) ;
  
  Standard_EXPORT     void Remove(const Standard_Integer fromIndex,const Standard_Integer toIndex) ;
  
       const TColGeom_SequenceOfSurface& Sequence() const;
  
        TColGeom_SequenceOfSurface& ChangeSequence() ;
  
  Standard_EXPORT     Handle_TColGeom_HSequenceOfSurface ShallowCopy() const;




  DEFINE_STANDARD_RTTI(TColGeom_HSequenceOfSurface)

protected:




private: 


TColGeom_SequenceOfSurface mySequence;


};

#define Item Handle_Geom_Surface
#define Item_hxx <Geom_Surface.hxx>
#define TheSequence TColGeom_SequenceOfSurface
#define TheSequence_hxx <TColGeom_SequenceOfSurface.hxx>
#define TCollection_HSequence TColGeom_HSequenceOfSurface
#define TCollection_HSequence_hxx <TColGeom_HSequenceOfSurface.hxx>
#define Handle_TCollection_HSequence Handle_TColGeom_HSequenceOfSurface
#define TCollection_HSequence_Type_() TColGeom_HSequenceOfSurface_Type_()

#include <TCollection_HSequence.lxx>

#undef Item
#undef Item_hxx
#undef TheSequence
#undef TheSequence_hxx
#undef TCollection_HSequence
#undef TCollection_HSequence_hxx
#undef Handle_TCollection_HSequence
#undef TCollection_HSequence_Type_


// other Inline functions and methods (like "C++: function call" methods)
inline Handle_TColGeom_HSequenceOfSurface ShallowCopy(const Handle_TColGeom_HSequenceOfSurface& me) {
 return me->ShallowCopy();
}



#endif
