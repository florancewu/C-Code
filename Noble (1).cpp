//
//  Noble.cpp
//  Homework7
//
//  Created by Florance Wu on 11/10/16.
//  Copyright © 2016 Florance Wu. All rights reserved.
//

#include "Noble.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "Warrior.hpp"
using namespace std;

namespace Craft{
    
    Noble::Noble(const std::string& nameParam) :
    name(nameParam){}
    void Noble::hire(Warrior& warriorParam){
        army.push_back(&warriorParam);
        warriorParam.hire(this);
    }
    void Noble::fire(Warrior& warriorParam, bool output = true){
        for (size_t i = 0; i < army.size(); i++){
            if (&warriorParam == army[i]){
                army[i] = army[(army.size() - 1)];
                army.pop_back();
                warriorParam.fire();
                if (output){
                    std::cout << warriorParam.getName() << ", you're fired! -- " << name << std::endl;
                }
            }
        }
    }
    void Noble::display(ostream& os = cout) const {
        os << name << " has an army of " << army.size() << endl;
        for (size_t i = 0; i < army.size(); ++i){
            os << "\t";
            army[i]->display();
            os << endl;
        }
    }
    std::string Noble::getName() const {
        return name;
    }
    double Noble::getStrength() const {
        double strength = 0;
        for (size_t i = 0; i < army.size(); i++){
            strength = strength + army[i]->getStrength();
        }
        return strength;
    }
    void Noble::killArmy() const {
        for (size_t i = 0; i < army.size(); ++i){
            army[i]->die();
        }
    }
    void Noble::damageArmy(const double& proportionParam) const {
        for (size_t i = 0; i < army.size(); ++i){
            army[i]->hurt(proportionParam);
        }
    }
    void Noble::battle(Noble& nobleParam){
        std::cout << name << " battles " << nobleParam.getName() << std::endl;
        double ourStrength = getStrength();
        double theirStrength = nobleParam.getStrength();
        if (theirStrength == 0 && ourStrength == 0){
            std::cout << "Oh, NO!  They're both dead!  Yuck!" << std::endl;
        }
        else if (theirStrength == 0){
            std::cout << "He's dead, " << name << std::endl;
        }
        else if (ourStrength == 0){
            std::cout << "He's dead, " << nobleParam.getName() << std::endl;
        }
        else if (theirStrength == ourStrength){
            killArmy();
            nobleParam.killArmy();
            std::cout << "Mutual Annihalation : " << name << " and " << nobleParam.getName() << " die at each other's hands" << std::endl;
        }
        else if (theirStrength > ourStrength){
            double proportion = ourStrength / theirStrength;
            nobleParam.damageArmy(proportion);
            killArmy();
            std::cout << nobleParam.getName() << " defeats " << name << std::endl;
        }
        else{
            double proportion = theirStrength / ourStrength;
            damageArmy(proportion);
            nobleParam.killArmy();
            std::cout << name << " defeats " << nobleParam.getName() << std::endl;
        }
    }
    
    ostream& operator<<(ostream& os, const Noble& rhs){
        rhs.display(os);
        return os;
    }
}