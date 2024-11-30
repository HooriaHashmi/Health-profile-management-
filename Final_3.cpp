#ifndef HEALTHPROFILEMANAGER_H
#define HEALTHPROFILEMANAGER_H

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "Final_2.cpp"

class Health_Profile_Manager {
private:
    vector<Health_Profile> profiles;

public:
    // Menu
    void menu() {
        int choice;
        do {
            cout << "\n--- Health Profile Manager ---\n";
            cout << "1. Create Profile\n";
            cout << "2. View Profile(s)\n";
            cout << "3. Update Profile\n";
            cout << "4. Save Profiles to File\n";
            cout << "5. Load Profiles from File\n";
            cout << "6. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            switch (choice) {
                case 1:
                    createProfile();
                    break;
                case 2:
                    viewProfiles();
                    break;
                case 3:
                    updateProfile();
                    break;
                case 4:
                    saveToFile();
                    break;
                case 5:
                    loadFromFile();
                    break;
                case 6:
                    cout << "Exiting program...\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 6);
    }

    // Create a Profile
    void createProfile() {
        string name;
        double weight, height, temperature, sugar;
        int systolic, diastolic;

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter weight (kg): ";
        while (!(cin >> weight) || weight <= 0) {
            cout << "Invalid input. Enter a positive weight (kg): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter height (m): ";
        while (!(cin >> height) || height <= 0) {
            cout << "Invalid input. Enter a positive height (m): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter body temperature (°C): ";
        while (!(cin >> temperature) || temperature <= 0) {
            cout << "Invalid input. Enter a positive body temperature (°C): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter blood sugar level (mg/dL): ";
        while (!(cin >> sugar) || sugar < 0) {
            cout << "Invalid input. Enter a valid blood sugar level (mg/dL): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter systolic blood pressure: ";
        while (!(cin >> systolic) || systolic <= 0) {
            cout << "Invalid input. Enter a valid systolic BP: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter diastolic blood pressure: ";
        while (!(cin >> diastolic) || diastolic <= 0) {
            cout << "Invalid input. Enter a valid diastolic BP: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        profiles.emplace_back(name, weight, height, temperature, sugar, systolic, diastolic);
        cout << "Profile created successfully!\n";
    }

    // View Profiles
    void viewProfiles() {
        string name;
        cout << "Enter the name(s) of profiles to view (comma-separated for multiple): ";
        cin.ignore();
        getline(cin, name);

        vector<string> selectedProfiles;
        stringstream ss(name);
        string token;

        while (getline(ss, token, ',')) {
            selectedProfiles.push_back(token);
        }

        for (const auto& profileName : selectedProfiles) {
            auto it = find_if(profiles.begin(), profiles.end(),
                              [&](const Health_Profile& profile) { return profile.getName() == profileName; });

            if (it != profiles.end()) {
                it->displayProfile();
            } else {
                cout << "Profile with name '" << profileName <<"Profile with name '" << profileName << "' not found.\n";
            }
        }
    }

    // Update a Profile
    void updateProfile() {
        string name;
        cout << "Enter the name of the profile to update: ";
        cin >> name;

        auto it = find_if(profiles.begin(), profiles.end(),
                          [&](const Health_Profile& profile) { return profile.getName() == name; });

        if (it != profiles.end()) {
            double weight, height, temperature, sugar;
            int systolic, diastolic;

            cout << "Enter new weight (kg): ";
            while (!(cin >> weight) || weight <= 0) {
                cout << "Invalid input. Enter a positive weight (kg): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter new height (m): ";
            while (!(cin >> height) || height <= 0) {
                cout << "Invalid input. Enter a positive height (m): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter new body temperature (°C): ";
            while (!(cin >> temperature) || temperature <= 0) {
                cout << "Invalid input. Enter a positive body temperature (°C): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter new blood sugar level (mg/dL): ";
            while (!(cin >> sugar) || sugar < 0) {
                cout << "Invalid input. Enter a valid blood sugar level (mg/dL): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter new systolic blood pressure: ";
            while (!(cin >> systolic) || systolic <= 0) {
                cout << "Invalid input. Enter a valid systolic BP: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter new diastolic blood pressure: ";
            while (!(cin >> diastolic) || diastolic <= 0) {
                cout << "Invalid input. Enter a valid diastolic BP: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            it->setWeight(weight);
            it->setHeight(height);
            it->setBodyTemperature(temperature);
            it->setBloodSugarLevel(sugar);
            it->setBloodPressure(systolic, diastolic);

            cout << "Profile updated successfully!\n";
        } else {
            cout << "Profile with name '" << name << "' not found.\n";
        }
    }

    // Save Profiles to File
    void saveToFile() {
        ofstream file("health_profiles.txt");
        if (!file) {
            cerr << "Error opening file for saving.\n";
            return;
        }

        for (const auto& profile : profiles) {
            file << "Name: " << profile.getName() << "\n";
            file << "Weight: " << profile.getWeight() << "\n";
            file << "Height: " << profile.getHeight() << "\n";
            file << "Body Temperature: " << profile.getBodyTemperature() << "\n";
            file << "Blood Sugar Level: " << profile.getBloodSugarLevel() << "\n";
            file << "Blood Pressure: " << profile.getSystolicBP() << "/" << profile.getDiastolicBP() << "\n";
            file << "BMI: " << profile.calculateBMI() << " (" << profile.bmiCategory() << ")\n";
            file << "---------------------------------\n";
        }

        cout << "Profiles saved to 'health_profiles.txt'.\n";
    }

    // Load Profiles from File
    void loadFromFile() {
        ifstream file("health_profiles.txt");
        if (!file) {
            cerr << "Error opening file for loading.\n";
            return;
        }

        profiles.clear();

        string name, line;
        double weight, height, temperature, sugar;
        int systolic, diastolic;

        while (getline(file, line)) {
            if (line.find("Name: ") == 0) {
                name = line.substr(6);
                getline(file, line);
                weight = stod(line.substr(8));
                getline(file, line);
                height = stod(line.substr(8));
                getline(file, line);
                temperature = stod(line.substr(18));
                getline(file, line);
                sugar = stod(line.substr(18));
                getline(file, line);
                sscanf(line.c_str(), "Blood Pressure: %d/%d", &systolic, &diastolic);

                profiles.emplace_back(name, weight, height, temperature, sugar, systolic, diastolic);
                getline(file, line); // Skip separator line
            }
        }

        cout << "Profiles loaded from 'health_profiles.txt'.\n";
    }
};

#endif

