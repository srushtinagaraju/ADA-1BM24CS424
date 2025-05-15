//Leetcode exercise on Stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char arr[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char ch) {
    s->arr[++(s->top)] = ch;
}

char pop(Stack *s) {
    if (s->top == -1) return '\0';
    return s->arr[(s->top)--];
}

int isOpening(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isValid(char *s) {
    Stack stack;
    init(&stack);
    for (int i = 0; i < strlen(s); i++) {
        if (isOpening(s[i])) {
            push(&stack, s[i]);
        } else {
            char top = pop(&stack);
            if (!isMatching(top, s[i])) {
                return 0;
            }
        }
    }
    return (stack.top == -1);
}

int main() {
    char s[] = "()[]{}";
    if (isValid(s)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    return 0;
}

//OUTPUT:
Input: ()[]{}
Output: Valid

//Leetcode exercises on Queue
  #include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
} Stack;

void initStack(Stack *stack, int capacity) {
    stack->arr = (int *)malloc(capacity * sizeof(int));
    stack->top = -1;
}

void push(Stack *stack, int value) {
    stack->arr[++(stack->top)] = value;
}

int pop(Stack *stack) {
    if (stack->top == -1) return -1;
    return stack->arr[(stack->top)--];
}

typedef struct {
    Stack s1, s2;
    int capacity;
} Queue;

void initQueue(Queue *q, int capacity) {
    initStack(&q->s1, capacity);
    initStack(&q->s2, capacity);
    q->capacity = capacity;
}

void enqueue(Queue *q, int value) {
    push(&q->s1, value);
}

int dequeue(Queue *q) {
    if (q->s2.top == -1) {
        while (q->s1.top != -1) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}

int main() {
    Queue q;
    initQueue(&q, 10);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("%d\n", dequeue(&q)); 
    printf("%d\n", dequeue(&q)); 

    return 0;
}

//OUTPUT:
Enqueue 1, 2, 3
Dequeue two elements
1
2


  //Leetcode exercises on Circular Queue
  #include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is Full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

int main() {
    CircularQueue q;
    initQueue(&q);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Dequeued: %d\n", dequeue(&q));
    enqueue(&q, 60);

    while (!isEmpty(&q)) {
        printf("Dequeued: %d\n", dequeue(&q));
    }
    return 0;
}
// OUTPUT:
Enqueue 10, 20, 30, 40, 50. 
Dequeue one and then enqueue 60.
Dequeued: 10
Dequeued: 20
Dequeued: 30
Dequeued: 40
Dequeued: 50

    //Leetcode exercises on Priority Queue
  #include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} PriorityQueue;

void initPriorityQueue(PriorityQueue *pq, int capacity) {
    pq->arr = (int *)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(PriorityQueue *pq, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < pq->size && pq->arr[left] > pq->arr[largest]) {
        largest = left;
    }
    
    if (right < pq->size && pq->arr[right] > pq->arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        swap(&pq->arr[i], &pq->arr[largest]);
        heapify(pq, largest);
    }
}

void insert(PriorityQueue *pq, int value) {
    if (pq->size == pq->capacity) {
        printf("Priority Queue is Full\n");
        return;
    }
    
    pq->size++;
    int i = pq->size - 1;
    pq->arr[i] = value;
    
    while (i != 0 && pq->arr[(i - 1) / 2] < pq->arr[i]) {
        swap(&pq->arr[i], &pq->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(PriorityQueue *pq) {
    if (pq->size <= 0) return -1;
    if (pq->size == 1) {
        pq->size--;
        return pq->arr[0];
    }

    int root = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    heapify(pq, 0);
    return root;
}

int main() {
    PriorityQueue pq;
    initPriorityQueue(&pq, 10);

    insert(&pq, 10);
    insert(&pq, 20);
    insert(&pq, 15);
    insert(&pq, 30);

    printf("Max: %d\n", extractMax(&pq));
    printf("Max: %d\n", extractMax(&pq));
    printf("Max: %d\n", extractMax(&pq));

    return 0;
}
//OUTPUT:
Insert 10, 20, 15, 30 into the priority queue.
Max: 30
Max: 20
Max: 15
