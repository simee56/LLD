// This is a thread-safe version of the Singleton pattern, 
// using a mutex with lock_guard inside getInstance() to prevent 
// race conditions when multiple threads call it simultaneously. 
// It ensures only one Singleton object is ever created, 
// even under concurrent access, unlike the earlier unprotected version. 
// In main(), s1 and s2 both get the same instance, so s1 == s2 prints 1

#include<iostream>
#include <mutex>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;

    Singleton() {
        cout <<  "Singleton Constructor called" << endl;
    }

public:
    static Singleton* getInstance() {
        lock_guard<mutex> lock(mtx);
        if(instance == nullptr) 
            instance = new Singleton;
        return instance;
    }
};

// Intitialize static member 
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}