#include <iostream>
#include <climits> // INT_MIN ke liye
using namespace std;

void findSecondLargest(int arr[], int size) {
    if (size < 2) {
        cout << "Array me kam se kam 2 elements hone chahiye!" << endl;
        return;
    }

    int firstMax = INT_MIN;
    int secondMax = INT_MIN;

    for (int i = 0; i < size; i++) {
        // Agar current element sabse bada hai
        if (arr[i] > firstMax) {
            secondMax = firstMax; // Purana max ab second max ban gaya
            firstMax = arr[i];    // Naya max update hua
        }
        // Agar current element firstMax se chota hai lekin secondMax se bada hai
        else if (arr[i] > secondMax && arr[i] != firstMax) {
            secondMax = arr[i];
        }
    }

    if (secondMax == INT_MIN) {
        cout << "Koi second largest element nahi mila (saare same hain)." << endl;
    } else {
        cout << "Sabse bada element: " << firstMax << endl;
        cout << "Dusra sabse bada (Second Largest): " << secondMax << endl;
    }
}

int main() {
    int numbers[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(numbers) / sizeof(numbers[0]); // Array ka size nikalna
    
    findSecondLargest(numbers, n);
    return 0;
}