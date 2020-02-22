//Queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *insertqueue(struct node *list)
{
    int x;
    struct node *temp,*p;
    p=(struct node *)malloc(sizeof(struct node));
    if(list==NULL)
    {
        printf("Enter the 1st element of the Queue:");
        scanf("%d",&x);
        p->data=x;
        p->next=NULL;
        list=p;
    }
    else
    {
        printf("Enter the 1st element of the Queue:");
        scanf("%d",&x);
        p->data=x;
        temp=list;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        p->next=NULL;
        temp->next=p;
    }
    printf("\n\n");
    return list;
}

struct node *deletequeue(struct node *list)
{
    struct node *p;
    if(list==NULL)
    {
        printf("Queue is empty !!");
    }
    else
    {
        p=list;
        printf("%d is deleted",p->data);
        list=p->next;
        free(p);
    }
    printf("\n\n");
    return list;
}

void display(struct node *list)
{
    if(list==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\n-----Queue-----\n");
        while(list!=NULL)
        {
            printf("%d\t",list->data);
            list=list->next;
        }
    }
    printf("\n\n");
}

int main()
{
    int n;
    struct node *list=NULL;
    while(1)
    {
        printf("----MENU----\n\n1.Insertion\n2.Deletion\n3.Display\n4.Exit");
        printf("\n\nEnter your choice:\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: list=insertqueue(list);
            break;
            case 2: list=deletequeue(list);
            break;
            case 3: display(list);
            break;
            case 4: exit(0);
            default: printf("Wrong choice!!\n\n");
        }
    }
}