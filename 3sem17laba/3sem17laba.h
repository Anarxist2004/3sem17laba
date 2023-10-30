
// 3sem17laba.h: основной файл заголовка для приложения 3sem17laba
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMy3sem17labaApp:
// Сведения о реализации этого класса: 3sem17laba.cpp
//

class CMy3sem17labaApp : public CWinApp
{
public:
	CMy3sem17labaApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy3sem17labaApp theApp;
