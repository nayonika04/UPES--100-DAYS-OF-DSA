#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Basic Queue Implementation
struct Queue {
    int items[MAX];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++(q->rear)] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Basic Stack Implementation
struct Stack {
    int items[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

void push(struct Stack* s, int value) {
    s->items[++(s->top)] = value;
}

int pop(struct Stack* s) {
    return s->items[(s->top)--];
}

// Logic to reverse queue using stack
void reverseQueue(struct Queue* q) {
    struct Stack s;
    initStack(&s);

    // Step 1: Dequeue everything from Queue and Push to Stack
    while (!isEmpty(q)) {
        push(&s, dequeue(q));
    }

    // Step 2: Pop everything from Stack and Enqueue back to Queue
    while (s.top != -1) {
        enqueue(q, pop(&s));
    }
}

int main() {
    int N, val;
    struct Queue q;
    initQueue(&q);

    if (scanf("%d", &N) != 1) return 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    reverseQueue(&q);

    // Print the reversed queue
    while (!isEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }

    return 0;
}
