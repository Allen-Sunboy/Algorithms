#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

long long F(long long n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return F(n - 1) + F(n - 2);
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
    for (int i = 0; i <= 50; i++)
        test(i);
    system("pause");
}