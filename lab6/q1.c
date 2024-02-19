#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to calculate the total number of nodes in a binary tree
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int data;
    char choice;

    do {
        printf("Enter a value to insert into the binary tree: ");
        scanf("%d", &data);
        root = insertNode(root, data);

        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &choice);  // Notice the space before %c to consume the newline character

    } while (choice == 'y' || choice == 'Y');

    // Calculate and print the total number of nodes
    int totalNodes = countNodes(root);
    printf("Total number of nodes in the binary tree: %d\n", totalNodes);

    // Add code here for experimental analysis and plotting

    return 0;
}
