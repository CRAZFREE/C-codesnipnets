
#include<bits/stdc++.h>
using namespace std;

void pattern5(int n){
	for (int k = 0 ; k < (2*n-1) ; k++){
    for(int j = 0; j < (2*n-1) ; j++){
      int top = k;
      int bottom = (2*n-1) - 1 - k;
      int left = j;
      int right = (2*n-1) - 1 - j;
      cout<<(n - min(min(top,bottom),min(left,right))); 
    }
    cout<<endl;
  }
}


int main(){
  int n;
  cin>>n;
  pattern5(n);
  return 0;
}
