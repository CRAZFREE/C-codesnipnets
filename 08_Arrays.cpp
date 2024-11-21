#include<bits/stdc++.h>

using namespace std;

// Array 
// To find the largest and second largest element in the array we can move with three approaches
// 1. Sort the array and return the specific element asked
// 2. Find the largest element in O(N) and again find the second largest in O(N)
// 3. We can use 2 pointer to find the second largest element O(N)


int largestElementInAnArray(vector<int> &arr, int n){
    int largest = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}

//O(N)
int secondLargest(vector<int> &arr, int n){
    int largest = arr[0];
    int secondLargest = -1;
    for(int i = 1; i < n; i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
        else if(secondLargest < arr[i] && arr[i] < largest){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

//O(2N)
int modifiedSecondLargest(vector<int> &arr, int n){
    int largest = largestElementInAnArray(arr, n);
    // cout<<largest<<endl;
    int secondLargest = -1;
    for(int i = 0;i < n;i++){
        if(arr[i] > secondLargest && arr[i] != largest ){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

//O(N)
bool isSorted(vector<int> &arr, int n){
    // int sorted = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] >= arr[i-1]){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

int removeDuplicateElementsFromArray(vector<int> &arr, int n){
    //create a set dataStructure because it stores unique elements 
    set<int> st;
    for(int i = 0;i < n; i++ ){
        //insert in set takes O(log N)
        st.insert(arr[i]); 
    }
    int index = 0;
    for(auto it : st){
        arr[index] = it;
        index++;
    }
    //Overall Time Complexity for this brute force method is O(N log N) + O(N)
    return index;
}

//Two pointer approach from removing thw duplicate from the array
int uniqueElement(vector<int> &arr, int n){
    int i = 0;
    for(int j = 1; j < n;j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return (i+1);
}

//removing the duplicate
int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int size = nums.size();
        int right = 0;
        vector<int> arr;
        for(int i = 0;i < size ; i++){
            if(nums[i] != val){
                nums[right] = nums[i];
                right++;
            }
        }
        return right;
    }

//Left Rotate the Array
//1 2 3 4 5
//2 3 4 5 1
//3 4 5 1 2
//4 5 1 2 3
void leftRotate(vector<int> &arr,int k){
    // cout<<temp<<endl;
    int n = arr.size();
    while(k>0){
        int temp = arr[n-1];
        int i = 0;
        for(i = n-2; i >= 0; i--){
            arr[i+1] = arr[i];
        }
        arr[0] = temp;
        k--;
    }
    // int i = 0;
    // for( i = 1; i < n; i++){
        // arr[i-1] = arr[i];
    // }
    // arr[n-1] = temp;
    for(auto x : arr){
        cout<<x<<" ";
    }
}

//0 1 2 3 4 5 6
//1 2 3 4 5 6 7
//3
//1 2 3 
//4 5 6 7 5 6 7
//TC O(N)
//SC O(d)
void leftRotateByD(vector<int> &arr, int d){
    vector<int> temp;
    int n = arr.size();
    //copying
    for(int i = 0; i < d; i++){
        temp.push_back(arr[i]);
    }
    //shifting
    for(int i = d; i < n ; i++){
        arr[i-d] = arr[i];
    }
    //copying back to arr
    for(int i = n - d; i < n; i++){
        arr[ i ] = temp[i - (n - d)];
    }
    for(auto x : arr){
        cout << x << " "; 
    }

}

void leftRotateByDModified(vector<int> &arr, int d){
    int n = arr.size();
    d = d % n;
    reverse(arr.begin(),arr.begin() + d);
    reverse(arr.begin() + d,arr.end());
    reverse(arr.begin(),arr.end());
    for(auto x : arr){
        cout << x << " ";
    }
}

//2 1 3 4
void rightRotate(vector<int> &arr, int n){
    int temp = arr[n-1];
    int i;
    for(i = n-2; i >= 0; i-- ){
        arr[i+1] = arr[i];
    }
    arr[0] = temp;
    for(auto x: arr){
        cout << x << " ";
    }
}


//Function to rotate an array 
void Reverse(int arr[], int start, int end){
    while(start<=end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k % n; // Ensure k is within the range [0, n)

//         // Reverse the entire array
//         reverse(nums.begin(), nums.end());
        
//         // Reverse the first k elements
//         reverse(nums.begin(), nums.begin() + k);
        
//         // Reverse the rest of the elements after k
//         reverse(nums.begin() + k, nums.end());
//     }


//Right Rotate
void modifiedRightRotate(vector<int> &arr, int n, int k){
    k = k % n;
    
    // reverse()
}


//Solve this Problem later 
bool check(vector<int>& nums) {
        bool sorted = false;
        int n = nums.size();
        int count = 0;
        while(!sorted || (count != n) || (!sorted && (count != n)) ){
            cout<<"count is : "<<count<<endl;
            cout<<sorted<<endl;
            bool issorted = false;
            int temp = nums[0];
            for(int i = 1; i < n; i++){
                nums[i-1] = nums[i];
            }
            nums[n-1] = temp;
            for(auto x : nums){
                cout<< x << " ";
            }
            cout<<"\n";
            for(int i = 1; i < n; i++){
                if(nums[i - 1] <= nums[i]){
                    cout<<"sorted order\n";
                    issorted = true;
                }
                else{
                    cout<<"Not sorted";
                    issorted = false;
                    // break;
                }
            }
            if(issorted){
                sorted = true;
            }
            else{
                sorted = false;
            }
            count++;
        }
        return sorted;
    }

void Union(vector<int> &arr1, vector<int> &arr2){
    set<int> st;


    //let n1 be the size of arr1
    //O(n1 logn)
    for(int i =0 ;i < arr1.size();i++){
        st.insert(arr1[i]);
    }

    //let n2 bee the size of arr2
    //O(n2 logn)
    for(int i = 0; i < arr2.size(); i++){
        st.insert(arr2[i]);
    }

    vector<int> unionarr;
    //let n3 be the size of unionarr 
    //O(n3)
    for(auto it : st){
        unionarr.push_back(it);
    }


    //TC -> O(n1 logn) + O(n2 logn) + O(n3)
    //Worst case -> O(n1 log n1) + O(n2 log n2) + O(n1 + n2)
    for(auto it : unionarr){
        cout << it << " "; 
    }
}

void unionModified(vector<int> &arr1, vector<int> &arr2){
    int i = 0;
    int j = 0;
    int n = arr1.size();
    int m = arr2.size();
    vector<int> temp;
    while( i < n && j < m){
        if( arr1[i] <= arr2[j]){
            if( temp.size() == 0 || temp.back() != arr1[i]){
                temp.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if( temp.size() == 0 || temp.back() != arr2[j]){
                temp.push_back(arr2[j]);
            }
            j++;
        }
    }

    while( j < m){
        if( arr2[j] <= arr1[i]){
            if( temp.size() == 0 || temp.back() != arr2[j]){
                temp.push_back(arr2[j]);
            }
            j++;
        }
    }

    while( i < n){
        if( arr1[i] <= arr2[j]){
            if( temp.size() == 0 || temp.back() != arr1[i]){
                temp.push_back(arr1[i]);
            }
            i++;
        }
    }

    for(auto it : temp){
        cout<< it <<" ";
    }
}

void intersection(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int visited[n2] = {0};
    vector<int> intersect;
    //TC -> O(n1+n2)
    //SC -> O(n2) + O(n1+n2)
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(arr1[i] == arr2[j] && visited[j] != 1){
                intersect.push_back(arr1[i]);
                visited[j] = 1;
                break;
            }
            if( arr2[j] > arr1[i]){
                break;
            }
        }
    }
    for(auto x : intersect){
        cout << x << " ";
    }
}

void modifiedIntersection(vector<int> &arr1, vector<int> & arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> intersect;
    while(i < n1 && j < n2){
        if(arr1[i] == arr2[j]){
            intersect.push_back(arr1[i]);
            i++;
            j++;
        }
        else{
            if( arr1[i] < arr2[j]){
                i++;
            }
            else{
                j++;
            }
        }
    }
    for(auto x : intersect){
        cout << x << " ";
    }

}

int missingNumber(vector<int> & arr, int m){
    int n = arr.size();
    //T.C. -> O(n2)
    for(int i = 1; i <= m ; i++ ){
        int flag = 0;
        for(int j =0 ; j < n; j++){
            if( i == arr[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            return i;
        }
    }

}
int betterMissingNumber(vector<int> &arr, int m){
    
    vector<int> h(m+1,0);
    cout<<m+1<<endl;
    
    // hash<int> h[m+1];
    int n = arr.size();


    //TC -> O(N)
    for(int i = 0; i< n;i ++){
        // h[i] = 0;
        h[arr[i]] = 1;
        // cout<< arr[i] << " ";
        // cout << h[arr[i]] << " ";
        // cout<<endl;
    }
    // cout<<endl;
    //TC -> O(N)
    for(int i =1; i < m+1; i++){
        if(h[i] == 0){
            return i;
        }
    }
    return -1;
}

int optimalMissingNumber(vector<int> &arr, int m){
    int sum = ( m * ( m + 1 ) ) /2;
    int sum2 = 0;
    for(int i = 0 ; i < arr.size(); i++ ){
        sum2 = sum2 + arr[i];
    }
    return sum - sum2;
}

//XOR approaach
int optimalXORMissingNumber(vector<int> &arr , int m){
    int x = 0;
    for(int i = 1; i <= m ; i++ ){
        x =  x ^ i; 
    }
    int y = 0;
    for(int i = 0 ;i < arr.size(); i++){
        y = y ^ arr[i];
    }
    return (x ^ y);
}

//Find the lement that appears once and other elements appears twice
int consecutiveOnes(vector<int> &arr){
    int n = arr.size();
    int count = 0;
    for(int i = 0;i < n; i++){
        count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == arr[i]){
                count++;
            }
        }
        if(count == 1){
            return arr[i];
        }
    }
}

//Now for the above problem the TC is coming as O(n2) now this can be reduced
//to O(3n) using the hashing but can we use the hashing data structure everytime
//the answer to that is no because when the element size is very big say 10^12 or more 
// then we need to move to the map data structure

int hashFindOnce(vector<int> &arr){
    int n = arr.size();
    int max = arr[0];
    for(int i = 1; i < n; i++ ){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    vector<int> hash(max,0);

    for(int i =0; i < n; i++){
        hash[arr[i]]++;
    }

    for(int i = 0;i < n; i++){
        if(hash[arr[i]] == 1){
            return arr[i];
        }
    }
}

//Now when we are using the map data structure the TC varies for the unordered map
// and ordered map
// ordered map takes O(log n) for searching and insertion 
// Therefore the TC will be O(N log m) m is the size of the map
// In case of unordered map it will take O(N) but in worst case it can gp to O(N2)
// Which is very rare to happen

int mapFindOnce(vector<int> &arr){
    // int n = arr.size();

    // map<long long, int> mpp(n,0);

    // for(int i = 0 ; i < n; i++){
    //     mpp[arr[i]]++;
    // }

    // for(auto it : mpp){
    //     if(it.second == 1){
    //         return it.first;
    //     }
    // }
}

int XORFindOnce(vector<int> &arr){
    int n  = arr.size();
    int x = 0;
    for(int i = 0; i < n;i++){
        x = x ^ arr[i];
    }
    return x;
}

int firstMissing(vector<int> &arr, int n)
{
    // Write your code here.
    int x = 0;
    for( int i = 0; i < n; i++){
        x = x ^ i;
    }
    int y = 0;
    for( int i = 0; i < n; i++){
        if(arr[i] > -1){
            y = y ^ arr[i]; 
        }
    }
    return (x ^ y);
}

vector<int> twoSum(vector<int> &arr, int target){
    int n = arr.size();
    int i,j;
    vector<int> sol;
    for( i = 0 ; i < n; i++){
        int find = target - arr[i];
        for( j = i+1; j < n; j++){
            // cout<<find<<endl;
            // cout<<j<<endl;
            if( find == arr[j] ){
                sol.push_back(i);
                sol.push_back(j);
                return sol;
            }
        }
    }
    // return sol;
}

//TC -> o(N log N) O(N) O(N2)
//SC -> O(N)
bool twoSumHash(vector<int> &arr, int target){
    int n = arr.size();
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        int x = arr[i];
        int remain = target - arr[i];
        if( mpp.find(remain) != mpp.end()){
            return true;//return {mpp[more],i};
        }
        mpp[x] = i;
    }
    return false;
}

//2 pointer approach
//TC -> O(N) + O(nlogn) (while + sorting)
//SC -> O(N) (considering sorting)
int tooSum(vector<int> &arr, int target){
    sort(arr.begin(),arr.end());
    int i = 0;
    int j = arr.size() - 1;
    while( i < j ){
        int sum = arr[i] + arr[j];
        // cout << sum << endl;
        if(sum < target){
            i++;
        }
        else if(sum > target){
            j--;
        }
        else{
            return 1;
        }
    }
    return 0;
}


//Left Rotate Matrix K times
vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        int m = mat[0].size();
        int n = mat.size();
        k = k % m;
        int i = 0;
        int j = 1;
        cout << n << " " << m << " "<< k << " \n";
        while ( i < 3 ){
            // cout << i << endl;
             // Reverse the entire array
            reverse(mat[i].begin(), mat[i].end());

//         // Reverse the first k elements
            reverse(mat[i].begin(), mat[i].begin() + k);
        
//         // Reverse the rest of the elements after k
            reverse(mat[i].begin() + k, mat[i].end());
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                    cout << mat[i][j] << " ";
                cout << "\n";
            }
            // i++;
            // for(auto x : mat[i]){
                // cout << x << " ";
            // }
            // cout<<endl;
        }
        return mat;
    }

//Sort an array of 0's 1's and 2's
// 0 1 2 0 1 2 1 2 0 0 0 1
// 0 1 1 0 1 2 1 2 0 0 0 

// Dutch National Flag Algorithm
// We use three pointer
// low mid and high
// 0 - low -1 will be zzeros (extreme left)
// low - mid -1 will be ones 
// high + 1 - n will be twos (extreme right)
vector<int> dNFA(vector<int> &arr, int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap( arr[mid] , arr[low]);
            low++;
            mid++;
        }
        else if ( arr[mid] == 1){
            mid++;
        }
        else{
            swap( arr[mid], arr[high]);
            high--;
        }
    }
    return arr;
}

//Majority Element
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        for(int i =0 ;i < nums.size(); i++){
            mpp[nums[i]]++;
        }
        for( auto it : mpp){
            if(it.second > (nums.size() /2 )){
                return it.first;
            }
        }
    }

    int MVA(vector<int> &nums){
        int ele = 0;
        int cnt = 0;
        for(int i = 0 ;i < nums.size(); i++){
            if(cnt == 0){
                ele = nums[i];
                cnt = 1; 
            }
            else if( nums[i] == ele) {
                cnt++;            
            }
            else{
                cnt--;
            }

        }
        return ele;
    }

    //Kadane Algorithm
    int maxSubSum(vector<int> &arr){
        int maxi = INT_MIN;
        int sum = 0;
        int secEle = 0;
        int minEle = INT_MAX;
        int start;
        int end;
        int startele; 

        for(int i = 0; i < arr.size(); i++){
            if(sum == 0){
                start = i;
            }
            sum = sum + arr[i];
            if( sum > maxi){
                maxi = sum;
                startele = start;
                end = i;
                if(arr[i] < minEle){
                    secEle = minEle;
                    minEle = arr[i];
                }
                if(arr[i] < secEle && arr[i] > minEle){
                    secEle = arr[i];
                }
            }
            if(sum < 0 ){
                sum = 0;
            }

        }
        cout << startele << endl;
        cout << end << endl;
        cout << minEle << endl;
        cout << secEle << endl;
        return maxi;
    }


//Next Permutation
void nextPermutation(vector<int>& nums) {
        int index = -1;
        //Finding the break point
        for(int i = nums.size()-2;i >= 0; i-- ){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverse(nums.begin(),nums.end());
        }
        else{
            //Find the smallest greater element
            for(int i = nums.size()-1; i >= 0; i--){
                if( nums[i] > nums[index]){
                    swap(nums[i],nums[index]);
                    break;
                }
            }
            //reverse the rest of element form index+1
            reverse(nums.begin() + index + 1, nums.end());
        }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix){
    int col = 1;
    int n = matrix.size();
    int m = matrix[0].size();
    //iterating in the matrix to make the oth row and col as initializing
    for(int i = n; i > 0; i--){
        for(int j = m; j > 0; j-- ){
            if( matrix[i][j] == 0){
                matrix[i][0] = 0;
                if( j != 0){
                    matrix[0][j] = 0;
                }
                else{
                    col = 0;
                }
            }
        }
    }
    for(int i = n; i > 0; i--){
        for(int j = m; j > 0; j-- ){
            if( matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    if(matrix[0][0] == 0){
        //row 0 is to be zero
        for(int  j = 0 ; j < m; j++ ){
            matrix[0][j] = 0;
        }
    }
    if( col == 0){
        for(int i =0 ;i < n ;i++){
            matrix[i][0] = 0;
        }
    }
    return matrix;


}

int maxLen(vector<int> &arr, int n){
    int maxi = INT_MIN;
    int count = 0;
    for(int i = 0; i < n; i++){
        int xr = 0;
        count = 0;
        for( int j = i ; j < n ; j++){
            xr = xr + arr[j];
            count++;
            // cout<<count; 
            // cout<<endl;
            if(xr == 0 && maxi < count){
                maxi = count;
            }
        }
    }
    return maxi;
}


int minOperations(vector<string>& logs){
    stack<string> st;
    for(int i = 0 ; i < logs.size(); i++){
        if( logs[i] == "../"){
            st.pop();
        }
        else if( logs[i] == "./"){
            continue;
        }
        else{
            st.push(logs[i]);
        }
    }
    int count = 0;
    while(!(st.empty())){
        count = count + 1;
        st.pop();
    }

    return count ;
}

vector<int> subarraySum(vector<int> arr, int n, long long s) {
        // Your code here
        int start;
        int end;
        long long sum = 0;
        for ( int i = 0; i <= n; i++){
            cout << "Starting sum " << sum << endl;
            cout << i << endl;
            start = i;
            sum += arr[i] ;
            cout << "When Started sum is " << sum << endl;
            for( int j = i+1; j <= n ; j++){
                // cout << j <<endl;
                sum += arr[j];
                cout << "sum " << sum <<endl;
                if( sum == s){
                    end = j;
                    // break;
                    return {start,end};
                }
                if( sum > s){
                    sum = 0;
                    break;
                }
            }
        }
        return {-1};
    }

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> temp;
        for( int i = 0;i < queries.size(); i++){
            int initialCity = 0;
            int distance = 0;
            int totalDistance = n - 1;
            while (initialCity != queries[i][0]){
                distance++;
                initialCity++;
            }
            cout << "total distance " << totalDistance <<endl;
            cout << "distance covered " << distance <<endl;
            
            int rd = totalDistance - distance;
            cout << "remaining distance " << rd <<endl;

            
            int skip = queries[i][1] - queries[i][0] - 1;
            rd = rd - skip;
            cout << "Skip Distance " << skip <<endl;
            cout << "remaining distance " << rd <<endl;
            int fd = rd + distance; 
            temp.push_back(fd);
        }
        return temp;
    }

int maxSumOfTriplets(int N, vector<int> A){
        sort(A.begin(),A.end());
        int n = A.size();
        if (N == 1){
            return A[0];
        }
        if(N == 2){
            return A[0] + A[1];
        }
        int maxSum = 0;
        maxSum = A[n-1] + A[n-2] + A[n-3];
        return maxSum;
}

int main(){

    int n;
    cin >> n;

    // int m;
    // cin >> m;

    // int k;
    // cin >> k;

    // long long s;
    // cin >> s;

    // vector<vector<int>> mat(3,vector<int> (2));
        
    // for (int i = 0; i < 3; i++)
        // for (int j = 0; j < 2; j++)
            cin >> mat[i][j];
    
    vector<int> arr;
    // vector<int> arr2;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    

    // for(int i = 0; i < m; i++){
    //     int num;
    //     cin >> num;
    //     arr2.push_back(num);
    // }

    // int largestElement = largestElementInAnArray(arr,n);
    // int secondLargestElement = modifiedSecondLargest(arr,n);
    // cout<<isSorted(arr,n);
    // int uniqueElements = removeDuplicateElementsFromArray(arr,n);
    // int uniqueElements = uniqueElement(arr,n); 
    // leftRotateByD(arr,k);
    // leftRotateByDModified(arr,k);
    // if(check(arr)){
    //     cout<<"Array is sorted\n";
    // }
    // else{
    //     cout<<"Not ssorted\n";
    // }
    // rightRotate(arr,n);
    // unionModified(arr1,arr2);
    // intersection(arr1,arr2);
    // modifiedIntersection(arr1,arr2);
    // int x = missingNumber(arr1,m);
    // int x = betterMissingNumber(arr1, m);
    // int x = optimalMissingNumber(arr1,m);
    // int x = optimalXORMissingNumber(arr1,m);
    // int x = consecutiveOnes(arr1);
    // int x = hashFindOnce(arr1);
    // int x = mapFindOnce(arr1);
    // int x = XORFindOnce(arr1);
    // vector<int> x = twoSum(arr1,m);
    // int x = firstMissing(arr1,n);
    // bool x = twoSumHash(arr1,m);
    // int x = tooSum(arr1,m);
    // cout << x;
    // for(auto it : x){
        // cout << it << " ";
    // }
    // cout << secondLargestElement;
    // cout<<uniqueElements;
    // vector<vector<int>> ans = rotateMatrix(k, mat);
    // vector<int> ans = dNFA(arr, n);
    // int x = majorityElement(arr);
    // int x = MVA(arr); 
    // int x = maxSubSum(arr);
    // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < m; j++)
        // cout << ans[i] << " ";
        // cout << "\n";
    // }
    // int x = maxLen(arr,n);
    // cout << x;
    // arr = subarraySum(arr,n,s);
    arr = shortestDistanceAfterQueries(n,mat);
    for(auto x : arr){
        cout << x << " ";
    }
    cout<<endl;

    return 0;
}

//Write the same for the smallest Element
//Removes duplicated in-place from sorted array [Done]