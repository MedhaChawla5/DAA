#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};


int height(struct node* root){
    if(root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh>rh?(lh+1):(rh+1));
}

int balance_factor(struct node* root){
    if(root == NULL)
        return 0;
    int bf = height(root->left)-height(root->right);
    return bf;
}
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t balance factor : %d\n",root->data ,balance_factor(root));
        inorder(root->right);
    }
}
struct node* insert(struct node* root ,int val){
    if(root == NULL ){
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp-> data = val;
        temp->right = temp->left = NULL;
        return temp;
    }
    else if(val > root->data){
        root->right = insert(root->right, val);
    }
    else if(val < root->data){
        root->left = insert(root->left , val);
    }
    else{
        printf("Duplicate values cannot be inserted");
    }
    return root;
}


int main(){
    struct node* root ;
    root = NULL;
    
    printf("1]insert 2]inorder 3]exit \n");
    while(1){
    printf("Enter choice : \t");
    int ch;
    scanf("%d",&ch);
    if(ch==1){
        printf("Enter a value you want to insert");
        int val;
        scanf("%d",&val);
        root = insert(root ,val);
    }
    if(ch==2){
        inorder(root);
        printf("\n");
    }
    if(ch == 3){
        exit(1);
    }}
}