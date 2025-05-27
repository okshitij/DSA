#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, m;
    printf("enter starting table and number of tables");
    scanf("%d %d", &n, &m);

    for(int i=1; i<=10; i++)
    {
        
        for(int j=n; j<=n+m-1; j++)
        
            printf("%3d\t", i*j );
            printf("\n");
            
    }

return 0;

}