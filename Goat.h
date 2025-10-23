// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public: 
    Goat()                          { name = ""; age = 0; color = ""; }
    // write three more constructors
    Goat(string name)               { set_name(name);set_age(0);set_color(""); }
    Goat(string name, int age)      { set_name(name);set_age(age);set_color(""); }
    Goat(string name, int age, string color){ set_name(name);set_age(age);set_color(color);}

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // write overloaded < operator for the std::list
    bool operator<(Goat &goat) const{
        return name<goat.get_name();// sort by name
    }
};

#endif