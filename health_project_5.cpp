#ifndef HEALTHPROFILEMANAGER_H
#define HEALTHPROFILEMANAGER_H

#include "health_project_4.cpp"
#include <vector>
using namespace std;

class HealthProfileManager {
private:
    vector<Health_profile> profiles;

public:
    void add_profile(const Health_profile& profile);
    void view_profile(const string& name) const;
    void delete_profile(const string& name);
    void display_all_profiles() const;
};

#endif
