//Insertion sort

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,temp,a[100],n;
    
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0 && a[j]>temp;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }    
    
    printf("\n\nArray after sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
   
}