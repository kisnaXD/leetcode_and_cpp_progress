#include <bits/stdc++.h>
using namespace std;

// Adding Two Linked Lists

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

Node* addTwoLinkedLists(Node* h1, Node* h2) {
    Node* dN = new Node(-1);
    Node* curr = dN;
    Node* t1 = h1;
    Node* t2 = h2;
    int carry = 0;
    while(t1!= nullptr || t2 != nullptr) {
        int sum = carry;
        if(t1!= nullptr) {
            sum+=t1->data;
        }
        if(t2!= nullptr) {
            sum+=t2->data;
        }
        Node* newNode = new Node(sum%10);
        carry = sum/10;
        curr->next = newNode;
        curr = curr->next;
        if(t1!= nullptr) {
            t1 = t1->next;
        }
        if(t2!= nullptr) {
            t2 = t2->next;
        }
    }
    if(carry) {
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dN->next;
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
    vector<int> v1;
    vector<int> v2;
    v1.push_back(2);
    v1.push_back(5);
    v2.push_back(2);

    Node* h1 = convertToArray(v1, 2);
    Node* h2 = convertToArray(v2, 1);
    Node* answer = addTwoLinkedLists(h1, h2);
    printLL(answer);
    return 0;
}