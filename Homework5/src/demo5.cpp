#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
#include <cmath> //log2()
#include <windows.h>

using namespace std;

default_random_engine e(time(0));
uniform_int_distribution<long long> u(0, 4294967295);

long long A[200000007];
int n;

void radixSort(long long A[], int n)
{
    int b = 32;
    int r = log2(n); //基数
    int d = b / r + 1;
    int n0 = pow(2, r); //位数取值可能

    long long *A_temp = new long long[200000007]; //数字处理
    long long *a = new long long[200000007]; //当前位数，最低位数

    long long *B = new long long[200000007];
    long long *B_temp = new long long[200000007];

    long long *C = new long long[n0+3];

    for(int i = 0; i < n; i++)
        A_temp[i] = A[i];

    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < n0; j++)
            C[j] = 0;
        
        for(int j = 0; j < n; j++)
            a[j] = A_temp[j] % n0;
        
        for(int j = 0; j < n; j++)
            C[a[j]]++;
        
        for(int j = 1; j < n0; j++)
            C[j] += C[j-1];
        
        for(int j = n-1; j >= 0; j--)
        {
            B[C[a[j]]-1] = A[j];
            B_temp[C[a[j]]-1] = A_temp[j];
            C[a[j]]--;
        }

        for(int j = 0; j < n; j++)
        {
            A[j] = B[j];
            A_temp[j] = B_temp[j] / n0;
        }

    }

    delete[] A_temp;
    delete[] a;
    delete[] B;
    delete[] C;
    delete[] B_temp;

}

void test(int n)
{
    for(int i = 0; i < n; i++)
        A[i] = u(e);

    // for(int i = 0; i < n; i++)
    //     cout << A[i] << " ";
    // cout << "\n";

    LARGE_INTEGER freq, time_start, time_end;
    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&time_start);

    radixSort(A, n);

    QueryPerformanceCounter(&time_end);

    double elap = (double)(time_end.QuadPart - time_start.QuadPart) / (double)freq.QuadPart * 1000000; // 单位 微秒
    cout << setprecision(12) << elap << "\n";

    // for(int i = 0; i < n; i++)
    //     cout << A[i] << " ";
    // cout << "\n";

}

int main()
{
    cin >> n;

    test(n);

    // for(int i = 10; i <= 100000000; i *= 10)
    // {
    //     cout << i << " ";
    //     test(i);
    // }

    system("pause");

}