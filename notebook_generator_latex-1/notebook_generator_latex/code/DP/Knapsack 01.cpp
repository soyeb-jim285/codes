/*
There are NN items, numbered 1,2,…,N. For each i (1≤i≤N), Item i has a weight of wi​ and a value of vi.
Taro has decided to choose some of the N items and carry them home in a knapsack. The capacity of the knapsack is W, which means that the sum of the weights of items taken must be at most W.
Find the maximum possible sum of the values of items that Taro takes home.
*/
vector<vector<ll>> dp(110, vector<ll>(100000+10, -1));
ll fn(ll ind, ll wt, vector<pair<ll, ll>> &vc)
{
    if (ind < 0)
        return 0;
    if (wt < 0)
        return 0;
    if (dp[ind][wt] != -1)
        return dp[ind][wt];
    ll ans = fn(ind - 1, wt, vc);
    if (wt - vc[ind].first >= 0)
        ans = max(ans, fn(ind - 1, wt - vc[ind].first, vc) + vc[ind].second);
    return dp[ind][wt] = ans;
}
void solve()
{
    ll n, w;
    cin >> n >> w;
    vector<pair<ll, ll>> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i].first >> vc[i].second;
    }
    cout << fn(n - 1, w, vc);
}