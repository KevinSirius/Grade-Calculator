//
//  Class.cpp
//  Grade Cal
//
//  Created by Kevin Sirius Yang on 12/28/19.
//  Copyright © 2019 Kevin Sirius Yang. All rights reserved.
//
#include "Class.hpp"

Class::Class(const std::string& name) : name(name), grade(0.0), sectionSize(0) {};

Class::~Class(){
    if (sectionSize != 0){
        for (size_t i = 0; i < sectionSize; i++){
            delete Sections[i];
        }
    }
}

void Class::changeName(const std::string newName){
    name = newName;
}
const std::string& Class::returnName(){
    return name;
}
bool Class::addSection(const std::string& name, double perc){
    Sections.push_back(new Section(name, perc));
    sectionSize += 1;
    return 1;
}
size_t Class::findSection(const std::string& name){
    for (size_t i = 0; i < Sections.size(); i++){
        if (name == Sections[i]->returnSectionName()){
            return i;
        }
    }
    return Sections.size();
}
Section* Class::returnSectionAddr(const std::string& name){
    size_t index = findSection(name);
    if (index != sectionSize){
        return Sections[index];
    }
    return nullptr;
}
bool Class::removeSection(const std::string& name){
    size_t index = findSection(name);
    if (Sections.size() == index){
        return 0;
    }
    for (size_t i = index; i < Sections.size(); i++){
        Sections[i] = Sections[i+1];
    }
    Sections.pop_back();
    sectionSize -= 1;
    return 1;
}
double Class::returnOverallGrade(){
    double result = 0;
    for (size_t i = 0; i < Sections.size(); i++){
        result += Sections[i]->returnSectionGrade();
    }
    return result;
}
bool Class::addItem(Section* section, const std::string& itemName, double grade, double maxGrade){
    if (section->addItem(itemName, grade, maxGrade)){
        return 1;
    }
    return 0;
}
