// FRIEND CLASS AND FUNCTION

// to grant a member level access to a function that aren't the member of the class or to all the member of the seperate class

// We need to declare all the friemds class and functions in the class itself (not in the class which is the friend)

// https://learn.microsoft.com/en-us/cpp/cpp/friend-cpp?view=msvc-170   resource to refer

// Can a constructor be private 

#include<bits/stdc++.h>

using namespace std;

class Chai{
    private:
        int servings;
        string teaName;
    
    public:
        // One of the many ways to declare the constructor
        Chai(int serving, string name): teaName(name), servings(serving){}

        friend bool compare(const Chai& obj1,const Chai& obj2);
        
        // Chai(int serving,string name){
        //     teaName = name;
        //     servings = serving;
        // }

        void display(){
            cout << "Tea Name : " << teaName <<endl;
            cout << "Number of servings :  " << servings << endl;
            
        }
};

// we can also define the friend function outside the class as well 
bool compare(const Chai& obj1,const Chai& obj2){
    return obj1.servings > obj2.servings;
}

int main(){
    Chai masalaChai(4,"Masala Chai");
    Chai gingerChai(9,"Ginger Chai");

    masalaChai.display();

    if(compare(masalaChai,gingerChai)){
        cout << "Masala is more";
    }else{
        cout << "Masala is less";
    }

    return 0;
}