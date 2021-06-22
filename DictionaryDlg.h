
// DictionaryDlg.h : 헤더 파일
//
#ifndef _DICTIONARYDLG_H_
#define _DICTIONARYDLG_H_
#pragma once
#include "Contrller.h"
#include "afxwin.h"

// CDictionaryDlg 대화 상자
class CDictionaryDlg : public CDialogEx
{
// 생성입니다.
public:
	CDictionaryDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DICTIONARY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


public:
	afx_msg void OnBnClickedButtonInsert();
	afx_msg void OnLbnSelchangeListWord();
	afx_msg void OnBnClickedButtonRemove();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonTest();
	afx_msg void OnEnChangeEditSearch();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonLoad();

	char* m_szWord;
	char* m_szMean;

	CString m_strSearch;

	Info* node;
	Contrller* controller;

	CListBox m_ListBox_Word;
	CListBox m_ListBox_Mean;
	CEdit m_Edit_Search;

	void ShowWord(Info* node);
	void ShowMean(Info* node);
	void SearchWord(Info* node, char* word);
	afx_msg void OnDestroy();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
UINT ThreadLoad(LPVOID pParam);
UINT ThreadSave(LPVOID pParam);
#endif