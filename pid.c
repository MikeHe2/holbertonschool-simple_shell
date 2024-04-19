#include "main.h"
/**
 * main - prints process id
 *
 * Return: 0 always succesful
 *
*/

int main(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("%u\n", my_pid);
	return (0);
}
