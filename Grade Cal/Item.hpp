//
//  Item.hpp
//  Grade Cal
//
//  Created by Kevin Sirius Yang on 12/28/19.
//  Copyright © 2019 Kevin Sirius Yang. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp
#include <string>
#include <stdio.h>
class Item{
private:
    std::string name;
    double grade;
    double maxGrade;
public:
    Item(const std::string&, double, double);
    void changeGrade(double);
    const std::string& returnName();
    void changeMaxGrade(double);
    double returnItemGrade();
};
#endif /* Item_hpp */
