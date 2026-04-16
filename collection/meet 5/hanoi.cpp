#include <iostream>
using namespace std;

struct Stack {
    int data[5]; 
    int top;

    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }


    void push(int value) {
        if (top >= 4) {
            cout << "Stack Penuh!" << endl;
            return;
        }
        data[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        return data[top--];
    }
};


void hanoi(int n, Stack& asal, Stack& bantu, Stack& tujuan, char namaAsal, char namaBantu, char namaTujuan, int& langkah) {
    if (n == 1) {
        int batu = asal.pop();
        tujuan.push(batu);
        cout << langkah++ << ". Pindahkan batu " << batu << " dari " << namaAsal << " ke " << namaTujuan << endl;
        return;
    }

    hanoi(n - 1, asal, tujuan, bantu, namaAsal, namaTujuan, namaBantu, langkah);

    int batu = asal.pop();
    tujuan.push(batu);
    cout << langkah++ << ". Pindahkan batu " << batu << " dari " << namaAsal << " ke " << namaTujuan << endl;


    hanoi(n - 1, bantu, asal, tujuan, namaBantu, namaAsal, namaTujuan, langkah);
}

int main() {
    Stack A, B, C;
    int langkah = 1;

    A.push(30);
    A.push(20);
    A.push(10);

    cout << "Penyelesaian Menara Hanoi (10, 20, 30):\n" << endl;

    hanoi(3, A, B, C, 'A', 'B', 'C', langkah);

    return 0;
}