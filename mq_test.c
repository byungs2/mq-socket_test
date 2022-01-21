#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>

int main (int argc, char *argv[]) {
	int client_socket;
	client_socket = socket (PF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in server_addr;
	memset (&server_addr, 0, sizeof (server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons (5080);
	server_addr.sin_addr.s_addr = inet_addr ("10.7.114.110");
	connect (client_socket, (struct sockaddr *)&server_addr, sizeof (server_addr));
	write (client_socket, "OP_END", strlen("OP_END") + 1);
	close (client_socket);

	return 0;
}

