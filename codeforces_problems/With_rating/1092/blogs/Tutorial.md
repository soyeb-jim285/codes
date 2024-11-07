# Tutorial

[1092A - Uniform String](../problems/A._Uniform_String.md "Codeforces Round 527 (Div. 3)")

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
		int n, k;
		cin >> n >> k;
		for (int j = 0; j < n; ++j) {
			cout << char('a' + j % k);
		}
		cout << endl;
	}
	
	return 0;
}
```
[1092B - Teams Forming](../problems/B._Teams_Forming.md "Codeforces Round 527 (Div. 3)")

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
	int res = 0;
	for (int i = 0; i < n; i += 2) {
		res += a[i + 1] - a[i];
	}
	
	cout << res << endl;
	
	return 0;
}
```
[1092C - Prefixes and Suffixes](../problems/C._Prefixes_and_Suffixes.md "Codeforces Round 527 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v;

string res;

bool check(const string &pref, const string &suf) {
	string s = pref + suf.substr(n - 2);
	multiset<string> vv, sPref, sSuf;
	for (int i = 0; i < n - 1; ++i) {
		sPref.insert(s.substr(0, n - i - 1));
		vv.insert(s.substr(0, n - i - 1));
		sSuf.insert(s.substr(i + 1));
		vv.insert(s.substr(i + 1));
	}
	if (vv == multiset<string>(v.begin(), v.end())) {
		for (int i = 0; i < 2 * n - 2; ++i) {
			if (sPref.count(v[i])) {
				res += 'P';
				sPref.erase(sPref.find(v[i]));
			} else if (sSuf.count(v[i])) {
				res += 'S';
				sSuf.erase(sSuf.find(v[i]));
			} else {
				assert(false);
			}
		}
		return true;
	}
	return false;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n;
	v = vector<string>(2 * n - 2);
	vector<string> big;
	for (int i = 0; i < 2 * n - 2; ++i) {
		cin >> v[i];
		if (int(v[i].size()) == n - 1) {
			big.push_back(v[i]);
		}
	}
	
	if (check(big[0], big[1])) {
		cout << res << endl;
	} else {
		check(big[1], big[0]);
		cout << res << endl;
	}
	
	return 0;
}
```
[1092D1 - Great Vova Wall (Version 1)](../problems/D1._Great_Vova_Wall_(Version_1).md "Codeforces Round 527 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution 1**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;

int n;
int a[N];

int main() {
	scanf("%d", &n);
	forn(i, n){
		scanf("%d", &a[i]);
		a[i] &= 1;
	}
	
	vector<int> st;
	forn(i, n){
		if (!st.empty() && a[i] == st.back())
			st.pop_back();
		else
			st.push_back(a[i]);
	}
	
	puts(st.size() <= 1 ? "YES" : "NO");
	return 0;
}
```
 **Solution 2**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;

int n;
int a[N];

int main() {
	scanf("%d", &n);
	forn(i, n){
		scanf("%d", &a[i]);
		a[i] &= 1;
	}
	
	set<pair<int, int>> seg, even;
	forn(i, n){
		int j = i;
		while (j + 1 < n && a[j + 1] == a[i]) ++j;
		seg.insert({i, j});
		if ((j - i + 1) % 2 == 0)
			even.insert({i, j});
		i = j;
	}
	
	while (seg.size() > 1 && !even.empty()){
		auto cur = *even.begin();
		even.erase(cur);
		seg.erase(cur);
		auto it = seg.lower_bound(cur);
		if (it != seg.end()){
			cur.second = it->second;
			if ((it->second - it->first + 1) % 2 == 0)
				even.erase(*it);
			seg.erase(it);
		}
		it = seg.lower_bound(cur);
		if (it != seg.begin()){
			--it;
			cur.first = it->first;
			if ((it->second - it->first + 1) % 2 == 0)
				even.erase(*it);
			seg.erase(it);
		}
		seg.insert(cur);
		if ((cur.second - cur.first + 1) % 2 == 0)
			even.insert(cur);
	}
	
	puts(seg.size() == 1 ? "YES" : "NO");
	return 0;
}
```
[1092D2 - Great Vova Wall (Version 2)](../problems/D2._Great_Vova_Wall_(Version_2).md "Codeforces Round 527 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 1000 * 1000 + 13;

int n;
int a[N];

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i]);
	vector<int> st;
	
	int mx = *max_element(a, a + n);
	
	forn(i, n){
		if (a[i] == mx) continue;
		
		int j = i - 1;
		while (j + 1 < n && a[j + 1] != mx){
			++j;
			if (!st.empty() && st.back() == a[j]){
				st.pop_back();
			}
			else if (st.empty() || st.back() > a[j]){
				st.push_back(a[j]);
			}
			else{
				puts("NO");
				return 0;
			}
		}
		
		if (!st.empty()){
			puts("NO");
			return 0;
		}
		
		i = j;
	}
	
	puts("YES");
	return 0;
}

```
[1092E - Minimal Diameter Forest](../problems/E._Minimal_Diameter_Forest.md "Codeforces Round 527 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;
const int INF = 1000000000;

int n, m;
vector<int> g[N];

int bfs(int x, int dist[N]){
	queue<int> q;
	q.push(x);
	dist[x] = 0;
	int lst = -1;
	while (!q.empty()){
		int v = q.front();
		q.pop();
		lst = v;
		for (auto u : g[v]) if (dist[u] > dist[v] + 1){
			dist[u] = dist[v] + 1;
			q.push(u);
		}
	}
	return lst;
}

int distx[N], disty[N];
bool used[N];
vector<int> cur;

void dfs(int v){
	used[v] = true;
	cur.push_back(v);
	for (auto u : g[v]) if (!used[u])
		dfs(u);
}

int main() {
	scanf("%d%d", &n, &m);
	forn(i, m){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	forn(i, n) distx[i] = disty[i] = INF;
	
	vector<pair<int, int>> comps;
	forn(i, n) if (!used[i]){
		cur.clear();
		dfs(i);
		int x = bfs(i, distx);
		int y = bfs(x, disty);
		for (auto v : cur) distx[v] = INF;
		bfs(y, distx);
		int d = disty[y], center;
		for (auto v : cur) if (distx[v] == d / 2 && disty[v] == d - d / 2)
			center = v;
		comps.push_back({d, center});
	}
	
	vector<pair<int, int>> ans;
	nth_element(comp.begin(), comp.end() - 1, comp.end());
	forn(i, int(comps.size()) - 1){
		g[comps[i].second].push_back(comps.back().second);
		g[comps.back().second].push_back(comps[i].second);
		ans.push_back({comps[i].second, comps.back().second});
	}
	
	forn(i, n) distx[i] = disty[i] = INF;
	int y = bfs(bfs(comps.back().second, distx), disty);
	
	printf("%dn", disty[y]);
	for (auto it : ans)
		printf("%d %dn", it.first + 1, it.second + 1);
	return 0;
}

```
[1092F - Tree with Maximum Cost](../problems/F._Tree_with_Maximum_Cost.md "Codeforces Round 527 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

long long res, ans;

vector<int> a;
vector<long long> sum;
vector<vector<int>> g;

void dfs(int v, int p = -1, int h = 0) {
	res += h * 1ll * a[v];
	sum[v] = a[v];
	
	for (auto to : g[v]) {
		if (to == p) {
			continue;
		}
		dfs(to, v, h + 1);
		sum[v] += sum[to];
	}
}

void go(int v, int p = -1) {
	ans = max(ans, res);
	
	for (auto to : g[v]) {
		if (to == p) {
			continue;
		}
		
		res -= sum[to];
		sum[v] -= sum[to];
		res += sum[v];
		sum[to] += sum[v];
		
		go(to, v);
		
		sum[to] -= sum[v];
		res -= sum[v];
		sum[v] += sum[to];
		res += sum[to];
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	a = vector<int>(n);
	sum = vector<long long>(n);
	g = vector<vector<int>>(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dfs(0);
	go(0);
	
	cout << ans << endl;
	
	return 0;
}
```
