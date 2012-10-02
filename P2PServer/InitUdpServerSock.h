////////////////////////////////////////////////////////////////////////////////
// 서브시스템  : 
// 프로그램 ID : InitUdpServerSock.h
// 기능요약    : UDP Server
// 작성일      : 2003.11.14
// 작성자      : 이용휴
// 수정일	   : 2009.07.15
// 수정자      : 신상우
// 수정내역    : 리눅스용에서 윈도우용으로 수정
////////////////////////////////////////////////////////////////////////////////

#ifndef __INITUDPSERVERSOCK_H__
#define __INITUDPSERVERSOCK_H__

////////////////////////////////////////////////////////////////////////////////
//
extern BOOL SetSockOptionSendBuffSize(SOCKET nDesc, int nSize);
extern BOOL SetSockOptionRecvBuffSize(SOCKET nDesc, int nSize);

////////////////////////////////////////////////////////////////////////////////
//
extern BOOL InitUdpServerSock(UINT, SOCKET*);
extern void UninitUdpServerSock(SOCKET);

#endif

