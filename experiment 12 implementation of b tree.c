#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 4

struct BTreeNode {
    int num_keys;
    int keys[MAX_KEYS - 1];
    struct BTreeNode* children[MAX_KEYS];
};

typedef struct BTreeNode BTreeNode;

BTreeNode* createNode(int key) {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    if (newNode != NULL) {
        newNode->num_keys = 1;
        newNode->keys[0] = key;
        for (int i = 0; i < MAX_KEYS; i++) {
            newNode->children[i] = NULL;
        }
    }
    return newNode;
}

void insertKey(BTreeNode* node, int key) {
    int i = node->num_keys - 1;
    while (i >= 0 && key < node->keys[i]) {
        node->keys[i + 1] = node->keys[i];
        i--;
    }
    node->keys[i + 1] = key;
    node->num_keys++;
}

BTreeNode* insert(BTreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (root->num_keys == MAX_KEYS - 1) {
        // Split the root
        BTreeNode* newRoot = createNode(root->keys[MAX_KEYS / 2]);
        BTreeNode* newChild = createNode(key);

        newRoot->children[0] = root;
        newRoot->children[1] = newChild;
        newRoot->num_keys = 1;

        root->num_keys = MAX_KEYS / 2;
        newChild->num_keys = MAX_KEYS / 2;

        return newRoot;
    }

    if (key < root->keys[0]) {
        // Insert in the left child
        root->children[0] = insert(root->children[0], key);
    } else {
        int i = 0;
        while (i < root->num_keys && key > root->keys[i]) {
            i++;
        }
        root->children[i] = insert(root->children[i], key);
    }

    insertKey(root, key);
    return root;
}

void printTree(BTreeNode* root, int level) {
    if (root != NULL) {
        printf("Level %d: ", level);
        for (int i = 0; i < root->num_keys; i++) {
            printf("%d ", root->keys[i]);
        }
        printf("\n");

        for (int i = 0; i <= root->num_keys; i++) {
            printTree(root->children[i], level + 1);
        }
    }
}

int main() {
    BTreeNode* root = NULL;
    int keys[] = {20, 10, 30, 5, 15, 25, 35};

    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        root = insert(root, keys[i]);
    }

    printf("B-Tree Structure:\n");
    printTree(root, 0);

    return 0;
}
