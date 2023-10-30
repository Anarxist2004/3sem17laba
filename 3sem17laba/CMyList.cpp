// CMyList.cpp: файл реализации
//

#include "pch.h"
#include "3sem17laba.h"
#include "CMyList.h"


// CMyList

IMPLEMENT_DYNAMIC(CMyList, CListCtrl)

CMyList::CMyList()
{
	Create(0, rect, this,0);
}

CMyList::~CMyList()
{

}


BEGIN_MESSAGE_MAP(CMyList, CListCtrl)
END_MESSAGE_MAP()



// Обработчики сообщений CMyList


