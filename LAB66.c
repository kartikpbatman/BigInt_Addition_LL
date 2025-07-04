#include <stdio.h>
#include <stdlib.h>


struct node{
	int info;
	struct node *link;
};
void display(struct node *FIRST);
struct node *INSMID(int n,struct node *FIRST);
struct node *INSFIRST(int n,struct node *FIRST);
void freeall(struct node *FIRST);

int main(){
	 struct node *FIRST=NULL;
	int choice=0;
	int n;
	while(choice!=-1){
		printf("enter -1 to exit\n\tenter 1 to insert\n\tenter 2 to call gcd\n\tenter 3 to diplay\n\t");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\n\tenter the data u want to insert = ");
				scanf("%d",&n);
				FIRST=INSFIRST(n,FIRST);
				break;
				
			case 2:
				struct node *temp=FIRST;
				for(struct node*i=temp;i!=NULL;i=i->link){
					int a=i->info;
					int b=(i->link)->info;
					while(b!=0){
						temp=b;
						b=a%b;
						a=temp;
					}
					INSMID(a,i);
				}
				
				break;
			
			case 3:
				display(FIRST);
				break;
			default:
				freeall(FIRST);
				break;
				
		}
	}
}

struct node *INSMID(int a,struct node *i){
	struct node *prev=i;
	struct node *next=i->link;
	struct node *newnode=(struct node *)(malloc(sizeof(struct node)));
	newnode->info=a;
	prev->link=newnode;
	newnode->link=next;
}

struct node *INSFIRST(int n,struct node *FIRST){
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

void display(struct node *FIRST){
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
