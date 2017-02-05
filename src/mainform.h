//---------------------------------------------------------------------------
#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------

struct SBasicData;
struct SBasicData2;

class TfrmMain : public TForm
{
__published:
   TButton *btnDoAction;
   void __fastcall btnDoActionClick(TObject *Sender);

public:
   __fastcall TfrmMain (TComponent* Owner);

private:
   void __fastcall DoAction1 (SBasicData& oData);
   void __fastcall DoAction2 (SBasicData& oData);

   void __fastcall DoAction1 (SBasicData2& oData);
};

//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
