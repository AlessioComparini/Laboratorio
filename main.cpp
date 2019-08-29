#include <iostream>
#include "TodoList.h"

using namespace std;

void ClearScreen() {
    int n;
    for (n = 0; n < 10; n++)
        printf("\n\n\n\n\n\n\n\n\n\n");
}

int main() {
    TodoList todoList;
    menu:
    cout << "MAIN MENU" << endl;
    cout << "1- Activity list" << endl;
    cout << "2- Add activity" << endl;
    cout << "3- Remove activity" << endl;
    cout << "4- Exit" << endl;
    int choice;
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case 1:
        subMenu1:
            cin.clear();
            todoList.printAllActivities();
            cout << "What do you want to do?" << endl;
            cout << "1- Modify an activity" << endl;
            cout << "2- Go back" << endl;
            cout << "3- Exit" << endl;
            cin >> choice;
            cin.ignore();
            switch (choice) {
                default:
                    cout << "Digit error, try again." << endl;
                    goto subMenu1;
                case 1: {
                    int activitySel;
                    bool error = false;
                    do {
                        if (error)
                            cout << "Out of range number, try again" << endl;
                        cout << "Number of the activity to modify: ";
                        cin >> activitySel;
                        cout << endl;
                        error = true;
                    } while (activitySel < 0 || activitySel > todoList.getSize());
                    cout << "Activity " << activitySel << "is selected" << endl;
                    cout << "1- Delete it" << endl;
                    cout << "2- Mark as done" << endl;
                    cout << "3- Cancel operation and go back" << endl;
                    subMenu2:
                    cin >> choice;
                    cin.ignore();
                    switch (choice) {
                        default:
                            cout << "Digit error, try again." << endl;
                            goto subMenu2;
                        case 1:
                            todoList.removeActivity(activitySel);
                            cout << "Activity deleted succesfully!" << endl;
                            goto subMenu1;
                        case 2:
                            todoList.setActivityDone(activitySel);
                            cout << "Good job!" << endl;
                            goto subMenu1;
                        case 3:
                            goto subMenu1;
                    }
                }
                case 2:
                    goto menu;
                case 3:
                    return 0;

            }
        case 2 : {
            string title;
            string description;
            int day = 0;
            int month = 0;
            bool error = false;
            cout << "Title of the activity: " << endl;
            getline(cin, title);
            cout << "Description of the activity: " << endl;
            getline(cin, description);
            do {
                if (error)
                    cout << "Out of range number" << endl;
                error = false;
                cout << "Month of expiration: " << endl;
                do {
                    if (error) {
                        cin.clear();
                        cin.ignore();
                        cout << "Bad input, try again." << endl;
                    }
                    cin >> month;
                    error = true;
                } while (cin.fail());
                cin.ignore();
                error = true;
            } while (month > 12 || month < 1);
            error = false;
            do {
                if (error)
                    cout << "Out of range number" << endl;
                cout << "Day of expiration: " << endl;
                cin >> day;
                cin.ignore();
                error = true;
            } while (day > 31 || day < 1);
            Date expiration(day, month);
            Activity a(description, title, expiration, false);
            todoList.addActivity(a);
        }
            goto menu;
        case 3: {
            todoList.printAllActivities();
            cout << "Number of the activity you want to delete: ";
            int deleteActivity;
            cin >> deleteActivity;
            cout << endl;
            if (deleteActivity <= 0 || deleteActivity > todoList.getSize())
                cout << "Out of range number" << endl;
            else {
                todoList.removeActivity(deleteActivity);
                cout << "Activity deleted succesfully" << endl;
            }
        }
            goto menu;
        case 4:
            return 0;
        default:
            cout << "Digit error, try again." << endl;
            goto menu;
    }


}