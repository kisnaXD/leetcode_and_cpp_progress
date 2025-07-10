#include <bits/stdc++.h>
using namespace std;

// Copying a Linked List with Random Pointers

class Node {
    public: 
    int data;
    Node* next;
    Node* random;

    Node(int d, Node* n, Node* r) {
        data = d;
        next = n;
        random = r;
    }

    Node (int d) {
        data = d;
        next = nullptr;
        random = nullptr;
    }
};

void insertCopyInBetween(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* nextElement = temp->next;
        Node* copy = new Node(temp->data); 
        copy->next = nextElement;
        temp->next = copy;
        temp = nextElement;         
    }
}

void connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != NULL) {
        Node* copyNode = temp->next;
        if(temp->random) {
            copyNode->random = temp->random->next; 
        }
        else {
            copyNode->random = NULL;   
        }
        temp = temp->next->next;   
    }
}

Node* getDeepCopyList(Node* head){
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;             
    while(temp != NULL) {
        res->next = temp->next;
        res = res->next;
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;   
}

Node* copyRandomList(Node* head) {
    if(!head) return nullptr;
    insertCopyInBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head); 
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
    return 0;
}