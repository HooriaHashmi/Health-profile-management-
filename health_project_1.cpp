//This class only takes the patient's vital
#ifndef HEALTHPROFILE_H
#define HEALTHPROFILE_H// Header guards ensuring there is no repetition of files

#include <string>//Directives
#include <vector>
using namespace std;

class HealthProfile { //Class creation
protected: //Declared as protected to be accessed by derived classes
    string name;
    double weight;
    double height;
    double temperature;
    double sugar_level; //Declaration
    vector<string> weeklyRecord;

public: //Declared as public to be accessed by all classes
    HealthProfile(string name, double weight, double height, double temperature = 0.0, double sugar_level = 0.0);

    void set_weight //void returning functions
    (double w); //setting the credentials
    void set_height
    (double h);
    void set_temperature
    (double temp);
    void set_Sugar_level
    (double sugar_level);

    string get_Name() const; //value returning functions
    double get_Weight() const; //getting the credentials
    double get_Height() const;
    double get_Temperature() const;
    double get_Sugar_Level() const;

    double calculate_BMI() const; //performing calculations
    string bmi_category() const;
    string temperature_status() const;
    string Sugar_status() const;
    void display_Profile() const;
    void store_Record();
    void display_Weekly_Records() const;
};

#endif
