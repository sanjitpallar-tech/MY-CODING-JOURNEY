def expense_tracker():
    # Ek khali list jisme saara data store hoga
    products = []
    
    print("--- Welcome to Product Expense Tracker ---")
    
    while True:
        # User se product ka naam lena
        product_name = input("\nProduct ka naam daalein (ya 'exit' likhein band karne ke liye): ").strip()
        
        # Agar user exit likhe toh loop band ho jaye
        if product_name.lower() == 'exit':
            break
            
        # Price (Kharcha) input lena aur handle karna agar galat number daale
        try:
            price = float(input(f"'{product_name}' ka kharcha (Price) daalein: ₹"))
        except ValueError:
            print("❌ Kripya sahi number (amount) daalein!")
            continue
            
        # Product aur price ko dictionary me daal kar list me save karna
        products.append({"name": product_name, "price": price})
        print(f"✅ '{product_name}' save ho gaya!")

    # --- Ab Final Hisaab Show Karte Hain ---
    print("\n" + "="*30)
    print("📋 AAPKA FINAL HISAAB KITAB")
    print("="*30)
    
    if not products:
        print("Aapne koi kharcha add nahi kiya.")
    else:
        total_expense = 0
        # Saare products ko ek ek karke print karna
        for index, item in enumerate(products, 1):
            print(f"{index}. {item['name']}: ₹{item['price']:.2f}")
            total_expense += item['price']
            
        print("-"*30)
        print(f"💰 KUL KHARCHA (Total Expense): ₹{total_expense:.2f}")
        print("="*30)

# Program ko chalane ke liye function call karein
expense_tracker()