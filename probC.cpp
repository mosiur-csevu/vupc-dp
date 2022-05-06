#include <bits/stdc++.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
typedef long long int ll;
typedef unsigned long long int ull;

int main()
{
    int n;
    cin >> n;
    ll f[n + 1][8];
    ll inf = 1e7;

    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j < 8; j++)
        {
            f[i][j] = inf;
        }
    }
    ll ans = inf;
    f[0][0] = 0;

    for (ll i = 0; i < n; i++)
    {
        ll cost;
        string s;
        cin >> cost >> s;
        int string_mask = 0;
        for (int pos = 0; pos < 3; pos++)
        {
            char c = 'C' - pos;
            bool have = 0;
            for (char d : s)
            {
                if (c == d)
                    have = 1;
            }
            if (have)
                string_mask += (1 << pos);
        }

        cout << "----mask for " << s << ": " << string_mask << endl;
        for (ll mask = 0; mask < 8; mask++)
        {
            f[i + 1][mask] = min(f[i + 1][mask], f[i][mask]);
            f[i + 1][mask | string_mask] = min(f[i + 1][mask | string_mask], f[i][mask] + cost);
        }

        for (ll i = 0; i <= n; i++)
        {
            for (ll j = 0; j < 8; j++)
            {
                cout << f[i][j] << " ";
            }
            cout << endl;
        }
    }

    if (f[n][7] == inf)
        cout << -1 << endl;
    else
        cout << f[n][7] << endl;
    return 0;
}