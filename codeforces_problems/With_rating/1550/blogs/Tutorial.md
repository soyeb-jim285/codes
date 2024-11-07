# Tutorial

[1550A - Find The Array](../problems/A._Find_The_Array.md "Educational Codeforces Round 111 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1550A - Find The Array](../problems/A._Find_The_Array.md "Educational Codeforces Round 111 (Rated for Div. 2)")

The maximum sum we can construct with $n$ elements is $1 + 3 + 5 + 7 + \dots + 2n-1 = n^2$, so we need at least $\lceil\sqrt{s}\rceil$ elements to construct the sum equal to $s$. Let's show how to express $s$ with exactly $\lceil\sqrt{s}\rceil$ elements.

Let $\lceil\sqrt{s}\rceil = d$. By taking $1 + 3 + 5 + 7 + \dots + 2d-3$, we achieve a sum of $(d-1)^2$ using $d - 1$ elements. $s - (d-1)^2$ is not less than $1$ and not greater than $2d-1$ (since $\sqrt{(d-1)^2} = d-1$, and $\sqrt{(d-1)^2 + 2d} > d$). Thus, we can just add $s - (d-1)^2$ to our array, and the sum becomes exactly $s$.

So, the solution is to find the minimum $n$ such that $n^2 \ge s$.

 **Solution (BledDest)**
```cpp
def maxSum(x):
	return x ** 2

def getAns(x):
	res = 1
	while maxSum(res) < x:
		res += 1
	return res

def main():
	t = int(input())
	for i in range(t):
		print(getAns(int(input())))

main()
```
[1550B - Maximum Cost Deletion](../problems/B._Maximum_Cost_Deletion.md "Educational Codeforces Round 111 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1550B - Maximum Cost Deletion](../problems/B._Maximum_Cost_Deletion.md "Educational Codeforces Round 111 (Rated for Div. 2)")

Let $l_1, l_2, \dots, l_k$ be the length of the substring deleted at the $i$-th step. Then the number of points will be equal to $\sum\limits_{i=1}^{k} (a \cdot l_i + b)$ or $a\sum\limits_{i=1}^{k}l_i + bk$. The sum of all $l_i$ is equal to $n$ (because in the end we deleted the entire string), so the final formula has the form $an + bk$. Obviously, for $b \ge 0$, you should delete the characters one by one so that $k=n$. Now $b < 0$ and you have to delete the string in the minimum number of operations. Let the string $s$ consist of $m$ blocks of zeros and ones, then $\lfloor\frac{m}{2}\rfloor + 1$ is the minimum number of operations for which the entire string can be deleted. As long as the number of blocks is more than $2$, we will delete the second block, the number of blocks will decrease by $2$ after each such operation (the block that we delete will disappear, and the first and third blocks will merge into one).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    int m = unique(s.begin(), s.end()) - s.begin();
    cout << n * a + max(n * b, (m / 2 + 1) * b) << 'n'; 
  }
}
```
[1550C - Manhattan Subarrays](../problems/C._Manhattan_Subarrays.md "Educational Codeforces Round 111 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1550C - Manhattan Subarrays](../problems/C._Manhattan_Subarrays.md "Educational Codeforces Round 111 (Rated for Div. 2)")

Let's figure out criteria for the bad triple $p$, $q$, $r$. It's not hard to prove that the triple is bad, iff point $q$ lies inside the bounding box of points $p$ and $r$. In other words, if $\min(x_p, x_r) \le x_q \le \max(x_p, x_r)$ and $\min(y_p, y_r) \le y_q \le \max(y_p, y_r)$.

Now, looking at points $p = (a_i, i)$, $q = (a_j, j)$ and $r = (a_k, k)$ we can see that the bad situation may arise only if $i < j < k$ — so we can check only ordered triples.

Looking closely at inequality $\min(a_i, a_k) \le a_j \le \max(a_i, a_k)$ we can note that there are two situations where $(i, j, k)$ forms a bad triple: when either $a_i \le a_j \le a_k$ or $a_i \ge a_j \ge a_k$. In other words, subarray is bad if and only if it contains either non-decreasing subsequence of length $3$ or non-increasing subsequence of length $3$.

The final observation is that any sequence of length at least $5$ contains either non-decreasing or non-increasing subsequence of length $3$. It's not hard to prove it, either brute-forcing all possible variants (of relative orders) on paper, or searching/remembering the theorem that says it.

As a result you need to check only subarrays of length at most $4$ whichever the way you want. The complexity is $O(n)$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<li, li> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n;
vector<li> a;

inline bool read() {
	if(!(cin >> n))
		return false;
	a.resize(n);
	fore (i, 0, n)
		cin >> a[i];
	return true;
}

li d(const pt &a, const pt &b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

inline void solve() {
	li ans = 0;
	fore (i, 0, n) {
		fore (j, i, n) {
			if (i + 2 <= j) {
				bool ok = true;
				fore (i1, i, j) fore (i2, i1 + 1, j) {
					if (d(pt(a[i1], i1), pt(a[j], j)) == d(pt(a[i1], i1), pt(a[i2], i2)) + d(pt(a[i2], i2), pt(a[j], j)))
						ok = false;
				}
				if (!ok)
					break;
			}
			ans++;
		}
	}
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);

	int t; cin >> t;
	
	while(t--) {
		read();
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
[1550D - Excellent Arrays](../problems/D._Excellent_Arrays.md "Educational Codeforces Round 111 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1550D - Excellent Arrays](../problems/D._Excellent_Arrays.md "Educational Codeforces Round 111 (Rated for Div. 2)")

Firstly, let's learn the structure of good array $a$ with maximum $F(a)$. Suppose, $a_i = i + k_i$, then $a_i + a_j = i + j$ $\Leftrightarrow$ $k_i = -k_j$. In other words, we can group $a_i$ by $|k_i|$ and pairs will appear only inside each group. It's easy to prove that if the group has size $m$ then it's optimal to split it in half: one with $+k_i$ and other with $-k_i$. Then the number of pairs inside the group will be equal to $\left\lfloor \frac{m}{2} \right\rfloor \cdot \left\lceil \frac{m}{2} \right\rceil$.

It's also not hard to prove that in this case it's optimal to place all elements inside one group. In other words, it's optimal to make a half of all elements as $a_i = i + k$ and the other half as $a_i = i - k$ for some integer $k > 0$. Then $F(a) = \left\lfloor \frac{n}{2} \right\rfloor \cdot \left\lceil \frac{n}{2} \right\rceil$.

To achieve maximum $F(a)$ the excellent array should also have this structure. Let $\mathit{half} = \left\lfloor \frac{n}{2} \right\rfloor$. For a fixed $k$ if $n$ is even then we should choose exactly $\mathit{half}$ positions $i$ to set as $a_i = i + k$, but if $n$ is odd, we can choose either $\mathit{half}$ or $\mathit{half} + 1$ positions.

Let's analyze what happens with different $k$. Obviously, $k \ge 1$. While $k \le \min(1 - l, r - n)$ both $i + k$ and $i - k$ are in the segment $[l, r]$ for any $i$. In this case we can choose any $a_i$ as $i + k$, so there are exactly $\binom{n}{\mathit{half}}$ ways for even $n$ and $\binom{n}{\mathit{half}} + \binom{n}{\mathit{half} + 1}$ ways for odd $n$.

When $k > \min(1 - l, r - n)$ then for $i \in [1, \mathit{lf})$ (where $\mathit{lf} = \max(1, l + k)$) there is only one choice — to set $a_i = i + k$. Analogically, for $i \in (\mathit{rg}, n]$ (where $\mathit{rg} = \min(n, r - k)$) there is only choice to set $a_i = i - k$.

What remains is $\mathit{rg} - \mathit{lf} + 1$ elements without restrictions, so there are $\binom{\mathit{rg} - \mathit{lf} + 1}{\mathit{half} - (\mathit{lf} - 1)}$ ways to choose for even $n$ or $\binom{\mathit{rg} - \mathit{lf} + 1}{\mathit{half} - (\mathit{lf} - 1)} + \binom{\mathit{rg} - \mathit{lf} + 1}{\mathit{half} + 1 - (\mathit{lf} - 1)}$ ways for odd $n$.

Note that it's convenient to say that $\binom{n}{k} = 0$ if $k < 0$ or $n < k$, so we don't need extra checks.

Lastly, note that we can process all $k \in [1, \min(1 - l, r - n)]$ with one formula and there are only $O(n)$ of $k > \min(1 - l, r - n)$ with non-zero number of ways to choose, so we can iterate over all such $k$ straightforwardly.

The total complexity is $O(n \log{\mathit{MOD}})$ because of precomputation of factorials and inverse factorials to calculate $\binom{n}{k}$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

const int MOD = int(1e9) + 7;

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

const int N = 200 * 1000 + 55;
int f[N], inf[N];

void precalc() {
	f[0] = inf[0] = 1;
	fore (i, 1, N) {
		f[i] = mul(f[i - 1], i);
		inf[i] = binPow(f[i], MOD - 2);
	}
}

int C(int n, int k) {
	if (k < 0 || n < k)
		return 0;
	return mul(f[n], mul(inf[n - k], inf[k]));
}

int n, l, r;

inline bool read() {
	if(!(cin >> n >> l >> r))
		return false;
	return true;
}

inline void solve() {
	int half = n / 2;
	int st = min(1 - l, r - n);
	
	int ans = mul(st, C(n, half));
	if (n & 1)
		ans = norm(ans + mul(st, C(n, half + 1)));
	
	for (int k = st + 1; ; k++) {
		int lf = max(1, l + k);
		int rg = min(n, r - k);
		
		if (rg + 1 - lf < 0)
			break;
		
		ans = norm(ans + C(rg + 1 - lf, half - (lf - 1)));
		if (n & 1)
			ans = norm(ans + C(rg + 1 - lf, half + 1 - (lf - 1)));
	}
	
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	precalc();
	int t; cin >> t;
	while (t--) {
		read();
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
[1550E - Stringforces](../problems/E._Stringforces.md "Educational Codeforces Round 111 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1550E - Stringforces](../problems/E._Stringforces.md "Educational Codeforces Round 111 (Rated for Div. 2)")

Notice that if there are substrings of length $x$ for each letter, then there are also substrings of length $x-1$. Thus, the function on the answer is monotonous, so the binary search is applicable.

Let's have some answer $x$ fixed by binary search. We have to place $k$ blocks of letters of length $x$ somewhere in a string. If we fix an order these blocks go into the string, then the greedy algorithm for placing them works. Put each block after the previous one but as far to the left as possible (the correctness can be proven by showing that picking not the furthest to the left position can't be more optimal). If there exists such an order that all blocks fit, then the answer is greater than or equal to $x$.

The common transition is to move from iterating over permutations to dynamic programming over submasks. Let $dp[mask]$ be the smallest prefix of the string, such that all blocks of letters from the mask fit into this prefix. The transitions are the same: pick a new block and place it as early after that prefix as possible.

So far the solution works pretty slow, since for each of $2^k$ masks we have to find the earliest possible position for a block. Let's use some precalculations to perform the transitions in $O(1)$.

Notice that the transition doesn't depend on a mask, only on a length of the previous prefix. Thus, for every prefix and every letter, we can save the closest position for a block.

Let $pos[i][j]$ be the closest position for a prefix of length $i$ and the $j$-th letter. $pos[i][j]$ is at least equal to $pos[i + 1][j]$. However, if the block can be placed at the $i$-th position, then it should be updated. That can happen if the closest occurrence of any letter except $j$ is not smaller than $j + x$. Thus, we can also maintain the closest occurrence of every letter. With some smart iterations, we can do the precalculations in $O(nk)$.

The dynamic programming works in $O(2^k \cdot k)$ then.

Overall complexity: $O((nk + 2^k \cdot k) \log n)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n, k;
string s;

bool check(int d){
	vector<int> lst(k, n);
	vector<vector<int>> pos(n + 1, vector<int>(k, n + 1));
	for (int i = n - 1; i >= 0; --i){
		if (s[i] != '?'){
			lst[s[i] - 'a'] = i;
		}
		int cur = n;
		forn(j, k){
			pos[i][j] = (i + d <= cur ? i + d : pos[i + 1][j]);
			cur = min(cur, lst[j]);
		}
		cur = n;
		for (int j = k - 1; j >= 0; --j){
			if (i + d > cur) pos[i][j] = pos[i + 1][j];
			cur = min(cur, lst[j]);
		}
	}
	vector<int> dp(1 << k, n + 1);
	dp[0] = 0;
	forn(mask, 1 << k) if (dp[mask] < n + 1){
		forn(i, k) if (!((mask >> i) & 1))
			dp[mask | (1 << i)] = min(dp[mask | (1 << i)], pos[dp[mask]][i]);
	}
	return dp[(1 << k) - 1] <= n;
}

int main() {
	cin >> n >> k;
	cin >> s;
	int l = 1, r = n;
	int res = 0;
	while (l <= r){
		int m = (l + r) / 2;
		if (check(m)){
			res = m;
			l = m + 1;
		}
		else{
			r = m - 1;
		}
	}
	cout << res << endl;
	return 0;
}
```
[1550F - Jumping Around](../problems/F._Jumping_Around.md "Educational Codeforces Round 111 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1550F - Jumping Around](../problems/F._Jumping_Around.md "Educational Codeforces Round 111 (Rated for Div. 2)")

Notice that increasing $k$ only increases the range of the jump distances in both directions. So every rock that was reachable with some $k$, will be reachable with $k+1$ as well. Thus, let's try to find the smallest possible value of $k$ to reach each rock.

Let's imagine this problem as a graph one and consider the following algorithm. For every pair of rocks, make an edge of weight equal to the smallest $k$ required to jump from one to another. For some rocks $v$ and $u$ that is $w = |d - |a_v - a_u||$. How to check the reachability with these edges? Well, if the jump range value is $k$, then there should exist of path by edges of weight no more than $k$. So we can start with an empty graph, first add the edges of the smallest weight, then the second smallest, and so on. The first time a pair of vertices becomes reachable from each other is the minimum such weight.

An experienced reader can notice the resemblance with the Kruskal algorithm for finding the minimum spanning tree. After the spanning tree is constructed, the minimum $k$ is the maximum value on a path between the vertices.

The issue is that Kruskal requires $O(n^2 \log n^2)$ to construct an MST for a complete graph. Prim can make it $O(n^2)$, which is still too much. Thus, the solution is to resort to Boruvka.

On each iteration of Boruvka we have to find the smallest weight edge from each component to some other one. We can solve it the following way. Maintain a sorted set of rocks coordinates. The smallest weight edges are the ones that are the closest to $d$ distance from each rock. So we could query a lower_bound of $a_i - d$ and $a_i + d$ on each rock $i$ to find them. Don't forget to look at the both sides of the lower_bound result.

However, the issue is that we can bump into the rocks from the same component. Thus, let's process components one by one. When processing a component, first remove all its vertices from the set. Then query the edges for each vertex. Then add the vertices back. This way, only the edges to other components will be considered.

That makes it an $O(n \log^2 n)$ construction, with one log from the number of Boruvka iterations and another $n \log n$ from finding the edges. That should pass if coded carefully enough, and that is basically the intended solution.

Still, there exists a $O(n \log n)$ construction. That will require a $O(n)$ algorithm for finding the edges. So there are four possible edges for each rock $i$: the closest to $a_i - d$ from the left, from the right and the same for $a_i + d$. Let's consider only the first case, the rest will be similar.

The coordinates are sorted beforehand, and we are processing the rocks from left to right. We can maintain a pointer to the latest encountered rock to the left of $a_i - d$. The issue with it being from the same component is still there. Let's go around it by also storing the second latest encountered rock such that it's from the different component from the actual latest one. This can be updated in the same manner one calculates the second maximum of the array.

Now you just have to do that for all four cases. This two pointers approach makes it $O(n)$ for each iteration, thus making the construction $O(n \log n)$.

Since the queries ask for a path from some fixed vertex $s$ to a certain vertex $i$, it's the same as calculating the maximum edge on a path from the root of the tree to each vertex. Can be done with a simple dfs. The only thing left is to check if the minimum possible $k$ is less than or equal to the one provided in the query.

Overall complexity: $O(n \log^2 n + q)$ or $O(n \log n + q)$.

 **Solution 1 (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int INF = 1e9;

struct edge2{
	int u, w;
};

vector<vector<edge2>> g;

struct edge3{
	int v, u, w;
};

bool operator <(const edge3 &a, const edge3 &b){
	if (a.w != b.w)
		return a.w < b.w;
	if (min(a.v, a.u) != min(b.v, b.u))
		return min(a.v, a.u) < min(b.v, b.u);
	return max(a.v, a.u) < max(b.v, b.u);
}

vector<vector<int>> comps;
vector<int> p;

bool unite(int a, int b){
	a = p[a], b = p[b];
	if (a == b) return false;
	if (comps[a].size() < comps[b].size()) swap(a, b);
	for (int v : comps[b]){
		p[v] = a;
		comps[a].push_back(v);
	}
	comps[b].clear();
	return true;
}

vector<int> mn;

void dfs(int v, int p, int d){
	mn[v] = d;
	for (auto e : g[v]) if (e.u != p)
		dfs(e.u, v, max(d, e.w));
}

int main() {
	int n, q, s, d;
	scanf("%d%d%d%d", &n, &q, &s, &d);
	--s;
	vector<int> a(n);
	forn(i, n) scanf("%d", &a[i]);
	vector<int> idx(a[n - 1] + 1);
	forn(i, n) idx[a[i]] = i;
	comps.resize(n);
	p.resize(n);
	forn(i, n) comps[i] = vector<int>(1, i), p[i] = i;
	g.resize(n);
	set<int> pos(a.begin(), a.end());
	int cnt = n;
	while (cnt > 1){
		vector<edge3> es;
		for (const vector<int> &comp : comps) if (!comp.empty()){
			for (int i : comp)
				pos.erase(a[i]);
			edge3 mn = {-1, -1, INF};
			for (int i : comp){
				for (int dx : {-d, d}){
					auto it = pos.lower_bound(a[i] + dx);
					if (it != pos.end())
						mn = min(mn, {i, idx[*it], abs(abs(a[i] - *it) - d)});
					if (it != pos.begin()){
						--it;
						mn = min(mn, {i, idx[*it], abs(abs(a[i] - *it) - d)});
					}
				}
			}
			for (int i : comp)
				pos.insert(a[i]);
			assert(mn.v != -1);
			es.push_back(mn);
		}
		for (auto e : es){
			if (unite(e.v, e.u)){
				--cnt;
				g[e.v].push_back({e.u, e.w});
				g[e.u].push_back({e.v, e.w});
			}
		}
	}
	mn.resize(n);
	dfs(s, -1, 0);
	forn(_, q){
		int i, k;
		scanf("%d%d", &i, &k);
		--i;
		puts(mn[i] <= k ? "Yes" : "No");
	}
	return 0;
}
```
 **Solution 2 (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int INF = 1e9;

struct edge2{
	int u, w;
};

vector<vector<edge2>> g;

struct edge3{
	int v, u, w;
	edge3(){}
	edge3(int v, int u, int w) : v(v), u(u), w(w) {
		if (v > u) swap(v, u);
	}
};

bool operator <(const edge3 &a, const edge3 &b){
	if (a.w != b.w)
		return a.w < b.w;
	if (a.v != b.v)
		return a.v < b.v;
	return a.u < b.u;
}

vector<int> p, rk;

int getp(int a){
	return a == p[a] ? a : p[a] = getp(p[a]);
}

bool unite(int a, int b){
	a = getp(a), b = getp(b);
	if (a == b) return false;
	if (rk[a] < rk[b]) swap(a, b);
	rk[a] += rk[b];
	p[b] = a;
	return true;
}

vector<int> mn;

void dfs(int v, int p, int d){
	mn[v] = d;
	for (auto e : g[v]) if (e.u != p)
		dfs(e.u, v, max(d, e.w));
}

int main() {
	int n, q, s, d;
	scanf("%d%d%d%d", &n, &q, &s, &d);
	--s;
	vector<int> a(n);
	forn(i, n) scanf("%d", &a[i]);
	p.resize(n);
	rk.resize(n);
	forn(i, n) rk[i] = 1, p[i] = i;
	g.resize(n);
	int cnt = n;
	int iter = 0;
	while (cnt > 1){
		++iter;
		vector<edge3> es(n, edge3(-1, -1, INF));
		int j, mn1, mn2;
		j = 0, mn1 = -1, mn2 = -1;
		forn(i, n) getp(i);
		forn(i, n){
			while (j < n && a[i] - a[j] > d){
				if (mn1 == -1 || p[mn1] == p[j])
					mn1 = j;
				else{
					mn2 = mn1;
					mn1 = j;
				}
				++j;
			}
			if (mn1 != -1 && p[mn1] != p[i]){
				es[p[i]] = min(es[p[i]], edge3(mn1, i, abs(abs(a[i] - a[mn1]) - d)));
			}
			if (mn2 != -1 && p[mn2] != p[i]){
				es[p[i]] = min(es[p[i]], edge3(mn2, i, abs(abs(a[i] - a[mn2]) - d)));
			}
		}
		j = 0, mn1 = -1, mn2 = -1;
		forn(i, n){
			while (j < n && a[j] - a[i] <= d){
				if (mn1 == -1 || p[mn1] == p[j])
					mn1 = j;
				else{
					mn2 = mn1;
					mn1 = j;
				}
				++j;
			}
			if (mn1 != -1 && p[mn1] != p[i]){
				es[p[i]] = min(es[p[i]], edge3(mn1, i, abs(abs(a[i] - a[mn1]) - d)));
			}
			if (mn2 != -1 && p[mn2] != p[i]){
				es[p[i]] = min(es[p[i]], edge3(mn2, i, abs(abs(a[i] - a[mn2]) - d)));
			}
		}
		j = n - 1, mn1 = -1, mn2 = -1;
		for (int i = n - 1; i >= 0; --i){
			while (j >= 0 && a[j] - a[i] > d){
				if (mn1 == -1 || p[mn1] == p[j])
					mn1 = j;
				else{
					mn2 = mn1;
					mn1 = j;
				}
				--j;
			}
			if (mn1 != -1 && p[mn1] != p[i]){
				es[p[i]] = min(es[p[i]], edge3(mn1, i, abs(abs(a[i] - a[mn1]) - d)));
			}
			if (mn2 != -1 && p[mn2] != p[i]){
				es[p[i]] = min(es[p[i]], edge3(mn2, i, abs(abs(a[i] - a[mn2]) - d)));
			}
		}
		j = n - 1, mn1 = -1, mn2 = -1;
		for (int i = n - 1; i >= 0; --i){
			while (j >= 0 && a[i] - a[j] <= d){
				if (mn1 == -1 || p[mn1] == p[j])
					mn1 = j;
				else{
					mn2 = mn1;
					mn1 = j;
				}
				--j;
			}
			if (mn1 != -1 && p[mn1] != p[i]){
				es[p[i]] = min(es[p[i]], edge3(mn1, i, abs(abs(a[i] - a[mn1]) - d)));
			}
			if (mn2 != -1 && p[mn2] != p[i]){
				es[p[i]] = min(es[p[i]], edge3(mn2, i, abs(abs(a[i] - a[mn2]) - d)));
			}
		}
		for (auto e : es) if (e.v != -1){
			if (unite(e.v, e.u)){
				--cnt;
				g[e.v].push_back({e.u, e.w});
				g[e.u].push_back({e.v, e.w});
			}
		}
	}
	mn.resize(n);
	dfs(s, -1, 0);
	forn(_, q){
		int i, k;
		scanf("%d%d", &i, &k);
		--i;
		puts(mn[i] <= k ? "Yes" : "No");
	}
	return 0;
}
```
