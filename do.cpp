#include<bits/stdc++.h>

using namespace std;




bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Number of rows
    int row = matrix.size();

        //Number of columns
    int col = matrix[0].size() - 1;
    cout << col <<endl;


    for( int i = 0 ; i < row; i++ ){
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

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
        
    int low = 0;
    int high = m-1;

    int row = -1;
    int col = -1;

    int maxi = INT_MIN;

    while( low <= high){
        int mid = (low + high) / 2;

        for( int i = 0; i < n ; i++){
            if(maxi < mat[i][mid]){
                maxi = mat[i][mid];
                row = i;
                col = mid;
            }
        }
        //upper mat[i-1][mid] 
        //left mat[i][mid-1]
        //right mat[i][mid +1]
        //lower mat[i+1][mid]    
        if( mat[row -1][col] < mat[row][col] && mat[row][col - 1] < mat[row][col] && mat[row][col + 1] < mat[row][col] && mat[row + 1][col] < mat[row][col]){
            return { row,col};
        }
        if( mat[row][col -1] > mat[row][col]){
            high = mid - 1;
        }
        if( mat[row][col + 1] > mat[row][col]){
            low = mid + 1;
        }
    }
    return {};
}

int main(){
    int n;

    cin >> n;

    int m;
    cin >> m;

    // int target;
    // cin >> target;

    vector<vector<int>> arr;




    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j <= m; j++){
            int nums;
            cin >> nums;
            arr[i][j] = nums ;
        }
    }

    // cout << searchMatrix(arr,target);

    vector<int> mat(2);
    mat = findPeakGrid(arr);
    for ( auto x : mat ){
        cout << x << " ";
    }
    return 0;
}