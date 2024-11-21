#include<bits/stdc++.h>

using namespace std;

int select(int arr[],int i,int n){
    // cout<<i<<endl;
    int min = i;
    // cout<<mi<<endl;
    // int m = sizeof(arr);
    // cout<<"m = "<<m<<endl;
    for(int j=i+1;j < n;j++){
        if(arr[j] < arr[min]){
                min = j;
        }
    }
    return min;
}

void selectionSort(int arr[], int n){
    int mini ,i =0 ;
    while(n != i){
        // cout<<n<<endl;
        // cout<<i<<endl;
        mini = select(arr,i,n);
        // cout<<mini<<endl;
        swap(arr[i],arr[mini]);
        i++;
        // cout<<mini<<"  "<<i<<endl;
        // for(int k =0 ; k < n; k++){
            // cout<< arr[k] <<" ";
        // }
        // cout<<endl;
    }
}

void bubbleSort(vector<int> &arr,int n){
    int max = 0;
    for(int i = 0; i < n-1; i++ ){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                max++;
            }
        }
        if(!max){
            break;
        }
    }

}

void insertionSort(vector<int> &arr,int n){
    for(int i =1;i<n;i++){
        cout<<i<<endl;
        for(int j = i-1; j >= 0; j--){
            if(arr[i] < arr[j]){
                swap(arr[i--],arr[j]);
            }
            cout<<"Step : "<<j<<endl;
            for(auto x : arr){
               cout<< x << " ";
            }
            cout<<endl;        
        }
    }
    cout<<"Yes\n";
}

//Less time
void insertionSortGFG(int arr[], int n)
    {
        //code here
        for(int i =1;i<n;i++){
        // cout<<i<<endl;
            int key = arr[i];
            int j = i - 1;
            
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    
    }

// int* merge(int arr[], int low, int mid,int high){
//     int left  = low;
//     int right = mid + 1;
//     int *temp;
//     while(left <= mid && right <= high ){
//         //second array element is less than the firtst element of first array
//         if(arr[left] < arr[right]){
//             //store it in temp
//             temp[left] = arr[left];
//             left++;            
//         }
//         else{
//             temp[right] = arr[right];
//             right++;
//         }
//     }
//     while(left > mid){
//         temp[right] = arr[right];
//         right++;
//     }
//     while(right > high){
//         temp[left] = arr[left];
//         left++;
//     }
//     return temp;
// }


// void mergeSort(int arr[], int low , int high){
//     if( low >= high) return;
//     int mid = low = high / 2;
//     mergeSort(arr, low, mid);
//     mergeSort(arr, mid + 1, high);
//     arr = merge(arr,low ,mid , high);
// }

void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int left = l;
         int right = m;
         vector<int> temp;
         while(left <= m && right <= r ){
             if(arr[left] < arr[right]){
                //  temp.push_back(left) = arr[left];
                 temp.push_back(arr[left]);
                 left++;
             }
             else{
                 temp.push_back(arr[right]);
                 right++;
             }
         }
         while(left > m){
            temp.push_back(arr[right]);
            right++;
         }
         while(right > r){
            temp.push_back(arr[left]);
            left++;
         }
         for(int i = l; i < r; i++){
             arr[i] = temp[i - l];
         }
    }
        // public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l >= r) return;
        int mid = l + r /2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }

int p(vector<int> &arr,int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j ){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }
        if(i < j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}




void qS(vector<int> &arr,int low, int high){
    if(low < high){
        int pivotIndex = p(arr,low,high);
        qS(arr,low,pivotIndex - 1);
        qS(arr,pivotIndex + 1,high);
    }
}



int main(){
    int n;
    cin >> n;

    vector<int> arr;
    int v[n];

    for(int i =0 ;i < n;i++){
        int num;
        cin>>num;
        v[i]=num;
        arr.push_back(num);
    }

    // for(int i = 0; i < n ; i++){
    //     cout<<v[i] << " " ;
    // }

    // cout << endl;

    // for(int i = 0;i < n; i++){
    //     int num;
    //     cin >> num;
    //     arr.push_back(num);
    // }

    // selectionSort(v,n);
    // bubbleSort(arr,n);
    // insertionSort(arr,n);
    // insertionSortGFG(v,n);
    mergeSort(v,0,n);
    // qS(arr,0,n-1);


    // for(int i = 0; i < n ; i++){
    //     cout<<v[i] << " " ;
    // }

    // cout<<endl;

    for(auto x : arr){
        cout<< x << " ";
    }

}
#include<bits/stdc++.h>

using namespace std;

int select(int arr[],int i,int n){
    // cout<<i<<endl;
    int min = i;
    // cout<<mi<<endl;
    // int m = sizeof(arr);
    // cout<<"m = "<<m<<endl;
    for(int j=i+1;j < n;j++){
        if(arr[j] < arr[min]){
                min = j;
        }
    }
    return min;
}

void selectionSort(int arr[], int n){
    int mini ,i =0 ;
    while(n != i){
        // cout<<n<<endl;
        // cout<<i<<endl;
        mini = select(arr,i,n);
        // cout<<mini<<endl;
        swap(arr[i],arr[mini]);
        i++;
        // cout<<mini<<"  "<<i<<endl;
        // for(int k =0 ; k < n; k++){
            // cout<< arr[k] <<" ";
        // }
        // cout<<endl;
    }
}

void bubbleSort(vector<int> &arr,int n){
    int max = 0;
    for(int i = 0; i < n-1; i++ ){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                max++;
            }
        }
        if(!max){
            break;
        }
    }

}

void insertionSort(vector<int> &arr,int n){
    for(int i =1;i<n;i++){
        cout<<i<<endl;
        for(int j = i-1; j >= 0; j--){
            if(arr[i] < arr[j]){
                swap(arr[i--],arr[j]);
            }
            cout<<"Step : "<<j<<endl;
            for(auto x : arr){
               cout<< x << " ";
            }
            cout<<endl;        
        }
    }
    cout<<"Yes\n";
}

//Less time
void insertionSortGFG(int arr[], int n)
    {
        //code here
        for(int i =1;i<n;i++){
        // cout<<i<<endl;
            int key = arr[i];
            int j = i - 1;
            
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    
    }

// int* merge(int arr[], int low, int mid,int high){
//     int left  = low;
//     int right = mid + 1;
//     int *temp;
//     while(left <= mid && right <= high ){
//         //second array element is less than the firtst element of first array
//         if(arr[left] < arr[right]){
//             //store it in temp
//             temp[left] = arr[left];
//             left++;            
//         }
//         else{
//             temp[right] = arr[right];
//             right++;
//         }
//     }
//     while(left > mid){
//         temp[right] = arr[right];
//         right++;
//     }
//     while(right > high){
//         temp[left] = arr[left];
//         left++;
//     }
//     return temp;
// }


// void mergeSort(int arr[], int low , int high){
//     if( low >= high) return;
//     int mid = low = high / 2;
//     mergeSort(arr, low, mid);
//     mergeSort(arr, mid + 1, high);
//     arr = merge(arr,low ,mid , high);
// }

void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int left = l;
         int right = m;
         vector<int> temp;
         while(left <= m && right <= r ){
             if(arr[left] < arr[right]){
                //  temp.push_back(left) = arr[left];
                 temp.push_back(arr[left]);
                 left++;
             }
             else{
                 temp.push_back(arr[right]);
                 right++;
             }
         }
         while(left > m){
            temp.push_back(arr[right]);
            right++;
         }
         while(right > r){
            temp.push_back(arr[left]);
            left++;
         }
         for(int i = l; i < r; i++){
             arr[i] = temp[i - l];
         }
    }
        // public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l >= r) return;
        int mid = l + r /2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }

int p(vector<int> &arr,int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j ){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }
        if(i < j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}




void qS(vector<int> &arr,int low, int high){
    if(low < high){
        int pivotIndex = p(arr,low,high);
        qS(arr,low,pivotIndex - 1);
        qS(arr,pivotIndex + 1,high);
    }
}



int main(){
    int n;
    cin >> n;

    vector<int> arr;
    int v[n];

    for(int i =0 ;i < n;i++){
        int num;
        cin>>num;
        v[i]=num;
        arr.push_back(num);
    }

    // for(int i = 0; i < n ; i++){
    //     cout<<v[i] << " " ;
    // }

    // cout << endl;

    // for(int i = 0;i < n; i++){
    //     int num;
    //     cin >> num;
    //     arr.push_back(num);
    // }

    // selectionSort(v,n);
    // bubbleSort(arr,n);
    // insertionSort(arr,n);
    // insertionSortGFG(v,n);
    mergeSort(v,0,n);
    // qS(arr,0,n-1);


    // for(int i = 0; i < n ; i++){
    //     cout<<v[i] << " " ;
    // }

    // cout<<endl;

    for(auto x : arr){
        cout<< x << " ";
    }

}