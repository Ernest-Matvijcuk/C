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
    int number;
    cout << "Введіть число: ";
    cin >> number;

    if (isPrime(number)) 
        cout << number << " є простим числом.\n";
    else 
        cout << number << " не є простим числом.\n";

    return 0;
}
