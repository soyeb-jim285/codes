# Tutorial_(en)

Thanks for participating in the round, we hope you liked the problems!

 **Solve count predictions (official div. 2)**

| Handle | A | B | C | D | E1 | E2 | F |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Vladithur](https://codeforces.com/profile/Vladithur "Master Vladithur") | 16K | 8K | 3K | 900 | 500 | 50 | 4 |
| [GlowCheese](https://codeforces.com/profile/GlowCheese "Master GlowCheese") | 14K | 9K | 5K | 500 | ? | ? | ? |
| [thanhchauns2](https://codeforces.com/profile/thanhchauns2 "Candidate Master thanhchauns2") | 14K | 8K | 2K | 1K | 500 | ? | ? |
| [QuangBuiCPP](https://codeforces.com/profile/QuangBuiCPP "Expert QuangBuiCPP") | 14K | 7K | 2K | 1K | 500 | 24 | 5 |
| [welleyth](https://codeforces.com/profile/welleyth "Master welleyth") | 16K | 10K | 4K | 1.5K | 600 | 130 | 2 |
| [Kon567889](https://codeforces.com/profile/Kon567889 "Master Kon567889") | 14K | 10K | 5K | 2K | ? | ? | 5 |

[1712A - Wonderful Permutation](../problems/A._Wonderful_Permutation.md "Codeforces Round 813 (Div. 2)")

 **Hint**The smallest possible sum is 1+2+…+k.

 **Tutorial**
### [1712A - Wonderful Permutation](../problems/A._Wonderful_Permutation.md "Codeforces Round 813 (Div. 2)")

For any permutation $p$ of length $n$, the final sum $p_1 + p_2 + \ldots + p_k$ after some number of operations can't be less than $1 + 2 + \ldots + k$. 

This means that we need to apply the operation at least once for every $i$ such that $1 \le i \le k$ and $p_i > k$. Every time we apply it, we have to choose some index $j$ such that $k < j \le n$ and $p_j \le k$. 

This is always possible since initially the number of suitable $i$ is equal to the number of suitable $j$, and one operation decreases both the number of suitable $i$ and the number of suitable $j$ by one. 

It is easy to see that in the end, the set $\{p_1, p_2, \ldots, p_k \}$ only contains the values $\{1, 2, \ldots , k \}$, which means that the sum is equal to $1 + 2 + \ldots + k$, which is the smallest sum we can get.

So the answer is the the number of $i$ such that $1 \le i \le k$ and $p_i > k$.

Complexity: $\mathcal{O}(n)$

 **Solution**
```cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = 'n';
typedef long long ll;
typedef long double ld;

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		
		vector<int> b = a;
		sort(all(b));
		int x = b[k - 1];
		
		int ans = 0;
		for (int i = 0; i < k; i++) {
			if (a[i] > x) ans++;
		}
		cout << ans << nl;
	}
}
```
Bonus: solve for every kk from 11 to nn for n≤105n≤105.

[1712B - Woeful Permutation](../problems/B._Woeful_Permutation.md "Codeforces Round 813 (Div. 2)")

 **Hints****Hint 1**In an optimal answer, for all 1≤i≤n, lcm(i,pi)=i⋅pi.

 **Hint 2**lcm(x,x+1)=x⋅(x+1).

 **Hint 3**lcm(x,x+1)+lcm(x+1,x)=x2+(x+1)2−1.

 **Tutorial**
### [1712B - Woeful Permutation](../problems/B._Woeful_Permutation.md "Codeforces Round 813 (Div. 2)")

A well know fact is that gcd(a,b)⋅lcm(a,b)=a⋅b for any two positive integers a and b. Since gcd(x,x+1)=1 for all positive x, we get that lcm(x,x+1)=x⋅(x+1). 

All of this should hint that for even n, the optimal permutation looks like this: 2,1,4,3,…,n,n−1. Add for odd n, it looks like this: 1,3,2,5,4,…,n,n−1.

Complexity: O(n)

Turns out the formal proof is pretty hard. You are welcome to try and find something simpler.

Define f(x,y) as x⋅y if x≠y, and x otherwise. It is easy to see that lcm(x,y)≤f(x,y). We will find the maximum possible value of f(1,p1)+…f(n,pn) and show that it is reached by our construction.

Suppose we want to solve this problem: find the max possible value of 1⋅p1+…+n⋅pn, if for all i>1, pi≠i. This is equivalent to maximizing f(1,p1)+…f(n,pn), because if there is such an index i, it is always optimal to swap pi with pj for any 1≤j<i.

Let's build a graph on this permutation with n vertices and add all edges i→pi. Except for maybe p1=1, all the other cycles have a length of at least 2. 

Let's look at one such cycle x1,x2,…,xk. The optimal value with no restrictions on the value of pi would be x21+x22+…+x2k, but right now we have x1⋅x2+x2⋅x3+…+xk⋅x1. Subtracting one from the other:

x21+x22+…+x2k−(x1⋅x2+x2⋅x3+…+xk⋅x1)= =x212−x1⋅x2+x222+x222−x2⋅x3+x232+…+x2k2−xk⋅x1+x212= =(x1−x2)2+(x2−x3)2+…+(xk−x1)22≥ ≥|x1−x2|+|x2−x3|…+|xk−x1|2≥ ≥max(x1…xk)−min(x1…xk)

So we need to minimize the sum of max(x1…xk)−min(x1…xk) over all cycles. 

If n is even, it is easy to see the minimum possible value of this is n2, and it doesn't matter what p1 equals to. 

For odd n we have to look at two cases: p1=1 and p1≠1. In the first case, the minimum possible sum is n−12, in the second case, it is n+12, which is worse that in the previous case.

Returning to the original problem, our constructions also achieve this minimal difference from 12+22+…n even when we change f back into lcm, so they are optimal.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = 'n';
typedef long long ll;
typedef long double ld;

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (n % 2 == 0) {
			for (int i = 1; i <= n; i += 2) {
				cout << i + 1 << ' ' << i << ' ';
			}
			cout << nl;
		} else {
			cout << 1 << ' ';
			for (int i = 2; i <= n; i += 2) {
				cout << i + 1 << ' ' << i << ' ';
			}
			cout << nl;
		}
	}
}

```
Bonus: try to prove the solution without the editorial!

[1712C - Sort Zero](../problems/C._Sort_Zero.md "Codeforces Round 813 (Div. 2)")

 **Hints****Hint 1**The operation only decreases numbers.

 **Hint 2**An array is sorted if there is no index i such that ai>ai+1.

 **Hint 3**Suppose there is an index i such that ai>ai+1. What operations do you need to perform to make ai≤ai+1?

 **Tutorial**
### [1712C - Sort Zero](../problems/C._Sort_Zero.md "Codeforces Round 813 (Div. 2)")

An array is sorted in non-decreasing order if and only if there is no index $i$ such that $a_i > a_{i + 1}$. This leads to a strategy: while there is at least one such index $i$, apply one operation with $x = a_i$.

Why is this optimal? Since our operation can only decrease values, and we must decrease $a_i$ so that $a_i > a_{i + 1}$ is no longer true, this leaves us no choice but to use the operation with $x = a_i$.

You can simulate this strategy by maintaining a set of bad indices, since if an index $i$ becomes bad, after you apply an operation with $x = a_i$, it can never become bad again. So in total, there are at most $2 \cdot (n - 1)$ operations with the set.

Complexity: $\mathcal{O}(n \log n)$ or $\mathcal{O}(n)$, depending on which set you use.

Note: you can solve the problem in $\mathcal{O}(n)$ by noticing that if an index $i$ is bad, we need to apply the operation for all unique non-zero values in $\{a_1 \ldots a_i\}$. This is also quite a bit shorter to code.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())
 
const char nl = 'n';
typedef long long ll;
typedef long double ld;
 
using namespace std;
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		map<int, vector<int>> p;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			p[a[i]].push_back(i);
		}
		
		int ans = 0;
		set<int> ts;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) ts.insert(i);
		}
		
		while (!ts.empty()) {
			int i = *ts.begin();
			int x;
			if (a[i] > 0) {
				x = a[i];
			} else {
				x = a[i + 1];
			}
			
			for (int j: p[x]) {
				a[j] = 0;
				ts.erase(j - 1);
				ts.erase(j);
				if (j > 0 && a[j - 1] > a[j]) ts.insert(j - 1);
				if (j + 1 < n && a[j] > a[j + 1]) ts.insert(j);
			}
			ans++;
		}
		
		cout << ans << nl;
	}
}

```
Bonus: solve for when aiai can also be negative.

[1712D - Empty Graph](../problems/D._Empty_Graph.md "Codeforces Round 813 (Div. 2)")

 **Hints****Hint 1**d(u;v)≤2⋅min(a1…an)

 **Hint 2***diameter* ≤2⋅min(a1…an)

 **Hint 3***diameter* ≤max1≤i≤n−1min(ai,ai+1)

 **Hint 4**Binary search on the answer or do a clever greedy.

 **Tutorial**
### [1712D - Empty Graph](../problems/D._Empty_Graph.md "Codeforces Round 813 (Div. 2)")

First of all, we will always use the operation to assign $10^9$ to $a_i$.

1. Suppose $u < v$. Then $\operatorname{d}(u, v) = \min(\min(a_u \ldots a_v), 2 \cdot \min(a_1 \ldots a_n))$.

Proof: since the weight of an edge is always $\ge \min(a_1 \ldots a_n)$, the best we can do with one edge is $\min(a_u \ldots a_v)$. And the best we can possibly do with two edges is $2 \cdot \min(a_1 \ldots a_n)$, which turns out possible to achieve.

Subproof: suppose $i_{min}$ is the index of one of the minimums in the array. If $u \le i_{min} \le v$, then $\min(a_u \ldots a_v)$ is optimal, so we don't need two edges in the first place. Else, either $i_{min} < u$ or $i_{min} > v$. In the first case, we can notice that $\operatorname{d}(u, 1) + \operatorname{d}(1, v) = 2 \cdot \min(a_1 \ldots a_n)$. In the second case, $\operatorname{d}(u, n) + \operatorname{d}(n, v) = 2 \cdot \min(a_1 \ldots a_n)$. 

$ $

2. The diameter of the graph is equal to $\max\limits_{1 \le i \le n - 1}{\operatorname{d}(i, i + 1)} = \min \left( \max\limits_{1 \le i \le n - 1}{\min(a_i,a_{i+1})}, 2 \cdot \min(a_1 \ldots a_n) \right)$.

Proof: since the minimum of a subsegment can only decrease when it's length increases, it is optimal to look only at the distance between two adjacent vertices.

Now we can either do binary search on the answer, or we can do a clever greedy. 

$ $

Binary search solution:

Suppose the answer is $\ge ans$. First of all, we need to apply the operation for all $a_i < \frac{ans}{2}$. If there are not enough operations to do this, return false. Otherwise assign $10^9$ to such $a_i$. If there are no operations left, just calculate the diameter and see if it is $\ge ans$.

If there is at least one operation left, there are two cases: $k = 1$ and $k \ge 2$. If the first case, it is optimal to apply our operation near one of the maximums in the array to maximize $\min(a_i, a_{i + 1})$, so we need to return true if $\max(a_1 \ldots a_n) \ge ans$. With $k > 1$, it is optimal to apply the operation near an index which has been turned into $10^9$, so we always return true.

Make sure to binary search on $ans$ from $1$ to $10^9$ inclusive. Doing it from $1$ to $2\cdot 10^9$ needs another case to work.

Complexity: $\mathcal{O}(n \log A)$.

$ $

Greedy solution:

We can actually maintaining the diameter of the graph while supporting point update queries (set $a_i$ to some value). To do this, we can use any structure that can get $\max\limits_{1 \le i \le n - 1}{\min(a_i,a_{i+1})}$ (multiset, segment tree) and another structure to maintain the minimum in the array.

Change the $k - 1$ smallest values in the array into $10^9$. For every $i$ from $1$ to $n$, change $a_i$ to $10^9$, get the diameter, and then change $a_i$ back to it's original value. The answer is the max value over all the returned diameters.

Proof: obviously works for $k = 1$, so suppose $k \ge 2$. Since we changed at least one value, we will check if having two adjacent $10^9$ is optimal, maximizing $\max\limits_{1 \le i \le n - 1}{\min(a_i,a_{i+1})}$. And we will also check if we need to change the $k$-th smallest value, in this case maximizing $2 \cdot \min(a_1 \ldots a_n)$.

Complexity: $\mathcal{O}(n \log n)$

Note: it is also possible to solve without data structures by doing a bit more casework, but the solution is still $\mathcal{O}(n \log n)$ due to sorting.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = 'n';
typedef long long ll;
typedef long double ld;

using namespace std;

const int inf = 1000000000;

bool f(vector<int> a, int k, int ans) {
	int n = gsize(a);
	int dk = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] * 2 < ans) {
			a[i] = inf;
			k--;
			dk++;
		}
	}
	
	if (k < 0) return false;
	if ((k > 0 && dk > 0) || k >= 2) return true;
	
	if (k == 1 && dk == 0) {
		return *max_element(all(a)) >= ans;
	}
	
	for (int i = 0; i < n - 1; i++) {
		if (min(a[i], a[i + 1]) >= ans) return true;
	}
	
	return false;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int lb = 0, ub = inf, tans = 0;
	while (lb <= ub) {
		int tm = (lb + ub) / 2;
		if (f(a, k, tm)) {
			tans = tm;
			lb = tm + 1;
		} else {
			ub = tm - 1;
		}
	}
	
	cout << tans << nl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) solve();
}

```
Bonus: solve for every kk from 11 to nn.

[1712E2 - LCM Sum (hard version)](../problems/E2._LCM_Sum_(hard_version).md "Codeforces Round 813 (Div. 2)")

 **Hints****Hint 1**Count the number of "bad" triplets such that lcm(i,j,k)<i+j+k.

 **Hint 2**lcm(i,j,k)≤2⋅k in a bad triplet.

 **Hint 3**A triplet is bad iff lcm(i,j,k)=k or (lcm(i,j,k)=2⋅k and i+j>k).

 **Hint 4**lcm(i,j,k)=x implies i, j, and k are all divisors of x.

 **Hint 5**For every k, iterate over all pairs of divisors of 2⋅k.

 **Hint 6**Think of the "bad" triplets as of segments [i;k] with some weight.

 **Hint 7**Solve in offline.

 **Tutorial**
### [1712E2 - LCM Sum (hard version)](../problems/E2._LCM_Sum_(hard_version).md "Codeforces Round 813 (Div. 2)")

Let's count the number of bad triplets that don't satisfy the condition, i.e. $\operatorname{lcm}(i,j,k) < i + j + k$. Then the answer for one test case is $\frac{(r - l + 1) \cdot (r - l) \cdot (r - l - 1)}{6} - $ the number of bad triplets.

Since $i < j < k$, a triplet is bad only when $\operatorname{lcm}(i,j,k) = k$ or ($\operatorname{lcm}(i,j,k) = 2 \cdot k$ and $i + j > k$). This means that both $i$ and $j$ must be a divisor of $2\cdot k$. 

For every segment $[i; k]$ where $i$ is a divisor of $2 \cdot k$, let's count the number of $j$ such that $i < j < k$. Let's call it the weight of the segment. Turns out that for the current constraints, for every $k$, we can iterate over all pairs of $1 \le i < j < k$, where $i$ and $j$ are divisors of $2 \cdot k$, and check if the triplet is bad. If it is, then we increase the weight of the segment $[i; k]$ by one. 

To get answers for the test cases, we just need to find the sum of the weights of the segments $[i; k]$ that are inside $[l; r]$. This is a pretty standard problem, which can be solved in offline using a data structure that supports point add and range sum. 

It is possible to solve E1 without a data structure by iterating over the segments and checking for every one of them if it lies inside $[l; r]$.

Complexity: $\mathcal{O}(n \log^2 n + t \log n + \sum_{i = 1}^n \sigma_0(2 \cdot i)^2)$ with a seg tree ($\sum_{i = 1}^n \sigma_0(2 \cdot i)$ is about $n \log n$ and a seg tree update works in $\mathcal{O}(\log n)$, so we get $n \log^2 n$). 

You can also use sqrt decomposition to get $\mathcal{O}(n \log n + t \sqrt n + \sum_{i = 1}^n \sigma_0(2 \cdot i)^2)$.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())
 
const char nl = 'n';
typedef long long ll;
typedef long double ld;
 
using namespace std;

const int maxn = 200000; 

int t[(maxn + 1) * 4];

void update(int v, int tl, int tr, int i, int x) {
	t[v] += x;
	if (tl != tr - 1) {
		int tm = (tl + tr) / 2;
		if (i < tm) update(2*v + 1, tl, tm, i, x);
		else update(2*v + 2, tm, tr, i, x);
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (l >= r) return 0;
	if (tl == l && tr == r) return t[v];
	else {
		int tm = (tl + tr) / 2;
		int r1 = query(2*v + 1, tl, tm, l, min(r, tm));
		int r2 = query(2*v + 2, tm, tr, max(l, tm), r);
		return r1 + r2;
	}
}
 
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	vector<vector<int>> d(2*maxn + 1);
	
	for (int i = 1; i <= maxn; i++) {
		for (int j = i; j <= 2*maxn; j += i) {
			d[j].push_back(i);
		}
	}
	
	vector<vector<pair<int, int>>> segs(maxn + 1);
	
	for (int k = 1; k <= maxn; k++) {
		for (int ti = 0; ti < gsize(d[2*k]); ti++) {
			int i = d[2*k][ti], ct = 0;
			
			for (int tj = ti + 1; tj < gsize(d[2*k]); tj++) {
				int j = d[2*k][tj];
				if (j >= k) break;
				if (i + j > k || (k % i == 0 && k % j == 0)) ct++;
			}
			
			if (ct > 0)	{
				segs[i].emplace_back(k, ct);
			}
		}
	}
	
	
	
	int T;
	cin >> T;
	
	vector<ll> ans(T);
	vector<array<int, 3>> queries;
	
	for (int i = 0; i < T; i++) {
		ll l, r;
		cin >> l >> r;
		queries.push_back({l, r, i});
		ans[i] = (r - l + 1) * (r - l) * (r - l - 1) / 6;
	}
	
	sort(all(queries));
	
	int ti = T - 1;
	for (int i = maxn; i >= 1; i--) {
		
		// Update ST
		for (auto [r, ct]: segs[i]) {
			update(0, 0, maxn + 1, r, ct);
		}
		
		// Get Answers
		while (ti >= 0 && queries[ti][0] == i) {
			ans[queries[ti][2]] -= query(0, 0, maxn + 1, i, queries[ti][1] + 1);
			ti--;
		}
	}
	for (int i = 0; i < T; i++) cout << ans[i] << nl;
}

```
Bonus: solve the problem in O((n+t)logn)O((n+t)logn) or better.

[1712F - Triameter](../problems/F._Triameter.md "Codeforces Round 813 (Div. 2)")

 **Hints****Hint 1**Let fv be the distance to the closest vertex ∈L to v. You can calculate it for every vertex in O(n).

 **Hint 2**The distance in the new graph d′(u,v) is equal to min(d(u,v),fu+fv+x)

 **Hint 3**Suppose there is a vertex v with fv>0. Then there is always a vertex u in the subtree of v such that fu<fv and depthu > depthv.

 **Hint 4**Think small-to-large merging.

 **Hint 5**Maintain the largest value of depthv over all v with fv=i for all needed i.

 **Hint 6**In this problem, small-to-large merging works in O(n).

 **Hint 7**The diameter is ≤n. So you can increase it by 1 at most n times.

 **Tutorial**
### [1712F - Triameter](../problems/F._Triameter.md "Codeforces Round 813 (Div. 2)")

We will solve the problem independently $q$ times.

Let $f_v$ be the distance to the closest leaf from vertex $v$, can be found using a simple bfs with multiple start sources. Let $d'(u, v)$ be the distance in the resulting graph. 

Then $d'(u, v) = \min(f_u + f_v + x, d(u, v))$. A short proof: we'll either go through an edge between two leaves or we won't. In the second case, the answer is clearly $d(u, v)$. In the first case, our objective is to get to a leaf as fast as possible, use an edge with weight $x$, and then move to the destination vertex.

We want to find the maximum possible value of $d'(u, v)$. As is pretty standard in tree problems, we can do small-to-large merging. Let's maintain $val[v][i] = $ the max value of $depth_u$ over all $u$ in the subtree of $v$ with $f_u = i$.

We have a variable $ans$, initially $ans = 0$. For some $lca$, we will first merge all the subtrees, and then add $lca$ to the merged $val[lca]$. We will also update $ans$ during this. The final answer will be $ans - 1$.

$ $

Merging two subtrees:

Suppose we are merging subtree $u$ into subtree $v$, $len(val[u]) \le len(val[v])$, with some current $lca$:

First of all, iterate $i$ from $0$ to $len(val[u]) - 1$. For every $i$, do this cycle: $j = max(0, ans - i - x)$; if $j < len(val[v])$ and $val[u][i] + val[v][j] - 2 \cdot depth_{lca} \ge ans$, then do $ans := ans + 1$ and continue, else break and continue to the next $i$.

Why does this work? Because all $val$ arrays are sorted in decreasing order. Why? Because for some vertex $v$ with $f_v > 0$, there is always a vertex $u$ in it's subtree with $depth_u > depth_v$.

After we are done with that, update $val[v][i] := \max(val[v][i], val[u][i])$ for every $i < len(val[u])$. 

$ $

Adding $lca$ to the merged $val[lca]$:

When we are adding $lca$ to $val[lca]$, we update the answer in almost the same way, only we set $i$ to $f_{lca}$ and $val[u][i]$ to $depth_{lca}$. After that we either do $val[lca][i] := max(val[lca][i], depth_{lca})$ or if $len(val[lca]) = f_{lca}$, just append $depth_{lca}$ to the back of $val[lca]$.

$ $

Complexity:

This particular variant of small to large merging works in $\mathcal{O}(n)$ since when merging two structures of size $a$ and $b$, the new size is $\min(a, b)$. You can find the proof [here](https://codeforces.com/blog/entry/100910?#comment-897459).

Since we increase $ans$ at most $n$ times, and we can calculate $f_v$ for all vertices in $\mathcal{O}(n)$, the complexity is $\mathcal{O}(n)$ per query, so $\mathcal{O}(q \cdot n)$ for all queries.

Note that doing small-to-large merging once and updating $q$ answers simultaneously is much faster that doing small-to-large merging $q$ times. In the first case, you can even get away with using binary search to update the answer, in the second case you cannot.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = 'n';
typedef long long ll;
typedef long double ld;

using namespace std;

const int maxn = 1000000;
int f[maxn], d[maxn];
vector<int> g[maxn], g2[maxn], val[maxn];
int n, q;

vector<int> ans, x;

void solve() {
	
	for (int v = n - 1; v >= 0; v--) {
		for (int u: g[v]) {
			if (gsize(val[u]) > gsize(val[v])) swap(val[u], val[v]);
			for (int fu = 0; fu < gsize(val[u]); fu++) {
				for (int qi = 0; qi < q; qi++) {
					while (true) {
						int fv = max(0, ans[qi] - fu - x[qi]);
						if (fv < gsize(val[v]) && 
							val[v][fv] + val[u][fu] - 2*d[v] >= ans[qi]) ans[qi]++;
						else break;
					}
				}
			}
			for (int fu = 0; fu < gsize(val[u]); fu++) {
				val[v][fu] = max(val[v][fu], val[u][fu]);
			}
			val[u].clear();
			val[u].shrink_to_fit();
		}
		{
			int fu = f[v];
			for (int qi = 0; qi < q; qi++) {
				while (true) {
					int fv = max(0, ans[qi] - fu - x[qi]);			
					if (fv < gsize(val[v]) && 
						val[v][fv] - d[v] >= ans[qi]) ans[qi]++;
					else break;
				}
			}
			if (fu == gsize(val[v])) {
				val[v].push_back(d[v]);
			}
		}
	}
	
	for (int i = 0; i < q; i++) {
		ans[i]--;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	vector<int> deg(n);
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		d[i] = d[p - 1] + 1;
		g[p - 1].push_back(i);
		g2[i].push_back(p - 1);
	}
	
	{
		queue<int> qe;
		vector<bool> used(n, false);
		for (int i = 0; i < n; i++) {
			if (gsize(g2[i]) + gsize(g[i]) == 1) {
				qe.push(i);
				used[i] = true;
			}
		}
		
		while (!qe.empty()) {
			int v = qe.front();
			qe.pop();
			for (int u: g[v]) {
				if (used[u]) continue;
				f[u] = f[v] + 1;
				qe.push(u);
				used[u] = true;
			}
			
			for (int u: g2[v]) {
				if (used[u]) continue;
				f[u] = f[v] + 1;
				qe.push(u);
				used[u] = true;
			}
		}
	}
	
	cin >> q;
	for (int i = 0; i < q; i++) {
		int tx;
		cin >> tx;
		x.push_back(tx);
		ans.push_back(0);
	}
	
	solve();
	
	for (int tans: ans) cout << tans << ' ';
	cout << nl;
}
```
Bonus: solve for n,q≤106.

**Don't forget to rate the problems!**

 **Problem Feedback****A*** Good problem 


[*390*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*87*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*18*](https://codeforces.com/data/like?action=like "I like this")
 **B*** Good problem 

 
[*334*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*104*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*52*](https://codeforces.com/data/like?action=like "I like this")
 **C*** Good problem 

 
[*416*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*79*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*20*](https://codeforces.com/data/like?action=like "I like this")
 **D*** Good problem 

 
[*346*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*38*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*84*](https://codeforces.com/data/like?action=like "I like this")
 **E1*** Good problem 

 
[*213*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*35*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*18*](https://codeforces.com/data/like?action=like "I like this")
 **E2*** Good problem 

 
[*150*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*13*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*22*](https://codeforces.com/data/like?action=like "I like this")
 **F*** Good problem 

 
[*59*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*10*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*10*](https://codeforces.com/data/like?action=like "I like this")
PS: Solution codes probably will be added later.

**UPD: explanations of the references:**

 **Click here**Hope you liked them!

 **A**The quote is just a modification of the original title of KonoSuba.

 **B**This is just something I invented, no reference here. Hope you liked the short poem!

 **C**The quote is the meme "people die when they are killed" in the Fate series, changed to fit the programming context. And the title is just "Fate Zero" changed to "Sort Zero".

 **D**"Do you have a wish?" is a recurring phrase in the LN series [HakoMari](https://codeforces.com/https://myanimelist.net/manga/55215/Utsuro_no_Hako_to_Zero_no_Maria), referring to the wish granting "boxes". The title is just "Empty Box" changed to "Empty Graph". Also, "O_o" is a reference to one of the main characters, "O".

 **E**The quote can probably be traced to many origins, but I personally modified the quote "We are legion, for we are many" from the series 86. There were also a lot of 6's and 8's in the sample, which might have helped you guess.

 **F**I didn't really think about this one, just modified a quote from Vivy a bit.

**UPD2: added solution codes (better late than never...)**

