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

Node* oddEvenLinkedList(Node* head) {
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;
    while(even!=nullptr && even->next!=nullptr) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
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
    printLL(oddEvenLinkedList(head));
    return 0;
}