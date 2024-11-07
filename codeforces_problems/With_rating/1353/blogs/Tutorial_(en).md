# Tutorial_(en)

All problems, except the problem D, are mine. The problem D author is [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov").

[1353A - Most Unstable Array](../problems/A._Most_Unstable_Array.md "Codeforces Round 642 (Div. 3)")

 **Tutorial**
### [1353A - Most Unstable Array](../problems/A._Most_Unstable_Array.md "Codeforces Round 642 (Div. 3)")

If $n=1$ then the answer is $0$. Otherwise, the best way is to construct the array $[0, m, 0, \dots, 0]$. For $n=2$ we can't reach answer more than $m$ and for $n > 2$ we can't reach the answer more than $2m$ because each unit can't be used more than twice. So the answer can be represented as $min(2, n - 1) \cdot m$.

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
		int n, m;
		cin >> n >> m;
		cout << min(2, n - 1) * m << endl;
	}
	
	return 0;
}
```
[1353B - Two Arrays And Swaps](../problems/B._Two_Arrays_And_Swaps.md "Codeforces Round 642 (Div. 3)")

 **Tutorial**
### [1353B - Two Arrays And Swaps](../problems/B._Two_Arrays_And_Swaps.md "Codeforces Round 642 (Div. 3)")

Each move we can choose the minimum element in $a$, the maximum element in $b$ and swap them (if the minimum in $a$ is less than maximum in $b$). If we repeat this operation $k$ times, we get the answer. This can be done in $O(n^3)$, $O(n^2)$ but authors solution is $O(n \log n)$.

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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		vector<int> b(n);
		for (auto &it : b) cin >> it;
		sort(a.begin(), a.end());
		sort(b.rbegin(), b.rend());
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (i < k) ans += max(a[i], b[i]);
			else ans += a[i];
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1353C - Board Moves](../problems/C._Board_Moves.md "Codeforces Round 642 (Div. 3)")

 **Tutorial**
### [1353C - Board Moves](../problems/C._Board_Moves.md "Codeforces Round 642 (Div. 3)")

It is intuitive (and provable) that the best strategy is to move each figure to the center cell $(\frac{n+1}{2}, \frac{n+1}{2})$. Now, with some paperwork or easy observations, we can notice that we have exactly $8$ cells with the shortest distance $1$, $16$ cells with the shortest distance $2$, $24$ cells with the shortest distance $3$ and so on. So we have $8i$ cells with the shortest distance $i$. So the answer is $1 \cdot 8 + 2 \cdot 16 + 3 \cdot 24 + \dots + (\frac{n-1}{2})^2 \cdot 8$. It can be rewritten as $8 (1 + 4 + 9 + \dots + (\frac{n-1}{2})^2)$ so we can just calculate the sum of squares of all integers from $1$ to $\frac{n-1}{2}$ using loop (or formula $\frac{n(n+1)(2n+1)}{6}$) and multiply the answer by $8$.

Time complexity: $O(n)$ or $O(1)$.

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
		long long ans = 0;
		for (int i = 1; i <= n / 2; ++i) {
			ans += i * 1ll * i;
		}
		cout << ans * 8 << endl;
	}
	
	return 0;
}
```
[1353D - Constructing the Array](../problems/D._Constructing_the_Array.md "Codeforces Round 642 (Div. 3)")

 **Tutorial**
### [1353D - Constructing the Array](../problems/D._Constructing_the_Array.md "Codeforces Round 642 (Div. 3)")

This is just an implementation problem. We can use some kind of heap or ordered set to store all segments we need in order we need. To solve this problem on C++ with std::set, we can just rewrite the comparator for std::set like this:


```cpp
struct cmp {  
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {  
		int lena = a.second - a.first + 1;  
		int lenb = b.second - b.first + 1;  
		if (lena == lenb) return a.first < b.first;  
		return lena > lenb;  
	}  
};  

```
And then just write the std::set like this:


```cpp
set<pair<int, int>, cmp> segs;  

```
Now the minimum element of the set will be the segment that we need to choose. Initially, the set will contain only one segment $[0;n-1]$. Suppose we choose the segment $[l; r]$ during the $i$-th action. Let $id = \lfloor\frac{l+r}{2}\rfloor$, where $\lfloor\frac{x}{y}\rfloor$ is $x$ divided by $y$ rounded down. Assign (set) $a[id] := i$, then if the segment $[l; id-1]$ has positive (greater than zero) length, push this segment to the set and the same with the segment $[id+1;r]$. After $n$ such actions we get the answer.

Time complexity: $O(n \log n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

struct cmp {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		int lena = a.second - a.first + 1;
		int lenb = b.second - b.first + 1;
		if (lena == lenb) return a.first < b.first;
		return lena > lenb;
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
		int n;
		cin >> n;
		set<pair<int, int>, cmp> segs;
		segs.insert({0, n - 1});
		vector<int> a(n);
		for (int i = 1; i <= n; ++i) {
			pair<int, int> cur = *segs.begin();
			segs.erase(segs.begin());
			int id = (cur.first + cur.second) / 2;
			a[id] = i;
			if (cur.first < id) segs.insert({cur.first, id - 1});
			if (id < cur.second) segs.insert({id + 1, cur.second});
		}
		for (auto it : a) cout << it << " ";
		cout << endl;
	}
	
	return 0;
}
```
[1353E - K-periodic Garland](../problems/E._K-periodic_Garland.md "Codeforces Round 642 (Div. 3)")

 **Tutorial**
### [1353E - K-periodic Garland](../problems/E._K-periodic_Garland.md "Codeforces Round 642 (Div. 3)")

Let $t_i$ be the string containing all characters of $s$ that have indices $i, i + k, i + 2k$ and so on (i.e. all such positions that have the remainder $i$ modulo $k$). Suppose we choose that all turned on lamps will have remainder $i$ modulo $k$. Then we need to remove all ones at the positions that do not belong to this remainder. Also considering the string $t_i$, we need to spend the minimum number of moves to make this string of kind "contiguous block of zeros, contiguous block of ones and again contiguous block of zeros", because considering the characters modulo $k$ will lead us to exactly this pattern (notice that some blocks can be empty).

How to calculate the answer for the string $t_i$ in linear time? Let $dp_i[p]$ be the number of moves we need to fix the prefix of $t_i$ till the $p$-th character in a way that the $p$-th character of $t_i$ is '1'. Let $cnt(S, l, r)$ be the number of ones in $S$ on the segment $[l; r]$. Notice that we can calculate all required values $cnt$ in linear time using prefix sums. Then we can calculate $dp_i[p]$ as $min(cnt(t_i, 0, p - 1) + [t_i[p] \ne~ '1'], dp_i[p-1] + [t_i[p] \ne~ '1'])$, where $[x]$ is the boolean value of the expression $x$ ($1$ if $x$ is true and $0$ otherwise). Let $len(S)$ be the length of $S$. Then the actual answer for the string $t_i$ can be calculated as $ans_i = \min(cnt(t_i, 0, len(t_i) - 1), \min\limits_{p=0}^{len(t_i) - 1} (dp_i[p] + cnt(t_i, p + 1, len(t_i) - 1)))$ (thus we consider the case when the obtained string doesn't contan ones at all and consider each position as the last position of some one).

So the actual answer can be calculated as $\min\limits_{i=0}^{k-1} (ans_i + cnt(s, 0, len(s) - 1) - cnt(t_i, 0, len(t_i) - 1))$.

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
	
	auto solve = [](const string &s) {
		int n = s.size();
		int all = count(s.begin(), s.end(), '1');
		int ans = all;
		vector<int> res(n);
		int pref = 0;
		for (int i = 0; i < n; ++i) {
			int cur = (s[i] == '1');
			pref += cur;
			res[i] = 1 - cur;
			if (i > 0) res[i] += min(res[i - 1], pref - cur);
			ans = min(ans, res[i] + all - pref);
		}
		return ans;
	};
	
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		vector<string> val(k);
		int cnt = count(s.begin(), s.end(), '1');
		for (int i = 0; i < n; ++i) {
			val[i % k] += s[i];
		}
		int ans = 1e9;
		for (auto &it : val) ans = min(ans, solve(it) + (cnt - count(it.begin(), it.end(), '1')));
		cout << ans << endl;
	}
	
	return 0;
}
```
[1353F - Decreasing Heights](../problems/F._Decreasing_Heights.md "Codeforces Round 642 (Div. 3)")

 **Tutorial**
### [1353F - Decreasing Heights](../problems/F._Decreasing_Heights.md "Codeforces Round 642 (Div. 3)")

Firstly, consider the field in $0$-indexation. Suppose that the cell $(0, 0)$ has some fixed height. Let it be $b_{0, 0}$. Then we can determine what should be the height of the cell $(i, j)$ as $b_{i, j} = b_{0, 0} + i + j$. In fact, it does not matter which way we choose, we actually need only the number of moves to reach the cell and the height of the cell $(0, 0)$.

Then (when the height of the cell $(0, 0)$ is fixed) we can solve the problem with the following dynamic programming: $dp_{i, j}$ is the minimum number of operations we need to reach the cell $(i, j)$ from the cell $(0, 0)$. Initially, all values $dp_{i, j} = +\infty$ except $dp_{0, 0} = 0$. Then $dp_{i, j}$ can be calculated as $min(dp_{i - 1, j}, dp_{i, j - 1}) + (a_{i, j} - b_{i, j})$. But one more thing: if $a_{i, j} < b_{i, j}$ then this value of $dp$ is incorrect and we cannot use it. We also can't update $dp$ from the incorrect values. The answer for the problem with the fixed height of the cell $(0, 0)$ is $dp_{n - 1, m - 1} + a_{0, 0} - b_{0, 0}$ (only when $dp_{n-1,m-1}$ is correct and $a_{i, j} \ge b_{i, j}$). This part can be calculated in $O(n^2)$.

But if we iterate over all possible heights, our solution obvious will get time limit exceeded verdict. Now we can notice one important fact: in the optimal answer, the height of some cell remains unchanged. Let this cell be $(i, j)$. Then we can restore the height of the cell $(0, 0)$ as $a_{i, j} - i - j$ and run our quadratic dynamic programming to find the answer for this height.

Time complexity: $O(n^4)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const long long INF64 = 1e18;

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
		vector<vector<long long>> a(n, vector<long long>(m));
		forn(i, n) forn(j, m) {
			cin >> a[i][j];
		}
		long long a00 = a[0][0];
		long long ans = INF64;
		forn(x, n) forn(y, m) {
			long long need = a[x][y] - x - y;
			if (need > a00) continue;
			a[0][0] = need;
			vector<vector<long long>> dp(n, vector<long long>(m, INF64));
			dp[0][0] = a00 - need;
			forn(i, n) forn(j, m) {
				long long need = a[0][0] + i + j;
				if (need > a[i][j]) continue;
				if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j] - need);
				if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j] - need);
			}
			ans = min(ans, dp[n - 1][m - 1]);
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
