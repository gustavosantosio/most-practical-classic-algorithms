"""
Radix Sort - Sorting Algorithm

Time Complexity:
- Best case: O(nk) where n is the number of elements and k is the number of digits in the largest number
- Average case: O(nk)
- Worst case: O(nk)

Space Complexity: O(n+k) where k is the range of possible values

How it works:
Radix Sort is a non-comparative sorting algorithm that sorts integers by processing individual digits.
1. Start with the least significant digit (units)
2. Group numbers into buckets according to the current digit value
3. Collect the numbers from the buckets in order
4. Repeat the process for each digit position, up to the most significant digit
"""

def radix_sort(arr, reverse=False):
    """
    Implementation of the Radix Sort algorithm for positive integers.
    
    Args:
        arr: List of positive integers to be sorted
        reverse: If True, sorts in descending order; if False, in ascending order
        
    Returns:
        Sorted list
    """
    # Create a copy of the array to avoid modifying the original
    result = arr.copy()
    
    # Find the maximum number to determine the number of digits
    max_num = max(result)
    
    # Perform counting sort for each digit position
    exp = 1
    while max_num // exp > 0:
        result = _counting_sort(result, exp, reverse)
        exp *= 10
            
    return result

def _counting_sort(arr, exp, reverse):
    """
    Helper function to sort numbers based on a specific digit.
    
    Args:
        arr: List to be sorted
        exp: Digit position (1 for units, 10 for tens, etc.)
        reverse: Sort direction
        
    Returns:
        List sorted by the specific digit
    """
    n = len(arr)
    output = [0] * n
    count = [0] * 10  # 10 possible digits (0-9)
    
    # Count occurrences of each digit at the current position
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1
    
    # Adjust count to contain actual positions in the output array
    if not reverse:
        # Ascending order
        for i in range(1, 10):
            count[i] += count[i - 1]
    else:
        # Descending order
        for i in range(8, -1, -1):
            count[i] += count[i + 1]
    
    # Build the output array
    i = n - 1
    while i >= 0:
        index = (arr[i] // exp) % 10
        if not reverse:
            output[count[index] - 1] = arr[i]
            count[index] -= 1
        else:
            output[count[index] - 1] = arr[i]
            count[index] -= 1
        i -= 1
    
    return output

def main():
    """Main function to demonstrate the use of Radix Sort."""
    # Example with numbers
    arr = [170, 45, 75, 90, 802, 24, 2, 66]
    print("Original array:", arr)
    
    # Ascending order
    sorted_arr = radix_sort(arr)
    print("Ascending order:", sorted_arr)
    
    # Descending order
    sorted_arr_desc = radix_sort(arr, reverse=True)
    print("Descending order:", sorted_arr_desc)

if __name__ == "__main__":
    main()
