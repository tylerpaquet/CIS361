#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch;
	int word_count = 0;
	int symbol_count = 0;
	int word = 0;
	int symbol = 0;
	
	/*FILE *fin, *fout;
	fin = fopen("lab1b.dat", "r");
	fout = fopen("lab1b.out", "w");
	if(fin == NULL || fout == NULL)
	{
		printf("file could not be opened\n");
		//exit(1);
	}*/

	printf("Enter text (Ctrl-D to quit).\n");
	
	while(ch = getchar())
	{

		if(ch == EOF)
			break;
		if(isalnum(ch) || ch == '_')
		{
			word++;
			if(symbol == 1)
				symbol = 0;		
		}

		if(!(isalnum(ch) || ch == '_') && !(isspace(ch)))
		{
			symbol++;
			if(word == 1)
				word = 0;
		}
		
		else if((isspace(ch)) || (ch=='\n')){
            //printf(" ");
            if(word > 1){
                word_count++;
                word = 0;
                if(symbol < 2) symbol = 0;
            }
            if(symbol > 1){
                symbol_count++;
                word = 0;
                symbol = 0;
            }
            else{
                word = 0;
                symbol = 0;
            }
        }
		
	}

	printf("\nThere are %d words\n", word_count);
    printf("There are %d symbol sequences\n", symbol_count);
	return 0;
}
