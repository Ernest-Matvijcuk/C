#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int size;
    cout << "Введіть розмір масиву: ";
    cin >> size;

    double* arr = new double[size];

    for (int i = 0; i < size; i++) {
        arr[i] = -2 + static_cast<double>(rand()) / RAND_MAX * 4;
    }

    int positiveCount = 0, negativeCount = 0;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if (arr[i] > 0) positiveCount++;
        else if (arr[i] < 0) negativeCount++;
    }

    cout << "\nКількість додатних чисел: " << positiveCount;
    cout << "\nКількість від'ємних чисел: " << negativeCount << endl;

    delete[] arr;

    return 0;
}
