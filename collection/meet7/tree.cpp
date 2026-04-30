#include <iostream>

using namespace std;

struct Node {
    int label; 
    Node *left, *right, *parent;
};

Node* buildTreeDariUser(Node* parentNode = NULL) {
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node* nodeBaru = new Node();
    nodeBaru->label = data;
    nodeBaru->parent = parentNode;

    cout << "Masukkan anak KIRI dari node [" << data << "] (ketik -1 jika kosong): ";
    nodeBaru->left = buildTreeDariUser(nodeBaru);

    cout << "Masukkan anak KANAN dari node [" << data << "] (ketik -1 jika kosong): ";
    nodeBaru->right = buildTreeDariUser(nodeBaru);

    return nodeBaru;
}

int cariBatasKedalaman(Node *node) {
    if (node == NULL) return 0;

    if (node->left == NULL && node->right == NULL) return 1;

    if (node->left == NULL) return cariBatasKedalaman(node->right) + 1;
    if (node->right == NULL) return cariBatasKedalaman(node->left) + 1;

    int kedalamanKiri = cariBatasKedalaman(node->left);
    int kedalamanKanan = cariBatasKedalaman(node->right);

    if (kedalamanKiri < kedalamanKanan) {
        return kedalamanKiri + 1;
    } else {
        return kedalamanKanan + 1;
    }
}

int main() {
    cout << "=== PROGRAM BINARY TREE ===" << endl;
    cout << "Masukkan nilai Root (ketik -1 jika tree kosong): ";
    
    Node *root = buildTreeDariUser();

    if (root != NULL) {
        int output = cariBatasKedalaman(root);
        cout << "\n---------------------------------" << endl;
        cout << "Tree selesai dibangun!" << endl;
        cout << "Batas Kedalaman (Minimum Depth) : " << output << endl;
        cout << "---------------------------------" << endl;
    } else {
        cout << "\nTree kosong, tidak ada kedalaman yang bisa dihitung." << endl;
    }

    return 0;
}