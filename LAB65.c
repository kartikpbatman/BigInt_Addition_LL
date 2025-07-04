#include <stdio.h>
#include <stdlib.h>

struct node{
	int info;
	struct node *link;
};
void display(struct node *FIRST);
void sort(struct node *FIRST);
struct node *INSFIRST(int n,struct node *FIRST);
void freeall(struct node *FIRST);


int main(){
	struct node *FIRST=NULL;
	int choice=0;
	int n;
	while(choice!=-1){
		printf("enter -1 to exit\n\tenter 1 to insert\n\tenter 2 to sort\n\tenter 3 to diplay\n\t");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\n\tenter the data u want to insert = ");
				scanf("%d",&n);
				FIRST=INSFIRST(n,FIRST);
				break;
				
			case 2:
				sort(FIRST);
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


void sort(struct node* FIRST){
	struct node* temp;
    for(struct node* i=FIRST;i!=NULL;i=i->link){
        for(struct node* j=FIRST;j->link!=NULL;j=j->link){
            if(j->info < (j->link)->info){
                temp=j->info;
                j->info=(j->link)->info;
                (j->link)->info=temp;
            }
        }
    }
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



