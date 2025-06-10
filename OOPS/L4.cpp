#include <iostream>
using namespace std;

class Hero
{
    // properties
public:
    int health;
    char level;

    // a class has an inbuilt constructor but when a constructor is created that in built one dies off
    Hero()
    {
        cout << "Constructor called" << endl; // whenever u create a object this hero constructor is called
    }

    // parametrized constructor
    Hero(int health, char level)
    {

        this->level = level;
        this->health = health; // "this" - element that stores the address of the object
        // this-> health takes the variable of object not the paramter of default constructor which is by default taken when health is not mentioned
    }

    // Copy constructor
    Hero(Hero &temp)
    {
        cout << "Copy constructor calledd" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }

    void setHealth(int h)
    {
        health = h;
    }

    void setLevel(char l)
    {
        level = l;
    }
};

int main()
{

    Hero *a = new Hero(10, 'A'); // paramter is given
    cout << "The Health is : " << a->health << endl;

    // copying an object
    Hero Ramesh(70, 'C');

    // copy constructor
    Hero Suresh(Ramesh); // all the values of level and health of hero rsmesh will be copied to suresh also
    return 0;
}