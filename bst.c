#include<stdio.h>
#include<stdlib.h>


struct node{
    int info;
    struct node* lptr;
    struct node* rptr;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}

struct node* insertNode(struct node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return *root;
    }
    if (data < (*root)->info) {
        (*root)->lptr = insertNode(&((*root)->lptr), data);
    } else if (data > (*root)->info) {
        (*root)->rptr = insertNode(&((*root)->rptr), data);
    }
    return *root;
}


struct node* deleteNode(struct node** root, int data) {
    if(*root==NULL) {
        return NULL;
    }
    if((*root)->info>data) {
        (*root)->lptr = deleteNode(&(*root)->lptr, data);
    }
    else if((*root)->info<data) {
        (*root)->rptr=deleteNode(&(*root)->rptr, data);
    }
    else {
        // if((*root)->lptr==NULL && (*root)->rptr==NULL) {
        //     free(*root);
        //     return NULL;
        // }
        if((*root)->lptr==NULL) {
            struct node* save=(*root)->rptr;
            free(*root);
            return save;
        }
        else if ((*root)->rptr==NULL) {
            struct node* save=(*root)->lptr;
            free(*root);
            return save;
        }
        else {
            struct node* temp=(*root)->rptr;
            while(temp->lptr!=NULL) {
                temp=temp->lptr;
            }
            (*root)->info=temp->info;
            (*root)->rptr=deleteNode(&(*root)->rptr, temp->info);
        }
    }

    return *root;
}



int searchNode(struct node** root, int data) {
    if (*root == NULL || (*root)->info == data) {
        return 1;
    }
    if (data < (*root)->info) {
        return searchNode(&((*root)->lptr), data);
    }
    else if (data > (*root)->info) {
        return searchNode(&((*root)->rptr), data);
    }
    return 0;
}


void preorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->info);
    preorder(root->lptr);
    preorder(root->rptr);
}

void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->lptr);
    printf("%d ", root->info);
    inorder(root->rptr);
}

void postorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->lptr);
    postorder(root->rptr);
    printf("%d ", root->info);
}


int main() {

    struct node* bst = NULL;

    int n;
    while(1) {
        printf("Enter data : ");
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        else {
            insertNode(&bst, n);
        }
    }

    int t;
    while(1) {
        int c;
        printf("Chose option from below:\n");
        printf("1. insert node\n");
        printf("2. delete node\n");
        printf("3. search node\n");
        printf("4. preorder traversal\n");
        printf("5. inorder traversal\n");
        printf("6. postorder traversal\n");
        printf("-1. exit\n");
        scanf("%d", &c);


        switch(c) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &t);
                insertNode(&bst, t);
            break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &t);
                deleteNode(&bst, t);
            break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &t);
                if(searchNode(&bst, t)) {
                    printf("Node %d found.\n", t);
                } else {
                    printf("Node %d not found.\n", t);
                }
            break;
            case 4:
                printf("\nPreorder traversal: ");
                preorder(bst);
                printf("\n");
            break;
            case 5:
                printf("\nInorder traversal: ");
                inorder(bst);
                printf("\n");
            break;
            case 6:
                printf("\nPostorder traversal: ");
                postorder(bst);
                printf("\n");
            break;
        }
        if(c == -1) {
            break;
        }
    }
    free(bst);
    return 0;
}