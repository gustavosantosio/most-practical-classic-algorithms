/**
 * Radix Sort - Sorting Algorithm
 *
 * Time Complexity:
 * - Best case: O(nk) where n is the number of elements and k is the number of digits in the largest number
 * - Average case: O(nk)
 * - Worst case: O(nk)
 *
 * Space Complexity: O(n+k) where k is the range of possible values
 *
 * How it works:
 * Radix Sort is a non-comparative sorting algorithm that sorts integers by processing individual digits.
 * 1. Start with the least significant digit (units)
 * 2. Group numbers into buckets according to the current digit value
 * 3. Collect the numbers from the buckets in order
 * 4. Repeat the process for each digit position, up to the most significant digit
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Helper function to find the maximum number in the array.
 * 
 * @param arr Array of integers
 * @param n Size of the array
 * @return The maximum number in the array
 */
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/**
 * Helper function to sort numbers based on a specific digit.
 * 
 * @param arr Array to be sorted
 * @param n Size of the array
 * @param exp Digit position (1 for units, 10 for tens, etc.)
 * @param reverse Sort direction
 */
void countingSort(int arr[], int n, int exp, bool reverse) {
    int* output = (int*)malloc(n * sizeof(int));
    int count[10] = {0}; // 10 possible digits (0-9)
    
    // Count occurrences of each digit at the current position
    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }
    
    // Adjust count to contain actual positions in the output array
    if (!reverse) {
        // Ascending order
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
    } else {
        // Descending order
        for (int i = 8; i >= 0; i--) {
            count[i] += count[i + 1];
        }
    }
    
    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }
    
    // Copy the result back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    // Free the memory allocated
    free(output);
}

/**
 * Implementation of the Radix Sort algorithm for positive integers.
 * 
 * @param arr Array of positive integers to be sorted
 * @param n Size of the array
 * @param reverse If true, sorts in descending order; if false, in ascending order
 */
void radixSort(int arr[], int n, bool reverse) {
    // Create a copy of the array to avoid modifying the original
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    
    // Find the maximum number to determine the number of digits
    int max = getMax(result, n);
    
    // Perform counting sort for each digit position
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(result, n, exp, reverse);
    }
    
    // Copy the result back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
    
    // Free the memory allocated
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
 * Main function to demonstrate the use of Radix Sort.
 */
int main() {
    // Example with numbers
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printIntArray(arr, n);
    
    // Ascending order
    int arrAsc[n];
    memcpy(arrAsc, arr, n * sizeof(int));
    radixSort(arrAsc, n, false);
    printf("Ascending order: ");
    printIntArray(arrAsc, n);
    
    // Descending order
    int arrDesc[n];
    memcpy(arrDesc, arr, n * sizeof(int));
    radixSort(arrDesc, n, true);
    printf("Descending order: ");
    printIntArray(arrDesc, n);
    
    return 0;
}
