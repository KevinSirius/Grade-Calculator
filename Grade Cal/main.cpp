//
//  main.cpp
//  Grade Cal
//
//  Created by Kevin Sirius Yang on 12/28/19.
//  Copyright © 2019 Kevin Sirius Yang. All rights reserved.
//
using namespace std;
#include <iostream>
#include <string>
#include "User.hpp"
int main() {
    User* currentUser = new User;
    
    
}

void listenToCommand(User* user){
    string command;
    string name;
    double tempDouble;
    Class* currentClass = nullptr;
    Section* currentSection = nullptr;
    cin >> command;
    if (command == "exit"){
        exit(0);
    }
    else if (command == "AddClass"){
        cout << "Please Enter Name" << endl;
        cin >> name;
        user->addClass(name);
    }
    else if (command == "RemoveClass"){
        cout << "Please Enter Name" << endl;
        cin >> name;
        if (user->removeClass(name)){
            cout << "Remove Successful!" << endl;
        } else {
            cout << "Remove Fail!" << endl;
        }
    }
    else if (command == "Class"){
        cout << "Please Enter Name" << endl;
        cin >> name;
        currentClass = user->returnClassAddr(name);
        if (currentClass == nullptr){
            cout << "Class Not Found!" << endl;
        }
    }
    else if (command == "Section"){
        if (currentClass == nullptr){
            cout << "You are not in a class yet!" << endl;
        } else {
            cout << "Please Enter Name" << endl;
            cin >> name;
            currentSection = currentClass->returnSectionAddr(name);
            if (currentSection == nullptr){
                cout << "Section Not Found!" << endl;
            }
        }
    }
    else if (command == "AddSection"){
        if (currentClass == nullptr){
            cout << "You are not in a class yet!" << endl;
        } else {
            cout << "Please Enter Name" << endl;
            cin >> name;
            cout << "Please Enter Grade Percentage" << endl;
            cin >> tempDouble;
            if (currentClass->addSection(name, tempDouble)){
                cout << "Success!" << endl;
            } else{
                cout << "Error Creating Section" << endl;
            }
        }
    }
    else if (command == "RemoveSection"){
        if (currentClass == nullptr){
            cout << "You are not in a class yet!" << endl;
        } else {
            cout << "Please Enter Name" << endl;
            cin >> name;
            if (currentClass->returnSectionAddr(name) != nullptr){
                if (currentClass->removeSection(name)){ //update from string to pointer later
                    cout << "Success" << endl;
                } else {
                    cout << "Error Deleting Section" << endl;
                }
            }
        }
    }
    else if (command == "ChangeSection"){
        if (currentClass == nullptr){
            cout << "You are not in a class yet!" << endl;
        } else {
            cout << "Please Enter Name" << endl;
            cin >> name;
            if (currentClass->returnSectionAddr(name) != nullptr){
                if (currentClass->removeSection(name)){ //update from string to pointer later
                    cout << "Success" << endl;
                } else {
                    cout << "Error Deleting Section" << endl;
                }
            }
        }
    }
    
}

void test(){
    
}
