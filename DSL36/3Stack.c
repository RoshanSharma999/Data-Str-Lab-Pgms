#include<stdio.h>

#define size 20
int st[size];
int top = -1;

void push(int item){
    if(top == size-1) printf("Stack overflow\n");
    else st[++top] = item;
}

void pop(){
    if(top == -1) printf("Stack underflow\n");
    else printf("Poped item is %d\n", st[top--]);
}

void palindrome(){
    if(top == -1) {
        printf("Empty stack\n");
        return;
    }
    int rev[size];
    for(int i=top; i >= 0; i--){
        rev[top-i] = st[i];
    }
    for(int i=0; i<=top; i++){
        if(rev[i] != st[i]){
            printf("Not a palindrome\n");
            return;
        }
    }
    printf("Palindrome\n");
}

void display(){
    if(top == -1) printf("Stack is empty\n");
    else{
        printf("\nStack:\n");
        for(int i = top; i >= 0; i--){
            printf("%d\n", st[i]);
        }
        printf("\n");
    }
}

int main(){
    int opt, item;
    display();
    palindrome();
    pop();
    push(10);
    push(20);
    push(10);
    display();
    pop();
    display();
    return 0;
}