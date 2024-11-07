# Tutorial

[1606A - AB Balance](../problems/A._AB_Balance.md "Educational Codeforces Round 116 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1606A - AB Balance](../problems/A._AB_Balance.md "Educational Codeforces Round 116 (Rated for Div. 2)")

Let's look at the first and the last characters of s. Note that if s1=sn (where n=|s|), then AB(s) is always equal to BA(s). 

It can be proved, for example, by induction: if s consists of equal characters then AB(s)=BA(s)=0; if s has a structure like abb...ba (or baa...ab) then AB(s)=BA(s)=1.

Otherwise, there is at least one character si in the middle that equal to s1 and sn. So we can split string s in s[1..i] and s[i..n]. Both these string has AB=BA (by induction), so our string s also has AB(s)=BA(s).

As a result, if s1=sn then the answer is 0, and we print the string untouched. Otherwise, we replace either s1 or sn and get the desired string.

(It also can be proved that if s1≠sn then AB(s)≠BA(s))

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        println(s.last() + s.substring(1))
    }
}
```
[1606B - Update Files](../problems/B._Update_Files.md "Educational Codeforces Round 116 (Rated for Div. 2)")

 **Tutorial**
### [1606B - Update Files](../problems/B._Update_Files.md "Educational Codeforces Round 116 (Rated for Div. 2)")

Let $cur$ be the current number of computers with the update already installed (initially it is $1$). Then, in $1$ hour, we can increase $cur$ by $\min(cur, k)$. From here we can see that the value of $cur$ will double for the first few hours, and then, when it becomes greater than $k$, it will begin to increase by exactly $k$.

The process when the number of computers doubles can be modeled using a loop, because the number of doublings does not exceed $\log{n}$. And after that, we have to increase the answer by $\left\lceil {\frac{n - cur}{k}} \right\rceil$ to take the number of additions of $k$ into account.

Note that computing $\left\lceil {\frac{n - cur}{k}} \right\rceil$ should be done without using fractional data types; to calculate $\left\lceil {\frac{x}{y}} \right\rceil$ in integers, you should divide $x + y - 1$ by $y$ using integer division (this will work provided that both $x$ and $y$ are non-negative, and $y \ne 0$). If you use real numbers, this may cause precision issues.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  int t;
  cin >> t;
  while (t--) {
    li n, k;
    cin >> n >> k;
    li ans = 0, cur = 1;
    while (cur < k) {
      cur *= 2;
      ++ans;
    }
    if (cur < n) ans += (n - cur + k - 1) / k;
    cout << ans << 'n';
  }
}
```
[1606C - Banknotes](../problems/C._Banknotes.md "Educational Codeforces Round 116 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1606C - Banknotes](../problems/C._Banknotes.md "Educational Codeforces Round 116 (Rated for Div. 2)")

First of all, let's find out how to calculate $f(s)$. This can be done greedily, let's iterate from the higher denominations to the lower ones, the number of banknotes of $i$-th type is equal to $\left\lfloor {\frac{s}{10^{a_i}}} \right\rfloor$ (the value of $s$ here changes to reflect that we have already taken some banknotes; that is, we subtract $\left\lfloor {\frac{s}{10^{a_i}}} \right\rfloor \cdot 10^{a_i}$ from $s$ each time, which is the same as taking $s$ modulo $10^{a_i}$). We can see that after we process the $i$-th type of banknotes, the condition $s < 10^{a_i}$ holds, which means that the number of banknotes of $i$-th type does not exceed $\frac{10^{a_{i + 1}}}{10^{a_i}} - 1$ (except in the case of $i = n$).

Now we can find the minimum number $s$ such that $f(s) > k$. Let $\mathit{lft}$ be the number of banknotes that still remains to take, initially equal to $k+1$ (because we want $f(s)$ to be at least $k + 1$). Let's iterate from the lower denominations to the highest ones, the number of banknotes of $i$-th type we take should be equal to $\min(\mathit{lft}, \frac{10^{a_{i + 1}}}{10^{a_i}} - 1)$ — the minimum of how many we need to take and how many we are allowed to take, so as not to break the minimality of the function $f$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    k += 1;
    vector<int> a(n);
    for (int& x : a) {
      cin >> x;
      int cur = 1;
      while (x--) cur *= 10;
      x = cur;
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
      int cnt = k;
      if (i + 1 < n) cnt = min(cnt, a[i + 1] / a[i] - 1);
      res += a[i] * 1LL * cnt;
      k -= cnt;
    }
    cout << res << 'n';
  }
} 
```
[1606D - Red-Blue Matrix](../problems/D._Red-Blue_Matrix.md "Educational Codeforces Round 116 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1606D - Red-Blue Matrix](../problems/D._Red-Blue_Matrix.md "Educational Codeforces Round 116 (Rated for Div. 2)")

Imagine you fixed some cut and then colored one row red. Which rows can now be colored red or blue so that the condition on the left matrix is satisfied? If the row has at least one number greater or equal than the numbers in the red row, then the row must be red. Otherwise, it can be either red or blue.

However, imagine a weaker condition. Let's look only at the first cell in each row. Sort the rows by the first cell in them. Similarly, if a row is colored red, all the rows that are further in the sorted order should also be red, because they already have a greater or equal number in them.

It implies that after you sort the rows, the only possible colorings are: color some prefix of the rows in blue and the remaining suffix in red.

So there are $n$ possible colorings and $m$ possible cuts. If we learn to check if they are perfect in $O(1)$, we can get the solution in $O(nm)$.

Turns out, the condition "all numbers in the submatrix should be greater than all numbers in the other submatrix" is the same as "the minimum in the first submatrix should be greater than the maximum in the second submatrix".

Thus, you can first precalculate prefix and suffix minimums and maximums and check a coloring and a cut in $O(1)$.

Overall complexity: $O(n \log n + nm)$ per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int INF = 1e9;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--){
		int n, m;
		scanf("%d%d", &n, &m);
		vector<vector<int>> a(n, vector<int>(m));
		forn(i, n) forn(j, m) scanf("%d", &a[i][j]);
		vector<int> ord(n);
		iota(ord.begin(), ord.end(), 0);
		sort(ord.begin(), ord.end(), [&a](int x, int y){ return a[x][0] > a[y][0]; });
		vector<vector<int>> mxl(n, vector<int>(m, -INF));
		vector<vector<int>> mnr(n, vector<int>(m, INF));
		for (int i = n - 1; i >= 0; --i) forn(j, m){
			mxl[i][j] = a[ord[i]][j];
			if (i < n - 1) mxl[i][j] = max(mxl[i][j], mxl[i + 1][j]);
			if (j > 0) mxl[i][j] = max(mxl[i][j], mxl[i][j - 1]);
		}
		for (int i = n - 1; i >= 0; --i) for (int j = m - 1; j >= 0; --j){
			mnr[i][j] = a[ord[i]][j];
			if (i < n - 1) mnr[i][j] = min(mnr[i][j], mnr[i + 1][j]);
			if (j < m - 1) mnr[i][j] = min(mnr[i][j], mnr[i][j + 1]);
		}
		vector<int> mnl(m, INF), mxr(m, -INF);
		pair<int, int> ans(-1, -1);
		forn(i, n - 1){
			forn(j, m){
				mnl[j] = min(mnl[j], a[ord[i]][j]);
				if (j > 0) mnl[j] = min(mnl[j], mnl[j - 1]);
			}
			for (int j = m - 1; j >= 0; --j){
				mxr[j] = max(mxr[j], a[ord[i]][j]);
				if (j < m - 1) mxr[j] = max(mxr[j], mxr[j + 1]);
			}
			forn(j, m - 1) if (mnl[j] > mxl[i + 1][j] && mxr[j + 1] < mnr[i + 1][j + 1]){
				ans = {i, j};
			}
		}
		if (ans.first == -1){
			puts("NO");
			continue;
		}
		puts("YES");
		string res(n, '.');
		forn(i, n) res[ord[i]] = i <= ans.first ? 'R' : 'B';
		printf("%s %dn", res.c_str(), ans.second + 1);
	}
	return 0;
}
```
[1606E - Arena](../problems/E._Arena.md "Educational Codeforces Round 116 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1606E - Arena](../problems/E._Arena.md "Educational Codeforces Round 116 (Rated for Div. 2)")

Let's calculate the following dynamic programming $dp_{i, j}$ — the number of ways to choose the initial health if there are $i$ heroes still alive, and they already received $j$ damage. Let's iterate over $k$ — the number of heroes that will survive after the next round. Then we have to make a transition to the state $dp_{k, nj}$, where $nj = \min(x, j + i - 1)$ (the minimum of the maximum allowed health and $j$ plus the damage done in this round). It remains to understand with what coefficient we should make this transition in dynamic programming. This coefficient is equal to $\binom{i}{i - k} \cdot (nj - j)^{i - k}$ — the number of ways to choose which of the $i$ living heroes will die in this round multiplied by the number of ways to choose health for these $i - k$ heroes (because their health is greater than $j$ so that they are still alive at the moment, but not more than $nj$ so that they are guaranteed to die in this round). Of course, we don't make any transitions from the states $dp_{i,j}$ where $i < 2$, since they represent the fights that have already finished.

The answer is the sum of all $dp_{0, j}$ for every $j \in [0, x]$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int MOD = 998244353;

int n, x;
int c[N][N], dp[N][N];

int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

int main() {
  cin >> n >> x;
  for (int i = 0; i <= n; ++i) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; ++j) 
      c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
  }
  dp[n][0] = 1;
  for (int i = n; i > 1; i--) {
    for (int j = 0; j < x; ++j) {
      if (!dp[i][j]) continue;
      int pw = 1, nj = min(x, j + i - 1);
      for (int k = i; k >= 0; k--) {
        dp[k][nj] = add(dp[k][nj], mul(dp[i][j], mul(c[i][k], pw)));
        pw = mul(pw, nj - j);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= x; ++i)
    ans = add(ans, dp[0][i]);
  cout << ans << endl;
} 
```
[1606F - Tree Queries](../problems/F._Tree_Queries.md "Educational Codeforces Round 116 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1606F - Tree Queries](../problems/F._Tree_Queries.md "Educational Codeforces Round 116 (Rated for Div. 2)")

A naive solution to this problem would be to implement a recursive function which answers each query: let $f(v, k)$ be the answer to the query "$v$ $k$", we can calculate it as $\sum\limits_{u \in children(v)} \max(1, f(u, k) - k)$, since for each child $u$ of vertex $v$, we either delete it and change the score by $f(u, k) - k$, or choose to let it remain, and this increases the score by $1$. Unfortunately, it is too slow.

Let's try to optimize it. First of all, $f(v, k-1) \ge f(v, k)$ since if we choose the exact same subset of vertices to delete for the query "$v$ $k-1$" as we've chosen for the query "$v$ $k$", our score won't decrease. Using this fact, we can show that if it's optimal to remove some vertex in the query "$v$ $k$", it's also optimal to remove a vertex in the query "$v$ $k-1$" because it's optimal to remove vertex $u$ if $f(u, k) - k > 1$, and if this condition holds for some value of $k$, then it holds for each smaller value of $k$.

Let $opt(u)$ be the maximum value of $k$ when it's optimal to remove the vertex $u$. We will calculate these values for all vertices of the tree using an event processing method: we'll process the values of $k$ from $200000$ to $0$ and use a set or a priority queue to store events of the form "at the value $i$, vertex $u$ becomes optimal to delete". This set/priority queue should sort the events in descending order of the value of $k$, and in case of ties, in descending order of depths of the vertices (to make sure that vertices with the same value of $opt(u)$ are processed from bottom to up). 

Let's analyze the implementation of this process more in detail. For each vertex, we will store two values — the number of vertices we should remove from its subtree, and the number of children this vertex will optimally have. Using these two values, we can easily calculate the value of $opt$ for a vertex. When a vertex is "removed" (that is, the event corresponding to this vertex is processed), these values for this vertex should be added to its current parent (we can use DSU to find the current parent easily, for example; and don't forget that the number of vertices we have to remove for this new parent also increases by $1$); then we recalculate the value of $opt$ for the current parent and change the event corresponding to this current parent (note that the value of $opt$ for the current parent shouldn't be greater than the value of $opt$ for the vertex we've deleted).

Okay, this allows us to calculate when it's optimal to delete each vertex. But how do we answer queries? One of the ways to do this is to process queries in the same event processing algorithm (and for every value of $k$, we first "remove" the vertices $u$ with $opt(u) = k$, then process the queries). There is an issue that when we remove a vertex, it can affect the answer not only for its current parent, but also for the vertices that could be its parents, but are already deleted; to handle this, instead of adding the values of the deleted vertex only to the values of its current parent, we perform an addition on the whole path from the vertex to the current parent (excluding the vertex itself). This path addition can be performed with a Fenwick or Segment tree over the Eulerian tour of the tree, and this yields a compexity of $O(n \log n)$, though with a high constant factor. 

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

struct Vertex
{
 	int cost;
 	int depth;
 	int idx;
 	Vertex() {};
 	Vertex(int cost, int depth, int idx) : cost(cost), depth(depth), idx(idx) {};
};

bool operator <(const Vertex& a, const Vertex& b)
{
 	if(a.cost != b.cost)
 		return a.cost > b.cost;
 	if(a.depth != b.depth)
 		return a.depth > b.depth;
 	return a.idx < b.idx;
}

struct DSU
{
	int n;
 	vector<int> p;
 	vector<int> top;

 	int get(int x)
 	{
 		if(p[x] == x)
 			return x;
 		return p[x] = get(p[x]); 	
 	}

 	int get_top(int x)
 	{
 	 	return top[get(x)];
 	}

 	void merge(int x, int par)
 	{
 	 	p[x] = par;
 	}

 	DSU(int k = 0)
 	{
 	 	n = k;
 	 	p.resize(n);
 	 	iota(p.begin(), p.end(), 0);
 	 	top = p;
 	};
};

const int N = 200043;

int n;
vector<int> g[N];
int p[N], d[N], tin[N], tout[N];
int qv[N];
int qk[N];
int T = 0;

void dfs(int v = 0, int par = -1)
{
 	tin[v] = T++;
 	p[v] = par;
 	if(par == -1)
 		d[v] = 0;
 	else
 		d[v] = d[par] + 1;
 	for(auto x : g[v])
 		if(x != par)
 			dfs(x, v);
 	tout[v] = T;
}

pair<long long, long long> tree[4 * N];

pair<long long, long long> operator+(const pair<long long, long long>& a, const pair<long long, long long>& b)
{
 	return make_pair(a.first + b.first, a.second + b.second);
}

pair<long long, long long> get(int v, int l, int r, int L, int R)
{
 	if(L >= R) return {0, 0};
 	if(l == L && r == R) return tree[v];
 	int m = (l + r) / 2;
 	return get(v * 2 + 1, l, m, L, min(R, m)) + get(v * 2 + 2, m, r, max(m, L), R);
}

void add(int v, int l, int r, int pos, pair<long long, long long> val)
{
 	if(l == r - 1)
 		tree[v] = tree[v] + val;
 	else
 	{
 	 	int m = (l + r) / 2;
 	 	if(pos < m) add(v * 2 + 1, l, m, pos, val);
 	 	else add(v * 2 + 2, m, r, pos, val);
 	 	tree[v] = tree[v] + val;
 	}                                                                  
}

pair<long long, long long> get_vertex_value(int v)
{
 	return get(0, 0, n, tin[v], tout[v]);
}

void add_on_path(int x, int y, pair<long long, long long> val)
{
 	// x is a descendant of y
 	add(0, 0, n, tin[x], val);
 	if(p[y] != -1)
 		add(0, 0, n, tin[p[y]], make_pair(-val.first, -val.second));
}

int calculate_cost(int v, int correction)
{
	//cerr << v << " " << correction << endl;
 	pair<long long, long long> res = get_vertex_value(v);
 	// first - (second + 1) * k <= 0
 	long long k = (res.first + res.second) / (res.second + 1) - 1;
 	if(correction < k) return correction;
 	return k;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
	 	int x, y;
	 	scanf("%d %d", &x, &y);
	 	--x;
	 	--y;
	 	g[x].push_back(y);
	 	g[y].push_back(x);
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
	 	scanf("%d %d", &qv[i], &qk[i]);
	 	--qv[i];
	}                   

	dfs();
	DSU dsu(n);
                        
	vector<long long> ans(q);
	set<Vertex> pq;
	vector<Vertex> curv(n);
	for(int i = 0; i < n; i++)
	{                     
	 	int count_children = g[i].size();
	 	if(i != 0) count_children--;               
	 	add_on_path(i, i, make_pair((long long)(count_children), 0ll)); 
	 	if(i != 0)
	 	{
	 		curv[i] = Vertex(calculate_cost(i, 200000), d[i], i);
			pq.insert(curv[i]);                                   
	 	}
                          
	}
                        
	for(int i = 0; i < q; i++)
		pq.insert(Vertex(qk[i], -1, i));

	while(!pq.empty())
	{
		Vertex z = *pq.begin();
		pq.erase(pq.begin());
		if(z.depth == -1)
		{
		 	auto res = get_vertex_value(qv[z.idx]);
		 	ans[z.idx] = res.first - res.second * z.cost;
	    }
	    else
	    {
	     	int v = z.idx;
	     	int pv = p[v];
	     	int newtop = dsu.get_top(pv);
	     	pair<long long, long long> val = get_vertex_value(v);
	     	val.second++;
	     	val.first--;
	     	if(newtop != 0)
	     		pq.erase(curv[newtop]);
	     	add_on_path(pv, newtop, val);
	     	if(newtop != 0)
	     		curv[newtop].cost = calculate_cost(newtop, z.cost);
	     	if(newtop != 0)
	     		pq.insert(curv[newtop]);
	     	dsu.merge(v, pv);
	    }
	}	

	for(int i = 0; i < q; i++)
		printf("%lldn", ans[i]);
}
```
