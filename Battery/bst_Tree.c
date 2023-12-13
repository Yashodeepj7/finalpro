#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct TreeNode {
	char name[50];
	char phoneNumber[20];
	struct TreeNode *left;
	struct TreeNode *right;
};
 
struct TreeNode* createNode(char name[], char phoneNumber[]) {
	struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    strcpy(newNode->name, name);
    strcpy(newNode->phoneNumber, phoneNumber);
	newNode->left = newNode->right = NULL;
	return newNode;
}
 
struct TreeNode* insert(struct TreeNode* root, char name[], char phoneNumber[]) {
	if (root == NULL) {
    	return createNode(name, phoneNumber);
	}
 
	if (strcmp(name, root->name) < 0) {
    	root->left = insert(root->left, name, phoneNumber);
	} else if (strcmp(name, root->name) > 0) {
    	root->right = insert(root->right, name, phoneNumber);
	}
 
	return root;
}
 
struct TreeNode* search(struct TreeNode* root, char name[]) {
	if (root == NULL || strcmp(root->name, name) == 0) {
    	return root;
	}
 
	if (strcmp(name, root->name) < 0) {
    	return search(root->left, name);
	}
 
	return search(root->right, name);
}
 
struct TreeNode* findMin(struct TreeNode* node) {
	while (node->left != NULL) {
    	node = node->left;
	}
	return node;
}
 
struct TreeNode* deleteNode(struct TreeNode* root, char name[]) {
	if (root == NULL) {
    	return root;
	}
 
	if (strcmp(name, root->name) < 0) {
    	root->left = deleteNode(root->left, name);
	} else if (strcmp(name, root->name) > 0) {
    	root->right = deleteNode(root->right, name);
	} else {
    	if (root->left == NULL) {
        	struct TreeNode* temp = root->right;
            free(root);
        	return temp;
    	} else if (root->right == NULL) {
        	struct TreeNode* temp = root->left;
            free(root);
        	return temp;
    	}
 
    	struct TreeNode* temp = findMin(root->right);
        strcpy(root->name, temp->name);
        strcpy(root->phoneNumber, temp->phoneNumber);
    	root->right = deleteNode(root->right, temp->name);
	}
 
	return root;
}
 
void printPhoneList(struct TreeNode* root) {
	if (root != NULL) {
        printPhoneList(root->left);
        printf("%s: %s\n", root->name, root->phoneNumber);
        printPhoneList(root->right);
	}
}
 
int main() {
	struct TreeNode* root = NULL;
	int choice;
	char name[50];
	char phoneNumber[20];
 
	do {
        printf("\nPhone List Menu:\n");
        printf("1. Insert new name\n");
        printf("2. Search for a name\n");
        printf("3. Delete an existing name\n");
        printf("4. Print entire phone list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
    	switch (choice) {
        	case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phoneNumber);
            	root = insert(root, name, phoneNumber);
            	break;
        	case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
            	if (search(root, name) != NULL) {
                    printf("%s found in the phone list.\n", name);
            	} else {
                    printf("%s not found in the phone list.\n", name);
            	}
            	break;
        	case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
            	root = deleteNode(root, name);
            	break;
        	case 4:
                printf("\nPhone List:\n");
                printPhoneList(root);
            	break;
        	case 5:
                printf("Exiting program.\n");
            	break;
        	default:
                printf("Invalid choice. Please enter a valid option.\n");
    	}
	} while (choice != 5);
 
	return 0;
}

