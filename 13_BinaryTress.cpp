#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//    1
// 2    7
//3      8
// 4    9
//5 6 10 11
void leftBoundary(TreeNode* root, vector<int>& ans){
    // vector<int> ans;
    if( root == NULL){
        return ;
    }
    if( root -> left == NULL && root -> right == NULL){
        return ;
    }
    ans.push_back(root -> val);
    // for( auto x : ans){
    //     cout << x << " ";
    // }    
    if( root -> left)
        leftBoundary(root -> left,ans);
    else{
        leftBoundary(root -> right,ans);
    }
    

    // return ans;
}

//    1
// 2    7
//3      8
// 4    9
//5 6 10 11
void rightBoundary(TreeNode* root, vector<int>& ans){
    if( root == NULL){
        return ;
    }
    if( root -> left == NULL && root -> right == NULL){
        return ;
    }
    
    // stack<TreeNode*> st;

    // st.push(root -> val);
    
    // for( auto x : ans){
    //     cout << x << " ";
    // }    
    if( root -> right)
        rightBoundary(root -> right,ans);
    else{
        rightBoundary(root -> left,ans);
    }
}


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if( root == NULL){
            return {};
        }

        if( (root -> left == NULL) && (root -> right == NULL) ){
            return {{root -> val}};
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        
        bool leftToRight = true;

        while(!q.empty()){
            
            //size of the queue
            int size = q.size();
            
            //vector to store the level wise traversal
            vector<int> a;

            //Traverse the node at each level 
            for( int i = 0; i < size; i++){
                TreeNode* currentNode = q.front();
                q.pop();

                //calculate the index
                int index = leftToRight ? i : (size - 1 - i);

                a[index] = currentNode -> val;

                if( currentNode -> left)
                    q.push( currentNode -> left);
                if( currentNode -> right)
                    q.push(currentNode -> right);
                // cout << cnt % 2 << endl;
                // if( cnt % 2 == 1 ){
                //     if( currentNode -> right)
                //         q.push(currentNode -> right);
                //     if( currentNode -> left)
                //         q.push( currentNode -> left);
                // }
                // else{
                //     cout << "This is left to right" << endl;
                //     if( currentNode -> left)
                //         q.push( currentNode -> left);
                //     if( currentNode -> right)
                //         q.push(currentNode -> right);
                // }
                // a.push_back(currentNode -> val);
                leftToRight = !leftToRight;

                ans.push_back(a);
            }
            // cnt = 0;
        }
        return ans;
    }




//    1
// 2    7
//3      8
// 4    9
//5 6 10 11
int main(){
    TreeNode* p = new TreeNode(1);
    TreeNode* q = new TreeNode(2);
    TreeNode* r = new TreeNode(7);
    TreeNode* s = new TreeNode(3);
    TreeNode* t = new TreeNode(8);
    TreeNode* u = new TreeNode(4);
    TreeNode* v = new TreeNode(9);
    TreeNode* w = new TreeNode(5);
    TreeNode* x = new TreeNode(6);
    TreeNode* y = new TreeNode(10);
    TreeNode* z = new TreeNode(11);

//    p
// q    r
//s      t
// u    v
//w x y z

    p -> left = q;
    p -> right = r;
    q -> left = s;
    r -> right = t;
    s -> right = u;
    t -> left = v;
    u -> left = w;
    u -> right = x;
    v -> left = y;
    v -> right = z;

    // vector<vector<int>> ans;
    // ans = zigzagLevelOrder(p); 
    // for( auto row : ans){
    //     for( auto x : row){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    stack<int> st;
    vector<int> ans;
    leftBoundary(p,ans);
    rightBoundary(p -> right,ans);
    for( auto x : ans){
        cout << x << " ";
    }
    return 0;
}