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

void insertionSort(long long A[], int n) {
    for (int j = 1; j < n; j++) {
        long long key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
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

    insertionSort(A, n);

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

    // for(int i = 10; i <= 1000000; i *= 10)
    // {
    //     cout << i << " ";
    //     test(i);
    // }

    system("pause");
}