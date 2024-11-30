#ifndef HEALTHPROFILEMANAGER_H
#define HEALTHPROFILEMANAGER_H

#include "health_project_4.cpp"
#include <vector>
using namespace std;

class HealthProfileManager {
private:
    vector<HealthProfile> profiles;

public:
    void addProfile(const HealthProfile& profile);
    void viewProfile(const string& name) const;
    void deleteProfile(const string& name);
    void displayAllProfiles() const;
};

#endif
