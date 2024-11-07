# Tutorial

Suddendly, all ideas of this contest are mine. And I'm very sorry about one missing small test in the problem B. This is the biggest mistake I made during the preparation of this round.

[1324A - Yet Another Tetris Problem](../problems/A._Yet_Another_Tetris_Problem.md "Codeforces Round 627 (Div. 3)")

 **Tutorial**
### [1324A - Yet Another Tetris Problem](../problems/A._Yet_Another_Tetris_Problem.md "Codeforces Round 627 (Div. 3)")

The answer is "YES" only if all $a_i$ have the same parity (i.e. all $a_i$ are odd or all $a_i$ are even). That's because placing the block doesn't change the parity of the element and the $-1$ operation changes the parity of all elements in the array. 

 **Solution**
```cpp
for i in range(int(input())):
	n = int(input())
	cnto = sum(list(map(lambda x: int(x) % 2, input().split())))
	print('YES' if cnto == 0 or cnto == n else 'NO')
```
[1324B - Yet Another Palindrome Problem](../problems/B._Yet_Another_Palindrome_Problem.md "Codeforces Round 627 (Div. 3)")

 **Tutorial**
### [1324B - Yet Another Palindrome Problem](../problems/B._Yet_Another_Palindrome_Problem.md "Codeforces Round 627 (Div. 3)")

The first observation is that we can always try to find the palindrome of length $3$ (otherwise, we can remove some characters from the middle until its length becomes $3$).

The second observation is that the palindrome of length $3$ is two equal characters and some other (maybe, the same) character between them. Now there are two ways: find the pair of equal non-adjacent characters in $O(n^2)$ or do it in $O(n)$ (for each character we only need to consider its left and right occurrences).

 **Solution**
```cpp
for i in range(int(input())):
	n = int(input())
	s = list(map(int, input().split()))
	ok = False
	for i in range(n):
		for j in range(i + 2, n):
			if s[i] == s[j]: ok = True
	print('YES' if ok else 'NO')
```
[1324C - Frog Jumps](../problems/C._Frog_Jumps.md "Codeforces Round 627 (Div. 3)")

 **Tutorial**
### [1324C - Frog Jumps](../problems/C._Frog_Jumps.md "Codeforces Round 627 (Div. 3)")

The only observation we need is that we don't need to jump left at all. This only decreases our position so we have less freedom after the jump to the left. Then, to minimize $d$, we only need to jump between the closest 'R' cells. So, if we build the array $b = [0, r_1, r_2, \dots, r_k, n + 1]$, where $r_i$ is the position of the $i$-th 'R' cell from left to right ($1$-indexed), then the answer is $\max\limits_{i=0}^{k} b_{i + 1} - b_i$.

Time complexity: $O(n)$.

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
		string s;
		cin >> s;
		vector<int> pos;
		pos.push_back(0);
		for (int i = 0; i < int(s.size()); ++i) {
			if (s[i] == 'R') pos.push_back(i + 1);
		}
		pos.push_back(s.size() + 1);
		int ans = 0;
		for (int i = 0; i < int(pos.size()) - 1; ++i) {
			ans = max(ans, pos[i + 1] - pos[i]);
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1324D - Pair of Topics](../problems/D._Pair_of_Topics.md "Codeforces Round 627 (Div. 3)")

 **Tutorial**
### [1324D - Pair of Topics](../problems/D._Pair_of_Topics.md "Codeforces Round 627 (Div. 3)")

Let's rewrite the inequality from $a_i + a_j > b_i + b_j$ to $(a_i - b_i) + (a_j - b_j) > 0$. This looks much simpler. Let's build the array $c$ where $c_i = a_i - b_i$ and sort this array. Now our problem is to find the number of pairs $i < j$ such that $c_i + c_j > 0$.

Let's iterate over all elements of $c$ from left to right. For simplicity, we consider only "greater" summands. Because our sum ($c_i + c_j$) must be greater than $0$, then at least one of these summands will be positive. So, if $c_i \le 0$, just skip it. Now $c_i > 0$ and we need to calculate the number of such $j$ that $c_i + c_j > 0$ and $j < i$. It means that each $c_j \ge -c_i + 1$ (for some $j < i$) will be okay. Such leftmost position $j$ can be found with std::lower_bound or binary search. Then add the value $i-j$ to the answer and consider the next element.

Time complexity: $O(n \log n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto &it : a) cin >> it;
	for (auto &it : b) cin >> it;
	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		c[i] = a[i] - b[i];
	}
	sort(c.begin(), c.end());
	
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (c[i] <= 0) continue;
		int pos = lower_bound(c.begin(), c.end(), -c[i] + 1) - c.begin();
		ans += i - pos;
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1324E - Sleeping Schedule](../problems/E._Sleeping_Schedule.md "Codeforces Round 627 (Div. 3)")

 **Tutorial**
### [1324E - Sleeping Schedule](../problems/E._Sleeping_Schedule.md "Codeforces Round 627 (Div. 3)")

This is a very standard dynamic programming problem. Let $dp_{i, j}$ be the maximum number of good sleeping times if Vova had a sleep $i$ times already and the number of times he goes to sleep earlier by one hour is exactly $j$. Then the value $\max\limits_{j=0}^{n} dp_{n, j}$ will be the answer. Initially, all $dp_{i, j} = -\infty$ and $dp_{0, 0} = 0$.

What about transitions? Let the current state of the dynamic programming be $dp_{i, j}$ and $s = \sum\limits_{k=0}^{i} a_k$. Then we can don't go to sleep earlier and make the first transition: $dp_{i + 1, j} = max(dp_{i + 1, j}, dp_{i, j} + |(s - j) \% h \in [l; r]|)$. The sign $\%$ is modulo operation and the notation $|f|$ is the boolean result of the expression $f$ ($1$ if $f$ is true and $0$ otherwise). And the second transition if we go to sleep earlier: $dp_{i + 1, j + 1} = max(dp_{i + 1, j + 1}, dp_{i, j} + |(s - j - 1) \% h \in [l; r]|)$.

Don't forget to don't make transitions from unreachable states.

Time complexity: $O(n^2)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

bool in(int x, int l, int r) {
	return l <= x && x <= r;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, h, l, r;
	cin >> n >> h >> l >> r;
	vector<int> a(n);
	for (auto &it : a) cin >> it;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));
	dp[0][0] = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		for (int j = 0; j <= n; ++j) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + in((sum - j) % h, l, r));
			if (j < n) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + in((sum - j - 1) % h, l, r));
		}
	}
	
	cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
	
	return 0;
}
```
[1324F - Maximum White Subtree](../problems/F._Maximum_White_Subtree.md "Codeforces Round 627 (Div. 3)")

 **Tutorial**
### [1324F - Maximum White Subtree](../problems/F._Maximum_White_Subtree.md "Codeforces Round 627 (Div. 3)")

This problem is about the "rerooting" technique. Firstly, let's calculate the answer for some fixed root. How can we do this? Let $dp_v$ be the maximum possible difference between the number of white and black vertices in some subtree of $v$ (yes, the subtree of the rooted tree, i.e. $v$ and all its direct and indirect children) that contains the vertex $v$. We can calculate this dynamic programming by simple dfs, for the vertex $v$ it will look like this: $dp_v = a_v + \sum\limits_{to \in children(v)} max(0, dp_{to})$.

Okay, we can store the answer for the root somewhere. What's next? Let's try to change the root from the vertex $v$ to some adjacent to it vertex $to$. Which states of dynamic programming will change? Only $dp_v$ and $dp_{to}$. Firstly, we need to "remove" the child $to$ from the subtree of the vertex $v$: $dp_v = dp_v - max(0, dp_{to})$. Then we need to "attach" the vertex $v$ and make it a child of the vertex $to$: $dp_{to} = dp_{to} + max(0, dp_v)$. Then we need to run this process recursively from $to$ (store the answer, reroot the tree and so on) and when it ends we need to "rollback" our changes. Now $v$ is the root again and we can try the next child of $v$ as the root.

Time complexity: $O(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> dp;
vector<int> ans;
vector<vector<int>> g;

void dfs(int v, int p = -1) {
	dp[v] = a[v];
	for (auto to : g[v]) {
		if (to == p) continue;
		dfs(to, v);
		dp[v] += max(dp[to], 0);
	}
}

void dfs2(int v, int p = -1) {
	ans[v] = dp[v];
	for (auto to : g[v]) {
		if (to == p) continue;
		dp[v] -= max(0, dp[to]);
		dp[to] += max(0, dp[v]);
		dfs2(to, v);
		dp[to] -= max(0, dp[v]);
		dp[v] += max(0, dp[to]);
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	a = dp = ans = vector<int>(n);
	g = vector<vector<int>>(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == 0) a[i] = -1;
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dfs(0);
	dfs2(0);
	for (auto it : ans) cout << it << " ";
	cout << endl;
	
	return 0;
}
```
