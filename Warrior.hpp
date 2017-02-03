//
//  Warrior.hpp
//  Homework7
//
//  Created by Florance Wu on 11/10/16.
//  Copyright © 2016 Florance Wu. All rights reserved.
//

#ifndef Warrior_hpp
#define Warrior_hpp

#include <stdio.h>

#endif /* Warrior_hpp */
#include <string>
#include <iostream>

namespace Craft{
    
    class Noble;
    
    class Warrior{
    public:
        Warrior(const std::string& nameParam, const double& strengthParam);
        void display() const;
        std::string getName() const;
        double getStrength() const;
        void die();
        void hurt(const double& proportionParam);
        void hire(Noble* noblePtr);
        void fire();
        Noble* getMaster() const;
        void runaway();
    protected:
    private:
        const std::string name;
        double strength;
        Noble* master;
    };
    
}

