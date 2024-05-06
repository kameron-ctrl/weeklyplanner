#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string mealPlan1_b, mealPlan1_l, mealPlan1_d, mealPlan1_s;
    string mealPlan2_b, mealPlan2_l, mealPlan2_d, mealPlan2_s;
    string mealPlan3_b, mealPlan3_l, mealPlan3_d, mealPlan3_s;
    string mealPlan4_b, mealPlan4_l, mealPlan4_d, mealPlan4_s;
    string mealPlan5_b, mealPlan5_l, mealPlan5_d, mealPlan5_s;
    string mealPlan6_b, mealPlan6_l, mealPlan6_d, mealPlan6_s;
    string mealPlan7_b, mealPlan7_l, mealPlan7_d, mealPlan7_s;

    int choice;

    do {
        cout << "1. Input meal preferences for each day of the week." << endl;
        cout << "2. Generate a meal plan." << endl;
        cout << "3. Save meal plan to file." << endl;
        cout << "4. Load meal plan from file." << endl;
        cout << "5. Exit program." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character

        switch (choice) {
            case 1: {
                cout << "Input meal preferences for each day of the week:" << endl;
                cout << "Day 1:" << endl;
                cout << "Breakfast: ";
                getline(cin, mealPlan1_b);
                cout << "Lunch: ";
                getline(cin, mealPlan1_l);
                cout << "Dinner: ";
                getline(cin, mealPlan1_d);
                cout << "Snack: ";
                getline(cin, mealPlan1_s);
                
                cout << "Day 2:" << endl;
                cout << "Breakfast: ";
                getline(cin, mealPlan2_b);
                cout << "Lunch: ";
                getline(cin, mealPlan2_l);
                cout << "Dinner: ";
                getline(cin, mealPlan2_d);
                cout << "Snack: ";
                getline(cin, mealPlan2_s);

                // Similar lines for days 3 to 7

                break;
            }
            case 2: {
                cout << "Generated meal plan:" << endl;
                cout << "Day 1:" << endl;
                cout << "Breakfast: " << mealPlan1_b << endl;
                cout << "Lunch: " << mealPlan1_l << endl;
                cout << "Dinner: " << mealPlan1_d << endl;
                cout << "Snack: " << mealPlan1_s << endl;
                
                cout << "Day 2:" << endl;
                cout << "Breakfast: " << mealPlan2_b << endl;
                cout << "Lunch: " << mealPlan2_l << endl;
                cout << "Dinner: " << mealPlan2_d << endl;
                cout << "Snack: " << mealPlan2_s << endl;

                // Similar lines for days 3 to 7

                break;
            }
            case 3: {
                ofstream file("meal_plan.txt");
                if (file.is_open()) {
                    file << "Day 1:" << endl;
                    file << "Breakfast: " << mealPlan1_b << endl;
                    file << "Lunch: " << mealPlan1_l << endl;
                    file << "Dinner: " << mealPlan1_d << endl;
                    file << "Snack: " << mealPlan1_s << endl;
                    
                    // Similar lines for days 2 to 7

                    cout << "Meal plan saved to file successfully." << endl;
                    file.close();
                } else {
                    cout << "Unable to open file for saving." << endl;
                }
                break;
            }
            case 4: {
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
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
