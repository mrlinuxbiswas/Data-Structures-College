//merge sort

#include<stdio.h>
#include<stdlib.h>

void Merge(long int a[], long int tmp[], long int lpos, long int rpos, long int rend)
{
    long int i, lend, n, tmppos;
    lend = rpos - 1;
    tmppos = lpos;
    n = rend - lpos + 1;

    while(lpos <= lend && rpos <= rend)
    {
        if(a[lpos] <= a[rpos])
            tmp[tmppos++] = a[lpos++];
        else
            tmp[tmppos++] = a[rpos++];
    }

    while(lpos <= lend)
        tmp[tmppos++] = a[lpos++];
    while(rpos <= rend)
        tmp[tmppos++] = a[rpos++];

    for(i = 0; i < n; i++, rend--)
        a[rend] = tmp[rend];
}

void MSort(long int a[], long int tmp[], long int left, long int right)
{
    long int center;
    if(left < right)
    {
        center = (left + right) / 2;
        MSort(a, tmp, left, center);
        MSort(a, tmp, center + 1, right);
        Merge(a, tmp, left, center + 1, right);
    }
}
int MergeSort(long int a[], long int n)
{
    long int *tmparray;
    tmparray = malloc(sizeof(int) * n);
    MSort(a, tmparray, 0, n-1);
    free(tmparray);
    return 0;
}
int main()
{
    long int i, n, a[10];
    scanf("%ld",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%ld",&a[i]);
    }
    MergeSort(a,n);
    for(i = 0; i < n; i++)
        printf("%ld",a[i]);
}
