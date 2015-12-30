#include "LCS.h"
#include "Util.h"

void LCSLength(int* xArray, int xArrayLen, int* yArray, int yArrayLen, int** cTable, int rowLen, int colLen){
    int i;
    for( i = 0; i < rowLen; i++){
        *((int*)cTable + colLen * i) = 0;
    }
    for( i = 0; i < colLen; i++){
        *((int*)cTable + i ) = 0;
    }
    int j;
    for( i = 0; i < rowLen; i++){
        for( j = 0; j < colLen; j++){
            printf("%d|",*((int*)cTable + colLen*i + j));
        }
        printf("\n");
        printf("----------------\n");

    }

    for( i = 1; i < xArrayLen; i++){
        for( j = 1; j < yArrayLen; j++){
            if(xArray[i] == yArray[j]){
                *((int*)cTable + colLen * i + j) = *((int*)cTable + colLen * (i-1) + j - 1) + 1;
            }else{
                *((int*)cTable + colLen * i + j) = myMax(*((int*)cTable + colLen * i + j-1), *((int*)cTable + colLen * (i-1) + j));
            }
        }
    }
}
//m,n is the max index of an array
void backtrack(int** cTable, int colLen, int* xArray, int* yArray, int m, int n, int* resArray, int maxLCSLen, int curPos){
    if(m == 0 || n == 0){
        return;
    }
    if(xArray[m] == yArray[n]){
        resArray[curPos] = xArray[m];
        curPos-=1;
        backtrack(cTable,colLen, xArray, yArray, m-1,n-1,resArray,maxLCSLen, curPos);
    }else{
        int j = *((int*)cTable + colLen * m + n - 1);
        int k = *((int*)cTable + colLen * (m-1) + n);
        if( j > k){
            backtrack(cTable, colLen, xArray, yArray, m,n-1,resArray,maxLCSLen, curPos);
        }else{
            backtrack(cTable, colLen, xArray, yArray, m-1,n,resArray,maxLCSLen, curPos);
        }
    }
}

//https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Longest_common_subsequence#Reading_out_all_LCSs
//http://selfsupport.com.pk/questions/22299345/how-to-print-all-possible-solutions-for-longest-common-subsequence
void backtrackAll(int** cTable, int colLen, int* xArray, int* yArray, int m, int n, int** resArray,int lcsCurNumber, int maxLCSLen, int curPos){
    if( m == 0 || n == 0){
        lcsCurNumber+=1;
    } else if(xArray[m] == yArray[n]){
        int i = 0;
        for( i = 0; i <= lcsCurNumber; i++){
            *((int*)resArray + colLen*lcsCurNumber+curPos) = xArray[m];
        }
        curPos-=1;
    }else{
        lcsCurNumber+=1;
        int j = *((int*)cTable + colLen*m + n - 1);
        int k = *((int*)cTable + colLen*(m-1) + n);
        if(j >= k){
            backtrackAll(cTable, colLen, xArray, yArray, m, n - 1, resArray,lcsCurNumber, maxLCSLen, curPos);
        }
        if(k >= j){
            backtrackAll(cTable, colLen, xArray, yArray, m-1, n,resArray,lcsCurNumber,maxLCSLen, curPos);
        }
    }
}




