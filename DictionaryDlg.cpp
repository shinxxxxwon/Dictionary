
// DictionaryDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Dictionary.h"
#include "DictionaryDlg.h"
#include "afxdialogex.h"
#include "SubDlg.h"
#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDictionaryDlg 대화 상자



CDictionaryDlg::CDictionaryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDictionaryDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDictionaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_WORD, m_ListBox_Word);
	DDX_Control(pDX, IDC_LIST_MEAN, m_ListBox_Mean);
	DDX_Control(pDX, IDC_EDIT_SEARCH, m_Edit_Search);
}

BEGIN_MESSAGE_MAP(CDictionaryDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CDictionaryDlg::OnBnClickedButtonInsert)
	ON_LBN_SELCHANGE(IDC_LIST_WORD, &CDictionaryDlg::OnLbnSelchangeListWord)
	ON_BN_CLICKED(IDC_BUTTON_REMOVE, &CDictionaryDlg::OnBnClickedButtonRemove)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CDictionaryDlg::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_TEST, &CDictionaryDlg::OnBnClickedButtonTest)
	ON_EN_CHANGE(IDC_EDIT_SEARCH, &CDictionaryDlg::OnEnChangeEditSearch)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CDictionaryDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CDictionaryDlg::OnBnClickedButtonLoad)
	ON_WM_DESTROY()
	ON_WM_VSCROLL()
END_MESSAGE_MAP()


// CDictionaryDlg 메시지 처리기

BOOL CDictionaryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CDictionaryDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CDictionaryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDictionaryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CDictionaryDlg::OnBnClickedButtonInsert()
{
	SubDlg subDlg;	
	if(subDlg.DoModal() == IDOK)
	{
		m_szWord = (LPSTR)(LPCSTR)subDlg.m_strWord;
		m_szMean = (LPSTR)(LPCSTR)subDlg.m_strMean;

		node = controller->InsertNode(node, m_szWord, m_szMean);
	}
	m_ListBox_Word.ResetContent();
	ShowWord(node);
}

void CDictionaryDlg::OnBnClickedButtonRemove()
{
	int nSel = m_ListBox_Word.GetCurSel();
	CString str;
	m_ListBox_Word.GetText(nSel, str);
	char* szTemp = new char[str.GetLength()+1];
	strcpy(szTemp, str);
	node = controller->Delete(node, szTemp);
	delete[] szTemp;
	m_ListBox_Word.ResetContent();
	m_ListBox_Mean.ResetContent();
	ShowWord(node);
}


void CDictionaryDlg::ShowWord(Info* node)
{
	if(node != NULL)
	{
		if(m_ListBox_Word.GetCount() > 999)
		{
			return;
		}
		ShowWord(node->left);
		m_ListBox_Word.InsertString(-1, node->szWord);
		ShowWord(node->right);
	}
}

void CDictionaryDlg::ShowMean(Info* node)
{
	int nSel = m_ListBox_Word.GetCurSel();
	CString str;
	m_ListBox_Word.GetText(nSel, str);
	char* szTemp = new char[str.GetLength()+1];
	strcpy(szTemp, str);

	if(node != NULL)
	{
		ShowMean(node->left);
		if(strcmp(node->szWord, szTemp) == 0)
		{
			m_ListBox_Mean.InsertString(-1, node->szMean);
		}
		ShowMean(node->right);
	}
	delete[] szTemp;
}

void CDictionaryDlg::OnLbnSelchangeListWord()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ListBox_Mean.ResetContent();
	ShowMean(node);
}


void CDictionaryDlg::OnBnClickedButtonEdit()
{
	int nSel = m_ListBox_Word.GetCurSel();
	CString str;
	m_ListBox_Word.GetText(nSel, str);

	node = controller->Search(node, (LPSTR)(LPCSTR)str);
	SubDlg subDlg;
	subDlg.m_strWord = node->szWord;
	subDlg.m_strMean = node->szMean;
	char arrTemp[100];
	strcpy(arrTemp, subDlg.m_strWord);
	if(subDlg.DoModal() == IDOK)
	{
		char arrWord[100];
		char arrMean[100];

		strcpy(arrWord, (LPSTR)(LPCSTR)subDlg.m_strWord);
		strcpy(arrMean, (LPSTR)(LPCSTR)subDlg.m_strMean);

		strcpy(node->szWord, arrWord);
		strcpy(node->szMean, arrMean);

		//OnBnClickedButtonLoad();
		//node = controller->Delete(node, arrTemp);
		m_ListBox_Word.ResetContent();
		m_ListBox_Mean.ResetContent();
		ShowWord(node);
	}

}


void CDictionaryDlg::OnBnClickedButtonTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ListBox_Word.ResetContent();
	ShowWord(node);
}


void CDictionaryDlg::SearchWord(Info* node, char* word)
{
	char *szTemp;
	if(node != NULL)
	{
		szTemp = strstr(node->szWord, word);
		SearchWord(node->left, word);
		CString str;
		m_Edit_Search.GetWindowText(str);

		if(str == TEXT(""))
		{
			
			m_ListBox_Word.ResetContent();
			ShowWord(node);
			return;
		}

		if(m_ListBox_Word.GetCount() > 999)
		{
			return;
		}

		if(szTemp != NULL)
		{
			node = controller->Search(node, szTemp);
			m_ListBox_Word.InsertString(-1, node->szWord);
			int n = GetLastError();
			CString st;
			st.Format(TEXT("%d"), n);
			//MessageBox(st);
		}
		SearchWord(node->right, word);
	}
}

void CDictionaryDlg::OnEnChangeEditSearch()
{
	m_Edit_Search.GetWindowText(m_strSearch);
	m_ListBox_Word.ResetContent();
	m_ListBox_Mean.ResetContent();

	SearchWord(node, (LPSTR)(LPCSTR)m_strSearch);
	int n = GetLastError();
	CString str;
	str.Format(TEXT("%d"), n);
	//MessageBox(str);

	//if(!AfxBeginThread(ThreadSearch, this))
	//{
	//	MessageBox("Search Thread Error");
	//}
}


void CDictionaryDlg::OnBnClickedButtonSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	/*if(!AfxBeginThread(ThreadSave, this))
	{
		MessageBox("Thread Save Error");
	}*/

	CFileFind finder;
	FILE* pFile_out;

	BOOL bChkDir = finder.FindFile(_T("../Dictonary_DATA"));

	if(!bChkDir)
	{
		CreateDirectory(_T("../Dictonary_DATA"), NULL);
	}

	pFile_out = fopen(_T("../Dictonary_DATA/Dictionary_DATA.dat"),_T( "wb"));
	if(node != NULL)
	{
		controller->Save(node, pFile_out);
		fclose(pFile_out);
		MessageBox(TEXT("저장 완료!"));
	}
	else
	{
		MessageBox(TEXT("단어가 입력되어 있지 않습니다."));
	}
}



void CDictionaryDlg::OnBnClickedButtonLoad()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/*if(!AfxBeginThread(ThreadLoad, this))
	{
		MessageBox("Load실패");
	}*/
	FILE* pFile_in;

	pFile_in = fopen(TEXT("../Dictonary_DATA/Dictionary_DATA.dat"), TEXT("rb"));
	if(pFile_in != NULL)
	{
		node = controller->Load(node, pFile_in);
		fclose(pFile_in);
		ShowWord(node);
	}
	else
	{
		MessageBox(TEXT("데이터 파일이 없습니다."));
	}

}

UINT ThreadLoad(LPVOID pParam)
{
	FILE* pFile_in;

	CDictionaryDlg *pDlg = (CDictionaryDlg*)pParam;

	pFile_in = fopen(TEXT("../Dictonary_DATA/Dictionary_DATA.dat"), TEXT("rb"));
	pDlg->node = pDlg->controller->Load(pDlg->node, pFile_in);
	fclose(pFile_in);
	pDlg->ShowWord(pDlg->node);
	pDlg->MessageBox(TEXT("불러오기 완료!"));
	return 1;
}

UINT ThreadSave(LPVOID pParam)
{
	CFileFind finder;
	FILE* pFile_out;

	CDictionaryDlg *pDlg = (CDictionaryDlg*)pParam;

	BOOL bChkDir = finder.FindFile(_T("../Dictonary_DATA"));

	if(!bChkDir)
	{
		CreateDirectory(_T("../Dictonary_DATA"), NULL);
	}

	pFile_out = fopen(TEXT("../Dictonary_DATA/Dictionary_DATA.dat"), TEXT("wb"));
	pDlg->controller->Save(pDlg->node, pFile_out);

	fclose(pFile_out);

	pDlg->MessageBox(TEXT("저장 완료!"));

	return 1;
}

void CDictionaryDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	free(node);
}


void CDictionaryDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}
