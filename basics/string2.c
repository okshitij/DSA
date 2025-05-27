#include<stdio.h>
#include<string.h>
int main()
{
    char str1[50], str2[50],str3[50],h,value,j;
    int length1, length2,i,a;
    printf("Enter first string: \n");
    scanf("%s",str1);
    printf("Enter second string: \n");
    scanf("%s",str2);
    printf("Press + for inbuilt function\nPress - for user defined function\n");
    scanf("\n%c",&h);
    switch(h)
    {
        case '+':

        length1=strlen(str1);
        printf("Length of the string 1 is %d \n",length1);
        length2=strlen(str2);
        printf("Length of the string 2 is %d \n",length2);

        strcat(str1,str2);
        printf("String obtained on concatenation is %s\n",str1);
        
        strcpy(str3,str1);
        strcpy(str2,str3);
        puts(str2);
       
        value=strcmp(str1,str2);
        if(value==0)
            printf("The strings are same\n");
        else
            printf("The strings are not same\n");
        
        break; 
    
       
        case '-':
        
        i=0;
        while(str1[i]!='\0')
        {
            i++;
        }
        printf("Length of the string 1 is %d\n",i);
        j=0;
        while (str2[j]!='\0')
        {
            j++;
        }
        printf("length of string 2 is %d\n",j);
         for(i=0;str2[i]!='\0';i++)
        {
            str3[i]=str2[i];
        }
        str3[i]='\0';
        
        for(i=0;str1[i]!='\0';i++)
        {
            str2[i]=str1[i];
        }
        str2[i]='\0';
        printf("The string 2 becomes %s\n",str2);
        
        for(i=0;str1[i]!='\0'&&str3[i]!='\0';i++)
        {
            if(str1[i]==str3[i])
            {
                a=0;
            }
            else{
                a=1;
            }
        }
            if(a==0)
           printf("The strings are same\n");
            else
            printf("The strings are not same\n");
       
        
      while(str1[i]!='\0')
        i++;
        j=0;
        while(str3[j]!='\0')
        {
            str1[i]=str3[j];
            j++;
            i++;
        }
        str1[i]='\0';
        printf("String obtained of concatenation is %s\n",str1);

    }

    return 0;
}