#include<bits/stdc++.h>

using namespace std;

vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    while( k > 0){
        int mini = INT_MAX;
        int index = INT_MAX;
        cout << "array content  " ;
        for ( auto it : nums){
            cout << it << " ";
        }
        cout << endl;
        cout << "MINI " << mini << endl;
        cout << "Index "<< index << endl;
        for( int i = 0; i < nums.size(); i++){
            cout << "i " << i << endl; 
            if( mini > nums[i]){
                cout << "Running Minimum" << endl;
                mini = nums[i];
                cout << mini << endl;
                index = i;
                cout << index << endl;
            }
        }
        // cout << mini << endl;
        // cout << index << endl;
        nums[index] = nums[index] * multiplier;
        cout << nums[index] << endl;
        k--;
        mini = INT_MAX;
        index = INT_MAX;         
    }
    cout << "array content  " ;
    for ( auto it : nums){
        cout << it << " ";
    }
    cout << endl;
    return nums;
}

int generateKey(int num1, int num2, int num3) {
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        string s3 = to_string(num3);
        int i = 0;
        int key = 0;
        while(i < 4){
            cout <<" Index "<< i << endl;
            cout << s1[i] << endl;
            cout << s2[i] << endl;
            cout << s3[i] << endl;
            if( s1[i] == NULL ) 
                s1[i] = 0;
            if( s2[i] == NULL )
                s2[i] = 0;
            if( s3[i] == NULL )
                s3[i] = 0;
            cout << s1[i] << endl;
            cout << s2[i] << endl;
            cout << s3[i] << endl;
            // int a1 = atoi(s1)
            int num = min( s3[i], min(s2[i], s1[i]));
            cout <<"Number "<< num << endl;
            key = key * 10 + num;
            i++;
        }
        return key;
    }

int main(){

    int n;
    cin >> n;

    int k;
    cin >> k;

    int mul;
    cin >> mul;

    vector<int> nums;

    for( int i = 0;i < n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }

    nums = getFinalState(nums,k,mul); 
}