import math

def print_primes_upto_n(n):
    print(f"{n} tak ke Prime Numbers:")
    
    # 2 se leke n tak har number ko check karenge
    for num in range(2, n + 1):
        is_prime = True
        
        # 2 se leke us number ke square root tak divide karke check karenge
        for i in range(2, int(math.isqrt(num)) + 1):
            if num % i == 0:
                is_prime = False  # Agar divide ho gaya toh prime nahi hai
                break
                
        if is_prime:
            print(num, end=" ")
    print()  # New line ke liye

# Test karna (Maan lijiye n = 30)
print_primes_upto_n(30)