#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Output ko ache se format karne ke liye (jaise tables)

using namespace std;

int main() {
    cout << "=============================================\n";
    cout << "   BANK ANNUAL DEPOSIT REPORT GENERATOR   \n";
    cout << "=============================================\n\n";

    // 12 Mahino ki list
    vector<string> months = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    vector<double> deposits(12); // Har mahine ka amount store karne ke liye array
    double total_annual_deposit = 0.0;

    // User se har mahine ka data lena
    for (int i = 0; i < 12; i++) {
        while (true) {
            cout << months[i] << " mein kitna paisa jamaa hua (Rs.): ";
            cin >> deposits[i];

            // Error handling: Agar user galat input dale (jaise text ya minus value)
            if (cin.fail() || deposits[i] < 0) {
                cin.clear(); // Error state clear karne ke liye
                cin.ignore(10000, '\n'); // Purani galat input ko skip karne ke liye
                cout << "Invalid input! Kripya ek sahi positive number dalein.\n";
            } else {
                total_annual_deposit += deposits[i];
                break; // Sahi input milne par loop se bahar
            }
        }
    }

    double average_monthly_deposit = total_annual_deposit / 12.0;

    // --- REPORT GENERATION ---
    cout << "\n=============================================\n";
    cout << "          FINAL ANNUAL BANK REPORT          \n";
    cout << "=============================================\n";
    
    // Table Headers ko align karne ke liye setw() ka use kiya hai
    cout << left << setw(15) << "Month" << " | " << "Amount Deposited (Rs.)" << "\n";
    cout << "---------------------------------------------\n";

    // Har mahine ka hisaab print karna
    // fixed aur setprecision(2) se point ke baad sirf 2 numbers dikhenge (e.g., 500.00)
    cout << fixed << setprecision(2);
    for (int i = 0; i < 12; i++) {
        cout << left << setw(15) << months[i] << " | Rs. " << deposits[i] << "\n";
    }

    cout << "---------------------------------------------\n";
    // Total aur Average dikhana
    cout << "Total Annual Deposit   : Rs. " << total_annual_deposit << "\n";
    cout << "Average Monthly Deposit: Rs. " << average_monthly_deposit << "\n";
    cout << "=============================================\n";

    return 0;
}