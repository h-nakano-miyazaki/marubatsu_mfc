
// marubatsuDlg.h : ヘッダー ファイル
//

#pragma once

#define DISP_MSG_CPUTURN	"CPUの番です。（考慮中...）"
#define DISP_MSG_YOURTURN	"あなたの番です。空いているマスをクリックしてください。"

// CmarubatsuDlg ダイアログ
class CmarubatsuDlg : public CDialogEx
{
// コンストラクション
public:
	CmarubatsuDlg(CWnd* pParent = NULL);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MARUBATSU_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート

	int turn_num;	// ターン数.
	bool senkoFlg;	// TRUE:先攻、FALSE:後攻.
	int rsltFlg;

	void EnebleField();
	void DisableField();

	// 枠1～9.
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

// 実装
protected:
	HICON m_hIcon;

	// フィールド状態.
	int m_field[9];

	// 生成された、メッセージ割り当て関数
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
