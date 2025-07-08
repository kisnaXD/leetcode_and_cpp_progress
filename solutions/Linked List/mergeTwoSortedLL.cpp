#include <bits/stdc++.h>
using namespace std;

// Merge Two Sorted Linked Lists

class Node {
    public: 
    int data;
    Node* next;

    Node(int d, Node* n, Node* b) {
        data = d;
        next = n;
    }

    Node (int d) {
        data = d;
        next = nullptr;
    }
};

Node* mergeTwoLists(Node* l1, Node* l2) {
    Node* t1 = l1;
    Node* t2 = l2;
    Node* dN = new Node(-1);
    Node* temp = dN;
    while(t1!=nullptr && t2!=nullptr) {
        if(t1->data < t2->data) {
            temp->next = t1;
            temp = temp->next;
            t1 = t1->next;
        } else {
            temp->next = t2;
            temp = temp->next;
            t2 = t2->next;
        }
    }
    if(t1 == nullptr) {
        temp->next = t2;
    } else if(t2 == nullptr) {
        temp->next = t1;
    }
    Node* head = dN->next;
    delete dN;
    return head;
}

Node* convertToArray(vector<int> &arr, int N) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<N; i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
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
    v.push_back(5);
    v.push_back(7);
    v.push_back(8);
    v.push_back(12);

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(11);

    Node* tail = convertToArray(v1, 3);
    Node* head = convertToArray(v, 4);
    printLL(mergeTwoLists(head, tail));
    return 0;
}