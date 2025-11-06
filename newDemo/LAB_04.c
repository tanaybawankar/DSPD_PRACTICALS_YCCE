#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void CreateSLL()
{
    int ele, ch;
    struct node *newnode, *temp;
    do
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("ENTER DATA:");
        scanf("%d", &ele);
        newnode->data = ele;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
        printf("Do you want to continew:");
        scanf("%d", &ch);
    } while (ch != 0);
}
void display_no_node()
{
    struct node *temp;
    int count = 1;
    temp = head;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("NO OF NODE:%d", count);
}
void display_SLL()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("\t%d", temp->data);
        temp = temp->next;
    }
}
void main()
{
    int ch;
    do
    {
        printf("\n1]:FOR CREATE_SLLC\n2] FOR DISPLAY\n3]NUMBER OF NODE\n0]EXIT");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            CreateSLL();
            break;
        case 2:
            display_SLL();
            break;
        case 3:
            display_no_node();
            break;
        default:
            printf("ENTER VALID ANSWER");
            break;
        }
    } while (ch != 0);
}