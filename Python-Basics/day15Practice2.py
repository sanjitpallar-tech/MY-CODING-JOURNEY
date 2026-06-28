def reverse_string(mystr):
    reversed_str = ""
    
    # Loop string ke aakhri index se start hoga aur 0 tak jayega
    # range(start, stop, step) -> yahan step -1 hai yani ulta chalega
    for i in range(len(mystr) - 1, -1, -1):
        reversed_str += mystr[i]  # Ek ek character piche se jod rahe hain
        
    return reversed_str

# Test karna
original = "MUMBAI"
print(f"Original String: {original}")
print(f"Reversed String: {reverse_string(original)}")