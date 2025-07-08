#include <bits/stdc++.h>
using namespace std;

// Rotate Linked List by K Times

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

Node* rotateLL(Node* head, int K) {
    if(head==nullptr || head->next==nullptr) {
        return head;
    }
    int c = 1;
    Node* temp = head;
    while(temp->next != nullptr) {
        c++;
        temp = temp->next;
    }
    if(K%c == 0) {
        return head;
    }
    K = K%c;
    temp->next = head;
    int t = c-K-1;
    temp = head;
    while(t>0 && temp!=nullptr) {
        temp = temp->next;
        t--;
    }
    head = temp->next;
    temp->next = nullptr;
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
    v.push_back(12);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);

    Node* head = convertToArray(v, 4);
    printLL(rotateLL(head, 2));
    return 0;
}