#include <iostream>
using namespace std;

int iterativeFibonacci(int n) {
    if (n <= 1) return n;

    int prev = 0, curr = 1;

    for (int i = 2; i <= n; ++i) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }

    return curr;
}

int recursiveFibonacci(int n) {
    if (n <= 1) return n;
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

// Iterative Fibonacci function
long long fibonacci(int n) {
    if (n < 0) return -1; // Handle negative input
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    long long prev = 0, current = 1;
    for (int i = 2; i <= n; i++) {
        long long next = prev + current;
        prev = current;
        current = next;
    }
    return current;
}

int main() {
    int n = 10; // Test with n = 10

    // Option 1: Use iterativeFibonacci
    cout << "Iterative Fibonacci(" << n << ") = " << iterativeFibonacci(n) << endl;
    
    // Option 2: Use recursiveFibonacci
    // cout << "Recursive Fibonacci(" << n << ") = " << recursiveFibonacci(n) << endl;
    
    // Option 3: Use fibonacci (long long version)
    // cout << "Long long Fibonacci(" << n << ") = " << fibonacci(n) << endl;

    return 0;
}