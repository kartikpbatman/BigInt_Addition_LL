#include<stdio.h>
#include<string.h>
#include<math.h>
#define size 30

int Stack[size];
int top=-1;

void push(int n) {
    if (top == size - 1) {
        printf("Stack Overflow\n");
    }
    else {
        Stack[++top] = n;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    else {
        return Stack[top--];
    }
}


int main() {
    char postfix[size];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    int l=0;
    for(int i=0; postfix[i]!='\0'; i++) {
        if(postfix[i]==',') {
            if(top == -1) {
                printf("Invalid postfix expression\n");
                return 0;
            }
            if(l>1) {
                int arr[l];
                for(int j=0; j<l; j++) {
                    arr[j] = pop();
                }
                int ans=0;
                for(int i=l-1; i>=0; i--) {
                    double temp = pow(10.0, i*1.0);
                    ans+=arr[i]*temp;
                }
                push(ans);
                l=0;
            }
            else {
                l=0;
                continue;
            }
        }
        else if(postfix[i]>='0' && postfix[i]<='9') {
            push(postfix[i]-'0');
            l++;
        }
        else {
            if(top==-1) {
                printf("Invalid postfix expression\n");
                return 0;
            }
            else {
                int op2 = pop();
                int op1 = pop();
                switch(postfix[i]) {
                    case '+': 
                        push(op1 + op2);
                    break;
                    case '-': 
                        push(op1 - op2);
                    break;
                    case '*': 
                        push(op1 * op2);
                    break;
                    case '/': 
                        if(op2 == 0) {
                            printf("Division by zero error\n");
                            return 0;
                        }
                        push(op1 / op2); 
                        break;
                    case '^': push(pow(op1, op2)); break;
                    default: 
                        printf("Invalid operator %c\n", postfix[i]);
                        return 0;
                }
            }
        }
    }

    if(top == 0) {
        printf("Result: %d\n", Stack[top]);
    } else {
        printf("Invalid postfix expression\n");
    }
    return 0;
}