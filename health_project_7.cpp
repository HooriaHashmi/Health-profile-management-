#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// HealthProfile class definition
class HealthProfile {
private:
    string name;
    double weight;
    double height;
    double temperature;
    double sugar_level;

public:
    // Constructor
    Health_profile(const string& name, double weight, double height, double temperature, double sugar_level)
        : name(name), weight(weight), height(height), temperature(temperature), sugar_level(sugar_level) {}

    // Getter for name
    string get_Name() const {
        return name;
    }

    // Display profile information
    void display_Profile() const {
        cout << "Name: " << name << "\n"
             << "Weight: " << weight << " kg\n"
             << "Height: " << height << " m\n"
             << "Temperature: " << temperature << " °C\n"
             << "Sugar Level: " << sugar_level << " mg/dL\n";
    }
};

// HealthProfileManager class definition
class HealthProfileManager {
private:
    vector<Health_profile> profiles;

public:
    void add_profile(const Health_profile& profile) {
        profiles.push_back(profile);
    }

    void view_profile(const string& name) const {
        for (const auto& profile : profiles) {
            if (profile.get_Name() == name) {
                profile.display_Profile();
                return;
            }
        }
        cout << "Profile not found.\n";
    }

    void delete_profile(const string& name) {
        auto originalSize = profiles.size();
        profiles.erase(remove_if(profiles.begin(), profiles.end(),
                                  [&name](const Health_profile& p) { return p.get_Name() == name; }),
                       profiles.end());
        if (profiles.size() < originalSize) {
            cout << "Profile deleted.\n";
        } else {
            cout << "Profile not found for deletion.\n";
        }
    }

    void display_all_profiles() const {
        if (profiles.empty()) {
            cout << "No profiles available.\n";
            return;
        }
        for (const auto& profile : profiles) {
            profile.display_Profile();
            cout << "-------------------------\n"; // Separator for readability
        }
    }
};

// Example usage
int main() {
    HealthProfileManager manager;

    // Adding profiles
    manager.add_profile(Health_profile("John Doe", 70.0, 1.75, 37.0, 90.0));
    manager.add_profile(Health_profile("Jane Smith", 65.0, 1.65, 36.5, 85.0));

    // Display all profiles
    cout << "All Profiles:\n";
    manager.display_all_profiles();

    // View a specific profile
    cout << "\nViewing Profile for John Doe:\n";
    manager.view_profile("John Doe");

    // Delete a profile
    cout << "\nDeleting Profile for Jane Smith:\n";
    manager.delete_profile("Jane Smith");

    // Display all profiles again
    cout << "\nAll Profiles after deletion:\n";
    manager.display_all_profiles();

    return 0;
}
