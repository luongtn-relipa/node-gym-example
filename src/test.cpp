#include "test.h"
#include <cmath>

int add(int a, int b) {
    return a + b;
}

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return n >= 2;
}
