# Base Class: Representing the 1st Generation
class Grandparent:
    def __init__(self, eyes):
        # Single underscore denotes 'protected' by convention in Python
        self._eye_color = eyes  

    def display_grandparent_traits(self):
        print("--- 1st Generation (Grandparent) ---")
        print(f"Eye Color: {self._eye_color}")


# Derived Class: Representing the 2nd Generation (Inherits from Grandparent)
class Parent(Grandparent):
    def __init__(self, eyes, hair):
        # Call the Grandparent constructor to pass down eye color
        super().__init__(eyes)  
        self._hair_type = hair

    def display_parent_traits(self):
        print("--- 2nd Generation (Parent) ---")
        print(f"Inherited Eye Color: {self._eye_color}")
        print(f"Hair Type: {self._hair_type}")


# Derived Class: Representing the 3rd Generation (Inherits from Parent)
class Child(Parent):
    def __init__(self, eyes, hair, special_talent):
        # Call the Parent constructor to pass down eyes and hair
        super().__init__(eyes, hair)  
        # Double underscore makes this strictly private to the Child class
        self.__talent = special_talent  

    def display_child_traits(self):
        print("--- 3rd Generation (Child) ---")
        print(f"Inherited Eye Color: {self._eye_color}")  # From Grandparent
        print(f"Inherited Hair Type: {self._hair_type}")   # From Parent
        print(f"Unique Talent: {self.__talent}")


# --- Execution ---
if __name__ == "__main__":
    print("=== GENETIC LINEAGE REPORT ===" + "\n")
    
    # Parameters: Eye Color (Grandparent), Hair Type (Parent), Talent (Child)
    modern_child = Child("Deep Blue", "Curly Brown", "Virtuoso Pianist")
    
    # The child object displays all its inherited and unique traits
    modern_child.display_child_traits()