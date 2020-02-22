//STACK__LINKED_LIST

#include<stdio.h>
#include<stdlib.h>
int n=5;

struct node 
{
    int data;
    struct node *next;
};

struct node *top=NULL;

void pushin()
{
    struct node *p, *temp;
    int x,s=0;
    
    temp=top;
    while(temp!=NULL)
    {
        s++;
        temp=temp->next;
    }
    if(s==n)
    {
        printf("Stack overflow !!");
    }
    else
    {
        printf("Enter the element you want to insert:\n");
        scanf("%d",&x);
        p=(struct node *)malloc(sizeof(struct node));
        p->data=x;
    
        p->next=top;
        top=p;
    }
    printf("\n\n");
}

void popout()
{
    struct node *p;
    if(top==NULL)
    {
        printf("Stack underflow !!");
    }
    else
    {
        p=top;
        printf("%d is popped",p->data);
        top=top->next;
        free(p);
    }
    printf("\n\n");
}

void size()
{
    struct node *temp;
    int s=0;
    if(top==NULL)
    {
        printf("Stack is empty !!");
    }
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            s++;
            temp=temp->next;
        }
        printf("Size of stack is ::- %d",s);
    }
    printf("\n\n");
}

void display()
{
    struct node *temp;
    if(top==NULL)
    {
        printf("Stack is empty !!");
    }
    else
    {
        printf("----:: Stack Is ::----\n");
        temp=top;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
    printf("\n\n");
}

int main()
{
    int n;
    while(1)
    {
        printf("----MENU----\n\n1.Push\n2,Pop\n3.Size.\n4.Display\n5.Exit\n\n");
        printf("Enter your choice:-\n");
        scanf("%d",&n);
        
        switch(n)
        {
            case 1: pushin();
            break;
            case 2: popout();
            break;
            case 3: size();
            break;
            case 4: display();
            break;
            case 5: exit(0);
            default: printf("\nWrong choice !!\n\n");
        }
    }
}