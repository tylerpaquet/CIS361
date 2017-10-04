#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * removeDuplicates(char word[]);
int targetFound(char charArray[], int num, char target);
void initializeEncryptArray(char key[], char encrypt[]);
void initializeDecryptArray(char encrypt[], char decrypt[]);
void processingInput(FILE  * inf, FILE * outf, char substitute[]);

int main(int argc, char* argv[])
{
    char encrypt[26], decrypt[26];
    int choice;
    char * keyString = argv[2];
    FILE *fin, *fout;

    choice = atoi(argv[1]);

    fin = fopen(argv[3], "r");
    fout = fopen(argv[4], "w");

    if(choice == 1)
    {
        initializeEncryptArray(keyString, encrypt);
        processingInput(fin, fout, encrypt);
    }
    if(choice == 2)
    {
        initializeEncryptArray(keyString, encrypt);
        initializeDecryptArray(encrypt, decrypt);
        processingInput(fin, fout, decrypt);
    }
    

}

char * removeDuplicates(char word[])
{
    int end = 1;
    int length = strlen(word);
    int current;
    int i;
    current = 1;

    for(end = 1; end < length; end++)
    {
        for(i = 0; i < end; i++)
        {
            if(word[end] == word[i])
                break;
        }

        if(i == end)
        {
            word[current] = word[i];
            current++;
        }
    }

    word[current] = 0;
    return word;
}

int targetFound(char charArray[], int num, char target)
{
    return 0;
}

void initializeEncryptArray(char key[], char encrypt[])
{
    key = removeDuplicates(key);
    int keylength = strlen(key);
    int i;
    for(i = 0; i < keylength; i++)
    {
        encrypt[i] = (toupper(key[i]));
    }
    char ch ='Z';
    for(i = keylength; i < (26 + keylength); i++)
    {
        encrypt[i] = ch;
        ch--;
    }
    removeDuplicates(encrypt);
}

void initializeDecryptArray(char encrypt[], char decrypt[])
{
    int i;
    for(i = 0; i < 26; i++)
    {
        decrypt[encrypt[i] - 65] = 65 + i;
    }
}

void processingInput(FILE  * inf, FILE * outf, char substitute[])
{
    char ch;
    if (inf ==  NULL || outf == NULL)
    {
        printf("File could not be opened\n");
        exit(1);
    }

    while(fscanf(inf, "%c", &ch) != EOF)
    {
        if(isalpha(ch))
        {
            if(isupper(ch))
            {
                fprintf(outf, "%c", substitute[ch - 65]);
            }
            if(islower(ch))
            {
                fprintf(outf, "%c", tolower(substitute[ch - 97]));
            }

        }
        else
        {
           fprintf(outf, "%c", ch);
        }
    }

    fclose(inf);
    fclose(outf);
}