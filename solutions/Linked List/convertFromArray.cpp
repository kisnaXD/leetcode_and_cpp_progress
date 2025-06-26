#include <bits/stdc++.h>
using namespace std;

// Converting an array to a linked list

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

int main() {
    vector<int> v;
    v.push_back(12);
    v.push_back(8);
    v.push_back(5);
    Node* header = convertFromArray(v, 3);
    cout << header->data;
}