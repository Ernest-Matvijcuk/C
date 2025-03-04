#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

int main() {
    srand(time(0));

    const int size = 3;
    int** matrix = new int*[size];

    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 21 - 10;
        }
    }

    cout << "Матриця:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout.width(4);
            cout << matrix[i][j];
        }
        cout << endl;
    }

    cout << "\nЕлементи на головній діагоналі: ";
    for (int i = 0; i < size; i++) {
        cout << matrix[i][i] << " ";
    }

    cout << "\nЕлементи на побічній діагоналі: ";
    for (int i = 0; i < size; i++) {
        cout << matrix[i][size - 1 - i] << " ";
    }

    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] % 2 == 0)
                evenCount++;
            else
                oddCount++;
        }
    }

    cout << "\nКількість парних чисел: " << evenCount;
    cout << "\nКількість непарних чисел: " << oddCount << endl;

    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
