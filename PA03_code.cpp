#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void displayMenuOptions() {
    cout << "1. Input meal preferences for each day of the week." << endl;
    cout << "2. Generate a meal plan." << endl;
    cout << "3. Save meal plan to file." << endl;
    cout << "4. Load meal plan from file." << endl;
    cout << "5. Exit program." << endl;
}

void inputMealPreferences(vector<vector<string> >& mealPlan) {
    cout << "Input meal preferences for each day of the week:" << endl;
    for (int day = 0; day < 7; day++) {
        cout << "Day " << day + 1 << ":" << endl;
        vector<string> meals;
        cout << "Breakfast: ";
        string breakfast;
        getline(cin, breakfast);
        meals.push_back(breakfast);
        cout << "Lunch: ";
        string lunch;
        getline(cin, lunch);
        meals.push_back(lunch);
        cout << "Dinner: ";
        string dinner;
        getline(cin, dinner);
        meals.push_back(dinner);
        cout << "Snack: ";
        string snack;
        getline(cin, snack);
        meals.push_back(snack);
        mealPlan.push_back(meals);
    }
}


void generateMealPlan(const vector<vector<string> >& mealPlan) {
    cout << "Generated meal plan:" << endl;
    for (int day = 0; day < 7; day++) {
        cout << "Day " << day + 1 << ":" << endl;
        cout << "Breakfast: " << mealPlan[day][0] << endl;
        cout << "Lunch: " << mealPlan[day][1] << endl;
        cout << "Dinner: " << mealPlan[day][2] << endl;
        cout << "Snack: " << mealPlan[day][3] << endl;
    }
}


void saveMealPlanToFile(const vector<vector<string> >& mealPlan) {
    ofstream file("meal_plan.txt");
    if (file.is_open()) {
        for (int day = 0; day < 7; day++) {
            file << "Day " << day + 1 << ":" << endl;
            file << "Breakfast: " << mealPlan[day][0] << endl;
            file << "Lunch: " << mealPlan[day][1] << endl;
            file << "Dinner: " << mealPlan[day][2] << endl;
            file << "Snack: " << mealPlan[day][3] << endl;
        }
        cout << "Meal plan saved to file successfully." << endl;
        file.close();
    } else {
        cout << "Unable to open file for saving." << endl;
    }
}


void loadMealPlanFromFile(vector<vector<string> >& mealPlan) {
    ifstream file("meal_plan.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file for loading." << endl;
    }
}

int main() {
    vector<vector<string> > mealPlan;

    int choice;
    do {
        displayMenuOptions();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character
        switch (choice) {
            case 1:
                inputMealPreferences(mealPlan);
                break;
            case 2:
                generateMealPlan(mealPlan);
                break;
            case 3:
                saveMealPlanToFile(mealPlan);
                break;
            case 4:
                loadMealPlanFromFile(mealPlan);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
