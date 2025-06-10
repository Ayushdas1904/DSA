#include<iostream>
// #include "Hero.cpp" //how to use classes explicitly
using namespace std;

class Hero{
    //properties
    private:
    int health; //private

    public:
    char level;

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setLevel(char l){
        level = l;
    }
};

int main(){
    Hero Ramesh;

    Ramesh.setHealth(70);
    // Ramesh.setLevel('A');
    Ramesh.level = 'A';

    cout << "health is : " << Ramesh.getHealth()  << endl;
    cout << "level is : " << Ramesh.getLevel() << endl; //cannot access until the properties are public
    cout << "size: " << sizeof(Ramesh);
    return 0;
}