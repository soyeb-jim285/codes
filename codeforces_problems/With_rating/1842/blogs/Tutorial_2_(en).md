# Tutorial_2_(en)


### [1842A - Tenzing and Tsondu](../problems/A._Tenzing_and_Tsondu.md)

 **Tutorial**Let's view it as when monsters x and y fight, their health changes into max(x−y,0) and max(y−x,0) respectively. So any monster with 0 health is considered dead. Therefore, a player loses when the health of his monsters are all 0.

Notice that max(x−y,0)=x−min(x,y) and max(y−x,0)=y−min(x,y). Therefore, after each step, the sum of the health of monsters decrease by the same amount for both players.

Therefore, we only need to know ∑ai and ∑bi to determine who wins. If ∑ai>∑bi, Tsondu wins. Else if ∑ai<∑bi, Tenzing wins. Else, it is a draw.

 **Code**
```cpp
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, a[50], b[50];
        long long sumA = 0, sumB = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i], sumA += a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i], sumB += b[i];
        if (sumA > sumB) cout << "Tsondun";
        if (sumA < sumB) cout << "Tenzingn";
        if (sumA == sumB) cout << "Drawn";
    }
}
```
### [1842B - Tenzing and Books](../problems/B._Tenzing_and_Books.md)

 **Tutorial**Observe the bitwise OR: if a bit of the *knowledge* changes to 1, it will never become 0.

It tells us, if a book has difficulty rating y, and x|y≠x, Tenzing will never read this book because it will change a 0 bit in x to 1.

We called a number y valid if x|y=x. For each sequence, we can find a longest prefix of it such that all numbers in this prefix are valid. Find the bitwise OR of the three prefix and check whether it equals to x.

Time complexity: O(n) per test case.

 **Alternative Solution**A naive approach is to enumerate the prefixes of the three stacks, which is an enumeration of n3. For each stack, the bitwise OR of the prefix has at most 31 different values (including empty prefix), because the bitwise OR of the prefix is non-decreasing, and each change will increase the number of 1s in binary. Since the number of 1s in binary cannot exceed 30, it can be changed at most 30 times. Therefore, the enumeration is reduced to min(n,31)3. In the worst case, the time complexity is O(∑n∗312).

 **Code**
```cpp
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x, a[100000];
        cin >> n >> x;
        int s = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) cin >> a[j];
            for (int j = 0; j < n; j++) {
                if ((x | a[j]) != x) break;
                s |= a[j];
            }
        }
        if (s == x) cout << "YESn";
        else cout << "NOn";
    }
}
```
 **Alternative Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x, ai;
        cin >> n >> x;
        vector<int> pre[3];
        for (int i = 0; i < 3; i++) {
            int s = 0;
            pre[i].push_back(s);
            for (int j = 0; j < n; j++) {
                cin >> ai;
                if ((s | ai) != s)
                    s |= ai, pre[i].push_back(s);
            }
        }
        bool ans = 0;
        for (int A : pre[0]) for (int B : pre[1]) for (int C : pre[2])
            ans |= (A | B | C) == x;
        cout << (ans ? "YESn" : "NOn");
    }
}
```
### [1842C - Tenzing and Balls](../problems/C._Tenzing_and_Balls.md)

 **Tutorial**Let us write down the original index of each range we delete.

Firstly, it is impossible to delete ranges (a,c) and (b,d) where a<b<c<d.

Secondly, if we delete ranges (a,d) and (b,c) where a<b<c<d, we must have deleted range (b,c) before deleting range (a,d). Yet, the effect of deleting range (b,c) and then (a,d) is the same as only deleting (a,d).

Therefore, we can assume that in an optimal solution, the ranges we delete are all disjoint. Therefore, we want to find some disjoint range [l1,r1],[l2,r2],...,[lm,rm] such that ali=ari and ∑(ri−li+1) is maximized.

We can write a DP. dpi denotes the minimum number of points we do not delete when considering the subarray a[1…i]. We have dpi=min(dpi−1+1,min{dpj|aj+1=ai,j+1<i}).

This dp can be calculated in O(n) since we can store for each x what the minimum dpj which satisfy aj+1=x.

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        const int N = 200000 + 5;
        int n, a[N], dp[N], buc[N];
        cin >> n;
        dp[0] = 0;
        for (int i = 1; i <= n; i++) buc[i] = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            dp[i] = min(dp[i - 1] + 1, buc[a[i]]);
            buc[a[i]] = min(buc[a[i]], dp[i - 1]);
        }
        cout << n - dp[n] << 'n';
    }
}
```
### [1842D - Tenzing and His Animal Friends](../problems/D._Tenzing_and_His_Animal_Friends_.md)

 **Tutorial**Consider the restrictions on u, v, and y as a weighted edge between u and v with weight y. Obviously, the final answer will not exceed the shortest path from 1 to n.

One possible approach to construct the solution is to start with the set 1 and add vertices one by one. If i is added to the set at time Ti, then we need to ensure that |Tu−Tv|≤y for any edge between u and v in the set. This can be modeled as a system of difference constraints problem and solved using shortest path algorithms.

To be more specific, we can add vertices in increasing order of their distances from 1. The time for each set can be calculated as the difference between the distances from 1 to the two adjacent vertices in the sorted order.

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n, m;
long long dis[100][100];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    memset(dis, 0x3f, sizeof dis);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        dis[u][v] = dis[v][u] = w;
    }
    for (int i = 0; i < n; i++) dis[i][i] = 0;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    if (dis[0][n - 1] > 1e18)
        cout << "inf", exit(0);
    int ord[100];
    iota(ord, ord + n, 0);
    sort(ord + 1, ord + n, [](int a, int b) {
        return dis[0][a] < dis[0][b];
    });
    string s(n, '0');
    vector<pair<string, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        int u = ord[i], v = ord[i + 1];
        s[u] = '1';
        ans.emplace_back(s, dis[0][v] - dis[0][u]);
        if (v == n - 1) break;
    }
    cout << dis[0][n - 1] << ' ' << ans.size() << 'n';
    for (auto [s, t] : ans)
        cout << s << ' ' << t << 'n';
}
```
### [1842E - Tenzing and Triangle](../problems/E._Tenzing_and_Triangle.md)

 **Tutorial**Observe that all triangles will be disjoint, if two triangle were not disjoint, we can merge them together to such that the cost used is less. Therefore, we can consider doing DP.

The oblique side of the triangle is a segment on the line y=k−x. Therefore, we use the interval [L,R] to represent the triangle with the upper left corner at (L,k−L) and the lower right corner at (R,k−R).

First, suppose that all points will generate costs. After covering points with a triangle, the costs can be reduced. Let f(L,R) represent the sum of costs of points covered by triangle [L,R] minus A×(R−L). We need to find several intervals [l1,r1],[l2,r2],⋯,[lm,rm] without common parts and maximize ∑f(li,ri).

Let dpi represent the maximum value of ∑f(li,ri) when considering the prefix [1,i]. There are two transitions:

 * If i is not covered by any interval, then dpi←dpi−1.
* If i is covered by interval [j+1,i], then dpi←dpj+f(j+1,i).

Enumerate from small to large for i, maintain gj=dpj+f(j+1,i). When i−1→i, g will change as follows:

 * Subtract A from g0…i−1.
* For each point (x,k−i), add the cost of the point to g0…x.

g needs to support interval addition and global maximum value (assuming that illegal positions are 0), which can be achieved using a segment tree.

Time complexity is O((n+k)logk).

 **Alternative Solution**Please first understand the approach in the tutorial. A triangle [L,R] can cover a point (x,y) iff L≤x and k−y≤R. Therefore, point (x,y) can be regarded as interval [x,k−y]. Now the problem is transformed into one where some intervals [l,r] have a cost of w, and you can place some non-overlapping intervals. If [l,r] is not included in any placed interval, then you need to pay a cost of w. Further transformation: you can pay a cost of A to cover [i,i+1], and for an interval [l,r] with a cost of w, if interval [l,r] is not completely covered, then you need to pay a cost of w. Try to use minimum cut to solve this problem:

 * First establish a bipartite graph with n left nodes representing the points in the original problem and k right nodes representing intervals [i,i+1].
* The source node is connected to each left node with an edge capacity equal to the node's cost.
* Each right node is connected to the sink node with an edge capacity of A.
* For each left node representing interval [l,r], it is connected to right nodes l,l+1,l+2,...,r−1 with an edge capacity of infinity.

According to the maximum flow minimum cut theorem, let's consider how to find the maximum flow of this graph.

This is basically a maximum matching problem of a bipartite graph. Each left node can match an interval on the right side, and each node has matching frequency restriction. A greedy algorithm: First sort all intervals in increasing order of the right endpoint, then consider each interval in turn and match it with positions within the interval from left to right. Specifically, let cnti represent how many times the i-th point on the right side can still be matched. Initially, cnt0…k−1=A. For each interval [l,r] that can be matched at most w times, each time find the smallest i in [l,r−1] such that cnti≠0, and match min(cnti,w) times with i.

Use a Disjoint Set Union to query the smallest i≥l such that cnti≠0. The time complexity is O(nα(n)).

The Method of Four Russians can also be used to achieve O(n) time complexity. Divide the sequence into blocks of 64, use bit operations and `__builtin_ctzll` for searching within the block, and use Disjoint Set Union to skip blocks where cnti is all 0. In this way, the union operation only needs O(nlogn) times and the find operation only needs O(n) times. It can be proved that in this case, the time complexity of Disjoint Set Union is O(n) instead of O(nα(n)).

 **Code**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 8, M = 1 << 18;
 
int n, k, A, c[M << 1][2], dp[N];
vector<pair<int, int>> p[N];
 
void insert(int i, int v) {
    for (i += M; i; i >>= 1) c[i][0] = v, v = max(v, c[i ^ 1][0]);
}
void add(int i, int v) {
    for (i += M + 1; i > 1; i >>= 1) {
        int v1 = i & 1 ? v : 0;
        c[i ^ 1][0] += v1, c[i ^ 1][1] += v1;
        c[i >> 1][0] = max(c[i][0], c[i ^ 1][0]) + c[i >> 1][1];
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> k >> A;
    int sum = 0;
    while (n--) {
        int x, y, w;
        cin >> x >> y >> w;
        p[k - y].emplace_back(x, w);
        sum += w;
    }
    for (int i = 1; i <= k; i++) {
        add(i - 1, -A);
        for (auto [x, w] : p[i]) add(x, w);
        dp[i] = max(dp[i - 1], c[1][0]);
        insert(i, dp[i]);
    }
    cout << sum - dp[k] << 'n';
}
```
 **Alternative Code O(n alpha n)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 8;

int n, k, A, cnt[N], pa[N];
vector<pair<int, int>> v[N];

int find(int x) {
    return !pa[x] ? x : pa[x] = find(pa[x]);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> k >> A;
    while (n--) {
        int x, y, w;
        cin >> x >> y >> w;
        v[k - y].emplace_back(x, w);
    }
    for (int i = 0; i < k; i++) cnt[i] = A;
    int ans = 0;
    for (int r = 1; r <= k; r++)
        for (auto [l, w] : v[r])
            while (l < r) {
                int tmp = min(w, cnt[l]);
                ans += tmp, cnt[l] -= tmp, w -= tmp; 
                if (!cnt[l]) l = pa[l] = find(l + 1);
                if (!w) break;
            }
    cout << ans << 'n';
}
```
 **Alternative Code O(n)**
```cpp
#include <bits/stdc++.h>

struct IO {
    static const int inSZ = 1 << 17;
    char inBuf[inSZ], *in1, *in2;
    inline __attribute((always_inline))
    int read() {
        if(__builtin_expect(in1 > inBuf + inSZ - 32, 0)) {
            auto len = in2 - in1;
            memcpy(inBuf, in1, len);
            in1 = inBuf, in2 = inBuf + len;
            in2 += fread(in2, 1, inSZ - len, stdin);
            if(in2 != inBuf + inSZ) *in2 = 0;
        }
        int res = 0;
        unsigned char c = *in1++;
        while(res = res * 10 + (c - 48), (c = *in1++) >= 48);
        return res;
    }
    IO() {
        in1 = inBuf;
        in2 = in1 + fread(in1, 1, inSZ, stdin);
    }
} IO;
inline int read() { return IO.read(); }

using namespace std;

const int N = 2e5 + 8, N2 = N / 64 + 8;

int n, k, A, pts[N][3], buc[N], LW[N][2];
int cnt[N], pa[N2], Rp[N];
uint64_t mask[N2];

int find(int x) {
    return pa[x] < 0 ? x : pa[x] = find(pa[x]);
}

int main() {
    n = read(), k = read(), A = read();
    for (int i = 0; i < n; i++) {
        pts[i][1] = read();
        pts[i][0] = k - read();
        pts[i][2] = read();
        buc[pts[i][0]]++;
    }
    for (int i = 1; i <= k; i++) buc[i + 1] += buc[i];
    for (int i = 0; i < n; i++) {
        int t = --buc[pts[i][0]];
        memcpy(LW[t], pts[i] + 1, 8);
    }
    for (int i = 0; i < k; i++) cnt[i] = A;
    memset(mask, 0xff, sizeof mask);
    memset(pa, -1, sizeof pa);
    iota(Rp, Rp + N2, 0);
    int ans = 0;
    for (int r = 1; r <= k; r++)
        for (int i = buc[r]; i < buc[r + 1]; i++) {
            int l = LW[i][0], w = LW[i][1];
            ans += w;
            int lb = Rp[find(l >> 6)], rb = r >> 6;
            auto S0 = mask[lb];
            if (lb == l >> 6) S0 &= ~0ULL << (l & 63);
            while (lb < rb) {
                auto S = S0;
                for (; S; S &= S - 1) {
                    int p = lb * 64 + __builtin_ctzll(S);
                    int tmp = min(w, cnt[p]);
                    cnt[p] -= tmp, w -= tmp;
                    if (!w) break;
                }
                mask[lb] ^= S0 ^ S;
                if (!w) break;
                int nxt = find(lb + 1);
                if (!mask[lb]) {
                    lb = find(lb);
                    if (pa[nxt] > pa[lb]) swap(nxt, lb), Rp[nxt] = Rp[lb];
                    pa[nxt] += pa[lb], pa[lb] = nxt;
                }
                lb = Rp[nxt], S0 = mask[lb];
            }
            if (w != 0 & lb == rb) {
                S0 &= (1ULL << (r & 63)) - 1;
                auto S = S0;
                for (; S; S &= S - 1) {
                    int p = lb * 64 + __builtin_ctzll(S);
                    int tmp = min(w, cnt[p]);
                    cnt[p] -= tmp, w -= tmp;
                    if (!w) break;
                }
                mask[lb] ^= S0 ^ S;
            }
            ans -= w;
        }
    cout << ans << 'n';
}
```
### [1842F - Tenzing and Tree](../problems/F._Tenzing_and_Tree.md)

 **Tutorial**Let root be the centroid of all black vertices and sizei be the number of black vertices in the subtree of node i.

Then the value is ∑i≠rootk−2⋅sizei=(n−1)⋅k−2⋅∑i≠rootsizei.

Consider painting node i black, the total contributio to all of its ancestors is 2⋅depthi, where depthi is the distance from root to i.

Since we want to maximize the value, we can greedily select the node with the smallest depthi.

But how do we ensure that root is the centroid after selecting other black vertices? We can simply take the maximum of all possible root because if a node is not the centroid, some edges will have a negative weight, making it worse than the optimal answer.

Enumerate all possible root and use BFS to add vertices based on their distance to root. The complexity is O(n2).

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 8;

int n, ans[N];
vector<int> G[N];

void bfs(int u) {
    static int q[N], dis[N];
    memset(dis, -1, sizeof dis);
    q[1] = u, dis[u] = 0;
    for (int l = 1, r = 2; l < r; l++) {
        u = q[l];
        for (int v : G[u]) if (dis[v] < 0)
            dis[v] = dis[u] + 1, q[r++] = v;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += dis[q[i]]; 
        ans[i] = max(ans[i], (n - 1) * i - sum * 2);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 0; i < n; i++) bfs(i);
    for (int i = 0; i <= n; i++)
        cout << ans[i] << ' ';
}
```
### [1842G - Tenzing and Random Operations](../problems/G._Tenzing_and_Random_Operations.md)

 **Tutorial**Before starting to solve this problem, let's establish two basic properties:

 * For two completely independent random variables x1,x2, we have E(x1x2)=E(x1)E(x2).
* For (a+b)×(c+d), we have E((a+b)×(c+d))=E(ac)+E(ad)+E(bc)+E(bd).

Returning to this problem, let xi,j be a random variable: its value is v when the i-th operation sets aj to aj+v, otherwise it is 0.

Then note that the answer is the expected value of ∏ni=1(ai+∑mj=1xj,i).

Applying the second property above to split the product, each term is a product of some ai and x.

Specifically, each term has n factors, and for each i∈[1,n], either ai is one of its factors, or some xj,i is one of its factors.

Let's investigate the expectation of a specific term. Note that if i1<i2, then E(xj,i1×xj,i2)=E(xj,i1)×v, that is, if xj,i1 is 0 then the whole product is 0, and if xj,i1 is v then xj,i2 must be v.

Therefore, for all the x factors in a term, we categorize them by the first index, i.e. we group all xj,... into category j. For each category, we only need to focus on the first variable. If it's v, then the remaining variables take value v, otherwise the result is 0. Note that the variables in different categories are completely independent (because their values are determined by operations in two different rounds), so the expected product of the variables in two categories can be split into the product of the expected products of the variables within each category.

Our goal is to compute the expected sum of all the terms, which can be nicely combined with DP:

Let dp(i,j) be the value that we have determined the first i factors of each term and there are j categories that have appeared at least once (if adding the variable at position i+1 brings contribution v, otherwise the contribution is i+1n×v). The transition can be easily calculated with O(1), depending on whether to append ai+1 or x...,i+1 to each term, and if it's the latter, we discuss whether the variable belongs to one of the j categories that have appeared or the other m−j categories. The time complexity is O(n×min(n,m)).

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 8, P = 1e9 + 7;

int n, m, v, a[N], coef[N], dp[N][N];

long long Pow(long long a, int n) {
    long long r = 1;
    while (n) {
        if (n & 1) r = r * a % P;
        a = a * a % P, n >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> v;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        auto coef = i * Pow(n, P - 2) % P * v % P;
        for (int j = 0; j < i; j++) {
            dp[i][j + 1] = dp[i - 1][j] * coef % P * (m - j) % P;
            dp[i][j] = (dp[i][j] + dp[i - 1][j] * (a[i] + 1LL * j * v % P)) % P;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        (ans += dp[n][i]) %= P;
    cout << ans << 'n';
}
```
### [1842H - Tenzing and Random Real Numbers](../problems/H._Tenzing_and_Random_Real_Numbers.md)

 **Hint 1**Ignoring time complexity for now, how do we calculate the answer? The first step is to enumerate which variables are <0.5 and which variables are >0.5.

 **Hint 2**Sort all variables xi by min(xi,1−xi) and enumerate the sorted result (referring to the permutation).

 **Tutorial**Suppose no variable equals 0.5, because the probability of being equal to 0.5 is 0, variables less than 0.5 are called white vertices, and those greater than 0.5 are called black vertices. Each black and white coloring is equiprobable, so we can calculate the probability that satisfies all conditions for each black and white coloring, and then take the average.

For two variables less than 0.5, the condition of ≤1 is always satisfied, and the condition of ≥1 is never satisfied. Therefore, we do not need to consider the conditions between same-colored points. The condition between white vertex u and black vertex v, xu+xv≤1, is satisfied only when xu≤1−xv. Let yu=min(xu,1−xu)={xu(u is white)1−xu(u is black), then yu can be regarded as a random variable in [0,0.5), for ≤1 condition, the white vertex's y must be less than or equal to the black vertex's y, so we add an edge from the white vertex to the black vertex; for ≥1 condition, we add an edge from the black vertex to the white vertex.

We get a directed graph that restricts the size relationship of y1⋯n. Suppose that sorting y1⋯n from small to large is yp1,yp2,⋯,ypn, then each permutation p is equiprobable, and this p contributes if and only if it is a topological sort, so the probability that satisfies all conditions is the number of topological sorts divided by n!.

Now the problem has been transformed into a counting problem. For each coloring, count the total number of topological sorts. Now we do not enumerate coloring directly but enumerate topological sorts directly by enumerating a permutation p such that yp1<yp2<⋯<ypn and count the number of colorings that satisfy the conditions. It can be found that ≤1 condition limits variablesin in the front position of p to be less than 0.5, and ≥1 condition limits variables in the front position of p to be greater than 0.5.

Then we can use bit-mask DP. Let dpmask represent that we have added all vertices in mask into topological sort. We enumerate new added vertex u for transition. If all variables with ≤1 conditions between it are included in mask, it can be colored black; if all variables with ≥1 conditions between it are included in mask, it can be colored white.

Time complexit is O(2nn).

 **Code**
```cpp
#include <iostream>
 
const int P = 998244353;
 
long long Pow(long long a, int n) {
    long long r = 1;
    while (n) {
        if (n & 1) r = r * a % P;
        a = a * a % P, n >>= 1;
    }
    return r;
}
inline void inc(int& a, int b) {
    if((a += b) >= P) a -= P;
}
 
int n, m, G[20][2], f[1 << 20];
 
int main() {
    std::cin >> n >> m;
    while (m--) {
        int t, i, j;
        std::cin >> t >> i >> j;
        i--, j--;
        G[i][t] |= 1 << j;
        G[j][t] |= 1 << i;
    }
    f[0] = 1;
    for (int S = 0; S < 1 << n; S++)
        for (int i = 0; i < n; i++) if (~S >> i & 1) {
            if ((G[i][0] | S) == S) inc(f[S | 1 << i], f[S]);
            if ((G[i][1] | S) == S) inc(f[S | 1 << i], f[S]);
        }
    long long t = 1;
    for (int i = 1; i <= n; i++) t = t * i * 2 % P;
    std::cout << f[(1 << n) - 1] * Pow(t, P - 2) % P << 'n';
}
```
### [1842I - Tenzing and Necklace](../problems/I._Tenzing_and_Necklace.md)

 **Hint 1**How to solve it if you want to cut exactly m edges ?

 **Hint 2**DP+divide and conquer

 **Tutorial**Add a constraint: "you must cut off m edges".

Consider enumerating the minimum cut edges from small to large. 

Suppose the minimum cut edge chosen is a1, and the subsequent optimal solution is a2,a3,...,am. 

If another minimum cut edge is selected: b1, and the subsequent optimal solution is b2,b3,...,bm.

Assume that ai<ai+1,bi<bi+1,b1>a1.

#### 1. It is possible to only adjust b2,b3,...,bm, so that ∀1≤i≤mbi≥ai, and the total cost after adjustment remains unchanged.

The adjustment method is as follows:

Find the smallest i such that bi<ai, and find the first j such that bj≥aj after i, if it does not exist, let j=m+1.

It can be observed that (bi,bi+1,bi+2,...,bj−1) can be replaced with (ai,ai+1,ai+2,...,aj−1), which is still a valid solution. Moreover, the solution (ai,ai+1,ai+2,...,aj−1) can also be replaced with (bi,bi+1,bi+2,...,bj−1), because bi−1≥ai−1 and bj≥aj.

Since a and b are both optimal solutions with fixed a1 and b1, wbi+wbi+1+...+wbj−1=wai+wai+1+...+waj−1. Therefore, replacing (bi,bi+1,bi+2,...,bj−1) with (ai,ai+1,ai+2,...,aj−1) does not increase the total cost.

Repeat the above adjustment until there is no bi<ai.

Similarly, it can be proven that only adjusting a2,a3,...,am is feasible, so that ∀1≤i≤mbi≥ai, and the total cost after adjustment remains unchanged.

#### 2. If ∀1≤i≤mbi≥ai is already satisfied, it is possible to only adjust b2,b3,...,bm, so that ∀1≤i<mai≤bi≤ai+1, and the total cost after adjustment remains unchanged. Assume that a1<b1≤a2.

The adjustment method is as follows:

Find the smallest i such that bi>ai+1, and find the first j such that bj≤aj+1 after i (let am+1=+∞).

(bi,bi+1,bi+2,...,bj−1) can be replaced with (ai+1,ai+2,ai+3,...,aj), which is still a valid solution. Moreover, the solution (ai+1,ai+2,ai+3,...,aj) can also be replaced with (bi,bi+1,bi+2,...,bj−1), because bi−1≤ai and bj≤aj+1.

Since a and b are both optimal solutions with fixed a1 and b1, wbi+wbi+1+...+wbj−1=wai+1+wai+2+...+waj. Therefore, replacing (bi,bi+1,bi+2,...,bj−1) with (ai+1,ai+2,ai+3,...,aj) does not increase the total cost.

Similarly, it can be proven that only adjusting a2,a3,...,am is feasible, so that ∀1≤i<mai≤bi≤ai+1, and the total cost after adjustment remains unchanged.

#### 3. If b1>a2, it is possible to adjust b1,b2,...,bm, so that b1≤a2, and the total cost does not increase.

The adjustment method is as follows:

Find the smallest j such that bj≤aj+1 (let am+1=+∞).

It can be observed that (a2,a3,a4,...,aj) can be replaced with (b1,b2,b3,...,bj−1), which is still a valid solution. Moreover, the solution (b1,b2,b3,...,bj−1) can also be replaced with (a2,a3,a4,...,aj), because bj≤aj+1.

Since a is the optimal solution with fixed a1 and b1, wb1+wb2+...+wbj−1≥wa2+wa3+...+waj. Therefore, replacing (b1,b2,b3,...,bj−1) with (a2,a3,a4,...,aj) does not increase the total cost.

 

---

Combining the above conclusions, we can obtain a solution that must cut off m edges:

Let a1=1, find the optimal solution a1,a2,a3,...,am. 

Then, it can be assumed that all bi satisfy ai≤bi≤ai+1.

A divide-and-conquer algorithm can be used. Let solve((l1,r1),(l2,r2),(l3,r3),...,(lm,rm)) represent the optimal solution for all li≤bi≤ri.

If l1>r1, then we are done. Otherwise, let x=⌊l1+r12⌋, we can use DP to calculate the cost and solution for b1=x in O(∑ri−li+1) time complexity. Then, recursively calculate solve((l1,b1−1),(l2,b2),(l3,b3),...,(lm,bm)) and solve((b1+1,r1),(b2,r2),(b3,r3),...,(bm,rm)).

Time complexity analysis: ∑ri−li+1=(∑ri−li)+m. If the sum of adjacent parts is ≤k, it can be merged, but it is definitely not the optimal solution. Therefore, m≤2⌈nk⌉. Assuming that the length of the first segment is r1−l1+1=O(k), the time complexity is O(nlogk+mk)=O(nlogk).

Finally, we need to calculate the solution for all possible m and take the min as the final answer. After pruning the first edge, if the optimal solution requires cutting off m′ edges, similar to the previous proof, other solutions can be adjusted to satisfy |m−m′|≤1 and the total cost does not increase. 

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 8;

int n, K, a[N], pre[N * 2];
long long dp[N * 2], ans;

vector<int> trim(vector<int> a, int L, int R) {
    return vector(a.begin() + L, a.end() - R);
}
vector<int> init() {
    static int q[N];
    q[1] = 0;
    for (int i = 1, l = 1, r = 1; i <= n; i++) {
        if (q[l] < i - K) l++;
        dp[i] = dp[q[l]] + a[i], pre[i] = q[l];
        while (l <= r && dp[i] < dp[q[r]]) r--;
        q[++r] = i;
    }
    ans = dp[n];
    vector<int> res;
    for (int i = n; i; i = pre[i]) res.push_back(i);
    res.push_back(0), reverse(res.begin(), res.end());
    return res;
}
vector<int> solve(int first, vector<int> L, vector<int> R) {
    dp[first] = a[first];
    int l = first, r = first;
    long long val; int p;
    auto checkMin = [&](int i) {
        if (dp[i] < val) val = dp[i], p = i;
    };
    for (int i = 0; i < L.size(); i++) {
        val = 1e18, p = 0;
        for (int j = R[i]; j >= L[i]; j--) {
            for (; r >= max(l, j - K); r--) checkMin(r + i);
            dp[j + i + 1] = val + a[j];
            pre[j + i + 1] = p;
        }
        l = L[i], r = R[i];
    }
    val = 1e18, p = 0;
    for (int i = max(L.back(), n - K + first); i <= R.back(); i++)
        checkMin(i + L.size());
    ans = min(ans, val);
    vector<int> res;
    for (int i = L.size(); i; i--) res.push_back(p - i), p = pre[p];
    reverse(res.begin(), res.end());
    return res;
}
void divide(int l, int r, vector<int> L, vector<int> R) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    auto M = solve(mid, L, R);
    divide(l, mid - 1, L, M), divide(mid + 1, r, M, R);
}
void divide(vector<int> p) {
    p.push_back(n), divide(1, p[0], trim(p, 0, 1), trim(p, 1, 0));
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> K;
        for (int i = 1; i <= n; i++) cin >> a[i];
        a[0] = a[n];
        auto p = init();
        divide(trim(p, 1, 1));
        divide(solve(0, trim(p, 0, 1), trim(p, 1, 0)));
        if ((p.size() - 2) * K >= n)
            divide(solve(0, trim(p, 1, 2), trim(p, 2, 1)));
        cout << ans << 'n';
    }
}
```
