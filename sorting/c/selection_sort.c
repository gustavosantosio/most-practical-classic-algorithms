/**
 * Selection Sort - Sorting Algorithm
 *
 * Time Complexity:
 * - Best case: O(n²)
 * - Average case: O(n²)
 * - Worst case: O(n²)
 *
 * Space Complexity: O(1) - in-place sorting
 *
 * How it works:
 * Selection Sort divides the array into two parts: a sorted subarray and an unsorted subarray.
 * In each iteration, the algorithm finds the smallest (or largest) element from the unsorted subarray
 * and places it in the correct position in the sorted subarray.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Implementation of the Selection Sort algorithm for integers.
 * 
 * @param arr Array to be sorted
 * @param n Size of the array
 * @param reverse If true, sorts in descending order; if false, in ascending order
 */
void selectionSortInt(int arr[], int n, bool reverse) {
    // Use a copy of the array to avoid modifying the original
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        // Assume the first unsorted element is the extreme (minimum or maximum)
        int extremeIdx = i;
        
        // Find the extreme element (minimum or maximum) in the unsorted part
        for (int j = i + 1; j < n; j++) {
            // Comparison based on sort direction
            if ((!reverse && result[j] < result[extremeIdx]) || 
                (reverse && result[j] > result[extremeIdx])) {
                extremeIdx = j;
            }
        }
        
        // Swap the extreme element with the first unsorted element
        if (extremeIdx != i) {
            int temp = result[i];
            result[i] = result[extremeIdx];
            result[extremeIdx] = temp;
        }
    }
    
    // Copy the result back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
    
    // Free allocated memory
    free(result);
}

/**
 * Implementation of the Selection Sort algorithm for strings.
 * 
 * @param arr String array to be sorted
 * @param n Size of the array
 * @param reverse If true, sorts in descending order; if false, in ascending order
 */
void selectionSortString(char* arr[], int n, bool reverse) {
    // Use a copy of the array to avoid modifying the original
    char** result = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        // Assume the first unsorted element is the extreme (minimum or maximum)
        int extremeIdx = i;
        
        // Find the extreme element (minimum or maximum) in the unsorted part
        for (int j = i + 1; j < n; j++) {
            // Comparison based on sort direction
            if ((!reverse && strcmp(result[j], result[extremeIdx]) < 0) || 
                (reverse && strcmp(result[j], result[extremeIdx]) > 0)) {
                extremeIdx = j;
            }
        }
        
        // Swap the extreme element with the first unsorted element
        if (extremeIdx != i) {
            char* temp = result[i];
            result[i] = result[extremeIdx];
            result[extremeIdx] = temp;
        }
    }
    
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
 * Main function to demonstrate the use of Selection Sort.
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
    selectionSortInt(arrAsc, n, false);
    printf("Ascending order: ");
    printIntArray(arrAsc, n);
    
    // Descending order
    int arrDesc[n];
    memcpy(arrDesc, arr, n * sizeof(int));
    selectionSortInt(arrDesc, n, true);
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
    selectionSortString(strArrAsc, strN, false);
    printf("Ascending order: ");
    printStringArray(strArrAsc, strN);
    
    // Descending order
    char* strArrDesc[strN];
    for (int i = 0; i < strN; i++) {
        strArrDesc[i] = strArr[i];
    }
    selectionSortString(strArrDesc, strN, true);
    printf("Descending order: ");
    printStringArray(strArrDesc, strN);
    
    return 0;
}
