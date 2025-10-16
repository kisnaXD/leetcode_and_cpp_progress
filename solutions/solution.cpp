#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// LFU Cache

struct Node {
    int key, value, count;
    Node* next;
    Node* prev;
    Node(int k, int v) {
        key = k;
        value = v;
        count = 1;
    }
};

struct List {
    int size;
    Node* head;
    Node* tail;
    List() {
        size = 0;
        head = new Node(-105, 0);
        tail = new Node(-101, 0);
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node* n) {
        Node* t = head->next;
        n->next = t;
        n->prev = head;
        head->next = n;
        t->prev = n;
        size+=1;
    }

    void removeNode(Node* delNode) {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        size-=1;
    }
};

class LFUCache {
public:
    int size, minFreq, capacity;
    unordered_map<int, Node*> fMap;
    unordered_map<int, List*> lMap;
    LFUCache(int c) {
        size = 0;
        minFreq = 0;
        capacity = c;
    }

    void updateFreqList(Node* n) {
        fMap.erase(n->key);
        lMap[n->count]->removeNode(n);
        if(n->count == minFreq && lMap[n->count]->size==0) {
            minFreq+=1;
        }
        List* nextH = new List();
        if(lMap.find(n->count+1) != lMap.end()) {
            nextH = lMap[n->count+1];
        }
        n->count+=1;
        nextH->addFront(n);
        lMap[n->count] = nextH;
        fMap[n->key] = n;
    }
    int get(int key) {
        if(fMap.find(key) != fMap.end()) {
            Node* n = fMap[key];
            int v = n->value;
            updateFreqList(n);
            return v;
        } else {
            return -1;
        }
    }
    void put(int key, int value) {
        if(capacity == 0) {
            return;
        }
        if(fMap.find(key) != fMap.end()) {
            Node* n = fMap[key];
            n->value = value;
            updateFreqList(n);
        } else {
            if(size == capacity) {
                List* L = lMap[minFreq];
                fMap.erase(L->tail->prev->key);
                lMap[minFreq]->removeNode(L->tail->prev);
                size--;
            }
            size+=1;
            minFreq = 1;
            List* newL = new List();
            if(lMap.find(minFreq) != lMap.end()) {
                newL = lMap[minFreq];
            }
            Node* n = new Node(key, value);
            newL->addFront(n);
            fMap[key] = n;
            lMap[minFreq] = newL;
        }
    }
};

int main() {
    return 0;
}