#include <iostream>
#include <chrono>

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
    constexpr int n = 10; // Test with n = 10
    int out_iter, out_rec;
    long long out_ai;


    // Option 1: Use iterativeFibonacci
    auto start_iter = chrono::high_resolution_clock::now();
    out_iter = iterativeFibonacci(n);
    auto end_iter   = chrono::high_resolution_clock::now();
    
    // Option 2: Use recursiveFibonacci
    auto start_rec = chrono::high_resolution_clock::now();
    out_rec = recursiveFibonacci(n);
    auto end_rec   = chrono::high_resolution_clock::now();
    
    // Option 3: Use fibonacci (long long version)
    auto start_ai = chrono::high_resolution_clock::now();
    out_ai = fibonacci(n);
    auto end_ai   = chrono::high_resolution_clock::now();
    
    // Output
    cout << "Iterative Fibonacci(" << n << ") = " << out_iter << endl;
    cout << "Recursive Fibonacci(" << n << ") = " << out_rec << endl;
    cout << "Long long Fibonacci(" << n << ") = " << out_ai << endl;


    // Timing
    auto diff_iter = chrono::duration_cast<chrono::nanoseconds>(end_iter - start_iter);
    auto diff_rec  = chrono::duration_cast<chrono::nanoseconds>(end_rec  - start_rec);
    auto diff_ai   = chrono::duration_cast<chrono::nanoseconds>(end_ai   - start_ai);
    
    cout << "Tempo Iterativo: " << diff_iter.count() << " ns\n";
    cout << "Tempo Recursivo: " << diff_rec.count()  << " ns\n";
    cout << "Tempo AI: "        << diff_ai.count()   << " ns\n";


    return 0;
}