//CIRCULAR__LINKED__LIST

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createlist(struct node *list)
{
    struct node *p;
    int i,x,n;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    
    if(n==0)
    {
        printf("No node in the list !");
    }
    
    else
    {
        printf("Enter the 1st element you want to insert:");
        scanf("%d",&x);
        p=(struct node *)malloc(sizeof(struct node));
        p->data=x;
        
        list=p;
        list->next=list;
        
        for(i=2;i<=n;i++)
        {
             printf("Enter the next element you want to insert:");
             scanf("%d",&x);
             p=(struct node *)malloc(sizeof(struct node));
             p->data=x;
             
             p->next=list->next;
             list->next=p;
             list=p;
        }
    }
    return list;
}

struct node *insertbeg(struct node *list)
{
    struct node *p;
    int x;
    printf("Enter the element you want to insert:\n");
    scanf("%d",&x);
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    
    if(list==NULL)
    {
        list=p;
        list->next=list;
    }
    else
    {
        p->next=list->next;
        list->next=p;
    }
    return list;
}

struct node *insertend(struct node *list)
{
    struct node *p;
    int x;
    printf("Enter the element you want to insert:\n");
    scanf("%d",&x);
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    
    if(list==NULL)
    {
        list=p;
        list->next=list;
    }
    else
    {
        p->next=list->next;
        list->next=p;
        list=p;
    }
}

struct node *insertany(struct node *list)
{
    
}

struct node *deletebeg(struct node *list)
{
    struct node *p;
    if(list==NULL)
    {
        printf("Empty List!");
        return list;
    }
    else
    {
        p=list->next;
        list->next=p->next;
        free(p);
        return list;
    }
}

struct node *deleteend(struct node *list)
{
    struct node *p, *temp;
    p=list;
    temp=list->next;
    if(list==NULL)
    {
        printf("Empty List!!");
        return list;
    }
    else
    {
        while(temp->next!=list)
        {
            temp=temp->next;
        }
        temp->next=list->next;
        list=temp;
        free(p);
        return list;
    }
}

struct node *deleteany(struct node *list)
{
    struct node *p, *temp;
    int i,k;
    printf("Enter the position:\n");
    scanf("%d",&k);
    
    if(list==NULL)
    {
        printf("Empty list!!");
        return list;
    }
    else
    {
        if(k==1)
        {
            p=list->next;
            list->next=p->next;
            free(p);
        }
        else
        {
            temp=list->next;
            for(i=1;i<k-1 && temp!=NULL ;i++)
            {
                temp=temp->next;
                if(temp==NULL)
                break;
            }
            if(temp==NULL)
            {
                 printf("\nPosition Invalid !!\nYou can delete only upto %d-th position !!",i);
            }
            else
            {
                if(temp->next==list)
                {
                    p=list;
                    temp->next=list->next;
                    list=temp;
                    free(p);
                }
                else
                {
                    p=temp->next;
                    temp->next=p->next;
                    free(p);
                } 
            }
        }
    }
    return list;
}

void display(struct node *list)
{
    struct node *temp;
    if(list==NULL)
    {
        printf("List is empty !!");
    }
    
    else
    {
        printf("----:: List ::----\n");
        temp=list->next;
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        while(temp!=list->next);
    }
}

int main()
{
    int n;
    struct node *list=NULL;
    list=createlist(list);
    
    while(1)
    {
        printf("\n\n----MENU----\n\n1.Insert at beginning\n2.Insert at end\n3.Insert at any position\n4.Delete from beginning");
        printf("\n5.Delete from end\n6.Delete from any position\n7.Display\n8.Exit\n\nEnter your choice:\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: list=insertbeg(list);
            break;
            case 2: list=insertend(list);
            break;
            case 3: list=insertany(list);
            break;
            case 4: list=deletebeg(list);
            break;
            case 5: list=deleteend(list);
            break;
            case 6: list=deleteany(list);
            break;
            case 7: display(list);
            break;
            case 8: exit(0);
            default: printf("\nWrong choice");
        }
    }
}