/**
 * Heap Sort - Sorting Algorithm
 *
 * Time Complexity:
 * - Best case: O(n log n)
 * - Average case: O(n log n)
 * - Worst case: O(n log n)
 *
 * Space Complexity: O(1) - in-place sorting
 *
 * How it works:
 * Heap Sort uses a binary heap data structure to sort elements.
 * 1. Build a max heap (for ascending order) or min heap (for descending order) from the array
 * 2. Repeatedly extract the root element (which is the largest or smallest) and rebuild the heap
 * 3. The extracted elements form the sorted array
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Helper function to maintain the heap property for integers.
 * 
 * @param arr Array to heapify
 * @param n Size of the heap
 * @param i Index of the current node
 * @param reverse If true, creates a min heap; if false, creates a max heap
 */
void heapifyInt(int arr[], int n, int i, bool reverse) {
    // Initialize the largest/smallest as the root
    int extreme = i;
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2;  // Right child
    
    // Check if left child exists and is greater/smaller than the root
    if (left < n) {
        if ((!reverse && arr[left] > arr[extreme]) || (reverse && arr[left] < arr[extreme])) {
            extreme = left;
        }
    }
    
    // Check if right child exists and is greater/smaller than the largest/smallest so far
    if (right < n) {
        if ((!reverse && arr[right] > arr[extreme]) || (reverse && arr[right] < arr[extreme])) {
            extreme = right;
        }
    }
    
    // If the largest/smallest is not the root
    if (extreme != i) {
        // Swap the root with the largest/smallest
        int temp = arr[i];
        arr[i] = arr[extreme];
        arr[extreme] = temp;
        
        // Recursively heapify the affected sub-tree
        heapifyInt(arr, n, extreme, reverse);
    }
}

/**
 * Implementation of the Heap Sort algorithm for integers.
 * 
 * @param arr Array to be sorted
 * @param n Size of the array
 * @param reverse If true, sorts in descending order; if false, in ascending order
 */
void heapSortInt(int arr[], int n, bool reverse) {
    // Use a copy of the array to avoid modifying the original
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    
    // Build a max heap (for ascending order) or min heap (for descending order)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyInt(result, n, i, reverse);
    }
    
    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        // Swap the root (maximum/minimum element) with the last element
        int temp = result[0];
        result[0] = result[i];
        result[i] = temp;
        
        // Call heapify on the reduced heap
        heapifyInt(result, i, 0, reverse);
    }
    
    // Copy the result back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
    
    // Free allocated memory
    free(result);
}

/**
 * Helper function to maintain the heap property for strings.
 * 
 * @param arr Array to heapify
 * @param n Size of the heap
 * @param i Index of the current node
 * @param reverse If true, creates a min heap; if false, creates a max heap
 */
void heapifyString(char* arr[], int n, int i, bool reverse) {
    // Initialize the largest/smallest as the root
    int extreme = i;
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2;  // Right child
    
    // Check if left child exists and is greater/smaller than the root
    if (left < n) {
        if ((!reverse && strcmp(arr[left], arr[extreme]) > 0) || 
            (reverse && strcmp(arr[left], arr[extreme]) < 0)) {
            extreme = left;
        }
    }
    
    // Check if right child exists and is greater/smaller than the largest/smallest so far
    if (right < n) {
        if ((!reverse && strcmp(arr[right], arr[extreme]) > 0) || 
            (reverse && strcmp(arr[right], arr[extreme]) < 0)) {
            extreme = right;
        }
    }
    
    // If the largest/smallest is not the root
    if (extreme != i) {
        // Swap the root with the largest/smallest
        char* temp = arr[i];
        arr[i] = arr[extreme];
        arr[extreme] = temp;
        
        // Recursively heapify the affected sub-tree
        heapifyString(arr, n, extreme, reverse);
    }
}

/**
 * Implementation of the Heap Sort algorithm for strings.
 * 
 * @param arr String array to be sorted
 * @param n Size of the array
 * @param reverse If true, sorts in descending order; if false, in ascending order
 */
void heapSortString(char* arr[], int n, bool reverse) {
    // Use a copy of the array to avoid modifying the original
    char** result = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    
    // Build a max heap (for ascending order) or min heap (for descending order)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyString(result, n, i, reverse);
    }
    
    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        // Swap the root (maximum/minimum element) with the last element
        char* temp = result[0];
        result[0] = result[i];
        result[i] = temp;
        
        // Call heapify on the reduced heap
        heapifyString(result, i, 0, reverse);
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
 * Main function to demonstrate the use of Heap Sort.
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
    heapSortInt(arrAsc, n, false);
    printf("Ascending order: ");
    printIntArray(arrAsc, n);
    
    // Descending order
    int arrDesc[n];
    memcpy(arrDesc, arr, n * sizeof(int));
    heapSortInt(arrDesc, n, true);
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
    heapSortString(strArrAsc, strN, false);
    printf("Ascending order: ");
    printStringArray(strArrAsc, strN);
    
    // Descending order
    char* strArrDesc[strN];
    for (int i = 0; i < strN; i++) {
        strArrDesc[i] = strArr[i];
    }
    heapSortString(strArrDesc, strN, true);
    printf("Descending order: ");
    printStringArray(strArrDesc, strN);
    
    return 0;
}
