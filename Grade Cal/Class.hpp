//
//  Class.hpp
//  Grade Cal
//
//  Created by Kevin Sirius Yang on 12/28/19.
//  Copyright © 2019 Kevin Sirius Yang. All rights reserved.
//

#ifndef Class_hpp
#define Class_hpp

#include <vector>
#include <string>
#include <stdio.h>
#include "Section.hpp"




class Class{
private:
    std::string name;
    double grade; //overall Grade
    std::vector<Section*> Sections;
    size_t sectionSize;
public:
    Class(const std::string&);
    ~Class();
    const std::string& returnName();
    void changeName(const std::string);
    bool addSection(const std::string&, double perc);
    size_t findSection(const std::string& name);
    Section* returnSectionAddr(const std::string& name);
    bool removeSection(const std::string& name);
    double returnOverallGrade();
    bool addItem(Section*, const std::string&, double, double);
};

#endif /* Class_hpp */
