# List & Tuples

'''list1 = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
list2 = [1, 3, 5, 9, 11, 13, 15, 19, 21, 23]

print(list1)
print(list2)'''

'''max = []
min = []

max.append(input("Enter the First number is: "))
min.append(input("Enter the Second number is: "))

if("min > max"):
    print("Maximum is the bigger")
elif("max > min"):
    print("Minimum is bigger")
else:
    print("None")'''


# 1. Yeh hamari purani list hai jisme duplicates hain
'''original_list = [1, 2, 2, 3, 4, 4, 1, 5]

# 2. Ek nayi khali list banayi jisme unique elements rakhenge
unique_list = []

# 3. Loop chalakar purani list ke har element ko check karenge
for number in original_list:
    # Check kar rahe hain ki number naye list mein hai ya nahi
    if number not in unique_list:
        unique_list.append(number)  # Agar nahi hai toh add kar do

# 4. Final result print karenge
print("Original List:", original_list)
print("Unique List:", unique_list)'''


numbers_list = [1, 2, 3, 4, 5]

squares_list = []

for num in numbers_list:

    sqaure_value = num**2

    squares_list.append(sqaure_value)

    final_tuple = tuple(squares_list)

    print("Hamara Final tuple: ", final_tuple)







    