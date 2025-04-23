/**
 * Bubble Sort - Sorting Algorithm
 *
 * Time Complexity:
 * - Best case: O(n) when the array is already sorted
 * - Average case: O(n²)
 * - Worst case: O(n²)
 *
 * Space Complexity: O(1) - in-place sorting
 *
 * How it works:
 * Bubble Sort compares adjacent pairs of elements and swaps them if they are in the wrong order.
 * The algorithm traverses the array multiple times, "bubbling" the largest element to the end in each pass.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Implementation of the Bubble Sort algorithm for integers.
 * 
 * @param arr Array to be sorted
 * @param n Size of the array
 * @param reverse If true, sorts in descending order; if false, in ascending order
 */
void bubbleSortInt(int arr[], int n, bool reverse) {
    // Use a copy of the array to avoid modifying the original
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    
    // Optimization flag: if no swaps are made in a pass, the array is already sorted
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        
        // In each pass, the largest element "bubbles" to the end
        // Therefore, we don't need to check the last i elements
        for (int j = 0; j < n - i - 1; j++) {
            // Comparison based on sort direction
            if ((!reverse && result[j] > result[j + 1]) || (reverse && result[j] < result[j + 1])) {
                // Swap elements
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
                swapped = true;
            }
        }
        
        // If no swaps were made in this pass, the array is already sorted
        if (!swapped) {
            break;
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
 * Implementation of the Bubble Sort algorithm for strings.
 * 
 * @param arr String array to be sorted
 * @param n Size of the array
 * @param reverse If true, sorts in descending order; if false, in ascending order
 */
void bubbleSortString(char* arr[], int n, bool reverse) {
    // Use a copy of the array to avoid modifying the original
    char** result = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        
        for (int j = 0; j < n - i - 1; j++) {
            // Comparison based on sort direction
            if ((!reverse && strcmp(result[j], result[j + 1]) > 0) || 
                (reverse && strcmp(result[j], result[j + 1]) < 0)) {
                // Swap elements
                char* temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
                swapped = true;
            }
        }
        
        if (!swapped) {
            break;
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
 * Main function to demonstrate the use of Bubble Sort.
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
    bubbleSortInt(arrAsc, n, false);
    printf("Ascending order: ");
    printIntArray(arrAsc, n);
    
    // Descending order
    int arrDesc[n];
    memcpy(arrDesc, arr, n * sizeof(int));
    bubbleSortInt(arrDesc, n, true);
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
    bubbleSortString(strArrAsc, strN, false);
    printf("Ascending order: ");
    printStringArray(strArrAsc, strN);
    
    // Descending order
    char* strArrDesc[strN];
    for (int i = 0; i < strN; i++) {
        strArrDesc[i] = strArr[i];
    }
    bubbleSortString(strArrDesc, strN, true);
    printf("Descending order: ");
    printStringArray(strArrDesc, strN);
    
    return 0;
}
