#include <bits/stdc++.h>
using namespace std;

// Adding 1 to a Linked List

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

Node* add1ToLinkedList(Node* head) {
    int carry = adder(head);
    if(carry == 1) {
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}

int adder(Node* head) {
    if(head == nullptr) {
        return NULL;
    }
    int carry = adder(head->next);
    head->data = head->data + carry;
    if(head->data < 10) {
        return 0;
    }
    head->data = 0;
    return 1;
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