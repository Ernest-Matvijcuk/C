#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    const int size = 5;
    int matrix[size][size];

    int *ptr = &matrix[0][0];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(ptr + i * size + j) = rand() % 99 + 1;
        }
    }

    cout << "Матриця:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout.width(4);
            cout << *(ptr + i * size + j);
        }
        cout << endl;
    }

    cout << "\nЕлементи на головній діагоналі: ";
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i * size + i) << " ";
    }

    cout << "\nЕлементи на побічній діагоналі: ";
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i * size + (size - 1 - i)) << " ";
    }

    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < size * size; i++) {
        if (*(ptr + i) % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    cout << "\nКількість парних чисел: " << evenCount;
    cout << "\nКількість непарних чисел: " << oddCount << endl;

    return 0;
}
