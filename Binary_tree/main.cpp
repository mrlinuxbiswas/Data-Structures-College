//binary tree

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

struct node *createtree()
{
    int x;
    struct node *p;
    printf("Enter the element you want to insert: ");
    scanf("%d",&x);
    
    if(x<=-1)
    {
        return NULL;
    }
    else
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->data=x;
        
        printf("\n\nEnter the left child of %d:\n",x);
        p->lchild=createtree();
        printf("\n\nEnter the right child of %d:\n",x);
        p->rchild=createtree();
    }
    return p;
}

void display(struct node *p, int i)
{
    int a;
    if(p==NULL)
        return;
    display(p->rchild,i+1);
    printf("\n");
    
    for(a=0;a<i;a++)
    {
        printf("    ");
    }
    printf("%d",p->data);
    
    display(p->lchild,i+1);
}

int main()
{
    struct node *root=NULL;
    root=createtree();
    printf("\n\nThe tree is:-------\n\n\n\n");
    display(root,0);
}