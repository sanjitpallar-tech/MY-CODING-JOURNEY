#include <iostream>
#include <cmath> // Used for the pow() function

// Base Class: Holds the fundamental data
class Number {
protected:
    int originalNumber;

public:
    // Constructor to initialize the number
    Number(int num) : originalNumber(num) {}
};

// Derived Class 1: Adds capability to analyze digits (Inherits from Number)
class DigitExtractor : public Number {
protected:
    int digitCount;

public:
    // Constructor passes the number to the Base class
    DigitExtractor(int num) : Number(num), digitCount(0) {}

    // Helper method to count how many digits are in the number
    int countDigits() {
        int temp = originalNumber;
        int count = 0;
        while (temp > 0) {
            count++;
            temp /= 10;
        }
        digitCount = count;
        return digitCount;
    }
};

// Derived Class 2: Adds the Armstrong math logic (Inherits from DigitExtractor)
class ArmstrongChecker : public DigitExtractor {
private:
    int sumOfPowers;

public:
    // Constructor passes the number up to DigitExtractor
    ArmstrongChecker(int num) : DigitExtractor(num), sumOfPowers(0) {}

    // The core logic to check if it qualifies as an Armstrong Number
    bool isArmstrong() {
        // Step 1: Get the digit count (Inherited function)
        int power = countDigits(); 
        
        int temp = originalNumber;
        sumOfPowers = 0;

        // Step 2: Extract each digit and raise it to the power of 'digitCount'
        while (temp > 0) {
            int digit = temp % 10;
            sumOfPowers += std::pow(digit, power);
            temp /= 10;
        }

        // Step 3: Compare the sum to the original number (Inherited variable)
        return (sumOfPowers == originalNumber);
    }

    void displayResult() {
        std::cout << "Testing number: " << originalNumber << std::endl;
        std::cout << "Total digits: " << digitCount << std::endl;
        std::cout << "Sum of digits raised to power " << digitCount << ": " << sumOfPowers << std::endl;

        if (isArmstrong()) {
            std::cout << "Result: YES, it is an Armstrong Number! ✨" << std::endl;
        } else {
            std::cout << "Result: NO, it is not an Armstrong Number." << std::endl;
        }
    }
};

int main() {
    std::cout << "=== ARMSTRONG NUMBER CHECKER (OOP) ===" << std::endl << std::endl;

    // Test Case 1: 153 (1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153)
    ArmstrongChecker test1(153);
    test1.displayResult();

    std::cout << "\n-----------------------------------\n" << std::endl;

    // Test Case 2: 1634 (1^4 + 6^4 + 3^4 + 4^4 = 1 + 1296 + 81 + 256 = 1634)
    ArmstrongChecker test2(1634);
    test2.displayResult();

    std::cout << "\n-----------------------------------\n" << std::endl;

    // Test Case 3: A non-Armstrong number
    ArmstrongChecker test3(524);
    test3.displayResult();

    return 0;
}