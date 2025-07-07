#include <bits/stdc++.h>
using namespace std;

// Deleting all occurrences by Key

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

Node* deleteAllByKey(Node* head, int K) {
    Node* mover = head;
    Node* newHead = head;
    while(mover!= nullptr) {
        if(mover->data == K) {
            if(mover == newHead) {
                mover = mover->next;
                newHead = mover;
                Node* toBeDel = mover->back;
                delete toBeDel;
                mover->back = nullptr;
            } else {
                mover->back->next = mover->next;
                mover->next->back = mover->back;
                Node* t = mover;
                mover = mover->next;
                delete t;
            }
        } else {
            mover = mover->next;
        }
    }
    return newHead;
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
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(7);
    v.push_back(4);

    Node* head = convertToArray(v, 5);
    head = deleteAllByKey(head, 10);
    printLL(head);
    return 0;
}