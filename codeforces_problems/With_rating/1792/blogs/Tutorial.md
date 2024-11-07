# Tutorial

[1792A - GamingForces](../problems/A._GamingForces.md "Educational Codeforces Round 142 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1792A - GamingForces](../problems/A._GamingForces.md "Educational Codeforces Round 142 (Rated for Div. 2)")

The first spell looks pretty weak compared to the second spell. Feels like you almost always replace one with another. Let's show that you can totally avoid casting the spell of the first type twice or more on one monster.

Let the two first spell casts be (i,j) and (i,k) for some monsters i,j and k. You can replace them by a cast of the second spell on i and a cast of the first spell on (j,k). That would deal even more damage to i and the same amount to j and k. The number of casts doesn't change.

Thus, it only makes sense to use the first spell on monsters with 1 health. Calculate the number of them, kill the full pairs of them with the first spell, and use the second spell on the remaining monsters.

Overall complexity: O(n) per testcase.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt1 = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      cnt1 += (x == 1);
    }
    cout << n - cnt1 / 2 << 'n';
  }
}
```
[1792B - Stand-up Comedian](../problems/B._Stand-up_Comedian.md "Educational Codeforces Round 142 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1792B - Stand-up Comedian](../problems/B._Stand-up_Comedian.md "Educational Codeforces Round 142 (Rated for Div. 2)")

First, let Eve tell the jokes of the first type — they will never do any harm. At the same time, let her tell the jokes of the fourth time at the very end — they will not do any good.

Types two and three are kind of opposites of each other. If you tell jokes of each of them one after another, then the moods of both spectators don't change. Let's use that to our advantage. Tell the jokes of these types in pairs until one of them runs out. There's a little corner case here, though. If there were no jokes of the first type, then you can't use a single pair because of the spectators leaves after one joke.

Finally, try to tell the remaining jokes of the same type before the fourth type. So the construction looks like $1, 1, \dots, 1, 2, 3, 2, 3, \dots, 2, 3, 2, 2, 2, \dots, 2, 4, 4, 4, \dots, 4$ with $2$ and $3$ possibly swapped with each other.

Let's recover the answer from that construction. After the first type, both moods are $a_1$. After the alternating jokes, the moods are still the same. After that, one of the spectators will have his/her mood only decreasing until the end. Once it reaches $-1$, the show ends.

Thus, Eve can tell $a_1 + min(a_2, a_3) \cdot 2 + min(a_1 + 1, abs(a_2 - a_3) + a_4)$ jokes if $a_1 \neq 0$. Otherwise, it's always $1$.

Overall complexity: $O(1)$.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
    a1, a2, a3, a4 = map(int, input().split())
    if a1 == 0:
        print(1)
    else:
        print(a1 + min(a2, a3) * 2 + min(a1 + 1, abs(a2 - a3) + a4))
```
[1792C - Min Max Sort](../problems/C._Min_Max_Sort.md "Educational Codeforces Round 142 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1792C - Min Max Sort](../problems/C._Min_Max_Sort.md "Educational Codeforces Round 142 (Rated for Div. 2)")

If the array is already sorted, then the answer is $0$. Otherwise, there is a last operation, after which the permutation takes the form $1, 2, \dots, n$. Which means that the elements $1$ and $n$ are selected as the last operation (because they are at the first and last positions after the operation). Now we know that the last operation is $(1, n)$ and it doesn't matter where exactly these numbers are in the permutation, i. e. we can assume that the answer has increased by $1$, and consider only the numbers $2, 3, \dots, n-2, n-$1. Similarly, for the "remaining" permutation, there are two options, either it is sorted, and then the answer is $1$, or there is a last operation and the numbers $2$ and $n-1$ are used in it. And so on until the "remaining" permutation is sorted or empty.

It remains to find out how to quickly check whether the numbers in the segment $[k, n - k + 1]$ are sorted (they go in the correct order in the initial permutation). Note that this segment corresponds to values of elements, not to positions in the permutation. If this segment is sorted for some $k$, then the answer does not exceed $k-1$.

There are several ways to check, let's consider one of them. Note that if the segment $[k, n - k + 1]$ is sorted for some value $k$, then it will be sorted for large values as well. So we can start with the maximum value of $k$ (which is equal to $\left\lfloor\frac{n+1}{2}\right\rfloor$) and decrease it until the segment remains sorted. Now for each $k$ we need only two checks that $pos_k$ < $pos_{k + 1}$ and $pos_{n - k + 1}$ > $pos_{n - (k + 1) + 1}$, where $pos_i$ is the position of the element $i$ in the permutation.

Thus, we got the solution in linear time.

Another way is to run binary search on $k$ since if the numbers in $[k, n - k + 1]$ appear in the permutation in sorted order, the same holds for $k+1$. This approach yields a solution in $O(n \log n)$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      pos[x] = i;
    }
    int l = (n + 1) / 2, r = (n + 2) / 2;
    while (l > 0 && (l == r || (pos[l] < pos[l + 1] && pos[r - 1] < pos[r]))) {
      --l;
      ++r;
    }
    cout << (n - r + l + 1) / 2 << 'n';
  }
}
```
[1792D - Fixed Prefix Permutations](../problems/D._Fixed_Prefix_Permutations.md "Educational Codeforces Round 142 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1792D - Fixed Prefix Permutations](../problems/D._Fixed_Prefix_Permutations.md "Educational Codeforces Round 142 (Rated for Div. 2)")

Let's try to solve for one of the given permutations. Let it be some $p$. How to make the answer for it at least $1$? Well, we have to find another permutation $q$ such that $p \cdot q = (1, r_2, r_3, \dots, r_m)$. How about at least $k$? Well, the same: $p \cdot q = (1 2 \dots, k, r_{k+1}, \dots, r_m)$.

Push $q$ to the right side of the equation. $p = (1 2 \dots, k, r_{k+1}, \dots, r_m) \cdot q^{-1}$. Now think. What does it actually mean for some permutation to be multiplied by $(1, 2, \dots, k)$? It stays the same. So the first $k$ elements of $p$ will be equal to the first $k$ elements of $q^{-1}$.

Thus, you have to find a permumtation such that its inverse has the longest common prefix with $p$. This can be done in multiple ways. For example, you can store all inverses in a trie and traverse it with $p$ until you reach a dead end. Or simply push all prefixes of each inverse into a set and iterate over $k$. Alternatively, you can just sort inverses and do lower_bound for $p$ in this list — the permutation with longest common prefix will be either the result or the one before it.

Overall complexity: $O(nm)/O(nm \log n)/O(nm^2 \log n)$ per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); i++) 

int get(const vector<int> &a, const vector<int> &b){
	int res = 0;
	while (res < int(a.size()) && a[res] == b[res])
		++res;
	return res;
}

int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, m;
		scanf("%d%d", &n, &m);
		vector<vector<int>> a(n, vector<int>(m));
		forn(i, n) forn(j, m){
			scanf("%d", &a[i][j]);
			--a[i][j];
		}
		vector<vector<int>> b(n, vector<int>(m));
		forn(i, n) forn(j, m) b[i][a[i][j]] = j;
		sort(b.begin(), b.end());
		forn(i, n){
			int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			int ans = 0;
			if (j > 0) ans = max(ans, get(a[i], b[j - 1]));
			if (j < n) ans = max(ans, get(a[i], b[j]));
			printf("%d ", ans);
		}
		puts("");
	}
}
```
[1792E - Divisors and Table](../problems/E._Divisors_and_Table.md "Educational Codeforces Round 142 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1792E - Divisors and Table](../problems/E._Divisors_and_Table.md "Educational Codeforces Round 142 (Rated for Div. 2)")

Firstly, let's factorize $m$. Since $m = m_1 \cdot m_2$ we can factorize $m_1$ and $m_2$ separately and then "unite" divisors. For example, use can get canonical representations of $m_1 = p_1^{f_1} p_2^{f_2} \dots p_k^{f_k}$ and $m_2 = p_1^{g_1} p_2^{g_2} \dots p_k^{g_k}$ to get canonical representation of $m = p_1^{f_1 + g_1} p_2^{f_2 + g_2} \dots p_k^{f_k + g_k}$ and then use it to generate all divisors of $m$.

Let's estimate the number of divisors $divs(m)$. It's convenient for our purposes to estimate it as $O(m^{\frac{1}{3}})$. More precisely, there are at most $105\,000$ divisors for $m \le 10^{18}$ (search "Highly Composite Numbers" for more info).

How to calculate the answer $a_i$ for each divisor $d$? There are two ways.

The intended solution: for each $d$ we are searching for the minimum $x$ that $d = x y$ and $y \le n$. Since $d$ is fixed, the minimum $x$ means the maximum $y \le n$. So let's find $y$ instead. In other words, for each $d$ we need to find the maximum $y$ such that $y$ divides $d$ and $y \le n$. We can do it efficiently with $dp$ on divisors.

Let $dp[d]$ be the maximum $y$ that is a divisor of $d$ and $y \le n$. If $d \le n$ then, obviously, $dp[d] = d$. Otherwise, we know that we are searching $y < d$.

Let say that $p_1, p_2, \dots, p_k$ are the prime divisors of the initial number $m$. Since $y$ is a divisor of $d$ and $y < d$ then exists some $p_i$ among the set of prime divisors such that $y$ is a divisor of $\frac{d}{p_i}$ as well. So, instead of brute search, it's enough to take a value $dp[\frac{d}{p_i}]$.

In other words, if $d > n$ we can calculate $dp[d] = \max\limits_{p_i | d}{dp[\frac{d}{p_i}]}$.

Ok, now we know value $dp[d]$ for each divisor $d$. Since we found the maximum $y \le n$, the last step is to calculate the desired $x = \frac{d}{dp[d]}$ and if $x \le n$ we found the answer $a_i$, otherwise ($x > n$) it means that $d$ is not presented $n \times n$ table and $a_i = 0$.

The total complexity is $O(\sqrt{m_1 + m_2} + divs(m) \cdot z(m) \cdot \log(divs(m)))$ per test, where $divs(m)$ is the number of divisors of $m$ ($divs(m) \le 105\,000$) and $z(m)$ is the number of prime divisor of $m$ ($z(m) \le 15$). Note that complexity is quite high, so you should write it at least a little accurate, for example store $dp[d]$ in an array, not map, and search position of $dp[\frac{d}{p_i}]$ with $lower\\_bound()$.

There is also a way to get rid of extra $\log(divs(m))$ factor if you iterate through $dp$ is a smart way.

The alternative solution (faster, easier, unproven): Let's generate a list of all divisors of $m$ as $d_1, d_2, \dots, d_l$ in the increasing order. For some divisor $d_i$ we are searching the minimum $x$ that is a divisor of $d_i$ and $\frac{d_i}{x} \le n$. It means that $x \ge \left\lceil \frac{d_i}{n} \right\rceil$.

So let's just find the first position $j$ such that $d_j \ge \left\lceil \frac{d_i}{n} \right\rceil$ with $lower\\_bound$ and start iterating from $j$ onward searching the first $d_j$ that is a divisor of $d_i$. The found $d_j$ would be the minimum $x$ we need.

It looks like, in average, we will find the correct $d_j$ quite fast, or we'll break when $d_j > n$.

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
const ld EPS = 1e-9;

int n;
li m1, m2;

inline bool read() {
	if(!(cin >> n >> m1 >> m2))
		return false;
	return true;
}

vector<pt> mFact;
vector<li> divs;

void factM(li m1, li m2) {
	mFact.clear();

	for (int d = 2; d * d <= m1 || d * d <= m2; d++) {
		int cnt = 0;
		while (m1 % d == 0) {
			m1 /= d;
			cnt++;
		}
		while (m2 % d == 0) {
			m2 /= d;
			cnt++;
		}
		if (cnt > 0)
			mFact.push_back({d, cnt});
	}
	if (m1 > m2)
		swap(m1, m2);
	if (m1 > 1)
		mFact.push_back({m1, 1});
	if (m2 > 1) {
		if (m2 == m1)
			mFact.back().y++;
		else
			mFact.push_back({m2, 1});
	}
}

void genDivisors(int pos, li val) {
	if (pos >= sz(mFact)) {
		divs.push_back(val);
		return;
	}
	li cur = val;
	fore (pw, 0, mFact[pos].y + 1) {
		genDivisors(pos + 1, cur);
		if (pw < mFact[pos].y)
			cur *= mFact[pos].x;
	}
}

inline void solve() {
	factM(m1, m2);

	divs.clear();
	genDivisors(0, 1);
	sort(divs.begin(), divs.end());

	vector<int> ans(sz(divs), 0);

	vector<li> dp(sz(divs), -1);
	fore (id, 0, sz(divs)) {
		if (divs[id] <= n)
			dp[id] = divs[id];
		for (auto [p, pw] : mFact) {
			if (divs[id] % p != 0)
				continue;
			
			int pos = int(lower_bound(divs.begin(), divs.end(), divs[id] / p) - divs.begin());
			dp[id] = max(dp[id], dp[pos]);
		}

		if (divs[id] / dp[id] <= n)
			ans[id] = divs[id] / dp[id];
	}

	int cnt = 0;
	int xorSum = 0;
	fore (i, 0, sz(ans)) {
		cnt += ans[i] > 0;
		xorSum ^= ans[i];
	}
	
//	cout << sz(ans) << endl;
//	cout << ans << endl;
	cout << cnt << " " << xorSum << endl;
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
[1792F1 - Graph Coloring (easy version)](../problems/F1._Graph_Coloring_(easy_version).md "Educational Codeforces Round 142 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1792F1 - Graph Coloring (easy version)](../problems/F1._Graph_Coloring_(easy_version).md "Educational Codeforces Round 142 (Rated for Div. 2)")

Lemma: if an undirected graph is disconnected, then its complement is connected. Similarly, if its complement is disconnected, then the graph itself is connected.

Proof: suppose a graph is disconnected. Pick two vertices $x$ and $y$ from different components. Every vertex outside of $x$'s component is connected to $x$ in the complement, and every vertex outside of $y$'s component is connected to $y$ in the complement; the complement also contains the edge from $x$ to $y$, so all vertices in the complement graph belong to the single component.

Why do we need this lemma at all? We can treat the graph formed by blue edges as the complement to the graph formed by red edges. So, if the "red" graph is disconnected, then the "blue" graph is connected, so we don't need to consider the case when some set of vertices is connected by neither color. We only need to make sure that no set of vertices is connected by both colors.

Let $A_n$ be the answer for $n$. Every graph counted in $A_n$ is either red-disconnected or blue-disconnected; since there is a bijection between red-disconnected and blue-disconnected graphs (you can flip the colors of all edges to transform one type into the other), we will count only red-disconnected graphs and multiply it by $2$.

Let $B_n$ be the number of blue-connected graphs with $n$ vertices meeting the properties of the problem statement. It's easy to see that $A_n = 2 \cdot B_n$ if $n > 1$, otherwise $A_n = B_n$ (the case $n = 1$ is special because a graph on one vertex is both red-connected and blue-connected). To calculate $A_n$, let's iterate on $k$ — the number of vertices which are in the same "red" component as $1$. This component must be a red-connected graph which meets the problem statement, so the number of ways to build the graph on these $k$ vertices is $B_k$; there are $\frac{(n-1)!}{(k-1)!(n-k)!}$ ways to choose the vertices in the same component as $1$, and the remaining graph can be either red-connected or blue-connected, so the number of ways to build the remaining graph is $A_{n-k}$.

Thus, we get the following two relations:

$$B_{n} = \sum\limits_{k=1}^{n-1} B_k A_{n-k} \frac{(n-1)!}{(k-1)!(n-k)!}$$

$$A_n = 2 \cdot B_n \textrm{ if } n>1 \textrm{, otherwise } B_n$$

We can calculate all values with dynamic programming using these formulas in $O(n^2)$.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int varMul(int x)
{
    return x;
}

template<typename... Args>
int varMul(int x, Args... args)
{
    return mul(x, varMul(args...));
}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

vector<int> fact, rfact;
vector<int> dp;
int n;

void precalc()
{
    fact.resize(n + 1);
    rfact.resize(n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = mul(i, fact[i - 1]);
    for(int i = 0; i <= n; i++)
        rfact[i] = binpow(fact[i], MOD - 2);
    dp.resize(n + 1, -1);
}

int C(int n, int k)
{
    if(n < 0 || n < k || k < 0) return 0;
    return varMul(fact[n], rfact[k], rfact[n - k]);
}

int calc(int x)
{
    if(dp[x] != -1) return dp[x];
    if(x == 1) return dp[x] = 1;
    if(x == 2) return dp[x] = 1;
    dp[x] = 0;
    int& d = dp[x];
    for(int i = 1; i < x; i++)
    {
        d = add(d, varMul(calc(i), (i == x - 1 ? (MOD + 1) / 2 : calc(x - i)), 2, C(x - 1, i - 1)));
    }   
    return d;
}

int main()
{
    cin >> n;
    precalc();
    cout << add(mul(calc(n), 2), -2) << endl;
}
```
[1792F2 - Graph Coloring (hard version)](../problems/F2._Graph_Coloring_(hard_version).md "Educational Codeforces Round 142 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1792F2 - Graph Coloring (hard version)](../problems/F2._Graph_Coloring_(hard_version).md "Educational Codeforces Round 142 (Rated for Div. 2)")

Please read the tutorial for the easy version first, since this tutorial uses some definitions from it.

Okay, we need more definitions. Here they come:

$$C_0 = 0, C_i = \frac{A_i}{i!} \textrm{ if } i > 0$$

$$D_0 = 0, D_i = \frac{B_i}{(i-1)!} \textrm{ if } i > 0$$

This way, we can transform the formula for $B_n$ to the following:

$$B_n = (n-1)! \cdot \sum\limits_{k=1}^{n-1} C_{n-k} D_k$$.

Or even this, since $C_0 = D_0 = 0$:

$$B_n = (n-1)! \cdot \sum\limits_{k=0}^{n} C_{n-k} D_k$$.

This is almost the convolution of the sequences $C$ and $D$ (with a bit extra additional operations after the convolution), so, to compute the sequence $B$, we just need to compute the sequences $C$ and $D$, and then calculate their convolution with NTT. All that's left is to multiply every element by the corresponding factorial.

But wait, that's not so easy. In order to calculate $C_i$ and $D_i$, we need to know $B_i$. Note that we can ignore the fact that $C_i$ and $D_i$ appear in the formula for $B_i$, since they are multiplied by $0$, so at least we don't have a dependency cycle. Unfortunately, we cannot just straightforwardly use convolution if we don't know the sequences $C_i$ and $D_i$.

The model solution handles it using the following approach. Let's generate $A$, $B$, $C$ and $D$ in parallel: on the $i$-th iteration, calculate $B_i$, then calculate $A_i$, $C_i$ and $D_i$ using it. And sometimes we will calculate the convolution of the sequences $C$ and $D$.

Suppose we want to calculate $B_i$, and the last time we calculated the convolution of $C$ and $D$ was after the iteration $t$. Back then, we knew all elements from $C_0$ to $C_t$ and from $D_0$ to $D_t$. So, the $i$-th term in the convolution of $C$ and $D$ contained the sum of $C_{i-k} D_k$ over all $k$ such that $k \le t$ and $i - k \le t$. So, in order to calculate $B_i$, we have to pick this value from the convolution and then add the sum of $C_{i-k} D_k$ over all $k$ such that $k > t$ or $k \le i - t$, and there are $2(i-t)$ such values.

Suppose we compute the convolution every $K$ iterations. Then the maximum value of $i-t$ is $K$, and every value of $B_i$ is calculated in $O(K)$. We also make $\frac{n}{K}$ convolutions, so the total complexity of this solution will be $O(\frac{n^2 \log n}{K} + nK)$, which can be transformed into $O(n \sqrt{n \log n})$ if we pick $K = \sqrt{n \log n}$.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int LOGN = 18;
const int N = (1 << LOGN);
const int MOD = 998244353;
const int g = 3;

#define forn(i, n) for(int i = 0; i < int(n); i++)

inline int mul(int a, int b)
{
    return (a * 1ll * b) % MOD;
}

inline int norm(int a) 
{
    while(a >= MOD)
        a -= MOD;
    while(a < 0)
        a += MOD;
    return a;
}

inline int binPow(int a, int k) 
{
    int ans = 1;
    while(k > 0) 
    {
        if(k & 1)
            ans = mul(ans, a);
        a = mul(a, a);
        k >>= 1;
    }
    return ans;
}

inline int inv(int a) 
{
    return binPow(a, MOD - 2);
}

vector<int> w[LOGN];
vector<int> iw[LOGN];
vector<int> rv[LOGN];

void precalc() 
{
    int wb = binPow(g, (MOD - 1) / (1 << LOGN));
    
    for(int st = 0; st < LOGN; st++) 
    {
        w[st].assign(1 << st, 1);
        iw[st].assign(1 << st, 1);
        
        int bw = binPow(wb, 1 << (LOGN - st - 1));
        int ibw = inv(bw);
        
        int cw = 1;
        int icw = 1;
        
        for(int k = 0; k < (1 << st); k++) 
        {
            w[st][k] = cw;
            iw[st][k] = icw;
            
            cw = mul(cw, bw);
            icw = mul(icw, ibw);
        }
        
        rv[st].assign(1 << st, 0);
        
        if(st == 0) 
        {
            rv[st][0] = 0;
            continue;
        }
        int h = (1 << (st - 1));
        for(int k = 0; k < (1 << st); k++)
            rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
    }
}

inline void fft(int a[N], int n, int ln, bool inverse) 
{   
    for(int i = 0; i < n; i++) 
    {
        int ni = rv[ln][i];
        if(i < ni)
            swap(a[i], a[ni]);
    }
    
    for(int st = 0; (1 << st) < n; st++) 
    {
        int len = (1 << st);
        for(int k = 0; k < n; k += (len << 1)) 
        {
            for(int pos = k; pos < k + len; pos++) 
            {
                int l = a[pos];
                int r = mul(a[pos + len], (inverse ? iw[st][pos - k] : w[st][pos - k]));
                
                a[pos] = norm(l + r);
                a[pos + len] = norm(l - r);
            }
        }
    }
    
    if(inverse) 
    {
        int in = inv(n);
        for(int i = 0; i < n; i++)
            a[i] = mul(a[i], in);
    }
}

int aa[N], bb[N], cc[N];

vector<int> multiply(vector<int> a, vector<int> b) 
{
    int sza = a.size();
    int szb = b.size();
    int n = 1, ln = 0;
    while(n < (sza + szb))
        n <<= 1, ln++;
    for(int i = 0; i < n; i++)
        aa[i] = (i < sza ? a[i] : 0);
    for(int i = 0; i < n; i++)
        bb[i] = (i < szb ? b[i] : 0);
        
    fft(aa, n, ln, false);
    fft(bb, n, ln, false);
    
    for(int i = 0; i < n; i++)
        cc[i] = mul(aa[i], bb[i]);
        
    fft(cc, n, ln, true);
    
    int szc = n;
    vector<int> c(szc);
    szc = n;
    for(int i = 0; i < n; i++)
        c[i] = cc[i];
    return c;
}                    

int main()
{
    int n;
    cin >> n;
    vector<int> fact(n + 1);
    fact[0] = 1;
    for(int i = 0; i < n; i++)
        fact[i + 1] = mul(fact[i], i + 1);
    precalc();
    vector<int> A = {0, 1, 2};
    vector<int> B = {0, 1, 1};
    vector<int> C = {0, 1, 1};
    vector<int> D = {0, 1, 1};
    vector<int> conv;
    const int K = 2000;
    int last_conv = -1e9;
    while(A.size() <= n)
    {
        int cur = A.size();
        if(cur - last_conv >= K)
        {
            last_conv = cur - 1;
            conv = multiply(C, D);
        }
        /*for(auto x : conv) cerr << x << " ";
        cerr << endl;*/
        int val_A;
        if(last_conv * 2 >= cur)
        {
            val_A = conv[cur];
            // [cur - last_conv, last_conv] are already used
            for(int i = 1; i < (cur - last_conv); i++)
            {
                val_A = norm(val_A + mul(C[i], D[cur - i]));
            }
            for(int i = last_conv + 1; i < cur; i++)
            {
                val_A = norm(val_A + mul(C[i], D[cur - i]));
            }
        }
        else
        {
            val_A = 0;
            for(int i = 1; i <= cur - 1; i++)
            {
                val_A = norm(val_A + mul(C[i], D[cur - i]));
            }
        }
        val_A = mul(val_A, fact[cur - 1]);
        val_A = mul(val_A, 2);
        A.push_back(val_A);
        B.push_back(mul(val_A, inv(2)));
        C.push_back(mul(val_A, inv(fact[cur])));
        D.push_back(mul(B.back(), inv(fact[cur - 1])));
    }
    cout << norm(A[n] - 2) << endl;
}
```
