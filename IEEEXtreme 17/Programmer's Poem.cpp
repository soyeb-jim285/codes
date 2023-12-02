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
    ll n, k;
    cin >> n >> k;
    map<string, int> mp;
    map<int, char> mpx;
    string s;
    getline(cin, s);
    ll ct = 1;
    while (n--)
    {
        getline(cin, s);
        string x = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                mp[x] = ct;
                x = "";
            }
            else
            {
                x += tolower(s[i]);
            }
        }
        mp[x] = ct;
        ct++;
    }
    getline(cin, s);
    vector<int> ans(k);
    map<int, int> ase;
    char j = 'A';
    ct = 0;
    while (k--)
    {
        getline(cin, s);
        string x = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                // mp[x] = ct;
                x = "";
            }
            else
            {
                x += tolower(s[i]);
            }
        }
        if (mp[x])
        {
            ans[ct] = mp[x];
            ase[ans[ct]]++;
        }
        else
        {
            ans[ct] = -1;
        }
        ct++;
    }
    //for(auto ic: ans)
    //cout << ic << " ";
    //cout << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == -1)
            cout << "X";
        else
        {
            if (ase[ans[i]] > 1)
            {
                if (mpx[ans[i]])
                    cout << mpx[ans[i]];
                else
                {
                    mpx[ans[i]] = j;
                    cout << j;
                    j++;
                    if (j == 'X')
                        j++;
                }
            }
            else{
                cout << "X";
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}