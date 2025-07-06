#include <bits/stdc++.h>
using namespace std;

// Sorting a Linked List of only 0's, 1's and 2's

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

Node* sortLL012(Node* head) {
    Node* zero = nullptr;
    Node* one = nullptr;
    Node* two = nullptr;
    Node* zeroh = nullptr;
    Node* oneh = nullptr;
    Node* twoh = nullptr;
    Node* mover = head;
    while(mover!=nullptr) {
        if(mover->data == 0) {
            if(zero == nullptr) {
                zero = mover;
                zeroh = zero;
            } else {
                zero->next = mover;
                zero = zero->next;
            }
        } else if(mover->data == 1) {
            if(one == nullptr) {
                one = mover;
                oneh = one;
            } else {
                one->next = mover;
                one = one->next;
            }
        } else  {
            if(two == nullptr) {
                two = mover;
                twoh = two;
            } else {
                two->next = mover;
                two = two->next;
            }
        }
        mover = mover->next;
    }
    zero->next = oneh;
    one->next = twoh;
    two->next = nullptr;
    return zeroh;
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
    v.push_back(1);
    v.push_back(2);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);

    Node* head = convertToArray(v, 5);
    printLL(sortLL012(head));
    return 0;
}