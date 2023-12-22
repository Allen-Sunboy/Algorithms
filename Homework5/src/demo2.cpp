#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

#include <windows.h>

using namespace std;

default_random_engine e(time(0));
uniform_int_distribution<long long> u(0, 4294967295);

long long A[200000007];
int n;

void shellSort(long long A[], int n) {
    int gap = n;
    while (gap > 1) {
        gap = gap / 3 + 1;
        for (int i = gap; i < n; i++) {
            long long key = A[i];
            int j = i - gap;
            while (j >= 0 && A[j] > key) {
                A[j + gap] = A[j];
                j -= gap;
            }
            A[j + gap] = key;
        }
    }
}

void test(int n) {
    for (int i = 0; i < n; i++)
        A[i] = u(e);

    // for(int i = 0; i < n; i++)
    //     cout << A[i] << " ";
    // cout << "\n";

    LARGE_INTEGER freq, time_start, time_end;
    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&time_start);

    shellSort(A, n);

    QueryPerformanceCounter(&time_end);

    double elap = (double)(time_end.QuadPart - time_start.QuadPart) /
                  (double)freq.QuadPart * 1000000; // 单位 微秒
    cout << setprecision(12) << elap << "\n";

    // for(int i = 0; i < n; i++)
    //     cout << A[i] << " ";
    // cout << "\n";
}

int main() {
    cin >> n;

    test(n);

    // for(int i = 10; i <= 100000000; i *= 10)
    // {
    //     cout << i << " ";
    //     test(i);
    // }

    system("pause");
}