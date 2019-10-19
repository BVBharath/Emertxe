/*
Steps:

1. Create the socket.
2. Bind the socket to the particular port(OPTIONAL).
3. connect 
5. Send
6. Close
*/

#include "common.h"
#define SERVER_BUFFER		25
#define SERVER_IP			"127.0.0.1"
#define SERVER_PORT			5000
#define SERVER_QUEUE_SIZE	20

int main()
{
	int sockfd;
	int status;
	struct sockaddr_in serv_addr;
	char client_buffer[25];

	/* Create the TCP socket */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Socket");
		exit(1);
	}

	/* Bind : OPTIONAL */

	/* Populate the server details */
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serv_addr.sin_port = htons(SERVER_PORT);

	/* Connect:  */
	if ( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))== -1)
	{
		perror("Connect");
		exit(2);
	}
	
	/* Read the info from the user */
	printf("Enter the message: ");
	scanf("%[^\n]s", client_buffer);

	/* Receive the data */
	if (status = send(sockfd, client_buffer, 25, 0))
	{
		printf("Message sent SUCCESSFULLY\n");
	}
	else
	{
		printf("Message FAILED to send\n");
	}
	memset(client_buffer, 0, 25);
	
	printf("server is waiting\n");
	recv(sockfd, client_buffer, 25, 0);
	printf("%s\n", client_buffer);
	/* Close the fds */
	close(sockfd);
}


