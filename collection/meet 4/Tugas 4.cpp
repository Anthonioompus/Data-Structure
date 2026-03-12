#include <iostream>
using namespace std;

//Struct dari linked list
struct Node {
    int data;
    Node *next;
};

// Pointer global 
Node *awal = NULL, *akhir = NULL, *baru, *bantu;

// Fungsi untuk menambah data 
void insertData(int nilai) {
    baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    
    if (awal == NULL) {
        awal = akhir = baru;
    } else {
        akhir->next = baru;
        akhir = baru;
    }
}

// Fungsi utama untuk reverse 
void reverseList() {
    Node *prev = NULL;
    Node *current = awal;
    Node *next = NULL;

    akhir = awal; 

    while (current != NULL) {
        next = current->next;   
        current->next = prev;   
        prev = current;         
        current = next;         
    }
    
    awal = prev; 
}

// Fungsi simpel untuk cetak data
void tampilData() {
    bantu = awal;
    while (bantu != NULL) {
        cout << bantu->data;
        if (bantu->next != NULL) cout << " -> ";
        bantu = bantu->next;
    }
    cout << endl;
}

int main() {
    insertData(5);
    insertData(4);
    insertData(3);
    insertData(2);
    insertData(1);

    cout << "Input  : ";
    tampilData();

    reverseList();

    cout << "Output : ";
    tampilData();

    return 0;
}