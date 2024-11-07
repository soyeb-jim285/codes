# Tutorial

[1296A - Array with Odd Sum](../problems/A._Array_with_Odd_Sum.md "Codeforces Round 617 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1296A - Array with Odd Sum](../problems/A._Array_with_Odd_Sum.md "Codeforces Round 617 (Div. 3)")

Firstly, if the array already has an odd sum, the answer is "YES". Otherwise, we need to change the parity of the sum, so we need to change the parity of some number. We can do in only when we have at least one even number and at least one odd number. Otherwise, the answer is "NO".

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
		int sum = 0;
		bool odd = false, even = false;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			sum += x;
			odd |= x % 2 != 0;
			even |= x % 2 == 0;
		}
		if (sum % 2 != 0 || (odd && even)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}
```
[1296B - Food Buying](../problems/B._Food_Buying.md "Codeforces Round 617 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1296B - Food Buying](../problems/B._Food_Buying.md "Codeforces Round 617 (Div. 3)")

Let's do the following greedy solution: it is obvious that when we buy food that costs exactly $10^k$ for $k \ge 1$, we don't lose any burles because of rounding. Let's take the maximum power of $10$ that is not greater than $s$ (let it be $10^c$), buy food that costs $10^c$ (and add this number to the answer) and add $10^{c-1}$ to $s$. Apply this process until $s < 10$ and then add $s$ to the answer.

Time complexity: $O(\log s)$ per test case.

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
		int s;
		cin >> s;
		int ans = 0;
		int pw = 1000 * 1000 * 1000;
		while (s > 0) {
			while (s < pw) pw /= 10;
			ans += pw;
			s -= pw - pw / 10;
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1296C - Yet Another Walking Robot](../problems/C._Yet_Another_Walking_Robot.md "Codeforces Round 617 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1296C - Yet Another Walking Robot](../problems/C._Yet_Another_Walking_Robot.md "Codeforces Round 617 (Div. 3)")

Formally, the problem asks you to remove the shortest cycle from the robot's path. Because the endpoint of the path cannot be changed, the number of 'L's should be equal to the number of 'R's and the same with 'U' and 'D'.

How to find the shortest cycle? Let's create the associative array $vis$ (std::map for C++) which will say for each point of the path the maximum number of operations $i$ such that if we apply first $i$ operations we will stay at this point. Initially, this array will contain only the point $(0, 0)$ with the value $0$. Let's go over all characters of $s$ in order from left to right. Let the current point be $(x_i, y_i)$ (we applied first $i+1$ operations, $0$-indexed). If this point is in the array already, let's try to update the answer with the value $i - vis[(x_i, y_i)] + 1$ and left and right borders with values $vis[(x_i, y_i)]$ and $i$ correspondingly. Then let's assign $vis[(x_i, y_i)] := i + 1$ and continue.

If there were no updates of the answer, the answer is -1. Otherwise, you can print any substring you found.

Time complexity: $O(n \log n)$ per test case.

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
		string s;
		cin >> n >> s;
		int l = -1, r = n;
		map<pair<int, int>, int> vis;
		pair<int, int> cur = {0, 0};
		vis[cur] = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'L') --cur.first;
			if (s[i] == 'R') ++cur.first;
			if (s[i] == 'U') ++cur.second;
			if (s[i] == 'D') --cur.second;
			if (vis.count(cur)) {
				if (i - vis[cur] + 1 < r - l + 1) {
					l = vis[cur];
					r = i;
				}
			}
			vis[cur] = i + 1;
		}
		if (l == -1) {
			cout << -1 << endl;
		} else {
			cout << l + 1 << " " << r + 1 << endl;
		}
	}
	
	return 0;
}
```
[1296D - Fight with Monsters](../problems/D._Fight_with_Monsters.md "Codeforces Round 617 (Div. 3)")

Inspiration: [300iq](https://codeforces.com/profile/300iq "Legendary Grandmaster 300iq"), idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1296D - Fight with Monsters](../problems/D._Fight_with_Monsters.md "Codeforces Round 617 (Div. 3)")

Let's calculate the minimum number of secret technique uses we need to kill each of the monsters. Let the current monster has $h$ hp. Firstly, it is obvious that we can take $h$ modulo $a+b$ (except one case). If it becomes zero, let's "rollback" it by one pair of turns. Then the number of uses of the secret technique we need is $\lceil\frac{h}{a}\rceil - 1$.

Let's sort all $n$ monsters by this value and take the "cheapest" set of monsters (prefix of the sorted array) with the sum of values less than or equal to $k$.

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
	
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		h[i] %= a + b;
		if (h[i] == 0) h[i] += a + b;
		h[i] = ((h[i] + a - 1) / a) - 1;
	}
	sort(h.begin(), h.end());
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (k - h[i] < 0) break;
		++ans;
		k -= h[i];
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1296E1 - String Coloring (easy version)](../problems/E1._String_Coloring_(easy_version).md "Codeforces Round 617 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1296E1 - String Coloring (easy version)](../problems/E1._String_Coloring_(easy_version).md "Codeforces Round 617 (Div. 3)")

Note that the actual problem is to divide the string into two subsequences that both of them are non-decreasing. You can note that this is true because you cannot the relative order of the elements colored in the same color, but you can write down subsequences of different colors in any order you want.

In this problem, you can write the following dynamic programming: $dp_{pos, c_1, c_2}$ is $1$ if you can split the prefix of the string $s[1..pos]$ into two non-decreasing sequences such that the first one ends with the character $c_1$ and the second one — with $c_2$ (characters are numbered from $0$ to $25$), otherwise $dp_{pos, c_1, c_2}$ is zero. Initially, only $dp_{0, 0, 0} = 1$, other values are zeros. Transitions are very easy: if the current value of dp is $dp_{i, c_1, c_2}$ then we can make a transition to $dp_{i + 1, c, c_2}$ if $c \ge c_1$ and to $dp_{i + 1, c_1, c}$ if $c \ge c_2$. Then you can restore the answer by carrying parent values.

But there is another very interesting solution. Let's go from left to right and carry two sequences $s_1$ and $s_2$. If the current character is not less than the last character of $s_1$ then let's append it to $s_1$, otherwise, if this character is not less than the last character of $s_2$ then append it to $s_2$, otherwise the answer is "NO".

If the answer isn't "NO" then $s_1$ and $s_2$ are required sequences. The proof and other stuff will be in the editorial of the hard version.

Time complexity: $O(n \cdot AL^2)$ or $O(n \cdot AL)$ or $O(n)$.

 **Solution (dp)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 222;
const int AL = 26;

bool dp[N][AL][AL];
pair<pair<int, int>, int> p[N][AL][AL];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	string s;
	cin >> n >> s;
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		int c = s[i] - 'a';
		for (int c1 = 0; c1 < AL; ++c1) {
			for (int c2 = 0; c2 < AL; ++c2) {
				if (!dp[i][c1][c2]) continue;
				if (c >= c1) {
					dp[i + 1][c][c2] = 1;
					p[i + 1][c][c2] = make_pair(make_pair(c1, c2), 0);
				}
				if (c >= c2) {
					dp[i + 1][c1][c] = 1;
					p[i + 1][c1][c] = make_pair(make_pair(c1, c2), 1);	
				}
			}
		}
	}
	
	int x = -1, y = -1;
	for (int c1 = 0; c1 < AL; ++c1) {
		for (int c2 = 0; c2 < AL; ++c2) {
			if (dp[n][c1][c2]) {
				x = c1, y = c2;
			}
		}
	}
	
	if (x == -1) {
		cout << "NO" << endl;
		return 0;
	}
	
	string res;
	for (int i = n; i > 0; --i) {
		int prvx = p[i][x][y].first.first;
		int prvy = p[i][x][y].first.second;
		if (p[i][x][y].second) res += '1';
		else res += '0';
		x = prvx;
		y = prvy;
	}
	
	reverse(res.begin(), res.end());
	cout << "YES" << endl << res << endl;
	
	return 0;
}
```
 **Solution (greedy)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	string s;
	cin >> n >> s;
	string res;
	char lst0 = 'a', lst1 = 'a';
	for (int i = 0; i < n; ++i) {
		if (s[i] >= lst0) {
			res += '0';
			lst0 = s[i];
		} else if (s[i] >= lst1) {
			res += '1';
			lst1 = s[i];
		} else {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl << res << endl;
	
	return 0;
}
```
[1296E2 - String Coloring (hard version)](../problems/E2._String_Coloring_(hard_version).md "Codeforces Round 617 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1296E2 - String Coloring (hard version)](../problems/E2._String_Coloring_(hard_version).md "Codeforces Round 617 (Div. 3)")

The solution of this problem is based on Dilworth's theorem. You can read about it on Wikipedia. In two words, this theorem says that the minimum number of non-decreasing sequences we need to cover the whole sequence equals the length of longest decreasing subsequence.

Let's calculate the dynamic programming $dp_i$ — the length of longest decreasing sequence that ends in the position $i$. To recalculate this dynamic, let's carry the array $maxdp$ of length $26$, where $maxdp_c$ means the maximum value of $dp$ for the character $c$ on the prefix we already considered. So, initially all $dp_i$ are ones, all values of $maxdp$ are zeros. For the position $i$ we update $dp_i$ with $max(maxdp_{s_i + 1}, maxdp_{s_i + 2}, \dots, maxdp_{25}) + 1$ and update $maxdp_{s_i}$ with $dp_i$.

Okay, how to restore the answer? That's pretty easy. The color of the $i$-th character is exactly $dp_i$. Why it is so? If $dp_i$ becomes greater than $max(maxdp_{s_i + 1}, maxdp_{s_i + 2}, \dots, maxdp_{25})$ then we surely need to use the new color for this character because we cannot append it to the end of any existing sequence. Otherwise, we will append it to some existing sequence (with the maximum possible number) and because it has the maximum number and we didn't update the value of $dp$ with the number of this sequence plus one, the current character is not less than the last in this sequence.

Time complexity: $O(n \cdot AL)$ or $O(n \log n)$.

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
	string s;
	cin >> n >> s;
	
	vector<int> maxdp(26);
	vector<int> dp(n, 1);
	for (int i = 0; i < n; ++i) {
		for (int c = 25; c > s[i] - 'a'; --c) {
			dp[i] = max(dp[i], maxdp[c] + 1);
		}
		maxdp[s[i] - 'a'] =  max(maxdp[s[i] - 'a'], dp[i]);
	}
	
	cout << *max_element(maxdp.begin(), maxdp.end()) << endl;
	for (int i = 0; i < n; ++i) cout << dp[i] << " ";
	cout << endl;
	
	return 0;
}
```
[1296F - Berland Beauty](../problems/F._Berland_Beauty.md "Codeforces Round 617 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1296F - Berland Beauty](../problems/F._Berland_Beauty.md "Codeforces Round 617 (Div. 3)")

Firstly, let's precalculate $n$ arrays $p_1, p_2, \dots, p_n$. The array $p_v$ is the array of "parents" if we run dfs from the vertex $v$. So, $p_{v, u}$ is the vertex that is the previous one before $u$ on the directed path $(v, u)$. This part can be precalculated in time $O(n^2)$ and we need it just for convenience.

Initially, all values $f_j$ (beauties of the edges) are zeros. Let's consider queries in order of non-decreasing $g_i$. For the current query, let's consider the whole path $(a_i, b_i)$ and update the value $f_j$ for each $j$ on this path in the following way: $f_j = max(f_j, g_i)$. After processing all queries, let's replace all values $f_j = 0$ with $f_j = 10^6$. This part works also in time $O(n^2)$.

And the last part of the solution is to check if the data we constructed isn't contradictory. We can iterate over all paths $(a_i, b_i)$ and find the minimum value $f_j$ on this path. We have to sure if it equals $g_i$. If it isn't true for at least one query, then the answer is -1.

Otherwise, we can print the resulting tree.

Time complexity: $O(n^2)$, but it can be done in at least $O(n \log n)$ (I hope someone can explain this solution because I am too lazy to do it now).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> val;
vector<vector<pair<int, int>>> g;

void dfs(int v, int pv, int pe, vector<pair<int, int>> &p) {
	p[v] = make_pair(pv, pe);
	for (auto it : g[v]) {
		int to = it.first;
		int idx = it.second;
		if (to == pv) continue;
		dfs(to, v, idx, p);
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n;
	g = vector<vector<pair<int, int>>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(make_pair(v, i));
		g[v].push_back(make_pair(u, i));
	}
	
	vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(n));
	for (int i = 0; i < n; ++i) {
		dfs(i, -1, -1, p[i]);
	}
	
	val = vector<int>(n - 1, 1000000);

    cin >> m;
	vector<pair<pair<int, int>, int>> q(m);
	for (int i = 0; i < m; ++i) {
		cin >> q[i].first.first >> q[i].first.second >> q[i].second;
		--q[i].first.first;
		--q[i].first.second;
	}
	sort(q.begin(), q.end(), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return a.second < b.second;
	});
	
	for (int i = 0; i < m; ++i) {
		int u = q[i].first.first;
		int v = q[i].first.second;
		while (v != u) {
			int pv = p[u][v].first;
			int pe = p[u][v].second;
			val[pe] = q[i].second;
			v = pv;
		}
	}
	
	for (int i = 0; i < m; ++i) {
		int u = q[i].first.first;
		int v = q[i].first.second;
		int mx = 1000000;
		while (v != u) {
			int pv = p[u][v].first;
			int pe = p[u][v].second;
			mx = min(mx, val[pe]);
			v = pv;
		}
		if (mx != q[i].second) {
			cout << -1 << endl;
			return 0;
		}
	}
	
	for (int i = 0; i < n - 1; ++i) {
		cout << val[i] << " ";
	}
	cout << endl;
	
	return 0;
}

```
