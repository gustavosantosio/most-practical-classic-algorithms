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

/**
 * Implementation of the Merge Sort algorithm.
 * 
 * @param {Array} arr - Array to be sorted
 * @param {boolean} reverse - If true, sorts in descending order; if false, in ascending order
 * @returns {Array} - Sorted array
 */
function mergeSort(arr, reverse = false) {
    // Create a copy of the array to avoid modifying the original
    const result = [...arr];
    
    // Base case: if the array has size 0 or 1, it's already sorted
    if (result.length <= 1) {
        return result;
    }
    
    // Divide the array into two halves
    const mid = Math.floor(result.length / 2);
    const left = result.slice(0, mid);
    const right = result.slice(mid);
    
    // Recursively sort each half
    const sortedLeft = mergeSort(left, reverse);
    const sortedRight = mergeSort(right, reverse);
    
    // Merge the two sorted halves
    return merge(sortedLeft, sortedRight, reverse);
}

/**
 * Function to merge two sorted sublists.
 * 
 * @param {Array} left - Left sorted sublist
 * @param {Array} right - Right sorted sublist
 * @param {boolean} reverse - Sort direction
 * @returns {Array} - Merged sorted array
 */
function merge(left, right, reverse) {
    const result = [];
    let i = 0, j = 0;
    
    // Compare elements from the two sublists and add the smaller (or larger) to the result
    while (i < left.length && j < right.length) {
        if (!reverse) {
            // Ascending order
            if (left[i] <= right[j]) {
                result.push(left[i]);
                i++;
            } else {
                result.push(right[j]);
                j++;
            }
        } else {
            // Descending order
            if (left[i] >= right[j]) {
                result.push(left[i]);
                i++;
            } else {
                result.push(right[j]);
                j++;
            }
        }
    }
    
    // Add the remaining elements from the left sublist
    while (i < left.length) {
        result.push(left[i]);
        i++;
    }
    
    // Add the remaining elements from the right sublist
    while (j < right.length) {
        result.push(right[j]);
        j++;
    }
    
    return result;
}

/**
 * Main function to demonstrate the use of Merge Sort.
 */
function main() {
    // Example with numbers
    const arr = [64, 34, 25, 12, 22, 11, 90];
    console.log("Original array:", arr);
    
    // Ascending order
    const sortedArr = mergeSort(arr);
    console.log("Ascending order:", sortedArr);
    
    // Descending order
    const sortedArrDesc = mergeSort(arr, true);
    console.log("Descending order:", sortedArrDesc);
    
    // Example with strings
    const strArr = ["banana", "apple", "orange", "pineapple", "grape"];
    console.log("\nOriginal string array:", strArr);
    
    // Ascending order
    const sortedStrArr = mergeSort(strArr);
    console.log("Ascending order:", sortedStrArr);
    
    // Descending order
    const sortedStrArrDesc = mergeSort(strArr, true);
    console.log("Descending order:", sortedStrArrDesc);
}

// Execute the main function
main();
