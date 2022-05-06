#include <bits/stdc++.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
typedef long long int ll;
typedef unsigned long long int ull;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n+1];
    string s;
    cin >> s;

    bool not_broken[26] = {0};

    for (ll i = 0; i < k; i++)
    {
        char c;
        cin >> c;
        not_broken[c - 'a'] = 1;
    }

    for (ll i = 0; i < n; i++)
    {
        if (not_broken[s[i] - 'a'] == 1)
            a[i] = 1;
        else
            a[i] = 0;
    }

    ll f[n + 1];
    f[0] = 0;

    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        if (a[i])
            f[i + 1] = f[i] + 1;
        else
            f[i + 1] = 0;
        ans += f[i + 1];
    }
    cout << ans << endl;

    return 0;
}