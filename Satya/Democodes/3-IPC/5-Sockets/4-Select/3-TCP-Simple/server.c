/*
Steps:

1. Create the socket.
2. Bind the socket to the particular port.
3. Listen now
4. Accept
5. Receive
6. Close
*/

#include "common.h"
#define SERVER_BUFFER		25
#define SERVER_IP			"127.0.0.1"
#define SERVER_PORT			5000
#define SERVER_QUEUE_SIZE	20

int main()
{
	int sockfd, new_sockfd;
	struct sockaddr_in serv_addr;
	char server_buffer[25];
	fd_set rdfds;
    struct timeval tv;
	
	/* Create the TCP socket */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
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

	/* Listen */
	if (listen(sockfd, SERVER_QUEUE_SIZE) == -1)
	{
		perror("Listen");
		exit(3);
	}
	
	FD_ZERO (&rdfds);
	FD_SET (sockfd, &rdfds);

	tv.tv_sec = 7;
	tv.tv_usec = 0;
			
	/* Accept */
	if ((new_sockfd = accept(sockfd, (struct sockaddr *) NULL, NULL)) == -1)
	{
		perror("Accept");
		exit(4);
	}

	int rv = select(sockfd + 1, &rdfds, NULL, NULL, &tv);

	if (rv == 0)
	{
		printf("Time out occured\n");
	}
	else
	{
		//if (FD_ISSET(sockfd, &rdfds))
		{
			/* Receive the data */
			recv(new_sockfd, server_buffer, 25, 0);

			/* Print the message */
			printf("%s\n", server_buffer);

			FD_SET (sockfd, &rdfds);
		}

	}

	/* Close the fds */
	close(sockfd);
	close(new_sockfd);
}


