
#include<bits/stdc++.h> 
// #include<iostream>
using namespace std;
int binarySearch(vector<int>& nums, int low, int high, int target){
    if( low > high){
        return -1;
    }
    int mid = (low + high)/2;
    if(nums[mid] == target){
        return mid;      
    }
    else if(nums[mid] > target){
        high = mid -1;
        return binarySearch(nums,low,high,target);
    }
    else{
        low = mid + 1;
        return binarySearch(nums,low,high,target);
    }
}
int search(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int res = binarySearch(nums,low,high,target);
    return res;
}

int f(int i, int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if( i == 0 & j == 0) return 1;
        if( i < 0 || j < 0 )  return 0;
        if(obstacleGrid[i][j] == 1) return 0;
        if( dp[i][j] != -1) return dp[i][j];
        int up = f(i-1,j,obstacleGrid,dp);
        int left = f(i,j-1,obstacleGrid,dp);
        return dp[i][j] = (up + left);
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int> (n,-1));
    return f(m-1,n-1,obstacleGrid,dp);
}

long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        long long prefix =1;
        long long suffix = 1;
        int n = arr.size();
        long long ans = INT_MIN;
        long long m = 1e9 + 7;
        
        if( n == 1) return arr[0];
        
        for( int i = 0; i < n; i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            
            prefix = (prefix * arr[i]) % m;
            cout<<"prefix : "<<prefix<<endl;
            
            suffix = ( suffix * arr[n - i -1] ) % m;
            cout<<"suffix: "<<suffix<<endl;
            ans = max ( ans, max( prefix, suffix ));
            cout<<"max: "<<ans<<endl;

        }
        
        return ans;
    }

    // Given a sorted array arr[] of size n without duplicates,
    // and given a value x. Floor of x is defined as the
    // largest element k in arr[] such that k is smaller than or equal to x.
    // Find the index of k(0-based indexing). 
    // Lower bound arr[i] >= x.
    // 1 1 1 2 3 5 6
    // 1
int lower(vector<int>& arr, long long n, long long x){
    int low = 0;
    int high = n-1;
    int ans = n; 
    while( low <= high){
        int mid = (low + high) / 2;
        if( arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans; 
}

int upper(vector<int>& arr, long long n, long long x){
    int low = 0;
    int high = n-1;
    int ans = n; 
    while( low <= high){
        int mid = (low + high) / 2;
        if( arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans; 
}

int search1(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    while( low <= high){
        int mid = (low + high) / 2;
        if( nums[mid] == target)
            return mid;
        if( nums[low] < nums[mid]){
            if( nums[low] <= target && target <= nums[mid-1]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if( nums[mid + 1] <= target && target <= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }

        }
    }        
}

int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int mini = INT_MAX;
    int mid;
    int index = -1;
    while( low <= high){
        mid = (low + high) / 2;
        if( nums[low] <= nums[high]){
            if( nums[low] < mini){
                index = low;
                mini = nums[low];
            }
            // mini = min(mini,nums[low]);
            break;
        } 
        if( nums[low] <= nums[mid]){
            if( nums[low] < mini){
                index = low;
                mini = nums[low];
            }
            // mini = min(mini,nums[low]);
            low = mid + 1;
        }
        else if( nums[mid] <= nums[high]){
            if( nums[mid] < mini){
                index = mid;
                mini = nums[mid];
            }
            high = mid -1;
            // mini = min(mini, nums[mid]);
        }
    }
    // cout << mid << endl;
    return index;
}

vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int l =-1;
        int n = arr.size();
        int low = 0;
        int high = n -1;
        int f = -1;
        for( int i = 0; i < n; i++){
            if( arr[i] <= x){
                f = arr[i];
                cout <<"floor "<< f <<endl; 
                maxi = max(f,maxi);

            }
            if( arr[i] >= x){
                l = arr[i];
                mini = min(l,mini);
            }
        }
        if( mini == INT_MAX){
            mini = -1;
        }
        if( maxi == INT_MIN){
            maxi = -1;
        }
        return {maxi,mini};
    }

int findKRotation(vector<int> &arr) {
    // Code Here
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n; 
    while( low <= high){
        int mid = (low + high) / 2;
        if( arr[mid] > 0){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans; 
}

long long int floorSqrt(long long int x) 
    {
        // Your code goes here 
        long long int low = 1;
        long long int high = x;
        long long ans = 1;
        while(low <= high){
            long long int mid = (low + high)/ 2;
            if( mid * mid == x){
                return mid;
            }
            else if( mid * mid > x){
                high = mid - 1;
            }
            else{
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }


    vector<int> s;
    int mini = INT_MAX;
    // int count = 0;
void f(int index,int total_sum,int n,int d,vector<int>& arr, int sum1, int count){
    cout<<"index "<< index <<endl;
    int diff;
    //base case
    if ( index < 0) return ;
    if( index == 0) {
        // cout <<  "Inside print" <<endl;
        sum1 += arr[0];
        int sum2 = total_sum - sum1;
        diff = abs((sum1) - sum2);
        cout << "sum  " << sum1 <<endl;
        cout << "Difference " <<diff << endl;
        // mini = min ( mini,diff);
        if( mini > diff ){
            mini = diff;
            count += 1;
        }
        cout <<"mini "<< mini << endl;
        s.push_back(sum1);
        for(auto x :s){
            cout << x <<" ";
        }
        cout<<endl;
        cout <<"count " << count <<endl;
        return ;
    }

    cout << "NOT TAKE " << endl;
    f(index - 1,total_sum,n,d,arr,sum1,count);

    //pick
    // cout<<"pick " <<endl;
    cout << "TAKE " << endl;

    sum1 += arr[index];
    // diff = abs((2*sum1) - total_sum);
    
    // mini = min ( mini,diff);
    // cout <<"mini "<< mini << endl;   
    s.push_back(sum1);

    // cout <<"sum1 "<< sum1 <<endl;
    f(index-1,total_sum,n,d,arr,sum1,count);
    // sum1 -= arr[index];
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

        f(index,total_sum, n, d,arr,sum1,0);
        return 0;
}


int main(){
    // cout<<"Hello"<<endl;
    // int m;
    // cin >> m;

    int n;
    // long long n;

    cin >> n;

    int k;
    cin >> k;

    vector<int> arr;
    // vector<vector<int>> obstacleGrid;

    // for(int i = 0; i < m; i++){
    //     for(int j = 0 ; j < n; j++){
    //         int nums;
    //         cin >> nums;
    //         obstacleGrid[i][j] = nums ;
    //     }
    // }

    // cout << uniquePathsWithObstacles(obstacleGrid);
    for(int i = 0 ; i < n; i++){
        int num;
        cin >> num; 
        arr.push_back(num);
    }

    // int target;
    // cin >> target;

    // cout << search(arr,target);
    // cout<<findMaxProduct(arr);
    // int lb = lower(arr,n,k);
    // int ub = upper(arr,n,k);
    
    // if(lb == n || arr[lb] != k){
        // cout << "-1 -1";
    // }
    // else{
        // ub = ub - lb;
        // cout<<lb<<" "<<ub;
    // }
    // cout << search1(arr,k);
    // cout << findMin(arr);
    // cout << floorSqrt(n);
    cout << countPartitions(n,k,arr);
    // arr = getFloorAndCeil(k,arr); 
    // for(auto x : arr){
        // cout << x <<endl;
    // }
    // cout<<findKRotation(arr);
    return 0;
}





