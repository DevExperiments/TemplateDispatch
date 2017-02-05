//---------------------------------------------------------------------------
#ifndef DispatchH
#define DispatchH
//---------------------------------------------------------------------------
#include <vector.h>

template <typename TData>
class TDispatcher
{
public:
   __fastcall ~TDispatcher (void) {
      oDispatchHandlers.clear ();
   }

   struct TDispatchHandler {
      typedef void __fastcall (__closure * FnOnDispatch) (TData& oData);
      typedef FnOnDispatch TDispatchFnType;
      FnOnDispatch OnDispatch;

      __fastcall TDispatchHandler (void) : OnDispatch(NULL) {}
      __fastcall TDispatchHandler (FnOnDispatch pFnOnDispatch) : OnDispatch(pFnOnDispatch) {}
      __fastcall ~TDispatchHandler (void) { OnDispatch = NULL; }
   };

   typedef TData TDispatchData;
   
	void __fastcall Subscribe (const TDispatchHandler& oCallbackData) {
		oDispatchHandlers.push_back (oCallbackData);
	}

	void __fastcall Dispatch (TData& oData) {
		for (TDispatchHandlersIterator iter = oDispatchHandlers.begin (); iter != oDispatchHandlers.end (); ++iter) {
			TDispatchHandler oDispatchHandler = *iter;
			FireCallbackX (oData, oDispatchHandler);
		}
	}

	void __fastcall Dispatch (const TData& oData) const {
		for (TDispatchHandlersConstIterator iter = oDispatchHandlers.begin (); iter != oDispatchHandlers.end (); ++iter) {
			TDispatchHandler oDispatchHandler = *iter;
			FireCallbackX (oData, oDispatchHandler);
		}
	}

private:
	typedef vector<TDispatchHandler> TDispatchHandlers;
	typedef TDispatchHandlers::iterator TDispatchHandlersIterator;
  typedef TDispatchHandlers::const_iterator TDispatchHandlersConstIterator;

	TDispatchHandlers oDispatchHandlers;

   inline void __fastcall FireCallbackX (TData& oData, TDispatchHandler& oDispatchFn) {
      TDispatchHandler::TDispatchFnType Fn = oDispatchFn.OnDispatch;
      if (Fn) Fn (oData);
   }

   inline void __fastcall FireCallbackX (const TData& oData, TDispatchHandler& oDispatchFn) const {
      TDispatchHandler::TDispatchFnType Fn = oDispatchFn.OnDispatch;
      if (Fn) Fn (oData);
   }
};
//---------------------------------------------------------------------------
#endif
