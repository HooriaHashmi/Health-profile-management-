#ifndef EXTENDEDHEALTHPROFILE_H
#define EXTENDEDHEALTHPROFILE_H//these are the extended health profile fields

#include "health_project_2.cpp" //making sure to include the previous file as inheritance will be implemented here

class ExtendedHealthProfile : public Health_profile {
public: //use of inheritance to inherit the properties of the parent class which is health profile
        //here we are adding the extended health profile fields
        //The constructor is used to initialize the object's attributes

        
    ExtendedHealthProfile(string name, double weight, double height, double body_temperature = 0.0, double blood_sugar_level = 0.0)
        : Health_profile(name, weight, height, body_temperature, blood_sugar_level) {}

    void advanced_analysis();
};

#endif
