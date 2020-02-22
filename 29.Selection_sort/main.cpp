//Selection sort

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
    
    for(i=0;i<n-1;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                pos=j;
                if(i!=pos)
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
    }
    
    printf("\n\nArray after sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}