#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNumber;
    char name[50];
    float percentage;
};

void bubbleSort(struct Student* students, int n) {
    int i, j;  // Declare i and j outside the loop
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            if (students[j].percentage < students[j + 1].percentage) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    int i;  // Declare i outside the loop
    for (i = 0; i < n; ++i) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
    }

    bubbleSort(students, n);

    printf("\nTop Ten Toppers:\n");
    int j;  // Declare j outside the loop
    for (j = 0; j < 10 && j < n; ++j) {
        printf("%d. Roll Number: %d, Name: %s, Percentage: %.2f\n", j + 1, students[j].rollNumber,
               students[j].name, students[j].percentage);
    }

    free(students);

    return 0;
}

