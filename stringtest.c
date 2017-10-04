#include <stdio.h>
#include <string.h>

int main()
{
	char test[] = "Hello";
	printf("%s\n", test);
	int i;
	for(i = 0; i < strlen(test); i++)
	{
		printf("%c\n", test[i]);
	}
}
