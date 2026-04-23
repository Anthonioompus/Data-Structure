#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

struct Queue {
    Node* front = NULL;
    Node* rear = NULL;
};

void enqueue(Queue& q, char huruf) {
    Node* newNode = new Node; 
    newNode->data = huruf;
    newNode->next = NULL;

    if (q.rear == NULL) {
        q.front = newNode;
        q.rear = newNode;
        return;
    }

    q.rear->next = newNode;
    q.rear = newNode;
}

char dequeue(Queue& q) {
    if (q.front == NULL) return '\0'; 

    Node* temp = q.front;
    char huruf = temp->data; 
    
    q.front = q.front->next; 

    if (q.front == NULL) {
        q.rear = NULL;
    }

    delete temp; 
    return huruf;
}

int main() {
    string input;
    Queue q; 
    
    cout << "Masukkan susunan kata yang ingin dicek: ";
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        enqueue(q, input[i]);
    }

    bool isPalindrome = true;

    for (int i = input.length() - 1; i >= 0; i--) {
        char hurufDariQueue = dequeue(q);
        
        if (hurufDariQueue != input[i]) {
            isPalindrome = false;
            break;
        }
    }

    cout << "\nOutput:" << endl;
    if (isPalindrome) {
        cout << "Queue adalah palindrome selamat" << endl;
    } else {
        cout << "Queue bukan palindrome yahh" << endl;
    }

    return 0;
}