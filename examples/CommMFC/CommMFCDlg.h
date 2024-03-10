// CommMFCDlg.h : ͷ�ļ�
//

#pragma once

#include <string>

//About CSerialPort start
#include "CSerialPort/SerialPort.h"
#include "CSerialPort/SerialPortInfo.h"
using namespace itas109;
//About CSerialPort end


// CCommMFCDlg �Ի���
class CCommMFCDlg : public CDialog, public CSerialPortListener // About CSerialPort 
{
// ����
public:
	CCommMFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_COMMMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	void onReadEvent(const char *portName, unsigned int readBufferLen); // About CSerialPort


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CComboBox m_PortNr;
	CComboBox m_BaudRate;
	CComboBox m_Parity;
	CComboBox m_Stop;
	CComboBox m_DataBits;
	CButton m_OpenCloseCtrl;
	CEdit m_Send;
	CEdit m_ReceiveCtrl;
	CStatic m_recvCountCtrl;
	CStatic m_sendCountCtrl;
	CEdit m_ReceiveTimeoutMSCtrl;
	UINT m_ReceiveTimeoutMS;

	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonOpenClose();
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedButtonClear();

private:
	CSerialPort m_SerialPort;//About CSerialPort 

	int rx; 
	int tx;	
public:
    CButton m_dtrCtrl;
    CButton m_rtsCtrl;
    afx_msg void OnBnClickedCheckDtr();
    afx_msg void OnBnClickedCheckRts();
};
