
// Dictionary.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CDictionaryApp:
// �� Ŭ������ ������ ���ؼ��� Dictionary.cpp�� �����Ͻʽÿ�.
//

class CDictionaryApp : public CWinApp
{
public:
	CDictionaryApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CDictionaryApp theApp;