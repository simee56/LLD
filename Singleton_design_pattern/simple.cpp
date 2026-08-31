// It's a creational design pattern that ensures a class has only one 
// instance throughout the program and provides a global point of access to it. 
// This is done by making the constructor private and exposing a static method 
// that creates the instance only once and returns the same one on subsequent calls.

#include<iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() {
        cout <<  "Singleton Constructor called" << endl;
    }

public:
    static Singleton* getInstance() {
        if(instance == nullptr) 
            instance = new Singleton;
        return instance;
    }
};

// Intitialize static member 
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}