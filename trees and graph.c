#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int id;
    char name[50];
    float marks;
    struct node *left, *right;
};

// Create node
struct node* create(int id, char name[], float marks) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->id = id;
    strcpy(newnode->name, name);
    newnode->marks = marks;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Insert
struct node* insert(struct node* root, int id, char name[], float marks) {
    if (root == NULL)
        return create(id, name, marks);

    if (id < root->id)
        root->left = insert(root->left, id, name, marks);
    else if (id > root->id)
        root->right = insert(root->right, id, name, marks);

    return root;
}

// Search
void search(struct node* root, int id) {
    if (root == NULL) {
        printf("Student not found\n");
        return;
    }

    if (id == root->id) {
        printf("ID: %d\nName: %s\nMarks: %.2f\n", root->id, root->name, root->marks);
        return;
    }

    if (id < root->id)
        search(root->left, id);
    else
        search(root->right, id);
}

// Inorder display
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("ID: %d | Name: %s | Marks: %.2f\n", root->id, root->name, root->marks);
        inorder(root->right);
    }
}

// Main menu
int main() {
    struct node* root = NULL;
    int choice, id;
    char name[50];
    float marks;

    while (1) {
        printf("\n--- STUDENT RECORD BST ---\n");
        printf("1. Insert Student\n");
        printf("2. Search Student\n");
        printf("3. Display All (Sorted by ID)\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Marks: ");
                scanf("%f", &marks);
                root = insert(root, id, name, marks);
                break;

            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                search(root, id);
                break;

            case 3:
                printf("\nStudent Records:\n");
                inorder(root);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
