#include <fstream>

using namespace std;

ifstream fin("ghiocei.in");
ofstream fout("ghiocei.out");

bool f[10];

int sumc(int n)
{
    int s = 0;
    while(n)
    {
        f[n % 10] = 1;
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main()
{
    int n;
    fin >> n;
    int d[100][100];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            fin >> d[i][j];
            d[i][j] = sumc(d[i][j]);
        }
    for(int i = 1; i < 10; i++)
        if(f[i])    fout << i;
    fout << "\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            fout << d[i][j] << " ";
        }
        fout << "\n";
    }
    return 0;
}
