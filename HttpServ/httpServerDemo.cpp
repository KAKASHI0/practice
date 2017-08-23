// HttpServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Winsock2.h>
#include <cstdio>

#pragma comment(lib,"ws2_32.lib")

void main()
{
	char sendBuf[1024];//�������ͻ��˵��ַ���
	char recvBuf[1024];//���ܿͻ��˷��ص��ַ���
	WSADATA wsaData;
	SOCKET sockServer;
	SOCKADDR_IN addrServer;
	SOCKET sockClient;
	SOCKADDR_IN addrClient;
	WSAStartup(MAKEWORD(2,2),&wsaData);
	sockServer=socket(AF_INET,SOCK_STREAM,0);
	addrServer.sin_addr.S_un.S_addr=htonl(INADDR_ANY);//INADDR_ANY��ʾ�κ�IP
	addrServer.sin_family=AF_INET;
	addrServer.sin_port=htons(8000);//�󶨶˿�6000
	bind(sockServer,(SOCKADDR*)&addrServer,sizeof(SOCKADDR));

	//Listen������
	listen(sockServer,1);//5Ϊ�ȴ�������Ŀ
	printf("������������:\n������...\n");
	int len=sizeof(SOCKADDR);
	
	while(1)
	{
		//���������̣�ֱ���пͻ�����������Ϊֹ
		sockClient=accept(sockServer,(SOCKADDR*)&addrClient,&len);
		//���ղ���ӡ�ͻ�������
		recv(sockClient,recvBuf,1024,0);
		//printf("+=====+%s\n",recvBuf);
		sprintf_s(sendBuf,"HTTP/1.1 200 OK\nContent-Type:text/html\nServer:myserver\n\n hello World\n");		
		send(sockClient,sendBuf,strlen(sendBuf),0);
		closesocket(sockClient);
	}
	

	//�ر�socket
	closesocket(sockClient);
	WSACleanup();
}

