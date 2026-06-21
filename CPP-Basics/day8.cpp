#include <iostream>
#include <string>

// Base Class: Representing the 1st Generation
class Grandparent {
protected:
    std::string eyeColor;

public:
    // Constructor
    Grandparent(std::string eyes) : eyeColor(eyes) {}

    void displayGrandparentTraits() {
        std::cout << "--- 1st Generation (Grandparent) ---" << std::endl;
        std::cout << "Eye Color: " << eyeColor << std::endl;
    }
};

// Derived Class: Representing the 2nd Generation (Inherits from Grandparent)
class Parent : public Grandparent {
protected:
    std::string hairType;

public:
    // Constructor passes eye color to Grandparent and sets hair type
    Parent(std::string eyes, std::string hair) 
        : Grandparent(eyes), hairType(hair) {}

    void displayParentTraits() {
        std::cout << "--- 2nd Generation (Parent) ---" << std::endl;
        std::cout << "Inherited Eye Color: " << eyeColor << std::endl;
        std::cout << "Hair Type: " << hairType << std::endl;
    }
};

// Derived Class: Representing the 3rd Generation (Inherits from Parent)
class Child : public Parent {
private:
    std::string talent;

public:
    // Constructor passes traits up the chain and sets its own unique trait
    Child(std::string eyes, std::string hair, std::string specialTalent)
        : Parent(eyes, hair), talent(specialTalent) {}

    void displayChildTraits() {
        std::cout << "--- 3rd Generation (Child) ---" << std::endl;
        std::cout << "Inherited Eye Color: " << eyeColor << std::endl; // From Grandparent
        std::cout << "Inherited Hair Type: " << hairType << std::endl;   // From Parent
        std::cout << "Unique Talent: " << talent << std::endl;
    }
};

int main() {
    // Creating a Child object and passing the genetic traits down the line
    // Parameters: Eye Color (Grandparent), Hair Type (Parent), Talent (Child)
    Child modernChild("Deep Blue", "Curly Brown", "Virtuoso Pianist");

    // Displaying the transferred genetic information
    std::cout << "=== GENETIC LINEAGE REPORT ===" << std::endl << std::endl;
    
    // The child has access to all the traits passed down
    modernChild.displayChildTraits();

    return 0;
}

