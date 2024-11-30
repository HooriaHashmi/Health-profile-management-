#include "health_project_3.cpp"
#include <iostream>
using namespace std;

//Another use of inheritance where this time we are using a base class to inherit from which is extendedhealthprofile
void ExtendedHealthProfile::advanced_analysis() {
    cout << "Performing advanced health analysis for " << name << "...\n";
    cout << "Body Mass Index (BMI): " << calculate_BMI() << " (" << bmi_category() << ")\n";
}
