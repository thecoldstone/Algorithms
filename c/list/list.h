#include <stdbool.h>
#include "student.h"

typedef struct list {
    TStudent student;
    struct list* next;
    struct list* previous;
} TList;

void    init_list(TList* list);
bool    empty_list(TList* list);
TList*  insert_list(TList* list, TStudent* student);
