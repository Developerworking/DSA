#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the queue structure
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Initialize the queue
void initializeQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Check if the queue is full
int isFull(struct Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Enqueue (add) an element to the rear of the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue Overflow. Cannot enqueue %d.\n", item);
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = item;
        printf("Enqueued %d into the queue.\n", item);
    }
}

// Dequeue (remove) an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value indicating failure
    } else {
        int item = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return item;
    }
}

// Peek at the front element of the queue without dequeuing it
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No element to peek.\n");
        return -1; // Return a sentinel value indicating failure
    } else {
        return queue->items[queue->front];
    }
}

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    int choice, item;

    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue (Add) element to the rear of the queue\n");
        printf("2. Dequeue (Remove) element from the front of the queue\n");
        printf("3. Peek at the front element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(&myQueue, item);
                break;
            case 2:
                item = dequeue(&myQueue);
                if (item != -1) {
                    printf("Dequeued %d from the queue.\n", item);
                }
                break;
            case 3:
                item = peek(&myQueue);
                if (item != -1) {
                    printf("Front element: %d\n", item);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
