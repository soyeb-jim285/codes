/*
    score = 100pt;
*/
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
    ll tk;
    cin >> tk;
    vector<vector<string>> vc(5);
    vector<vector<pair<ll, ll>>> pri(5);
    for (int i = 0; i < 5; i++)
    {
        ll n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            string x;
            cin >> x;
            vc[i].push_back(x);
            ll val;
            cin >> val;
            pri[i].push_back({val, j});
        }
        sort(pri[i].begin(), pri[i].end());
    }
    vector<string> ans(5);
    for (int i = 0; i < 5; i++)
    {
        ans[i] = vc[i][pri[i][0].second];
    }
    ll mx = 0;
    for (int i = 0; i < (int)pri[4].size(); i++)
    {
        ll sum1 = pri[4][i].first;
        if (sum1 < tk)
            for (int j = 0; j < (int)pri[3].size(); j++)
            {
                ll sum2 = sum1 + pri[3][j].first;
                if (sum2 < tk)
                    for (int k = 0; k < (int)pri[2].size(); k++)
                    {
                        ll sum3 = sum2 + pri[2][k].first;
                        if (sum3 < tk)
                            for (int ii = 0; ii < (int)pri[1].size(); ii++)
                            {
                                ll sum4 = sum3 + pri[1][ii].first;
                                if (sum4 < tk)
                                {
                                    pair p = make_pair(tk - sum4, (ll)pri[0].size());
                                    auto ic = upper_bound(pri[0].begin(), pri[0].end(), p) - pri[0].begin();
                                    ic--;
                                    if (ic >= 0 && ic < (int)pri[0].size())
                                    {
                                        ll sum = sum4 + pri[0][ic].first;
                                        vector<string> aa(5);
                                        aa[0] = vc[0][pri[0][ic].second];
                                        aa[1] = vc[1][pri[1][ii].second];
                                        aa[2] = vc[2][pri[2][k].second];
                                        aa[3] = vc[3][pri[3][j].second];
                                        aa[4] = vc[4][pri[4][i].second];
                                        // cout <<sum1 << " "<< sum2 << " "<< sum3 << " "<< sum4 << " "<< tk - sum4 << " "<< ic<< " " << vc[0][pri[0][ic].second] << "\n";
                                        //  for(auto il : pri[0])
                                        //  cout << il.first << " " << il.second << "\n";
                                        if (sum >= mx)
                                        {
                                            if (sum == mx)
                                            {
                                                bool ck = 0;
                                                if(aa < ans)
                                                {
                                                    ans = aa;
                                                }
                                            }
                                            else
                                            {
                                                mx = sum;
                                                ans = aa;
                                            }
                                        }
                                    }
                                }
                            }
                    }
            }
    }
    for (auto ic : ans)
        cout << ic << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}