/*
    score = 100pt
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
string decode(string s)
{
    int key = 14;
    string t = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            t += ((int)s[i] - (int)'A' + key) % 26 + 'A';
            // cout << (int)s[i]<< "=" << ((int)s[i]-(int)'A'+key)%26+'A' << " ";
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            // cout << (int)s[i]<< "=" << ((int)s[i]-(int)'a'+key)%26+'a' << " ";
            t += ((int)s[i] - (int)'a' + key) % 26 + 'a';
        }
        else
        {
            t += s[i];
        }
    }
    cout << "\n";
    return t;
}
int main()
{
    string line;
    while (getline(cin, line))
    {
        cout << decode(line);
    }
    return 0;
}
