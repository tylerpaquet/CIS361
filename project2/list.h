//
// Created by Tyler on 10/16/2016.
//

#ifndef CIS361PROJECT2_LIST_H
#define CIS361PROJECT2_LIST_H
#include "queue.h"
#include <stdbool.h>
//#include <mem.h>
#include <string.h>
void insert(int linenum, char ident[]);
void printlist(FILE *fout);
struct node* find(char ident[]);
int findIdent(char ident[]);
#endif //CIS361PROJECT2_LIST_H
