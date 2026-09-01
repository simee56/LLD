#ifndef USER_H
#define USER_H

#include<iostream>
#include "Cart.h"
using namespace std;

class User {
private:
    static int nextUserId;
    int UserId;
    string name;
    string address;
    Cart* cart;
public:
    User(int UserId, const string& name, const string& address) {
        this->name = name;
        this->address = address;
        this->UserId = ++nextUserId;
        this->cart = new Cart();
    };

    ~User() {
        delete cart;
    };

    // Getters and Setters
    string getName() const {
        return name;
    }

    void setName(const string &n) {
        name = n;
    }

    string getAddress() const {
        return address;
    }

    void setAddress(const string &a) {
        address = a;
    }

    Cart* getCart() const {
        return cart;
    }
};

int User::nextUserId = 0;

#endif