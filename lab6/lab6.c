#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXLINE 80
#define MAXARG  20

void background (char * cmd);

int main()
{
    char cmd[MAXLINE];

    for(; ;)
    {
        printf("mysh$ ");
        fgets(cmd, MAXLINE, stdin);

        if(strcmp(cmd, "exit\n") == 0)
        {
            exit(0);
        }
        else
        {
            int i = fork();
            if(i == 0)
            {
                background(cmd);
            }
        }
	
	wait();
    }
}

void background (char * cmd)
{
    int i = 0;
    char *argv[MAXARG];
    char *token;
    token = strtok(cmd, "\t\n");

    while(token != NULL)
    {
        argv[i] = token;
        token = strtok(NULL, "\t\n");
        i++;
    }
    
    argv[i] = NULL;

    execvp(argv[0], &argv[0]);
    printf("Unknown command\n");
}

