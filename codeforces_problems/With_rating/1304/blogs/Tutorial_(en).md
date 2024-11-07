# Tutorial_(en)

[1304A — Two Rabbits](../problems/A._Two_Rabbits.md)

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		cout << ((y - x) % (a + b) == 0 ? (y - x) / (a + b) : -1) << endl;
	}
}
```
[1304B — Longest Palindrome](../problems/B._Longest_Palindrome.md)

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
string s[MAX_N];

int main()
{
	set<string> dict;
	int n, m, i;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> s[i];
		dict.insert(s[i]);
	}
	vector<string> left, right;
	string mid;
	for (i = 0; i < n; i++)
	{
		string t = s[i];
		reverse(t.begin(), t.end());
		if (t == s[i])
			mid = t;
		else if (dict.find(t) != dict.end())
		{
			left.push_back(s[i]);
			right.push_back(t);
			dict.erase(s[i]);
			dict.erase(t);
		}
	}
	cout << left.size() * m * 2 + mid.size() << endl;
	for (string x : left)
		cout << x;
	cout << mid;
	reverse(right.begin(), right.end());
	for (string x : right)
		cout << x;
	cout << endl;
}
```
[1304C — Air Conditioner](../problems/C._Air_Conditioner.md)

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;

int t[MAX_N], lo[MAX_N], hi[MAX_N];

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m, i;
		cin >> n >> m;
		for (i = 0; i < n; i++)
			cin >> t[i] >> lo[i] >> hi[i];
		int prev = 0;
		int mn = m, mx = m;
		bool flag = true;
		for (i = 0; i < n; i++)
		{
			mx += t[i] - prev;
			mn -= t[i] - prev;
			if (mx < lo[i] || mn > hi[i])
			{
				flag = false;
				break;
			}
			mx = min(mx, hi[i]);
			mn = max(mn, lo[i]);
			prev = t[i];
		}
		if (flag)
			cout << "YESn";
		else
			cout << "NOn";
	}
}
```
[1304D — Shortest and Longest LIS](../problems/D._Shortest_and_Longest_LIS.md)

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;
int ans[MAX_N + 5];

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, i, j;
		string s;
		cin >> n >> s;

		int num = n, last = 0;
		for (i = 0; i < n; i++)
		{
			if (i == n - 1 || s[i] == '>')
			{
				for (j = i; j >= last; j--)
					ans[j] = num--;
				last = i + 1;
			}
		}
		for (i = 0; i < n; i++)
			cout << ans[i] << (i == n - 1 ? 'n' : ' ');

		num = 1, last = 0;
		for (i = 0; i < n; i++)
		{
			if (i == n - 1 || s[i] == '<')
			{
				for (j = i; j >= last; j--)
					ans[j] = num++;
				last = i + 1;
			}
		}
		for (i = 0; i < n; i++)
			cout << ans[i] << (i == n - 1 ? 'n' : ' ');
	}
}
```
[1304E — 1-Trees and Queries](../problems/E._1-Trees_and_Queries.md)

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;
const int LIM = 17;
const int INF = (int)1e9 + 7;

vector<int> adj[MAX_N + 5];
int depth[MAX_N + 5];
int par[MAX_N + 5][LIM + 1];

void build(int cur, int p)
{
	int i;

	depth[cur] = depth[p] + 1;
	par[cur][0] = p;
	for (i = 1; i <= LIM; i++)
		par[cur][i] = par[par[cur][i - 1]][i - 1];

	for (int x : adj[cur])
		if (x != p)
			build(x, cur);
}

int lca_len(int a, int b)
{
	int i, len = 0;

	if (depth[a] > depth[b])
		swap(a, b);
	for (i = LIM; i >= 0; i--)
	{
		if (depth[par[b][i]] >= depth[a])
		{
			b = par[b][i];
			len += (1 << i);
		}
	}
	
	if (a == b)
		return len;
	for (i = LIM; i >= 0; i--)
	{
		if (par[a][i] != par[b][i])
		{
			a = par[a][i];
			b = par[b][i];
			len += (1 << (i + 1));
		}
	}
	return len + 2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q, i;
	cin >> n;
	
	for (i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	build(1, 0);

	cin >> q;
	while (q--)
	{
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		int without = lca_len(a, b);
		int with = min(lca_len(a, x) + lca_len(y, b), lca_len(a, y) + lca_len(x, b)) + 1;
		int ans = INF;
		if (without % 2 == k % 2)
			ans = without;
		if (with % 2 == k % 2)
			ans = min(ans, with);
		cout << (ans <= k ? "YES" : "NO") << 'n';
	}
}
```
[1304F1 — Animal Observation (easy version)](../problems/F1._Animal_Observation_(easy_version).md)

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50;
const int MAX_M = 20000;
const int MAX_K = 20;

int animal[MAX_N + 5][MAX_M + 5];
int psum[MAX_N + 5][MAX_M + 5];
int lmax[MAX_N + 5][MAX_M + 5];
int rmax[MAX_N + 5][MAX_M + 5];
int dp[MAX_N + 5][MAX_M + 5];

inline int ps(int i, int j, int k)
{
	return psum[i][k] - psum[i][j - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j;

	int n, m, k;
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cin >> animal[i][j];
			psum[i][j] = psum[i][j - 1] + animal[i][j];
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m - k + 1; j++)
		{
			int p = ps(i, j, j + k - 1) + ps(i + 1, j, j + k - 1);
			if (i == 1)
			{
				dp[i][j] = p;
				continue;
			}
			int mx = 0;
			for (int x = max(1, j - k + 1); x <= min(m - k + 1, j + k - 1); x++)
				mx = max(mx, dp[i - 1][x] + p - ps(i, max(x, j), min(x + k - 1, j + k - 1)));
			dp[i][j] = mx;
			if (j > k)
				dp[i][j] = max(dp[i][j], lmax[i - 1][j - k] + p);
			if (j + k - 1 <= m - k)
				dp[i][j] = max(dp[i][j], rmax[i - 1][j + k] + p);
		}
		for (j = 1; j <= m - k + 1; j++)
			lmax[i][j] = max(lmax[i][j - 1], dp[i][j]);
		for (j = m - k + 1; j >= 1; j--)
			rmax[i][j] = max(rmax[i][j + 1], dp[i][j]);
	}

	cout << *max_element(dp[n] + 1, dp[n] + m + 1) << 'n';
}
```
[1304F2 — Animal Observation (hard version)](../problems/F2._Animal_Observation_(hard_version).md)

 **Tutorial**Tutorial is loading... **Solution: O(nmlogm)**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50;
const int MAX_M = 20000;
const int MAX_K = 20;

int animal[MAX_N + 5][MAX_M + 5];
int psum[MAX_N + 5][MAX_M + 5];
int dp[MAX_N + 5][MAX_M + 5];
int t[MAX_M * 4], lazy[MAX_M * 4];

void update_lazy(int i, int lo, int hi)
{
	if (lazy[i])
	{
		t[i] += lazy[i];
		if (lo != hi)
		{
			lazy[i * 2] += lazy[i];
			lazy[i * 2 + 1] += lazy[i];
		}
		lazy[i] = 0;
	}
}

int update(int i, int lo, int hi, int l, int r, int val)
{
	update_lazy(i, lo, hi);
	if (lo > r || hi < l)
		return t[i];
	if (l <= lo && hi <= r)
	{
		t[i] += val;
		if (lo != hi)
		{
			lazy[i * 2] += val;
			lazy[i * 2 + 1] += val;
		}
		return t[i];
	}
	int mid = (lo + hi) / 2;
	return t[i] = max(update(i * 2, lo, mid, l, r, val), update(i * 2 + 1, mid + 1, hi, l, r, val));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j;

	int n, m, k;
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cin >> animal[i][j];
			psum[i][j] = psum[i][j - 1] + animal[i][j];
		}
	}

	int mm = m - k + 1;

	for (i = 1; i <= mm; i++)
		dp[1][i] = psum[1][i + k - 1] - psum[1][i - 1] + psum[2][i + k - 1] - psum[2][i - 1];
	for (i = 2; i <= n; i++)
	{
		memset(t, 0, sizeof t);
		memset(lazy, 0, sizeof lazy);
		for (j = 1; j <= mm; j++)
			update(1, 1, mm, j, j, dp[i - 1][j]);
		for (j = 1; j <= k; j++)
			update(1, 1, mm, 1, j, -animal[i][j]);
		for (j = 1; j <= mm; j++)
		{
			dp[i][j] = t[1] + psum[i][j + k - 1] - psum[i][j - 1] + psum[i + 1][j + k - 1] - psum[i + 1][j - 1];
			if (j != mm)
			{
				update(1, 1, mm, max(1, j - k + 1), j, animal[i][j]);
				update(1, 1, mm, j + 1, j + k, -animal[i][j + k]);
			}
		}
	}

	cout << *max_element(dp[n] + 1, dp[n] + mm + 1) << endl;
}
```
 **Solution: O(nm)**
```cpp
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int MAX_N = 50;
const int MAX_M = 20000;
const int MAX_K = 20;

int n, m, k;

inline int ps(vvi &p, int i, int s, int e)
{
	if (s < 1)
		return p[i][e];
	return p[i][e] - p[i][s - 1];
}

void calc_overlapped(vvi &ar, vvi &p, vvi &dp, int i)
{
	int j;
	deque<pii> dq;
	for (j = 1; j <= m - k + 1; j++)
	{
		int num = dp[i - 1][j] - ps(p, i, j, j + k - 1);
		if (dq.size() && dq.front().second <= j - k)
			dq.pop_front();
		while (dq.size() && dq.back().first + ps(p, i, dq.back().second, j - 1) <= num)
			dq.pop_back();
		dq.push_back({ num, j });
		dp[i][j] = dq.front().first + ps(p, i, dq.front().second, j - 1) + ps(p, i, j, j + k - 1) + ps(p, i + 1, j, j + k - 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j;

	cin >> n >> m >> k;

	vvi init(n + 5, vi(m + 5, 0));
	vvi animal, animal_rev, psum, psum_rev, lmax, rmax, dp, dpl, dpr;
	animal = animal_rev = psum = psum_rev = lmax = rmax = dp = dpl = dpr = init;	

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cin >> animal[i][j];
			psum[i][j] = psum[i][j - 1] + animal[i][j];
			animal_rev[i][m - j + 1] = animal[i][j];
		}
		for (j = 1; j <= m; j++)
			psum_rev[i][j] = psum_rev[i][j - 1] + animal_rev[i][j];
	}

	deque<pii> dq;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m - k + 1; j++)
		{
			if (j > k)
				dp[i][j] = lmax[i - 1][j - k];
			if (j <= m - k * 2 + 1)
				dp[i][j] = max(dp[i][j], rmax[i - 1][j + k]);
			dp[i][j] += ps(psum, i, j, j + k - 1) + ps(psum, i + 1, j, j + k - 1);
		}

		calc_overlapped(animal, psum, dpl, i);
		calc_overlapped(animal_rev, psum_rev, dpr, i);

		for (j = 1; j <= m - k + 1; j++)
		{
			dp[i][j] = max({ dp[i][j], dpl[i][j], dpr[i][m - j - k + 2] });
			dpl[i][j] = dpr[i][m - j - k + 2] = dp[i][j];
		}
			
		for (j = 1; j <= m - k + 1; j++)
			lmax[i][j] = max(lmax[i][j - 1], dp[i][j]);
		for (j = m - k + 1; j >= 1; j--)
			rmax[i][j] = max(rmax[i][j + 1], dp[i][j]);
	}

	cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
}
```
