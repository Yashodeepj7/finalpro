#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insert(int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* current = head;
        for (int i = 0; i < position - 1; i++) {
            if (current == NULL) {
                printf("Position out of range.\n");
                return;
            }
            current = current->next;
        }
        if (current == NULL) {
            printf("Position out of range.\n");
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void delete(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    
    struct Node* current = head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
    
    printf("Element not found in the list.\n");
}

void reverse() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}

void search(int data) {
    struct Node* current = head;
    int position = 0;
    
    while (current != NULL) {
        if (current->data == data) {
            printf("Element %d found at position %d.\n", data, position);
            return;
        }
        current = current->next;
        position++;
    }
    
    printf("Element %d not found in the list.\n", data);
}

int countElements() {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

int main() {
    int choice, data, position;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Reverse\n");
        printf("6. Search\n");
        printf("7. Count Elements\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to create: ");
                scanf("%d", &data);
                create(data);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insert(data, position);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 5:
                reverse();
                break;
            case 6:
                printf("Enter data to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 7:
                printf("Number of elements in the list: %d\n", countElements());
                break;
            case 8:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }L
    
    return 0;
}



