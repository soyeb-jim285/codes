/*
score = 50pt
*/

#include <bits/stdc++.h>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <string_view>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
int const N = 1e4 + 5;
vector<string> names;
map<int, bool> map_ins, map_vis;
map<int, string> map_name;
map<int, int> map_yes, map_no, map_bg, map_ed, map_naa;
set<int> rts, id, roots;
map<int, int> new_ind;
bool ins[N], vis[N];
string name[N];
int yes[N], no[N], bg[N], ed[N], naa[N];
vector<vector<int>> indds(1e6 + 5);
vector<int> utf8StringToCodePointsWithSpaces(const std::string &utf8_string)
{
    std::vector<int> codePoints;

    for (size_t i = 0; i < utf8_string.length();)
    {
        unsigned int codePoint = 0;
        unsigned char leadingByte = utf8_string[i];

        // Handle spaces (whitespace)
        if (leadingByte == ' ')
        {
            codePoints.push_back(' '); // Space character
            i++;
        }
        else if ((leadingByte & 0b10000000) == 0)
        {
            codePoint = leadingByte;
            i += 1;
        }
        else if ((leadingByte & 0b11100000) == 0b11000000)
        {
            codePoint = leadingByte & 0b00011111;
            codePoint <<= 6;
            codePoint |= utf8_string[i + 1] & 0b00111111;
            i += 2;
        }
        else if ((leadingByte & 0b11110000) == 0b11100000)
        {
            codePoint = leadingByte & 0b00001111;
            codePoint <<= 12;
            codePoint |= (utf8_string[i + 1] & 0b00111111) << 6;
            codePoint |= utf8_string[i + 2] & 0b00111111;
            i += 3;
        }
        else if ((leadingByte & 0b11111000) == 0b11110000)
        {
            codePoint = leadingByte & 0b00000111;
            codePoint <<= 18;
            codePoint |= (utf8_string[i + 1] & 0b00111111) << 12;
            codePoint |= (utf8_string[i + 2] & 0b00111111) << 6;
            codePoint |= utf8_string[i + 3] & 0b00111111;
            i += 4;
        }

        codePoints.push_back(codePoint);
    }

    return codePoints;
}
void dfs(int n)
{
    //cout << n << "-----\n";
    vis[n] = 1;
    if (ins[n])
    {
        if (!vis[yes[n]])
            dfs(yes[n]);
        if (!vis[no[n]])
            dfs(no[n]);
        bg[n] = bg[yes[n]];
        ed[n] = ed[no[n]];
    }
    else
    {
        bg[n] = names.size();
        ed[n] = names.size();
        names.push_back(name[n]);
        //cout << n << " " << name[n] << " " << bg[n] << " " << ed[n] << "\n";
    }
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        char x;
        cin >> x;
        int ind;
        cin >> ind;
        new_ind[ind] = i;
        // rts.insert(ind);
        if (x == 'I')
            map_ins[ind] = 1;
        else
            map_ins[ind] = 0;
        string xx;
        cin >> xx;
        if (map_ins[ind])
        {
            map_naa[ind] = utf8StringToCodePointsWithSpaces(xx)[0];
            // map_indds[utf8StringToCodePointsWithSpaces(xx)[0]].push_back(ind);
            //cout << xx << " " << map_naa[ind] << "\n";
            int a, b;
            cin >> a >> b;
            // id.insert(a);
            // id.insert(b);
            map_yes[ind] = a;
            map_no[ind] = b;
        }
        else
        {
            map_name[ind] = xx;
        }
    }
    for (auto ic : new_ind)
    {
        rts.insert(ic.second);
        ins[ic.second] = map_ins[ic.first];
        if (ins[ic.second])
        {
            naa[ic.second] = map_naa[ic.first];
            indds[naa[ic.second]].push_back(ic.second);
            yes[ic.second] = new_ind[map_yes[ic.first]];
            no[ic.second] = new_ind[map_no[ic.first]];
            id.insert(yes[ic.second]);
            id.insert(no[ic.second]);
        }
        else
        {
            name[ic.second] = map_name[ic.first];
        }
    }
    for (auto i = rts.begin(); i != rts.end(); i++)
    {
         if (!id.count(*i))
             roots.insert(*i);
     }
     for (auto i = roots.begin(); i != roots.end(); i++)
    {
         dfs(*i);
     }
    string p;
    getline(cin, p);
    while (q--)
    {
        string x;
        getline(cin, x);
        // cout << x << "\n";
        vector<int> nums = utf8StringToCodePointsWithSpaces(x);
        vector<int> fi(names.size(), 0);
        map<int, bool> lkj;
        for (int i = 0; i < nums.size(); i++)
        {
            if (indds[nums[i]].size())
            {
                //cout << nums[i] << " ";
                for (int j = 0; j < indds[nums[i]].size(); j++)
                {
                    int child = no[indds[nums[i]][j]];
                    fi[bg[child]] += 1;
                    fi[ed[child]] -= 1;
                    lkj[bg[child]] = 1;
                    lkj[ed[child]] = 1;
                    // cout << bg[child] << " " << ed[child]<< " " << fi[bg[child]] << " " << fi[ed[child]] << "\n";
                }
            }
        }
        ll ct = 0;
        set<string> s;
        //for (auto ic : fi)
        //    cout << ic << " ";
        //cout << "\n";
        for (int i = 0; i < names.size(); i++)
        {
            ct += fi[i];
            if (ct == 0 && lkj[i] == 0)
            {
                s.insert(names[i]);
            }
        }
        for (auto i = s.begin(); i != s.end(); i++)
            cout << *i << " ";
        cout << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}