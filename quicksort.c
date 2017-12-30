/*
===========================================================
Author: Tan Ho 
File type: C language
===========================================================
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdarg.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print(int *a, int number){
    printf("Entered values:\n");
    for(int i = 0; i<number; i++){
        printf("%d\n",a[i]);
    }
}

void partition(int arr[], int min, int max, int *i, int *j){
    int pivot = arr[max];
    int low;
    int high = max;
    int equal = min;

    for (low = min; low <= high; low++){
        if (arr[low] < pivot){
            swap(arr+low, arr+equal);
            equal++;
        }else if (arr[low] > pivot){
            swap(arr+low, arr+high);
            high--;
            low--;
        }
    }

    *i = low;
    *j = equal - 1;
}

void threeway_quicksort(int arr[], int min, int max){
    if(min <= max){
        int i,j;
        partition(arr, min, max, &i, &j);
        threeway_quicksort(arr, min, j);
        threeway_quicksort(arr, i, max);
    }
}

int main() {
    //Code here
    int i,number;
    printf("Please enter the number of elements!\n");
    scanf("%d",&number);
    int marks[number];

    for (i=0;i<number;i++){
        printf("Enter a element\n");
        scanf("%d",(marks+i));
    }

    threeway_quicksort(marks, 0, number-1);
    print(marks, number);
}

