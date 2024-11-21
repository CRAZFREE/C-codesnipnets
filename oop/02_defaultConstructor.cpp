#include<bits/stdc++.h>

using namespace std;

class Chai{
public:
    string teaName;
    int servings;
    vector<string> ingredients;

    // if you are not creating any coinstructor, the compiler will
    // automatically creates a constructor which we won't be able to see
    Chai(){
        cout <<"Constructor called"<<endl;
        teaName = "Unknown Tea";
        servings = 1;
        ingredients = {"Water", "Tealeaves"};
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

    Chai defaultChai;
    defaultChai.display();


    return 0;
}