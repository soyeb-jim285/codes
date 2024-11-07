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
    string str;
    getline(cin, str);
    set<string> ans;
    vector<string> aro, ki;
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        string x = "";
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == ' ')
            {
                if (x == "->" || x == "??")
                {
                    if (x == "->")
                    {
                        aro.push_back(str);
                    }
                    else
                    {
                        ki.push_back(str);
                    }
                }
                else
                {
                    ans.insert(x);
                }
                x = "";
            }
            else
            {
                x += str[j];
            }
        }
        ans.insert(x);
    }
    map<string, vector<string>> mp;
    for (int i = 0; i < ki.size(); i++)
    {
        string x = "", a = "";
        for (int j = 0; j < ki[i].size(); j++)
        {
            if (ki[i][j] == ' ')
            {
                if (!a.size())
                    a = x;
                x = "";
            }
            else
            {
                x += ki[i][j];
            }
        }
        mp[a].push_back(x);
        mp[x].push_back(a);
    }
    for (int i = 0; i < aro.size(); i++)
    {
        string x = "", a = "";
        for (int j = 0; j < aro[i].size(); j++)
        {
            if (aro[i][j] == ' ')
            {
                if (!a.size())
                    a = x;
                x = "";
            }
            else
            {
                x += aro[i][j];
            }
        }
        ans.erase(x);
        for (auto ic : mp[x])
        {
            ans.erase(ic);
        }
    }
    for(auto ic: ans)
    cout << ic << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}