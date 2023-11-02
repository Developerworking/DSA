#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the stack structure
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Push an element onto the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow. Cannot push %d.\n", item);
    } else {
        stack->items[++stack->top] = item;
        printf("Pushed %d onto the stack.\n", item);
    }
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value indicating failure
    } else {
        return stack->items[stack->top--];
    }
}

// Peek at the top element of the stack without popping it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No element to peek.\n");
        return -1; // Return a sentinel value indicating failure
    } else {
        return stack->items[stack->top];
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
