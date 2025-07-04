#include <bits/stdc++.h>
using namespace std;

// Check if a Linked List is a Palindrome

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
    Node* front = nullptr;
    Node* prev = nullptr;
    while(mover!=nullptr) {
        front = mover->next;
        mover->next = prev;
        prev = mover;
        mover = front;
    }
    return prev;
}
bool isPalindrome(Node* head) {
    Node* s = head;
    Node* f = head;
    while(f->next != nullptr && f->next->next!=nullptr) {
        s = s->next;
        f = f->next->next;
    }
    Node* nH = reverseLL(s->next);
    f = head;
    Node* sec = nH;
    while(sec != nullptr) {
        if(f->data != sec->data) {
            nH = reverseLL(nH);
            return false;
        }
        sec = sec->next;
        f = f->next;
    }
    nH = reverseLL(nH);
    return true;
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
    v.push_back(8);
    v.push_back(12);

    Node* head = convertToArray(v, 4);
    cout << isPalindrome(head);
    return 0;
}