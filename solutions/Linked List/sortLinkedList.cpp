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

Node* findMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* f = head->next;
    Node* s = head;
    while(f!=nullptr && f->next != nullptr) {
        s = s->next;
        f = f->next->next;
    }
    return s;
}

Node* mergeBack(Node* l1, Node* l2) {
    Node* dN = new Node(-1);
    Node* temp = dN;
    while(l1!=nullptr && l2!=nullptr) {
        if(l1->data < l2->data) {
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
    }
    if(l1!=nullptr) {
        temp->next = l1;
    } else {
        temp->next = l2;
    }
    return dN->next;
}

Node* mergeSort(Node* head) {
    if(head==nullptr || head->next==nullptr) {
        return head;
    }
    Node* middle = findMiddle(head);
    Node* lH = head;
    Node* rH = middle->next;
    middle->next = nullptr;
    lH = mergeSort(lH);
    rH = mergeSort(rH);
    return mergeBack(lH, rH);
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
    printLL(mergeSort(head));
    return 0;
}