#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* init_queue() {
    Queue* q = (Queue*) malloc(sizeof(Queue)); 
    if(q != NULL) {
        q->front = q->rear = NULL;
    }
    return q;
}

Node* new_node(Data data) { 
    Node* n = (Node*) malloc(sizeof(Node));
    if(n != NULL) {
        n->data = data;
    }
    return n;
}

int isEmpty(Queue* q){
    return q->front == NULL ? TRUE : FALSE;
}

void enqueue(Queue* q, Node* node){

    if((q == NULL) || (node == NULL)) {
        return;
    }

    if(q->rear == NULL) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node; 
    }

    #ifdef CIRCULAR
    q->rear->next = q->front;
    #endif

}

void dequeue(Queue* q) {

    if(q->front == NULL) {
        return;
    }

    if(q->front == q->rear) {
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } else {
        Node* tmp = q->front;
        q->front = q->front->next;
        #ifdef CIRCULAR
        q->rear->next = q->front;
        #endif
        free(tmp);
    }
    
}

void free_queue(Queue* q) {
    
    while(!isEmpty(q)) {
        printf("Age: %d\n", q->front->data.age);
        dequeue(q);
    }

}

Node* last_node(Queue* q) {
    return q->rear;
}

int main() {

    Queue* queue = init_queue();
    Node* node;

    #ifdef CIRCULAR
    printf("* Circular Queue *\n");
    #else 
    printf("* Normal Queue *\n");
    #endif

    // Insert some data
    for(int i = 0; i < 5; i++) {
        node = (Node*) malloc(sizeof(Node));
        node->data.age = i + i;
        enqueue(queue, node);
    }

    // Verify success
    printf("Last inserted : %d\n", last_node(queue)->data.age);
    #ifdef CIRCULAR
    printf("The first item in queue : %d\n", last_node(queue)->next->data.age);
    #else 
    printf("The first item in queue : %d\n", queue->front->data.age);
    #endif

    // Free queue
    free_queue(queue);

    return 0;

}
