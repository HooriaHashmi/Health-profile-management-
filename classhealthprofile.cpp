#include <iostream>
#include <string>
#include <cmath>
using namespace std;



class Profile {
public:
    // Constructor to initialize the profile with a name
    Profile(const std::string &name) : name(name) {}

    // Method to display the profile
    void displayProfile() {
        std::cout << "Profile Name: " << name << std::endl;
    }

private:
    std::string name; // Member variable to hold the name
};

int main() {
    // Create an instance of Profile
    Profile profile("John Doe");

    // Call the displayProfile method
    profile.displayProfile();

    return 0;
}

class Health_Information { //Class to store the health information
protected:
    string name; // Variable declarations
    double weight;
    double height; 
    double body_temperature;
    double blood_sugar;
   
                            
public:
    Health_Information(string name, double weight, double height, double body_temperature = 0.0, double blood_sugar = 0.0) // Use of constructors
        : name(name), weight(weight), height(height), body_temperature(body_temperature), blood_sugar(blood_sugar) {}

    void set_weight(double w) { 
        weight = w;
    }

    void set_height(double h) { 
        height = h;
    }

    void set_body_temperature(double temp) {
         body_temperature = temp;
    }

    void set_blood_sugar(double level) {
         blood_sugar = level;
    }

    
    string get_name() {
         return name; 
    }
    double get_weight() { 
        return weight; 
    }
    double get_height() { 
        return height; 
    }
    double get_body_temperature() { 
        return body_temperature;
    }
    double get_blood_sugar() { 
        return blood_sugar; 
    }
    double BMI() {
        return weight / pow(height, 2);
    }
};