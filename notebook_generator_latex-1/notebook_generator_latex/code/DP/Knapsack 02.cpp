/*W <= 1e9*/
ll fn(ll ind, ll val, vector<pair<ll, ll>> &vc)
{
    if (val == 0)
        return 0;
    if (ind < 0)
        return 1e18;
    if (dp[ind][val] != -1)
        return dp[ind][val];
    ll ans = fn(ind - 1, val, vc);
    if (val - vc[ind].second >= 0)
        ans = min(ans, fn(ind - 1, val - vc[ind].second, vc) + vc[ind].first);
    return dp[ind][val] = ans;
}
void solve()
{
    ll n, w;
    cin >> n >> w;
    vector<pair<ll, ll>> vc(n);
    for (int i = 0; i < n; i++)
        cin >> vc[i].first >> vc[i].second;
    for (int i = 1e5 + 9; i >= 0; i--)
    {
        if (fn(n - 1, i, vc) <= w)
        {
            cout << i << "\n";
            return;
        }
    }
}