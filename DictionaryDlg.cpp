
// DictionaryDlg.cpp : ���� ����
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


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CDictionaryDlg ��ȭ ����



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


// CDictionaryDlg �޽��� ó����

BOOL CDictionaryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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
	
	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CDictionaryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

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
		MessageBox(TEXT("���� �Ϸ�!"));
	}
	else
	{
		MessageBox(TEXT("�ܾ �ԷµǾ� ���� �ʽ��ϴ�."));
	}
}



void CDictionaryDlg::OnBnClickedButtonLoad()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	/*if(!AfxBeginThread(ThreadLoad, this))
	{
		MessageBox("Load����");
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
		MessageBox(TEXT("������ ������ �����ϴ�."));
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
	pDlg->MessageBox(TEXT("�ҷ����� �Ϸ�!"));
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

	pDlg->MessageBox(TEXT("���� �Ϸ�!"));

	return 1;
}

void CDictionaryDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	free(node);
}


void CDictionaryDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}
