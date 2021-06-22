#ifndef _SUBDLG_H_
#define _SUBDLG_H_
#include "afxwin.h"
#include <string>
#pragma once


// SubDlg ��ȭ �����Դϴ�.

class SubDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SubDlg)

public:
	SubDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SubDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CString m_strWord;
	CString m_strMean;

	CEdit m_EDIT_WORD;
	CEdit m_EDIT_MEAN;

	afx_msg void OnBnClickedOk();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
};

#endif