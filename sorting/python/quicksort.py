"""
Quicksort - Sorting Algorithm

Time Complexity:
- Best case: O(n log n)
- Average case: O(n log n)
- Worst case: O(n²) when the chosen pivot is always the smallest or largest element

Space Complexity: 
- O(log n) for the recursive call stack in the average case
- O(n) in the worst case

How it works:
Quicksort is a divide and conquer sorting algorithm.
1. Choose an element as a pivot
2. Partition the array around the pivot (smaller elements to the left, larger to the right)
3. Recursively sort the two sub-partitions
"""

def quicksort(arr, reverse=False):
    """
    Implementation of the Quicksort algorithm.
    
    Args:
        arr: List to be sorted
        reverse: If True, sorts in descending order; if False, in ascending order
        
    Returns:
        Sorted list
    """
    # Create a copy of the array to avoid modifying the original
    result = arr.copy()
    
    # Internal function for recursive sorting
    def _quicksort(low, high):
        if low < high:
            # Partition the array and get the pivot index
            pivot_idx = _partition(low, high)
            
            # Recursively sort the sub-partitions
            _quicksort(low, pivot_idx - 1)
            _quicksort(pivot_idx + 1, high)
    
    # Function to partition the array around the pivot
    def _partition(low, high):
        # Choose the rightmost element as pivot
        pivot = result[high]
        
        # Index of the smaller element
        i = low - 1
        
        for j in range(low, high):
            # Comparison based on sort direction
            if (not reverse and result[j] <= pivot) or (reverse and result[j] >= pivot):
                # Increment the index of the smaller element
                i += 1
                # Swap elements
                result[i], result[j] = result[j], result[i]
        
        # Place the pivot in the correct position
        result[i + 1], result[high] = result[high], result[i + 1]
        
        # Return the pivot index
        return i + 1
    
    # Start the recursive sorting
    _quicksort(0, len(result) - 1)
    
    return result

def main():
    """Main function to demonstrate the use of Quicksort."""
    # Example with numbers
    arr = [64, 34, 25, 12, 22, 11, 90]
    print("Original array:", arr)
    
    # Ascending order
    sorted_arr = quicksort(arr)
    print("Ascending order:", sorted_arr)
    
    # Descending order
    sorted_arr_desc = quicksort(arr, reverse=True)
    print("Descending order:", sorted_arr_desc)
    
    # Example with strings
    str_arr = ["banana", "apple", "orange", "pineapple", "grape"]
    print("\nOriginal string array:", str_arr)
    
    # Ascending order
    sorted_str_arr = quicksort(str_arr)
    print("Ascending order:", sorted_str_arr)
    
    # Descending order
    sorted_str_arr_desc = quicksort(str_arr, reverse=True)
    print("Descending order:", sorted_str_arr_desc)

if __name__ == "__main__":
    main()
