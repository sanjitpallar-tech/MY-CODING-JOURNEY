# Step 1: User se uska naam input lena
naam = input("Apna naam enter karein: ")

# Step 2: Check karna ki naam mein 5 se zyada letters hain ya nahi
if len(naam) > 5:
    # Step 3: Agar 5 se bada hai, toh slicing use karke pehle 3 letters nikalna
    naam_ka_tukda = naam[0:3]
    print("Aapka naam bada hai! Short name:", naam_ka_tukda)
else:
    # Step 4: Agar naam 5 ya usse chota hai, toh pura naam print kar dena
    print("Aapka naam chota hai:", naam)





