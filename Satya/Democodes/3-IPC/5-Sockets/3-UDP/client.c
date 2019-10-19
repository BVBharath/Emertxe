/*
Steps:

1. Create the socket.
2. Bind the socket to the particular port(OPTIONAL).
3. Send
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
	int status;
	struct sockaddr_in serv_addr, cli_addr;
	char client_buffer[25];

	/* Create the TCP socket */
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		perror("Socket");
		exit(1);
	}

	/* Bind : OPTIONAL */

	/* Populate the server details */
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serv_addr.sin_port = htons(SERVER_PORT);

	/* Read the info from the user */
	printf("Enter the message: ");
	scanf("%[^\n]s", client_buffer);

	/* Receive the data */
	if (status = sendto(sockfd, client_buffer, 25, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr)))
	{
		printf("Message sent SUCCESSFULLY\n");
	}
	else
	{
		printf("Message FAILED to send\n");
	}

	/* Close the fds */
	close(sockfd);
}


