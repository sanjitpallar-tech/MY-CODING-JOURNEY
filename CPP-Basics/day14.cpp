#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Price ko .2f format me dikhane ke liye

using namespace std;

// Product ke liye ek structure (blueprint)
struct Product {
    string name;
    double price;
};

int main() {
    vector<Product> products; // Saare products store karne ke liye list
    string name;
    double price;

    cout << "--- Welcome to Product Expense Tracker (C++) ---" << endl;

    while (true) {
        cout << "\nProduct ka naam daalein (ya 'exit' likhein band karne ke liye): ";
        cin >> name;

        // Agar user exit likhe toh loop band ho jaye
        if (name == "exit" || name == "EXIT") {
            break;
        }

        cout << "'" << name << "' ka kharcha (Price) daalein: ";
        cin >> price;

        // Input validation: Agar user number ki jagah text daal de
        if (cin.fail()) {
            cout << "❌ Kripya sahi number (amount) daalein!" << endl;
            cin.clear(); // Error flag clear karne ke liye
            cin.ignore(10000, '\n'); // Galat input ko skip karne ke liye
            continue;
        }

        // New product ko vector (list) mein add karna
        products.push_back({name, price});
        cout << "✅ '" << name << "' save ho gaya!" << endl;
    }

    // --- Ab Final Hisaab Show Karte Hain ---
    cout << "\n==============================" << endl;
    cout << "📋 AAPKA FINAL HISAAB KITAB" << endl;
    cout << "==============================" << endl;

    if (products.empty()) {
        cout << "Aapne koi kharcha add nahi kiya." << endl;
    } else {
        double total_expense = 0;

        // Price ko hamesha 2 decimal tak dikhane ke liye setting
        cout << fixed << setprecision(2);

        // Saare products ko loop se print karna
        for (size_t i = 0; i < products.size(); ++i) {
            cout << i + 1 << ". " << products[i].name << ": " << products[i].price << " Rs" << endl;
            total_expense += products[i].price;
        }

        cout << "------------------------------" << endl;
        cout << "💰 KUL KHARCHA (Total Expense): " << total_expense << " Rs" << endl;
        cout << "==============================" << endl;
    }

    return 0;
}