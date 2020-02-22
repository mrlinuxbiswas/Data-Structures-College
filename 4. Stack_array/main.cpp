//STACK__ARRAY

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX],top=-1;
void pushin();
void popout();
void display();

int main()
{
    int n;
    while(1)
    {
        printf("----MENU----\n\n1.Push\n2.Pop\n3.Display\n4.Exit\n\n");
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
            default: printf("\nWrong choice");
        }
    }
}

void pushin()
{
    int x;

    if(top==MAX-1)
    {
        printf("\nStack is full !!");
    }
    else
    {
            
        printf("\nEnter the element you want to push:\n");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
    printf("\n\n");
}

void popout()
{
    if(top==-1)
    {
        printf("\nStack is empty !!");
    }
    else
    {
        printf("\n%d is popped !!!",stack[top]);
        top--;
    }
    printf("\n\n");
}

void display()
{
    int i;
    if(top==-1)
    {
        printf("\nStack is empty !!");
    }
    else
    {
        printf("\n----Stack is ::----\n");
        for(i=0;i<=top;i++)
        {
            printf("%d\t",stack[i]);
        }
    }
    printf("\n\n");
}
