#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

double st[30];
int top = -1;

double calc(char sym, double opr1, double opr2){
    switch(sym){
        case '$':
        case '^': return pow(opr1, opr2);
        case '/': return opr1/opr2;
        case '*': return opr1*opr2;
        case '+': return opr1+opr2;
        case '-': return opr1-opr2;
    }
}

double evalPOS(char postfix[]){
    double opr1, opr2;
    for(int i=0; postfix[i] != '\0'; i++){
        char sym = postfix[i];
        if(isdigit(sym)) st[++top] = sym - '0';
        else{
            opr2 = st[top--];
            opr1 = st[top--];
            st[++top] = calc(sym, opr1, opr2);
        }
    }
    return st[top--];
}

int main(){
    char postfix[30];
    printf("Enter a valid postfix exp: ");
    scanf("%s", postfix);
    printf("ANS: %.2lf", evalPOS(postfix));
    return 0;
}