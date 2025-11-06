#include <stdio.h>
#include <string.h>

#define SIZE 10

// Define structure for student
struct Student
{
    char name[50];
    int year;
    char branch[20];
    float cgpa;
};

// Function to sort students by CGPA (descending)
void sortByCGPA(struct Student s[], int n)
{
    struct Student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i].cgpa < s[j].cgpa)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

// Function to display student list
void display(struct Student s[], int n)
{
    printf("\nSorted Student List (by CGPA):\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-6s %-10s %-5s\n", "Name", "Year", "Branch", "CGPA");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%-20s %-6d %-10s %-5.2f\n", s[i].name, s[i].year, s[i].branch, s[i].cgpa);
    }
}

int main()
{
    struct Student students[SIZE];

    // Input student details
    for (int i = 0; i < SIZE; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name); // Read full name with spaces
        printf("Year: ");
        scanf("%d", &students[i].year);
        printf("Branch: ");
        scanf(" %[^\n]", students[i].branch);
        printf("CGPA: ");
        scanf("%f", &students[i].cgpa);
    }

    // Sort and display
    sortByCGPA(students, SIZE);
    display(students, SIZE);

    return 0;
}