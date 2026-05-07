#include <iostream>

using namespace std;

#define MAX 50 

int n; 
int costMatrix[MAX][MAX]; 

int visited[MAX];
int currentPath[MAX];
int bestPath[MAX + 1];
int minCost = 999999;
int startNode;

void cariJalur(int current, int count, int currentCost) {
    if (count == n) {
        int totalCost = currentCost + costMatrix[current][startNode];
        
        if (totalCost < minCost) {
            minCost = totalCost;
            for (int i = 0; i < n; i++) {
                bestPath[i] = currentPath[i];
            }
            bestPath[n] = startNode; 
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;         
            currentPath[count] = i; 

            cariJalur(i, count + 1, currentCost + costMatrix[current][i]);

            visited[i] = 0;
        }
    }
}

int main() {
    cout << "Masukkan jumlah desa (n): ";
    cin >> n;

    if (n <= 1 || n > MAX) {
        cout << "Jumlah desa tidak valid!\n";
        return 0;
    }

    cout << "\nMasukkan matriks jarak/biaya (pisahkan dengan spasi atau enter):\n";
    cout << "Beri nilai 0 untuk jarak simpul ke dirinya sendiri.\n";
    for (int i = 0; i < n; i++) {
        cout << "Input baris ke-" << (i + 1) << " (" << n << " angka): ";
        for (int j = 0; j < n; j++) {
            cin >> costMatrix[i][j];
        }
    }

    cout << "\nCost List yang diinputkan:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << costMatrix[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\nMasukkan titik awal Tukang Pos (1-" << n << "): ";
    int input;
    cin >> input;

    if (input < 1 || input > n) {
        cout << "Titik awal tidak valid!\n";
        return 0;
    }

    startNode = input - 1; 

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[startNode] = 1;
    currentPath[0] = startNode;
    
    cariJalur(startNode, 1, 0);

    cout << "\nJalur Terpendek :\n";
    for (int i = 0; i <= n; i++) {
        cout << (bestPath[i] + 1); 
        if (i < n) {
            cout << "--->";
        }
    }

    cout << "\n\nMinimum Cost : " << minCost << "\n";

    return 0;
}