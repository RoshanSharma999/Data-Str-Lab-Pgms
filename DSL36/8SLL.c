#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *head = NULL;

void insF(int item){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = item;
    temp->link = head;
    head = temp;
}

void insR(int item){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = item;
    temp->link = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    struct node *cur = head;
    while(cur->link != NULL) cur = cur->link;
    cur->link = temp;
}

void delF(){
    if(head == NULL) printf("Empty list\n");
    else{
        struct node *temp = head;
        head = head->link;
        printf("Deleted item is %d\n", temp->data);
        free(temp);
    }
}

void delR(){
    if(head == NULL) printf("Empty list\n");
    else if(head->link == NULL){
        printf("Deleted item is %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct node *prev, *cur = head;
        while(cur->link != NULL){
            prev = cur;
            cur = cur->link;
        } 
        prev->link = NULL;
        printf("Deleted item is %d\n", cur->data);
        free(cur);
    }
}

void display(){
    if(head == NULL) printf("Empty list\n");
    else{
        struct node *cur = head;
        while(cur != NULL){
            printf("%d->", cur->data);
            cur = cur->link;
        }
        printf("NULL\n");
    }
}

int main(){
    display();
    insF(20);
    insF(10);
    display();
    insR(30);
    insR(40);
    display();
    insF(5);
    display();
    delF();
    delR();
    display();
    return 0;
}