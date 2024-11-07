# Tutorial_(en)

Hello everyone, this is the editorial for [Codeforces Round 558 (Div. 2)](https://codeforces.com/contest/1163 "Codeforces Round 558 (Div. 2)"). I hope you enjoy the problem as well as I did!

[1163A - Eating Soup](../problems/A._Eating_Soup.md "Codeforces Round 558 (Div. 2)")

Author: [ArguteOnAir](https://codeforces.com/profile/ArguteOnAir "Expert ArguteOnAir")

 **Tutorial**
### [1163A - Eating Soup](../problems/A._Eating_Soup.md "Codeforces Round 558 (Div. 2)")

We can prove that the first one to leave the circle does not make any difference to our answer. So after trying some tests, you will probably come up with an idea of selecting the cats that are sitting right between the other two to be the prior ones to leave because, in this way, those vacancies will definitely be useful for creating more separate groups.

Therefore, if $m - 1 < \lfloor \frac{n}{2} \rfloor$, the answer is $m$ since each cat to leave (after the first cat) increases the number of groups. Otherwise, if $m + 1 \geq \lfloor \frac{n}{2} \rfloor$, each independent cat to leave decreases the number of groups so the answer is $n - m$. Summarily, the answer is $\min(m, n - m)$. Be careful with $m = 0$.

Complexity: $O(1)$.

 **Implementation**
```cpp
#include <iostream>

using namespace std;

int main ()
{
    int n, m;
	cin >> n >> m;
	cout << (m ? min(m, n - m) : 1) << endl;
	return 0;
}
```
[1163B2 - Cat Party (Hard Edition)](../problems/B2._Cat_Party_(Hard_Edition).md "Codeforces Round 558 (Div. 2)")

Author: [Shirone](https://codeforces.com/profile/Shirone "Specialist Shirone")

 **Tutorial**
### [1163B2 - Cat Party (Hard Edition)](../problems/B2._Cat_Party_(Hard_Edition).md "Codeforces Round 558 (Div. 2)")

We can iterate over all streaks and check for each streak if we can remove one day so that each color has the same number of cats.

There are 4 cases where we can remove a day from the streak to satisfy the condition:

* There is only one color in this streak.
* All appeared colors in this streak have the occurrence of $1$ (i.e. every color has exactly $1$ cat with that color).
* Every color has the same occurrence of cats, except for exactly one color which has the occurrence of $1$.
* Every color has the same occurrence of cats, except for exactly one color which has the occurrence exactly $1$ more than any other color.

All of these four conditions can be checked using counting techniques.

Complexity: $O(n)$.

 **Implementation**
```cpp
#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 1e5 + 10;

int n, color, ans, mx, f[N], cnt[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
    {
        scanf("%d", &color);
        cnt[f[color]]--;
        f[color]++;
        cnt[f[color]]++;
        mx = max(mx, f[color]);
        bool ok = false;
        if (cnt[1] == i) // every color has occurence of 1
            ok = true;
        else if (cnt[i] == 1) // only one color has the maximum occurence and the occurence is i
            ok = true;
        else if (cnt[1] == 1 && cnt[mx] * mx == i - 1) // one color has occurence of 1 and other colors have the same occurence
            ok = true;
        else if (cnt[mx - 1] * (mx - 1) == i - mx && cnt[mx] == 1) // one color has the occurence 1 more than any other color
            ok = true;
        if (ok)
            ans = i;
    }
    printf("%d", ans);
	return 0;
}
```
[1163C2 - Power Transmission (Hard Edition)](../problems/C2._Power_Transmission_(Hard_Edition).md "Codeforces Round 558 (Div. 2)")

Author: [GreymaneSilverfang](https://codeforces.com/profile/GreymaneSilverfang "Candidate Master GreymaneSilverfang")

 **Tutorial**
### [1163C2 - Power Transmission (Hard Edition)](../problems/C2._Power_Transmission_(Hard_Edition).md "Codeforces Round 558 (Div. 2)")

First, we will divide the problem into several parts: 1) construct the wires, 2) remove duplicates, and 3) count the number of pairs that intersect.

The first part is relatively simple: note that each wire is simply a line that goes through two distinct points (poles) on the $Oxy$ plane. Suppose this line goes through point $A(x_1,y_1)$ and point $B(x_2,y_2)$, then it can be described by the equation $ax - by = c$ where $a = y_1 - y_2$, $b = x_1 - x_2$, $c = y_1x_2 - y_2x_1$.

For step two, we will simplify the equation for each line by dividing each coefficient by their greatest common divisor. Now each equation uniquely identifies a line, and vice versa - so we can sort the wires by their values of a, b, and c; then remove adjacent duplicates.

The final part of the solution also makes use of this sorted list. As any pair of lines on the plane must intersect unless they are parallel, we only need to count the number of parallel pairs and subtract these from the total number of pairs. These are the pairs with the same slope (i.e. same value of a and b), and they already are next to each other in our list. We now iterate over these "blocks" of parallel lines and count the number of pairs each block contributes — a block of size $s$ gives $\frac{s(s-1)}{2}$ pairs.

Complexity: $O(n^2\log{n})$.

 **Implementation**
```cpp
#include <cstdio>
#include <map>
#include <set>
#include <utility>
const int N = 1001;
int x[N], y[N];
std::map<std::pair<int,int>,std::set<long long>> slope_map;

int gcd(int a, int b) 
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &x[i], &y[i]);
	long long total = 0, res = 0;
	for (int i = 1; i <= n - 1; ++i)
		for (int j = i + 1; j <= n; ++j)
		{
			int x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];
			// construct a line passing through (x1, y1) and (x2, y2)
			// line is expressed as equation ax - by = c with constant a, b, c 
			int a = y1 - y2, b = x1 - x2;
			// simplify equation
			int d = gcd(a, b); a /= d, b /= d;
			if (a < 0 || (a == 0 && b < 0))
			{
			    a = -a;
			    b = -b;
			}
			// lines with the same slope (same a, b) are stored in a map
			std::pair<int,int> slope(a, b);
			long long c = 1LL * a * x1 - 1LL * b * y1;
			if (!slope_map[slope].count(c))
			{
				++total;
				slope_map[slope].insert(c);
				// if this line is new, it intersects every line with different slope
				res += total - slope_map[slope].size();
			}
		}
	printf("%lldn", res);
}
```
[1163D - Mysterious Code](../problems/D._Mysterious_Code.md "Codeforces Round 558 (Div. 2)")

Author: [Kuroni](https://codeforces.com/profile/Kuroni "International Master Kuroni")

 **Tutorial**
### [1163D - Mysterious Code](../problems/D._Mysterious_Code.md "Codeforces Round 558 (Div. 2)")

Firstly, we will find the maximal value of $f(c', s) - f(c', t)$ via dynamic programming. Denote 'dp[i][ks][kt]' as the maximal value of the said value when replacing the first $i$-th character of $c$, and the KMP state for the replaced sub-code to be $ks$ and $kt$. The maximal value of $f(c', s) - f(c', t)$ for the whole code will lie among all end states $dp[n][ks][kt]$ for all values of $ks$ and $kt$.

Complexity: $O(|c| \cdot |s| \cdot |t|)$.

 **Implementation**
```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int K = 1005, N = 55, M = 55, INF = 1E9 + 7;

int k, n, m;
int kmp_s[N], nxt_s[N][26], kmp_t[M], nxt_t[M][26];
int dp[K][N][M];
char code[K], s[N], t[M];

void init(char s[], int n, int kmp[], int nxt[][26])
{
    kmp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int cur = kmp[i - 1];
        while (cur > 0 && s[cur + 1] != s[i])
            cur = kmp[cur];
        if (s[cur + 1] == s[i])
            ++cur;
        kmp[i] = cur;
    }

    for (int i = 0; i <= n; i++)
        for (char c = 'a'; c <= 'z'; c++)
        {
            int cur = i;
            while (cur > 0 && s[cur + 1] != c)
                cur = kmp[cur];
            if (s[cur + 1] == c)
                ++cur;
            nxt[i][c - 'a'] = cur;
        }
}

int main()
{
    scanf("%s%s%s", code + 1, s + 1, t + 1);
    k = strlen(code + 1); n = strlen(s + 1); m = strlen(t + 1);
    init(s, n, kmp_s, nxt_s); init(t, m, kmp_t, nxt_t);
    for (int i = 0; i <= k; i++)
        for (int ks = 0; ks <= n; ks++)
            for (int kt = 0; kt <= m; kt++)
                dp[i][ks][kt] = -INF;
    dp[0][0][0] = 0;
    for (int i = 0; i < k; i++)
        for (int ks = 0; ks <= n; ks++)
            for (int kt = 0; kt <= m; kt++)
                for (char c = 'a'; c <= 'z'; c++)
                    if (code[i + 1] == '*' || code[i + 1] == c) // we now add/replace the (i + 1)-th character
                    {
                        int ns = nxt_s[ks][c - 'a'], nt = nxt_t[kt][c - 'a'];
                        int tmp = dp[i][ks][kt] + (ns == n) - (nt == m); // add the new occurrences if any
                        dp[i + 1][ns][nt] = max(dp[i + 1][ns][nt], tmp);
                    }
    int ma = -INF;
    for (int ks = 0; ks <= n; ks++)
        for (int kt = 0; kt <= m; kt++)
            ma = max(ma, dp[k][ks][kt]);
    printf("%dn", ma);
}
```
[1163E - Magical Permutation](../problems/E._Magical_Permutation.md "Codeforces Round 558 (Div. 2)")

Author: [Kuroni](https://codeforces.com/profile/Kuroni "International Master Kuroni")

 **Tutorial**
### [1163E - Magical Permutation](../problems/E._Magical_Permutation.md "Codeforces Round 558 (Div. 2)")

The idea here is iterate $x$ and check if it is possible to create a magical permutation for the current $x$ we are iterating through.

An observation to be made is that if it is possible to create a magical permutation $P$ from $0$ to $2^x - 1$, then it must be possible to express each integer from $0$ to $2^x - 1$ as the xor value of elements in one subset of $S$. This is because $0$ is represented as the xor value of the empty subset of $S$. Because of that, every element to the left of $0$ in $P$ is also the xor value of one subset of $S$, and so is every element to the right of $0$ in $P$.

Because of that, we first check that if we can create every integer from $0$ to $2^x - 1$ using only the xor values of every subset of $S$. This is possible by creating a basis for integers from $0$ to $2^x - 1$ — $x$ integers such that each integer from $0$ to $2^x - 1$ is the xor value of a subset of these $x$ integers — from $S$ using Gaussian elimination.

Now, if it is possible to create such a basis for integers from $0$ to $2^x - 1$ using only elements of $S$, is it possible to create a magic permutation then? Recall that each integer from $0$ to $2^x - 1$ corresponds to the xor value of a subset of the basis, or in other words, corresponds to a bitmask of the basis. We can also narrow down the original condition, such that the xor value of any two consecutive elements belongs to the basis; or in other words, the corresponding bitmask of any two consecutive elements in the magical permutation differs by exactly 1 bit. The problem now becomes creating a permutation of integers from $0$ to $2^x - 1$ such that any two consecutive elements in this permutation differs by 1 bit, and then convert this permutation to a magical permutation using the created basis. It turns out that we can always do this using Gray codes, although DFS works just as well.

It also turns out that the basis for integers from $0$ to $2^x - 1$ does not exceed $2^x - 1$, we can sort $S$ and create the basis along with checking the aforementioned condition.

Complexity: $O(n \log n + n \log MAX + MAX)$ if Gray codes are used, or $O(n \log n + n \log MAX + MAX \log MAX)$ is DFS is used instead, where $MAX$ denotes the maximum value of elements in $S$.

 **Implementation**
```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005;

int n, a[N];
vector<int> basis, vec;

void add(int u)
{
    int tmp = u;
    // we keep the basis sorted in decreasing order
    for (int &v : basis)
        u = min(u, u ^ v);
    if (u > 0) // u is a new element in the basis
    {
        basis.push_back(u);
        vec.push_back(tmp);
        // now we move u up until the basis is decreasingly sorted again
        for (int i = basis.size() - 1; i > 0; i--)
            if (basis[i] > basis[i - 1])
                swap(basis[i], basis[i - 1]);
            else
                break;
    }
}

void gray_code(int size)
{
    vector<int> ans = {0};
    for (int i = 0; i < size; i++)
        for (int j = (1 << i) - 1; j >= 0; j--)
            ans.push_back(ans[j] ^ vec[i]);
    for (int &v : ans)
        printf("%d ", v);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    int pt = 0, x = 0;
    for (int i = 1; i < 20; i++)
    {
        for (; pt < n && a[pt] < (1 << i); pt++)
            add(a[pt]);
        if (basis.size() == i)
            x = i;
    }
    basis.clear();
    vec.clear();
    for (int i = 0; i < n && a[i] < (1 << x); i++)
        add(a[i]);
    printf("%dn", x);
    gray_code(x);
}
```
 **Implementation with DFS**
```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005, MX = 1E6 + 5;

int n, x = 0, a[N];
bool vis[MX];
vector<int> basis, vec, ans;

void add(int u)
{
    int tmp = u;
    for (int &v : basis)
        u = min(u, u ^ v);
    if (u > 0)
    {
        basis.push_back(u);
        vec.push_back(tmp);
        for (int i = basis.size() - 1; i > 0; i--)
            if (basis[i] > basis[i - 1])
                swap(basis[i], basis[i - 1]);
            else
                break;
    }
}

void DFS(int u, int it = 0)
{
    ans.push_back(u);
    vis[u] = true;
    if (it == (1 << x) - 1)
        return;
    for (int &v : vec)
        if (!vis[u ^ v])
        {
            DFS(u ^ v, it + 1);
            return;
        }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    int pt = 0;
    for (int i = 1; i < 20; i++)
    {
        for (; pt < n && a[pt] < (1 << i); pt++)
            add(a[pt]);
        if (basis.size() == i)
            x = i;
    }
    basis.clear();
    vec.clear();
    for (int i = 0; i < n && a[i] < (1 << x); i++)
        add(a[i]);
    printf("%dn", x);
    DFS(0);
    for (int &v : ans)
        printf("%d ", v);
}
```
[1163F - Indecisive Taxi Fee](../problems/F._Indecisive_Taxi_Fee.md "Codeforces Round 558 (Div. 2)")

Author: [Kuroni](https://codeforces.com/profile/Kuroni "International Master Kuroni")

 **Tutorial**
### [1163F - Indecisive Taxi Fee](../problems/F._Indecisive_Taxi_Fee.md "Codeforces Round 558 (Div. 2)")

Firstly, we will find and trace out one shortest path from vertex $1$ to vertex $n$ in the graph. Let's call this path main path, and we will number the edges on the main path as $E_1$, $E_2$, .., $E_k$ respectively. We will also call all of the other edges that does not belong to this main path candidate edges.

During the procedure, we can also calculate the shortest path from $1$ to every vertex $u$, and the shortest path from every vertex $u$ to $n$. After calculating all of these values, we can now query the shortest path from $1$ to $n$ that must pass through each edge $(u, v)$ in either direction.

We have a few observations to be made here:

Observation 1: Apart of the vertices belong to the main path, for each vertex $u$, the shortest path from $1$ to $u$ uses a prefix of the main path. More formally, there exists an index $l_u$ ($0 \leq l_u \leq k$) such that the shortest path from $1$ to $u$ must use the edges $E_1$, $E_2$, ..., $E_{l_u}$ at its beginning.

Using the same analogy, we can say that for each vertex $u$, the shortest path from $u$ to $n$ uses a suffix of the main path; or in other words, there exists an index $r_u$ ($1 \leq r_u \leq k + 1$) such that the shortest path from $u$ to $n$ must use the edges $E_{r_u}$, $E_{r_{u + 1}}$, ..., $E_k$ at its end. Note that if $l_u = 0$, the shortest path from $1$ to $u$ does not use a prefix of the main path, and if $r_u = k + 1$, the shortest path from $u$ to $n$ does not use a suffix of the main path.

For every vertex $v$ that belongs to the main path however, we will set $l_v = t, r_v = t + 1$, where $t$ is the position where $v$ appears on the main path.

What does this imply? This implies that the shortest from $1$ to $n$ that passes through $u$ does not rely on the edges $E_{l_u + 1}$, $E_{l_u + 2}$, ..., $E_{r_u - 1}$.

Observation 2: For each candidate edge $(u, v)$, the shortest path from $1$ to $n$ passing through this edge in the order $u \rightarrow v$ does not rely on the edges $E_{l_u + 1}$, $E_{l_u + 2}$, ..., $E_{r_v - 1}$. This is because, the shortest path passing through this order $u \rightarrow v$ will consist of the shortest path from $1$ to $u$, the edge $(u, v)$, and the shortest path from $v$ to $n$. With the same analogy, the shortest path from $1$ to $n$ passing through this edge in the order $v \rightarrow u$ does not rely on the edges $E_{l_v + 1}$, $E_{l_v + 2}$, ..., $E_{r_u - 1}$.

Using the observations, we can now answer the queries.

There are three cases that we should consider when answering the shortest path with the modified edge:

* The modified edge is a candidate edge (i.e. it does not belong to the main path): we will take the minimal of the main path and the shortest path that goes through this modified edge.
* The modified edge belongs to the main path, and its value decreases: the new shortest path is still the main path, and its new value is the old value subtracting the difference between the original and the modified weight of that edge.
* The modified edge belongs to the main path, and its value increases: the new shortest path is either one of these two options:
	1. The main path, its new value being the old value adding the weight-difference of the modified edge.
	2. The shortest path from $1$ to $n$ that does not use the modified edge. This shortest path must use a candidate edge, since we cannot reuse the main path anymore; more specifically, this shortest path uses a candidate edge that does not rely on the modified edge. To get the value of this option, recall in observation 2 that for each candidate edge $(u, v)$ and with its direction, we know the range of edges belonging to the main path that this candidate edge does not rely on. Hence, we can use a segment tree to manage and query the shortest path that does not rely on this edge.

Complexity: $O((m + n)\log{n})$.

 **Implementation**
```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 2E5 + 5, M = 2E5 + 5;
const long long INF = 1E18 + 7;

int n, m, q, ed, nw, mx, u[M], v[M], w[M], ind[M];
int tr[N], le[N], ri[N];
bool on_path[N];
long long dis[2][N];

struct TNode
{
    int u;
    long long val;

    TNode(int _u, long long _val)
    {
        u = _u;
        val = _val;
    }

    inline bool operator>(const TNode &oth) const
    {
        return val > oth.val;
    }
};
priority_queue<TNode, vector<TNode>, greater<TNode>> pq;

struct TEdge
{
    int v, w, ind;

    TEdge(int _v, int _w, int _ind)
    {
        v = _v;
        w = _w;
        ind = _ind;
    }
};
vector<TEdge> adj[N];

struct TTree
{
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    long long tr[4 * M];

    void build(int l, int r, int i)
    {
        tr[i] = INF;
        if (l == r)
            return;
        build(l, m, lc);
        build(m + 1, r, rc);
    }

    void upd(int l, int r, int i, int L, int R, long long v)
    {
        if (l > R || r < L || L > R)
            return;
        if (L <= l && r <= R)
        {
            tr[i] = min(tr[i], v);
            return;
        }
        upd(l, m, lc, L, R, v);
        upd(m + 1, r, rc, L, R, v);
    }

    long long que(int l, int r, int i, int u)
    {
        if (l == r)
            return tr[i];
        return min(tr[i], u <= m ? que(l, m, lc, u) : que(m + 1, r, rc, u));
    }

#undef m
#undef lc
#undef rc
} seg;

void dijkstra(int st, long long dis[], int get = 0)
{
    fill(dis + 1, dis + n + 1, INF);
    pq.push(TNode(st, dis[st] = 0));
    while (!pq.empty())
    {
        TNode u = pq.top(); pq.pop();
        if (u.val > dis[u.u])
            continue;
        for (TEdge &v : adj[u.u])
            if (dis[v.v] > u.val + v.w)
            {
                tr[v.v] = v.ind;
                if (get == 1 && !on_path[v.v])
                    le[v.v] = le[u.u];
                else if (get == 2 && !on_path[v.v])
                    ri[v.v] = ri[u.u];
                pq.push(TNode(v.v, dis[v.v] = u.val + v.w));
            }
    }
}

void trace()
{
    on_path[1] = true; le[1] = ri[1] = 0;
    for (int i = 1, cur = 1; cur != n; i++)
    {
        int edge = tr[cur];
        ind[edge] = mx = i;
        cur = u[edge] ^ v[edge] ^ cur;
        on_path[cur] = true;
        le[cur] = ri[cur] = i;
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", u + i, v + i, w + i);
        ind[i] = -1;
        adj[u[i]].push_back(TEdge(v[i], w[i], i));
        adj[v[i]].push_back(TEdge(u[i], w[i], i));
    }
    dijkstra(n, dis[1]); // reverse the initial dijkstra for the trace to increase from 1 -> n
    trace();
    dijkstra(1, dis[0], 1);
    dijkstra(n, dis[1], 2);
    seg.build(1, mx, 1);
    for (int i = 1; i <= m; i++)
        if (ind[i] == -1)
        {
            seg.upd(1, mx, 1, le[u[i]] + 1, ri[v[i]], dis[0][u[i]] + w[i] + dis[1][v[i]]);
            seg.upd(1, mx, 1, le[v[i]] + 1, ri[u[i]], dis[0][v[i]] + w[i] + dis[1][u[i]]);
        }
    while (q--)
    {
        scanf("%d%d", &ed, &nw);
        long long ans;
        if (ind[ed] > 0)
        {
            ans = dis[0][n] - w[ed] + nw;
            if (nw > w[ed])
                ans = min(ans, seg.que(1, mx, 1, ind[ed]));
        }
        else
        {
            ans = dis[0][n];
            if (nw < w[ed])
            {
                ans = min(ans, dis[0][u[ed]] + nw + dis[1][v[ed]]);
                ans = min(ans, dis[0][v[ed]] + nw + dis[1][u[ed]]);
            }
        }
        printf("%lldn", ans);
    }
}
```
