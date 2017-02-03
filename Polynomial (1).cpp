//
//  Polynomial.cpp
//  Homework8
//
//  Created by Florance Wu on 11/27/16.
//  Copyright © 2016 Florance Wu. All rights reserved.
//
#include <iostream>
#include "Polynomial.hpp"



void Polynomial::clean(){
    if (list->data == 0){
        Node* ptr = list;
        list = list->link;
        delete ptr;
    }
    Node* ptr = list;
    if (ptr != nullptr){
        while (ptr->link != nullptr){
            ptr = ptr->link;
        }
        if (ptr->data == 0){
            Node* ptr2 = list;
            while (ptr2->link->link != nullptr){
                ptr2 = ptr2->link;
            }
            delete ptr;
            ptr2->link = nullptr;
        }
    }
}

Polynomial::Polynomial(const vector<int>& vect ){
    if( vect.size() < 2){
        degree = 0; // Example : {4} - constant
    }
    else{
        degree = vect.size() - 1;
    }
    list = nullptr; // just in case it isn't empty
    for ( size_t i = 0; i < vect.size() ; i++){
        list = new Node(vect[i], list); //passes in the pointer to the previous value
    }
}
Polynomial::Polynomial(const Polynomial& base){
    degree = 0;
    list = nullptr;
    *this += base;
    
}
Polynomial& Polynomial::operator+=(const Polynomial & base){
    if (base.degree > degree){
        degree = base.degree;
    }
    if ( list == nullptr){
        list = new Node(0);
    }
    Node* ocurr = list;
    Node* tcurr = base.list;
    while (tcurr != nullptr){
        if (tcurr->link != nullptr && ocurr->link == nullptr){ // if the first list is shorter than the second
            ocurr->link = new Node(0);
        }
        ocurr->data = ocurr->data + tcurr->data;
        ocurr = ocurr->link;
        tcurr = tcurr->link;
    }
    clean();
    return *this;
}
double Polynomial::evaluate(int x) const{
    double result = 0;
    Node* curr = list;
    int deg = 0;
    while (curr != nullptr){
        int exp = 1;
        for (int i = 0; i < deg; ++i){
            exp = exp*x;
        }
        result = result + curr->data * exp;
        curr = curr->link;
        ++deg;
    }
    return result;
}

std::ostream& display(std::ostream& os, Node* head, int deg){
    if (head == nullptr) return os;
    display(os, head->link, deg + 1);
    if (head->data != 0){
        if (head->link != nullptr && head->data > 0){
            os << "+";
        }
        if (head->data != 1 || deg == 0){
            os << head->data;
        }
        if (deg != 0){
            os << "x";
        }
        if (deg != 1 && deg !=0){
            os << "^" << deg;
        }
    }
    return os;
}

ostream& operator<<(ostream& os, const Polynomial& poly){
    display(os, poly.list, 0);
    return os;
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs){
    Polynomial result(lhs);
    result += rhs;
    return result;
}

bool Polynomial::operator==(const Polynomial& comp) const{
    if (degree != comp.degree) return false;
    Node* ocurr = list;
    Node* tcurr = comp.list;
    while (ocurr != nullptr){
        if (tcurr == nullptr) return false;
        if (tcurr->data != ocurr->data) return false;
        tcurr = tcurr->link;
        ocurr = ocurr->link;
    }
    if (tcurr != nullptr) return false;
    return true;
}

bool Polynomial::operator!=(const Polynomial& comp) const{
    return !(*this == comp);
}
