# Tutorial

[1366A - Shovels and Swords](../problems/A._Shovels_and_Swords.md "Educational Codeforces Round 89 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1366A - Shovels and Swords](../problems/A._Shovels_and_Swords.md "Educational Codeforces Round 89 (Rated for Div. 2)")

There are three constraints on the number of emeralds:

1. the number of emeralds can't be greater than $a$;
2. the number of emeralds can't be greater than $b$;
3. the number of emeralds can't be greater than $\frac{a+b}{3}$.

So the answer is $\min(a, b, \frac{a+b}{3})$.

 **Solution (Roms)**
```cpp
for _ in range(int(input())):
    l, r = map(int, input().split())
    print(min(l, r, (l + r) // 3))
```
[1366B - Shuffle](../problems/B._Shuffle.md "Educational Codeforces Round 89 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1366B - Shuffle](../problems/B._Shuffle.md "Educational Codeforces Round 89 (Rated for Div. 2)")

Let's consider how the set of possible indices where the $1$ can be changes. Initially, only one index is correct — $x$. After performing an operation $l, r$ such that $x < l$ or $x > r$ this set does not change. But after performing an operation $l, r$ such that $l \le x \le r$ we should insert the elements $\{l, l+1, l+2, \dots, r-1, r\}$ into this set, if they are not present. 

Now consider how the set $\{L, L+1, L+2, \dots, R-1, R\}$ changes. If segments $[l, r]$ and $[L, R]$ do not share any indices, there are no changes — but if they do, the set turns into $\{ \min(l, L), \min(l, L)+1, \min(l, L)+2, \dots, \max(r, R)-1, \max(r, R) \}$.

So the set of reachable indices is always a segment of numbers, and to process an operation, we should check whether the segment from operation intersects with the segment of indices we have — and if it is true, unite them.

 **Solution (Roms)**
```cpp
for _ in range(int(input())):
    n, x, m = map(int, input().split())
    l, r = x, x
    for _ in range(m):
        L, R = map(int, input().split())
        if max(l, L) <= min(r, R):
            l = min(l, L)
            r = max(r, R)
            
    print(r - l + 1)
```
[1366C - Palindromic Paths](../problems/C._Palindromic_Paths.md "Educational Codeforces Round 89 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1366C - Palindromic Paths](../problems/C._Palindromic_Paths.md "Educational Codeforces Round 89 (Rated for Div. 2)")

Let's group the cells by their distance from the starting point: the group $0$ consists of a single cell $(1, 1)$; the group $1$ consists of the cells $(1, 2)$ and $(2, 1)$, and so on. In total, there are $n + m - 1$ groups.

Let's analyze the groups $k$ and $n + m - 2 - k$. There are two cases:

* if $k = 0$ or $n + m - 2 - k = 0$, then we are looking at the starting cell and the ending cell, and their contents should be equal;
* otherwise, suppose two cells $(x, y)$ and $(x + 1, y - 1)$ belong to the same group. We can easily prove that the contents of these two cells should be equal (for example, by analyzing two paths that go through cell $(x + 1, y)$ and coincide after this cell, but one goes to $(x + 1, y)$ from $(x, y)$, and another — from $(x + 1, y - 1)$) — and, using induction, we can prove that the contents of all cells in a group should be equal. And since the paths should be palindromic, the contents of the group $k$ should be equal to the contents of the group $n + m - 2 - k$.

So, in each pair of groups, we should calculate the number of $1$'s and $0$'s, and choose which of them to change. Note that if $n + m$ is even, the central group has no pair, so it should not be modified.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	vector<vector<int> > cnt(n + m - 1, vector<int>(2));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cnt[i + j][a[i][j]]++;
	int ans = 0;
	for(int i = 0; i <= n + m - 2; i++)
	{
		int j = n + m - 2 - i;
		if(i <= j) continue;
		ans += min(cnt[i][0] + cnt[j][0], cnt[i][1] + cnt[j][1]);
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
		solve();
}
```
[1366D - Two Divisors](../problems/D._Two_Divisors.md "Educational Codeforces Round 89 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1366D - Two Divisors](../problems/D._Two_Divisors.md "Educational Codeforces Round 89 (Rated for Div. 2)")

Firstly, for the fast factorization of given $a_i$, let's use Sieve of Eratosthenes: let's for each value $val \le 10^7$ calculate its minimum prime divisor $minDiv[val]$ in the same manner as the sieve do. Now we can factorize each $a_i$ in $O(\log{a_i})$ time by separating its prime divisors one by one using precalculated array $minDiv$.

Suppose, we have a factorization $a_i = p_1^{s_1} p_2^{s_2} \cdot \ldots \cdot p_k^{s_k}$. If $k = 1$ then any divisor of $a_i$ is divisible by $p_1$ so do the sum of divisors. Obviously, the answer is $-1$ $-1$.

Otherwise, we can divide all prime divisors $p_i$ into two non-empty groups $\{p_1, p_2, \dots, p_x\}$ and $\{p_{x + 1}, \dots, p_k\}$ and take $d_1 = p_1 \cdot p_2 \cdot \ldots \cdot p_x$ and $d_2 = p_{x + 1} \cdot \ldots \cdot p_k$. Any division is valid (proof is below), so, for example, we can take $d_1 = p_1$ and $d_2 = p_2 \cdot \ldots \cdot p_k$.

Let's prove that if $d_1 = p_1 \cdot p_2 \cdot \ldots \cdot p_x$ and $d_2 = p_{x + 1} \cdot \ldots \cdot p_k$ then $\gcd(d_1 + d_2, a_i) = 1$. Let's look at any $p_i$. We can assume that $a_i \equiv 0 \mod p_i$ and (without loss of generality) $d_1 \equiv 0 \mod p_i$. But it means that $d_2 \not\equiv 0 \mod p_i$, then $d_1 + d_2 \equiv 0 + d_2 \equiv d_2 \not\equiv 0 \mod p_i$. In other words, there are no prime divisor of $a_i$ which divides $d_1 + d_2$, so the $\gcd(d_1 + d_2, a_i) = 1$.

Time complexity is $O(A \log{\log{A}} + n \log{A})$ for the sieve and finding answers ($A \le 10^7$).

 **Solution (adedalic)**
```cpp
fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map { it.toInt() }

    val minDiv = IntArray(1e7.toInt() + 2) { it }
    for (i in 2 until minDiv.size) {
        if (minDiv[i] != i)
            continue
        for (j in i until minDiv.size step i)
            minDiv[j] = minOf(minDiv[j], i)
    }

    fun getPrimeDivisors(v: Int): ArrayList<Int> {
        val ans = ArrayList<Int>()
        var curVal = v
        while (curVal != 1) {
            if (ans.isEmpty() || ans.last() != minDiv[curVal])
                ans.add(minDiv[curVal])
            curVal /= minDiv[curVal]
        }
        return ans
    }

    val d1 = IntArray(n)
    val d2 = IntArray(n)
    for (id in a.indices) {
        val list = getPrimeDivisors(a[id])
        if (list.size < 2) {
            d1[id] = -1
            d2[id] = -1
        } else {
            d1[id] = list[0]
            list.removeAt(0)
            d2[id] = list.reduce { s, t -> s * t }
        }
    }
    println(d1.joinToString(" "))
    println(d2.joinToString(" "))
}
```
[1366E - Two Arrays](../problems/E._Two_Arrays.md "Educational Codeforces Round 89 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1366E - Two Arrays](../problems/E._Two_Arrays.md "Educational Codeforces Round 89 (Rated for Div. 2)")

At first, let's reverse arrays $a$ and $b$. Now array $b$ is sorted in descending order.

Now let's find minimum index $x$ such that $a_x = b_1$. If there is no such index or if $\min\limits_{1 \le i \le x}a_i < b_1$ then the answer is $0$ (because minimum on any prefix of array $a$ will never be equal to $b_1$).

Otherwise, let's find the minimum index $y > x$ such that $a_y = b_2$. If there is no such index or if $\min\limits_{x \le i \le y}a_i < b_2$ then the answer is $0$. Also let's find the minimum index $mid > x$ such that $a_{mid} < b_1$ (it can't be greater than $y$). The first subarray starts in position $1$ and ends in any position $x, x + 1, x + 2, \dots, mid - 1$ (because if it ends in position $mid$ or further, then the minimum in the first subarray is greater than $b_1$). So there are $mid - x$ ways to split subarrays $1$ and $2$.

A similar approach can be used to calculate the number of ways to split the second and third subarrays and, so on.

After all, you have to check that minimum in the last subarray is equal to $b_m$ (otherwise the answer is $0$).

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int MOD = 998244353;

int mul(int a, int b) {
    return (a * 1LL * b) % MOD;
}

int n, m;
int a[N], b[N];

int main() {	
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < m; ++i) scanf("%d", b + i);
    
    reverse(a, a + n);
    reverse(b, b + m);
    a[n] = -1;
    
    int mn = a[0];
    int pos = 0;
    while (pos < n && mn > b[0]) {
        ++pos;
        mn = min(mn, a[pos]);
    }
    
    if (pos == n || mn < b[0]) {
       puts("0");
       return 0;
    }
    
    assert(mn == b[0]);
    int res = 1;
    int ib = 0;
    while (true) {
        assert(mn == b[ib]);
        if (ib == m - 1){
            if(*min_element(a + pos, a + n) != b[ib]) {
               puts("0");
               return 0;
            }
            break;
        }
        
        bool f = true;
        int npos = pos;
        while (npos < n && mn != b[ib + 1]) {
            ++npos;
            mn = min(mn, a[npos]);
            
            if (f && mn < b[ib]){
                f = false;
                res = mul(res, npos - pos);
            }
        }
        
        if (npos == n || mn != b[ib + 1]) {
            puts("0");
            return 0;
        }
        
        ++ib;
        pos = npos;
    }
    
    printf("%dn", res);
    return 0;
}
```
[1366F - Jog Around The Graph](../problems/F._Jog_Around_The_Graph.md "Educational Codeforces Round 89 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1366F - Jog Around The Graph](../problems/F._Jog_Around_The_Graph.md "Educational Codeforces Round 89 (Rated for Div. 2)")

Let's observe what does the maximum weight of some fixed length path look like. Among the edges on that path the last one has the maximum weight. If it wasn't then the better total weight could be achieved by choosing a bigger weight edge earlier and going back and forth on it for the same number of steps. It actually helps us arrive to a conclusion that all optimal paths look like that: some simple path to an edge and then back and forth movement on it.

Any simple path in the graph has its length at most $m$. Let's separate the queries into two parts.

$k < m$ will be handled in a straightforward manner. Let $dp[v][k]$ be the maximum weight of a path that ends in $v$ and has exactly $k$ edges in it. That's pretty easy to calculate in $(n+m) \cdot m$.

You can also think of this $dp$ as some kind of Ford-Bellman algorithm — let $d_v$ on the $k$-th step be the maximum weight of the path to $v$ of length $k$. Iterate over all edges and try to update $d_v$ and $d_u$ for each edge $(v, u)$ (that's what I do in my solution if you refer to it).

Now for $k \ge m$. There was a very common assumption that after a bit more steps some edge will become the most optimal and will stay the most optimal until the end of time. However, that "a bit" cut-off is in fact too high to rely on (it must be somewhere around $n \cdot max_w$).

So the best path of length exactly $m$ ending in each vertex $v$ is $dp[v][m]$. Let the maximum weight adjacent edge to vertex $v$ be $mx_v$. So the path of length $k$ will have weight $mx_v \cdot (k - m) + dp[v][m]$. Treat it like a line $kx + b$ with coefficients $mx_v$ and $dp[v][m]$.

How do determine which line is the best for some $k$? Sure, experienced participants will immediately answer "convex hull". Build a lower envelope of the convex hull of these lines. If $q$ was a little smaller than we could query with binary search for each $k$, the same how convex hull is usually used. 

We have to examine the hull further. Each line in it becomes the best in some point, then stays the best for some interval and then never appears the best again. What are these line changing points? Well, it's just the intersection point of the adjacent lines in the hull. So having these points and the parameters of the line we can calculate its contribution to the answer with a sum of arithmetic progression formula.

There were just $n$ lines in the hull so you can build the hull in any complexity, I think I saw up to $O(n^2 \log n)$ performances in the participants codes.

There is a cool solution that involves some kind of Divide&Conquer on these lines. I personally thought of it in a sense of traversing a Li-Chao tree without actually building it. If anyone wants to explain this solution, feel free to do it in comments.

Overall complexity: $O((n+m) \cdot m + n \log n)$.

 **Solution (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const long long INF = 1e18;
const int MOD = 1000'000'007;
const int inv2 = (MOD + 1) / 2;

struct edge{
	int v, u, w;
};

struct frac{
	long long x, y;
	frac(long long a, long long b){
		if (b < 0) a = -a, b = -b;
		x = a, y = b;
	}
};

bool operator <=(const frac &a, const frac &b){
	return a.x * b.y <= a.y * b.x;
}

struct line{
	long long m, c;
	frac intersectX(const line &l) { return frac(c - l.c, l.m - m); }
};

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return a * 1ll * b % MOD;
}

int calc(int a1, int d, int n){
	assert(n >= 0);
	return mul(mul(n, inv2), add(mul(2, a1), mul(add(n, -1), d)));
}

int main() {
	int n, m;
	long long q;
	scanf("%d%d%lld", &n, &m, &q);
	vector<edge> e(m);
	vector<int> hv(n);
	forn(i, m){
		scanf("%d%d%d", &e[i].v, &e[i].u, &e[i].w);
		--e[i].v, --e[i].u;
		hv[e[i].v] = max(hv[e[i].v], e[i].w);
		hv[e[i].u] = max(hv[e[i].u], e[i].w);
	}
	
	int ans = 0;
	vector<long long> d(n, -INF), nd(n);
	d[0] = 0;
	forn(val, m){
		long long mx = 0;
		forn(i, n)
			mx = max(mx, d[i]);
		if (val)
			ans = add(ans, mx % MOD);
		nd = d;
		forn(i, m){
			nd[e[i].v] = max(nd[e[i].v], d[e[i].u] + e[i].w);
			nd[e[i].u] = max(nd[e[i].u], d[e[i].v] + e[i].w);
		}
		d = nd;
	}
	
	vector<line> fin;
	forn(i, n) fin.push_back({hv[i], d[i]});
	sort(fin.begin(), fin.end(), [](const line &a, const line &b){
		if (a.m != b.m)
			return a.m < b.m;
		return a.c > b.c;
	});
	fin.resize(unique(fin.begin(), fin.end(), [](const line &a, const line &b){
		return a.m == b.m;
	}) - fin.begin());
	
	vector<line> ch;
	for (auto cur : fin){
		while (ch.size() >= 2 && cur.intersectX(ch.back()) <= ch.back().intersectX(ch[int(ch.size()) - 2]))
			ch.pop_back();
		ch.push_back(cur);
	}
	
	long long prv = 0;
	q -= m;
	forn(i, int(ch.size()) - 1){
		frac f = ch[i].intersectX(ch[i + 1]);
		if (f.x < 0) continue;
		long long lst = min(q, f.x / f.y);
		if (lst < prv) continue;
		ans = add(ans, calc((ch[i].c + ch[i].m * prv) % MOD, ch[i].m % MOD, lst - prv + 1));
		prv = lst + 1;
	}
	ans = add(ans, calc((ch.back().c + ch.back().m * prv) % MOD, ch.back().m % MOD, q - prv + 1));
	
	printf("%dn", ans);
	return 0;
}
```
[1366G - Construct the String](../problems/G._Construct_the_String.md "Educational Codeforces Round 89 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1366G - Construct the String](../problems/G._Construct_the_String.md "Educational Codeforces Round 89 (Rated for Div. 2)")

The core idea of the solution is the following dynamic programming: $dp_{i, j}$ is the minimum number of characters we have to delete if we considered a subsequence of $i$ first characters of $s$, and it maps to $j$ first characters of $t$.

There are three obvious transitions in this dynamic programming:

* we can go from $dp_{i, j}$ to $dp_{i + 1, j}$ by skipping $s_i$;
* if $s_i = t_j$, we can go from $dp_{i, j}$ to $dp_{i + 1, j + 1}$;
* if $s_i$ is a dot, we can go from $dp_{i, j}$ to $dp_{i + 1, j - 1}$.

Unfortunately, these transitions cannot fully handle the case when we want to put some character and then delete it (these transitions don't allow us to do it for any character, only for some specific ones in specific situations). To handle it, suppose we want to take the character $s_i$ and then delete it, and we model it as follows: there exists the fourth transition from $dp_{i,j}$ to $dp_{i+len_i, j}$ without deleting anything, where $len_i$ is the length of the shortest substring of $s$ starting from $i$ that becomes empty if we apply the function $f$ to it. This substring can be described as a regular bracket sequence, where opening brackets correspond to letters, and closing brackets — to dots. We can precalculate this substring for each $i$ in $O(n)$.

Why is this transition enough? Suppose we don't want to take some letter from this shortest substring in the optimal answer; since it is the shortest substring meeting these constraints, the number of letters on each prefix of it (excluding the substring itself) is greater than the number of dots, so we can instead skip the first letter and try applying this transition from $dp_{i + 1, j}$, so this case is handled. And skipping any dots from this shortest substring is also suboptimal since we have to get rid of the character $s_i$.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)

const int INF = 1e9;
const int N = 10010;

int n, m;
string s, t;
int dp[N][N];
int nxt[N];

int main() {
	cin >> s >> t;
	n = sz(s), m = sz(t);
	
	forn(i, n) if (s[i] != '.') {
		int bal = 0;
		nxt[i] = -1;
		fore(j, i, n) {
			if (s[j] == '.') --bal;
			else ++bal;
			if (bal == 0) {
				nxt[i] = j;
				break;
			}
		}
	}
	
	forn(i, n + 1) forn(j, m + 1)
		dp[i][j] = INF;
	dp[0][0] = 0;
	
	forn(i, n) forn(j, m + 1) {
		dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
		if (j < m && s[i] == t[j])
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
		if (s[i] != '.' && nxt[i] != -1)
			dp[nxt[i] + 1][j] = min(dp[nxt[i] + 1][j], dp[i][j]);
	}
	
	cout << dp[n][m] << endl;
}
```
