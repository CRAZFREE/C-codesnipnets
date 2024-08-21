#include<bits/stdc++.h>

using namespace std;


//MAximum - BS, Dp, Greedy




//For a given cuboid we have Periimeter  = 4(l+b+h)
// Volume of a cuboid is V = l*b*h
// A = 2(lb + bh + lh )
// A = 2( l(b+h) + bh)
// A/2 - bh / ( b + h )
// l = A - 2bh / 2(b + h)
// A/2 - (lb + lh)
// b + h = (Perimeter - 4l) /4
// A = 2( l(Perimeter - 4l) /4 + bh)
// V = l * (A/2 - (lb + lh))
// V = lA/2 - l^2(b+h)
// (b + h) = P/4 - l
// V = lA/2 - l^2 (P/4 - l)
// V = lA/2 - l^2 P/4 - l^3
// dV/dl = A/2 - 2l P/4 - 3l ^ 2
//       = A/2 - lP/2 - 3l ^2
// To maximize dV/dl = 0
// 0 = A/2 - lP/2 -3l ^ 2
// 3l2 + lP/2 - A/2 = 0
// l = (P – (P2-24A)1/2) / 12 
// V = ((P – (P2-24A)1/2) / 12 )A/2 - ((P – (P2-24A)1/2) / 12)^2 P/4 - ((P – (P2-24A)1/2) / 12)^3

double maximumVolume(double Perimeter, double area){
        double P = perimeter;
        double A = area;
        double l = (P - sqrt(pow(P,2) - 24 * A)) / 12.0;
    
        // double V = l * (A /2.0 - l * ( (P / 4.0) - l));
        double V = ((P * l * l) - (8 * l * l * l)) / 4.0;

        return V;
}

    int countNumberswith4(int n) {
        // code here
        int copy = n;
        int count = 0;
        if(copy <= 10){
            return 1;
        }
        int r = 0;
        while(copy > 10){
            copy = copy / 10;
            r = copy % 10;
            
        }
        // int divisor = copy / 10;

    }

// int numTeams(vector<int>& rating) {
    // int n = rating.size();
// }



int main(){

    int n;
    cin >> n;

    int x = countNumberswith4(n);
    cout << x << endl;
    // double perimeter;
    // double area;

    // cin >> perimeter;
    // cin >> area;

    // double maximumVol = maximumVolume(perimeter,area);
    // cout<<setprecision(2)<< std :: fixed;
    // cout<<maximumVol<<endl;

}