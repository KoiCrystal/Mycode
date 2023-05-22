#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<string.h>
#include<stdbool.h>
static int make_socket_non_blocking(int fd)
{
	/*
	fd :file descriptor
	fd flags
	F_GETFL :is used to get fd status flags
	*/

	int flag;
	/*get fd status flag*/
	flag = fcntl(fd, F_GETFL, 0);
	if (flag == -1)
	{
		perror("get fd status error");
		return -1;
	}

	/*modify the flag*/
	flag |= O_NONBLOCK;

	/*set the flag*/
	if(fcntl(fd, F_SETFL, flag) == -1)
	{
		perror("set flag error");
		return -1;
	}
	return 0;
}

int main()
{
	int listensock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP );
	if (listensock_fd == -1)
	{
		perror("Open listensock_fd error");
		return -1;
	}

	/*re-use address*/
	int on = 0;
	setsockopt(listensock_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));


	/*local server address*/
	struct sockaddr_in server_addr;
	memset(&server_addr,0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(8000);

	if(bind(listensock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
	{
		perror("bind port error");
		return 0;
	}

	if (make_socket_non_blocking(listensock_fd) == -1)
	{
		perror("listensock_fd non blocking error");
		return 0;
	}

	if(listen(listensock_fd, 1000))
	{
		perror("start listen");
		return 0;
	}

	/*there is only a demo for accept*/

	/*information for client socket*/
	struct sockaddr_in client_addr;
	while(true)
	{
		socklen_t clientaddr_len = sizeof(client_addr);
		int conn_sock = accept(listensock_fd, (struct sockaddr*)&client_addr, &clientaddr_len);
		if (conn_sock>=0)
		{
			printf("6666");
		}
		
			


	}
	
		

}


