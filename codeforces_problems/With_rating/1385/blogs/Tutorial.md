# Tutorial

All ideas belong to [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov").

[1385A - Three Pairwise Maximums](../problems/A._Three_Pairwise_Maximums.md "Codeforces Round 656 (Div. 3)")

 **Tutorial**
### [1385A - Three Pairwise Maximums](../problems/A._Three_Pairwise_Maximums.md "Codeforces Round 656 (Div. 3)")

Suppose $x \le y \le z$. If $y \ne z$ then the answer is -1, because $z$ is the overall maximum among all three integers $a$, $b$ and $c$ and it appears in two pairs (so it should appear at most twice among $x$, $y$ and $z$). Otherwise, the answer exists and it can be $x$, $x$ and $z$ (it is easy to see that this triple fits well).

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
		vector<int> a(3);
		for (auto &it : a) cin >> it;
		sort(a.begin(), a.end());
		if (a[1] != a[2]) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl << a[0] << " " << a[0] << " " << a[2] << endl;
		}
	}
	
	return 0;
}
```
[1385B - Restore the Permutation by Merger](../problems/B._Restore_the_Permutation_by_Merger.md "Codeforces Round 656 (Div. 3)")

 **Tutorial**
### [1385B - Restore the Permutation by Merger](../problems/B._Restore_the_Permutation_by_Merger.md "Codeforces Round 656 (Div. 3)")

The solution is pretty simple: it's obvious that the first element of $a$ is the first element of the permutation $p$. Let's take it to $p$, remove it and its its copy from $a$. So we just have the smaller problem and can solve it in the same way. It can be implemented as "go from left to right, if the current element isn't used, take it and mark it's used".

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
		cin >> n;
		vector<int> a(2 * n);
		for (auto &it : a) cin >> it;
		vector<int> used(n);
		vector<int> p;
		for (int i = 0; i < 2 * n; ++i) {
			if (!used[a[i] - 1]) {
				used[a[i] - 1] = true;
				p.push_back(a[i]);
			}
		}
		for (auto it : p) cout << it << " ";
		cout << endl;
	}
	
	return 0;
}
```
[1385C - Make It Good](../problems/C._Make_It_Good.md "Codeforces Round 656 (Div. 3)")

 **Tutorial**
### [1385C - Make It Good](../problems/C._Make_It_Good.md "Codeforces Round 656 (Div. 3)")

Consider the maximum element $a_{mx}$ of the good array $a$ of length $k$. Then we can notice that the array $a$ looks like $[a_1 \le a_2 \le \dots \le a_{mx} \ge \dots \ge a_{k-1} \ge a_k]$. And this is pretty obvious that if the array doesn't have this structure, then it isn't good (you can see it yourself). So we need to find the longest such suffix. It's pretty easy doable with pointer: initially, the pointer $pos$ is at the last element. Then, while $pos > 1$ and $a_{pos - 1} \ge a_{pos}$, decrease $pos$ by one. If we're done with the previous step, we do the same, but while $pos > 1$ and $a_{pos - 1} \le a_{pos}$. The answer is $pos-1$.

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
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		int pos = n - 1;
		while (pos > 0 && a[pos - 1] >= a[pos]) --pos;
		while (pos > 0 && a[pos - 1] <= a[pos]) --pos;
		cout << pos << endl;
	}
	
	return 0;
}
```
[1385D - a-Good String](../problems/D._a-Good_String.md "Codeforces Round 656 (Div. 3)")

 **Tutorial**
### [1385D - a-Good String](../problems/D._a-Good_String.md "Codeforces Round 656 (Div. 3)")

Consider the problem in $0$-indexation. Define the function $calc(l, r, c)$ which finds the minimum number of changes to make the string $s[l \dots r)$ $c$-good string. Let $mid = \frac{l + r}{2}$. Then let $cnt_l = \frac{r - l}{2} - count(s[l \dots mid), c) + calc(mid, r, c + 1)$ and $cnt_r = \frac{r - l}{2} - count(s[mid \dots r), c) + calc(l, mid, c + 1)$, where $count(s, c)$ is the number of occurrences of the character $c$ in $s$. We can see that $cnt_l$ describes the second condition from the statement and $cnt_r$ describes the third one. So, $calc(l, r, c)$ returns $min(cnt_l, cnt_r)$ except one case. When $r - l = 1$, we need to return $1$ if $s_l \ne c$ and $0$ otherwise. This function works in $O(n \log n)$ (each element of $s$ belongs to exactly $\log{n}$ segments, like segment tree). You can get the answer if you run $calc(0, n,~ 'a')$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int calc(const string &s, char c) {
	if (s.size() == 1) {
		return s[0] != c;
	}
	int mid = s.size() / 2;
	int cntl = calc(string(s.begin(), s.begin() + mid), c + 1);
	cntl += s.size() / 2 - count(s.begin() + mid, s.end(), c);
	int cntr = calc(string(s.begin() + mid, s.end()), c + 1);
	cntr += s.size() / 2 - count(s.begin(), s.begin() + mid, c);
	return min(cntl, cntr);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		cout << calc(s, 'a') << endl;
	}
	
	return 0;
}
```
[1385E - Directing Edges](../problems/E._Directing_Edges.md "Codeforces Round 656 (Div. 3)")

 **Tutorial**
### [1385E - Directing Edges](../problems/E._Directing_Edges.md "Codeforces Round 656 (Div. 3)")

Firstly, if the graph consisting of initial vertices and only directed edges contains at least one cycle then the answer is "NO". Otherwise, the answer is always "YES". Let's build it. Let's build the topological sort of the graph without undirected edges. Then let's check for each directed edge if it's going from left to right (in order of topological sort). If it isn't true then there is a cycle and the answer is "NO". Otherwise, let's direct each edge from left to right in order of the topological sort.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> ord;
vector<int> used;
vector<vector<int>> g;

void dfs(int v) {
	used[v] = 1;
	for (auto to : g[v]) {
		if (!used[to]) dfs(to);
	}
	ord.push_back(v);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		g = vector<vector<int>>(n);
		vector<pair<int, int>> edges;
		for (int i = 0; i < m; ++i) {
			int t, x, y;
			cin >> t >> x >> y;
			--x, --y;
			if (t == 1) {
				g[x].push_back(y);
			}
			edges.push_back({x, y});
		}
		
		ord.clear();
		used = vector<int>(n);
		for (int i = 0; i < n; ++i) {
			if (!used[i]) dfs(i);
		}
		vector<int> pos(n);
		reverse(ord.begin(), ord.end());
		for (int i = 0; i < n; ++i) {
			pos[ord[i]] = i;
		}
		bool bad = false;
		for (int i = 0; i < n; ++i) {
			for (auto j : g[i]) {
				if (pos[i] > pos[j]) bad = true;
			}
		}
		if (bad) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			for (auto [x, y] : edges) {
				if (pos[x] < pos[y]) {
					cout << x + 1 << " " << y + 1 << endl;
				} else {
					cout << y + 1 << " " << x + 1 << endl;
				}
			}
		}
	}
	
	return 0;
}
```
[1385F - Removing Leaves](../problems/F._Removing_Leaves.md "Codeforces Round 656 (Div. 3)")

 **Tutorial**
### [1385F - Removing Leaves](../problems/F._Removing_Leaves.md "Codeforces Round 656 (Div. 3)")

This is mostly implementation problem. We can notice that all leaves are indistinguishable for us. So if we have some vertex with at least $k$ leaves attached to it, we can choose it, remove these leaves from the tree and continue the algorithm. The rest is just an implementation: let's maintain for each vertex $v$ the list of all leaves which are connected to it $leaves_v$ and the set of vertices which is sorted by the size of $leaves_v$. So let's take any vertex which Is connected with at least $k$ leaves (we can just take the vertex with the maximum value in the set) and remove any $k$ leaves attached to it. If it has zero leaves after the current move, let's mark is as a leaf and append it to the list of the corresponding vertex (you also need to remove edges from the graph fast to find the required vertex, so you may need to maintain the graph as the list of sets). And don't forget about the case $k=1$ because it may be special for your solution so you could handle it in a special way.

Time complexity: $O(n \log{n})$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n, k, ans;
vector<set<int>> g;
vector<set<int>> leaves;

struct comp {
	bool operator() (int a, int b) const {
		if (leaves[a].size() == leaves[b].size()) return a < b;
		return leaves[a].size() > leaves[b].size();
	}
};

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		g = leaves = vector<set<int>>(n);
		for (int i = 0; i < n - 1; ++i) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			g[x].insert(y);
			g[y].insert(x);
		}
		for (int i = 0; i < n; ++i) {
			if (g[i].size() == 1) {
				leaves[*g[i].begin()].insert(i);
			}
		}
		set<int, comp> st;
		for (int i = 0; i < n; ++i) {
			st.insert(i);
		}
		int ans = 0;
		while (true) {
			int v = *st.begin();
			if (int(leaves[v].size()) < k) break;
			for (int i = 0; i < k; ++i) {
				int leaf = *leaves[v].begin();
				g[leaf].erase(v);
				g[v].erase(leaf);
				st.erase(v);
				st.erase(leaf);
				leaves[v].erase(leaf);
				if (leaves[leaf].count(v)) leaves[leaf].erase(v);
				if (g[v].size() == 1) {
					int to = *g[v].begin();
					st.erase(to);
					leaves[to].insert(v);
					st.insert(to);
				}
				st.insert(v);
				st.insert(leaf);
				
			}
			ans += 1;
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1385G - Columns Swaps](../problems/G._Columns_Swaps.md "Codeforces Round 656 (Div. 3)")

 **Tutorial**
### [1385G - Columns Swaps](../problems/G._Columns_Swaps.md "Codeforces Round 656 (Div. 3)")

Firstly, we can determine that the answer is -1 if some number has not two occurrences. Otherwise, the answer exists (and we actually don't need to prove it because we can check it later). Let's find for each number $i$ from $1$ to $n$ indices of columns in which it appears $c_1[i]$ and $c_2[i]$. Consider some number $i$. If $c_1[i] = c_2[i]$ then let's just skip it, we can't change anything by swapping values in this column. Otherwise, let $r_1[i]$ be the number of row of the number $i$ in the column $c_1[i]$ and $r_2[i]$ is the number of row of the number $i$ in the column $c_2[i]$. If $r_1[i] = r_2[i]$ then it's obvious that at exactly one of these two columns should be swapped. The same, if $r_1[i] \ne r_2[i]$ then it's obvious that we either swap both of them or don't swap both of them. Let's build a graph consisting of $n$ vertices, when the vertex $v$ determines the state of the $v$-th column. If $r_1[i] = r_2[i]$ then let's add edge of color $1$ between vertices $c_1[i]$ and $c_2[i]$. Otherwise, let's add the edge of color $0$ between these vertices.

So, we have the graph consisting of several connected components and some strange edges. Let's color it. If the edge $(v, to)$ has the color $1$ then the color of the vertex $to$ should be different from the color of the vertex $v$. The same, if the edge $(v, to)$ has the color $0$ then the color of the vertex $to$ should be the same as the color of the vertex $v$. This makes sense, because edges with color $1$ mean that exactly one of the columns connected by this edge should be swapped (and vice versa).

So, after we colored the graph, we can ensure that conditions for each edge are satisfied. If it isn't so, the answer is -1 (but this case can't actually appear). Otherwise, we need to decide for each component independently, what is the color $0$ and the color $1$ means for it. The color $0$ can mean that the column having this color isn't swapped (and the color $1$ means that the column having this color is swapped in this case) and vice versa. We can choose greedily the minimum number of swaps for each component and print the answer.

Time complexity: $O(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int cnt0, cnt1;
vector<int> col, comp;
vector<vector<pair<int, int>>> g;

void dfs(int v, int c, int cmp) {
	col[v] = c;
	if (col[v] == 0) ++cnt0;
	else ++cnt1;
	comp[v] = cmp;
	for (auto [to, change] : g[v]) {
		if (col[to] == -1) {
			dfs(to, c ^ change, cmp);
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> a(2, vector<int>(n));
		vector<vector<int>> pos(n);
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
				--a[i][j];
				pos[a[i][j]].push_back(j);
			}
		}
		bool bad = false;
		g = vector<vector<pair<int, int>>>(n);
		for (int i = 0; i < n; ++i) {
			if (pos[i].size() != 2) {
				bad = true;
				break;
			}
			int c1 = pos[i][0], c2 = pos[i][1];
			if (c1 == c2) continue;
			int r1 = a[0][c1] != i, r2 = a[0][c2] != i;
			g[c1].push_back({c2, r1 == r2});
			g[c2].push_back({c1, r1 == r2});
		}
		col = comp = vector<int>(n, -1);
		int cnt = 0;
		vector<pair<int, int>> colcnt;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (col[i] == -1) {
				cnt0 = cnt1 = 0;
				dfs(i, 0, cnt);
				++cnt;
				colcnt.push_back({cnt0, cnt1});
				ans += min(cnt0, cnt1);
			}
		}
		for (int i = 0; i < n; ++i) {
			for (auto [j, diff] : g[i]) {
				if ((col[i] ^ col[j]) != diff) {
					bad = true;
				}
			}
		}
		if (bad) {
			cout << -1 << endl;
		} else {
			cout << ans << endl;
			for (int i = 0; i < n; ++i) {
				int changeZero = colcnt[comp[i]].first < colcnt[comp[i]].second;
				if (col[i] ^ changeZero) {
					cout << i + 1 << " ";
				}
			}
			cout << endl;
		}
	}
	
	return 0;
}
```
