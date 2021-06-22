// SubDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Dictionary.h"
#include "SubDlg.h"
#include "afxdialogex.h"
#include "DictionaryDlg.h"

// SubDlg ��ȭ �����Դϴ�.

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


// SubDlg �޽��� ó�����Դϴ�.


void SubDlg::OnBnClickedOk()
{
	m_EDIT_WORD.GetWindowText(m_strWord);
	m_EDIT_MEAN.GetWindowText(m_strMean);
	
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}
