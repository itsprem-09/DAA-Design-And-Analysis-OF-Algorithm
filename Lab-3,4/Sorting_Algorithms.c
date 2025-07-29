#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubbleSort(int arr[], int n){
    int swapped = 0;
    
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;  
                swapped = 1; 
            }
            
        }
        if (swapped == 0)
        {
            // printf("Array is Already Sorted!\n");
            // printArray(arr, n);
            return;
        } 
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void heapify(int arr[], int n, int i){
    int max = i;
    int leftChild = 2 * i - 1;
    int rightChild = 2 * i + 1;

    if (leftChild < n && arr[leftChild] > arr[max])
    {
        max = leftChild;
    }
    if (rightChild < n && arr[rightChild] > arr[max])
    {
        max = rightChild;
    }

    if (max != i)
    {
        int t = arr[max];
        arr[max] = arr[i];
        arr[i] = t;

        heapify(arr, n, max);
    }
}

void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n; i >= 0; i--)
    {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;

        heapify(arr, i, 0);
    }
}

void readData(const char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++)
        fscanf(file, "%d", &arr[i]);
    fclose(file);
}

typedef void (*SortFunction)(int[], int);

void testSort(int choice) {
    int sizes[] = {100, 1000, 10000, 100000};
    const char *caseFiles[] = {
        "./Testcases/worst_100000.txt",
        "./Testcases/avg_100000.txt",
        "./Testcases/best_100000.txt"
    };
    const char *caseNames[] = {"Worst Case", "Average Case", "Best Case"};

    SortFunction sortFunction;
    char sort_function_name[20];  // Fixed buffer size

    switch (choice) {
        case 1:
            sortFunction = bubbleSort;
            strcpy(sort_function_name, "Bubble Sort");
            break;
        case 2:
            sortFunction = insertionSort;
            strcpy(sort_function_name, "Insertion Sort");
            break;
        case 3:
            sortFunction = selectionSort;
            strcpy(sort_function_name, "Selection Sort");
            break;
        case 4:
            sortFunction = heapSort;
            strcpy(sort_function_name, "Heap Sort");
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("\n---- %s Sort Results ----\n", sort_function_name);

    int arr[100000];

    for (int i = 0; i < 4; i++) {
        int n = sizes[i];
        printf("\nFor n = %d:\n", sizes[i]);

        for (int c = 0; c < 3; c++) {
            readData(caseFiles[c], arr, n);

            clock_t start = clock();
            sortFunction(arr, n);
            clock_t end = clock();

            double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Time taken to sort the array: %s: %.4f seconds\n", 
                   caseNames[c], timeTaken);
        }
    }

    printf("------------------------------\n");
}

int main() {
    int choice;

    do {
        printf("\n===== Sorting Time Menu =====\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Heap Sort\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting...\n");
            break;
        } else if (choice >= 1 && choice <= 4) {
            testSort(choice);
        } else {
            printf("Invalid choice! Please enter 0-3.\n");
        }

    } while (1);

    return 0;
}