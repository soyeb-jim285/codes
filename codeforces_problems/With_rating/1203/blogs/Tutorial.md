# Tutorial

All ideas belong to [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

[1203A - Circle of Students](../problems/A._Circle_of_Students.md "Codeforces Round 579 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		vector<int> a(n);
		int pos = -1;
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
			if (a[j] == 1) pos = j;
		}
		bool okl = true, okr = true;
		for (int j = 1; j < n; ++j) {
			okl &= (a[(pos - j + n) % n] == j + 1);
			okr &= (a[(pos + j + n) % n] == j + 1);
		}
		if (okl || okr) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}
```
[1203B - Equal Rectangles](../problems/B._Equal_Rectangles.md "Codeforces Round 579 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		vector<int> a(4 * n);
		for (int j = 0; j < 4 * n; ++j) {
			cin >> a[j];
		}
		sort(a.begin(), a.end());
		int area = a[0] * a.back();
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			int lf = i * 2, rg = 4 * n - (i * 2) - 1;
			if (a[lf] != a[lf + 1] || a[rg] != a[rg - 1] || a[lf] * 1ll * a[rg] != area) {
				ok = false;
			}
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}
```
[1203C - Common Divisors](../problems/C._Common_Divisors.md "Codeforces Round 579 (Div. 3)")

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
	long long g = 0;
	for (int i = 0; i < n; ++i) {
		long long x;
		cin >> x;
		g = __gcd(g, x);
	}
	
	int ans = 0;
	for (int i = 1; i * 1ll * i <= g; ++i) {
		if (g % i == 0) {
			++ans;
			if (i != g / i) {
				++ans;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1203D1 - Remove the Substring (easy version)](../problems/D1._Remove_the_Substring_(easy_version).md "Codeforces Round 579 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	string s, t;
	cin >> s >> t;
	int ans = 0;
	for (int i = 0; i < int(s.size()); ++i) {
		for (int j = i; j < int(s.size()); ++j) {
			int pos = 0;
			for (int p = 0; p < int(s.size()); ++p) {
				if (i <= p && p <= j) continue;
				if (pos < int(t.size()) && t[pos] == s[p]) ++pos;
			}
			if (pos == int(t.size())) ans = max(ans, j - i + 1);
		}
	}
	cout << ans << endl;
	
	return 0;
}
```
[1203D2 - Remove the Substring (hard version)](../problems/D2._Remove_the_Substring_(hard_version).md "Codeforces Round 579 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	string s, t;
	cin >> s >> t;
	vector<int> rg(t.size());
	
	for (int i = int(t.size()) - 1; i >= 0; --i) {
		int pos = int(s.size()) - 1;
		if (i + 1 < int(t.size())) pos = rg[i + 1] - 1;
		while (s[pos] != t[i]) --pos;
		rg[i] = pos;
	}
	
	int ans = 0;
	int pos = 0;
	for (int i = 0; i < int(s.size()); ++i) {
		int rpos = int(s.size()) - 1;
		if (pos < int(t.size())) rpos = rg[pos] - 1;
		ans = max(ans, rpos - i + 1);
		if (pos < int(t.size()) && t[pos] == s[i]) ++pos;
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1203E - Boxers](../problems/E._Boxers.md "Codeforces Round 579 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	int lst = a[0] + 2;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int cur = -1;
		for (int dx = 1; dx >= -1; --dx) {
			if (a[i] + dx > 0 && a[i] + dx < lst) {
				cur = a[i] + dx;
				break;
			}
		}
		if (cur == -1) continue;
		++ans;
		lst = cur;
	}
	cout << ans << endl;
}
```
[1203F1 - Complete the Projects (easy version)](../problems/F1._Complete_the_Projects_(easy_version).md "Codeforces Round 579 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first + a.second > b.first + b.second;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, r;
	cin >> n >> r;
	vector<pair<int, int>> pos, neg;
	for (int i = 0; i < n; ++i) {
		pair<int, int> cur;
		cin >> cur.first >> cur.second;
		if (cur.second >= 0) pos.push_back(cur);
		else {
		    cur.first = max(cur.first, abs(cur.second));
		    neg.push_back(cur);
		}
	}
	
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end(), comp);
	
	int taken = 0;
	for (int i = 0; i < int(pos.size()); ++i) {
		if (r >= pos[i].first) {
			r += pos[i].second;
			++taken;
		}
	}
	
	vector<vector<int>> dp(neg.size() + 1, vector<int>(r + 1, 0));
	dp[0][r] = taken;
	for (int i = 0; i < int(neg.size()); ++i) {
		for (int cr = 0; cr <= r; ++cr) {
			if (cr >= neg[i].first && cr + neg[i].second >= 0) {
				dp[i + 1][cr + neg[i].second] = max(dp[i + 1][cr + neg[i].second], dp[i][cr] + 1);
			}
			dp[i + 1][cr] = max(dp[i + 1][cr], dp[i][cr]);
		}
	}
	
	int ans = 0;
	for (int cr = 0; cr <= r; ++cr) ans = max(ans, dp[int(neg.size())][cr]);
	cout << (ans == n ? "YES" : "NO") << endl;
	
	return 0;
}

```
[1203F2 - Complete the Projects (hard version)](../problems/F2._Complete_the_Projects_(hard_version).md "Codeforces Round 579 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first + a.second > b.first + b.second;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, r;
	cin >> n >> r;
	vector<pair<int, int>> pos, neg;
	for (int i = 0; i < n; ++i) {
		pair<int, int> cur;
		cin >> cur.first >> cur.second;
		if (cur.second >= 0) pos.push_back(cur);
		else {
		    cur.first = max(cur.first, abs(cur.second));
		    neg.push_back(cur);
		}
	}
	
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end(), comp);
	
	int taken = 0;
	for (int i = 0; i < int(pos.size()); ++i) {
		if (r >= pos[i].first) {
			r += pos[i].second;
			++taken;
		}
	}
	
	vector<vector<int>> dp(neg.size() + 1, vector<int>(r + 1, 0));
	dp[0][r] = taken;
	for (int i = 0; i < int(neg.size()); ++i) {
		for (int cr = 0; cr <= r; ++cr) {
			if (cr >= neg[i].first && cr + neg[i].second >= 0) {
				dp[i + 1][cr + neg[i].second] = max(dp[i + 1][cr + neg[i].second], dp[i][cr] + 1);
			}
			dp[i + 1][cr] = max(dp[i + 1][cr], dp[i][cr]);
		}
	}
	
	int ans = 0;
	for (int cr = 0; cr <= r; ++cr) ans = max(ans, dp[int(neg.size())][cr]);
	cout << ans << endl;
	
	return 0;
}

```
