# Tutorial

[1374A - Required Remainder](../problems/A._Required_Remainder.md "Codeforces Round 653 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1374A - Required Remainder](../problems/A._Required_Remainder.md "Codeforces Round 653 (Div. 3)")

There are two cases in this problem. If we try to maximize the answer, we need to consider only two integers: $n - n \bmod x + y$ and $n - n \bmod x - (x - y)$. Of course, the first one is better (we get rid of the existing remainder and trying to add $y$ to this number). If it's too big, then we can and need to take the second one (this number is just the first one but decreased by $x$). The answer can be always found between these numbers.

Time complexity: $O(1)$.

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
		int x, y, n;
		cin >> x >> y >> n;
		if (n - n % x + y <= n) {
			cout << n - n % x + y << endl;
		} else {
			cout << n - n % x - (x - y) << endl;
		}
	}
	
	return 0;
}
```
[1374B - Multiply by 2, divide by 6](../problems/B._Multiply_by_2,_divide_by_6.md "Codeforces Round 653 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1374B - Multiply by 2, divide by 6](../problems/B._Multiply_by_2,_divide_by_6.md "Codeforces Round 653 (Div. 3)")

If the number consists of other primes than $2$ and $3$ then the answer is -1. Otherwise, let $cnt_2$ be the number of twos in the factorization of $n$ and $cnt_3$ be the number of threes in the factorization of $n$. If $cnt_2 > cnt_3$ then the answer is -1 because we can't get rid of all twos. Otherwise, the answer is $(cnt_3 - cnt_2) + cnt_3$.

Time complexity: $O(\log{n})$.

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
		int cnt2 = 0, cnt3 = 0;
		while (n % 2 == 0) {
			n /= 2;
			++cnt2;
		}
		while (n % 3 == 0) {
			n /= 3;
			++cnt3;
		}
		if (n == 1 && cnt2 <= cnt3) {
			cout << 2 * cnt3 - cnt2 << endl;
		} else {
			cout << -1 << endl;
		}
	}
	
	return 0;
}
```
[1374C - Move Brackets](../problems/C._Move_Brackets.md "Codeforces Round 653 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**Tutorial is loading... **Solution**
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
		int ans = 0;
		int bal = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '(') ++bal;
			else {
				--bal;
				if (bal < 0) {
					bal = 0;
					++ans;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1374D - Zero Remainder Array](../problems/D._Zero_Remainder_Array.md "Codeforces Round 653 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1374D - Zero Remainder Array](../problems/D._Zero_Remainder_Array.md "Codeforces Round 653 (Div. 3)")

Firstly, we can understand that during each full cycle of $x$ from $0$ to $k-1$ we can fix each remainder only once. Notice that when we add some $x$ then we fix the remainder $k-x$ (and we don't need to fix elements which are already divisible by $k$). So, let $cnt_i$ be the number of such elements for which the condition $k - a_i \bmod k = i$ holds (i.e. the number of such elements that we can fix if we add the value $i \bmod k$ to them). We can count this using some logarithmic data structure (like std::map in C++).

So, what's the number of full cycles? It equals to the amount of most frequent element in $cnt$ minus one. So, the answer is at least $k \cdot (max(cnt) - 1)$. And there can be one last cycle which will be incomplete. So what is the remanining number of moves? It equals to the maximum possible $i$ among all $cnt_i = max(cnt)$. So if $key$ is the maximum such $i$ that $cnt_{key} = max(cnt)$ then the answer is $k \cdot (cnt_{key} - 1) + key + 1$.

Time complexity: $O(n \log{n})$.

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
		map<int, int> cnt;
		int mx = 0;
		for (auto &it : a) {
			if (it % k == 0) continue;
			++cnt[k - it % k];
			mx = max(mx, cnt[k - it % k]);
		}
		long long ans = 0;
		for (auto [key, value] : cnt) {
			if (value == mx) {
				ans = k * 1ll * (value - 1) + key + 1;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1374E1 - Reading Books (easy version)](../problems/E1._Reading_Books_(easy_version).md "Codeforces Round 653 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1374E1 - Reading Books (easy version)](../problems/E1._Reading_Books_(easy_version).md "Codeforces Round 653 (Div. 3)")

Let's divide all books into four groups:

* 00 — both Alice and Bob doesn't like these books;
* 01 — only Alice likes these books;
* 10 — only Bob likes these books;
* 11 — both ALice and Bob like these books.

Obviously, 00-group is useless now. So, how to solve the problem? Let's iterate over the number of books we take from 11-group. Let it be $cnt$. Then we obviously need to take exactly $k-cnt$ books from groups 01 and 10. Among all books in these three groups we have to choose the cheapest ones. To calculate sum of times in each group fast enought, we can sort each group independently and implement prefix sums on these arrays. If $k-cnt$ is less than zero or greater than the size of 01 or 10-group for each possible $cnt$ then the answer is -1.

And don't forget that the answer can be up to $2 \cdot 10^9$.

Time complexity: $O(n \log{n})$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 1;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	vector<int> times[4];
	vector<int> sums[4];
	for (int i = 0; i < n; ++i) {
		int t, a, b;
		cin >> t >> a >> b;
		times[a * 2 + b].push_back(t);
	}
	for (int i = 0; i < 4; ++i) {
		sort(times[i].begin(), times[i].end());
		sums[i].push_back(0);
		for (auto it : times[i]) {
			sums[i].push_back(sums[i].back() + it);
		}
	}
	
	int ans = INF;
	for (int cnt = 0; cnt < min(k + 1, int(sums[3].size())); ++cnt) {
		if (k - cnt < int(sums[1].size()) && k - cnt < int(sums[2].size())) {
			ans = min(ans, sums[3][cnt] + sums[1][k - cnt] + sums[2][k - cnt]);
		}
	}
	
	if (ans == INF) ans = -1;
	cout << ans << endl;
	
	return 0;
}
```
[1374E2 - Reading Books (hard version)](../problems/E2._Reading_Books_(hard_version).md "Codeforces Round 653 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 1;

#define size(a) int((a).size())

void updateSt(set<pair<int, int>> &st, set<pair<int, int>> &fr, int &sum, int need) {
	need = max(need, 0);
	while (true) {
		bool useful = false;
		while (size(st) > need) {
			sum -= st.rbegin()->first;
			fr.insert(*st.rbegin());
			st.erase(prev(st.end()));
			useful = true;
		}
		while (size(st) < need && size(fr) > 0) {
			sum += fr.begin()->first;
			st.insert(*fr.begin());
			fr.erase(fr.begin());
			useful = true;
		}
		while (!st.empty() && !fr.empty() && fr.begin()->first < st.rbegin()->first) {
			sum -= st.rbegin()->first;
			sum += fr.begin()->first;
			fr.insert(*st.rbegin());
			st.erase(prev(st.end()));
			st.insert(*fr.begin());
			fr.erase(fr.begin());
			useful = true;
		}
		if (!useful) break;
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> times[4];
	vector<int> sums[4];
	for (int i = 0; i < n; ++i) {
		int t, a, b;
		cin >> t >> a >> b;
		times[a * 2 + b].push_back({t, i});
	}
	for (int i = 0; i < 4; ++i) {
		sort(times[i].begin(), times[i].end());
		sums[i].push_back(0);
		for (auto it : times[i]) {
			sums[i].push_back(sums[i].back() + it.first);
		}
	}
	
	int ans = INF;
	int pos = INF;
	set<pair<int, int>> st;
	set<pair<int, int>> fr;
	int sum = 0;
	vector<int> res;
	for (int iter = 0; iter < 2; ++iter) {
		st.clear();
		fr.clear();
		sum = 0;
		int start = 0;
		while (k - start >= size(sums[1]) || k - start >= size(sums[2]) || m - start - (k - start) * 2 < 0) {
			++start;
		}
		if (start >= size(sums[3])) {
			cout << -1 << endl;
			return 0;
		}
		int need = m - start - (k - start) * 2;
		for (int i = 0; i < 3; ++i) {
			for (int p = size(times[i]) - 1; p >= (i == 0 ? 0 : k - start); --p) {
				fr.insert(times[i][p]);
			}
		}
		updateSt(st, fr, sum, need);
		for (int cnt = start; cnt < (iter == 0 ? size(sums[3]) : pos); ++cnt) {
			if (k - cnt >= 0) {	
				if (cnt + (k - cnt) * 2 + size(st) == m) {
					if (ans > sums[3][cnt] + sums[1][k - cnt] + sums[2][k - cnt] + sum) {
						ans = sums[3][cnt] + sums[1][k - cnt] + sums[2][k - cnt] + sum;
						pos = cnt + 1;
					}
				}
			} else {
				if (cnt + size(st) == m) {
					if (ans > sums[3][cnt] + sum) {
						ans = sums[3][cnt] + sum;
						pos = cnt + 1;
					}
				}
			}
			if (iter == 1 && cnt + 1 == pos) break;
			need -= 1;
			if (k - cnt > 0) {
				need += 2;
				fr.insert(times[1][k - cnt - 1]);
				fr.insert(times[2][k - cnt - 1]);
			}
			updateSt(st, fr, sum, need);
		}
		if (iter == 1) {
			for (int i = 0; i + 1 < pos; ++i) res.push_back(times[3][i].second);
			for (int i = 0; i <= k - pos; ++i) {
				res.push_back(times[1][i].second);
				res.push_back(times[2][i].second);
			}
			for (auto [value, position] : st) res.push_back(position);
		}
	}
	
	cout << ans << endl;
	for (auto it : res) cout << it + 1 << " ";
	cout << endl;
	
	return 0;
}
```
[1374F - Cyclic Shifts Sorting](../problems/F._Cyclic_Shifts_Sorting.md "Codeforces Round 653 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	auto make = [](vector<int> &a, int pos) {
		swap(a[pos + 1], a[pos + 2]);
		swap(a[pos], a[pos + 1]);
	};

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<pair<int, int>> res(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			res[i] = { a[i], i };
		}
		sort(res.begin(), res.end());
		for (int i = 0; i < n; ++i) {
			a[res[i].second] = i;
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				cnt += a[j] < a[i];
			}
		}
		if (cnt & 1) {
			for (int i = 0; i < n - 1; ++i) {
				if (res[i].first == res[i + 1].first) {
					swap(a[res[i].second], a[res[i + 1].second]);
					break;
				}
			}
		}
		vector<int> ans;
		for (int i = 0; i < n - 2; ++i) {
			int pos = min_element(a.begin() + i, a.end()) - a.begin();
			while (pos > i + 1) {
				make(a, pos - 2);
				ans.push_back(pos - 2);
				pos -= 2;
			}
			if (pos != i) {
				make(a, i);
				make(a, i);
				ans.push_back(i);
				ans.push_back(i);
				pos = i;
			}
		}
		for (int i = 0; i < 3; ++i) {
			if (is_sorted(a.begin(), a.end())) {
				break;
			}
			make(a, n - 3);
			ans.push_back(n - 3);
		}
		if (!is_sorted(a.begin(), a.end())) {
			cout << -1 << endl;
		} else {
			cout << ans.size() << endl;
			for (auto it : ans) cout << it + 1 << " ";
			cout << endl;
		}
	}
	
	return 0;
}
```
