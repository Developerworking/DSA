#include <stdio.h>
#include <stdlib.h>

// Define the maximum size for the list
#define MAX_SIZE 100

// Structure for the list
struct List {
    int array[MAX_SIZE];
    int size;
};

// Initialize the list
void initializeList(struct List* list) {
    list->size = 0;
}

// Add an element to the end of the list
void append(struct List* list, int value) {
    if (list->size < MAX_SIZE) {
        list->array[list->size] = value;
        list->size++;
    } else {
        printf("List is full. Cannot append.\n");
    }
}

// Display the elements in the list
void displayList(struct List* list) {
    if (list->size == 0) {
        printf("The list is empty.\n");
    } else {
        printf("List elements: ");
        for (int i = 0; i < list->size; i++) {
            printf("%d ", list->array[i]);
        }
        printf("\n");
    }
}

int main() {
    struct List myList;
    initializeList(&myList);

    int choice, value;

    while (1) {
        printf("\nList Menu:\n");
        printf("1. Append element to the list\n");
        printf("2. Display list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to append: ");
                scanf("%d", &value);
                append(&myList, value);
                break;
            case 2:
                displayList(&myList);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
