#include<stdio.h> 
int main() 
{ 
    float percentage;
    printf("enter the score in percentage: ");
    scanf("%f", &percentage);
    if(percentage<=100 && percentage>=90)
        printf("grade of student: A");
    else if(percentage<90 && percentage>=80)
        printf("grade of student: B ");
    else if(percentage<80 && percentage>=70)
        printf("grade of student: C");
    else if(percentage<70 && percentage>=60)
        printf("grade of student: D");
    else
        printf("grade of student: F");
    return 0;
}
