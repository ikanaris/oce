// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TColGeom_HArray1OfSurface_HeaderFile
#define _TColGeom_HArray1OfSurface_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_TColGeom_HArray1OfSurface_HeaderFile
#include <Handle_TColGeom_HArray1OfSurface.hxx>
#endif

#ifndef _TColGeom_Array1OfSurface_HeaderFile
#include <TColGeom_Array1OfSurface.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Handle_Geom_Surface_HeaderFile
#include <Handle_Geom_Surface.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class Standard_RangeError;
class Standard_DimensionMismatch;
class Standard_OutOfRange;
class Standard_OutOfMemory;
class Geom_Surface;
class TColGeom_Array1OfSurface;



class TColGeom_HArray1OfSurface : public MMgt_TShared {

public:

  
  Standard_EXPORT   TColGeom_HArray1OfSurface(const Standard_Integer Low,const Standard_Integer Up);
  
  Standard_EXPORT   TColGeom_HArray1OfSurface(const Standard_Integer Low,const Standard_Integer Up,const Handle(Geom_Surface)& V);
  
  Standard_EXPORT     void Init(const Handle(Geom_Surface)& V) ;
  
        Standard_Integer Length() const;
  
        Standard_Integer Lower() const;
  
        Standard_Integer Upper() const;
  
        void SetValue(const Standard_Integer Index,const Handle(Geom_Surface)& Value) ;
  
       const Handle_Geom_Surface& Value(const Standard_Integer Index) const;
  
        Handle_Geom_Surface& ChangeValue(const Standard_Integer Index) ;
  
       const TColGeom_Array1OfSurface& Array1() const;
  
        TColGeom_Array1OfSurface& ChangeArray1() ;




  DEFINE_STANDARD_RTTI(TColGeom_HArray1OfSurface)

protected:




private: 


TColGeom_Array1OfSurface myArray;


};

#define ItemHArray1 Handle_Geom_Surface
#define ItemHArray1_hxx <Geom_Surface.hxx>
#define TheArray1 TColGeom_Array1OfSurface
#define TheArray1_hxx <TColGeom_Array1OfSurface.hxx>
#define TCollection_HArray1 TColGeom_HArray1OfSurface
#define TCollection_HArray1_hxx <TColGeom_HArray1OfSurface.hxx>
#define Handle_TCollection_HArray1 Handle_TColGeom_HArray1OfSurface
#define TCollection_HArray1_Type_() TColGeom_HArray1OfSurface_Type_()

#include <TCollection_HArray1.lxx>

#undef ItemHArray1
#undef ItemHArray1_hxx
#undef TheArray1
#undef TheArray1_hxx
#undef TCollection_HArray1
#undef TCollection_HArray1_hxx
#undef Handle_TCollection_HArray1
#undef TCollection_HArray1_Type_


// other Inline functions and methods (like "C++: function call" methods)


#endif
