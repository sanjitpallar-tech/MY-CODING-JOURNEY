#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    int start = 0;
    int end = str.length() - 1;

    // Dono taraf se ek-ek character compare karte hue beech me aayenge
    while (start < end) {
        if (str[start] != str[end]) {
            return false; // Agar match nahi hua toh palindrome nahi hai
        }
        start++; // Aage badho
        end--;   // Piche aao
    }
    return true; // Agar loop poora chal gaya toh palindrome hai
}

int main() {
    string word = "RADAR";
    
    if (isPalindrome(word)) {
        cout << word << " ek Palindrome string hai!" << endl;
    } else {
        cout << word << " Palindrome nahi hai." << endl;
    }
    return 0;
}