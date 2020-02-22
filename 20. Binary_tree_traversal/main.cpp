//Binary tree traversal

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

void preorder(struct node *p)
{
    if(p==NULL)
        return;
    printf("%d ",p->data);
    preorder(p->lchild);
    preorder(p->rchild);
}

void inorder(struct node *p)
{
    if(p==NULL)
        return;
    inorder(p->lchild);
    printf("%d ",p->data);
    inorder(p->rchild);
}

void postorder(struct node *p)
{
     if(p==NULL)
        return;
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d ",p->data);
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
    int n;
    struct node *root=NULL;
    root=createtree();
    printf("\n\nThe tree is:-------\n\n\n\n");
    display(root,0);
    
    while(1)
    {
        printf("\n\n1.Recursive traversal\n2.Non-recursive traversal\n3.Exit\n\nEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1: printf("pre-order traversal: ");
                        preorder(root);
                        printf("\n\n");
                        printf("pre-order traversal: ");
                        inorder(root);
                        printf("\n\n");
                        printf("pre-order traversal: ");
                        postorder(root);
                        printf("\n\n");
            break;
            case 2:
            break;
            case 3: exit(0);
            default: printf("\nWrong choice!!");
        }
    }
}