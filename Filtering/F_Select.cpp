// F_Select.cpp : 实现文件
//

#include "stdafx.h"
#include "Filtering.h"
#include "F_Select.h"
#include "afxdialogex.h"
#include "FilteringDlg.h"

#include "filtersize.h"
#include "Filepath.h"
#include "TThreshold.h"
#include "TThreshold2.h"

#include <opencv2/opencv.hpp> 
#include<opencv2/highgui/highgui.hpp> 

using namespace std;
using namespace cv;

int Mfilter_num = 0;
int Blfilter_num = 0;
int Elfilter_num = 0;
int Ilfilter_num = 0;
int Bhfilter_num = 0;
int Ehfilter_num = 0;
int Ihfilter_num = 0;
int Sharpen_num = 0;
int MDfilter_num = 0;

CString m_strTmpFile0 = _T("");

// F_Select 对话框

IMPLEMENT_DYNAMIC(F_Select, CDialogEx)


F_Select::F_Select(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Select, pParent)
{

}

F_Select::~F_Select()
{
}

void F_Select::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(F_Select, CDialogEx)
	ON_BN_CLICKED(IDOK, &F_Select::OnBnClickedOk)
	ON_BN_CLICKED(IDC_Meanfilter, &F_Select::OnBnClickedMeanfilter)
	ON_BN_CLICKED(IDCMedianfilter, &F_Select::OnBnClickedCmedianfilter)
	ON_BN_CLICKED(IDC_Sharpen, &F_Select::OnBnClickedSharpen)
	ON_BN_CLICKED(IDC_Ihighfilter, &F_Select::OnBnClickedIhighfilter)
	ON_BN_CLICKED(IDC_Ehighfilter, &F_Select::OnBnClickedEhighfilter)
	ON_BN_CLICKED(IDC_Bhighfilter, &F_Select::OnBnClickedBhighfilter)
	ON_BN_CLICKED(IDC_Ilowfilter, &F_Select::OnBnClickedIlowfilter)
	ON_BN_CLICKED(IDC_Elowfilter, &F_Select::OnBnClickedElowfilter)
	ON_BN_CLICKED(IDC_Blowfilter, &F_Select::OnBnClickedBlowfilter)
	ON_BN_CLICKED(IDCANCEL, &F_Select::OnBnClickedCancel)
END_MESSAGE_MAP()


// F_Select 消息处理程序


void F_Select::OnBnClickedOk()
{
	if (Mfilter_num == 0 && Blfilter_num == 0 && Elfilter_num == 0 && Ilfilter_num == 0 && Bhfilter_num == 0 && Ehfilter_num == 0 && Ihfilter_num == 0 && Sharpen_num == 0 && MDfilter_num == 0) {
		int result = MessageBox(TEXT("请选择操作方式"), TEXT("提示"), MB_OK);
	}
	if (Mfilter_num == 1) {
		f_Mfilter();
	}
		if (Blfilter_num == 1) {
			f_Blfilter();
		}

		if (Elfilter_num == 1) {
			f_Elfilter();
		}

		if (Ilfilter_num == 1) {
			f_Ilfilter();
		}

		if (Bhfilter_num == 1) {
			f_Bhfilter();
		}

		if (Ehfilter_num == 1) {
			f_Ehfilter();
		}

		if (Ihfilter_num == 1) {
			f_Ihfilter();
		}

		if (Sharpen_num == 1) {
			f_Sharpen();
		}

		if (MDfilter_num == 1) {
			f_MDfilter();
		}


		// TODO: 在此添加控件通知处理程序代码
		CDialogEx::OnOK();
}

void F_Select::OnBnClickedMeanfilter()
{
	Mfilter_num = 1;
	// TODO: 在此添加控件通知处理程序代码
}



void F_Select::OnBnClickedCmedianfilter()
{
	Mfilter_num = 0;
	Blfilter_num = 0;
	Elfilter_num = 0;
	Ilfilter_num = 0;
	Bhfilter_num = 0;
	Ehfilter_num = 0;
	Ihfilter_num = 0;
	Sharpen_num = 0;
	MDfilter_num = 0;
	MDfilter_num = 1;
	// TODO: 在此添加控件通知处理程序代码
}


void F_Select::OnBnClickedSharpen()
{
	Mfilter_num = 0;
	Blfilter_num = 0;
	Elfilter_num = 0;
	Ilfilter_num = 0;
	Bhfilter_num = 0;
	Ehfilter_num = 0;
	Ihfilter_num = 0;
	Sharpen_num = 0;
	MDfilter_num = 0;
	Sharpen_num = 1;
	// TODO: 在此添加控件通知处理程序代码
}


void F_Select::OnBnClickedIhighfilter()
{
	Mfilter_num = 0;
	Blfilter_num = 0;
	Elfilter_num = 0;
	Ilfilter_num = 0;
	Bhfilter_num = 0;
	Ehfilter_num = 0;
	Ihfilter_num = 0;
	Sharpen_num = 0;
	MDfilter_num = 0;
	Ihfilter_num = 1;
	// TODO: 在此添加控件通知处理程序代码
}


void F_Select::OnBnClickedEhighfilter()
{
	Mfilter_num = 0;
	Blfilter_num = 0;
	Elfilter_num = 0;
	Ilfilter_num = 0;
	Bhfilter_num = 0;
	Ehfilter_num = 0;
	Ihfilter_num = 0;
	Sharpen_num = 0;
	MDfilter_num = 0;
	Ehfilter_num = 1;
	// TODO: 在此添加控件通知处理程序代码
}


void F_Select::OnBnClickedBhighfilter()
{
	Mfilter_num = 0;
	Blfilter_num = 0;
	Elfilter_num = 0;
	Ilfilter_num = 0;
	Bhfilter_num = 0;
	Ehfilter_num = 0;
	Ihfilter_num = 0;
	Sharpen_num = 0;
	MDfilter_num = 0;
	Bhfilter_num = 1;
	// TODO: 在此添加控件通知处理程序代码
}


void F_Select::OnBnClickedIlowfilter()
{
	Mfilter_num = 0;
	Blfilter_num = 0;
	Elfilter_num = 0;
	Ilfilter_num = 0;
	Bhfilter_num = 0;
	Ehfilter_num = 0;
	Ihfilter_num = 0;
	Sharpen_num = 0;
	MDfilter_num = 0;
	Ilfilter_num = 1;
	// TODO: 在此添加控件通知处理程序代码
}


void F_Select::OnBnClickedElowfilter()
{
	Mfilter_num = 0;
	Blfilter_num = 0;
	Elfilter_num = 0;
	Ilfilter_num = 0;
	Bhfilter_num = 0;
	Ehfilter_num = 0;
	Ihfilter_num = 0;
	Sharpen_num = 0;
	MDfilter_num = 0;
	Elfilter_num = 1;
	// TODO: 在此添加控件通知处理程序代码
}


void F_Select::OnBnClickedBlowfilter()
{
	Mfilter_num = 0;
	Blfilter_num = 0;
	Elfilter_num = 0;
	Ilfilter_num = 0;
	Bhfilter_num = 0;
	Ehfilter_num = 0;
	Ihfilter_num = 0;
	Sharpen_num = 0;
	MDfilter_num = 0;
	Blfilter_num = 1;
	// TODO: 在此添加控件通知处理程序代码
}


void F_Select::f_Mfilter()
{
	Filtersize = 0;
	D0 = -1;
	D1 = -1;
	a = -1;
	m_strTmpFile = _T("");
	m_strTmpFile0 = _T("");
	m_strTmpFile1 = _T("");
	m_strTmpFile2 = _T("");
	m_strTmpFile3 = _T("");
	
	filtersize safAS;
	safAS.DoModal();
	CString Ctttm_strTmpFile = m_strTmpFile;
	m_strTmpFile0 = m_strTmpFile;
	if (m_strTmpFile0.IsEmpty() || Filtersize == 0) {
		AfxMessageBox(_T("请重新输入参数"));
		return;
	}
	CStringA outstra((TCHAR  *)(LPCTSTR)(Ctttm_strTmpFile));
	string tttm_strTmpFile((char  *)(LPCSTR)(outstra));

	// 获取输出文件路径并转换为string类型
	CStringA stra((TCHAR  *)(LPCTSTR)(infilename));
	string str((char  *)(LPCSTR)(stra));

	// 读取原始图像
	cv::Mat image = cv::imread(str, 1);

	// 定义滤波后的图像
	cv::Mat img_jingxiang;

	// 对原始图像进行均值滤波
	cv::blur(image, img_jingxiang, cv::Size(Filtersize, Filtersize));

	// 保存滤波后的图像
	imwrite(tttm_strTmpFile, img_jingxiang);
	int result = MessageBox(TEXT("操作完成"), TEXT("提示"), MB_OK);


}


void  F_Select::f_Blfilter() 
{
	Filtersize = 0;
	D0 = -1;
	D1 = -1;
	a = -1;
	m_strTmpFile = _T("");
	m_strTmpFile0 = _T("");
	m_strTmpFile1 = _T("");
	m_strTmpFile2 = _T("");
	m_strTmpFile3 = _T("");

	TThreshold2 safAS;
	safAS.DoModal();
	CString Ctttm_strTmpFile = m_strTmpFile3;
	m_strTmpFile0 = m_strTmpFile3;
	if (m_strTmpFile0.IsEmpty() || D1 < 0 || a<0) {
		AfxMessageBox(_T("请重新输入参数"));
		return; // 如果m_strTmpFile0为空，则不执行任何代码并返回
	}
	CStringA outstra((TCHAR*)(LPCTSTR)(Ctttm_strTmpFile));
	std::string tttm_strTmpFile((char*)(LPCSTR)(outstra));
	CStringA stra((TCHAR*)(LPCTSTR)(infilename));
	std::string str((char*)(LPCSTR)(stra));

	cv::Mat src = cv::imread(str, 0); // 读取灰度图像
	cv::Mat img_jingxiang = butterworth_low_pass_filter(src, D1, a);
	cv::imwrite(tttm_strTmpFile, img_jingxiang);
	int result = MessageBox(TEXT("操作完成"), TEXT("提示"), MB_OK);

	// 空函数
}

void  F_Select::f_Elfilter() 
{

	Filtersize = 0;
	D0 = -1;
	D1 = -1;
	a = -1;
	m_strTmpFile = _T("");
	m_strTmpFile0 = _T("");
	m_strTmpFile1 = _T("");
	m_strTmpFile2 = _T("");
	m_strTmpFile3 = _T("");

	TThreshold safAS;
	safAS.DoModal();
	CString Ctttm_strTmpFile = m_strTmpFile2;
	m_strTmpFile0 = m_strTmpFile2;
	if (m_strTmpFile0.IsEmpty() || D0 < 0) {
		AfxMessageBox(_T("请重新输入参数"));
		return; // 如果m_strTmpFile0为空，则不执行任何代码并返回
	}
	CStringA outstra((TCHAR  *)(LPCTSTR)(Ctttm_strTmpFile));
	string tttm_strTmpFile((char  *)(LPCSTR)(outstra));
	CStringA stra((TCHAR  *)(LPCTSTR)(infilename));
	IplImage * src;
	src = cvLoadImage(stra, CV_LOAD_IMAGE_GRAYSCALE);
	IplImage * bwimage1 = maINDA(src, D0);
	cvSaveImage(outstra, bwimage1);
	int result = MessageBox(TEXT("操作完成"), TEXT("提示"), MB_OK);
	// 空函数
}

void  F_Select::f_Ilfilter()
{
	Filtersize = 0;
	D0 = -1;
	D1 = -1;
	a = -1;
	m_strTmpFile = _T("");
	m_strTmpFile0 = _T("");
	m_strTmpFile1 = _T("");
	m_strTmpFile2 = _T("");
	m_strTmpFile3 = _T("");

	TThreshold safAS;
	safAS.DoModal();
	CString Ctttm_strTmpFile = m_strTmpFile2;
	m_strTmpFile0 = m_strTmpFile2;
	if (m_strTmpFile0.IsEmpty() || D0 < 0) {
		AfxMessageBox(_T("请重新输入参数"));
		return; // 如果m_strTmpFile0为空，则不执行任何代码并返回
	}
	CStringA outstra((TCHAR  *)(LPCTSTR)(Ctttm_strTmpFile));
	string tttm_strTmpFile((char  *)(LPCSTR)(outstra));
	CStringA stra((TCHAR  *)(LPCTSTR)(infilename));
	string str((char  *)(LPCSTR)(stra));
	cv::Mat src = cv::imread(str, 0);
	Mat img_jingxiang = ideal_low_pass_filter(src, D0);
	imwrite(tttm_strTmpFile, img_jingxiang);
	int result = MessageBox(TEXT("操作完成"), TEXT("提示"), MB_OK);
	// 空函数
}

void  F_Select::f_Bhfilter() 
{
	Filtersize = 0;
	D0 = -1;
	D1 = -1;
	a = -1;
	m_strTmpFile = _T("");
	m_strTmpFile0 = _T("");
	m_strTmpFile1 = _T("");
	m_strTmpFile2 = _T("");
	m_strTmpFile3 = _T("");

	TThreshold2 safAS;
	safAS.DoModal();
	CString Ctttm_strTmpFile = m_strTmpFile3;
	m_strTmpFile0 = m_strTmpFile3;
	if (m_strTmpFile0.IsEmpty() || D1 < 0 || a<0) {
		AfxMessageBox(_T("请重新输入参数"));
		return; // 如果m_strTmpFile0为空，则不执行任何代码并返回
	}
	CStringA outstra((TCHAR*)(LPCTSTR)(Ctttm_strTmpFile));
	std::string tttm_strTmpFile((char*)(LPCSTR)(outstra));
	CStringA stra((TCHAR*)(LPCTSTR)(infilename));
	std::string str((char*)(LPCSTR)(stra));

	cv::Mat src = cv::imread(str, 0);
	cv::Mat img_jingxiang;
	float D1 = 5.0f;
	img_jingxiang = butterworth_high_pass_filter(src, D1, a);
	cv::imwrite(tttm_strTmpFile, img_jingxiang);
	int result = MessageBox(TEXT("操作完成"), TEXT("提示"), MB_OK);
	// 空函数
}

void F_Select::f_Ehfilter()
{
	Filtersize = 0;
	D0 = -1;
	D1 = -1;
	a = -1;
	m_strTmpFile = _T("");
	m_strTmpFile0 = _T("");
	m_strTmpFile1 = _T("");
	m_strTmpFile2 = _T("");
	m_strTmpFile3 = _T("");

	TThreshold safAS;
	safAS.DoModal();
	CString Ctttm_strTmpFile = m_strTmpFile2;
	m_strTmpFile0 = m_strTmpFile2;
	if (m_strTmpFile0.IsEmpty() || D0 < 0) {
		AfxMessageBox(_T("请重新输入参数"));
		return; // 如果m_strTmpFile0为空，则不执行任何代码并返回
	}
	CStringA outstra((TCHAR  *)(LPCTSTR)(Ctttm_strTmpFile));
	string tttm_strTmpFile((char  *)(LPCSTR)(outstra));
	CStringA stra((TCHAR  *)(LPCTSTR)(infilename));
	IplImage * src;
	src = cvLoadImage(stra, CV_LOAD_IMAGE_GRAYSCALE);
	double D0 = 8;
	IplImage * bwimage1 = maINDA(src, D0);
	cvSaveImage(outstra, bwimage1);
	int result = MessageBox(TEXT("操作完成"), TEXT("提示"), MB_OK);
	// 空函数
}


void F_Select::f_Ihfilter()
{
	Filtersize = 0;
	D0 = -1;
	D1 = -1;
	a = -1;
	m_strTmpFile = _T("");
	m_strTmpFile0 = _T("");
	m_strTmpFile1 = _T("");
	m_strTmpFile2 = _T("");
	m_strTmpFile3 = _T("");

	TThreshold safAS;
	safAS.DoModal();
	CString Ctttm_strTmpFile = m_strTmpFile2;
	m_strTmpFile0 = m_strTmpFile2;
	if (m_strTmpFile0.IsEmpty() || D0 < 0) {
		AfxMessageBox(_T("请重新输入参数"));
		return; // 如果m_strTmpFile0为空，则不执行任何代码并返回
	}
	CStringA outstra((TCHAR  *)(LPCTSTR)(Ctttm_strTmpFile));
	string tttm_strTmpFile((char  *)(LPCSTR)(outstra));
	CStringA stra((TCHAR  *)(LPCTSTR)(infilename));
	string str((char  *)(LPCSTR)(stra));
	cv::Mat src = cv::imread(str, 0);
	Mat img_jingxiang = ideal_high_pass_filter(src, D0);;
	imwrite(tttm_strTmpFile, img_jingxiang);
	int result = MessageBox(TEXT("操作完成"), TEXT("提示"), MB_OK);
}


void  F_Select::f_Sharpen() 
{
	Filtersize = 0;
	D0 = -1;
	D1 = -1;
	a = -1;
	m_strTmpFile = _T("");
	m_strTmpFile0 = _T("");
	m_strTmpFile1 = _T("");
	m_strTmpFile2 = _T("");
	m_strTmpFile3 = _T("");

	Filepath safAS;
	safAS.DoModal();
	CString Ctttm_strTmpFile = m_strTmpFile1;
	m_strTmpFile0 = m_strTmpFile1;
	if (m_strTmpFile0.IsEmpty()) {
		AfxMessageBox(_T("请重新输入参数"));
		return;
	}
	CStringA outstra((TCHAR*)(LPCTSTR)(Ctttm_strTmpFile));
	string tttm_strTmpFile((char*)(LPCSTR)(outstra));

	CStringA stra((TCHAR*)(LPCTSTR)(infilename));
	string str((char*)(LPCSTR)(stra));

	cv::Mat image = cv::imread(str, 1);

	cv::Mat img_jingxiang;
	int rows = image.rows;        // 原图的行
	int cols = image.cols * image.channels();   // 原图的列
	int offsetx = image.channels();       // 像素点的偏移量

	img_jingxiang = Mat::ones(image.rows - 2, image.cols - 2, image.type());

	char arith[9] = { 0, -1, 0, -1, 5, -1, 0, -1, 0 };

	for (int i = 1; i < rows - 1; i++)
	{
		const uchar* previous = image.ptr<uchar>(i - 1);
		const uchar* current = image.ptr<uchar>(i);
		const uchar* next = image.ptr<uchar>(i + 1);
		uchar* output = img_jingxiang.ptr<uchar>(i - 1);

		for (int j = offsetx; j < cols - offsetx; j++)
		{
			output[j - offsetx] = saturate_cast<uchar>(previous[j - offsetx] * arith[0] + previous[j] * arith[1] + previous[j + offsetx] * arith[2] +
				current[j - offsetx] * arith[3] + current[j] * arith[4] + current[j + offsetx] * arith[5] +
				next[j - offsetx] * arith[6] + next[j] * arith[7] + next[j - offsetx] * arith[8]);
		}
	}

	imwrite(tttm_strTmpFile, img_jingxiang);
	int result = MessageBox(TEXT("操作完成"), TEXT("提示"), MB_OK);

	// 空函数
}

void  F_Select::f_MDfilter() 
{
	Filtersize = 0;
	D0 = -1;
	D1 = -1;
	a = -1;
	m_strTmpFile = _T("");
	m_strTmpFile0 = _T("");
	m_strTmpFile1 = _T("");
	m_strTmpFile2 = _T("");
	m_strTmpFile3 = _T("");

	filtersize safAS;
	safAS.DoModal();
	
	CString Ctttm_strTmpFile = m_strTmpFile;
	m_strTmpFile0 = m_strTmpFile;
	if (m_strTmpFile0.IsEmpty() || Filtersize == 0) {
		AfxMessageBox(_T("请重新输入参数"));
		return;
	}
	CStringA outstra((TCHAR*)(LPCTSTR)(Ctttm_strTmpFile));
	string tttm_strTmpFile((char*)(LPCSTR)(outstra));
	CStringA stra((TCHAR*)(LPCTSTR)(infilename));
	string str((char*)(LPCSTR)(stra));

	cv::Mat image = cv::imread(str, 1);
	cv::Mat img_jingxiang;
	if (Filtersize % 2 == 0)
	{
		Filtersize = Filtersize - 1;
	}
	medianBlur(image, img_jingxiang, Filtersize);
	imwrite(tttm_strTmpFile, img_jingxiang);
	int result = MessageBox(TEXT("操作完成"), TEXT("提示"), MB_OK);
	// 空函数
}


void F_Select::OnBnClickedCancel()
{
	// 关闭对话框
	EndDialog(IDCANCEL);
}

void F_Select::fftshift(cv::Mat &plane0, cv::Mat &plane1)
{
	int cx = plane0.cols / 2;
	int cy = plane0.rows / 2;
	cv::Mat part1_r(plane0, cv::Rect(0, 0, cx, cy));
	cv::Mat part2_r(plane0, cv::Rect(cx, 0, cx, cy));
	cv::Mat part3_r(plane0, cv::Rect(0, cy, cx, cy));
	cv::Mat part4_r(plane0, cv::Rect(cx, cy, cx, cy));
	cv::Mat temp;
	part1_r.copyTo(temp);
	part4_r.copyTo(part1_r);
	temp.copyTo(part4_r);
	part2_r.copyTo(temp);
	part3_r.copyTo(part2_r);
	temp.copyTo(part3_r);
	cv::Mat part1_i(plane1, cv::Rect(0, 0, cx, cy));
	cv::Mat part2_i(plane1, cv::Rect(cx, 0, cx, cy));
	cv::Mat part3_i(plane1, cv::Rect(0, cy, cx, cy));
	cv::Mat part4_i(plane1, cv::Rect(cx, cy, cx, cy));
	part1_i.copyTo(temp);
	part4_i.copyTo(part1_i);
	temp.copyTo(part4_i);
	part2_i.copyTo(temp);
	part3_i.copyTo(part2_i);
	temp.copyTo(part3_i);
}

cv::Mat F_Select::frequency_filter(cv::Mat &scr, cv::Mat &blur)
{
	cv::Mat mask = scr == scr;
	scr.setTo(0.0f, ~mask);

	cv::Mat plane[] = { scr.clone(), cv::Mat::zeros(scr.size() , CV_32FC1) };
	cv::Mat complexIm;
	cv::merge(plane, 2, complexIm);
	cv::dft(complexIm, complexIm);

	cv::split(complexIm, plane);

	fftshift(plane[0], plane[1]);

	cv::Mat blur_r, blur_i, BLUR;
	cv::multiply(plane[0], blur, blur_r);
	cv::multiply(plane[1], blur, blur_i);
	cv::Mat plane1[] = { blur_r, blur_i };

	fftshift(plane1[0], plane1[1]);
	cv::merge(plane1, 2, BLUR);

	cv::idft(BLUR, BLUR);
	BLUR = BLUR / BLUR.rows / BLUR.cols;

	cv::split(BLUR, plane);

	return plane[0];
}

cv::Mat F_Select::image_make_border(cv::Mat &src)
{
	int w = cv::getOptimalDFTSize(src.cols);
	int h = cv::getOptimalDFTSize(src.rows);

	cv::Mat padded;
	cv::copyMakeBorder(src, padded, 0, h - src.rows, 0, w - src.cols,
		cv::BORDER_CONSTANT, cv::Scalar::all(0));
	padded.convertTo(padded, CV_32FC1);

	return padded;
}

cv::Mat F_Select::ideal_high_kernel(cv::Mat &scr, float sigma)
{
	cv::Mat ideal_high_pass(scr.size(), CV_32FC1);
	float d0 = sigma;
	for (int i = 0; i < scr.rows; i++) {
		for (int j = 0; j < scr.cols; j++) {
			double d = sqrt(pow((i - scr.rows / 2), 2) + pow((j - scr.cols / 2), 2));
			if (d <= d0) {
				ideal_high_pass.at<float>(i, j) = 0;
			}
			else {
				ideal_high_pass.at<float>(i, j) = 1;
			}
		}
	}
	return ideal_high_pass;
}

cv::Mat F_Select::ideal_high_pass_filter(cv::Mat &src, float sigma)
{
	cv::Mat padded = image_make_border(src);
	cv::Mat ideal_kernel = ideal_high_kernel(padded, sigma);
	cv::Mat result = frequency_filter(padded, ideal_kernel);
	return result;
}

cv::Mat F_Select::butterworth_high_pass_filter(cv::Mat &src, float d0, int n)
{
	cv::Mat padded = image_make_border(src);
	cv::Mat butterworth_kernel = butterworth_high_kernel(padded, d0, n);
	cv::Mat result = frequency_filter(padded, butterworth_kernel);
	return result;
}

cv::Mat F_Select::butterworth_high_kernel(cv::Mat &scr, float sigma, int n)
{
	cv::Mat butterworth_high_pass(scr.size(), CV_32FC1);
	float D0 = (float)sigma;
	for (int i = 0; i < scr.rows; i++) {
		for (int j = 0; j < scr.cols; j++) {
			float d = sqrt(pow(float(i - scr.rows / 2), 2) + pow(float(j - scr.cols / 2), 2));
			butterworth_high_pass.at<float>(i, j) = 1.0f - 1.0f / (1.0f + pow(d / D0, 2 * n));
		}
	}
	return butterworth_high_pass;
}

void  F_Select::ILPF(CvMat* src, const double D0) {
	int i, j;
	int state = -1;
	double tempD;

	long width, height;
	width = src->width;
	height = src->height;

	long x, y;
	x = width / 2;
	y = height / 2;

	CvMat* H_mat;
	H_mat = cvCreateMat(src->height, src->width, CV_64FC2);

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i > y && j > x) {
				state = 3;
			}
			else if (i > y) {
				state = 1;
			}
			else if (j > x) {
				state = 2;
			}
			else {
				state = 0;
			}

			switch (state) {
			case 0:
				tempD = (double)(i * i + j * j);
				tempD = sqrt(tempD);
				break;
			case 1:
				tempD = (double)((height - i) * (height - i) + j * j);
				tempD = sqrt(tempD);
				break;
			case 2:
				tempD = (double)(i * i + (width - j) * (width - j));
				tempD = sqrt(tempD);
				break;
			case 3:
				tempD = (double)((height - i) * (height - i) + (width - j) * (width - j));
				tempD = sqrt(tempD);
				break;
			default:
				break;
			}

			tempD = exp(-pow(D0 / tempD, 2));

			((double*)(H_mat->data.ptr + H_mat->step * i))[j * 2] = tempD;
			((double*)(H_mat->data.ptr + H_mat->step * i))[j * 2 + 1] = 0.0;
		}
	}

	cvMulSpectrums(src, H_mat, src, CV_DXT_ROWS);
	cvReleaseMat(&H_mat);
}


IplImage * F_Select::maINDA(IplImage * im, double D0) 
{
	IplImage* bwimage1;
	IplImage* realInput;
	IplImage* imaginaryInput;
	IplImage* complexInput;
	int dft_M, dft_N;
	CvMat* dft_A, tmp, *dft_B;
	IplImage* image_Re;
	IplImage* image_Im;
	double m, M;

	// 输入图像是灰度图
	dft_M = cvGetOptimalDFTSize(im->height - 1);
	dft_N = cvGetOptimalDFTSize(im->width - 1);
	dft_B = cvCreateMat(dft_M, dft_N, CV_64FC2);
	dft_A = cvCreateMat(dft_M, dft_N, CV_64FC2);
	cvZero(dft_A);
	cvZero(dft_B);

	// 先把im扩充，之后赋值就不需要扩充。根据图的需要，这里扩充白色边界，在im中也就是cvScalar(255) 
	// 扩充的颜色值应该与背景颜色一致，否则会在背景与前景相接的位置检测到多余的轮廓。 
	IplImage* large_img = cvCreateImage(cvSize(dft_N, dft_M), IPL_DEPTH_8U, 1); // IPL_DEPTH_8U-----uchar 
	cvCopyMakeBorder(im, large_img, cvPoint((dft_N - im->width) / 2, (dft_M - im->height) / 2), IPL_BORDER_CONSTANT, cvScalar(255)); // 0表示黑色）

	realInput = cvCreateImage(cvSize(dft_N, dft_M), IPL_DEPTH_64F, 1);
	imaginaryInput = cvCreateImage(cvSize(dft_N, dft_M), IPL_DEPTH_64F, 1);
	complexInput = cvCreateImage(cvSize(dft_N, dft_M), IPL_DEPTH_64F, 2);
	// 高通滤波之前，需要转化成double，实部输入就是灰度图本身，虚部是空，合并为复变量complexInput，这时尺寸已经满足要求 
	cvScale(large_img, realInput, 1.0, 0.0);
	cvZero(imaginaryInput);
	cvMerge(realInput, imaginaryInput, NULL, NULL, complexInput);

	// 把数据直接裁剪到中心位置 
	cvGetSubRect(dft_A, &tmp, cvRect(0, 0, complexInput->width, complexInput->height));
	cvCopy(complexInput, &tmp, NULL);

	// DFT变换，高通滤波，DFT反变换 
	cvDFT(dft_A, dft_A, CV_DXT_FORWARD, complexInput->height);
	ILPF(dft_A, D0);
	cvDFT(dft_A, dft_A, CV_DXT_INVERSE, complexInput->height);

	// 取出实部 
	image_Re = cvCreateImage(cvSize(dft_N, dft_M), IPL_DEPTH_64F, 1);
	image_Im = cvCreateImage(cvSize(dft_N, dft_M), IPL_DEPTH_64F, 1);
	cvSplit(dft_A, image_Re, image_Im, 0, 0);
	IplImage* uint8image = cvCreateImage(cvGetSize(image_Re), IPL_DEPTH_8U, 1);
	cvMinMaxLoc(image_Re, &m, &M, NULL, NULL, NULL);
	cvConvertScale(image_Re, uint8image, 255 / (M - m), 255 * (-m) / (M - m));

	// 二值化 
	bwimage1 = cvCreateImage(cvGetSize(uint8image), IPL_DEPTH_8U, 1); // 二值图像 
	cvAdaptiveThreshold(uint8image, bwimage1, 255, CV_ADAPTIVE_THRESH_MEAN_C, 0, 11, 10.0);
	return bwimage1;
}

cv::Mat F_Select::ideal_low_kernel(cv::Mat& src, float sigma) {
	cv::Mat ideal_low_pass(src.size(), CV_32FC1);
	float d0 = sigma; // 半径D0越小，模糊越大；半径D0越大，模糊越小

	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			double d = sqrt(pow((i - src.rows / 2), 2) + pow((j - src.cols / 2), 2)); // 分子，计算pow必须为float型

			if (d <= d0) {
				ideal_low_pass.at<float>(i, j) = 1;
			}
			else {
				ideal_low_pass.at<float>(i, j) = 0;
			}
		}
	}

	return ideal_low_pass;
}


cv::Mat F_Select::ideal_low_pass_filter(cv::Mat& src, float sigma) {
	cv::Mat padded = image_make_border(src);
	cv::Mat ideal_kernel = ideal_low_kernel(padded, sigma);
	cv::Mat result = frequency_filter(padded, ideal_kernel);
	return result;
}

cv::Mat F_Select::butterworth_low_pass_filter(cv::Mat& src, float d0, int n) {
	// H = 1 / (1+(D/D0)^2n)，n表示巴特沃斯滤波器的次数
	// 阶数n=1 无振铃和负值，阶数n=2 轻微振铃和负值，阶数n=5 明显振铃和负值，阶数n=20 与ILPF相似
	cv::Mat padded = image_make_border(src);
	cv::Mat butterworth_kernel = butterworth_low_kernel(padded, d0, n);
	cv::Mat result = frequency_filter(padded, butterworth_kernel);
	return result;
}

cv::Mat F_Select::butterworth_low_kernel(cv::Mat& src, float sigma, int n) {
	cv::Mat butterworth_low_pass(src.size(), CV_32FC1);
	float D0 = sigma; // 半径D0越小，模糊越大；半径D0越大，模糊越小
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			float d = sqrt(pow(float(i - src.rows / 2), 2) + pow(float(j - src.cols / 2), 2)); // 分子，计算pow必须为float型
			butterworth_low_pass.at<float>(i, j) = 1.0f / (1.0f + pow(d / D0, 2 * n));
		}
	}
	return butterworth_low_pass;
}


