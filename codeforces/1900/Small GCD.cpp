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
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n), vc(n), pre(n), val(1e5 + 10);
    ll big = 0;
    vector<ll> nw;
    map<ll, ll> mp;
    set<ll> s;
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
        a[i] = n - 1 - i;
        mp[vc[i]] += n - 1 - i;
        big = max(big, vc[i]);
    }
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];
    for (int i = 0; i < n - 1; i++)
    {
        ll ct = 1;
        ll sum = pre[n - 2] - pre[i];
        val[vc[i]] += a[i];
        cout << sum << " --\n";
        while (ct * vc[i] < big)
        {
            if (mp[ct * vc[i]])
            {
                if (ct == 1)
                {
                    ans += (mp[ct * vc[i]] - val[vc[i]]) * vc[i];
                    sum -= mp[ct * vc[i]] - val[vc[i]];
                }
                else
                {
                    ans += mp[ct * vc[i]] * vc[i];
                    sum -= mp[ct * vc[i]];
                }
                cout << vc[i] << " " << ct * vc[i] << " " << mp[ct * vc[i]] << " " << a[i] << " " << ans << " " << sum << "\n";
            }
            ct++;
        }
        ans += sum;
    }
    cout << ans << "\n";
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
/*
6 12 8	    gcd(6, 8)   =	2
6 12 10	    gcd(6, 10)  =	2
6 12 15	    gcd(6, 12)  =	6
6 12 12	    gcd(6, 12)  =	6
6 12 18	    gcd(6, 12)  =	6
6 12 16	    gcd(6, 12)  =	6
6 8 10	    gcd(6, 8)   =	2
6 8 15	    gcd(6, 8)   =	2
6 8 12	    gcd(6, 8)   =	2
6 8 18	    gcd(6, 8)   =	2
6 8 16	    gcd(6, 8)   =	2
6 10 15	    gcd(6, 10)  =	2
6 10 12	    gcd(6, 10)  =	2
6 10 18	    gcd(6, 10)  =	2
6 10 16	    gcd(6, 10)  =	2
6 15 12	    gcd(6, 12)  =	6
6 15 18	    gcd(6, 15)  =	3
6 15 16	    gcd(6, 15)  =	3
6 12 18	    gcd(6, 12)  =	6
6 12 16	    gcd(6, 12)  =	6
6 18 16	    gcd(6, 16)  =	2
12 8 10	    gcd(8, 10)  =	2
12 8 15	    gcd(8, 12)  =	4
12 8 12	    gcd(8, 12)  =	4
12 8 18	    gcd(8, 12)  =	4
12 8 16	    gcd(8, 12)  =	4
12 10 15	gcd(10, 12) =	2
12 10 12	gcd(10, 12) =	2
12 10 18	gcd(10, 12) =	2
12 10 16	gcd(10, 12) =	2
12 15 12	gcd(12, 12) =	12
12 15 18	gcd(12, 15) =	3
12 15 16	gcd(12, 15) =	3
12 12 18	gcd(12, 12) =	12
12 12 16	gcd(12, 12) =	12
12 18 16	gcd(12, 16) =	4
8 10 15	    gcd(8, 10)  =	2
8 10 12	    gcd(8, 10)  =	2
8 10 18	    gcd(8, 10)  =	2
8 10 16	    gcd(8, 10)  =	2
8 15 12	    gcd(8, 12)  =	4
8 15 18	    gcd(8, 15)  =	1
8 15 16	    gcd(8, 15)  =	1
8 12 18	    gcd(8, 12)  =	4
8 12 16	    gcd(8, 12)  =	4
8 18 16	    gcd(8, 16)  =	8
10 15 12	gcd(10, 12) =	2
10 15 18	gcd(10, 15) =	5
10 15 16	gcd(10, 15) =	5
10 12 18	gcd(10, 12) =	2
10 12 16	gcd(10, 12) =	2
10 18 16	gcd(10, 16) =	2
15 12 18	gcd(12, 15) =	3
15 12 16	gcd(12, 15) =	3
15 18 16	gcd(15, 16) =	1
12 18 16	gcd(12, 16) =	4
*/