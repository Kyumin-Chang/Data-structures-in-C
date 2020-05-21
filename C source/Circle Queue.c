#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define MAX_SIZE 20
typedef int element;
typedef int boolean;

typedef struct __circleQueue {
    int rear;
    int front;
    element* data;

}Queue;

void init_queue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->data = (element*)malloc(sizeof(element) * MAX_SIZE);
}

boolean is_empty(Queue* q) {

    if (q->front == q->rear) return TRUE;
    else return FALSE;
}

boolean is_full(Queue* q) {

    if (((q->rear + 1) % MAX_SIZE) == q->front) return TRUE;
    else return FALSE;

}
void enqueue(Queue* q, element data) {

    if (is_full(q)) {
        printf("\n공간이 없습니다!\n");
        return;
    }
    else {
        q->rear = (q->rear + 1) % (MAX_SIZE);
        q->data[q->rear] = data;
    }
    return;
}

int delqueue(Queue* q) {
    if (is_empty(q)) {
        printf("큐가 비었습니다!\n");
    }
    q->front = (q->front + 1) % (MAX_SIZE);
    return q->data[q->front];
}



void queue_print(Queue q) {
    int i = q.front;
    if (is_empty(&q)) {
        printf("\n큐가 비어있습니다!\n");
        return;
    }

    do {
        i = (i + 1) % MAX_SIZE;
        printf("%d  ", q.data[i]);
        if (i == q.rear) {
            break;
        }
    } while (i != q.front);
    printf("\n\n");
    return;
}

int main() {
    Queue q;
    init_queue(&q);

    for (int i = 0; i < 7; i++) {
        enqueue(&q, i);
        queue_print(q);
    }

    for (int i = 0; i < 5; i++) {
        delqueue(&q);
        queue_print(q);
    }
    
    for (int i = 0; i < 8; i++) {
        enqueue(&q, i);
        queue_print(q);
    }

    for (int i = 0; i < 7; i++) {
        delqueue(&q);
        queue_print(q);
    }

    free(q.data);
    return 0;
}