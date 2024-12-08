#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = (high + low) / 2;
            cout << mid << endl;
            if(nums[mid] == target){
                return mid;
            }

            else if( nums[mid] < target){
                low = mid + 1;
            }

            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};


int main(){
    Solution sol;

    int n;
    cin >> n;

    int target;
    cin >> target;

    vector<int> nums;

    for(int i =0; i < n;i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }

    cout << sol.search(nums,target);

    return 0;
}