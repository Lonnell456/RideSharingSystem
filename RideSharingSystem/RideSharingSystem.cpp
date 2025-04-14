#include <iostream>
#include <vector>
using namespace std;

// Base Ride class
class Ride {
protected:
    int rideID;
    string pickupLocation;
    string dropoffLocation;
    double distance;

public:
    Ride(int id, string pickup, string dropoff, double dist)
        : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), distance(dist) {
    }

    virtual double fare() {
        return distance * 1.0; // base rate
    }

    virtual void rideDetails() {
        cout << "Ride ID: " << rideID << ", From: " << pickupLocation << ", To: " << dropoffLocation
            << ", Distance: " << distance << " miles, Fare: $" << fare() << endl;
    }

    virtual ~Ride() {}
};

// StandardRide subclass
class StandardRide : public Ride {
public:
    StandardRide(int id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {
    }

    double fare() override {
        return distance * 1.5;
    }
};

// PremiumRide subclass
class PremiumRide : public Ride {
public:
    PremiumRide(int id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {
    }

    double fare() override {
        return distance * 3.0;
    }
};

// Driver class with encapsulation
class Driver {
private:
    int driverID;
    string name;
    double rating;
    vector<Ride*> assignedRides;

public:
    Driver(int id, string driverName, double driverRating)
        : driverID(id), name(driverName), rating(driverRating) {
    }

    void addRide(Ride* ride) {
        assignedRides.push_back(ride);
    }

    void getDriverInfo() {
        cout << "Driver ID: " << driverID << ", Name: " << name << ", Rating: " << rating << endl;
        cout << "Assigned Rides:" << endl;
        for (auto& ride : assignedRides) {
            ride->rideDetails();
        }
    }
};

// Rider class
class Rider {
private:
    int riderID;
    string name;
    vector<Ride*> requestedRides;

public:
    Rider(int id, string riderName) : riderID(id), name(riderName) {}

    void requestRide(Ride* ride) {
        requestedRides.push_back(ride);
    }

    void viewRides() {
        cout << "Rider ID: " << riderID << ", Name: " << name << endl;
        cout << "Ride History:" << endl;
        for (auto& ride : requestedRides) {
            ride->rideDetails();
        }
    }
};

// Sample usage
int main() {
    StandardRide* ride1 = new StandardRide(101, "Home", "Mall", 10);
    PremiumRide* ride2 = new PremiumRide(102, "Office", "Airport", 15);

    Driver driver(1, "Alice", 4.9);
    Rider rider(1, "Bob");

    driver.addRide(ride1);
    driver.addRide(ride2);

    rider.requestRide(ride1);
    rider.requestRide(ride2);

    cout << "\nDriver Info:\n";
    driver.getDriverInfo();

    cout << "\nRider Info:\n";
    rider.viewRides();

    // Demonstrating polymorphism
    cout << "\nPolymorphic Ride List:\n";
    vector<Ride*> rideList = { ride1, ride2 };
    for (auto& ride : rideList) {
        ride->rideDetails();
    }

    delete ride1;
    delete ride2;
    return 0;
}
 