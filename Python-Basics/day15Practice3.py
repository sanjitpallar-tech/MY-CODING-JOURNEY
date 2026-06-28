def generate_fibonacci(n):
    if n <= 0:
        print("Kripya 0 se bada number dalein.")
        return
    
    a, b = 0, 1
    print(f"Fibonacci ke pehle {n} terms:")
    
    for i in range(n):
        print(a, end=" ")
        # Agla term calculate karke variables swap karna
        next_term = a + b
        a = b
        b = next_term
    print()

# Test karna (Pehle 10 terms)
generate_fibonacci(10)