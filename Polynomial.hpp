//
//  Polynomial.hpp
//  Homework8
//
//  Created by Florance Wu on 11/27/16.
//  Copyright © 2016 Florance Wu. All rights reserved.
//

#ifndef Polynomial_hpp
#define Polynomial_hpp
#include <stdio.h>
using namespace std;
#include <vector>

struct Node{
    Node(const int& data, Node* link = nullptr): data(data), link(link){}
    int data;
    Node* link;
};

class Polynomial{
public:
    Polynomial(const vector<int>& vect = vector<int>{0});
    Polynomial(const Polynomial& def);
    friend std::ostream& operator<<(std::ostream&, const Polynomial&);
    Polynomial& operator+=(const Polynomial& base);
    bool operator==(const Polynomial& comp) const;
    bool operator!=(const Polynomial& comp) const;
    double evaluate(int x) const;
    void clean();
private:
    int degree;
    Node* list;
    
};

ostream& operator<<(ostream& os, const Polynomial& poly);
ostream& display(std::ostream& os, Node* head, int deg);
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);

#endif /* Polynomial_hpp */