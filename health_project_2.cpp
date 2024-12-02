//This file is an extension of the original code which is included here
//It focuses on setting and getting the values of the parameters of the model
//while file one focused on variable declaration for the most part


#include "health_project_1.cpp" //Made sure to include the correct file
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

Health_profile::Health_profile(string name, double weight, double height, double temperature, double sugar_level)
    : name(name), weight(weight), height(height), temperature(temperature), sugar_level(sugar_level) {}

void Health_profile::set_weight(double w) {
     weight = w; 
     }
void Health_profile::set_height(double h) { 
    height = h; 
    }
void Health_profile::set_temperature(double temp) { 
    temperature = temp; 
    }
void Health_profile::set_Sugar_level(double level) { 
    sugar_level = level; 
    }

string Health_profile::get_Name() const {
     return name;
    }
double Health_profile::get_Weight() const { 
    return weight; 
    }
double Health_profile::get_Height() const { 
    return height; 
    }
double Health_profile::get_Temperature() const { 
    return temperature; 
    }
double Health_profile::get_Sugar_Level() const { 
    return sugar_level; 
    }

double Health_profile::calculate_BMI() const {
    return weight / pow(height, 2);
}

//This is also an extension of the original code which is included here 
//which focuses on the calculation of the health status of the patient
//This includes BMI temperature status and sugar level status
string Health_profile::bmi_category() const {
    double bmi = calculate_BMI();
    if (bmi < 18.5) 
    return "Underweight";
    else if (bmi < 24.9)
    return "Normal weight";
    else if (bmi < 29.9) 
    return "Overweight";

    else return "Obese";
}

string Health_profile::temperature_status() const {
    if (temperature < 36.1) 
    return "Low";
    else if (temperature <= 37.2) 
    return "Normal";

    else return "High";
}

string Health_profile::Sugar_status() const {
    if (sugar_level < 70) 
    return "Low";
    else if (sugar_level <= 140) 
    return "Normal";

    else return "High";
}

//This part of the code talks about the main function which is the entry point of the program
//It deals with the creation of an object of the class HealthProfile and the execution of the methods of the class
void Health_profile::display_Profile() const {
    cout << "Name: " << name << "\n"
         << "Weight: " << weight << " kg\n"
         << "Height: " << height << " m\n"
         << "BMI: " << fixed << setprecision(2) << calculate_BMI() << " (" << bmi_category() << ")\n"
         << "Temperature: " << temperature << " °C (" << temperature_status() << ")\n"
         << "Blood Sugar: " << sugar_level << " mg/dL (" << Sugar_status() << ")\n";
}

void Health_profile::store_Record() {
    weeklyRecord.push_back("Weight: " + to_string(weight) + ", BMI: " + bmi_category());
}

void Health_profile::display_Weekly_Records() const {
    for (const string& record : weeklyRecord) {
        cout << record << endl;
    }
}
