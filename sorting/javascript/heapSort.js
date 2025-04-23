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

/**
 * Implementation of the Heap Sort algorithm.
 * 
 * @param {Array} arr - Array to be sorted
 * @param {boolean} reverse - If true, sorts in descending order; if false, in ascending order
 * @returns {Array} - Sorted array
 */
function heapSort(arr, reverse = false) {
    // Create a copy of the array to avoid modifying the original
    const result = [...arr];
    const n = result.length;
    
    // Build a max heap (for ascending order) or min heap (for descending order)
    for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
        heapify(result, n, i, reverse);
    }
    
    // Extract elements one by one
    for (let i = n - 1; i > 0; i--) {
        // Swap the root (maximum/minimum element) with the last element
        [result[0], result[i]] = [result[i], result[0]];
        
        // Call heapify on the reduced heap
        heapify(result, i, 0, reverse);
    }
    
    return result;
}

/**
 * Helper function to maintain the heap property.
 * 
 * @param {Array} arr - Array to heapify
 * @param {number} n - Size of the heap
 * @param {number} i - Index of the current node
 * @param {boolean} reverse - If true, creates a min heap; if false, creates a max heap
 */
function heapify(arr, n, i, reverse) {
    // Initialize the largest/smallest as the root
    let extreme = i;
    const left = 2 * i + 1;  // Left child
    const right = 2 * i + 2;  // Right child
    
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
    if (extreme !== i) {
        // Swap the root with the largest/smallest
        [arr[i], arr[extreme]] = [arr[extreme], arr[i]];
        
        // Recursively heapify the affected sub-tree
        heapify(arr, n, extreme, reverse);
    }
}

/**
 * Main function to demonstrate the use of Heap Sort.
 */
function main() {
    // Example with numbers
    const arr = [64, 34, 25, 12, 22, 11, 90];
    console.log("Original array:", arr);
    
    // Ascending order
    const sortedArr = heapSort(arr);
    console.log("Ascending order:", sortedArr);
    
    // Descending order
    const sortedArrDesc = heapSort(arr, true);
    console.log("Descending order:", sortedArrDesc);
    
    // Example with strings
    const strArr = ["banana", "apple", "orange", "pineapple", "grape"];
    console.log("\nOriginal string array:", strArr);
    
    // Ascending order
    const sortedStrArr = heapSort(strArr);
    console.log("Ascending order:", sortedStrArr);
    
    // Descending order
    const sortedStrArrDesc = heapSort(strArr, true);
    console.log("Descending order:", sortedStrArrDesc);
}

// Execute the main function
main();
