# 1. 
'''str = "Programming"

dic_str = {}

for char in str:
    if char in dic_str:
        dic_str[char] += 1
    else:
        dic_str[char] = 1

        print(dic_str)'''

'''set = {1, 2, 2, 3, 4, 4, 5}

print(set)
print(len(set))'''

'''dic1 = {'apple':50, 'banana':20}
dic2 = {'banana' :25, 'orange' :30}

merge_dic = dic1.copy()

for item, price in dic2.items():
    if item in merge_dic:
        merge_dic[item] += price
    else:
        merge_dic[item] = price

        print(merge_dic)'''


# 1. Pehle humne normal lists banayi
class_a_list = ["Rahul", "Amit", "Priya", "Rohan"]
class_b_list = ["Rohan", "Priya", "Vikas", "Sonu"]

# 2. Sets ke tools use karne ke liye, lists ko SET mein convert kiya
class_a = set(class_a_list)
class_b = set(class_b_list)

print("--- RESULTS ---")

# Twist 1: Dono mein common students
common_students = class_a.intersection(class_b)
print("Dono classes mein common students:", common_students) 
# Output: {'Priya', 'Rohan'}

# Twist 2: Jo sirf Class A mein hain
only_in_a = class_a.difference(class_b)
print("Sirf Class A ke students:", only_in_a) 
# Output: {'Rahul', 'Amit'}

# Twist 3: Saare unique students dono classes ke
all_students = class_a.union(class_b)
print("Saare unique students ki list:", all_students) 
# Output: {'Rahul', 'Amit', 'Priya', 'Rohan', 'Vikas', 'Sonu'}


