#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again = true;
    set<Goat> mainTrip;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES]; //names
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS]; //colors
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();
    //GOAT MANAGER ENGINE

    cout<<"*** GOAT MANAGER 3001***\n";
    while(again){
        int input = main_menu();
        switch (input){
            case 1:
                add_goat(mainTrip,names,colors);
                break;
            case 2:
                delete_goat(mainTrip);
                break;
            case 3:
                display_trip(mainTrip);
                break;
            case 4:
                again = false;
                break;
        }
    }
    return 0;
}

int main_menu(){
    cout<<"[1] Add a goat\n";
    cout<<"[2] Delete a goat\n";
    cout<<"[3] List goats\n";
    cout<<"[4] Quit\n";
    cout<<"Choice --> ";
    int input;
    cin>>input;
    while(input<1||input>4){    //check the int value returned between 1-4.repeat until valid input.
        cout<<"Invalid entry, try again. Select a option between 1-4: ";
        cin>>input;
    }
    return input;
}

void add_goat(set<Goat> &trip, string name[], string colors[]){
    trip.insert(Goat(name[rand()%SZ_NAMES],rand()%(MAX_AGE+1),colors[rand()%SZ_COLORS]));//new goat with random values added.
    cout<<"Goat Added!\n";
}

int select_goat(set<Goat> trip){
    int input;
    display_trip(trip);
    cout<<"Select which goat:";
    cin>>input;
    if(input>trip.size() || input<1){
        cout<<"Out of Bounds, returning to main menu\n";
    }
    return input-1;
}

void delete_goat(set<Goat> &trip){
    if(trip.empty()){cout<<"List is Empty. Terminating.\n"; return;}
    int input = select_goat(trip);
    auto it = trip.begin();
    advance(it,input); //found this in the geeksforgeeks resources.
    trip.erase(it); //apparently this calls the destructor
}


void display_trip(set<Goat> trip){
    int counter=1;
    cout<<"=====================\n";
    for(auto it = trip.begin(); it != trip.end(); it++){
        cout<<"["<<counter<<"] "<<it->get_name()<<" ("<<it->get_age()<<", "<<it->get_color()<<")\n";
        counter++;
    }
    cout<<"=====================\n";
}