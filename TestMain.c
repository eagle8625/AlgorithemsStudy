#include "InsertSort.h"
#include "AddBinary.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "LCS.h"
#include "Util.h"
#include <stdio.h>
int main(void){
//    descend();
//    ascend();
//    addBinary();
//   selectionSort();

/*//merge sort test code
    int mergeSortTestArray[] = {34,56,1,46,1,76,91};
    //In C, passing parameter not support Array type actually, just a pointer is passed
    int totalLen = sizeof(mergeSortTestArray)/sizeof(int);
    printf("%d\n",totalLen);
//    doMerge(mergeSortTestArray,0,3,7);
    mergeSort(totalLen,mergeSortTestArray,0,6);
    int q;
    printf("%s\n","The last result:");
    for( q = 0; q < totalLen; q++){
        printf("%d\n",mergeSortTestArray[q]);
    }
  */

   /*
    int binarySearchTestArray[] = {1,1,34,46,56,78};
    int result = binarySearch(6,binarySearchTestArray,782);
    printf("%s\n%d\n","binary search result:",result);
    */
    /*
    int findAddendTestArray[] = {34,56,1,46,2,76,91};
    int totalLen = sizeof(findAddendTestArray)/sizeof(int);
    int result = findAddend(totalLen,findAddendTestArray,100,98);
    printf("%s\n%d\n","Addend search result:",result);
    */

//merge sort test code

    /*
    int mergeSortTestArray[] = {34,56,1,46,1,76,91};
    //In C, passing parameter not support Array type actually, just a pointer is passed
    int totalLen = sizeof(mergeSortTestArray)/sizeof(int);
    printf("%d\n",totalLen);
//    doMerge(mergeSortTestArray,0,3,7);
    int * count = malloc(sizeof(int));
    *count = 0;
    findInversionsNumByMergeSort(totalLen,mergeSortTestArray,0,6,count);
    int q;
    printf("%s\n","The last result:");
    for( q = 0; q < totalLen; q++){
        printf("%d\n",mergeSortTestArray[q]);
    }
    printf("%d\n",*count);

    free(count);*/
//The first element is only added to compute LCS,
    int xArray[] = {-1,34,56,1,46,1,76,91};
    int yArray[] = {-1,34,2,76,28};
    int cArray[8][5] = {0};
    LCSLength(xArray,8,yArray,5,cArray,8,5);
    //Get LCS' table containing the LCS length
    int i, j;
    for( i = 0; i < 8; i++){
        for( j = 0; j < 5; j++){
            printf("%d|",cArray[i][j]);
        }
        printf("\n");
        printf("--------\n");
    }
    int lcsLength = cArray[7][4] ;
    printf("LCS length is %d\n", lcsLength);

    int lcsArray[lcsLength];
    backtrack(cArray, 5, xArray,yArray,7,4,lcsArray, lcsLength, lcsLength - 1);

    printf("LCS is:");
    for( i = 0; i < lcsLength; i++){
        printf("%d|",lcsArray[i]);
    }
    printf("\n-----One LCS End.------------\n");
    int ** allLcs = malloc( 8 * sizeof(int*));
    allLcs[0] = malloc(8*5*sizeof(int));
    for( i = 1; i < 8; i++){
        allLcs[i] = allLcs[0] + i*5;
    }

    backtrackAll(cArray,5,xArray,yArray,7,4,allLcs,0,lcsLength,lcsLength - 1);
    for( i = 0; i < 8; i++){
        for( j = 0; j < 5; j++){
            printf("%d|",*((int*)allLcs + i * 8 + j));
        }
        printf("\n----------------------\n");
    }
    free(allLcs[0]);
    free(allLcs);

    return 0;
}
