/**
 * Merge Sort - Sorting Algorithm
 *
 * Time Complexity:
 * - Best case: O(n log n)
 * - Average case: O(n log n)
 * - Worst case: O(n log n)
 *
 * Space Complexity: O(n) - requires additional space for temporary arrays
 *
 * How it works:
 * Merge Sort is a divide and conquer sorting algorithm.
 * 1. Divide the array into two halves
 * 2. Recursively sort each half
 * 3. Merge the two sorted halves to produce the final sorted array
 */
import java.util.Arrays;

public class MergeSort {
    
    /**
     * Implementation of the Merge Sort algorithm for integers.
     * 
     * @param arr Array to be sorted
     * @param reverse If true, sorts in descending order; if false, in ascending order
     * @return Sorted array
     */
    public static int[] mergeSort(int[] arr, boolean reverse) {
        // Create a copy of the array to avoid modifying the original
        int[] result = Arrays.copyOf(arr, arr.length);
        
        // Start the recursive sorting
        result = mergeSortRecursive(result, reverse);
        
        return result;
    }
    
    /**
     * Recursive method for Merge Sort.
     * 
     * @param arr Array to be sorted
     * @param reverse Sort direction
     * @return Sorted array
     */
    private static int[] mergeSortRecursive(int[] arr, boolean reverse) {
        // Base case: if the array has size 0 or 1, it's already sorted
        if (arr.length <= 1) {
            return arr;
        }
        
        // Divide the array into two halves
        int mid = arr.length / 2;
        int[] left = Arrays.copyOfRange(arr, 0, mid);
        int[] right = Arrays.copyOfRange(arr, mid, arr.length);
        
        // Recursively sort each half
        left = mergeSortRecursive(left, reverse);
        right = mergeSortRecursive(right, reverse);
        
        // Merge the two sorted halves
        return merge(left, right, reverse);
    }
    
    /**
     * Method to merge two sorted sublists.
     * 
     * @param left Left sorted sublist
     * @param right Right sorted sublist
     * @param reverse Sort direction
     * @return Merged sorted array
     */
    private static int[] merge(int[] left, int[] right, boolean reverse) {
        int[] result = new int[left.length + right.length];
        int i = 0, j = 0, k = 0;
        
        // Compare elements from the two sublists and add the smaller (or larger) to the result
        while (i < left.length && j < right.length) {
            if (!reverse) {
                // Ascending order
                if (left[i] <= right[j]) {
                    result[k++] = left[i++];
                } else {
                    result[k++] = right[j++];
                }
            } else {
                // Descending order
                if (left[i] >= right[j]) {
                    result[k++] = left[i++];
                } else {
                    result[k++] = right[j++];
                }
            }
        }
        
        // Add the remaining elements from the left sublist
        while (i < left.length) {
            result[k++] = left[i++];
        }
        
        // Add the remaining elements from the right sublist
        while (j < right.length) {
            result[k++] = right[j++];
        }
        
        return result;
    }
    
    /**
     * Overloaded mergeSort method for ascending order by default.
     * 
     * @param arr Array to be sorted
     * @return Array sorted in ascending order
     */
    public static int[] mergeSort(int[] arr) {
        return mergeSort(arr, false);
    }
    
    /**
     * Implementation of the Merge Sort algorithm for strings.
     * 
     * @param arr String array to be sorted
     * @param reverse If true, sorts in descending order; if false, in ascending order
     * @return Sorted array
     */
    public static String[] mergeSort(String[] arr, boolean reverse) {
        // Create a copy of the array to avoid modifying the original
        String[] result = Arrays.copyOf(arr, arr.length);
        
        // Start the recursive sorting
        result = mergeSortRecursive(result, reverse);
        
        return result;
    }
    
    /**
     * Recursive method for Merge Sort of strings.
     * 
     * @param arr Array to be sorted
     * @param reverse Sort direction
     * @return Sorted array
     */
    private static String[] mergeSortRecursive(String[] arr, boolean reverse) {
        // Base case: if the array has size 0 or 1, it's already sorted
        if (arr.length <= 1) {
            return arr;
        }
        
        // Divide the array into two halves
        int mid = arr.length / 2;
        String[] left = Arrays.copyOfRange(arr, 0, mid);
        String[] right = Arrays.copyOfRange(arr, mid, arr.length);
        
        // Recursively sort each half
        left = mergeSortRecursive(left, reverse);
        right = mergeSortRecursive(right, reverse);
        
        // Merge the two sorted halves
        return merge(left, right, reverse);
    }
    
    /**
     * Method to merge two sorted string sublists.
     * 
     * @param left Left sorted sublist
     * @param right Right sorted sublist
     * @param reverse Sort direction
     * @return Merged sorted array
     */
    private static String[] merge(String[] left, String[] right, boolean reverse) {
        String[] result = new String[left.length + right.length];
        int i = 0, j = 0, k = 0;
        
        // Compare elements from the two sublists and add the smaller (or larger) to the result
        while (i < left.length && j < right.length) {
            if (!reverse) {
                // Ascending order
                if (left[i].compareTo(right[j]) <= 0) {
                    result[k++] = left[i++];
                } else {
                    result[k++] = right[j++];
                }
            } else {
                // Descending order
                if (left[i].compareTo(right[j]) >= 0) {
                    result[k++] = left[i++];
                } else {
                    result[k++] = right[j++];
                }
            }
        }
        
        // Add the remaining elements from the left sublist
        while (i < left.length) {
            result[k++] = left[i++];
        }
        
        // Add the remaining elements from the right sublist
        while (j < right.length) {
            result[k++] = right[j++];
        }
        
        return result;
    }
    
    /**
     * Overloaded mergeSort method for ascending order of strings by default.
     * 
     * @param arr String array to be sorted
     * @return Array sorted in ascending order
     */
    public static String[] mergeSort(String[] arr) {
        return mergeSort(arr, false);
    }
    
    /**
     * Main method to demonstrate the use of Merge Sort.
     */
    public static void main(String[] args) {
        // Example with numbers
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("Original array: " + Arrays.toString(arr));
        
        // Ascending order
        int[] sortedArr = mergeSort(arr);
        System.out.println("Ascending order: " + Arrays.toString(sortedArr));
        
        // Descending order
        int[] sortedArrDesc = mergeSort(arr, true);
        System.out.println("Descending order: " + Arrays.toString(sortedArrDesc));
        
        // Example with strings
        String[] strArr = {"banana", "apple", "orange", "pineapple", "grape"};
        System.out.println("\nOriginal string array: " + Arrays.toString(strArr));
        
        // Ascending order
        String[] sortedStrArr = mergeSort(strArr);
        System.out.println("Ascending order: " + Arrays.toString(sortedStrArr));
        
        // Descending order
        String[] sortedStrArrDesc = mergeSort(strArr, true);
        System.out.println("Descending order: " + Arrays.toString(sortedStrArrDesc));
    }
}
