#include "InsertSort.h"
#include "AddBinary.h"
#include "SelectionSort.h"
#include "MergeSort.h"
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
    int findAddendTestArray[] = {34,56,1,46,2,76,91};
    int totalLen = sizeof(findAddendTestArray)/sizeof(int);
    int result = findAddend(totalLen,findAddendTestArray,100,98);
    printf("%s\n%d\n","Addend search result:",result);

    return 0;
}
