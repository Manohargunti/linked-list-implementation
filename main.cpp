#include <iostream>
using namespace std;

struct Node {
    int row;
    int col;
    int val;
    Node* next;
};

class SparseMatrix {
private:
    Node* head;
public:
    SparseMatrix() {
        head = nullptr;
    }

    void insert(int r, int c, int v) {
        if (v == 0) return;
        Node* newNode = new Node;
        newNode->row = r;
        newNode->col = c;
        newNode->val = v;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Sparse matrix is empty." << endl;
            return;
        }
        cout << "Row Col Val" << endl;
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->row << " " << temp->col << " " << temp->val << endl;
            temp = temp->next;
        }
    }
};

int main() {
    int m, n;

    cout << "Enter number of rows: ";
    cin >> m;
    if (m <= 0) {
        cout << "Invalid entry! Number of rows must be greater than 0." << endl;
        return 0;
    }

    cout << "Enter number of columns: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid entry! Number of columns must be greater than 0." << endl;
        return 0;
    }

    SparseMatrix sm;
    cout << "Enter " << m * n << " matrix elements one by one:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cout << "Element at (" << i << "," << j << "): ";
            cin >> val;
            sm.insert(i, j, val);
        }
    }

    cout << "\nSparse Matrix Representation (Linked List):" << endl;
    sm.display();

    return 0;
}
