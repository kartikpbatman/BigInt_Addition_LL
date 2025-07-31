#include<stdio.h>
#include<string.h>
#include<math.h>
#define size 30

char StackA[size];
int StackB[size];
int topA = -1;
int topB = -1;



void pushA(char c) {
    if (topA == size - 1) {
        printf("Stack Overflow\n");
    } else {
        StackA[++topA] = c;
    }
}

void pushB(int n) {
    if (topB == size - 1) {
        printf("Stack Overflow\n");
    } else {
        StackB[++topB] = n;
    }
}

int popA() {
    if (topA == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return StackA[topA--];
    }
}

int popB() {
    if (topB == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return StackB[topB--];
    }
}

int main() {
    char prifix[size];
    printf("Enter the prefix expression: ");
    scanf("%s", prifix);

    strcat(prifix, ",");
    
    int l = 0;
    for(int i=0; prifix[i]!='\0'; i++) {
        if(prifix[i]==',') {
            if(topA == -1 && topB == -1) {
                printf("Invalid prifix expression\n");
                return 0;
            }
            if(l>1) {
                int arr[l];
                for(int j=0; j<l; j++) {
                    arr[j] = popB();
                }
                int ans=0;
                for(int i=l-1; i>=0; i--) {
                    double temp = pow(10.0, i*1.0);
                    ans+=arr[i]*temp;
                }
                pushB(ans);
                l=0;
            }
            if(topB==1) {
                int op2 = popB();
                int op1 = popB();
                switch(popA()) {
                    case '+': 
                        pushB(op1 + op2);
                        break;
                    case '-': 
                        pushB(op1 - op2);
                        break;
                    case '*': 
                        pushB(op1 * op2);
                        break;
                    case '/': 
                        if(op2 == 0) {
                            printf("Division by zero error\n");
                            return 0;
                        }
                        pushB(op1 / op2); 
                        break;
                    case '^': 
                        pushB(pow(op1, op2)); 
                        break;
                    default: 
                        printf("Invalid operator %c\n", prifix[i]);
                        return 0;
                }
                l = 0;
            }
            else {
                l=0;
                continue;
            }
        }
        else if(prifix[i]>='0' && prifix[i]<='9') {
            pushB(prifix[i]-'0');
            l++;
        }
        else {
            pushA(prifix[i]);
        }
    }

    if(topB == 0) {
        printf("Result: %d\n", StackB[topB]);
    } else {
        printf("Invalid postfix expression\n");
    }
    return 0;
}