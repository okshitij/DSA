#include <stdio.h>
int count(int n,char *arr)
{
    int i,j,k,v=0,c=0;
    char arr_vowel[100];
    char arr_consonant[100];

    for (i = 0;i < n;i++)
    {
        if (*(arr+i) == 'a' || *(arr+i) == 'e' || *(arr+i) == 'i' || *(arr+i) == 'o' || *(arr+i) == 'u')
        {
            arr_vowel[v] = *(arr+i);
            v++;
        }
        else if (*(arr+i) == ' ')
            continue;
        else
        {
            arr_consonant[c] = *(arr+i);
            c++;
        }
    }
    printf("number of vowels are %d\n",v);
    for (j = 0;j < v;j++)
        printf("%c",arr_vowel[j]);
    printf("\n");
    printf("number of consonants are %d\n",c);
    for (k = 0;k < c;k++)
        printf("%c",arr_consonant[k]);
}

int main()
{
    int n,i,j,k;
    printf("enter the number of elements in string\n");
    scanf("%d",&n);

    char arr[100];
    printf("enter the string\n");
    scanf("%*c");

    for (i = 0;i < n;i++)
        scanf("%c",&arr[i]);
    printf("\n");

    count(n,arr);

}