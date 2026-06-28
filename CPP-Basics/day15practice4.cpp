#include <iostream>
using namespace std;

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    // Start aur End ke elements ko aapas me swap karte jao
    while (start < end) {
        // C++ ka inbuilt swap function
        swap(arr[start], arr[end]);
        
        start++; // Aage badho
        end--;   // Piche aao
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    reverseArray(arr, n);

    cout << "Reversed Array: ";
    printArray(arr, n);

    return 0;
}