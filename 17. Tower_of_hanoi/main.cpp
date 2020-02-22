//tower of hanoi

#include <stdio.h>

void hanoi(int n, char start, char temp, char dest);

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    
    printf("\n\nThe sequences are:::::\n\n");
    hanoi(n,'A','B','C');
    return 0;
}

void hanoi(int n, char start, char temp, char dest)
{
    if(n==1)
    {
        printf("Move disk %d from %c to %c\n",n,start,dest);
        return;
    }
    hanoi(n-1,start,dest,temp);
    printf("Move disk %d from %c to %c\n",n,start,dest);
    hanoi(n-1,temp,start,dest);
}