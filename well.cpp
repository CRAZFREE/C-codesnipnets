#include<bits/stdc++.h>

using namespace std;
string curr = "";
int f(int i , int j , string s1, string s2){
    // Base condition
    if( i < 0 || j < 0){
        cout << "====================\n";
        cout << curr << endl;
        cout << "====================\n";
        return 0;
    }

    // int x = 0;
    if(s1[i] == s2[j]){
        // cout << curr + s1[i] << endl;
        return (1 + f(i-1,j-1,s1,s2));
    }
    else{
        return max(f(i-1,j,s1,s2),f(i,j-1,s1,s2));
    }


}


int main(){
    string s1;
    string s2;

    cin>> s1;
    cin>> s2;

    int i = s1.size();
    int j = s2.size();

    cout << f(i-1,j-1,s1,s2);
}