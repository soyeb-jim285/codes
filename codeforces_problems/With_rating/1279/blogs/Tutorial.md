# Tutorial

[1279A - New Year Garland](../problems/A._New_Year_Garland.md "Educational Codeforces Round 79 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1279A - New Year Garland](../problems/A._New_Year_Garland.md "Educational Codeforces Round 79 (Rated for Div. 2)")

Let r≤g≤b (if it is not the case, do some swaps). If b>r+g+1, then at least two blue lamps will be adjacent — so there is no solution.

Otherwise the answer can be easily constucted. Place all blue lamps in a row. Then place red lamps: one between the first and the second blue lamp, one between the second and the third, and so on. Then place all green lamps: one between the (b−1)-th blue lamp and the b-th, one between the blue lamps with numbers (b−2) and (b−1), and so on. Since r+g≥b−1, there is at least one non-blue lamp between each pair of blue lamps. If g=b, we didn't place all green lamps, we can place the remaining one before all other lamps (the same with r=b).

So, if we swap l, g and b in such a way that r≤g≤b, we only have to check that b≤r+g+1.

 **Solution (Roms)**
```cpp
for t in range(int(input())):
	a = sorted(list(map(int, input().split())))
	print('Yes' if a[2] <= a[0] + a[1] + 1 else 'No')
```
[1279B - Verse For Santa](../problems/B._Verse_For_Santa.md "Educational Codeforces Round 79 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1279B - Verse For Santa](../problems/B._Verse_For_Santa.md "Educational Codeforces Round 79 (Rated for Div. 2)")

If $\sum\limits_{i=1}^n a_i \le s$ then answer is 0. 

Otherwise let's find we minimum index $x$ such that $\sum\limits_{i=1}^x a_i > s$. It's useless to skip a part $i > x$, because Vasya just has not time to recite previous part (it's change nothing). So he has to skip a part $i \le x$. And among such parts it's beneficial to skip part with maximum value of $a_i$.

 **Solution (Roms)**
```cpp
for t in range(int(input())):
    n, t = map(int, input().split())
    a = list(map(int, input().split()))
    id = 0
    for i in range(n):
        if a[i] > a[id]:
            id = i
        t -= a[i]
        if t < 0:
            break

    if t >= 0:
        id = -1 
    print(id + 1)
```
[1279C - Stack of Presents](../problems/C._Stack_of_Presents.md "Educational Codeforces Round 79 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1279C - Stack of Presents](../problems/C._Stack_of_Presents.md "Educational Codeforces Round 79 (Rated for Div. 2)")

At first let's precalculate array $pos$ such that $pos_{a_i} = i$.

Now presume that we have to calculate answer for $b_i$. Then there are two cases (let's denote $lst = \max\limits_{1 \le j < i} pos_{b_j}$, initially $lst = -1$):

1. if $pos_{b_i} > lst$ then we have to spend $1 + 2 \cdot (pos_{b_i} - (i - 1))$ seconds on it (1 second on the gift $b_i$, $pos_{b_i} - (i - 1)$ seconds on removing gifts above and $pos_{b_i} - (i - 1)$ seconds on pushing these gifts);
2. if $pos_{b_i} < lst$ then we can reorder gifts by previous actions such that gift $b_i$ be on the top of stack. So we spend only 1 second on it.
 **Solution (Roms)**
```cpp
for t in range(int(input())):
	n, m = map(int, input().split())
	a = [x - 1 for x in list(map(int, input().split()))]
	b = [x - 1 for x in list(map(int, input().split()))]
	pos = a[:]
	for i in range(n):
		pos[a[i]] = i
	
	lst = -1
	res = m
	for i in range(m):
		if pos[b[i]] > lst:
			res += 2 * (pos[b[i]] - i)
			lst = pos[b[i]]
	
	print(res)
```
[1279D - Santa's Bot](../problems/D._Santa's_Bot.md "Educational Codeforces Round 79 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1279D - Santa's Bot](../problems/D._Santa's_Bot.md "Educational Codeforces Round 79 (Rated for Div. 2)")

First of all, how to deal with the fractions modulo $998244353$? According to Fermat's little theorem, $x^{\phi(m)} \equiv 1 (mod m)$ if $x$ is coprime with $m$. So, the inverse element for the denominator $y$ is $y^{\phi(998244353) - 1} = y^{998244351}$, taken modulo $998244353$.

A cool property of fractions taken modulo $998244353$ (or any other number such that denominator is coprime with it) is that if we want to add two fractions together and calculate the result modulo some number, we can convert these fractions beforehand and then just add them as integer numbers. The same works with subtracting, multiplying, dividing and exponentiating fractions.

Okay, now for the solution itself. We know that there are at most $10^6$ possible pairs of $(x, y)$; we can iterate on these pairs, calculate the probability that the fixed pair is included in the robot's decision (that probability is $\frac{1}{x \cdot k_x}$), and calculate the probability that $(x, y)$ extends to a valid triple (it is equal to $\frac{cnt_y}{z}$, where $cnt_y$ is the number of kids who want item $y$). Multiplying these two probabilities, we get the probability that $(x, y)$ is chosen and produces a valid decision (since these events are independent), and we sum up these values over all possible pairs $(x, y)$.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a) * (a))
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int MOD = 998244353;
const int N = 1e6 + 7;

int n;
vector<int> a[N];
int cnt[N];
int inv[N];

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

int mul(int a, int b) {
	return a * 1ll * b % MOD;
}

int binpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	forn(i, n) {
		int k;
		scanf("%d", &k);
		a[i].resize(k);
		forn(j, k) scanf("%d", &a[i][j]);
		forn(j, k) cnt[a[i][j]]++;
	}
	
	forn(i, N) inv[i] = binpow(i, MOD - 2);
	
	int ans = 0;
	forn(i, n) for (auto x : a[i])
		ans = add(ans, mul(mul(inv[n], inv[sz(a[i])]), mul(cnt[x], inv[n])));
			
	printf("%dn", ans);
}
```
[1279E - New Year Permutations](../problems/E._New_Year_Permutations.md "Educational Codeforces Round 79 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1279E - New Year Permutations](../problems/E._New_Year_Permutations.md "Educational Codeforces Round 79 (Rated for Div. 2)")

Let's calculate $cycle_n$ — the number of permutations of length $n$, which have a maximum at the position $1$ and consist of exactly one cycle. Each good permutation can be divided into such blocks, so we'll need this value later.

It is easy to notice that $cycle_n = (n-2)!$.

Let's calculate the following dynamic programming $dp_i$ — the number of good permutations consisting of elements $[i, n]$.

To calculate $dp_i$, let's iterate over $j$ — the maximum element of the first block, it determines the length of this block $(j - i + 1)$.

$dp_i = \sum_{j=i}^n(dp_{j + 1} \cdot cycle_{j - i - 1})$.

Now let's use the standard method of lexicographic recovery.

We will iterate over which element to put next, it immediately determines the size of the new block and all the elements in it. If the number of permutations starting with such block is at least $k$, then you need to restore this block entirely and reduce the task to the one without this block. Otherwise, you need to subtract the number of permutations starting on such block from $k$ and proceed to the next option for the block.

We will also use lexicographic recovery to restore the block. You must carefully maintain the current block so that it consists of exactly one cycle. To do this, you can use DSU or explicitly check for a cycle.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a) * (a))
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)

typedef long long li;
typedef long double ld;

const int N = 55;
const li INF = 2e18;

int n;
li k;

li cycl[N], cnt[N];
bool used[N];
int ans[N];

li add(li x, li y) {
	return min(INF, x + y);
}

li mul(li x, li y) {
	ld t = ld(x) + y;
	if (t > INF) return INF;
	return x * y;
}

void solve() {
	cin >> n >> k;
	--k;

	cycl[0] = cycl[1] = 1;
	fore(i, 2, n + 1) 
		cycl[i] = mul(cycl[i - 1], i - 1);
		
	cnt[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		cnt[i] = 0;
		fore(val, i, n) {
			int len = (val - i) + 1;
			cnt[i] = add(cnt[i], mul(cnt[i + len], cycl[len - 1]));
		}
	}
	
	if (cnt[0] <= k) {
		cout << -1 << endl;
		return;
	}
	
	memset(used, 0, sizeof(used));
	memset(ans, -1, sizeof(ans));
	
	forn(i, n) {
		fore(val, i, n) {
			int len = (val - i) + 1;
			li cur = mul(cnt[i + len], cycl[len - 1]); 
			
			if (cur <= k)  {
				k -= cur;
				continue;	
			}
			
			ans[i] = val;
			used[val] = true;
			
			for (int j = i + 1; j < i + len; j++) {
				int lft = len - (j - i) - 1;
				fore(nval, i, val) if (!used[nval] && j != nval) {
					if (j != i + len - 1) {
						int tmp = ans[nval];
						while (tmp != -1 && tmp != j) 
							tmp = ans[tmp];
						if (tmp == j) continue;
					}
					
					li cur = mul(cnt[i + len], cycl[lft]); 
					if (cur <= k) {
						k -= cur;
						continue;	
					}
					
					ans[j] = nval;
					used[nval] = true;		
					break;
				}
			}
				
			i += len - 1;
			break;
		}
	}

	forn(i, n) cout << ans[i] + 1 << ' ';
	cout << endl;
}

int main() {
	int tc;
	cin >> tc;
	forn(i, tc) solve();
}
```
[1279F - New Year and Handle Change](../problems/F._New_Year_and_Handle_Change.md "Educational Codeforces Round 79 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1279F - New Year and Handle Change](../problems/F._New_Year_and_Handle_Change.md "Educational Codeforces Round 79 (Rated for Div. 2)")

Let's simplify the problem a bit: we need either to minimize the number of lowercase letters or to minimize the number of uppercase letters. Both variants can be described by the following model: we have a binary array $a$ where $a[i] = 0$ if $s[i]$ is in the correct case and $a[i] = 1$ otherwise. We can do at most $k$ operations "set $0$ on the segment $[i, i + l - 1]$" and we'd like to minimize the total sum of $a$.

At first, let's start with a solution which is pretty slow but correct. Let $dp[len][c]$ be the minimum sum of the prefix $a[0] \dots a[len - 1]$ such that $c$ operations was already applied on it.

In order to calculate this $dp$ somehow efficiently, we need to understand that it's optimal to avoid intersections of segments of applied operations so we can further specify the state of $dp$ with the following: all $c$ applied operations have their right borders $\le len - 1$. It's easy to specify the transitions: we either apply set operation on $[len, len + l - 1]$ and relax $dp[len + l][c + 1]$ with $dp[len][c]$ or not and relax $d[len + 1][c]$ with $dp[len][c] + a[len]$.

It still $O(nk)$ so we'd like to optimize it more — and we can do it using the "lambda-optimization" i. e. "aliens trick". Here we will try to describe what "aliens trick" is and the "features" of its application on the discrete calculations.

In general, "aliens trick" allows you to get rid of the restriction on the total number of operations applied to the array (sometimes it's the number of segments in the partition of the array) by replacing it with the binary search of the value $\lambda$ connected to it. The $\lambda$ is the cost of using the operation (or the cost to use one more segment in the partition). In other words, we can use as many operations as we want but we need to pay for each of them. Often, we can calculate the answer without the restriction faster. 

The main restriction of the using this dp-optimization is the following (in case of the discrete model): consider the answer $ans(c)$ for the fixed $c$, or $dp[n][c]$. If we look at the function $ans(c)$ it should be "somewhat convex", i.e $ans(c - 1) - ans(c) \ge ans(c) - ans(c + 1)$ (or, sometimes, $ans(c) - ans(c - 1) \ge ans(c + 1) - ans(c)$) for all possible $c$.

Let's look at the answers of the modified version of the problem (with cost $\lambda$ for each used operation) as function $res(\lambda, c)$. It's easy to prove that $res(\lambda, c) = ans(c) + \lambda c$ and it's also "somewhat convex" for a fixed $\lambda$ (as a sum of convex functions). But, more important, it has the following property: let $c_\lambda$ be the position where the $res(\lambda, c)$ is the minimum possible. It can be proven (from the convex property) that $c_{\lambda} \ge c_{\lambda + 1}$.

This property leads to the solution: binary search $\lambda$ while keeping track of the $c_\lambda$, i. e. find the minimum $\lambda$ that $c_\lambda \le k$. But there are several problems related to the discrete origin of the problem: 

* The $c_\lambda$ is not unique. In general case, there is a segment $[cl_\lambda, cr_\lambda]$ where the minimum $res(\lambda, c)$ can be achieved. But there is still a property that $cl_\lambda \ge cl_{\lambda + 1}$ and $cr_\lambda \ge cr_{\lambda + 1}$. So we need to ensure that we will always find either minimum such $c_\lambda$ or maximum such $c_\lambda$.
* The second problem comes from the first one. There are situations when $c_\lambda - c_{\lambda + eps} > 1$. It creates a problem in the next situation: suppose the binary search finished with $\lambda_{opt}$; the $c_{\lambda_{opt} - 1} > k$ and $c_{\lambda_{opt}} < k$. But we need to use exactly $k$ operations, what to do? Using float values will not help, so we don't need them (so we'll use usual integer bs). Suppose we minimized the $c_{\lambda_{opt}}$ then we can show that $k \in [cl_{\lambda_{opt}}, cr_{\lambda_{opt}}]$ or, in other words, $res(\lambda_{opt}, k) = res(\lambda_{opt}, c_{\lambda_{opt}})$. So we can claim that we calculated the value not only for $c_{\lambda_{opt}}$ but also for $k$.

In the end, if we can efficiently calculate $c_\lambda$ and $res(\lambda, c_\lambda)$ for the fixed $\lambda$, then we can binary search $\lambda_{opt}$, extract $res(\lambda_{opt}, c_{\lambda_{opt}})$ and claim that the $dp[n][k] = res(\lambda_{opt}, c_{\lambda_{opt}}) - \lambda_{opt} k$.

Finally, let's discuss, how to calculate $c_\lambda$ and $res(\lambda, c_\lambda)$ for a fixed $\lambda$. Since $res(\lambda, c_\lambda)$ is just a minimum cost and the $c_\lambda$ is the minimum number of operations with such cost. We can calculate it by simplifying our starting $dp$. (Remember, the cost is calculated in a next way: for each remaining $1$ in $a$ we pay $1$ and for each used operation we pay $\lambda$).

Let $d[len] = \{cost_{len}, cnt_{len}\}$, where $cost_{len}$ is minimum cost on the prefix of length $len$ and $cnt_{len}$ is minimum number of operations $cost_{len}$ can be achieved. Then the transitions are almost the same: we either let $a[len]$ be and relax $d[pos + 1]$ with $\{cost_{len} + a[len], cnt_{len}\}$ or start new operation and relax $d[pos + len]$ with $\{cost_{len} + \lambda, cnt_{len} + 1\}$. The result is pair $d[n]$.

Some additional information: we should carefully choose the borders of the binary search: we should choose the left border so it's optimal to use operation whenever we can (usually, $0$ or $-1$). And we should choose the right border so it's never optimal to use even one operation (usually more than the maximum possible answer).

The total complexity is $O(n \log{n})$.

P. S.: We don't have the strict proof that the $ans(c)$ is convex, but we have faith and stress. We'd appreciate it if someone would share the proof in the comment section.

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1000 * 1000 + 11;
const int INF = 1e9;

int n, k, l;
string s;
int a[N];
pair<int, int> dp[N];

int calc(int mid) {
	for (int i = 0; i <= n; ++i) {
		dp[i] = make_pair(INF, INF);
	}
	dp[0] = make_pair(0, 0);
	for (int i = 0; i < n; ++i) {
		if (dp[i + 1] > make_pair(dp[i].first + a[i], dp[i].second)) {
			dp[i + 1] = make_pair(dp[i].first + a[i], dp[i].second);
		}
		if (dp[min(n, i + l)] > make_pair(dp[i].first + mid, dp[i].second + 1)) {
			dp[min(n, i + l)] = make_pair(dp[i].first + mid, dp[i].second + 1);
		}
	}
	return dp[n].second;
}

int solve() {
	int l = 0, r = n;
	int res = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (calc(mid) > k) {
			l = mid + 1;
			res = mid;
		} else {
			r = mid - 1;
		}
	}
	if (calc(res) <= k) return 0;
	calc(res + 1);
	return dp[n].first - (res + 1) * 1ll * k;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> k >> l >> s;
	for (int i = 0; i < n; ++i) {
		a[i] = islower(s[i]) > 0;
	}
	int ans = INF;
	ans = min(ans, solve());
	for (int i = 0; i < n; ++i) {
		a[i] = isupper(s[i]) > 0;
	}
	ans = min(ans, solve());
	cout << ans << endl;
	
	return 0;
}
```
