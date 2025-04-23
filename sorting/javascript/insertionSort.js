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

/**
 * Implementation of the Insertion Sort algorithm.
 * 
 * @param {Array} arr - Array to be sorted
 * @param {boolean} reverse - If true, sorts in descending order; if false, in ascending order
 * @returns {Array} - Sorted array
 */
function insertionSort(arr, reverse = false) {
    // Create a copy of the array to avoid modifying the original
    const result = [...arr];
    const n = result.length;
    
    // Start from the second element (index 1)
    for (let i = 1; i < n; i++) {
        // Element to be inserted into the sorted part
        const key = result[i];
        
        // Move elements of the sorted part that are greater (or smaller) than key
        // one position ahead of their current position
        let j = i - 1;
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
    
    return result;
}

/**
 * Main function to demonstrate the use of Insertion Sort.
 */
function main() {
    // Example with numbers
    const arr = [64, 34, 25, 12, 22, 11, 90];
    console.log("Original array:", arr);
    
    // Ascending order
    const sortedArr = insertionSort(arr);
    console.log("Ascending order:", sortedArr);
    
    // Descending order
    const sortedArrDesc = insertionSort(arr, true);
    console.log("Descending order:", sortedArrDesc);
    
    // Example with strings
    const strArr = ["banana", "apple", "orange", "pineapple", "grape"];
    console.log("\nOriginal string array:", strArr);
    
    // Ascending order
    const sortedStrArr = insertionSort(strArr);
    console.log("Ascending order:", sortedStrArr);
    
    // Descending order
    const sortedStrArrDesc = insertionSort(strArr, true);
    console.log("Descending order:", sortedStrArrDesc);
}

// Execute the main function
main();
