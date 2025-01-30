#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;

void insF(int item){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = item;
    temp->prev = NULL;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void delF(){
    if(head == NULL) printf("Empty list\n");
    else if(head->next == NULL){
        printf("Node deleted is %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        head = head->next;
        head->prev = NULL;
        printf("Node deleted is %d\n", temp->data);
        free(temp);
        temp = NULL;
    }
}

void insR(int item){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = item;
    temp->prev = NULL;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    struct node *cur = head;
    while(cur->next != NULL) cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
}

void delR(){
    if(head == NULL) printf("Empty list\n");
    else if(head->next == NULL){
        printf("Node deleted is %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct node *cur = head;
        while(cur->next != NULL) cur = cur->next;
        printf("Node deleted is %d\n", cur->data);
        cur->prev->next = NULL;
        free(cur);
    }
}

void display(){
    if(head == NULL) printf("empty list\n");
    else {
        printf("NULL <=> ");
        struct node *cur = head;
        while(cur != NULL){
            printf("%d <=> ", cur->data);
            cur = cur->next;
        }
        printf("NULL\n");
    }
}

void search(int key){
    if(head == NULL){
        printf("Empty list\n");
        return;
    }
    int pos = 1;
    struct node *cur = head;
    while(cur != NULL){
        if(cur -> data == key){
            printf("Key %d found at position %d", key, pos);
            return;
        }
        pos++;
        cur = cur->next;
    }
    printf("Key %d not found\n", key);
}

int main(){
    display();
    insF(30);
    insF(20);
    insR(40);
    insR(50);
    insF(10);
    display();
    delR();
    delF();
    display();
    search(5);
    search(40);
    return 0;
}