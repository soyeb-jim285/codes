# Tutorial

[1073A - Diverse Substring](../problems/A._Diverse_Substring.md "Educational Codeforces Round 53 (Rated for Div. 2)")

 **Tutorial**
### [1073A - Diverse Substring](../problems/A._Diverse_Substring.md "Educational Codeforces Round 53 (Rated for Div. 2)")

Notice that the string of two distinct letter is already diverse. That implies that the answer is "NO" if and only if all the letters in the string are the same. Otherwise you can check all pairs of adjacent letters in $O(n)$.

Overall complexity: $O(n)$.

 **Solution (PikMike)**
```cpp
n = int(input())
s = input()
for i in range(n - 1):
	if (s[i] != s[i + 1]):
		print("YES")
		print(s[i], s[i + 1], sep="")
		exit(0)
print("NO")
```
[1073B - Vasya and Books](../problems/B._Vasya_and_Books.md "Educational Codeforces Round 53 (Rated for Div. 2)")

 **Tutorial**
### [1073B - Vasya and Books](../problems/B._Vasya_and_Books.md "Educational Codeforces Round 53 (Rated for Div. 2)")

Let's maintain the pointer $pos$ to the topmost non-deleted book and whether each book whether is removed from the stack or not. Initially, all books are in a stack, and $pos$ is 0 (if we store the array 0-indexed). We will process the array $B$ in the order $b_1, b_2, \dots b_n$. If the current book $b_i$ is removed from the stack, then the answer for it is zero. Otherwise, we will increment the pointer $pos$ until the equality $a_{pos} = b_i$ is satisfied, while marking all the intermediate books in the array $u$. After that, the answer for the book $b_i$ will be the number of marked books in the $u$ array (including itself).

Since the pointer $pos$ shifts $n$ times at total, we get a solution with an $O(n)$ complexity.

 **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 9;

int n;
int a[N];
int b[N];
bool u[N];

int main() {
//	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
    	scanf("%d", a + i);
    }
    for(int i = 0; i < n; ++i){
    	scanf("%d", b + i);
    }
	
	int pos = 0;
	for(int i = 0; i < n; ++i){
		int x = b[i];
		if(u[x]){
			printf("0 ");
			continue;
		}
		
		int cnt = 0;
		while(true){
			++cnt;
			u[a[pos]] = true;
			if(a[pos] == x) break;
			++pos;
		} 
		
		++pos;
		printf("%d ", cnt);
	}    
	
	puts("");
    return 0;
}
```
[1073C - Vasya and Robot](../problems/C._Vasya_and_Robot.md "Educational Codeforces Round 53 (Rated for Div. 2)")

 **Tutorial**
### [1073C - Vasya and Robot](../problems/C._Vasya_and_Robot.md "Educational Codeforces Round 53 (Rated for Div. 2)")

Denote $d = |x| + |y​|$. If $d > n$, then the answer is -1, since the robot will not have the time to reach $(x, y)$ cell in $n$ steps. Also, if $d$ and $n$ have different parity, then the answer is also -1, as in one move the robot changes the parity of the sum of its coordinates.

In all other cases, the answer exists. Let's use binary search to solve this problem. Consider all segments of length $len$. For a fixed length of the segment $len$, let's iterate over the position of the beginning of the segment $l$. At the same time, we will maintain the cell that the robot will stop at if it execute all commands, except commands with indices $l, l + 1, \dots, l + len - 1$. We denote this position as $(x_0, y_0)$. We also calculate the distances from the cell $(x_0, y_0)$ to the cell $(x, y)$ — the value $d_0 = |x - x_0| + |y ​​- y_0|$. If there is at least one position of the beginning of the segment for which $d_0 \le len$, then we can change the segment of length $len$ so that the robot comes to the $(x, y)$ cell, otherwise it can't.

 **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 9;

string s;
int n;
int x, y;

void upd(pair<int, int> &pos, char mv, int d){
	if(mv == 'U')
		pos.second += d;
	if(mv == 'D')
		pos.second -= d;
	if(mv == 'L')
		pos.first -= d;
	if(mv == 'R')
		pos.first += d;
}

bool can(pair<int, int> u, pair<int, int> v, int len){
	int d = abs(u.first - v.first) + abs(u.second - v.second);
	if(d % 2 != len % 2) return false;
	return len >= d;
}

bool ok(int len){
	pair<int, int> pos = make_pair(0, 0);
	for(int i = len; i < n; ++i)
		upd(pos, s[i], 1);

	int l = 0, r = len;
	while(true){
		if(can(pos, make_pair(x, y), len))
			return true;
		
		if(r == n) break;
		upd(pos, s[l++], 1);
		upd(pos, s[r++], -1);		
	}
	
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	
	cin >> n;
	cin >> s;
	cin >> x >> y;
	
	if(!ok(n)){
		puts("-1");
		return 0;
	}
	
	int l = -1, r = n;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(ok(mid)) r = mid;
		else l = mid;
	}
	
	cout << r << endl;
    return 0;
}
```
[1073D - Berland Fair](../problems/D._Berland_Fair.md "Educational Codeforces Round 53 (Rated for Div. 2)")

 **Tutorial**
### [1073D - Berland Fair](../problems/D._Berland_Fair.md "Educational Codeforces Round 53 (Rated for Div. 2)")

Let's code the following process. Go one circle across the booths, calculate the total cost $C$ of sweets bought and the number $S$ of sweets bought. Now you can decrease you money down to $T = T~mod~C$ and add $S \cdot (T~div~C)$ to answer. It represents that you went maximum number of such circles. The later circles will have smaller cost. Let's continue this process until $T$ becomes smaller than the minimum priced sweet.

The number of operations made is $O(\log T)$. Let $T_{cur}$ be the amount of money before some operation, $C_{cur}$ be the total cost of sweets bought on that operation and $T_{new} = T_{cur}~mod~C_{cur}$. $T_{new}$ is actually smaller than $C_{cur}$ (that's how modulo works) and smaller than $T_{cur} - C_{cur}$ (that's also how modulo works). And these inequalities imply that $T_{new} < \frac{T_{cur}}{2}$. That leads to about $O(\log T)$ steps to reach the minimal price.

Overall complexity: $O(n \log T)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;

typedef long long li;

int n;
int a[N];

void get(li T, li& pr, li& cnt){
	pr = 0, cnt = 0;
	forn(i, n){
		if (T >= a[i]){
			T -= a[i];
			pr += a[i];
			++cnt;
		}
	}
}

int main() {
	li T;
	scanf("%d%lld", &n, &T);
	forn(i, n)
		scanf("%d", &a[i]);
	
	int mn = *min_element(a, a + n);
	li ans = 0;
	while (T >= mn){
		li pr, cnt;
		get(T, pr, cnt);
		ans += cnt * (T / pr);
		T %= pr;
	}
	printf("%lldn", ans);
	return 0;
}
```
[1073E - Segment Sum](../problems/E._Segment_Sum.md "Educational Codeforces Round 53 (Rated for Div. 2)")

 **Tutorial**
### [1073E - Segment Sum](../problems/E._Segment_Sum.md "Educational Codeforces Round 53 (Rated for Div. 2)")

Let's calculate the answer as the sum of suitable numbers in range $[1; r]$ minus the sum of suitable numbers in range $[1; l - 1]$. Now our problem is to calculate the sum of suitable numbers in range $[1; n]$.

The main approach for this problem is digit DP. Let's calculate two dynamic programmings $dp_{pos, mask, f}$ and $dps_{pos, mask, f}$. $pos$ means that now we are at the $pos$-th digit of the number $n$ (at the digit corresponding to $10^{len - pos - 1}$, where $len$ is the decimal length of a number), $mask$ is a binary mask describing digits we already use and $f$ equals $1$ if the current prefix of number we trying to obtain is the same as the prefix of number $n$ (otherwise $f$ equals $0$).

So what means $dp_{pos, mask, f}$? It means the count of numbers (in general, not numbers but their prefixes) in range $[1; n]$ of length exactly $|n|$ without leading zeroes corresponding to this state. So what the point of this DP? Its point is helping us to calculate the main DP, $dps_{pos, mask, f}$, which means the sum of numbers (in general, not numbers but their prefixes) in range $[1; n]$ of length exactly $|n|$ without leading zeroes corresponding to this state.

How do we calculate the answer? Firstly, let $len$ be the length of $n$. Let $calc(n)$ be the function calculating the sum of numbers from $1$ to $n$ containing at most $k$ different digits. How to calculate it? Let $calcdp(x)$ be the sum of numbers from $1$ to $x$ containing at most $k$ different digits and having length exactly $|x|$. Then $calc(n)$ seems to be pretty easy: for each length $i$ from $1$ to $len-1$ add to the answer $calcdp(10^i - 1)$. And the last step is to add to the answer $calcdp(n)$.

How to calculate dynamic programmings? Initially, all states are zeroes (excluding $dp_{0, 0, 1}$, which is $1$).

Firstly, let's calculate $dp$. After calculating it we can calculate $dps$ in almost the same way. Let's iterate over all possible lengths and over all possible masks. Let the current state is $dp_{pos, mask, 0}$. Then let's iterate over next digit we will place in this number and place it. If $pos = 0$ then $dig = 1 \dots 9$ otherwise $dig = 0 \dots 9$. The transition is pretty easy: $dp_{pos + 1, mask | 2^{dig}, 0} += dp_{pos, mask, 0}$. There $|$ is the bitwise OR operation. For $f = 1$ transitions are almost the same expect the restrictions on digit we place and the state we update. If we now at the position $pos$ with mask $mask$ and $f = 1$ then the current digit of $n$ is $n_{pos}$. Then let's iterate over next digit: $dig = 1 \dots n_{pos}$ if $pos = 0$ otherwise $dig = 0 \dots n_{pos}$. The transition is also easy: $dp_{pos + 1, mask | 2^{dig}, dig = n_{pos}} += dp_{pos, mask, f}$.

After calculating the previous DP we can calculate $dps$. All the process is the same as in the previous dynamic programming expect the value we will add in transitions. In the previous DP this value was equal $dp_{pos, mask, f}$, in the current DP this value equals to $val = dps_{pos, mask, f} + dig \cdot 10^{len - pos - 1} \cdot dp_{pos, mask, f}$. Don't forget to calculate it modulo $998244353$!

So after calculating all the values of DPs, what is the answer for $calcdp(n)$? It is $\sum\limits_{mask = 0}^{2^{10} - 1} dps_{|n|, mask, 0} + dps_{|n|, mask, 1}$ for all masks with at most $k$ bits.

I'm pretty sure that there is another way to avoid leading zeroes in calculating these DPs but this one is very straight-forward and simple.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<long long, int> pt;

const int N = 20;
const int M = 1 << 10;
const int MOD = 998244353;

int k;
int pw10[N];
int bitCnt[M];

pt dp[N][M][2];

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}

int mul(int a, int b) {
	return a * 1ll * b % MOD;
}

int calc(const string &s) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			dp[i][j][0] = dp[i][j][1] = { 0ll, 0 };
		}
	}
	
	int len = s.size();
	dp[0][0][1] = { 1ll, 0 };
	for (int i = 0; i < len; ++i) {
		int cdig = s[i] - '0';
		for (int mask = 0; mask < M; ++mask) {
			if (dp[i][mask][0].x == 0 && dp[i][mask][1].x == 0) continue;
			for (int dig = (i == 0); dig <= 9; ++dig) {
				int nmask = mask | (1 << dig);
				long long cnt = dp[i][mask][0].x;
				int sum = add(dp[i][mask][0].y, mul(dig, mul(pw10[len - i - 1], cnt % MOD)));
				dp[i + 1][nmask][0].x += cnt;
				dp[i + 1][nmask][0].y = add(dp[i + 1][nmask][0].y, sum);
			}
			
			for (int dig = (i == 0); dig <= cdig; ++dig) {
				int nmask = mask | (1 << dig);
				long long cnt = dp[i][mask][1].x;
				int sum = add(dp[i][mask][1].y, mul(dig, mul(pw10[len - i - 1], cnt % MOD)));
				dp[i + 1][nmask][dig == cdig].x += cnt;
				dp[i + 1][nmask][dig == cdig].y = add(dp[i + 1][nmask][dig == cdig].y, sum);
			}
		}
	}
	
	int ans = 0;
	for (int mask = 0; mask < M; ++mask) {
		if (bitCnt[mask] > k) continue;
		ans = add(ans, dp[len][mask][0].y);
		ans = add(ans, dp[len][mask][1].y);
	}
	return ans;
}

int calc(long long n) {
	int len = to_string(n).size();
	int ans = 0;
	for (int l = 1; l < len; ++l) {
		ans = add(ans, calc(string(l, '9')));
	}
	ans = add(ans, calc(to_string(n)));
	return ans;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	pw10[0] = 1;
	for (int i = 1; i < N; ++i) {
		pw10[i] = mul(pw10[i - 1], 10);
	}
	for (int i = 0; i < M; ++i) {
		bitCnt[i] = __builtin_popcount(i);
	}
	
	long long l, r;
	cin >> l >> r >> k;
	int ans = add(calc(r), -calc(l - 1));
	cout << ans << endl;
	
	return 0;
}
```
[1073F - Choosing Two Paths](../problems/F._Choosing_Two_Paths.md "Educational Codeforces Round 53 (Rated for Div. 2)")

 **Tutorial**
### [1073F - Choosing Two Paths](../problems/F._Choosing_Two_Paths.md "Educational Codeforces Round 53 (Rated for Div. 2)")

Firstly, let's call a path from $u$ to $v$ good, if $u$ is a leaf, $v$ is a vertex of degree at least $3$ (the number of their neighbors is at least $3$) and there are no other vertices of degree at least $3$ on this path expect the vertex $v$.

The first step of the solution is to remove all the good paths from $u$ to $v$ (but we should not remove the vertex $v$) and remember for each vertex $v$ the sum of two maximum lengths of good paths which end in the vertex $v$. Let this value for the vertex $v$ be $val_v$. For example, if for some vertex $v$ there are $3$ good paths with end in it of lengths $2$, $3$ and $5$ correspondingly, then $val_v$ will be $5 + 3 = 8$.

Okay, it is easy to see that the maximum intersection of two paths in the answer will be equal to the length of the diameter of the obtained tree. But we can not take any diameter of this tree and call it the answer because of the second constraint: we need to find some diameter from $x$ to $y$ such that the sum $val_x + val_y$ is maximum possible. How do we do that?

There is such an awesome (and well-known) fact that the center of a tree belongs to all diameters of this tree. Let's root the tree by the center of a tree (if the length of the diameter is odd (the center of a tree is an edge) then let's root the tree by any end of this edge, it does not matter).

There is one case when the length of the diameter is $1$ but it is pretty trivial to handle it.

Now our problem is to find two neighbors of the root of the new tree such that in their subtrees are vertices which form some diameter of this tree and the sum of values of these vertices is maximum possible. Let's calculate the vertex with the maximum distance from a root (and with the maximum possible $val_v$ for equals distances) by simple DFS for each neighbor of a root. It can be done in $O(n)$ and the last part is to find two maximums of this list, it also can be done in $O(n)$ or $O(n \log n)$, depends on implementation.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define size(a) int((a).size())

typedef pair<int, int> pt;

const int N = 200 * 1000 + 11;

int n;
vector<int> g[N];

int p[N];
int dist[N];

bool bad[N];
int value[N];
pt res[N];
vector<pt> best[N];

void dfs(int v, int par = -1, int d = 0) {
	p[v] = par;
	dist[v] = d;
	for (auto to : g[v]) {
		if (to == par) {
			continue;
		}
		dfs(to, v, d + 1);
	}
}

int getFarthest(int v) {
	dfs(v);
	int res = v;
	for (int i = 0; i < n; ++i) {
		if (bad[i]) {
			continue;
		}
		if (dist[res] < dist[i]) {
			res = i;
		}
	}
	return res;
}

pt get(int v) {
	return { dist[v], value[v] };
}

int getBetter(int v, int u) {
	if (get(v) > get(u)) {
		return v;
	}
	return u;
}

int getBest(int v, int par) {
	int res = v;
	for (auto to : g[v]) {
		if (to == par || bad[to]) {
			continue;
		}
		res = getBetter(res, getBest(to, v));
	}
	return res;
}

pt calc(int v) {
	dfs(v);
	
	vector<int> ch;
	for (auto to : g[v]) {
		if (!bad[to]) {
			ch.push_back(to);
		}
	}
	if (size(ch) == 1) {
		return { v, ch[0] };
	}
	
	vector<int> pref(size(ch));
	vector<int> suf(size(ch));
	vector<int> best(size(ch));
	for (int i = 0; i < size(ch); ++i) {
		int to = ch[i];
		best[i] = pref[i] = suf[i] = getBest(to, v);
	}
	for (int i = 1; i < size(ch); ++i) {
		pref[i] = getBetter(pref[i], pref[i - 1]);
		suf[size(ch) - i - 1] = getBetter(suf[size(ch) - i - 1], suf[size(ch) - i]);
	}
	
	pt ans = { -1, -1 };
	pt res = { 0, 0 };
	for (int i = 0; i < size(ch); ++i) {
		int bst = -1;
		if (i == 0) {
			bst = suf[i + 1];
		} else if (i + 1 == size(ch)) {
			bst = pref[i - 1];
		} else {
			bst = getBetter(pref[i - 1], suf[i + 1]);
		}
		pt curRes = { dist[bst] + dist[best[i]], value[bst] + value[best[i]] };
		if (res < curRes) {
			res = curRes;
			ans = { best[i], bst };
		}
	}
	
	return ans;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	int root = -1;
	for (int i = 0; i < n; ++i) {
		if (size(g[i]) > 2) {
			root = i;
			dfs(i);
			break;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		if (size(g[i]) != 1) {
			continue;
		}
		int v = i;
		while (size(g[v]) < 3) {
			bad[v] = true;
			v = p[v];
		}
		best[v].push_back({dist[i] - dist[v], i});
	}
	
	for (int i = 0; i < n; ++i) {
		if (size(best[i]) >= 2) {
			sort(best[i].rbegin(), best[i].rend());
			value[i] = best[i][0].first + best[i][1].first;
			res[i] = { best[i][0].second, best[i][1].second };
		}
	}
	
	int u = getFarthest(root);
	int v = getFarthest(u);
	vector<int> path;
	while (v != u) {
		path.push_back(v);
		v = p[v];
	}
	path.push_back(u);
	
	pt ans = calc(path[size(path) / 2]);
	
	printf("%d %dn", res[ans.x].x + 1, res[ans.y].x + 1);
	printf("%d %dn", res[ans.x].y + 1, res[ans.y].y + 1);
	
	return 0;
}
```
[1073G - Yet Another LCP Problem](../problems/G._Yet_Another_LCP_Problem.md "Educational Codeforces Round 53 (Rated for Div. 2)")

 **Tutorial**
### [1073G - Yet Another LCP Problem](../problems/G._Yet_Another_LCP_Problem.md "Educational Codeforces Round 53 (Rated for Div. 2)")

At first, implement your favourite string suffix structure for comparing pair of suffixes lexicographically fast enough. For example, it's a Suffix Array + linear LCP + Sparse Table. Now we can compare two suffixes $i$ and $j$ by finding $l = lcp(i, j)$ and comparing $s[i + l]$ with $s[j + l]$.

We will process queries online. Let current query be a pair of arrays $a$ ($|a| = k$) and $b$ ($|b| = l$). We will calculate answer in two parts: $$\sum\limits_{s[a_i \dots n] < s[b_j \dots n]}{lcp(s[a_i \dots n], s[b_j \dots n])} + \sum\limits_{s[a_i \dots n] \ge s[b_j \dots n]}{lcp(s[a_i \dots n], s[b_j \dots n])}.$$

To calculate the first sum we can sort all $c = a + b$ suffixes in lexicographical order and maintain some information for prefixes of $c$. What information we need to maintain? We need some Data Structure which will hold $lcp$ of suffixes from $a$. When we process some $c_i = b_j$ we need just a total sum of all $lcp$ in the DS. If $c_i = a_j$, we should add to the DS length of $a_j$-th suffix. And when we move from $c_i$ to $c_{i + 1}$ we must recalculate some $lcp$. Since $c$ is sorted, all we need is to set $lcp_k = min(lcp_k, lcp(s[c_i \dots n], s[c_{i + 1} \dots n]))$.

In fact, this Data Structure is just a $map$. In this $map$ we will hold for each length $l$ number of suffixes with $lcp = l$ (we will hold only non-zero values). When we should add some suffix $a_j$, we manually increase some value by one. Setting $min$ with $v = lcp(s[c_i \dots n], s[c_{i + 1} \dots n])$ can be done with decreasing maximum in $map$ while its more than $v$. It can be proven, that there will be $O(|a| + |b|)$ operations with $map$ for one query. The total sum can be maintained in some global variable, which will be recalculated each time $map$ changes.

To calculate the second sum we can just reverse $c$ and run the same algorithm. So total complexity is $O(n \log^2{n} + (\sum\limits_{i = 1}^{i = q}{k_i} + \sum\limits_{i = 1}^{i = q}{l_i}) \log{n})$.

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

template<class A, class B> ostream& operator <<(ostream &out, const pair<A, B> &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream &out, const vector<A> &v) {
	out << "[";
	fore(i, 0, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

const int N = 200 * 1000 + 555;
const int LOGN = 18;

int n, q;
char s[N];

bool read() {
	if(!(cin >> n >> q))
		return false;
	assert(scanf("%s", s) == 1);
	return true;
}

int c[N], id[N], lcp[N];
int mn[LOGN][N];
int lg2[N];

void buildSuffArray() {
	s[n++] = '$';
	
	for(int l = 1; l < 2 * n; l <<= 1) {
		vector< pair<pt, int> > d;
		fore(i, 0, n)
			d.emplace_back(l == 1 ? pt(s[i], 0) : pt(c[i], c[(i + (l >> 1)) % n]), i);
		stable_sort(d.begin(), d.end());
		
		c[d[0].y] = 0;
		fore(i, 1, n)
			c[d[i].y] = c[d[i - 1].y] + (d[i].x != d[i - 1].x);
		if(c[d.back().y] == n - 1)
			break;
	}
	
	fore(i, 0, n)
		id[c[i]] = i;
		
	int l = 0;
	fore(i, 0, n) {
		if(c[i] == n - 1)
			continue;
		l = max(0, l - 1);
		int j = id[c[i] + 1];
		
		while(i + l < n && j + l < n && s[i + l] == s[j + l])
			l++;
		lcp[c[i]] = l;
	}
	
	n--;
	lg2[0] = lg2[1] = 0;
	fore(i, 2, N) {
		lg2[i] = lg2[i - 1];
		if((1 << (lg2[i] + 1)) <= i)
			lg2[i]++;
	}
	
	fore(i, 0, n)
		mn[0][i] = lcp[i];
	fore(pw, 1, LOGN) fore(i, 0, n) {
		mn[pw][i] = mn[pw - 1][i];
		if(i + (1 << (pw - 1)) < n)
			mn[pw][i] = min(mn[pw][i], mn[pw - 1][i + (1 << (pw - 1))]);
	}
}

int getMin(int l, int r) {
	int ln = lg2[r - l];
	return min(mn[ln][l], mn[ln][r - (1 << ln)]);
}

int getLCP(int i, int j) {
	if(i == j) return n - i;
	i = c[i], j = c[j];
	return getMin(min(i, j), max(i, j));
}

bool cmp(const pt &a, const pt &b) {
	if(a.x == b.x)
		return a.y < b.y;
	int l = getLCP(a.x, b.x);
	return s[a.x + l] < s[b.x + l];
}

void solve() {
	buildSuffArray();
	
	fore(_, 0, q) {
		int k, l;
		assert(scanf("%d%d", &k, &l) == 2);
		vector<int> a(k), b(l);
		fore(i, 0, k)
			assert(scanf("%d", &a[i]) == 1), a[i]--;
		fore(j, 0, l)
			assert(scanf("%d", &b[j]) == 1), b[j]--;
			
		li ans = 0;
		vector<pt> c;
		for(auto v : a)
			c.emplace_back(v, 1);
		for(auto v : b)
			c.emplace_back(v, 0);
		sort(c.begin(), c.end(), cmp);
		
		fore(k, 0, 2) {
			li sum = 0;
			map<int, int> cnt;
			
			fore(i, 0, sz(c)) {
				int id = c[i].x, tp = c[i].y;
				if(tp == 0)
					ans += sum;
				else {
					cnt[n - id]++;
					sum += (n - id);
				}
				if(i + 1 < sz(c)) {
					int len = getLCP(c[i].x, c[i + 1].x);
					while(!cnt.empty()) {
						auto it = --cnt.end();
						if(it->x <= len)
							break;
						
						sum -= it->x * 1ll * it->y;
						cnt[len] += it->y;
						sum += it->y * 1ll * len;
						cnt.erase(it);
					}
				}
			}
			reverse(c.begin(), c.end());
		}
		printf("%lldn", ans);
	}
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
#endif
	}
	return 0;
}
```
