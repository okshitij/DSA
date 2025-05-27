#include<stdio.h>
int main()
{
    int a,e,b=31,c=30,d=28,f=29;
    printf("enter month number: ");
    scanf("%d",&a);
    printf("enter the year: ");
    scanf("%d",&e);
    
    if(a==1||a==3||a==5||a==7||a==8||a==10||a==12)
        printf("number of days is %d",b);
    else if(a==4||a==6||a==9||a==11)
        printf("number of days is %d",c);
    else if(a==2)
    {   if(e%4==0)
            printf("number of days is %d",f);
        else
            printf("number of days is %d",d);}
    else
        printf("incorrect input");
    return 0;
}
    
    
