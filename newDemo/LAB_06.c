#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node
{
    int data;
    struct node *left, *right;
};

// Create a new node
struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search an element in BST
void search(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("NULL\n");
        return;
    }

    if (root->data == key)
    {
        printf("Found\n");
    }
    else if (key < root->data)
    {
        search(root->left, key);
    }
    else
    {
        search(root->right, key);
    }
}

// Delete only a leaf node
struct node *deleteLeaf(struct node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else
    {
        // Check if it is a leaf node
        if (root->left == NULL && root->right == NULL)
        {
            printf("Deleting leaf node: %d\n", root->data);
            free(root);
            return NULL;
        }
        else
        {
            printf("Not a leaf node, cannot delete.\n");
        }
    }
    return root;
}

// Inorder Traversal (optional display)
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main()
{
    struct node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Search an element\n");
        printf("2. Insert an element\n");
        printf("3. Delete a leaf element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to search: ");
            scanf("%d", &value);
            search(root, value);
            break;

        case 2:
            printf("Enter element to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Inserted successfully.\n");
            printf("Current Inorder: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Enter leaf element to delete: ");
            scanf("%d", &value);
            root = deleteLeaf(root, value);
            printf("Current Inorder: ");
            inorder(root);
            printf("\n");
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}