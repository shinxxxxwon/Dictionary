#ifndef _SUBDLG_H_
#define _SUBDLG_H_
#include "afxwin.h"
#include <string>
#pragma once


// SubDlg 대화 상자입니다.

class SubDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SubDlg)

public:
	SubDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SubDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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