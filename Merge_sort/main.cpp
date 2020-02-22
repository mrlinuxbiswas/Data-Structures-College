//Merge sort

#include <stdio.h>

void mergesort(int arr[],int low,int high);
void merge(int arr[],int temp[],int low1,int high1,int low2,int high2);
void copy(int arr[],int temp[],int low,int high);

void mergesort(int arr[],int low,int high)
{
    int mid,temp[100];
    
    if(low==high)
    {
        return ;
    }
    
    mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,low);
    
    merge(arr,temp,low,mid,mid+1,high);
    copy(arr,temp,low,high);
}

void merge(int arr[],int temp[],int low1,int high1,int low2,int high2)
{
    int i=low1;
    int j=low2;
    int k=low1;
    
    while(i<=high1 && j<=high2)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }
        
        while(i<=high1)
        {
            temp[k++]=arr[i++];
        }
        while(j<=high2)
        {
            temp[k++]=arr[j++];
        }
    }
}

void copy(int arr[],int temp[],int low,int high)
{
    int i;
    for(i=low;i<=high;i++)
    {
        arr[i]=temp[i];
    }
}

int main()
{
    int i,arr[100],n;
    
    printf("Enter the size: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    mergesort(arr,0,n-1);
    
    printf("The sorted list is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}
