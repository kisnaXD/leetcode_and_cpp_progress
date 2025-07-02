#include <bits/stdc++.h>
using namespace std;

// Deletions and Insertions from a Doubly Linked List

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

Node* deleteHead(Node* head) {
    if((head == nullptr) || (head->next == nullptr)) {
        return nullptr;
    }
    Node* newHead = head->next;
    newHead->back = nullptr;
    head->next = nullptr;
    delete head;
    return newHead;
}

Node* deleteTail(Node* head) {
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    Node* mover = head;
    while(mover->next != nullptr) {
        mover = mover->next;
    }
    mover->back->next = nullptr;
    delete mover;
    return head;
}

Node* deleteKth(Node* head, int K) {
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    if(K==1) {
        Node* newHead = head->next;
        newHead->back = nullptr;
        return newHead;
    }
    int c = 0;
    Node* mover = head;
    while(mover!=nullptr) {
        c++;
        if(c==K) {
            if(mover->next == nullptr) {
                mover->back->next = mover->next;
                mover->next = nullptr;
                mover->back = nullptr;
            } else {
                mover->next->back = mover->back;   
                mover->back->next = mover->next;
                mover->next = nullptr;
                mover->back = nullptr;
            }
            delete mover;
            break;
        }
        mover = mover->next;
    }
    return head;
}

Node* deleteValue(Node* head, int K) {
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    Node* mover = head;
    while(mover!=nullptr) {
        if(mover->data == K) {
            if(mover->next == nullptr) {
                mover->back->next = nullptr;
                mover->next = nullptr;
                mover->back = nullptr;
            } else if(mover->back == nullptr) {
                mover->next->back = nullptr;
                head = mover->next;
                mover->next = nullptr;
                mover->back = nullptr;
            } else {
                mover->next->back = mover->back;   
                mover->back->next = mover->next;
                mover->next = nullptr;
                mover->back = nullptr;
            }
            delete mover;
            break;
        }
        mover = mover->next;
    }
    return head;
}

Node* insertAtHead(Node* head, int K) {
    Node* newNode = new Node(K);
    newNode->next = head;
    head->back = newNode;
    return newNode;
}

Node* insertAtTail(Node* head, int K) {
    Node* newNode = new Node(K);
    Node* mover = head;
    while(mover->next!= nullptr) {
        mover = mover->next;
    }
    newNode->back = mover;
    mover->next = newNode;
    return head;
}

Node* insertAtK(Node* head, int K, int i) {
    Node* newNode = new Node(i);
    Node* mover = head;
    int c = 0;
    if(K==1) {
        newNode->next = head;
        head->back = newNode;
        return newNode;
    }
    while(mover!=nullptr) {
        c++;
        if(c==K) {
            if(mover->next == nullptr) {
                mover->next = newNode;
                newNode->back = mover;
            } else {
                mover->next->back = newNode;
                newNode->next = mover->next;
                mover->next = newNode;
                newNode->back = mover;
            }
            break;
        }
        mover = mover->next;
    }
    return head;
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
}

int main() {
    vector<int> v;
    v.push_back(12);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);

    Node* head = convertToArray(v, 4);
    printLL(insertAtK(head,4,12));
    return 0;
}