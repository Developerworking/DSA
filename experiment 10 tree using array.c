#include <stdio.h>
#include <stdlib.h>

// Define the binary tree structure using an array
int tree[100];
int size = 0; // Tracks the number of elements in the tree

// Function for inorder traversal
void inorderTraversal(int index) {
    if (index < size) {
        inorderTraversal(2 * index + 1); // Left child
        printf("%d ", tree[index]);
        inorderTraversal(2 * index + 2); // Right child
    }
}

// Function for preorder traversal
void preorderTraversal(int index) {
    if (index < size) {
        printf("%d ", tree[index]);
        preorderTraversal(2 * index + 1); // Left child
        preorderTraversal(2 * index + 2); // Right child
    }
}

// Function for postorder traversal
void postorderTraversal(int index) {
    if (index < size) {
        postorderTraversal(2 * index + 1); // Left child
        postorderTraversal(2 * index + 2); // Right child
        printf("%d ", tree[index]);
    }
}

int main() {
    int data, i = 0;

    printf("Enter the elements to create a binary tree (end with -1):\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        tree[i++] = data;
    }
    size = i;

    printf("Inorder traversal: ");
    inorderTraversal(0);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(0);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(0);
    printf("\n");

    return 0;
}
