#include<stdio.h>

#define size 20
int q[size];
int r = -1;
int f = 0;

void enqueue(int item){
    if(r == size-1) printf("Overflow\n");
    else q[++r] = item;
}

void dequeue(){
    if(r<f) printf("Underflow\n");
    else printf("Poped item is %d\n", q[f++]);
}

void display(){
    if(r<f) printf("Empty\n");
    else{
        for(int i = f; i <= r; i++){
            printf("%d\n", q[i]);
        }
    }
}
int main(){
    display();
    dequeue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}