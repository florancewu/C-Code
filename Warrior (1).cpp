//
//  Warrior.cpp
//  Homework7
//
//  Created by Florance Wu on 11/10/16.
//  Copyright © 2016 Florance Wu. All rights reserved.
//

#include <string>
#include <iostream>
#include "Warrior.hpp"
#include "Noble.hpp"
using namespace std;


namespace Craft{
    
    Warrior::Warrior(const std::string& nameParam, const double& strengthParam) :
    name(nameParam), strength(strengthParam), master(nullptr){}
    void Warrior::display() const {
        std::cout << name << ": " << strength;
    }
    std::string Warrior::getName() const {
        return name;
    }
    double Warrior::getStrength() const {
        return strength;
    }
    void Warrior::die() {
        strength = 0;
    }
    void Warrior::hurt(const double& proportionParam){
        strength = strength - (proportionParam * strength);
    }
    void Warrior::hire(Noble* noblePtr){
        master = noblePtr;
    }
    void Warrior::fire(){
        master = nullptr;
    }
    Noble* Warrior::getMaster() const{
        return master;
    }
    void Warrior::runaway(){
        cout << name << " flees in terror, abandoning his lord, " << master->getName() << endl;
        master->fire(*this, false);
    }
}