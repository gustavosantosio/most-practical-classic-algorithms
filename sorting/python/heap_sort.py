"""
Heap Sort - Sorting Algorithm

Time Complexity:
- Best case: O(n log n)
- Average case: O(n log n)
- Worst case: O(n log n)

Space Complexity: O(1) - in-place sorting

How it works:
Heap Sort uses a binary heap data structure to sort elements.
1. Build a max heap (for ascending order) or min heap (for descending order) from the array
2. Repeatedly extract the root element (which is the largest or smallest) and rebuild the heap
3. The extracted elements form the sorted array
"""

def heap_sort(arr, reverse=False):
    """
    Implementation of the Heap Sort algorithm.
    
    Args:
        arr: List to be sorted
        reverse: If True, sorts in descending order; if False, in ascending order
        
    Returns:
        Sorted list
    """
    # Create a copy of the array to avoid modifying the original
    result = arr.copy()
    n = len(result)
    
    # Build a max heap (for ascending order) or min heap (for descending order)
    for i in range(n // 2 - 1, -1, -1):
        _heapify(result, n, i, reverse)
    
    # Extract elements one by one
    for i in range(n - 1, 0, -1):
        # Swap the root (maximum/minimum element) with the last element
        result[i], result[0] = result[0], result[i]
        
        # Call heapify on the reduced heap
        _heapify(result, i, 0, reverse)
            
    return result

def _heapify(arr, n, i, reverse):
    """
    Helper function to maintain the heap property.
    
    Args:
        arr: Array to heapify
        n: Size of the heap
        i: Index of the current node
        reverse: If True, creates a min heap; if False, creates a max heap
    """
    # Initialize the largest/smallest as the root
    extreme = i
    left = 2 * i + 1  # Left child
    right = 2 * i + 2  # Right child
    
    # Check if left child exists and is greater/smaller than the root
    if left < n:
        if (not reverse and arr[left] > arr[extreme]) or (reverse and arr[left] < arr[extreme]):
            extreme = left
    
    # Check if right child exists and is greater/smaller than the largest/smallest so far
    if right < n:
        if (not reverse and arr[right] > arr[extreme]) or (reverse and arr[right] < arr[extreme]):
            extreme = right
    
    # If the largest/smallest is not the root
    if extreme != i:
        # Swap the root with the largest/smallest
        arr[i], arr[extreme] = arr[extreme], arr[i]
        
        # Recursively heapify the affected sub-tree
        _heapify(arr, n, extreme, reverse)

def main():
    """Main function to demonstrate the use of Heap Sort."""
    # Example with numbers
    arr = [64, 34, 25, 12, 22, 11, 90]
    print("Original array:", arr)
    
    # Ascending order
    sorted_arr = heap_sort(arr)
    print("Ascending order:", sorted_arr)
    
    # Descending order
    sorted_arr_desc = heap_sort(arr, reverse=True)
    print("Descending order:", sorted_arr_desc)
    
    # Example with strings
    str_arr = ["banana", "apple", "orange", "pineapple", "grape"]
    print("\nOriginal string array:", str_arr)
    
    # Ascending order
    sorted_str_arr = heap_sort(str_arr)
    print("Ascending order:", sorted_str_arr)
    
    # Descending order
    sorted_str_arr_desc = heap_sort(str_arr, reverse=True)
    print("Descending order:", sorted_str_arr_desc)

if __name__ == "__main__":
    main()
