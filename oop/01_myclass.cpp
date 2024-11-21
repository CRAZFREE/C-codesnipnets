#include<bits/stdc++.h>

// if not using bits/stdc++.h
// #include<iostream.h>
// #include<vector.h>


using namespace std;


class Chai{
    // by default they all are private, public in union and struct
    public:
        //data members/ sttributes / variables 
        int servings;
        string teaName;
        vector<string> ingredients; 

        //Member functions
        void display(){
            cout << "Tea Name : " << teaName << endl;
            cout << "servings : " << servings << endl;
            cout << "Ingredients : ";
            for(auto ingredient : ingredients){
                cout << ingredient << " ";
            }
            cout << endl;
        }
    private:
        int dummy;
    // You can have any number of times private public and protected
    // and anyehere in the class 

};


int main(){
    Chai chaiOne;
    chaiOne.
}