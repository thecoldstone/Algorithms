#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

Node* new_node(Data* data) {

    Node* node = (Node*) malloc(sizeof(Node));
    
    if(node != NULL) {
        node->data = data;
    }

    return node;

}

Data* new_data(int age, char* name) {

    Data* data = (Data*) malloc(sizeof(Data));

    if(data != NULL) {
        data->age = age;
        data->name = (char*) malloc(sizeof(char) * strlen(name));
        strcpy(data->name, name);
    }

    return data;

}

void free_data(Data* data) {
    
    if(data == NULL) return;

    free(data->name);
    free(data);

}

void append_start(Node** list, Data* data) {

    if(list == NULL) return;

    Node* new = new_node(data);
    
    if(new == NULL) return;
    
    #ifdef CURR
    new->curr = new;
    #endif
    new->next = *list;
    *list = new;

}

void append(Node* list, Data* data) {

    if(list == NULL) return;

    Node* tmp = list;
    Node* new = new_node(data);
    while(tmp->next != NULL){
        tmp = tmp->next;
    }

    tmp->next = new;
    #ifdef DOUBLY
    new->prev = tmp;
    #endif
    #ifdef CURR
    new->curr = new;
    #endif

}

#ifdef CURR
void set_current(Node* list, int index) {

    if(list == NULL) return;

    Node* tmp = list;
    int i = index;

    while(tmp->next != NULL && i--) {
        tmp = tmp->next;
    }

    if(tmp != list->curr) {
        list->curr = tmp;
    }

}

Node* get_current(Node* list) {
    return list->curr;
}
#endif

void print_node(Node* list, int index) {
    
    if(list == NULL) return;

    Node* tmp = list;
    int i = index;

    while(tmp->next != NULL && i--) {
        tmp = tmp->next;
    }

    printf("Node %d: Age : %d, Name : %s |\n", index, tmp->data->age, tmp->data->name);

}

void print_list(Node* list) {

    if(list == NULL) return;
    
    Node* tmp = list;

    printf("The list: ");

    while(tmp != NULL){
        printf(" Age : %d, Name : %s | ", tmp->data->age, tmp->data->name);
        tmp = tmp->next;
    }

    printf("\n");

}

Data* pop(Node** list) {

    if(*list == NULL) return NULL;

    Node* tmp;
    Data* retdata;

    tmp = (*list)->next;
    retdata = (*list)->data;

    // free_data((*list)->data);
    free(*list);
    *list = tmp;

    return retdata;

}

void delete_last(Node* list) {

    if(list == NULL) return;

    if(list->next == NULL) {
        free_list(list);
    }

    Node* second_last = list;
    while(second_last->next->next != NULL)
        second_last = second_last->next;
    
    #ifdef CURR
    if(second_last->next == list->curr) {
        list->curr = NULL;
    }
    #endif

    free_node(second_last->next);

    second_last->next = NULL;
}  

void free_node(Node* node) {
    free_data(node->data);
    free(node);
}

void free_list(Node* list) {

    Node* tmp;

    while(list != NULL) {
        tmp = list;
        list = list->next;
        free_data(tmp->data);
        free(tmp);
    }

}

int main() {

    // Preprocessors that user can define in Makefile 
    // Hint: (-D Name)
    #ifdef DOUBLY
    printf("[+] Doubly Linke List\n");
    #endif
    #ifdef CURR
    printf("[+] Linked List with Current Node\n");
    #endif 
    #ifndef DOUBLY
    printf("[+] Normal Linked List\n");
    #endif
    printf("\n\n\n");

    Data* data = new_data(20, "Name");

    Node* list = new_node(data);

    for(int i = 0; i < 4 ; ++i) {
        Data* d = new_data(20 + i, "Name");
        append(list, d);
    }
    
    print_list(list);

    #ifdef CURR
    set_current(list, 2);
    printf("CURRENT NODE Age : %d, Name : %s \n", get_current(list)->data->age, get_current(list)->data->name);
    #endif

    delete_last(list);

    print_list(list);

    // Data* popped_data = pop(&list);

    // printf("Pop the first element: Age :  %d, Name : %s\n", popped_data->age, popped_data->name);

    // free(popped_data);

    // print_list(list);

    free_list(list);

    return 0;

}
