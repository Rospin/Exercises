#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cestor.in");
ofstream fout("cestor.out");

int main()
{
    int q = 1, r = 0, k = 0, x, y, nc, nl, m, v;
    char op;
    fin >> x >> y >> nl >> nc >> m;
    for(int o = 1; o <= m; o++)
    {
        fin >> op;
        switch(op)
        {
            case 'E':
                q *= 2;
                break;
            case 'R':
                if(q != 1)
                    q /= 2;
                break;
            case 'V':
                int a;
                fin >> a;
                k += a;
                break;
            case 'C':
                r++;
                break;
            case 'T':
                r--;
                break;
        }
    }
    if(r > 0)
    {
        r = r % 4;
    }else
    {
        if(r % 4 == 0)
            r = 0;
        else
            r = r % 4 + 4;
    }
    if(x % q == 0)
        x = x / q;
    else
        x = x / q + 1;
    if(y % q == 0)
        y = y / q;
    else
        y = y / q + 1;
    switch(r)
    {
        case 0:
            v = 1;
            v += (x - 1) * nc;
            v += y - 1;
            break;
        case 1:
            v = nc * (nl - 1) + 1;
            cout << q << " " << r << " " << k << " " << v << " ";
            v -= (y - 1) * nc;
            v += x - 1;
            break;
        case 2:
            v = nc * nl;
            v -= (x - 1) * nc;
            v -= y - 1;
            break;
        case 3:
            v = nc;
            v += (y - 1) * nc;
            v -= x - 1;
            break;
    }
    v += k;
    fout << v;
    return 0;
}
