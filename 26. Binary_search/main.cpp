//Binary search

#include <stdio.h>

int binarysearch(int a[], int n, int search)
{
    int low=0,high=n-1,mid;
    
    while(low<=high)
    {
        mid=(low+high)/2;
        if(search>a[mid])
        {
            low=mid+1;
        }
        else if(search<a[mid])
        {
            high=mid-1;
        }
        else
            return mid;
    }
    return -1;
}

int main()
{
    int i,n,search,index,a[100];
    
    printf("Enter the size of the list: ");
    scanf("%d",&n);
    printf("Enter the elements of the list:\n");
    for(i=0;i<n;i++)
    {
         scanf("%d",&a[i]);
    }
    
    printf("Enter the element you want to search: ");
    scanf("%d",&search);
    
    index=binarysearch(a,n,search);
    if(index==-1)
    {
        printf("%d is not found in the list !!",search);
    }
    else
    {
        printf("%d is found in position %d-th",search,index);
    }
}
        