#include <iostream>
#include <string>

using namespace std;

class Transport {
protected:
    string model;

public:
    Transport(const string& model) : model(model) {}
    virtual ~Transport() {}

    virtual void displayInfo() const {
        cout << "Model: " << model << endl;
    }
};

class Ship : public Transport {
protected:
    int displacement;

public:
    Ship(const string& model, int displacement) : Transport(model), displacement(displacement) {}
    virtual ~Ship() {}

    virtual void displayInfo() const override {
        Transport::displayInfo();
        cout << "Displacement: " << displacement << " tons" << endl;
    }
};

class PassengerTransport : public Transport {
protected:
    int passengerCapacity;

public:
    PassengerTransport(const string& model, int passengerCapacity) : Transport(model), passengerCapacity(passengerCapacity) {}
    virtual ~PassengerTransport() {}

    virtual void displayInfo() const override {
        Transport::displayInfo();
        cout << "Passenger capacity: " << passengerCapacity << " persons" << endl;
    }
};

class PassengerShip : public Ship, public PassengerTransport {
public:
    PassengerShip(const string& model, int displacement, int passengerCapacity) : Ship(model, displacement), PassengerTransport(model, passengerCapacity) {}
    virtual ~PassengerShip() {}

    virtual void displayInfo() const override {
        Ship::displayInfo();
        cout << "Passenger capacity: " << passengerCapacity << " persons" << endl;
    }
};

int main() {
    PassengerShip ship("Titanic", 54321, 1111);

    cout << "Ship Information:" << endl;
    ship.displayInfo();

    return 0;
}
