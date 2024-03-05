#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string mealOptions[7][4];

    while (true) {
        int choice;
        cout << "Welcome to the Weekly Meal Planner!\n";
        cout << "1. Add meal option\n";
        cout << "2. Generate meal plan\n";
        cout << "3. Save meal plan to file\n";
        cout << "4. Load meal plan from file\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) { 
            int dayIndex;
            cout << "Enter day number (1-7): ";
            cin >> dayIndex;
            if (dayIndex >= 1 && dayIndex <= 7) {
                cout << "Enter Breakfast option for day " << dayIndex << ": ";
                cin >> mealOptions[dayIndex - 1][0];
                cout << "Enter Lunch option for day " << dayIndex << ": ";
                cin >> mealOptions[dayIndex - 1][1];
                cout << "Enter Dinner option for day " << dayIndex << ": ";
                cin >> mealOptions[dayIndex - 1][2];
                cout << "Enter Snack option for day " << dayIndex << ": ";
                cin >> mealOptions[dayIndex - 1][3];
            } else {
                cout << "Invalid day number. Please enter a number between 1 and 7.\n";
            }
        } else if (choice == 2) { 
            cout << "Meal Plan:\n";
            for (int i = 0; i < 7; ++i) {
                cout << "Day " << i + 1 << ":\n";
                cout << "Breakfast: " << mealOptions[i][0] << "\n";
                cout << "Lunch: " << mealOptions[i][1] << "\n";
                cout << "Dinner: " << mealOptions[i][2] << "\n";
                cout << "Snack: " << mealOptions[i][3] << "\n";
            }
        } else if (choice == 3) { 
            ofstream file("meal_plan.txt");
            if (file.is_open()) {
                for (int i = 0; i < 7; ++i) {
                    file << "Day " << i + 1 << ":\n";
                    file << "Breakfast: " << mealOptions[i][0] << "\n";
                    file << "Lunch: " << mealOptions[i][1] << "\n";
                    file << "Dinner: " << mealOptions[i][2] << "\n";
                    file << "Snack: " << mealOptions[i][3] << "\n";
                }
                file.close();
                cout << "Meal plan saved to meal_plan.txt\n";
            } else {
                cout << "Unable to open file meal_plan.txt\n";
            }
        } else if (choice == 4) { 
            ifstream file("meal_plan.txt");
            if (file.is_open()) {
                string line;
                int dayIndex = 0;
                while (getline(file, line)) {
                    if (line.find("Day") != string::npos) {
                        dayIndex = stoi(line.substr(line.find(" ") + 1));
                    } else {
                        size_t pos = line.find(": ");
                        if (pos != string::npos) {
                            string mealType = line.substr(0, pos);
                            string mealOption = line.substr(pos + 2);
                            mealOptions[dayIndex - 1][mealType == "Breakfast" ? 0 : (mealType == "Lunch" ? 1 : (mealType == "Dinner" ? 2 : 3))] = mealOption;
                            dayIndex++; 
                        }
                    }
                }
                file.close();
                cout << "Meal plan loaded from meal_plan.txt\n";
            } else {
                cout << "Unable to open file meal_plan.txt\n";
            }
        } else if (choice == 5) { 
            cout << "Exiting...\n";
            return 0;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
