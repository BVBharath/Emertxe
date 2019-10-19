/*
Steps:

1. Create the socket.
2. Bind the socket to the particular port.
3. Receive
4. Close
*/

#include "common.h"
#define SERVER_BUFFER		25
#define SERVER_IP			"127.0.0.1"
#define SERVER_PORT			6000
#define SERVER_QUEUE_SIZE	20

int main()
{
	int sockfd;
	int cli_len;
	struct sockaddr_in serv_addr, cli_addr;
	char server_buffer[25];

	/* Create the TCP socket */
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		perror("Socket");
		exit(1);
	}

	/* Bind */
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serv_addr.sin_port = htons(SERVER_PORT);

	if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
	{
		perror("Bind");
		exit(2);
	}

	/* Prompt the user */
	printf("Satya: Server is waiting\n");

	/* Receive the data */
	cli_len = sizeof(struct sockaddr_in);
	recvfrom(sockfd, server_buffer, 25, 0, (struct sockaddr *)&cli_addr, &cli_len);

	/* Print the message */
	printf("%s\n", server_buffer);

	/* Close the fds */
	close(sockfd);
}


