#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for the stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1; // Return a sentinel value indicating failure
    }
    return stack->array[stack->top--];
}

// Get the precedence of an operator
int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0;
}

// Convert infix expression to postfix expression
char* infixToPostfix(char* infix) {
    struct Stack* stack = createStack(strlen(infix));
    char* postfix = (char*)malloc(strlen(infix) * sizeof(char));
    int i, j = 0;

    for (i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && stack->array[stack->top] != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && stack->array[stack->top] != '(') {
                printf("Invalid expression\n");
                return NULL;
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(stack->array[stack->top])) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0';

    return postfix;
}

// Evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    int i, op1, op2;

    for (i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            push(stack, postfix[i] - '0');
        } else {
            op2 = pop(stack);
            op1 = pop(stack);
            switch (postfix[i]) {
                case '+':
                    push(stack, op1 + op2);
                    break;
                case '-':
                    push(stack, op1 - op2);
                    break;
                case '*':
                    push(stack, op1 * op2);
                    break;
                case '/':
                    push(stack, op1 / op2);
                    break;
            }
        }
    }
    return stack->array[stack->top];
}

int main() {
    char infix[100], *postfix;
    int result;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    postfix = infixToPostfix(infix);
    if (postfix != NULL) {
        printf("Postfix expression: %s\n", postfix);

        result = evaluatePostfix(postfix);
        printf("Result of evaluation: %d\n", result);

        free(postfix);
    }

    return 0;
}
