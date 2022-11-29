
// marubatsu.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CmarubatsuApp:
// このクラスの実装については、marubatsu.cpp を参照してください。
//

class CmarubatsuApp : public CWinApp
{
public:
	CmarubatsuApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CmarubatsuApp theApp;