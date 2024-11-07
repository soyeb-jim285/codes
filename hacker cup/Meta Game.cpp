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
    vector<ll> vc(2 * n), pre(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> vc[i];
    }
    ll ones = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        int ind = (i + n) % (2 * n);
        if (ind < 0)
            ind += 2 * n;
        if (vc[i] < vc[ind])
        {
            pre[i] = 1;
            ones++;
        }
        else if (vc[i] == vc[ind])
            pre[i] = -1;
        else
            pre[i] = 0;
    }
    ll fst = 0, seg = 0, fstind = -1;
    if (n % 2)
    {
        if (ones != n - 1)
        {
            cout << "-1\n";
            return;
        }
    }
    else
    {
        if (ones != n)
        {
            cout << "-1\n";
            return;
        }
    }
    //for (auto ic : pre)
    //    cout << ic << " ";
    //cout << "\n";
    ones = 0;
    int zero = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (pre[i] == 1)
        {
            ones++;
            zero = 0;
            if (fstind == -1)
                fstind = i;
        }
        else
        {
            if (ones)
            {
                seg++;
                if (seg == 1)
                {
                    fst = ones;
                    //cout << ones << " " << i << "\n";
                }
            }
            zero++;
            ones = 0;
        }
    }
    if (ones)
    {
        seg++;
        if (seg == 1)
            fst = ones;
    }
    if (seg > 2)
    {
        cout << "-1\n";
        return;
    }
    else
    {
        //cout << fst << " " << seg << " " << fstind << "\n";
        if (seg == 1)
        {
            cout << fstind + n / 2 << "\n";
        }
        else
        {
            if (pre[0] == 1 && pre[2 * n - 1] == 1)
            {
                cout << fst - n / 2 << "\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen64("meta_game_input.txt", "r", stdin);
    freopen64("meta_game_out.txt", "w", stdout);
    int t, tt = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << tt++ << ": ";
        solve();
    }
    return 0;
}