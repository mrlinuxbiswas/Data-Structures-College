//  ARRAY operation

#include<stdio.h>
#include<stdlib.h>
int arr[100],n;

void insertion()
{
    int pos,i,l;
    printf("\n\nEnter the position:\n");
    scanf("%d",&pos);
    if(pos<=n)
    {
        printf("\nEnter the element:\n");
        scanf("%d",&l);
        for(i=n;i>=pos-1;i--)
        {
            arr[i+1]=arr[i];
        }
        arr[pos-1]=l;
        n++;
    }
    else
    {
        printf("illegal operation");
    }
}

void display()
{
    int i;
    printf("\n\nThe array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

void deletion()
{
    int i,pos;
    printf("\nEnter the position:\n");
    scanf("%d",&pos);
    if(pos<=n)
    {
       for(i=pos-1;i<n-1;i++)
       {
        arr[i]=arr[i+1];
       }
       n--;
    }
    else
    {
        printf("\nIllegal operation");
    }
}

int main()
{
    int i,j;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    while(1)
    {
        printf("\n\n------Menu------\n1.Insertion\n2.Deletion\n3.Display\n4.Exit");
        printf("\n\nEnter the number to perform the Operation:\n");
        scanf("%d",&j);
        switch(j)
        {
            case 1: insertion();
                    break;
            case 2: deletion();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\nWrong Choice:");
        }
    }
}
