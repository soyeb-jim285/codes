# Tutorial_(en)

[1328A - Divisibility Problem](../problems/A._Divisibility_Problem.md "Codeforces Round 629 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1328A - Divisibility Problem](../problems/A._Divisibility_Problem.md "Codeforces Round 629 (Div. 3)")

If $a \% b = 0$ ($a$ is divisible by $b$), just print $0$. Otherwise, we need exactly $b - a \% b$ moves to make zero remainder of $a$ modulo $b$. $\%$ is modulo operation.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a % b == 0) cout << 0 << endl;
		else cout << b - a % b << endl;
	}
	
	return 0;
}
```
[1328B - K-th Beautiful String](../problems/B._K-th_Beautiful_String.md "Codeforces Round 629 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1328B - K-th Beautiful String](../problems/B._K-th_Beautiful_String.md "Codeforces Round 629 (Div. 3)")

Let's try to find the position of the leftmost occurrence of 'b' (iterate over all positions from $n-2$ to $0$). If $k \le n - i - 1$ then this is the required position of the leftmost occurrence of 'b'. Then the position of rightmost occurrence is $n - k$ so we can print the answer. Otherwise, let's decrease $k$ by $n-i-1$ (remove all strings which have the leftmost 'b' at the current position) and proceed to the next position. It is obvious that in such a way we consider all possible strings in lexicographic order.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n, k;
        cin >> n >> k;
        string s(n, 'a');
        for (int i = n - 2; i >= 0; i--) {
            if (k <= (n - i - 1)) {
                s[i] = 'b';
                s[n - k] = 'b';
                cout << s << endl;
                break;
            }
            k -= (n - i - 1);
        }
    }
}

```
[1328C - Ternary XOR](../problems/C._Ternary_XOR.md "Codeforces Round 629 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1328C - Ternary XOR](../problems/C._Ternary_XOR.md "Codeforces Round 629 (Div. 3)")

Let's iterate from left to right over the digits of $x$. If the current digit is either $0$ or $2$ then we can set $a_i = b_i = 0$ or $a_i = b_i = 1$ correspondingly. There are no better choices. And if the current digit $x_i$ is $1$ then the optimal choise is to set $a_i = 1$ and $b_i = 0$. What happens after the first occurrence of $1$? Because of this choice $a$ is greater than $b$ even if all remaining digits in $b$ are $2$. So for each $j > i$ set $a_j = 0$ and $b_j = x_j$ and print the answer. The case without $1$ is even easier and in fact we handle it automatically.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		string x;
		cin >> n >> x;
		string a(n, '0'), b(n, '0');
		for (int i = 0; i < n; ++i) {
			if (x[i] == '1') {
				a[i] = '1';
				b[i] = '0';
				for (int j = i + 1; j < n; ++j) {
					b[j] = x[j];
				}
				break;
			} else {
				a[i] = b[i] = '0' + (x[i] - '0') / 2;
			}
		}
		cout << a << endl << b << endl;
	}
	
	return 0;
}
```
[1328D - Carousel](../problems/D._Carousel.md "Codeforces Round 629 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1328D - Carousel](../problems/D._Carousel.md "Codeforces Round 629 (Div. 3)")

The answer to this problem is at most $3$. Let's prove it by construction.

Firstly, if all $t_i$ are equal then the answer is $1$. Otherwise, there are at least two different values in the array $t$ so the answer is at least $2$. If $n$ is even then the answer is always $2$ because you can color figures in the following way: $[1, 2, 1, 2, \dots, 1, 2]$. If $n$ is odd then consider two cases. The first case is when some pair of adjacent figures have the same type. Then the answer is $2$ because you can merge these two values into one and get the case of even $n$. Otherwise, all pairs of adjacent figures have different types and if you consider this cyclic array as a graph (cycle of length $n$) then you can notice that it isn't bipartite so you need at least $3$ colors to achieve the answer (color all vertices in such a way that any two adjacent vertices have different colors). And the answer looks like $[1, 2, 1, 2, \dots, 1, 2, 3]$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	if (count(a.begin(), a.end(), a[0]) == n) {
		cout << 1 << endl;
		for (int i = 0; i < n; ++i) {
			cout << 1 << " ";
		}
		cout << endl;
		return 0;
	}
	
	if (n % 2 == 0) {
		cout << 2 << endl;
		for (int i = 0; i < n; ++i) {
			cout << i % 2 + 1 << " ";
		}
		cout << endl;
		return 0;
	}
	
	for (int i = 0; i < n; ++i) {
		if (a[i] == a[(i + 1) % n]) {
			vector<int> ans(n);
			for (int j = 0, pos = i + 1; pos < n; ++pos, j ^= 1) {
				ans[pos] = j + 1;
			}
			for (int j = 0, pos = i; pos >= 0; --pos, j ^= 1) {
				ans[pos] = j + 1;
			}
			cout << 2 << endl;
			for (int pos = 0; pos < n; ++pos) {
				cout << ans[pos] << " ";
			}
			cout << endl;
			return 0;
		}
	}
	
	cout << 3 << endl;
	for (int i = 0; i < n - 1; ++i) {
		cout << i % 2 + 1 << " ";
	}
	cout << 3 << endl;
    return 0;    
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

int q;
cin >> q;
for (int qq = 0; qq < q; qq++) {
    solve();
}

	return 0;
}
```
[1328E - Tree Queries](../problems/E._Tree_Queries.md "Codeforces Round 629 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") and [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1328E - Tree Queries](../problems/E._Tree_Queries.md "Codeforces Round 629 (Div. 3)")

Firstly, let's choose some deepest (farthest from the root) vertex $fv$ in the query (among all such vertices we can choose any). It is obvious that every vertex in the query should either belong to the path from the root to $fv$ or the distance to some vertex of this path should be at most one. Now there are two ways: write some LCA algorithms and other hard stuff which is unnecessary in this problem or write about $15$ lines of code and solve the problem.

Let's take every non-root vertex (except $fv$) and replace it with its parent. So, what's next? Now the answer is "YES" if each vertex (after transformation) belongs to the path from root to $fv$. Now we just need to check if it is true.

We can do this using the very standard technique: firstly, let's run dfs from the root and calculate for each vertex the first time we visited it ($tin$) and the last time we visited it ($tout$).

We can do this using the following code: 


```cpp
  
void dfs(int v, int par = -1) {  
    tin[v] = T++;  
    for (auto to : g[v]) {  
        if (to == par) continue;  
        dfs(to, v);  
    }  
    tout[v] = T++;  
}  

```
Initially, $T$ equals zero. Now we have a beautiful structure giving us so much information about the tree. Consider all segments $[tin_v; tout_v]$. We can see that there is no pair of intersecting segments. The pair of segments $[tin_v; tout_v]$ and $[tin_u; tout_u]$ is either non-intersecting at all or one segment lies inside the other one. The second beautiful fact is that for each vertex $u$ in the subtree of $v$ the segment $[tin_u; tout_u]$ lies inside the segment $[tin_v; tout_v]$.

So, we can check if one vertex is the parent of the other: the vertex $v$ is the parent of the vertex $u$ if and only if $tin_v \le tin_u$ and $tout_u \le tout_v$ (the vertex is the parent of itself).

How do we check if the vertex $u$ lies on the path from the root to the vertex $fv$? It lies on this path if the root is the parent of $u$ (it is always true) and $u$ is the parent of $fv$. This approach can be used for each vertical path (such a path from $x$ to $y$ that $lca(x, y)$ is either $x$ or $y$).

Time complexity: $O(n + m)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int T;
vector<int> p, d;
vector<int> tin, tout;
vector<vector<int>> g;

void dfs(int v, int par = -1, int dep = 0) {
	p[v] = par;
	d[v] = dep;
	tin[v] = T++;
	for (auto to : g[v]) {
		if (to == par) continue;
		dfs(to, v, dep + 1);
	}
	tout[v] = T++;
}

bool isAnc(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	T = 0;
	p = d = vector<int>(n);
	tin = tout = vector<int>(n);
	g = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0);
	
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		vector<int> v(k);
		for (auto &it : v) {
			cin >> it;
			--it;
		}
		
		int u = v[0];
		for (auto it : v) if (d[u] < d[it]) u = it;
		for (auto &it : v) {
			if (it == u) continue;
			if (p[it] != -1) it = p[it];
		}
		bool ok = true;
		for (auto it : v) ok &= isAnc(it, u);
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}
```
[1328F - Make k Equal](../problems/F._Make_k_Equal.md "Codeforces Round 629 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1328F - Make k Equal](../problems/F._Make_k_Equal.md "Codeforces Round 629 (Div. 3)")

This problem is just all about the implementation. Firstly, let's sort the initial values and compress them to pairs $(i, cnt[val])$, where $cnt[val]$ is the number of elements $val$. The first observation is pretty standard and easy: some equal elements will remain unchanged. So let's iterate over all elements $val$ in some order and suppose that all elements $val$ will remain unchanged. Firstly, we need $need = max(0, k - cnt[val])$ elements which we should obtain by some moves. The second observation is that we first need to take elements from one end (only less or only greater) and only then from the other (if needed).

Consider the case when we first take less elements. The other case is almost symmetric.

Let $needl = min(need, prefcnt_{prv})$ be the number of less than $val$ which we need to increase to $val$. If $needl = 0$ then skip the following step. Otherwise, let $prefcnt_i$ be the number of elements less than or equal to $i$, $prefsum_i$ be the sum of all elements less than or equal to $i$ and $prv$ be the previous value (the maximum value less than $val$). Then we need to increase all elements less than or equal to $prv$ at least to the value $val-1$. It costs $(val - 1) \cdot prefcnt_{prv} - prefsum_{prv}$ moves. And then we need $needl$ moves to increase $needl$ elements to $val$.

And let $needr = max(0, need - needl)$ be the number of elements greater than $val$ which we need to decrease to $val$ if we increased $needl$ elements already. If $needr = 0$ then skip the following step. Otherwise, let $sufcnt_i$ be the number of elements greater than or equal to $i$, $prefsum_i$ be the sum of all elements greater than or equal to $i$ and $nxt$ be the next value (the minimum value greater than $val$). Then we need to decrease all elements greater than or equal to $prv$ at least to the value $val+1$. It costs $sufsum_{nxt} - (val + 1) \cdot sufcnt_{nxt}$ moves. And then we need $needr$ moves to decrease $needr$ elements to $val$.

So we can update the answer with the sum of values described above and proceed to the next value. Arrays $prefcnt, sufcnt, prefsum, sufsum$ are just simple prefix and suffix sums which can be calculated in $O(n)$ using very standard and easy dynamic programming. Don't forget about the overflow.

Total time complexity: $O(n \log n)$ because of sorting.

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
	
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &it : a) cin >> it;
	
	sort(a.begin(), a.end());
	vector<pair<int, int>> cnt;
	for (auto it : a) {
		if (cnt.empty() || cnt.back().first != it) {
			cnt.push_back({it, 1});
		} else {
			++cnt.back().second;
		}
	}
	vector<long long> prefsum, sufsum;
	vector<int> prefcnt, sufcnt; 
	for (int i = 0; i < int(cnt.size()); ++i) {
		long long cursum = cnt[i].first * 1ll * cnt[i].second;
		int curcnt = cnt[i].second;
		if (prefsum.empty()) {
			prefsum.push_back(cursum);
			prefcnt.push_back(curcnt);
		} else {
			prefsum.push_back(prefsum.back() + cursum);
			prefcnt.push_back(prefcnt.back() + curcnt);
		}
	}
	for (int i = int(cnt.size()) - 1; i >= 0; --i) {
		long long cursum = cnt[i].first * 1ll * cnt[i].second;
		int curcnt = cnt[i].second;
		if (sufsum.empty()) {
			sufsum.push_back(cursum);
			sufcnt.push_back(curcnt);
		} else {
			sufsum.push_back(sufsum.back() + cursum);
			sufcnt.push_back(sufcnt.back() + curcnt);
		}
	}
	reverse(sufsum.begin(), sufsum.end());
	reverse(sufcnt.begin(), sufcnt.end());
	
	long long ans = INF64;
	for (int i = 0; i < int(cnt.size()); ++i) {
		int cur = max(0, k - cnt[i].second);
		
		int needl = 0;
		if (i > 0) needl = min(cur, prefcnt[i - 1]);
		int needr = max(0, cur - needl);
		long long res = 0;
		if (i > 0 && needl > 0) {
			res += prefcnt[i - 1] * 1ll * (cnt[i].first - 1) - prefsum[i - 1];
			res += needl;
		}
		if (i + 1 < int(cnt.size()) && needr > 0) {
			res += sufsum[i + 1] - sufcnt[i + 1] * 1ll * (cnt[i].first + 1);
			res += needr;
		}
		ans = min(ans, res);
		
		needr = 0;
		if (i + 1 < int(cnt.size())) needr = min(cur, sufcnt[i + 1]);
		needl = max(0, cur - needr);
		res = 0;
		if (i > 0 && needl > 0) {
			res += prefcnt[i - 1] * 1ll * (cnt[i].first - 1) - prefsum[i - 1];
			res += needl;
		}
		if (i + 1 < int(cnt.size()) && needr > 0) {
			res += sufsum[i + 1] - sufcnt[i + 1] * 1ll * (cnt[i].first + 1);
			res += needr;
		}
		ans = min(ans, res);
	}
	
	cout << ans << endl;
	
	return 0;
}
```
