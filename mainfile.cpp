#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
using namespace std;




// Assuming these classes are defined properly
#include "extended_classhealthprofile.cpp" // Use header files instead of .cpp
#include "classhealthprofile.cpp"


class Health_manager {
private:
    vector<Extended_Health_Profile> profiles; // Vector to hold health profiles

public:
    void createProfile(string name, double weight, double height, double body_temperature, double blood_sugar) {
        if (weight <= 0) {
            cout << "Invalid weight. Must be greater than 0.\n";
            return;
        }
        if (height <= 0) {
            cout << "Invalid height. Must be greater than 0.\n";
            return;
        }
        if (body_temperature < 35.0 || body_temperature > 42.0) { 
            cout << "Invalid body temperature. Must be between 35.0 and 42.0 °C.\n";
            return;
        }
        if (blood_sugar < 0) {
            cout << "Invalid blood sugar level. Must be non-negative.\n";
            return;
        }
        // If all validations pass, create the profile
        profiles.emplace_back(name, weight, height, body_temperature, blood_sugar); // Assuming constructor exists
        cout << "Profile for " << name << " created successfully.\n";
    }

    void readfile(string name) {
        bool profileFound = false; // Flag to check if the profile exists

        for (const auto& p : profiles) {
            if (p.get_name() == name) {
                profileFound = true; 
                p.displayfile(); 
                
                cout << "BMI: " << p.BMI() << " (" << p.bmi_category() << ")\n";
                cout << "Body Temperature Status: " << p.temperature_status() << "\n";
                cout << "Blood Sugar Status: " << p.blood_sugar_status() << "\n";
                cout << p.generate_feedback() << endl;
                break; // Exit the loop once the profile is found
            }
        }

        // If profile is not found, inform the user
        if (!profileFound) {
            cout << "Profile with the name '" << name << "' was not found.\n";
            cout << "Please check the name and try again.\n";
        }
    }

    void updatefile(string name) {
        // Check if the profile exists
        for (auto& p : profiles) {
            if (p.get_name() == name) {
                double new_weight, new_height, new_body_temperature, new_blood_sugar;

                // Get new values from the user with validation
                cout << "Updating profile for " << name << ".\n";

                // Update weight
                cout << "Enter new weight (kg): ";
                cin >> new_weight;
                while (new_weight <= 0) {
                    cout << "Invalid weight. Please enter a value greater than 0: ";
                    cin >> new_weight;
                }
                p.set_weight(new_weight);

                // Update height
                cout << "Enter new height (m): ";
                cin >> new_height;
                while (new_height <= 0) {
                    cout << "Invalid height. Please enter a value greater than 0: ";
                    cin >> new_height;
                }
                p.set_height(new_height);

                // Update body temperature
                cout << "Enter new body temperature (°C): ";
                cin >> new_body_temperature;
                while (new_body_temperature < 35.0 || new_body_temperature > 42.0) {
                    cout << "Invalid body temperature. Please enter a value between 35.0 and 42.0: ";
                    cin >> new_body_temperature;
                }
                p.set_body_temperature(new_body_temperature);

                // Update blood sugar level
                cout << "Enter new blood sugar level (mg/dL): ";
                cin >> new_blood_sugar;
                while (new_blood_sugar < 0) {
                    cout << "Invalid blood sugar level. Please enter a non-negative value: ";
                    cin >> new_blood_sugar;
                }
                p.set_blood_sugar(new_blood_sugar);

                // cout << "Profile updated successfully.\n";
                // p.store_record(); // Optional: Store the updated record
                // return;
            }
        }
        cout << "Profile with the name '" << name << "' was not found.\n";
    }
    
    void deletefile(string name) {
        for (auto it = profiles.begin(); it != profiles.end(); ++it) {
            if (it->get_name() == name) {
                profiles.erase(it);                cout << "Profile deleted.\n";
                return;
            }
        }
        cout << "Profile not found.\n";
    }

    void save_to_file() {
        ofstream file("health_profiles.txt");
        if (!file) {
            cout << "Error opening file for saving.\n";
            return;
        }
        for (const auto& profile : profiles) {
            file << profile.get_name() << " " 
                 << profile.get_weight() << " " 
                 << profile.get_height() << " " 
                 << profile.get_body_temperature() << " "
                 << profile.get_blood_sugar() << " " 
                 << profile.BMI() << " " 
                 << profile.bmi_category() << " " 
                 << profile.temperature_status() << " "
                 << profile.blood_sugar_status() << "\n";
        }
        cout << "Profiles saved to file.\n";
    }

    void load_from_file() {
        ifstream file("health_profiles.txt");
        if (!file) {
            cout << "Error opening file for loading.\n";
            return;
        }
        string name;
        double weight, height, bodyTemperature, bloodSugarLevel;
        profiles.clear(); // Clear existing profiles before loading

        while (file >> name >> weight >> height >> bodyTemperature >> bloodSugarLevel) {
            profiles.emplace_back(name, weight, height, bodyTemperature, bloodSugarLevel);
        }
        cout << "Profiles loaded from file.\n";
    }

    void displayAllProfiles() const {
        if (profiles.empty()) {
            cout << "No profiles available.\n";
            return;
        }
        for (const auto& profile : profiles) {
            profile.displayProfile();
        }
    }

    void menu() {
        int choice;
        do {
            cout << "\nHealth Profile Manager\n";
            cout << "1. Create Profile\n";
            cout << "2. View Profile\n";
            cout << "3. Update Profile\n";
            cout << "4. Delete Profile\n";
            cout << "5. Save Profiles to File\n";
            cout << "6. Load Profiles from File\n";
            cout << "7. Display All Profiles\n";
            cout << "8. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between 1 and 8.\n";
                continue;
            }

            string name;
            switch (choice) {
                case 1:
                    {
                        string name;
                        double weight, height, body_temperature, blood_sugar;
                        cout << "Enter Name: ";
                        cin >> name;
                        cout << "Enter Weight (kg): ";
                        cin >> weight;
                        cout << "Enter Height (m): ";
                        cin >> height;
                        cout << "Enter Body Temperature (°C): ";
                        cin >> body_temperature;
                        cout << "Enter Blood Sugar Level (mg/dL): ";
                        cin >> blood_sugar;
                        createProfile(name, weight, height, body_temperature, blood_sugar);
                    }
                    break;
                case 2:
                    cout << "Enter Name of the Profile to View: ";
                    cin >> name;
                    readfile(name);
                    break;
                case 3:
                    cout << "Enter Name of the Profile to Update: ";
                    cin >> name;
                    updatefile(name);
                    break;
                case 4:
                    cout << "Enter Name of the Profile to Delete: ";
                    cin >> name;
                    deletefile(name);
                    break;
                case 5:
                    save_to_file();
                    break;
                case 6:
                    load_from_file();
                    break;
                case 7:
                    displayAllProfiles();
                    break;
                case 8:
                    cout << "Exiting the program.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 8);
    }
};

int main() {
    Health_manager manager;
    manager.menu();
    return 0;
}