#ifndef _QUEUE_H
#define _QUEUE_H

#define FALSE 0
#define TRUE  1

typedef union t_data {
    char* name;
    int age;
} Data;

typedef struct t_node {
    Data data;
    struct t_node* next;
} Node;

typedef struct t_queue {
    Node *front;
    Node *rear;
} Queue;

Queue* init_queue();

Node* new_node(Data data);

int isEmpty(Queue* q);

void enqueue(Queue* q, Node* node);

void dequeue(Queue* q);

void free_queue(Queue* q);

Node* last_node(Queue* q);

#endif
