# E_(en)

[1076A - Minimizing the String](../problems/A._Minimizing_the_String.md "Educational Codeforces Round 54 (Rated for Div. 2)")

 **Tutorial**
### [1076A - Minimizing the String](../problems/A._Minimizing_the_String.md "Educational Codeforces Round 54 (Rated for Div. 2)")

By the definition of lexicographical comparing we can see that if we can remove one character we always have to do it. Besides, we have to remove the character from the leftmost position $i$ such that $i < n$ and $s_i > s_{i + 1}$ or from the position $n$ if there is no such $i$.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	int pos = n - 1;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] > s[i + 1]) {
			pos = i;
			break;
		}
	}
	cout << s.substr(0, pos) + s.substr(pos + 1) << endl;
	return 0;
}
```
[1076B - Divisor Subtraction](../problems/B._Divisor_Subtraction.md "Educational Codeforces Round 54 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

long long get(long long n){
	for (long long i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return i;
	return n;
}

int main() {
	long long n;
	scanf("%lld", &n);
	long long cnt = 0;
	if (n % 2 != 0){
		n -= get(n);
		++cnt;
	}
	printf("%lldn", cnt + n / 2);
	return 0;
}
```
[1076C - Meme Problem](../problems/C._Meme_Problem.md "Educational Codeforces Round 54 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef double ld;
typedef pair<int, int> pt;

li d;

inline bool read() {
	if(!(cin >> d))
		return false;
	return true;
}

inline void solve() {
	if(d == 0) {
		cout << "Y " << 0.0 << " " << 0.0 << endl;
		return;
	}
	if(d < 4) {
		cout << "N" << endl;
		return;
	}
	
	ld D = sqrt(d * li(d - 4));
	ld a = (d + D) / 2.0;
	ld b = (d - D) / 2.0;
	
	cout << "Y " << a << " " << b << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	cout << fixed << setprecision(9);
	
	int tc = 1;
	assert(cin >> tc);
	
	while(tc--) {
		assert(read());
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
[1076D - Edge Deletion](../problems/D._Edge_Deletion.md "Educational Codeforces Round 54 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, int> > > g[300043];

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++)
	{
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		--x;
		--y;
		g[x].push_back(make_pair(y, make_pair(w, i)));
		g[y].push_back(make_pair(x, make_pair(w, i)));
	}
	set<pair<long long, int> > q;
	vector<long long> d(n, (long long)(1e18));
	d[0] = 0;
	q.insert(make_pair(0, 0));
	vector<int> last(n, -1);
	int cnt = 0;
	vector<int> ans;
	while(!q.empty() && cnt < k)
	{
		auto z = *q.begin();
		q.erase(q.begin());
		int k = z.second;
		if(last[k] != -1)
		{
			cnt++;
			ans.push_back(last[k]);
		}
		for(auto y : g[k])
		{
			int to = y.first;
			int w = y.second.first;
			int idx = y.second.second;
			if(d[to] > d[k] + w)
			{
				q.erase(make_pair(d[to], to));
				d[to] = d[k] + w;
				last[to] = idx;
				q.insert(make_pair(d[to], to));
			}
		}
	}		
	printf("%dn", ans.size());
	for(auto x : ans) printf("%d ", x + 1);
}	
```
[1076E - Vasya and a Tree](../problems/E._Vasya_and_a_Tree.md "Educational Codeforces Round 54 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 9;

int n, m;	
vector <int> g[N];
vector <pair<int, int> > q[N];
long long add[N];
long long res[N];

void dfs(int v, int pr, int h, long long sum){
	for(auto p : q[v]){
		int l = h, r = h + p.first;
		add[l] += p.second;
		if(r + 1 < N) add[r + 1] -= p.second;
	}
	sum += add[h];
	res[v] = sum;	
	for(auto to : g[v])
		if(to != pr)
			dfs(to, v, h + 1, sum);
			
	for(auto p : q[v]){
		int l = h, r = h + p.first;
		add[l] -= p.second;
		if(r + 1 < N) add[r + 1] += p.second;
	}
}

int main() {	
//	freopen("input.txt", "r", stdin);
	
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		int v, h, d;
		scanf("%d %d %d", &v, &h, &d);
		--v;
		q[v].push_back(make_pair(h, d));
	}
	
	dfs(0, 0, 0, 0);
	for(int i = 0; i < n; ++i)
		printf("%lld ", res[i]);
	puts("");
	
	return 0;
}
```
[1076F - Summer Practice Report](../problems/F._Summer_Practice_Report.md "Educational Codeforces Round 54 (Rated for Div. 2)")

 **Tutorial**
### [1076F - Summer Practice Report](../problems/F._Summer_Practice_Report.md "Educational Codeforces Round 54 (Rated for Div. 2)")

Let's intruduce the following dynamic programming approach. $dp[N][2]$, $dp[i][j]$ is the smallest number of elements of type $j$ page $i$ can end with. If we learn to recalculate it, the answer will be "YES" if $dp[n][0] \le k$ or $dp[n][1] \le k$. I will try to prove it on the fly.

Let's look into the constructing of each page from the following perspective. I'll consider the cases when the current page ends with tables and the previous page ends with either tables or formulas. Let's write down all the tables and then put formulas as separators to them. I will call number of tables on the end of the previous page $pa$, the number of formulas on the end of the previous page $pb$, the number on tables on the current page $a$ and the number of formulas on the current page $b$. 

In the case with tables on the end of the previous page the smallest number of separators you can have is $cnt = \lceil \frac{pa + a}{k} \rceil - 1$. Moreover, if you have $b > cnt$, you can put one of the formulas right before the end of the page, ending it with $1$ table. The only case is when there are too many separators. $b$ should be less or equal to $a \cdot k$ (you can put up to $k$ separators before each table).

The case with formulas on the end of the previous page isn't that different. The smallest number of separators is $cnt = \lceil \frac{a}{k} \rceil - 1$ and the limit to the number of separators is $(a - 1) \cdot k + (k - pb)$ (you can't put $k$ separators before the first table as in the first case, the maximum number to that position is determined by the previous page).

Now let's take a look at resulting expressions. You can notice that lowering $pa$ can only decrease the lower bound on the number of separators and lowering $pb$ can only increase the upper bound on the number of separators. That shows that minimizing the values in $dp[i][j]$ is always profitable.

Overall complexity: $O(n)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef long long li;

const int N = 300 * 1000 + 13;
const int INF = 1e9;

int dp[N][2];

int n, k;
int a[N], b[N];

int get(int pa, int pb, int a, int b){
	int ans = INF;
	
	if (pa <= k){
		int tot = pa + a;
		int cnt = (tot + k - 1) / k - 1;
		if (b == cnt)
			ans = min(ans, tot - cnt * k);
		else if (b > cnt && b <= a * li(k))
			ans = min(ans, 1);
	}
	
	if (pb <= k){
		int cnt = (a + k - 1) / k - 1;
		if (b == cnt)
			ans = min(ans, a - cnt * k);
		else if (b > cnt && b <= (a - 1) * li(k) + (k - pb))
			ans = min(ans, 1);
	}
	
	return ans;
}

int main() {
	scanf("%d%d", &n, &k);
	forn(i, n) scanf("%d", &a[i]);
	forn(i, n) scanf("%d", &b[i]);
	
	forn(i, N) forn(j, 2) dp[i][j] = INF;
	dp[0][0] = 0;
	dp[0][1] = 0;
	forn(i, n){
		dp[i + 1][0] = get(dp[i][0], dp[i][1], a[i], b[i]);
		dp[i + 1][1] = get(dp[i][1], dp[i][0], b[i], a[i]);
	}
	
	puts(dp[n][0] <= k || dp[n][1] <= k ? "YES" : "NO");
	return 0;
}
```
[1076G - Array Game](../problems/G._Array_Game.md "Educational Codeforces Round 54 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 200043;

typedef long long li;

int n, m;
li a[N];
int q;
int f[N * 4];
vector<int> T[4 * N];
vector<int> T2[4 * N];
int mask;
int cur;

vector<int> combine(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(1 << m);
	for(int i = 0; i < (1 << m); i++)
		c[i] = b[a[i]];
	return c;
}

vector<int> init(li x)
{
	vector<int> ans(1 << m);
	for(int i = 0; i < (1 << m); i++)
	{
		if(i != mask || (x & 1) == 0)
			ans[i] = ((i << 1) & mask) ^ 1;
		else
			ans[i] = ((i << 1) & mask);
	}	
	return ans;
}

void upd(int v)
{
	T[v] = combine(T[v * 2 + 2], T[v * 2 + 1]);
	T2[v] = combine(T2[v * 2 + 2], T2[v * 2 + 1]);
}

void build(int v, int l, int r)
{
	if(l == r - 1)
	{
		T[v] = init(a[l]);
		T2[v] = init(a[l] ^ 1);
		return;
	}
	int m = (l + r) >> 1;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	upd(v);
}

void push(int v, int l, int r)
{
	if(f[v])
	{
		swap(T[v], T2[v]);
		if(l != r - 1)
		{
			f[v * 2 + 1] ^= 1;
			f[v * 2 + 2] ^= 1;
		}
		f[v] = 0;
	}
}

vector<int> id;

void get(int v, int l, int r, int L, int R)
{
	push(v, l, r);
	if(L >= R)
		return;
	if(l == L && r == R)
	{
		cur = T[v][cur];
	}
	else
	{
		int m = (l + r) >> 1;
		get(v * 2 + 2, m, r, max(L, m), R);
		get(v * 2 + 1, l, m, L, min(R, m));
		upd(v);	
	}
}

void add(int v, int l, int r, int L, int R)
{
	push(v, l, r);
	if(L >= R)
		return;
	if(l == L && r == R)
	{
		f[v] ^= 1;
		push(v, l, r);
		return;
	}
	else
	{
		int m = (l + r) >> 1;
		add(v * 2 + 1, l, m, L, min(R, m));
		add(v * 2 + 2, m, r, max(L, m), R);
		upd(v);
	}
}

int main() 
{ 
	scanf("%d %d %d", &n, &m, &q);
	mask = (1 << m) - 1;
	for(int i = 0; i < (1 << m); i++)
		id.push_back(i);
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	build(0, 0, n);
	for(int i = 0; i < q; i++)
	{
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		--l;
		if(t == 1)
		{
			li d;
			scanf("%lld", &d);
			if(d & 1)
				add(0, 0, n, l, r);
		}
		else
		{
			cur = mask;
			get(0, 0, n, l, r);
			
			if((cur & 1) == 1)
				puts("1");
			else
				puts("2");
		}
	}
}
```
