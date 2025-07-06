#include <bits/stdc++.h>
using namespace std;

// Finding the intersection point of a Y Linked List

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

Node* intersectionOfYLinkedList(Node* h1, Node* h2) {
    Node* t1 = h1;
    Node* t2 = h2;
    if(h1 == nullptr || h2 == nullptr) {
        return nullptr;
    }
    while(t1!=t2) {
        t1 = t1->next;
        t2 = t2->next;
        if(t1==t2) {
            return t1;
        }
        if(t1 == nullptr) {
            t1 = h2;
        }
        if(t2 == nullptr) {
            t2 = h1;
        }
    }
    return t1;
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
    return 0;
}