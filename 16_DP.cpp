#include<bits/stdc++.h>

using namespace std;

int fib(int n){
    if(n < 2){
        return n;
    }

    return fib(n-1) + fib(n-2);
}

//To convert into DP 
//1. declare a vector.
//2. decalre the condition.
//3. return the recursive call in the form of vector.

int dpFib(vector<int> &dp, int n){
    if( n <= 1){
        return n;
    }

    if( dp[n] != -1) return dp[n];

    return dp[n] = dp[n-1] + dp[n-2];
}

int f(vector<vector<int>>& points, int n, int ind, int last, vector<vector<int>>& dp){
        int maxi = 0;
        // int m = points[0].size();
        if(ind == 0){
            // maxi = 0;
            for(int i = 0; i< 3; i++){
                if(i != last){
                    maxi = max ( maxi, points[0][i]);
                }
            }
            return maxi;
        }
        if( dp[ind][last] != -1) return dp[ind][last];
        maxi = 0;
        for(int i = 0 ;i < 3;i++){
            if( i != last){
                int point = points[ind][i] + f(points,n,ind -1,i,dp);
                maxi = max( maxi, point);
            }
        }
        return (dp[ind][last] = maxi);
    }

//DP on Subsequences
// Subsequences -> contigious and non contigious
// Follow the order
// Subset might or might not follow

//Problem 1
// Subset Sum equals to K
// 1. Approach -> Generate all subsequences and check if any of them gives a sum of K
// PowerSet or Recursion (Lec 8 / 6
//1. Express (index, target)
//2. explore the possibilities of that Index either include or exclude
//3. return true/ false

int f( int index, int target, vector<int>& nums ){

    //base case
    if( target == 0) return true;

    if( index == 0) return (nums[index] == target);

    //Explore all the possibilities 
    bool not_take = f(index - 1, target, nums);

    bool take = false;
    if( target >= nums[index]){
        take = f(index - 1,target - nums[index], nums);
    }
    return (take || not_take);
}

bool f(int index, vector<int>& nums, int target, vector<vector<int>>& dp){

        if( target == 0) return true;

        if( index == 0) return (nums[0] == target);

        if( dp[index][target] != -1) return dp[index][target];

        bool not_take = f(index - 1, nums,target,dp);

        bool take = false;

        if( target >= nums[index]){
            take = f( index - 1, nums, target - nums[index],dp);
        }

        return dp[index][target] = (take | not_take); 
}

int minimumDifference(vector<int>& nums) {
        
}

//5 2 6 4 
//s1 
//s2
//total_sum
//d = 3
//

    vector<int> s;
void f(int index,int total_sum,int n,int d,vector<int>& arr, int sum1){

    //base case
    if( index == -1) {
        cout <<  "Inside print" <<endl;
        sum1 += arr[0];
        s.push_back(sum1);
        for(auto x :s){
            cout << x <<" ";
        }
        cout<<endl;
    }
    f(index - 1,total_sum,n,d,arr,sum1);

    //pick
    sum1 += arr[index];
    // cout << sum1 <<endl;
    f(index-1,total_sum,n,d,arr,sum1);

    //not_pick
    // sum1 -= arr[index];
    // cout << sum1 << endl;
    // cout << sum1 << endl;
}

int countPartitions(int n, int d, vector<int>& arr) {
        // Code here

        int total_sum =0;
        for ( int i = 0; i < n; i++){
            total_sum += arr[i];
        }
        int index = n-1; 
        int sum1 = 0;

        f(index,total_sum, n, d,arr,sum1);
        return 0;
}

void sort012(vector<int>& a, int n)
    {
        // code here
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < n ;i++){
            if( a[i] == 0){
                count0++;
            }
            if( a[i] == 1){
                count1++;
            }
            if( a[i] == 2){
                count2++;
            }
        }
        cout << count0 << endl;
        cout << count1 << endl;
        cout << count2 << endl;
        
        int i = 0;
        for(; i < count0;i++){
            cout <<"ith Value "<< i << endl;
            a[i] = 0;
            cout << a[i] <<endl;
        }
        // cout << i << endl;
        for(int j = count0; j < count1;j++){
            cout <<"ith Value "<< j << endl;
            a[j] = 1;
        }
        for(; i <= count2;i++){
            a[i-1] = 2;
        }
    }

int f1(int index, int target, vector<int>& nums){
    if( index == 0){
        if(abs(target) == nums[0]){
            cout << "Target equal "<<endl;
            return 1;
        }
        // else if(abs(target) == nums[index] && target < 0 ){
        //     cout << "Target equal with neg "<<endl;
        //     return 1;
        // }
        else{
            cout << "Target " <<target <<endl;
            cout << "target not equal " << endl;
            return 0;
        }
    }

    cout << "Target " << target << " At index " << index << endl;
    // cout << index << endl;        


    //Running the -1
    cout << "Running the -1" <<endl;
    int negative = f1(index -1, target + nums[index], nums);
    cout <<"Result of -1 " << "Target " << target << " At index " << index <<" is "<< negative << endl;
    
    // cout << negative << endl;
    // target = target - nums[index];
    int positive = 0;
    cout << "Current target " << target << endl;
    // if(nums[index] <= abs(target)){
        cout << "Running the +1" << endl;
        positive = f1(index-1,target - nums[index],nums);
        // cout << positive <<endl;
        cout <<"Result of +1 " << "Target " << target  << " At index " << index <<" is "<< positive << endl;

    // }
    // else{
        // positive = 0;
    // }


    return (positive + negative); 
}
    
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();

    return f1(n-1, target, nums );
}


/*
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sumAll = accumulate(nums.begin(), nums.end(), 0);

        // If the absolute target is greater than sumAll, there's no solution
        if (abs(target) > sumAll) return 0;

        vector<int> dp(2 * sumAll + 1, 0);
        
        // Initial condition: There's one way to reach 0 with zero elements
        dp[sumAll] = 1;

        // Process each number in nums
        for (int num : nums) {
            vector<int> next(2 * sumAll + 1, 0);
            for (int j = 0; j <= 2 * sumAll; ++j) {
                if (dp[j] != 0) {
                    if (j + num <= 2 * sumAll) {
                        next[j + num] += dp[j];
                    }
                    if (j - num >= 0) {
                        next[j - num] += dp[j];
                    }
                }
            }
            dp = next;
        }

        return dp[target + sumAll];
    }
};
*/

int f(int index, vector<int>& coins, int amount){

    if( index == 0){
        return amount == coins[0];
    }


    int not_take = f( index - 1 , coins, amount);

    int take = 0;

    if (coins[index] <= amount);
        take = 1 + f(index, coins, amount - coins[index]);

    return (take + not_take);
}

int change( vector<int>& coins, int amount){
    int n = coins.size();
    int index = n - 1;

    return f(index , coins, amount);

}


int main() {
        int n;
        cin >> n;

        int d;
        cin >> d;
        
        vector<int> arr;

        for(int i = 0 ;i < n; i++){
            int num;
            cin >> num;
            arr.push_back(num);
        }
        
        
        // vector<vector<int>> points;
        // for (int i = 0; i < n; ++i) {
        //     vector<int> temp;
        //     for (int j = 0; j < 3; ++j) {
        //         int x;
        //         cin >> x;
        //         temp.push_back(x);
        //     }
        //     points.push_back(temp);
        // }

        // Solution obj;
        // int ind = points.size();
        // int last = points[0].size(); 
        // vector<vector<int>> dp( ind ,vector<int> (last+1,-1) );
        // cout << f(points, n, ind-1, last,dp) << endl;
        // cout << countPartitions(n,d,arr);
        // sort012(arr,n);
        cout << findTargetSumWays(arr,d);

        // for(auto x : arr){
            // cout << x << " ";
        // }

    
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int fib(int n){
    if(n < 2){
        return n;
    }

    return fib(n-1) + fib(n-2);
}

//To convert into DP 
//1. declare a vector.
//2. decalre the condition.
//3. return the recursive call in the form of vector.

int dpFib(vector<int> &dp, int n){
    if( n <= 1){
        return n;
    }

    if( dp[n] != -1) return dp[n];

    return dp[n] = dp[n-1] + dp[n-2];
}

int f(vector<vector<int>>& points, int n, int ind, int last, vector<vector<int>>& dp){
        int maxi = 0;
        // int m = points[0].size();
        if(ind == 0){
            // maxi = 0;
            for(int i = 0; i< 3; i++){
                if(i != last){
                    maxi = max ( maxi, points[0][i]);
                }
            }
            return maxi;
        }
        if( dp[ind][last] != -1) return dp[ind][last];
        maxi = 0;
        for(int i = 0 ;i < 3;i++){
            if( i != last){
                int point = points[ind][i] + f(points,n,ind -1,i,dp);
                maxi = max( maxi, point);
            }
        }
        return (dp[ind][last] = maxi);
    }

//DP on Subsequences
// Subsequences -> contigious and non contigious
// Follow the order
// Subset might or might not follow

//Problem 1
// Subset Sum equals to K
// 1. Approach -> Generate all subsequences and check if any of them gives a sum of K
// PowerSet or Recursion (Lec 8 / 6
//1. Express (index, target)
//2. explore the possibilities of that Index either include or exclude
//3. return true/ false

int f( int index, int target, vector<int>& nums ){

    //base case
    if( target == 0) return true;

    if( index == 0) return (nums[index] == target);

    //Explore all the possibilities 
    bool not_take = f(index - 1, target, nums);

    bool take = false;
    if( target >= nums[index]){
        take = f(index - 1,target - nums[index], nums);
    }
    return (take || not_take);
}

bool f(int index, vector<int>& nums, int target, vector<vector<int>>& dp){

        if( target == 0) return true;

        if( index == 0) return (nums[0] == target);

        if( dp[index][target] != -1) return dp[index][target];

        bool not_take = f(index - 1, nums,target,dp);

        bool take = false;

        if( target >= nums[index]){
            take = f( index - 1, nums, target - nums[index],dp);
        }

        return dp[index][target] = (take | not_take); 
}

int minimumDifference(vector<int>& nums) {
        
}

//5 2 6 4 
//s1 
//s2
//total_sum
//d = 3
//

    vector<int> s;
void f(int index,int total_sum,int n,int d,vector<int>& arr, int sum1){

    //base case
    if( index == -1) {
        cout <<  "Inside print" <<endl;
        sum1 += arr[0];
        s.push_back(sum1);
        for(auto x :s){
            cout << x <<" ";
        }
        cout<<endl;
    }
    f(index - 1,total_sum,n,d,arr,sum1);

    //pick
    sum1 += arr[index];
    // cout << sum1 <<endl;
    f(index-1,total_sum,n,d,arr,sum1);

    //not_pick
    // sum1 -= arr[index];
    // cout << sum1 << endl;
    // cout << sum1 << endl;
}

int countPartitions(int n, int d, vector<int>& arr) {
        // Code here

        int total_sum =0;
        for ( int i = 0; i < n; i++){
            total_sum += arr[i];
        }
        int index = n-1; 
        int sum1 = 0;

        f(index,total_sum, n, d,arr,sum1);
        return 0;
}

void sort012(vector<int>& a, int n)
    {
        // code here
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < n ;i++){
            if( a[i] == 0){
                count0++;
            }
            if( a[i] == 1){
                count1++;
            }
            if( a[i] == 2){
                count2++;
            }
        }
        cout << count0 << endl;
        cout << count1 << endl;
        cout << count2 << endl;
        
        int i = 0;
        for(; i < count0;i++){
            cout <<"ith Value "<< i << endl;
            a[i] = 0;
            cout << a[i] <<endl;
        }
        // cout << i << endl;
        for(int j = count0; j < count1;j++){
            cout <<"ith Value "<< j << endl;
            a[j] = 1;
        }
        for(; i <= count2;i++){
            a[i-1] = 2;
        }
    }

int f1(int index, int target, vector<int>& nums){
    if( index == 0){
        if(abs(target) == nums[0]){
            cout << "Target equal "<<endl;
            return 1;
        }
        // else if(abs(target) == nums[index] && target < 0 ){
        //     cout << "Target equal with neg "<<endl;
        //     return 1;
        // }
        else{
            cout << "Target " <<target <<endl;
            cout << "target not equal " << endl;
            return 0;
        }
    }

    cout << "Target " << target << " At index " << index << endl;
    // cout << index << endl;        


    //Running the -1
    cout << "Running the -1" <<endl;
    int negative = f1(index -1, target + nums[index], nums);
    cout <<"Result of -1 " << "Target " << target << " At index " << index <<" is "<< negative << endl;
    
    // cout << negative << endl;
    // target = target - nums[index];
    int positive = 0;
    cout << "Current target " << target << endl;
    // if(nums[index] <= abs(target)){
        cout << "Running the +1" << endl;
        positive = f1(index-1,target - nums[index],nums);
        // cout << positive <<endl;
        cout <<"Result of +1 " << "Target " << target  << " At index " << index <<" is "<< positive << endl;

    // }
    // else{
        // positive = 0;
    // }


    return (positive + negative); 
}
    
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();

    return f1(n-1, target, nums );
}


/*
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sumAll = accumulate(nums.begin(), nums.end(), 0);

        // If the absolute target is greater than sumAll, there's no solution
        if (abs(target) > sumAll) return 0;

        vector<int> dp(2 * sumAll + 1, 0);
        
        // Initial condition: There's one way to reach 0 with zero elements
        dp[sumAll] = 1;

        // Process each number in nums
        for (int num : nums) {
            vector<int> next(2 * sumAll + 1, 0);
            for (int j = 0; j <= 2 * sumAll; ++j) {
                if (dp[j] != 0) {
                    if (j + num <= 2 * sumAll) {
                        next[j + num] += dp[j];
                    }
                    if (j - num >= 0) {
                        next[j - num] += dp[j];
                    }
                }
            }
            dp = next;
        }

        return dp[target + sumAll];
    }
};
*/

int f(int index, vector<int>& coins, int amount){

    if( index == 0){
        return amount == coins[0];
    }


    int not_take = f( index - 1 , coins, amount);

    int take = 0;

    if (coins[index] <= amount);
        take = 1 + f(index, coins, amount - coins[index]);

    return (take + not_take);
}

int change( vector<int>& coins, int amount){
    int n = coins.size();
    int index = n - 1;

    return f(index , coins, amount);

}


int main() {
        int n;
        cin >> n;

        int d;
        cin >> d;
        
        vector<int> arr;

        for(int i = 0 ;i < n; i++){
            int num;
            cin >> num;
            arr.push_back(num);
        }
        
        
        // vector<vector<int>> points;
        // for (int i = 0; i < n; ++i) {
        //     vector<int> temp;
        //     for (int j = 0; j < 3; ++j) {
        //         int x;
        //         cin >> x;
        //         temp.push_back(x);
        //     }
        //     points.push_back(temp);
        // }

        // Solution obj;
        // int ind = points.size();
        // int last = points[0].size(); 
        // vector<vector<int>> dp( ind ,vector<int> (last+1,-1) );
        // cout << f(points, n, ind-1, last,dp) << endl;
        // cout << countPartitions(n,d,arr);
        // sort012(arr,n);
        cout << findTargetSumWays(arr,d);

        // for(auto x : arr){
            // cout << x << " ";
        // }

    
    return 0;
}