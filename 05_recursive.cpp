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
        return;
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

int main(){
    int n;
    cin >> n;

    vector<int> arr;

    for(int i = 0; i < n; i++){
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    vector<vector<int>> ans;
    ans = substes(arr);

    for(int i =0; i < ans.size(); i++){
        for(int j = 0 ; j < ans[i].size(); j++){
            cout<< ans[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}