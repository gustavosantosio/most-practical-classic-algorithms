/**
 * Quicksort - Sorting Algorithm
 *
 * Time Complexity:
 * - Best case: O(n log n)
 * - Average case: O(n log n)
 * - Worst case: O(n²) when the chosen pivot is always the smallest or largest element
 *
 * Space Complexity: 
 * - O(log n) for the recursive call stack in the average case
 * - O(n) in the worst case
 *
 * How it works:
 * Quicksort is a divide and conquer sorting algorithm.
 * 1. Choose an element as a pivot
 * 2. Partition the array around the pivot (smaller elements to the left, larger to the right)
 * 3. Recursively sort the two sub-partitions
 */

/**
 * Implementation of the Quicksort algorithm.
 * 
 * @param {Array} arr - Array to be sorted
 * @param {boolean} reverse - If true, sorts in descending order; if false, in ascending order
 * @returns {Array} - Sorted array
 */
function quicksort(arr, reverse = false) {
    // Create a copy of the array to avoid modifying the original
    const result = [...arr];
    
    // Internal function for recursive sorting
    function quicksortRecursive(low, high) {
        if (low < high) {
            // Partition the array and get the pivot index
            const pivotIdx = partition(low, high);
            
            // Recursively sort the sub-partitions
            quicksortRecursive(low, pivotIdx - 1);
            quicksortRecursive(pivotIdx + 1, high);
        }
    }
    
    // Function to partition the array around the pivot
    function partition(low, high) {
        // Choose the rightmost element as pivot
        const pivot = result[high];
        
        // Index of the smaller element
        let i = low - 1;
        
        for (let j = low; j < high; j++) {
            // Comparison based on sort direction
            if ((!reverse && result[j] <= pivot) || (reverse && result[j] >= pivot)) {
                // Increment the index of the smaller element
                i++;
                // Swap elements
                [result[i], result[j]] = [result[j], result[i]];
            }
        }
        
        // Place the pivot in the correct position
        [result[i + 1], result[high]] = [result[high], result[i + 1]];
        
        // Return the pivot index
        return i + 1;
    }
    
    // Start the recursive sorting
    quicksortRecursive(0, result.length - 1);
    
    return result;
}

/**
 * Main function to demonstrate the use of Quicksort.
 */
function main() {
    // Example with numbers
    const arr = [64, 34, 25, 12, 22, 11, 90];
    console.log("Original array:", arr);
    
    // Ascending order
    const sortedArr = quicksort(arr);
    console.log("Ascending order:", sortedArr);
    
    // Descending order
    const sortedArrDesc = quicksort(arr, true);
    console.log("Descending order:", sortedArrDesc);
    
    // Example with strings
    const strArr = ["banana", "apple", "orange", "pineapple", "grape"];
    console.log("\nOriginal string array:", strArr);
    
    // Ascending order
    const sortedStrArr = quicksort(strArr);
    console.log("Ascending order:", sortedStrArr);
    
    // Descending order
    const sortedStrArrDesc = quicksort(strArr, true);
    console.log("Descending order:", sortedStrArrDesc);
}

// Execute the main function
main();
