#include <bits/stdc++.h>
using namespace std;

// Reversing a Linked List Iteratively and Recursively

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

Node* reverseLL(Node* head) {
    Node* mover = head;
    Node* prev = nullptr;
    Node* front = nullptr;
    while(mover!=nullptr) {
        front = mover->next;
        mover->next = prev;
        prev = mover;
        mover = front;
    }
    return prev;
}

Node* recursivelyReverse(Node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* newHead = recursivelyReverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
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
    v.push_back(12);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);

    Node* head = convertToArray(v, 4);
    Node* trueHead = convertToArray(v, 4);
    printLL(reverseLL(head));
    printLL(recursivelyReverse(trueHead));
    return 0;
}