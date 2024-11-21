#include<bits\stdc++.h>

using namespace std;


class DisjointSet {
    private : 
    vector<int> rank, parent;

    public : 
    DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i = 0; i< n; i++){
            parent[i] = i;
        }
    }

    void unionByRank(int u, int v){
        int ultimateParentOfU = findParent(U);
        int ultimateParentOfV = findParent(v);
        // The nodes are already connected so no need to conect them
        if( ultimateParentOfU == ultimateParentOfV) return;
        else if( rank[ultimateParentOfU] < rank[ultimateParentOfV]){
            parent[ultimateParentOfU] = ultimateParentOfV;
        }
        else if( rank[ultimateParentOFV] < rank[ultimateparentOfU]){
            parent[ultimateParentOfV] = ultimateParentOfU;
        }
        else{
            // Make anyone as the leader and increase the rank of that node
            parent[ultimateParentOfV] = ultimateParentOfU;
            rank[ultimateParentOfU]++;
        }
    }

    int findParent)
}




int main(){
    DisjointSet ds(7);

}