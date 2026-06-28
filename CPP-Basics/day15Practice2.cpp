#include <iostream>
using namespace std;

void calculateFactorial(int n) {
    if (n < 0) {
        cout << "Negative numbers ka factorial nahi hota!" << endl;
        return;
    }

    unsigned long long factorial = 1; // Badi value store karne ke liye

    // Loop 1 se lekar n tak chalega aur multiply karta jayega
    for (int i = 1; i <= n; i++) {
        factorial *= i; // factorial = factorial * i
    }

    cout << n << " ka Factorial hai: " << factorial << endl;
}

int main() {
    int num = 5;
    calculateFactorial(num);
    return 0;
}