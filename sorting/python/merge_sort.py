"""
Merge Sort - Sorting Algorithm

Time Complexity:
- Best case: O(n log n)
- Average case: O(n log n)
- Worst case: O(n log n)

Space Complexity: O(n) - requires additional space for temporary arrays

How it works:
Merge Sort is a divide and conquer sorting algorithm.
1. Divide the array into two halves
2. Recursively sort each half
3. Merge the two sorted halves to produce the final sorted array
"""

def merge_sort(arr, reverse=False):
    """
    Implementation of the Merge Sort algorithm.
    
    Args:
        arr: List to be sorted
        reverse: If True, sorts in descending order; if False, in ascending order
        
    Returns:
        Sorted list
    """
    # Create a copy of the array to avoid modifying the original
    result = arr.copy()
    
    # Internal function for recursive sorting
    def _merge_sort(arr):
        # Base case: if the array has size 0 or 1, it's already sorted
        if len(arr) <= 1:
            return arr
            
        # Divide the array into two halves
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]
        
        # Recursively sort each half
        left = _merge_sort(left)
        right = _merge_sort(right)
        
        # Merge the two sorted halves
        return _merge(left, right)
    
    # Function to merge two sorted sublists
    def _merge(left, right):
        result = []
        i = j = 0
        
        # Compare elements from the two sublists and add the smaller (or larger) to the result
        while i < len(left) and j < len(right):
            if not reverse:
                # Ascending order
                if left[i] <= right[j]:
                    result.append(left[i])
                    i += 1
                else:
                    result.append(right[j])
                    j += 1
            else:
                # Descending order
                if left[i] >= right[j]:
                    result.append(left[i])
                    i += 1
                else:
                    result.append(right[j])
                    j += 1
        
        # Add the remaining elements from the left sublist
        result.extend(left[i:])
        
        # Add the remaining elements from the right sublist
        result.extend(right[j:])
        
        return result
    
    # Start the recursive sorting
    return _merge_sort(result)

def main():
    """Main function to demonstrate the use of Merge Sort."""
    # Example with numbers
    arr = [64, 34, 25, 12, 22, 11, 90]
    print("Original array:", arr)
    
    # Ascending order
    sorted_arr = merge_sort(arr)
    print("Ascending order:", sorted_arr)
    
    # Descending order
    sorted_arr_desc = merge_sort(arr, reverse=True)
    print("Descending order:", sorted_arr_desc)
    
    # Example with strings
    str_arr = ["banana", "apple", "orange", "pineapple", "grape"]
    print("\nOriginal string array:", str_arr)
    
    # Ascending order
    sorted_str_arr = merge_sort(str_arr)
    print("Ascending order:", sorted_str_arr)
    
    # Descending order
    sorted_str_arr_desc = merge_sort(str_arr, reverse=True)
    print("Descending order:", sorted_str_arr_desc)

if __name__ == "__main__":
    main()
