# Tutorial

All ideas belong to [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov").

[1249A - Yet Another Dividing into Teams](../problems/A._Yet_Another_Dividing_into_Teams.md "Codeforces Round 595 (Div. 3)")

 **Tutorial**
### [1249A - Yet Another Dividing into Teams](../problems/A._Yet_Another_Dividing_into_Teams.md "Codeforces Round 595 (Div. 3)")

The answer is always $1$ or $2$. Why it is so? Because if there is no such pair $i, j$ among all students that $|a_i - a_j| = 1$ then we can take all students into one team. Otherwise, we can divide them into two teams by their programming skill parity.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
		}
		bool ok = true;
		for (int p1 = 0; p1 < n; ++p1) {
			for (int p2 = 0; p2 < p1; ++p2) {
				ok &= abs(a[p1] - a[p2]) != 1;
			}
		}
		cout << 2 - ok << endl;
	}
	
	return 0;
}
```
[1249B1 - Books Exchange (easy version)](../problems/B1._Books_Exchange_(easy_version).md "Codeforces Round 595 (Div. 3)")

 **Tutorial**
### [1249B1 - Books Exchange (easy version)](../problems/B1._Books_Exchange_(easy_version).md "Codeforces Round 595 (Div. 3)")

In this problem you just need to implement what is written in the problem statement. For the kid $i$ the following pseudocode will calculate the answer (indices of the array $p$ and its values are $0$-indexed):


```cpp
  
pos = p[i]  
ans = 1  
while pos != i:  
    ans += 1  
    pos = p[pos]  

```
 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		vector<int> p(n);
		for (int j = 0; j < n; ++j) {
			cin >> p[j];
			--p[j];
		}
		for (int j = 0; j < n; ++j) {
			int cnt = 0;
			int k = j;
			do {
				++cnt;
				k = p[k];
			} while (k != j);
			cout << cnt << " ";
		}
		cout << endl;
	}
	
	return 0;
}
```
[1249B2 - Books Exchange (hard version)](../problems/B2._Books_Exchange_(hard_version).md "Codeforces Round 595 (Div. 3)")

 **Tutorial**
### [1249B2 - Books Exchange (hard version)](../problems/B2._Books_Exchange_(hard_version).md "Codeforces Round 595 (Div. 3)")

In this problem, we can notice that when we calculate the answer for the kid $i$, we also calculate the answer for kids $p_i$, $p_{p_i}$ and so on. So we can a little bit modify the pseudocode from the easy version to calculate answers faster:


```cpp
  
pos = p[i]  
ans = 1  
cycle = [i]  
while pos != i:  
    cycle.append(pos)  
    ans += 1  
    pos = p[pos]  
for el in cycle: res[el] = ans  

```
And of course, we don't need to run this while for all elements for which we already calculated the answer. Total time complexity is $O(n)$ because you'll process each element exactly once.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		vector<int> p(n);
		for (int j = 0; j < n; ++j) {
			cin >> p[j];
			--p[j];
		}
		vector<int> used(n);
		vector<int> ans(n);
		for (int j = 0; j < n; ++j) {
			if (!used[j]) {
				vector<int> cur;
				while (!used[j]) {
					cur.push_back(j);
					used[j] = true;
					j = p[j];
				}
				for (auto el : cur) ans[el] = cur.size();
			}
		}
		for (int j = 0; j < n; ++j) cout << ans[j] << " ";
		cout << endl;
	}
	
	return 0;
}
```
[1249C1 - Good Numbers (easy version)](../problems/C1._Good_Numbers_(easy_version).md "Codeforces Round 595 (Div. 3)")

 **Tutorial**
### [1249C1 - Good Numbers (easy version)](../problems/C1._Good_Numbers_(easy_version).md "Codeforces Round 595 (Div. 3)")

As you can see from the example, the maximum answer doesn't exceed $2 \cdot 10^4$. So we can run some precalculation before all queries, which will find all good numbers less than $2 \cdot 10^4$. The number is good if it has no $2$ in the ternary numeral system. When you read the next query, you can increase $n$ until you find some precalculated good number. Time complexity is $O(nq + n \log n)$.

You also can implement the solution which doesn't use any precalculations and just increase $n$ each time in each query and checks if the number is good inside this loop. Then time complexity will be $O(n q \log n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		while (true) {
			bool ok = true;
			int cur = n;
			while (cur > 0) {
				if (ok && cur % 3 == 2) ok = false;
				cur /= 3;
			}
			if (ok) break;
			++n;
		}
		cout << n << endl;
	}
	
	return 0;
}
```
[1249C2 - Good Numbers (hard version)](../problems/C2._Good_Numbers_(hard_version).md "Codeforces Round 595 (Div. 3)")

 **Tutorial**
### [1249C2 - Good Numbers (hard version)](../problems/C2._Good_Numbers_(hard_version).md "Codeforces Round 595 (Div. 3)")

Let's see the representation of $n$ in the ternary numeral system. If it has no twos, then the answer is $n$. Otherwise, let $pos_2$ be the maximum position of $2$ in the ternary representation. Then we obviously need to replace it with $0$ and add some power of three to the right from it. Let $pos_0$ be the leftmost position of $0$ to the right from $pos_2$. We can add $3^{pos_0}$ and replace all digits from the position $pos_0 - 1$ to the position $0$ with $0$. Then the resulting number will be good because we replaced all twos with zeros and the minimum because, in fact, we added only one power of three and this power is the minimum one we could add.

Time complexity is $O(\log n)$ per query.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const long long INF64 = 1e18;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		long long n;
		cin >> n;
		vector<int> vals;
		int pos2 = -1;
		while (n > 0) {
			vals.push_back(n % 3);
			if (vals.back() == 2) pos2 = int(vals.size()) - 1;
			n /= 3;
		}
		vals.push_back(0);
		if (pos2 != -1) {
			int pos0 = find(vals.begin() + pos2, vals.end(), 0) - vals.begin();
			vals[pos0] = 1;
			for (int i = pos0 - 1; i >= 0; --i) {
				vals[i] = 0;
			}
		}
		long long ans = 0;
		long long pw = 1;
		for (int i = 0; i < int(vals.size()); ++i) {
			ans += pw * vals[i];
			pw *= 3;
		}
		if (vals.back() == 1) ans = pw / 3;
		cout << ans << endl;
	}
	
	return 0;
}
```
[1249D1 - Too Many Segments (easy version)](../problems/D1._Too_Many_Segments_(easy_version).md "Codeforces Round 595 (Div. 3)")

 **Tutorial**
### [1249D1 - Too Many Segments (easy version)](../problems/D1._Too_Many_Segments_(easy_version).md "Codeforces Round 595 (Div. 3)")

In this problem, the following greedy solution works: let's find the leftmost point covered by more than $k$ segments. We should fix it somehow. How to do it? Let's find some segment that was not removed already, it covers this point and its rightmost end is maximum possible, and remove this segment.

You can implement it in any time you want, even in $O(n^3)$ naively.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 250;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> segs(n);
	vector<int> cnt(N);
	for (int i = 0; i < n; ++i) {
		cin >> segs[i].first >> segs[i].second;
		++cnt[segs[i].first];
		--cnt[segs[i].second + 1];
	}
	
	for (int i = 0; i + 1 < N; ++i) {
		cnt[i + 1] += cnt[i];
	}
	
	vector<int> ans(n);
	for (int i = 0; i < N; ++i) {
		while (cnt[i] > k) {
			int pos = -1;
			for (int p = 0; p < n; ++p) {
				if (!ans[p] && (segs[p].first <= i && i <= segs[p].second) && (pos == -1 || segs[p].second > segs[pos].second)) {
					pos = p;
				}
			}
			assert(pos != -1);
			for (int j = segs[pos].first; j <= segs[pos].second; ++j) {
				--cnt[j];
			}
			ans[pos] = 1;
		}
	}
	
	cout << accumulate(ans.begin(), ans.end(), 0) << endl;
	for (int i = 0; i < n; ++i) {
		if (ans[i]) cout << i + 1 << " ";
	}
	cout << endl;
	
	return 0;
}
```
[1249D2 - Too Many Segments (hard version)](../problems/D2._Too_Many_Segments_(hard_version).md "Codeforces Round 595 (Div. 3)")

 **Tutorial**
### [1249D2 - Too Many Segments (hard version)](../problems/D2._Too_Many_Segments_(hard_version).md "Codeforces Round 595 (Div. 3)")

In this problem, we need to implement the same greedy solution as in the easy version, but faster. Firstly, let's calculate for each point the number of segments covering it. We can do it using standard trick with prefix sums: increase $cnt_{l_i}$, decrease $cnt_{r_i + 1}$ and build prefix sums on the array $cnt$.

Let's maintain the set of segments that cover the current point, sorted by the right endpoint. We can do this with almost the same trick: append to the array $ev_{l_i}$ the index $i$ that says us that in the point $l_i$ the $i$-th segment is opened. And add to the $ev_{r_i + 1}$ the index $-i$ that says us that in the point $r_i + 1$ the $i$-th segment is closed. Note that you need to add $1$-indexed values $i$ because $+0$ and $-0$ are the same thing actually. We can change the array $cnt$ to carry the number of segments covering each point using some structure, but we don't need to do it. Let's maintain the variable $curSub$ that will say us the number of segments covering the current point that was already removed. Also, let's carry another one array $sub$ which will say us when we need to decrease the variable $curSub$.

So, we calculated the array of arrays $ev$, the array $cnt$ and we can solve the problem now. For the point $i$, let's remove and add all segments we need, using the array $ev_i$ and add $sub_i$ to $curSub$. Now we know that the set of segments is valid, $curSub$ is also valid and we can fix the current point if needed. While $cnt_i - curSub > k$, let's repeat the following sequence of operations: take the segment with the maximum right border $rmax$ from the set, remove it, increase $curSub$ by one and decrease $sub_{rmax + 1}$ by one.

Note that when we remove segments from the set at the beginning of the sequence of moves for the point $i$, we don't need to remove segments that we removed by fixing some previous points, and we need to pay attention to it.

Time complexity: $O(n \log n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 200200;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> segs(n);
	vector<int> cnt(N);
	vector<vector<int>> ev(N);
	for (int i = 0; i < n; ++i) {
		cin >> segs[i].first >> segs[i].second;
		++cnt[segs[i].first];
		--cnt[segs[i].second + 1];
		ev[segs[i].first].push_back(i + 1);
		ev[segs[i].second + 1].push_back(-i - 1);
	}
	
	for (int i = 0; i + 1 < N; ++i) {
		cnt[i + 1] += cnt[i];
	}
	
	vector<int> ans(n), sub(N);
	set<pair<int, int>> curSegs;
	int curSub = 0;																																				
	for (int i = 0; i < N; ++i) {
		curSub += sub[i];
		for (auto it : ev[i]) {
			if (it > 0) {
				curSegs.insert(make_pair(segs[it - 1].second, it - 1));
			} else {
				auto iter = curSegs.find(make_pair(segs[-it - 1].second, -it - 1));
				if (iter != curSegs.end()) curSegs.erase(iter);
			}
		}
		while (cnt[i] - curSub > k) {
			assert(!curSegs.empty());
			int pos = curSegs.rbegin()->second;
			curSegs.erase(prev(curSegs.end()));
			++curSub;
			--sub[segs[pos].second + 1];
			ans[pos] = 1;
		}
	}
	
	cout << accumulate(ans.begin(), ans.end(), 0) << endl;
	for (int i = 0; i < n; ++i) {
		if (ans[i]) cout << i + 1 << " ";
	}
	cout << endl;
	
	return 0;
}
```
[1249E - By Elevator or Stairs?](../problems/E._By_Elevator_or_Stairs_.md "Codeforces Round 595 (Div. 3)")

 **Tutorial**
### [1249E - By Elevator or Stairs?](../problems/E._By_Elevator_or_Stairs_.md "Codeforces Round 595 (Div. 3)")

This is easy dynamic programming problem. It is easy to understand that we don't need to go down at all (otherwise your solution will be Dijkstra's algorithm, not dynamic programming). Let $dp_{i, 0}$ be the minimum required time to reach the floor $i$ if we not in the elevator right now and $dp_{i, 1}$ be the minimum required time to reach the floor $i$ if we in the elevator right now.

Initially, all values $dp$ are $+\infty$, except $dp_{1, 0} = 0$ and $dp_{1, 1} = c$.

Transitions are pretty easy: 

* $dp_{i + 1, 0} = min(dp_{i + 1, 0}, dp_{i, 0} + a_i)$ (we was not in the elevator and going to the next floor using stairs);
* $dp_{i + 1, 0} = min(dp_{i + 1, 0}, dp_{i, 1} + a_i)$ (we was in the elevator and going to the next floor using stairs);
* $dp_{i + 1, 1} = min(dp_{i + 1, 1}, dp_{i, 0} + b_i + c)$ (we was not in the elevator and going to the next floor using elevator);
* $dp_{i + 1, 1} = min(dp_{i + 1, 1}, dp_{i, 1} + b_i)$ (we was in the elevator and going to the next floor using elevator).

The answer for the $i$-th floor is $min(dp_{i, 0}, dp_{i, 1})$.

Time complexity: $O(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, c;
	cin >> n >> c;
	vector<int> a(n - 1), b(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		cin >> b[i];
	}
	vector<vector<int>> dp(n, vector<int>(2, INF));
	dp[0][0] = 0, dp[0][1] = c;
	for (int i = 0; i < n - 1; ++i) {
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + a[i]);
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + a[i]);
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + b[i]);
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + b[i] + c);
	}
	
	for (int i = 0; i < n; ++i) {
		cout << min(dp[i][0], dp[i][1]) << " ";
	}
	cout << endl;
	
	return 0;
}
```
[1249F - Maximum Weight Subset](../problems/F._Maximum_Weight_Subset.md "Codeforces Round 595 (Div. 3)")

Thanks to [neal](https://codeforces.com/profile/neal "International Grandmaster neal") for the [additional editorial](https://codeforces.com/blog/entry/70822) of this problem and providing the linear solution!

 **Tutorial**
### [1249F - Maximum Weight Subset](../problems/F._Maximum_Weight_Subset.md "Codeforces Round 595 (Div. 3)")

Let's solve this problem using dynamic programming on a tree. Suppose the tree is rooted and the root of the tree is $1$. Also, let's increase $k$ to find the subset in which any pair of vertices had distance $k$ or greater instead of $k+1$ or greater.

Let $dp_{v, dep}$ be the maximum total weight of the subset in the subtree of $v$ if the vertex with the minimum depth we took has depth at least $dep$. Then the answer is $dp_{1, 0}$.

Firstly, let's calculate this dynamic programming for all children of $v$. Then we are ready to calculate all $dp_{v, dep}$ for all $dep$ from $0$ to $n$.

Let the current depth be $dep$, then there are two cases: if $dep = 0$ then $dp_{v, dep} = a_v + \sum\limits_{to \in children(v)} dp_{to, max(0, k - dep - 1)}$. Otherwise, let's iterate over all children of $v$ and let $to$ be such child of $v$ that the vertex with the minimum depth we took is in the subtree of $to$. Then $dp_{v, dep} = max(dp_{v, dep}, dp_{to, dep - 1} + \sum\limits_{other \in children(v) \backslash \{to\}} dp_{other, max(dep - 1, k - dep - 1)}$.

After we calculated all values of $dp_{v, dep}$ for the vertex $v$, we can notice that this is not what we wanted. The current value of $dp_{v, dep}$ means the maximum total weight of the subset in the subtree of $v$ if the vertex with the minimum depth we took has depth exactly $dep$. To fix this, let's push $dp_{v, dep}$ to $dp_{v, dep - 1}$ for all depths from $n$ to $1$.

Time complexity: $O(n^3)$ but it can be easily optimized to $O(n^2)$ using some prefix and suffix maximums.

You can ask, why this is $O(n^3)$ but not $O(n^4)$ because we iterating over all vertices, then over all possible depths, and then over children of the vertex, and again over children of the vertex. But in fact, this is $O(n^3)$ because if we change the order of multiplication, we can see that we are iterating over pairs (parent, child), then over children and possible depths, and the number of such pairs is $O(n)$, so the complexity is $O(n^3)$.

 **Solution (Vovuh, n^3)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 210;

int n, k;
vector<int> a;
vector<vector<int>> g, dp;

void dfs(int v, int p) {
	dp[v][0] = a[v];
	for (auto to : g[v]) {
		if (to != p) dfs(to, v);
	}
	for (int dep = 0; dep < N; ++dep) {
		if (dep == 0) {
			for (auto to : g[v]) {
				if (to == p) continue;
				dp[v][dep] += dp[to][max(0, k - dep - 1)];
			}
		} else {
			for (auto to : g[v]) {
				if (to == p) continue;
				int cur = dp[to][dep - 1];
				for (auto other : g[v]) {
					if (other == p || other == to) continue;
					cur += dp[other][max(dep - 1, k - dep - 1)];
				}
				dp[v][dep] = max(dp[v][dep], cur);
			}
		}
	}
	for (int dep = N - 1; dep > 0; --dep) {
		dp[v][dep - 1] = max(dp[v][dep - 1], dp[v][dep]);
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> k;
	++k;
	a = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	g = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dp = vector<vector<int>>(n, vector<int>(N));
	dfs(0, -1);
	cout << dp[0][0] << endl;
	
	return 0;
}
```
 **Solution (PikMike, n^2)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int N = 200 + 13;
const int INF = 1e9;

int n, k;
int a[N];
vector<int> g[N];
int dp[N][N];
int d[N];
int tmp[N];

void dfs(int v, int p = -1){
	d[v] = 1;
	dp[v][0] = a[v];
	for (auto u : g[v]) if (u != p){
		dfs(u, v);
		int nw = max(d[v], d[u] + 1);
		forn(i, nw)
			tmp[i] = -INF;
		forn(i, d[v]) for (int j = max(0, k - i); j < d[u]; ++j)
			tmp[min(i, j + 1)] = max(tmp[min(i, j + 1)], dp[v][i] + dp[u][j]);
		forn(i, d[u])
			tmp[i + 1] = max(tmp[i + 1], dp[u][i]);
		forn(i, d[v])
			dp[v][i] = max(dp[v][i], tmp[i]);
		for (int i = d[v]; i < nw; ++i)
			dp[v][i] = tmp[i];
		d[v] = nw;
		for (int i = d[v] - 1; i > 0; --i)
			dp[v][i - 1] = max(dp[v][i - 1], dp[v][i]);
	}
}

int main(){
	scanf("%d%d", &n, &k);
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0);
	printf("%dn", dp[0][0]);
}
```
