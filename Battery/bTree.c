#include <stdio.h>
#include <stdlib.h>

// Define a node for the binary tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the height of a binary tree
int findHeight(struct Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

// Function to print leaf nodes of a binary tree
void printLeafNodes(struct Node *root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
    } else {
        printLeafNodes(root->left);
        printLeafNodes(root->right);
    }
}

// Function to create the mirror image of a binary tree
struct Node *createMirrorImage(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }

    // Swap the left and right subtrees
    struct Node *temp = root->left;
    root->left = createMirrorImage(root->right);
    root->right = createMirrorImage(temp);

    return root;
}

// Function to print the binary tree level-wise
void printLevelOrder(struct Node *root, int level) {
    if (root == NULL) {
        return;
    }

    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printLevelOrder(root->left, level - 1);
        printLevelOrder(root->right, level - 1);
    }
}

// Function to print the binary tree level-wise
void printLevelWise(struct Node *root) {
    int height = findHeight(root);
    int i;
    for ( i = 1; i <= height; i++) {
        printf("Level %d: ", i);
        printLevelOrder(root, i);
        printf("\n");
    }
}

// Function to deallocate memory used by the binary tree
void freeTree(struct Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Create a sample binary tree
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Find height of the tree
    int height = findHeight(root);
    printf("Height of the tree: %d\n", height);

    // Print leaf nodes
    printf("Leaf nodes: ");
    printLeafNodes(root);
    printf("\n");

    // Create the mirror image of the tree
    struct Node *mirrorRoot = createMirrorImage(root);

    // Print the original tree level-wise
    printf("Original Tree Level-wise:\n");
    printLevelWise(root);

    // Print the mirror image level-wise
    printf("\nMirror Image Level-wise:\n");
    printLevelWise(mirrorRoot);

    // Free memory
    freeTree(root);
    freeTree(mirrorRoot);

    return 0;
}

