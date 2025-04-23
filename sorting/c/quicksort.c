/**
 * Quicksort - Sorting Algorithm
 *
 * Time Complexity:
 * - Best case: O(n log n)
 * - Average case: O(n log n)
 * - Worst case: O(n²) when the chosen pivot is always the smallest or largest element
 *
 * Space Complexity: 
 * - O(log n) for the recursive call stack in the average case
 * - O(n) in the worst case
 *
 * How it works:
 * Quicksort is a divide and conquer sorting algorithm.
 * 1. Choose an element as a pivot
 * 2. Partition the array around the pivot (smaller elements to the left, larger to the right)
 * 3. Recursively sort the two sub-partitions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Function to partition the array around the pivot.
 * 
 * @param arr Array to be partitioned
 * @param low Starting index of the partition
 * @param high Ending index of the partition
 * @param reverse Sort direction
 * @return Pivot index after partitioning
 */
int partitionInt(int arr[], int low, int high, bool reverse) {
    // Choose the rightmost element as pivot
    int pivot = arr[high];
    
    // Index of the smaller element
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        // Comparison based on sort direction
        if ((!reverse && arr[j] <= pivot) || (reverse && arr[j] >= pivot)) {
            // Increment the index of the smaller element
            i++;
            // Swap elements
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Place the pivot in the correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    // Return the pivot index
    return i + 1;
}

/**
 * Recursive method for Quicksort.
 * 
 * @param arr Array to be sorted
 * @param low Starting index of the partition
 * @param high Ending index of the partition
 * @param reverse Sort direction
 */
void quicksortRecursiveInt(int arr[], int low, int high, bool reverse) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIdx = partitionInt(arr, low, high, reverse);
        
        // Recursively sort the sub-partitions
        quicksortRecursiveInt(arr, low, pivotIdx - 1, reverse);
        quicksortRecursiveInt(arr, pivotIdx + 1, high, reverse);
    }
}

/**
 * Implementation of the Quicksort algorithm for integers.
 * 
 * @param arr Array to be sorted
 * @param n Size of the array
 * @param reverse If true, sorts in descending order; if false, in ascending order
 */
void quicksortInt(int arr[], int n, bool reverse) {
    // Use a copy of the array to avoid modifying the original
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    
    // Start the recursive sorting
    quicksortRecursiveInt(result, 0, n - 1, reverse);
    
    // Copy the result back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
    
    // Free allocated memory
    free(result);
}

/**
 * Function to partition the string array around the pivot.
 * 
 * @param arr Array to be partitioned
 * @param low Starting index of the partition
 * @param high Ending index of the partition
 * @param reverse Sort direction
 * @return Pivot index after partitioning
 */
int partitionString(char* arr[], int low, int high, bool reverse) {
    // Choose the rightmost element as pivot
    char* pivot = arr[high];
    
    // Index of the smaller element
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        // Comparison based on sort direction
        if ((!reverse && strcmp(arr[j], pivot) <= 0) || 
            (reverse && strcmp(arr[j], pivot) >= 0)) {
            // Increment the index of the smaller element
            i++;
            // Swap elements
            char* temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Place the pivot in the correct position
    char* temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    // Return the pivot index
    return i + 1;
}

/**
 * Recursive method for Quicksort of strings.
 * 
 * @param arr Array to be sorted
 * @param low Starting index of the partition
 * @param high Ending index of the partition
 * @param reverse Sort direction
 */
void quicksortRecursiveString(char* arr[], int low, int high, bool reverse) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIdx = partitionString(arr, low, high, reverse);
        
        // Recursively sort the sub-partitions
        quicksortRecursiveString(arr, low, pivotIdx - 1, reverse);
        quicksortRecursiveString(arr, pivotIdx + 1, high, reverse);
    }
}

/**
 * Implementation of the Quicksort algorithm for strings.
 * 
 * @param arr String array to be sorted
 * @param n Size of the array
 * @param reverse If true, sorts in descending order; if false, in ascending order
 */
void quicksortString(char* arr[], int n, bool reverse) {
    // Use a copy of the array to avoid modifying the original
    char** result = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    
    // Start the recursive sorting
    quicksortRecursiveString(result, 0, n - 1, reverse);
    
    // Copy the result back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
    
    // Free allocated memory
    free(result);
}

/**
 * Function to print an integer array.
 */
void printIntArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * Function to print a string array.
 */
void printStringArray(char* arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("\"%s\"", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * Main function to demonstrate the use of Quicksort.
 */
int main() {
    // Example with numbers
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printIntArray(arr, n);
    
    // Ascending order
    int arrAsc[n];
    memcpy(arrAsc, arr, n * sizeof(int));
    quicksortInt(arrAsc, n, false);
    printf("Ascending order: ");
    printIntArray(arrAsc, n);
    
    // Descending order
    int arrDesc[n];
    memcpy(arrDesc, arr, n * sizeof(int));
    quicksortInt(arrDesc, n, true);
    printf("Descending order: ");
    printIntArray(arrDesc, n);
    
    // Example with strings
    char* strArr[] = {"banana", "apple", "orange", "pineapple", "grape"};
    int strN = sizeof(strArr) / sizeof(strArr[0]);
    
    printf("\nOriginal string array: ");
    printStringArray(strArr, strN);
    
    // Ascending order
    char* strArrAsc[strN];
    for (int i = 0; i < strN; i++) {
        strArrAsc[i] = strArr[i];
    }
    quicksortString(strArrAsc, strN, false);
    printf("Ascending order: ");
    printStringArray(strArrAsc, strN);
    
    // Descending order
    char* strArrDesc[strN];
    for (int i = 0; i < strN; i++) {
        strArrDesc[i] = strArr[i];
    }
    quicksortString(strArrDesc, strN, true);
    printf("Descending order: ");
    printStringArray(strArrDesc, strN);
    
    return 0;
}
