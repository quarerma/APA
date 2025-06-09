#include <iostream>
#include <chrono>
#include <array>
#include <stdexcept>

const int horner_iter(const int a[], const int x, const int n)
{
    int p = a[n];
    const int z = n-1;
    for(int i = z; i >= 0; i--)
        p = a[i] + x*p;
    return p;
}

const int horner_rec(const int a[], const int x, const int n, const int i)
{
    if(i < 0)
        return 0;
    return a[n-i] + x * horner_rec(a, x, n, i-1);
}

// Recursive Horner's method with tail recursion optimization (AI GENERATED)
constexpr int horner_recursive(const std::array<int, 9>& coeffs, int x, int degree, int index = 0, int accumulator = 0) {
    if (degree < 0 || degree >= coeffs.size()) {
        throw std::out_of_range("Invalid polynomial degree");
    }
    if (index > degree) {
        return accumulator;
    }
    return horner_recursive(coeffs, x, degree, index + 1, accumulator * x + coeffs[index]);
}

int main()
{
    constexpr int n = 8;
    constexpr int x = 2;
    constexpr std::array<int, 9> a = {1, 1, 2, 20, 49, 34, 23, 43, 556};
    int out_rec, out_iter, out_new_rec;

    try {
        auto start_rec = std::chrono::high_resolution_clock::now();
        out_rec = horner_rec(a.data(), x, n, n);
        auto end_rec = std::chrono::high_resolution_clock::now();
        std::cout << "Horner Recursivo: " << out_rec << '\n';
        
        auto start_iter = std::chrono::high_resolution_clock::now();
        out_iter = horner_iter(a.data(), x, n);
        auto end_iter = std::chrono::high_resolution_clock::now();
        std::cout << "Horner Iterativo: " << out_iter << '\n';
        
        // New Recursive (AI GENERATED)
        auto start_new_rec = std::chrono::high_resolution_clock::now();
        out_new_rec = horner_recursive(a, x, n);
        auto end_new_rec = std::chrono::high_resolution_clock::now();
        std::cout << "Horner Recursivo Novo: " << out_new_rec << '\n';
        
        // Timing
        auto diff_rec = std::chrono::duration_cast<std::chrono::nanoseconds>(end_rec - start_rec);
        auto diff_iter = std::chrono::duration_cast<std::chrono::nanoseconds>(end_iter - start_iter);
        auto diff_new_rec = std::chrono::duration_cast<std::chrono::nanoseconds>(end_new_rec - start_new_rec);
        std::cout << "Tempo Recursivo: " << diff_rec.count() << " ns\n";
        std::cout << "Tempo Iterativo: " << diff_iter.count() << " ns\n";
        std::cout << "Tempo Recursivo Novo: " << diff_new_rec.count() << " ns\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << '\n';
        return 1;
    }
    
    return 0;
}