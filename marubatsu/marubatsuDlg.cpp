
// marubatsuDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "marubatsu.h"
#include "marubatsuDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// �A�v���P�[�V�����̃o�[�W�������Ɏg���� CAboutDlg �_�C�A���O

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �_�C�A���O �f�[�^
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ����
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmarubatsuDlg �_�C�A���O



CmarubatsuDlg::CmarubatsuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MARUBATSU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmarubatsuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_BUTTON1, m_waku01);
	DDX_Text(pDX, IDC_BUTTON2, m_waku02);
	DDX_Text(pDX, IDC_BUTTON3, m_waku03);
	DDX_Text(pDX, IDC_BUTTON4, m_waku04);
	DDX_Text(pDX, IDC_BUTTON5, m_waku05);
	DDX_Text(pDX, IDC_BUTTON6, m_waku06);
	DDX_Text(pDX, IDC_BUTTON7, m_waku07);
	DDX_Text(pDX, IDC_BUTTON8, m_waku08);
	DDX_Text(pDX, IDC_BUTTON9, m_waku09);

	DDX_Text(pDX, IDC_MSG, m_msg);
}

BEGIN_MESSAGE_MAP(CmarubatsuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CmarubatsuDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CmarubatsuDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CmarubatsuDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CmarubatsuDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CmarubatsuDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CmarubatsuDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CmarubatsuDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CmarubatsuDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CmarubatsuDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CmarubatsuDlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CmarubatsuDlg ���b�Z�[�W �n���h���[

BOOL CmarubatsuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// IDM_ABOUTBOX �́A�V�X�e�� �R�}���h�͈͓̔��ɂȂ���΂Ȃ�܂���B
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// ����������.
	AllClear();
	DisableField();

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �t�B�[���h�\��.
void CmarubatsuDlg::DisplayField()
{
	// �t�B�[���h�̒l�ɏ]���ĉ�ʕ\��.
	for (int i=0;i<9;i++)
	{
		if (m_field[i] == 1)
		{
			switch (i)
			{
			case 0:
				m_waku01 = "��";
				break;
			case 1:
				m_waku02 = "��";
				break;
			case 2:
				m_waku03 = "��";
				break;
			case 3:
				m_waku04 = "��";
				break;
			case 4:
				m_waku05 = "��";
				break;
			case 5:
				m_waku06 = "��";
				break;
			case 6:
				m_waku07 = "��";
				break;
			case 7:
				m_waku08 = "��";
				break;
			case 8:
				m_waku09 = "��";
				break;
			default:
				break;
			}
		}
		else if (m_field[i] == 2)
		{
			switch (i)
			{
			case 0:
				m_waku01 = "�~";
				break;
			case 1:
				m_waku02 = "�~";
				break;
			case 2:
				m_waku03 = "�~";
				break;
			case 3:
				m_waku04 = "�~";
				break;
			case 4:
				m_waku05 = "�~";
				break;
			case 5:
				m_waku06 = "�~";
				break;
			case 6:
				m_waku07 = "�~";
				break;
			case 7:
				m_waku08 = "�~";
				break;
			case 8:
				m_waku09 = "�~";
				break;
			default:
				break;
			}
		}
	}
	UpdateData(FALSE);	// ��ʍX�V
}

// ��U��U����.
void CmarubatsuDlg::judgeSenko()
{
	int num = rand() % 2;
	if (num == 1)
	{
		senkoFlg = true;	// ��U.
	}
	else
	{
		senkoFlg = false;	// ��U.
	}
}

// CPU�^�[������.
void CmarubatsuDlg::CPUturn()
{
	// �I������.
	judgeResult();
	if (rsltFlg != 0)
	{
		gameEnd();
		return;
	}
	m_msg = DISP_MSG_CPUTURN;
	UpdateData(FALSE);	// ��ʍX�V

	// CPU�^�[�����̏���.
	turn_num++;
	Sleep(1000);

	CPUputon();
	DisplayField();

	// �I������.
	judgeResult();
	if (rsltFlg != 0)
	{
		gameEnd();
		return;
	}

	// �v���C���[�̃^�[������.
	EnebleField();
	m_msg = DISP_MSG_YOURTURN;
	UpdateData(FALSE);	// ��ʍX�V
}

void CmarubatsuDlg::gameEnd()
{
	// �Q�[���I��.
	DisableField();
	if (rsltFlg == 1)
	{
		m_msg = "�v���C���[�̏����I�I";
	}
	else if (rsltFlg == 2)
	{
		m_msg = "CPU�̏����I�I";
	}
	// �Q�[���J�n�{�^���������i�A���N���b�N�h�~�j.
	(CButton*)GetDlgItem(IDC_BUTTON10)->EnableWindow(TRUE);

	UpdateData(FALSE);	// ��ʍX�V
}

// CPU�u���ꔻ��.
void CmarubatsuDlg::CPUputon()
{
	while (1)
	{
		int num = rand() % 9;
		if (m_field[num] == 0)
		{
			m_field[num] = 2;
			break;
		}
	}
}

// ���s����.
void CmarubatsuDlg::judgeResult()
{
	// �c����.
	if ((m_field[0] == m_field[1]) && (m_field[0] == m_field[2]))
	{
		if (m_field[0] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[0] == 2)
		{
			rsltFlg = 2;
		}
	}
	if ((m_field[3] == m_field[4]) && (m_field[3] == m_field[5]))
	{
		if (m_field[3] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[3] == 2)
		{
			rsltFlg = 2;
		}
	}
	if ((m_field[6] == m_field[7]) && (m_field[6] == m_field[8]))
	{
		if (m_field[6] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[6] == 2)
		{
			rsltFlg = 2;
		}
	}

	// ������.
	if ((m_field[0] == m_field[3]) && (m_field[0] == m_field[6]))
	{
		if (m_field[0] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[0] == 2)
		{
			rsltFlg = 2;
		}
	}
	if ((m_field[1] == m_field[4]) && (m_field[1] == m_field[7]))
	{
		if (m_field[1] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[1] == 2)
		{
			rsltFlg = 2;
		}
	}
	if ((m_field[2] == m_field[5]) && (m_field[2] == m_field[8]))
	{
		if (m_field[2] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[2] == 2)
		{
			rsltFlg = 2;
		}
	}

	// �΂ߔ���.
	if ((m_field[0] == m_field[4]) && (m_field[0] == m_field[8]))
	{
		if (m_field[0] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[0] == 2)
		{
			rsltFlg = 2;
		}
	}
	if ((m_field[2] == m_field[4]) && (m_field[2] == m_field[6]))
	{
		if (m_field[2] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[2] == 2)
		{
			rsltFlg = 2;
		}
	}
}


// �t�B�[���h������.
void CmarubatsuDlg::DisableField()
{
	(CButton*)GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
}
// �t�B�[���h�L����.
void CmarubatsuDlg::EnebleField()
{
	(CButton*)GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
}


void CmarubatsuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CmarubatsuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N���C�A���g�̎l�p�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R���̕`��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ���[�U�[���ŏ��������E�B���h�E���h���b�O���Ă���Ƃ��ɕ\������J�[�\�����擾���邽�߂ɁA
//  �V�X�e�������̊֐����Ăяo���܂��B
HCURSOR CmarubatsuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CmarubatsuDlg::OnBnClickedButton1()
{
	m_field[0] = 1;
	DisplayField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton2()
{
	m_field[1] = 1;
	DisplayField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton3()
{
	m_field[2] = 1;
	DisplayField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton4()
{
	m_field[3] = 1;
	DisplayField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton5()
{
	m_field[4] = 1;
	DisplayField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton6()
{
	m_field[5] = 1;
	DisplayField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton7()
{
	m_field[6] = 1;
	DisplayField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton8()
{
	m_field[7] = 1;
	DisplayField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton9()
{
	m_field[8] = 1;
	DisplayField();
	CPUturn();
}

void CmarubatsuDlg::AllClear()
{
	rsltFlg = 0;

	turn_num = 0;
	for(int i=0;i<9;i++)
	{
		m_field[i] = 0;
	}

	m_waku01 = "";
	m_waku02 = "";
	m_waku03 = "";
	m_waku04 = "";
	m_waku05 = "";
	m_waku06 = "";
	m_waku07 = "";
	m_waku08 = "";
	m_waku09 = "";
	UpdateData(FALSE);	// ��ʍX�V
}




void CmarubatsuDlg::OnBnClickedButton10()
{
	AllClear();
	// ��U�Ȃ�CPU�����A��U�Ȃ烁�b�Z�[�W�\��.
	judgeSenko();
	if (senkoFlg == true)
	{
		EnebleField();
		m_msg = DISP_MSG_YOURTURN;
	}
	else
	{
		// CPU�������s.
		m_msg = DISP_MSG_CPUTURN;
		CPUturn();
	}
	UpdateData(FALSE);	// ��ʍX�V

	// �Q�[���J�n�{�^���������i�A���N���b�N�h�~�j.
	(CButton*)GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);

}