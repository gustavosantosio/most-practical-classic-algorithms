"""
Insertion Sort - Sorting Algorithm

Time Complexity:
- Best case: O(n) when the array is already sorted
- Average case: O(n²)
- Worst case: O(n²)

Space Complexity: O(1) - in-place sorting

How it works:
Insertion Sort builds the sorted list one item at a time.
The algorithm divides the array into a sorted part and an unsorted part.
In each iteration, it removes one element from the unsorted part and
inserts it into the correct position within the sorted part.
"""

def insertion_sort(arr, reverse=False):
    """
    Implementation of the Insertion Sort algorithm.
    
    Args:
        arr: List to be sorted
        reverse: If True, sorts in descending order; if False, in ascending order
        
    Returns:
        Sorted list
    """
    n = len(arr)
    # Create a copy of the array to avoid modifying the original
    result = arr.copy()
    
    # Start from the second element (index 1)
    for i in range(1, n):
        # Element to be inserted into the sorted part
        key = result[i]
        
        # Move elements of the sorted part that are greater (or smaller) than key
        # one position ahead of their current position
        j = i - 1
        if not reverse:
            # Ascending order
            while j >= 0 and result[j] > key:
                result[j + 1] = result[j]
                j -= 1
        else:
            # Descending order
            while j >= 0 and result[j] < key:
                result[j + 1] = result[j]
                j -= 1
                
        # Insert the element in the correct position
        result[j + 1] = key
            
    return result

def main():
    """Main function to demonstrate the use of Insertion Sort."""
    # Example with numbers
    arr = [64, 34, 25, 12, 22, 11, 90]
    print("Original array:", arr)
    
    # Ascending order
    sorted_arr = insertion_sort(arr)
    print("Ascending order:", sorted_arr)
    
    # Descending order
    sorted_arr_desc = insertion_sort(arr, reverse=True)
    print("Descending order:", sorted_arr_desc)
    
    # Example with strings
    str_arr = ["banana", "apple", "orange", "pineapple", "grape"]
    print("\nOriginal string array:", str_arr)
    
    # Ascending order
    sorted_str_arr = insertion_sort(str_arr)
    print("Ascending order:", sorted_str_arr)
    
    # Descending order
    sorted_str_arr_desc = insertion_sort(str_arr, reverse=True)
    print("Descending order:", sorted_str_arr_desc)

if __name__ == "__main__":
    main()
