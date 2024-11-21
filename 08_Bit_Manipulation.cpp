#include<bits/stdc++.h>

using namespace std;

bool isPowerOfTwo(int n) {
        int x = 0;
        int cnt = 0;
        int cnt0 = 0; 
        while( n > 0){
            x = n % 2 ;
            cout << x;
            n = n / 2;
            cnt++;
            if( x == 0){
                cnt0++;
            }
        }
        cout << x << endl; 
        if( x == 1 && (cnt0 == (cnt - 1))){
            return true;
        }
        return false;
}

int main(){
    int n;

    cin >> n;

    cout << isPowerOfTwo(n);
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

bool isPowerOfTwo(int n) {
        int x = 0;
        int cnt = 0;
        int cnt0 = 0; 
        while( n > 0){
            x = n % 2 ;
            cout << x;
            n = n / 2;
            cnt++;
            if( x == 0){
                cnt0++;
            }
        }
        cout << x << endl; 
        if( x == 1 && (cnt0 == (cnt - 1))){
            return true;
        }
        return false;
}

int main(){
    int n;

    cin >> n;

    cout << isPowerOfTwo(n);
    return 0;
}