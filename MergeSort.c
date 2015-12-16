#include <stdio.h>

void doMerge(int arr[], int firstStartIdx, int firstEndIdx, int secondEndIdx){
        int arrIntLen = sizeof(arr);
    int intLen = sizeof(int);
    printf("%d\n%d\n",arrIntLen, intLen);

    int i,j,k,leftLen, rightLen;
    leftLen = firstEndIdx - firstStartIdx + 1;
    rightLen = secondEndIdx - firstEndIdx;
    int leftArray[leftLen];
    int rightArray[rightLen];
    printf("%s","Left child array:\n");

    for( i = firstStartIdx,j = 0; i <= firstEndIdx; i++,j++ ){
        leftArray[j] = arr[i];
        printf("%d\n",leftArray[j]);

    }
    printf("%s","Right child array:\n");
    for(i = firstEndIdx + 1, j = 0; i <= secondEndIdx; i++, j++){
        rightArray[j] = arr[i];
        printf("%d\n",rightArray[j]);
    }

    j = 0;
    k = 0;

    for(i = firstStartIdx; i <= secondEndIdx; i++){

        if(j == leftLen){
            for(; k < rightLen; k++){
                arr[i] = rightArray[k];
                i++;
            }
            break;
        }

        if(k == rightLen){
            for(; j < leftLen; j++){
                arr[i] = leftArray[j];
                i++;
            }
            break;
        }

        if(leftArray[j] < rightArray[k]){
            arr[i] = leftArray[j];
                j++;
        }else{
            arr[i] = rightArray[k];
                k++;
        }
    }

    int totalLen = sizeof(arr)/sizeof(int);
    printf("%s","Sorted child array:\n");
    printf("%d\n",totalLen);

    for( i = 0; i < totalLen; i++){
        printf("%d\n",arr[i]);
    }
}

void mergeSort(int intArray[], int startIdx, int lastIdx){
    int q;
    if(startIdx < lastIdx){
        q = (startIdx + lastIdx) / 2;
        mergeSort(intArray, startIdx, q);
        mergeSort(intArray, q+1, lastIdx);
        doMerge(intArray, startIdx, q, lastIdx);
    }
}

