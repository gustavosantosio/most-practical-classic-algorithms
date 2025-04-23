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
import java.util.Arrays;

public class Quicksort {
    
    /**
     * Implementation of the Quicksort algorithm for integers.
     * 
     * @param arr Array to be sorted
     * @param reverse If true, sorts in descending order; if false, in ascending order
     * @return Sorted array
     */
    public static int[] quicksort(int[] arr, boolean reverse) {
        // Create a copy of the array to avoid modifying the original
        int[] result = Arrays.copyOf(arr, arr.length);
        
        // Start the recursive sorting
        quicksortRecursive(result, 0, result.length - 1, reverse);
        
        return result;
    }
    
    /**
     * Recursive method for Quicksort.
     * 
     * @param arr Array to be sorted
     * @param low Starting index of the partition
     * @param high Ending index of the partition
     * @param reverse Sort direction
     */
    private static void quicksortRecursive(int[] arr, int low, int high, boolean reverse) {
        if (low < high) {
            // Partition the array and get the pivot index
            int pivotIdx = partition(arr, low, high, reverse);
            
            // Recursively sort the sub-partitions
            quicksortRecursive(arr, low, pivotIdx - 1, reverse);
            quicksortRecursive(arr, pivotIdx + 1, high, reverse);
        }
    }
    
    /**
     * Method to partition the array around the pivot.
     * 
     * @param arr Array to be partitioned
     * @param low Starting index of the partition
     * @param high Ending index of the partition
     * @param reverse Sort direction
     * @return Pivot index after partitioning
     */
    private static int partition(int[] arr, int low, int high, boolean reverse) {
        // Choose the rightmost element as pivot
        int pivot = arr[high];
        
        // Index of the smaller element
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            // Comparison based on sort direction
            if ((!reverse && arr[j] <= pivot) || (reverse && arr[j] >= pivot)) {
                // Increment the index of the smaller element
                i++;
                // Swap elements
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        // Place the pivot in the correct position
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        // Return the pivot index
        return i + 1;
    }
    
    /**
     * Overloaded quicksort method for ascending order by default.
     * 
     * @param arr Array to be sorted
     * @return Array sorted in ascending order
     */
    public static int[] quicksort(int[] arr) {
        return quicksort(arr, false);
    }
    
    /**
     * Implementation of the Quicksort algorithm for strings.
     * 
     * @param arr String array to be sorted
     * @param reverse If true, sorts in descending order; if false, in ascending order
     * @return Sorted array
     */
    public static String[] quicksort(String[] arr, boolean reverse) {
        // Create a copy of the array to avoid modifying the original
        String[] result = Arrays.copyOf(arr, arr.length);
        
        // Start the recursive sorting
        quicksortRecursive(result, 0, result.length - 1, reverse);
        
        return result;
    }
    
    /**
     * Recursive method for Quicksort of strings.
     * 
     * @param arr Array to be sorted
     * @param low Starting index of the partition
     * @param high Ending index of the partition
     * @param reverse Sort direction
     */
    private static void quicksortRecursive(String[] arr, int low, int high, boolean reverse) {
        if (low < high) {
            // Partition the array and get the pivot index
            int pivotIdx = partition(arr, low, high, reverse);
            
            // Recursively sort the sub-partitions
            quicksortRecursive(arr, low, pivotIdx - 1, reverse);
            quicksortRecursive(arr, pivotIdx + 1, high, reverse);
        }
    }
    
    /**
     * Method to partition the string array around the pivot.
     * 
     * @param arr Array to be partitioned
     * @param low Starting index of the partition
     * @param high Ending index of the partition
     * @param reverse Sort direction
     * @return Pivot index after partitioning
     */
    private static int partition(String[] arr, int low, int high, boolean reverse) {
        // Choose the rightmost element as pivot
        String pivot = arr[high];
        
        // Index of the smaller element
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            // Comparison based on sort direction
            if ((!reverse && arr[j].compareTo(pivot) <= 0) || 
                (reverse && arr[j].compareTo(pivot) >= 0)) {
                // Increment the index of the smaller element
                i++;
                // Swap elements
                String temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        // Place the pivot in the correct position
        String temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        // Return the pivot index
        return i + 1;
    }
    
    /**
     * Overloaded quicksort method for ascending order of strings by default.
     * 
     * @param arr String array to be sorted
     * @return Array sorted in ascending order
     */
    public static String[] quicksort(String[] arr) {
        return quicksort(arr, false);
    }
    
    /**
     * Main method to demonstrate the use of Quicksort.
     */
    public static void main(String[] args) {
        // Example with numbers
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("Original array: " + Arrays.toString(arr));
        
        // Ascending order
        int[] sortedArr = quicksort(arr);
        System.out.println("Ascending order: " + Arrays.toString(sortedArr));
        
        // Descending order
        int[] sortedArrDesc = quicksort(arr, true);
        System.out.println("Descending order: " + Arrays.toString(sortedArrDesc));
        
        // Example with strings
        String[] strArr = {"banana", "apple", "orange", "pineapple", "grape"};
        System.out.println("\nOriginal string array: " + Arrays.toString(strArr));
        
        // Ascending order
        String[] sortedStrArr = quicksort(strArr);
        System.out.println("Ascending order: " + Arrays.toString(sortedStrArr));
        
        // Descending order
        String[] sortedStrArrDesc = quicksort(strArr, true);
        System.out.println("Descending order: " + Arrays.toString(sortedStrArrDesc));
    }
}
