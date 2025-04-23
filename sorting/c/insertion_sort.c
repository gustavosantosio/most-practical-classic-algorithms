/**
 * Insertion Sort - Sorting Algorithm
 *
 * Time Complexity:
 * - Best case: O(n) when the array is already sorted
 * - Average case: O(n²)
 * - Worst case: O(n²)
 *
 * Space Complexity: O(1) - in-place sorting
 *
 * How it works:
 * Insertion Sort builds the sorted list one item at a time.
 * The algorithm divides the array into a sorted part and an unsorted part.
 * In each iteration, it removes one element from the unsorted part and
 * inserts it into the correct position within the sorted part.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Implementation of the Insertion Sort algorithm for integers.
 * 
 * @param arr Array to be sorted
 * @param n Size of the array
 * @param reverse If true, sorts in descending order; if false, in ascending order
 */
void insertionSortInt(int arr[], int n, bool reverse) {
    // Use a copy of the array to avoid modifying the original
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    
    // Start from the second element (index 1)
    for (int i = 1; i < n; i++) {
        // Element to be inserted into the sorted part
        int key = result[i];
        
        // Move elements of the sorted part that are greater (or smaller) than key
        // one position ahead of their current position
        int j = i - 1;
        if (!reverse) {
            // Ascending order
            while (j >= 0 && result[j] > key) {
                result[j + 1] = result[j];
                j--;
            }
        } else {
            // Descending order
            while (j >= 0 && result[j] < key) {
                result[j + 1] = result[j];
                j--;
            }
        }
        
        // Insert the element in the correct position
        result[j + 1] = key;
    }
    
    // Copy the result back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
    
    // Free allocated memory
    free(result);
}

/**
 * Implementation of the Insertion Sort algorithm for strings.
 * 
 * @param arr String array to be sorted
 * @param n Size of the array
 * @param reverse If true, sorts in descending order; if false, in ascending order
 */
void insertionSortString(char* arr[], int n, bool reverse) {
    // Use a copy of the array to avoid modifying the original
    char** result = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    
    // Start from the second element (index 1)
    for (int i = 1; i < n; i++) {
        // Element to be inserted into the sorted part
        char* key = result[i];
        
        // Move elements of the sorted part that are greater (or smaller) than key
        // one position ahead of their current position
        int j = i - 1;
        if (!reverse) {
            // Ascending order
            while (j >= 0 && strcmp(result[j], key) > 0) {
                result[j + 1] = result[j];
                j--;
            }
        } else {
            // Descending order
            while (j >= 0 && strcmp(result[j], key) < 0) {
                result[j + 1] = result[j];
                j--;
            }
        }
        
        // Insert the element in the correct position
        result[j + 1] = key;
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
 * Main function to demonstrate the use of Insertion Sort.
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
    insertionSortInt(arrAsc, n, false);
    printf("Ascending order: ");
    printIntArray(arrAsc, n);
    
    // Descending order
    int arrDesc[n];
    memcpy(arrDesc, arr, n * sizeof(int));
    insertionSortInt(arrDesc, n, true);
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
    insertionSortString(strArrAsc, strN, false);
    printf("Ascending order: ");
    printStringArray(strArrAsc, strN);
    
    // Descending order
    char* strArrDesc[strN];
    for (int i = 0; i < strN; i++) {
        strArrDesc[i] = strArr[i];
    }
    insertionSortString(strArrDesc, strN, true);
    printf("Descending order: ");
    printStringArray(strArrDesc, strN);
    
    return 0;
}
