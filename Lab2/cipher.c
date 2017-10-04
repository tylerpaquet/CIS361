#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char encrypt(char ch, int k);

int main(int argc, char* argv[])
{  
	int choice;
	char ch;
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf ("Usage: cipher option key infile, outfile\n");
		printf ("Option 1 for encryption and 2 for decryption");
		exit(1);
	}
	
	choice = atoi(argv[1]);
	char * keyString = argv[2];
	int key[100];
	int i;
	int size = 0;
	

	for(i = 0; keyString[i] != '\0' ; i++)
	{
		key[i] = keyString[i] - 65;
		size++;
	}

	if (choice == 2)
	{
		int i;
		for(i = 0; i < size; i++)
		{
			key[i] = key[i] * -1;
		}
	}

    	fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");
    
    	if (fin ==  NULL || fout == NULL) 
	{
		printf("File could not be opened\n");
		exit(1);
	}
	
	int count = 0;
	while ( fscanf(fin, "%c", &ch) != EOF )
	{
		fprintf(fout, "%c", encrypt(ch, key[count%size]));
		count++;
	}

	fclose(fin);
	fclose(fout);

	return 0;
}

char encrypt(char ch, int k)
{
	if ( k < 0 )
		k = k + 26;

	if ( isupper(ch) )
		return (ch - 'A' + k) % 26 + 'A';
	
	if ( islower(ch) )
		return (ch - 'a' + k) % 26 + 'a';
	
	return ch;
}
