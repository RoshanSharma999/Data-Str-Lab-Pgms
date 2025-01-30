#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

struct node* createNode(int item){
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = item;
    newNode->left = newNode->right = NULL;
    return newNode;
} 

struct node* insert(int data, struct node *root){
    if(root == NULL) {
        printf("Score %d inserted\n", data);
        return createNode(data);
    }
    if(data < root->data) root->left = insert(data, root->left);
    else if(data > root->data) root->right = insert(data, root->right);
    else printf("Duplicate score not allowed\n");
    return root;
}

void inorder(struct node *root){
    if(root != NULL) {
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}

void min(struct node *root){
    if(root == NULL) printf("empty tree\n");
    else {
        while(root->left != NULL) root = root->left;
        printf("Smallest element is: %d\n", root->data);
    }
}

void max(struct node *root){
    if(root == NULL) printf("empty tree\n");
    else {
        while(root->right != NULL) root = root->right;
        printf("Largest element is: %d\n", root->data);
    }
}

void search(int key, struct node *root){
    if(root == NULL){
        printf("Key %d not found\n", key);
        return;
    }
    if(key == root->data){
        printf("Key %d found in BST\n", key);
    } else if(key < root->data){
        search(key, root->left);
    } else {
        search(key, root->right);
    }
}

int main(){
    inorder(root);
    root = insert(10, root);
    root = insert(5, root);
    root = insert(20, root);
    root = insert(15, root);
    root = insert(50, root);
    root = insert(5, root);
    root = insert(35, root);
    inorder(root);
    min(root);
    max(root);
    search(33, root);
    search(5, root);
    search(50, root);
    return 0;
}