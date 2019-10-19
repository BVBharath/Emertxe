/*
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main()
{
	struct addrinfo *res;
	char node;
	char service;
	struct addrinfo hints;
	
	/* Set Family,
	1. AF_INET - IPv4
	2. AF_INET6 - IPv6
	3. AF_UNSPEC
	*/
	hints.ai_family = AF_UNSPEC;
	
	/* Set the preferred socket type.
	1. SOCK_STREAM
	2. SOCK_DTREAM
	*/
	hints.ai_socktype = SOCK_STREAM;

	/*Set the protocol
	0 indicates any protocol can be return by this function
	*/

	/*
	Set the flags
	*/
	hints.ai_flags = AI_PASSIVE;

	


	getaddrinfo(&node, &service, &hints, &res);

	printf("Node: %d\n", node);
	printf("Service: %d\n", service);

	printf("Socket Type: %d\n", hints.ai_socktype);
}
