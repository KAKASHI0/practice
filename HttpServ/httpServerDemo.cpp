// HttpServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Winsock2.h>
#include <cstdio>

#pragma comment(lib,"ws2_32.lib")

void main()
{
	char sendBuf[1024];//发送至客户端的字符串
	char recvBuf[1024];//接受客户端返回的字符串
	WSADATA wsaData;
	SOCKET sockServer;
	SOCKADDR_IN addrServer;
	SOCKET sockClient;
	SOCKADDR_IN addrClient;
	WSAStartup(MAKEWORD(2,2),&wsaData);
	sockServer=socket(AF_INET,SOCK_STREAM,0);
	addrServer.sin_addr.S_un.S_addr=htonl(INADDR_ANY);//INADDR_ANY表示任何IP
	addrServer.sin_family=AF_INET;
	addrServer.sin_port=htons(8000);//绑定端口6000
	bind(sockServer,(SOCKADDR*)&addrServer,sizeof(SOCKADDR));

	//Listen监听端
	listen(sockServer,1);//5为等待连接数目
	printf("服务器已启动:\n监听中...\n");
	int len=sizeof(SOCKADDR);
	
	while(1)
	{
		//会阻塞进程，直到有客户端连接上来为止
		sockClient=accept(sockServer,(SOCKADDR*)&addrClient,&len);
		//接收并打印客户端数据
		recv(sockClient,recvBuf,1024,0);
		//printf("+=====+%s\n",recvBuf);
		sprintf_s(sendBuf,"HTTP/1.1 200 OK\nContent-Type:text/html\nServer:myserver\n\n hello World\n");		
		send(sockClient,sendBuf,strlen(sendBuf),0);
		closesocket(sockClient);
	}
	

	//关闭socket
	closesocket(sockClient);
	WSACleanup();
}

