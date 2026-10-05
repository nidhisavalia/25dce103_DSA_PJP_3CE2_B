#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
    int capacity;

public:
    Stack(int n) {
        capacity = n;
        top = -1;
    }

    void push(int tray) {
        if (top == capacity - 1) {
            cout << "Error: Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = tray;

        cout << "Placed: " << tray << endl;
        displayTop();
    }

    void pop() {
        if (top == -1) {
            cout << "Error: Stack Underflow" << endl;
            return;
        }

        cout << "Taken: " << arr[top] << endl;
        top--;

        displayTop();
    }

    void displayTop() {
        if (top == -1)
            cout << "Top: Empty" << endl;
        else
            cout << "Top: " << arr[top] << endl;

        cout << endl;
    }
};

int main() {
    int n;

    cout << "Enter capacity: ";
    cin >> n;

    Stack s(n);

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    s.pop();
    s.pop();

    s.pop();

    return 0;
}