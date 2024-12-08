// getter - gets you the values
// setter - sets the values

// convention get followed by the variable name in capitalised way
// getTeaName

#include<bits/stdc++.h>



using namespace std;

class Chai{
    private:
        string teaName;
        int servings;
        vector<string> ingredients;
    
    public:
        Chai(){
            teaName = "Unknown";
            servings = 1;
            ingredients = {"Tea Leaves", "Water"};
        }


        // getter for teaName
        string getTeaName(){
            return teaName;
        }

        // setter for teaNAme
        void setTeaName(string name){
            // logic 
            // To modify the input taken from the user
            teaName = name;
        }

        // getter for servings
        // setter for servings
        // getter for ingredients

        //setter for ingredients
        void setIngredients(vector<string>& ing){
            ingredients = ing;
        }

        void display(){
            cout <<"Tea Name : "< teaName << endl;
            cout <<"Number of cups : "< servings << endl;
            // cout <<"Tea Name : "< teaName << endl;
            
        }
};


int main(){
    Chai masalaChai("masala Chia", 3);
    
    return 0;
}