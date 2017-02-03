//
//  Noble.hpp
//  Homework7
//
//  Created by Florance Wu on 11/10/16.
//  Copyright © 2016 Florance Wu. All rights reserved.
//

#ifndef Noble_hpp
#define Noble_hpp
#include <string>
#include <vector>
#include <stdio.h>

#endif /* Noble_hpp */


namespace Craft{
    class Warrior;
    class Noble{
    public:
        Noble(const std::string& nameParam);
        void hire(Warrior& warriorParam);
        void fire(Warrior& warriorParam, bool output);
        void display(std::ostream& os) const;
        std::string getName() const;
        double getStrength() const;
        void killArmy() const;
        void damageArmy(const double& proportionParam) const;
        void battle(Noble& nobleParam);
    protected:
    private:
        const std::string name;
        std::vector<Warrior*> army;
    };
    
    std::ostream& operator<<(std::ostream& os, const Noble& rhs);
    
}

