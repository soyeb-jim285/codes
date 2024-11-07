# Tutorial_(en)

[1000A - Codehorses T-shirts](../problems/A._Codehorses_T-shirts.md "Educational Codeforces Round 46 (Rated for Div. 2)")

 **Editorial**
### [1000A - Codehorses T-shirts](../problems/A._Codehorses_T-shirts.md "Educational Codeforces Round 46 (Rated for Div. 2)")

At first, let's remove all coinciding entries of both lists. The most convinient way is to use map/hashmap but it's not the only option. Now divide entries into categories by their length. You can notice that it takes exactly one second to remove an entry in each category (to make it equal to an entry of the opposing list). Thus the answer is $n - (number~of~coinciding~entries)$.

Overall complexity: $O(n \log n)$ or $O(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;


int main() {
	int n;
	cin >> n;
	
	vector<string> a(n), b(n);
	forn(i, n) cin >> a[i];
	forn(i, n) cin >> b[i];
	
	map<string, int> cnta, cntb;
	forn(i, n) ++cnta[a[i]];
	forn(i, n) ++cntb[b[i]];
	
	int ans = n;
	for (auto it : cnta) ans -= min(it.second, cntb[it.first]);
	
	cout << ans << endl;
	return 0;
}
```
[1000B - Light It Up](../problems/B._Light_It_Up.md "Educational Codeforces Round 46 (Rated for Div. 2)")

 **Editorial**
### [1000B - Light It Up](../problems/B._Light_It_Up.md "Educational Codeforces Round 46 (Rated for Div. 2)")

At first, let's insert $0$ and $M$ in array $a$, so all possible positions for inserting will always belong to $(a_i, a_{i + 1})$. 

At second, let $x$ be value to insert and $a_i < x < a_{i + 1}$. It can be proven, that it's always optimal to move $x$ to $a_i$ or to $a_{i + 1}$. So, for each $(a_i, a_{i + 1})$ we need to check only $x = a_i + 1$ and $x = a_{i + 1} - 1$. To check it fast enough, we need to know total time of lamp is lit for each prefix and precalculate for each $i$, total time of lamp is lit if starting from $a_i$ light is on / lights is off.

Result complexity is $O(n)$.

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

int n, M;
vector<int> a;

inline bool read() {
	if(!(cin >> n >> M))
		return false;
	a.assign(n, 0);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	return true;
}

vector<int> f[2];

inline void solve() {
	a.insert(a.begin(), 0);
	a.push_back(M);
	
	f[0].assign(a.size(), 0);
	f[1].assign(a.size(), 0);
	
	for(int i = int(a.size()) - 2; i >= 0; i--) {
		f[0][i] = f[1][i + 1];
		f[1][i] = (a[i + 1] - a[i]) + f[0][i + 1];
	}
	
	int ans = f[1][0];
	for(int i = 0; i + 1 < int(a.size()); i++) {
		if(a[i + 1] - a[i] < 2)
			continue;
		
		int tp = (i & 1) ^ 1;
		int pSum = f[1][0] - f[tp][i];
		ans = max(ans, pSum + (a[i + 1] - a[i] - 1) + f[tp][i + 1]);
	}
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	if(read())
		solve();
	return 0;
}
```
[1000C - Covered Points Count](../problems/C._Covered_Points_Count.md "Educational Codeforces Round 46 (Rated for Div. 2)")

 **Editorial**
### [1000C - Covered Points Count](../problems/C._Covered_Points_Count.md "Educational Codeforces Round 46 (Rated for Div. 2)")

This problem with small coordinates can be solved using partial sums and some easy counting. Let's carry an array $cnt$, where $cnt_i$ will be equal to the number of segments that cover the point with coordinate $i$. How to calculate $cnt$ in $O(n + maxX)$?

For each segment ($l_i, r_i$) let's add $+1$ to $cnt_{l_i}$ and $-1$ to $cnt_{r_i + 1}$. Now build on this array prefix sums and notice that $cnt_i$ equals the number of segments that cover the point with coordinate $i$. Then $ans_i$ will be equal to $\sum\limits_{j = 0}^{maxX} cnt_j = i$. All the answers can be calculated in $O(maxX)$ in total. So the total complexity of this solution is $O(n + maxX)$.

But in our problem it is too slow to build an entire array $cnt$. So what should we do? It is obvious that if any coordinate $j$ is not equals some $l_i$ or some $r_i + 1$ then $cnt_i = cnt_{i - 1}$. So we do not need carry all the positions explicitly. Let's carry all $l_i$ and $r_i + 1$ in some logarithmic data structure or let's use the coordinate compression method.

The coordinate compression method allows us to transform the set of big sparse objects to the set of small compressed objects maintaining the relative order. In our problems let's make the following things: push all $l_i$ and $r_i + 1$ in vector $cval$, sort this vector, keep only unique values and then use the position of elements in vector $cval$ instead of original value (any position can be found in $O(\log n)$ by binary search or standard methods as lower_bound in C++).

So the first part of the solution works in $O(n \log n)$. Answer can be calculated using almost the same approach as in solution to this problem with small coordinates. But now we know that between two adjacent elements $cval_i$ and $cval_{i + 1}$ there is exactly $cval_{i + 1} - cval_{i}$ points with answer equals to $cnt_i$. So if we will iterate over all pairs of the adjacent elements $cval_i$ and $cval_{i + 1}$ and add $cval_{i + 1} - cval_i$ to the $ans_{cnt_i}$, we will calculate all the answers in $O(n)$.

So the total complexity of the solution is $O(n \log n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	scanf("%d", &n);
	vector<pair<long long, long long>> a(n);
	vector<long long> cval;
	for (auto &i : a) {
		scanf("%lld %lld", &i.first, &i.second);
		cval.push_back(i.first);
		cval.push_back(i.second + 1);
		
	}
	sort(cval.begin(), cval.end());
	cval.resize(unique(cval.begin(), cval.end()) - cval.begin());
	
	vector<int> cnt(2 * n);
	for (auto &i : a) {
		int posl = lower_bound(cval.begin(), cval.end(), i.first) - cval.begin();
		int posr = lower_bound(cval.begin(), cval.end(), i.second + 1) - cval.begin();
		++cnt[posl];
		--cnt[posr];
	}
	for (int i = 1; i < 2 * n; ++i)
		cnt[i] += cnt[i - 1];
		
	vector<long long> ans(n + 1);
	for (int i = 1; i < 2 * n; ++i)
		ans[cnt[i - 1]] += cval[i] - cval[i - 1];
	
	for (int i = 1; i <= n; ++i)
		printf("%lld ", ans[i]);
	puts("");
	
	return 0;
}
```
[1000D - Yet Another Problem On a Subsequence](../problems/D._Yet_Another_Problem_On_a_Subsequence.md "Educational Codeforces Round 46 (Rated for Div. 2)")

 **Editorial**
### [1000D - Yet Another Problem On a Subsequence](../problems/D._Yet_Another_Problem_On_a_Subsequence.md "Educational Codeforces Round 46 (Rated for Div. 2)")

The problem is solved by the dynamic programming.

Let $dp_i$ be the answer for the prefix of the array starting at $i$ (it contains the indices $i, i + 1, \dots, n$).

If $a_i \le 0$, then $dp_i = 0$.

Otherwise, let's go over the position $j$, with which the next good array begins. Then we need to select $a_i$ positions among $j-i-1$ positions, which will be elements of the array. The number of ways to choose an unordered set of $k$ items from $n$ of different objects is calculated using the formula $C_n^k = \frac{n!}{K!(N -k)!}$. Thus, the dynamics is as follows:

$dp_i = \sum\limits_{j = i + a_i + 1}^{n + 1} {C_{j - i - 1}^{a_i} \cdot dp_j}$.

The basis of dynamics is the value $dp_{n + 1} = 1$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1009;
const int MOD = 998244353;

int n;
int a[N];
int dp[N];
int C[N][N];

int main() {
	for(int i = 0; i < N; ++i){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	}
	
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	
	dp[n] = 1;
	for(int i = n - 1; i >= 0; --i){
		if(a[i] <= 0) continue;
		
		for(int j = i + a[i] + 1; j <= n; ++j){
				dp[i] += (dp[j] * 1LL * C[j - i - 1][a[i]]) % MOD;
				dp[i] %= MOD;
		}
	}

	int sum = 0;
	for(int i = 0; i < n; ++i){
		sum += dp[i];
		sum %= MOD;
	}
	cout << sum << endl;
	
    return 0;
}
```
[1000E - We Need More Bosses](../problems/E._We_Need_More_Bosses.md "Educational Codeforces Round 46 (Rated for Div. 2)")

 **Editorial**
### [1000E - We Need More Bosses](../problems/E._We_Need_More_Bosses.md "Educational Codeforces Round 46 (Rated for Div. 2)")

It's quite obvious that we can place bosses only on the bridges of the given graph — if an edge is not a bridge, then removing it doesn't make the graph disconnected, so there still exists a path between any pair of vertices. And if we fix two vertices $s$ and $t$, and then find some simple path between them, then we will place the bosses on all bridges belonging to this path (since the set of bridges would stay the same no matter which simple path between $s$ and $t$ we choose).

If we find bridges in the given graph and compress all 2-edge-connected components (two vertices belong to the same 2-edge-connected component iff there exists a path between these vertices such that there are no bridges on this path) into single vertices, we will obtain a special tree called bridge tree. Every edge of a bridge tree corresponds to a bridge in the original graph (and vice versa). Since we want to find the path with maximum possible number of bridges, we only need to find the diameter of the bridge tree, and this will be the answer to the problem.

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 500043;

vector<int> g[N];
vector<int> t[N];
int tin[N], tout[N], fup[N];
int p[N];
int T = 1;
int rnk[N];
vector<pair<int, int> > bridges;
int st;
int d[N];
int n, m;

int get(int x)
{
 	return (p[x] == x ? x : p[x] = get(p[x]));
}

void link(int x, int y)
{
 	x = get(x);
 	y = get(y);
 	if(x == y) return;
 	if(rnk[x] > rnk[y])
 		swap(x, y);
 	p[x] = y;
 	rnk[y] += rnk[x];	
}

int dfs(int x, int par = -1)
{
	tin[x] = T++;
	fup[x] = tin[x];
	for(auto y : g[x])
	{
	 	if(tin[y] > 0)
	 	{
	 		if(par != y)
	 			fup[x] = min(fup[x], tin[y]);
	 	}
	 	else
	 	{
	 	 	int f = dfs(y, x);
	 	 	fup[x] = min(fup[x], f);
	 	 	if(f > tin[x])
	 	 		bridges.push_back(make_pair(x, y));
	 	 	else
	 	 		link(x, y);
	 	}
	}
	tout[x] = T++;                                      
	return fup[x];
}      

void build()
{
 	for(auto z : bridges)
 	{
 	 	int x = get(z.first);
 	 	int y = get(z.second);
 	 	st = x;
 	 	t[x].push_back(y);
 	 	t[y].push_back(x);
 	}
}

pair<int, int> bfs(int x)
{
	for(int i = 0; i < n; i++)
		d[i] = n + 1;
	d[x] = 0;
	queue<int> q;
	q.push(x);
	int last = 0;
	while(!q.empty())
	{
	 	last = q.front();
	 	q.pop();
	 	for(auto y : t[last])
	 		if(d[y] > d[last] + 1)
	 		{
	 		 	d[y] = d[last] + 1;
	 		 	q.push(y);
	 		}
	}
	return make_pair(last, d[last]);
}

int main()
{                
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		rnk[i] = 1, p[i] = i;
	for(int i = 0; i < m; i++)
	{
	 	int x, y;
	 	scanf("%d %d", &x, &y);
	 	--x;
	 	--y;
	 	g[x].push_back(y);
	 	g[y].push_back(x);
	}
	dfs(0);
	build();
	pair<int, int> p1 = bfs(st);
	pair<int, int> p2 = bfs(p1.first);
	printf("%dn", p2.second);
}
```
[1000F - One Occurrence](../problems/F._One_Occurrence.md "Educational Codeforces Round 46 (Rated for Div. 2)")

 **Editorial**
### [1000F - One Occurrence](../problems/F._One_Occurrence.md "Educational Codeforces Round 46 (Rated for Div. 2)")

Suppose all queries have the same right border $r$. Then the answer for the query can be some integer $i$ such that the last occurence of $i$ on the prefix $[1, r]$ of the array is inside the segment, but the second to last occurence is outside the segment (or even does not exist). More formally, let $f(i)$ be the maximum index $j$ such that $j < i$ and $a_j = a_i$ (or $-1$ if there is no such $j$); the answer to the query is some number $a_k$ such that $l \le k \le r$ and $f(k) < l$ (and $k$ is the rightmost occurence of $a_k$ in the segment $[1, r]$). For a fixed right border $r$, we can build a segment tree which for every index $x$ such that $x$ is the rightmost occurence of $a_x$ on $[1, r]$ stores the value of $f(x)$; and if we query minimum on the segment $[l, r]$ in such tree, we can try to find the answer. Let the position of minimum be $m$. If $f(m) < l$, then $a_m$ can be the answer; otherwise there is no answer.

But this is too slow since we can't afford to build a segment tree for every possible value of $r$. There are two methods how to deal with this problem: you may sort all queries by their right borders and maintain the segment tree while shifting the right border (when going from $r$ to $r + 1$, we have to update the values in the positions $f(r + 1)$ and $r + 1$), or we may use a persistent segment tree and get an online solution.

We tried to eliminate solutions using Mo's algorithm, but in fact it's possible to squeeze some implementations of it into TL. There are two optimizations that might help there. When dividing the elements into blocks, we may sort the first block in the ascending order of right borders, the second — in descending, the third — in ascending order again, and so on. And also it's possible to obtain a Mo-based solution with worst case complexity of $O((n + q) \sqrt{n})$ if we maintain the set of possible answers using sqrt decomposition on it.

 **Solution with persistent segment tree**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
const int N = 500001;

typedef pair<int, int> pt;

#define x first
#define y second
#define mp make_pair

struct node
{
 	pt val;
	node* l;
	node* r;
	node() : val(mp(INF, 0)), l(NULL), r(NULL) {};
	node(node* l, node* r) 
	{
	 	this->val = min(l->val, r->val);
		this->l = l;
		this->r = r;
	}
	node(int pos, int val)
	{
	 	this->val = mp(val, pos);
		this->l = NULL;
		this->r = NULL;
	}
};

typedef node* stree;

pt query(stree t, int l, int r, int L, int R)
{
 	if(L >= R)
		return mp(INF, 0);
	if(l == L && r == R)
		return t->val;
	int mid = (l + r) >> 1;
	pt q1 = query(t->l, l, mid, L, min(mid, R));
	pt q2 = query(t->r, mid, r, max(mid, L), R);
	return min(q1, q2);
}

stree update(stree t, int l, int r, int pos, int val)
{
 	if(l == r - 1)
		return new node(pos, val);
	else
	{
	 	int mid = (l + r) >> 1;
		if(pos < mid)
			return new node(update(t->l, l, mid, pos, val), t->r);
		else
			return new node(t->l, update(t->r, mid, r, pos, val));
	}
}

stree build(int l, int r)
{
 	if(l == r - 1)
		return new node(l, INF);
	else
	{
	 	int mid = (l + r) >> 1;
		return new node(build(l, mid), build(mid, r));
	}
}

int main()
{
 	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	vector<int> left(n);
	map<int, int> last;
	for(int i = 0; i < n; i++)
	{
	 	if(!last.count(a[i]))
			left[i] = -1;
		else
			left[i] = last[a[i]];
		last[a[i]] = i;
	}

	vector<stree> T(n + 1);
	T[0] = build(0, n);
	for(int i = 0; i < n; i++)
	{
		stree cur = T[i];
		if(left[i] != -1)
			cur = update(cur, 0, n, left[i], INF);
		cur = update(cur, 0, n, i, left[i]);
		T[i + 1] = cur;	
	}                      
	
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
	 	int l, r;
		scanf("%d %d", &l, &r);
		--l;
		pt ans = query(T[r], 0, n, l, r);
		if(ans.x < l)
			printf("%dn", a[ans.y]);
		else
			printf("0n");
	}
}
```
 **Solution with persistent segment tree (a bit unreadable but runs faster)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
const int N = 500001;

typedef pair<int, int> pt;

#define x first
#define y second
#define mp make_pair

const int M = 60 * N;

pt bufp[M];
int lf[M];
int rg[M];
int szt = 0;

int newnode(pt val)
{
	bufp[szt] = val;
	return szt++;
}

int newnode(int l, int r)
{
 	lf[szt] = l;
	rg[szt] = r;
	if(bufp[l].x < bufp[r].x)
	    bufp[szt] = bufp[l];
	else
	    bufp[szt] = bufp[r];
	return szt++;
}

pt curans;

void query(int t, int l, int r, int L, int R)
{
 	if(L >= R)
		return;
	if(l == L && r == R)
	{
	    if(bufp[t].x < curans.x)
	        curans = bufp[t];
	    return;
	}
	int mid = (l + r) >> 1;
	query(lf[t], l, mid, L, min(mid, R));
	query(rg[t], mid, r, max(mid, L), R);
}

int update(int t, int l, int r, int pos, int val)
{
 	if(l == r - 1)
		return newnode(mp(val, pos));
	else
	{
	 	int mid = (l + r) >> 1;
		if(pos < mid)
			return newnode(update(lf[t], l, mid, pos, val), rg[t]);
		else
			return newnode(lf[t], update(rg[t], mid, r, pos, val));
	}
}

int build(int l, int r)
{
 	if(l == r - 1)
		return newnode(mp(INF, l));
	else
	{
	 	int mid = (l + r) >> 1;
		return newnode(build(l, mid), build(mid, r));
	}
}

int last[N];

int main()
{
 	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	vector<int> left(n);
	for(int i = 0; i < N; i++)
	    last[i] = -1;
	for(int i = 0; i < n; i++)
	{
	 	left[i] = last[a[i]];
		last[a[i]] = i;
	}

	vector<int> T(n + 1);
	T[0] = build(0, n);
	for(int i = 0; i < n; i++)
	{
		int cur = T[i];
		if(left[i] != -1)
			cur = update(cur, 0, n, left[i], INF);
		cur = update(cur, 0, n, i, left[i]);
		T[i + 1] = cur;	
	}                      
	
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
	 	int l, r;
		scanf("%d %d", &l, &r);
		--l;
		curans = mp(INF, 0);
		query(T[r], 0, n, l, r);
		if(curans.x < l)
			printf("%dn", a[curans.y]);
		else
			printf("0n");
	}
}
```
 **Solution with standard segment tree**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define x first
#define y second

const int N = 500 * 1000 + 13;
const int INF = 1e9;

pair<pair<int, int>, int> t[4 * N];

void build(int v, int l, int r){
	if (l == r - 1){
		t[v] = make_pair(make_pair(INF, INF), l);
		return;
	}
	
	int m = (l + r) / 2;
	
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

void update(int v, int l, int r, int pos, int prv, int nxt){
	if (l == r - 1){
		t[v].x = make_pair(nxt, prv);
		return;
	}
	
	int m = (l + r) / 2;
	
	if (pos < m)
		update(v * 2, l, m, pos, prv, nxt);
	else
		update(v * 2 + 1, m, r, pos, prv, nxt);
	
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

pair<pair<int, int>, int> get(int v, int l, int r, int L, int R){
	if (L >= R)
		return make_pair(make_pair(INF, INF), -1);
	
	if (l == L && r == R)
		return t[v];
	
	int m = (l + r) / 2;
	
	return min(get(v * 2, l, m, L, min(m, R)), get(v * 2 + 1, m, r, max(m, L), R));
}

int n, m;
int a[N];
pair<pair<int, int>, int> q[N];
int pos[N];
int ans[N];

bool comp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b){
	return a.x.y < b.x.y;
}

int main() {
	memset(pos, -1, sizeof(pos));
	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i]);
	scanf("%d", &m);
	forn(i, m){
		scanf("%d%d", &q[i].x.x, &q[i].x.y);
		--q[i].x.x, --q[i].x.y;
		q[i].y = i;
	}
	sort(q, q + m, comp);
	
	build(1, 0, n);
	int lst = -1;
	forn(i, m){
		int l = q[i].x.x;
		int r = q[i].x.y;
		
		for (int j = lst + 1; j <= r; ++j){
			if (pos[a[j]] != -1)
				update(1, 0, n, pos[a[j]], -INF, j);
			update(1, 0, n, j, pos[a[j]], -INF);
			pos[a[j]] = j;
		}
		
		auto it = get(1, 0, n, l, r + 1);
		
		if (it.y == -1 || it.x.x != -INF || it.x.y >= l){
			ans[q[i].y] = 0;
		}
		else{
			ans[q[i].y] = a[it.y];
		}
		
		lst = r;
	}
	
	forn(i, m)
		printf("%dn", ans[i]);
	
	return 0;
}
```
 **Mo-based solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define x first
#define y second

const int N = 500 * 1000 + 13;
const int P = 800;
const int INF = 1e9;

bool comp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b){
	int num = a.x.x / P;
	if (num != b.x.x / P)
		return a.x.x < b.x.x;
	if (num & 1)
		return a.x.y < b.x.y;
	return a.x.y > b.x.y;
}

int val[N];
int cnt[N];
int bl[P];
int tot;

inline void add(int x){
	++cnt[x];
	if (cnt[x] == 1){
		++val[x];
		++bl[x / P];
		++tot;
	}
	else if (cnt[x] == 2){
		--val[x];
		--bl[x / P];
		--tot;
	}
}

inline void sub(int x){
	--cnt[x];
	if (cnt[x] == 1){
		++val[x];
		++bl[x / P];
		++tot;
	}
	else if (cnt[x] == 0){
		--val[x];
		--bl[x / P];
		--tot;
	}
}

int get(){
	if (tot == 0) 
		return 0;
	
	forn(i, P){
		if (bl[i] > 0){
			for (int j = i * P;; ++j){
				if (val[j]){
					return j;
				}
			}
		}
	}
	
	assert(false);
}

int n, m;
int a[N], ans[N];
pair<pair<int, int>, int> q[N];

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i]);
	scanf("%d", &m);
	forn(i, m){
		scanf("%d%d", &q[i].x.x, &q[i].x.y);
		--q[i].x.x, --q[i].x.y;
		q[i].y = i;
	}
	sort(q, q + m, comp);
	
	int l = 0, r = -1;
	
	forn(i, m){
		int L = q[i].x.x;
		int R = q[i].x.y;
		
		while (r < R){
			++r;
			add(a[r]);
		}
		
		while (r > R){
			sub(a[r]);
			--r;
		}
		
		while (l > L){
			--l;
			add(a[l]);
		}
		
		while (l < L){
			sub(a[l]);
			++l;
		}
		
		ans[q[i].y] = get();
	}
	
	forn(i, m)
		printf("%dn", ans[i]);
	
	return 0;
}
```
[1000G - Two-Paths](../problems/G._Two-Paths.md "Educational Codeforces Round 46 (Rated for Div. 2)")

 **Editorial**
### [1000G - Two-Paths](../problems/G._Two-Paths.md "Educational Codeforces Round 46 (Rated for Div. 2)")

Let's solve this task in several steps.

Step 1. Calculate $dp_i$ for each vertex.

Let $dp_i$ be maximal profit of some 2-path starting at $i$ and finishing at $i$. If vertex $i$ is a root of the tree, then $dp_i$ equivalent to $d'_i$, where $d'_i$ — maximal profit of 2-path $(i, i)$, when we can go only in subtree of $i$. The $d'_i$ can be calculated with next approach: $d'_v = a_v + \sum\limits_{to \in \text{Children}(v)}{\max(0, d'_{to} - 2 \cdot w(v, to))}$.

To calculate $dp_i$ we can use next technique. Let's manage next invariant: when processing vertex $v$ all its neighbours (even parent) will hold $d'_i$ as if $v$ its parent. Then $dp_v = a_v + \sum\limits_{to \in \text{Neighbours}(v)}{\max(0, d'_{to} - 2 \cdot w(v, to))}$. After that, we can proceed with each child $to$ of $v$, but before moving to it we must change value $d'_v$ since we must keep invariant true. To keep it true, it's enough to set $d'_v = dp_v - \max(0, d'_{to} - 2 \cdot w(v, to))$. Also let's memorize value $\max(0, d'_{to} - 2 \cdot w(v, to))$ as $dto(v, to)$.

Step 2. Processing queries.

Let simple path $(qu, qv)$ be $qu \rightarrow p_1 \rightarrow p_2 \rightarrow \dots \rightarrow p_k \rightarrow qv$. If $qu = qv$ then answer is $dp_{qu}$. Otherwise, each edge on this simple path must be used exactly once. But, while travelling from $qu$ to $qv$ using this simple path, at each vertex $v$ we can go somewhere and return to $v$ — the only condition is not use edges from simple path. And we can do it using precalculated values $dp_i$ and $dto(v, to)$. So, if we want to find max profit of 2-path $(v, v)$ with prohibited edges $(v, to_1)$, $(v, to_2)$, so we can use value $dp_v - dto(v, to_1) - dto(v, to_2)$.

Finally, to process queries, let's find $l = lca(qu, qv)$, divide it on two queries $(qu, l)$, $(qv, l)$. Now we can handle all queries offline, travelling on tree in dfs order. Let's manage some data structure on current path from current vertex to the root (this DS can be based on array of depths). Then, when we come to vertex $v$, just add value $dp_v - dto(v, \text{parent}(v))$ to DS in position $\text{depth}(v)$ (and erase it before exit). Each query $(v, l)$ becomes a query of sum to some subsegment in DS (don't forget carefully handle value in lca). And, before moving from $v$ to $to$, you need subtract $dto(v, to)$ from current value of $v$ (here you can at once subtract weight of edge $(v, to)$). Don't forget to return each change in DS, when it needed.

As we can see, DS is just a BIT with sum on segment and change in position.

Result complexity is $O((n + m) \log{n})$. Fast IO are welcome.

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}

template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
	out << "[";
	fore(i, 0, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

const int M = 400 * 1000 + 555;
const int N = 300 * 1000 + 555;
const int LOGN = 19;

int n, m, a[N];
vector<pt> g[N];

inline bool read() {
	if(!(cin >> n >> m))
		return false;
	fore(i, 0, n)
		assert(scanf("%d", &a[i]) == 1);
	fore(i, 0, n - 1) {
		int u, v, w;
		assert(scanf("%d%d%d", &u, &v, &w) == 3);
		u--, v--;
		
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	fore(i, 0, n)
		sort(all(g[i]));
	return true;
}

int tin[N], tout[N], T = 0;
int p[N][LOGN];

int h[N];
li d1[N];

void calc1(int v, int pr) {
	tin[v] = T++;
	p[v][0] = pr;
	fore(st, 1, LOGN)
		p[v][st] = p[p[v][st - 1]][st - 1];
	
	d1[v] = a[v];
	fore(i, 0, sz(g[v])) {
		int to = g[v][i].x;
		int w = g[v][i].y;
		
		if(to == pr)
			continue;

		h[to] = h[v] + 1;
		calc1(to, v);
		d1[v] += max(0ll, d1[to] - 2ll * w);
	}
	tout[v] = T++;
}

li dp[N];
vector<li> dto[N];

void calcRRT(int v) {
	dp[v] = a[v];
	dto[v].assign(sz(g[v]), 0ll);
	
	fore(i, 0, sz(g[v])) {
		int to = g[v][i].x;
		int w = g[v][i].y;
		
		li curVal = max(0ll, d1[to] - 2ll * w);
		dp[v] += curVal;
		dto[v][i] = curVal;
	}
	
	fore(i, 0, sz(g[v])) {
		int to = g[v][i].x;
		if(h[to] < h[v])
			continue;
		
		li tmp = d1[v];
		d1[v] = dp[v] - dto[v][i];
		calcRRT(to);
		d1[v] = tmp;
	}
}

inline bool isP(int l, int v) {
	return tin[l] <= tin[v] && tout[v] <= tout[l];
}

int lca(int u, int v) {
	if(isP(u, v)) return u;
	if(isP(v, u)) return v;
	
	for(int st = LOGN - 1; st >= 0; st--)
		if(!isP(p[v][st], u))
			v = p[v][st];
	return p[v][0];
}


li getDto(int v, int to) {
	int pos = int(lower_bound(all(g[v]), pt(to, -1)) - g[v].begin());
	if(pos >= sz(g[v]) || g[v][pos].x != to)
		return 0;
	return dto[v][pos];
}

li f[N];

inline void inc(int pos, li val) {
	for(; pos < N; pos |= pos + 1)
		f[pos] += val;
}

inline li sum(int pos) {
	li ans = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		ans += f[pos];
	return ans;
}

inline li getSum(int l, int r) {
	return sum(r) - sum(l);
}

li ans[M];
vector<pt> qs[N];

void calcAns(int v) {
	li vAdd = dp[v] - getDto(v, p[v][0]);
	inc(h[v], vAdd);
	
	for(pt &q : qs[v]) {
		int up = q.x, id = q.y;
		ans[id] += getSum(h[up] - 1, h[v]) + getDto(up, p[up][0]);
	}
	
	fore(i, 0, sz(g[v])) {
		int to = g[v][i].x;
		int w = g[v][i].y;
		if(h[to] < h[v])
			continue;
		
		li curSub = dto[v][i] + w;
		inc(h[v], -curSub);
		
		calcAns(to);
		inc(h[v], +curSub);
	}
	inc(h[v], -vAdd);
}

inline void solve() {
	T = 0;
	h[0] = 0;
	calc1(0, 0);
	calcRRT(0);
	
	fore(i, 0, m) {
		int u, v;
		assert(scanf("%d%d", &u, &v) == 2);
		u--, v--;
		
		int l = lca(u, v);		
		ans[i] = -dp[l];
		
		qs[u].emplace_back(l, i);
		qs[v].emplace_back(l, i);
	}
	
	calcAns(0);
	fore(i, 0, m)
		printf("%lldn", ans[i]);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
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
