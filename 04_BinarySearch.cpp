#include<bits/stdc++.h>

using namespace std;


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

int multi(int mid, int n, int m){
	   long long ans = 1;
	   for( int i = 1; i <= n; i++){
	       ans = ans * mid;
        //    cout << ans << endl;
	       if( ans > m) return 2;
	   }
	   if( ans == mid) return 1;
	   return 0;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int low = 1;
        int high = m;
        while(low <= high){
            int mid = (low + high)/ 2;
            int ans = multi(mid,n,m);
            // cout <<"In main " << mid << endl;
             
            // cout <<"In ans main "<< ans << endl;
            if( ans == 1){
                return mid;
            }
            else if( ans == 2){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
	}

bool isPossible(vector<int>& bloomDay, int day, int m, int k){
    int count = 0;
    int noB = 0;
    for( int i = 0; i < bloomDay.size(); i++){
        if( bloomDay[i] <= day){
            count++;
        }
        else{
            noB += count/k;
            count = 0;
        }
    }
    noB += count/k;
    if(noB >= m){
        return true;
    }
    return false;
}
// 1 10 3 10 2
//1 2 3 4 5 6 7 8 9 10
int minDays(vector<int>& bloomDay, int m, int k) {
    int low = *min_element(bloomDay.begin(),bloomDay.end());

    int high = *max_element(bloomDay.begin(),bloomDay.end());

    while( low <= high){
        int mid = (low + high) / 2;

        if( isPossible(bloomDay,mid,m,k)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
        
    }
    return low;         
}


int f(vector<int>&arr, int pages , int m){
    int student = 1;
    int pagesPerStudent = 0;
    int n = arr.size();

    cout << m << endl;

    for( int i = 0; i < n; i++){
        if( pagesPerStudent + arr[i] <= pages){
            pagesPerStudent += arr[i];
            cout << "Student " << student << " Get " << pagesPerStudent << endl;
        }
        else{
            cout << "else part " << endl;
            student++;
            pagesPerStudent = arr[i];
            cout << "Student " << student << " Get " << pagesPerStudent << endl;
        }
    }
    return student;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if ( m > n ){
        return -1;
    }
    if ( m == n){
        return *max_element(arr.begin(),arr.end());
    }
    int low = *max_element(arr.begin(),arr.end());
    cout << low << endl;
    int high = 0;

    for( int i = 0; i < n; i++){
        high = high + arr[i];
    }

    cout << high << endl;

    // int high = 2 * low;
    int studentCount = 0;
    int ans = -1;
    while( low <= high){
        int mid = (low + high) / 2;
        cout << mid << endl;
        studentCount = f(arr,mid,m); 
        if ( studentCount > m){
            // ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
    // while(low <= high){
        // int mid = (high + low) / 2;
        
    // }
}

bool check( vector<int>& nums,int sum,int k){
        int partition = 1;
        int n = nums.size();
        int sumpersubset = 0;
        // cout << "Sum " << sum << endl;
        // cout << "For before "<< endl;
        for (int i = 0; i < n; i++){
            // cout << "For After  "<< endl;

            // cout << " 1" << endl;

            // cout << "index " << i << endl;
            if( sumpersubset + nums[i] <= sum){
                sumpersubset += nums[i];
                // cout <<"Sum per Subset is "<< sumpersubset << endl;
            }
            else{
                partition += 1;
                sumpersubset = nums[i];
            }
            // cout << "partition " << partition <<endl;
            if ( partition > k){
                return true;
            }
        }
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *max_element(nums.begin(),nums.end());

        int high = accumulate(nums.begin(),nums.end(),0);

        int ans = 0;

        while( low <= high){
            int mid = ( low + high ) / 2;
            // cout << mid << endl;
            // cout << "Low " << low << endl;
            // cout << "High " << high << endl;
            if( check(nums, mid, k) == true){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        } 
        return low;
    }

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Number of rows
        int row = matrix.size();

        //Number of columns
        int col = matrix[0].size() - 1;
        cout << col <<endl;


        for( int i = 0 ; i < row; i++ ){
                // int col = matrix[i].size() -1;
                if( target == matrix[i][col]){
                    return true;
                }
                if( target < matrix[i][col]){
                    col--;
                }
                else{
                    i++;
                }
        }
        return false;
    }    


int main(){
    // cout<<"Hello"<<endl;
    // int m;
    // cin >> m;

    int n;

    cin >> n;

    int m;
    cin >> m;

    int target;
    cin >> target;

    // vector<int> arr;
    vector<vector<int>> arr;

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            int nums;
            cin >> nums;
            arr[i][j] = nums ;
        }
    }

    cout << searchMatrix(arr,target);

    // cout << uniquePathsWithObstacles(obstacleGrid);
    // for(int i = 0 ; i < n; i++){
        // int num;
        // cin >> num; 
        // arr.push_back(num);
    // }

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
    // cout << NthRoot(n,k);
    // cout << minDays(bloomDay,m,k);
    // cout << findPages(arr,n,k);
    // cout << splitArray(arr,k);
    // arr = getFloorAndCeil(k,arr); 
    // for(auto x : arr){
        // cout << x <<endl;
    // }
    // cout<<findKRotation(arr);
    return 0;
}