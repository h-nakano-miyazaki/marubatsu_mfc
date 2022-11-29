
// marubatsuDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once

#define DISP_MSG_CPUTURN	"CPU�̔Ԃł��B�i�l����...�j"
#define DISP_MSG_YOURTURN	"���Ȃ��̔Ԃł��B�󂢂Ă���}�X���N���b�N���Ă��������B"

// CmarubatsuDlg �_�C�A���O
class CmarubatsuDlg : public CDialogEx
{
// �R���X�g���N�V����
public:
	CmarubatsuDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^�[

// �_�C�A���O �f�[�^
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MARUBATSU_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g

	int turn_num;	// �^�[����.
	bool senkoFlg;	// TRUE:��U�AFALSE:��U.
	int rsltFlg;

	void EnebleField();
	void DisableField();

	// �g1�`9.
	CString m_waku01;
	CString m_waku02;
	CString m_waku03;
	CString m_waku04;
	CString m_waku05;
	CString m_waku06;
	CString m_waku07;
	CString m_waku08;
	CString m_waku09;

	CString m_msg;

// ����
protected:
	HICON m_hIcon;

	// �t�B�[���h���.
	int m_field[9];

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	void judgeSenko();
	void CPUturn();
	void DisplayField();
	void CPUputon();
	void judgeResult();
	void gameEnd();

public:
	void AllClear();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
};
