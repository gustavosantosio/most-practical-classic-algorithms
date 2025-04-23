/**
 * Merge Sort - Sorting Algorithm
 *
 * Time Complexity:
 * - Best case: O(n log n)
 * - Average case: O(n log n)
 * - Worst case: O(n log n)
 *
 * Space Complexity: O(n) - requires additional space for temporary arrays
 *
 * How it works:
 * Merge Sort is a divide and conquer sorting algorithm.
 * 1. Divide the array into two halves
 * 2. Recursively sort each half
 * 3. Merge the two sorted halves to produce the final sorted array
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Function to merge two sorted integer sublists.
 * 
 * @param left Left sorted sublist
 * @param leftSize Size of the left sublist
 * @param right Right sorted sublist
 * @param rightSize Size of the right sublist
 * @param reverse Sort direction
 * @return Merged sorted array
 */
int* mergeInt(int left[], int leftSize, int right[], int rightSize, bool reverse) {
    int* result = (int*)malloc((leftSize + rightSize) * sizeof(int));
    int i = 0, j = 0, k = 0;
    
    // Compare elements from the two sublists and add the smaller (or larger) to the result
    while (i < leftSize && j < rightSize) {
        if (!reverse) {
            // Ascending order
            if (left[i] <= right[j]) {
                result[k++] = left[i++];
            } else {
                result[k++] = right[j++];
            }
        } else {
            // Descending order
            if (left[i] >= right[j]) {
                result[k++] = left[i++];
            } else {
                result[k++] = right[j++];
            }
        }
    }
    
    // Add the remaining elements from the left sublist
    while (i < leftSize) {
        result[k++] = left[i++];
    }
    
    // Add the remaining elements from the right sublist
    while (j < rightSize) {
        result[k++] = right[j++];
    }
    
    return result;
}

/**
 * Recursive method for Merge Sort of integers.
 * 
 * @param arr Array to be sorted
 * @param size Size of the array
 * @param reverse Sort direction
 * @return Sorted array
 */
int* mergeSortRecursiveInt(int arr[], int size, bool reverse) {
    // Base case: if the array has size 0 or 1, it's already sorted
    if (size <= 1) {
        int* result = (int*)malloc(size * sizeof(int));
        if (size == 1) {
            result[0] = arr[0];
        }
        return result;
    }
    
    // Divide the array into two halves
    int mid = size / 2;
    int* left = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc((size - mid) * sizeof(int));
    
    // Copy the elements to the sublists
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    
    // Recursively sort each half
    int* sortedLeft = mergeSortRecursiveInt(left, mid, reverse);
    int* sortedRight = mergeSortRecursiveInt(right, size - mid, reverse);
    
    // Free the memory of the original sublists
    free(left);
    free(right);
    
    // Merge the two sorted halves
    int* result = mergeInt(sortedLeft, mid, sortedRight, size - mid, reverse);
    
    // Free the memory of the sorted sublists
    free(sortedLeft);
    free(sortedRight);
    
    return result;
}

/**
 * Implementation of the Merge Sort algorithm for integers.
 * 
 * @param arr Array to be sorted
 * @param n Size of the array
 * @param reverse If true, sorts in descending order; if false, in ascending order
 */
void mergeSortInt(int arr[], int n, bool reverse) {
    // Start the recursive sorting
    int* result = mergeSortRecursiveInt(arr, n, reverse);
    
    // Copy the result back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
    
    // Free allocated memory
    free(result);
}

/**
 * Function to merge two sorted string sublists.
 * 
 * @param left Left sorted sublist
 * @param leftSize Size of the left sublist
 * @param right Right sorted sublist
 * @param rightSize Size of the right sublist
 * @param reverse Sort direction
 * @return Merged sorted array
 */
char** mergeString(char* left[], int leftSize, char* right[], int rightSize, bool reverse) {
    char** result = (char**)malloc((leftSize + rightSize) * sizeof(char*));
    int i = 0, j = 0, k = 0;
    
    // Compare elements from the two sublists and add the smaller (or larger) to the result
    while (i < leftSize && j < rightSize) {
        if (!reverse) {
            // Ascending order
            if (strcmp(left[i], right[j]) <= 0) {
                result[k++] = left[i++];
            } else {
                result[k++] = right[j++];
            }
        } else {
            // Descending order
            if (strcmp(left[i], right[j]) >= 0) {
                result[k++] = left[i++];
            } else {
                result[k++] = right[j++];
            }
        }
    }
    
    // Add the remaining elements from the left sublist
    while (i < leftSize) {
        result[k++] = left[i++];
    }
    
    // Add the remaining elements from the right sublist
    while (j < rightSize) {
        result[k++] = right[j++];
    }
    
    return result;
}

/**
 * Recursive method for Merge Sort of strings.
 * 
 * @param arr Array to be sorted
 * @param size Size of the array
 * @param reverse Sort direction
 * @return Sorted array
 */
char** mergeSortRecursiveString(char* arr[], int size, bool reverse) {
    // Base case: if the array has size 0 or 1, it's already sorted
    if (size <= 1) {
        char** result = (char**)malloc(size * sizeof(char*));
        if (size == 1) {
            result[0] = arr[0];
        }
        return result;
    }
    
    // Divide the array into two halves
    int mid = size / 2;
    char** left = (char**)malloc(mid * sizeof(char*));
    char** right = (char**)malloc((size - mid) * sizeof(char*));
    
    // Copy the elements to the sublists
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    
    // Recursively sort each half
    char** sortedLeft = mergeSortRecursiveString(left, mid, reverse);
    char** sortedRight = mergeSortRecursiveString(right, size - mid, reverse);
    
    // Free the memory of the original sublists
    free(left);
    free(right);
    
    // Merge the two sorted halves
    char** result = mergeString(sortedLeft, mid, sortedRight, size - mid, reverse);
    
    // Free the memory of the sorted sublists
    free(sortedLeft);
    free(sortedRight);
    
    return result;
}

/**
 * Implementation of the Merge Sort algorithm for strings.
 * 
 * @param arr String array to be sorted
 * @param n Size of the array
 * @param reverse If true, sorts in descending order; if false, in ascending order
 */
void mergeSortString(char* arr[], int n, bool reverse) {
    // Start the recursive sorting
    char** result = mergeSortRecursiveString(arr, n, reverse);
    
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
 * Main function to demonstrate the use of Merge Sort.
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
    mergeSortInt(arrAsc, n, false);
    printf("Ascending order: ");
    printIntArray(arrAsc, n);
    
    // Descending order
    int arrDesc[n];
    memcpy(arrDesc, arr, n * sizeof(int));
    mergeSortInt(arrDesc, n, true);
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
    mergeSortString(strArrAsc, strN, false);
    printf("Ascending order: ");
    printStringArray(strArrAsc, strN);
    
    // Descending order
    char* strArrDesc[strN];
    for (int i = 0; i < strN; i++) {
        strArrDesc[i] = strArr[i];
    }
    mergeSortString(strArrDesc, strN, true);
    printf("Descending order: ");
    printStringArray(strArrDesc, strN);
    
    return 0;
}
