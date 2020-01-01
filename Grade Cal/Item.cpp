//
//  Item.cpp
//  Grade Cal
//
//  Created by Kevin Sirius Yang on 12/28/19.
//  Copyright © 2019 Kevin Sirius Yang. All rights reserved.
//

#include "Item.hpp"

Item::Item(const std::string& name, double grade, double maxGrade) : name(name), grade(grade), maxGrade(maxGrade){};
double Item::returnItemGrade(){
    return grade / maxGrade;
}
void Item::changeGrade(double newG){
    grade = newG;
}
void Item::changeMaxGrade(double newM){
    maxGrade = newM;
}
const std::string& Item::returnName(){
    return name;
}
