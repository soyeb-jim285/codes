#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
void solve()
{
    ll n;
    cin >> n;
    stack<pair<ld, ld>> st;
    for (int i = 0; i < n; i++)
    {
        ld pos, r;
        cin >> pos >> r;
        ld red = r;
        if (st.size() == 0)
        {
            st.push({pos, red});
            printf("%.3Lf\n", red);
        }
        else
        {
            bool ck = 0;
            ld mn = r;
            while (st.size())
            {
                ld a = st.top().second;
                ld d = pos - st.top().first;
                ld rr = (1.0 * d * d) / (4 * a);
                mn = min(mn, rr);
                if (rr < a)
                {
                    printf("%.3Lf\n", mn);
                    st.push({pos, mn});
                    ck = 1;
                    break;
                }
                else
                    st.pop();
            }
            if (!ck)
            {
                st.push({pos, mn});
                printf("%.3Lf\n", mn);
            }
        }
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    cout << setprecision(20);
    solve();
    return 0;
}
