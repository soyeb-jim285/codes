#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> vl;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        vl.push_back(x);
    }
    map<ll, ll> mp;
    ll ct = 0;
    for (ll i = 0; i < n; i++)
    {
        if (vl[i] >= 360)
        {
            vl[i] = vl[i] % 360;
        }
        else if (vl[i] <= -360)
        {
            vl[i] = -(abs(vl[i]) % 360);
        }
        if (mp[vl[i]] == 0)
        {
            ct++;
            if (vl[i] >= 0)
            {
                mp[vl[i]]++;
                ll tm = vl[i] + 180;
                mp[tm]++;
                mp[tm - 360]++;
            }
            else
            {
                mp[vl[i]]++;
                ll tm = vl[i] - 180;
                mp[tm]++;
                mp[tm + 360]++;
            }
        }
        else 
        continue;
    }
    ll ans = ct * 2;
    if (ans == 0)
        cout << "1" << endl;
    else
        cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}