#include<bits/stdc++.h>

using namespace std;
int mini = 1e9;
int f(int n,int m){
	if(n == 0)
		return 1;

	if(n < 0)
		return 0;
	cout << "Running " << endl;
	int x = 0;
	for(int i = m; i > 0; i--){
		x += f(n-i,m);
		
		
	}

	return x;
}

int k(int n,int m){
	return f(n,m);
}

int f(int i,int n,string s1, string s2){
	// Base condition

	//not take the ith index
	int notTake = 0 + f(i-1,n,s1,s2);

	int take = 0 + f();
	t
}


int main(){
	string s1,s2;

	cin >> s1;
	cin >> s2;

	int res = 0;
	int n = s1.size();
	res = f(n,n,s1,s2);
	return 0;
}