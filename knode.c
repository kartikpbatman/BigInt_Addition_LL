#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
}
;
struct node* INSFIRST(int X,struct node* FIRST);
struct node* SW(int k,struct node* FIRST);
void freeall(struct node *FIRST);
struct node* INSLAST(int x, struct node* FIRST);
struct node* display(struct node* FIRST);

int main(){
    struct node *FIRST=NULL;
    int choice=0;
    while(choice!=-1){
        printf("enter -1 to exit\n\n");
        int n;
        printf("enter 1 to make a new node and enter data\n\nenter 2 to insert into existing node\n\nenter 3 display all nodes\n\nenter 4 to swap\n\t");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\n\tenter data u want to insert = ");
                scanf("%d",&n);
                FIRST=INSFIRST(n,FIRST);
                break;

            case 2:
                printf("\n\tenter data u want to insert ");
                scanf("%d",&n);
                FIRST=INSLAST(n,FIRST);
                break;

            case 3: 
                display(FIRST);
                break;

            case 4:
                int k;
                printf("enter value for k = ");
                scanf("%d",&k);
                FIRST=SW(k,FIRST);
                break;

            default:
				freeall(FIRST);
				break;
        }
    }
}

struct node* INSLAST(int n,struct node* FIRST){
    struct node* newnode=(struct node*)(malloc((sizeof(struct node))));
    if (newnode==NULL){
        printf("Memory allocation failed\n");
        return FIRST;
    }
    newnode->info=n;
    newnode->link=NULL;

    if (FIRST==NULL){
        return newnode;
    }

    struct node* temp=FIRST;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link = newnode;
    return FIRST;
}

struct node* display(struct node* FIRST){
    printf("\n\t");
    if(FIRST==NULL){
        printf("node doesnt exist");

    }
    else{
        struct node* save=FIRST;
        while(save!=NULL){
            printf("|%d| -> ",save->info);
            save=save->link;
        }
        printf("NULL\n\n");
    }

}


struct node* INSFIRST(int n,struct node* FIRST){
    struct node* newnode =(struct node*)(malloc((sizeof(struct node))));
    if(newnode==NULL){
        printf("memory allocation failed");
        return FIRST;
    }
    newnode->info=n;
    newnode->link=FIRST;
    FIRST=newnode;
    return FIRST;
}

struct node *SW(int k, struct node *FIRST)

{
    struct node* curr = FIRST;
    int count = 0;
    while (curr && count < k) {
        curr = curr->link;
        count++;
    }
    if (count < k) return FIRST;  


    curr = FIRST;
    struct node* prev = NULL;
    struct node* next = NULL;
    count = 0;
    while (curr && count < k) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next)
        FIRST->link = SW( k,next);

    return prev;
}


void freeall(struct node * FIRST){
    if(FIRST==NULL){
        printf("no node available");
        return;
    }
    struct node* temp;
    while(FIRST!=NULL){
        temp=FIRST;
        free(temp);
        FIRST=FIRST->link;
    }
}
