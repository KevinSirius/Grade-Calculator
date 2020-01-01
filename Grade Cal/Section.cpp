//
//  Section.cpp
//  Grade Cal
//
//  Created by Kevin Sirius Yang on 12/28/19.
//  Copyright © 2019 Kevin Sirius Yang. All rights reserved.
//

#include "Section.hpp"


Section::Section(const std::string& name, double percentage) : name(name), percentage(percentage), itemSize(0){};

Section::~Section(){
    if (itemSize != 0){
        for (size_t i = 0; i < itemSize; i++){
            delete Items[i];
        }
    }
}
void Section::changeSectionPer(double perc){
    percentage = perc;
}
void Section::changeSectionName(const std::string& NewName){
    name = NewName;
}
const std::string& Section::returnSectionName(){
    return name;
}
double Section::returnSectionPerc(){
    return percentage;
}
double Section::returnSectionGrade(){
    double result = 0;
    for (int i = 0; i < Items.size(); i++){
        result += Items[i]->returnItemGrade();
    }
    result *= percentage;
    return result;
}
bool Section::addItem(const std::string& name, double grade, double maxGrade){
    Items.push_back(new Item(name, grade, maxGrade));
    itemSize += 1;
    return 1;
}
size_t Section::findItem(const std::string& name){
    for (size_t i = 0; i < Items.size(); i++){
        if (Items[i]->returnName() == name){
            return i;
        }
    }
    return Items.size();
}
const Item* Section::returnItemAddr(const std::string& name){
    size_t index = findItem(name);
    if (index != itemSize){
        return Items[index];
    }
    return nullptr;
}
bool Section::removeItem(const std::string& name){
    size_t index = findItem(name);
    if (index == Items.size()){
        return 0;
    }
    for (size_t i = index; i < Items.size(); i++){
        Items[i] = Items[i+1];
    }
    Items.pop_back();
    itemSize -= 1;
    return 1;
}
bool changeItem(Item* item, double grade, double maxGrade){
    item->changeGrade(grade);
    item->changeMaxGrade(maxGrade);
    return 1;
}
