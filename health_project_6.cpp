#include "health_project_7.cpp"
#include <iostream>
using namespace std;

void HealthProfileManager::add_profile(const Health_profile& profile) {
    profiles.push_back(profile);
}

void HealthProfileManager::view_profile(const string& name) const {
    for (const auto& profile : profiles) {
        if (profile.getName() == name) {
            profile.display_profile();
            return;
        }
    }
    cout << "Profile not found.\n";
}

void HealthProfileManager::delete_profile(const string& name) {
    profiles.erase(remove_if(profiles.begin(), profiles.end(),
                             [&name](const Health_profile& p) { return p.getName() == name; }),
                   profiles.end());
    cout << "Profile deleted.\n";
}

void HealthProfileManager::display_all_profiles() const {
    for (const auto& profile : profiles) {
        profile.display_profile();
    }
}
