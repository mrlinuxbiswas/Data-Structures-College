//queue using array

#include <stdio.h>
#include <stdlib.h>
#define MAX 6
int queue[MAX], front=0, rear=-1;

void pushin()
{
    int x;
    printf("Enter the element you want to insert:\n");
    scanf("%d",&x);
    if(rear==MAX-1)
    {
        printf("queue is full !!");
    }
    else
    {
        if(rear<front)
        {
            rear=0;
            queue[rear]=x;
        }
        else
        {
            rear++;
            queue[rear]=x;
        }
    }
    printf("\n\n");
}

void popout()
{
    int x;
    if(rear==-1)
    {
        printf("queue is empty !!");
    }
    else
    {
        if(rear==front)
        {
            x=queue[front];
            printf("%d is deleted !!",x);
            front=0;
            rear=-1;
        }
        else 
        {
            x=queue[front];
            printf("\n%d is deleted !!",x);
            front++;
        }
    }
    printf("\n\n");
}

void display()
{
    int i;
    if(rear==-1)
    {
        printf("\nqueue is empty!!");
    }
    else
    {
        printf("---queue---\n");
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
    printf("\n\n");
}
int main()
{
    int n;
    while(1)
    {
        printf("----MENU----\n\n1.Insert\n2.Delete\n3.Display\n4.Exit\n\n");
        printf("Enter your choice:\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: pushin();
            break;
            case 2: popout();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default: printf("\nWrong choice\n\n");
        }
    }
}

