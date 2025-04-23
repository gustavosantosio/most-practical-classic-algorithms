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
import java.util.Arrays;

public class SelectionSort {
    
    /**
     * Implementation of the Selection Sort algorithm for integers.
     * 
     * @param arr Array to be sorted
     * @param reverse If true, sorts in descending order; if false, in ascending order
     * @return Sorted array
     */
    public static int[] selectionSort(int[] arr, boolean reverse) {
        // Create a copy of the array to avoid modifying the original
        int[] result = Arrays.copyOf(arr, arr.length);
        int n = result.length;
        
        for (int i = 0; i < n; i++) {
            // Assume the first unsorted element is the extreme (minimum or maximum)
            int extremeIdx = i;
            
            // Find the extreme element (minimum or maximum) in the unsorted part
            for (int j = i + 1; j < n; j++) {
                // Comparison based on sort direction
                if ((!reverse && result[j] < result[extremeIdx]) || 
                    (reverse && result[j] > result[extremeIdx])) {
                    extremeIdx = j;
                }
            }
            
            // Swap the extreme element with the first unsorted element
            if (extremeIdx != i) {
                int temp = result[i];
                result[i] = result[extremeIdx];
                result[extremeIdx] = temp;
            }
        }
        
        return result;
    }
    
    /**
     * Overloaded selectionSort method for ascending order by default.
     * 
     * @param arr Array to be sorted
     * @return Array sorted in ascending order
     */
    public static int[] selectionSort(int[] arr) {
        return selectionSort(arr, false);
    }
    
    /**
     * Implementation of the Selection Sort algorithm for strings.
     * 
     * @param arr String array to be sorted
     * @param reverse If true, sorts in descending order; if false, in ascending order
     * @return Sorted array
     */
    public static String[] selectionSort(String[] arr, boolean reverse) {
        // Create a copy of the array to avoid modifying the original
        String[] result = Arrays.copyOf(arr, arr.length);
        int n = result.length;
        
        for (int i = 0; i < n; i++) {
            // Assume the first unsorted element is the extreme (minimum or maximum)
            int extremeIdx = i;
            
            // Find the extreme element (minimum or maximum) in the unsorted part
            for (int j = i + 1; j < n; j++) {
                // Comparison based on sort direction
                if ((!reverse && result[j].compareTo(result[extremeIdx]) < 0) || 
                    (reverse && result[j].compareTo(result[extremeIdx]) > 0)) {
                    extremeIdx = j;
                }
            }
            
            // Swap the extreme element with the first unsorted element
            if (extremeIdx != i) {
                String temp = result[i];
                result[i] = result[extremeIdx];
                result[extremeIdx] = temp;
            }
        }
        
        return result;
    }
    
    /**
     * Overloaded selectionSort method for ascending order of strings by default.
     * 
     * @param arr String array to be sorted
     * @return Array sorted in ascending order
     */
    public static String[] selectionSort(String[] arr) {
        return selectionSort(arr, false);
    }
    
    /**
     * Main method to demonstrate the use of Selection Sort.
     */
    public static void main(String[] args) {
        // Example with numbers
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("Original array: " + Arrays.toString(arr));
        
        // Ascending order
        int[] sortedArr = selectionSort(arr);
        System.out.println("Ascending order: " + Arrays.toString(sortedArr));
        
        // Descending order
        int[] sortedArrDesc = selectionSort(arr, true);
        System.out.println("Descending order: " + Arrays.toString(sortedArrDesc));
        
        // Example with strings
        String[] strArr = {"banana", "apple", "orange", "pineapple", "grape"};
        System.out.println("\nOriginal string array: " + Arrays.toString(strArr));
        
        // Ascending order
        String[] sortedStrArr = selectionSort(strArr);
        System.out.println("Ascending order: " + Arrays.toString(sortedStrArr));
        
        // Descending order
        String[] sortedStrArrDesc = selectionSort(strArr, true);
        System.out.println("Descending order: " + Arrays.toString(sortedStrArrDesc));
    }
}
