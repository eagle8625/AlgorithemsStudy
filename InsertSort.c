#include <stdio.h>


int mainT(void){
   descend();
   ascend();
   return 0;
}

void descend(){
    int intArray[] = {34,56,1,46,1,76,91,213};
    int len = sizeof(intArray)/sizeof(int);
    int j,i;
    for(j = 1; j < len; j++){
        int key = intArray[j];
        i = j - 1;
        while(i>=0){
            if(intArray[i] < key){
              intArray[i+1] = intArray[i];
              i--;
            }else{
                break;
            }
        }
        intArray[i+1] = key;
    }
    for(i = 0; i < len; i++){
        printf("%d\n",intArray[i]);

    }
    printf("Descend sorting end!\n");
}

void ascend(){
    int intArray[] = {23,1,56,7,83,124,78,10};
    int len = sizeof(intArray)/sizeof(int);
    int i,j;
    for(j = 1; j < len; j++){
        i = j - 1;
        int key = intArray[j];
        while(i >= 0 && (intArray[i]> key)){
            intArray[i+1] = intArray[i];
            i--;
        }
        intArray[i+1] = key;
    }
    for(i = 0; i < len; i++){
        printf("%d\n",intArray[i]);

    }
}
