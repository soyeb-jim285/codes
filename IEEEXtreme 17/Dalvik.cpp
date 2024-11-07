#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

typedef long long int ll;
typedef long double ld;
typedef queue<ll> ql;
typedef vector<ll> vl;
typedef vector<pair<ll, ll>> vll;
typedef vector<pair<ll, pair<ll, ll>>> vp;
typedef vector<vector<ll>> vvl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
#define f(i, g, h) for (long long int i = g; i < h; i++)
const long long int md = 1000000007;

ll binpow(ll x, ll y)
{
    // cout << x << " " << y << " " << res << endl;
    ll res = 1;
    while (y > 0)
    {
        if (y % 2)
        {
            res *= x % md;
            res %= md;
        }
        x = (x * x) % md;
        y /= 2;
    }
    return res % md;
}
//---------------------------------------------------------------------------------------------------------------------------
void l0(vl &v);
void l1(vl &v);
void l2(vl &v);
void l3(vl &v);
void l4(vl &v);
void l5(vl &v);
void l6(vl &v);

void l0(vl &v)
{
    //cout << "*0*\n";
    //for (auto ic : v)
    //    cout << ic << " ";
    //cout << "\n";
    v[11] += v[1];
    v[10] += v[0];
    v[13] = v[10];
    v[14] = v[4];
    v[15] = v[4];
    l1(v);
    // return;
}

void l1(vl &v)
{
    //cout << "*1*\n";
    //for (auto ic : v)
    //    cout << ic << " ";
    //cout << "\n";
    v[16] = v[13] + v[13];
    if (v[16 <= v[1]])
    {
        l2(v);
    }
    else
    {
        v[13] -= v[1];
        v[14] += v[3];
        v[15] += v[1];
        l1(v);
        l2(v);
    }
    // return;
}

void l2(vl &v)
{
    //cout << "*2*\n";
    //for (auto ic : v)
    //    cout << ic << " ";
    //cout << "\n";
    if (v[13] > v[4])
    {
        l3(v);
    }
    else
    {
        v[13] = v[4] - v[13];
        l3(v);
    }
    // return;
}

void l3(vl &v)
{
    //cout << "*3*\n";
    //for (auto ic : v)
    //    cout << ic << " ";
    //cout << "\n";
    v[17] = v[4];
    v[18] = v[3];
    l4(v);
    // return;
}

void l4(vl &v)
{
    //cout << "*4*\n";
    //for (auto ic : v)
    //    cout << ic << " ";
    //cout << "\n";
    v[17] += v[13];
    v[18] += v[3];
    if (v[18] <= v[6])
    {
        l4(v);
    }
    else
    {
        v[18] = v[3];
        l5(v);
    }
    // return;
}

void l5(vl &v)
{
    //cout << "*5*\n";
    //for (auto ic : v)
    //    cout << ic << " ";
    //cout << "\n";
    v[17] -= v[9];
    v[18] += v[3];
    if (v[18] <= v[12])
        l5(v);
    else if (v[17] >= v[4])
        l6(v);
    else
    {
        v[5] = v[14];
        v[6] = v[12];
        v[7] = v[15];
        v[8] = v[10];
        v[9] = v[13];
        l6(v);
    }
    // return;
}

void l6(vl &v)
{
    //cout << "*0*\n";
    //for (auto ic : v)
    //    cout << ic << " ";
    //cout << "\n";
    v[12] += v[3];
    if (v[12] <= v[2])
        l0(v);
    else
    {
        cout << v[6] << "\n";
        return;
    }
}

void solve()
{
    vl v(20, 0);
    v[3] = 1;
    cin >> v[0] >> v[1] >> v[2];
    v[4] = v[3] - v[3];
    v[5] = v[4] - v[3];
    v[6] = v[3];
    v[7] = v[4];
    v[7] -= v[1];
    v[8] = v[0];
    v[9] = v[0];
    v[9] = v[0] + v[1];
    v[10] = v[4];
    v[11] = v[4];
    v[12] = v[3];
    for (auto ic : v)
        cout << ic << " ";
    cout << "\n";
    l0(v);
    for (auto ic : v)
        cout << ic << " ";
    cout << "\n";
}

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
<Thesaurus>
<TermInfo><T>Power electronics</T><NT>Power integrated circuits</NT></TermInfo>
<TermInfo><T>Power integrated circuits</T><BT>Power electronics</BT><NT>Air traffic control</NT><UF>Integrated circuit supply</UF></TermInfo>
<TermInfo><T>Air traffic control</T><BT>Power integrated circuits</BT></TermInfo>
<TermInfo><T>Product safety engineering</T><NT>Consumer protection</NT></TermInfo>
<TermInfo><T>Consumer protection</T><BT>Product safety engineering</BT></TermInfo>
</Thesaurus>
This article has a lot of air traffic control information.  It also talks about integrated circuit supply.  If you want consumer protection you better have product safety engineering.  Don\x92t be a fool with power integrated circuits.
*/