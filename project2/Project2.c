#include <stdio.h>
#include <ctype.h>
#include "list.h"

int main(int argc, char* argv[])
{
    FILE *fin, *fout;
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");

    char line[256];
    char ident[100] = "";

    int i = 1;
    while(fgets(line, sizeof(line), fin))
    {
        if(line[0] == '}')
        {
            goto print;
        }
        char c;
        int j;
        int readflag = 1;
        int nextidentflag = 0;
        for(j = 0; line[j] != '\n'; j++)
        {
            if(readflag == 0)
            {
                if(line[j-2] == '*' && line[j-1] == '/')
                {
                    readflag = 1;
                }

                if(line[j] == '"')
                {
                    readflag = 1;
                }
            }

            if(readflag == 1)
            {
                if(line[j] == '/' && line[j+1] == '*')
                {
                    readflag = 0;
                }

                if(line[j] == '"')
                {
                    readflag = 0;
                }

                if(!isalnum(line[j+1]))
                {
                    nextidentflag = 1;
                }

            }

            if(readflag == 1)
            {
                if(isalnum(line[j]))
                {
                    ident[strlen(ident)] = line[j];
                }
                if(nextidentflag == 1)
                {
                    insert(i, ident);
                    memset(ident,0,strlen(ident));
                    nextidentflag = 0;
                }
            }
        }
        insert(i, ident);
        memset(ident,0,strlen(ident));
        i++;


    }
    print:
    printlist(fout);
}

