#include <stdio.h>
#include <stdlib.h>

void write(FILE* temp) 
{
    char name[100]; 
    printf("Enter name: ");
    scanf("%99s", name);
    fprintf(temp, "%s ", name);
    
    int roll;
    printf("Enter roll no.: ");
    scanf("%d", &roll);
    fprintf(temp, "%d ", roll);

    printf("Enter Email: ");
    scanf("%99s", name);
    fprintf(temp, "%s ", name);

    printf("Enter course name: ");
    scanf("%99s", name);
    fprintf(temp, "%s\n", name);
}

void reading(FILE* temp) 
{
    int roll;
    char* name = NULL; 
    char* email = NULL;
    char* course = NULL;
    
    name = malloc(100);
    email = malloc(100);
    course = malloc(100);

    while (fscanf(temp, "%99s %d %99s %99s", name, &roll, email, course) == 4) 
    printf("Name = %s\tRoll no. = %d\tEmail = %s\tCourse = %s\n", name, roll, email, course);
    
    free(name);
    free(email);
    free(course);
    name = email = course = NULL;
}

int main() {
    int n;
    printf("Enter no. of students:");
    scanf("%d", &n);

    FILE* stu;
    stu = fopen("Students.txt", "w+");
    
    for (int i = 0; i < n; i++) write(stu);
    fclose(stu);

    stu = fopen("Students.txt", "r");

    reading(stu);
    fclose(stu); 
}
