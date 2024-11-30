#ifndef HEALTHPROFILE_H
#define HEALTHPROFILE_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Health_Profile {
protected:
    string name;
    double weight;
    double height;
    double bodyTemperature;
    double bloodSugarLevel;
    int systolicBP;
    int diastolicBP;

public:
    //constructors
    Health_Profile(string name, double weight, double height, double bodyTemperature = 0.0, 
                  double bloodSugarLevel = 0.0, int systolicBP = 120, int diastolicBP = 80)
        : name(name), weight(weight), height(height), bodyTemperature(bodyTemperature),
          bloodSugarLevel(bloodSugarLevel), systolicBP(systolicBP), diastolicBP(diastolicBP) {}

    // Setters
    void setWeight(double w) { 
        weight = w;
         }
    void setHeight(double h) { 
        height = h;
         }
    void setBodyTemperature(double temp) { 
        bodyTemperature = temp;
         }
    void setBloodSugarLevel(double sugar) { 
        bloodSugarLevel = sugar;
         }
    void setBloodPressure(int sys, int dia) { 
        systolicBP = sys; diastolicBP = dia;
         }

    // Getters
    string getName() const { 
        return name; 
        }
    double getWeight() const { 
        return weight; 
        }
    double getHeight() const { 
        return height; 
        }
    double getBodyTemperature() const { 
        return bodyTemperature; 
        }
    double getBloodSugarLevel() const { 
        return bloodSugarLevel; 
        }
    int getSystolicBP() const { 
        return systolicBP; 
        }
    int getDiastolicBP() const { 
        return diastolicBP; 
        }

    // Calculate BMI
    double calculateBMI() const {
        return weight / (height * height);
    }

    // BMI Category
    string bmiCategory() const {
        double bmi = calculateBMI();
        if (bmi < 18.5) 
        return "Underweight";

        else if (bmi < 24.9) 
        return "Normal weight";

        else if (bmi < 29.9) 
        return "Overweight";

        else return "Obese";
    }

    // Temperature Status
    string temperatureStatus() const {
        if (bodyTemperature < 36.1) 
        return "Low";

        else if (bodyTemperature <= 37.2) 
        return "Normal";

        else return "High";
    }

    // Blood Sugar Status
    string bloodSugarStatus() const {
        if (bloodSugarLevel < 70) 
        return "Low";

        else if (bloodSugarLevel <= 140) 
        return "Normal";

        else return "High";
    }

    // Blood Pressure Status
    string bloodPressureStatus() const {
        if (systolicBP < 120 && diastolicBP < 80) 
        return "Normal";

        else if (systolicBP < 130 && diastolicBP < 80) 
        return "Elevated";

        else if (systolicBP <= 139 || diastolicBP <= 89) 
        return "Hypertension Stage 1";
        
        else return "Hypertension Stage 2";
    }

    // Display Profile
    void displayProfile() const {
        cout << fixed << setprecision(2);
        cout << "---------------------------------\n";
        cout << "Name            : " << name << "\n";
        cout << "Weight          : " << weight << " kg\n";
        cout << "Height          : " << height << " m\n";
        cout << "Body Temperature: " << bodyTemperature << " °C (" << temperatureStatus() << ")\n";
        cout << "Blood Sugar     : " << bloodSugarLevel << " mg/dL (" << bloodSugarStatus() << ")\n";
        cout << "Blood Pressure  : " << systolicBP << "/" << diastolicBP << " (" << bloodPressureStatus() << ")\n";
        cout << "BMI             : " << calculateBMI() << " (" << bmiCategory() << ")\n";
        cout << "---------------------------------\n";
    }
};

#endif
