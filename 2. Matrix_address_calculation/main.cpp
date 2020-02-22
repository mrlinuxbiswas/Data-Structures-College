//Matrix address calculation

#include <stdio.h>
#include <stdlib.h>
int a[100][100];

int main()
{
    int i,j,m,n,x,y,ch;
    long int b,ca,ra;

    printf("Enter the number of row:\n");
    scanf("%d",&m);
    printf("Enter the number of column:\n");
    scanf("%d",&n);

    printf("\n\nEnter the elements of the array:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    while(1)
    {
        printf("\n\n----MENU----\n\n1.Row major\n2.Column Major\n3.Exit\n\n");
        printf("Enter your Choice:\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("\nEnter the row position:\n");
                    scanf("%d",&x);
                    if(x>=m)
                    {
                        printf("\nInvalid row Position!");
                    }
                    else
                    {
                        printf("Enter the column position:\n");
                        scanf("%d",&y);
                        if(y>=n)
                        {
                            printf("\nInvalid column Position!");
                        }
                        else
                        {
                            b=(long int)&a[0][0];
                            printf("\nBase Address: %ld",b);
                            ra=b+sizeof(int)*(x*n+y);
                            printf("\nRow major address: %ld",ra);
                        }
                    }
            break;
            case 2: printf("\nEnter the column position:\n");
                    scanf("%d",&y);
                    if(y>=n)
                    {
                        printf("\nInvalid column Position!");
                    }
                    else
                    {
                        printf("Enter the row position:\n");
                        scanf("%d",&x);
                        if(x>=n)
                        {
                            printf("\nInvalid row Position!");
                        }
                        else
                        {
                            b=(long int)&a[0][0];
                            printf("\nBase Address: %ld",b);
                            ca=b+sizeof(int)*(x+m*y);
                            printf("\nRow major address: %ld",ca);
                        }
                    }
            break;
            case 3: exit(0);
            default: printf("\nWrong choice!");
        }
    }
}
