#include <stdio.h>

void doMerge(int arraylen,  int arr[], int firstStartIdx, int firstEndIdx, int secondEndIdx){

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

    i = firstStartIdx;
    while(j < leftLen && k < rightLen){//Copy the remainder into arr after the loop
         if(leftArray[j] < rightArray[k]){
            arr[i] = leftArray[j];
            j++;
        }else{
            arr[i] = rightArray[k];
            k++;
        }
        i++;
    }

    if(j == leftLen){
        for(; k < rightLen; k++){
             arr[i] = rightArray[k];
             i++;
        }
    }else if(k == rightLen){
        for(; j < leftLen; j++){
            arr[i] = leftArray[j];
            i++;
        }
    }
    /*
    //In one loop compare with all the elements
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
    }*/

    printf("%s","Sorting array:\n");

    for( i = 0; i < arraylen; i++){
        printf("%d\n",arr[i]);
    }
}

void mergeSort(int arraylen, int intArray[], int startIdx, int lastIdx){
    int q;
    if(startIdx < lastIdx){
        q = (startIdx + lastIdx) / 2;
        mergeSort(arraylen,intArray, startIdx, q);
        mergeSort(arraylen,intArray, q+1, lastIdx);
        doMerge(arraylen,intArray, startIdx, q, lastIdx);
    }
}

