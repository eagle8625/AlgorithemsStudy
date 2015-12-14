#include <stdio.h>

void selectionSort(void){
    int intArray[] = {23,1,56,7,83,124,78,10};
    int len = sizeof(intArray)/sizeof(int);
    int i,j,minTmp, minTmpIdx;
    //initial value starting from zero

    for(i = 0; i < len ; i++){
        minTmp = intArray[i];
        minTmpIdx = i;
        for(j = i + 1; j < len; j++){
            if(intArray[j] < minTmp){
                minTmp = intArray[j];
                minTmpIdx = j;
            }
        }

        intArray[minTmpIdx] = intArray[i];
        intArray[i] = minTmp;
     }
    for(j = 0; j < len; j++){
        printf("%d\n",intArray[j]);
    }
   }

