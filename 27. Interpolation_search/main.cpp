//INTERPOLINATION

#include <stdio.h>
 
int interpolation(int a[],int low,int high,int search)
{
    int mid;
    while(low<=high) 
    {
        mid=low+(high-low)*((search-a[low])/(a[high]-a[low]));
        
        if(search==a[mid])
        {
            return mid;  
        }
        if(search<a[mid])
        {
            low=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }     
    return -1;
}

int main()
{
    int a[200],i,n,search,index;
    
    printf("Enter the size: "); 
    scanf("%d",&n);
    printf("Enter Elements in ascending order:\n"); 
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the element you want to search: ");
    scanf("%d",&search);
    
    index=interpolation(a,0,n-1,search);
    
    if (index==-1)
        printf("\nElement %d not found\n",search);
    else
        printf("\nElement %d found at position %d-th\n",search,index);
    return 0;
}