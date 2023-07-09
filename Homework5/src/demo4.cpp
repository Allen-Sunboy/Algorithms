#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>

#include <windows.h>

using namespace std;

default_random_engine e(time(0));
uniform_int_distribution<long long> u(0, 4294967295);

long long A[200000007];
int n;

void merge(long long A[], int p, int q, int r)
{
    // int x = r - p + 3;
    long long *an = new long long[r - p + 3];
    int i = p, j = q + 1, k = 0;
    while(i <= q && j <= r)
    {
        if(A[i] < A[j])
            an[k++] = A[i++];
        else
            an[k++] = A[j++];
    }
    while(i <= q)
        an[k++] = A[i++];
    while(j <= r)
        an[k++] = A[j++];
    for(i = 0; i < k; i++)
        A[p + i] = an[i];
    delete[] an;
}


void mergeSort(long long A[], int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
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

    mergeSort(A, 0, n-1);

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