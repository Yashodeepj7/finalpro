#include<stdio.h>
#include<stdlib.h>

struct Student
{
	char name[50];
	int score;
};

void bubbleSort(struct Student students[],int n)
{
	struct Student temp;
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(students[j].score<students[j+1].score)
			{
			
			temp=students[j];
			students[j]=students[j+1];
			students[j+1]=temp;
		}
		}
	}
 } 
 
 int main()
 {
 	int n;
 	
 	printf("Enter no of students\n");
 	scanf("%d",&n);
 	
 	struct Student student[n];
 	
 	for(int i=0;i<n;i++)
 	{
 		printf("Enter name of student %d\n",i+1);
 		scanf("%s",student[i].name);
 		
 		printf("Enter score of a student %d\n",i+1);
 		scanf("%d",&student[i].score);
	 }
	 
	 bubbleSort(student,n);
	 
	 printf("TOp ten topper are : \n");
	 
	 for(int i=0;i<n&&i<10;i++)
	 {
	 	printf("%d,%s score=%d\n",i+1,student[i].name,student[i].score);
	 }
	 
	 return 0;
 }
