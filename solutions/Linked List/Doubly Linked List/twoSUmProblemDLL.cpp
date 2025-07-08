#include <bits/stdc++.h>
using namespace std;

// Finding pairs with a given sum in a sorted Doubly Linked List

class Node {
    public: 
    int data;
    Node* next;
    Node* back;

    Node(int d, Node* n, Node* b) {
        data = d;
        next = n;
        back = b;
    }

    Node (int d) {
        data = d;
        next = nullptr;
        back = nullptr;
    }
};

vector< pair<Node*, Node*> > twoSumProblemDLL(Node* head, int K) {
    Node* mover = head;
    Node* end = head;
    int c1 = 1;
    int c2 = 1;
    vector< pair<Node*, Node*> > v;
    while(end->next!=nullptr) {
        end = end->next;
        c2+=1;
    }
    while(c2>c1) {
        int sum = mover->data + end->data;
        if(sum == K) {
            pair<Node*, Node*> p;
            p.first = mover;
            p.second = end;
            v.push_back(p);
            mover = mover->next;
            end = end->back;
            c2--;
            c1++;
        } else if (sum < K) { 
            mover = mover->next;
            c1 ++;
        } else {
            end = end->back;
            c2 --;
        }
    }
    return v;
}

Node* convertToArray(vector<int> &arr, int N) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<N; i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}

void printLL(Node* head) {
    Node* mover = head;
    while(mover!=nullptr) {
        cout << mover->data;
        cout << " ";
        mover = mover->next;
    }
    cout << endl;
}

int main() {
    vector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(9);
    v.push_back(12);
    v.push_back(13);

    Node* head = convertToArray(v, 5);
    vector< pair<Node*, Node*> > v1 = twoSumProblemDLL(head, 17);
    for( auto it: v1) {
        cout << it.first->data << " " << it.second->data << endl;
    }
    return 0;
}