//Infix expression

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

char stack[MAX],ch;
int top=-1,i;
void push(char );
char pop();
int valid(char exp[]);
int match(char left, char right);
int empty();

int main()
{
    char expression[MAX];
    int choice='y';
    while(choice=='y')
    {
        printf("Enter the expression with parentheses:\n");
        gets(expression);
        
        printf("%s",expression);
        
        if(valid(expression))
        {
            printf("\nValid Expression:-");
        }
        else
            printf("\nInvalid Expression:-");
        
        printf("\n\n1.To Check another expression press 'y' :-\n2.To exit press any:-\n");
        scanf("%c",&choice);
        if(choice!='y')
        {
            exit(0);
        }
        fflush(stdin);
    }
}

int valid( char exp[])
{
    printf(".");
    for(i=0;i<strlen(exp);i++)
    {
        printf("\ny\n");
        if(exp[i]== ' ( ' || exp[i]== ' { ' || exp[i]== ' [ ')
        {
            printf("\n.......\n");
            push(exp[i]);
        }
        if(exp[i]==' ) ' || exp[i]==' } ' || exp[i]==' ] ')
        {
            printf(",.,.,.,.,");
            if(empty())
            {
                printf("Right parentheses are more than left parentheses:\n");
                return 0;
            }
            else
            {
                ch=pop();
                if(!match(ch,exp[i]))
                {
                    printf("Mismatch parentheses are:-- %c and %c\n",ch,exp[i]);
                    return 0;
                }
            }
        }
    }
    if(empty())
    {
        printf("Balanced parentheses !\n");
        return 1;
    }
    else
    {
        printf("Left parentheses are more than right parentheses !\n");
        return 0;
    }
}

int empty()
{
    if(top==-1)
    {
        return 1;
    }
    else
        return 0;
}

int match(char left, char right)
{
    if(left==' ( ' && right==' ) ')
    {
        return 1;
    }
    if(left==' { ' && right==' } ')
    {
        return 1;
    }
     if(left==' [ ' && right==' ] ')
    {
        return 1;
    }
    else
        return 0;
}

void push( char exp[])
{
    top++;
    stack[top]=exp[i];
    printf("%c\n",stack[top]);
}

char pop()
{
    char a;
    a=stack[top];
    top--;
    return a;
}