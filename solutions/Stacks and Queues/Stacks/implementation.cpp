#include <bits/stdc++.h>
using namespace std;

// Stack Implementation

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

class stackUsingArrays {
    int top;
    int stack[10];
    public:
        stackUsingArrays() {
            top = -1;
        }
        void push(int x) {
            if(top+1 == 10) {
                cout << "Stack is full" << endl;
            } else {
                stack[++top] = x;
            }
        }
        int pop() {
            if(top == -1) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            top -= 1;
            return stack[top+1];
        }
        int topElement() {
            if(top == -1) {
                cout << "Stack is Empty" << endl;
                return -1;
            }
            return stack[top];
        }
        int size() {
            return top+1;
        }
};

class stackUsingLinkedLists {
    int top;
    Node* head;
    public:
        void push(int x) {
            Node* newNode = new Node(x);
            newNode->next = head;
            head = newNode;
            top += 1;
        }
        Node* pop() {
            if(head == NULL) {
                cout << "Stack is Empty";
                return NULL;
            }
            Node* temp = head;
            head = head->next;
            top -= 1;
            return temp;
        }
        Node* topElement() {
            return head;
        }
        int size() {
            return top + 1;
        }
};

int main() {
    int n = 8;
    stackUsingArrays stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.pop();
    cout << stack1.topElement() << endl;
    stack1.push(25);
    stack1.pop();
    stack1.pop();
    cout << stack1.topElement() << endl;
    stack1.pop();
    cout << stack1.topElement() << endl;
    cout << stack1.size() << endl;

    stackUsingLinkedLists stack2;
    stack2.push(10);
    stack2.push(20);
    stack2.push(30);
    stack2.pop();
    cout << stack2.topElement()->data << endl;
    stack2.push(25);
    stack2.pop();
    stack2.pop();
    cout << stack2.topElement()->data << endl;
    stack2.pop();
    cout << stack2.topElement()->data << endl;
    cout << stack2.size();

    return 0;
}