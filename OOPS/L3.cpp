#include<iostream>
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

    //statically
    Hero Ramesh;

    //dynamically
    Hero *a = new Hero;
    (*a).level = 'B';
    cout << "level is: " << (*a).level <<endl;
    cout << "level is: " << a->level;



    return 0;
}