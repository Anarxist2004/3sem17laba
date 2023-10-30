
// 3sem17labaView.cpp: реализация класса CMy3sem17labaView
//


#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "3sem17laba.h"
#endif
#include "CMyList.h"
#include "3sem17labaDoc.h"
#include "3sem17labaView.h"
#include <iostream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3sem17labaView

IMPLEMENT_DYNCREATE(CMy3sem17labaView, CView)

BEGIN_MESSAGE_MAP(CMy3sem17labaView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Создание или уничтожение CMy3sem17labaView

CMy3sem17labaView::CMy3sem17labaView() noexcept
{
	// TODO: добавьте код создания

}

CMy3sem17labaView::~CMy3sem17labaView()
{
}

BOOL CMy3sem17labaView::PreCreateWindow(CREATESTRUCT& cs)
{


	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs




	return CView::PreCreateWindow(cs);
}

// Рисование CMy3sem17labaView

void CMy3sem17labaView::OnDraw(CDC* pDC)
{
	CMy3sem17labaDoc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (FLAG == 0)
	{

		MYSQL* conn;
		conn = mysql_init(NULL);
		if (conn == NULL)
		{
			// Если дескриптор не получен – выводим сообщение об ошибке
			fprintf(stderr, "Error: can'tcreate MySQL-descriptor\n");

		}
		// Подключаемся к серверу

		if (!mysql_real_connect(conn, "localhost", "root", "Stud813850!", "logisticcompany", NULL, NULL, 0))
		{
			// Если нет возможности установить соединение с сервером
			// базы данных выводим сообщение об ошибке
			printf("Error: can'tconnecttodatabase %s\n", mysql_error(conn));
		}
		else
		{
			MessageBoxW(0);
		}
		FLAG++;
	}


	if (pDoc->m_bCars == 1) {
		 CRect rectListCtrl(30, 30, 300, 200); // Задаем координаты и размер List Control
    CarTable.Create(WS_VISIBLE | WS_CHILD | LVS_REPORT, rectListCtrl, this, 0);

    CarTable.InsertColumn(0, _T("Column 1"), LVCFMT_LEFT, 100); // Добавляем колонки
    CarTable.InsertColumn(1, _T("Column 2"), LVCFMT_LEFT, 100);
    // ... добавление других колонок

    CarTable.InsertItem(0, _T("Item 1")); // Добавление элементов в List Control
    CarTable.SetItemText(0, 1, _T("Description 1"));

    CarTable.InsertItem(1, _T("Item 2"));
    CarTable.SetItemText(1, 1, _T("Description 2"));
	
	}
	else {
		CarTable.DeleteAllItems();
	}
	if (pDoc->m_bDrivers == 1) {
		CRect rectListCtrl(30, 250, 300, 500); // Задаем координаты и размер List Control
		DriverTable.Create(WS_VISIBLE | WS_CHILD | LVS_REPORT, rectListCtrl, this, 0);

		DriverTable.InsertColumn(0, _T("Column 1"), LVCFMT_LEFT, 100); // Добавляем колонки
		DriverTable.InsertColumn(1, _T("Column 2"), LVCFMT_LEFT, 100);
		// ... добавление других колонок

		DriverTable.InsertItem(0, _T("Item 1")); // Добавление элементов в List Control
		DriverTable.SetItemText(0, 1, _T("Description 1"));

		DriverTable.InsertItem(1, _T("Item 2"));
		DriverTable.SetItemText(1, 1, _T("Description 2"));
	}
	if (pDoc->m_bfl == 1) {
		CRect rectListCtrl(30, 500, 300, 700); // Задаем координаты и размер List Control
		FLTable.Create(WS_VISIBLE | WS_CHILD | LVS_REPORT, rectListCtrl, this, 0);

		FLTable.InsertColumn(0, _T("Column 1"), LVCFMT_LEFT, 100); // Добавляем колонки
		FLTable.InsertColumn(1, _T("Column 2"), LVCFMT_LEFT, 100);
		// ... добавление других колонок

		FLTable.InsertItem(0, _T("Item 1")); // Добавление элементов в List Control
		FLTable.SetItemText(0, 1, _T("Description 1"));

		FLTable.InsertItem(1, _T("Item 2"));
		FLTable.SetItemText(1, 1, _T("Description 2"));
	}
	//MYSQL* conn;
	//conn = mysql_init(NULL);
	//if (conn == NULL)
	//{
	//	// Если дескриптор не получен – выводим сообщение об ошибке
	//	fprintf(stderr, "Error: can'tcreate MySQL-descriptor\n");

	//}
	//mysql_init(conn);
	//if (!mysql_real_connect(conn, "localhost", "root", "Stud813850!", "mydb", NULL, NULL, 0))
	//{
	//	// Если нет возможности установить соединение с сервером
	//	// базы данных выводим сообщение об ошибке
	//	printf("Error: can'tconnecttodatabase %s\n", mysql_error(conn));
	//}
	//else
	//{
	//	MessageBoxW(L"некит мразь");
	//}
	//mysql_set_character_set(conn, "utf8");

	



	

	



	// TODO: добавьте здесь код отрисовки для собственных данных
	//Invalidate(0);
}


// Печать CMy3sem17labaView

BOOL CMy3sem17labaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMy3sem17labaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMy3sem17labaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CMy3sem17labaView

#ifdef _DEBUG
void CMy3sem17labaView::AssertValid() const
{
	CView::AssertValid();
}

void CMy3sem17labaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3sem17labaDoc* CMy3sem17labaView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3sem17labaDoc)));
	return (CMy3sem17labaDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CMy3sem17labaView
