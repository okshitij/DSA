#include<stdio.h>
#include<string.h>

#define N strlen(crc_key)

int i,j;
char data[30];
char crc_key[20];
char checksum[30];

void XOR();

int main()
{
    printf("Enter data to be transmitted: ");
    scanf("%s", &data);

    printf("Enter the CRC key: ");
    scanf("%s", &crc_key);

    int data_length = strlen(data);
    for(i = data_length; i<data_length+N-1; i++)
        data[i] = '0';
    printf("new data = %s\n", data); 


    for(i=0; i<N; i++)
        checksum[i] = data[i];
    
    do
    {
        if(checksum[0] == '1')
            XOR();
        for(j=0; j<N-1; j++)
            checksum[j] = checksum[j+1];
        checksum[j] = data[i++];
    }while(i <= data_length+N-1);


    printf("the check value is: %s\n", &checksum);


    for(i=data_length;i<data_length+N-1;i++)
        data[i]=checksum[i-data_length];


    printf("final data to be sent is: %s\n", data);

    printf("Enter the received data: ");
    scanf("%s", data);
    printf("Data received: %s\n", data);

    for(i=0; i<N; i++)
        checksum[i] = data[i];
    
    do
    {
        if(checksum[0] == '1')
            XOR();
        for(j=0; j<N-1; j++)
            checksum[j] = checksum[j+1];
        checksum[j] = data[i++];
    }while(i <= data_length+N-1);
    

    int count = 0;
    for(i=0; (i<N-1) && (checksum[i] != '1'); i++)
    {
        if(i<N-1)
            printf("error detected");
        else
            printf("no error");
    }

    return 0;
}

void XOR()
{
    for(j=1; j<N; j++)
        checksum[j] = ((checksum[j] == crc_key[j]) ? '0' : '1');
}

