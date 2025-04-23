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
import java.util.Arrays;

public class RadixSort {
    
    /**
     * Implementation of the Radix Sort algorithm for positive integers.
     * 
     * @param arr Array of positive integers to be sorted
     * @param reverse If true, sorts in descending order; if false, in ascending order
     * @return Sorted array
     */
    public static int[] radixSort(int[] arr, boolean reverse) {
        // Create a copy of the array to avoid modifying the original
        int[] result = Arrays.copyOf(arr, arr.length);
        
        // Find the maximum number to determine the number of digits
        int max = getMax(result);
        
        // Perform counting sort for each digit position
        for (int exp = 1; max / exp > 0; exp *= 10) {
            result = countingSort(result, exp, reverse);
        }
        
        return result;
    }
    
    /**
     * Helper function to find the maximum number in the array.
     * 
     * @param arr Array of integers
     * @return The maximum number in the array
     */
    private static int getMax(int[] arr) {
        int max = arr[0];
        for (int i = 1; i < arr.length; i++) {
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
     * @param exp Digit position (1 for units, 10 for tens, etc.)
     * @param reverse Sort direction
     * @return Array sorted by the specific digit
     */
    private static int[] countingSort(int[] arr, int exp, boolean reverse) {
        int n = arr.length;
        int[] output = new int[n];
        int[] count = new int[10]; // 10 possible digits (0-9)
        
        // Initialize the count array
        Arrays.fill(count, 0);
        
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
        
        return output;
    }
    
    /**
     * Overloaded radixSort method for ascending order by default.
     * 
     * @param arr Array to be sorted
     * @return Array sorted in ascending order
     */
    public static int[] radixSort(int[] arr) {
        return radixSort(arr, false);
    }
    
    /**
     * Main method to demonstrate the use of Radix Sort.
     */
    public static void main(String[] args) {
        // Example with numbers
        int[] arr = {170, 45, 75, 90, 802, 24, 2, 66};
        System.out.println("Original array: " + Arrays.toString(arr));
        
        // Ascending order
        int[] sortedArr = radixSort(arr);
        System.out.println("Ascending order: " + Arrays.toString(sortedArr));
        
        // Descending order
        int[] sortedArrDesc = radixSort(arr, true);
        System.out.println("Descending order: " + Arrays.toString(sortedArrDesc));
    }
}
