// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepMesh_FaceAttribute_HeaderFile
#define _BRepMesh_FaceAttribute_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_BRepMesh_FaceAttribute_HeaderFile
#include <Handle_BRepMesh_FaceAttribute.hxx>
#endif

#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _BRepMesh_ClassifierPtr_HeaderFile
#include <BRepMesh_ClassifierPtr.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif


//! auxiliary class for FastDiscret and FastDiscretFace classes <br>
class BRepMesh_FaceAttribute : public MMgt_TShared {

public:

  
  Standard_EXPORT   BRepMesh_FaceAttribute();
  
        Standard_Real& GetDefFace() ;
  
        Standard_Real& GetUMin() ;
  
        Standard_Real& GetVMin() ;
  
        Standard_Real& GetUMax() ;
  
        Standard_Real& GetVMax() ;
  
        Standard_Real& GetDeltaX() ;
  
        Standard_Real& GetDeltaY() ;
  
        Standard_Real& GetMinX() ;
  
        Standard_Real& GetMinY() ;
  
        BRepMesh_ClassifierPtr& GetClassifier() ;




  DEFINE_STANDARD_RTTI(BRepMesh_FaceAttribute)

protected:




private: 


Standard_Real mydefface;
Standard_Real myumin;
Standard_Real myumax;
Standard_Real myvmin;
Standard_Real myvmax;
Standard_Real mydeltaX;
Standard_Real mydeltaY;
Standard_Real myminX;
Standard_Real myminY;
BRepMesh_ClassifierPtr myclassifier;


};


#include <BRepMesh_FaceAttribute.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
