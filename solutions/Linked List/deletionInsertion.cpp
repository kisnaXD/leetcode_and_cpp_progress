#include <bits/stdc++.h>
using namespace std;

// Insertion & Deletion in Linked List

struct Node {
    public:
    int data;
    Node* next;

    Node(int data1, Node* node1) {
        data = data1;
        next = node1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* convertFromArray(vector<int> &arr, int N) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<N; i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* deleteHead(Node* head) {
    if(head==NULL) {
        return head;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head) {
    if(head == NULL || head->next == NULL) {
        return NULL;
    }
    Node* mover = head;
    while(mover->next->next != NULL) {
        mover = mover->next;
    }
    delete mover->next;
    mover->next = nullptr;
    return head;
}

Node* deleteKth(Node*head, int K) {
    if(head==NULL) {
        return head;
    }
    if(K==1) {
        Node*temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int c = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr) {
        c++;
        if(c==K) {
            prev->next = prev->next->next;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* deleteK(Node* head, int K) {
    if(head==NULL) {
        return head;
    }
    if(head->data == K) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr) {
        if(temp->data == K) {
            prev->next = prev->next->next;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertAtHead(Node* head, int K) {
    Node* newNode = new Node(K, head);
    return newNode;
}

Node* insertAtTail(Node* head, int K) {
    Node* newNode = new Node(K, nullptr);
    Node* temp = head;
    while(temp!=nullptr) {
        if(temp->next == nullptr) {
            temp->next = newNode;
            break;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

Node* insertAtPosition(Node* head, int K, int i) {
    int c = 0;
    Node* temp = new Node(K);
    Node* prev = NULL;
    if(head==NULL) {
        return temp;
    }
    if(i==1) {
        temp->next = head;
        return temp;
    }
    Node* mover = head;
    while(mover!=nullptr) {
        c+=1;
        if(c==i) {
            prev->next = temp;
            temp->next = mover;
            break;
        }
        prev = mover;
        mover = mover->next;
    }
    return head;
}

int main() {
    vector<int> v;
    v.push_back(12);
    v.push_back(8);
    v.push_back(5);
    Node* header = convertFromArray(v, 3);
    Node* afterAdding7 = insertAtPosition(header, 12, 2);
    Node* mover = afterAdding7;
    while(mover != nullptr) {
        cout << mover->data;
        mover = mover->next;
        cout << " ";
    }
}