# Tutorial

[1555A - PizzaForces](../problems/A._PizzaForces.md "Educational Codeforces Round 112 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1555A - PizzaForces](../problems/A._PizzaForces.md "Educational Codeforces Round 112 (Rated for Div. 2)")

Note that the "speed" of cooking 1 slice of pizza is the same for all sizes — 1 slice of pizza for 2.5 minutes.

If n is odd, then we will increase it by 1 (since the pizza is cooked only with an even number of pieces). Now the value of n is always even. If n<6, then for such n the answer is equal to the answer for n=6, so we can say that n=max(n,6). While n≥12 we can order a small pizza. Eventually the value of n will be equal to 6, 8 or 10. This means that for any n there will be a set of pizzas with exactly n slices. Then the answer is n∗2.5 (in the solution, it is better to use the formula n/2∗5).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << max(6LL, n + 1) / 2 * 5 << 'n';
  }
}
```
[1555B - Two Tables](../problems/B._Two_Tables.md "Educational Codeforces Round 112 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1555B - Two Tables](../problems/B._Two_Tables.md "Educational Codeforces Round 112 (Rated for Div. 2)")

Firstly, let's notice the next property: if two axis-aligned rectangles don't intersect, then we can draw a vertical or horizontal line between them. In other words, either max(x1,x2)≤min(x3,x4) or max(x3,x4)≤min(x1,x2) if x1 and x2 are coordinates of the one rectangle and x3 and x4 of the other one (analogically, for y coordinates).

Now, suppose you want to move the first table by (dx,dy). Note that if in result they will be divided by vertical line then we can set dy=0 — they still will be divided, but the total distance will decrease. Analogically, if divided by horizontal line, we can set dx=0.

In other words, it's always optimal to move the table either horizontally or vertically.

Let's look at the case of horizontal move: at first, we need to check that both tables can fit in the room, or their total width w+(x2−x1)≤W. If yes, then we calculate the movement distance dx as follows: if we move the table right then there should be at least w to the left of it, or w≤x1+dx ⇔ dx≥w−x1. Since we want to minimize dx then we take dx=max(0,w−x1).

If we want to move the table left, then there should be at least w to the right, or x2−dx≤W−w ⇔ dx≥x2−(W−w), minimizing dx means taking dx=max(0,x2−(W−w)). So, the result is min(max(0,w−x1),max(0,x2−(W−w))).

The vertical case can be handled in the same manner, if h+(y2−y1)≤H then the result is min(max(0,h−y1),max(0,y2−(H−h))).

The answer is the minimum among all possible variants, or −1 if both cases are impossible.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

const int INF = int(1e9);

int W, H;
int x1, y1, x2, y2;
int w, h;

inline bool read() {
	if(!(cin >> W >> H))
		return false;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> w >> h;
	return true;
}

inline void solve() {
	int ans = INF;
	if (x2 - x1 + w <= W) {
		ans = min(ans, max(0, w - x1));
		ans = min(ans, max(0, x2 - (W - w)));
	}
	if (y2 - y1 + h <= H) {
		ans = min(ans, max(0, h - y1));
		ans = min(ans, max(0, y2 - (H - h)));
	}
	if (ans == INF)
		cout << -1 << endl;
	else
		cout << double(ans) << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif	
	cout << fixed << setprecision(9);
	int t; cin >> t;
	while(t--) {
		(read());
		solve();
	}
	return 0;
}
```
[1555C - Coin Rows](../problems/C._Coin_Rows.md "Educational Codeforces Round 112 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1555C - Coin Rows](../problems/C._Coin_Rows.md "Educational Codeforces Round 112 (Rated for Div. 2)")

First, observe that each of the players has only m options for their path — which column to go down in.

Let's consider a Bob's response to a strategy chosen by Alice. The easiest way to approach that is to look at the picture of the Alice's path.

 ![](images/aff054639f51aa0ed9d4671c1bf5a57b15b7fdeb.png) The path clearly separates the field into two independent pieces — suffix of the first row and the prefix of the second row. Bob can't grab the coins from both of them at once. However, he can grab either of them fully. So the optimal path for him will be one of these two options.

You can precalculate some prefix sums and become able to get the Bob's score given the Alice's path. Alice has m possibly paths, so you can iterate over them and choose the minimum answer.

However, prefix sums are not required, since you can quickly recalculate both needed sums while iterating over the Alice's column to go down in.

Overall complexity: O(m) per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int INF = 2e9 + 10;

int main() {
	int t;
	scanf("%d", &t);
	forn(_, t){
		int n;
		scanf("%d", &n);
		vector<vector<int>> a(2, vector<int>(n));
		forn(i, 2) forn(j, n)
			scanf("%d", &a[i][j]);
		int ans = INF;
		int sum1 = 0, sum2 = 0;
		forn(i, n) sum1 += a[0][i];
		forn(i, n){
			sum1 -= a[0][i];
			ans = min(ans, max(sum1, sum2));
			sum2 += a[1][i];
		}
		printf("%dn", ans);
	}
}

```
[1555D - Say No to Palindromes](../problems/D._Say_No_to_Palindromes.md "Educational Codeforces Round 112 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1555D - Say No to Palindromes](../problems/D._Say_No_to_Palindromes.md "Educational Codeforces Round 112 (Rated for Div. 2)")

Note that in the beautiful string si≠si−1 (because it is a palindrome of length 2) and si≠si−2 (because it is a palindrome of length 3). This means si=si−3, i.e. a beautiful string has the form abcabcabc..., up to the permutation of the letters a, b and c.

For each permutation of the letters a, b and c, we will construct a string t, of the form abcabcabc... of length n. Let's define an array a of length n as follows: ai=0 if si=ti (i.e. the character at the i-th position does not need to be changed) and ai=1 otherwise. Let's build an array pr of prefix sums of the array a. Now you can process a query of the number of positions that need to be replaced for the current line t in O(1).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<int>> pr(6, vector<int>(n + 1));
  string t = "abc";
  int cur = 0;
  do {
    for (int i = 0; i < n; ++i)
      pr[cur][i + 1] = pr[cur][i] + (s[i] != t[i % 3]);
    ++cur;
  } while (next_permutation(t.begin(), t.end()));
  while (m--) {
    int l, r;
    cin >> l >> r;
    int ans = n;
    for (int i = 0; i < 6; ++i)
      ans = min(ans, pr[i][r] - pr[i][l - 1]);
    cout << ans << "n";
  }
}

```
[1555E - Boring Segments](../problems/E._Boring_Segments.md "Educational Codeforces Round 112 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh"), [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1555E - Boring Segments](../problems/E._Boring_Segments.md "Educational Codeforces Round 112 (Rated for Div. 2)")

Take a look at the condition for a good subset.

The major implication it makes is that every point (even non-integer) of the segment [1;m] should be covered by at least one segment. If some point isn't, then there is no way to jump across the gap it produces.

At the same time, this condition is enough to have a path, since for every half-integer point (0.5, 1.5 and so on) there exists a segment that covers it. So you can take that segment to go from 1 to 2, then from 2 to 3 and so on.

Thus, we are asked to select a subset of segments that covers the entire segment [1;m] in its union.

The main prerequisite to the following solution is knowing the way to maintain the union of segments. For now, I can tell you that there is a data structure that allows you to add a segment, remove a segment and query the length of the current union.

Let's continue with making some observations on the cost function. 

If you fix the minimum and the maximum value, you are free to select all segments that have their value in-between.

That allows us to transition from selecting a subset of segment to an interval, if you sort the segments by their weight.

If you fix only minimum, then the required maximum should be as small as possible. However, if some value suffices as a maximum, then any value greater than it also suffices (since it only adds extra segments to the subset). This makes the function on the maximum monotonous.

So the binary search applicable. You could iterate over the minimum and binary search the maximum. However, it's not too clear how to make a check function. You would need to find a union of some interval of segments quickly. I don't really know a way to do that, so let's try something different.

Instead, let's forget about binary search and try to reach a two pointers solution. Let f(x) be the smallest possible maximum, given the fixed minimum is x. We want f(x+1) to be greater than or equal than f(x) for two pointers to be applicable.

That condition indeed holds. Imagine if f(x+1) is smaller than f(x). So there exists some optimal subset for x+1. Add all segments with weight x to that subset. That brings the minimum to x. However, it doesn't change the maximum, so f(x) is at least equal to f(x+1), what contradicts the assumption.

Finally, the solution comes up to the following. Iterate over the minimum value x, while maintaining f(x). When going from x to x+1, keep increasing the value of f until the union of the segments is exactly m.

Going from x to x+1 and increasing the value of f is actually removing some segments and adding some segments to the data structure.

The data structure that helps us with that is a segment tree. The i-th leaf of the tree holds the number of segments that cover the interval (i;i+1). Add/remove segment makes it add/subtract on a range. The union is full if the there are no intervals that are covered by zero segments. Thus, let's store the minimum of the subtree in every intermediate node. If the minimum on the tree is above zero, then the current subset is good.

Instead of applying two pointers on the values of the segments, let's apply them on the sorted segments themselves. That makes moving the pointer exactly one update to the segtree.

Overall complexity: O(nlogn+nlogm).

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int INF = 1e9;

vector<int> t, ps;

void push(int v){
	if (v * 2 + 1 < int(ps.size())){
		ps[v * 2] += ps[v];
		ps[v * 2 + 1] += ps[v];
	}
	t[v] += ps[v];
	ps[v] = 0;
}

void upd(int v, int l, int r, int L, int R, int val){
	push(v);
	if (L >= R)
		return;
	if (l == L && r == R){
		ps[v] += val;
		push(v);
		return;
	}
	int m = (l + r) / 2;
	upd(v * 2, l, m, L, min(m, R), val);
	upd(v * 2 + 1, m, r, max(m, L), R, val);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int get(){
	return t[1] + ps[1];
}

struct seg{
	int l, r, w;
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<seg> a(n);
	forn(i, n){
		scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].w);
		--a[i].l, --a[i].r;
	}
	--m;
	sort(a.begin(), a.end(), [](const seg &a, const seg &b){
		return a.w < b.w;
	});
	t.resize(4 * m);
	ps.resize(4 * m);
	int ans = INF;
	int j = 0;
	forn(i, n){
		while (j < n && get() == 0){
			upd(1, 0, m, a[j].l, a[j].r, 1);
			++j;
		}
		if (get() == 0){
			break;
		}
		ans = min(ans, a[j - 1].w - a[i].w);
		upd(1, 0, m, a[i].l, a[i].r, -1);
	}
	printf("%dn", ans);
	return 0;
}

```
[1555F - Good Graph](../problems/F._Good_Graph.md "Educational Codeforces Round 112 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1555F - Good Graph](../problems/F._Good_Graph.md "Educational Codeforces Round 112 (Rated for Div. 2)")

Firstly, let's prove that a good graph has one important property: any two of its simple cycles intersect by at most one vertex, i. e. there is no edge that belongs to more than one simple cycle (cactus definition, yeah).

Let's prove it by showing that if two simple cycles of weight k>0 intersects (by edges) then they will induce a simple cycle of weight ≠k. There are two cases: 

* if cycles intersect by a single path, then we can create a new cycle by merging parts of cycles excluding the intersecting path — it will be simple and will have weight k⊕k=0≠k;
* if cycles intersect by more than one path, we can do the next transformation: suppose the common paths are u1−v1, u2−v2, …, and they are ordered in the way how they lie on the first cycle. Let's create a third cycle using two paths from v1 to u2: from the first cycle and from the second cycle. It's easy to see that the third cycle is simple, and more over it has only one common path with the second cycle. So, it's either the third cycle has weight not equal to k or the case 1.

Okay, let's analyze the edges we try to add. Let's divide all edges in two types: tree edges and all other edges (we will name them cycle edges). Let's name an edge as a tree edge if it connects two different components at a moment when we are trying to add it in the graph.

It's obvious that we will add all tree edges in the graph, since they can't make it bad (since they don't induce new cycles). But there is a more interesting observation: when we try to add a cycle edge (u,v), it should induce an only one simple cycle where all other edges are tree edges and these tree edges can't be used in any other cycle.

It induces at least one "all-tree-edge" cycle, since u and v are already connected. It can't induce more than one "all-tree-edge" cycle, since it contradicts with tree edge definition, and if it induces a cycle with some other cycle edge, then we can replace that cycle edge with its own tree-edge path: our cycle will become "all-tree-edge" cycle, but it will use already used tree edges. In other words, it's enough to consider only one "all-tree-edge" cycle induced by any cycle edge.

The final trick is to calculate the answer in two steps: at the first step, we will find only tree edges (using DSU) that will form a spanning forest in our graph.

The second step is for each cycle edge (u,v) to calculate the XOR X on a path between u and v in our spanning forest, check that X⊕edge_weight=1 and check that none of edges on the path from u to v are used in other cycle.

Calculating X is easy: if we precalculate for each vertex v the XOR on path from v to root xr[v] then X=xr[u]⊕xr[v].

Checking that none of the edges are used on the path from u to v is a bit tricky: if we mark an edge by adding 1 to it, then we should be able to take a sum on path and add on path. There are structures that are capable of it (like HLD and other), but let's look closely.

Note that we mark each tree edge at most once, so we can manually add 1 to each edge, and only asking sum on path should be fast. In other words, we need a data structure (DS) that can add value at edge and take the sum on path — and such DS is a Fenwick tree (BIT) built on Euler tour of tree: it can add value at edge and ask a sum on path from v to root. So we need to find LCA as well, since sum of path (u,v) is equal to sum(u)+sum(v)−2⋅sum(LCA(u,v)).

As a result, complexity is O((n+m)log(n)) with quite a low constant from LCA and BIT.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
	fore(i, 0, sz(v)) {
		if(i) out << " ";
		out << v[i];
	}
	return out;
}

const int INF = int(1e9);
const li INF64 = li(1e18);

int n, q;
vector< array<int, 3> > es;

inline bool read() {
	if(!(cin >> n >> q))
		return false;
	es.resize(q);
	fore (i, 0, q) {
		cin >> es[i][0] >> es[i][1] >> es[i][2];
		es[i][0]--;
		es[i][1]--;
	}
	return true;
}

vector< vector<pt> > g;

const int LOG = 19;
vector<int> up[LOG];
vector<int> tin, tout;
vector<int> xr;
int T = 0;

void dfs(int v, int p, int curXor) {
	tin[v] = T++;
	xr[v] = curXor;
	up[0][v] = p;
	fore (pw, 1, LOG)
		up[pw][v] = up[pw - 1][up[pw - 1][v]];
	
	for (auto [to, w] : g[v]) {
		if (to == p)
			continue;
		dfs(to, v, curXor ^ w);
	}
	tout[v] = T;
}

void buildLCA() {
	fore (pw, 0, LOG)
		up[pw].resize(n);
	tin.assign(n, -1);
	tout.assign(n, -1);
	xr.assign(n, 0);
	
	T = 0;
	fore (v, 0, n) {
		if (tin[v] != -1)
			continue;
		dfs(v, v, 0);
	}
}

int isPar(int p, int v) {
	return tin[p] <= tin[v] && tout[v] <= tout[p];
}

int lca(int u, int v) {
	if (isPar(u, v)) return u;
	if (isPar(v, u)) return v;
	
	for (int pw = LOG - 1; pw >= 0; pw--) {
		if (!isPar(up[pw][v], u))
			v = up[pw][v];
	}
	return up[0][v];
}

vector<int> par, rk;

void init(int n) {
	par.assign(n, 0);
	iota(par.begin(), par.end(), 0);
	rk.assign(n, 1);
}

int top(int v) {
	if (par[v] != v)
		return par[v] = top(par[v]);
	return v;
}

bool unite(int u, int v) {
	u = top(u);
	v = top(v);
	if (u == v)
		return false;
	if (rk[u] < rk[v])
		swap(u, v);
	par[v] = u;
	rk[u] += rk[v];
	return true;
}

vector<int> F;
void inc(int pos, int val) {
	for(; pos < sz(F); pos |= pos + 1)
		F[pos] += val;
}
int sum(int pos) {
	int ans = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		ans += F[pos];
	return ans;
}

void addOnPath(int v, int l) {
	while (v != l) {
		inc(tin[v], 1);
		inc(tout[v], -1);
		v = up[0][v];
	}
}

inline void solve() {
	init(n);
	g.resize(n);
	
	vector<int> ans(q, -1);
	fore (i, 0, q) {
		int u = es[i][0];
		int v = es[i][1];
		int x = es[i][2];
		
		if (unite(u, v)) {
			ans[i] = 1;
			g[u].emplace_back(v, x);
			g[v].emplace_back(u, x);
		}
	}
	
	buildLCA();
	F.assign(2 * n + 5, 0);
	
	fore (i, 0, q) {
		if (ans[i] != -1)
			continue;
		
		ans[i] = 0;
		int u = es[i][0];
		int v = es[i][1];
		int x = es[i][2];
		
		int xorPath = xr[u] ^ xr[v];
		if ((xorPath ^ x) != 1)
			continue;
		
		int l = lca(u, v);
		int usedOnPath = sum(tin[u]) + sum(tin[v]) - 2 * sum(tin[l]);
		if (usedOnPath > 0)
			continue;
		
		ans[i] = 1;
		addOnPath(u, l);
		addOnPath(v, l);
	}
	
	for (int res : ans)
		cout << (res ? "YES" : "NO") << 'n';
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	if(read()) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
