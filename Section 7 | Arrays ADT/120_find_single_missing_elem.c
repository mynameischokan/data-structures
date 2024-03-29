/*
 *  ======================
 *  Finding Single missing element in sorted Array
 *  ======================
 *  Have to find missing element;
 *      1. [1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12] => sequence of first natural numbers
            - sum of first n natural nums => n(n+1)/2
                                             12(12+1)/2
                                             78 - SUM of elements = missing element
        2. [6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17] => NOT a first sequence of natural numbers
            - define first(l), last(h) elements and total num of elements
            - start subtracting index from element: l-i
                                                    6-0 = 6
                                                    7-1 = 6
                                                    8-2 = 6
                                                    9-3 = 6
                                                    10-4 = 6
                                                    11-5 = 6
                                                    13-6 = 7
            - when detect diff, add index to diff:  6+6 = 12 (is missing element)
 */

#include <stdio.h>
#include <stdlib.h>


struct Array
{
    int *A;
    int size;
    int length;
};


void Display(struct Array arr)
{
    printf("Elemnets are: \n");
    for(int i=0; i<arr.length; i++)
    {
        printf("%d\n", arr.A[i]);
    }
}


int Sum(struct Array elems)
{
    int s = 0;
    for(int i=0; i<elems.length; i++)
        s += elems.A[i];
    return s;
}


void FindMissingElemInSeqOfFirstNaturalNums(struct Array arr)
{
    int n = arr.A[arr.length-1];
    int sumOfNaturalNums = n*(n+1)/2;
    printf("Missing element is: %d", sumOfNaturalNums-Sum(arr));
}


void FindMissingElemInSeqOfNumbers(struct Array arr)
{
    int diff = arr.A[0];
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i]-i != diff)
        {
            printf("Missing element is: %d", i+diff);
            break;
         }
    }
}


int main()
{
    struct Array arr;
    arr.size = 15;
    arr.length = 11;
    arr.A = (int *)malloc(arr.size * sizeof(int));
    int elems[11] = {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};
    arr.A = elems;
    return 0;
}
