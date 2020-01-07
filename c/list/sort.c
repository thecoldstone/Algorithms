#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {

    TList list_of_students;
    
    init_list(&list_of_students);

    if(empty_list(&list_of_students)) {
       printf("Good"); 
    }

    return 0;
}
