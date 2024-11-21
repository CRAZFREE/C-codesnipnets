#include<bits/stdc++.h>

using namespace std;

int countDigit(int n){
    int count;
    count = log10(n) + 1;
    return count;
}



int extractDigit(int n){
    int ed, newDigit=0;
    while(n>0){
        ed = n % 10;
        n = n / 10;
        newDigit = newDigit * 10 + ed; 
    }
    return newDigit;
}


int reverse(int n){
    if(n<0){
        int c = abs(n);
        c=(extractDigit(abs(c)))*-1;
        cout<<c;
    }
    else{
        cout<<extractDigit(n);
    }
}

// (sum)^d == number 
bool checkArmstrong(int n){
	//Write your code here
	int copy = n;
	int count_digit=0;
	count_digit = log10(copy) + 1;
	cout<<count_digit<<endl;
	int rem = 0;
	int arm = 0;
    int sum = 0;
	while(copy>0){
		rem = copy % 10;
		copy =copy / 10;
		cout<<"copy : "<<copy<<endl;
		cout<<rem<<endl;
		sum = (pow(rem,count_digit));
        cout<<"sum : "<<sum<<endl;
        arm = arm + sum; 
		cout<<arm<<endl;
	}
	if(arm == n)
		return true;
	else
		return false;
}

//36
// what all numbers which divides 36 
//1,2,3,4,6,9,12,18,36
//these are going to lie between 1 to 36 or we can say that it is between 1 to n
// so we can loop it from 1 to n
// this is taking big O of n time complexity
void printAllDivisors(int n){
    for(int i=1;i<=36;i++){
        // if i is completely dividing n then it is a divisor of n
        if(n % i == 0){
            cout<<i<<" "; 
        }
    }
}

void revisedDivisor(int n){
    int sq = sqrt(n);
    vector<int> div;
    // TC is O(sqrt(n))
    for (int i=1;i*i<=n ; i++){
        if(n % i==0){
            div.push_back(i);
            // cout<<i<<" ";
            if(n/i != i){
                div.push_back(n/i);
                // cout<< n/i << " ";
            }
        }
    }
    // n log n time (here n is number of factors)
    sort(div.begin(),div.end());
    // O(number of factors)
    for(auto it : div){
        cout<< it << " ";
    }
}

// Number which has 2 factor 1 and itself
// Checking for Prime
bool checkForPrime(int n){
    int count = 0;
    for (int i = 1; i * i <= n ; i++){
        if( n % i == 0){
            count++;
            if( n/i != i){
                count++;
            }
        }
    }
    // cout<< count <<endl;
    if(count == 2){
        return true;
    }
    else 
        return false;
    return false;
}

// Greatest Common Divisor GCD
// Highest Common Factor HCF
// Gcd(n1,n2) if n1 > n2
// gcd(20,15)
// gcd(5,15)
int GCD(int n1, int n2){
    if(n1 == 0 || n2 == 0){
        if(n1 == 0){
            return n2;
        }
        else 
            return n1;
    }
    if(n1 > n2){
        n1 = n1 - n2;
        return GCD(n1,n2); 
    }
    else
        n2 = n2 -n1;
        return GCD(n2,n1);
}

int minJumps(vector<int>& arr, int n){
        // Your code here
        int count = 0;
        if( arr[0] == 0){
            return -1;
        }
        for( int i = 0; i < n ;cout <<"index " << i << endl  ){
            
            cout <<"value at index " << arr[i] << endl;
            
            i = i + arr[i];
            count++;
            cout << count << endl;

        }
        return count;
}

int findComplement(int num) {
        if( num == 1){
            return 0;
        }
        if( num == 0){
            return 0;
        }
        int digits;
        digits = log2(num) + 1;
        cout << digits << endl;
        
        long long num2;
        cout << num2 << endl;

        return num ^ ;

    }


int main(){
    int n;
    cin>>n;

    // vector<int> arr;

    // for ( int i =0; i < n; i++){
        // int num;
        // cin >> num;
        // arr.push_back(num);
    // }

    cout << findComplement(n); 
    // cout<<checkArmstrong(n);
    // printAllDivisors(n);
    // revisedDivisor(n);
    // if(checkForPrime(n)){
        // cout << "Prime";
    // }
    // else    
        // cout<<"Not Prime";
    cout<<endl;
    // cout<<GCD(20,15);
    return 0;
}