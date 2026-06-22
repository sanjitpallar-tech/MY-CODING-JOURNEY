import sys

def smart_calculator():
    print("====================================")
    print("    Smart Python Calculator v1.0   ")
    print("====================================")
    print("Enter your expression (or type 'exit' to quit).")
    print("Examples: 2 + 3 * 4,  (10 - 2) / 4,  2**3 (for 2^3)")
    print("------------------------------------")

    while True:
        try:
            # Get user input
            user_input = input("\ncalc > ").strip()
            
            # Check for exit condition
            if user_input.lower() in ['exit', 'quit']:
                print("Goodbye!")
                sys.exit()
                
            if not user_input:
                continue

            # Evaluate the expression safely
            # Note: We limit the globals/locals for a layer of basic safety
            result = eval(user_input, {"__builtins__": None}, {})
            print(f"Result: {result}")

        except ZeroDivisionError:
            print("Error: Division by zero is not allowed.")
        except (SyntaxError, NameError, TypeError):
            print("Error: Invalid expression. Please check your math syntax.")
        except Exception as e:
            print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    smart_calculator()