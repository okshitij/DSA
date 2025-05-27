#include<stdio.h>

struct h
{
    int a;
    char b;
}s1;

struct z
{
    int *c;
    char *d;
}s2,*s3;

int main()
{
    int *ptr1;
    char *ptr2;
    printf("%d\n", sizeof(s1));
    printf("%d\n", sizeof(s2));
    printf("%d\n", sizeof(ptr1));
    printf("%d\n", sizeof(ptr2));
    printf("%d\n", sizeof(s3));

    return 0;

}