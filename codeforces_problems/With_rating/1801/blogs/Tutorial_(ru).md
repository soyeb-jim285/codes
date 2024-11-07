# Tutorial_(ru)

[1802A - Likes](https://codeforces.com/contest/1802/problem/A "Codeforces Round 857 (Div. 2)")
-----------------------------------------------------------------------------------------------

Idea: [Aleks5d](https://codeforces.com/profile/Aleks5d "International Master Aleks5d"), Preparation: [vaaven](https://codeforces.com/profile/vaaven "Master vaaven")

 **Solution**Let's show a construction that maximizes the number of likes. We need to first leave all the likes that we can put, and only then delete them.

To minimize the number of likes, we need to delete the like (if we can) immediately after we post it.

The code below implements these constructs.

 **Code**
```cpp
#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n;
    cin >> n;
    int likes = 0, dislikes = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0) likes++;
        else dislikes++;
    }
    for (int i = 1; i <= n; ++i) {
        if (i <= likes) cout << i << ' ';
        else cout << likes * 2 - i << ' ';
    }
    cout << 'n';

    for (int i = 1; i <= n; ++i) {
        if (i <= dislikes * 2) cout << i % 2 << ' ';
        else cout << (i - dislikes * 2) << ' ';
    }
    cout << 'n';
}

signed main() {
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}

```
[1802B - Settlement of Guinea Pigs](https://codeforces.com/contest/1802/problem/B "Codeforces Round 857 (Div. 2)")
-------------------------------------------------------------------------------------------------------------------

Idea and preparation: [Aleks5d](https://codeforces.com/profile/Aleks5d "International Master Aleks5d")

 **Solution**Todo

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int known = 0, unknown = 0;
    int need = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 1) ++unknown;
        else {
            known += unknown;
            unknown = 0;
        }
        need = max(need, unknown + (known ? known / 2 + 1 : 0));
    }
    cout << need << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
```
[1801A - The Very Beautiful Blanket](../problems/A._The_Very_Beautiful_Blanket.md "Codeforces Round 857 (Div. 1)")
--------------------------------------------------------------------------------------------------------------------

Idea and preparation: [4qqqq](https://codeforces.com/profile/4qqqq "Expert 4qqqq")

 **Solution**The maximum number of different numbers we can type is always n⋅m. Let's show how you can build an example for any n and m.

Note that if we were able to construct a correct matrix, then any of its submatrix is also a correct matrix of a smaller size. Therefore, let's build a correct matrix for some N and M, and as an answer we will output the upper left corner of this matrix of the desired size.

Take N=M=28 and construct the matrix using the following algorithm. Let's break it into blocks of size 2×2. Let's number the blocks from left to right and from top to bottom in order, starting from zero. The $i$th block will have the form

4i+0 4i+1

4i+2 4i+3

With this construction, the bitwise exclusive OR any submatrix of size 2×2 will be zero. You can verify this as follows. Let's look at the upper left corner of (i,j) of an arbitrary submatrix of size 2×2. There are 4 cases:

 1. both coordinates are even;
2. i is even, j is odd;
3. i odd, j even;
4. both coordinates are odd.

Immediately note that i,j<200<28

Consider the most unpleasant case — the last one. The remaining cases are treated in a similar way. In this case, the submatrix will have the form:

4i+3 4(i+1)+2

4(i+28)+1 4(i+28+1)+0

Note that the second part of each term is less than 4, and the first part of each term is greater than or equal to 4. Therefore, they can be considered independently.

3⊕2⊕1⊕0 = 0.

If i=1, then

4i⊕4(i+1) = 12,

4(1+28)⊕4(2+28) = 12.

If i≠1, then

4i⊕4(i+1) = 4

4(i+28)⊕4(i+28+1)=4 (for i=0, you can check with your hands, for 1<i<28 4(i+28) will be reduced and 4 will remain from the second term).

4⊕4⊕0 = 0. Thus, in the selected submatrix, the bitwise exclusive OR is zero.

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int SZ = 256;

int v[SZ][SZ];

void Solve(){
    int n, m;
    cin >> n >> m;

    cout << n * m << 'n';

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cout << v[i][j] << " n"[j + 1 == m];
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    {
        int now = 0;
        int n = 256;
        int m = 256;

        for(int i = 0; i < n; i += 2)
            for(int j = 0; j < m; j += 2){
                v[i][j] = now;
                v[i][j + 1] = now + 1;
                v[i + 1][j] = now + 2;
                v[i + 1][j + 1] = now + 3;
                now += 4;
            }
    }

    int num_test = 1;
    cin >> num_test;

    for(int i = 1; i <= num_test; i++){
        Solve();
    }
}
```
[1801B - Buying gifts](../problems/B._Buying_gifts.md "Codeforces Round 857 (Div. 1)")
------------------------------------------------------------------------------------------------------

Idea: [Tikhon228](https://codeforces.com/profile/Tikhon228 "Master Tikhon228"), Preparation: [DishonoredRighteous](https://codeforces.com/profile/DishonoredRighteous "Grandmaster DishonoredRighteous")

 **Solution**To begin with, let's sort all departments in descending order bi (and if ~--- is equal, in ascending order ai). Now let's go through the i department, in which the most expensive gift for the second girlfriend will be bought. Note that in all departments with numbers j<i, Sasha must buy a gift for the first girlfriend, otherwise the gift i will not have the maximum value among the gifts bought for the second girlfriend. Therefore, we will immediately find the value of m=maxj<iaj. Thus, we can already get the answer |m−bi|.

In all departments with numbers j>i, for which aj≤m, Sasha can buy a gift for any of her friends, and this will not affect the answer in any way. Now consider all departments with numbers j>i for which aj>m. If you buy a gift for your first girlfriend in some of these departments, the value of m will increase, which means the answer may improve. Therefore, let's iterate through all these departments and update the response with the value |aj−bi|.

Time O(n2).

Let's optimize this solution. To begin with, instead of calculating the value of m anew at each iteration, we will maintain its value in some variable. Then, when moving from department i−1 to department i, we will update the value of m as follows: m:=max(m,ai).

It remains to learn how to quickly find the optimal department number j, such that j>i, aj>m, as well as |aj−bi| is minimal. Let's choose on the suffix of the array the minimum aj, such that aj≥bi, and also the maximum aj, such that aj≤bi. You can notice that the optimal aj is one of the two selected numbers (you also need to remember to check the condition aj>m). Therefore, it is enough to update the answer only with the help of them.

You can search for these two elements using the \texttt{set} data structure. We will support in the set all aj located on the suffix. Then you can find the necessary two elements for O(logn). When moving from department i−1 to department i, you need to remove the value ai−1 from the data structure.

Time O(nlogn)

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

template<typename T>
bool smin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool smax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const int INF = 0x3f3f3f3f;
const int N = 500100;

std::pair<int, int> a[N];

void run() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }

    sort(a, a + n, [&](const pair<int, int>& p1, 
                            const pair<int, int>& p2) {
        return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
    });

    multiset<int> setik;
    for (int i = 0; i < n; ++i) {
        setik.insert(a[i].first);
    }

    int mx = -INF;
    int ans = INF;
    
    for (int i = 1; i < n; ++i) {
        smin(ans, abs(a[i].first - a[0].second));
    }
    
    for (int i = 0; i < n; ++i) {
        setik.erase(setik.find(a[i].first));
        if (i == 0) {
            mx = a[i].first;
            continue;
        }

        smin(ans, abs(mx - a[i].second));
        auto it = setik.lower_bound(a[i].second);
        if (it != setik.end() && *it >= mx) {
            smin(ans, abs(*it - a[i].second));
        }
        if (it != setik.begin() && *std::prev(it) >= mx) {
            smin(ans, abs(*prev(it) - a[i].second));
        }

        smax(mx, a[i].first);
    }

    printf("%dn", ans);
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        run();
    }
    return 0;
}
```
[1801C - Music Festival](../problems/C._Music_Festival.md "Codeforces Round 857 (Div. 1)")
--------------------------------------------------------------------------------------------------------

Idea: [vaaven](https://codeforces.com/profile/vaaven "Master vaaven"), Preparation: [ViktorSM](https://codeforces.com/profile/ViktorSM "Expert ViktorSM")

 **Solution**Let's introduce the concept of a compressed album for an album, which is obtained from the original one by removing all elements except those that are the first maxima on their corresponding prefixes.

For example:

For the album [1,4,4,3,6,5,6] the album will be compressed [1,4,6].

Now we note that the solution of the original problem is reduced to solving the same problem, but on compressed albums. Indeed, the answer to them will not be different, because if some element increased the impression on ordinary albums, then it will increase if you compress albums and vice versa. Next, it will be assumed that all albums have been compressed beforehand.

Let's introduce dpc — the maximum impression that can be obtained if there were no albums such that they have elements larger than c. Then, dpc is equal to dpc−1, or you can add another element or two if c is the maximum element for some album. Then for all compressed albums, it can be recalculated through the value of dp at the point before the first element of the album, or through c−1. Thus, for recalculation, it is enough to know for each c which albums ended in this index, as well as for each album its first element. Solution for O(K)

Let's now solve the complete problem. For each value of c, let's remember the indexes of albums that contain an element equal to c. We go in order of increasing c, we maintain for each album the value of dpi — the maximum impression that can be obtained if there were no elements of large c and Masha listened to the last i album. Suppose for the next c there is an album i, that there is a song with the coolness of c in it. Then dpi should be taken as the maximum of dpi+1 and the values for all dpj+1, such that the maximum element in the jth album is less than the maximum element of ith, since she could listen to this track, either next in this album, or after listening to some other album completely. Note that you can store the value of mx — maximum for all albums for which the maximum value in them is less than c and recalculate it when moving to c+1, storing those albums that have ended, then you will get a solution for O(K+C).

 **Code**
```cpp
#include "bits/stdc++.h"
#include <algorithm>
#include <locale>
#include <random>
#include <unordered_map>
#include <vector>

using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
typedef long long ll;
typedef long double db;
typedef unsigned long long ull;

vector<int> shrink(vector<int> &a) {
  vector<int> a1;
  int n = a.size();
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > mx) {
      a1.emplace_back(a[i]);
      mx = a[i];
    }
  }
  return a1;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  int k;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    a[i].resize(k);
    for (auto &j : a[i]) {
      cin >> j;
    }
  }
  vector<vector<int>> a1(n);
  for (int i = 0; i < n; ++i) {
    a1[i] = shrink(a[i]);
  }
  map<int, vector<int>> b;
  for (int i = 0; i < n; ++i) {
    for (auto &j : a1[i]) {
      b[j].emplace_back(i);
    }
  }
  vector<int> dp(n);
  int closed = 0;
  for (auto &it : b) {
    int c = it.first;
    int newclosed = 0;
    for (auto &i : it.second) {
      if (c == a1[i].back()) {
        dp[i] = max(dp[i] + 1, closed + 1);
        newclosed = max(newclosed, dp[i]);
        continue;
      }
      if (c == a1[i].front()) {
        dp[i] = closed + 1;
        continue;
      }
      dp[i] = max(dp[i] + 1, closed + 1);
    }
    closed = max(closed, newclosed);
  }
  cout << *max_element(all(dp));
}

signed main() {
  int t = 0;
  cin >> t;
  while (t --> 0) {
      solve();
      cout << 'n';
  }
  return 0;
}
```
[1801D - The way home](../problems/D._The_way_home.md "Codeforces Round 857 (Div. 1)")
------------------------------------------------------------------------------------------------------

Idea: [Tikhon228](https://codeforces.com/profile/Tikhon228 "Master Tikhon228"), Preparation: [Ormlis](https://codeforces.com/profile/Ormlis "Legendary Grandmaster Ormlis")

 **Solution**Note that the show can be done "postponed". As soon as we don't have enough money to walk along the edge, we can do several shows in advance among the peaks that we have already passed, so as to earn the maximum amount of money.

For the general case, you can write dp[v][best]=(min show,max money), where v is the number of the vertex where we are, and best is the vertex with max. wi, which we have already passed through. It can be shown that it is optimal to minimize the number of shows first, and then maximize the amount of money. This dynamics can be recalculated using Dijkstra's algorithm. Asymptotics of O(mnlogn)

 **Code**
```cpp
#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define ar array
#define vec vector

using namespace std;

using ll = long long;
using pi = pair<int, int>;

using vi = vector<int>;
using vpi = vector<pair<int, int>>;

const ll INF = 2e18;
const int maxN = 3e5 + 10;

struct PathParams {
    ll num_show;
    int money;
};

bool operator==(const PathParams &a, const PathParams &b) {
    return tie(a.num_show, a.money) == tie(b.num_show, b.money);
}

bool operator!=(const PathParams &a, const PathParams &b) {
    return !(a == b);
}

struct State {
    PathParams params;
    int v;
    int best;
};

bool operator<(const PathParams &a, const PathParams &b) {
    if (a.num_show != b.num_show) return a.num_show < b.num_show;
    return a.money > b.money;
}

bool operator<(const State &a, const State &b) {
    return tie(a.params, a.v, a.best) < tie(b.params, b.v, b.best);
}

bool operator>(const State &a, const State &b) {
    return !(a < b);
}

void solve() {
    int n, m, p, group;
    cin >> n >> m >> p;
    vector dp(n, vector<PathParams>(n, {INF, 0}));
    vector<vpi> g(n);
    vi w(n);
    rep(i, n) cin >> w[i];
    rep(i, m) {
        int a, b, s;
        cin >> a >> b >> s;
        a--;
        b--;
        g[a].emplace_back(b, s);
    }
    dp[0][0] = {0, p};
    priority_queue<State, vector<State>, greater<>> pq;
    pq.push({.params = {.num_show=0, .money=p}, .v = 0, .best=0});
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        int v = current.v;
        int best = current.best;
        if (dp[v][best] != current.params) continue;
        for (auto &[u, s]: g[v]) {
            auto state2 = current;
            PathParams &path = state2.params;
            if (path.money < s) {
                ll need = (s - path.money + w[best] - 1) / w[best];
                path.num_show += need;
                path.money += need * w[best];
                assert(path.money < s + w[best]);
            }
            path.money -= s;
            state2.v = u;
            if (w[u] > w[state2.best]) state2.best = u;
            if (path < dp[u][state2.best]) {
                dp[u][state2.best] = path;
                pq.push(state2);
            }
        }
    }
    ll ans = INF;
    rep(i, n) {
        ans = min(ans, dp[n - 1][i].num_show);
    }
    cout << (ans == INF ? -1 : ans) << 'n';
}

signed main() {
    int t = 1;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}
```
[1801E - Gasoline prices](../problems/E._Gasoline_prices.md "Codeforces Round 857 (Div. 1)")
---------------------------------------------------------------------------------------------------------

Idea and preparation: [Kirill22](https://codeforces.com/profile/Kirill22 "International Grandmaster Kirill22")

 **Solution**To begin with, let's understand what is required of us. A tree is given, in each vertex of which the price range for this vertex is recorded. A query is a pair of paths of equal length, the prices at the i-th vertices along these paths should be equal for all i. We need to find the number of ways to place prices at the vertices for each prefix of restrictions

Let's start with a slow solution of the problem. We will store the connectivity components (in each vertex prices should be equal). For each of them, we store an acceptable price range. The answer will be the product of the lengths of the ranges over all components. We will go along the paths and combine 2 vertices into one component using DSU. It is clear that to speed up this solution, it is necessary to search faster for the moments when two vertices are combined into one component.

First, let's analyze the long solution. Let's make a heavy-light decomposition, with which we will hash the paths in the tree, taking the root number of its components as a symbol for the vertex. Now, with the help of bin search, we will look for the first moment when the hashes on the path prefixes differ, that is, two vertices are combined into one component. With the help of transfusions, we will update the roots of their components for vertices and the tree of segments for hld. We will get n unions, we will find each one for O(log2(n)) using hld. There will also be O(n⋅log(n)) updates in the segment tree due to overflows. For each request there will be O(log2(n)) from hld. The final asymptotic O((n+q)⋅log2(n))

Now let's give a beautiful solution to this problem. Let's start with bamboo.

Replace the equality of prices on a pair of paths with two pairs of paths with lengths equal to the maximum power of two, less than the length of the original path (as in sparse table). Now the path lengths of all constraints have become powers of two. We will iterate over the powers of two in descending order 2k, for each path of length 2k we will get a vertex in the graph, we will also get a vertex for each such path in reverse order. Now the constraints define edges in such a graph. Let's spend them, select the spanning tree. For each edge from the backbone, we divide the constraints into 2 constraints with path lengths half as long and continue the process. On a layer with lengths 1, we will get the spanning tree we need, which will be responsible for the first moments when some pairs of vertices were combined into components. Note that no more than 2n edges will be added down from each layer, as well as no more than 2q edges from queries. That is, each layer will work for O((n+q)⋅α(n)), where α(n) is the average operating time in DSU, the inverse of the Ackerman function. We got the solution in O((n+q)⋅α(n)⋅log(n))

For a complete solution on the tree, first we divide a pair of paths into three pairs of corresponding vertical paths (take from the 4 end vertices of these paths the pair of vertices closest to the lca on its path, then we pair this path with a vertical path (part of another path), now we get one vertical path and an arbitrary path in the tree, let's split the second path by lca and the first by the corresponding lengths). Next, we will proceed similarly to bamboo, only the place of the vertex responsible for the segment, we will get the vertex responsible for the binary ascent in the tree to a height equal to the power of two.

 **Code**
```cpp
#include "bits/stdc++.h"

using namespace std;

const int mod = (int) 1e9 + 7;

int inv(int x) {
    int res = 1, n = mod - 2;
    while (n) {
        if (n & 1) {
            res = res * 1ll * x % mod;
        }
        x = x * 1ll * x % mod;
        n /= 2;
    }
    return res;
}

const int N = (int) 2e5 + 22, K = 18;
vector<int> g[N];
pair<int, int> a[N];
int n, q, ans = 1;
int h[N], up[N][K], lg[N];
vector<array<int, 3>> graph[K]; // lower vertex1, lower vertex2, time, vertex with direction
vector<array<int, 3>> gr[N];
vector<array<int, 3>> edges;

struct dsu {
    vector<int> p, sz;

    void build(int n) {
        p.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int get(int v) {
        return (v == p[v] ? v : p[v] = get(p[v]));
    }

    bool merge(int v, int u) {
        v = get(v), u = get(u);
        if (v != u) {
            if (sz[v] > sz[u]) {
                swap(v, u);
            }
            p[v] = u;
            sz[u] += sz[v];
            return true;
        }
        return false;
    }
} G, dsu[K];

void dfs(int v, int pr, int d) {
    h[v] = d;
    up[v][0] = pr;
    for (int j = 1; j < K; j++) {
        up[v][j] = up[up[v][j - 1]][j - 1];
    }
    for (auto u : g[v]) {
        dfs(u, v, d + 1);
    }
}

int la(int v, int x) {
    for (int j = 0; j < K; j++) {
        if (x >> j & 1) {
            v = up[v][j];
        }
    }
    return v;
}

int lca(int v, int u) {
    if (h[v] > h[u]) {
        swap(v, u);
    }
    u = la(u, h[u] - h[v]);
    if (v == u) {
        return v;
    }
    for (int j = K - 1; j >= 0; j--) {
        if (up[v][j] != up[u][j]) {
            v = up[v][j], u = up[u][j];
        }
    }
    return up[v][0];
}

int id(int v) {
    return (v > 0 ? v : -v + n);
}

int sgn(int v) {
    return (v > 0 ? 1 : -1);
}

void add_edge(int j, int v, int u, int t) {
    if (dsu[j].merge(id(v), id(u))) {
        if (j > 0) {
            if (sgn(v) == sgn(u)) {
                add_edge(j - 1, v, u, t);
                add_edge(j - 1, sgn(v) * up[abs(v)][j - 1], sgn(u) * up[abs(u)][j - 1], t);
            } else {
                if (sgn(v) == -1) {
                    swap(v, u);
                }
                add_edge(j - 1, v, sgn(u) * up[abs(u)][j - 1], t);
                add_edge(j - 1, sgn(v) * up[abs(v)][j - 1], u, t);
            }
        } else {
            edges.push_back({abs(v), abs(u), t});
        }
    }
}

void add(int v, int u, int x, int y, int t, int type1, int type2) {
    if (h[v] < h[u]) {
        swap(v, u);
    }
    if (h[x] < h[y]) {
        swap(x, y);
    }
    assert(h[v] - h[u] == h[x] - h[y]);
    int g = lg[h[v] - h[u]];
    if (type1 == type2) {
        add_edge(g, type1 * v, type2 * x, t);
        add_edge(g, type1 * la(v, h[v] - h[u] - (1 << g) + 1), type2 * la(x, h[x] - h[y] - (1 << g) + 1), t);
    } else {
        add_edge(g, type1 * v, type2 * la(x, h[x] - h[y] - (1 << g) + 1), t);
        add_edge(g, type1 * la(v, h[v] - h[u] - (1 << g) + 1), type2 * x, t);
    }
}

void merge(int v, int u) {
    v = G.get(v), u = G.get(u);
    if (v != u) {
        G.merge(v, u);
        if (G.sz[v] > G.sz[u]) {
            swap(v, u);
        }
        if (a[v].first <= a[v].second) {
            ans = ans * 1ll * inv(a[v].second - a[v].first + 1) % mod;
        }
        if (a[u].first <= a[u].second) {
            ans = ans * 1ll * inv(a[u].second - a[u].first + 1) % mod;
        }
        a[u].first = max(a[u].first, a[v].first);
        a[u].second = min(a[u].second, a[v].second);
        if (a[u].first > a[u].second) {
            ans = 0;
        } else {
            ans = ans * 1ll * (a[u].second - a[u].first + 1) % mod;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int j = 2; j < N; j++) {
        lg[j] = lg[j / 2] + 1;
    }
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int v;
        cin >> v;
        g[v].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        ans = ans * 1ll * (a[i].second - a[i].first + 1) % mod;
    }
    dfs(1, 1, 0);
    cin >> q;
    for (int j = 0; j < K; j++) {
        dsu[j].build(2 * n + 1);
    }
    for (int i = 0; i < q; i++) {
        int v, u, x, y;
        cin >> v >> u >> x >> y;
        int w = lca(v, u);
        int z = lca(x, y);
        if (h[v] - h[w] > h[x] - h[z]) {
            swap(v, x);
            swap(u, y);
            swap(w, z);
        }
        if (v != w) {
            int d = h[v] - h[w];
            int v2 = la(v, d - 1);
            int x2 = la(x, d - 1);
            add(v, v2, x, x2, i, 1, 1);
            v = up[v2][0];
            x = up[x2][0];
        }
        if (x != z) {
            int d = h[x] - h[z];
            int v2 = la(u, (h[u] - h[v]) - d);
            int x2 = la(x, d - 1);
            add(v, up[v2][0], x, x2, i, -1, 1);
            v = v2;
            x = up[x2][0];
        }
        add(v, u, x, y, i, (h[v] > h[u] ? 1 : -1), (h[x] > h[y] ? 1 : -1));
    }
    G.build(n + 1);
    int j = 0;
    for (int i = 0; i < q; i++) {
        while (j < (int) edges.size() && edges[j][2] == i) {
            merge(edges[j][0], edges[j][1]);
            j++;
        }
        cout << ans << 'n';
    }
}
```
[1801F - Another n-dimensional chocolate bar](../problems/F._Another_n-dimensional_chocolate_bar.md "Codeforces Round 857 (Div. 1)")
------------------------------------------------------------------------------------------------------------------------------

Idea and preparation: [Tikhon228](https://codeforces.com/profile/Tikhon228 "Master Tikhon228")

 **Solution**For A we denote the maximum value of ai

To begin with, let's solve the problem for O(n⋅k⋅f(k,A)) using dynamic programming.

Let's put dp[i][j]— the maximum possible volume of the smallest piece, if by the first i measurements we divided the chocolate into j parts. If we have divided into more than k parts, we will also put the result in dp[i][k]. In terms of calculation, we need to decide how many hours to divide the chocolate bar along the next dimension. Let's look at several ways to do this.

 * It is possible for O(k) to sort out the state to which we are moving, and from this calculate how many parts you need to divide the chocolate bar along the next dimension. — We get O(n⋅k2)
* It is possible for O(A) to sort out how many parts we divide the chocolate bar along the next dimension.
* Being in the state of dp[i][j], you can iterate over bi — into how many parts to divide the chocolate until j⋅bi≤k. It can be shown that such a solution will work for O(n⋅k⋅lnk)

The key idea

 * suppose we need to divide a chocolate bar into 10 parts, and along the first measurements we have already divided it into 5 parts, or 6 parts, or 7,8 or 9 parts. All these states are not distinguishable for us, because in all these cases we need to divide the chocolate bar into at least 2 parts. It remains to understand how many such <> states there are and learn how to store them. There are several approaches for this, let's analyze one of them:
* we are interested in all the values of ⌈ki⌉ for i=1,2,…k— this is how many parts the chocolate bar may still need to be divided into. Among them, only O(√k)different, since either i≤√k, or the value of ⌈ki⌉≤√k itself. If we make all these numbers states, and recalculate, iterating over the state to which to go, we get O(n⋅√k⋅√k)=O(n⋅k)— this is still not enough to solve the hollow problem.

Last observation

If we are in the state of dp[i][remain] where remain=⌈ki⌉ for some i, we will apply the same idea to it. From it, we are interested in transitions to the states ⌈remainj⌉ for j=1,2,…remain. What kind of asymptotics will be obtained if we iterate over only interesting transitions?

n⋅(√k∑r=12⋅√r+2⋅√⌈kr⌉)

 * it can be shown that this is O(n⋅k3/4)— which solves the problem
 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;
int a[MAXN];

const int MAXK = 1e7 + 100, MAXH = 1e4;
int hsh[MAXK];
int rev[MAXH];

double dp[MAXN][MAXH];

vector<array<int, 2>> go[MAXH];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int id = 0;
    for (int c = 1;; ++id) {
        rev[id] = (k + c - 1) / c;
        hsh[(k + c - 1) / c] = id;
        int t = (k + c - 1) / c - 1;
        if (t == 0) break;
        c = (k + t - 1) / t;
    }
    ++id;
    dp[0][hsh[k]] = k;

    for (int i = 0; i < id; ++i) {
        int k = rev[i];
        for (int c = 1;;) {
            go[i].push_back({c, hsh[(k + c - 1) / c]});
            int t = (k + c - 1) / c - 1;
            if (t == 0) break;
            c = (k + t - 1) / t;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < id; ++j) {
            double val = dp[i][j];
            if (val == 0) continue;
            for (auto elem : go[j]) {
                int c = elem[0], k1 = elem[1];
                if (c > a[i]) break;
                int cur = a[i] / c;
                dp[i + 1][k1] = max(dp[i + 1][k1], val * cur / a[i]);
            }
        }
    }
    cout << fixed << setprecision(20);
    cout << dp[n][hsh[1]] << 'n';
    return 0;
}

```
[1801G - A task for substrings](../problems/G._A_task_for_substrings.md "Codeforces Round 857 (Div. 1)")
---------------------------------------------------------------------------------------------------------------

Idea and preparation: [grphil](https://codeforces.com/profile/grphil "Master grphil")

 **Solution**Let's use the Aho-Korasik structure to store strings from S. Let's build compressed suffix links on it. This way it is a little more optimal to find all the lines from S ending in this position t.

Denote by pref[i] the number of substrings of S in the prefix t of length i.

Denote by suf[i] the number of substrings of S in the suffix t starting from the position i.

Note that pref[r]+suf[l]−priv[|T|] is equal to the number of substrings of the string for t from S on the segment [l,p] minus the number of substrings of t from S that begin before l and end later than r.

For each query, we will find a substring t that matches si, which covers the string t[l,r] and ends as close as possible to r. If there is no such thing, then the answer can be calculated using the previous formula. Otherwise, t[l,r] is invested in si[l′,r′]. At the same time, there are no substrings of S in the string si that begin before l′ and end later than r′. To get the answer, we apply the previous formula with the string si and the sub-section [l′,r′].

Asymptotics: O(S+t+mlogm)

 **Code**
```cpp
#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

struct node {
	int nx[26];
	int p;
	int pp;
	int len;
	int id;
	int cnt;
	bool term;

	node() : p(-1), pp(-1), len(0), id(-1), term(false), cnt(0) {
		for (int i = 0; i < 26; i++) {
			nx[i] = -1;
		}
	}
};

vector<node> g;

vector<string> s[2];

string t[2];

vector<vector<long long>> c[2], pid[2];

vector<long long> tc[2];

int add(int a, char c) {
	c -= 'a';
	if (g[a].nx[c] == -1) {
		g[a].nx[c] = g.size();
		g.emplace_back();
		g.back().len = g[a].len + 1;
	}
	return g[a].nx[c];
}

void build_aho(int a) {
	vector<pair<int, int>> q;
	for (int i = 0; i < 26; i++) {
		if (g[a].nx[i] == -1) {
			g[a].nx[i] = a;
		} else {
			q.emplace_back(a, i);
		}
	}

	int qb = 0;
	while (qb < q.size()) {
		int b = q[qb].x;
		int i = q[qb].y;
		qb++;
		int v = g[b].nx[i];
		int c = g[b].p;

		if (g[v].term) { // bug in c != -1
			g[v].cnt = 1;
		}

		if (c == -1) {
			g[v].p = a;
			g[b].pp = -1;
		} else {
			g[v].p = g[c].nx[i];
			if (g[v].term) {
				g[v].pp = v;
			} else {
				g[v].pp = g[g[v].p].pp;
			}
			g[v].cnt += g[g[v].p].cnt;
		}

		for (int i = 0; i < 26; i++) {
			if (g[v].nx[i] == -1) {
				g[v].nx[i] = g[g[v].p].nx[i];
			} else {
				q.emplace_back(v, i);
			}
		}
	}
}

vector<vector<pair<int, int>>> ts;
vector<int> qlen;
priority_queue<pair<int, int>> h;
vector<long long> ans;

long long get_ans(int rdst, int len, vector<long long>& a, vector<long long>& b, bool substr) {
	int l = a.size() - 1 - rdst;
	int r = l + len;
	long long cnt = a[r] + b[a.size() - 1 - l] - a.back();
	if (substr && l == 0 && r == a.size() - 1) {
		cnt++;
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	g.emplace_back(); g.emplace_back();
	s[0].resize(n); s[1].resize(n);
	c[0].resize(n); c[1].resize(n);
	pid[0].resize(n); pid[1].resize(n);
	ans.resize(m);

	cin >> t[0];
	t[1] = t[0];
	reverse(t[1].begin(), t[1].end());
	ts.resize(t[0].size());

	for (int i = 0; i < n; i++) {
		cin >> s[0][i];
	}
	sort(s[0].begin(), s[0].end(),  
	[](const string& a, const string& b) { return a.size() < b.size(); });

	for (int i = 0; i < n; i++) {
		s[1][i] = s[0][i];
		reverse(s[1][i].begin(), s[1][i].end());

		for (int e = 0; e < 2; e++) {
			int a = e;
			for (auto j : s[e][i]) {
				a = add(a, j);
			}
			g[a].term = true;
			g[a].id = i;
		}
	}

	build_aho(0); build_aho(1);

	for (int e = 0; e < 2; e++) {
		tc[e].resize(t[0].size() + 1);

		int a = e;
		for (int i = 0; i < t[0].size(); i++) {
			a = g[a].nx[t[e][i] - 'a'];
			tc[e][i + 1] = tc[e][i] + g[a].cnt;
		}
		for (int i = 0; i < n; i++) {;
			c[e][i].resize(s[0][i].size() + 1);
			pid[e][i].resize(s[0][i].size() + 1, -1);

			int a = e;
			for (int j = 0; j < s[e][i].size(); j++) {
				a = g[a].nx[s[e][i][j] - 'a'];
				c[e][i][j + 1] = c[e][i][j] + g[a].cnt;
				
				if (g[a].term) { // bug always
					pid[e][i][j + 1] = g[a].id;
				}
			}

			for (int j = (int)s[e][i].size() - 1; j >= 0; j--) { // bug forget
				if (pid[e][i][j] == -1) {
					pid[e][i][j] = pid[e][i][j + 1];
				}
			}
			c[e][i].back()--; // bug forget string itself
			
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		ts[b - 1].emplace_back(a, i);
		qlen.emplace_back(b - a);
	}

	int a = 0;
	for (int i = 0; i < t[0].size(); i++) {
		// cout << i << ' ' << t[0][i] << 'n';
		for (auto j : ts[i]) {
			h.emplace(j);
		}

		a = g[a].nx[t[0][i] - 'a'];

		if (g[a].pp != -1) { // bug ignore
			int id = g[g[a].pp].id;
			int bg = i + 1 - (int)s[0][id].size();
			while (h.size() > 0 && h.top().x >= bg) {
				int rdst = i - h.top().x + 1;
				int nid = pid[1][id][rdst]; // bug forget

				// cout << h.top().x << ' ' << h.top().y << ' ' << rdst << ' ' << nid << 'n';

				ans[h.top().y] = get_ans(rdst, qlen[h.top().y], 
				    c[0][nid], c[1][nid], true);
				h.pop();
			}
		}
	}

	while (h.size() > 0) {
		// cout << h.top().x << ' ' << h.top().y << 'n';
		ans[h.top().y] = get_ans(t[0].size() - h.top().x, qlen[h.top().y], tc[0], tc[1], false);
		h.pop();
	}

	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << 'n';
}
```
