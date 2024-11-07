# Tutorial

[1845A - Forbidden Integer](../problems/A._Forbidden_Integer.md "Educational Codeforces Round 151 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1845A - Forbidden Integer](../problems/A._Forbidden_Integer.md "Educational Codeforces Round 151 (Rated for Div. 2)")

The problem is about considering the least amount of cases possible. I propose the following options.

If $x \neq 1$, then you can always print $n$ ones. So the answer is YES.

If $k = 1$, then no integer is available, so the answer is NO.

If $k = 2$, then only $2$ is available, so you can only collect even $n$. So if it's odd, the answer is NO.

Otherwise, you can always collect $n$ with the following construction: if $n$ is even then take $2$, otherwise take $3$. Then take $\lfloor \frac{n}{2} \rfloor - 1$ twos. You can see that an even $n$ only uses twos, so it fits the previous check. If it's odd, then $k$ is at least $3$, so $3$ is allowed to take.

Overall complexity: $O(n)$ per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n, k, x = map(int, input().split())
	if x != 1:
		print("YES")
		print(n)
		print(*([1] * n))
	elif k == 1 or (k == 2 and n % 2 == 1):
		print("NO")
	else:
		print("YES")
		print(n // 2)
		print(*([3 if n % 2 == 1 else 2] + [2] * (n // 2 - 1)))
```
[1845B - Come Together](../problems/B._Come_Together.md "Educational Codeforces Round 151 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1845B - Come Together](../problems/B._Come_Together.md "Educational Codeforces Round 151 (Rated for Div. 2)")

Let $d(P_1, P_2)$ be the Manhattan distance between points $P_1 = (x_1, y_1)$ and $P_2 = (x_2, y_2)$. Then $d(P_1, P_2) = |x_1 - x_2| + |y_1 - y_2|$.

Note that if you are going from $A$ to $B$ (or to $C$) along the shortest path, the Manhattan distance will be decreasing with each move. So Bob and Carol can walk together as along as they find the next cell that is closer to both $B$ and $C$.

Now note that if they are in the bounding box of cells $B$ and $C$ then there are no such "next cell", since $d(X, B) + d(X, C)$ is constant and equal to $d(A, B)$ if $X$ is in the bounding box. In other words, Bob and Carol can walk together until they reach some cell $X$ inside the bounding box, where they split up.

Finally, let's look at the total distance they will walk: from one side it's $d(A, B) + d(A, C)$. But from the other side it's $2 \cdot d(A, X) + d(X, B) + d(X, C)$.

So, $$d(A, X) = \frac{d(A, B) + d(A, C) - (d(X, B) + d(X, C))}{2}$$ But since $d(X, B) + d(X, C) = d(B, C)$ whichever $X$ is chosen we can calculate answer as $$\frac{d(A, B) + d(A, C) - d(B, C)}{2} + 1$$ where $+1$ is because we are talking about cells $A$, $B$ and $C$ and not just points.

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

pt A, B, C;

inline bool read() {
	if(!(cin >> A.x >> A.y))
		return false;
	cin >> B.x >> B.y;
	cin >> C.x >> C.y;
	return true;
}

int dist(const pt &A, const pt &B) {
	return abs(A.x - B.x) + abs(A.y - B.y);
}

inline void solve() {
	cout << (dist(A, B) + dist(A, C) - dist(B, C)) / 2 + 1 << endl;
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
[1845C - Strong Password](../problems/C._Strong_Password.md "Educational Codeforces Round 151 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1845C - Strong Password](../problems/C._Strong_Password.md "Educational Codeforces Round 151 (Rated for Div. 2)")

Consider the naive solution. You iterate over all password options that fit the criteria on $l$ and $r$ and check if they appear in $s$ as a subsequence.

That check can be performed greedily: find the first occurrence of the first digit of the password, then find the first occurrence after it of the second digit of the password, and so on. If all digits are found, then it's present. Otherwise, it isn't.

Notice how the checks from the $i$-th digit onwards only depend on the position of the $(i-1)$-st digit. Moreover, to have a lower probability to find these digits, we want the $(i-1)$-st digit to be as much to the right as possible.

That leads us to the greedy solution to the full problem. Iterate over the first digit and choose the one that appears as much to the right as possible. Then the same for the second digit, and so on. If any digit is not found in the string after the starting position of the check, then the password that starts with the chosen digits is strong.

So far, the solution sounds like $O(nmD)$, where $D$ is the number of digits (equal to $10$). Which is actually fine under these constraints, but we can do better.

One option is to precalculate something to help us find the next occurrence of each digit. For example, that can be an array of positions of each digit. Then we can use lower_bound on it to find the next one. That would be $O(n + D + mD \log n)$.

Alternatively, you can calculate an array $\mathit{next}[i][j]$ that stores the next occurrence of digit $j$ from position $i$. It's possible to calculate $\mathit{next}[i]$ from $\mathit{next}[i + 1]$. Notice that only $\mathit{next}[i][s[i]]$ changes. So you can copy $\mathit{next}[i + 1]$ into $\mathit{next}[i]$ and set $\mathit{next}[i][s[i]] = i$. Now you can just query the array by looking into the corresponding cells. That would be $O(nD + mD)$.

Finally, let's analyze the complexity of the linear search better. So, for each digit, actually run a while loop that searches the string until it encounters that letter. We proposed that it is $O(nmD)$. Notice that if some iteration of the loop for the $i$-th digit passes a position $x$, then the digits from the $(i+1)$-st onwards won't look into it. So, such position can only be checked in $O(D)$ loops (all loops for the current digit). Thus, each of $n$ positions can only be accessed $O(D)$ times, making the solution $O(m + nD)$, which makes it the fastest of all our options. That is basically the same analysis as two pointers. $O(m)$ comes from the outer loop over digits that you can't really get rid of. However, you can say that $m \le n$ ($m > n$ can be solved in $O(1)$), and call the solution $O(nD)$.

Overall complexity: $O(m + nD)$ for each testcase.

 **Solution (awoo)**
```cpp
import sys
for _ in range(int(sys.stdin.readline())):
	s = [int(c) for c in sys.stdin.readline().strip()]
	n = len(s)
	m = int(sys.stdin.readline())
	l = sys.stdin.readline()
	r = sys.stdin.readline()
	mx = 0
	for i in range(m):
		li = int(l[i])
		ri = int(r[i])
		nmx = mx
		for c in range(li, ri + 1):
			cur = mx
			while cur < n and s[cur] != c:
				cur += 1
			nmx = max(nmx, cur)
		mx = nmx + 1
	print("YES" if mx > n else "NO")
```
[1845D - Rating System](../problems/D._Rating_System.md "Educational Codeforces Round 151 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1845D - Rating System](../problems/D._Rating_System.md "Educational Codeforces Round 151 (Rated for Div. 2)")

Let's fix some $k$ and look at the first and the last moment when the rating should fall below $k$, but doesn't. After such moments, the rating is equal to $k$. So we can "delete" all changes (array elements) between those moments. And the remaining changes (to the left from the first moment and to the right from the last moment) can be considered without any additional constraints (the value of $k$ doesn't affect those changes).

Using this fact, we can see that the total rating is not greater than the sum of the whole array minus some continuous segment. So the maximum possible final rating doesn't exceed the sum of the array minus the minimum sum segment (this segment can be empty, if all elements are positive). In fact, there is always such $k$ that provides such rating. Let the minimum sum segment be $[l; r]$, then $k$ is equal to the prefix sum from $1$-st to $(l-1)$-th positions of the array. 

The only remaining question is: why the rating after $r$-th match is equal to $k$? It can't fall below $k$ (since the rating is at least $k$ already); and if it is greater than $k$, then there is a positive suffix of the segment $[l; r]$, so we can remove it, and the sum of the segment would decrease. Which means the segment $[l; r]$ is not minimum sum segment, which contradicts the previous statement. So the rating after $r$-th match is equal to $k$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    li delta = 0, ans = 0;
    li sum = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
      li x; cin >> x;
      sum += x;
      mx = max(mx, sum);
      if (sum - mx < delta) {
        delta = sum - mx;
        ans = mx;
      }
    }
    cout << ans << 'n';
  }
}
```
[1845E - Boxes and Balls](../problems/E._Boxes_and_Balls.md "Educational Codeforces Round 151 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1845E - Boxes and Balls](../problems/E._Boxes_and_Balls.md "Educational Codeforces Round 151 (Rated for Div. 2)")

Consider a harder problem. For each $k'$ from $0$ to $k$, what's the number of arrangements that have $k'$ as the smallest number of operations needed that obtain them?

That would help us solve the full problem. You just have to sum up the answer for $k'$ such that they have the same parity as $k$ (since, once the arrangement is obtained, you can perform two moves on it and change nothing).

Turns out, calculating the smallest number of operations for a fixed arrangement is not that hard. Let the initial arrangement have balls in boxes $c_1, c_2, \dots, c_t$ for some $t$; the fixed arrangement have balls in boxes $d_1, d_2, \dots, d_t$. Then the first ball in the fixed arrangement has to come from the box of the first ball in the initial one. And so on. So the answer is at least $\sum\limits_{i=1}^t |c_t - d_t|$. That estimate can be achieved. Just move the balls one by one from left to right. So that amount is actually the smallest possible.

That can lead to a dynamic programming solution. Following this construction, let $\mathit{dp}[i][j][k]$ be the number of ways to fill the first $i$ boxes with $j$ balls such that the smallest number of operations to move the first $j$ balls of the initial arrangement into their new boxes is $k$. The transitions are trivial. Either leave the $i$-th (all $0$-indexed) box empty and go to $\mathit{dp}[i+1][j][k]$ or put a ball into it and go to $\mathit{dp}[i+1][j+1][k + |i - c_j|]$. The answer will be in $\mathit{dp}[n][t][k']$ for all $k'$ of the same parity as $k$. That solution is $O(n^2k)$ that is supposedly too much (although unfortunately can be squeezed if you try hard enough).

That solution has surprisingly little to do with the full one but gives us some insight into the problem.

For a faster solution, let's change the way we calculate the smallest number of operations. What is exactly $|c_t - d_t|$? Let $c_t > d_t$. Then on its path the ball crosses the spaces between boxes $c_t$ and $c_t-1$, $c_t-1$ and $c_t-2$, so on until $d_t+1$ and $d_t$. The amount is exactly $(c_t - d_t)$.

Thus, we could instead calculate the number of balls that move across each space between the boxes along their paths and add up the values. Now it's some sort of balance. We could also denote balls going to the right as positive values and going to the left as negative values. Notice how if some ball moves from a box $i$ to a box $i-1$ in the optimal construction, then there is no ball that moves from $i-1$ to $i$. Just because the balls never cross each other paths. So the absolute value of the balance is still what we have to add up.

Intuitively, the value for space between boxes $i$ and $i+1$ is equal to the signed difference between the initial number of balls to the left of it and the one in the current arrangement. If the numbers are different, then we move exactly this amount of ball from one side to another.

Now we can pack it into another dynamic programming. Let $\mathit{dp}[i][j][k]$ be the number of ways to fill the first $i$ boxes, such that the current balance is $j$ and the smallest number of operations to achieve that is $k$.

The transitions are the following. If we place a ball into box $i$, the balance changes to $j + 1 - a_i$ ($a_i$ is whether there was a ball in box $i$ initially) and $|j + 1 - a_i|$ gets added to $k$. If we don't place a ball, the balance changes to $j - a_i$ and $|j - a_i|$ gets added to $k$.

Notice that at the end the balance will be $0$ if and only if we placed as many boxes as there were initially. So, the answer will be in $\mathit{dp}[n][0][k']$ for all $k'$ of the same parity as $k$.

That solution is still $O(n^2k)$ and even worse in the way that $j$ can range from $-n$ to $n$, doubling the runtime.

However, notice how $j$ can't change by more than $1$ on each step. At the same time, $|j|$ always gets added to $k$. Thus, to make $j$ equal to $0$ at the end, we would have to add $|j| + (|j| - 1) + (|j| - 2) + \dots + 1$ to $k$. And since $k$ can't exceed $1500$, $|j|$ actually can't exceed $55$ (more or less $O(\sqrt{k})$).

So, that solution can be optimized to $O(nk^{1.5})$ by reducing the second dimension of the dynamic programming.

In order to store values from $-x$ to $x$ in an array, shift them up by $x$. So the values become from $0$ to $2x$.

In order to avoid $O(nk^{1.5})$ memory, instead of storing all $n$ layers of the dp, only store the current and the next one. That will make it $O(k^{1.5})$ memory. 

Overall complexity: $O(nk^{1.5})$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int MOD = int(1e9) + 7;

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(n);
	forn(i, n) scanf("%d", &a[i]);
	int lim = 1;
	while (lim * (lim + 1) < k * 2) ++lim;
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(2 * lim + 1, vector<int>(k + 1)));
	dp[0][lim][0] = 1;
	forn(ii, n){
		int i = ii & 1;
		int ni = i ^ 1;
		dp[ni] = vector<vector<int>>(2 * lim + 1, vector<int>(k + 1));
		forn(j, 2 * lim + 1) forn(t, k + 1) if (dp[i][j][t]){
			forn(z, 2){
				int nj = j + z - a[ii];
				int nt = t + abs(nj - lim);
				if (nt <= k) dp[ni][nj][nt] = add(dp[ni][nj][nt], dp[i][j][t]);
			}
		}
	}
	int ans = 0;
	for (int t = k & 1; t <= k; t += 2)
		ans = add(ans, dp[n & 1][lim][t]);
	printf("%dn", ans);
	return 0;
}
```
[1845F - Swimmers in the Pool](../problems/F._Swimmers_in_the_Pool.md "Educational Codeforces Round 151 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1845F - Swimmers in the Pool](../problems/F._Swimmers_in_the_Pool.md "Educational Codeforces Round 151 (Rated for Div. 2)")

Firstly, note that there are two different situations when some two swimmers meet: they either move in the same direction, or in opposite directions.

Suppose, swimmers $i$ and $j$ meet while moving in the same direction. We can write some easy system of equation and get that they will meet each $\frac{2l}{|v_i - v_j|}$ seconds. Analogically, if they meet while moving in the opposite directions, they will meet each $\frac{2l}{v_i + v_j}$ seconds.

Let's create array $w$ that will contain all possible values $|v_i \pm v_j|$ exactly once. If $V = \max{v_i}$ then values $w_i \le 2V$ and we can calculate all of them using FFT fast multiplication two times: for sums $v_i + v_j$ and for differences $v_i - v_j$.

Okay, we got all possible $w_i$, how to calculate the answer. For a fixed value $w_i$ meeting moments are $\frac{2l \cdot k}{w_i}$ for all $k$ in segment $[1, k_i]$. $k_i$ is the upper bound and can be calculated as $k_i = \left\lfloor \frac{t \cdot w_i}{2l} \right\rfloor$.

We found that for each $w_i$ there are exactly $k_i$ meeting points, but since in one meeting moment more than two swimmers may meet we need to calculate each value $\frac{2l \cdot k}{w_i}$ exactly once. 

Note that $\frac{2l \cdot k_1}{w_i} = \frac{2l \cdot k_2}{w_j}$ iff $\frac{k_1}{w_i} = \frac{k_2}{w_j}$. And we can rephrase our task as following: calculate the number of unique fractions $\frac{k}{w_i}$ where $1 \le k \le k_i$.

The key idea here is to calculate only irreducible fractions. Suppose we have fractions $\frac{1}{w_i}, \frac{2}{w_i}, \dots, \frac{k_i}{w_i}$. Let's add to the answer only irreducible fractions among them (we will discuss how to do it later). For any other fraction $\frac{k'}{w_i}$ $(k', w_i) = d > 1$ and $d$ is a divisor of $w_i$.

If we fix some divisor $d$ of $w_i$ there will be exactly $\left\lfloor \frac{k_i}{d} \right\rfloor$ fractions $\frac{k'}{w_i}$ with $d | (k', w_i)$. Moreover, numerators will also form a segment $[1, \frac{k_i}{d}]$. So, instead of calculating them now, we will just "pass" that task to $w_j = \frac{w_i}{d}$.

In total, we iterate $w_i$ in decreasing order, add only the number of irreducible fractions $\frac{k}{w_i}$ to the answer. Then iterate over all divisors $d$ of $w_i$ and "update" value $k_j$ for $w_j = \frac{w_i}{d}$ with value $\frac{k_i}{d}$.

How to calculate the number of irreducible fractions $\frac{k}{w_i}$ with $1 \le k \le k_i$? With Möbius function, of course: $$ ir_i = \sum_{d | w_i}{\mu(d) \left\lfloor \frac{k_i}{d} \right\rfloor} $$ since for each divisor $d$ of $w_i$ there are exactly $\left\lfloor \frac{k_i}{d} \right\rfloor$ fractions where $(k', w_i)$ is divisible by $d$.

Both passing calculations and Möbius inversion works in $O(\text{number of divisors}(w_i))$. And since we iterate over all $w_i \le 2 V$, the total complexity is $O(V \log V)$.

Both FFT and next part works in $O(V \log V)$, so the total complexity is $O(n + V \log V)$.

P.S.: If you note that if $w_j = \frac{w_i}{d}$ then $k_j$ is always equal to $\frac{k_i}{d}$ then you can not only simplify the part with "passing down calculations" but get rid of Möbius inversion at all, replacing it with Sieve-like two for-s iterations.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
	fore(i, 0, sz(v)) {
		if(i) out << " ";
		out << v[i];
	}
	return out;
}

const int INF = int(1e9);
const li INF64 = li(1e18);

const int LOGN = 19;
const int N = (1 << LOGN) + 555;

struct comp {
	double x, y;
	comp(double x = .0, double y = .0) : x(x), y(y) {}
	inline comp conj() { return comp(x, -y); }
};

inline comp operator +(const comp &a, const comp &b) {
	return comp(a.x + b.x, a.y + b.y);
}

inline comp operator -(const comp &a, const comp &b) {
	return comp(a.x - b.x, a.y - b.y);
}

inline comp operator *(const comp &a, const comp &b) {
	return comp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

inline comp operator /(const comp &a, const double &b) {
	return comp(a.x / b, a.y / b);
}

namespace FFT {
	const double PI = acosl(-1.0);
	vector<comp> w[LOGN];
	vector<int> rv;

	void precalc() {
		forn(st, LOGN) {
			w[st].resize(1 << st);
			forn(i, 1 << st) {
				double ang = PI / (1 << st) * i;
				w[st][i] = comp(cos(ang), sin(ang));
			}
		}
		rv.assign(1 << LOGN, 0);
	    fore(i, 1, sz(rv))
			rv[i] = (rv[i >> 1] >> 1) | ((i & 1) << (LOGN - 1));
	}
	
	inline void fft(comp a[N], int n, bool inv) {
		int ln = __builtin_ctz(n);
		forn(i, n) {
	        int ni = rv[i] >> (LOGN - ln);
	        if(i < ni) swap(a[i], a[ni]);
	    }
	
		for(int st = 0; st < ln; st++) {
			int len = 1 << st;
			for(int k = 0; k < n; k += (len << 1))
				fore(pos, k, k + len) {
					comp l = a[pos];
					comp r = a[pos + len] * w[st][pos - k];
					
					a[pos] = l + r;
					a[pos + len] = l - r;
				}
		}
	
		if(inv) {
			forn(i, n)
				a[i] = a[i] / n;
			reverse(a + 1, a + n);
		}
	}
	
	comp aa[N], bb[N], cc[N];
	
	inline void multiply(int a[N], int sza, int b[N], int szb, int c[N], int &szc) {
		int ln = 1;
		while(ln < (sza + szb)) // sometimes works max(sza, szb)
			ln <<= 1;
			
		forn(i, ln)
			aa[i] = (i < sza ? a[i] : comp());
		forn(i, ln)
			bb[i] = (i < szb ? b[i] : comp());
			
		fft(aa, ln, false);
		fft(bb, ln, false);
		
		forn(i, ln)
			cc[i] = aa[i] * bb[i];
			
		fft(cc, ln, true);
		
		szc = ln;
		forn(i, szc)
			c[i] = int(cc[i].x + 0.5);
	}
}

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

li l, t;
int n;
vector<int> v;

inline bool read() {
	if(!(cin >> l >> t >> n))
		return false;
	v.resize(n);
	fore (i, 0, n)
		cin >> v[i];
	return true;
}

int mu[N], minD[N];
vector<int> divs[N];

void precalcDivs(int N) {
	fore (d, 1, N) {
		for (int v = d; v < N; v += d)
			divs[v].push_back(d);
	}
	
	mu[1] = 1;
	fore (d, 2, N) {
		if (minD[d] == 0)
			minD[d] = d;
		
		if (minD[d] != minD[d / minD[d]])
			mu[d] = -mu[d / minD[d]];
		
		for (int v = 2 * d; v < N; v += d) {
			if (minD[v] == 0)
				minD[v] = d;
		}
	}
}

int vs[2][N], res[N], ps[N];
li mxk[N];

inline void solve() {
	FFT::precalc();

	fore (i, 0, n) {
		vs[0][v[i]] = 1;
		vs[1][v[i]] = 1;
	}
	int sz = 1 + *max_element(v.begin(), v.end());
	
	int szRes = 0;
	FFT::multiply(vs[0], sz, vs[1], sz, res, szRes);
	
	fore (i, 0, szRes) {
		if (!(i & 1) && vs[0][i >> 1] > 0)
			res[i]--;
		if (res[i] > 0) {
			ps[i] = 1;
		}
	}
	
	memset(vs[1], 0, sizeof vs[1]);
	fore (i, 0, n)
		vs[1][sz - 1 - v[i]] = 1;
	FFT::multiply(vs[0], sz, vs[1], sz, res, szRes);
	
	fore (i, sz, szRes) {
		if (res[i] > 0) {
			ps[i - sz + 1] = 1;
		}
	}
	
	precalcDivs(2 * sz);
	
	int ans = 0;
	for (int i = N - 1; i > 0; i--) {
		if (ps[i] > 0)
			mxk[i] = max(mxk[i], t * 1ll * i / (2ll * l));
		
		for (int d : divs[i]) {
//			ans += mu[d] * (mxk[i] / d);
			ans = norm(ans + mu[d] * int((mxk[i] / d) % MOD));
			mxk[i / d] = max(mxk[i / d], mxk[i] / d);
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
