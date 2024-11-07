# Tutorial

[1437A - Marketing Scheme](../problems/A._Marketing_Scheme.md "Educational Codeforces Round 97 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1437A - Marketing Scheme](../problems/A._Marketing_Scheme.md "Educational Codeforces Round 97 (Rated for Div. 2)")

Note that if $\left\lfloor \frac{l}{a} \right\rfloor < \left\lfloor \frac{r}{a} \right\rfloor$ then exists such $k \cdot a$ that $l \le ka \le r$ and, obviously, a customer, who wants to buy $ka$ cans won't buy more than he wants.

That's why $\left\lfloor \frac{l}{a} \right\rfloor = \left\lfloor \frac{r}{a} \right\rfloor$ and we can rephrase our task as finding such $a$ that $\frac{a}{2} \le (l \bmod a) \le (r \bmod a) < a$. The longer the segment $[\frac{a}{2}, a)$ is the better and the maximum we can take is $a = 2l$. 

As a result, we need to check that $r < a \leftrightarrow r < 2l$.

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (l, r) = readLine()!!.split(' ').map { it.toInt() }
        println(if (2 * l > r) "YES" else "NO");
    }
}
```
[1437B - Reverse Binary Strings](../problems/B._Reverse_Binary_Strings.md "Educational Codeforces Round 97 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1437B - Reverse Binary Strings](../problems/B._Reverse_Binary_Strings.md "Educational Codeforces Round 97 (Rated for Div. 2)")

We need to make our string alternating, i. e. $s_i \neq s_{i + 1}$. When we reverse substring $s_l \dots s_r$, we change no more than two pairs $s_{l - 1}, s_l$ and $s_r, s_{r + 1}$. Moreover, one pair should be a consecutive pair 00 and other — 11. So, we can find lower bound to our answer as maximum between number of pairs of 00 and number of pairs of 11. And we can always reach this lower bound, by pairing 00 with 11 or with left/right border of $s$. 

Another way to count the answer is next: suppose we want to make string 0101..., then let's transform $s$ to 1 + $s$ + 0. For example, if $s =$ 0110, we will get 101100. We claim that after this transformation, we will have equal number of 00 and 11, so the answer is the number of consecutive pairs of the same character divided by two. The answer is the minimum between answers for 1 + $s$ + 0 and 0 + $s$ + 1.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

const int INF = int(1e9);

int n;
string s;

inline bool read() {
	if(!(cin >> n >> s))
		return false;
	return true;
}

int cntSame(const string &s) {
	int ans = 0;
	fore (i, 1, sz(s))
		ans += (s[i - 1] == s[i]);
	assert(ans % 2 == 0);
	return ans / 2;
}

inline void solve() {
	int ans = INF;
	fore (k, 0, 2) {
		ans = min(ans, cntSame(string(1, '0' + k) + s + string(1, '1' - k)));
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc; cin >> tc;
	while(tc--) {
		assert(read());
		solve();
	}
	return 0;
}
```
[1437C - Chef Monocarp](../problems/C._Chef_Monocarp.md "Educational Codeforces Round 97 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1437C - Chef Monocarp](../problems/C._Chef_Monocarp.md "Educational Codeforces Round 97 (Rated for Div. 2)")

There are a lot of solutions for the problem. Let's start with the easiest one.

Sort the dishes in the non-decreasing order of their optimal time. I claim that there is an optimal answer such that the times $T$ for each dish go in the increasing order. That's not too hard to prove (something along the lines of if there are two dishes $i$ and $j$ such that $t_i < t_j$ and $T_i > T_j$, then $|t_i - T_i| + |t_j - T_j|$ is always greater than $|t_i - T_j| + |t_j - T_i|$).

So we can use dynamic programming to solve the task. Let $dp[i][T]$ be the minimum total unpleasant value if $i$ dishes are processed and the current minute is $T$. For the transitions you can either put out the current dish $i$ at the current minute $T$ or wait one more minute. Notice that you'll never need more time than $2n$ minutes (the actual constraint is even smaller, just consider the case with all dishes times equal to $n$).

So that dp works in $O(n^2)$.

The other possible solution is matching. Let's build the following graph. The left partition is $n$ vertices corresponding to dishes. The right partition is $2n$ vertices corresponding to minutes (as we saw in previous solution $2n$ is always enough). Now add the edges between all dishes and all minutes with the cost of their absolute different. Finally, find the minimum cost maximum matching. That can be done with MCMF or Hungarian algorithm.

Both should pass pretty easily.

There's also a solution in $O(n \log n)$ involving the slope trick.

 **Solution 1 (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int INF = 1e9;

void solve(){
	int n;
	scanf("%d", &n);
	vector<int> t(n);
	forn(i, n){
		scanf("%d", &t[i]);
		--t[i];
	}
	sort(t.begin(), t.end());
	vector<vector<int>> dp(n + 1, vector<int>(2 * n, INF));
	dp[0][0] = 0;
	forn(i, n + 1) forn(j, 2 * n - 1) if (dp[i][j] < INF){
		if (i < n) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(t[i] - j));
		dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
	}
	printf("%dn", dp[n][2 * n - 1]);
}

int main() {
	int q;
	scanf("%d", &q);
	forn(_, q) solve();
}
```
 **Solution 2 (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

template<typename T>
T hungarian(const vector<vector<T>>& cost) {
    const T INF = numeric_limits<T>::max();
    int n = cost.size(), m = cost[0].size();
    vector<T> u(n + 1), v(m + 1), dist(m + 1);
    vector<int> p(m + 1), way(m + 1), used(m + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        fill(dist.begin(), dist.end(), INF);
        do {
            used[j0] = i;
            int i0 = p[j0], j1 = -1;
            T delta = INF;
            for (int j = 1; j <= m; ++j) if (used[j] != i) {
                T cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                if (cur < dist[j]) dist[j] = cur, way[j] = j0;
                if (dist[j] < delta) delta = dist[j], j1 = j;
            }
            forn(j, m + 1) {
                if (used[j] == i) u[p[j]] += delta, v[j] -= delta;
                else dist[j] -= delta;
            }
            j0 = j1;
        } while (p[j0] != 0);
        for (int j1; j0; j0 = j1)
            p[j0] = p[j1 = way[j0]];
    }
    
    return -v[0];
}

void solve(){
	int n;
	scanf("%d", &n);
	vector<int> t(n);
	forn(i, n){
		scanf("%d", &t[i]);
		--t[i];
	}
	vector<vector<int>> cost(n, vector<int>(2 * n));
	forn(i, n) forn(j, 2 * n) cost[i][j] = abs(t[i] - j);
	printf("%dn", hungarian(cost));
}

int main() {
	int q;
	scanf("%d", &q);
	forn(_, q) solve();
}
```
[1437D - Minimal Height Tree](../problems/D._Minimal_Height_Tree.md "Educational Codeforces Round 97 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1437D - Minimal Height Tree](../problems/D._Minimal_Height_Tree.md "Educational Codeforces Round 97 (Rated for Div. 2)")

Due to the nature of BFS, the visiting order consists of several segments: first goes root (has depth $0$), then all vertices with depth $1$, then all vertices with depth $2$ and so on. Since any vertex of depth $d$ is a child of vertex of depth $d - 1$, then it's optimal to make the number of vertices with depth $1$ as many as possible, then make the number of vertices with depth $2$ as many as possible and so on.

Since children of a vertex are viewed in ascending order and form a segment in visiting order then an arbitrary segment of visiting order can be children of the same vertex iff elements in the segments are in ascending order.

These two observations lead us to a greedy strategy: $a_1 = 1$, then let's find the maximum $r_1$ that segment $a_2, \dots, a_{r_1}$ is in ascending order — they will be the children of $a_1$ and the only vertices of depth $1$. Next search the maximum $r_2$ such that segment $a_{r_1 + 1}, \dots, a_{r_2}$ is in ascending order — they will be the children of $a_2$, and so on. It's easy to see that this strategy maximizes the number of vertices of each depth level, so minimize the height of the tree.

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
const li INF64 = li(1e18);

int n;
vector<int> a;

inline bool read() {
	if(!(cin >> n))
		return false;
	a.resize(n);
	fore (i, 0, n)
		cin >> a[i];
	return true;
}

inline void solve() {
	vector<int> h(n, INF);
	h[0] = 0;
	int lst = 0;
	fore (i, 1, n) {
		if (i - 1 > 0 && a[i - 1] > a[i])
			lst++;
		h[i] = h[lst] + 1;
	}
	cout << h[n - 1] << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc; cin >> tc;
	while(tc--) {
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
[1437E - Make It Increasing](../problems/E._Make_It_Increasing.md "Educational Codeforces Round 97 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1437E - Make It Increasing](../problems/E._Make_It_Increasing.md "Educational Codeforces Round 97 (Rated for Div. 2)")

First, let's solve the problem without blocked positions.

Let's look at the array $b_i = a_i - i$. Obviously, if $a$ strictly increases, then $b$ does not decrease, and vice versa. Now we have to find the maximum number of positions in the $b$ array that can be left unchanged. And you can always choose an integer that will not break the non-decreasing array $b$ for the rest of positions. This problem can be solved in $O(n \log{n})$ by analogy with the largest increasing subsequence, but now you can take equal elements.

Now you can realize that the segments between two blocked positions do not depend on each other, and the initial problem can be solved as the problem described above. All that remains is to check that all blocked positions do not break the strict array increment.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int N = 500 * 1000 + 13;

int n, k;
int a[N], b[N];

int main() {
	scanf("%d%d", &n, &k);
	forn(i, n) scanf("%d", &a[i + 1]);
	a[0] = -1e9;
	a[n + 1] = 2e9;
	forn(i, n + 2) a[i] -= i;
	forn(i, k) scanf("%d", &b[i + 1]);
	b[k + 1] = n + 1;
	
	int ans = 0;
	forn(i, k + 1) {
		int l = b[i], r = b[i + 1];
		if (a[l] > a[r]) {
			puts("-1");
			return 0;
		}
		vector<int> lis;
		for (int j = l + 1; j < r; ++j) if (a[l] <= a[j] && a[j] <= a[r]) {
			auto pos = upper_bound(lis.begin(), lis.end(), a[j]);
			if (pos == lis.end()) lis.push_back(a[j]);
			else *pos = a[j];
		}
		ans += (r - l - 1) - int(lis.size());
	}
	
	printf("%dn", ans);
}
```
[1437F - Emotional Fishermen](../problems/F._Emotional_Fishermen.md "Educational Codeforces Round 97 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1437F - Emotional Fishermen](../problems/F._Emotional_Fishermen.md "Educational Codeforces Round 97 (Rated for Div. 2)")

First of all, sort the fishermen so it is easier to consider them in ascending order.

The key observation that allows us to solve the problem is the following: there will be an increasing sequence of happy fishermen, and all other fishermen will be unhappy.

Consider the fisherman $i$ which belongs to the increasing sequence. Let's analyze which fisherman will be next to it in the order. It is either a fisherman that will be happy, or a fisherman that will be sad. In the first case, the fish caught by this fisherman must have a size of at least $2a_i$, in the second case — at most $\frac{a_i}{2}$.

The first case will be considered later. For the second case, if we know the number of fishermen that were already placed in the order, we know that all of them (except the $i$-th one) belong to the "sad" category (that is, the fish of every already placed fisherman, except for the $i$-th one, is at least two times smaller than the fish of the $i$-th fisherman). So, if we have already placed $j$ fishermen, the last happy fisherman was the $i$-th one, and we want to place a sad fisherman, then the number of ways to choose this sad fisherman is exactly $cntLess(i) - j + 1$, where $cntLess(i)$ is the number of fishermen $k$ such that $2 a_k \le a_i$.

If we can handle the first case, this observation will allow us to solve the problem with dynamic programming. Let $dp_{i, j}$ be the number of ways to choose $j$ first fishermen in the order so that the $i$-th fisherman is the last happy one. The case when the next fisherman is sad can be handled with a transition to the state $dp_{i, j + 1}$ (don't forget to multiply by the number of ways to choose the next sad fisherman, as described earlier). 

What about the case when the next fisherman is happy? We should iterate on the fisherman $k$ such that $a_k \ge 2a_i$ and transition from $dp_{i, j}$ to $dp_{k, j + 1}$, but this part works in $O(n^3)$. To get an $O(n^2)$ solution, we have to speed it up with prefix sums or something like that.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 5043;
const int MOD = 998244353;

int dp[N][N];
int pdp[N][N];
int cntLess[N];
int lastLess[N];
int a[N];
int n;

int add(int x, int y)
{
 	x += y;
 	while(x >= MOD) x -= MOD;
 	while(x < 0) x += MOD;
 	return x;
}

int sub(int x, int y)
{
 	return add(x, MOD - y);
}

int mul(int x, int y)
{
 	return (x * 1ll * y) % MOD;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n; i++)
	{
	 	cntLess[i] = 0;
	 	lastLess[i] = -1;
	 	for(int j = 0; j < n; j++)
	 		if(a[j] * 2 <= a[i])
	 		{
	 		 	lastLess[i] = j;
	 		 	cntLess[i]++;
	 		}
	}
	for(int i = 0; i < n; i++)
	{
	 	dp[i][1] = 1;
	 	pdp[i + 1][1] = add(pdp[i][1], dp[i][1]);
	}
	for(int k = 2; k <= n; k++)
		for(int i = 0; i < n; i++)
		{
			if(cntLess[i] + 1 >= k)
		 		dp[i][k] = add(mul(dp[i][k - 1], add(cntLess[i], sub(2, k))), pdp[lastLess[i] + 1][k - 1]);
		 	else
		 		dp[i][k] = 0;
		 	//cerr << i << " " << k << " " << dp[i][k] << endl;                                
		 	pdp[i + 1][k] = add(pdp[i][k], dp[i][k]);
		}

	cout << dp[n - 1][n] << endl;
}
```
[1437G - Death DBMS](../problems/G._Death_DBMS.md "Educational Codeforces Round 97 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1437G - Death DBMS](../problems/G._Death_DBMS.md "Educational Codeforces Round 97 (Rated for Div. 2)")

I'm feeling extremely amused by the power of Aho-Corasick lately, so I will describe two solutions of this problem with it. Feel free to point out how cool you are solving the task with hashes or some suffix structure but Aho solutions will still be cooler. I also want to mention I'm quite proud of the name I came up with for that task :)

First, let's assume that the words in the dictionary are unique.

Build an Aho-Corasick automaton on the dictionary. Then build the tree of its suffix links.

For the first solution you can use the fact that there are not a lot of words in the dictionary that can end in each position. To be exact, at most one word per unique word length. Thus, that's bounded by the square root of the total length.

For that reason you can iterate over all the words that end in all positions of the queries in $O(q \sqrt n)$. How to do that fast? For each vertex of the automaton precalculate the closest vertex up the suffix link tree that's a terminal. Feed the query word into the automaton and from each vertex you stay at just jump up the tree until you reach the root. Take the maximum value over all the visited terminals.

The second solution actually involves an extra data structure on top of that. No, it's not HLD. You are boring for using it.

Let's abuse the fact that you are allowed to solve the problem fully offline. For each word you can save the list of pairs (time, value) of the times the value of the word changed. For each vertex of the automaton you can save all the times that vertex has been queried from.

Now traverse the tree with dfs. When you enter the vertex, you want to apply all the updates that are saved for the words that are terminals here. What are the updates? From the list we obtained for a word you can generate such triples $(l, r, x)$ that this word had value $x$ from query $l$ to query $r$. Don't forget the $0$ value from $0$ to the first update to this word. Then ask all the queries. Then go to children. When you exit the vertex, you want all the updates to be gone. Well, there is a trick for these kinds of operations, it's called rollbacks. 

Maintain a segment tree over the query times, the $i$-th leaf should store the maximum value during the $i$-th query. The update operation updates the range with the new possible maximum. How to avoid using lazy propagation with such updates? Well, on point query you can collect all the values from the segtree nodes you visit on your way down. That way you don't have to push the updates all the way to the leaves. Not that it matters that much but the number of values to be saved for future rollbacks is decreased dramatically.

That solution works in $O((n + q) \log q)$.

 **Solution 1 (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int AL = 26;

vector<int> val;
vector<int> pos;

struct aho_corasick {
	struct node {
		map<int, int> nxt, go;
		int p, pch;
		int suf, ssuf;
		multiset<int> vals;
		bool term;
		
		node() {
			nxt.clear();
			go.clear();
			suf = ssuf = -1;
			term = false;
			vals.clear();
			p = -1, pch = -1;
		}
	};

	vector<node> nodes;
	
	aho_corasick() {
		nodes = vector<node>(1, node());
	}

	int add(const string& s) {
		int v = 0;
		forn(i, s.size()) {
			int c = s[i] - 'a';
			if (!nodes[v].nxt.count(c)) {
				nodes.push_back(node());
				nodes[v].nxt[c] = int(nodes.size()) - 1;
				nodes.back().p = v;
				nodes.back().pch = c;
			}
			v = nodes[v].nxt[c];
		}
		nodes[v].term = true;
		nodes[v].vals.insert(0);
		return v;
	}
	
	int feed(const string &s){
		int v = 0;
		int ans = -1;
		forn(i, s.size()){
			int c = s[i] - 'a';
			v = go(v, c);
			int u = v;
			while (u != 0){
				if (!nodes[u].vals.empty())
					ans = max(ans, *nodes[u].vals.rbegin());
				u = ssuf(u);
			}
		}
		return ans;
	}
	
	int go(int v, int c) {
		if (nodes[v].go.count(c))
			return nodes[v].go[c];
		if (nodes[v].nxt.count(c))
			return nodes[v].go[c] = nodes[v].nxt[c];
		if (v == 0)
			return nodes[v].go[c] = 0;
		return nodes[v].go[c] = go(suf(v), c);
	}
	
	int suf(int v) {
		if (nodes[v].suf != -1)
			return nodes[v].suf;
		if (v == 0 || nodes[v].p == 0)
			return nodes[v].suf = 0;
		return nodes[v].suf = go(suf(nodes[v].p), nodes[v].pch);
	}
	
	int ssuf(int v) {
		if (nodes[v].ssuf != -1)
			return nodes[v].ssuf;
		if (v == 0 || nodes[v].p == 0)
			return nodes[v].ssuf = 0;
		int s = suf(v);
		if (nodes[s].term)
			return nodes[v].ssuf = s;
		return nodes[v].ssuf = ssuf(s);
	}
};

aho_corasick ac;

int main() {
	int n, m;
	ios::sync_with_stdio(!cin.tie(0));
	cin >> n >> m;
	pos.resize(n);
	val.resize(n, 0);
	
	vector<int> tp2;
	
	ac = aho_corasick();
	
	forn(i, n){
		string s;
		cin >> s;
		pos[i] = ac.add(s);
	}
	
	forn(i, m){
		int t;
		cin >> t;
		if (t == 1){
			int j, x;
			cin >> j >> x;
			--j;
			ac.nodes[pos[j]].vals.erase(ac.nodes[pos[j]].vals.find(val[j]));
			val[j] = x;
			ac.nodes[pos[j]].vals.insert(val[j]);
		}
		else{
			string q;
			cin >> q;
			printf("%dn", ac.feed(q));
		}
	}
	
	return 0;
}
```
 **Solution 2 (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int AL = 26;
vector<vector<pair<int, int>>> upd;
vector<int> ans;
int n, m;

struct segtree{
	vector<int*> where;
	vector<int> vals;
	vector<int> t;
	int n;
	
	segtree(){}
	
	segtree(int n) : n(n){
		t.assign(4 * n, -1);
		where.clear();
		vals.clear();
	}
	
	void updh(int v, int l, int r, int L, int R, int val){
		if (L >= R)
			return;
		if (l == L && r == R){
			where.push_back(&t[v]);
			vals.push_back(t[v]);
			t[v] = max(t[v], val);
			return;
		}
		int m = (l + r) / 2;
		updh(v * 2, l, m, L, min(m, R), val);
		updh(v * 2 + 1, m, r, max(m, L), R, val);
	}
	
	void upd(int l, int r, int val){
		updh(1, 0, n, l, r, val);
	}
	
	int geth(int v, int l, int r, int pos){
		if (l == r - 1)
			return t[v];
		int m = (l + r) / 2;
		if (pos < m)
			return max(t[v], geth(v * 2, l, m, pos));
		return max(t[v], geth(v * 2 + 1, m, r, pos));
	}
	
	int get(int pos){
		return geth(1, 0, n, pos);
	}
	
	void rollback(){
		*where.back() = vals.back();
		where.pop_back();
		vals.pop_back();
	}
};

segtree st;

struct aho_corasick {
	struct node {
		map<int, int> nxt, go;
		int p, pch;
		int suf, ssuf;
		vector<int> term, qs;
		
		node() {
			nxt.clear();
			go.clear();
			suf = ssuf = -1;
			term.clear();
			p = -1, pch = -1;
			qs.clear();
		}
	};

	vector<node> nodes;
	vector<vector<int>> g;
	
	aho_corasick() {
		nodes = vector<node>(1, node());
	}

	void add(const string& s, int id) {
		int v = 0;
		forn(i, s.size()) {
			int c = s[i] - 'a';
			if (!nodes[v].nxt.count(c)) {
				nodes.push_back(node());
				nodes[v].nxt[c] = int(nodes.size()) - 1;
				nodes.back().p = v;
				nodes.back().pch = c;
			}
			v = nodes[v].nxt[c];
		}
		nodes[v].term.push_back(id);
	}
	
	void feed(const string &s, int id){
		int v = 0;
		forn(i, s.size()){
			int c = s[i] - 'a';
			v = go(v, c);
			nodes[v].qs.push_back(id);
		}
	}
	
	int go(int v, int c) {
		if (nodes[v].go.count(c))
			return nodes[v].go[c];
		if (nodes[v].nxt.count(c))
			return nodes[v].go[c] = nodes[v].nxt[c];
		if (v == 0)
			return nodes[v].go[c] = 0;
		return nodes[v].go[c] = go(suf(v), c);
	}
	
	int suf(int v) {
		if (nodes[v].suf != -1)
			return nodes[v].suf;
		if (v == 0 || nodes[v].p == 0)
			return nodes[v].suf = 0;
		return nodes[v].suf = go(suf(nodes[v].p), nodes[v].pch);
	}
	
	void build_tree() {
		g.resize(nodes.size());
		forn(v, nodes.size()) {
			int u = suf(v);
			if (v != u)
				g[u].push_back(v);
		}
	}
	
	void dfs(int v){
		int cur = st.where.size();
		for (auto i : nodes[v].term){
			int lst = m;
			for (auto it : upd[i]){
				st.upd(it.first, lst, it.second);
				lst = it.first;
			}
			st.upd(0, lst, 0);
		}
		for (auto j : nodes[v].qs){
			ans[j] = max(ans[j], st.get(j));
		}
		for (int u : g[v]){
			dfs(u);
		}
		int nw = st.where.size();
		forn(_, nw - cur){
			st.rollback();
		}
	}
};

aho_corasick ac;

int main() {
	ios::sync_with_stdio(!cin.tie(0));
	cin >> n >> m;
	upd.resize(n);
	ans.resize(m, -1);
	
	vector<int> tp2;
	
	ac = aho_corasick();
	st = segtree(m);
	
	forn(i, n){
		string s;
		cin >> s;
		ac.add(s, i);
	}
	forn(i, m){
		int t;
		cin >> t;
		if (t == 1){
			int j, x;
			cin >> j >> x;
			--j;
			upd[j].push_back(make_pair(i, x));
		}
		else{
			string q;
			cin >> q;
			ac.feed(q, i);
			tp2.push_back(i);
		}
	}
	forn(i, n){
		reverse(upd[i].begin(), upd[i].end());
	}
	
	ac.build_tree();
	ac.dfs(0);
	for (auto it : tp2)
		cout << ans[it] << "n";
	return 0;
}
```
