
// 3sem17labaView.h: интерфейс класса CMy3sem17labaView
//

#pragma once
#include "3sem17labaDoc.h"

class CMy3sem17labaView : public CView
{
protected: // создать только из сериализации
	CMy3sem17labaView() noexcept;
	DECLARE_DYNCREATE(CMy3sem17labaView)

// Атрибуты
public:
	CMy3sem17labaDoc *GetDocument() const;

	CListCtrl CarTable,DriverTable,FLTable;
	


	RECT rect = { 50,50,200,200 };
	bool FLAG = 0;
// Операции

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CMy3sem17labaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в 3sem17labaView.cpp
inline CMy3sem17labaDoc* CMy3sem17labaView::GetDocument() const
   { return reinterpret_cast<CMy3sem17labaDoc*>(m_pDocument); }
#endif

