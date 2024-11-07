# Tutorial

[1452A - Robot Program](../problems/A._Robot_Program.md "Educational Codeforces Round 98 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1452A - Robot Program](../problems/A._Robot_Program.md "Educational Codeforces Round 98 (Rated for Div. 2)")

Obviously, you can always obtain the optimal answer without using west or south moves. So the shortest path consists of $x$ east moves and $y$ north moves. 

Let's estimate the lower bound of the answer. Take a look at these constructions: "E?E?E?E?E" and "N?N?N?N?N" (let question mark be any command different from the used one). That's the tightest you can put east or north moves in.

So the answer is at least $2 \cdot max(x, y) - 1$. For $x \neq y$ you can put them just as in the construction and fill the rest of question marks with a stay in place move. $x = y$ case works differently, though. You can do it only in $x + y$ moves by taking alternating moves.

Overall complexity: $O(1)$ per testcase.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        int ans = max(x, y) * 2 - 1;
        if(x == y) ans++;
        cout << ans << endl;
    }
}
```
[1452B - Toy Blocks](../problems/B._Toy_Blocks.md "Educational Codeforces Round 98 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**Tutorial is loading... **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toLong() }

        val k = maxOf(a.max()!!, (a.sum() + n - 2) / (n - 1))
        println(k * (n - 1) - a.sum())
    }
}
```
[1452C - Two Brackets](../problems/C._Two_Brackets.md "Educational Codeforces Round 98 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (pikmike)**
```cpp
def calc(s, x, y):
	bal, cnt = 0, 0
	for c in s:
		if c == y:
			if bal > 0:
				bal -= 1
				cnt += 1
		elif c == x:
			bal += 1
	return cnt

for _ in range(int(input())):
	s = input()
	print(calc(s, '(', ')') + calc(s, '[', ']'))
```
[1452D - Radio Towers](../problems/D._Radio_Towers.md "Educational Codeforces Round 98 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1452D - Radio Towers](../problems/D._Radio_Towers.md "Educational Codeforces Round 98 (Rated for Div. 2)")

The crucial observation is that when the positions of towers are fixed, the way to set their signal powers is unique if it exists. That's because the first tower should have its signal power exactly equal to the required to cover all towns before it, the second tower should have signal power exactly equal to the required to cover all towns before it that weren't covered by the first one, and so on. So let's count the number of ways to cover all towns, and then divide it by $2^n$.

Covering all towns can be expressed as splitting $n$ into the sum of several positive odd integers. It can be calculated with dynamic programming with prefix sums, but we can also prove that the number of ways to split $n$ is exactly the $n$-th integer in the Fibonacci sequence as follows (this proof uses mathematical induction):

* for $n \le 2$, it's quite obvious;
* for $n > 2$ and $n \bmod 2 = 0$, let's iterate on the length of the last segment. We have to sum $F_1 + F_3 + \dots + F_{n - 1}$; $F_1 + F_3 = 1 + 2 = F_4$; $F_4 + F_5 = F_6$; $F_6 + F_7 = F_8$, and so on, until we get $F_{n - 2} + F_{n - 1} = F_n$;
* for $n > 2$ and $n \bmod 2 = 1$, let's iterate on the length of the last segment, and add $1$ to result since we can cover everything with a single segment. So, this is $1 + F_2 + F_4 + F_6 + \dots + F_{n - 1}$. $1 + F_2 = F_3$, $F_3 + F_4 = F_5$, and so on.

So, the answer to the problem is $\dfrac{F_n}{2^n}$.

The last thing we have to consider is that we have to print a fraction modulo $998244353$. Since $998244353$ is a prime, using Fermat little theorem, we can calculate $y^{-1}$ as $y^{998244351} \bmod 998244353$. Exponentiation must be done with some fast algorithm (for example, binary exponentiation).

Note: it's common in problems requiring to calculate something modulo some prime number to have problems with overflow in intermediate calculations or some other issues when we forget to take the result of some expression modulo $998244353$. I recommend using either special addition/multiplication/exponentiation functions that always take the result modulo $998244353$ (an example how to write and use them can be viewed in the model solution), or a special modular integer data structure with overloaded operators that you have to implement by yourself.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
    int ans = 1;
    while(y > 0)
    {
        if(y % 2 == 1)
            ans = mul(ans, x);
        x = mul(x, x);
        y /= 2;
    }
    return ans;
}

int divide(int x, int y)
{
    return mul(x, binpow(y, MOD - 2));
}

int main()
{
    int n;
    cin >> n;
    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++)
        fib[i] = add(fib[i - 1], fib[i - 2]);
    cout << divide(fib[n], binpow(2, n)) << endl;    
}
```
[1452E - Two Editorials](../problems/E._Two_Editorials.md "Educational Codeforces Round 98 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct seg{
	int l, r;
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<seg> a(m);
	forn(i, m){
		cin >> a[i].l >> a[i].r;
		--a[i].l;
	}
	sort(a.begin(), a.end(), [](const seg &a, const seg &b){
		return a.l + a.r < b.l + b.r;
	});
	vector<int> su(m + 1);
	forn(i, n - k + 1){
		int cur = 0;
		for (int j = m - 1; j >= 0; --j){
			cur += max(0, min(i + k, a[j].r) - max(i, a[j].l));
			su[j] = max(su[j], cur);
		}
	}
	int ans = su[0];
	forn(i, n - k + 1){
		int cur = 0;
		forn(j, m){
			cur += max(0, min(i + k, a[j].r) - max(i, a[j].l));
			ans = max(ans, cur + su[j + 1]);
		}
	}
	cout << ans << endl;
	return 0;
}
```
[1452F - Divide Powers](../problems/F._Divide_Powers.md "Educational Codeforces Round 98 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**Tutorial is loading... **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
	out << "[";
	fore(i, 0, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n, q;
vector<li> cnt;

inline bool read() {
	if(!(cin >> n >> q))
		return false;
	cnt.assign(n, 0);
	fore (i, 0, n)
		cin >> cnt[i];
	return true;
}

inline void solve() {
	fore (qs, 0, q) {
		int tp, pos;
		li val;
		cin >> tp >> pos >> val;
		if (tp == 1) {
			cnt[pos] = val;
		} else {
			li small = 0, cur = 0;
			fore (i, 0, pos + 1) {
				small += cnt[i] * ((1ll << i) - 1);
				val -= cnt[i];
			}
			if (val <= 0) {
				cout << 0 << 'n';
				continue;
			}
			
			int id = pos + 1;
			while (id < n) {
				li add = 1ll << (id - pos);
				li need = min(val / add, cnt[id]);
				cur += need * (add - 1);
				val -= need * add;
				small += need * add * ((1ll << pos) - 1);
				
				if (need == cnt[id])
					id++;
				else
					break;
			}
			if (val <= 0) {
				cout << cur << 'n';
				continue;
			}
			if (id >= n) {
				cout << (val > small ? -1 : cur + val) << 'n';
				continue;
			}
			
			li ans = INF64;
			while (id > pos) {
				if (small >= val)
					ans = min(ans, cur + val);
				cur++;
				id--;
				li add = 1ll << (id - pos);
				if (val >= add) {
					cur += add - 1;
					val -= add;
					small += add * ((1ll << pos) - 1);
				}
			}
			assert(val <= 0);
			cout << min(ans, cur) << endl;
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	if(read()) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
[1452G - Game On Tree](../problems/G._Game_On_Tree.md "Educational Codeforces Round 98 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**Tutorial is loading... **Solution 1 (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n;
vector<vector<int>> g;

vector<int> h, pcd, d;
vector<vector<int>> st, vals;
vector<int> a;
 
int dfs(int v, int s, int &cd, int p = -1){
	int sum = 1;
	for (int u : g[v]) if (h[u] == -1 && u != p)
		sum += dfs(u, s, cd, v);
	if (cd == -1 && (2 * sum >= s || p == -1))
		cd = v;
	return sum;
}
 
void build(int v, int s, int d, int p = -1){
	int cd = -1;
	dfs(v, s, cd);
	h[cd] = d;
	pcd[cd] = p;
	for (int u : g[cd]) if (h[u] == -1)
		build(u, s / 2, d + 1, cd);
}

vector<char> cur;

void calcd(int v, int p = -1){
	for (int u : g[v]) if (u != p && cur[u]){
		d[u] = d[v] + 1;
		calcd(u, v);
	}
}

vector<vector<int>> dist;

void init(){
	a.resize(n, -1);
	int k;
	scanf("%d", &k);
	queue<int> q;
	forn(i, k){
		int v;
		scanf("%d", &v);
		--v;
		q.push(v);
		a[v] = 0;
	}
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (int u : g[v]) if (a[u] == -1){
			a[u] = a[v] + 1;
			q.push(u);
		}
	}
	h.resize(n, -1);
	pcd.resize(n);
	build(0, n, 0);
	st.resize(n);
	vector<int> nd(n);
	forn(v, n){
		int u = v;
		while (u != -1){
			st[u].push_back(v);
			if (pcd[u] != -1)
				nd[pcd[u]] = max(nd[pcd[u]], nd[u] + 1);
			u = pcd[u];
		}
	}
	cur.resize(n);
	vals.resize(n);
	dist.resize(n);
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&nd](int x, int y){
		return nd[x] < nd[y];
	});
	d.resize(n);
	for (int v : ord){
		for (int u : st[v]) cur[u] = true;
		d[v] = 0;
		calcd(v);
		int mx = 0;
		for (int u : st[v]) mx = max(mx, d[u]);
		vals[v].resize(mx + 1, 0);
		for (int u : st[v]) vals[v][d[u]] = max(vals[v][d[u]], a[u]);
		forn(j, mx) vals[v][j + 1] = max(vals[v][j + 1], vals[v][j]);
		for (int u : st[v]) cur[u] = false;
		for (int u : st[v]) dist[u].push_back(d[u]);
	}
}

bool check(int v, int x){
	for (int i = 0, u = v; u != -1; u = pcd[u], ++i)
		if (x - dist[v][i] >= 0 && vals[u][min(int(vals[u].size()) - 1, x - dist[v][i])] > x)
			return true;
	return false;
}

int main() {
	scanf("%d", &n);
	g.resize(n);
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	init();
	forn(v, n){
		int res = 0;
		int l = 0, r = n;
		while (l <= r){
			int m = (l + r) / 2;
			if (check(v, m)){
				res = m + 1;
				l = m + 1;
			}
			else{
				r = m - 1;
			}
		}
		printf("%d ", res);
	}
	puts("");
}
```
 **Solution 2 (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 200043;
const int LN = 18;

vector<int> g[N];
vector<int> dist[N];
int sz[N];
int par[N];
bool used[N];
int max_dist[N];
vector<int> val[N];

int calc_size(int x, int p = -1)
{
    sz[x] = 1;
    for(auto y : g[x])
        if(y != p && !used[y])
            sz[x] += calc_size(y, x);
    return sz[x];   
}

int find_centroid(int x, int p, int s)
{
    int ans = -1;
    bool good = true;
    for(auto y : g[x])
        if(y != p && !used[y])
            good &= sz[y] * 2 <= s;
        else if(y == p && !used[y])
            good &= (s - sz[x]) * 2 <= s;
    if(good)
        ans = x;
    for(auto y : g[x])
        if(y != p && !used[y])
            ans = max(ans, find_centroid(y, x, s));
    return ans;
}

void calc_dist(int x, int p, int d, int s)
{
    dist[x].push_back(d);
    for(auto y : g[x])
        if(y != p && !used[y])
            calc_dist(y, x, d + 1, s);
    max_dist[s] = max(max_dist[s], d);  
}

int decomposition(int v)
{
    calc_size(v);
    int c = find_centroid(v, v, sz[v]);
    used[c] = true;
    for(auto y : g[c])
        if(!used[y])
        {
            par[decomposition(y)] = c;
        }
    used[c] = false;
    calc_dist(c, c, 0, c); 
    return c;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    decomposition(0);
    for(int i = 0; i < n; i++)
        val[i].resize(max_dist[i] + 1);    
    int k;
    scanf("%d", &k);
    vector<int> d(n, int(1e9));
    queue<int> q;
    for(int i = 0; i < k; i++)
    {
        int x;
        scanf("%d", &x);
        --x;
        q.push(x);
        d[x] = 0;
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto y : g[x])
            if(d[y] > d[x] + 1)
            {
                q.push(y);
                d[y] = d[x] + 1;
            }
    }
    for(int i = 0; i < n; i++)
    {
        if(d[i] == 0) continue;
        
        int curc = i;
        for(int j = 0; j < dist[i].size(); j++)
        {
            int dd = dist[i][j];
            if(dd > d[i] - 1)
            {
                curc = par[curc];
                continue;
            }
            dd = d[i] - 1 - dd;
            if(dd >= val[curc].size())
                dd = val[curc].size() - 1; 
            val[curc][dd] = max(val[curc][dd], d[i]);
            curc = par[curc];
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = max_dist[i]; j >= 1; j--)
            val[i][j - 1] = max(val[i][j], val[i][j - 1]);
    for(int i = 0; i < n; i++)
    {
        int ans = 0; 
        int curc = i;
        for(int j = 0; j < dist[i].size(); j++)
        {
            int dd = dist[i][j];
            ans = max(ans, val[curc][dd]);
            curc = par[curc];
        }
        if(d[i] == 0)
            ans = 0;
        printf("%d%c", ans, " n"[i == n - 1]);
    }
}
```
