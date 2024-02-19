#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->left = new->right = NULL;
    return new;
}

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

// Function to find the height of a tree
int height_tree(struct Node* root){
    if (root == NULL){
        return 0;
    }
    else{
        int left_h = height_tree(root->left);
        int right_h = height_tree(root->right);
        return (left_h>right_h ? left_h :right_h)+1;
    }
}

void inorder(struct Node* root){
    if(root){
         int balance_factor = height_tree(root->left) - height_tree(root->right);
        inorder(root->left);
        printf("%d\tbalance factor : %d\n",root->data,balance_factor);
        inorder(root->right);
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
    int x = height_tree(root) - 1;
    printf("Height of the tree : %d\n",x);
    
    inorder(root);
    
    return 0;
}
