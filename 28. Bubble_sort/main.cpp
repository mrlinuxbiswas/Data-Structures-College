//Bubble sort

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,temp,a[100],n,pos;
    
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(i=n-2;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                pos++;
            }
        }
         if(pos==0)
        {
            break;
        }
    }    
    
    printf("\n\nArray after sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}