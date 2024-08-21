#include<bits/stdc++.h>
using namespace std;

void explainPair(){
    pair<int,int> pair1 = {1,3};
    cout<<pair1.first<<" "<<pair1.second;
    cout<<endl;
    pair<int,pair<int,int>> pair2 = {1,{2,3}};
    cout<<pair2.first<<" "<<pair2.second.first<<" "<<pair2.second.second;
    cout<<endl;
    pair<int, int> pairArray[] = {{1,2},{3,4},{5,6}};
    cout<<pairArray;
    for(int i=0;i<3;i++){
        cout<<pairArray[i].first;
        cout<<endl;
    } 
}

void vec(){
    vector <int> vec1;
    vec1.push_back(1);
    vec1.emplace_back(2);

    vector <pair<int,int>> vec2;
    
    vec2.push_back({1,2});
    // No need of clury braces in emplace_back function while using pair
    vec2.emplace_back(3,4); 
    
    //Creates a vector of size 5 with default value as 100
    vector <int> vec3(5,100);
    //Creates a vector of size 5 with either default value as 0 or garbage value
    vector <int> vec4(5);
    //Creates a vector of size with the default values as 20
    vector <int> vec5(5,20);
    //Creates another container and copy the values of vector which is passed
    vector <int> vec6(vec5);


    //To access vector element just access with the array methods 
    //There is a way using at() function but generally it is not in practice
    cout<<vec1[1]<<" "<<vec1.at(0);

    vector<int> :: iterator it = vec6.begin();
    cout<<" "<<*it;

    it = it + 2;
    cout<<" "<<*it;
    cout<<endl;
    vector<int> v = {10,20,23,13};

    // v.erase(v.begin()+1);

    //When we want to delete multiple elements we should give the starting address
    //along with the address next to the last deleting element
    //[start,end)
    v.erase(v.begin()+1,v.end()-1); 

    for(auto it : v){
        cout<<it<<" ";
    }

    //Inserting

    vector<int> v1(2,100); // {100,100}
    v1.insert(v1.begin(),300); // {300,100,100}
    v1.insert(v1.begin()+1,2,10); // {300,10,10,100,100}
     
}

void explainList(){
    list<int> ls;

    ls.push_back(2);
    ls.emplace_back(4);
    ls.emplace_front(5);
    ls.push_front(3);
    //All functions are same as the vectors 

    for(auto it : ls){
        cout<<it<<" ";
    }
}

void explainDequeue(){
    deque<int> dq;

    dq.push_back(2);
    dq.emplace_back(4);

    dq.push_front(3);
    dq.emplace_front(5);

    dq.pop_back();
    dq.pop_front();

    //front() function is used to reference the first element of the deque container. 
    //back() function is used to reference the last element of the deque container.
    dq.back();
    dq.front();

    for(auto it : dq){
        cout<<it<<" ";
    }


}

void explainStack(){
    //Last in First Out
    //psuh , pop, top, size, empty
    stack<int> st;
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    //emplace similar to push
    st.emplace(7);

    cout<<st.top();
    
    st.pop();
    cout<<" "<<st.top();

    stack<int> st1 , st2;
    //swwaps the stack
    st1.swap(st2);
    //All operations are Big-Oh of 1

    
    
}



void explainQueue(){
    queue<int> q;
    //First In First Out
    q.push(1); //{1}
    q.push(2); //{1,2}
    q.push(3); //{1,2,3}
    q.emplace(4); //{1,2,3,4}

    //Add 5 to the last element of the queue i.e. 4
    q.back() +=5;

    cout<<q.back();
    cout<<q.front();

}

void explainPQ(){
    priority_queue<int> pq;

    //Mamimum value will be at top
    pq.push(1);
    pq.emplace(2);
    pq.push(3);
    pq.push(4);

    cout<<pq.top();
    // Minimum Heap
    priority_queue<int, vector<int>,greater<int>> pq1;
    pq1.push(2);
    pq1.push(5);
    pq1.push(1);
    pq1.emplace(3);

    cout<<pq1.top();
    //push, pop in logn and top in O(1)
}

void explainSet(){
    //only have the unique values inside it
    // stores everything in the sorted fashion
    //entire tree is maintained 
    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(5);
    st.emplace(6);//{1,2,3,4,5,6}

    //Functionallity of insert in vectors can be also used 
    //it just increases the efficiency

    //returns an iterator which points to the three
    auto ita = st.find(3);

    //return an iterator which points to st.end()
    //when the element is not present in the set
    auto itx = st.find(7);

    //deletes 5 and maintains the sorted order
    st.erase(5);
    //you can give the iterator to erase the element

    //it returns 1 if the element is there and 0 if the element is not there 
    int cnt = st.count(1);

    auto it1 = st.find(2);
    auto it2 = st.find(4);

    st.erase(it1,it2);
    
    //syntax
    // https://www.youtube.com/watch?v=edJ19qIL8WQ&t=0s
    // auto it = st.upper_bound(2);
    // auto it = st.lower_bound(2);

    //every function in set takes log(n) time


}

void explainMultiSet(){
    //only contain sorted not unique
    // it can have multiple occurence of elements

    multiset<int> ml;

    ml.insert(1); // {1}
    ml.insert(2);// {1,2}
    ml.emplace(2);//{1,2,2}
    ml.insert(3);//{1,2,2,3}

    //all 2 will get erased 
    ml.erase(2);
    ml.insert(3);

    int cot = ml.count(3);

    cout<<cot<<endl;

    for(auto p : ml){
        cout<<p<<" ";
    }

}

void explainUset(){
    unordered_set<int> us;
    //lower bounc and upper bound function does not work
    //rest all are same as above
    //Unique and rndomly stores the element no sorted manner
    //TC is O(1)
}

void explainMap(){
    
    //stores key and values correspond to those keys 
    //keys are unique
    //{key,val}
    //map stores unique keys in sorted order
    map<int, int> mp;
    map<int, pair<int,int>> mpp;
    map<pair<int,int>,int> mp1;

    mp[1]=2;
    // mpp.emplace({3,1});

    mp.insert({2,4});
    mp1[{1,2}]=10;

    for(auto k : mp){
        cout<<k.first<<" "<<k.second<<endl;
    }

    cout<<mp[1];
    cout<<endl;
    cout<<mp[4];

    //find, lower_bound and upper_bound are same


}

void explainMultiMap(){
    //same as map,but stores multiple keys
    //only map[key] cannot be used
}

void explainUnorderedMap(){
    //same as set and unorderd_set difference
}

bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    if(p1.first > p2.first) return true;
    return false;
}

void explainExtra(){

    //use the sort function to sort the array or the data 
    //a is the starting address of the array
    // a+n is the next address to the last element
    // sort(a,a+n);
    
    
    //same as the vector 
    //sort(v.begin(),v.end());

    // what if we want to sort the array in the descending manner
    // sort(a,a+n,greater<int>);

    //sort it according to increasing second element
    //if second element is same, then sort 
    //it according to the first element but in decreasing

    //This is my way kind of program 
    //for this we meed to write a user defined comp
    int n=3;
    pair<int,int> mypair[] = {{1,2},{2,1},{4,1}};


    sort(mypair,mypair+n,comp);

    cout<<"Hello"<<endl;
    
    for(auto q : mypair){
        cout<<q.first<<" "<<q.second<<endl;
    }

    //comp returns a boolean value 

    int num=7;
    int cnt = __builtin_popcount(num);

    cout<<cnt;
    cout<<endl;

    string s = "123";

    //if there are no more permutation it returns a false
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));

    pair<int,int> maxi = *(max_element(mypair,mypair+n));


}




int main(){
    // explainPair();
    // vec();
    // explainList();
    // explainDequeue();
    // explainStack();
    // explainQueue();
    // explainPQ();
    // explainSet();
    // explainMultiSet();
    // explainUset();
    // explainMap();
    explainExtra();
    return 0;
}