//Shell sort

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,temp,a[100],n,h;
    
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    printf("Enter the number to increment (must be an odd number): ");
    scanf("%d",&h);
    
    while(h>=1)
    {
        for(i=h;i<n;i++)
        {
            temp=a[i];
            for(j=i-h;j>=0 && a[j]>temp;j=j-h)
            {
                a[j+h]=a[j];
            }
            a[j+h]=temp;
        }
        h=h-2;
    }    
    
    printf("\n\nArray after sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
   
}