//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "mainForm.h"
#include "dispatch.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;

struct SBasicData {
	int ID;
};

struct SBasicData2 {
   AnsiString Name;
};

typedef TDispatcher<SBasicData> TBasicDataDispatcher;
typedef TDispatcher<SBasicData2> TBasicData2Dispatcher;

static TBasicDataDispatcher oDispatcher;
static TBasicData2Dispatcher oDispatcher2;

//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
   : TForm(Owner)
{
   TBasicDataDispatcher::TDispatchHandler oBasicDispatchHandler;
   oBasicDispatchHandler.OnDispatch = this->DoAction1;
   oDispatcher.Subscribe (oBasicDispatchHandler);

   oBasicDispatchHandler.OnDispatch = DoAction2;
   oDispatcher.Subscribe (oBasicDispatchHandler);

   TBasicData2Dispatcher::TDispatchHandler oBasic2DispatchHandler;
   oBasic2DispatchHandler.OnDispatch = this->DoAction1;
   oDispatcher2.Subscribe (oBasic2DispatchHandler);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::DoAction1 (SBasicData& oData)
{
   ShowMessage ("DoAction1 " + IntToStr (oData.ID));
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::DoAction2 (SBasicData& oData)
{
   ShowMessage ("DoAction2 " + IntToStr (oData.ID));
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::DoAction1 (SBasicData2& oData)
{
   ShowMessage (oData.Name);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnDoActionClick(TObject *Sender)
{
   TBasicDataDispatcher::TDispatchData oBasicData;
   oBasicData.ID = 100;
   oDispatcher.Dispatch (oBasicData);

   TBasicData2Dispatcher::TDispatchData oBasicData2;
   oBasicData2.Name = "Andy";
   oDispatcher2.Dispatch(oBasicData2);
}
