#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
vector<int> parent, rnk;

void make_set(int v)
{
    parent[v] = v;
    rnk[v] = 0;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<Edge> edges;
    map<string, int> mp;
    ll ct = 1;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        ll val;
        cin >> s1 >> s2 >> val;
        if (!mp[s1])
        {
            mp[s1] = ct;
            ct++;
        }
        if (!mp[s2])
        {
            mp[s2] = ct;
            ct++;
        }
        Edge p;
        p.u = mp[s1];
        p.v = mp[s2];
        p.weight = val;
        edges.push_back(p);
    }
    
    int cost = 0;
    vector<Edge> result;
    parent.resize(n);
    rnk.resize(n);
    for (int i = 0; i < n; i++)
        make_set(i);
    sort(edges.begin(), edges.end());
    for (Edge e : edges)
    {
        if (find_set(e.u) != find_set(e.v))
        {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
    for(Edge a: result)
    cout << a.u << " " << a.v << " " << "\n";
    cout << cost << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}