#include <bits/stdc++.h>
using namespace std;

// Reverse Nodes in K Group Size

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

Node* findKth(Node* head, int K) {
    K--;
    while(head!=nullptr && K>0) {
        K--;
        head = head->next;
    }
    return head;
}

Node* reverseKGroup(Node* head, int K) {
    Node* temp = head;
    Node* prevNode = nullptr;
    while(temp!=nullptr) {
        Node* KthNode = findKth(temp, K);
        if(KthNode == nullptr) {
            if(prevNode!=nullptr) {
                prevNode->next = temp;
            }
            break;
        }
        Node* nextNode = KthNode->next;
        KthNode->next = nullptr;
        reverseLL(temp);
        if(temp == head) {
            head = KthNode;
        } else {
            prevNode->next = KthNode;
        }
        prevNode = temp;
        temp = nextNode;
    }
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
    printLL(reverseKGroup(head, 2));
    return 0;
}