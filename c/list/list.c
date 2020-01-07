#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

void init_list(TList* list) {
    
    if(list == NULL) {
        return;
    }

    list->current = NULL;
    list->previos = NULL;
    list->next    = NULL;
}

bool empty_list(TList* list) {
    
    if(list->current == NULL && list->previos == NULL && list->next == NULL) {
        return true;
    } else {
        return false;
    }
   
}

TList* insert_list(TList* list, TStudent* student) {

    TList* 

    if(empty_list(list)) {
        
    }

    return ;
}
