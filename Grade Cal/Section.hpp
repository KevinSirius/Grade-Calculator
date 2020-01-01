//
//  Section.hpp
//  Grade Cal
//
//  Created by Kevin Sirius Yang on 12/28/19.
//  Copyright © 2019 Kevin Sirius Yang. All rights reserved.
//

#ifndef Section_hpp
#define Section_hpp

#include <string>
#include "Item.hpp"
#include <vector>
#include <stdio.h>
class Section{
private:
    std::string name;
    double percentage;
    std::vector<Item*> Items;
    size_t itemSize;
public:
    Section(const std::string&, double);
    ~Section();
    void changeSectionName(const std::string&);
    void changeSectionPer(double);
    const std::string& returnSectionName();
    double returnSectionPerc();
    double returnSectionGrade();
    bool addItem(const std::string& name, double grade, double maxGrade);
    bool removeItem(const std::string& name);
    size_t findItem(const std::string& name);
    const Item* returnItemAddr(const std::string& name);
    bool changeItem(Item*, double, double);
};
#endif /* Section_hpp */
