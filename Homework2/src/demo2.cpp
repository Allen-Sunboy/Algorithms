#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

long long F(long long n) {
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
    for (int i = 0; i <= 30000000; i += 1000000)
        test(i);
    system("pause");
}