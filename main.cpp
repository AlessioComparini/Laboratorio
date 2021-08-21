#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "TodoList.h"
#include <string.h>
#include <fstream>

using namespace std;

int main() {
    TodoList todoList;
    int choice;
    cout << "\nImport file? (1=si/0=no)" << endl;
    cin >> choice;
    if (choice){  //import from txt file
        FILE *filePTR;
        int countRiga = 0;
        char riga_del_file[50];
        char next[10];
        filePTR = fopen("C:\\Users\\aleal\\Documents\\LaboratorioDiProgrammazione\\TodoListImport.txt","r");
        if (filePTR){
            strcpy(next, "NEXT\n");
            char titolo[50], descrizione[50];
            int giorno, mese;
            bool done=false;
            while (!feof(filePTR)){
                fgets(riga_del_file,50,filePTR);
                printf(riga_del_file);
                if (strcmp(next,riga_del_file)==0){
                    countRiga=0;
                }
                if(countRiga==1)
                    strcpy(titolo,riga_del_file);
                if(countRiga==2)
                    strcpy(descrizione,riga_del_file);
                if(countRiga==3)
                    giorno=atoi(riga_del_file);
                if(countRiga==4)
                    mese=atoi(riga_del_file);
                if(countRiga==5){
                    char isTrue[5];
                    strcpy (isTrue, "true\n");
                    if (strcmp(isTrue,riga_del_file)==0){
                        done=true;
                    }
                    todoList.addActivity(Activity (titolo,descrizione,Date(giorno,mese),done));
                }
                countRiga++;
            }
            fclose(filePTR);
        }
        else {
            cout<< "Errore file"<< endl;
        }

    }
    menu:
    cout << "\nMAIN MENU" << endl;
    cout << "1- Activity list" << endl;
    cout << "2- Add activity" << endl;
    cout << "3- Remove activity" << endl;
    cout << "4- Export to file" << endl;
    cout << "5- Exit" << endl;
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case 1:
            subMenu1:
                cin.clear();
                todoList.printAllActivities();
                cout << "\nWhat do you want to do?" << endl;
                cout << "1- Modify an activity" << endl;
                cout << "2- Go back" << endl;
                cout << "3- Exit" << endl;
                cin >> choice;
                cin.ignore();
                switch (choice) {
                    default:
                        cout << "\nDigit error, try again." << endl;
                        goto subMenu1;
                        case 1: {
                            int activitySel;
                            bool error = false;
                            do {
                                if (error)
                                    cout << "\nOut of range number, try again" << endl;
                                cout << "Number of the activity to modify (type '0' to cancel): ";
                                cin >> activitySel;
                                if (!activitySel)
                                    goto subMenu1;
                                cout << endl;
                                error = true;
                            } while (activitySel < 1 || activitySel > todoList.getSize());
                            cout << "Activity " << activitySel << "is selected" << endl;
                            cout << "1- Delete it" << endl;
                            cout << "2- Mark as done" << endl;
                            cout << "3- Cancel operation and go back" << endl;
                            subMenu2:
                            cin >> choice;
                            cin.ignore();
                            switch (choice) {
                                default:
                                    cout << "\nDigit error, try again." << endl;
                                    goto subMenu2;
                                    case 1:
                                        todoList.removeActivity(activitySel);
                                        cout << "\nActivity deleted succesfully!" << endl;
                                        goto subMenu1;
                                        case 2:
                                            todoList.setActivityDone(activitySel);
                                            cout << "\nGood job!" << endl;
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
                        cout << "\nOut of range number" << endl;
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
            cout << "Number of the activity you want to delete (type '0' to cancel): ";
            int deleteActivity;
            cin >> deleteActivity;
            cout << endl;
            if(!deleteActivity)
                goto menu;
            if (deleteActivity <= 0 || deleteActivity > todoList.getSize())
                cout << "\nOut of range number" << endl;
            else {
                todoList.removeActivity(deleteActivity);
                cout << "\nActivity deleted succesfully" << endl;
            }
        }
        goto menu;
        case 4: {
            ofstream f("C:\\Users\\aleal\\Documents\\LaboratorioDiProgrammazione\\TodoListExport.txt", ios::out);
            if(!f){
                cout<<"Errore scrittura del file"<< endl;
                goto menu;
            }
            f.close();
            ofstream g("C:\\Users\\aleal\\Documents\\LaboratorioDiProgrammazione\\TodoListExport.txt", ios::app);
            for (int i =1;i<=todoList.getSize();i++){
                Activity a = todoList.getActivityy(i);
                g<<"NEXT"<<endl;
                g<<a.getTitle()<<endl;
                g<<a.getDescription()<<endl;
                g<<a.getExpiration().getDay()<<endl;
                g<<a.getExpiration().getMonth()<<endl;
                char done[6] = "false";
                if (a.isDone())
                    strcpy (done , "true");
                g<<done<<endl;
            }
            g.close();
        }
        case 5:
            return 0;
        default:
            cout << "\nDigit error, try again." << endl;
            goto menu;
    }

}