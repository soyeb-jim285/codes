# Tutorial

[1165A - Remainder](../problems/A._Remainder.md "Codeforces Round 560 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, x, y;
	string s;
	cin >> n >> x >> y >> s;
	
	int ans = 0;
	for (int i = n - x; i < n; ++i) {
		if (i == n - y - 1) ans += s[i] != '1';
		else ans += s[i] != '0';
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1165B - Polycarp Training](../problems/B._Polycarp_Training.md "Codeforces Round 560 (Div. 3)")

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
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	int pos = 1;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= pos) ++pos;
	}
	
	cout << pos - 1 << endl;
	
	return 0;
}
```
[1165C - Good String](../problems/C._Good_String.md "Codeforces Round 560 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

string s;
int n;
string res;

int main()
{
	cin >> n >> s;
	for(int i = 0; i < n; i++)
	{
		if(res.size() % 2 == 0 || res.back() != s[i])
			res.push_back(s[i]);
	}
	if(res.size() % 2 == 1) res.pop_back();
	cout << n - int(res.size()) << endl << res << endl;
	return 0;
}
```
[1165D - Almost All Divisors](../problems/D._Almost_All_Divisors.md "Codeforces Round 560 (Div. 3)")

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
	for (int i = 0; i < t; ++i) {

		int n;
		cin >> n;
		vector<long long> d(n);
		for (int i = 0; i < n; ++i) {
			cin >> d[i];
		}
		sort(d.begin(), d.end());
		long long x = d[0] * d[n - 1];
		
		vector<long long> dd;
		for (int i = 2; i * 1ll * i <= x; ++i) {
			if (x % i == 0) {
				dd.push_back(i);
				if (i != x / i) {
					dd.push_back(x / i);
				}
			}
		}
		sort(dd.begin(), dd.end());
		
		if (dd == d) {
			cout << x << endl;
		} else {
			cout << -1 << endl;
		}
	}
	
	return 0;
}
```
[1165E - Two Arrays and Sum of Functions](../problems/E._Two_Arrays_and_Sum_of_Functions.md "Codeforces Round 560 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	
	sort(b.begin(), b.end());
	vector<pair<long long, int>> val(n);
	for (int i = 0; i < n; ++i) {
		val[i].first = (i + 1) * 1ll * (n - i) * a[i];
		val[i].second = i;
	}
	sort(val.rbegin(), val.rend());
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = (ans + (val[i].first % MOD * 1ll * b[i]) % MOD) % MOD;
	}
	cout << ans << endl;
	
	return 0;
}
```
[1165F1 - Microtransactions (easy version)](../problems/F1._Microtransactions_(easy_version).md "Codeforces Round 560 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> k;
vector<pair<int, int>> q(1001);

bool can(int day) {
	vector<int> lst(n, -1);
	for (int i = 0; i < m; ++i) {
		if (q[i].first <= day) {
			lst[q[i].second] = max(lst[q[i].second], q[i].first);
		}
	}
	vector<vector<int>> off(1001);
	for (int i = 0; i < n; ++i) {
		if (lst[i] != -1) {
			off[lst[i]].push_back(i);
		}
	}
	vector<int> need = k;
	int cur_money = 0;
	for (int i = 0; i <= day; ++i) {
		++cur_money;
		if (i > 1000) continue;
		for (auto it : off[i]) {
			if (cur_money >= need[it]) {
				cur_money -= need[it];
				need[it] = 0;
			} else {
				need[it] -= cur_money;
				cur_money = 0;
				break;
			}
		}
	}
	return accumulate(need.begin(), need.end(), 0) * 2 <= cur_money;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m;
	k = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		cin >> k[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> q[i].first >> q[i].second;
		--q[i].first;
		--q[i].second;
	}
	
	for (int l = 0; l <= 2000; ++l) {
		if (can(l)) {
			cout << l + 1 << endl;
			return 0;
		}
	}
	
	assert(false);
	
	return 0;
}
```
[1165F2 - Microtransactions (hard version)](../problems/F2._Microtransactions_(hard_version).md "Codeforces Round 560 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> k;
vector<pair<int, int>> q(200001);

bool can(int day) {
	vector<int> lst(n, -1);
	for (int i = 0; i < m; ++i) {
		if (q[i].first <= day) {
			lst[q[i].second] = max(lst[q[i].second], q[i].first);
		}
	}
	vector<vector<int>> off(200001);
	for (int i = 0; i < n; ++i) {
		if (lst[i] != -1) {
			off[lst[i]].push_back(i);
		}
	}
	vector<int> need = k;
	int cur_money = 0;
	for (int i = 0; i <= day; ++i) {
		++cur_money;
		if (i > 200000) continue;
		for (auto it : off[i]) {
			if (cur_money >= need[it]) {
				cur_money -= need[it];
				need[it] = 0;
			} else {
				need[it] -= cur_money;
				cur_money = 0;
				break;
			}
		}
	}
	return accumulate(need.begin(), need.end(), 0) * 2 <= cur_money;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m;
	k = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		cin >> k[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> q[i].first >> q[i].second;
		--q[i].first;
		--q[i].second;
	}
	
	int l = 0, r = 400000;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (can(mid)) r = mid;
		else l = mid;
	}
	
	for (int i = l; i <= r; ++i) {
		if (can(i)) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	
	assert(false);
	
	return 0;
}
```
