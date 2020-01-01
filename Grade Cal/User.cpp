//
//  User.cpp
//  Grade Cal
//
//  Created by Kevin Sirius Yang on 12/28/19.
//  Copyright © 2019 Kevin Sirius Yang. All rights reserved.
//

#include "User.hpp"

User::User() : classSize(0) {}

User::~User(){
    if (classSize != 0){
        for (size_t i = 0; i < classSize; i++){
            delete allClasses[i];
        }
    }
}

void User::addClass(const std::string& name){
    User::allClasses.push_back(new Class(name));
}

size_t User::findClass(const std::string& name){
    for (size_t i = 0; i < User::allClasses.size(); i++){
        if (User::allClasses[i]->returnName() == name){
            return i;
        }
    }
    return User::allClasses.size();
}
Class* User::returnClassAddr(const std::string& name){
    size_t index = findClass(name);
    if (index != classSize){
        return allClasses[index];
    }
    return nullptr;
}
bool User::removeClass(const std::string& name){
    size_t index = User::findClass(name);
    if (index == User::allClasses.size()){
        return false;
    }
    for (size_t i = index; i < User::allClasses.size(); i++){
        User::allClasses[i] = User::allClasses[i+1];
    }
    User::allClasses.pop_back();
    return true;
}

