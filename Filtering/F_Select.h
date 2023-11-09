#pragma once

#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>

extern CString m_strTmpFile0;

extern int Mfilter_num ;
extern int Blfilter_num;
extern int Elfilter_num;
extern int Ilfilter_num;
extern int Bhfilter_num;
extern int Ehfilter_num;
extern int Ihfilter_num;
extern int Sharpen_num;
extern int MDfilter_num;

// F_Select 对话框

class F_Select : public CDialogEx
{
	DECLARE_DYNAMIC(F_Select)

public:
	F_Select(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~F_Select();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Select };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedMeanfilter();
	afx_msg void OnBnClickedCmedianfilter();
	afx_msg void OnBnClickedSharpen();
	afx_msg void OnBnClickedIhighfilter();
	afx_msg void OnBnClickedEhighfilter();
	afx_msg void OnBnClickedBhighfilter();
	afx_msg void OnBnClickedIlowfilter();
	afx_msg void OnBnClickedElowfilter();
	afx_msg void OnBnClickedBlowfilter();
	afx_msg void f_Mfilter();
	afx_msg void f_Blfilter();
	afx_msg void f_Elfilter();
	afx_msg void f_Ilfilter();
	afx_msg void f_Bhfilter();
	afx_msg void f_Ehfilter();
	afx_msg void f_Ihfilter();
	afx_msg void f_Sharpen();
	afx_msg void f_MDfilter();
	afx_msg void OnBnClickedCancel();
	

private:
	void fftshift(cv::Mat &plane0, cv::Mat &plane1);
	cv::Mat frequency_filter(cv::Mat &scr, cv::Mat &blur);
	cv::Mat image_make_border(cv::Mat &src);
	cv::Mat ideal_high_kernel(cv::Mat &scr, float sigma);
	cv::Mat ideal_high_pass_filter(cv::Mat &src, float sigma);
	cv::Mat butterworth_high_pass_filter(cv::Mat &src, float d0, int n);
	cv::Mat butterworth_high_kernel(cv::Mat &scr, float sigma, int n);
	void ILPF(CvMat * src, const double D0);
	IplImage* maINDA(IplImage* im, double D0);
	cv::Mat ideal_low_kernel(cv::Mat & scr, float sigma);
	cv::Mat ideal_low_pass_filter(cv::Mat & src, float sigma);
	cv::Mat butterworth_low_pass_filter(cv::Mat & src, float d0, int n);
	cv::Mat butterworth_low_kernel(cv::Mat & src, float sigma, int n);
};
