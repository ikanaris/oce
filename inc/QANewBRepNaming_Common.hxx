// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _QANewBRepNaming_Common_HeaderFile
#define _QANewBRepNaming_Common_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _QANewBRepNaming_BooleanOperationFeat_HeaderFile
#include <QANewBRepNaming_BooleanOperationFeat.hxx>
#endif
class TDF_Label;
class BRepAlgoAPI_BooleanOperation;



class QANewBRepNaming_Common  : public QANewBRepNaming_BooleanOperationFeat {
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

  
  Standard_EXPORT   QANewBRepNaming_Common();
  
  Standard_EXPORT   QANewBRepNaming_Common(const TDF_Label& ResultLabel);
  
  Standard_EXPORT     void Load(BRepAlgoAPI_BooleanOperation& MakeShape) const;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
