// What is a function?
// Recursion
// When a function calls itself 
// until a specified condition is met
// BASE CONDITION
// 
#include<bits/stdc++.h>

// #include<iostream>
// #in/clude<vector>

using namespace std;

void fun1(long long m,long long product, int n){
    vector<long long> a;
    // long long product = a.end() - 1; 
    // long long product = 1;
    product = product * m;
    if(product > n){
        return ; 
    }
    a.push_back(product);
    fun1(m+1,product,n);
}

// return a vector 
// n = 21
// factorial <= n
// 1 2 6 


std::vector<long long> fun(int n){
    vector<long long> a;
    // cout<<n<<"\n";
    long long  m =1;
    long long product =1;
    fun1(m,product,n);
    return a;
}

//  vector<long long> a;



vector<long long> factorialNumbers(long long N, long long c)
    {
        // Write Your Code here
        vector<long long> a;
        if(N == 1){
            a.push_back(1);
            return a;
        }
        a = factorialNumbers(N-1,c);
        cout<<"N "<<N;
        long long num = N * a[N-2];
        if(num <= c){
            a.push_back(num);
        }
        return a;
    }

    vector<long long> factorialNumbers1(long long N){
    vector<long long> a;
    long long c = N;
    a = factorialNumbers(N,c);
    return a;
}


vector<int> reverseArray(int n, vector<int> &nums)
{
    // Write your code here.
    for(int i = 0, j = n-1 ; i <= n/2 , j >= i  ; i++ , j-- ){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    return nums;
}

string reverseArray(int i,string N,int M){
    if(i > M/2)
        return N;
    swap(N[i],N[M-i-1]);
    cout<<N;
    cout<<endl;
    reverseArray(i+1,N,M);
}

bool isPalindrome(int i, string N,int M){
    if(i >= M/2)
        return true;
    if(N[i] != N[M-i-1])
        return false;
    isPalindrome(i+1,N,M);
}

int main(){
    // long long N;
    // cin>>N;
    // vector<long long> v;
    // v = factorialNumbers1(N);
    // for(auto it : v){
    //     cout << it << " ";
    // }
    string s;
    cin>>s;
    int i = 0;
    int m = s.length();
    cout<<m<<endl;
    string W = reverseArray(i,s,m);
    cout<<W;
    return 0;
}



// StackOverFlow
// Segmentation Fault
// 