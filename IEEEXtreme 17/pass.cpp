#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

bool yo(string s1, string s2, gp_hash_table<string, int> &mp)
{
    ll n1 = s1.size(), n2 = s2.size();
    ll n = min(n1, n2);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string x = s1.substr(i, n1 - i - j);
            string y = s2.substr(i, n2 - i - j);
            if (mp[x] == mp[y] && mp[x] != 0)
            {
                return true;
            }
            if (s1[n1 - j - 1] != s2[n2 - j - 1])
                break;
        }
        if (s1[i] != s2[i])
            break;
    }
    return false;
}

void solve()
{
    int n, k = 0;
    cin >> n;
    gp_hash_table<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        ll m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            string s;
            cin >> s;
            mp[s] = i + 1;
        }
    }
    int m;
    cin >> m;
    while (m--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (yo(s1, s2, mp) == true)
            cout << "REJECT\n";
        else
            cout << "OK\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}