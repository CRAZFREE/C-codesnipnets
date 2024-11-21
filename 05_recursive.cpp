#include<bits/stdc++.h>

using namespace std;

int sum = 0;
vector<vector<int>> subs(int index,vector<int> &arr, vector<int> &nums, int target){
    int n = nums.size();
    vector<vector<int>> ans;
    if(index >= n){
        if( sum == target){
            ans.push_back({arr});
            for(auto it : arr){
                cout<< it << " ";
            }
            cout<<endl;
        }
        // for( int i = 0; i < ans.size();i++){
        //     for(int j =0; j < ans[i].size();j++){
        //         cout << ans[i][j] << " ";
        //     }
        //     cout<<endl;
        // }
        // return;
    }
    sum = sum + arr[index];
    arr.push_back(nums[index]);
    subs(index+1,arr,nums,target);
    arr.pop_back();
    subs(index+1,arr,nums,target);
    return ans;
}

vector<vector<int>> substes(vector<int> &nums){
    vector<int> arr;
    int index = 0;
    int k = 4;
    vector<vector<int>> ans;
    ans = subs(0 , arr, nums,k);
    for( int i = 0; i < ans.size();i++){
            for(int j =0; j < ans[i].size();j++){
                cout<<"Print"<<endl;
                cout << ans[i][j] << " ";
            }
            cout<<endl;
        }
    return ans;

}

double myPow( double x, int n){
    if( n == 0){
        return 1;
    }
    if( n == 1){
        return x;
    }
    int nn = abs(n);
        double res = 1;
        res = myPow(x, nn-1);
        res = res * x;
    if( n > 0){
        return res;
    }
    else{
        if( n % 2){
            return (-1/res);
        }
        else{
            return 1/res;
        }
    }
    return res;
}

long long p (long long x, long long n){
    long long modu = 1000000007;
    if( x == 0){
        return 1;
    }
    if( n == 0){
        return 1;
    }
    if ( n == 1){
        return x;
    }

    if( n % 2){
        return (x * p(x,n-1)) % modu;
    }
    else{
        return (x * x * p(x,n/2 - 1)) % modu;
    }

}

// 4_5_4_5_ 
int countGoodNumbers(long long n) {
    // string s = to_string(n);
    long long digits = log2(n) + 1;
    // cout << digits << endl;
    long long res = 1;
    long long modu = 1000000007;
    long long evenCount = ceil(n/2);
    long long oddCount = floor(n/2);
    // for( int i = 0; i < digits; i++){
    //     if( i % 2 == 0){
    //         evenCount++; 
    //     }
    //     else{
    //         oddCount++;
    //     }
    // }
    cout << evenCount << endl;
    cout << oddCount << endl;
    if(evenCount){
        res = res * p(5,evenCount);
        res = res % 1000000007;
    }
    cout << res << endl;
    if(oddCount){
        res = res * p(4, oddCount);
        res = res % modu;
    }
    cout << res << endl;
    cout << ((5^25) * (4^25)) % modu;
    return res;
}






int main(){
    long long n;
    cin >> n;

    // double x;
    // cin >> x;

    // cout << myPow(x,n);

    cout << countGoodNumbers(n);

    // cout << p(x,n);

    // vector<int> arr;

    // for(int i = 0; i < n; i++){
    //     int nums;
    //     cin >> nums;
    //     arr.push_back(nums);
    // }

    // vector<vector<int>> ans;
    // ans = substes(arr);

    // for(int i =0; i < ans.size(); i++){
    //     for(int j = 0 ; j < ans[i].size(); j++){
    //         cout<< ans[i][j] << " ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}