
// Filtering.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFilteringApp: 
// �йش����ʵ�֣������ Filtering.cpp
//

class CFilteringApp : public CWinApp
{
public:
	CFilteringApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFilteringApp theApp;