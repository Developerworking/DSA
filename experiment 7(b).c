#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the stack
struct Node {
    int data;
    struct Node* next;
};

// Define the stack structure
struct Stack {
    struct Node* top;
};

// Initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Push an element onto the stack
void push(struct Stack* stack, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push %d.\n", item);
        return;
    }
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack.\n", item);
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value indicating failure
    } else {
        struct Node* poppedNode = stack->top;
        int item = poppedNode->data;
        stack->top = poppedNode->next;
        free(poppedNode);
        return item;
    }
}

// Peek at the top element of the stack without popping it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No element to peek.\n");
        return -1; // Return a sentinel value indicating failure
    } else {
        return stack->top->data;
    }
}

int main() {
    struct Stack myStack;
    initializeStack(&myStack);

    int choice, item;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push element onto the stack\n");
        printf("2. Pop element from the stack\n");
        printf("3. Peek at the top element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(&myStack, item);
                break;
            case 2:
                item = pop(&myStack);
                if (item != -1) {
                    printf("Popped %d from the stack.\n", item);
                }
                break;
            case 3:
                item = peek(&myStack);
                if (item != -1) {
                    printf("Top element: %d\n", item);
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
