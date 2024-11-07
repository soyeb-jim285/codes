# Tutorial

[1101A - Minimum Integer](../problems/A._Minimum_Integer.md "Educational Codeforces Round 58 (Rated for Div. 2)")

 **Tutorial**
### [1101A - Minimum Integer](../problems/A._Minimum_Integer.md "Educational Codeforces Round 58 (Rated for Div. 2)")

There are two basic cases we have to consider: either the element we want to find is less than $l_i$, or it is greater than $r_i$.

In the first case, we are interested in $d_i$ itself: it is the minimum positive number divisible by $d_i$, and if it is less than $l_i$, then it is the answer.

In the second case, we have to find minimum element that is greater than $r_i$ and is divisible by $d_i$. This can be done as follows: we calculate the number of elements divisible by $d_i$ that are not greater than $r_i$ as $c = \lfloor \frac{r_i}{d_i} \rfloor$, and then we take $(c+1)$-th element, which is $d_i(c + 1)$.

 **Solution (BledDest)**
```cpp
q = int(input())
for i in range(q):
    l, r, d = map(int, input().split())
    if(d < l or d > r):
        print(d)
    else:
        print((r // d) * d + d)
```
[1101B - Accordion](../problems/B._Accordion.md "Educational Codeforces Round 58 (Rated for Div. 2)")

 **Tutorial**
### [1101B - Accordion](../problems/B._Accordion.md "Educational Codeforces Round 58 (Rated for Div. 2)")

No cases. No any special thoughts. Just greedy.

The solution consists of six steps: 

1. Remove the prefix of the string until the position of leftmost '[' character. If there is no such character, print -1;
2. Remove the prefix of the string until the position of leftmost ':' character. If there is no such character, print -1;
3. Reverse the string;
4. Remove the prefix of the string until the position of leftmost ']' character. If there is no such character, print -1;
5. Remove the prefix of the string until the position of leftmost ':' character. If there is no such character, print -1;
6. Print the number of '|' characters in the remaining string plus four.
 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

void rem(string &s, const string &c) {
	auto pos = s.find(c);
	if (pos == string::npos) {
		cout << -1 << endl;
		exit(0);
	}
	s.erase(0, pos + 1);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	string s;
	cin >> s;
	
	rem(s, "[");
	rem(s, ":");
	reverse(s.begin(), s.end());
	rem(s, "]");
	rem(s, ":");
	
	cout << count(s.begin(), s.end(), '|') + 4 << endl;
	
	return 0;
}
```
[1101C - Division and Union](../problems/C._Division_and_Union.md "Educational Codeforces Round 58 (Rated for Div. 2)")

 **Tutorial**
### [1101C - Division and Union](../problems/C._Division_and_Union.md "Educational Codeforces Round 58 (Rated for Div. 2)")

Let's prove that division possible if and only if union of all segments has two and more segments. 

If the union have at least two segments, then we can choose one of them and put all segments it contains in one group and other segments to another group. On the other hand, if we can divide all segments in two groups in such way that there are no pair from different group which intersects, then union of segments from the first group doesn't intersect union of segments from another and union of unions consists of several non-intersecting components.

How can it help? If union of segments consits of several segments then exists $x$ such that for any segment $[l_i, r_i]$ either $l_i \le r_i \le x$ or $x < l_i \le r_i$ and both parts are non-empty. Moreover, $x$ equals to one of $r_i$.

It leads us straight to one of possible solutions: sort all segments by $r_i$ in increasing order and for each $r_i$ we should check that $r_i < \min\limits_{i < j \le n}{l_j}$ (suffix minimum). If we've found such $r_i$ then all prefix goes to one group and suffix — to another.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<int, int> pt;

int n;
vector< pair<pt, int> > segs;

inline bool read() {
	if(!(cin >> n))
		return false;
	segs.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> segs[i].x.x >> segs[i].x.y;
		segs[i].y = i;
	}
	return true;
}

bool cmp(const pair<pt, int> &a, const pair<pt, int> &b) {
	if(a.x.y != b.x.y)
		return a.x.y < b.x.y;
	if(a.x.x != b.x.x)
		return a.x.x < b.x.x;
	return a.y < b.y;
}

inline void solve() {
	sort(segs.begin(), segs.end(), cmp);
	
	int mn = segs[n - 1].x.x;
	for(int i = n - 2; i >= 0; i--) {
		if(segs[i].x.y < mn) {
			vector<int> ts(n, 2);
			for(int id = 0; id <= i; id++)
				ts[segs[id].y] = 1;
			
			for(int t : ts)
				cout << t << ' ';
			cout << 'n';
				
			return;
		}
		mn = min(mn, segs[i].x.x);
	}
	cout << -1 << 'n';
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc;
	cin >> tc;
	
	while(tc--) {
		assert(read());
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
[1101D - GCD Counting](../problems/D._GCD_Counting.md "Educational Codeforces Round 58 (Rated for Div. 2)")

 **Tutorial**
### [1101D - GCD Counting](../problems/D._GCD_Counting.md "Educational Codeforces Round 58 (Rated for Div. 2)")

I know there exists $O(n \log MAXN)$ solution and author of the problem promises to tell it to you ([here he explained it](Tutorial.md?#comment-484152)). I'd love to tell easier to code and about the same time to work $O(n \log^2 MAXN)$ solution.

At first, notice that it is only enough to check the paths such that all vertices on it is divisible by some prime.

Let's for each $v$ calculate the path of the maximum length to pass through it. That means that one part of this path goes down to one child of it and another part goes down to another child.

For each vertex we will store the lengths of maximum paths through vertices with values divisible by each prime in $a_v$. That is $O(n \log MAXN)$ memory. To recalc the answer we will store all values of children nodes, sort them and update the answer with two pointers technique.

Don't forget about the case of $n = 1$!

Overall complexity: $O(n \log^2 MAXN)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 200 * 1000 + 13;

int n;
int a[N];
vector<int> g[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n - 1){
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		g[x].pb(y);
		g[y].pb(x);
	}
	return true;
}

vector<pt> dp[N];
int ans;

void calc(int v, int p = -1){
	vector<pt> chd;
	for (auto u : g[v]) if (u != p){
		calc(u, v);
		for (auto it : dp[u])
			chd.pb(it);
	}
	
	sort(all(chd));
	forn(i, sz(chd)){
		int j = i - 1;
		int mx1 = 0, mx2 = 0;
		while (j + 1 < sz(chd) && chd[j + 1].x == chd[i].x){
			++j;
			if (chd[j].y >= mx1)
				mx2 = mx1, mx1 = chd[j].y;
			else if (chd[j].y > mx2)
				mx2 = chd[j].y;
		}
		if (a[v] % chd[i].x == 0){
			ans = max(ans, mx1 + mx2 + 1);
			dp[v].pb(mp(chd[i].x, mx1 + 1));
			while (a[v] % chd[i].x == 0)
				a[v] /= chd[i].x;
		}
		else{
			ans = max(ans, mx1);
		}
		i = j;
	}
	
	for (int i = 2; i * i <= a[v]; ++i) if (a[v] % i == 0){
		dp[v].pb(mp(i, 1));
		ans = max(ans, 1);
		while (a[v] % i == 0)
			a[v] /= i;
	}
	
	if (a[v] > 1){
		dp[v].pb(mp(a[v], 1));
		ans = max(ans, 1);
	}
}

void solve() {
	forn(i, N) dp[i].clear();
	ans = 0;
	calc(0);
	printf("%dn", ans);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

#ifdef _DEBUG
	while(read()) {	
#else
	if (read()){
#endif
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}
```
[1101E - Polycarp's New Job](../problems/E._Polycarp's_New_Job.md "Educational Codeforces Round 58 (Rated for Div. 2)")

 **Tutorial**
### [1101E - Polycarp's New Job](../problems/E._Polycarp's_New_Job.md "Educational Codeforces Round 58 (Rated for Div. 2)")

Let's find the smallest wallet to fit all bills. One its side is the maximum side of any bill. Now we orient the bills in such a way that their longer side is put against this side of the wallet. The second side of the wallet is the maximum of the other sides. More formally, for set of bills $(a_1, b_1)$, $(a_2, b_2)$, ... ($a_i \le b_i$ for each $i$), the minimum wallet is ($max~a_i$, $max~b_i$).

The minimum wallet fits all sufficient wallets.

So the solution is maintaining the maximum of all $a_i$ and $b_i$ and checking if $h \ge a_i$ and $w \ge b_i$ ($h \le w$).

Choose your i/o functions wisely.

Overall complexity: $O(n)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int mxa = 0, mxb = 0;
	static char buf[5];
	forn(i, n){
		int x, y;
		scanf("%s%d%d", buf, &x, &y);
		if (x < y)
			swap(x, y);
		if (buf[0] == '+'){
			mxa = max(mxa, x);
			mxb = max(mxb, y);
		}
		else{
			puts(mxa <= x && mxb <= y ? "YES" : "NO");
		}
	}
}
```
[1101F - Trucks and Cities](../problems/F._Trucks_and_Cities.md "Educational Codeforces Round 58 (Rated for Div. 2)")

 **Tutorial**
### [1101F - Trucks and Cities](../problems/F._Trucks_and_Cities.md "Educational Codeforces Round 58 (Rated for Div. 2)")

First (bonus) solution: implement idea from Blogewoosh #6. Time complexity will be somewhat $O((q + \log{q} \log{\text{MAX}})n)$ and space complexity is $O(n + q)$.

Honest solution: Note, that for each truck lower bound on the answer is $\max(c_i \cdot (a[p_{j + 1}] - a[p_{j}])) = c_i \cdot \max(a[p_{j + 1}] - a[p_j])$, where $p_0 = s_i, p_1, p_2, \dots, p_{r_i + 1} = f_i$ is optimal partition of $[a[s_i], a[f_i]]$ on $r_i + 1$ segments (partition which minimize maximum length of segment) and doesn't depend on $c_i$ of truck.

So, it enough to calculate $d[l][r][k]$ — optimal partition of segment $[a[l], a[r]]$ on $k$ segments.

Let $opt[l][r][k]$ be position, where last segment starts in partition with value $d[l][r][k]$. Note, that $opt[l][r][k] \le opt[l][r + 1][k]$.

On the other hand, $d[l][r][k] = \min\limits_{l \le j \le r}(\max(d[l][j][k - 1], a[r] - a[j]))$. But $d[l][j][k - 1] \le d[l][j + 1][k - 1]$ and $a[r] - a[j] > a[r] - a[j + 1]$, then $\max(d[l][j][k - 1], a[r] - a[j])$ is somewhat "convex".

Finally, best $j$ is no more than $opt[l][r][k]$, And we can look at $j$ as second pointer (along with $r$ as first pointer). So we can for each $r$ move $j$ while answer "relaxes" (while answer is decreasing or staying same). In result, for each $l$ and $k$ there will be $O(n)$ operations in total.

Optimizing memory consumption is easy, if we notice that we can iterate over $l$ but not save it as state of dp.

In the end, time complexity is $O(n^3 + q)$ and space complexity is $O(n^2 + q)$.

 **Solution 1 (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

#define mp make_pair
#define pb push_back

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

const int INF = int(1e9);
const int N = 411;

int n, m;
int a[N];
vector< pair<pt, pt> > qs;

inline bool read() {
	if(!(cin >> n >> m))
		return false;
	fore(i, 0, n)
		cin >> a[i];
	qs.resize(m);
	fore(i, 0, m) {
		cin >> qs[i].x.x >> qs[i].x.y >> qs[i].y.x >> qs[i].y.y;
		qs[i].x.x--; qs[i].x.y--;
	}
	return true;
}

vector<int> ids[N];
int d[N][N];

inline void solve() {
	fore(i, 0, m)
		ids[qs[i].x.x].push_back(i);
	li ans = -1;
	
	fore(l, 0, n) {
		fore(r, l, n)
			d[0][r] = a[r] - a[l];
		
		fore(k, 1, n + 1) {
			int opt = l;
			fore(r, l, n) {
				while(opt < r && max(d[k - 1][opt], a[r] - a[opt]) >= max(d[k - 1][opt + 1], a[r] - a[opt + 1]))
					opt++;
				
				d[k][r] = max(d[k - 1][opt], a[r] - a[opt]);
			}
		}
		
		for(int id : ids[l])
			ans = max(ans, d[qs[id].y.y][qs[id].x.y] * 1ll * qs[id].y.x);
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
 **Solution 2 (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

#define mp make_pair
#define pb push_back

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const int N = 411;

int n, m;
int a[N];
vector< pair<pt, pt> > qs;

inline bool read() {
	if(!(cin >> n >> m))
		return false;
	fore(i, 0, n)
		cin >> a[i];
	qs.resize(m);
	fore(i, 0, m) {
		cin >> qs[i].x.x >> qs[i].x.y >> qs[i].y.x >> qs[i].y.y;
		qs[i].x.x--; qs[i].x.y--;
	}
	return true;
}

int getCnt(const pair<pt, pt> &q, li mx) {
	li dist = mx / q.y.x;
	
	int s = q.x.x, f = q.x.y;
	int u = s, cnt = 0;
	while(u < f) {
		int v = u;
		while(v < f && a[v + 1] - a[u] <= dist)
			v++;
		
		if(v == u)
			return INF;
		
		cnt++;
		u = v;
	}
	return cnt - 1;
}

li upd(const pair<pt, pt> &q, li lf, li rg) {
	if(getCnt(q, lf) <= q.y.y)
		return lf;
	
	while(rg - lf > 1) {
		li mid = (lf + rg) >> 1;
		(getCnt(q, mid) <= q.y.y ? rg : lf) = mid;
	}
	return rg;
}

inline unsigned int getHash(const vector<int> &vals) {
	unsigned int hash = 0;
	for(int v : vals)
		hash = hash * 3 + v;
	return hash;
}

inline void solve() {
	auto seed = getHash(vector<int>(a, a + n));
	fore(i, 0, m)
		seed = seed * 3 + getHash({qs[i].x.x, qs[i].x.y, qs[i].y.x, qs[i].y.y});
	mt19937 rnd(seed);
	
	vector<int> ids(m, 0);
	iota(all(ids), 0);
	shuffle(all(ids), rnd);
	
	li curv = 0;
	for(int id : ids)
		curv = upd(qs[id], curv, 2 * INF64);
	cout << curv << endl;
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
[1101G - (Zero XOR Subset)-less](../problems/G._(Zero_XOR_Subset)-less.md "Educational Codeforces Round 58 (Rated for Div. 2)")

 **Tutorial**
### [1101G - (Zero XOR Subset)-less](../problems/G._(Zero_XOR_Subset)-less.md "Educational Codeforces Round 58 (Rated for Div. 2)")

Let's consider some division $[0, i_1)$, $[i_1, i_2)$, ..., $[i_k, n)$. Represent the XOR sum of the subset via prefix-XOR. Those are $pr[i_1] \oplus pr[0]$, $pr[i_2] \oplus pr[i_1]$, ..., $pr[n] \oplus pr[i_k]$.

I claim that you can collect any subset that is a XOR of an even number of $pr[x]$ for pairwise distinct values of $x$. Let's take a look on some prefix of processed segments, where the last segment is taken into subset. The previous taken $pr[x]$'s can't be changed, the last taken $pr[x]$ can either be eliminated if we also take the current segment (and that segment erases one value and adds one) or added to the answer if we don't take it (but the next taken segment will add two values). You can see that the parity doesn't change.

Moreover, you can collect any subset that is a XOR of an odd number of $pr[x]$ for pairwise distinct values of $x$. Just forget about $pr[0]$ taken into the answer, as its value is $0$. Then all the even subsets which included it will become odd.

This way we can collect all subsets of $pr[x]$ for some division. Now you just want find the division that produces the maximum number of linearly independent numbers (binary vectors). That is — the size of the basis of the space of chosen numbers (binary vectors). 

Now it's time to abuse the fact that adding a number into the set can only increase the size of basis of the space. Thus, adding anything to the maximum set won't change the answer (otherwise the result would be greater than the "maximum").

Finally, you say that the maximum basis size is equal to the basis size of all the prefix-XOR and easily calculate in $O(n \log MAXN)$.

The only corner case is $pr[n]$ being $0$ itself. Then for any division the full subset will also give $0$ result. That is the only case with answer $-1$.

Overall complexity: $O(n \log MAXN)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;
const int LOGN = 30;

int n;
int a[N], pr[N];
int base[LOGN];

void try_gauss(int v){
	for(int i = LOGN - 1; i >= 0; i--)
		if (base[i] != -1 && (v & (1 << i)))
			v ^= base[i];
	if (v == 0)
		return;
	for(int i = LOGN - 1; i >= 0; i--) if (v & (1 << i)){
		base[i] = v;
		return;
	}
}

int main() {
	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &a[i]);
	memset(base, -1, sizeof(base));
	forn(i, n){
		pr[i + 1] = pr[i] ^ a[i];
		try_gauss(pr[i + 1]);
	}
	if (pr[n] == 0){
		puts("-1");
		return 0;
	}
	int siz = 0;
	forn(i, LOGN)
		siz += (base[i] != -1);
	printf("%dn", siz);
}
```
