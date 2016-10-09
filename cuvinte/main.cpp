#include <stdio.h>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

ifstream fin("cuvinte.in");
ofstream fout("cuvinte.out");

int main()
{
    int terminal = 0;
    short f[26];
    for(int cuv = 1; cuv <= 3; cuv++)
    {
        terminal = 0;
        char cc[1000], cs[1000];
        fin.getline(cc, 1000);
        int ccl = strlen(cc) - 1, csl = -1;
        for(int k = 0; k <= 25; k++)
            f[k] = 0;
        for(int i = 0; i <= ccl; i++)
            f[cc[i] - 65] ++;

        for(int i = 65; i <= 90; i++)
        {
            while(cs[csl] == i && csl >= 0)
            {
                csl --;
                terminal ++;
                f[i - 65]--;
            }
            for(int j = ccl; j >= 0 && f[i - 65]; j--)
            {
                if(cc[j] == i)
                {
                    ccl--;
                    terminal++;
                    f[i - 65]--;
                }else
                {
                    ccl --;
                    csl ++;
                    cs[csl] = cc[j];
                    f[cc[j] - 65]--;
                }
            }
            if(f[i - 65])   break;
        }
        fout << terminal << "\n";
    }
    return 0;
}
