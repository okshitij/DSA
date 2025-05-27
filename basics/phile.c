#include <stdio.h>
int main()
{
    //three modes, r,w,a
    FILE *fileptr;
    fileptr=fopen("C:\\Users\\sw\\OneDrive\\Desktop\\file.txt","w");
    if (fileptr=NULL)
        printf("Error");
    else
        fprintf(fileptr,"hello my name is kshitij");
    fclose(fileptr);
    return 0;
}