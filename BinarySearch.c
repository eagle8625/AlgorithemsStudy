#include <stdio.h>
#include <stdbool.h>

int binarySearch(int arraylen, int array[], int compareValue){
    int middleIdx = arraylen/2;
    int startIdx = 0;
    int endIdx = arraylen - 1;
    bool found = false;
    while( middleIdx >= 0 && middleIdx < arraylen && (startIdx <= endIdx)){
        if( array[middleIdx] == compareValue){
            printf("%s\n","Found, index:");
            printf("%d\n",middleIdx);
            found = true;
            break;
        }else if(array[middleIdx] > compareValue){
            endIdx = middleIdx - 1;
            middleIdx = (endIdx - startIdx + 1) / 2;
        }else{
            startIdx = middleIdx + 1;
            middleIdx = (endIdx - startIdx ) / 2 + startIdx;
        }
    }
    if(found) return middleIdx;
    else return -1;
}

