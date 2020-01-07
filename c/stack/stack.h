#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>

#define MAX_STACK 20
extern int STACK_SIZE;

/* ADT zásobník implementovaný ve statickém poli */
typedef struct {
    char arr[MAX_STACK];                             /* pole pro uložení hodnot */
    int top;                                /* index prvku na vrcholu zásobníku */
} tStack;

void stackInit ( tStack* s );
int stackEmpty ( const tStack* s );
int stackFull ( const tStack* s );
int stackTop ( const tStack* s);
void stackPop ( tStack* s );
void stackPush ( tStack* s, char c );

#endif

/* Konec hlavičkového souboru c202.h */
