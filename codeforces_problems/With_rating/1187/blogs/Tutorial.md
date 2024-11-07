# Tutorial

[1187A - Stickers and Toys](../problems/A._Stickers_and_Toys.md "Educational Codeforces Round 67 (Rated for Div. 2)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1187A - Stickers and Toys](../problems/A._Stickers_and_Toys.md "Educational Codeforces Round 67 (Rated for Div. 2)")

Note, that there are exactly $n - t$ eggs with only a sticker and, analogically, exactly $n - s$ with only a toy. So we need to buy more than $\max(n - t, n - s)$ eggs, or exactly $\max(n - t, n - s) + 1$.

 **Solution (adedalic)**
```cpp
fun main(args: Array<String>) {
    val tc = readLine()!!.toInt()
    for (i in 1..tc) {
        val (n, s, t) = readLine()!!.split(' ').map { it.toInt() }
        println(maxOf(n - s, n - t) + 1)
    }
}
```
[1187B - Letters Shop](../problems/B._Letters_Shop.md "Educational Codeforces Round 67 (Rated for Div. 2)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**Tutorial is loading... **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n, m;
string s, t;
vector<int> pos[26];

int main() {
	cin >> n >> s;
	forn(i, n)
		pos[s[i] - 'a'].push_back(i + 1);
	
	cin >> m;
	forn(i, m){
		cin >> t;
		vector<int> cnt(26);
		for (auto &c : t)
			++cnt[c - 'a'];
		int ans = -1;
		forn(j, 26) if (cnt[j] > 0)
			ans = max(ans, pos[j][cnt[j] - 1]);
		cout << ans << "n";
	}
	return 0;
}
```
[1187C - Vasya And Array](../problems/C._Vasya_And_Array.md "Educational Codeforces Round 67 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1187C - Vasya And Array](../problems/C._Vasya_And_Array.md "Educational Codeforces Round 67 (Rated for Div. 2)")

Let's consider array $b_1, b_2, \dots , b_{n-1}$, such that $b_i = a_{i + 1} - a_i$.

Then subarray $a_l, a_{l+1}, \dots , a_r$ is sorted in non-decreasing order if and only if all elements $b_l, b_{l + 1} , \dots , b_{r - 1}$ are greater or equal to zero.

So if we have fact $t_i = 1, l_i, r_i$, then all elements $b_{l_i}, b_{l_i + 1}, \dots , b_{r_i - 1}$ must be greater or equal to zero.

Let's create the following array $b$: $b_i = 0$ if there is such a fact ${t_j, l_j, r_j}$ that $t_j = 1, l_j \le i < r_j$, and $b_i = -1$ otherwise.

After that we create the following array $a$: $a_1 = n$, and for all other indexes $a_i = a_{i - 1} + b_{i - 1}$.

This array $a$ satisfies all facts ${t_i, l_i, r_i}$ such that $t_i = 1$. So all we have to do is check that all remaining facts are satisfied.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

int n, m;
int l[N], r[N], s[N];
int d[N];
int dx[N];
int res[N];
int nxt[N];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i){
		scanf("%d %d %d", s + i, l + i, r + i);
		--l[i], --r[i];
		if(s[i] == 1)
			++d[l[i]], --d[r[i]];
	}

	memset(dx, -1, sizeof dx);
	int sum = 0;
	for(int i = 0; i < n - 1; ++i){
		sum += d[i];
		if(sum > 0)	
			dx[i] = 0;
	}		

	res[0] = n;
	for(int i = 1; i < n; ++i)
		res[i] = res[i - 1] + dx[i - 1];	

	nxt[n - 1] = n - 1;
	for(int i = n - 2; i >= 0; --i){
		if(res[i] <= res[i + 1])
			nxt[i] = nxt[i + 1];
		else 
			nxt[i] = i;
	}			

	for(int i = 0; i < m; ++i){
		if(s[i] != (nxt[l[i]] >= r[i])){
			puts("NO");
			return 0;		
		}
	}	

	puts("YES");
	for(int i = 0; i < n; ++i)
		printf("%d ", res[i]);
	puts("");

	return 0;
}                             	



```
[1187D - Subarray Sorting](../problems/D._Subarray_Sorting.md "Educational Codeforces Round 67 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1187D - Subarray Sorting](../problems/D._Subarray_Sorting.md "Educational Codeforces Round 67 (Rated for Div. 2)")

Let's reformulate this problem in next form: we can sort only subarray of length 2 (swap two consecutive elements $i$ and $i+1$ if $a_i > a_{i + 1}$). It is simular tasks because we can sort any array by sorting subbarray of length 2 (for example bubble sort does exactly that). 

Now lets look at elements $a_1$ and $b_1$. If $a_1 = b_1$ then we will solve this task for arrays $a_2, a_3, \dots , a_n$ and $b_2, b_3, \dots , b_n$. 

Otherwise lets look at minimum position $pos$ such that $a_{pos} = b_1$ (if there is no such position then answer to the problem is NO). We can move element $a_{pos}$ to the beginning of array only if all elements $a_1, a_2, \dots, a_{pos - 1}$ greater then $a_{pos}$. In other words any index $i$ such that $a_i < a_{pos}$ must be greater then $pos$. And if this condition holds, then we just delete element $a_{pos}$ and solve task for arrays $a_1, a_2, \dots, a_{pos - 2}, a_{pos-1}, a_{pos + 1}, a_{pos + 2}, \dots , a_n$ and $b_2, b_3, \dots, b_n$.

But instead of deleting this element $a_{pos}$ we will change information about minimum index $i$ such that $b_1 = a_i$. This index will be the minimum index $i$ such that $i > pos$ and $a_{pos} = a_i$.

For do this we will maintain $n$ stacks $s_1, s_2, \dots , s_n$ such that for any element $x$ of stack $s_i$ condition $a_x = i$ holds and moreover all elements in stacks are sorted in ascending order (the top element of stack is minimal). For example if $a = [1, 2, 3, 1, 2, 2]$, then $s_1 = [1, 4]$, $s_2 = [2, 5, 6]$, $s_3 = [3]$, $s_4, s_5, s_6 = []$. For finding minimum element on top of stacks $s_1, s_2, \dots , s_i$ we can use some data structure (for example segment tree).

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;
const int INF = int(1e9) + 99;

int t, n;
int a[N], b[N];
vector <int> p[N];
int st[4 * N + 55];

int getMin(int v, int l, int r, int L, int R){
	if(L >= R) return INF;
	if(l == L && r == R)
		return st[v];

	int mid = (l + r) / 2;
	return min(getMin(v * 2 + 1, l, mid, L, min(R, mid)),
		getMin(v * 2 + 2, mid, r, max(mid, L), R));	
}

void upd(int v, int l, int r, int pos, int x){
	if(r - l == 1){
		st[v] = x;
		return;
	}

	int mid = (l + r) / 2;
	if(pos < mid) upd(v * 2 + 1, l, mid, pos, x);
	else upd(v * 2 + 2, mid, r, pos, x);
		
	st[v] = min(st[v * 2 + 1], st[v * 2 + 2]);
}

int main() {
	scanf("%d", &t);
	for(int tc = 0; tc < t; ++tc){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			p[i].clear();					
		for(int i = 0; i < n; ++i){
			scanf("%d", a + i);
			--a[i];
			p[a[i]].push_back(i);	
		}	
		for(int i = 0; i < n; ++i){
			scanf("%d", b + i);	
			--b[i];		
		}

		for(int i = 0; i < 4 * n; ++i) st[i] = INF;
		for(int i = 0; i < n; ++i){
			reverse(p[i].begin(), p[i].end());
			if(!p[i].empty()) upd(0, 0, n, i, p[i].back());
		}

		bool ok = true;
		for(int i = 0; i < n; ++i){
			if(p[b[i]].empty()){
				ok = false;
				break;
			}

			int pos = p[b[i]].back();
			if(getMin(0, 0, n, 0, b[i]) < pos){
				ok = false;
				break;
			}

			p[b[i]].pop_back();
			upd(0, 0, n, b[i], p[b[i]].empty()? INF : p[b[i]].back());			
		}

		if(ok) puts("YES");
		else puts("NO");
	}	
	
	return 0;
}
```
[1187E - Tree Painting](../problems/E._Tree_Painting.md "Educational Codeforces Round 67 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1187E - Tree Painting](../problems/E._Tree_Painting.md "Educational Codeforces Round 67 (Rated for Div. 2)")

I should notice that there is much simpler idea and solution for this problem without rerooting technique but I will try to explain rerooting as the main solution of this problem (it can be applied in many problems and this is just very simple example).

What if the root of the tree is fixed? Then we can notice that the answer for a subtree can be calculated as $dp_v = s_v + \sum\limits_{to \in ch(v)} dp_{to}$, where $ch(v)$ is the set of children of the vertex $v$. The answer on the problem for the fixed root will be $dp_{root}$.

How can we calculate all possible values of $dp_{root}$ for each root from $1$ to $n$ fast enough? We can apply rerooting! When we change the root of tree from the vertex $v$ to the vertex $to$, we can notice that only four values will change: $s_v, s_{to}, dp_v$ and $dp_{to}$. Firstly, we need to cut the subtree of $to$ from the tree rooted at $v$. Let's subtract $dp_{to}$ and $s_{to}$ from $dp_v$, then let's change the size of the subtree of $v$ (subtract $s_{to}$ from it). Now we have the tree without the subtree of $to$. Then we need to append $v$ as a child of $to$. Add $s_v$ to $s_{to}$ and add $s_v$ and $dp_v$ to $dp_{to}$. Now we have $to$ as a root of the tree and can update the answer with $dp_{to}$. When we changes the root of the tree back from $to$ to $v$, we just need to rollback all changes we made.

So, overall idea is the following: calculate sizes of subtrees for some fixed root, calculate dynamic programming for this root, run dfs which will reroot the tree with any possible vertex and update the answer with the value of dynamic programming for each possible root.

The code of function that reroots the tree seems like this: 


```cpp
  
void dfs(int v, int p = -1) {  
	ans = max(ans, dp[v]);  
	for (auto to : g[v]) {  
		if (to == p) continue;  
		  
		dp[v] -= dp[to];  
		dp[v] -= siz[to];  
		siz[v] -= siz[to];  
		siz[to] += siz[v];  
		dp[to] += siz[v];  
		dp[to] += dp[v];  
		  
		dfs(to, v);  
		  
		dp[to] -= dp[v];  
		dp[to] -= siz[v];  
		siz[to] -= siz[v];  
		siz[v] += siz[to];  
		dp[v] += siz[to];  
		dp[v] += dp[to];  
	}  
}  

```
 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n;
long long ans;
vector<int> siz;
vector<long long> dp;
vector<vector<int>> g;

int calcsize(int v, int p = -1) {
	siz[v] = 1;
	for (auto to : g[v]) {
		if (to == p) continue;
		siz[v] += calcsize(to, v);
	}
	return siz[v];
}

long long calcdp(int v, int p = -1) {
	dp[v] = siz[v];
	for (auto to : g[v]) {
		if (to == p) continue;
		dp[v] += calcdp(to, v);
	}
	return dp[v];
}

void dfs(int v, int p = -1) {
	ans = max(ans, dp[v]);
	for (auto to : g[v]) {
		if (to == p) continue;
		
		dp[v] -= dp[to];
		dp[v] -= siz[to];
		siz[v] -= siz[to];
		siz[to] += siz[v];
		dp[to] += siz[v];
		dp[to] += dp[v];
		
		dfs(to, v);
		
		dp[to] -= dp[v];
		dp[to] -= siz[v];
		siz[to] -= siz[v];
		siz[v] += siz[to];
		dp[v] += siz[to];
		dp[v] += dp[to];
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n;
	g = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	ans = 0;
	siz = vector<int>(n);
	dp = vector<long long>(n);
	
	calcsize(0);
	calcdp(0);
	dfs(0);
	
	cout << ans << endl;
	
	return 0;
}
```
 **Alternative solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;

using namespace std;

const int N = 200 * 1000 + 13;

int n;
vector<int> g[N];

int siz[N];
li sum[N];

void init(int v, int p = -1){
	siz[v] = 1;
	sum[v] = 0;
	for (auto u : g[v]) if (u != p){
		init(u, v);
		siz[v] += siz[u];
		sum[v] += sum[u];
	}
	sum[v] += (siz[v] - 1);
}

li dp[N];

void dfs(int v, int p = -1){
	dp[v] = 0;
	li tot = 0;
	for (auto u : g[v]) if (u != p)
		tot += sum[u];
	for (auto u : g[v]) if (u != p){
		dfs(u, v);
		dp[v] = max(dp[v], (n - siz[u] - 1) + dp[u] + (tot - sum[u]));
	}
	if (g[v].size() == 1){
		dp[v] = n - 1;
	}
}

int main() {
	scanf("%d", &n);
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	if (n == 2) {
		cout << 3 << endl;
		return 0;
	}
	
	forn(i, n) if (int(g[i].size()) > 1){
		init(i);
		dfs(i);
		printf("%lldn", dp[i] + n);
		break;
	}
	
	return 0;
}
```
[1187F - Expected Square Beauty](../problems/F._Expected_Square_Beauty.md "Educational Codeforces Round 67 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms") and [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1187F - Expected Square Beauty](../problems/F._Expected_Square_Beauty.md "Educational Codeforces Round 67 (Rated for Div. 2)")

As usual with tasks on an expected value, let's denote $I_i(x)$ as indicator function: $I_i(x) = 1$ if $x_i \neq x_{i - 1}$ and $0$ otherwise; $I_1(x) = 1$. Then we can note that $B(x) = \sum\limits_{i = 1}^{n}{I_i(x)}$. Now we can make some transformations: $E(B^2(x)) = E((\sum\limits_{i = 1}^{n}{I_i(x)})^2) = E(\sum\limits_{i = 1}^{n}{ \sum\limits_{j = 1}^{n}{I_i(x) I_j(x)} }) = \sum\limits_{i = 1}^{n}{ \sum\limits_{j = 1}^{n}{E(I_i(x) I_j(x))} }$.

Now we'd like to make some casework: 

* if $|i - j| > 1$ ($i$ and $j$ aren't consecutive) then $I_i(x)$ and $I_j(x)$ are independent, that's why $E(I_i(x) I_j(x)) = E(I_i(x)) E(I_j(x))$;
* if $i = j$ then $E(I_i(x) I_i(x)) = E(I_i(x))$;
* $|i - j| = 1$ need further investigation.

For the simplicity let's transform segment $[l_i, r_i]$ to $[l_i, r_i)$ by increasing $r_i = r_i + 1$.

Let's denote $q_i$ as the probability that $x_{i-1} = x_i$: $q_i = \max(0, \frac{\min(r_{i - 1}, r_i) - \max(l_{i - 1}, l_i)}{(r_{i - 1} - l_{i - 1})(r_i - l_i)})$ and $q_1 = 0$. Let's denote $p_i = 1 - q_i$. In result, $E(I_i(x)) = p_i$.

The final observation is the following: $E(I_i(x) I_{i + 1}(x))$ is equal to the probability that $x_{i - 1} \neq x_i$ and $x_i \neq x_{i + 1}$ and can be calculated by inclusion-exclusion principle: $E(I_i(x) I_{i + 1}(x)) = 1 - q_{i} - q_{i + 1} + P(x_{i-1} = x_i\ \\&\ x_i = x_{i + 1})$, where $P(x_{i-1} = x_i\ \\&\ x_i = x_{i + 1}) = \max(0, \frac{\min(r_{i-1}, r_i, r_{i+1}) - \max(l_{i-1}, l_i, l_{i+1})}{(r_{i-1} - l_{i-1})(r_i - l_i)(r_{i+1} - l_{i+1})})$.

In result, $E(B^2(x)) = \sum\limits_{i = 1}^{n}{( p_i + p_i\sum\limits_{|j - i| > 1}{p_j} + E(I_{i-1}(x) I_i(x)) + E(I_i(x) I_{i+1}(x)) )}$ and can be calculated in $O(n \log{MOD})$ time.

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

const int MOD = int(1e9) + 7;

int norm(int a) {
	while(a >= MOD) a -= MOD;
	while(a < 0) a += MOD;
	return a;
}
int mul(int a, int b) {
	return int(a * 1ll * b % MOD);
}
int binPow(int a, int k) {
	int ans = 1;
	for(; k > 0; k >>= 1) {
		if(k & 1)
			ans = mul(ans, a);
		a = mul(a, a);
	}
	return ans;
}
int inv(int a) {
	int b = binPow(a, MOD - 2);
	assert(mul(a, b) == 1);
	return b;
}

int n;
vector<int> l, r;

inline bool read() {
	if(!(cin >> n))
		return false;
	l.resize(n);
	r.resize(n);
	
	fore(i, 0, n)
		cin >> l[i];
	fore(i, 0, n) {
		cin >> r[i];
		r[i]++;
	}
	return true;
}

vector<int> p;

int calcEq(int i0) { 
	int i1 = i0 + 1;
	int pSame = 0;
	if(i0 > 0) {
		int cnt = max(0, min({r[i0 - 1], r[i0], r[i1]}) - max({l[i0 - 1], l[i0], l[i1]}));
		pSame = mul(cnt, inv(mul(mul(r[i0 - 1] - l[i0 - 1], r[i0] - l[i0]), r[i1] - l[i1])));
	}
	return norm(1 - norm(2 - p[i0] - p[i1]) + pSame);
}

inline void solve() {
	p.assign(n, 0);
	p[0] = 1;
	fore(i, 1, n) {
		int cnt = max(0, min(r[i - 1], r[i]) - max(l[i - 1], l[i]));
		p[i] = norm(1 - mul(cnt, inv(mul(r[i - 1] - l[i - 1], r[i] - l[i]))));
	}
	
	int sum = 0;
	fore(i, 0, n)
		sum = norm(sum + p[i]);
	
	int ans = 0;
	fore(i, 0, n) {
		int curS = sum;
		for(int j = max(0, i - 1); j < min(n, i + 2); j++)
			curS = norm(curS - p[j]);
		
		ans = norm(ans + mul(p[i], curS));
		
		if(i > 0)
			ans = norm(ans + calcEq(i - 1));
		ans = norm(ans + p[i]);
		if(i + 1 < n)
			ans = norm(ans + calcEq(i));
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
[1187G - Gang Up](../problems/G._Gang_Up.md "Educational Codeforces Round 67 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1187G - Gang Up](../problems/G._Gang_Up.md "Educational Codeforces Round 67 (Rated for Div. 2)")

First of all, one crucial observation is that no person should come to the meeting later than $100$ minutes after receiving the message: the length of any simple path in the graph won't exceed $49$, and even if all organization members should choose the same path, we can easily make them walk alone if the first person starts as soon as he receives the message, the second person waits one minute, the third person waits two minutes, and so on.

Let's model the problem using mincost flows. First of all, we need to expand our graph: let's create $101$ "time layer" of the graph, where $i$-th layer represents the state of the graph after $i$ minutes have passed. The members of the organization represent the flow in this graph. We should add a directed edge from the source to every crossroad where some person lives, with capacity equal to the number of persons living near that crossroad (of course, this edge should lead into $0$-th time layer, since everyone starts moving immediately). To model that some person can wait without moving, we can connect consecutive time layers: for every vertex representing some crossroad $x$ in time layer $i$, let's add a directed edge with infinite capacity to the vertex representing the same crossroad in the layer $i + 1$. To model that people can walk along the street, for every street $(x, y)$ and every layer $i$ let's add several edges going from crossroad $x$ in the layer $i$ to crossroad $y$ in the layer $i + 1$ (the costs and the capacities of these edges will be discussed later). And to model that people can attend the meeting, for each layer $i$ let's add a directed edge from the vertex representing crossroad $1$ in that layer to the sink (the capacity should be infinite, the cost should be equal to $ci$).

Okay, if we find a way to model the increase of discontent from the companies of people going along the same street at the same moment, then the minimum cost of the maximum flow in this network is the answer: maximization of the flow ensures that all people attend the meeting, and minimization of the cost ensures that the discontent is minimized. To model the increase of discontent from the companies of people, let's convert each edge $(x, y)$ of the original graph into a large set of edges: for each layer $i$, let's add $k$ edges with capacity $1$ from the crossroad $x$ in the layer $i$ to the crossroad $y$ in the layer $i + 1$. The first edge should have the cost equal to $d$, the second edge — equal to $3d$, the third — $5d$ and so on, so if we choose $z$ minimum cost edges between this pair of nodes, their total cost will be equal to $d z^2$. Don't forget that each edge in the original graph is undirected, so we should do the same for the node representing $y$ in layer $i$ and the node representing $x$ in layer $i + 1$.

Okay, now we have a network with $\approx 5000$ vertices and $\approx 500000$ edges, and we have to find the minimum cost flow in it (and the total flow does not exceed $50$). Strangely enough, we could not construct a test where the basic implementation of Ford-Bellman algorithm with a queue runs for a long time (but perhaps it's possible to fail it). But if you are not sure about its complexity, you can improve it with the following two optimizations:

* use Dijkstra with potentials instead of Ford-Bellman with queue;
* compress all edges that connect the same nodes of the network into one edge with varying cost.
 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

struct edge
{
	int y, c, f, cost;
	edge() {};
	edge(int y, int c, int f, int cost) : y(y), c(c), f(f), cost(cost) {};
};

vector<edge> e;

const int N = 14043;
vector<int> g[N];

long long ans = 0;
long long d[N];
int p[N];
int pe[N];
int inq[N];

const long long INF64 = (long long)(1e18);

int s = N - 2;
int t = N - 1;

int rem(int x)
{
	return e[x].c - e[x].f;
}

void push_flow()
{
	for(int i = 0; i < N; i++) d[i] = INF64, p[i] = -1, pe[i] = -1, inq[i] = 0;
	d[s] = 0;
	queue<int> q;
	q.push(s);
	inq[s] = 1;
	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		inq[k] = 0;
		for(auto x : g[k])
		{
			if(!rem(x)) continue;
			int c = e[x].cost;
			int y = e[x].y;
			if(d[y] > d[k] + c)
			{
				d[y] = d[k] + c;
				p[y] = k;
				pe[y] = x;
				if(inq[y] == 0)
				{
					inq[y] = 1;
					q.push(y);
				}
			}
		}
	}
	int cur = t;
//	vector<int> zz(1, cur);
	while(cur != s)
	{
		e[pe[cur]].f++;
		e[pe[cur] ^ 1].f--;
		cur = p[cur];
//		zz.push_back(cur);
	}
//	reverse(zz.begin(), zz.end());
//	for(auto x : zz) cerr << x << " ";
//	cerr << endl;
	ans += d[t];
}

void add_edge(int x, int y, int c, int cost)
{
	g[x].push_back(e.size());
	e.push_back(edge(y, c, 0, cost));
	g[y].push_back(e.size());
	e.push_back(edge(x, 0, 0, -cost));
}

int main()
{
	int n, m, k, c, d;
	cin >> n >> m >> k >> c >> d;
	for(int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		--x;
		add_edge(s, x, 1, 0);
	}
	int tt = 101;
	for(int i = 0; i < tt; i++)
		add_edge(0 + i * n, t, k, i * c);
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		for(int i = 0; i < tt - 1; i++)
			for(int j = 0; j < k; j++)
				add_edge(x + i * n, y + i * n + n, 1, d * (j * 2 + 1));
		for(int i = 0; i < tt - 1; i++)
			for(int j = 0; j < k; j++)
				add_edge(y + i * n, x + i * n + n, 1, d * (j * 2 + 1));
 	}
 	for(int i = 0; i < n; i++)
 		for(int j = 0; j < tt - 1; j++)
 			add_edge(i + j * n, i + j * n + n, k, 0);
 	for(int i = 0; i < k; i++)
 		push_flow();
 	cout << ans << endl;
}
```
