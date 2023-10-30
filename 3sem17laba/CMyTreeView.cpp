// CMyTreeView.cpp: файл реализации
//

#include "pch.h"
#include "3sem17laba.h"
#include "CMyTreeView.h"
#include "3sem17labaDoc.h"
#include "3sem17labaView.h"
// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

CMyTreeView::CMyTreeView()
{

}

CMyTreeView::~CMyTreeView()
{
}

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// Диагностика CMyTreeView

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CMyTreeView


int CMyTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{

	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS | TVS_CHECKBOXES;

	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	

	return 0;
}

void CMyTreeView::FillTree()
{
	CTreeCtrl& tree = GetTreeCtrl();
	

	tree.DeleteAllItems();

	m_hDrivers = tree.InsertItem(L"Объекты", -1, -1, NULL, TVI_FIRST);
	m_hCars = tree.InsertItem(L"Машины", - 1, -1, NULL, TVI_FIRST);
	m_hfl = tree.InsertItem(L"рейсы", - 1, -1, NULL, TVI_FIRST);

	
}

void CMyTreeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CTreeView::OnLButtonDown(nFlags, point);
	CTreeCtrl& tree = GetTreeCtrl();


	CRect rc;


	tree.GetItemRect(m_hDrivers, &rc, false);
	if (rc.PtInRect(point))
		tree.SelectItem(m_hDrivers);

	tree.GetItemRect(m_hCars, &rc, false);
	if (rc.PtInRect(point))
		tree.SelectItem(m_hCars);

	tree.GetItemRect(m_hfl, &rc, false);
	if (rc.PtInRect(point))
		tree.SelectItem(m_hfl);

	m_pDoc->m_bCars = tree.GetCheck(m_hCars);
	m_pDoc->m_bDrivers = tree.GetCheck(m_hDrivers);
	m_pDoc->m_bfl = tree.GetCheck(m_hfl);
	m_pDoc->pView->Invalidate();
}
