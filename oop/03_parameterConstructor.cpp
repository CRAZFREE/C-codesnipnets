#include<bits/stdc++.h>

using namespace std;

class Chai{
public:
    string teaName;
    int servings;
    vector<string> ingredients;

    // if you are not creating any coinstructor, the compiler will
    // automatically creates a constructor which we won't be able to see

    //parameterized or parameter constructor
    Chai(string name, int serving, vector<string> ing){
        cout <<"Parameter Constructor called"<<endl;
        teaName = name;
        servings = serving;
        ingredients = ing;
    }

    void display(){
        cout << "Tea Name : " << teaName << endl;
        cout << "servings : " << servings << endl;
        cout << "Ingredients : ";
        for(auto ingredient : ingredients){
            cout << ingredient << " ";
        }
        cout << endl;
    }

};


int main(){

    Chai lemonTea("Lemon Tea", 23, {"Lemon","Water","Honey"});
    lemonTea.display();


    return 0;
}