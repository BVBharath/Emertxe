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
	int sockfd, new_sockfd, status;
	struct sockaddr_in serv_addr;
	char server_buffer[25];

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

while(1)
{

		/* Accept */
		if ((new_sockfd = accept(sockfd, (struct sockaddr *) NULL, NULL)) == -1)
		{
			perror("Accept");
			exit(4);
		}
		pid_t pid = fork();

		if (pid == 0)
		{
			/* Receive the data */
			recv(new_sockfd, server_buffer, 25, 0);

			/* Print the message */
			printf("%s\n", server_buffer);
			memset(server_buffer, 0, 25);

			/* Close the fds */
		//close(new_sockfd);

			/* Exit */
		//	exit(0);
		}
		else
		{
			wait(0);
			printf("enter the message\n");
			scanf("%s", server_buffer);

			if(status = send(sockfd, server_buffer, 25, 0))
			{
				printf("message sent successfull\n");

			}
			else
			{
				printf("message was not sent successfully\n");

			}

		}


			close(new_sockfd);
	}

		close(sockfd);
}


