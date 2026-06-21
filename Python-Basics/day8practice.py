# Base Class: Holds the fundamental data
class Number:
    def __init__(self, num):
        self._original_number = num


# Derived Class 1: Adds capability to analyze digits
class DigitExtractor(Number):
    def __init__(self, num):
        super().__init__(num)
        self._digit_count = 0

    # Helper method to count how many digits are in the number
    def count_digits(self):
        temp = self._original_number
        count = 0
        while temp > 0:
            count += 1
            temp //= 10  # '//' is floor division in Python (removes decimal)
        self._digit_count = count
        return self._digit_count


# Derived Class 2: Adds the Armstrong math logic
class ArmstrongChecker(DigitExtractor):
    def __init__(self, num):
        super().__init__(num)
        self.__sum_of_powers = 0  # Private variable

    # The core logic to check if it qualifies as an Armstrong Number
    def is_armstrong(self):
        # Step 1: Get the digit count (Inherited function)
        power = self.count_digits()
        
        temp = self._original_number
        self.__sum_of_powers = 0

        # Step 2: Extract each digit and raise it to the power of 'digit_count'
        while temp > 0:
            digit = temp % 10
            self.__sum_of_powers += digit ** power  # '**' is the power operator in Python
            temp //= 10

        # Step 3: Compare the sum to the original number (Inherited variable)
        return self.__sum_of_powers == self._original_number

    def display_result(self):
        print(f"Testing number: {self._original_number}")
        print(f"Total digits: {self._digit_count}")
        print(f"Sum of digits raised to power {self._digit_count}: {self.__sum_of_powers}")

        if self.is_armstrong():
            print("Result: YES, it is an Armstrong Number! ✨")
        else:
            print("Result: NO, it is not an Armstrong Number.")


# --- Execution ---
if __name__ == "__main__":
    print("=== ARMSTRONG NUMBER CHECKER (OOP) ===" + "\n")

    # Test Case 1: 153
    test1 = ArmstrongChecker(153)
    test1.display_result()

    print("\n" + "-----------------------------------" + "\n")

    # Test Case 2: 524
    test2 = ArmstrongChecker(524)
    test2.display_result()