#include <bits/stdc++.h>
using namespace std;

// Returning the length of a Loop in a Linked List

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

int lengthOfLoop(Node* head) {
    Node* s = head;
    Node* f = head;
    while(f!=nullptr && f->next!=nullptr) {
        s = s->next;
        f = f->next->next;
        if(s==f) {
            int c = 1;
            f = f->next;
            while(s!=f) {
                f = f->next;
                c++;
            }
            return c;
        }
    }
    return 0;
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