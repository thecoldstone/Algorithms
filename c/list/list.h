#ifndef _LIST_H
#define _LIST_H

typedef struct t_data {
    char* name;
    int age;
} Data;

typedef struct t_node {
    Data* data;
    struct t_node* next;
    #ifdef CURR
    struct t_node* curr;
    #endif
    #ifdef DOUBLY
    struct t_node* prev;
    #endif
} Node;

Node* new_node(Data* data);

Data* new_data(int age, char* name);

void free_data(Data* data);

void append_start(Node** list, Data* data);

void append(Node* list, Data* data);

Data* pop(Node** list);

void print_list(Node* list);

void free_node(Node* node);

void free_list(Node* list);

#endif
