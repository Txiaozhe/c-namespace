#include<stdio.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib") // 静态库
 
void findIP(char *ip, int size) 
{
	WORD v = MAKEWORD(1, 1);
	WSADATA wsaData;
	WSAStartup(v, &wsaData); // 加载套接字库
 
	struct hostent *phostinfo = gethostbyname("");
	char *p = inet_ntoa (* ((struct in_addr *)(*phostinfo->h_addr_list)) ); 				
	strncpy(ip, p, size - 1);
	ip[size - 1] = '\0';
	WSACleanup( );
} 
 
int main()
{
	char ip[20] = {0};
	findIP(ip, sizeof(ip));
	printf("%s\n", ip);
 
	return 0;
}
