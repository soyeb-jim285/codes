# Tutorial

[1140A - Detective Book](../problems/A._Detective_Book.md "Educational Codeforces Round 62 (Rated for Div. 2)")

 **Tutorial**
### [1140A - Detective Book](../problems/A._Detective_Book.md "Educational Codeforces Round 62 (Rated for Div. 2)")

Solution is just some implementation: simulate algorithm given in the legend, maintaining maximum over all $a_i$ on prefix and breaking when the maximum becomes smaller than index of the next page.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

inline bool read() {
	if(!(cin >> n))
		return false;
	a.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	return true;
}

inline void solve() {
	int cnt = 0, pos = 0;
	while(pos < n) {
		cnt++;
		int mx = pos;
		while(pos < n && pos <= mx) {
			mx = max(mx, a[pos]);
			pos++;
		}
	}
	cout << cnt << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif	
	if(read()) {
		solve();
	}
	return 0;
}
```
[1140B - Good String](../problems/B._Good_String.md "Educational Codeforces Round 62 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int main(){
	cin >> t;
	for(int tc = 0; tc < t; ++tc){
		cin >> n >> s;
		int res = n - 1;
		for(int i = 0; i < n; ++i)
			if(s[i] == '>' || s[n - 1 - i] == '<')
				res = min(res, i);
		
		cout << res << endl;
	}

	return 0;
}

```
[1140C - Playlist](../problems/C._Playlist.md "Educational Codeforces Round 62 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 300009;

int n, k;
pair<int, int> a[N];

int main() {
	cin >> n >> k;
	
	for(int i = 0; i < n; ++i)
		cin >> a[i].second >> a[i].first;

	sort(a, a + n);
	long long res = 0;
	long long sum = 0;
	set<pair<int, int> > s;
	for(int i = n - 1; i >= 0; --i){
		s.insert(make_pair(a[i].second, i));
		sum += a[i].second;
		while(s.size() > k){
			auto it = s.begin();
			sum -= it->first;
			s.erase(it);
		}

		res = max(res, sum * a[i].first);
	}

	cout << res << endl;
	return 0;
}

```
[1140D - Minimum Triangulation](../problems/D._Minimum_Triangulation.md "Educational Codeforces Round 62 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;

	long long ans = 0;
	for(int id = 2; id < n; id++)
		ans += 1ll * id * (id + 1);
	
	cout << ans << endl;
}
```
[1140E - Palindrome-less Arrays](../problems/E._Palindrome-less_Arrays.md "Educational Codeforces Round 62 (Rated for Div. 2)")

 **Tutorial**
### [1140E - Palindrome-less Arrays](../problems/E._Palindrome-less_Arrays.md "Educational Codeforces Round 62 (Rated for Div. 2)")

At first, "array contains a palindromic subarray of length $\ge 3$" is equivalent to "array contains a palindromic subarray of length $=3$". So we need to calculate number of arrays without palindromes of length $3$. It's equivalent to finding arrays where $a[i] \neq a[i + 2]$ for all appropriate $i$.

Note, that $i$ and $i + 2$ have same parity, so all odd and all even positions in array are independent, and answer is the product of the number of ways to choose numbers for odd positions, and the number of ways to choose numbers for even positions.

In terms of same parity our condition morphs to $a[i] \neq a[i + 1]$ and we need to calculate all ways to replace ($-1$)-s in such way that all pairs of consecutive elements are different.

To calculate it let's look at sequences of consecutive ($-1$)-s. They will look like $a, -1, -1, \dots, -1, b$ with $l$ ($-1$)-s, where $a$ and $b$ are positive (case where $a$ is empty can be considered as $k \cdot (a, -1, \dots, -1, b \text{ with $l - 1$ ($-1$)-s})$, case with empty $b$ is solved the same way).

In the end we need to find a way to calculate the number of those sequences. There are only two fundamental types of sequences: $a, -1, \dots, -1, a$ (same value from both ends) and $a, -1, \dots, -1, b$ ($a \neq b$). Exact values of $a$ and $b$ don't really matter.

Let's find a way to calculate both values (name them $cntSame$ and $cntDiff$) for $l$ consecutive ($-1$)-s in $O(\log{l})$ time. Base values: $cntSame(0) = 0, cntDiff(0) = 1$.

Let's try to choose value of $-1$ in the middle of sequence: if $l \mod 2 = 1$, then we can split sequence in two sequences of length $\lfloor l / 2 \rfloor$ and $cntSame(l) = cntSame(l / 2)^2 + (k - 1) \cdot cntDiff(l / 2)^2$ and $cntDiff(l) = 2 \cdot cntSame(l / 2) \cdot cntDiff(l / 2) + (k - 2) \cdot cntDiff(l / 2)^2$.

If $l \mod 2 = 0$ then just iterate over value of last $-1$, then $cntSame(l) = (k - 1) \cdot cntDiff(l - 1)$ and $cntDiff(l) = cntSame(l - 1) + (k - 2) \cdot cntDiff(l - 1)$.

Resulting complexity is $O(n)$.

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

const int MOD = 998244353;
int norm(int a) {
    while(a >= MOD) a -= MOD;
    while(a < 0) a += MOD;
    return a;
}
int mul(int a, int b) {
    return int(a * 1ll * b % MOD);
}

int n, k;
vector<int> a;

inline bool read() {
    if(!(cin >> n >> k))
        return false;
    a.resize(n);
    fore(i, 0, n)
        cin >> a[i];
    return true;
}

pair<int, int> calc(int len) {
    if(len == 0) return {0, 1};
    if(len & 1) {
        auto res = calc(len >> 1);
        return {norm(mul(res.x, res.x) + mul(k - 1, mul(res.y, res.y))),
                norm(mul(2, mul(res.x, res.y)) + mul(k - 2, mul(res.y, res.y)))};
    }
    auto res = calc(len - 1);
    return {mul(k - 1, res.y), norm(res.x + mul(k - 2, res.y))};
}

vector<int> curArray;

int calcSeg(int l, int r) {
    if(r >= sz(curArray)) {
        int len = r - l - 1, cf = 1;
        if(l < 0)
            len--, cf = k;
        if(len == 0) return cf;

        auto res = calc(len - 1);
        return mul(cf, norm(res.x + mul(k - 1, res.y)));
    }
    if(l < 0) {
        if(r - l == 1) return 1;
        auto res = calc(r - l - 2);
        return norm(res.x + mul(k - 1, res.y));
    }
    auto res = calc(r - l - 1);
    return curArray[l] == curArray[r] ? res.x : res.y;
}

inline void solve() {
    int ans = 1;
    fore(k, 0, 2) {
        curArray.clear();
        for(int i = 0; 2 * i + k < n; i++)
            curArray.push_back(a[2 * i + k]);

        int lst = -1;
        fore(i, 0, sz(curArray)){
            if(curArray[i] == -1) continue;
            ans = mul(ans, calcSeg(lst, i));
            lst = i;
        }
        ans = mul(ans, calcSeg(lst, sz(curArray)));
    }
    cout << ans << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(0);
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
[1140F - Extending Set of Points](../problems/F._Extending_Set_of_Points.md "Educational Codeforces Round 62 (Rated for Div. 2)")

 **Tutorial**
### [1140F - Extending Set of Points](../problems/F._Extending_Set_of_Points.md "Educational Codeforces Round 62 (Rated for Div. 2)")

Let's try to analyze how the size of $E(S)$ can be calculated. Let's connect points having same $x$-coordinates to each other, and do the same for points having same $y$-coordinates. Then we can solve the problem for each component separatedly: after the algorithm is run, the component will contain the points $(X, Y)$ such that at least one point in the component has $x$-coordinate equal to $X$, and at least one point in the component (maybe same, maybe another one) has $y$-coordinate equal to $Y$. So the answer for each component is the product of the number of distinct $x$-coordinates and the number of distinct $y$-coordinates in the component. 

Now we can process insertion queries: there are many ways to do it, but, in my opinion, the easiest way to handle them is to create a separate vertex for every $x$-coordinate and $y$-coordinate, and process each point as an edge connecting vertices corresponding to its coordinates (edges can be easily added by using DSU with rank heuristics).

To handle removals, we will get rid of them completely. Transform the input into a set of $O(q)$ events "some point exists from query $l$ to query $r$". Then build a segment tree over queries, and break each event into $O(\log q)$ segments with this segment tree. Then we can initialize a DSU, and run DFS on the vertices of the segment tree to get answers for all queries. When we enter some node, we add all edges that exist on the corresponding segment into DSU. If we are in a leaf node, we may compute the $E(S)$ for the corresponding query. And when we leave a vertex, we can rollback all changes we made when we entered it. One important moment is that using path compression in DSU here is meaningless since it doesn't work with rollbacks well.

This solution works in $O(q \log^2 q)$.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long li;

#define x first
#define y second

const int N = 300043;
const int K = 300000;

int p[2 * N];
int s1[2 * N];
int s2[2 * N];
li ans = 0;

int* where[80 * N];
int val[80 * N];
int cur = 0;

void change(int& x, int y)
{
	where[cur] = &x;
	val[cur] = x;
	x = y;
	cur++;
}

void rollback()
{
	cur--;
	(*where[cur]) = val[cur];
}

int get(int x)
{
	if(p[x] == x)
		return x;
	return get(p[x]);
}

void merge(int x, int y)
{
	x = get(x);
	y = get(y);
	if(x == y) return;
	ans -= s1[x] * 1ll * s2[x];
	ans -= s1[y] * 1ll * s2[y];
	if(s1[x] + s2[x] < s1[y] + s2[y])
		swap(x, y);
	change(p[y], x);
	change(s1[x], s1[x] + s1[y]);
	change(s2[x], s2[x] + s2[y]);
	ans += s1[x] * 1ll * s2[x];
}

void init()
{
	for(int i = 0; i < K; i++)
	{
		p[i] = i;
		p[i + K] = i + K;
		s1[i] = 1;
		s2[i + K] = 1;
	}
}

vector<pair<int, int> > T[4 * N];

void add(int v, int l, int r, int L, int R, pair<int, int> val)
{
	if(L >= R) return;
	if(L == l && R == r)
		T[v].push_back(val);
	else
	{
		int m = (l + r) / 2;
		add(v * 2 + 1, l, m, L, min(R, m), val);
		add(v * 2 + 2, m, r, max(m, L), R, val);
	}
}

li res[N];

void dfs(int v, int l, int r)
{
	li last_ans = ans;
	int state = cur;
	for(auto x : T[v])
		merge(x.x, x.y + K);
	if(l == r - 1)
		res[l] = ans;
	else
	{
		int m = (l + r) / 2;
		dfs(v * 2 + 1, l, m);
		dfs(v * 2 + 2, m, r);
	}
	while(cur != state) rollback();
	ans = last_ans;
}

int main()
{
	int q;
	scanf("%d", &q);
	map<pair<int, int>, int> last;
	for(int i = 0; i < q; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		pair<int, int> p = make_pair(x, y);
		if(last.count(p))
		{
			add(0, 0, q, last[p], i, p);
			last.erase(p);
		}
		else
			last[p] = i;
	}
	for(auto x : last)
		add(0, 0, q, x.y, q, x.x);
	init();
	dfs(0, 0, q);
	for(int i = 0; i < q; i++)
		printf("%I64d ", res[i]);
}
```
[1140G - Double Tree](../problems/G._Double_Tree.md "Educational Codeforces Round 62 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long li;

#define x first
#define y second

const int N = 600043;

li d1[N];
li d2[N][2];
li dist_temp[N][2];
vector<pair<int, int> > g[N];
vector<int> qs[N];
int qq[N][2];
li ans[N];
int n;
int used[N];
int cnt[N];
int last[N];
int cc = 1;

void preprocess()
{
	set<pair<li, int> > q;
	for(int i = 0; i < n; i++)
		q.insert(make_pair(d1[i], i));
	while(!q.empty())
	{
		int k = q.begin()->second;
		q.erase(q.begin());
		for(auto e : g[k])
		{
			int to = e.first;
			li w = d2[e.second][0] + d2[e.second][1];
			if(d1[to] > w + d1[k])
			{
				q.erase(make_pair(d1[to], to));
				d1[to] = w + d1[k];
				q.insert(make_pair(d1[to], to));
			}
		}
	}
}

void dfs1(int x, int p = -1)
{
	if(used[x]) return;
	cnt[x] = 1;
	for(auto y : g[x])
	{
		int to = y.first;
		if(!used[to] && to != p)
		{
			dfs1(to, x);
			cnt[x] += cnt[to];
		}
	}
}

vector<int> cur_queries;
pair<int, int> c;
int S = 0;

void find_centroid(int x, int p = -1)
{
	if(used[x])	return;
	int mx = 0;
	for(auto y : g[x])
	{
		int to = y.first;
		if(!used[to] && to != p)
		{
			find_centroid(to, x);
			mx = max(mx, cnt[to]);
		}
	}
	if(p != -1)
		mx = max(mx, S - cnt[x]);
	c = min(c, make_pair(mx, x));
}	

void dfs2(int x, int p = -1, int e = -1)
{
	if(used[x]) return;
	if(p == -1)
	{
		dist_temp[x * 2][0] = dist_temp[x * 2 + 1][1] = 0ll;
		dist_temp[x * 2][1] = dist_temp[x * 2 + 1][0] = d1[x];
	}
	else
	{
		for(int k = 0; k < 2; k++)
		{
			li& D0 = dist_temp[x * 2][k];
			li& D1 = dist_temp[x * 2 + 1][k];
			D0 = dist_temp[p * 2][k] + d2[e][0];
			D1 = dist_temp[p * 2 + 1][k] + d2[e][1];
			D0 = min(D0, D1 + d1[x]);
			D1 = min(D1, D0 + d1[x]); 
		}
	}
	for(auto y : qs[x])
	{
		if(ans[y] != -1) continue;
		if(last[y] == cc)
			cur_queries.push_back(y);
		else
			last[y] = cc;
	}
	for(auto y : g[x])
	{
		int to = y.first;
		if(!used[to] && to != p)
			dfs2(to, x, y.second);
	}
}

void centroid(int v)
{
	if(used[v]) return;
	dfs1(v);
	S = cnt[v];
	c = make_pair(int(1e9), -1);
	find_centroid(v);
	int C = c.second;
	used[C] = 1;
	for(auto y : g[C])
		centroid(y.first);
	cc++;
	cur_queries.clear();
	used[C] = 0;
	dfs2(C);
	for(auto x : cur_queries)
	{
		int u = qq[x][0];
		int v = qq[x][1];
		ans[x] = min(dist_temp[u][0] + dist_temp[v][0], dist_temp[u][1] + dist_temp[v][1]);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%I64d", &d1[i]);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		li w1, w2;
		scanf("%d %d %I64d %I64d", &x, &y, &w1, &w2);
		--x;
		--y;
		d2[i][0] = w1;
		d2[i][1] = w2;
		g[x].push_back(make_pair(y, i));
		g[y].push_back(make_pair(x, i));
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		scanf("%d", &qq[i][0]);
		scanf("%d", &qq[i][1]);
		--qq[i][0];
		--qq[i][1];
		qs[qq[i][0] / 2].push_back(i);
		qs[qq[i][1] / 2].push_back(i);
	}
	preprocess();
	for(int i = 0; i < q; i++)
		ans[i] = -1;
	centroid(0);
	for(int i = 0; i < q; i++)
		cout << ans[i] << endl;
}
```
