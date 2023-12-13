#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a car model
struct CarModel {
    char modelName[50];
    char manufacturer[50];
    float price;
    float engineCapacity;
    struct CarModel* next;
    struct CarModel* prev;
};

// Declare the head pointer
struct CarModel* head = NULL;

// Function to insert a new car model into the linked list
void insertCarModel(const char modelName[], const char manufacturer[], float price, float engineCapacity) {
    struct CarModel* newCarModel = (struct CarModel*)malloc(sizeof(struct CarModel));
    int i;
    for (i = 0; modelName[i] != '\0'; i++) {
        newCarModel->modelName[i] = modelName[i];
    }
    newCarModel->modelName[i] = '\0';

    for (i = 0; manufacturer[i] != '\0'; i++) {
        newCarModel->manufacturer[i] = manufacturer[i];
    }
    newCarModel->manufacturer[i] = '\0';

    newCarModel->price = price;
    newCarModel->engineCapacity = engineCapacity;
    newCarModel->next = NULL;

    if (head == NULL) {
        newCarModel->prev = NULL;
        head = newCarModel;
    } else {
        struct CarModel* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newCarModel;
        newCarModel->prev = temp;
    }

    printf("Car model added successfully!\n");
}



// Function to delete a car model from the linked list
void deleteCarModel(const char modelName[]) {
    struct CarModel* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->modelName, modelName) == 0) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }

            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }

            free(temp);
            printf("Car model deleted successfully!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Car model not found!\n");
}

// Function to display all car models within a specified price range
void displayModelsInRange(float minPrice, float maxPrice) {
    printf("\nCar models within the price range %.2f to %.2f:\n", minPrice, maxPrice);

    struct CarModel* temp = head;
    while (temp != NULL) {
        if (temp->price >= minPrice && temp->price <= maxPrice) {
            printf("Model: %s\n", temp->modelName);
            printf("Manufacturer: %s\n", temp->manufacturer);
            printf("Price: %.2f\n", temp->price);
            printf("Engine Capacity: %.2f\n\n", temp->engineCapacity);
        }
        temp = temp->next;
    }
}

// Function to display all details given a car model
void displayCarDetails(const char modelName[]) {
    struct CarModel* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->modelName, modelName) == 0) {
            printf("\nDetails for car model '%s':\n", modelName);
            printf("Manufacturer: %s\n", temp->manufacturer);
            printf("Price: %.2f\n", temp->price);
            printf("Engine Capacity: %.2f\n\n", temp->engineCapacity);
            return;
        }
        temp = temp->next;
    }

    printf("Car model not found!\n");
}

// Function to display the menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Insert a new car model\n");
    printf("2. Delete a car model\n");
    printf("3. Display car models within a price range\n");
    printf("4. Display details for a car model\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char modelName[50], manufacturer[50];
    float price, engineCapacity, minPrice, maxPrice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter model name: ");
                scanf("%s", modelName);
                printf("Enter manufacturer: ");
                scanf("%s", manufacturer);
                printf("Enter price: ");
                scanf("%f", &price);
                printf("Enter engine capacity: ");
                scanf("%f", &engineCapacity);
                insertCarModel(modelName, manufacturer, price, engineCapacity);
                break;

            case 2:
                printf("Enter model name to delete: ");
                scanf("%s", modelName);
                deleteCarModel(modelName);
                break;

            case 3:
                printf("Enter minimum price: ");
                scanf("%f", &minPrice);
                printf("Enter maximum price: ");
                scanf("%f", &maxPrice);
                displayModelsInRange(minPrice, maxPrice);
                break;

            case 4:
                printf("Enter model name to display details: ");
                scanf("%s", modelName);
                displayCarDetails(modelName);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

