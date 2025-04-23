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
import java.util.Arrays;

public class InsertionSort {
    
    /**
     * Implementation of the Insertion Sort algorithm for integers.
     * 
     * @param arr Array to be sorted
     * @param reverse If true, sorts in descending order; if false, in ascending order
     * @return Sorted array
     */
    public static int[] insertionSort(int[] arr, boolean reverse) {
        // Create a copy of the array to avoid modifying the original
        int[] result = Arrays.copyOf(arr, arr.length);
        int n = result.length;
        
        // Start from the second element (index 1)
        for (int i = 1; i < n; i++) {
            // Element to be inserted into the sorted part
            int key = result[i];
            
            // Move elements of the sorted part that are greater (or smaller) than key
            // one position ahead of their current position
            int j = i - 1;
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
     * Overloaded insertionSort method for ascending order by default.
     * 
     * @param arr Array to be sorted
     * @return Array sorted in ascending order
     */
    public static int[] insertionSort(int[] arr) {
        return insertionSort(arr, false);
    }
    
    /**
     * Implementation of the Insertion Sort algorithm for strings.
     * 
     * @param arr String array to be sorted
     * @param reverse If true, sorts in descending order; if false, in ascending order
     * @return Sorted array
     */
    public static String[] insertionSort(String[] arr, boolean reverse) {
        // Create a copy of the array to avoid modifying the original
        String[] result = Arrays.copyOf(arr, arr.length);
        int n = result.length;
        
        // Start from the second element (index 1)
        for (int i = 1; i < n; i++) {
            // Element to be inserted into the sorted part
            String key = result[i];
            
            // Move elements of the sorted part that are greater (or smaller) than key
            // one position ahead of their current position
            int j = i - 1;
            if (!reverse) {
                // Ascending order
                while (j >= 0 && result[j].compareTo(key) > 0) {
                    result[j + 1] = result[j];
                    j--;
                }
            } else {
                // Descending order
                while (j >= 0 && result[j].compareTo(key) < 0) {
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
     * Overloaded insertionSort method for ascending order of strings by default.
     * 
     * @param arr String array to be sorted
     * @return Array sorted in ascending order
     */
    public static String[] insertionSort(String[] arr) {
        return insertionSort(arr, false);
    }
    
    /**
     * Main method to demonstrate the use of Insertion Sort.
     */
    public static void main(String[] args) {
        // Example with numbers
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("Original array: " + Arrays.toString(arr));
        
        // Ascending order
        int[] sortedArr = insertionSort(arr);
        System.out.println("Ascending order: " + Arrays.toString(sortedArr));
        
        // Descending order
        int[] sortedArrDesc = insertionSort(arr, true);
        System.out.println("Descending order: " + Arrays.toString(sortedArrDesc));
        
        // Example with strings
        String[] strArr = {"banana", "apple", "orange", "pineapple", "grape"};
        System.out.println("\nOriginal string array: " + Arrays.toString(strArr));
        
        // Ascending order
        String[] sortedStrArr = insertionSort(strArr);
        System.out.println("Ascending order: " + Arrays.toString(sortedStrArr));
        
        // Descending order
        String[] sortedStrArrDesc = insertionSort(strArr, true);
        System.out.println("Descending order: " + Arrays.toString(sortedStrArrDesc));
    }
}
