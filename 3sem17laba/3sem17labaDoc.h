
// 3sem17labaDoc.h: интерфейс класса CMy3sem17labaDoc 
//


#pragma once
class CMyList;
class CMyTreeView;
class CMy3sem17labaView;
class CMy3sem17labaDoc : public CDocument
{
protected: // создать только из сериализации
	CMy3sem17labaDoc() noexcept;
	DECLARE_DYNCREATE(CMy3sem17labaDoc)

// Атрибуты
public:
	CMy3sem17labaView* pView;
	CMyTreeView* pTree;

	bool m_bCars , m_bDrivers, m_bfl ;
// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CMy3sem17labaDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
