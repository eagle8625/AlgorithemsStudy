#include <stdio.h>

void addBinary(){
    int binaryArrayA[] = {0,1,0,0,1,1,1,1,0,0,0,1,1,1,1,1};
    int binaryArrayB[] = {1,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1};

    int len = sizeof(binaryArrayA)/sizeof(int);
    int binaryArrayC[len + 1];

    int i,j, carry = 0;

    for(i = 0; i < len; i++){
        binaryArrayC[i] = (binaryArrayA[i] + binaryArrayB[i] + carry) % 2;//remainder
        carry = (binaryArrayA[i] + binaryArrayB[i] + carry) / 2;//

    }
    binaryArrayC[i] = carry;

    for(j = 0; j < len + 1; j++){
        printf("%d",binaryArrayC[j]);
    }
    printf("\n");
}
