// Sometimes implementation of all functions cannot be provided in a base class because we don’t know the implementation. Such a class is called an abstract class

// A pure virtual function is declared by assigning 0 in the declaration.

//  A class is abstract if it has at least one pure virtual function.

// Do more with the abstraction


#include<bits/stdc++.h>

using namespace std;


class Tea{
    public:
    // pure virtual function
    virtual void prepareIngredients() = 0;
    virtual void brew() = 0;
    virtual void serve() = 0;

    void makeTea(){
        prepareIngredients();
        brew();
        serve();
    }
};


// Derived class
class MasalaTea : public Tea{
    void prepareIngredients() override{
        cout << "Tea leaves with water and chai masala" << endl;
    }

    void brew() override {
        cout << "The masala chai is brewed" << endl;
    }

    void serve() override {
        cout << "Masala Chai is ready to serve " << endl;
    }
};


int main(){
    MasalaTea masalaChai; 

    masalaChai.makeTea();
    return 0;
}