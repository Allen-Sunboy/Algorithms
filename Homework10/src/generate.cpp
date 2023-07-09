#include <iostream>
#include <fstream>
#include <ctime>
#include <random>
using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789 ~!@$%&()-_=+;:\'\",.?";

char T[10000005];
char P[1005];

void generate(int n, int m)
{
    if(n < m)
    {
        std::cout << "error: must T.length >= P.length\n";
        return;
    }
    int alphabetLength = alphabet.length();

    time_t t = time(0);
    string fileName = to_string(t);
    fileName += ".txt";

    ofstream fout;
    fout.open(fileName);

    srand(time(0));

    for(int i = 0; i < n; i++)
        T[i] = alphabet[rand() % alphabetLength];

    default_random_engine e(time(0));
    uniform_int_distribution<int> u(0, n-m);

    int p = u(e);
    for(int i = 0; i < m; i++)
        P[i] = T[i+p];

    fout << T;
    fout.close();

    std::cout << P << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    generate(n, m);
    
    system("pause");
}