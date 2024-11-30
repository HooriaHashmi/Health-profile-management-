This is my second attempt at the haelth profile management system 
i am building this system from stratch and i have encountered many obstacles as well as eye-opening revelations 
i will highlight both sides of the coin and hope that i make progess

Health_project_1.cpp
Extra Features
Comprehensive Data Attributes:
The class captures multiple vital statistics: name, weight, height, temperature, and sugar_level. This broad data representation allows for a more holistic view of a patient's health.
Weekly Record Tracking: The inclusion of a vector<string> weeklyRecord allows for the storage of health data over time, enabling users to track changes and trends in their health metrics.
Constructor with Default Parameters:
The constructor allows for optional parameters (temperature and sugar_level), making it flexible for users who may not have all data at the time of profile creation.
Encapsulation:
The use of protected attributes with public getter and setter methods promotes encapsulation. This is a good practice in object-oriented programming, ensuring that the internal state of the object is protected.
Health Calculations: Methods like calculate_BMI, bmi_category, temperature_status, and Sugar_status provide functionality to derive meaningful health metrics from the stored data, 
which can help users understand their health status better.
Profile Display:
The display_Profile method allows for easy visualization of the health profile, which is crucial for users to quickly assess their health information.
Data Storage and Retrieval:
The presence of methods for storing and displaying weekly records suggests that the class can be used for ongoing health monitoring, which is beneficial for both patients and healthcare providers.
Suggestions for Improvement
Implement All Methods:
Ensure that all declared methods in the header file are implemented in the corresponding .cpp file. This includes the logic for calculations and record management.
Input Validation:
Implement validation in the setter methods to ensure that only valid values are accepted (e.g., non-negative values for weight and height). This can prevent the creation of invalid health profiles.

Improvements I saw
1. Better implementation of inheritance
2. Comprehensive use of getters and setters
3. Proper use of constructors
4. Deliberate use of comments
5. use of headers guards

Difficulties faced
1. Problem linking files
2. Function Declaration/Definition Mismatch
3. class redefinition
4. Private Member Access
