#include <bits/stdc++.h>
using namespace std;

// Segrregate Odd and Even Indexed Nodes in a Linked List

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

Node* nthNodeFromBack(Node* head, int K) {
    if(head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        Node* f = head;
        Node* s = head;
        for(int i=0; i<K; i++) {
            f = f->next;
        }
        if(f==nullptr) {
            return head->next;
        }
        while(f->next != nullptr) {
            f = f->next;
            s = s->next;
        }
        Node* delNode = s->next;
        s->next = s->next->next;
        delete delNode;
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
    v.push_back(7);
    v.push_back(6);
    v.push_back(5);

    Node* head = convertToArray(v, 5);
    printLL(nthNodeFromBack(head, 3));
    return 0;
}