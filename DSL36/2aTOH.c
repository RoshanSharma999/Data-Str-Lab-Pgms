#include<stdio.h>

void toh(int n, char src, char dst, char aux){
    if(n == 1) printf("Move disk no %d from %c to %c\n", n, src, dst);
    else{
        toh(n-1, src, aux, dst);
        printf("Move disk no %d from %c to %c\n", n, src, dst);
        toh(n-1, aux, dst, src);
    }
}

int main(){
    int n;
    printf("Enter no of disk : ");
    scanf("%d", &n);
    printf("A - Source\nB - Destination\nC - Auxilary\n");
    toh(n, 'A', 'B', 'C');
    return 0;
}