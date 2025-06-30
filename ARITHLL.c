#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node* createNode(int X,struct node* FIRST1,int count1);
struct node* createSNode(int X, struct node* FIRST2,int count2);
struct node* arithAdd(struct node* FIRST1,struct node* FIRST2,int count1,int count2);
void freeall(struct node* FIRST1,struct node* FIRST2);

int main(){
    struct node* FIRST1=NULL;
    struct node* FIRST2=NULL;
    int choice=0;
    int count1=0,count2=0;
    int n;
    while(choice!=-1){
        printf("\n\t1: Insert into First linked list\n\t2: Insert into second Linked List\n\t3: Add two and print results\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("\n\tenter the data u want to insert = ");
            scanf("%d",&n);
            FIRST1=createNode(n,FIRST1,count1);
            break;
            case 2:
            printf("\n\tenter the data u want to insert = ");
            scanf("%d",&n);
            FIRST2=createSNode(n,FIRST2,count2);
            break;
            case 3:
            arithAdd(FIRST1,FIRST2,count1,count2);
            break;
            case -1:
            freeall(FIRST1,FIRST2);
            break;
        }
    }
    return 0;
}

struct node* createNode(int n,struct node* FIRST1,int count1){
    struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
    if(newnode==NULL){
        printf("memory allocation failed");
        return FIRST1;
    }
    struct node* temp=FIRST1;
    if(FIRST1==NULL){
        newnode->info=n;
        newnode->link=NULL;
        FIRST1=newnode;
        count1++;
        return FIRST1;
    }
    else{
        while(temp->link!=NULL){
            temp=temp->link;
        }
        newnode->info=n;
        newnode->link=NULL;
        count1++;
        temp->link=newnode;
        return FIRST1;
    }
}

struct node* createSNode(int n,struct node* FIRST2,int count2){
    struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
    if(newnode==NULL){
        printf("memory allocation failed");
        return FIRST2;
    }
    newnode->info=n;
    newnode->link=FIRST2;
    FIRST2=newnode;
    return FIRST2;
}

struct node* arithAdd(struct node* FIRST1,struct node* FIRST2,int count1,int count2){
    struct node* NEWF=NULL;
    struct node* NEWL=NULL;
    struct node* prev=NULL;
    struct node* curr=FIRST1;
    struct node* next;
    while(curr!=NULL){
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    FIRST1=prev;
    curr=FIRST2;
    prev=NULL;
    while(curr!=NULL){
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    FIRST2=prev;
    struct node* firstptr=FIRST1;
    struct node* secondptr=FIRST2;
    int carry=0;
    while(firstptr!=NULL || secondptr!=NULL || carry!=0){
        int sum=carry;
        if(firstptr!=NULL){
            sum+=firstptr->info;
            firstptr=firstptr->link;
        }
        if(secondptr!=NULL){
            sum+=secondptr->info;
            secondptr=secondptr->link;
        }
        struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
        newnode->info=sum%10;
        newnode->link=NULL;
        if(NEWF==NULL){
            NEWF=newnode;
            NEWL=newnode;
        }
        else{
            NEWL->link=newnode;
            NEWL=newnode;
        }
        carry=sum/10;
    }
    struct node* save=NEWF;
    printf("\tnew added linked list : \n\t");
    while(save!=NULL){
        printf("|%d| -> ",save->info);
        save=save->link;
    }
    printf("NULL\n");
    freeall(FIRST1,FIRST2);
    return NEWF;
}

void freeall(struct node* FIRST1,struct node* FIRST2){
    struct node* temp;
    while(FIRST1!=NULL){
        temp=FIRST1;
        FIRST1=FIRST1->link;
        free(temp);
    }
    while(FIRST2!=NULL){
        temp=FIRST2;
        FIRST2=FIRST2->link;
        free(temp);
    }
}
