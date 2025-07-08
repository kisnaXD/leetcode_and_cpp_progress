#include <bits/stdc++.h>
using namespace std;

// Merge K Sorted Linked Lists

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

Node* mergeKLists(vector<Node*>& l) {
    int K = l.size();
    priority_queue< pair<int, Node*>, vector<pair<int, Node*> >, greater<pair<int, Node*> > > pq;
    for(int i=0; i<K; i++) {
        if(l[i]) {
            pq.push({l[i]->data, l[i]});
        }
    }
    Node* dN = new Node(-1);
    Node* temp = dN;
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        if(it.second->next != nullptr) {
            pq.push({it.second->next->data, it.second->next});
        }
        temp->next = it.second;
        temp = temp->next;
    }
    return dN->next;
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
    v.push_back(5);
    v.push_back(7);
    v.push_back(8);
    v.push_back(12);

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(11);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(25);

    vector<int> v3;
    v3.push_back(26);
    v3.push_back(27);
    v3.push_back(28);

    vector<Node*> v4;

    Node* head = convertToArray(v, 4);
    Node* head1 = convertToArray(v1, 3);
    Node* head2 = convertToArray(v2, 3);
    Node* head3 = convertToArray(v3, 3);
    v4.push_back(head);
    v4.push_back(head1);
    v4.push_back(head2);
    v4.push_back(head3);
    printLL(mergeKLists(v4));
    return 0;
}