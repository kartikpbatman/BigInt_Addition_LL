#include<stdio.h>
#include<string.h>
#define size 30

char Stack[size];
int top=-1;


void push(char c) {
    if (top == size - 1) {
        printf("Stack Overflow\n");
    }
    else {
        Stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    else {
        return Stack[top--];
    }
}

int inputPre(char c) {
    switch (c) {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5;
        case '(': return 9;
        case ')': return 0;
        default : return 7;
    }
}

int stackPre(char c) {
    switch (c) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 6;
        case '(': return 0;
        default : return 8;
    }
}

int Rank(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return -1;
    }
    else if(c == '(' || c == ')') {
        return 0;
    }
    return 1;
}

void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    for(int i=0; i<n; i++) {
        if(str[i]=='(') str[i]=')';
        else if(str[i]==')') str[i]='(';
    }
}


int main() {
    char infix[size], prifix[size];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    reverse(infix);

    strcat(infix, ")");
    push('(');

    int i = 0, j = 0, rank=0;
    while(infix[i]!='\0') {
        if(Rank(infix[i])==1) {
            prifix[j++]=infix[i++];
            rank++;
        }
        else {
            while(stackPre(Stack[top]) > inputPre(infix[i])) {
                char tamp = pop();
                if(tamp=='(' || tamp==')') {
                    continue;
                }
                prifix[j++] = tamp;
                rank+=Rank(tamp);
                if(rank<1){
                    printf("Invalid expression\n");
                    return 0;
                }
            }

            if (infix[i] == ')') {
                pop();
                i++;
            } else {
                push(infix[i++]);
            }
        }
    }

    if(rank!=1 || top!=-1) {
        printf("Invalid expression\n");
        return 0;
    }
    else {
        reverse(prifix);
        prifix[j] = '\0';
        printf("prifix expression: %s\n", prifix);
    }

    return 0;
}