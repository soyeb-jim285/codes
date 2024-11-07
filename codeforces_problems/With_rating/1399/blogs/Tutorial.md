# Tutorial

All ideas belong to [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov").

[1399A - Remove Smallest](../problems/A._Remove_Smallest.md "Codeforces Round 661 (Div. 3)")

 **Tutorial**
### [1399A - Remove Smallest](../problems/A._Remove_Smallest.md "Codeforces Round 661 (Div. 3)")

Firstly, let's sort the initial array. Then it's obvious that the best way to remove elements is from smallest to biggest. And if there is at least one $i$ such that $2 \le i \le n$ and $a_i - a_{i-1} > 1$ then the answer is "NO", because we have no way to remove $a_{i-1}$. Otherwise, the answer is "YES".

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
		sort(a.begin(), a.end());
		bool ok = true;
		for (int i = 1; i < n; ++i) {
			ok &= (a[i] - a[i - 1] <= 1);
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}
```
[1399B - Gifts Fixing](../problems/B._Gifts_Fixing.md "Codeforces Round 661 (Div. 3)")

 **Tutorial**
### [1399B - Gifts Fixing](../problems/B._Gifts_Fixing.md "Codeforces Round 661 (Div. 3)")

At first, consider the problems on candies and oranges independently. Then it's pretty obvious that for candies the optimal way is to decrease all $a_i$ to the value $min(a)$ (we need obtain at least this value to equalize all the elements and there is no point to decrease elements further). The same works for the array $b$. Then, if we unite these two problems, we need to take the maximum moves we need for each $i$, because we need exactly that amount of moves to decrease $a_i$ to $min(a)$ and $b_i$ to $min(b)$ simultaneously.

So, the answer is $\sum\limits_{i=1}^{n} max(a_i - min(a), b_i - min(b))$.

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
		vector<int> a(n), b(n);
		for (auto &it : a) cin >> it;
		for (auto &it : b) cin >> it;
		int mna = *min_element(a.begin(), a.end());
		int mnb = *min_element(b.begin(), b.end());
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += max(a[i] - mna, b[i] - mnb);
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1399C - Boats Competition](../problems/C._Boats_Competition.md "Codeforces Round 661 (Div. 3)")

 **Tutorial**
### [1399C - Boats Competition](../problems/C._Boats_Competition.md "Codeforces Round 661 (Div. 3)")

This is just an implementation problem. Firstly, let's fix $s$ (it can be in range $[2; 2n]$), find the maximum number of boats we can obtain with this $s$ and choose the maximum among all found values.

To find the number of pairs, let's iterate over the smallest weight in the team in range $[1; \lfloor\frac{s + 1}{2}\rfloor - 1]$. Let this weight be $i$. Then (because the sum of weights is $s$) the biggest weight is $s-i$. And the number of pairs we can obtain with such two weights and the total weight $s$ is $min(cnt_i, cnt_{s - i})$, where $cnt_i$ is the number of occurrences of $i$ in $w$. And the additional case: if $s$ is even, we need to add $\lfloor\frac{cnt_{\frac{s}{2}}}{2}\rfloor$. Don't forget that there is a case $s - i > n$, so you need to assume that these values $cnt$ are zeros.

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
		vector<int> cnt(n + 1);
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			++cnt[x];
		}
		int ans = 0;
		for (int s = 2; s <= 2 * n; ++s) {
			int cur = 0;
			for (int i = 1; i < (s + 1) / 2; ++i) {
				if (s - i > n) continue;
				cur += min(cnt[i], cnt[s - i]);
			}
			if (s % 2 == 0) cur += cnt[s / 2] / 2;
			ans = max(ans, cur);
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1399D - Binary String To Subsequences](../problems/D._Binary_String_To_Subsequences.md "Codeforces Round 661 (Div. 3)")

 **Tutorial**
### [1399D - Binary String To Subsequences](../problems/D._Binary_String_To_Subsequences.md "Codeforces Round 661 (Div. 3)")

Let's iterate over all characters of $s$ from left to right, maintaining two arrays $pos_0$ and $pos_1$, where $pos_0$ stores indices of all subsequences which end with '0' and $pos_1$ stores indices of all subsequences which end with '1'. If we met '0', then the best choice is to append it to some existing subsequence which ends with '1'. If there are no such sequences, we need to create new one which ends with '0'. Otherwise we need to convert one of '1'-sequences to '0'-sequence. The same works with characters '1'. So, when we don't need to create the new sequence, we try to don't do that. And values in arrays $pos_0$ and $pos_1$ help us to determine the number of sequence we assign to each character.

And also, there is a cute proof of this solution from Gassa: let $f(i)$ be the difference between the number of '1' and the number of '0' on the prefix of $s$ of length $i$. We claim that the answer is $max(f(i)) - min(f(i))$ and let's show why is it true. Let's build a function on a plane with points $(i, f(i))$. Then we can match each $x$ between $min(f(i))$ and $max(f(i))$ with some subsequence.

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
		vector<int> ans(n);
		vector<int> pos0, pos1;
		for (int i = 0; i < n; ++i) {
			int newpos = pos0.size() + pos1.size();
			if (s[i] == '0') {
				if (pos1.empty()) {
					pos0.push_back(newpos);
				} else {
					newpos = pos1.back();
					pos1.pop_back();
					pos0.push_back(newpos);
				}
			} else {
				if (pos0.empty()) {
					pos1.push_back(newpos);
				} else {
					newpos = pos0.back();
					pos0.pop_back();
					pos1.push_back(newpos);
				}
			}
			ans[i] = newpos;
		}
		cout << pos0.size() + pos1.size() << endl;
		for (auto it : ans) cout << it + 1 << " ";
		cout << endl;
	}
	
	return 0;
}
```
[1399E1 - Weights Division (easy version)](../problems/E1._Weights_Division_(easy_version).md "Codeforces Round 661 (Div. 3)")

 **Tutorial**
### [1399E1 - Weights Division (easy version)](../problems/E1._Weights_Division_(easy_version).md "Codeforces Round 661 (Div. 3)")

Let's define $cnt_i$ as the number of leaves in the subtree of the $i$-th edge (of course, in terms of vertices, in the subtree of the lower vertex of this edge). Values of $cnt$ can be calculated with pretty standard and simple dfs and dynamic programming.

Then we can notice that our edges are independent and we can consider the initial answer (sum of weights of paths) as $\sum\limits_{i=1}^{n-1} w_i \cdot cnt_i$. Let $diff(i)$ be the difference between the current impact of the $i$-th edge and the impact of the $i$-th edge if we divide its weight by $2$. $diff(i) = w_i \cdot cnt_i - \lfloor\frac{w_i}{2}\rfloor \cdot cnt_i$. This value means how the sum of weights decreases if we divide the weight of the $i$-th edge by $2$.

Create ordered set which contains pairs $(diff(i), i)$. Then the following greedy solution works: let's take the edge with maximum $diff(i)$ and divide its weight by $2$. Then re-add it into the set with new value $diff(i)$. When the sum becomes less than or equal to $S$, just stop and print the number of divisions we made.

The maximum number of operations can reach $O(n \log w)$ so the solution complexity is $O(n \log{w} \log{n})$ (each operation takes $O(\log{n})$ time because the size of the set is $O(n)$).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> w, cnt;
vector<vector<pair<int, int>>> g;

long long getdiff(int i) {
	return w[i] * 1ll * cnt[i] - (w[i] / 2) * 1ll * cnt[i];
}

void dfs(int v, int p = -1) {
	if (g[v].size() == 1) cnt[p] = 1;
	for (auto [to, id] : g[v]) {
		if (id == p) continue;
		dfs(to, id);
		if (p != -1) cnt[p] += cnt[id];
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
		long long s;
		cin >> n >> s;
		w = cnt = vector<int>(n - 1);
		g = vector<vector<pair<int, int>>>(n);
		for (int i = 0; i < n - 1; ++i) {
			int x, y;
			cin >> x >> y >> w[i];
			--x, --y;
			g[x].push_back({y, i});
			g[y].push_back({x, i});
		}
		dfs(0);
		set<pair<long long, int>> st;
		long long cur = 0;
		for (int i = 0; i < n - 1; ++i) {
			st.insert({getdiff(i), i});
			cur += w[i] * 1ll * cnt[i];
		}
		cerr << cur << endl;
		int ans = 0;
		while (cur > s) {
			int id = st.rbegin()->second;
			st.erase(prev(st.end()));
			cur -= getdiff(id);
			w[id] /= 2;
			st.insert({getdiff(id), id});
			++ans;
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1399E2 - Weights Division (hard version)](../problems/E2._Weights_Division_(hard_version).md "Codeforces Round 661 (Div. 3)")

 **Tutorial**
### [1399E2 - Weights Division (hard version)](../problems/E2._Weights_Division_(hard_version).md "Codeforces Round 661 (Div. 3)")

Read the easy version editorial first, because almost all solution is the solution to the easy version with little changes.

Firstly, let's simulate the greedy process we used to solve the easy version problem, for edges with cost $1$ and edges with cost $2$, independently. But we don't stop when our sum reach something, let's simulate until our sum becomes $0$ and store each intermediate result in the array $v_1$ for edges with cost $1$ and $v_2$ for edges with cost $2$. So, the array $v_1$ contains the initial total impact of edges of cost $1$, then the impact after making one move, two moves, and so on... The same with $v_2$ but for edges with cost $2$.

Now let's fix how many moves on edges with cost $1$ we do. Let it be $i$ (and arrays $v_1$ and $v_2$ are $0$-indexed). Then the sum we obtain from the $1$-cost edges is $v_1[i]$. So we need to find the minimum number of moves $p$ we can do on $2$-cost edges so that $v_1[i] + v_2[p] \le S$. This can be done using binary search or moving pointer (if we iterate over $i$ in increasing order, place $p$ at the end of $v_2$ and move it to the left while $v_1[i] + v_2[p] \le S$). Then, if $v_1[i] + v_2[p] \le S$, we can update the answer with the value $i + 2p$.

Time complexity is actually the same as in easy version of the problem: $O(n \log{w} \log{n})$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n;
vector<int> w, c, cnt;
vector<vector<pair<int, int>>> g;

long long getdiff(int i) {
	return w[i] * 1ll * cnt[i] - (w[i] / 2) * 1ll * cnt[i];
}

void dfs(int v, int p = -1) {
	if (g[v].size() == 1) cnt[p] = 1;
	for (auto [to, id] : g[v]) {
		if (id == p) continue;
		dfs(to, id);
		if (p != -1) cnt[p] += cnt[id];
	}
}

vector<long long> get(int clr) {
	set<pair<long long, int>> st;
	long long cur = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (c[i] == clr) {
			st.insert({getdiff(i), i});
			cur += w[i] * 1ll * cnt[i];
		}
	}
	vector<long long> res;
	res.push_back(cur);
	while (cur > 0 && !st.empty()) {
		int id = st.rbegin()->second;
		st.erase(prev(st.end()));
		cur -= getdiff(id);
		res.push_back(cur);
		w[id] /= 2;
		st.insert({getdiff(id), id});
	}
	return res;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		long long s;
		cin >> n >> s;
		w = c = cnt = vector<int>(n - 1);
		g = vector<vector<pair<int, int>>>(n);
		for (int i = 0; i < n - 1; ++i) {
			int x, y;
			cin >> x >> y >> w[i] >> c[i];
			--x, --y;
			g[x].push_back({y, i});
			g[y].push_back({x, i});
		}
		dfs(0);
		vector<long long> v1 = get(1), v2 = get(2);
		int pos = int(v2.size()) - 1;
		int ans = INF;
		for (int i = 0; i < int(v1.size()); ++i) {
			while (pos > 0 && v1[i] + v2[pos - 1] <= s) --pos;
			if (v1[i] + v2[pos] <= s) {
				ans = min(ans, i + pos * 2);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1399F - Yet Another Segments Subset](../problems/F._Yet_Another_Segments_Subset.md "Codeforces Round 661 (Div. 3)")

 **Tutorial**
### [1399F - Yet Another Segments Subset](../problems/F._Yet_Another_Segments_Subset.md "Codeforces Round 661 (Div. 3)")

Firstly, let's compress the given borders of segments (just renumerate them in such a way that the maximum value is the minimum possible and the relative order of integers doesn't change). Pretty standard approach.

Now let's do recursive dynamic programming $dp_{l, r}$. This state stores the answer for the segment $[l; r]$ (not necessarily input segment!). How about transitions? Firstly, if there is a segment covering the whole segment $[l; r]$, why don't just take it? It doesn't change anything for us. The first transition is just skip the current left border and try to take the additional answer from the state $dp_{l + 1, r}$. The second transition is the following: let's iterate over all possible segments starting at $l$ (we can store all right borders of such segments in some array $rg_l$). Let the current segment be $[l; nr]$. If $nr \ge r$, just skip it (if $nr > r$ then we can't take this segment into the answer because it's out of $[l; r]$, and if $nr = r$ then we can't take it because we considered it already). Then we can take two additional answers: from $dp_{l, nr}$ and from $dp_{nr + 1, r}$. Don't forger about some corner cases, like when $nr + 1 > r$ or $l + 1 > r$ and something like that.

You can get the answer if you run the calculation from the whole segment.

What is the time complexity of this solution? We obviously have $O(n^2)$ states. And the number of transitions is also pretty easy to calculate. Let's fix some right border $r$. For this right border, we consider $O(n)$ segments in total. Summing up, we get $O(n^2)$ transitions. So the time complexity is $O(n^2)$.

P.S. I am sorry about pretty tight ML (yeah, I saw Geothermal got some memory issues because of using map). I really wanted to make it 512MB but just forgot to do that.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rg;
vector<vector<int>> dp;

int calc(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	dp[l][r] = 0;
	if (l > r) return dp[l][r];
	bool add = count(rg[l].begin(), rg[l].end(), r); // can't be greater than 1
	dp[l][r] = max(dp[l][r], add + (l + 1 > r ? 0 : calc(l + 1, r)));
	for (auto nr : rg[l]) {
		if (nr >= r) continue;
		dp[l][r] = max(dp[l][r], add + calc(l, nr) + (nr + 1 > r ? 0 : calc(nr + 1, r)));
	}
	return dp[l][r];
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
		vector<int> l(n), r(n);
		vector<int> val;
		for (int i = 0; i < n; ++i) {
			cin >> l[i] >> r[i];
			val.push_back(l[i]);
			val.push_back(r[i]);
		}
		sort(val.begin(), val.end());
		val.resize(unique(val.begin(), val.end()) - val.begin());
		for (int i = 0; i < n; ++i) {
			l[i] = lower_bound(val.begin(), val.end(), l[i]) - val.begin();
			r[i] = lower_bound(val.begin(), val.end(), r[i]) - val.begin();
		}
		int siz = val.size();
		dp = vector<vector<int>>(siz, vector<int>(siz, -1));
		rg = vector<vector<int>>(siz);
		for (int i = 0; i < n; ++i) {
			rg[l[i]].push_back(r[i]);
		}
		cout << calc(0, siz - 1) << endl;
	}
	
	return 0;
}
```
