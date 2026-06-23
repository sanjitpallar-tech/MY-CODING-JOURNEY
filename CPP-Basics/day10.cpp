#include <iostream>
using namespace std;

int main() {
    int num, originalNum, remainder, result = 0;

    cout << "Ek number enter kijiye: ";
    cin >> num;

    // Original number ko save kar lete hain kyunki 'num' loop mein change ho jayega
    originalNum = num;

    // Loop tab tak chalega jab tak number 0 nahi ho jata
    while (originalNum != 0) {
        // % 10 karne se hamein last digit mil jata hai (Jaise 153 % 10 = 3)
        remainder = originalNum % 10;
        
        // Us last digit ka cube karke 'result' mein jadd (add) rahe hain
        result += remainder * remainder * remainder;
        
        // / 10 karne se last digit hat jata hai (Jaise 153 / 10 = 15)
        originalNum /= 10;
    }

    // Check kar rahe hain ki cube ka sum original number ke barabar hai ya nahi
    if (result == num) {
        cout << num << " ek Armstrong number hai!" << endl;
    } else {
        cout << num << " Armstrong number nahi hai." << endl;
    }

    return 0;
}