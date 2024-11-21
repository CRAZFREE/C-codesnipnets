#include<bits/stdc++.h>

using namespace std;


bool isValid(string s) {
    int n = s.length();
    stack<char> st;
    for( int i = 0; i < n; i++){
        if( s[i] == '[' || s[i] == '{' || s[i] == '('){
            st.push(s[i]);
        }
        else{
            if(!st.empty()){
                char x = st.top();
                cout << st.top() << endl;
                if( (s[i] == ')' && x == '(') || (s[i] == ']' && x == '[') || (s[i] == '}' && x == '{') ){
                    st.pop();
                    // return true;
                }
                else{
                    return false;
                }
            }
            if( i == n){
                return false;
            }
        }

    }
    cout << st.empty() << endl;
    if( st.empty())
        // cout <<" True "<< endl;
        return true;
    return false;
}

string infixToPrefix( string exp){
    int n = exp.size();
    stack<char> st;
    string ans = "";

    for( int i = n -1; i >= 0; --i){
        char ch = exp[i];
        // cout <<"current char " << ch<<endl;  
        if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            // cout << "Outer if" << endl;
            ans = ch + ans;
            // cout << ans << endl;
        }
        else{
            if( ch != '('){
                // cout << "Inner if "<< endl;
                st.push(ch);
            }
            else{
                while( st.top() != ')'){
                    // cout << "Inner else" << endl;
                    char x = st.top();
                    // cout <<"Top of stack "<< x << endl;
                    ans = x + ans;
                    // cout << ans << endl;
                    st.pop();
                }
                // cout << "Top of stack after " << st.top() << endl;
                st.pop();
            }
        }
    }
    while(!st.empty()){
        char x = st.top();
        ans = x + ans;
        st.pop();
    }
    return ans;
}

int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int mini;
        int modu = 1e9 + 7;
        for( int i = 0; i < n ; i++){
            for( int j = 0 ; j <= i; j++){
                mini = INT_MAX;
                for( int k = j; k <= i; k++){
                    mini = min(arr[k], mini);
                }
                sum += mini;
                sum = sum % modu;
            }
            // sum += mini;
        }
        return sum;
    }

//Using Monotonic Stack
int sumMins(vector<int>& arr){
    int n = arr.size();
    vector<int> pse(n,-1);
    vector<int> nge(n,-1);
    stack<int> st;



    for(int i = 0; i < n; i++){
        {
            int size = st.size();
            for(int i = 0; i < size ; i++){
                cout << i << " ";
            }
            cout << endl;
        }
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }

        if(!st.empty()){
            pse[i] = st.top();
        }

        st.push(arr[i]);
    }


    for(auto x : pse){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}


int main(){
    // string s = "(A-(B/C))*((A/K)-L)";
    // cout << isValid(s);
    // cout << infixToPrefix(s);

    int n;
    cin >> n;

    vector<int> arr;

    for( int i = 0; i< n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    cout << sumMins(arr);

    // int num1;
    // cin >> num1;

    // int num2;
    // cin >> num2;

    // int num3;
    // cin >> num3;

    // cout << generateKey(num1 , num2, num3);

    return 0;

}