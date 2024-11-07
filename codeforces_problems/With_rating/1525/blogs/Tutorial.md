# Tutorial

[1525A - Potion-making](../problems/A._Potion-making.md "Educational Codeforces Round 109 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1525A - Potion-making](../problems/A._Potion-making.md "Educational Codeforces Round 109 (Rated for Div. 2)")

Since you need $e$ liters of essence to be exactly $k\ \%$ of potion then we can write an equality: $\frac{e}{e + w} = \frac{k}{100}$ or $k = x \cdot e$ and $100 = x \cdot (e + w)$ for some integer $x$. Since we need to minimize $e + w$ and $x(e + w) = 100$, then we should maximize $x$, but both $k$ and $100$ should be divisible by $x$. In other words, taking $x$ as Greatest Common Divisor of $k$ and $100$ is optimal.

As a result $e + w = \frac{100}{x} = \frac{100}{\gcd(k, 100)}$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int k; cin >> k;
		cout << 100 / gcd(100, k) << endl;
	}
	return 0;
}

```
[1525B - Permutation Sort](../problems/B._Permutation_Sort.md "Educational Codeforces Round 109 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1525B - Permutation Sort](../problems/B._Permutation_Sort.md "Educational Codeforces Round 109 (Rated for Div. 2)")

To solve the problem, it is enough to consider several cases:

* if the array is already sorted, the answer is 0;
* if a[1]=1 (or a[n]=n), then you can sort the array in one operation by selecting the subarray [1,n−1] (or [2,n]);
* if a[1]=n and a[n]=1, you can perform the sequence of operations [1,n−1], [2,n] and [1,n−1] and sort the array on each of them (you can't do it faster since you can't move both n to position n and 1 to position 1 in only 2 operations);
* otherwise, the array can be sorted in 2 operations.
 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int &x : a) scanf("%d", &x);
    int ans = 2;
    if (is_sorted(a.begin(), a.end()))
      ans = 0;
    else if (a[0] == 1 || a[n - 1] == n)
      ans = 1;
    else if (a[0] == n && a[n - 1] == 1)
      ans = 3;
    printf("%dn", ans);
  }
}

```
[1525C - Robot Collisions](../problems/C._Robot_Collisions.md "Educational Codeforces Round 109 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1525C - Robot Collisions](../problems/C._Robot_Collisions.md "Educational Codeforces Round 109 (Rated for Div. 2)")

Notice that the robots that start at even coordinates can never collide with the robots that start at odd coordinates. You can see that if a robot starts at an even coordinate, it'll be at an even coordinate on an even second and at an odd coordinate on an odd second.

Thus, we'll solve the even and the odd cases separately.

Sort the robots by their starting coordinate. Apparently, that step was an inconvenience for some of you. There is a common trick that can help you to implement that. Create a separate array of integer indices 1,2,…,n and sort them with a comparator that looks up the value by indices provided to tell the order. This gives you the order of elements and doesn't require you to modify the original data in any way.

Consider the task without reflections of the wall. Take a look at the first robot. If it goes to the left, then nothing ever happens to it. Otherwise, remember that it goes to the right. Look at the next one. If it goes to the left, then it can collide with the first one if that went to the right. Otherwise, remember that it also goes to the right. Now for the third one. If this one goes to the left, who does it collide with? Obviously, the rightmost alive robot that goes to the right.

So the idea is to keep a stack of the alive robots. If a robot goes to the left, then check if the stack is empty. If it isn't, then the top of the stack robot is the one who will collide with it. Pop it from the stack, since it explodes. If a robot goes to the right, simply push it to the stack. The time of the collision is just the distance between the robots divided by 2.

If there are robots left in the stack after every robot is processed, then they all go to the right together, so they never collide.

What changes when the reflections are introduced?

Almost nothing, actually. Well, now if the stack is empty and a robot goes to the left, then it behaves as a one going to the right. You can reflect the part of the way from its start to the wall. Just say that instead of starting at some x going to the left, it starts at −x going to the right. Since there's no one alive to the left of him initially, that will change nothing. That −x should be used for computing the collision time.

However, the final robots in the stack also act differently. First, the top of the stack robots reflects off the wall and collides with the second on the stack one. Then the third and the fourth and so on. So you can pop them in pairs until 0 or 1 are left.

The coordinate reflection trick can be used here as well. Imagine that the top of the stack starts at m+(m−x) and goes to the left instead of starting in x going to the right. For the same reason it changes nothing.

Overall complexity: O(nlogn).

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct bot{
	int x, d;
};

int main() {
	int t;
	cin >> t;
	forn(_, t){
		int n, m;
		scanf("%d%d", &n, &m);
		vector<bot> a(n);
		forn(i, n) scanf("%d", &a[i].x);
		forn(i, n){
			char c;
			scanf(" %c", &c);
			a[i].d = c == 'L' ? -1 : 1;
		}
		vector<int> ord(n);
		iota(ord.begin(), ord.end(), 0);
		sort(ord.begin(), ord.end(), [&a](int x, int y){
			return a[x].x < a[y].x;
		});
		vector<int> ans(n, -1);
		vector<vector<int>> par(2);
		for (int i : ord){
			int p = a[i].x % 2;
			if (a[i].d == -1){
				if (par[p].empty())
					par[p].push_back(i);
				else{
					int j = par[p].back();
					par[p].pop_back();
					ans[i] = ans[j] = (a[i].x - (a[j].d == 1 ? a[j].x : -a[j].x)) / 2;
				}
			}
			else{
				par[p].push_back(i);
			}
		}
		forn(p, 2){
			while (int(par[p].size()) > 1){
				int i = par[p].back();
				par[p].pop_back();
				int j = par[p].back();
				par[p].pop_back();
				ans[i] = ans[j] = (2 * m - a[i].x - (a[j].d == 1 ? a[j].x : -a[j].x)) / 2;
			}
		}
		forn(i, n){
			printf("%d ", ans[i]);
		}
		puts("");
	}
	return 0;
}

```
[1525D - Armchairs](../problems/D._Armchairs.md "Educational Codeforces Round 109 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1525D - Armchairs](../problems/D._Armchairs.md "Educational Codeforces Round 109 (Rated for Div. 2)")

Let's say that the starting position of people are $x_1, x_2, \dots, x_k$ (in sorted order) and ending positions of people are $y_1, y_2, \dots, y_k$ (also in sorted order). It's always optimal to match these starting and ending positions in sorted order: the leftmost starting position is matched with the leftmost ending, the second starting position is matched with the second ending, and so on. To prove it, suppose that position $X_1$ is matched with $Y_2$, position $X_2$ is matched with $Y_1$, $X_1 \le X_2$ and $Y_1 \le Y_2$. If both persons go to the left or to the right, it means that either $X_1 \le X_2 \le Y_1 \le Y_2$ or $Y_1 \le Y_2 \le X_1 \le X_2$, so nothing changes if we swap the matched positions. If, instead, the person that goes from $X_1$ to $Y_2$ goes to the right, and the person that goes from $X_2$ to $Y_1$ goes to the left, the segment $[\max(X_1, Y_1), \min(X_2, Y_2)]$ belongs to both paths, and swapping the matched pairs removes this segment from both paths (and decreases the total time). So, if the order of starting positions is sorted and the order of ending positions is sorted, these positions should be matched exactly in those order.

Using this fact, we can implement the following dynamic programming: let $dp_{i, j}$ be the minimum time if we considered $i$ first positions and picked $j$ of them as the ending ones. Transitions are the following: we either take the current position as the ending one (if it's not a starting one), match it with the $j$-th starting position and go to $dp_{i+1, j+1}$, or we skip the current position and go to $dp_{i+1,j}$. It works in $O(n^2)$ since it has up to $O(n^2)$ states and just up to $2$ transitions from each state.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

const int INF = int(1e9);

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> pos;
	for(int i = 0; i < n; i++)
		if(a[i] == 1)
			pos.push_back(i);
	int k = pos.size();
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
	dp[0][0] = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= k; j++)
		{
		 	if(dp[i][j] == INF) continue;
		 	dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
		 	if(j < k && a[i] == 0)
		 		dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(pos[j] - i));
		}
	cout << dp[n][k] << endl;
}

```
[1525E - Assimilation IV](../problems/E._Assimilation_IV.md "Educational Codeforces Round 109 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1525E - Assimilation IV](../problems/E._Assimilation_IV.md "Educational Codeforces Round 109 (Rated for Div. 2)")

Let $I(j)$ be the indicator function equal to $1$ if the $j$-th point is controlled by any city and $0$ otherwise. Then the expected number of controlled points $ans$ can be written as $E(\sum\limits_{j=1}^{m}{I(j)}) = \sum\limits_{j=1}^{m}{E(I(j))}$ (by linearity of expected value).

The expected value of the indicator function is equal to the probability of this function equal to $1$ ($E(I(j)) = P[I(j) = 1]$). In other words, for each point we need to calculate the probability of this point being controlled by any city.

Let's instead calculate the probability of point $j$ not being controlled by any city. Suppose, the distance between point $j$ and some city $i$ is equal to $x$. If we build a Monument in city $i$ at step $< n + 1 - x$ (zero indexed) then the point will be controlled by city $i$. But building the Monument at any step greater or equal than $n + 1 - x$ is fine.

Let's for each turn $k \in [0, n)$ calculate the number of cities that you can build Monument in starting this turn as $cnt[k]$. Our task is to calculate the number of permutations that are consistent with array $cnt$.

At first turn, we can choose one of $cnt[0]$ cities, at second turn we have $cnt[0] + cnt[1] - 1$ choices, at third step — $cnt[0] + cnt[1] + cnt[2] - 2$ choices, and so on. Using this idea, it's not hard to calculate the number of good permutations and then the initial probablity $P[I(j) = 1]$ $\equiv$ $1 - \text{good_permutations} \cdot (n!)^{-1} \pmod{998244353}$.

The expected value $ans \equiv \sum\limits_{j=1}^{m}{P[I(j) = 1]} \pmod{998244353}$.

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
	while (a >= MOD)
		a -= MOD;
	while (a < 0)
		a += MOD;
	return a;
}
int mul(int a, int b) {
	return int(a * 1ll * b % MOD);
}
int binPow(int a, int k) {
	int ans = 1;
	while (k > 0) {
		if (k & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		k >>= 1;
	}
	return ans;
}
int inv(int a) {
	return binPow(a, MOD - 2);
}

vector< vector<int> > d;
int n, m;

inline bool read() {
	if(!(cin >> n >> m))
		return false;
	d.resize(n, vector<int>(m));
	fore (i, 0, n) fore (j, 0, m)
		cin >> d[i][j];
	return true;
}

inline void solve() {
	int invFact = 1;
	fore (i, 1, n + 1)
		invFact = mul(invFact, i);
	invFact = inv(invFact);
	
	int E = 0;
	fore (j, 0, m) {
		vector<int> cnt(n + 1, 0);
		fore (i, 0, n)
			cnt[n + 1 - d[i][j]]++;
		
		vector<int> d(n + 1, 0);
		d[0] = 1;
		int rem = 0;
		fore (i, 0, n) {
			rem += cnt[i];
			d[i + 1] = norm(d[i + 1] + mul(d[i], rem));
			rem = max(0, rem - 1);
		}
//		cerr << d[n] << " - " << norm(1 - mul(d[n], invFact)) << endl;
		E = norm(E + 1 - mul(d[n], invFact));
	}
	cout << E << endl;
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
[1525F - Goblins And Gnomes](../problems/F._Goblins_And_Gnomes.md "Educational Codeforces Round 109 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1525F - Goblins And Gnomes](../problems/F._Goblins_And_Gnomes.md "Educational Codeforces Round 109 (Rated for Div. 2)")

First of all, let's try to solve the following problem: given a DAG, cover its vertices with the minimum number of vertex-disjoint paths. Solving this problem allows us to calculate the number of goblins that can pillage all of the halls when the tunnel network is fixed. This problem is a fairly classical one; since the number of vertices in each path is greater than the number of arcs in it exactly by $1$, we should take the maximum possible number of arcs into our paths. So we can reduce this problem to bipartite maximum matching — build a bipartite graph where each part consists of $n$ vertices, and for every directed arc $(x, y)$ in the original graph, connect the vertex $x$ of the left part to the vertex $y$ in the right part of the bipartite graph. The maximum matching in this graph allows us to pick the maximum number of arcs into the paths of the original problem (the matching ensures that each vertex has at most one chosen ingoing arc and at most one chosen outgoing arc, so the paths are vertex-disjoint). Okay, now we at least can check if the goblin wave can pillage all of the halls.

Let's say that the minimum number of goblins required to pillage the original city is $c$. Obviously, in order to pass the $c$-th wave and waves after it, we have to increase this number. In one minute, Monocarp can block all of the tunnels leading to some hall or out of some hall — and in terms of our reduction to the bipartite matching problem, it means that we remove all edges connected to some vertex of the bipartite graph. Obviously, in one minute, we can increase $c$ by at most $1$, since $c$ is equal to the difference between $n$ and the maximum matching size.

It turns out that it's always possible to choose a vertex that belongs to all maximum matchings in the bipartite graph (note that it doesn't work in non-bipartite graphs, but in our problem, it doesn't matter). For the proof of this fact, you can check the last paragraph of the editorial. So, each minute Monocarp prepares for a wave, he increases the maximum number of goblins he can repel by $1$.

Now the solution splits into two much easier parts. The first part is finding a sequence in which Monocarp blocks the tunnels, so that each his action reduces the size of the maximum matching by $1$. Since the constraints are small, even a naive approach in $O(n^5)$ — always iterate on the vertex we try to remove from the graph and check that removing it is possible by running Kuhn's algorithm — is fast enough. The second part is to choose when Monocarp calls waves of goblins and when he prepares for them — this can be easily done with dynamic programming: let $dp_{i,j}$ be the maximum Monocarp's score if he has already passed $i$ waves, and the current size of the maximum matching is $j$. The most naive implementation of this dynamic programming runs in $O(n^3)$, so the whole solution works in $O(n^5)$.

We can improve it to $O(n^3)$, though it is not needed under these constraints. Instead of finding the vertices to remove from the bipartite graph one-by-one, let's find all of them at once in $O(n^3)$. Recall that the size of maximum matching in a bipartite graph is equal to the size of its minimum vertex cover, and the minimum vertex cover can be reconstructed after finding the maximum matching. If we remove a vertex from the minimum vertex cover, the size of the minimum vertex cover of the remaining graph is reduced by $1$, so the size of the maximum matching is reduced by $1$ as well. It means that we can always choose to remove a vertex from the minimum vertex cover we found. By the way, it also proves that it's always possible to remove a vertex from a bipartite graph so the size of the maximum matching decreases by $1$ (obviously, if it's not $0$ already).

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

const int N = 543;
const long long INF = (long long)(1e18);

struct Matching
{
 	int n1, n2;
 	vector<set<int>> g;
 	vector<int> mt, used;

 	void init()
 	{
 	 	mt = vector<int>(n2, -1);
 	}

 	int kuhn(int x)
 	{
 	 	if(used[x] == 1) return 0;
 	 	used[x] = 1;
 	 	for(auto y : g[x])
 	 		if(mt[y] == -1 || kuhn(mt[y]) == 1)
 	 		{
 	 		 	mt[y] = x;
 	 		 	return 1;
 	 		}
 	 	return 0;
 	}

 	int calc()
 	{
 	 	init();
 	 	int sum = 0;
 	 	for(int i = 0; i < n1; i++)
 	 	{
 	 		used = vector<int>(n1, 0);
 	 		sum += kuhn(i);
 	 	}
 	 	return sum;
 	}

 	void remove_vertex(int v, bool right)
 	{
 	 	if(right)
 	 	{
 	 		for(int i = 0; i < n1; i++)
 	 			g[i].erase(v);
 	 	}
 	 	else
 	 		g[v].clear();
 	}

 	void add_edge(int x, int y)
 	{
 		g[x].insert(y);
 	}

 	Matching() {};
 	Matching(int n1, int n2) : n1(n1), n2(n2)
 	{
 		g.resize(n1);
 	};
};

int n, m, k;
long long dp[N][N];
int p[N][N];
vector<int> g[N];
long long x[N], y[N];

int main()
{
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
	 	int u, v;
	 	cin >> u >> v;
	 	--u;
	 	--v;
	 	g[u].push_back(v);
	}
	for(int i = 0; i < k; i++)
		cin >> x[i] >> y[i];

	Matching mt(n, n);
	for(int i = 0; i < n; i++)
		for(auto j : g[i])
			mt.add_edge(i, j);
	int cnt = mt.calc();
	int cur = cnt;
	vector<int> seq;
	while(cur > 0)
	{
		int idx = 0;
		for(int i = 0; i < n; i++)
		{
		 	Matching mt2 = mt;
		 	mt2.remove_vertex(i, false);
		 	if(mt2.calc() < cur)
		 		idx = i + 1;
		 	mt2 = mt;
		 	mt2.remove_vertex(i, true);
		 	if(mt2.calc() < cur)
		 		idx = -(i + 1);
		}
		assert(idx != 0);
		seq.push_back(idx);
		mt.remove_vertex(abs(idx) - 1, idx < 0);
		cur--;
	}	
	reverse(seq.begin(), seq.end());
	for(int i = 0; i <= k; i++)
		for(int j = 0; j <= cnt; j++)
			dp[i][j] = -INF;
	dp[0][cnt] = 0;
	for(int i = 0; i < k; i++)
		for(int j = 0; j <= cnt; j++)
		{
			if(dp[i][j] == -INF) continue;
			for(int z = 0; z <= j; z++)
			{
				if(i + 1 + z >= n) continue;
			 	int t = j - z;
			 	long long add = max(0ll, x[i] - t * y[i]);
			 	if(dp[i + 1][z] < dp[i][j] + add)
			 	{
			 	 	dp[i + 1][z] = dp[i][j] + add;
			 	 	p[i + 1][z] = j;
			 	}
			}
		}
	cur = max_element(dp[k], dp[k] + cnt + 1) - dp[k];
	vector<int> res;
	for(int i = k; i > 0; i--)
	{
		res.push_back(0);
		for(int j = p[i][cur] - 1; j >= cur; j--)
			res.push_back(seq[j]);
		cur = p[i][cur];	
	}
	reverse(res.begin(), res.end());
	cout << res.size() << endl;
	for(auto x : res) cout << x << " ";
	cout << endl;
}

```
