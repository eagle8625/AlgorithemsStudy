
int findAddend(int arraylen,int *intArray,int sum,int addend){
    //Firstly sort the array using merge sort algorithm
    mergeSort(arraylen,intArray,0,arraylen-1);
    //Secondly compute the other addend
    int theOtherAddend = sum - addend;
    //Finally, search the addend by binary searching
    int result = binarySearch(arraylen,intArray,theOtherAddend);
    return result;
}

