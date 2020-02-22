//   CIRCULAR_QUEUE

#include <stdio.h>
#include <stdlib.h>
int queue[100], front, rear,MAX;

void pushin()
{
    int x;
    printf("Enter the element you want to insert:\n");
    scanf("%d",&x);
    
    if ((front == 0 && rear == MAX-1) || 
            (rear == (front-1)%(MAX-1))) 
    { 
        printf("\nQueue is Full\n\n"); 
        return; 
    } 
  
    else if (front == -1) 
    { 
        front = rear = 0; 
        queue[rear] = x; 
    } 
  
    else if (rear == MAX-1 && front != 0) 
    { 
        rear = 0; 
        queue[rear] = x; 
    } 
  
    else
    { 
        rear++; 
        queue[rear] = x; 
    } 
    printf("\n\n");
}

void popout()
{
    int x;
    if(rear==-1)
    {
        printf("\nqueue is empty!!\n\n");
        return;
    }
    else
    {
        if(rear==front)
        {
            x=queue[front];
            printf("%d is deleted !!",x);
            front=-1;
            rear=-1;
        }
        else 
        {
            if(front==MAX-1)
            {
                x=queue[front];
                printf("%d is deleted !!",x);
                front=0;
            }
            else
            {
                x=queue[front];
                printf("%d is deleted !!",x);
                front++;
            }
        }
    }
    printf("\n\n");
}

void display()
{
    int i;
    printf("front=%d rear=%d\n",front,rear);
    if(rear==-1)
    {
        printf("\nqueue is empty!!");
    }
    else
    {
        printf("----Queue is---!!\n");
        if(front<=rear)
        {
            for(i=front;i<=rear;i++)
            {
                printf("%d\t",queue[i]);
            }
        }
        else
        {
            if(front>rear)
            {
                for(i=0;i<=rear;i++)
                {
                    printf("%d\t",queue[i]);
                }
                for(i=front;i<MAX;i++)
                {
                    printf("%d\t",queue[i]);
                }
            }
        }
    }
    printf("\n\n");
}
int main()
{
    int n;
    front=-1;
    rear=-1;
    printf("Enter the size of the queue:\n");
    scanf("%d",&MAX);
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

