#include<bits/stdc++.h>

using namespace std;

class Chai{
    private:

        string teaName;
        int servings;
        vector<string> ingredients;

    public:

        // delegating constructor
        Chai(string name) : Chai(name, 1, {"Water", "Tea Leaves"}){}

        Chai(string name, int serve, vector<string> ing): teaName(name), servings(serve), ingredients(ing){
            cout <<"Main constructor called" <<endl;
        }

        void display(){
            cout <<"Tea Name : "<< teaName << endl;
            cout <<"Number of cups : "<< servings << endl;
            for(auto x : ingredients){
                cout << x << " ";
            }
            cout<<endl;
            
        }



};


int main(){
    Chai quickChai("QuickChai");

    quickChai.display();
    return 0;
}