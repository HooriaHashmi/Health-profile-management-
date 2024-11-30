#include "health_project_7.cpp"
#include <iostream>
using namespace std;

void HealthProfileManager::addProfile(const HealthProfile& profile) {
    profiles.push_back(profile);
}

void HealthProfileManager::viewProfile(const string& name) const {
    for (const auto& profile : profiles) {
        if (profile.getName() == name) {
            profile.displayProfile();
            return;
        }
    }
    cout << "Profile not found.\n";
}

void HealthProfileManager::deleteProfile(const string& name) {
    profiles.erase(remove_if(profiles.begin(), profiles.end(),
                             [&name](const HealthProfile& p) { return p.getName() == name; }),
                   profiles.end());
    cout << "Profile deleted.\n";
}

void HealthProfileManager::displayAllProfiles() const {
    for (const auto& profile : profiles) {
        profile.displayProfile();
    }
}
