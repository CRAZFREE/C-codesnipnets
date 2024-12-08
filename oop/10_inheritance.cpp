#include<bits/stdc++.h>

using namespace std;


// base class/ Main class / Parent class
class Tea{
    protected:
        string teaName;
        int servings;
    
    public:
        // constructor
        Tea(string name, int serve): teaName(name) , servings(serve) {
            cout << "Tea constructor is called to serve " << servings << " cups of " << teaName << endl; 
        }

        // virtual function
        virtual void brew() const {
            cout << "Brewing " << teaName << "with the virtual function" << endl;
        }

        virtual void serve() const {
            cout << "Serving " << servings << "cups with virtual" << endl;
        }

        // Destructor for the class
        virtual ~Tea(){
            cout << "Destrucxtor is called" << endl;
        }


};


class GreenTea : public Tea {
    public:
        GreenTea(int serve): Tea("GreenTea" , serve){
            cout << "GreenTea constructor is called" << endl;
        } 

        void brew() const override{
            cout << "Brewing " << teaName << " by steeping greem leaves" << endl;
        }

        ~GreenTea(){
            cout << "Green Tea Destructor is called" << endl;
        }
};

class MasalaTea : public Tea{
    public:
        MasalaTea(int serve): Tea("GreenTea" , serve){
            cout << "MasalaTea constructor is called" << endl;
        } 

        // Now the final keyword will not allow any other class to overridw the brew function using MasalaTea class 
        void brew() const override final{
            cout << "Brewing " << teaName << " with spices and milk" << endl;
        }

        ~MasalaTea(){
            cout << "Masala Tea Destructor is called" << endl;
        }

};




int main(){
    return 0;                   
}