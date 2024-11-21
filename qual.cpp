#include<bits/stdc++.h>

using namespace std;

vector<int> f(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> arr1(n);
    if(k == 0){
        for(int i = 0; i < n; i++){
            arr[i] = 0;
        }
    }
    else if(k > 0){
        for(int i = 0; i < n; i++ ){
            int cnt = 0;
            int sum = 0;
            int j = i + 1;
            while(cnt != k){
                sum += arr[j];
                j++;
                j = j % n;
                cnt++;
            }
            arr1[i] = sum;
        }
    }
    else{
        for(int i = 0; i < n; i++){
            for (int j = i - 1; j > i - 1 - abs(k); j--) {
                    arr1[i] += arr[((j % n) + n) % n];
                }
            // arr1[i] = sum;
        }
    }
    return arr1;
}


int main(){
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> arr;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr.push_back(num); 
    }

    arr = f(arr,k);

    for(auto x : arr){
        cout << x << " ";
    }
}