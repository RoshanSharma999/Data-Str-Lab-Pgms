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
    if(head == NULL){
        head = temp;
        temp->link = head;
        return;
    }
    struct node *cur = head;
    while(cur->link != head) cur = cur->link;
    temp->link = head;
    cur->link = temp;
    head = temp;
}

void insR(int item){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = item;
    if(head == NULL){
        head = temp;
        temp->link = head;
        return;
    }
    struct node *cur = head;
    while(cur->link != head) cur = cur->link;
    cur->link = temp;
    temp->link = head; 
}

void delR(){
    if(head == NULL){
        printf("Empty list\n");
        return;
    }
    if(head->link == head){
        printf("Deleted item is %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct node *cur = head;
    while(cur->link->link != head) cur = cur->link;
    printf("Deleted item is %d\n", cur->link->data);
    free(cur->link);
    cur->link = head;
}

void display(){
    if(head == NULL){
        printf("Empty list\n");
        return;
    }
    struct node *cur = head;
    do{
        printf("%d\n", cur->data);
        cur = cur->link;
    } while(cur != head);
}

void search(int key){
    if(head == NULL) printf("Empty list\n");
    else {
        struct node *cur = head;
        int pos = 1;
        do{
            if(cur->data == key){
                printf("Key %d found at position %d\n", key, pos);
                return;
            }
            cur = cur->link;
            pos++;
        } while(cur != head);
    }
    printf("Key %d not found\n", key);
}

int main(){
    display();
    insF(20);
    insR(30);
    insF(10);
    insF(5);
    insR(40);
    display();
    delR();
    display();
    search(6);
    search(30);
    return 0;
}