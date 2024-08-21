#include<bits/stdc++.h>

using namespace std;

//{ Driver Code Starts
// #include<bits/stdc++.h>
// using namespace std; 

// } Driver Code Ends
// class Solution{
//     public:
//     //Function to count the frequency of all elements from 1 to N in the array.
//     void frequencyCount(vector<int>& arr,int N, int P)
//     { 
//         // code here
//         vector<int> count;
//         // copy(arr.begin(), N, count.begin());
//         count.insert(count.begin(), arr.begin(),arr.end());
        
//         for(int i=0;i<N;i++){
//             arr[i] =0;
//         }
        

//         for(int i =0;i<P;i++){
//             // arr[i]=0;
//             // cout<<count[i]-1<<" ";
//             if(count[i]-1<N)
//                 arr[count[i]-1] += 1;
//             // cout<<"Arr value "<<arr[count[i]-1]<<" ";
//         // }
//         }
//     }
// };


// //{ Driver Code Starts.

// int main() 
// { 
// 	long long t;
	
// 	//testcases
// 	cin >> t;
	
// 	while(t--){
	    
// 	    int N, P;
// 	    //size of array
// 	    cin >> N; 
	    
// 	    vector<int> arr(N);
	    
// 	    //adding elements to the vector
// 	    for(int i = 0; i < N ; i++){
// 	        cin >> arr[i]; 
// 	    }
//         cin >> P;
//         Solution ob;
//         //calling frequncycount() function
// 		ob.frequencyCount(arr, N, P); 
		
// 		//printing array elements
// 	    for (int i = 0; i < N ; i++) 
// 			cout << arr[i] << " ";
// 	    cout << endl;
// 	}	
// 	return 0; 
// }


 
//Driver Code Ends
// int countFrequency(int k, vector<int> a){
//     return 0;
// }

// int main(){
    // int n;
    // cin>>n;

    // vector<int> v;
    // vector<int> count(13,0);


    // //precompute
    // for(int i =0; i <n ;i++){
    //     int a;
    //     cin>>a;
    //     v.push_back(a);
    //     // count[v[a]] =+ 1; 
    // }



    // int q;
    // cin>>q;
    // while(q--){
    //     int key;
    //     cin>>key;
    //     cout<<count[key];
    //     cout<<"\n";
    // }
    // cout<<count[k]<<endl;
    // return 0;
    // for(int )
// }


//This is using vector for hashing
/*********************************************************************************
int main(){
    int n;
    cin >> n;
    
    vector<int> a;


    for(int i = 0;i <n;i++){
        int num;
        cin >> num;
        a.push_back(num); 
              
    }

    //precompute
    vector<int> hash(n,0);
    for(int i = 0;i < n; i++ ){
        cout<<a[i]<<" ";
        cout<<endl;
        hash[a[i]-1]++;
    }

    for(auto x : hash){
        cout<<x<<" ";
    }
    cout<<"\n";

    int q;
    cin >> q;
    while(q--){
        int key;
        cin>> key;
        cout<<hash[key-1]<<" ";
    }
    
    return 0;

}
*/

//using map for hashing
// int main(){
//     int n;
//     cin >> n;

//     map<int, int> mpp;
//     vector<int> a;

//     for(int i = 0;i < n; i++){
//         int num;
//         cin >> num;
//         a.push_back(num);
//     }

//     //precompute
//     for(int i =0 ;i<n;i++){
//         mpp[a[i]]++;
//     }

//     int q;
//     cin>>q;

//     while(q--){
//         int value;
//         cin >> value;

//         cout<<mpp[value]<<" ";
//     }


// }

//Frequency of Most Frequent Elemenet

int maxFrequency(vector<int> &nums, int k){
    int maxElement = nums[0] ;
    while(k){
        cout<<maxElement<<endl;
        cout<<k<<endl;
        for(int i = 0;i < nums.size(); ++i){
            if(maxElement < nums[i]){
                maxElement = nums[i];
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if( nums[i] == maxElement )
                continue;
            nums[i]++;
            k--;
            if(!k)
                break;
        }
        for(int i = 0;i < nums.size(); ++i){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
    return maxElement;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int k;
    cin >> k;

    int output = maxFrequency(arr,k);
    cout<<output;

    return 0;
}