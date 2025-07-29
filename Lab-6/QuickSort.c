#include <stdio.h>
#include<time.h>
#include <stdlib.h>

void generateBestCase(int arr[], int i, int j){
    if (i < j)
    {
        int mid = (i + j) / 2;

        int temp = arr[i];
        arr[i] = arr[mid];
        arr[mid] = temp;

        generateBestCase(arr, i + 1, mid);
        generateBestCase(arr, mid + 1, j);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (pivot >= arr[i] && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }

        if (i < j)
        {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void qs(int arr[], int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

// void swap(int *a, int *b) {
//     int t = *a; *a = *b; *b = t;
// }

// int partition(int arr[], int low, int high) {
//     // randomly pick a pivot and move it to the end
//     int pivotIndex = low + rand() % (high - low + 1);
//     swap(&arr[pivotIndex], &arr[high]);
//     int pivot = arr[high];

//     int i = low - 1;
//     for (int j = low; j < high; j++) {
//         if (arr[j] <= pivot) {
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i + 1], &arr[high]);
//     return i + 1;
// }

// // QuickSort with tail‐recursion elimination
// void qs(int arr[], int low, int high) {
//     while (low < high) {
//         int p = partition(arr, low, high);
//         // recurse on smaller side first
//         if (p - low < high - p) {
//             qs(arr, low, p - 1);
//             low = p + 1;
//         } else {
//             qs(arr, p + 1, high);
//             high = p - 1;
//         }
//     }
// }

int main(){
    FILE *file;

    clock_t start, end;
    double cpu_time_used;
    int n=100000;
    int array[n];

    // file=fopen("./Testcases/worst_100000.txt", "r");
    // for(int i=0; i<n; i++){
    //     fscanf(file, "%d", &array[i]);
    // }
    // fclose(file);

    // printf("Worst case scenario: \n");
    // start = clock();
    // qs(array, 0 ,n-1);
    // end=clock();

    // cpu_time_used=((double)(end-start))/ CLOCKS_PER_SEC;
    // printf("Time taken to sort the array: %f seconds\n", cpu_time_used);

    file=fopen("./Testcases/avg_100000.txt", "r");
    for(int i=0; i<n; i++){
        fscanf(file, "%d", &array[i]);
    }
    fclose(file);

    printf("Average case scenario: \n");
    start = clock();
    qs(array, 0 ,n-1);
    end=clock();

    cpu_time_used=((double)(end-start))/ CLOCKS_PER_SEC;
    printf("Time taken to sort the array: %f seconds\n", cpu_time_used);

    file=fopen("./Testcases/best_100000.txt", "r");
    for(int i=0; i<n; i++){
        fscanf(file, "%d", &array[i]);
    }
    fclose(file);

    generateBestCase(array, 0, n - 1);

    printf("Best case scenario: \n");
    start = clock();
    qs(array, 0 ,n-1);
    end=clock();

    cpu_time_used=((double)(end-start))/ CLOCKS_PER_SEC;
    printf("Time taken to sort the array: %f seconds\n", cpu_time_used);


    printf("-------------------------------------------------------\n");


    n=1000;
    int array2[n];

    file=fopen("./Testcases/worst_100000.txt", "r");
    for(int i=0; i<n; i++){
        fscanf(file, "%d", &array2[i]);
    }
    fclose(file);

    printf("Worst case scenario: \n");
    start = clock();
    qs(array2, 0 ,n-1);
    end=clock();

    cpu_time_used=((double)(end-start))/ CLOCKS_PER_SEC;
    printf("Time taken to sort the array: %f seconds\n", cpu_time_used);

    file=fopen("./Testcases/avg_100000.txt", "r");
    for(int i=0; i<n; i++){
        fscanf(file, "%d", &array2[i]);
    }
    fclose(file);

    printf("Average case scenario: \n");
    start = clock();
    qs(array2, 0 ,n-1);
    end=clock();

    cpu_time_used=((double)(end-start))/ CLOCKS_PER_SEC;
    printf("Time taken to sort the array: %f seconds\n", cpu_time_used);

    file=fopen("./Testcases/best_100000.txt", "r");
    for(int i=0; i<n; i++){
        fscanf(file, "%d", &array2[i]);
    }
    fclose(file);

    generateBestCase(array2, 0, n - 1);

    printf("Best case scenario: \n");
    start = clock();
    qs(array2, 0 ,n-1);
    end=clock();

    cpu_time_used=((double)(end-start))/ CLOCKS_PER_SEC;
    printf("Time taken to sort the array: %f seconds\n", cpu_time_used);

     printf("-------------------------------------------------------\n");


    n=100;
    int array3[n];

    file=fopen("./Testcases/worst_100000.txt", "r");
    for(int i=0; i<n; i++){
        fscanf(file, "%d", &array3[i]);
    }
    fclose(file);

    printf("Worst case scenario: \n");
    start = clock();
    qs(array3, 0 ,n-1);
    end=clock();

    cpu_time_used=((double)(end-start))/ CLOCKS_PER_SEC;
    printf("Time taken to sort the array: %f seconds\n", cpu_time_used);

    file=fopen("./Testcases/avg_100000.txt", "r");
    for(int i=0; i<n; i++){
        fscanf(file, "%d", &array3[i]);
    }
    fclose(file);

    printf("Average case scenario: \n");
    start = clock();
    qs(array3, 0 ,n-1);
    end=clock();

    cpu_time_used=((double)(end-start))/ CLOCKS_PER_SEC;
    printf("Time taken to sort the array: %f seconds\n", cpu_time_used);

    file=fopen("./Testcases/best_100000.txt", "r");
    for(int i=0; i<n; i++){
        fscanf(file, "%d", &array3[i]);
    }
    fclose(file);

    generateBestCase(array3, 0, n - 1);

    printf("Best case scenario: \n");
    start = clock();
    qs(array3, 0 ,n-1);
    end=clock();

    cpu_time_used=((double)(end-start))/ CLOCKS_PER_SEC;
    printf("Time taken to sort the array: %f seconds\n", cpu_time_used);

    return 0;
}