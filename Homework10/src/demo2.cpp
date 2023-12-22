#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

#include <windows.h>

using namespace std;

char T[10000005];
char P[1005];
int pi[1005];

void computeP() {
    int m = strlen(P);
    pi[0] = -1;
    int i = 0, j = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j])
            j = pi[j];
        i++;
        j++;
        if (P[i] == P[j])
            pi[i] = pi[j];
        else
            pi[i] = j;
    }
}

void KMPMatcher() {
    int n = strlen(T);
    int m = strlen(P);

    computeP();
    std::cout << "shift: ";
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j])
            j = pi[j];
        i++;
        j++;
        if (j == m) {
            std::cout << i - j << " ";
            j = pi[j];
        }
    }
    std::cout << endl;
}

void read(string fileName) {
    ifstream fin;
    fin.open(fileName);

    if (!fin) {
        std::cout << "ERROR!\n";
        fin.close();
        return;
    }

    while (fin.getline(T, 10000005)) {
        LARGE_INTEGER freq, time_start, time_end;
        QueryPerformanceFrequency(&freq);
        QueryPerformanceCounter(&time_start);

        KMPMatcher();

        QueryPerformanceCounter(&time_end);
        double elap = (double)(time_end.QuadPart - time_start.QuadPart) /
                      (double)freq.QuadPart * 1000000; // 单位：微秒
        std::cout << "time: ";
        std::cout << elap << endl;
    }

    fin.close();
}

int main() {
    string fileName;
    getline(cin, fileName);

    string PString;
    getline(cin, PString);
    strcpy(P, PString.data());

    read(fileName);

    system("pause");
}
