"""
Selection Sort - Sorting Algorithm

Time Complexity:
- Best case: O(n²)
- Average case: O(n²)
- Worst case: O(n²)

Space Complexity: O(1) - in-place sorting

How it works:
Selection Sort divides the array into two parts: a sorted subarray and an unsorted subarray.
In each iteration, the algorithm finds the smallest (or largest) element from the unsorted subarray
and places it in the correct position in the sorted subarray.
"""

def selection_sort(arr, reverse=False):
    """
    Implementation of the Selection Sort algorithm.
    
    Args:
        arr: List to be sorted
        reverse: If True, sorts in descending order; if False, in ascending order
        
    Returns:
        Sorted list
    """
    n = len(arr)
    # Create a copy of the array to avoid modifying the original
    result = arr.copy()
    
    for i in range(n):
        # Assume the first unsorted element is the extreme (minimum or maximum)
        extreme_idx = i
        
        # Find the extreme element (minimum or maximum) in the unsorted part
        for j in range(i + 1, n):
            # Comparison based on sort direction
            if (not reverse and result[j] < result[extreme_idx]) or (reverse and result[j] > result[extreme_idx]):
                extreme_idx = j
                
        # Swap the extreme element with the first unsorted element
        if extreme_idx != i:
            result[i], result[extreme_idx] = result[extreme_idx], result[i]
            
    return result

def main():
    """Main function to demonstrate the use of Selection Sort."""
    # Example with numbers
    arr = [64, 34, 25, 12, 22, 11, 90]
    print("Original array:", arr)
    
    # Ascending order
    sorted_arr = selection_sort(arr)
    print("Ascending order:", sorted_arr)
    
    # Descending order
    sorted_arr_desc = selection_sort(arr, reverse=True)
    print("Descending order:", sorted_arr_desc)
    
    # Example with strings
    str_arr = ["banana", "apple", "orange", "pineapple", "grape"]
    print("\nOriginal string array:", str_arr)
    
    # Ascending order
    sorted_str_arr = selection_sort(str_arr)
    print("Ascending order:", sorted_str_arr)
    
    # Descending order
    sorted_str_arr_desc = selection_sort(str_arr, reverse=True)
    print("Descending order:", sorted_str_arr_desc)

if __name__ == "__main__":
    main()
