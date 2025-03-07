#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    cout << "Прості числа від 0 до 21: ";
    for (int i = 0; i <= 21; i++) {
        if (isPrime(i))
            cout << i << " ";
    }
    cout << endl;

    return 0;
}
