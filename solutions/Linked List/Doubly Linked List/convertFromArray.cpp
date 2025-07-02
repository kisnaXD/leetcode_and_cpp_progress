#include <bits/stdc++.h>
using namespace std;

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

int main() {
    vector<int> v;
    v.push_back(12);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);

    Node* head = convertToArray(v, 4);
    Node* mover = head;
    while(mover!=nullptr) {
        cout << mover->data;
        cout << " ";
        mover = mover->next;
    }

}