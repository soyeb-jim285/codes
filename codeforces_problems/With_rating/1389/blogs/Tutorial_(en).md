# Tutorial_(en)

[1389A - LCM Problem](../problems/A._LCM_Problem.md "Educational Codeforces Round 92 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1389A - LCM Problem](../problems/A._LCM_Problem.md "Educational Codeforces Round 92 (Rated for Div. 2)")

Suppose we have chosen $x$ and $y$ as the answer, and $x$ is not a divisor of $y$. Since $LCM(x, y)$ belongs to $[l, r]$, we could have chosen $x$ and $LCM(x, y)$ instead. So if the answer exists, there also exists an answer where $x$ is a divisor of $y$.

If $2l > r$, then there is no pair $(x, y)$ such that $l \le x < y \le r$ and $x|y$. Otherwise, $x = l$ and $y = 2l$ is the answer.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    l, r = map(int, input().split())
    if l * 2 > r:
        print(-1, -1)
    else:
        print(l, l * 2)
```
[1389B - Array Walk](../problems/B._Array_Walk.md "Educational Codeforces Round 92 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1389B - Array Walk](../problems/B._Array_Walk.md "Educational Codeforces Round 92 (Rated for Div. 2)")

Notice that your final position is determined by the number of moves to the left you make. Let there be exactly $t$ moves to the left, that leaves us with $k - t$ moves to the right. However, let's interpret this the other way. You have $t$ pairs of moves (right, left) to insert somewhere inside the sequence of $k - 2t$ moves to the right.

Easy to see that all the positions from $1$ to $k - 2t + 1$ will always be visited. And the extra pairs can also increase the score by visiting some positions ($i+1$, $i$) for some $i$ from $1$ to $k - 2t + 1$.

Notice that it's always optimal to choose exactly the same $i$ for all the pairs (right, left). And that $i$ should be such that $a_{i+1} + a_i$ is maximum possible.

You can implement this idea in a straightforward manner: iterate over $t$ and calculate the sum of values from $1$ to $k - 2t + 1$ and the maximum value of $a_{i+1} + a_i$ over $i$ from $1$ to $k - 2t + 1$.

That will lead to a $O(zn)$ solution per testcase.

You can optimize it to $O(n)$ with prefix sums or with some clever order to iterate over $t$. It's also possible to iterate over the final position and restore the number of left moves required to achieve it.

Overall complexity: $O(zn)$ or $O(n)$ per testcase.

 **Solution 1 (pikmike)**
```cpp
for _ in range(int(input())):
	n, k, z = map(int, input().split())
	a = [int(x) for x in input().split()]
	ans = 0
	s = 0
	mx = 0
	for t in range(z + 1):
		pos = k - 2 * t
		if pos < 0:
			continue
		mx = 0
		s = 0
		for i in range(pos + 1):
			if i < n - 1:
				mx = max(mx, a[i] + a[i + 1])
			s += a[i]
		ans = max(ans, s + mx * t)
	print(ans)
```
 **Solution 2 (pikmike)**
```cpp
for _ in range(int(input())):
	n, k, z = map(int, input().split())
	a = [int(x) for x in input().split()]
	ans = 0
	s = 0
	mx = 0
	for i in range(k + 1):
		if i < n - 1:
			mx = max(mx, a[i] + a[i + 1])
		s += a[i]
		if i % 2 == k % 2:
			tmp = (k - i) // 2
			if tmp <= z:
				ans = max(ans, s + mx * tmp)
	print(ans)
```
[1389C - Good String](../problems/C._Good_String.md "Educational Codeforces Round 92 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1389C - Good String](../problems/C._Good_String.md "Educational Codeforces Round 92 (Rated for Div. 2)")

Let's analyze when the string is good. Suppose it is $t_1t_2 \dots t_k$.

The cyclic shifts of this string are $t_kt_1t_2 \dots t_{k-1}$ and $t_2t_3 \dots t_k t_1$. We get the following constraints for a good string: $t_k = t_2$, $t_1 = t_3$, $t_2 = t_4$, ..., $t_{k - 2} = t_k$, $t_{k - 1} = t_1$. If the string has odd length, then all characters should be equal to each other; otherwise, all characters on odd positions should be equal, and all characters on even positions should be equal.

Now, since there are only $10$ different types of characters, we can brute force all possible combinations of the first and the second character of the string we want to obtain (there are only $100$ of them) and, for each combination, greedily construct the longest possible subsequence of $s$ beginning with those characters in $O(n)$.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)

int solve(const string& s, int x, int y) {
	int res = 0;
	for (auto c : s) if (c - '0' == x) {
		++res;
		swap(x, y);
	}
	if (x != y && res % 2 == 1)
		--res;
	return res;
}

void solve() {
	string s;
	cin >> s;
	int ans = 0;
	forn(x, 10) forn(y, 10)
		ans = max(ans, solve(s, x, y));
	cout << sz(s) - ans << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) solve();
}
```
[1389D - Segment Intersections](../problems/D._Segment_Intersections.md "Educational Codeforces Round 92 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1389D - Segment Intersections](../problems/D._Segment_Intersections.md "Educational Codeforces Round 92 (Rated for Div. 2)")

At first, note that intersection_length of segments $[l_1, r_1]$ and $[l_2, r_2]$ can be calculated as $\min(r_1, r_2) - \max(l_1, l_2)$. If it's negative then segments don't intersect, otherwise it's exactly length of intersection.

Now we have two major cases: do segments $[l_1, r_1]$ and $[l_2, r_2]$ already intersect or not.

If segments intersect then we already have $n \cdot (\min(r_1, r_2) - \max(l_1, l_2))$ as the total intersection. Note, that making both segments equal to $[\min(l_1, l_2), \max(r_1, r_2)]$ in each pair are always optimal since in each step we will increase the total intersection by $1$.

After making all segments equal to $[\min(l_1, l_2), \max(r_1, r_2)]$ we can increase total intersection by $1$ only in two steps: we need to extend both segments in one pair.

In result, we can find not a hard formula to calculate the minimum number of steps: we already have $n \cdot (\min(r_1, r_2) - \max(l_1, l_2))$ of the total intersection, then we can increase it by at most $n \cdot ((\max(r_1, r_2) - \min(l_1, l_2)) - (\min(r_1, r_2) - \max(l_1, l_2)))$ using one step per increase, and then to any number using two steps per increase.

In the case of non-intersecting $[l_1, l_2]$ and $[r_1, r_2]$, we should at first "invest" some number of steps in each pair to make them intersect. So let's iterate over the number of segments to "invest" $cntInv$. We should make $cntInv \cdot (\max(l_1, l_2) - \min(r_1, r_2))$ steps to make segments touch. Now, $cntInv$ segments touch so we can use almost the same formulas for them as in the previous case.

The total complexity is $O(n)$ per test case.

 **Solution (adedalic)**
```cpp
import kotlin.math.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toLong() }
        val (l1, r1) = readLine()!!.split(' ').map { it.toLong() }
        val (l2, r2) = readLine()!!.split(' ').map { it.toLong() }

        var ans = 1e18.toLong()
        if (max(l1, l2) <= min(r1, r2)) {
            val rem = max(0L, k - n * (min(r1, r2) - max(l1, l2)))
            val maxPossible = n * (abs(l1 - l2) + abs(r1 - r2))
            ans = min(rem, maxPossible) + max(0L, rem - maxPossible) * 2
        } else {
            val invest = max(l1, l2) - min(r1, r2)
            for (cntInv in 1..n) {
                var curAns = invest * cntInv
                val maxPossible = (max(r1, r2) - min(l1, l2)) * cntInv
                curAns += min(k, maxPossible) + max(0L, k - maxPossible) * 2
                ans = min(ans, curAns)
            }
        }
        println(ans)
    }
}
```
[1389E - Calendar Ambiguity](../problems/E._Calendar_Ambiguity.md "Educational Codeforces Round 92 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (pikmike)**
```cpp
fun gcd(a: Long, b: Long): Long {
	if (a == 0L) return b
	return gcd(b % a, a)
}

fun main() {
	repeat(readLine()!!.toInt()) {
		val (m, d, w) = readLine()!!.split(' ').map { it.toLong() }
		val w2 = w / gcd(d - 1, w)
		val mn = minOf(m, d)
		var cnt = mn / w2
		println((2 * (mn - w2) - w2 * (cnt - 1)) * cnt / 2)
	}
}
```
[1389F - Bicolored Segments](../problems/F._Bicolored_Segments.md "Educational Codeforces Round 92 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1389F - Bicolored Segments](../problems/F._Bicolored_Segments.md "Educational Codeforces Round 92 (Rated for Div. 2)")

There are two approaches to this problem. Most of the participants of the round got AC by implementing dynamic programming with data structures such as segment tree, but I will describe another solution which is much easier to code.

Let's consider a graph where each vertex represents a segment, and two vertices are connected by an edge if the corresponding segments compose a bad pair.

Since each bad pair is formed by two segments of different colors, the graph is bipartite. The problem asks us to find the maximum independent set, and in bipartite graphs, the size of the independent set is equal to $V - M$, where $V$ is the number of vertices, and $M$ is the size of the maximum matching.

The only thing that's left is finding the maximum matching. Let's use event processing approach to do it: for each segment, create two events "the segment begins" and "the segment ends". While processing the events, maintain the currently existing segments in two sets (grouped by their colors and sorted by the time they end). When a segment ends, let's try to match it with some segment of the opposite color — and it's quite obvious that we should choose a segment with the minimum $r_i$ to form a pair.

Overall, this solution runs in $O(n \log n)$.

 **Solution 1 (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)

typedef pair<int, int> pt;

const int N = 200 * 1000;

int n;
int l[N], r[N], t[N];
set<pt> st[2];

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%d%d%d", &l[i], &r[i], &t[i]), --t[i];
	
	vector<pair<int, pt>> ev;
	forn(i, n) {
		ev.pb(mp(l[i], mp(0, i)));
		ev.pb(mp(r[i], mp(1, i)));
	}

	sort(all(ev));
	
	int ans = 0;
	for (auto it : ev) {
		int i = it.y.y;
		if (it.y.x) {
			int j = t[i];
			int k = j ^ 1;
			if (st[j].count(mp(r[i], i)) && !st[k].empty()) {
				++ans;
				st[k].erase(st[k].begin());
			}
			if (st[j].count(mp(r[i], i))) st[t[i]].erase(mp(r[i], i));
		} else {
			st[t[i]].insert(mp(r[i], i));
		}
	}
	
	printf("%dn", n - ans);
}
```
 **Solution 2 (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)

typedef pair<int, int> pt;

const int INF = 1e9;
const int N = 200 * 1000;

int n;
vector<pt> a[2];

struct segtree {
	int n;
	vector<int> t, ps;
	segtree(int n) : n(n) {
		t.resize(4 * n, -INF);
		ps.resize(4 * n, 0);
	}
	
	void push(int v, int l, int r) {
		if (l + 1 != r) {
			ps[v * 2 + 1] += ps[v];
			ps[v * 2 + 2] += ps[v];
		}
		t[v] += ps[v];
		ps[v] = 0;
	}
	
	void upd(int v, int l, int r, int pos, int val) {
		push(v, l, r);
		if (l + 1 == r) {
			t[v] = val;
			return;
		}
		int m = (l + r) >> 1;
		if (pos < m) upd(v * 2 + 1, l, m, pos, val);
		else upd(v * 2 + 2, m, r, pos, val);
		t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
	}
	
	void add(int v, int l, int r, int L, int R, int val) {
		push(v, l, r);
		if (L >= R) return;
		if (l == L && r == R) {
			ps[v] += val;
			push(v, l, r);
			return;
		}
		int m = (l + r) >> 1;
		add(v * 2 + 1, l, m, L, min(m, R), val);
		add(v * 2 + 2, m, r, max(m, L), R, val);
		t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
	}
	
	int get(int v, int l, int r, int L, int R) {
		push(v, l, r);
		if (L >= R) return -INF;
		if (l == L && r == R) 
			return t[v];
		int m = (l + r) >> 1;
		int r1 = get(v * 2 + 1, l, m, L, min(m, R));
		int r2 = get(v * 2 + 2, m, r, max(m, L), R);
		t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
		return max(r1, r2);
	}
	
	void upd(int pos, int val) {
		return upd(0, 0, n, pos, val);
	}
	
	void add(int l, int r, int val) {
		return add(0, 0, n, l, r, val);
	}
	
	int get(int l, int r) {
		return get(0, 0, n, l, r);
	}
};

int main() {
	scanf("%d", &n);
	forn(i, n) {
		int l, r, t;
		scanf("%d%d%d", &l, &r, &t);
		a[t - 1].pb(mp(r, l));
	}
	
	forn(i, 2) sort(all(a[i]), [](pt a, pt b) {
		if (a.x == b.x) return a.y > b.y;
		return a.x < b.x;
	});
	
	segtree t1(sz(a[0]) + 1), t2(sz(a[1]) + 1);
	t1.upd(0, 0);
	t2.upd(0, 0);
		
	int ans = 0;
	for (int i = 0, j = 0; i + j < n; ) {
		if (i < sz(a[0]) && (j == sz(a[1]) || a[0][i].x <= a[1][j].x)) {
			int pos = upper_bound(all(a[1]), mp(a[0][i].y, -INF)) - a[1].begin() + 1; 
			int cur = t2.get(0, pos) + 1;
			ans = max(ans, cur);
			t1.upd(i + 1, cur);
			t2.add(0, pos, 1);
			++i;
		} else {
			int pos = upper_bound(all(a[0]), mp(a[1][j].y, -INF)) - a[0].begin() + 1; 
			int cur = t1.get(0, pos) + 1;
			ans = max(ans, cur);
			t2.upd(j + 1, cur);
			t1.add(0, pos, 1);
			++j;
		}
	}
	
	printf("%dn", ans);
}
```
[1389G - Directing Edges](../problems/G._Directing_Edges.md "Educational Codeforces Round 92 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1389G - Directing Edges](../problems/G._Directing_Edges.md "Educational Codeforces Round 92 (Rated for Div. 2)")

Suppose we want to calculate the maximum profit for some vertex in $O(n)$. Let's try to find out how it can be done, and then optimize this process so we don't have to run it $n$ times.

First of all, we have to find the bridges and biconnected components in our graph. Why do we need them? Edges in each biconnected component can be directed in such a way that it becomes a strongly connected component, so we don't have to leave these edges undirected (it is never optimal). Furthermore, for each such component, either all vertices are saturated or no vertex is saturated. Let's build a tree where each vertex represents a biconnected component of the original graph, and each edge represents a bridge. We can solve the problem for this tree, and then the answer for some vertex of the original graph is equal to the answer for the biconnected component this vertex belongs to.

Okay, now we have a problem on tree. Let's implement the following dynamic programming solution: root the tree at the vertex we want to find the answer for, and for each vertex, calculate the value of $dp_v$ — the maximum profit we can get for the subtree of vertex $v$, if it should be reachable by all special vertices from its subtree.

Let's analyze how we can calculate these $dp$ values. Suppose we have a vertex $v$ with children $v_1$, $v_2$, ..., $v_d$, we have already calculated the $dp$ values for the children, and we want to calculate $dp_v$. First of all, since the vertex $v$ is going to be saturated, we will get the profit from it, so we initialize $dp_v$ with $c_v$. Then we should decide whether we want to get the profit from the children of vertex $v$. Suppose the edge leading from $v$ to $v_i$ has weight $w_i$. If we want to take the profit from the subtree of $v_i$, we (usually) have to make this edge undirected, so both vertices are saturated, thus we get $dp_{v_i} - w_i$ as profit — or we could leave this edge directed from $v_i$ to $v$, so the vertex $v$ is saturated, and $v_i$ is not, and get $0$ as the profit. But sometimes we can gain the profit from the vertex $v_i$ and its subtree without leaving the edge undirected: if all special vertices belong to the subtree of $v_i$, we can just direct this edge from $v_i$ to $v$, and there is no reason to choose the opposite direction or leave the edge undirected. Similarly, if all special vertices are outside of this subtree, there's no reason to direct the edge from $v_i$ to $v$. So, if one of this conditions is met, we can get the full profit from the subtree of $v_i$ without leaving the edge undirected.

Okay, let's summarize it. We can calculate $dp_v$ as $dp_v = c_v + \sum \limits_{i=1}^{d} f(v_i)$, where $f(v_i)$ is either $dp_{v_i}$ if one of the aforementioned conditions is met (we don't have to leave the edge undirected if we want to saturate both vertices), or $f(v_i) = \max(0, dp_{v_i} - w_i)$ otherwise. Now we have an $O(n^2)$ solution.

Let's optimize it to $O(n)$. Root the tree at vertex $1$ and calculate the dynamic programming as if $1$ is the root. Then, we shall use rerooting technique to recalculate the dynamic programming for all other vertices: we will try each vertex as the root of the tree, and $dp_v$ is the answer for the vertex $v$ if it is the root. The rerooting technique works as follows: let's run DFS from the initial root of the tree, and when we traverse an edge by starting or finishing a recursive call of DFS, we move the root along the edge; so, if we call $DFS(x)$, $x$ is the current root; if it has some child $y$, we move the root to $y$ the same moment when we call $DFS(y)$, and when the call of $DFS(y)$ ends, the root moves back to $x$.

Okay, the only thing that's left is to describe how we move the root. If the current root is $x$, and we want to move it to $y$ (a vertex adjacent to $x$), then we have to change only the values of $dp_x$ and $dp_y$: first of all, since $y$ is no longer a child of $x$, we have to subtract the value that was added to $dp_x$ while we considered vertex $y$; then, we have to make $x$ the child of vertex $y$, so we add the profit we can get from the vertex $x$ to $dp_y$. It can be done in $O(1)$, so our solution runs in $O(n)$, though with a very heavy constant factor.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long li;

const int N = 300043;

bool is_bridge[N];
int w[N];
int c[N];
int v[N];
vector<pair<int, int> > g[N];

vector<pair<int, int> > g2[N];
int comp[N];
li sum[N];
li dp[N];
int cnt[N];
int fup[N];
int tin[N];
int T = 0;
li ans[N];
int v1[N], v2[N];

int n, m, k;

int dfs1(int x, int e)
{
	tin[x] = T++;
	fup[x] = tin[x];
	for(auto p : g[x])
	{
		int y = p.first;
		int i = p.second;
		if(i == e)
			continue;
		if(tin[y] != -1)
			fup[x] = min(fup[x], tin[y]);
		else
		{
			fup[x] = min(fup[x], dfs1(y, i));
			if(fup[y] > tin[x])
				is_bridge[i] = true;
		}
	}
	return fup[x];
}

void dfs2(int x, int cc)
{
	if(comp[x] != -1)
		return;
	comp[x] = cc;
	cnt[cc] += v[x];
	sum[cc] += c[x];
	for(auto y : g[x])
		if(!is_bridge[y.second])
			dfs2(y.first, cc);
}

void process_edge(int x, int y, int m, int weight)
{
	li add_dp = dp[y];
	if(cnt[y] > 0 && cnt[y] < k)
		add_dp = max(0ll, add_dp - weight);
	
	cnt[x] += m * cnt[y];
	dp[x] += m * add_dp;
}

void link(int x, int y, int weight)
{
	process_edge(x, y, 1, weight);
}

void cut(int x, int y, int weight)
{
	process_edge(x, y, -1, weight);
}

void dfs3(int x, int p)
{
    dp[x] = sum[x];
	for(auto e : g2[x])
	{
		int i = e.second;
		int y = e.first;
		if(y == p)
			continue;
		dfs3(y, x);
		link(x, y, w[i]);
	}
}

void dfs4(int x, int p)
{
	ans[x] = dp[x];
	for(auto e : g2[x])
	{
		int i = e.second;
		int y = e.first;
		if(y == p)
			continue;
		cut(x, y, w[i]);
		link(y, x, w[i]);
		dfs4(y, x);
		cut(y, x, w[i]);
		link(x, y, w[i]);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(int  i = 0; i < k; i++)
	{
		int x;
		scanf("%d", &x);
		--x;
		v[x] = 1;
	}
	for(int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for(int i = 0; i < m; i++)
		scanf("%d", &w[i]);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &v1[i], &v2[i]);
		--v1[i];
		--v2[i];
		g[v1[i]].push_back(make_pair(v2[i], i));
		g[v2[i]].push_back(make_pair(v1[i], i));
	}
	
	for(int i = 0; i < n; i++)
	{
		tin[i] = -1;
		comp[i] = -1;
	}
	dfs1(0, -1);
	int cc = 0;
	for(int i = 0; i < n; i++)
		if(comp[i] == -1)
			dfs2(i, cc++);
	for(int i = 0; i < m; i++)
		if(is_bridge[i])
		{
			g2[comp[v1[i]]].push_back(make_pair(comp[v2[i]], i));
			g2[comp[v2[i]]].push_back(make_pair(comp[v1[i]], i));
		}
	dfs3(0, 0);
	dfs4(0, 0);
	for(int i = 0; i < n; i++)
		printf("%lld ", ans[comp[i]]);
	puts("");
}
```
