#include <bits/stdc++.h>

using namespace std;



string removeOuterParentheses(string s) {
    string result;
    int n = s.size();
    stack<char> st;

    //push the outermost element onto the stack
    // ( pushed into stack
    // st.push(s[0]);

    //to store the top of the stack
    char x;

    for(int i = 0; i < n; i++ ){
        cout << i << endl;
    
        if( s[i] == '('){
            cout <<"Size ( " << st.size() << endl;

            //storing it on to the array result
            if( st.size() > 0){
                result.push_back(s[i]);        
            }    
            //pushing on to the stack
            st.push(s[i]);
             
        }
        else{
            cout <<"Size " << st.size() << endl;
            st.pop();
            if( st.size() > 0){
                result.push_back(s[i]);
            }
        }
    }
    return result;
}

string reverseWords(string s) {
    int n = s.size();
    string result;
    //to store the element
    stack<char> st;

    int spaces =0;
    for( int i = n -1; i >= 0; i--){
        
        if(s[i] != ' '){
            spaces = 0;
            st.push(s[i]);
        }
        else{
            if(spaces == 0){
                while(!(st.empty())){
                    result.push_back(st.top());
                    st.pop();
                }
                // char x = st.top();
                // result.push_back(x);
            }
            spaces++;
        }
        cout << result;
        // st.push(s[i]);
        // result.push_back(s[i]);'

        
    }
    return result;
}

string largestOddNumber(string num) {
    string str="";
        int n = num.size();
        int oddlen = 0;
        for( int i = 0 ; i < n ; i++){
            // cout << num[i] << endl;
            if( num[i] % 2 == 0){
                continue;
            }
            else{
                oddlen = i + 1;
                // cout << oddlen << endl;
            }
        }
        // cout << oddlen << endl;
        if( oddlen == 0){
            return "";
        }
        for( int i = 0; i < oddlen ; i++){
            str += num[i];
            // cout << str[i] << endl;
        }
        // cout << str << endl;
        return str;
}

int lengthOfAString(string s){
    int count = 1;
    int i = 0;
    while(s[i] != '/0'){
        count++;
        i++;
    }
    return count;
}

bool rotateString(string s, string goal) {
        int m = s.length();
        cout << m << endl;
        int n = m - 1;
        cout << n << endl;
        vector<char> temp(m); 
        while( n > 0){
            cout << "Running While " << endl;
            for( int i = 1; i < m; i++){
                temp[i-1] = s[i]; 
            }
            temp[n-1] = s[0];
            if( temp == goal){
                return true;
            }
            n--;
            cout << temp << endl;
        }
        return false;
    }

int main(){
    // int n;
    // cin >> n;

    string s;

    cin >> s;

    string goal;
    cin >> goal;

    // for(int i = 0; i < n; i++){
        // char ch;
        // cin >> ch;
        // s.push_back(ch);
    // }

    // cout << reverseWords(s);
    // cout << removeOuterParentheses(s);
    // cout << largestOddNumber(s);
    // cout << lengthOfAString(s);
    cout << rotateString(s,goal);
    cout << endl;

    return 0;
}