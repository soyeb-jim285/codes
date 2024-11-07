# Tutorial

[990A - Commentary Boxes](../problems/A._Commentary_Boxes.md "Educational Codeforces Round 45 (Rated for Div. 2)")

 **Tutorial**
### [990A - Commentary Boxes](../problems/A._Commentary_Boxes.md "Educational Codeforces Round 45 (Rated for Div. 2)")

Notice that you need to check just two numbers: the closest one less or equal to nn and the closest one greater than nn. Distances to them are (nmodm)(nmodm) and (m−(nmodm))(m−(nmodm)) respectively. Now you should multiply the first result by bb, the second result by aa and compare the products.

Overall complexity: O(1)O(1).

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++)
 
using namespace std;

int main() {
	long long n, m;
	int a, b;
	
	cin >> n >> m >> a >> b;
	cout << min(n % m * b, (m - n % m) * a) << endl;
	return 0;
}
```
[990B - Micro-World](../problems/B._Micro-World.md "Educational Codeforces Round 45 (Rated for Div. 2)")

 **Tutorial**
### [990B - Micro-World](../problems/B._Micro-World.md "Educational Codeforces Round 45 (Rated for Div. 2)")

It can be proved that the optimal answer equals to a number of bacteria which can't be eaten by any other bacteria. So for each bacteria ii you need to check existence of any bacteria jj satisfying condition ai<aj≤ai+Kai<aj≤ai+K.

There plenty of ways to check this condition. One of them is to sort array aa and for each ii find minimal aj>aiaj>ai with upper_bound or with two-pointers technique. Or you can use the fact that ai≤106ai≤106 and build solution around it.

Result complexity is O(nlogn)O(nlog⁡n).

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 555;
int n, k, a[N];

inline bool read() {
	if(!(cin >> n >> k))
		return false;
	for(int i = 0; i < n; i++)
		assert(scanf("%d", &a[i]) == 1);
	return true;
}

inline void solve() {
	sort(a, a + n);
	a[n++] = int(2e9);
	
	int ans = 0, u = 0;
	for(int i = 0; i < n - 1; i++) {
		while(u < n && a[i] == a[u])
			u++;
		if(a[u] - a[i] > k)
			ans++;
	}
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif

	if(read()) {
		solve();
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
#endif
	}
	return 0;
}
```
[990C - Bracket Sequences Concatenation Problem](../problems/C._Bracket_Sequences_Concatenation_Problem.md "Educational Codeforces Round 45 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 7;

int n;
string s[N];
char buf[N];
int cnt[N];

int getBalance(string &s){
	int bal = 0;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '(')
			++bal;
		else
			--bal;
		
		if(bal < 0)
			return -1;
	}
	
	return bal;
}

string rev(string &s){
	string revs = s;
	reverse(revs.begin(), revs.end());
	for(int i = 0; i < revs.size(); ++i)
		if(revs[i] == '(')
			revs[i] = ')';
		else
			revs[i] = '(';
		
	return revs;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s", buf);
		s[i] = buf;
	}

	for(int i = 0; i < n; ++i){
		int bal = getBalance(s[i]);
		if(bal != -1)
			++cnt[bal];
	}
	
	long long res = 0;	
	for(int i = 0; i < n; ++i){
		s[i] = rev(s[i]);
		int bal = getBalance(s[i]);
		if(bal != -1)
			res += cnt[bal];
	}
	
	printf("%I64dn", res);
	return 0;
}
```
[990D - Graph And Its Complement](../problems/D._Graph_And_Its_Complement.md "Educational Codeforces Round 45 (Rated for Div. 2)")

 **Tutorial**
### [990D - Graph And Its Complement](../problems/D._Graph_And_Its_Complement.md "Educational Codeforces Round 45 (Rated for Div. 2)")

Let's prove that if a>1a>1, then b=1b=1. Let GG be the original graph, and HH — the complement of the graph GG. Let's look at each pair of vertices (u,v)(u,v). If uu and vv belong to different components of the graph GG, then there is an edge between them in the graph HH. Otherwise, uu and vv belong to the same component of the graph GG, but since GG has more than one component, there is vertex xx in other component of GG, and there are edges {u,x}{u,x} and {v,x}{v,x} in HH. That's why, there is a connected path for any pair of vertices (u,v)(u,v), and the graph HH is connected. Similarly, the case b>1b>1 is proved.

So, if min(a,b)>1min(a,b)>1, then the answer is "NO". Otherwise, min(a,b)=1min(a,b)=1. Consider the case where b=1b=1 (if b>ab>a, we can swap aa and bb, and output complement of the constructed graph). To have aa components in the graph GG, it is enough to connect the vertex 11 with the vertex 22, the vertex 22 with the vertex 33, ⋯⋯, the vertex n−an−a with the vertex n−a+1n−a+1. 

A particular cases are the tests n=2,a=1,b=1n=2,a=1,b=1 and n=3,a=1,b=1n=3,a=1,b=1. There is no suitable graph for them.

 **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(1e3) + 7;

int n, a, b;
bool mat[N][N];

int main(){
	scanf("%d %d %d", &n, &a, &b);

	if(min(a, b) > 1){
		puts("NO");
		return 0;
	}
	
	if(a == 1 && b == 1){
		if(n == 2 || n == 3){
			puts("NO");
			return 0;
		}
		puts("YES");
		for(int i = 1; i < n; ++i)
			mat[i][i - 1] = mat[i - 1][i] = true;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j)
				printf("%c", '0' + mat[i][j]);
			puts("");
		}
		return 0;
	}
	
	bool x = false;
	if(a == 1){
		swap(a, b);
		x = true;
	}
	for(int i = n - a; i > 0; --i)
		mat[i][i - 1] = mat[i - 1][i] = true;
	puts("YES");
	for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j)
				printf("%c", '0' + ((x ^ mat[i][j]) && (i != j)));
			puts("");
		}
	return 0;
}
```
[990E - Post Lamps](../problems/E._Post_Lamps.md "Educational Codeforces Round 45 (Rated for Div. 2)")

 **Tutorial**
### [990E - Post Lamps](../problems/E._Post_Lamps.md "Educational Codeforces Round 45 (Rated for Div. 2)")

Let's start with learning how to place lamps of fixed power to cover the segment with the minimal number of them. The following greedy strategy works: find the rightmost non-blocked position that is covered by lamps and place lamp there until either everything is covered or rightmost free position is to the left of the last placed lamp. Initially you only consider 00 to be covered. Function f(i)f(i) — the minimal number of post lamps to cover segment [0;i][0;i] is clearly monotonous, thus you want to update states as early as possible.

Okay, now you iterate over all l∈[1;k]l∈[1;k] and update the answer with the results multiplied by cost.

Now, why will this work fast? You obviously precalculate the rightmost free position for each prefix segment. If there are any free positions to the right of last placed lamp then the rightmost of them will always be the rightmost for the entire prefix segment. Finally, any two consecutive iterations of the algorithm will either move you by k+1k+1 positions or return -1. This can be easily proven by contradiction.

Overall complexity: O(n⋅logn)O(n⋅log⁡n), as you do about nlnl steps for each ll and that is a common series sum.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int INF = 1e9;
const long long INF64 = 1e18;
const int N = 1000 * 1000 + 13;

int n, m, k;
bool pos[N];
int lst[N], s[N], a[N];

int get(int l){
	int r = 0, i = -1, res = 0;
	while (r < n){
		if (lst[r] <= i)
			return INF;
		i = lst[r];
		r = lst[r] + l;
		++res;
	}
	return res;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	forn(i, m) scanf("%d", &s[i]);
	forn(i, k) scanf("%d", &a[i]);
	forn(i, n) pos[i] = true;
	forn(i, m) pos[s[i]] = false;
	forn(i, n){
		if (pos[i])
			lst[i] = i;
		else if (i)
			lst[i] = lst[i - 1];
		else
			lst[i] = -1;
	}
	long long ans = INF64;
	forn(i, k){
		long long t = get(i + 1);
		if (t != INF)
			ans = min(ans, a[i] * t);
	}
	printf("%lldn", ans == INF64 ? -1 : ans);
	return 0;
}
```
[990F - Flow Control](../problems/F._Flow_Control.md "Educational Codeforces Round 45 (Rated for Div. 2)")

 **Tutorial**
### [990F - Flow Control](../problems/F._Flow_Control.md "Educational Codeforces Round 45 (Rated for Div. 2)")

The answer is "Impossible" if and only if the sum of values is not equal to 00. Writing some number on edge does not change the total sum and the goal of the problem is to make 00 in each vertex, thus getting 00 in total.

The algorithm is simple: you get an arbitrary spanning tree (with dfs or dsu), output the difference between sums of values of subtrees (can be calculated with dfs) for edges in this tree and 00 for the rest of edges.

Let's take an arbitrary correct answer. If is has some cycle in graph of edges with non-zero numbers on them, then you can remove it. For example, select any edge on it and subtract the number on it from all the edges of the cycle. This doesn't break the correctness of the answer, as you change both in and out flows for each vertex by the same value. Now that edge has 00. This way, any answer can be transformed to tree. And for any edge on tree we want to tranfer excess water units from the larger subtree to the smaller.

Overall complexity: O(n+m)O(n+m).

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

mt19937 rnd(time(NULL));

const int N = 1'000'013;

int n, m;
pair<int, int> e[N];
int a[N], rk[N];
long long sum[N], ans[N];

int p[N];

int getP(int a){
	return (a == p[a] ? a : p[a] = getP(p[a]));
}

bool merge(int a, int b){
	a = getP(a);
	b = getP(b);
	if (a == b) return false;
	if (rk[a] > rk[b]) swap(a, b);
	p[a] = b;
	rk[b] += rk[a];
	return true;
}

bool used[N];
vector<int> g[N];
int h[N];

void dfs(int v, int p){
	sum[v] = a[v];
	for (auto u : g[v]){
		if (u != p){
			h[u] = h[v] + 1;
			dfs(u, v);
			sum[v] += sum[u];
		}
	}
}

int main() {
	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &a[i]);
	
	forn(i, n) p[i] = i, rk[i] = 1;
	scanf("%d", &m);
	forn(i, m){
		int &v = e[i].first;
		int &u = e[i].second;
		scanf("%d%d", &v, &u);
		--v, --u;
		if (merge(v, u)){
			g[v].push_back(u);
			g[u].push_back(v);
			used[i] = true;
		}
	}
	
	long long tot = 0;
	forn(i, n) tot += a[i];
	if (tot != 0){
		puts("Impossible");
		return 0;
	}
	
	dfs(0, -1);
	
	puts("Possible");
	forn(i, m){
		if (used[i]){
			int v = e[i].first, u = e[i].second;
			if (h[v] < h[u])
				ans[i] = sum[u];
			else
				ans[i] = -sum[v];
		}
		printf("%lldn", ans[i]);
	}
	return 0;
}
```
[990G - GCD Counting](../problems/G._GCD_Counting.md "Educational Codeforces Round 45 (Rated for Div. 2)")

 **Tutorial**
### [990G - GCD Counting](../problems/G._GCD_Counting.md "Educational Codeforces Round 45 (Rated for Div. 2)")

Firstly, for every i∈[1,2⋅105]i∈[1,2⋅105] we can calculate the number of paths such that g(x,y)g(x,y) is divisible by ii. We can do it as follows: generate all divisors of numbers aiai (numbers not exceeding 2⋅1052⋅105 have at most 160160 divisors, so this will be fast enough), and then for every i∈[1,2⋅105]i∈[1,2⋅105] analyze the graph containing the vertices that have ii as its divisor. Each component of this graph gives us k(k+1)2k(k+1)2 paths (if its size is kk), and this is the only formula we need to calculate the number of paths where g(x,y)g(x,y) is divisible by ii (let this be h(i)h(i)).

How can we get the answer if we know the values of h(i)h(i)? We can use inclusion-exclusion with Mobius function, for example, to prove that ans(1)=∑i=12⋅105μ(i)h(i)ans(1)=∑i=12⋅105μ(i)h(i); and then if we want to apply the same technique for finding ans(x)ans(x) with any possible xx, we could divide all numbers aiai by xx and do the same thing. But it might be too slow, so it's better to rewrite this formula as ans(x)=∑i=1⌊2⋅105x⌋μ(i)h(xi)ans(x)=∑i=1⌊2⋅105x⌋μ(i)h(xi), because we will do exactly the same when dividing all numbers by xx.

In fact, most contestants have written a much easier version of this solution, so this might be a bit too complicated.

This problem can also be solved with centroid decomposition.

 **Solution with Möbius (Bleddest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 200043;

int d[N];

void sieve()
{
	vector<int> pr;
 	for(int i = 2; i < N; i++) 
 	{
		if (d[i] == 0) 
		{
			d[i] = i;
			pr.push_back(i);
		}
		for(auto x : pr)
		{
			if (x > d[i] || x * 1ll * i >= N)
				break;
			d[i * x] = x;
		}
	}
}

int mobius(int x)
{
	int last = -1;
	int res = 1;
	while(x != 1)
	{
		if(last == d[x])
			res = 0;
		else
			res = -res;
		last = d[x];
		x /= d[x];
	}
	return res;
}

int mb[N];

vector<int> need_bfs[N];
int used[N];
vector<int> g[N];
int a[N];
int cc = 0;
int q[N];
int hd, tl;
int good[N];

int bfs(int x, int gc)
{
    hd = 0;
    tl = 0;
    q[tl++] = x;
    used[x] = cc;
    while(hd < tl)
    {
        int z = q[hd++];
        for(auto y : g[z])
        {
            if(good[a[y]] == cc && used[y] < cc)
            {
                used[y] = cc;
                q[tl++] = y;
            }
        }
    }
	return tl;
}

long long ans1[N];
long long ans2[N];

int main() {
	sieve();
	for(int i = 1; i < N; i++)
		mb[i] = mobius(i);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 0; i < n; i++)
	{
		need_bfs[a[i]].push_back(i);
	}
	for(int i = 200000; i >= 1; i--)
	{
		cc++;
		for(int j = i; j <= 200000; j += i)
		    good[j] = cc;
		for(int j = i; j <= 200000; j += i)
		    for(auto x : need_bfs[j])
		    {
		        if(used[x] == cc) continue;
			    int z = bfs(x, i);
			    ans1[i] += z * 1ll * (z + 1) / 2;
		    }
	    for(int j = i, k = 1; j <= 200000; j += i, k++)
	        ans2[i] += mb[k] * ans1[j];
	}
	for(int i = 1; i <= 200000; i++)
		if(ans2[i])
			printf("%d %lldn", i, ans2[i]);
	return 0;
}
```
 **Solution with centroid (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream &out, const pair<A, B> &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}

template<class A> ostream& operator <<(ostream &out, const vector<A> &v) {
	out << "[";
	for(auto &e : v)
		out << e << ", ";
	return out << "]";
}

const int N = 1000 * 1000 + 555;
const int LOGN = 21;
int mind[N];
int pw[LOGN][N];

int n, a[N];
vector<int> g[N];
li res[N];

bool gen() {
	mt19937 rnd(42);
	n = 200 * 1000;
	fore(i, 0, n)
		a[i] = 831600;
	fore(i, 1, n) {
		int u = rnd() % i, v = i;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	return true;
}

inline bool read() {
//	return gen();
	if(!(cin >> n))
		return false;
	fore(i, 0, n)
		assert(scanf("%d", &a[i]) == 1);
	fore(i, 0, n - 1) {
		int u, v;
		assert(scanf("%d%d", &u, &v) == 2);
		u--, v--;
		
		g[u].push_back(v);
		g[v].push_back(u);
	}
	return true;
}

vector<pt> dv[N];

inline int gcd(int a, int b) {
	int ans = 1;
	unsigned int u = 0, v = 0;
	while(u < dv[a].size() && v < dv[b].size()) {
		if(dv[a][u].x < dv[b][v].x)
			u++;
		else if(dv[a][u].x > dv[b][v].x)
			v++;
		else {
			ans *= pw[min(dv[a][u].y, dv[b][v].y)][dv[a][u].x];
			u++, v++;
		}
	}
	return ans;
}

bool used[N];
int sz[N];

void calcSz(int v, int p) {
	sz[v] = 1;
	for(int to : g[v]) {
		if(to == p || used[to])
			continue;
		calcSz(to, v);
		sz[v] += sz[to];
	}
}

int findC(int v, int p, int all) {
	for(int to : g[v]) {
		if(to == p || used[to])
			continue;
		if(sz[to] > all / 2)
			return findC(to, v, all);
	}
	return v;
}

int u[N], T = 0;
int cntD[N];

inline void addDiv(int d, int cnt) {
	if(u[d] != T)
		u[d] = T, cntD[d] = 0;
	cntD[d] += cnt;
}

int cds[N], szcds;

void calcDs(int v, int p, int gc) {
	gc = gcd(a[v], gc);
	cds[szcds++] = gc;
	for(int to : g[v]) {
		if(to == p || used[to])
			continue;
		calcDs(to, v, gc);
	}
}

vector<int> cps, cmx, vmx;

void check(int curd, int curg, int pos, int add) {
	if(pos >= (int)cps.size()) {
		if(u[curd] == T)
			res[curg] += cntD[curd] * 1ll * add;
		return;
	}
	
	fore(st, 0, cmx[pos] + 1) {
		check(curd, curg, pos + 1, add);
		
		curd *= cps[pos];
		if(st < vmx[pos])
			curg *= cps[pos];
	}
}

pt ops[N]; int szops;
int cntDiff[N];

void calc(int v) {
	calcSz(v, -1);
	int c = findC(v, -1, sz[v]);
	used[c] = 1;
	
//	cerr << "C = "<< c << endl;
	
	cps.resize(dv[a[c]].size());
	cmx.resize(cps.size());
	vmx.resize(cmx.size());
	
	fore(i, 0, cps.size()) {
		cps[i] = dv[a[c]][i].x;
		cmx[i] = dv[a[c]][i].y;
	}
	
	T++;
	addDiv(a[c], 1);
	
	for(int to : g[c]) {
		if(used[to]) continue;
		
		szcds = 0;
		calcDs(to, c, a[c]);
		fore(i, 0, szcds)
			cntDiff[cds[i]]++;
			
		szops = 0;
		fore(j, 0, szcds) {
			if(cntDiff[cds[j]] == 0)
				continue;
			
			int p = 0, val = cds[j];
			fore(i, 0, vmx.size()) {
				if(p >= (int)dv[val].size() || dv[val][p].x > cps[i])
					vmx[i] = 0;
				else
					vmx[i] = dv[val][p].y, p++;
			}
			
			check(1, 1, 0, cntDiff[cds[j]]);
			ops[szops++] = {cds[j], cntDiff[cds[j]]};
			cntDiff[cds[j]] = 0;
		}
		
		fore(j, 0, szops)
			addDiv(ops[j].x, ops[j].y);
	}
	
	for(int to : g[c]) {
		if(used[to]) continue;
		calc(to);
	}
}

inline void solve() {
	iota(mind, mind + N, 0);
	fore(i, 2, N) {
		if(mind[i] != i)
			continue;
		
		pw[0][i] = 1;
		fore(st, 1, LOGN)
			pw[st][i] = pw[st - 1][i] * i;
		
		for(li j = i * 1ll * i; j < N; j += i)
			mind[j] = min(mind[j], i);
	}
	fore(i, 2, N) {
		int val = i;
		while(mind[val] > 1) {
			if(dv[i].empty() || dv[i].back().x != mind[val])
				dv[i].emplace_back(mind[val], 0);
			dv[i].back().y++;
			val /= mind[val];
		}
	}
	
	memset(res, 0, sizeof res);
	
	T = 0;
	calc(0);
	
	fore(i, 0, n)
		res[a[i]]++;
	
	fore(i, 1, 1000'000 + 1) {
		if(res[i])
			printf("%d %lldn", i, res[i]);
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif

	if(read()) {
		solve();
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
#endif
	}
	return 0;
}
```
