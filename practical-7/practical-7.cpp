
#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Error: Queue is full" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = value;

        cout << "Inserted: " << value << endl;
        displayFront();
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Error: Queue is empty" << endl;
            return;
        }

        cout << "Removed: " << arr[front] << endl;
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }

        displayFront();
    }

    void displayFront() {
        if (front == -1)
            cout << "Front token: None" << endl;
        else
            cout << "Front token: " << arr[front] << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n1. Join (Enqueue)";
        cout << "\n2. Serve (Dequeue)";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter token number: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 3);

    return 0;
}
