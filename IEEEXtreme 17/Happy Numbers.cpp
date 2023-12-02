#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
vector<vector<multiset<ll>>> vp(16);
ll const mod = 1e13 + 37;
vector<ll> fact(16 + 1);
map<int, bool> one;
int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
void fc()
{
    fact[0] = 1;
    for (int i = 1; i < 17; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
}
ll binpowmod(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
            res = res % m;
        }
        a *= a;
        a = a % m;
        b >>= 1;
    }
    return res;
}
ll sqv(ll n)
{
    ll ans = 0;
    while (n > 0)
    {
        ans += (n % 10) * (n % 10);
        n /= 10;
    }
    return ans;
}
bool fn(ll n)
{
    map<ll, bool> mp;
    while (mp[n] == 0 && n != 1)
    {
        mp[n] = 1;
        n = sqv(n);
    }
    if (n == 1)
        return 1;
    else
        return 0;
}
void CombinationRepetitionUtil(int chosen[], int arr[],
                               int index, int r, int start, int end, ll & ans, vector<int> samne)
{
    if (index == r)
    {
        map<int, int> mp;
        ll cg = 0;
        for (auto ic : samne)
            cg += ic * ic;
        for (int i = 0; i < r; i++)
        {
            mp[arr[chosen[i]]]++;
            cg += arr[chosen[i]] * arr[chosen[i]];
            // tmp.insert(arr[chosen[i]]);
        }
        if (one[cg])
        {
            ll sum = 0, niche = 1;
            for (auto ic : mp)
            {
                sum += ic.second;
                niche *= fact[ic.second];
            }
            ans = fact[sum];
            ans = ans * binpowmod(niche, mod - 2, mod);
            cout << ans << "\n";
        }

        // vp[r].push_back(tmp);
        return;
    }
    for (int i = start; i <= end; i++)
    {
        chosen[index] = i;
        CombinationRepetitionUtil(chosen, arr, index + 1,
                                  r, i, end, ans, samne);
    }
    return;
}
void CombinationRepetition(int arr[], int n, int r, ll & ans, vector<int> samne)
{
    int chosen[r + 1];
    CombinationRepetitionUtil(chosen, arr, 0, r, 0, n - 1, ans, samne);
}
int numdig(ll n)
{
    int ans = 0;
    while (n > 0)
    {
        ans++;
        n /= 10;
    }
    return ans;
}
ll fnn(ll n)
{
    ll ans = 0;
    vector<int> samne;
    for (int i = numdig(n) - 1; i >= 0; i--)
    {
        string x = to_string(n);
        for (int j = 0; j < x[samne.size()] - '0'; j++)
        {
            samne.push_back(j);
            CombinationRepetition(arr, 10, i, ans, samne);
            samne.pop_back();
        }
        samne.push_back(x[samne.size()] - '0');
    }
    return ans;
}
void solve()
{
    ll n, m;
    cin >> n >> m;

    for (int i = 1; i <= 1296; i++)
    {
        if (fn(i))
        {
            one[i] = 1;
        }
    }
    cout << fnn(n) << " " << fnn(m) << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fc();
    solve();
    return 0;
}