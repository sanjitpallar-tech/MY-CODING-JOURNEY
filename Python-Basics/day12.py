def bank_annual_report():
    print("=============================================")
    print("   BANK ANNUAL DEPOSIT REPORT GENERATOR   ")
    print("=============================================\n")
    
    # 12 Mahino ki list
    months = [
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    ]
    
    # Har mahine ka hisaab rakhne ke liye dictionary
    monthly_deposits = {}
    
    # User se har mahine ka data lena
    for month in months:
        while True:
            try:
                amount = float(input(f"{month} mein kitna paisa jamaa hua (₹): "))
                if amount < 0:
                    print("Amount minus (-) mein nahi ho sakta. Kripya sahi value dalein.")
                    continue
                monthly_deposits[month] = amount
                break
            except ValueError:
                print("Invalid input! Kripya sirf numbers dalein.")

    # Calculations
    total_annual_deposit = sum(monthly_deposits.values())
    average_monthly_deposit = total_annual_deposit / 12

    # --- REPORT GENERATION ---
    print("\n" + "="*45)
    print("          FINAL ANNUAL BANK REPORT          ")
    print("="*45)
    print(f"{'Month':<15} | {'Amount Deposited (₹)':<20}")
    print("-" * 45)
    
    # Har mahine ka hisaab print karna
    for month, amount in monthly_deposits.items():
        print(f"{month:<15} | ₹{amount:,.2f}")
        
    print("-" * 45)
    # Total aur Average dikhana
    print(f"Total Annual Deposit : ₹{total_annual_deposit:,.2f}")
    print(f"Average Monthly Deposit: ₹{average_monthly_deposit:,.2f}")
    print("="*45)

# Program ko run karne ke liye function call
if __name__ == "__main__":
    bank_annual_report()