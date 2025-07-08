#include <bits/stdc++.h>
using namespace std;

// Removing Duplicates from a Sorted Doubly Linked List

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

Node* removeDuplicates(Node* head) {
    Node* current = head;

    while (current && current->next) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = duplicate->next;
            if (duplicate->next)
                duplicate->next->back = current;
            delete duplicate;
        } else {
            current = current->next;
        }
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
    cout << endl;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);

    Node* head = convertToArray(v, 5);
    printLL(removeDuplicates(head));
    return 0;
}