#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. ABSTRACTION (Abstract Class using Pure Virtual Function)
// Yeh base class hai jiska direct object nahi ban sakta.
class Product {
private:
    int id;
    string name;
    double price; // ENCAPSULATION: Data members ko private rakha hai

public:
    // Constructor
    Product(int p_id, string p_name, double p_price) {
        id = p_id;
        name = p_name;
        price = p_price;
    }

    // Getters and Setters (Encapsulation ko maintain karne ke liye)
    int getId() { return id; }
    string getName() { return name; }
    double getPrice() { return price; }
    
    void setPrice(double new_price) {
        if(new_price > 0) price = new_price;
    }

    // Pure Virtual Function (Abstraction & Polymorphism ka base)
    virtual void displayDetails() = 0; 
    
    // Virtual Destructor
    virtual ~Product() {}
};


// 2. INHERITANCE (Electronics product inherits Product)
class Electronics : public Product {
private:
    int warrantyMonths;
    string brand;

public:
    // Constructor Forwarding / Initializer List
    Electronics(int p_id, string p_name, double p_price, string b, int w) 
        : Product(p_id, p_name, p_price), brand(b), warrantyMonths(w) {}

    // POLYMORPHISM: Method Overriding
    void displayDetails() override {
        cout << "[Electronics] ID: " << getId() 
             << " | Name: " << getName() 
             << " | Brand: " << brand 
             << " | Price: ₹" << getPrice() 
             << " | Warranty: " << warrantyMonths << " Months" << endl;
    }
};


// INHERITANCE: Clothing product inherits Product
class Clothing : public Product {
private:
    string size;
    string material;

public:
    Clothing(int p_id, string p_name, double p_price, string s, string m) 
        : Product(p_id, p_name, p_price), size(s), material(m) {}

    // POLYMORPHISM: Method Overriding
    void displayDetails() override {
        cout << "[Clothing]    ID: " << getId() 
             << " | Name: " << getName() 
             << " | Size: " << size 
             << " | Material: " << material 
             << " | Price: ₹" << getPrice() << endl;
    }
};


// 3. POLYMORPHISM (Compile-time / Function Overloading)
class DiscountManager {
public:
    // Regular customer discount (Percentage based)
    double calculateDiscount(double originalPrice, double discountPercentage) {
        return originalPrice - (originalPrice * (discountPercentage / 100.0));
    }

    // VIP customer discount (Flat discount + Seasonal discount)
    double calculateDiscount(double originalPrice, double flatDiscount, double seasonalBonus) {
        return originalPrice - flatDiscount - seasonalBonus;
    }
};


// 4. CART CLASS (Aggregation - Managing a collection of Product pointers)
class ShoppingCart {
private:
    vector<Product*> items; // Run-time polymorphism achieve karne ke liye pointers use kiye hain

public:
    void addProduct(Product* prod) {
        items.push_back(prod);
        cout << "🛒 Added to Cart: " << prod->getName() << endl;
    }

    void viewCart() {
        cout << "\n--- Your Shopping Cart ---" << endl;
        if(items.empty()) {
            cout << "Your cart is empty!" << endl;
            return;
        }
        for (Product* prod : items) {
            prod->displayDetails(); // Dynamic Binding / Runtime Polymorphism
        }
        cout << "--------------------------" << endl;
    }

    double calculateTotal() {
        double total = 0;
        for (Product* prod : items) {
            total += prod->getPrice();
        }
        return total;
    }
};


// --- Main Execution ---
int main() {
    cout << "=== WELCOME TO OOPS E-COMMERCE SYSTEM ===\n" << endl;

    // Objects creation (Heap allocation for runtime polymorphism)
    Product* laptop = new Electronics(101, "MacBook M3", 125000, "Apple", 12);
    Product* phone = new Electronics(102, "Galaxy S24", 75000, "Samsung", 24);
    Product* jacket = new Clothing(201, "Leather Jacket", 4500, "XL", "Pure Leather");

    // Cart Object
    ShoppingCart userCart;

    // Adding products to cart
    userCart.addProduct(laptop);
    userCart.addProduct(phone);
    userCart.addProduct(jacket);

    // View Cart (Demonstrating Runtime Polymorphism)
    userCart.viewCart();

    // Calculate Total Billing
    double totalBill = userCart.calculateTotal();
    cout << "Initial Total Bill: ₹" << totalBill << endl;

    // Encapsulation Check & Price Update
    cout << "\n--- Updating Laptop Price (Encapsulation) ---" << endl;
    laptop->setPrice(120000); // Price updated through setter
    cout << "New Laptop Price: ₹" << laptop->getPrice() << endl;
    
    // Recalculating Total
    totalBill = userCart.calculateTotal();
    cout << "Updated Total Bill: ₹" << totalBill << endl;

    // Discount Calculation (Demonstrating Compile-time Polymorphism / Overloading)
    DiscountManager dm;
    cout << "\n--- Applying Discounts (Function Overloading) ---" << endl;
    
    // Scenario 1: Regular User (10% off)
    double regularFinal = dm.calculateDiscount(totalBill, 10.0);
    cout << "Regular Customer Final Price (10% Off): ₹" << regularFinal << endl;

    // Scenario 2: VIP User (₹5000 flat off + ₹1500 festival bonus)
    double vipFinal = dm.calculateDiscount(totalBill, 5000.0, 1500.0);
    cout << "VIP Customer Final Price (Flat + Bonus Off): ₹" << vipFinal << endl;

    // Memory Cleanup (De-allocating dynamic memory)
    delete laptop;
    delete phone;
    delete jacket;

    return 0;
}