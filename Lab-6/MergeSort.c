#include<stdio.h>
#include <limits.h>

void printArray(int arr[], int n){
    printf("\n---------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n---------------------\n");
}


void merge(int arr[], int low, int mid, int high){

    int n = mid - low + 2;
    int m = high - mid  + 1;

    int actualLength = high - low + 1;
    printf("acutal : %d\n",actualLength);
    int left[n];
    int right[m];

    for (int i = 0; i < n - 1; i++)
    {
        left[i] = arr[low+i];
    }

    for (int i = 0; i < m - 1; i++)
{
    right[i] = arr[mid + 1 + i];
}


    
    left[n - 1] = INT_MAX;
    right[m - 1] = INT_MAX;
// printf("Left");
//     printArray(left, n);
// printf("Right");

//     printArray(right, m);
    int i = 0;
    int j = 0;

    for (int k = low; k <= high; k++)
    {
        if (left[i] < right[j])
        {
            printf("min left : %d\n",left[i]);
            arr[k] = left[i];
            i++;
        }
        else
        {   
            printf("min right: %d\n",right[j]);
            
            arr[k] = right[j];
            j++;
        }
    }
    printArray(arr,actualLength);
    return;
    
}

void mergeSort(int arr[], int low, int high){
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
    
}

void main(){
    int arr[] = {22, 12, 12, 45, 43, 15, -4};
    int n = 7;

    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
}