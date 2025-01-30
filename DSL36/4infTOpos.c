#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char st[30];
int top = -1; 

int stPrec(char op){
    switch(op){
        case '$':
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return -1;
    }
}
int inpPrec(char op){
    switch(op){
        case '$':
        case '^': return 4;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return -1;
    }
}

void infTOpos(char infix[], char postfix[]){
    int k = 0;
    for(int i = 0; infix[i] != '\0'; i++){
        char sym = infix[i];
        if(isalnum(sym)) postfix[k++] = sym;
        else if(sym == '(') st[++top] = sym;
        else if(sym == ')'){
            while(st[top] != '('){
                postfix[k++] = st[top--];
            }
            top--;
        }
        else{
            while(stPrec(st[top]) >= inpPrec(sym)){
                postfix[k++] = st[top--];
            }
            st[++top] = sym;
        }
    }
    while(top != -1){
        postfix[k++] = st[top--];
    }
    postfix[k] = '\0';
}

int main(){
    char infix[30], postfix[30]; 
    printf("Enter a valid infix exp: ");
    scanf("%s", infix);
    infTOpos(infix, postfix);
    printf("Equivalent postfix expresion:\n%s\n", postfix);
    return 0;
}