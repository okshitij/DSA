#include <stdio.h>
int n,i;
int fibonacci(int* series, int n)
{
    for (i = 3;i < n;i++)
        series[i] = series[i-1] + series[i-2];
}

int main()
{
    int k,m;
    printf("enter the value of n\n");
    scanf("%d",&k);
        int a[k];
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;

    if (k>3)
        fibonacci(a, k);

    for (m = 0;m < k;m++)
        printf("%d\t",a[m]);

}