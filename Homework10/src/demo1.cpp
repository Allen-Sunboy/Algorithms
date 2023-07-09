#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

#include <windows.h>

using namespace std;

char T[10000005];
char P[1005];

void BFMatcher()
{
    int n = strlen(T);
    int m = strlen(P);
    std::cout << "shift: ";
    for(int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while(P[j] == T[i+j] && j < m)
            j++;
        if(j == m)
            std::cout << i << " ";
    }
    std::cout << endl;
}

void read(string fileName)
{
    ifstream fin;
    fin.open(fileName);

    if(!fin)
    {
        std::cout << "ERROR!\n";
        fin.close();
        return;
    }

    while(fin.getline(T, 10000005))
    {
        LARGE_INTEGER freq, time_start, time_end;
        QueryPerformanceFrequency(&freq);
        QueryPerformanceCounter(&time_start);

        BFMatcher();

        QueryPerformanceCounter(&time_end);
        double elap = (double)(time_end.QuadPart - time_start.QuadPart) / (double)freq.QuadPart * 1000000; // 单位：微秒
        std::cout << "time: ";
        std::cout << elap << endl;
    }

    fin.close();
}


int main()
{
    string fileName;
    getline(cin, fileName);

    string PString;
    getline(cin, PString);
    strcpy(P, PString.data());

    read(fileName);

    system("pause");
}
