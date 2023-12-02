/*You are given strings ss and tt. Find one longest string that is a subsequence of both ss and tt.*/
void fn(ll i, ll j, vector<ll> & ans, vector<vector<ll>> &vc)
{
    if (vc[i][j] == 0)
        return;
    if (vc[i][j] > vc[i - 1][j] && vc[i][j] > vc[i][j - 1])
    {
        fn(i - 1, j - 1, ans, vc);
        ans.push_back(i);
    }
    else if (vc[i][j] == vc[i-1][j])
    {
        fn(i-1, j, ans, vc);
    }
    else{
        fn(i, j-1, ans, vc);
    }
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<ll>> vc(s1.size() + 1, vector<ll>(s2.size() + 1, 0));
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
            {
                vc[i + 1][j + 1] = 1 + vc[i][j];
            }
            else
            {
                vc[i + 1][j + 1] = max(vc[i][j + 1], vc[i + 1][j]);
            }
        }
    }
    vector<ll> ans;
    fn(s1.size(), s2.size(), ans, vc);
    for(auto ic: ans)
    cout << s1[ic-1];
}