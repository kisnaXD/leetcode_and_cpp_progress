#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// LRU Cache

struct Node {
    public:
    int key;
    int value;
    Node* next;
    Node* back;

    Node() {
        key = -1;
        value = -1;
        next = nullptr;
        back = nullptr;
    }

    Node(int k, int v) {
        key = k;
        value = v;
        next = nullptr;
        back = nullptr;
    }
};

void deleteNode(Node* n) {
    n->back->next = n->next;
    n->next->back = n->back;
}

void insertAtHead(Node* head, Node* n) {
    n->next = head->next;
    n->back = head;
    head->next->back = n;
    head->next = n;
}

class LRUCache {
public:
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;
    int capacity;
    LRUCache(int c) {
        capacity = c;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->back = head;
    }
    
    int get(int k) {
        if(mpp.find(k) == mpp.end()) {
            return -1;
        } else {
            Node* n = mpp[k];
            deleteNode(n);
            insertAtHead(head, n);
            return n->value;
        }
    }
    
    void put(int k, int v) {
        if(mpp.find(k) == mpp.end()) {
            if(mpp.size() == capacity) {
                Node* toRemove = tail->back;
                deleteNode(toRemove);
                mpp.erase(toRemove->key);
            }
            Node* nN = new Node(k, v);
            insertAtHead(head, nN);
            mpp[k] = nN;
        } else {
            mpp[k]->value = v;
            Node* n = mpp[k];
            deleteNode(n);
            insertAtHead(head, n);
        }
    }
};

int main() {
    return 0;
}