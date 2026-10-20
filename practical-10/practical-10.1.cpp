
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> shelves[10];
    int n, code;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter book code: ";
        cin >> code;

        int index = code % 10;
        shelves[index].push_back(code);
    }

    cout << "\nFinal shelf contents:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";

        if (shelves[i].empty()) {
            cout << "Empty";
        } else {
            for (int code : shelves[i]) {
                cout << code << " -> ";
            }
            cout << "NULL";
        }

        cout << endl;
    }

    return 0;
}
