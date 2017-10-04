#include <stdio.h>
#include <string.h>

#define LEN 4

char* strnsub (char *p, int n);

int main()
{
	char line[] = "His textbook was bought from that bookstore";  
	char *p1, *p2;

	p1 = line;
	
	while ( *p1 != '\0' && p1 != NULL) 	
	{
		p2 = p1 + 1;
		
		while ( *p2 != '\0' && p2 != NULL)	
		{
			if(strncmp(p1, p2, LEN) == 0)
			{
				goto done;
			}	
				
			p2++;

		}

		p1++;
	}

done:	printf ("the first substring: %s\n", strnsub(p1, LEN));
	printf ("the second substring: %s\n", strnsub(p2, LEN));

	return 0;
}

char* strnsub (char *p, int n)
{
	char substr[n];
	char * ptr;
	
	strncpy(substr, p, n);
	substr[n] = '\0';

	ptr = substr;
	return ptr;

}
