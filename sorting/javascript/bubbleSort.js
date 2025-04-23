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

/**
 * Implementation of the Bubble Sort algorithm.
 * 
 * @param {Array} arr - Array to be sorted
 * @param {boolean} reverse - If true, sorts in descending order; if false, in ascending order
 * @returns {Array} - Sorted array
 */
function bubbleSort(arr, reverse = false) {
    // Create a copy of the array to avoid modifying the original
    const result = [...arr];
    const n = result.length;
    
    // Optimization flag: if no swaps are made in a pass, the array is already sorted
    for (let i = 0; i < n; i++) {
        let swapped = false;
        
        // In each pass, the largest element "bubbles" to the end
        // Therefore, we don't need to check the last i elements
        for (let j = 0; j < n - i - 1; j++) {
            // Comparison based on sort direction
            if ((!reverse && result[j] > result[j + 1]) || (reverse && result[j] < result[j + 1])) {
                // Swap elements
                [result[j], result[j + 1]] = [result[j + 1], result[j]];
                swapped = true;
            }
        }
        
        // If no swaps were made in this pass, the array is already sorted
        if (!swapped) {
            break;
        }
    }
    
    return result;
}

/**
 * Main function to demonstrate the use of Bubble Sort.
 */
function main() {
    // Example with numbers
    const arr = [64, 34, 25, 12, 22, 11, 90];
    console.log("Original array:", arr);
    
    // Ascending order
    const sortedArr = bubbleSort(arr);
    console.log("Ascending order:", sortedArr);
    
    // Descending order
    const sortedArrDesc = bubbleSort(arr, true);
    console.log("Descending order:", sortedArrDesc);
    
    // Example with strings
    const strArr = ["banana", "apple", "orange", "pineapple", "grape"];
    console.log("\nOriginal string array:", strArr);
    
    // Ascending order
    const sortedStrArr = bubbleSort(strArr);
    console.log("Ascending order:", sortedStrArr);
    
    // Descending order
    const sortedStrArrDesc = bubbleSort(strArr, true);
    console.log("Descending order:", sortedStrArrDesc);
}

// Execute the main function
main();
