#include <iostream>
#include <string>

using namespace std;

// Student naam ki class banayi
class Student {
private:
    int rollNumber;
    float height; // cms ya feet me
    float weight; // kgs me

public:
    // Data input lene ke liye function
    void inputData(int roll) {
        rollNumber = roll;
        cout << "\nStudent Roll Number " << rollNumber << " ka data dalein:\n";
        cout << "Height (in cm) dalein: ";
        cin >> height;
        cout << "Weight (in kg) dalein: ";
        cin >> weight;
    }

    // Data display karne ke liye function
    void displayData() {
        cout << rollNumber << "\t\t" << height << " cm\t\t" << weight << " kg\n";
    }
};

int main() {
    // 56 baccho ke liye Array of Objects banaya
    int totalStudents = 8;
    Student classRoom[totalStudents]; 

    cout << "--- 8 Students ka Data Entry Setup ---\n";
    
    // Sabhi 56 students ka data input lene ke liye loop
    for(int i = 0; i < totalStudents; i++) {
        // i + 1 isliye taaki Roll Number 1 se start ho (0 se nahi)
        classRoom[i].inputData(i + 1); 
    }

    // Sabhi students ka data print karne ke liye
    cout << "\n--- Students ka Height aur Weight Report ---\n";
    cout << "Roll No.\tHeight\t\tWeight\n";
    cout << "-------------------------------------------\n";
    
    for(int i = 0; i < totalStudents; i++) {
        classRoom[i].displayData();
    }

    return 0;
}