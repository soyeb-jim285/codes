# Tutorial

All ideas except the problem C belong to [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov").

[1213A - Chips Moving](../problems/A._Chips_Moving.md "Codeforces Round 582 (Div. 3)")

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
	cin >> n;
	int cnto = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		cnto += x & 1;
	}
	
	cout << min(cnto, n - cnto) << endl;
	
	return 0;
}
```
[1213B - Bad Prices](../problems/B._Bad_Prices.md "Codeforces Round 582 (Div. 3)")

 **Tutorial**
### [1213B - Bad Prices](../problems/B._Bad_Prices.md "Codeforces Round 582 (Div. 3)")

Let $minPrice_i$ be the minimum price of the berPhone during days $i, i + 1, \dots, n$. We can precalculate this array moving from right to left and carrying the minimum price we met (in other words, if we iterate over all $i$ from $n$ to $1$ then $minPrice_i = a_i$ if $i = n$ otherwise $minPrice_i = min(a_i, minPrice_{i + 1})$). Then the answer is the number of such days $i$ from $1$ to $n-1$ that $a_i > minPrice_{i + 1}$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn(i, n)
            cin >> a[i];
        int ans = 0;
        int right_min = INT_MAX;
        for (int i = n -  1; i >= 0; i--) {
            if (a[i] > right_min)
                ans++;
            right_min = min(right_min, a[i]);
        }
        cout << ans << endl;
    }
}
```
[1213C - Book Reading](../problems/C._Book_Reading.md "Codeforces Round 582 (Div. 3)")

 **Tutorial**
### [1213C - Book Reading](../problems/C._Book_Reading.md "Codeforces Round 582 (Div. 3)")

Let $k = \lfloor\frac{n}{m}\rfloor$ be the number of integers from $1$ to $n$ divisible by $m$. We can notice that because we write down only the last digit of each number divisible by $m$ then the length of the "cycle" of digits does not exceed $10$. In fact, we can always suppose that it is $10$ because $i \cdot m \% 10 = (10 + i) \cdot m \% 10$ for all $i$ from $0$ to $9$. So let $cycle_i = m * (i + 1) \% 10$ for all $i$ from $0$ to $9$. Then the answer is $\lfloor\frac{k}{10}\rfloor \cdot \sum\limits_{i=0}^{9} cycle_i + \sum\limits_{i=0}^{k \% 10} cycle_i$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int q;
    cin >> q;
    forn(i, q) {
        long long n, m;
        cin >> n >> m;
        n = n / m;
        vector<int> digits(10);
        forn(i, 10)
            digits[i] = ((i + 1) * m) % 10;
        long long sum = 0;
        forn(i, n % 10)
            sum += digits[i];
        cout << sum + n / 10 * accumulate(digits.begin(), digits.end(), 0LL) << endl;
    }
}
```
[1213D1 - Equalizing by Division (easy version)](../problems/D1._Equalizing_by_Division_(easy_version).md "Codeforces Round 582 (Div. 3)")

 **Tutorial**
### [1213D1 - Equalizing by Division (easy version)](../problems/D1._Equalizing_by_Division_(easy_version).md "Codeforces Round 582 (Div. 3)")

Let $x$ be the number such that after some sequence of moves there will be at least $k$ elements $x$ in the array. We can see that there is always $O(n \log n)$ possible candidates because all values $x$ are among all possible values of $\lfloor\frac{a_i}{2^m}\rfloor$ for some $m$ from $0$ to $18$. So we need to check each candidate separately and try to update the answer with it. How to do this?

Let the current number we trying to obtain is $x$. Then let's iterate over all $a_i$ in any order. Let $y$ be the current value of $a_i$. Let's divide it by $2$ while its value is greater than $x$ and carry the number of divisions we made $cur$. If after all divisions $y=x$ then let's remember the value of $cur$ in some array $cnt$. If after iterating over all $n$ elements of $a$ the size of $cnt$ is greater than or equal to $k$ then let's sort it and update the answer with the sum of $k$ smallest values of $cnt$.

Time complexity: $O(n^2 \log^2max(a_i) \log(n \log max(a_i)))$ or $O(n^2 \log^2max(a_i))$, depends on sorting method.

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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	vector<int> poss;
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		while (x > 0) {
			poss.push_back(x);
			x /= 2;
		}
	}
	
	int ans = 1e9;
	for (auto res : poss) {
		vector<int> cnt;
		for (int i = 0; i < n; ++i) {
			int x = a[i];
			int cur = 0;
			while (x > res) {
				x /= 2;
				++cur;
			}
			if (x == res) {
				cnt.push_back(cur);
			}
		}
		if (int(cnt.size()) < k) continue;
		sort(cnt.begin(), cnt.end());
		ans = min(ans, accumulate(cnt.begin(), cnt.begin() + k, 0));
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1213D2 - Equalizing by Division (hard version)](../problems/D2._Equalizing_by_Division_(hard_version).md "Codeforces Round 582 (Div. 3)")

 **Tutorial**
### [1213D2 - Equalizing by Division (hard version)](../problems/D2._Equalizing_by_Division_(hard_version).md "Codeforces Round 582 (Div. 3)")

In this problem we need to write almost the same solution as in the previous one (easy version) but faster. Observe that we calculate the value of $\lfloor\frac{a_i}{2^m}\rfloor$ too many times. Let $vals_x$ for all $x$ from $1$ to $2 \cdot 10^5$ be the array of numbers of divisions we need to obtain $x$ from every possible $a_i$ from which we can. We can calculate these arrays in time $O(n \log n)$. How? Let's iterate over all $a_i$ and divide it by $2$ while it is positive (and carry the number of divisions $cur$). Then let's add to the array $vals_{a_i}$ the number $cur$ before each division.

Then we can see that we obtain the array $cnt$ from the tutorial of the previous problem for each $x$ from $1$ to $2 \cdot 10^5$. Let's iterate over all possible values of $x$ and try to update the answer with the sum of $k$ smallest values of $vals_x$ if there is at least $k$ elements in this array.

Time complexity: $O(n \log n \log(n \log n))$ or $O(n \log n)$, depends on sorting method.

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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	vector<vector<int>> vals(200 * 1000 + 11);
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		int cur = 0;
		while (x > 0) {
			vals[x].push_back(cur);
			x /= 2;
			++cur;
		}
	}
	
	int ans = 1e9;
	for (int i = 0; i <= 200 * 1000; ++i) {
		sort(vals[i].begin(), vals[i].end());
		if (int(vals[i].size()) < k) continue;
		ans = min(ans, accumulate(vals[i].begin(), vals[i].begin() + k, 0));
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1213E - Two Small Strings](../problems/E._Two_Small_Strings.md "Codeforces Round 582 (Div. 3)")

 **Tutorial**
### [1213E - Two Small Strings](../problems/E._Two_Small_Strings.md "Codeforces Round 582 (Div. 3)")

We can check the following solution by stress-testing (or maybe prove it somehow): let's iterate over all possible permutations of the string "abc". Let the first character of the current permutation be $c_1$, the second one be $c_2$ and the third one be $c_3$. Then let's add the following two candidates to the answer: "c_1 c_2 c_3 c_1 c_2 c_3 ... c_1 c_2 c_3" (the string consisting of $n$ copies of "c_1 c_2 c_3") and "c_1 ... c_1 c_2 ... c_2 c_3 ... c_3" (exactly $n$ copies of $c_1$ then exactly $n$ copies of $c_2$ and exactly $n$ copies of $c_3$). Then the answer will be among these $12$ strings and we can check each of them naively.

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
	string s, t;
	cin >> n >> s >> t;
	string abc = "abc";
	vector<string> res;
	do {
		string cur;
		for (int i = 0; i < n; ++i) cur += abc;
		res.push_back(cur);
		res.push_back(string(n, abc[0]) + string(n, abc[1]) + string(n, abc[2]));
	} while (next_permutation(abc.begin(), abc.end()));
	
	for (auto str : res) {
		if (str.find(s) == string::npos && str.find(t) == string::npos) {
			cout << "YES" << endl << str << endl;
			return 0;
		}
	}
	
	assert(false);
	cout << "NO" << endl;
	
	return 0;
}
```
[1213F - Unstable String Sort](../problems/F._Unstable_String_Sort.md "Codeforces Round 582 (Div. 3)")

 **Tutorial**
### [1213F - Unstable String Sort](../problems/F._Unstable_String_Sort.md "Codeforces Round 582 (Div. 3)")

Because if we write down all characters of s in order of both permutations and this string will be sorted, it is obvious that these two strings are equal. Let's try the maximum possible number of distinct characters and then replace extra characters with 'z'. How to find the maximum number of distinct characters?

Let's iterate over all values of p (and q) in order from left to right. If we staying at the position i now, let's add to the set vals1 the value pi and to the set vals2 the value qi. And when these sets become equal the first time, let's say that the block of positions i such that values pi are in the set right now, have the same letter, and then clear both sets. We can see that this segment of positions is the minimum by inclusion set that can contain equal letters. We don't need to compare sets naively and clear them naively, you can see implementation details in author's solution.

If the number of such segments is less than k then the answer is "NO", otherwise the answer is "YES" and we can fill the string s with letters in order of these segments (if the segment is [l;r] then all characters of s with indices pl,pl+1,…,pr has the same letter, the first segment has the letter 'a', the second one has the letter 'b', and so on, all segments after 25-th has the letter 'z').

Time complexity: O(nlogn).

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
	vector<int> p1(n), p2(n);
	for (int i = 0; i < n; ++i) {
		cin >> p1[i];
		--p1[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> p2[i];
		--p2[i];
	}
	
	set<int> vals1, vals2;
	vector<int> rb;
	for (int i = 0; i < n; ++i) {
		if (vals2.count(p1[i])) {
			vals2.erase(p1[i]);
		} else {
			vals1.insert(p1[i]);
		}
		if (vals1.count(p2[i])) {
			vals1.erase(p2[i]);
		} else {
			vals2.insert(p2[i]);
		}
		if (vals1.empty() && vals2.empty()) {
			rb.push_back(i);
		}
	}
	
	if (int(rb.size()) < k) {
		cout << "NO" << endl;
	} else {
		string s(n, ' ');
		int l = 0;
		for (int it = 0; it < int(rb.size()); ++it) {
			int r = rb[it];
			char c = 'a' + min(it, 25);
			for (int i = l; i <= r; ++i) {
				s[p1[i]] = c;
			}
			l = r + 1;
		}
		cout << "YES" << endl << s << endl;
	}
	
	return 0;
}
```
[1213G - Path Queries](../problems/G._Path_Queries.md "Codeforces Round 582 (Div. 3)")

 **Tutorial**
### [1213G - Path Queries](../problems/G._Path_Queries.md "Codeforces Round 582 (Div. 3)")

Let's carry the value $res$ that means the answer for the current set of edges. Initially it is $0$. Let's sort all edges by their weight and all queries by their weight also (both in non-decreasing order).

Let's merge components of the tree using DSU (disjoint set union). We need to carry sizes of components also (it is easy if we use DSU). Then let's iterate over all queries in order of non-decreasing their weights. If the current query has weight $cw$ then let's merge all components connected by edges with weight $w_i \le cw$. When we merge two components with sizes $s_1$ and $s_2$, the answer changes like that: $res := res - \binom{s_1}{2} - \binom{s_2}{2} + \binom{s_1 + s_2}{2}$. The value $\binom{x}{2}$ equals to $\frac{x(x-1)}{2}$. It is so because we subtract all old paths corresponding to these components and add all new paths in the obtained component. So the answer for the current query will be $res$ after all required merges.

Time complexity: $O(n \log n + m \log m)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> p, rk;

int getp(int v) {
	if (v == p[v]) return v;
	return p[v] = getp(p[v]);
}

long long res;

long long get(int cnt) {
	return cnt * 1ll * (cnt - 1) / 2;
}

void merge(int u, int v) {
	u = getp(u);
	v = getp(v);
	
	if (rk[u] < rk[v]) swap(u, v);
	
	res -= get(rk[u]);
	res -= get(rk[v]);
	
	rk[u] += rk[v];
	
	res += get(rk[u]);
	
	p[v] = u;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	
	res = 0;
	p = rk = vector<int>(n, 1);
	iota(p.begin(), p.end(), 0);
	
	vector<pair<int, pair<int, int>>> e(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		cin >> e[i].second.first >> e[i].second.second >> e[i].first;
		--e[i].second.first;
		--e[i].second.second;
	}
	
	vector<pair<int, int>> q(m);
	vector<long long> ans(m);
	for (int i = 0; i < m; ++i) {
		cin >> q[i].first;
		q[i].second = i;
	}
	
	sort(e.begin(), e.end());
	sort(q.begin(), q.end());
	
	int pos = 0;
	for (int i = 0; i < m; ++i) {
		while (pos < n - 1 && e[pos].first <= q[i].first) {
			int u = e[pos].second.first;
			int v = e[pos].second.second;
			merge(u, v);
			++pos;
		}
		ans[q[i].second] = res;
	}
	
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}
```
