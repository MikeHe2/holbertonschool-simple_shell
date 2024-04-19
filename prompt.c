#include "main.h" 

/**
 * 
 * 
 * 
 * 
*/

int main()
{
	ssize_t read;
	char *buffer = NULL, *token;
	char *delim = " ";
	size_t size = 0;

	while(1)
	{
		printf("$ ");
		read = getline(&buffer, &size, stdin);
		if (read == -1)
		{
			printf("C ya later, don't forget your coffee!\n");
			free(buffer);
			return(0);
		}
		token = strtok(buffer, delim);
		while (token != NULL)
		{
			printf("%s", token);
			token = strtok(NULL, delim);
		}
		
	}
	return (0);
}