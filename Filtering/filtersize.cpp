// filtersize.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Filtering.h"
#include "filtersize.h"
#include "afxdialogex.h"
#include "F_Select.h"

int Filtersize = 0;
CString m_strTmpFile;
// filtersize �Ի���

IMPLEMENT_DYNAMIC(filtersize, CDialogEx)

filtersize::filtersize(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_filtersize, pParent)
{

}

filtersize::~filtersize()
{
}

void filtersize::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_filtersize, m_filtersize);
}


BEGIN_MESSAGE_MAP(filtersize, CDialogEx)
	ON_EN_CHANGE(IDC_filtersize, &filtersize::OnEnChangefiltersize)
	ON_BN_CLICKED(IDC_outdir, &filtersize::OnBnClickedoutdir)
	ON_BN_CLICKED(IDOK, &filtersize::OnBnClickedOk)
	ON_EN_CHANGE(IDC_dirshow, &filtersize::OnEnChangedirshow)
	ON_BN_CLICKED(IDCANCEL, &filtersize::OnBnClickedCancel)
END_MESSAGE_MAP()


// filtersize ��Ϣ�������


void filtersize::OnEnChangefiltersize()
{
	CString str;
	m_filtersize.GetWindowText(str);
	Filtersize = _tstoi(str);
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void filtersize::OnBnClickedoutdir()
{
	CString strFilter;
	strFilter = "dat file (*.jpg)|*.jpg; *.png||";
	if (Mfilter_num==1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("��ֵ�˲�"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//��ȡ�ļ�·��
			m_strTmpFile = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile);
		}
	}
	if (MDfilter_num==1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("��ֵ�˲�"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//��ȡ�ļ�·��
			m_strTmpFile = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile);
		}
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void filtersize::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void filtersize::OnEnChangedirshow()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void filtersize::OnBnClickedCancel()
{
	Filtersize = 0;
	CString m_strTmpFile = _T("");
	EndDialog(IDCANCEL);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
