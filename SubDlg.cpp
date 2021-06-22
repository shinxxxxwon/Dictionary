// SubDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Dictionary.h"
#include "SubDlg.h"
#include "afxdialogex.h"
#include "DictionaryDlg.h"

// SubDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(SubDlg, CDialogEx)

SubDlg::SubDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SubDlg::IDD, pParent)
{

}

SubDlg::~SubDlg()
{
}

void SubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_WORD, m_EDIT_WORD);
	DDX_Control(pDX, IDC_EDIT_MEAN, m_EDIT_MEAN);
}


BEGIN_MESSAGE_MAP(SubDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SubDlg::OnBnClickedOk)
	ON_WM_ACTIVATE()
END_MESSAGE_MAP()


// SubDlg 메시지 처리기입니다.


void SubDlg::OnBnClickedOk()
{
	m_EDIT_WORD.GetWindowText(m_strWord);
	m_EDIT_MEAN.GetWindowText(m_strMean);
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void SubDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	if(!m_strWord.IsEmpty() && !m_strMean.IsEmpty())
	{
		m_EDIT_WORD.SetWindowText(m_strWord);
		m_EDIT_MEAN.SetWindowText(m_strMean);
	}

	CDialogEx::OnActivate(nState, pWndOther, bMinimized);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
