# Tutorial

All ideas except the problem C belong to [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"). The author of C is [Rox](https://codeforces.com/profile/Rox "Candidate Master Rox").

Special thanks to [_overrated_](https://codeforces.com/profile/_overrated_ "Master _overrated_") for the invaluable help with the round preparation!

[1272A - Three Friends](../problems/A._Three_Friends.md "Codeforces Round 605 (Div. 3)")

 **Tutorial**
### [1272A - Three Friends](../problems/A._Three_Friends.md "Codeforces Round 605 (Div. 3)")

This problem can be solved with simple simulation. Let $na \in \{a - 1, a, a + 1\}$ be the new position of the first friend, $nb \in \{b - 1, b, b + 1\}$ and $nc \in \{c - 1, c, c + 1\}$ are new positions of the second and the third friends correspondingly. For the fixed positions you can update the answer with the value $|na - nb| + |na - nc| + |nb - nc|$. And iterating over three positions can be implemented with nested loops.

Time complexity: $O(1)$ per test case.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int calc(int a, int b, int c) {
	return abs(a - b) + abs(a - c) + abs(b - c);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = calc(a, b, c);
		for (int da = -1; da <= 1; ++da) {
			for (int db = -1; db <= 1; ++db) {
				for (int dc = -1; dc <= 1; ++dc) {
					int na = a + da;
					int nb = b + db;
					int nc = c + dc;
					ans = min(ans, calc(na, nb, nc));
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1272B - Snow Walking Robot](../problems/B._Snow_Walking_Robot.md "Codeforces Round 605 (Div. 3)")

 **Tutorial**
### [1272B - Snow Walking Robot](../problems/B._Snow_Walking_Robot.md "Codeforces Round 605 (Div. 3)")

Let $cnt[L]$ be the number of occurrences of the character 'L' in the initial string, $cnt[R]$ — the number of occurrences of the character 'R', $cnt[U]$ and $cnt[D]$ are the same things for remaining characters.

It is obvious that in every answer the number of 'L' equals the number of 'R' and the same for 'D' and 'U'. The maximum theoretic answer we can obtain has length $2 \cdot (min(cnt[L], cnt[R]) + min(cnt[U] + cnt[D]))$. And... We almost always can obtain this answer! If there is at least one occurrence of each character, then we can construct some kind of rectangular path: $min(cnt[L], cnt[R])$ moves right, then $min(cnt[U], cnt[D])$ moves up, and the completing part.

But there are some corner cases when some characters are missing. If $min(cnt[U], cnt[D]) = 0$ then our answer is empty or (if it is possible) it is "LR". The same if $min(cnt[L], cnt[R]) = 0$.

Time complexity: $O(|s|)$ per test case.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const string MOVES = "LRUD";

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string s;
		cin >> s;
		map<char, int> cnt;
		for (auto c : MOVES) cnt[c] = 0;
		for (auto c : s) ++cnt[c];
		int v = min(cnt['U'], cnt['D']);
		int h = min(cnt['L'], cnt['R']);
		if (min(v, h) == 0) {
			if (v == 0) {
				h = min(h, 1);
				cout << 2 * h << endl << string(h, 'L') + string(h, 'R') << endl;
			} else {
				v = min(v, 1);
				cout << 2 * v << endl << string(v, 'U') + string(v, 'D') << endl;
			}
		} else {
			string res;
			res += string(h, 'L');
			res += string(v, 'U');
			res += string(h, 'R');
			res += string(v, 'D');
			cout << res.size() << endl << res << endl;
		}
	}
	
	return 0;
}
```
[1272C - Yet Another Broken Keyboard](../problems/C._Yet_Another_Broken_Keyboard.md "Codeforces Round 605 (Div. 3)")

 **Tutorial**
### [1272C - Yet Another Broken Keyboard](../problems/C._Yet_Another_Broken_Keyboard.md "Codeforces Round 605 (Div. 3)")

Let's replace all characters of $s$ with zeros and ones (zero if the character is unavailable and one otherwise). Then we have the binary string and we have to calculate the number of contiguous segments of this string consisting only of ones. It can be done with two pointers approach.

If we are staying at the position $i$ and its value is zero, just skip it. Otherwise, let's find the leftmost position $j$ such that $j > i$ and the $j$-th value is zero. Then we have to add to the answer the value $\frac{(j - i) \cdot (j - i + 1)}{2}$ and set $i := j$.

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
	
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	set<char> st;
	for (int i = 0; i < k; ++i) {
		char c;
		cin >> c;
		st.insert(c);
	}
	
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int j = i;
		while (j < n && st.count(s[j])) ++j;
		int len = j - i;
		ans += len * 1ll * (len + 1) / 2;
		i = j;
	}
	cout << ans << endl;
	
	return 0;
}
```
[1272D - Remove One Element](../problems/D._Remove_One_Element.md "Codeforces Round 605 (Div. 3)")

 **Tutorial**
### [1272D - Remove One Element](../problems/D._Remove_One_Element.md "Codeforces Round 605 (Div. 3)")

Firstly, let's calculate for each $i$ from $1$ to $n$ two following values: $r_i$ and $l_i$. $r_i$ means the maximum length of the increasing sequence starting in the position $i$, and $l_i$ means the maximum length of the increasing sequence ending in the position $i$. Initially, all $2n$ values are $1$ (the element itself).

The array $r$ can be calculated in order from right to left with the following condition: if $a_i < a_{i + 1}$ then $r_i = r_{i + 1} + 1$, otherwise it still remain $1$. The same with the array $l$, but we have to calculate its values in order from left to right, and if $a_i > a_{i - 1}$ then $l_i = l_{i - 1} + 1$, otherwise it still remain $1$.

Having these arrays we can calculate the answer. The initial answer (if we don't remove any element) is the maximum value of the array $l$. And if we remove the $i$-th element (where $i = 2 \dots n - 1$), then we can update the answer with the value $l_{i - 1} + r_{i + 1}$ if $a_{i - 1} < a_{i + 1}$.

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
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 1;
	
	vector<int> rg(n, 1);
	for (int i = n - 2; i >= 0; --i) {
		if (a[i + 1] > a[i]) rg[i] = rg[i + 1] + 1;
		ans = max(ans, rg[i]);
	}
	
	vector<int> lf(n, 1);
	for (int i = 1; i < n; ++i) {
		if (a[i - 1] < a[i]) lf[i] = lf[i - 1] + 1;
		ans = max(ans, lf[i]);
	}
	
	for (int i = 0; i < n - 2; ++i) {
		if (a[i] < a[i + 2]) ans = max(ans, lf[i] + rg[i + 2]);
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1272E - Nearest Opposite Parity](../problems/E._Nearest_Opposite_Parity.md "Codeforces Round 605 (Div. 3)")

 **Tutorial**
### [1272E - Nearest Opposite Parity](../problems/E._Nearest_Opposite_Parity.md "Codeforces Round 605 (Div. 3)")

In this problem, we have directed graph consisting of $n$ vertices (indices of the array) and at most $2n-2$ edges. Some vertices have the value $0$, some have the value $1$. Our problem is to find for every vertex the nearest vertex having the opposite parity. Let's try to solve the problem for odd numbers and then just run the same algorithm with even numbers.

We have multiple odd vertices and we need to find the nearest even vertex for each of these vertices. This problem can be solved with the standard and simple but pretty idea. Let's inverse our graph and run a multi-source breadth-first search from all even vertices. The only difference between standard bfs and multi-source bfs is that the second one have many vertices at the first step (vertices having zero distance).

Now we can notice that because of bfs every odd vertex of our graph has the distance equal to the minimum distance to some even vertex in the initial graph. This is exactly what we need. Then just run the same algorithm for even numbers and print the answer.

Time complexity: $O(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n;
vector<int> a;
vector<int> ans;
vector<vector<int>> g;

void bfs(const vector<int> &start, const vector<int> &end) {
	vector<int> d(n, INF);
	queue<int> q;
	for (auto v : start) {
		d[v] = 0;
		q.push(v);
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto to : g[v]) {
			if (d[to] == INF) {
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}
	for (auto v : end) {
		if (d[v] != INF) {
			ans[v] = d[v];
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n;
	a = vector<int>(n);
	g = vector<vector<int>>(n);
	vector<int> even, odd;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] & 1) odd.push_back(i);
		else even.push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		int lf = i - a[i];
		int rg = i + a[i];
		if (0 <= lf) g[lf].push_back(i);
		if (rg < n) g[rg].push_back(i);
	}
	
	ans = vector<int>(n, -1);
	bfs(odd, even);
	bfs(even, odd);
	for (auto it : ans) cout << it << " ";
	cout << endl;
	
	return 0;
}
```
[1272F - Two Bracket Sequences](../problems/F._Two_Bracket_Sequences.md "Codeforces Round 605 (Div. 3)")

 **Tutorial**
### [1272F - Two Bracket Sequences](../problems/F._Two_Bracket_Sequences.md "Codeforces Round 605 (Div. 3)")

Firstly, notice that the length of the answer cannot exceed $400$ ($200$ copies of ()). Now we can do some kind of simple dynamic programming. Let $dp_{i, j, bal}$ be the minimum possible length of the prefix of the regular bracket sequence if we are processed first $i$ characters of the first sequence, first $j$ characters of the second sequence and the current balance is $bal$. Each dimension of this dp should have a size nearby $200 + \varepsilon$.

The base of this dp is $dp_{0, 0, 0} = 0$, all other values $dp_{i, j, bal} = +\infty$.

Transitions are very easy: if we want to place the opening bracket, then we increase $i$ if the $i$-th character of $s$ exists and equals '(', the same with the second sequence and $j$, the balance increases by one, and the length of the answer increases by one. If we want to place the closing bracket, then we increase $i$ if the $i$-th character of $s$ exists and equals ')', the same with the second sequence and $j$, the balance decreases by one, and the length of the answer increases by one. Note that the balance cannot be greater than $200$ or less than $0$ at any moment.

Don't forget to maintain parents in this dp to restore the actual answer!

The last problem that can be unresolved is how to write this dp? The easiest way is bfs, because every single transition increases our answer by one. Then we can restore answer from the state $dp_{|s|, |t|, 0}$. You can write it recursively, but I don't sure this will look good. And you also can write it just with nested loops, if you are careful enough.

Time complexity: $O(|s| \cdot |t| \cdot max(|s|, |t|))$.

If you know the faster solution, please share it!

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 202;
const int INF = 1e9;

int dp[N][N][2 * N];
pair<pair<int, int>, pair<int, char>> p[N][N][2 * N];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int bal = 0; bal < 2 * N; ++bal) {
				dp[i][j][bal] = INF;
			}
		}
	}
	
	dp[0][0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int bal = 0; bal < 2 * N; ++bal) {
				if (dp[i][j][bal] == INF) continue;
				
				int nxti = i + (i < n && s[i] == '(');
				int nxtj = j + (j < m && t[j] == '(');
				if (bal + 1 < 2 * N && dp[nxti][nxtj][bal + 1] > dp[i][j][bal] + 1) {
					dp[nxti][nxtj][bal + 1] = dp[i][j][bal] + 1;
					p[nxti][nxtj][bal + 1] = make_pair(make_pair(i, j), make_pair(bal, '('));
				}
				
				nxti = i + (i < n && s[i] == ')');
				nxtj = j + (j < m && t[j] == ')');
				if (bal > 0 && dp[nxti][nxtj][bal - 1] > dp[i][j][bal] + 1) {
					dp[nxti][nxtj][bal - 1] = dp[i][j][bal] + 1;
					p[nxti][nxtj][bal - 1] = make_pair(make_pair(i, j), make_pair(bal, ')'));
				}
			}
		}
	}
	
	int ci = n, cj = m, cbal = 0;
	for (int bal = 0; bal < 2 * N; ++bal) {
		if (dp[n][m][bal] + bal < dp[n][m][cbal] + cbal) {
			cbal = bal;
		}
	}
	string res = string(cbal, ')');
	while (ci > 0 || cj > 0 || cbal != 0) {
		int nci = p[ci][cj][cbal].first.first;
		int ncj = p[ci][cj][cbal].first.second;
		int ncbal = p[ci][cj][cbal].second.first;
		res += p[ci][cj][cbal].second.second;
		ci = nci;
		cj = ncj;
		cbal = ncbal;
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
	
	return 0;
}
```
