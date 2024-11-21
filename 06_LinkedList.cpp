#include<bits/stdc++.h>

using namespace std;


//Doubly Linked List
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1, Node* next1,Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* constructDLL(vector<int>& arr) {
        // code here
        Node* head = new Node(arr[0]);
        Node* p = head;
        int i = 1;
        while(i < arr.size()){
            Node* temp = new Node(arr[i], nullptr,p);
            p->next = temp;
            // temp -> prev = p;
            p = temp;
            i++;
        }
        return head;
    }

void print(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}



// Node* deleteNode(Node* head, int x) {
//         // Your code here


//         //if 0 or 1 node
//         if( head == NULL || head -> next == NULL){
//             return NULL;
//         }


//         Node* p =head;
//         int i = 0;
//         // delete the head
//         if( x == 1){
//             head = head -> next;
//             head -> prev = NULL;
//             p -> next = NULL;
//             free(p);
//             return head;
//         }
        
//         while( p != NULL){
//             i++;
//             if( i == x) break;
//             p = p->next;
//             // i++;
//         }
//         // delete the last node
//         if( p-> next == NULL){
//             Node* q = p -> prev;
//             q -> next = NULL;
//             p -> prev = NULL;
//             free(p);
//             free(q);
//             return head;
//         }
//         else{
//             Node* q = p -> prev;
//             Node* r = p -> next;
//             p -> prev -> next = r;
//             p -> next -> prev = q;
//             p -> next = NULL;
//             p -> prev = NULL;
//             // q -> next = NULL;
//             // free(r);
//             // free(q);
//             free(p);
//             return head;
//         }
//         return head;
//     }



Node* deleteNode(Node* head, int x) {
    // If the list is empty or x is invalid
    if (head == NULL || x <= 0) {
        return head;
    }

    Node* p = head;

    // Deleting the head node
    if (x == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(p);
        return head;
    }

    // Move to the x-th node
    for (int i = 1; i < x && p != NULL; i++) {
        p = p->next;
    }

    // If x is greater than the length of the list
    if (p == NULL) {
        return head;
    }

    // If we're deleting the last node
    if (p->next == NULL) {
        p->prev->next = NULL;
    } else {
        // Deleting a node in the middle
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    // Free the memory of the deleted node
    free(p);

    return head;
}



// struct Node{
//     int data;
//     Node* next;

//     Node(int data){
//         data = data;
//         next = NULL;
//     }
// };

Node* reverseList(Node* head){
    if( head == NULL || head -> next == NULL) return head;
        ListNode* newNode = reverseList(head -> next);
        ListNode* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newNode;
}

int main(){
    vector<int> arr = {12, 5, 8, 7};
    Node* head = constructDLL(arr);
    print(head);
    return 0;
}