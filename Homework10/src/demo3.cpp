#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

#include <windows.h>

using namespace std;

char T[10000005];
char P[1005];

int bmBc[130];
int bmGs[1005];
int Osuff[1005];

void computeOsuff()
{
    int m = strlen(P);
    int f = 0;
 
    Osuff[m - 1] = m;
    int g = m - 1;
    for(int i = m - 2; i >= 0; i--)
    {
        if(i > g && Osuff[i+m-1-f] < i-g)
            Osuff[i] = Osuff[i+m-1-f];
        else
        {
            if(i < g)
                g = i;
            f = i;
            while(g >= 0 && P[g] == P[g+m-1-f])
                g--;
            Osuff[i] = f - g;
        }
    }

}

void computeBmGs()
{
    int m = strlen(P);
    computeOsuff();
 
    for(int i = 0; i < m; i++)
        bmGs[i] = m;
    int j = 0;
    for(int i = m - 1; i >= 0; i--)
        if(Osuff[i] == i + 1)
            for(; j < m - 1 - i; j++)
                if(bmGs[j] == m)
                    bmGs[j] = m - 1 - i;    
    for(int i = 0; i <= m - 2; i++)
        bmGs[m-1-Osuff[i]] = m - 1 - i;

}

void computeBmBc()
{
    int m = strlen(P);
    for(int i = 0; i < 128; i++)
        bmBc[i] = m;
    for(int i = 0; i < m-1; i++)
        bmBc[P[i]] = m - i - 1;
}


void BMMatcher()
{
    int n = strlen(T);
    int m = strlen(P);

    computeBmBc();
    computeBmGs();

    std::cout << "shift: ";

    int s = 0;
    while(s <= n - m)
    {
        int i = m - 1;
        while(i >= 0 && P[i] == T[i + s])
            i--;
        if(i < 0)
        {
            std::cout << s << " ";
            s += bmGs[0];
        }
        else
            s += max(bmGs[i], bmBc[T[i + s]] - m + 1 + i);
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

        BMMatcher();

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
