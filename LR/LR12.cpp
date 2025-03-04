#include <iostream>

using namespace std;

int main() {
    int vector[] = {3, -5, 7, 10, -4, 14, 5, 2, -13};
    int n = sizeof(vector) / sizeof(vector[0]);

    int *ptr = vector;
    int *minPtr = vector;

    for (int *p = vector + 1; p < vector + n; p++) {
        if (*p < *minPtr) {
            minPtr = p;
        }
    }

    cout << "Мінімальний елемент: " << *minPtr << endl;

    return 0;
}
