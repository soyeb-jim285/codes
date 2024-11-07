# Tutorial

[1082A - Vasya and Book](../problems/A._Vasya_and_Book.md "Educational Codeforces Round 55 (Rated for Div. 2)")

 **Tutorial**
### [1082A - Vasya and Book](../problems/A._Vasya_and_Book.md "Educational Codeforces Round 55 (Rated for Div. 2)")

It is easy to understand that the optimal answer is achieved in one of three cases: 

1. Vasya is trying to visit page $y$ without visiting pages $1$ and $n$;
2. Vasya first goes to the page $1$, and then to the page $y$;
3. Vasya first goes to the $n$ page, and then to the $y$ page.

In the first case, Vasya can go directly to the $y$ page from the $x$ page if $|x-y|$ is divided by $d$.

In the second case, Vasya can get to page $y$ through page $1$, if $y - 1$ is divided by $d$. The required number of actions will be equal to $\lceil \frac{x - 1}{d} \rceil + \frac{y - 1}{d}$.

Similarly, in the third case, Vasya can go to the page $y$ through the page $n$ if $n - y$ is divided by $d$. The required number of actions will be equal to $\lceil\frac{n - x}{d} \rceil + \frac{n - y}{d}$.

If none of the three options described above is appropriate, then there is no answer.

 **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = int(2e9) + 99;

int n, x, y, d;

int dist(int x, int y){
	return (abs(x - y) + (d - 1)) / d;
}

int main() {
	
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
    	cin >> n >> x >> y >> d;
    	
    	int len = abs(x - y);
    	int res = INF;
    	
    	if(len % d == 0) 
    		res = min(res, dist(x, y));
    	
    	len = y - 1;
    	if(len % d == 0)
    		res = min(res, dist(x, 1) + dist(1, y));
    	
    	len = n - y;
    	if(len % d == 0)
    		res = min(res, dist(x, n) + dist(n, y));
    		
    	if(res == INF)
    		res = -1;
    	
    	cout << res << endl;
	}
	
	return 0;
}
```
[1082B - Vova and Trophies](../problems/B._Vova_and_Trophies.md "Educational Codeforces Round 55 (Rated for Div. 2)")

 **Tutorial**
### [1082B - Vova and Trophies](../problems/B._Vova_and_Trophies.md "Educational Codeforces Round 55 (Rated for Div. 2)")

Let $r_i$ be the maximal segment of gold cups that begins in the cup $i$. Let $l_i$ be the maximum segment of gold cups that ends in the cup $i$. Also, let the total number of gold cups be $cntG$.

Note that it makes no sense to change the cups of the same color. Then let's consider the silver cup, which will change with the gold cup, let its number be $i$. Then if $r_{i + 1} + l_{i - 1} < cntG$, then we will update the answer with the value $r_{i + 1} + l_{i - 1} + 1$, and otherwise with the value $r_{i + 1} + l_{i - 1}$. This will not work if all the cups are golden. In this case, the answer is $n$.

 **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
	
	cin >> n >> s;
	
	vector <int> l(n), r(n);
	for(int i = 0; i < n; ++i){
		if(s[i] == 'G'){
			l[i] = 1;
			if(i > 0) l[i] += l[i - 1];
		}
	}
	for(int i = n - 1; i >= 0; --i){
		if(s[i] == 'G'){
			r[i] = 1;
			if(i + 1 < n) r[i] += r[i + 1];
		}
	}
	
	
	int res = 0;
	int cntG = 0;
	for(int i = 0; i < n; ++i)
			cntG += s[i] == 'G';
			
	for(int i = 0; i < n; ++i){
		if(s[i] == 'G') continue;
		int nres = 1;
		if(i > 0) nres += l[i - 1];
		if(i + 1 < n) nres += r[i + 1];
		res = max(res, nres);
	}
	
	res = min(res, cntG);
	if(cntG == n) res = cntG;
	cout << res << endl;
	return 0;
}
```
[1082C - Multi-Subject Competition](../problems/C._Multi-Subject_Competition.md "Educational Codeforces Round 55 (Rated for Div. 2)")

 **Tutorial**
### [1082C - Multi-Subject Competition](../problems/C._Multi-Subject_Competition.md "Educational Codeforces Round 55 (Rated for Div. 2)")

At first, it's optimal to take candidates with maximal levels for a fixed subject.

At second, if we fix number of participants in each subject for some delegation, then it's always optimal to choose all subjects with positive sum of levels.

It leads us to a following solution. Let's divide all candidates by it's $s_i$ and sort each group in non-increasing order.

In result we can just iterate over all prefix sums for each group and update global answer of current length with current sum if it has a positive value.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

int n, m;
vector<int> s, r;

inline bool read() {
	if(!(cin >> n >> m))
		return false;
	s.assign(n, 0);
	r.assign(n, 0);
	
	fore(i, 0, n) {
		assert(cin >> s[i] >> r[i]);
		s[i]--;
	}
	return true;
}

vector< vector<int> > subs;

inline void solve() {
	subs.assign(m + 1, vector<int>());
	
	fore(i, 0, n)
		subs[s[i]].push_back(r[i]);
		
	fore(id, 0, sz(subs)) {
		sort(subs[id].begin(), subs[id].end());
		reverse(subs[id].begin(), subs[id].end());
	}
	
	vector<int> mx(n + 5, 0);
	fore(id, 0, sz(subs)) {
		int curSum = 0;
		fore(i, 0, sz(subs[id])) {
			curSum += subs[id][i];
			if(curSum < 0)
				break;
				
			mx[i + 1] += curSum;
		}
	}
	
	cout << *max_element(mx.begin(), mx.end()) << endl;
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
[1082D - Maximum Diameter Graph](../problems/D._Maximum_Diameter_Graph.md "Educational Codeforces Round 55 (Rated for Div. 2)")

 **Tutorial**
### [1082D - Maximum Diameter Graph](../problems/D._Maximum_Diameter_Graph.md "Educational Codeforces Round 55 (Rated for Div. 2)")

Let's construct the graph the following manner. Take all the vertices with $a_i > 1$ and build a bamboo out of them. Surely, all but the end ones will have degree $2$, the diameter now is the number of vertices minus 1.

One can show that building the graph any other way won't make the diameter greater.

How should we distribute the other vertices? Two of them can be used to increase diameter. And all the others won't matter, they can be paired with any of the vertices with degrees to spare. If no loops are added then the diameter won't change — the path that was the longest won't become any shorter.

All those facts imply that the graph should be a tree and the sum of $a_i$ should be at least $2n - 2$.

Overall complexity: $O(n)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 1000 + 7;

int n;
int a[N];

int main() {
	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &a[i]);
	
	int sum = 0;
	forn(i, n)
		sum += a[i];
	
	if (sum < 2 * n - 2){
		puts("NO");
		return 0;
	}
	
	vector<int> ones;
	forn(i, n) if (a[i] == 1){
		a[i] = 0;
		ones.push_back(i);
	}
	
	int t = ones.size();
	int dm = (n - t) - 1 + min(2, t);
	printf("YES %dn%dn", dm, n - 1);
	
	int lst = -1;
	if (!ones.empty()){
		lst = ones.back();
		ones.pop_back();
	}
	
	forn(i, n){
		if (a[i] > 1){
			if (lst != -1){
				--a[lst];
				--a[i];
				printf("%d %dn", lst + 1, i + 1);
			}
			lst = i;
		}
	}
	
	for (int i = n - 1; i >= 0; --i){
		while (!ones.empty() && a[i] > 0){
			--a[i];
			printf("%d %dn", i + 1, ones.back() + 1);
			ones.pop_back();
		}
	}
	return 0;
}
```
[1082E - Increasing Frequency](../problems/E._Increasing_Frequency.md "Educational Codeforces Round 55 (Rated for Div. 2)")

 **Tutorial**
### [1082E - Increasing Frequency](../problems/E._Increasing_Frequency.md "Educational Codeforces Round 55 (Rated for Div. 2)")

Let $cnt(l, r, x)$ be a number of occurrences of number $x$ in subsegment $[l, r]$.

The given task is equivalent to choosing $[l, r]$ and value $d$ such that $ans = cnt(1, l - 1, c) + cnt(l, r, d) + cnt(r + 1, n, c)$ is maximum possible. But with some transformations $ans = cnt(1, n, c) + (cnt(l, r, d) - cnt(l, r, c))$ so we need to maximize $cnt(l, r, d) - cnt(l, r, c)$.

Key observation is the next: if we fix some value $d$ then we can shrink each segment between consecutive occurrences of $d$ in one element with weight equal to $-cnt(l_i, r_i, c)$. Then we need just to find subsegment with maximal sum — the standard task which can be solved in $O(cnt(1, n, d))$.

Finally, total complexity is $\sum\limits_{d}{O(cnt(1, n, d))} = O(n)$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

const int INF = int(1e9);

int n, c;
vector<int> a;

inline bool read() {
	if(!(cin >> n >> c))
		return false;
	a.assign(n, 0);
	fore(i, 0, n)
		assert(scanf("%d", &a[i]) == 1);
	return true;
}

vector<int> cntC;

int getCnt(int l, int r) {
	return cntC[r] - cntC[l];
}

vector< vector<int> > segs;
vector<int> lst;

int maxSegment(const vector<int> &s) {
	int mx = -INF;
	
	int bal = 0;
	fore(i, 0, sz(s)) {
		bal = max(0, bal + s[i]);
		mx = max(mx, bal);
	}
	return mx;
}

inline void solve() {
	cntC.assign(n + 1, 0);
	fore(i, 0, n)
		cntC[i + 1] = cntC[i] + (a[i] == c);
	
	int cntDif = *max_element(a.begin(), a.end()) + 1;
	segs.assign(cntDif, vector<int>());
	lst.assign(cntDif, -1);
	
	fore(i, 0, n) {
		segs[a[i]].push_back(-getCnt(lst[a[i]] + 1, i));
		lst[a[i]] = i;
		segs[a[i]].push_back(1);
	}
	fore(v, 0, cntDif)
		segs[v].push_back(-getCnt(lst[v] + 1, n));
		
	int ans = 0;
	fore(v, 0, cntDif) {
		if(v == c) continue;
		ans = max(ans, maxSegment(segs[v]));
	}
	
	cout << getCnt(0, n) + ans << endl;
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
[1082F - Speed Dial](../problems/F._Speed_Dial.md "Educational Codeforces Round 55 (Rated for Div. 2)")

 **Tutorial**
### [1082F - Speed Dial](../problems/F._Speed_Dial.md "Educational Codeforces Round 55 (Rated for Div. 2)")

The first thing to come to one's mind is dynamic programming on a trie. The most naive of the solutions take $O(S \cdot n^2 \cdot k^2)$, where $S$ is the total length of strings.

I'll introduce the faster approach.

Let $dp[x][rem][k]$ be the solution for subtree of the vertex $x$ with $rem$ buttons remaining and $k$ is the closest ancestor vertex with the button used in it.

This dp will be recalced via the other dp.

Let $dp2[x][rem][k][m]$ be the same thing as $dp[x][rem][k]$ but only $m$ first children of $x$ is taken into consideration and $x$ doesn't have a button in it.

Give $z$ buttons to the current child, then update $dp2[x][rem][k][m]$ with $dp[m-th child of x][z][k][m]$ + $dp2[x][rem - z][k][m + 1]$.

$dp[x][rem][k]$ will then have two options: $dp[x][rem - 1][x]$ for $x$ having button in it and $dp2[x][rem][k][0]$ for $x$ not having button in it.

$dp[x][rem][k]$ has $O(1)$ transitions and $O(len^2 \cdot p)$ states.

$dp2[x][rem][k][m]$ has $O(k)$ total transitions and also $O(len^2 \cdot p)$ states.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 500 + 7;
const int M = 11;
const int INF = 1e9;

struct node{
	int nxt[10];
	int cnt;
	node(){
		memset(nxt, -1, sizeof(nxt));
		cnt = 0;
	}
};

node trie[N];
int cnt;
int h[N];

void add(string s, int m){
	int cur = 0;
	forn(i, s.size()){
		int c = s[i] - '0';
		if (trie[cur].nxt[c] == -1){
			trie[cur].nxt[c] = cnt;
			h[cnt] = h[cur] + 1;
			++cnt;
		}
		cur = trie[cur].nxt[c];
	}
	trie[cur].cnt += m;
}

int n, k;

int dp[N][M][N];
int dp2[N][M][N][M];

int calc(int x, int rem, int k){
	if (dp[x][rem][k] != -1)
		return dp[x][rem][k];
	
	vector<int> ch;
	forn(i, 10) if (trie[x].nxt[i] != -1)
		ch.push_back(trie[x].nxt[i]);
	
	dp[x][rem][k] = INF;
	if (rem > 0)
		dp[x][rem][k] = min(dp[x][rem][k], calc(x, rem - 1, x));
	
	dp2[x][rem][k][ch.size()] = 0;
	for (int i = int(ch.size()) - 1; i >= 0; --i) forn(z, rem + 1)
		dp2[x][rem][k][i] = min(dp2[x][rem][k][i], calc(ch[i], z, k) + dp2[x][rem - z][k][i + 1]);
	
	dp[x][rem][k] = min(dp[x][rem][k], dp2[x][rem][k][0] + (h[x] - h[k]) * trie[x].cnt);
	
	return dp[x][rem][k];
}

int main() {
	trie[0] = node();
	cnt = 1;
	
	cin >> n >> k;
	forn(i, n){
		string s;
		int m;
		cin >> s >> m;
		add(s, m);
	}
	
	memset(dp, -1, sizeof(dp));
	
	forn(i, N) forn(j, M) forn(l, N) forn(t, M)
		dp2[i][j][l][t] = INF;
	
	int ans = calc(0, k, 0);
	
	cout << ans << endl;
	return 0;
}
```
[1082G - Petya and Graph](../problems/G._Petya_and_Graph.md "Educational Codeforces Round 55 (Rated for Div. 2)")

 **Tutorial**
### [1082G - Petya and Graph](../problems/G._Petya_and_Graph.md "Educational Codeforces Round 55 (Rated for Div. 2)")

This problem can be reduced to one of well-known flow problems: "Projects and Instruments". In this problem, we have a set of projects we can do, each with its cost, and a set of instruments (each also having some cost). Each project depends on some instruments, and each instrument can be used any number of times. We have to choose a subset of projects and a subset of instruments so that if a project is chosen, all instruments that this project depends on are also chosen, and we have to maximize the difference between the sum of costs of chosen projects and the sum of costs of chosen instruments.

The problem about projects and instruments can be solved with the following flow network:

* for each project, create a vertex and add a directed edge from the source to this vertex with capacity equal to the cost of this project;
* for each instrument, create a vertex and add a directed edge from this vertex to the sink with capacity equal to the cost of this instrument;
* for each project, create edges with infinite capacity from the vertex denoting this project to all vertices denoting the required instruments for this project.

Let's analyze an $(S, T)$ cut between the source and the sink in this vertex, and construct some answer based on this cut as follows: if a project-vertex belongs to $S$, then we take this project; if an instrument-vertex belongs to $S$, then we take this instrument; all other projects and instruments are discarded. If an edge between some project and some instrument is cut, then it means that the answer is incorrect (we try to take a project requiring some instrument we don't take), and the cut value is infinite. Otherwise, the value of the cut is equal to the total cost of taken instruments and discarded projects, and we need to minimize it. So the minimum cut in this network denotes the best answer.

Reducing the given problem to this problem is easy: edges of the given graph are "projects", vertices of the given graph are "instruments".

Regarding implementation, any flow algorithm using capacity scaling should be sufficient. It seems that Dinic also passes, even though its complexity is $O(n^2 m)$.

 **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long li;

const int N = 2009;
const int INF = int(1e9) + 777;

struct edge{
	int to, f, c;
	edge () {}
	edge (int to, int f, int c) : to(to), f(f), c(c) {}
};

int n, m;
int s, t;
vector<edge> edges;
vector <int> g[N];
int u[N], cu;

void addEdge(int v, int to, int cap){

	g[v].push_back(edges.size());
	edges.push_back(edge(to, 0, cap));

	g[to].push_back(edges.size());
	edges.push_back(edge(v, 0, 0));
}

int dfs(int v, int need){
	if(v == t) return need;
	u[v] = cu;
	for(auto to : g[v]){
		edge &e = edges[to];
		if(u[e.to] != cu && e.c - e.f >= need){
			int add = dfs(e.to, need);
			if(add > 0){
				edges[to].f += add;
				edges[to ^ 1].f -= add;
				return add;
			}
		}
	}
	return 0;
}

li enlarge(int k){
	li res = 0;
	while(true){
		++cu;
		int add = dfs(s, k);
		res += add;
		if(add == 0) break;
	}
	return res;
}

li maxFlow(){
	li flow = 0;
	for(int k = (1 << 29); k > 0; k >>= 1){
		flow += enlarge(k);
	}
	return flow;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int nn, mm;
	cin >> nn >> mm;
	n = nn + mm + 5;
	m = nn + mm + mm + mm + 5;
	s = n - 1, t = n - 2;
	
	for(int i = 0; i < nn; ++i){
		int a;
		cin >> a;
		addEdge(i + mm, t, a);
	}

	li sum = 0;
	for(int i = 0; i < mm; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		sum += w;
		
		addEdge(s, i, w);
		addEdge(i, u + mm, INF);
		addEdge(i, v + mm, INF);
	}
	
	li fl = maxFlow();
	cout << sum - fl << endl;
	
	return 0;
}
```
