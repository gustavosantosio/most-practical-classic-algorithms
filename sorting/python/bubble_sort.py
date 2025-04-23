"""
Bubble Sort - Sorting Algorithm

Time Complexity:
- Best case: O(n) when the array is already sorted
- Average case: O(n²)
- Worst case: O(n²)

Space Complexity: O(1) - in-place sorting

How it works:
Bubble Sort compares adjacent pairs of elements and swaps them if they are in the wrong order.
The algorithm traverses the array multiple times, "bubbling" the largest element to the end in each pass.
"""

def bubble_sort(arr, reverse=False):
    """
    Implementation of the Bubble Sort algorithm.
    
    Args:
        arr: List to be sorted
        reverse: If True, sorts in descending order; if False, in ascending order
        
    Returns:
        Sorted list
    """
    n = len(arr)
    # Create a copy of the array to avoid modifying the original
    result = arr.copy()
    
    # Optimization flag: if no swaps are made in a pass, the array is already sorted
    for i in range(n):
        swapped = False
        
        # In each pass, the largest element "bubbles" to the end
        # Therefore, we don't need to check the last i elements
        for j in range(0, n - i - 1):
            # Comparison based on sort direction
            if (not reverse and result[j] > result[j + 1]) or (reverse and result[j] < result[j + 1]):
                # Swap elements
                result[j], result[j + 1] = result[j + 1], result[j]
                swapped = True
                
        # If no swaps were made in this pass, the array is already sorted
        if not swapped:
            break
            
    return result

def main():
    """Main function to demonstrate the use of Bubble Sort."""
    # Example with numbers
    arr = [64, 34, 25, 12, 22, 11, 90]
    print("Original array:", arr)
    
    # Ascending order
    sorted_arr = bubble_sort(arr)
    print("Ascending order:", sorted_arr)
    
    # Descending order
    sorted_arr_desc = bubble_sort(arr, reverse=True)
    print("Descending order:", sorted_arr_desc)
    
    # Example with strings
    str_arr = ["banana", "apple", "orange", "pineapple", "grape"]
    print("\nOriginal string array:", str_arr)
    
    # Ascending order
    sorted_str_arr = bubble_sort(str_arr)
    print("Ascending order:", sorted_str_arr)
    
    # Descending order
    sorted_str_arr_desc = bubble_sort(str_arr, reverse=True)
    print("Descending order:", sorted_str_arr_desc)

if __name__ == "__main__":
    main()
