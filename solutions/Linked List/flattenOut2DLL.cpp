#include <bits/stdc++.h>
using namespace std;

// Flatten Out a 2D Linked List

class Node {
    public: 
    int data;
    Node* next;
    Node* child;

    Node(int d, Node* n, Node* c) {
        data = d;
        next = n;
        child = c;
    }

    Node (int d) {
        data = d;
        next = nullptr;
        child = nullptr;
    }
};

Node* mergeTwoVertically(Node* l1, Node* l2) {
    Node* dN = new Node(-1);
    Node* t = dN;
    while(l1!=nullptr && l2!= nullptr) {
        if(l1->data < l2->data) {
            t->child = l1;
            t = l1;
            l1 = l1->child;
        } else {
            t->child = l2;
            t = l2;
            l2 = l2->child;
        }
        t->next == nullptr;
    }
    if(l1 == nullptr) {
        t->child = l2;
    }
    if(l2 == nullptr) {
        t->child = l1;
    }
    return dN->child;
}

Node* flattenOutLL(Node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* m = flattenOutLL(head->next);
    return mergeTwoVertically(head, m);
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