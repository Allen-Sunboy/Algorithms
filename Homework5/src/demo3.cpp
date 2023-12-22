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

int partition(long long A[], int p, int r) {
    long long x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

void quickSort(long long A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
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

    quickSort(A, 0, n - 1);

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