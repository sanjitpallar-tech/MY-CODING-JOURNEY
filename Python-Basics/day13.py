from abc import ABC, abstractmethod

# 1. ABSTRACTION (Abstract Base Class)
# Yeh ek blueprint hai, iska direct object nahi ban sakta.
class Vehicle(ABC):
    def __init__(self, brand, model, price):
        self.brand = brand
        self.model = model
        self.__price = price # ENCAPSULATION: Private variable (Direct access nahi hoga)

    # Getter method price access karne ke liye
    def get_price(self):
        return self.__price

    # Setter method price modify karne ke liye
    def set_price(self, new_price):
        if new_price > 0:
            self.__price = new_price
        else:
            print("Invalid Price!")

    @abstractmethod
    def start_engine(self):
        pass

    @abstractmethod
    def vehicle_info(self):
        pass


# 2. INHERITANCE (Base Class Car inherits Vehicle)
class Car(Vehicle):
    def __init__(self, brand, model, price, fuel_type):
        super().__init__(brand, model, price)
        self.fuel_type = fuel_type
        self.is_running = False

    def start_engine(self):
        self.is_running = True
        return f"The engine of {self.brand} {self.model} has started. Vroom Vroom!"

    def vehicle_info(self):
        return f"Car: {self.brand} {self.model} | Fuel: {self.fuel_type} | Price: ₹{self.get_price()}"


# 3. POLYMORPHISM (ElectricCar aur SportsCar alag tareeqe se behave karenge)
class ElectricCar(Car):
    def __init__(self, brand, model, price, battery_capacity):
        super().__init__(brand, model, price, fuel_type="Electric")
        self.battery_capacity = battery_capacity # in kWh

    # Method Overriding (Polymorphism)
    def start_engine(self):
        self.is_running = True
        return f"{self.brand} {self.model} starts silently. (Electric Mode Active) ⚡"
    
    # Method Overriding
    def vehicle_info(self):
        return f"EV Car: {self.brand} {self.model} | Battery: {self.battery_capacity}kWh | Price: ₹{self.get_price()}"


class SportsCar(Car):
    def __init__(self, brand, model, price, top_speed):
        super().__init__(brand, model, price, fuel_type="Petrol")
        self.top_speed = top_speed # in km/h

    # Method Overriding (Polymorphism)
    def start_engine(self):
        self.is_running = True
        return f"{self.brand} {self.model} roars to life! 🏎️"
    
    # Method Overriding
    def vehicle_info(self):
        return f"Sports Car: {self.brand} {self.model} | Top Speed: {self.top_speed} km/h | Price: ₹{self.get_price()}"


# 4. SHOWROOM CLASS (Aggregation - Managing multiple objects)
class Showroom:
    def __init__(self, name):
        self.name = name
        self.inventory = []

    def add_vehicle(self, vehicle):
        if isinstance(vehicle, Vehicle):
            self.inventory.append(vehicle)
            print(f"✅ Added to Inventory: {vehicle.brand} {vehicle.model}")
        else:
            print("❌ Invalid Vehicle Type!")

    def display_inventory(self):
        print(f"\n--- Welcome to {self.name} Inventory ---")
        if not self.inventory:
            print("Showroom is currently empty.")
        for index, vehicle in enumerate(self.inventory, start=1):
            print(f"{index}. {vehicle.vehicle_info()}")
        print("-" * 40)

    def test_drive(self, index):
        if 0 <= index < len(self.inventory):
            vehicle = self.inventory[index]
            print(f"\nTaking test drive of {vehicle.brand} {vehicle.model}...")
            print(vehicle.start_engine())
        else:
            print("❌ Invalid Selection for Test Drive!")


# --- Execution (Program Run Kaise Hoga) ---
if __name__ == "__main__":
    # Showroom create kiya
    my_showroom = Showroom("Apex Motors Mumbai")

    # Alag-alag type ki Cars ke Objects banaye (Polymorphism & Instance Creation)
    car1 = Car("Hyundai", "i20", 850000, "Petrol")
    car2 = ElectricCar("Tesla", "Model S", 8000000, 100)
    car3 = SportsCar("Ferrari", "SF90", 45000000, 340)

    print("--- Adding Cars to Showroom ---")
    my_showroom.add_vehicle(car1)
    my_showroom.add_vehicle(car2)
    my_showroom.add_vehicle(car3)

    # Showroom Inventory Display
    my_showroom.display_inventory()

    # Encapsulation Test (Direct price modification check)
    print("\n--- Updating Car Price via Encapsulation ---")
    print(f"Old Price of Tesla: ₹{car2.get_price()}")
    car2.set_price(8500000) # Setter use kiya
    print(f"New Price of Tesla: ₹{car2.get_price()}")

    # Test Drive (Polymorphism in Action)
    print("\n--- Starting Test Drives ---")
    my_showroom.test_drive(0) # Standard Car
    my_showroom.test_drive(1) # Electric Car (Silent start)
    my_showroom.test_drive(2) # Sports Car (Roar start)


                                                            
                                                          
                                                        


                        



