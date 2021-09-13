#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "TodoList.h"
#include "ListOfLists.h"
#include <string.h>
#include <fstream>

int getMaxDays(int year, int month);
static std::string listSelected;
using namespace std;

int main() {
    ListOfLists lol;
    nuovalista:
    cout<< "Nome lista:";
    getline(cin, listSelected);
    TodoList newList(listSelected);
    int choice;
    cout << "\nImport file? (1=si/0=no)" << endl;
    cin >> choice;

    if (choice){  //import from txt file
        FILE *filePTR;
        int countRiga = 0;
        char riga_del_file[50];
        filePTR = fopen("C:\\Users\\aleal\\Documents\\LaboratorioDiProgrammazione\\TodoList.txt","r");
        if (filePTR){
            char titolo[50], descrizione[50];
            int giorno, mese, anno;
            bool done=false;
            while (!feof(filePTR)){
                fgets(riga_del_file,50,filePTR);
                if (strcmp("NEXT\n",riga_del_file)==0){
                    countRiga=0;
                }
                int pos=0;
                for (char x : riga_del_file){
                    if (x == '\n'){
                        riga_del_file[pos]='\0';
                    }
                    pos++;
                }
                if(countRiga==1)
                    strcpy(titolo,riga_del_file);
                if(countRiga==2)
                    strcpy(descrizione,riga_del_file);
                if(countRiga==3)
                    giorno=atoi(riga_del_file);
                if(countRiga==4)
                    mese=atoi(riga_del_file);
                if(countRiga==5)
                    anno=atoi(riga_del_file);
                if(countRiga==6){
                    char isTrue[5];
                    strcpy (isTrue, "true");
                    if (strcmp(isTrue,riga_del_file)==0){
                        done=true;
                    }
                    string t = string(titolo);
                    string d = string(descrizione);
                    Activity a = Activity (t,d,Date(giorno,mese,anno),done);
                    newList.addActivity(a);
                }
                countRiga++;
            }
            fclose(filePTR);
        }
        else {
            cout<< "Errore file"<< endl;
        }

    }
    lol.addList(newList);
    menu:
    cin.clear();
    cout << "\nWhat to do in the list '" + listSelected +"'"  << endl;
    cout << "1- Activity list" << endl;
    cout << "2- Add activity" << endl;
    cout << "3- Remove activity" << endl;
    cout << "4- Export to file" << endl;
    cout << "5- Go back and chose another list" << endl;
    cout << "6- Exit" << endl;
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case 1:
            subMenu1:
                cin.clear();
                lol.getList(listSelected).printAllActivities();
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
                            } while (activitySel < 1 || activitySel > lol.getList(listSelected).getSize());
                            cout << "Activity " << activitySel << " is selected" << endl;
                            cout << "1- Delete it" << endl;
                            cout << "2- Mark as done" << endl;
                            cout << "3- Move the activity in another list" << endl;
                            cout << "4- Cancel operation and go back" << endl;
                            subMenu2:
                            cin >> choice;
                            cin.ignore();
                            switch (choice) {
                                default:
                                    cout << "\nDigit error, try again." << endl;
                                    goto subMenu2;
                                    case 1:
                                        lol.removeActivityFromList(listSelected,activitySel);
                                        cout << "\nActivity deleted succesfully!" << endl;
                                        goto subMenu1;
                                    case 2:
                                        lol.setActivityDone(listSelected, activitySel);
                                        cout << "\nGood job!" << endl;
                                        goto subMenu1;
                                    case 3:
                                        if (lol.getSize()<2){
                                            cout << "Not enought lists to move an item" << endl;
                                            goto menu;
                                        }
                                        else {
                                            string move;
                                            cout << "To which other list you want to move the activity? Choose between.." << endl;
                                            lol.printLists();
                                            cin.clear();
                                            getline(cin,move);
                                            if (lol.findList(move)){
                                                Activity a = lol.getList(listSelected).getActivityy(activitySel);
                                                lol.moveList (listSelected,move,a);
                                            }
                                            else
                                                cout<< "The input is not a list"<< endl;
                                            goto menu;
                                        }
                                    case 4:
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
                string date;
                bool error = true;
                int day=0,month=0,year=0;
                cout << "Title of the activity: " << endl;
                getline(cin, title);
                cout << "Description of the activity: " << endl;
                getline(cin, description);
                cout << "Date of expiration (DD/MM/YYYY): "<< endl;
                while (error){
                    error=false;
                    getline(cin, date);
                    day = stoi(date.substr(0,2));
                    month = stoi(date.substr(3,2));
                    year = stoi(date.substr(6,4));
                    if (year < 0 or day < 1 or month < 1 or month > 12 or day > getMaxDays(year,month)){
                        error = true;
                        cout << "Date not valid try again"<< endl;
                    }
                }
                Date expiration(day, month,year);
                Activity a(description, title, expiration, false);
                lol.addActivityToList(listSelected,a);
            }
            goto menu;
        case 3: {
            lol.getList(listSelected).printAllActivities();
            cout << "Number of the activity you want to delete (type '0' to cancel): ";
            int deleteActivity;
            cin >> deleteActivity;
            cout << endl;
            if(!deleteActivity)
                goto menu;
            if (deleteActivity <= 0 || deleteActivity > lol.getList(listSelected).getSize())
                cout << "\nOut of range number" << endl;
            else {
                lol.removeActivityFromList(listSelected,deleteActivity);
                cout << "\nActivity deleted succesfully" << endl;
            }
        }
        goto menu;
        case 4: {
            ofstream f("C:\\Users\\aleal\\Documents\\LaboratorioDiProgrammazione\\TodoList.txt", ios::out);
            if(!f){
                cout<<"Errore scrittura del file"<< endl;
                goto menu;
            }
            f.close();
            ofstream g("C:\\Users\\aleal\\Documents\\LaboratorioDiProgrammazione\\TodoList.txt", ios::app);
            for (int i =1;i<=lol.getList(listSelected).getSize();i++){
                Activity a = lol.getList(listSelected).getActivityy(i);
                g<<"NEXT"<<endl;
                g<<a.getTitle()<<endl;
                g<<a.getDescription()<<endl;
                g<<a.getExpiration().getDay()<<endl;
                g<<a.getExpiration().getMonth()<<endl;
                g<<a.getExpiration().getYear()<<endl;
                char done[6] = "false";
                if (a.isDone())
                    strcpy (done , "true");
                g<<done<<endl;
            }
            g.close();
            printf ("Export finished");
            goto menu;
        }
        case 5: {
            cout<<"Le liste disponibili sono: "<<endl;
            lol.printLists();
            std::string listChoice;
            while (true) {
                cout<<"Select a list typing its name (type '0' to create a new list) -> ";
                getline (cin, listChoice);
                if (listChoice == "0")
                    goto nuovalista;
                else if (lol.findList(listChoice)){
                    listSelected=lol.getList(listChoice).getName();
                    break;
                }
                else
                    cout << "Nome non presente in lista" << endl;
            }
            goto menu;
        }
        case 6:
            return 0;
        default:
            cout << "\nDigit error, try again." << endl;
            goto menu;
    }

}

int getMaxDays(int year, int month) {
    short unsigned int maxDay = 31;
    switch (month) {
        case 4: //April
        case 6: //June
        case 8: //September
        case 11: //November
        maxDay = 30;
        break;
        case 2: {

            if (year % 4 == 0) {
                if (year % 100 == 0) {
                    if (year % 400 == 0) {
                        maxDay = 29;
                    } else {
                        maxDay = 28;
                    }
                } else {
                    maxDay = 29;
                }
            } else {
                maxDay = 28;
            }
        }
    }
    return maxDay;
}
