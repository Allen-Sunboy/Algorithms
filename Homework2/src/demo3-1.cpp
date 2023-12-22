#include <chrono>
#include <cmath> //sqrt(), round()
#include <iostream>

using namespace std;
using namespace std::chrono;

const double sqrt5 = sqrt(5);

double power(double phi, long long n) {
    if (n == 0)
        return 1;
    else if (n == 1)
        return phi;
    else {
        double x = power(phi, n / 2);
        if (n % 2)
            return x * x * phi;
        else
            return x * x;
    }
}

long long F(long long n) {
    double phi = (sqrt5 + 1) / 2;
    long long result = round(power(phi, n) / sqrt5);
    return result;
}

void test(long long n) {
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

int main() {
    for (long long i = 1; i <= 1000000000000000; i *= 2)
        test(i);

    system("pause");
}