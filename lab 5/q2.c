#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to build a binary tree using user input
struct TreeNode* buildTree() {
    int value;
    struct TreeNode* root = NULL;

    printf("Enter the root value (or -1 for an empty tree): ");
    scanf("%d", &value);

    if (value != -1) {
        root = createNode(value);

        printf("Enter the left subtree for node %d:\n", value);
        root->left = buildTree();

        printf("Enter the right subtree for node %d:\n", value);
        root->right = buildTree();
    }

    return root;
}

// Function to find the height of a binary tree
int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

// Function to find the diameter of a binary tree
int diameter(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    // Calculate the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Calculate the diameter through the root
    int diameterThroughRoot = leftHeight + rightHeight + 1;

    // Recursively calculate the diameter in the left and right subtrees
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    // Return the maximum of diameterThroughRoot, leftDiameter, and rightDiameter
    return (diameterThroughRoot > leftDiameter) ? ((diameterThroughRoot > rightDiameter) ? diameterThroughRoot : rightDiameter) : ((leftDiameter > rightDiameter) ? leftDiameter : rightDiameter);
}

int main() {
    struct TreeNode* root = buildTree();

    int result = diameter(root);
    printf("Diameter of the binary tree is: %d\n", result);

    return 0;
}
