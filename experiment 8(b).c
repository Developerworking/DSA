#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Define the queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize the queue
void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Enqueue (add) an element to the rear of the queue
void enqueue(struct Queue* queue, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot enqueue %d.\n", item);
        return;
    }
    newNode->data = item;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d into the queue.\n", item);
}

// Dequeue (remove) an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value indicating failure
    } else {
        struct Node* frontNode = queue->front;
        int item = frontNode->data;
        queue->front = frontNode->next;
        free(frontNode);
        if (queue->front == NULL) {
            queue->rear = NULL;
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
        return queue->front->data;
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
