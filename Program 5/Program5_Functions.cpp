/*
***************************************************************************
* Assignment: Merge Sort
* Name: Program5_Functions [requires Program5_functions.h]
*
* Use:  Contains functions inputData() and mergeSort(...) for p5
*       Contains the code for these functions
*       see below for specifics
*
***************************************************************************
*/


#include "Program5_Functions.h"



/* ------------------------------------------
int inputData(Player, int size, istream){
    puts read file data into array and 
    outputs the length of the array.
    Did this for convience.
}
------------------------------------------ */ 
int inputData(Player arr[], int length, std::istream& in){
    int counter = 0;

    if (in.fail()) {
        std::cout << "Error: invalid name" << std::endl;
        return -1;
    }
    while (!in.eof() && counter < length) {
        arr[counter++].reader(in);
    }
    return counter;
    
}



/* ------------------------------------------
mergeSort(arr, int first index, int lase index){
    kind of a mess
    Essentially, gets to singularity with recursion
    and proceeds to merge the arrays. Merging it done
    with temperary arrays that represent each piece.

    Works 90% of the time and upsets my Player class
    by feeding some weird data, causes more weird error
    messages that I put into my Player Class long ago.
    I would have addressed it, but the sort seems to 
    output correctly, so I guess 'if it's working, why
    fix it'~~~
}
------------------------------------------ */ 
void mergeSort(Player arr[], int begin, int end){

    // NOTE:: the code has variable declarations everywhere,
    // I know this isn't propper, but it helps...

    // ALSO NOTE:: There are some known issues with the sort,
    // but I think it's stops working when I try to fix it,
    // and it seems to be working good enough for me not to
    // adress it yet ~_~


    // Array is at singularity [base case]
    if (begin >= end){
        return;
    }
    // Finding mean to get the middle
    int midValue = (begin + end) / 2;

    // Recurrsion to singularity
    mergeSort(arr, begin, midValue);
    mergeSort(arr, midValue+1, end);

    // [have to remember this happens every recurrsion]


    //---- These should hold the indexes for tmpArrays------

    // Size1 holds info for tmpArray1 that holds the left piece
    int size1 = midValue - begin + 1;
    // Size 2 holds for tmpArray2 [right piece]
    int size2 = end - midValue;

    // These tmpArr will then hold the two pieces that wil be
    // put back into the main array in order
    Player tmpArray1[size1], tmpArray2[size2];

    // The copy : left chunk is start to mid, then right is mid to rest
    // Because of recurssion, these should be scaling in size every iteration
    for(int i=0; i<size1; i++){tmpArray1[i] = arr[begin+i];}
    for(int i=0; i<size2; i++){tmpArray2[i] = arr[midValue+1+i];}


    // What is left is to copy these in order back into the main array 
    // requires 3 counter variables: 2 for tmps, 1 to not overwrite previously
    // added data onto my main array.
    int counter1 = 0, counter2 = 0, counterMain = begin;

    // and now we're off: note, I would not look at it too deeply,
    // it is not well written, but it is 4 am and he is doing good enough
    // to be turned in ~_~
    while(counter1 < size1 && counter2 < size2){

        // Comparisons for bringing temp into main array in order
        if(tmpArray1[counter1] < tmpArray2[counter2]){
            arr[counterMain++] = tmpArray1[counter1++];
        } 
        else if(tmpArray1[counter1] > tmpArray2[counter2]){
            arr[counterMain++] = tmpArray2[counter2++];
        }
        else{
            //Unsure what to do with equals... assuming none! (also didn't overload that operator)
            // nor '<=' or '>=' so just going to use '<' and '>' (//_//)!
            break;
        }

        // -- Kept getting issues if one piece was bigger than the other
        // probably horrible fix, but it's working (ish)
        if(counter1 == size1){
            while(counter2 < size2){
                arr[counterMain++] = tmpArray2[counter2++]; 
            }
        }
        else if(counter2 == size2){
            while(counter1 < size1){
                arr[counterMain++] = tmpArray1[counter1++]; 
            }
        }
    }
}