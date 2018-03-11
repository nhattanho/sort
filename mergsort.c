#include <stdlib.h>
#include <stdio.h>

void merg(int arr[], int low, int mid, int high){
    int n = high - low + 1;
    int a[n];
    int min = low;
    int low1 = mid + 1;
    int i;
    for(i = 0; i < n; i++){
        if (arr[low] <= arr[low1]){
            a[i] = arr[low++];
            if (low > mid){
                low = low1;
                break;
            }
        }else{
            a[i] = arr[low1++];
            if(low1 > high) break;
        }
    }
    for(int j=1; j<n-i; j++){
        arr[min+i+j] = arr[low++];
    }

    for(int j=0;j<=i;j++){
        arr[min++] = a[j];
    }   
}

void mergsort(int arr[], int low, int high){
    if( low < high){
        int mid = (low + high)/2;
        mergsort(arr, low, mid);
        mergsort(arr, mid+1, high);
        merg(arr,low, mid, high);
    }
}
int main() {
    //Code here
    int number;
    printf("Please enter the number of elements!\n");
    scanf("%d",&number);
    int marks[number];

    for(int i=0;i<number;i++){
        printf("Enter a element\n");
        scanf("%d",(marks+i));
    }
    mergsort(marks,0,number-1);
    printf("\nEntered values:\n");
    for(int i=0;i<number;i++){
        printf("%d\n",*(marks+i));
    }
   
    return 0;

}

