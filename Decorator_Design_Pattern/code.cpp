// The Decorator pattern lets you attach new behavior to an object dynamically, 
// by wrapping it in successive "decorator" objects — instead of using subclassing 
// to add every combination of features up front.

#include <iostream>
#include <string>

using namespace std;

// Component Interface: defines a common interface for Ninja and all power-up decorators.
class Character {
public:
    virtual string getAbilities() const = 0;
    virtual ~Character() {}  
};

// Concrete Component: Basic Ninja character with no power-ups.
class Ninja : public Character {
public:
    string getAbilities() const override {
        return "Ninja";
    }
};

// Abstract Decorator: CharacterDecorator "is-a" Charatcer and "has-a" Character.
class CharacterDecorator : public Character {
protected:
    Character* character;  // Wrapped component
public:
    CharacterDecorator(Character* c){
        this->character = c;
    }

};

// Concrete Decorator: Height-Increasing Power-Up.
class HeightUp : public CharacterDecorator {
public:
    HeightUp(Character* c) : CharacterDecorator(c) { }
    
    string getAbilities() const override {
        return character->getAbilities() + " with HeightUp";
    }
    
};

// Concrete Decorator: Gun Shooting Power-Up.
class GunPowerUp : public CharacterDecorator {
public:
    GunPowerUp(Character* c) : CharacterDecorator(c) { }
    
    string getAbilities() const override {
        return character->getAbilities() + " with Gun";
    }
};

// Concrete Decorator: Star Power-Up (temporary ability).
class StarPowerUp : public CharacterDecorator {
public:
    StarPowerUp(Character* c) : CharacterDecorator(c) { }
    
    string getAbilities() const override {
        return character->getAbilities() + " with Star Power (Limited Time)";
    }
    
    ~StarPowerUp() {
        cout << "Destroying StarPowerUp Decorator" << endl;
    }
};

int main() {
    // Create a basic Ninja character.
    Character* ninja = new Ninja();
    cout << "Basic Character: " << ninja->getAbilities() << endl;

    // Decorate Ninja with a HeightUp power-up.
    ninja = new HeightUp(ninja);
    cout << "After HeightUp: " << ninja->getAbilities() << endl;

    // Decorate Ninja further with a GunPowerUp.
    ninja = new GunPowerUp(ninja);
    cout << "After GunPowerUp: " << ninja->getAbilities() << endl;

    // Finally, add a StarPowerUp decoration.
    ninja = new StarPowerUp(ninja);
    cout << "After StarPowerUp: " << ninja->getAbilities() << endl;

    delete ninja;

    return 0;
}