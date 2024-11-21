#include<bits/stdc++.h>

using namespace std;


int componentOfGraph( vector<vector<int>> bg, int vertex){
    int size = vertex;

    visited[size] = {0};

    //push into the queue
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int s = q.size();
        
        for( int i = 0; i < s ; i++){
            
        }
    }

}



int main(){
    int vertex;

    cin >> vertex;

    vector<vector<int>> bg(n);

    for( int i = 0; i < n;i++){
        bg[i].resize(2);
        for( int j = 0; j < 2 ; j++){
            cin >> bg[i][j];
        }
    }

    int result = componentsInGraph(bg);

    cout << result << endl;

    return 0;
}