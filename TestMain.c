#include "InsertSort.h"
#include "AddBinary.h"
#include "SelectionSort.h"
#include "MergeSort.h"
int main(void){
//    descend();
//    ascend();
//    addBinary();
//   selectionSort();
    int mergeSortTestArray[] = {34,56,1,46,1,76,91,213};
    //In C, passing parameter not support Array type actually, just a pointer is passed
    int totalLen = sizeof(mergeSortTestArray)/sizeof(int);

    printf("%d\n",totalLen);
//    doMerge(mergeSortTestArray,0,3,7);
    mergeSort(totalLen,mergeSortTestArray,0,7);
    int q;
 printf("%s\n","The last result:");
    for( q = 0; q <= 7; q++){
        printf("%d\n",mergeSortTestArray[q]);
    }
    return 0;
}
