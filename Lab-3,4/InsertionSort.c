#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ,", arr[i]);
    } 
}

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

}

void main(){
    FILE *file;
    clock_t start, end;
    double cpu_time_used;
    int n = 100;
    int arr[n];
    
    file = fopen("./Testcases/worst_100.txt", "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    printf("Worst Case Scenario of %d Numbers :\n",n);
    start = clock();
    insertionSort(arr, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort Worst Case of %d numbers of the array : %f seconds\n", n,  cpu_time_used);

    printf("\n");

    file = fopen("./Testcases/best_100.txt", "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    printf("Best Case Scenario of %d Numbers :\n",n);
    start = clock();
    insertionSort(arr, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array of Best Case %d numbers  : %f seconds\n", n, cpu_time_used);

    printf("\n");
    
    file = fopen("./Testcases/avg_100.txt", "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    printf("Avg Case Scenario of %d Numbers :",n);
    start = clock();
    insertionSort(arr, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array of Avg Case %d numbers  : %f seconds\n", n, cpu_time_used);

    printf("\n");

    n = 1000;
    int arr2[n];
    file = fopen("./Testcases/best_1000.txt", "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr2[i]);
    }
    fclose(file);

    printf("Best Case Scenario of %d Numbers :",n);
    start = clock();
    insertionSort(arr2, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array of Best Case %d numbers  : %f seconds\n", n, cpu_time_used);

    printf("\n");

    file = fopen("./Testcases/worst_1000.txt", "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr2[i]);
    }
    fclose(file);

    printf("Worst Case Scenario of %d Numbers :",n);
    start = clock();
    insertionSort(arr2, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array of Worst Case %d numbers  : %f seconds\n", n, cpu_time_used);

    printf("\n");

    file = fopen("./Testcases/avg_1000.txt", "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr2[i]);
    }
    fclose(file);

    printf("Avg Case Scenario of %d Numbers :",n);
    start = clock();
    insertionSort(arr2, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array of Avg Case %d numbers  : %f seconds\n", n, cpu_time_used);

    printf("\n");

    n = 100000;
    int arr3[n];

    file = fopen("./Testcases/best_100000.txt", "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr3[i]);
    }
    fclose(file);

    printf("Best Case Scenario of %d Numbers :",n);
    start = clock();
    insertionSort(arr3, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array of Best Case %d numbers  : %f seconds\n", n, cpu_time_used);

    printf("\n");

    file = fopen("./Testcases/worst_100000.txt", "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr3[i]);
    }
    fclose(file);

    printf("Worst Case Scenario of %d Numbers :",n);
    start = clock();
    insertionSort(arr3, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array of Worst Case %d numbers  : %f seconds\n", n, cpu_time_used);

    printf("\n");

    file = fopen("./Testcases/avg_100000.txt", "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr3[i]);
    }
    fclose(file);

    printf("Avg Case Scenario of %d Numbers :",n);
    start = clock();
    insertionSort(arr3, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array of Avg Case %d numbers  : %f seconds\n", n, cpu_time_used);

    printf("\n");
   
    
    
}