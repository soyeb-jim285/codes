# Tutorial

I'm really sorry for the issue with the problem D difficulty, it was much harder than i expected, and there was a big difficulty gap between problems C and D. I hope in the next rounds it will never happen again.

**UPD**: I'd like to say a big thanks to [kevinsogo](https://codeforces.com/profile/kevinsogo "Гроссмейстер kevinsogo") for the great help with tutorials and the round preparation in general.

[999A - Мишка и контест](../problems/A._Mishka_and_Contest.md "Codeforces Round 490 (Div. 3)")

 **Tutorial**
### [999A - Mishka and Contest](../problems/A._Mishka_and_Contest.md "Codeforces Round 490 (Div. 3)")

You can iterate over all the elements of the array from left to right. Count the number of problems Mishka will solve from the left end of the list and break if he cannot solve the next one. Let's denote the number of problems Mishka will solve from the left end of the list by $\mathit{lf}$. Do the same thing independently from right to left. Denote the number of problems Mishka will solve from the right end of the list by $\mathit{rg}$. Then the answer is $\min(n, \mathit{lf} + \mathit{rg})$.

Time complexity — $O(n)$.

 **Solution (Vovuh)**
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
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	int ans = 0;
	while (!a.empty() && a.back() <= k) {
		++ans;
		a.pop_back();
	}
	reverse(a.begin(), a.end());
	while (!a.empty() && a.back() <= k) {
		++ans;
		a.pop_back();
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[999B - Переворотное шифрование](../problems/B._Reversing_Encryption.md "Codeforces Round 490 (Div. 3)")

 **Tutorial**
### [999B - Reversing Encryption](../problems/B._Reversing_Encryption.md "Codeforces Round 490 (Div. 3)")

To solve the problem, we can implement the encryption algorithm with a single change: we have to iterate over all divisors of $n$ in increasing order.

Time complexity — $O(n~ \cdot d(n))$, where $d(n)$ is a divisor count function for $n$. For example, $\max\limits_{i = 1}^{10^6}d(i) = 240$.

 **Solution (Vovuh)**
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
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) {
			reverse(s.begin(), s.begin() + i);
		}
	}
	cout << s << endl;
	
	return 0;
}
```
[999C - Алфавитное удаление](../problems/C._Alphabetic_Removals.md "Codeforces Round 490 (Div. 3)")

 **Tutorial**
### [999C - Alphabetic Removals](../problems/C._Alphabetic_Removals.md "Codeforces Round 490 (Div. 3)")

Let the lowercase Latin letters be indexed from $0$ to $25$.

There are exists at least two different solutions:

If $k = n$ exit the program. Otherwise, count the number of occurrences of each letter $i$ from $0$ to $25$. Let it be $\mathit{cnt}$. Now, find the (alphabetically) smallest letter that will be in the resulting string. It can be done as follows: iterate over all $i$ from $0$ to $25$, and if $\mathit{cnt}_i \le k$ then subtract it from $k$, otherwise, $i$ will be the smallest letter that will be in the resulting string. But we (possibly) need to remove some number of its leftmost occurrences. It is obvious that letters smaller than $i$ will not appear in the resulting string. Also, the $k$ leftmost occurrences of letter $i$ will be removed. Now, let's iterate over all letters in string $s$ from left to right and construct the resulting string $\mathit{res}$. If the current character of $s$ (let it be $s_j$) is smaller than $i$, then do nothing. If $s_j$ is greater than $i$, then add it to $\mathit{res}$. Otherwise $s_j = i$. If $k > 0$, then decrease $k$ by one, otherwise, add $s_j$ to $\mathit{res}$. The time complexity is $O(n)$.

Another solution is the following. Let's carry the vector of pairs $(s_i, i)$ where $s_i$ is the $i$-th character of $s$ and $i$ is its position. If we sort this vector with the standard compare function, it is easy to see that the first $k$ elements of this vector will be removed from the input string. Then if we will sort the last $n - k$ elements of this vector by its positions in the input string in increasing order, we will obtain the answer. The time complexity is $O(n \log n)$.

 **Solution 1 (Vovuh)**
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
	
	vector<int> cnt(26);
	for (auto c : s) ++cnt[c - 'a'];

	int pos = 26;
	for (int i = 0; i < 26; ++i) {
		if (k >= cnt[i]) {
			k -= cnt[i];
		} else {
			pos = i;
			break;
		}
	}
	
	string ans;
	int rem = k;
	for (auto c : s) {
		int cur = c - 'a';
		if (cur > pos || (cur == pos && rem == 0)) {
			ans += c;
		} else if (cur == pos) {
			--rem;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
```
 **Solution 2 (Vovuh)**
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

	vector<pair<char, int>> c(n);
	for (int i = 0; i < n; ++i)
		c[i] = make_pair(s[i], i);
	sort(c.begin(), c.end());
	sort(c.begin() + k, c.end(), [&] (const pair<char, int> &a, const pair<char, int> &b) {
		return a.second < b.second;
	});
	
	for (int i = k; i < n; ++i)
		cout << c[i].first;
	cout << endl;
	
	return 0;
}
```
[999D - Уравняй остатки](../problems/D._Equalize_the_Remainders.md "Codeforces Round 490 (Div. 3)")

 **Tutorial**
### [999D - Equalize the Remainders](../problems/D._Equalize_the_Remainders.md "Codeforces Round 490 (Div. 3)")

For each $i$ from $0$ to $m - 1$, find all elements of the array that are congruent to $i$ modulo $m$, and store their indices in a list. Also, create a vector called $\mathit{free}$, and let $k$ be $\frac{n}{m}$.

We have to cycle from $0$ to $m - 1$ twice. For each $i$ from $0$ to $m - 1$, if there are in list too many (i.e., $> k$) elements congruent to $i$ modulo $m$, remove the extra elements from this list and add them to $\mathit{free}$. If instead there are too few (i.e., $< k$) elements congruent to $i$ modulo $m$, remove the last few elements from the vector $\mathit{free}$. For every removed index $\mathit{idx}$, increase $a_\mathit{idx}$ by $(i - a_\mathit{idx}) \bmod m$. 

After doing so (after two passes), we print the total increase and the updated array.

It is obvious that after the first $m$ iterations, every list will have size at most $k$, and after $m$ more iterations, all lists will have the same sizes. It can be easily proved that this algorithm produces an optimal answer.

The time complexity is $O(n + m)$.

 **Solution (Vovuh)**
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
	int k = n / m;
	vector<int> a(n);
	vector<vector<int>> val(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		val[a[i] % m].push_back(i);
	}
	
	long long ans = 0;
	vector<pair<int, int>> fre;
	for (int i = 0; i < 2 * m; ++i) {
		int cur = i % m;
		while (int(val[cur].size()) > k) {
			int elem = val[cur].back();
			val[cur].pop_back();
			fre.push_back(make_pair(elem, i));
		}
		while (int(val[cur].size()) < k && !fre.empty()) {
			int elem = fre.back().first;
			int mmod = fre.back().second;
			fre.pop_back();
			val[cur].push_back(elem);
			a[elem] += i - mmod;
			ans += i - mmod;
		}
	}
	
	cout << ans << endl;
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
	
	return 0;
}
```
[999E - Достижимость из столицы](../problems/E._Reachability_from_the_Capital.md "Codeforces Round 490 (Div. 3)")

 **Tutorial**
### [999E - Reachability from the Capital](../problems/E._Reachability_from_the_Capital.md "Codeforces Round 490 (Div. 3)")

This problem is (almost) equivalent to the following: count the number of sources (the vertices with indegree equal to $0$) in the given graph's condensation. Thus, there exist solutions with complexity $O(n + m)$. However, the constraints in the problem are small, so solutions with complexity $O(n \cdot m)$ also pass.

One of these solutions is the following: first, let's mark all the vertices reachable from $s$ as good, using a simple DFS. Then, for each bad vertex $v$, count the number of bad vertices reachable from $v$ (it also can be done by simple DFS). Let this number be $\mathit{cnt}_v$. Now, iterate over all bad vertices in non-increasing order of $\mathit{cnt}_v$. For the current bad vertex $v$, if it is still not marked as good, run a DFS from it, marking all the reachable vertices as good, and increase the answer by $1$ (in fact, we are implicitly adding the edge $(s, v)$). It can be proved that this solution gives an optimal answer.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n, m, s;
vector<int> g[N];
bool used[N];
bool ok[N];

int cnt;

void dfs1(int v) {
	ok[v] = true;
	for (auto to : g[v])
		if (!ok[to])
			dfs1(to);
}

void dfs2(int v) {
	used[v] = true;
	++cnt;
	for (auto to : g[v])
		if (!used[to] && !ok[to])
			dfs2(to);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m >> s;
	--s;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
	}
	
	dfs1(s);
	
	vector<pair<int, int>> val;
	for (int i = 0; i < n; ++i) {
		if (!ok[i]) {
			cnt = 0;
			memset(used, false, sizeof(used));
			dfs2(i);
			val.push_back(make_pair(cnt, i));
		}
	}
	sort(val.begin(), val.end());
	reverse(val.begin(), val.end());
	
	int ans = 0;
	for (auto it : val) {
		if (!ok[it.second]) {
			++ans;
			dfs1(it.second);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
```
 **Linear Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n, m, s;
vector<int> g[N];
vector<int> tg[N];
vector<int> cg[N];
vector<int> ord;
int indeg[N];
bool ucomp[N];
bool used[N];
int comp[N];
int cnt;

void dfs1(int v) {
	used[v] = true;
	for (auto to : g[v])
		if (!used[to])
			dfs1(to);
	ord.push_back(v);
}

void dfs2(int v) {
	comp[v] = cnt;
	for (auto to : tg[v])
		if (comp[to] == -1)
			dfs2(to);
}

void dfs3(int v) {
	ucomp[v] = true;
	for (auto to : cg[v])
		if (!ucomp[to])
			dfs3(to);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m >> s;
	--s;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		tg[y].push_back(x);
	}
	
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs1(i);
		}
	}
	
	reverse(ord.begin(), ord.end());
	memset(comp, -1, sizeof(comp));
	for (int i = 0; i < n; ++i) {
		if (comp[ord[i]] == -1) {
			dfs2(ord[i]);
			++cnt;
		}
	}
	
	for (int v = 0; v < n; ++v) {
		for (auto to : g[v]) {
			if (comp[v] != comp[to]) {
				cg[comp[v]].push_back(comp[to]);
				++indeg[comp[to]];
			}
		}
	}
	
	dfs3(comp[s]);
	int ans = 0;
	for (int i = 0; i < cnt; ++i)
		if (!ucomp[i] && indeg[i] == 0)
			++ans;
			
	cout << ans << endl;
	
	return 0;
}
```
[999F - Карты и радость](../problems/F._Cards_and_Joy.md "Codeforces Round 490 (Div. 3)")

 **Tutorial**
### [999F - Cards and Joy](../problems/F._Cards_and_Joy.md "Codeforces Round 490 (Div. 3)")

It is obvious that we can solve the problem separately for each favorite number because each player has only one favorite number, and if the player gets a card not having his favorite number, his joy will not change.

Let $\mathit{dp}[x][y]$ be the maximum possible total joy of $x$ players with the same favorite number (it doesn't matter which one) and $y$ cards (containing their favorite number) if the cards are distributed among the players optimally. Note that $x \in [0, n]$ and $y \in [0, k \cdot n]$. At the beginning, all entries of the $\mathit{dp}$ table are zeroes. The transition in this dynamic programming depends on how many cards the $x$-th player will receive (which is between $0$ and $k$). In other words, the dynamic programming transition will look like:


```cpp
 for (int i = 0; i <= k; ++i) dp[x + 1][y + i] = max(dp[x + 1][y + i], dp[x][y] + h[i]),  

```
where $h[i]$ is the joy of the player if he receives exactly $i$ cards containing his favorite number. Note that $h[0] = 0$.

After filling the $\mathit{dp}$ table, the answer can be calculated very easily: $\mathit{ans} = \sum\limits_{i = 1}^{10^5}\mathit{dp}[f_i][c_i]$, where $f_i$ is the number of players with favorite number $i$ and $c_i$ is the number of cards containing the number $i$.

Time complexity is $O(n^2 \cdot k^2)$.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 520;
const int K = 12;
const int C = 100 * 1000 + 11;

int n, k;
int c[C];
int f[C];
vector<int> h;

int dp[N][K * N];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> k;
	h = vector<int>(k + 1);
	for (int i = 0; i < n * k; ++i) {
		int x;
		cin >> x;
		++c[x];
	}
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++f[x];
	}
	for (int i = 1; i <= k; ++i)
		cin >> h[i];
		
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n * k; ++j) {
			for (int cur = 0; cur <= k; ++cur) {
				dp[i + 1][j + cur] = max(dp[i + 1][j + cur], dp[i][j] + h[cur]);
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < C; ++i) {
		if (f[i] != 0) ans += dp[f[i]][c[i]];
	}
	
	cout << ans << endl;
	
	return 0;
}
```
