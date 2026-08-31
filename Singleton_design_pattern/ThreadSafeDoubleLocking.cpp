// This implements the Double-Checked Locking optimization — 
// it checks instance == nullptr first without locking, 
// and only acquires the mutex if it's actually null, 
// avoiding the overhead of locking on every call. 
// The second check inside the lock ensures that if two threads passed the first check simultaneously, 
// only one of them actually creates the instance. s1 and s2 end up pointing to the same object, 
// so s1 == s2 prints 1.

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
    // Double check locking..
    static Singleton* getInstance() {
        if (instance == nullptr) {  // First check (no locking)
            lock_guard<mutex> lock(mtx);  // Lock only if needed
            if (instance == nullptr) {  // Second check (after acquiring lock)
                instance = new Singleton();
            }
        }
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