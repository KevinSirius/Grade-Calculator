//
//  User.hpp
//  Grade Cal
//
//  Created by Kevin Sirius Yang on 12/28/19.
//  Copyright © 2019 Kevin Sirius Yang. All rights reserved.
//

#ifndef User_hpp
#define User_hpp
#include <vector>
#include <string>
#include "Class.hpp"
#include <stdio.h>
class User{
private:
    std::vector<Class*> allClasses;
    size_t classSize;
public:
    User();
    ~User();
    void addClass(const std::string& name);
    size_t findClass(const std::string& name);
    Class* returnClassAddr(const std::string& name);
    bool removeClass(const std::string& name);
    bool addSection(Class*, const std::string&, double);
    bool removeSection(const std::string& name);
    bool addItem(Class*, Section*, const std::string&, double, double);
    //calculateGPA();
};
#endif /* User_hpp */
