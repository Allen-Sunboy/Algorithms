#include <chrono>
#include <cmath> //sqrt(), round()
#include <iostream>

using namespace std;
using namespace std::chrono;

const double sqrt5 = sqrt(5);

long long F1(long long n) {
    long long a = 0, b = 1;
    if (n == 0)
        return a;
    else {
        for (long long i = 2; i <= n; i++) {
            b = a + b;
            a = b - a;
        }
        return b;
    }
}

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

long long F2(long long n) {
    double phi = (sqrt5 + 1) / 2;
    long long result = round(power(phi, n) / sqrt5);
    return result;
}

void test(int n) {
    cout << n << " ";

    long long result1 = F1(n);
    long long result2 = F2(n);

    cout << result1 << " " << result2 << " ";
    cout << result2 - result1;
    cout << "\n";
}

int main() {
    for (int i = 0; i <= 92; i++)
        test(i);

    system("pause");
}