#include<stdio.h>

#define size 3
int q[size];
int r = -1, f = 0, count = 0;

void enqueue(int item){
    if(count == size) printf("Overflow\n");
    else{
        r = (r+1) % size;
        q[r] = item;
        count++;
    }
}
void dequeue(){
    if(count == 0) printf("Underflow\n");
    else{
        printf("Poped item is %d\n", q[f]);
        f = (f+1) % size;
        count--;
    }
}
void display(){
    if(count == 0) printf("Empty queue\n");
    else{
        for(int i=0; i < count; i++){
            printf("%d\n", q[(f+i)%size]);
        }
    }
}

int main(){
    display();
    dequeue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    display();
    return 0;
}