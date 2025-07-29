#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int target){
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    } 
}

int binarySearchRecursive(int arr[], int low, int high, int target){
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binarySearchRecursive(arr, low, mid - 1, target);
    }
    else
    {
        return binarySearchRecursive(arr, mid + 1, high, target);
    }
}

void runSearchCase(const char *filename, int n) {
    int arr[n];
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    int testTargets[3] = {arr[0], arr[n / 2], arr[n - 1]};
    int testTargetsForBinary[3] = {arr[n / 2], arr[n / 4], arr[0]}; 

    const char *caseNames[] = {"Best Case", "Average Case", "Worst Case"};

    printf("\n--- Searching in %d elements ---\n", n);

    for (int i = 0; i < 3; i++) {
        clock_t start = clock();
        // int index = linearSearch(arr, n, testTargets[i]);
        int index = binarySearchRecursive(arr, 0, n-1, testTargetsForBinary[i]);
        clock_t end = clock();

        double timeTakenMs = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;

        printf("Element found at index: %d\n", index);
        printf("Time taken for %s: %.3f milliseconds\n", caseNames[i], timeTakenMs);
    }
}

int main() {
    runSearchCase("./Testcases/array_100.txt", 100);
    runSearchCase("./Testcases/array_1000.txt", 1000);
    runSearchCase("./Testcases/array_10000.txt", 10000);
    runSearchCase("./Testcases/array_100000.txt", 100000);
    return 0;
}
