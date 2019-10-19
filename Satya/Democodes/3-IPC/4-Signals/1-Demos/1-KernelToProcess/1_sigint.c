/*
1. Processes can send signals with each other.
2. Ex:-SIGINT, which is defined in signal.h
*/

#include <stdio.h>

int main()
{
	puts("Type: Ctrl + c");
	while(1);
}
