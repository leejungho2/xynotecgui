// EffectEngine.h : main header file for the EffectEngine DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CEffectEngineApp
// See EffectEngine.cpp for the implementation of this class
//

class CEffectEngineApp : public CWinApp
{
public:
	CEffectEngineApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
