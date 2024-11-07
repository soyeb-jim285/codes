# Tutorial_(en)

[1108A - Two distinct points](../problems/A._Two_distinct_points.md "Codeforces Round 535 (Div. 3)")

 **Tutorial**
### [1108A - Two distinct points](../problems/A._Two_distinct_points.md "Codeforces Round 535 (Div. 3)")

One of the possible answers is always a pair of endpoints of the given segments. So we can add all endpoints to the array and iterate over all pairs of elements of this array and check if the current pair is suitable or not.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		vector<int>a({l1, r1, l2, r2});
		int ans1 = 0, ans2 = 0;
		for (auto it : a) for (auto jt : a) {
			if (l1 <= it && it <= r1 && l2 <= jt && jt <= r2 && it != jt) {
				ans1 = it;
				ans2 = jt;
			}
		}
		cout << ans1 << " " << ans2 << endl;
	}
	
	return 0;
}
```
[1108B - Divisors of Two Integers](../problems/B._Divisors_of_Two_Integers.md "Codeforces Round 535 (Div. 3)")

 **Tutorial**
### [1108B - Divisors of Two Integers](../problems/B._Divisors_of_Two_Integers.md "Codeforces Round 535 (Div. 3)")

Let's take a look on the maximum element of the given array. Suddenly, this number is $x$ (or $y$, the order doesn't matter). Okay, what would we do if we know $x$ and merged list of divisors of $x$ and $y$? Let's remove all divisors of $x$ and see what we got. The maximum element in the remaining array is $y$. So, the problem is solved.

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
	multiset<int> a;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a.insert(x);
	}
	
	int x = *prev(a.end());
	for (int i = 1; i <= x; ++i) {
		if (x % i == 0) {
			a.erase(a.find(i));
		}
	}
	
	cout << x << " " << *prev(a.end()) << endl;
	
	return 0;
}
```
[1108C - Nice Garland](../problems/C._Nice_Garland.md "Codeforces Round 535 (Div. 3)")

 **Tutorial**
### [1108C - Nice Garland](../problems/C._Nice_Garland.md "Codeforces Round 535 (Div. 3)")

It is easy to see that any nice garland has one of the following $6$ patterns: 

* "BGRBGR ... BGR";
* "BRGBRG ... BRG";
* "GBRGBR ... GBR";
* "GRBGRB ... GRB";
* "RBGRBG ... RBG";
* "RGBRGB ... RGB";

We can hard-code all all this patterns or iterate over all these permutations of letters "BGR" using three nested loops or standard language functions. We can calculate for each pattern the cost to obtain such pattern from the given string and choose one with the minimum cost.

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
	
	vector<int> p(3);
	iota(p.begin(), p.end(), 0);
	
	string colors = "RGB";
	string res = "";
	int ans = 1e9;
	
	do {
		string t;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			t += colors[p[i % 3]];
			cnt += t[i] != s[i];
		}
		if (ans > cnt) {
			ans = cnt;
			res = t;
		}
	} while (next_permutation(p.begin(), p.end()));
	
	cout << ans << endl << res << endl;
	
	return 0;
}
```
[1108D - Diverse Garland](../problems/D._Diverse_Garland.md "Codeforces Round 535 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
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
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int j = i;
		while (j < n && s[i] == s[j]) {
			++j;
		}
		string q = "RGB";
		q.erase(q.find(s[i]), 1);
		if (j < n) q.erase(q.find(s[j]), 1);
		for (int k = i + 1; k < j; k += 2) {
			++ans;
			s[k] = q[0];
		}
		i = j - 1;
	}
	
	cout << ans << endl << s << endl;
	
	return 0;
}
```
[1108E1 - Array and Segments (Easy version)](../problems/E1._Array_and_Segments_(Easy_version).md "Codeforces Round 535 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(time(NULL));

const int INF = 1e9;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<pair<int, int>> b(m);
	for (int i = 0; i < m; ++i) {
		cin >> b[i].first >> b[i].second;
		--b[i].first;
		--b[i].second;
	}
	
	int ans = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
	vector<int> res;
	for (int i = 0; i < n; ++i) {
		vector<int> add(n + 1);
		vector<int> cur;
		for (int j = 0; j < m; ++j) {
			if (!(b[j].first <= i && i <= b[j].second)) {
				cur.push_back(j);
				for (int k = b[j].first; k <= b[j].second; ++k) {
					--add[k];
				}
			}
		}
		int mn = INF, mx = -INF;
		for (int j = 0; j < n; ++j) {
			mn = min(mn, a[j] + add[j]);
			mx = max(mx, a[j] + add[j]);
		}
		if (ans < mx - mn) {
			ans = mx - mn;
			res = cur;
		}
	}
	
	cout << ans << endl << res.size() << endl;
	shuffle(res.begin(), res.end(), rnd);
	for (auto it : res) cout << it + 1 << " ";
	cout << endl;
	
	return 0;
}
```
[1108E2 - Array and Segments (Hard version)](../problems/E2._Array_and_Segments_(Hard_version).md "Codeforces Round 535 (Div. 3)")

 **Tutorial**
### [1108E2 - Array and Segments (Hard version)](../problems/E2._Array_and_Segments_(Hard_version).md "Codeforces Round 535 (Div. 3)")

This tutorial is based on the previous problem (easy version) tutorial.

At first, I want to say I know that this problem and this approach can be implemented in $O(m \log n)$ with segment tree.

So, we iterate over all supposed maximums in the array and trying to apply all segments not covering our current element. How do we can calculate the answer for each element if this element is the supposed maximum?

Let's divide all segments we apply into two parts: the first part consists of segments such that their right endpoints is less than the current position and the second part consists of segments such that their left endpoints is greater than the current position. Then let's independently calculate answers for the left and for the right parts and merge them to obtain the answer.

I will consider only first part of the solution (first part of segments) because the second part is absolutely symmetric with it.

Let's maintain the minimum value on prefix of the array (let it be $mn$ and initially it equals to $+\infty$), maintain the array $ansv$ of length $n$ (initially its values are $-\infty$ and $ansv_i$ means the answer if the $i$-th element of the array will be supposed maximum) and the array $add$ of length $n$, where $add_i$ will be the value for which we decrease the $i$-th element (in other words, the number of segments we apply to the $i$-th element).

What do we do for the current position $i$? Firstly, let's update the answer for it with the value $a_i + add_i - mn$ (in other words, set $ansv_i := max(ansv_i, a_i + add_i - mn$)). Then let's apply all segments with right endpoints equals to the current position straight-forward and update the value $mn$ with each new value of covered elements. Just iterate over all positions $j$ of each segment ends in the current position, make $add_j := add_j - 1$ and set $mn := min(mn, a_j + add_j)$. And don't forget to update the value $mn$ with the value $a_i + add_i$ after all changes (because we need to update this value with each element not covered by segments too).

So then let's do the same from right to left and then $ansv_i$ will mean the answer if the $i$-th element is the supposed maximum in the resulting array. Then we can find any position of the maximum in the array $ansv$ and apply all segments which don't cover this position.

What is time complexity of the solution above? We iterate over all elements in the array, this is $O(n)$ and apply each segment in $O(n)$, so the final time complexity is $O(n + nm) = O(nm)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(time(NULL));

const int INF = 1e9;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<pair<int, int>> b(m);
	vector<vector<int>> lf(n), rg(n);
	for (int i = 0; i < m; ++i) {
		cin >> b[i].first >> b[i].second;
		--b[i].first;
		--b[i].second;
		lf[b[i].second].push_back(b[i].first);
		rg[b[i].first].push_back(b[i].second);
		}
	
	vector<int> ansv(n, -INF);
	
	vector<int> add(n + 1 , 0);
	int mn = a[0];
	
	for (int i = 0; i < n; ++i) {
		ansv[i] = max(ansv[i], a[i] - mn);
		for (auto l : lf[i]) {
			for (int j = l; j <= i; ++j) {
				--add[j];
				mn = min(mn, a[j] + add[j]);
			}
		}
		mn = min(mn, a[i] + add[i]);
	}
	
	add = vector<int>(n + 1, 0);
	mn = a[n - 1];
	
	for (int i = n - 1; i >= 0; --i) {
		ansv[i] = max(ansv[i], a[i] - mn);
		for (auto r : rg[i]) {
			for (int j = i; j <= r; ++j) {
				--add[j];
				mn = min(mn, a[j] + add[j]);
			}
		}
		mn = min(mn, a[i] + add[i]);
	}
	
	int ans = *max_element(ansv.begin(), ansv.end());
	vector<int> res;
	
	for (int i = 0; i < n; ++i) {
		if (ansv[i] == ans) {
			for (int j = 0; j < m; ++j) {
				if (!(b[j].first <= i && i <= b[j].second)) {
					res.push_back(j);
				}
			}
			break;
		}
	}
	
	cout << ans << endl << res.size() << endl;
	shuffle(res.begin(), res.end(), rnd);
	for (auto it : res) cout << it + 1 << " ";
	cout << endl;
	
	return 0;
}
```
[1108F - MST Unification](../problems/F._MST_Unification.md "Codeforces Round 535 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

vector<int> p, rk;

int getp(int v) {
	if (v == p[v]) return v;
	return p[v] = getp(p[v]);
}

bool merge(int v, int u) {
	u = getp(u);
	v = getp(v);
	
	if (u == v) return false;
	
	if (rk[u] < rk[v]) swap(u, v);
	
	rk[u] += rk[v];
	p[v] = u;
	
	return true;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	
	p = vector<int>(n);
	iota(p.begin(), p.end(), 0);
	rk = vector<int>(n, 1);
	
	vector<pair<pair<int, int>, int>> e(m);
	for (int i = 0; i < m; ++i) {
		cin >> e[i].x.x >> e[i].x.y >> e[i].y;
		--e[i].x.x;
		--e[i].x.y;
	}
	
	sort(e.begin(), e.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return a.y < b.y;
	});
	
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		int j = i;
		while (j < m && e[i].y == e[j].y) {
			++j;
		}
		int cnt = j - i;
		for (int k = i; k < j; ++k) {
			if (getp(e[k].x.x) == getp(e[k].x.y)) {
				--cnt;
			}
		}
		for (int k = i; k < j; ++k) {
			cnt -= merge(e[k].x.x, e[k].x.y);
		}
		ans += cnt;
		i = j - 1;
	}
	
	cout << ans << endl;
	
	return 0;
}
```
