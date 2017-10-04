#include <ctype.h>
#include "list.h"


struct node {
    char *ident;
    struct queue linenums;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void insert(int linenum, char ident[])
{
    struct node *link = (struct node*)malloc(sizeof(struct node));

    if(findIdent(ident) == 1)
    {
        link = head;
        while(link != NULL)
        {
            if(link->ident[0] == ident[0])
            {
                if(link->ident[strlen(ident) - 1] == ident[strlen(ident) - 1])
                {
                    pushQueue(&link->linenums, linenum);
                }
            }
            link = link->next;
        }

    }
    else
    {
        link->ident = malloc(sizeof(char));
        int i;
        for(i = 0; i < strlen(ident); i++)
        {
            link->ident[i] = ident[i];
        }
        link->ident[i] = '\n';
        initQueue(&link->linenums);
        pushQueue(&link->linenums, linenum);

        link->next = head;
        head = link;
    }


}

void printlist(FILE *fout)
{
    struct node *ptr = head;
    while(ptr != NULL)
    {
        if(isalnum(ptr->ident[0]) || ptr->ident[0] == '_')
        {
            int i;
            fprintf(fout, "Identifier: ");
            for(i = 0; ptr->ident[i] != '\n'; i++)
            {
                fprintf(fout, "%c", ptr->ident[i]);
            }
            //printf("%s\n", ptr->ident);
            fprintf(fout, "\n");
            fprintf(fout, "Appears on line(s): \n");
            printQueue(&ptr->linenums, fout);
            fprintf(fout, "----------------\n");
        }

        ptr = ptr->next;
    }
}

int findIdent(char ident[])
{
    struct node* current = head;
    while(current != NULL)
    {
        if(strcmp(current->ident, ident) == 0)
        {
            return 1;
        }
        if(current->ident[0] == ident[0])
        {
            if(current->ident[strlen(ident) - 1] == ident[strlen(ident) - 1])
            {
                return 1;
            }
        }
        current = current->next;
    }
    return 0;
}