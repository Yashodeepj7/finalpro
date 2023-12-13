#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct Student {
	int rollNumber;
	char name[50];
	float percentage;
};
 
int compareStudents(const void* a, const void* b) {
	return ((struct Student*)a)->rollNumber - ((struct Student*)b)->rollNumber;
}
 

int binarySearch(struct Student* students, int low, int high, int targetRoll) {
	while (low <= high) {
    	int mid = low + (high - low) / 2;
 
    	if (students[mid].rollNumber == targetRoll) {
        	return mid; 
    	}
 
    	if (students[mid].rollNumber < targetRoll) {
        	low = mid + 1; 
    	} else {
        	high = mid - 1; 
    	}
	}
 
}
 
int main() {
	int n; 
	printf("Enter the number of students: ");
	scanf("%d", &n);
 
	struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));
 
	for (int i = 0; i < n; ++i) {
    	printf("Enter details for student %d:\n", i + 1);
    	printf("Roll Number: ");
    	scanf("%d", &students[i].rollNumber);
    	printf("Name: ");
    	scanf("%s", students[i].name);
    	printf("Percentage: ");
    	scanf("%f", &students[i].percentage);
	}
 

	qsort(students, n, sizeof(struct Student), compareStudents);
 

	int targetRoll;
	printf("Enter the roll number to search: ");
	scanf("%d", &targetRoll);
 	int index = binarySearch(students, 0, n - 1, targetRoll);
 
	if (index != -1) {
    	printf("Student found!\n");
    	printf("Roll Number: %d\n", students[index].rollNumber);
    	printf("Name: %s\n", students[index].name);
    	printf("Percentage: %.2f\n", students[index].percentage);
	} else {
    	printf("Student not found.\n");
	}

	free(students);
 
	return 0;
}

