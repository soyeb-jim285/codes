#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
map<char, int> mp;
// bool chck(vector<char> t1, vector<char> t2)
//{
//     set<char> u1, u2;
//     for (ll i = 0; i < t1.size(); i++)
//     {
//         u1.insert(t1[i]);
//     }
//     for (ll i = 0; i < t2.size(); i++)
//     {
//         u2.insert(t1[i]);
//     }
//     if (u1.size() == 1 && u2.size() == 1)
//     {
//         if(u1==u2)
//         return true;
//         else false;
//     }
//     return false;
// }
void solve()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    map<int, int> ss1, ss2;
    deque<int> p2, p1;
    for (auto ic : s1)
        if (ic != ' ')
        {
            p1.push_back(mp[ic]);
            ss1[mp[ic]]++;
        }
    for (auto ic : s2)
        if (ic != ' ')
        {
            p2.push_back(mp[ic]);
            ss2[mp[ic]]++;
        }
    ll m = max(p1.size(), p2.size());
    map<int, int> mpx1, mpx2;
    ll ct = 0;
    while (p1.size() > 0 && p2.size() > 0)
    {
        ll a = p1.front(), b = p2.front();
        p1.pop_front();
        p2.pop_front();
        if (a > b)
        {
            p1.push_back(b);
        }
        else if (b > a)
        {
            p2.push_back(a);
        }
        else
        {
            p1.push_back(a);
            p2.push_back(b);
        }
        ct++;
        if (mpx1[ct % m] == p1.size() && mpx2[ct % m] == p2.size())
        {
            break;
        }
        mpx1[ct%m] = p1.size();
        mpx2[ct%m] = p2.size();
    }
    if (p1.size() && p2.size())
    {
        cout << "draw\n";
    }
    else if (p1.size())
    {
        cout << "player 1\n";
    }
    else
        cout << "player 2\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    mp['2'] = 1;
    mp['3'] = 2;
    mp['4'] = 3;
    mp['5'] = 4;
    mp['6'] = 5;
    mp['7'] = 6;
    mp['8'] = 7;
    mp['9'] = 8;
    mp['T'] = 9;
    mp['J'] = 10;
    mp['Q'] = 11;
    mp['K'] = 12;
    mp['A'] = 13;
    int t;
    cin >> t;
    string str;
    getline(cin, str);
    while (t--)
        solve();
    return 0;
}