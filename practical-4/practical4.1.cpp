#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertPosition(int value, int position) {
        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1) {
            insertFront(value);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    LinkedList queue;

    queue.insertFront(101);
    queue.display();

    queue.insertEnd(102);
    queue.display();

    queue.insertEnd(103);
    queue.display();

    queue.insertPosition(105, 2);
    queue.display();

    return 0;
}