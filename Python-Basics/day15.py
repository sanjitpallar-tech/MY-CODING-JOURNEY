def find_max_min(arr):
    if not arr:
        return None, None  # Agar array khali hai

    # Pehle element ko max aur min maan liya
    max_val = arr[0]
    min_val = arr[0]

    # Loop 1st index se aakhri tak chalega
    for i in range(1, len(arr)):
        if arr[i] > max_val:
            max_val = arr[i]  # Naya bada element mila
        if arr[i] < min_val:
            min_val = arr[i]  # Naya chota element mila

    return max_val, min_val

# Test karna
numbers = [12, 45, 2, 67, 8, 34]
maximum, minimum = find_max_min(numbers)
print(f"Sabse bada element: {maximum}")
print(f"Sabse chota element: {minimum}")
