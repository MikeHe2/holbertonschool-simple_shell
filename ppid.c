#include "main.h"
/**
 * main - get parent process id
 *
 * Return: 0 always succesful
 *
*/

int main(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%u\n", my_ppid);
	return (0);
}
