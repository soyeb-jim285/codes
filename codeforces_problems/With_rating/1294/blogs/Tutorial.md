# Tutorial

Thanks to [Rox](https://codeforces.com/profile/Rox "Candidate Master Rox") and [_overrated_](https://codeforces.com/profile/_overrated_ "Master _overrated_") for help with problem ideas and preparation!

[1294A - Collecting Coins](../problems/A._Collecting_Coins.md "Codeforces Round 615 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1294A - Collecting Coins](../problems/A._Collecting_Coins.md "Codeforces Round 615 (Div. 3)")

Suppose a≤b≤c. If it isn't true then let's rearrange our variables. Then we need at least 2c−b−a coins to make a, b and c equal. So if n<2c−b−a then the answer is "NO". Otherwise, the answer if "YES" if the number n−(2c−b−a) is divisible by 3. This is true because after making a,b and c equal we need to distribute all remaining candies between three sisters.

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
		int a[3], n;
		cin >> a[0] >> a[1] >> a[2] >> n;
		sort(a, a + 3);
		n -= 2 * a[2] - a[1] - a[0];
		if (n < 0 || n % 3 != 0) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
	
	return 0;
}
```
[1294B - Collecting Packages](../problems/B._Collecting_Packages.md "Codeforces Round 615 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1294B - Collecting Packages](../problems/B._Collecting_Packages.md "Codeforces Round 615 (Div. 3)")

It is obvious that if there is a pair of points $(x_i, y_i)$ and $(x_j, y_j)$ such that $x_i < x_j$ and $y_i > y_j$ then the answer is "NO". It means that if the answer is "YES" then there is some ordering of points such that $x_{i_1} \le x_{i_2} \le \dots \le x_{i_n}$ and $y_{i_1} \le y_{i_2} \le \dots \le y_{i_n}$ because we can only move right or up. But what is this ordering? it is just sorted order of points (firstly by $x_i$ then by $y_i$).

So we can sort all points, check if this ordering is valid and traverse among all these points. For each $k$ from $2$ to $n$ firstly do $x_{i_k} - x_{i_{k-1}}$ moves to the right then do $y_{i_k} - y_{i_{k-1}}$ moves to the up (because this order minimizing the answer lexicographically).

Time complexity: $O(n \log n)$ or $O(n^2)$.

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
    
    for (int tt = 0; tt < t; tt++) {
     	int n;
    	cin >> n;
    	vector<pair<int, int>> a(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i].first >> a[i].second;
    	}
    	sort(a.begin(), a.end());
    	pair<int, int> cur = make_pair(0, 0);
    	string ans;
    	bool ok = true;
    	for (int i = 0; i < n; ++i) {
    		int r = a[i].first - cur.first;
    		int u = a[i].second - cur.second;
    		if (r < 0 || u < 0) {
    			cout << "NO" << endl;
    			ok = false;
    			break;
    		}
    		ans += string(r, 'R');
    		ans += string(u, 'U');
    		cur = a[i];
    	}
    	
    	if (ok)
    	    cout << "YES" << endl << ans << endl;
   }

	return 0;
}
```
[1294C - Product of Three Numbers](../problems/C._Product_of_Three_Numbers.md "Codeforces Round 615 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1294C - Product of Three Numbers](../problems/C._Product_of_Three_Numbers.md "Codeforces Round 615 (Div. 3)")

Suppose $a < b < c$. Let's try to minimize $a$ and maximize $c$. Let $a$ be the minimum divisor of $n$ greater than $1$. Then let $b$ be the minimum divisor of $\frac{n}{a}$ that isn't equal $a$ and $1$. If $\frac{n}{ab}$ isn't equal $a$, $b$ and $1$ then the answer is "YES", otherwise the answer is "NO".

Time complexity: $O(\sqrt{n})$ per query.

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
		set<int> used;
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0 && !used.count(i)) {
				used.insert(i);
				n /= i;
				break;
			}
		}
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0 && !used.count(i)) {
				used.insert(i);
				n /= i;
				break;
			}
		}
		if (int(used.size()) < 2 || used.count(n) || n == 1) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			used.insert(n);
			for (auto it : used) cout << it << " ";
			cout << endl;
		}
	}
	
	return 0;
}
```
[1294D - MEX maximizing](../problems/D._MEX_maximizing.md "Codeforces Round 615 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1294D - MEX maximizing](../problems/D._MEX_maximizing.md "Codeforces Round 615 (Div. 3)")

Firstly, let's understand what the operation does. It changes the element but holds the remainder modulo $x$. So we can consider all elements modulo $x$.

Let $cnt_0$ be the number of elements with the value $0$ modulo $x$, $cnt_1$ be the number of elements with the value $1$ modulo $x$, and so on. Let's understand, where is the "bottleneck" of MEX. Obviously, we can always fill exactly $min(cnt_0, cnt_1, \dots, cnt_{x - 1})$ full blocks, so MEX is at least $min(cnt_0, cnt_1, \dots, cnt_{x - 1}) \cdot x$. MEX will be among all elements $y \in [0; x - 1]$ such that $cnt_y = min(cnt_0, cnt_1, \dots, cnt_{x - 1})$. Among all such elements MEX will be the minimum such $y$. Let it be $mn$. So the final value of MEX is $cnt_{mn} \cdot x + mn$.

How to deal with queries? Let's maintain the sorted set of pairs ($cnt_y, y$) for all $y \in [0; x - 1]$ and change it with respect to appended values. During each query let's change the set correspondingly and take the answer as the first element of this set using the formula above.

Time complexity: $O(n \log n)$. There is also an easy linear solution that uses the same idea but in a different way.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q, x;
	cin >> q >> x;
	vector<int> mods(x);
	
	set<pair<int, int>> vals;
	for (int i = 0; i < x; ++i) {
		vals.insert(make_pair(mods[i], i));
	}
	
	for (int i = 0; i < q; ++i) {
		int cur;
		cin >> cur;
		cur %= x;
		vals.erase(make_pair(mods[cur], cur));
		++mods[cur];
		vals.insert(make_pair(mods[cur], cur));
		cout << vals.begin()->first * x + vals.begin()->second << endl;
	}
	
	return 0;
}
```
[1294E - Obtain a Permutation](../problems/E._Obtain_a_Permutation.md "Codeforces Round 615 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1294E - Obtain a Permutation](../problems/E._Obtain_a_Permutation.md "Codeforces Round 615 (Div. 3)")

At first, let's decrease all elements by one and solve the problem in $0$-indexation.

The first observation is that we can solve the problem independently for each column.

Consider the column $j$ $(j \in [0; m-1])$. It consists of elements $[j; m + j, 2m + j, \dots, (n-1)m + j]$. Now consider some element $a_{i, j}$ $(i \in [0; n - 1])$. We don't need to replace it with some other number in only one case: if we shift the column such that $a_{i, j}$ will coincide with the corresponding number of the required matrix. Obviously, there is only one cyclic shift of the column that can rid us of replacing $a_{i, j}$. So, the idea is the following: let's calculate for each cyclic shift the number of elements we don't need to replace if we use this cyclic shift. Let for the $i$-th cyclic shift ($0$-indexed) it be $cnt_i$. Then the answer for this column can be taken as $\min\limits_{i=0}^{n-1} n - cnt_i + i$.

How to calculate for the element $a_{i, j}$ the corresponding cyclic shift? Firstly, if $a_{i, j} \% m \ne j$ ($\%$ is modulo operation) then there is no such cyclic shift. Otherwise, let $pos = \lfloor\frac{a_{i, j}}{m}\rfloor$. If $pos < n$ then there is such cyclic shift ($pos$ can be greater than or equal to $n$ because $a_{i, j}$ can be up to $2 \cdot 10^5$) and the number of such cyclic shift is $(i - pos + n) \% n$. So let's increase $cnt_{(i - pos + n) \% n}$ and continue. After considering all elements of this column take the answer by the formula above and go to the next column.

Time complexity: $O(nm)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			--a[i][j];	
		}
	}
	
	long long ans = 0;
	for (int j = 0; j < m; ++j) {
		vector<int> cnt(n);
		for (int i = 0; i < n; ++i) {
			if (a[i][j] % m == j) {
				int pos = a[i][j] / m;
				if (pos < n) {
					++cnt[(i - pos + n) % n];
				}
			}
		}
		int cur = n - cnt[0];
		for (int i = 1; i < n; ++i) {
			cur = min(cur, n - cnt[i] + i);
		}
		ans += cur;
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1294F - Three Paths on a Tree](../problems/F._Three_Paths_on_a_Tree.md "Codeforces Round 615 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1294F - Three Paths on a Tree](../problems/F._Three_Paths_on_a_Tree.md "Codeforces Round 615 (Div. 3)")

There is some obvious dynamic programming solution that someone can describe in the comments, but I will describe another one, that, in my opinion, much easier to implement.

Firstly, let's find some diameter of the tree. Let $a$ and $b$ be the endpoints of this diameter (and first two vertices of the answer). You can prove yourself why it is always good to take the diameter and why any diameter can be taken in the answer. Then there are two cases: the length of the diameter is $n-1$ or the length of the diameter is less than $n-1$. In the first case, you can take any other vertex as the third vertex of the answer $c$, it will not affect the answer anyway. Otherwise, we can run multi-source bfs from all vertices of the diameter and take the farthest vertex as the third vertex of the answer. It is always true because we can take any diameter and the farthest vertex will increase the answer as much as possible.

Time complexity: $O(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

vector<int> p;
vector<vector<int>> g;

pair<int, int> dfs(int v, int par = -1, int dist = 0) {
	p[v] = par;
	pair<int, int> res = make_pair(dist, v);
	for (auto to : g[v]) {
		if (to == par) continue;
		res = max(res, dfs(to, v, dist + 1));
	}
	return res;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	p = vector<int>(n);
	g = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);	
	}
	
	
	pair<int, int> da = dfs(0);
	pair<int, int> db = dfs(da.y);
	vector<int> diam;
	int v = db.y;
	while (v != da.y) {
		diam.push_back(v);
		v = p[v];
	}
	diam.push_back(da.y);
	
	if (int(diam.size()) == n) {
		cout << n - 1 << " " << endl << diam[0] + 1 << " " << diam[1] + 1 << " " << diam.back() + 1 << endl;
	} else {
		queue<int> q;
		vector<int> d(n, -1);
		for (auto v : diam) {
			d[v] = 0;
			q.push(v);
		}
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto to : g[v]) {
				if (d[to] == -1) {
					d[to] = d[v] + 1;
					q.push(to);
				}
			}
		}
		pair<int, int> mx = make_pair(d[0], 0);
		for (int v = 1; v < n; ++v) {
			mx = max(mx, make_pair(d[v], v));
		}
		cout << int(diam.size()) - 1 + mx.x << endl << diam[0] + 1 << " " << mx.y + 1 << " " << diam.back() + 1 << endl;
	}
	
	return 0;
}
```
