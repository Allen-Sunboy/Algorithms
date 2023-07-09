#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct matrix{
    long long a11, a12, a21, a22;
};

matrix mul(matrix a, matrix b)
{
    matrix c{a.a11 * b.a11 + a.a12 * b.a21, a.a11 * b.a12 + a.a12 * b.a22, 
    a.a21 * b.a11 + a.a22 * b.a21, a.a21 * b.a12 + a.a22 * b.a22};
    return c;
}

matrix power(matrix m, long long n)
{
    if(n == 0)
        return {1, 0, 0, 1};
    else if(n == 1)
        return m;
    else
    {
        matrix x = power(m, n/2);
        if(n % 2)
            return mul(mul(x, x), m);
        else
            return mul(x, x);
    }
}

long long F(long long n)
{
    matrix m{1, 1, 1, 0};
    matrix result = power(m, n);
    return result.a12;
}

void test(long long n)
{
    cout << n;
    cout << " ";

    auto start = steady_clock::now();
    long long result = F(n);
    auto end = steady_clock::now();

    duration<double, micro> diff = end - start;
    cout << diff.count();
    cout << " ";

    cout << result;
    cout << " ";
    
    cout << "\n";
}

int main()
{
    for(long long i = 1; i <= 1000000000000000; i *= 2)
        test(i);
    
    system("pause");

}