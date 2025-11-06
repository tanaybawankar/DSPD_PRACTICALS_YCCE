#include <stdio.h>

#define MAX 5
int s[MAX];
int top = -1;

// Function declarations
void push();
void pop();
void display();
void pali();

int main()
{
    int ch;
    do
    {
        printf("\nENTER 1: FOR PUSH");
        printf("\nENTER 2: FOR POP ELEMENT");
        printf("\nENTER 3: FOR PALINDROME CHECK");
        printf("\nENTER 4: FOR DISPLAY ELEMENT");
        printf("\nENTER 0: FOR EXIT\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            pali();
            break;
        case 4:
            display();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("ENTER A VALID OPTION\n");
        }
    } while (ch != 0);

    return 0;
}

// Push function
void push()
{
    int data;
    if (top == MAX - 1)
    {
        printf("Stack is overflow!!\n");
    }
    else
    {
        printf("ENTER DATA YOU WANT TO PUSH: ");
        scanf("%d", &data);
        top++;
        s[top] = data;
        printf("Pushed %d\n", data);
    }
}

// Pop function
void pop()
{
    if (top == -1)
    {
        printf("Stack is underflow!!\n");
    }
    else
    {
        printf("Popped %d\n", s[top]);
        top--;
    }
}

// Display function
void display()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements:\n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

// Palindrome check function
void pali()
{
    int isPali = 1;
    for (int i = 0; i <= top / 2; i++)
    {
        if (s[i] != s[top - i])
        {
            isPali = 0;
            break;
        }
    }
    if (isPali)
    {
        printf("Stack is a palindrome.\n");
    }
    else
    {
        printf("Stack is not a palindrome.\n");
    }
}