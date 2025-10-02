#include <bits/stdc++.h>
using namespace std;

// Queue Implementation

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

class queueUsingArrays {
    int front;
    int rear;
    int queue[10];
    public:
        queueUsingArrays() {
            front = -1;
            rear = -1;
        }
        void enqueue(int x) {
            if(rear == 9) {
                cout << "Queue is full" << endl;
            } else {
                if(front == -1) {
                    front = 0;
                }
                queue[++rear] = x;
            }
        }
        void dequeue() {
            if(front == -1) {
                cout << "Queue is empty" << endl;
            } else if(front == rear) {
                front = -1;
                rear = -1;
            } else {
                front += 1;
            }
        }
        int peek() {
            if(front == -1) {
                cout << "Queue is Empty" << endl;
                return -1;
            }
            return queue[front];
        }
        int size() {
            return rear+1;
        }
};

class queueUsingLinkedLists {
    Node* front;
    Node* rear;
    int s = 0;
    public:
        queueUsingLinkedLists() {
            s = 0;
            front = NULL;
            rear = NULL;
        }
        void enqueue(int x) {
            Node* newNode = new Node(x);
            if(front == NULL) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }
        void dequeue() {
            if(front == NULL) {
                cout << "Queue is Empty";
            } else {
                Node* temp = front;
                front = front->next;
                delete(temp);
            }
        }
        int peek() {
            return front->data;
        }
        int size() {
            return s;
        }
};

int main() {
    int n = 8;

    return 0;
}