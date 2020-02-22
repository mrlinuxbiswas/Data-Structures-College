//DOBULY__LINKED__LIST

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *createlist(struct node *list)
{
    struct node *p, *temp;
    int x,i,n;
    
    printf("Enter the Number of the nodes:\n");
    scanf("%d",&n);
    
    if(n==0)
    {
        printf("\nNo node in the list !!");
    }
    else
    {
        printf("Enter the 1st element you want to insert:");
        scanf("%d",&x);
        p=(struct node *)malloc(sizeof(struct node));
        p->data=x;
        
        p->prev=NULL;
        p->next=list;
        list=p;
        
        for(i=2;i<=n;i++)
        {
            printf("Enter the next element you want to insert:");
            scanf("%d",&x);
            p=(struct node *)malloc(sizeof(struct node));
            p->data=x;
            
            temp=list;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            p->next=NULL;
            temp->next=p;
            p->prev=temp;
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
        p->prev=NULL;
        p->next=list;
        list=p;
   }
   else
   {
        p->prev=NULL;
        p->next=list;
        list->prev=p;
        list=p;
   }
   
   return list;
}

struct node *insertend(struct node *list)
{
    struct node *p, *temp;
    int x;
    printf("Enter the element you want to insert:\n");
    scanf("%d",&x);
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    
    if(list==NULL)
    {
        printf("\nList is empty!");
    }
    else
    {
        temp=list;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        p->next=NULL;
        temp->next=p;
        p->prev=temp;
    }
    return list;
}

struct node *insertany(struct node *list)
{
    struct node *p, *temp;
    int i,x,k;
    printf("Enter the element you want to insert:\n");
    scanf("%d",&x);
    printf("Enter the position:\n");
    scanf("%d",&k);
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    
    if(list==NULL)
    {
        p->prev=NULL;
        p->next=list;
        list=p;
    }
    else
    {
        if(k==1)
        {
            p->prev=NULL;
            p->next=list;
            list->prev=p;
            list=p;
        }
        else
        {
            temp=list;
            for(i=1;i<k-1 && temp!=NULL;i++)
            {
                temp=temp->next;
                if(temp==NULL)
                    break;
            }
            if(temp==NULL)
            {
                 printf("\nInvalid position !!\nYou can insert only upto %d-th position",i);
            }

            else
            {
                if(temp->next=NULL)
                {       
                    p->next=NULL;
                    temp->next=p;
                    p->prev=temp;
                }  
                else
                {
                    p->next=temp->next;
                    p->prev=p;
                    temp->next->prev=p;
                    temp->next=p;
                }
            }
        }
    }
    return list;
}

struct node *deletebeg(struct node *list)
{
    struct node *p;
    
    if(list==NULL)
    {
        printf("\nList is empty !!");
    }
    else
    {
        if(list->next==NULL)
        {
            p=list;
            list=list->next;
            free(p);
        }
        else
        {
            p=list;
            list=list->next;
            list->prev=NULL;
            free(p);
        }
    }
    return list;
}

struct node *deleteend(struct node *list)
{
    struct node *p;
    if(list==NULL)
    {
        printf("\nList is empty !!");
    }
    else
    {
        p=list;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->prev->next=NULL;
        free(p);
    }
    return list;
}

struct node *deleteany(struct node *list)
{
    struct node *p;
    int i,k;
    printf("Enter the position:\n");
    scanf("%d",&k);
    
    if(list==NULL)
    {
        printf("\nList is empty !!");
    }
    else
    {
        if(k==1)
        {
            p=list;
            list=list->next;
            free(p);
        }
        else
        {
            p=list;
            for(i=1;i<k && p!=NULL;i++)
            {
                p=p->next;
                if(p==NULL)
                    break;
            }
            if(p==NULL)
            {
                 printf("\nInvalid position !!\nYou can insert only upto %d-th position",i);
            }
            else
            {
                if(p->next==NULL)
                {
                    p->prev->next=NULL;
                    free(p);
                }
                else
                {
                    p->prev->next=p->next;
                    p->next->prev=p->prev;
                    free(p);
                }
            }
        }
    }
    return list;
}

struct node *reverse(struct node *list)
{
    struct node *p, *q;
    if(list==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        p=list;
        q=p->next;
        p->next=NULL;
        p->prev=q;
        while(q!=NULL)
        {
            q->prev=q->next;
            q->next=p;
            p=q;
            q=q->prev;
        }
        list=p;
    }
        return list;
}

void display(struct node *list)
{
    int i;
    if(list==NULL)
    {
        printf("List is empty !");
    }
    else
    {
        printf("----:: List ::----\n");
        while(list!=NULL)
        {
            printf("%d\t",list->data);
            list=list->next;
        }
    }
}

int main()
{
    int n;
    struct node *list=NULL;
    list=createlist(list);
    
    while(1)
    {
        printf("\n\n----MENU----\n\n1.Insert at beginning\n2.Insert at end\n3.Insert at any position\n4.Delete from beg");
        printf("\n5.Delete from end\n6.Delete from any position\n7.Reverse list\n8.Display\n9.Exit\n\nEnter your choice:\n");
        scanf("%d",&n);
        
        switch(n)
        {
            case 1: list=insertbeg(list);
            break;
            case 2: list=insertend(list);
            break;
            case 3: list= insertany(list);
            break;
            case 4: list= deletebeg(list);
            break;
            case 5: list=deleteend(list);
            break;
            case 6: list=deleteany(list);
            break;
            case 7: list=reverse(list);
            break;
            case 8: display(list);
            break;
            case 9: exit(0);
            default: printf("\nWrong choice");
        }
    }
}