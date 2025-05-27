#include <stdio.h>
#include <string.h>
 void main() {
	int i,j,keylen,msglen,flag=0;
	char input[100], key[30],temp[100],checksum[100],rem[30],key1[30];
	
	printf("Enter Data: ");
	scanf("%s",input);
	printf("Enter Key: ");
	scanf("%s",key);
	
	keylen=strlen(key);
	msglen=strlen(input);
	strcpy(key1,key);
	
  // append zeroes at end of original mesg
	for (i=0;i<keylen-1;i++) {
		input[msglen+i]='0';
	}

  // copy input into temp (so we don't directly modify input)
  strcpy(temp, input);




  // apply binary division on temp (dividend) using key (divisor)
  for (int i = 0; i < msglen; i++) {
    
    // if we get a '1' in temp, start XOR operation
    if (temp[i] == '1') {
      
      // copare respective digits of key and temp
      for (int j = 0; j < keylen; j++) {

        // apply xor operation (here he modify temp directyl)
        if (temp[i + j] == key[j]) {
          temp[i + j] = '0';
        }
        else {
          temp[i + j] = '1';
        }
      }
    }
  }

  // copy input into checksum variale
  for (int i = 0; i < msglen; i++) {
    checksum[i] = input[i];
  }

  // copy (keylen - 1) digits as last digits of checksum
  for (int i = msglen; i < msglen + keylen - 1; i++) {
    checksum[i] = temp[i];
  }

  // put null byte at end of checksum
  checksum[msglen + keylen - 1] = '\0';

  printf("Data sent: %s", checksum);

	 flag =0;
	 


  // binary division on receiver side
   for (int i = 0; i < msglen; i++) {
    if (checksum[i] == '1') {
      for (int j = 0; j < keylen; j++) {
        if (checksum[i + j] == key[j]) {
          checksum[i + j] = '0';
        }
        else {
          checksum[i + j] = '1';
        }
      }
    }
  }
   printf("\nChecksum: %s", checksum);

  // if we find '1' in checksum (i.e. the remainder), error has occured
  // so, increment the flag
  for (int i = 0; i < msglen + keylen - 1; i++) {
    if (checksum[i] == '1') {
    flag++;
    }
  }
	 
  // if flag if 0, no error. else, error.
	 if (flag==0)
	 printf("\nNo Error");
	 else 
	 printf("\nError is Detected");
	
	
}