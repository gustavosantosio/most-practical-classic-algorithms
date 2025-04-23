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
import java.util.Arrays;

public class BubbleSort {
    
    /**
     * Implementation of the Bubble Sort algorithm for integers.
     * 
     * @param arr Array to be sorted
     * @param reverse If true, sorts in descending order; if false, in ascending order
     * @return Sorted array
     */
    public static int[] bubbleSort(int[] arr, boolean reverse) {
        // Create a copy of the array to avoid modifying the original
        int[] result = Arrays.copyOf(arr, arr.length);
        int n = result.length;
        
        // Optimization flag: if no swaps are made in a pass, the array is already sorted
        for (int i = 0; i < n; i++) {
            boolean swapped = false;
            
            // In each pass, the largest element "bubbles" to the end
            // Therefore, we don't need to check the last i elements
            for (int j = 0; j < n - i - 1; j++) {
                // Comparison based on sort direction
                if ((!reverse && result[j] > result[j + 1]) || (reverse && result[j] < result[j + 1])) {
                    // Swap elements
                    int temp = result[j];
                    result[j] = result[j + 1];
                    result[j + 1] = temp;
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
     * Overloaded bubbleSort method for ascending order by default.
     * 
     * @param arr Array to be sorted
     * @return Array sorted in ascending order
     */
    public static int[] bubbleSort(int[] arr) {
        return bubbleSort(arr, false);
    }
    
    /**
     * Implementation of the Bubble Sort algorithm for strings.
     * 
     * @param arr String array to be sorted
     * @param reverse If true, sorts in descending order; if false, in ascending order
     * @return Sorted array
     */
    public static String[] bubbleSort(String[] arr, boolean reverse) {
        // Create a copy of the array to avoid modifying the original
        String[] result = Arrays.copyOf(arr, arr.length);
        int n = result.length;
        
        for (int i = 0; i < n; i++) {
            boolean swapped = false;
            
            for (int j = 0; j < n - i - 1; j++) {
                // Comparison based on sort direction
                if ((!reverse && result[j].compareTo(result[j + 1]) > 0) || 
                    (reverse && result[j].compareTo(result[j + 1]) < 0)) {
                    // Swap elements
                    String temp = result[j];
                    result[j] = result[j + 1];
                    result[j + 1] = temp;
                    swapped = true;
                }
            }
            
            if (!swapped) {
                break;
            }
        }
        
        return result;
    }
    
    /**
     * Overloaded bubbleSort method for ascending order of strings by default.
     * 
     * @param arr String array to be sorted
     * @return Array sorted in ascending order
     */
    public static String[] bubbleSort(String[] arr) {
        return bubbleSort(arr, false);
    }
    
    /**
     * Main method to demonstrate the use of Bubble Sort.
     */
    public static void main(String[] args) {
        // Example with numbers
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("Original array: " + Arrays.toString(arr));
        
        // Ascending order
        int[] sortedArr = bubbleSort(arr);
        System.out.println("Ascending order: " + Arrays.toString(sortedArr));
        
        // Descending order
        int[] sortedArrDesc = bubbleSort(arr, true);
        System.out.println("Descending order: " + Arrays.toString(sortedArrDesc));
        
        // Example with strings
        String[] strArr = {"banana", "apple", "orange", "pineapple", "grape"};
        System.out.println("\nOriginal string array: " + Arrays.toString(strArr));
        
        // Ascending order
        String[] sortedStrArr = bubbleSort(strArr);
        System.out.println("Ascending order: " + Arrays.toString(sortedStrArr));
        
        // Descending order
        String[] sortedStrArrDesc = bubbleSort(strArr, true);
        System.out.println("Descending order: " + Arrays.toString(sortedStrArrDesc));
    }
}
