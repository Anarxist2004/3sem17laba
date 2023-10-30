#pragma once


// CMyList

class CMyList : public CListCtrl
{
	DECLARE_DYNAMIC(CMyList)

public:
	CMyList();
	RECT rect = {50,50,200,200};
	virtual ~CMyList();

protected:
	DECLARE_MESSAGE_MAP()
};


