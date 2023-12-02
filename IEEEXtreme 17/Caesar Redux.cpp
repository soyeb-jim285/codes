#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
void solve()
{
    ll n;
    cin >> n;
    string s;
    getline(cin, s);
    getline(cin, s);
    bool ck = 0;
    for (int i = 0; i < s.size() - 2; i++)
    {
        if (s[i] == 't' && s[i + 1] == 'h' && s[i + 2] == 'e')
        {
            if (i == 0 && i + 2 == s.size() - 1)
                ck = 1;
            else if (i == 0)
            {
                if (s[i + 3] == ' ')
                    ck = 1;
            }
            else if (i + 2 == s.size() - 1)
            {
                if (s[i - 1] == ' ')
                    ck = 1;
            }
            else
            {
                if (s[i - 1] == ' ' && s[i + 3] == ' ')
                    ck = 1;
            }
        }
    }
    // cout << ck << "\n";
    if (ck)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;
            s[i] -= n;
            if ((int)s[i] < 97)
                s[i] += 26;
        }
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;
            int k;
            if((int)s[i] + n > 122)
            {
                k = n -26;
            }
            else k = n;
            s[i]+= k;
            //cout << s[i] << " " << (int)s[i] << "\n";
        }
    }
    cout << s << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}