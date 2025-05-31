#include <iostream>
#include <chrono>

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

int main()
{
    constexpr int n = 8;
    constexpr int x = 2;
    constexpr int a[9] = {1,1,2,20,49,34,23,43,556};
    int out_rec, out_iter;

    // Recursivo
    auto start_rec = std::chrono::high_resolution_clock().now();
    out_rec = horner_rec(a, x, n, n);
    auto end_rec = std::chrono::high_resolution_clock().now();
    std::cout << "Horner Recursivo: " << out_rec << '\n';
    
    // Iterativo
    auto start_iter = std::chrono::high_resolution_clock().now();
    out_iter = horner_iter(a, x, n);
    auto end_iter = std::chrono::high_resolution_clock().now();
    std::cout << "Horner Iterativo: " << out_iter << '\n';
    
    // Tempo
    auto diff_rec = end_rec - start_rec;
    auto diff_iter = end_iter - start_iter;
    std::cout << "Tempo Recursivo: " << diff_rec.count() << "ms\n";
    std::cout << "Tempo Iterativo: " << diff_iter.count() << "ms\n";
    
    return 0;
}
