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

/**
 * Implementation of the Radix Sort algorithm for positive integers.
 * 
 * @param {Array} arr - Array of positive integers to be sorted
 * @param {boolean} reverse - If true, sorts in descending order; if false, in ascending order
 * @returns {Array} - Sorted array
 */
function radixSort(arr, reverse = false) {
    // Create a copy of the array to avoid modifying the original
    const result = [...arr];
    
    // Find the maximum number to determine the number of digits
    const max = Math.max(...result);
    
    // Perform counting sort for each digit position
    for (let exp = 1; Math.floor(max / exp) > 0; exp *= 10) {
        countingSort(result, exp, reverse);
    }
    
    return result;
}

/**
 * Helper function to sort numbers based on a specific digit.
 * 
 * @param {Array} arr - Array to be sorted
 * @param {number} exp - Digit position (1 for units, 10 for tens, etc.)
 * @param {boolean} reverse - Sort direction
 */
function countingSort(arr, exp, reverse) {
    const n = arr.length;
    const output = new Array(n).fill(0);
    const count = new Array(10).fill(0); // 10 possible digits (0-9)
    
    // Count occurrences of each digit at the current position
    for (let i = 0; i < n; i++) {
        const index = Math.floor(arr[i] / exp) % 10;
        count[index]++;
    }
    
    // Adjust count to contain actual positions in the output array
    if (!reverse) {
        // Ascending order
        for (let i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
    } else {
        // Descending order
        for (let i = 8; i >= 0; i--) {
            count[i] += count[i + 1];
        }
    }
    
    // Build the output array
    for (let i = n - 1; i >= 0; i--) {
        const index = Math.floor(arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }
    
    // Copy the result back to the original array
    for (let i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

/**
 * Main function to demonstrate the use of Radix Sort.
 */
function main() {
    // Example with numbers
    const arr = [170, 45, 75, 90, 802, 24, 2, 66];
    console.log("Original array:", arr);
    
    // Ascending order
    const sortedArr = radixSort(arr);
    console.log("Ascending order:", sortedArr);
    
    // Descending order
    const sortedArrDesc = radixSort(arr, true);
    console.log("Descending order:", sortedArrDesc);
}

// Execute the main function
main();
