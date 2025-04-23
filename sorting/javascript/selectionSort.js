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

/**
 * Implementation of the Selection Sort algorithm.
 * 
 * @param {Array} arr - Array to be sorted
 * @param {boolean} reverse - If true, sorts in descending order; if false, in ascending order
 * @returns {Array} - Sorted array
 */
function selectionSort(arr, reverse = false) {
    // Create a copy of the array to avoid modifying the original
    const result = [...arr];
    const n = result.length;
    
    for (let i = 0; i < n; i++) {
        // Assume the first unsorted element is the extreme (minimum or maximum)
        let extremeIdx = i;
        
        // Find the extreme element (minimum or maximum) in the unsorted part
        for (let j = i + 1; j < n; j++) {
            // Comparison based on sort direction
            if ((!reverse && result[j] < result[extremeIdx]) || 
                (reverse && result[j] > result[extremeIdx])) {
                extremeIdx = j;
            }
        }
        
        // Swap the extreme element with the first unsorted element
        if (extremeIdx !== i) {
            [result[i], result[extremeIdx]] = [result[extremeIdx], result[i]];
        }
    }
    
    return result;
}

/**
 * Main function to demonstrate the use of Selection Sort.
 */
function main() {
    // Example with numbers
    const arr = [64, 34, 25, 12, 22, 11, 90];
    console.log("Original array:", arr);
    
    // Ascending order
    const sortedArr = selectionSort(arr);
    console.log("Ascending order:", sortedArr);
    
    // Descending order
    const sortedArrDesc = selectionSort(arr, true);
    console.log("Descending order:", sortedArrDesc);
    
    // Example with strings
    const strArr = ["banana", "apple", "orange", "pineapple", "grape"];
    console.log("\nOriginal string array:", strArr);
    
    // Ascending order
    const sortedStrArr = selectionSort(strArr);
    console.log("Ascending order:", sortedStrArr);
    
    // Descending order
    const sortedStrArrDesc = selectionSort(strArr, true);
    console.log("Descending order:", sortedStrArrDesc);
}

// Execute the main function
main();
