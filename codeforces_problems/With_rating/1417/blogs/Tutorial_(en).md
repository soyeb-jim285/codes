# Tutorial_(en)

*Several unexpected Kuhn solutions passed for D1F. Could you please discuss your solutions in the comments and prove its correctness or provide any counter-examples. Author's solution uses flows with Dinic.* 

Editorial is not completed yet. Problem D1F will be added later. Hope you enjoyed the problemset!

Editorial was/will be written by [bthero](https://codeforces.com/profile/bthero "Master bthero") and [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest").

Our tester [namanbansal013](https://codeforces.com/profile/namanbansal013 "Expert namanbansal013") has made amazing video-tutorials on YouTube for problems [D2D/D1B](https://codeforces.com/https://youtu.be/LS51ijnR8jI) and [D2E/D1C](https://codeforces.com/https://youtu.be/rBSuG-_R3Yo). Make sure to check them out and show him some love!

Finally added the editorial for D1E. Currently it is very complicated and error-prone. 

Div2A by [bthero](https://codeforces.com/profile/bthero "Master bthero") 

 **Editorial**
### [1417A - Copy-paste](../problems/A._Copy-paste.md "Codeforces Round 673 (Div. 2)")

If we do our operation on two arbitrary integers $x \le y$, it is always better to copy $x$ into $y$ rather than to copy $y$ into $x$ (since a resulting pair $(x, x + y)$ is better than $(y, x + y)$). 

Now, let's assume that we do our operation on two integers $x \le y$ such that $x$ is not the minimum element of our array. If we replace $x$ with minimum, we can always achieve at least the same answer. Thus, we can take any index $m$ such that $a_m$ is the array minimum and use it to increase all other values.

Time complexity: $O(n)$ or $O(nk)$ per testcase.

Space complexity: $O(n)$

 **Code in C++ (BThero)**
```cpp
// chrono::system_clock::now().time_since_epoch().count()
#include<bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = (int)1e3 + 5;

int n, k;
int arr[MAXN];

void solve() {
  scanf("%d %d", &n, &k);
  
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
  }
  
  int mn = min_element(arr + 1, arr + n + 1) - arr;
  int ans = 0;
  
  for (int i = 1; i <= n; ++i) {
    if (i != mn) {
      while (arr[i] + arr[mn] <= k) {
        arr[i] += arr[mn];
        ++ans;
      }
    }
  }
  
  printf("%dn", ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  
  while (tt--) {
    solve();
  }

  return 0;
}
```
Div2B by [nkamzabek](https://codeforces.com/profile/nkamzabek "Expert nkamzabek") 

 **Editorial**
### [1417B - Two Arrays](../problems/B._Two_Arrays.md "Codeforces Round 673 (Div. 2)")

Let us partition the array into three sets $X$, $Y$, $Z$ such that $X$ contains all numbers less than $T/2$, $Y$ contains all numbers equal to $T/2$ and $Z$ contains all numbers greater than $T/2$. It is clear that $f(X) = f(Z) = 0$. Now, since each pair in $Y$ makes a sum of $T$, the best solution is to distribute all numbers in $Y$ equally among $X$ and $Z$. 

Time complexity: $O(n)$

Space complexity: $O(n)$

 **Code in C++ (hugopm)**
```cpp
#include <bits/stdc++.h>
#define len(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmax(x, v) x = max((x), (v))
#define chmin(x, v) x = min((x), (v))
using namespace std;
using ll = long long;

void solve() {
	int n, tar;
	cin >> n >> tar;
	int curMid = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		int r;
		if (tar % 2 == 0 && x == tar/2)
			r = (curMid++) % 2;
		else if (2*x < tar)
			r = 0;
		else
			r = 1;
		cout << r << " n"[i==n-1];
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);

	int nbTests;
	cin >> nbTests;
	for (int iTest = 0; iTest < nbTests; ++iTest) {
		solve();
	}
}
```
Div2C/Div1A by [nkamzabek](https://codeforces.com/profile/nkamzabek "Expert nkamzabek") 

 **Editorial**
### [1416A - k-Amazing Numbers](https://codeforces.com/contest/1416/problem/A "Codeforces Round 673 (Div. 1)")

Let's fix some arbitrary number $x$ and calculate the minimum value of $k$ such that $x$ occurs in all segments of length $k$. Let $p_1 < p_2 < \dots < p_m$ be the indices of entries of $x$ in the array. Then, for each $1 \le i < m$ it is clear that $k$ should be at least the value of $p_{i+1}-p_i$. Also, $k \ge p_1$ and $k \ge n - p_m + 1$. It is enough to just take the maximum of those values. Let's call this derived value of $k$ as $f(x)$.

Now, we can just go in increasing order of $x$ from $1$ to $n$ and try update the suffix $[f(x), n]$ with $x$. This can be done straightforwardly, just iterating over the range $[f(x), n]$. If we arrive at a cell for which the value of $x$ is already calculated, we immediately terminate our loop and continue our algorithm from $x+1$. 

Time complexity: $O(n)$.

Space complexity: $O(n)$.

 **Code in C++ (BThero)**
```cpp
// chrono::system_clock::now().time_since_epoch().count()
#include<bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = (int)3e5 + 5;

int f[MAXN], last[MAXN], arr[MAXN], ans[MAXN];
int n;

void solve() {
  scanf("%d", &n);
  
  for (int i = 1; i <= n; ++i) {
    f[i] = last[i] = 0;
    ans[i] = -1;
  }
  
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
  }
  
  for (int i = 1; i <= n; ++i) {
    int x = arr[i];
    f[x] = max(f[x], i - last[x]);
    last[x] = i;
  }
  
  for (int x = 1; x <= n; ++x) {
    f[x] = max(f[x], n - last[x] + 1);
    
    for (int i = f[x]; i <= n && ans[i] == -1; ++i) {
      ans[i] = x;
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", ans[i], " n"[i == n]);
  }
}

int main() {
  int tt;
  scanf("%d", &tt);
  
  while (tt--) {
    solve();
  }

  return 0;
}
```
Div2D/Div1B by [nkamzabek](https://codeforces.com/profile/nkamzabek "Expert nkamzabek") 

 **Editorial**
### [1416B - Make Them Equal](https://codeforces.com/contest/1416/problem/B "Codeforces Round 673 (Div. 1)")

Let $S$ be the sum of the array. If $S$ is not divisible by $n$, then the answer is obviously $-1$. Otherwise, there always exists a solution which uses no more than $3n$ queries. We will solve this problem in two phases.

First phase: gather the sum in $a_1$. Let's iterate over $2 \le i \le n$ in increasing order. If $a_i$ is divisible by $i$, we can immediately transfer it using one operation. Otherwise, we have to make it divisible by transferring $i - (a_i \bmod i)$ from $a_1$ to $a_i$. Note that this operation does not break a condition on non-negativity because all $a_i$ are initially positive. This way, we successfully finish this phase using at most $2(n-1)$ operations.

Second phase: distribute the sum across all elements. Just iterate over all $2 \le i \le n$ and make a transfer of $S/n$ from $a_1$ to $a_i$. This phase takes exactly $n-1$ operations.

Time complexity: $O(n)$

Space complexity: $O(n)$

 **Code in C++ (BThero)**
```cpp
// chrono::system_clock::now().time_since_epoch().count()
#include<bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = (int)1e4 + 5;

vector<array<int, 3>> ans;
int arr[MAXN];
int n;

void go(int x, int y, int z) {
  arr[x] -= x * z;
  arr[y] += x * z;
  ans.pb({x, y, z});
}

void solve() {
  scanf("%d", &n);
  
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
  }
  
  ans.clear();
  int sum = accumulate(arr + 1, arr + n + 1, 0);
  
  if (sum % n) {
    printf("-1n");
    return;
  }
  
  for (int i = 2; i <= n; ++i) {
    if (arr[i] % i) {
      go(1, i, i - arr[i] % i);
    }
    
    go(i, 1, arr[i] / i);
  }
  
  for (int i = 2; i <= n; ++i) {
    go(1, i, sum / n);
  }
  
  for (int i = 1; i <= n; ++i) {
    assert(arr[i] == sum / n);
  }
  
  assert((int)ans.size() <= 3 * n);
  printf("%dn", (int)ans.size());
  
  for (auto &[x, y, z] : ans) {
    printf("%d %d %dn", x, y, z);
  }
}

int main() {
  int tt;
  scanf("%d", &tt);
  
  while (tt--) {
    solve();
  }

  return 0;
}
```
Div2E/Div1C by [DimmyT](https://codeforces.com/profile/DimmyT "Master DimmyT") 

 **Editorial**
### [1416C - XOR Inverse](https://codeforces.com/contest/1416/problem/C "Codeforces Round 673 (Div. 1)")

Note: the integer $x$ from the statement is marked as an uppercase $X$ for clarity.

Take any arbitrary integers $x$ and $y$. It is a well-known fact that whether $x < y$ or $x > y$ depends only on one bit — the highest bit which differs in both.

So, let's construct a trie on our array integers. Represent each number as a binary string from the highest bit ($29$) to the lowest bit ($0$). Each leaf will keep a corresponding index/indices from the array and each non-leaf node will have at most two children — one for $0$-edge and one for $1$-edge. 

Let's denote $S(v)$ as a sorted list of indices of all values in the subtree of $v$. These lists can be easily maintained while inserting our numbers into trie. Take any arbitrary vertex $v$ which has both children and has a depth (distance from root) of $k$. Let $a$ and $b$ be its children. Here comes the most important thing to notice: If the $k$-th highest bit of $X$ is toggled, lists $S(a)$ and $S(b)$ will change their relative order. Otherwise, it will not change. Thus, exploiting the fact that both lists are sorted, we can efficiently calculate the corresponding number of inversions between those lists and add them to our values $sum[k][0]$ and $sum[k][1]$. $sum[i][j]$ means the number of inversions we have to add if $i$-th highest bit of $X$ is equal to $j$. 

After the calculation of our $sum$ table is done, the value of $X$ can be easily restored.

Time complexity: $O(n \log 10^9)$

Memory complexity: $O(n \log 10^9)$

 **Code in C++ (RedDreamer)**
```cpp
#include <bits/stdc++.h>
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define VAR(v, i) __typeof( i) v=(i)
#define forit(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
 
using namespace std;
 
const int maxn = (int)5e6 + 100;
const int maxm = (int)1e6 + 100;
const int mod = (int)1e9 + 7;
const int P = (int) 1e6 + 7; 
const double pi = acos(-1.0);
 
#define inf mod
 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   
typedef vector<ll> Vll;               
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;                        

int n, t[2][maxn], id = 1;
ll dp[2][30];
vi g[maxn];

void add(int x, int pos){
	int v = 0;
	forev(i, 29, 0){
		int bit = ((x >> i) & 1);
		if(!t[bit][v]) t[bit][v] = id++;
		v = t[bit][v];
		g[v].pb(pos);	
	}
}
void go(int v, int b = 29){
	int l = t[0][v], r = t[1][v];
	if(l) go(l, b - 1);
	if(r) go(r, b - 1);
	if(!l || !r) return;
	ll res = 0;
	int ptr = 0;
	for(auto x : g[l]){
		while(ptr < sz(g[r]) && g[r][ptr] < x) ptr++;
		res += ptr;
	}
	dp[0][b] += res;
	dp[1][b] += sz(g[l]) * 1ll * sz(g[r]) - res;
}
void solve(){
	scanf("%d", &n);
	forn(i, 1, n){
		int x;
		scanf("%d", &x);
		add(x, i);
	}
	go(0);
	ll inv = 0;
	int res = 0;
	forn(i, 0, 29){
		inv += min(dp[0][i], dp[1][i]);
		if(dp[1][i] < dp[0][i])
			res += (1 << i);
	}
	printf("%lld %d", inv, res);
}
 
int main () {
	int t = 1;
	//scanf("%d", &t);
	while(t--) solve();
}
```
Div2F/Div1D by [DimmyT](https://codeforces.com/profile/DimmyT "Master DimmyT")

 **Editorial**
### [1416D - Graph and Queries](https://codeforces.com/contest/1416/problem/D "Codeforces Round 673 (Div. 1)")

Basically, we want to transform each "connected component maximum" query into "segment maximum" query. It can be efficiently done using DSU and processing all queries in reversed order. For simplicity, let's assume all edges will eventually get deleted in the process. If not, you can always add some extra queries at the end. 

Initially, each vertex is a connected component on its own. We are processing all queries in reverse order. If the current query is of first type, remember the "boss" of the corresponding vertex. Otherwise, unite the corresponding vertices accordingly. If we want to unite two bosses $a$ and $b$, we create a new fake vertex $c$ and add edges $(a, c)$, $(b, c)$ so that the subtree of $c$ becomes responsible for both components of $a$ and $b$. Notice that we cannot apply small-to-large merging to our DSU, but we are still able to use path-compression heuristic. 

Now, our DSU-tree is ready. Each query of first type is now a subtree-maximum query and all queries of second type can be ignored. The solution onwards should be pretty straightforward. We first do an Eulerian tour on our tree to transform each subtree into a segment. Using segment tree we are able to efficiently process all queries.

Time complexity: $O((n + m + q) \log n)$ 

Space complexity: $O(n + m + q)$

 **Code in C++ (BThero)**
```cpp
// chrono::system_clock::now().time_since_epoch().count()
#include<bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = (int)5e5 + 5;
const int MAXM = (int)3e5 + 5;
const int MAXQ = (int)5e5 + 5;

pii e[MAXM], que[MAXQ], t[MAXN << 2];
vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN], timer;
int par[MAXN], arr[MAXN];
bool del[MAXM];
int n, m, q;

int getPar(int x) {
  if (x == par[x]) {
    return x;
  }
  
  return par[x] = getPar(par[x]);
}

void uni(int a, int b) {
  a = getPar(a);
  b = getPar(b);
  
  if (a == b) {
    return;
  }
  
  ++n;
  par[n] = n;
  par[a] = n;
  par[b] = n;
  adj[n].pb(a);
  adj[n].pb(b);
}

void dfs(int v) {
  tin[v] = ++timer;
  
  for (int to : adj[v]) {
    dfs(to);
  }
  
  tout[v] = timer;
}

pii segMax(int v, int tl, int tr, int l, int r) {
  if (l > r || tl > r || tr < l) {
    return mp(0, 0);
  }
  
  if (l <= tl && tr <= r) {
    return t[v];
  }
  
  int mid = (tl + tr) >> 1;
  int c1 = (v << 1), c2 = (c1 | 1);
  
  return max(segMax(c1, tl, mid, l, r), segMax(c2, mid + 1, tr, l, r));
}

void updPos(int v, int tl, int tr, int p, pii x) {
  if (tl == tr) {
    t[v] = x;
    return;
  }
  
  int mid = (tl + tr) >> 1;
  int c1 = (v << 1), c2 = (c1 | 1);
  
  if (p <= mid) {
    updPos(c1, tl, mid, p, x);
  }
  else {
    updPos(c2, mid + 1, tr, p, x);
  }
  
  t[v] = max(t[c1], t[c2]);
}

void solve() {
  scanf("%d %d %d", &n, &m, &q);
  
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
  }
  
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    e[i] = mp(u, v);
  }
  
  for (int i = 1; i <= q; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    que[i] = mp(a, b);
    
    if (a == 2) {
      del[b] = 1;
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    par[i] = i;
  }
  
  for (int i = 1; i <= m; ++i) {
    if (!del[i]) {
      uni(e[i].fi, e[i].se);
    }
  }
  
  for (int i = q; i > 0; --i) {
    int tp = que[i].fi;
    
    if (tp == 2) {
      int id = que[i].se;
      uni(e[id].fi, e[id].se);
    }
    else {
      que[i].se = getPar(que[i].se);
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    if (getPar(i) == i) {
      dfs(i);
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    updPos(1, 1, n, tin[i], mp(arr[i], tin[i]));
  }
  
  for (int i = 1; i <= q; ++i) {
    int tp = que[i].fi;
   
    if (tp == 1) {
      int v = que[i].se;
      pii tmp = segMax(1, 1, n, tin[v], tout[v]);
      
      if (tmp.fi == 0) {
        printf("0n");
      }
      else {
        printf("%dn", tmp.fi);
        updPos(1, 1, n, tmp.se, mp(0, 0));
      }
    }
  }
}

int main() {
  int tt = 1;
  
  while (tt--) {
    solve();
  }

  return 0;
}
```
Div1E by [bthero](https://codeforces.com/profile/bthero "Master bthero")

 **Editorial**
### [1416E - Split](https://codeforces.com/contest/1416/problem/E "Codeforces Round 673 (Div. 1)")

Note that minimizing $|b|$ is the same as maximizing the number of consecutive equal pairs. We will focus on the second version.

Let's forget about constraints and consider the most naive solution with dynamic programming. $DP[i][j]$ will store the answer if we have already considered ($a_1$, ..., $a_i$) and our last element $b_{2i}$ is equal to $j$. 

Let's get rid of our dimension $i$ and keep our $DP$ table by layers. Suppose that our current $i$-th layer is called $curDP$, next layer is called $nxtDP$, and $a_{i+1}$ is called $X$.

After carefully analyzing our transitions, we have the following observations: 

* for any $i$, $nxtDP[i] \ge max(curDP)$, since we always have a transition from our maximum.
* $max(nxtDP[i]) - min(nxtDP[i]) \le 2$, since we can add at most two pairs.
* The case $max(nxtDP[i]) - min(nxtDP[i]) = 2$ may occur only if $a_i$ is even. Moreover, $nxtDP[a_i/2]$ will be the only maximum element.
* For some suffix upto $i$ we always have a transition from $curDP[X-i] + 1$ to $nxtDP[i]$.
* If $X$ is even, instead of calculating $nxtDP[X/2]$ separately, we can calculate it as usual and increase its value by $1$ at the end.

Using everything said above, we could replace our naive $DP$ with the following:

1. A variable called $zero$ — the value of minimum of our current layer.
2. A set called $one$ — it keeps all indices $i$ such that $curDP[i] = zero + 1$.
3. A variable called $two$ — it is equal to $-1$ or $X/2$ depending on the parity of $X$ and the value of $curDP[X/2]$.

Basically, we want to be able to: 

* Erase some elements from the prefix/suffix of our set $one$.
* Check if some number $x$ is in our set $one$.
* Add a segment of values $[l, r]$ into out set $one$.
* Rotate all elements in our set by a pivot $x$. That is, a number $y$ should turn into $x-y$.

We can efficiently process all queries by maintaining $one$ as a simple set of non-intersecting segments. The rotation operation can be done as follows: 

1. Suppose we had an integer $X$ at the beginning.
2. We rotate everything by a pivot $A$. $X$ becomes $A-X$.
3. We rotate everything by a pivot $B$. $A-X$ becomes $B-A+X$.
4. Following the logic, $C-B+A-X$, $D-C+B-A+X$, ...
5. We can just maintain the sign of $X$ and a global pivot, which is the combination of all our rotation operations.

Time complexity: $O(n \log n)$

Space complexity: $O(n)$

 **Code in C++ (BThero)**
```cpp
// chrono::system_clock::now().time_since_epoch().count()
#include<bits/stdc++.h>

#define __DBG 1
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define debug(x) if (__DBG) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = (int)5e5 + 5;

int arr[MAXN];
int n;

void solve() {
  scanf("%d", &n);
  
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
  }
  
  int zero = 0, two = -1;
  set<pll> one;
  ll shifter = 0;
  int sign = 1;
  
  for (int i = 1; i <= n; ++i) {
    int x = arr[i];
    
    if (two != -1) {
      zero += 2;
      sign = 1;
      shifter = 0;
      one.clear();
      
      if (two < x) {
        one.insert(mp(x - two, x - two));
      }
    }
    else if (!one.empty()) {
      zero++;
      
      if (sign == -1) {
        // shifter - idx >= x
        // shifter - x >= idx
        // idx <= shifter - x
        ll lim = shifter - x;
        
        while (!one.empty() && one.begin() -> se <= lim) {
          one.erase(one.begin());
        }
        
        if (!one.empty() && one.begin() -> fi <= lim) {
          pll it = mp(lim + 1, one.begin() -> se);
          one.erase(one.begin());
          assert(it.fi <= it.se);
          one.insert(it);
        }
      }
      else {
        // shifter + idx >= x
        // idx >= x - shifter
        ll lim = x - shifter;
        
        while (!one.empty() && one.rbegin() -> fi >= lim) {
          one.erase(--one.end());
        }
        
        if (!one.empty() && one.rbegin() -> se >= lim) {
          pll it = mp(one.rbegin() -> fi, lim - 1);
          one.erase(--one.end());
          assert(it.fi <= it.se);
          one.insert(it);
        }
      }
      
      shifter = x - shifter;
      sign *= -1;
    }
    else {
      sign = -1;
      shifter = x;
      int lim = min(arr[i - 1] - 1, x - 1);
      
      if (1 <= lim) {
        one.insert(mp(1, lim));
      }
    }
    
    // consider x/2!
    two = -1;
    
    if (x % 2 == 0) {
      int y = x / 2;
      ll val = (y - shifter) / sign;
      auto it = one.lower_bound(mp(val + 1, (ll)-1e18));
      bool found = 0;
      
      if (it != one.begin()) {
        --it;
        
        if (it -> fi <= val && val <= it -> se) {
          found = 1;
        }
      }
      
      if (found) {
        two = y;
      }
      else {
        one.insert(mp(val, val));
      }
    }
  }
  
  int ans;
  
  if (two != -1) {
    ans = zero + 2;
  }
  else if (!one.empty()) {
    ans = zero + 1;
  }
  else {
    ans = zero;
  }
  
  printf("%dn", 2 * n - ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  
  while (tt--) {
    solve();
  }

  return 0;
}
```
 **Alternative solution code in C++ (hugopm)**
```cpp
#include <bits/stdc++.h>
#define int long long
#define len(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmax(x, v) x = max((x), (v))
#define chmin(x, v) x = min((x), (v))
using namespace std;
using pii = pair<int, int>;

struct EndSet {
	set<int> points;
	pii seg = {1, 0};

	int cbase = 0, cdir = 1;

	void setFree(int mx) {
		points.clear(), cbase = 0, cdir = 1;
		seg = {1, mx};
	}

	void setPush(int x) {
		setFree(0);
		points.insert(x);
	}

	void rotate(int balance) {
		cbase = balance - cbase;
		cdir = -cdir;
		seg = {balance - seg.second, balance - seg.first};
	}

	int tr(int x) {
		return cbase + cdir*x;
	}

	int anti(int x) {
		return cdir * (x - cbase);
	}

	bool in(int x) {
		if (points.count(anti(x)))
			return true;
		return (seg.first <= x && x <= seg.second);	
	}

	void push(int x) {
		points.insert(anti(x));
	}

	void popBelow(int x) {
		seg.second = min(seg.second, x);
		auto nextIt = [&] {
			return (cdir == 1 ? prev(points.end()) : points.begin());
		};
		while (!points.empty() && tr(*nextIt()) > x)
			points.erase(nextIt());
	}
	
	bool empty() {
		return points.empty() && seg.first > seg.second;
	}
};

void solve() {
	int n; cin >> n;
	EndSet util;
	int curAns = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		util.popBelow(x-1); 
		if (x % 2 == 0 && util.in(x/2)) {
			curAns += 2;
			util.setPush(x/2);
		} else if (util.empty()) {
			if (x % 2 == 0)
				curAns += 1, util.setPush(x/2);
			else
				util.setFree(x-1);
		} else {
			curAns += 1;
			if (x % 2 == 0)
				util.push(x/2);
		}
		util.rotate(x);
	}	
	cout << 2*n - curAns << "n";
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int nbTests;
	cin >> nbTests;
	for (int iTest = 0; iTest < nbTests; ++iTest) {
		solve();
	}
}
```
Div1F by [bthero](https://codeforces.com/profile/bthero "Master bthero")

 **Editorial**...

 **Code in C++ (BThero)**
```cpp
// chrono::system_clock::now().time_since_epoch().count()
#include<bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char dc[] = {'R', 'D', 'L', 'U'};
const int INF = (int)1e6;
const int MAXN = (int)3e5 + 5;

namespace {
  struct Edge {
    int v, to, f, c;
    
    Edge() {
      v = to = f = c = 0;
    }
    
    Edge(int v, int to, int c) : v(v), to(to), c(c) {
      f = 0;
    }
  };
  
  vector<Edge> e;
  vector<int> adj[MAXN];
  int ptr[MAXN], d[MAXN], q[MAXN];
  int S, T, newS, newT, V;
  int cap[2][MAXN];
  
  void prep() {
    e.clear();
    
    for (int i = 0; i < V; ++i) {
      adj[i].clear();
      ptr[i] = d[i] = q[i] = 0;
      cap[0][i] = cap[1][i] = 0;
    }
  }
  
  void addEdge(int u, int v, int c) {
    //printf("E %d %d %dn", u, v, c);
  
    adj[u].pb((int)e.size());
    e.pb(Edge(u, v, c));
    adj[v].pb((int)e.size());
    e.pb(Edge(v, u, 0));
  }
  
  void addEdgeLim(int u, int v) {
    //printf("F %d %dn", u, v);
    ++cap[0][v];
    ++cap[1][u];
  }
  
  bool bfs() {
    fill(d, d + V, -1);
    d[newS] = 0;
    int l = 0, r = 0;
    q[r++] = newS;
    
    while (l < r) {
      int v = q[l++];
      
      for (int id : adj[v]) {
        if (e[id].f < e[id].c) {
          int to = e[id].to;
          
          if (d[to] == -1) {
            d[to] = d[v] + 1;
            q[r++] = to;
          }
        }
      }
    }
    
    return d[newT] != -1;
  }
  
  int dfs(int v, int flow = INF) {
    if (!flow || v == newT) {
      return flow;
    }
    
    int sum = 0;
    
    for (; ptr[v] < (int)adj[v].size(); ++ptr[v]) {
      int id = adj[v][ptr[v]];
      int to = e[id].to;
      int can = e[id].c - e[id].f;
      
      if (d[to] != d[v] + 1 || can == 0) {
        continue;
      }
      
      int pushed = dfs(to, min(flow, can));
      
      if (pushed > 0) {
        e[id].f += pushed;
        e[id ^ 1].f -= pushed;
        sum += pushed;
        flow -= pushed;
        
        if (flow == 0) {
          return sum;
        }
      }
    }
    
    return sum;
  }
  
  int maxFlow() {
    int ret = 0;
    
    while (bfs()) {
      fill(ptr, ptr + V, 0);
    
      while (int pushed = dfs(newS)) {
        ret += pushed;
      }
    }
    
    return ret;
  }
}

vvi arr, follow;
int n, m;

bool inside(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

int id(int x, int y) {
  return x * m + y;
}

void solve() {
  scanf("%d %d", &n, &m);
  arr = follow = vvi(n, vi(m, -1));
  S = n * m;
  T = S + 1;
  newS = T + 1;
  newT = newS + 1;
  V = newT + 1;
  prep();
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int dir = 0; dir < 4; ++dir) {
        int ni = i + dx[dir], nj = j + dy[dir];
        
        if (inside(ni, nj)) {
          if (arr[ni][nj] < arr[i][j]) {
            follow[i][j] = dir;
          }
          else if ((i + j) % 2 == 0 && arr[ni][nj] == arr[i][j]) {
            addEdge(id(i, j), id(ni, nj), 1);
          }
        }
      }
      
      if (follow[i][j] == -1) {
        // important vertex
        if ((i + j) % 2) {
          addEdgeLim(id(i, j), T);
        }
        else {
          addEdgeLim(S, id(i, j));
        }
      }
      else {
        if ((i + j) % 2) {
          addEdge(id(i, j), T, 1);
        }
        else {
          addEdge(S, id(i, j), 1);
        }
      }
    }
  }
  
  for (int i = 0; i <= T; ++i) {
    if (cap[0][i] > 0) {
      addEdge(newS, i, cap[0][i]);
    }
    
    if (cap[1][i] > 0) {
      addEdge(i, newT, cap[1][i]);
    }
  }
  
  addEdge(T, S, INF);
  maxFlow();
  
  for (int id : adj[newS]) {
    if (e[id].f != e[id].c) {
      printf("NOn");
      return;
    }
  }
  
  vvi ansv, ansc;
  ansv = ansc = vvi(n, vi(m));
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int dir = follow[i][j];
      
      if (dir != -1) {
        int ni = i + dx[dir], nj = j + dy[dir];
        ansv[i][j] = arr[i][j] - arr[ni][nj];
        ansc[i][j] = dir;
      }
    }
  }
  
  for (Edge it : e) {
    int v = it.v, to = it.to;
    
    if (max(v, to) < n * m && it.f == it.c && it.c == 1) {
      int ax = v / m, ay = v % m;
      int bx = to / m, by = to % m;
      ansv[ax][ay] = arr[ax][ay] - 1;
      ansv[bx][by] = 1;
      
      for (int dir = 0; dir < 4; ++dir) {
        if (mp(ax + dx[dir], ay + dy[dir]) == mp(bx, by)) {
          ansc[ax][ay] = dir;
          ansc[bx][by] = (dir + 2) % 4;
        }
      }
    }
  }
  
  printf("YESn");
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d%c", ansv[i][j], " n"[j == m - 1]);
    }
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%c%c", dc[ansc[i][j]], " n"[j == m - 1]);
    }
  }
}

int main() {
  int tt;
  scanf("%d", &tt);
  
  while (tt--) {
    solve();
  }

  return 0;
}
```
