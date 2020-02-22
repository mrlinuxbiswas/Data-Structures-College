//Linear search

#include <stdio.h>

int linearsearch(int a[], int n, int serach)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==serach)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int a[100],search,i,n,index;
    
    printf("Enter the size of the list: ");
    scanf("%d",&n);
    printf("Enter the elements of list\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the elements u want to search: ");
    scanf("%d",&search);
    
    index=linearsearch(a,n,search);
    
    if(index==-1)
    {
        printf("%d is not found in the list", search);
    }
    else
    {
        printf("%d is found in position %d-th",search,index);
    }
}