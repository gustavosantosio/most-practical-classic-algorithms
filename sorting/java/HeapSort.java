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
import java.util.Arrays;

public class HeapSort {
    
    /**
     * Implementation of the Heap Sort algorithm for integers.
     * 
     * @param arr Array to be sorted
     * @param reverse If true, sorts in descending order; if false, in ascending order
     * @return Sorted array
     */
    public static int[] heapSort(int[] arr, boolean reverse) {
        // Create a copy of the array to avoid modifying the original
        int[] result = Arrays.copyOf(arr, arr.length);
        int n = result.length;
        
        // Build a max heap (for ascending order) or min heap (for descending order)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(result, n, i, reverse);
        }
        
        // Extract elements one by one
        for (int i = n - 1; i > 0; i--) {
            // Swap the root (maximum/minimum element) with the last element
            int temp = result[0];
            result[0] = result[i];
            result[i] = temp;
            
            // Call heapify on the reduced heap
            heapify(result, i, 0, reverse);
        }
        
        return result;
    }
    
    /**
     * Helper function to maintain the heap property.
     * 
     * @param arr Array to heapify
     * @param n Size of the heap
     * @param i Index of the current node
     * @param reverse If true, creates a min heap; if false, creates a max heap
     */
    private static void heapify(int[] arr, int n, int i, boolean reverse) {
        // Initialize the largest/smallest as the root
        int extreme = i;
        int left = 2 * i + 1;  // Left child
        int right = 2 * i + 2;  // Right child
        
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
        if (extreme != i) {
            // Swap the root with the largest/smallest
            int temp = arr[i];
            arr[i] = arr[extreme];
            arr[extreme] = temp;
            
            // Recursively heapify the affected sub-tree
            heapify(arr, n, extreme, reverse);
        }
    }
    
    /**
     * Overloaded heapSort method for ascending order by default.
     * 
     * @param arr Array to be sorted
     * @return Array sorted in ascending order
     */
    public static int[] heapSort(int[] arr) {
        return heapSort(arr, false);
    }
    
    /**
     * Implementation of the Heap Sort algorithm for strings.
     * 
     * @param arr String array to be sorted
     * @param reverse If true, sorts in descending order; if false, in ascending order
     * @return Sorted array
     */
    public static String[] heapSort(String[] arr, boolean reverse) {
        // Create a copy of the array to avoid modifying the original
        String[] result = Arrays.copyOf(arr, arr.length);
        int n = result.length;
        
        // Build a max heap (for ascending order) or min heap (for descending order)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(result, n, i, reverse);
        }
        
        // Extract elements one by one
        for (int i = n - 1; i > 0; i--) {
            // Swap the root (maximum/minimum element) with the last element
            String temp = result[0];
            result[0] = result[i];
            result[i] = temp;
            
            // Call heapify on the reduced heap
            heapify(result, i, 0, reverse);
        }
        
        return result;
    }
    
    /**
     * Helper function to maintain the heap property for strings.
     * 
     * @param arr Array to heapify
     * @param n Size of the heap
     * @param i Index of the current node
     * @param reverse If true, creates a min heap; if false, creates a max heap
     */
    private static void heapify(String[] arr, int n, int i, boolean reverse) {
        // Initialize the largest/smallest as the root
        int extreme = i;
        int left = 2 * i + 1;  // Left child
        int right = 2 * i + 2;  // Right child
        
        // Check if left child exists and is greater/smaller than the root
        if (left < n) {
            if ((!reverse && arr[left].compareTo(arr[extreme]) > 0) || 
                (reverse && arr[left].compareTo(arr[extreme]) < 0)) {
                extreme = left;
            }
        }
        
        // Check if right child exists and is greater/smaller than the largest/smallest so far
        if (right < n) {
            if ((!reverse && arr[right].compareTo(arr[extreme]) > 0) || 
                (reverse && arr[right].compareTo(arr[extreme]) < 0)) {
                extreme = right;
            }
        }
        
        // If the largest/smallest is not the root
        if (extreme != i) {
            // Swap the root with the largest/smallest
            String temp = arr[i];
            arr[i] = arr[extreme];
            arr[extreme] = temp;
            
            // Recursively heapify the affected sub-tree
            heapify(arr, n, extreme, reverse);
        }
    }
    
    /**
     * Overloaded heapSort method for ascending order of strings by default.
     * 
     * @param arr String array to be sorted
     * @return Array sorted in ascending order
     */
    public static String[] heapSort(String[] arr) {
        return heapSort(arr, false);
    }
    
    /**
     * Main method to demonstrate the use of Heap Sort.
     */
    public static void main(String[] args) {
        // Example with numbers
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("Original array: " + Arrays.toString(arr));
        
        // Ascending order
        int[] sortedArr = heapSort(arr);
        System.out.println("Ascending order: " + Arrays.toString(sortedArr));
        
        // Descending order
        int[] sortedArrDesc = heapSort(arr, true);
        System.out.println("Descending order: " + Arrays.toString(sortedArrDesc));
        
        // Example with strings
        String[] strArr = {"banana", "apple", "orange", "pineapple", "grape"};
        System.out.println("\nOriginal string array: " + Arrays.toString(strArr));
        
        // Ascending order
        String[] sortedStrArr = heapSort(strArr);
        System.out.println("Ascending order: " + Arrays.toString(sortedStrArr));
        
        // Descending order
        String[] sortedStrArrDesc = heapSort(strArr, true);
        System.out.println("Descending order: " + Arrays.toString(sortedStrArrDesc));
    }
}
