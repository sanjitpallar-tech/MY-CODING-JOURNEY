#include<iostream>
using namespace std;

int main()
{
    int number, originalNumber, remainder, reversedNumber = 0;

    cout << "Enter an integer: ";
    cin >> number;

    originalNumber = number; 

    while(number > 0)
    {
        remainder = number % 10;
        reversedNumber = (reversedNumber*10) + remainder;
        number = number / 10;

    }

    if(originalNumber == reversedNumber){
        cout <<originalNumber<< " is a Palindrome Number."<<endl;
    }
        else{
            cout <<originalNumber<< " is not a Palindrome Number."<<endl;

        }
        
            
            


    return 0;
}

