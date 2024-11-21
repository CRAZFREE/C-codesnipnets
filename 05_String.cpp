#include <bits/stdc++.h>
using namespace std;

int getMaxOccurrences(string components, int minLength, int maxLength, int maxUnique) {
    unordered_map<string, int> substringFrequency;
    int maxFrequency = 0;

    // Loop over all possible lengths within the range [minLength, maxLength]
    for (int len = minLength; len <= maxLength; len++) {
        unordered_map<char, int> charCount;
        int uniqueChars = 0;
        
        // Initialize the first window of length 'len'
        for (int i = 0; i < len; i++) {
            charCount[components[i]]++;
            if (charCount[components[i]] == 1) uniqueChars++;
        }

        // Check if this initial substring satisfies the unique character constraint
        if (uniqueChars <= maxUnique) {
            string substring = components.substr(0, len);
            substringFrequency[substring]++;
            maxFrequency = max(maxFrequency, substringFrequency[substring]);
        }

        // Slide the window across the string
        for (int i = len; i < components.size(); i++) {
            // Remove the character going out of the window
            char leftChar = components[i - len];
            charCount[leftChar]--;
            if (charCount[leftChar] == 0) uniqueChars--;

            // Add the new character coming into the window
            char rightChar = components[i];
            charCount[rightChar]++;
            if (charCount[rightChar] == 1) uniqueChars++;

            // Check if the current window satisfies the unique character constraint
            if (uniqueChars <= maxUnique) {
                string substring = components.substr(i - len + 1, len);
                substringFrequency[substring]++;
                maxFrequency = max(maxFrequency, substringFrequency[substring]);
            }
        }
    }
    
    return maxFrequency;
}
int f(string &s){
    int max = s[1] - 48;
    int ind =1;
    for(int i = 2; i < s.length(); i++){
        int x = s[i] - 48;
        if ( max < x){
            max = x;
            ind = i;
        }
    }
    return ind;
}
int solution(string& a, string& b){
    if(a[0]<b[0]) return solution(b,a);
    int n = a.length();
    int cnt = 0;
    int j = 0;
    while(j < n && a[j] == b[j] ){
        j++;
    }
    if(a[j]<b[j]) return solution(b,a);

        for(int i = j + 1; i < a.length();i++) if(a[i]>b[i]) {
            // cout << a[i];
            swap(a[i],b[i]);
            cnt++;
        }
    // cout<<a;
    return min(cnt,n-cnt-j);
}

int main() {
    string s;
    string t;
    cin >> s;
    cin >> t;

    int ans = solution(s,t);


    cout << ans << endl;

    return 0;
}
