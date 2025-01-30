#include<stdio.h>

int fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n-2) + fib(n-1);
}

int main(){
    int a;
    printf("Enter last no: ");
    scanf("%d", &a);
    for(int i=0; i <= a; i++){
        printf("fib %d = %d\n", i, fib(i));
    }
    return 0;
}