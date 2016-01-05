#include "LCS.h"
#include "Util.h"
#include <string.h>
#include <stdio.h>

void LCSLength(int* xArray, int xArrayLen, int* yArray, int yArrayLen, int** cTable, int rowLen, int colLen){
    int i;
    for( i = 0; i < rowLen; i++){
        *((int*)cTable + colLen * i) = 0;
    }
    //http://c-faq.com/aryptr/pass2dary.html
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
//This method doesn't work
//Need to realize Set structure which is not available now for me :(
void backtrackAll(int** cTable, int colLen, int* xArray, int* yArray, int m, int n, int** resArray,int lcsCurNumber, int maxLCSLen, int curPos){
    if( m == 0 || n == 0){
        lcsCurNumber+=1;
    } else if(xArray[m] == yArray[n]){
        backtrackAll(cTable, colLen, xArray, yArray, m-1, n - 1, resArray,lcsCurNumber, maxLCSLen, curPos);
        int i = 0;
        for( i = 0; i < lcsCurNumber; i++){
            *((int*)resArray + colLen*lcsCurNumber+curPos) = xArray[m];
        }
        curPos+=1;
    }else{
//        lcsCurNumber+=1;
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

void LCSLengthForString(char* x[], int m, char* y[], int n, int** cArray){
    int start = 0;
    while(start < m && start < n && (strcmp(x[start],y[start])==0)){
        start+=1;
    }
    int xEnd = m-1, yEnd = n-1;
    while(start <= m && start <= n && (strcmp(x[xEnd],y[yEnd]) == 0)){
        xEnd-=1;
        yEnd-=1;
    }
//    cArray = malloc((xEnd-start+2)*sizeof(int*));
//    cArray[0] = malloc((xEnd - start + 2)*(yEnd - start + 2)*sizeof(int));
    int i,j;
    for( i = 0; i <= (yEnd - start+1); i++){
        *((int*)cArray+i) = 0;
    }
    for(i = 0; i<= xEnd - start + 1; i++){
        for(j = 0; j <= yEnd - start + 1; j++){
            printf("%d|",*( (int*)cArray + i * (yEnd - start + 2) + j));
        }
        printf("\n---------------------\n");
    }

    for(j = 0; j <= (xEnd - start+1); j++){
        *((int*)cArray+j*(yEnd - start + 2)) = 0;
    }

    for(i = 0; i<= xEnd - start + 1; i++){
        for(j = 0; j <= yEnd - start + 1; j++){
            printf("%d|",*( (int*)cArray + i * (yEnd - start + 2) + j));
        }
        printf("\n---------------------\n");
    }

     for(i = 1; i<= xEnd - start + 1; i++){
        for(j = 1; j <= yEnd - start + 1; j++){
        *( (int*)cArray + i * (yEnd - start + 2) + j) = 0;
        }
    }

      for(i = 0; i<= xEnd - start + 1; i++){
        for(j = 0; j <= yEnd - start + 1; j++){
            printf("%d|",*( (int*)cArray + i * (yEnd - start + 2) + j));
        }
        printf("\n---------------------\n");
    }
    printf("\nInitial matrix array done\n");

    for( i = 1; i <= xEnd - start + 1; i++){
        for(j = 1; j <= yEnd - start + 1; j++){
            if((strcmp(x[start+i-1],y[start+j-1]))==0){
                *( (int*)cArray + i * (yEnd - start + 2) + j) = *( (int*)cArray + (i-1) * (yEnd - start + 2) + j - 1) + 1;
            }else{
                *( (int*)cArray + i * (yEnd - start + 2) + j) = myMax(*( (int*)cArray + (i-1) * (yEnd - start +2) + j),*( (int*)cArray + i * (yEnd - start + 2) + j - 1));
            }
        }
    }

    for(i = 0; i<= xEnd - start + 1; i++){
        for(j = 0; j <= yEnd - start + 1; j++){
            printf("%d|",*( (int*)cArray + i * (yEnd - start + 2) + j));
        }
        printf("\n---------------------\n");
    }
//        free(cArray[0]);
//        free(cArray);
    return;
}

void LCSLengthForStringWithoutCompression(char* x[], int m, char* y[], int n, int** cArray){
    int i,j;
    for( i = 0; i <= n; i++){
        *((int*)cArray+i) = 0;
    }
    for(i = 0; i<= m; i++){
        for(j = 0; j <= n; j++){
            printf("%d|",*( (int*)cArray + i * (n + 1) + j));
        }
        printf("\n---------------------\n");
    }

    for(j = 0; j <= m; j++){
        *((int*)cArray+j*(n+1)) = 0;
    }

    for(i = 0; i<= m; i++){
        for(j = 0; j <= n; j++){
            printf("%d|",*( (int*)cArray + i * (n + 1) + j));
        }
        printf("\n---------------------\n");
    }

     for(i = 1; i<= m; i++){
        for(j = 1; j <= n; j++){
        *( (int*)cArray + i * (n + 1) + j) = 0;
        }
    }

      for(i = 0; i<= m; i++){
        for(j = 0; j <= n; j++){
            printf("%d|",*( (int*)cArray + i * (n + 1) + j));
        }
        printf("\n---------------------\n");
    }
    printf("\nInitial matrix array done\n");

    for( i = 0; i < m; i++){
        for(j = 0; j <n; j++){
            if((strcmp(x[i],y[j]))==0){
                *( (int*)cArray + (i+1) * (n + 1) + j + 1) = *( (int*)cArray + i * (n + 1) + j) + 1;
            }else{
                *( (int*)cArray + (i+1) * (n + 1) + j + 1) = myMax(*( (int*)cArray + (i+1) * (n + 1) + j),*( (int*)cArray + i * (n + 1) + j + 1));
            }
        }
    }

    for(i = 0; i<= m; i++){
        for(j = 0; j <= n; j++){
            printf("%d|",*( (int*)cArray + i * (n + 1) + j));
        }
        printf("\n---------------------\n");
    }
//        free(cArray[0]);
//        free(cArray);
    return;
}

void printDiff(char* x[], int m, char* y[], int n, int** cArray, int cRow, int cCol){
    if(m > 0 && n > 0 && strcmp(x[m-1],y[n-1]) == 0){
        printDiff(x,m-1,y,n-1,cArray,cRow,cCol);
        printf(" %s\n",x[m-1]);
    }else{
        if( n > 0 && ( m == 0 || *((int*)cArray + m*cCol + n-1) >= *((int*)cArray + (m-1)*cCol + n))){
            printDiff(x,m,y,n-1,cArray,cRow,cCol);
            printf("+%s\n",y[n-1]);
        }
        else if(m > 0 && ( n == 0 || *((int*)cArray + (m-1)*cCol + n) > *((int*)cArray + m*cCol + n - 1))){
            printDiff(x,m-1,y,n,cArray,cRow,cCol);
            printf("-%s\n",x[m-1]);
        }
    }

}






