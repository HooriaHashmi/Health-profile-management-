#include "health_project_7.cpp"
#include "health_project_5.cpp"


int main() {

    HealthProfileManager manager;
    int choice;

    do {
        cout << "\nMenu:\n"
             << "1. Add Profile\n"
             << "2. View Profile\n"
             << "3. Delete Profile\n"
             << "4. Display All Profiles\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        string name;
        double weight, height, temperature, sugar_level;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter weight (kg): ";
                cin >> weight;
                cout << "Enter height (m): ";
                cin >> height;
                cout << "Enter body temperature (°C): ";
                cin >> temperature;
                cout << "Enter blood sugar level (mg/dL): ";
                cin >> sugar_level;
                manager.addProfile(HealthProfile(name, weight, height, temperature, sugar_level));
                break; //this adds the profile to the manager 

            case 2:
                cout << "Enter name to view: ";
                cin >> name;
                manager.viewProfile(name);
                break; //this views the profile with the given name

            case 3:
                cout << "Enter name to delete: ";
                cin >> name;
                manager.deleteProfile(name);
                break; // this deletes the profile with the given name

            case 4:
                manager.displayAllProfiles();
                break; // this displays all profiles

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
