# Tutorial_(en)

Hi, Codeforces!

[1529A - Eshag Loves Big Arrays](../problems/A._Eshag_Loves_Big_Arrays.md "Codeforces Round 722 (Div. 2)")

problem idea and solution: [AmShZ](https://codeforces.com/profile/AmShZ "Grandmaster AmShZ")

 **editorial**
### [1529A - Eshag Loves Big Arrays](../problems/A._Eshag_Loves_Big_Arrays.md "Codeforces Round 722 (Div. 2)")

We state that every element except for the elements with the smallest value can be deleted.

Proof: denote $MN$ as the minimum element (s) of the array $a$, in each operation pick $MN$ and some other element, say $X$, which is bigger than $MN$, since $AVG = \frac{X + MN}{2} < X$, then $X$ will be deleted.

Doing this for every $X > MN$ will result in the deletion of every element except for the elements with the smallest value. So the answer to the problem is $n - cntMN$, where $cntMN$ is the number of times $MN$ appeared in $a$.

complexity: $\mathcal{O}(n)$

 **official solution**
```cpp
// khodaya khodet komak kon
# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;
 
# define A                                               first

# define B                                               second

# define endl                                            'n'

# define sep                                             ' '

# define all(x)                                          x.begin(), x.end()

# define kill(x)                                         return cout << x << endl, 0

# define SZ(x)                                           int(x.size())

# define lc                                              id << 1

# define rc                                              id << 1 | 1
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e2 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;
 
int qq, n, a[xn], mn, ans;
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin >> qq;
	while (qq --){
		cin >> n, mn = inf, ans = 0;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], mn = min(mn, a[i]);
		for (int i = 1; i <= n; ++ i)
			ans += a[i] != mn;
		cout << ans << endl;
	}
 
	return 0;
}
```
[1529B - Sifid and Strange Subsequences](../problems/B._Sifid_and_Strange_Subsequences.md "Codeforces Round 722 (Div. 2)")

problem idea and solution: [Davoth](https://codeforces.com/profile/Davoth "Candidate Master Davoth")

 **editorial**
### [1529B - Sifid and Strange Subsequences](../problems/B._Sifid_and_Strange_Subsequences.md "Codeforces Round 722 (Div. 2)")

It's easy to prove that a strange subsequence can't contain more than one positive element.

So it's optimal to pick all of the non-positive elements, now we can pick at most one positive element.

Assume $x$ is the minimum positive element in the array. We can pick $x$ if no two elements in the already picked set such as $a$ and $b$ exist in a way that $|a - b| < x$. 

To check this, we just have to sort the already picked elements and see the difference between adjacent pairs. 

complexity: $\mathcal{O}(n\log n)$

 **official solution**
```cpp
// khodaya khodet komak kon
// Nightcall - London Grammer
# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;
 
# define A                                               first

# define B                                               second

# define endl                                            'n'

# define sep                                             ' '

# define all(x)                                          x.begin(), x.end()

# define kill(x)                                         return cout << x << endl, 0

# define SZ(x)                                           int(x.size())

# define lc                                              id << 1

# define rc                                              id << 1 | 1
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;
 
int qq, n, a[xn], ans, mn;
bool flag;
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
	cin >> qq;
	while (qq --){
		cin >> n, ans = 0;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], ans += (a[i] <= 0);
		sort(a + 1, a + n + 1), mn = inf;
		for (int i = 1; i <= n; ++ i)
			if (a[i] > 0)
				mn = min(mn, a[i]);
		flag = (mn < inf);
		for (int i = 2; i <= n; ++ i)
			if (a[i] <= 0)
				flag &= (a[i] - a[i - 1] >= mn);
		if (flag)
			cout << ans + 1 << endl;
		else
			cout << ans << endl;
	}
 
	return 0;
}
```
[1528A - Parsa's Humongous Tree](https://codeforces.com/contest/1528/problem/A "Codeforces Round 722 (Div. 1)")

problem idea and solution: [shokouf](https://codeforces.com/profile/shokouf "Candidate Master shokouf"), [AmShZ](https://codeforces.com/profile/AmShZ "Grandmaster AmShZ")

 **editorial**
### [1528A - Parsa's Humongous Tree](https://codeforces.com/contest/1528/problem/A "Codeforces Round 722 (Div. 1)")

The solution is based on the fact that an optimal assignment for $a$ exists such that for each vertex $v$, $a_v \in {l_v, r_v}$.

Proving this fact isn't hard, pick any assignment for $a$. Assume $v$ is a vertex in this assignment such that $a_v \notin {l_v, r_v}$.

Let $p$ be the number of vertices $u$ adjacent to $v$ such that $a_u > a_v$. 

Let $q$ be the number of vertices $u$ adjacent to $v$ such that $a_u < a_v$.

Consider the following cases:

* $p > q$: In this case we can decrease $a_v$ to $l_v$ and get a better result.
* $p < q$: In this case we can increase $a_v$ to $r_v$ and get a better result.
* $p = q$: In this case changing $a_v$ to $l_v$ or $r_v$ will either increase or not change the beauty of the tree.

Based on this fact, we can use dynamic programming to find the answer.

Define $dp_{v,0}$ as the maximum beauty of $v$'s subtree if $a_v$ is equal to $l_v$.

Similarly, define $dp_{v,1}$ as the maximum beauty of $v$'s subtree if $a_v$ is equal to $r_v$.

$dp_{v,j}$ is calculated based on $v$'s children, for each of $v$'s children such as $u$, we add $u$'s contribution to $dp_{v,j}$.

The transitions are: 

* $dp_{v,0} += max(dp_{u,0} + |l_v - l_u| , dp_{u,1} + |l_v - r_u|)$
* $dp_{v,1} += max(dp_{u,0} + |r_v - l_u| , dp_{u,1} + |r_v - r_u|)$

It's clear that the answer is equal to $max(dp_{v,0}, dp_{v,1})$.

complexity: $\mathcal{O}(n)$

 **official solution**
```cpp
// Call my Name and Save me from The Dark
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
 
const int N = 2e5 + 10;
ll dp[2][N]; int A[2][N], n; vector<int> adj[N];
 
void DFS(int v, int p = -1) {
    dp[0][v] = dp[1][v] = 0;
    for (int u : adj[v]) {
        if (u == p) continue;
        DFS(u, v);
        dp[0][v] += max(abs(A[0][v] - A[1][u]) + dp[1][u], dp[0][u] + abs(A[0][v] - A[0][u]));
        dp[1][v] += max(abs(A[1][v] - A[1][u]) + dp[1][u], dp[0][u] + abs(A[1][v] - A[0][u]));
    }
}
 
void Solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[0][i], &A[1][i]);
    fill(adj + 1, adj + n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    printf("%lldn", max(dp[0][1], dp[1][1]));
}
 
int main() {
    int t; scanf("%d", &t);
    while (t--) Solve();
    return 0;
}
```
[1528B - Kavi on Pairing Duty](https://codeforces.com/contest/1528/problem/B "Codeforces Round 722 (Div. 1)")

problem idea and solution: [alireza_kaviani](https://codeforces.com/profile/alireza_kaviani "International Grandmaster alireza_kaviani")

 **editorial**
### [1528B - Kavi on Pairing Duty](https://codeforces.com/contest/1528/problem/B "Codeforces Round 722 (Div. 1)")

Let $dp_i$ be the number of good pairings of $2i$ points.

Clearly, the answer is $dp_n$.

Lemma: Denote $x$ as the point matched with the point $1$. Notice that each point $p$ $(x < p \le 2n)$ belongs to a segment with length equal to $[1 , x]$'s length.

Proof: Assume some point $p$ $(x < p \le 2n)$ is paired with a point $q$ $(q > p)$, since $[p , q]$ doesn't lie inside $[1, x]$ then their size must be the equal for the pairing to be good.

To compute $dp_n$, consider the following cases:

* $x > n$: Similar to lemma mentioned above, it can be proved that each point $p$ $(1 \le p \le 2n-x+1)$ is paired with the point $i + x - 1$, the remaining unpaired $x - n - 1$ points form a continuous subarray which lies inside each of the current pairs, thus they can be paired in $dp_{x - n - 1}$ ways.
* $x \le n$: In this case, due to the lemma mentioned above all the segments must have the same length, thus their length must be a divisor of $n$, in this case they can be paired in $D(n)$ ways; where $D(n)$ is the number of divisors of $n$.

So $dp_n$ = $D(n) + \sum_{i = 0}^{n-1} {dp_i}$. 

Note that $dp_0 = dp_1 = 1$.

complexity: $\mathcal{O}(n\log n)$

 **official solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
 
#define X first
#define Y second
#define endl 'n'
 
const int N = 1e6 + 10;
const int MOD = 998244353;
 
int n, dp[N], S;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i + i; j <= n; j += i) {
            dp[j]++;
        }
    }
    dp[0] = S = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = (dp[i] + S) % MOD;
        S = (S + dp[i]) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}
```
[1528C - Trees of Tranquillity](https://codeforces.com/contest/1528/problem/C "Codeforces Round 722 (Div. 1)")

problem idea and solution: [AliShahali1382](https://codeforces.com/profile/AliShahali1382 "International Grandmaster AliShahali1382")

 **editorial**
### [1528C - Trees of Tranquillity](https://codeforces.com/contest/1528/problem/C "Codeforces Round 722 (Div. 1)")

Let's start with some observations.

Take any clique $C$ in the memorial graph.

Notice that the vertices of $C$ are a subset of a path from root to some leaf in Soroush's tree. So it's sufficient to solve the task for every leaf in Soroush's tree, specifically we should consider subsets of the paths starting from the root and ending in a leaf in Soroush's tree.

Assume you have a data structure that supports the following operations:

1. Insert a vertex.
2. Erase a vertex.
3. Among the vertices inside it, find the biggest set of vertices $S$ such that none of them is the ancestor of the other in Keshi's tree.

To solve the task, start doing DFS from the root of Soroush's tree. Every time you visit a new vertex $v$, add $v$ using the $1$-st operation. Every time you finish doing DFS in a vertex $v$, erase $v$ using the $2$-nd operation.

It's easy to see that the vertices in the data structure always form a path from root to some vertex $v$ in Soroush's tree.

The answer to the task is the maximum size of $S$ in the $3$-rd operation for every leaf $u$ of Soroush's tree, when adding $u$ has been the last operation in the data structure; In other words $ans = max(ans , x)$ where $x$ is the size of $S$ in the $3$-rd operation whenever you reach a leaf while doing DFS in Soroush's tree.

When adding a vertex $v$ to the data structure, if no vertex $u \in S$ existed such that $u$ was in $v$'s subtree in Keshi's tree, consider the following cases:

* If no ancestor of $v$ was in $S$, greedily add $v$ to $S$.
* Otherwise, let that ancestor be $w$, erase $w$ from $S$ and add $v$ instead.

On the other hand, if such a vertex $u$ already existed in $S$, we won't add $v$ to $S$ based on the greedy solution mentioned above.

Whatever notation used from here onwards refers to Keshi's tree unless stated.

Do a DFS on the tree and find the starting time/finishing time for each vertex.

It's widely known that vertex $v$ is an ancestor of vertex $u \iff$ $st_v \le st_u$ and $ft_v \ge ft_u$.

Observation: for any pair of vertices $u$ and $v$, segments $[st_u , ft_u]$ and $[st_v , ft_v]$ either don't share an element or one of them lies completely inside the other.

To construct the aforementioned data structure:

Let the set $S$ be a maximal set of the vertices that form a clique in the memorial graph. For each vertex $v$ we store a pair $\{st_v , v\}$ in $S$. 

Now to check whether any vertex $u$ in the subtree of vertex $v$ exists in $S$: Let $p$ be the first pair in $S$ such that the first element in $p \ge st_v$. If $p$'s second element's finishing time is less than $ft_v$ then $p$'s second element is in $v$'s subtree, otherwise it's not.

Now to check whether any ancestor of $v$ is in $S$ or not: Let $p$ be the first pair in $S$ such that $p$'s first element is less than $st_v$, it can be proved that if an ancestor $u$ of $v$ exists in $S$, then $p = \{st_u , u\}$, thus we can check if $v$ is in the subtree of $p$'s second element by the aforementioned observation.

Doing the erase operation is also possible by keeping a history of the deleted elements from the set $S$.

complexity: $\mathcal{O}(n \log n)$

 **official solution**
```cpp
#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'n', 0;
 
const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;
 
int n, m, k, u, v, x, y, t, a, b, ans;
int par1[MAXN], par2[MAXN];
int stt[MAXN], fnt[MAXN], timer;
vector<int> G1[MAXN], G2[MAXN];
set<pii> st;
 
int Add(int v){
	auto it=st.lower_bound({stt[v], v});
	if (it!=st.end() && fnt[it->second]<=fnt[v]) return -2;
	if (it==st.begin()) return -1;
	--it;
	int res=it->second;
	if (fnt[v]>fnt[res]) return -1;
	st.erase(it);
	return res;
}
void dfs1(int node){
	stt[node]=timer++;
	for (int v:G2[node]) dfs1(v);
	fnt[node]=timer;
}
void dfs2(int node){
	int res=Add(node);
	if (res!=-2) st.insert({stt[node], node});
	ans=max(ans, (int)st.size());
	for (int v:G1[node]) dfs2(v);
	if (res!=-2){
		st.erase({stt[node], node});
		if (res!=-1) st.insert({stt[res], res});
	}
}
 
void Solve(){
	cin>>n;
	for (int i=1; i<=n; i++) G1[i].clear(), G2[i].clear();
	for (int i=2; i<=n; i++) cin>>par1[i], G1[par1[i]].pb(i);
	for (int i=2; i<=n; i++) cin>>par2[i], G2[par2[i]].pb(i);
	timer=1;
	ans=0;
	dfs1(1);
	dfs2(1);
	cout<<ans<<"n";
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
```
 **better implementation of official solution: AaParsa**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
 
#define X first
#define Y second
#define endl 'n'
 
const int N = 3e5 + 10;
 
int t, n, L[N], R[N], timer, now, ans;
vector<int> Srsh[N], Msht[N];
set<pii> st;
 
void MshtDFS(int u) {
    L[u] = timer++;
    for (int v : Msht[u]) {
        MshtDFS(v);
    }
    R[u] = timer;
}
 
int ispar(int u, int v) {
    return L[u] <= L[v] && R[v] <= R[u];
}
 
void SrshDFS(int u) {
    int last = now;
    // add u
    auto it = st.lower_bound({L[u], 0});
    if (it != st.end())
        now += 1 - ispar(u, it->Y);
    if (it != st.begin()) {
        auto nxt = it--;
        now += 1 - ispar(it->Y, u);
        if (nxt != st.end())
            now -= 1 - ispar(it->Y, nxt->Y);
    }
    st.insert({L[u], u});
    ans = max(ans, now);
    // DFS
    for (int v : Srsh[u]) {
        SrshDFS(v);
    }
    // remove u
    st.erase({L[u], u});
    now = last;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> t;
    while (t --> 0) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            Srsh[i].clear();
            Msht[i].clear();
        }
        for (int u = 2; u <= n; u++) {
            int par; cin >> par;
            Srsh[par].push_back(u);
        }
        for (int u = 2; u <= n; u++) {
            int par; cin >> par;
            Msht[par].push_back(u);
        }
        timer = 0;
        MshtDFS(1);
        ans = now = 0;
        SrshDFS(1);
        cout << ans + 1 << endl;
    }
    return 0;
}
```
 **python solution: Tet**
```cpp
#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase
 
# region fastio
 
BUFSIZE = 8192
 
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("rn")
    
class FenwickTree:
    def __init__(self, x):
        """transform list into BIT"""
        self.bit = x
        for i in range(len(x)):
            j = i | (i + 1)
            if j < len(x):
                x[j] += x[i]
    def update(self, idx, x):
        """updates bit[idx] += x"""
        while idx < len(self.bit):
            self.bit[idx] += x
            idx |= idx + 1
 
    def query(self, end):
        """calc sum(bit[:end])"""
        end += 1
        x = 0
        while end:
            x += self.bit[end - 1]
            end &= end - 1
        return x
 
    def findkth(self, k):
        """Find largest idx such that sum(bit[:idx]) <= k"""
        idx = -1
        for d in reversed(range(len(self.bit).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(self.bit) and k >= self.bit[right_idx]:
                idx = right_idx
                k -= self.bit[idx]
        return idx + 1
 
g1 = []
g2 = []
st = []
ft = []
 
def dfs1(graph, start=0):
    n = len(graph)
    tim = 1
    visited = [False] * n    
    stack = [start]
    while stack:
        start = stack[-1]
        if not visited[start]:
            st[start] = tim
            tim = tim + 1
            visited[start] = True
            for child in graph[start]:
                if not visited[child]:
                    stack.append(child)
        else:
            stack.pop()
            ft[start] = tim
 
 
 
def Do(v):
    global ans , cnt , mem
    fen.update(st[v] , 1);
    if(fen.query(ft[v] - 1) - fen.query(st[v])):
        mem += [[v , 0 , 0]]
        return;
    u = fen2.query(st[v]);
    ok[v] = 1
    cnt += 1
    fen2.update(st[v] , v - u)
    fen2.update(ft[v] , u - v)
    mem += [[v , u , ok[u]]]
    cnt -= ok[u]
    ok[u] = 0
    return;
 
 
 
def undo():
    global cnt , ans , mem
    [v , u , a] = mem[-1]
    if(a != 0):
        ok[u] = 1
        cnt += 1
    cnt -= 1
    ok[v] = 0
    fen.update(st[v] , -1)
    fen2.update(st[v] , u - v)
    fen2.update(ft[v] , v - u)
    mem.pop()
    return;
 
 
def dfs(graph, start=0):
    global ans , cnt
    n = len(graph)
    visited = [False] * n   
    stack = [start]
    while stack:
        start = stack[-1]
        if not visited[start]:
            Do(start)
            ans = max(ans , cnt)
            visited[start] = True
            for child in graph[start]:
                if not visited[child]:
                    stack.append(child)
        else:
            stack.pop()
            undo()
 
 
 
def solve():
    global n, g1 , g2 , V , st , ft , fen , fen2 , mem , ok , cnt , ans 
    n = int(input())
    if(n == 1):
        print(1)
        exit(0)
    
    g1 = [] ; g2 = []
    
    for i in range(n):
        g1.append([])
        g2.append([])
    
    
# 0 base 
    
    V = list(map(int , input().split()))
    
    for i in range ( 1 , n ):
        v = V[i - 1]-1
        g1[v].append(i)
    
    V = list(map(int , input().split()))    
    
    for i in range ( 1 , n ):
        v = V[i-1]-1
        g2[v].append(i)
    st = [0] * (n + 100)
    ft = [0] * (n + 100)
    fen = FenwickTree([0] * (n + 3))
    fen2 = FenwickTree([0] * (n + 3))
    mem = []
    ok = [0]*(n + 100)
    cnt = 0
    ans = 0
    dfs1(g2)
    dfs(g1)
    print(ans)
 
q = int(input())
for i in range (q):
    solve()
```
 **another O(n.log) solution with seg-tree: N.N_2004**
```cpp
#include<bits/stdc++.h>
#define lc (id * 2)
#define rc (id * 2 + 1)
#define md ((s + e) / 2)
#define dm ((s + e) / 2 + 1)
#define ln (e - s + 1)
using namespace std;
 
typedef long long ll;
const ll MXN = 3e5 + 10;
const ll MXS = MXN * 4;
ll n, timer, ans, Ans;
ll lazy[MXS], seg[MXS];
ll Stm[MXN], Ftm[MXN];
vector<ll> adj[MXN][2];
void Build(ll id = 1, ll s = 1, ll e = n){
    lazy[id] = -1, seg[id] = 0;
    if(ln > 1) Build(lc, s, md), Build(rc, dm, e);
}
void Shift(ll id, ll s, ll e){
    if(lazy[id] == -1) return;
    seg[id] = lazy[id];
    if(ln > 1) lazy[lc] = lazy[rc] = lazy[id];
    lazy[id] = -1;
}
void Upd(ll l, ll r, ll x, ll id = 1, ll s = 1, ll e = n){
    Shift(id, s, e);
    if(e < l || s > r) return;
    if(l <= s && e <= r){
        lazy[id] = x; Shift(id, s, e);
        return;
    }
    Upd(l, r, x, lc, s, md), Upd(l, r, x, rc, dm, e);
    seg[id] = max(seg[lc], seg[rc]);
}
ll Get(ll l, ll r, ll id = 1, ll s = 1, ll e = n){
    Shift(id, s, e);
    if(e < l || s > r) return 0;
    if(l <= s && e <= r) return seg[id];
    return max(Get(l, r, lc, s, md), Get(l, r, rc, dm, e));
}
void prep(ll u, ll par, ll f){
    Stm[u] = ++ timer;
    for(auto v : adj[u][f]){
        if(v != par) prep(v, u, f);
    }
    Ftm[u] = timer;
}
bool Is_Jad(ll j, ll u){
    return (Stm[j] <= Stm[u] && Ftm[u] <= Ftm[j]);
}
void DFS(ll u, ll par, ll f){
    ll j = Get(Stm[u], Ftm[u]);
    if(!j) Upd(Stm[u], Ftm[u], u), ans ++;
    else{
        if(Is_Jad(j, u)){
            Upd(Stm[j], Ftm[j], 0);
            Upd(Stm[u], Ftm[u], u);
        }
    }
    Ans = max(Ans, ans);
    for(auto v : adj[u][f]){
        if(v != par) DFS(v, u, f);
    }
    if(!j) Upd(Stm[u], Ftm[u], 0), ans --;
    else{
        if(Is_Jad(j, u)){
            Upd(Stm[u], Ftm[u], 0);
            Upd(Stm[j], Ftm[j], j);
        }
    }
}
void solve(){
    cin >> n, timer = ans = Ans = 0;
    for(int i = 1; i <= n; i ++) adj[i][0].clear(), adj[i][1].clear();
    for(int t = 0; t < 2; t ++) for(int u = 2, v; u <= n; u ++){
        cin >> v, adj[v][t].push_back(u), adj[u][t].push_back(v);
    }
    Build(), prep(1, 0, 1);
    DFS(1, 0, 0);
    cout << Ans << 'n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    ll q; cin >> q;
    while(q --) solve();
    return 0;
}
/*!
    HE'S AN INSTIGATOR,
    ENEMY ELIMINATOR,
    AND WHEN HE KNOCKS YOU BETTER
    YOU BETTER LET HIM IN.
*/
//! N.N
```
[1528D - It's a bird! No, it's a plane! No, it's AaParsa!](https://codeforces.com/contest/1528/problem/D "Codeforces Round 722 (Div. 1)")

problem idea and solution: [AmShZ](https://codeforces.com/profile/AmShZ "Grandmaster AmShZ"), [AliShahali1382](https://codeforces.com/profile/AliShahali1382 "International Grandmaster AliShahali1382")

 **editorial**
### [1528D - It's a bird! No, it's a plane! No, it's AaParsa!](https://codeforces.com/contest/1528/problem/D "Codeforces Round 722 (Div. 1)")

Suppose we did normal dijkstra, the only case that might be missed is when we wait in a vertex for some time.

To handle the 'waiting' concept, we can add $n$ fake edges, $i$-th of which is from the $i$-th vertex to the $(i+1 \mod n)$ -th vertex with weight equal to one.

Note that unlike the cannons, fake edges do not rotate.

It can be proved that doing dijkstra in the new graph is sufficient if we guarantee that the first used edge is not fake.

We can map waiting for $x$ seconds and then using an edge to go to $u$ from $v$ to using a cannon and then using $x$ fake edges to go to $u$ from $v$.

Also due to the strict time limit you should use the $\mathcal{O}(n^2)$ variant of dijkstra.

complexity: $\mathcal{O}(n^3)$

 **official solution**
```cpp
#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'n', 0;
 
const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int N=605;
 
int n, m, k, u, v, x, y, t, a, b;
bool mark[N];
int G[N][N], D[N];

inline void upd(int &x, int y){ if (x>y) x=y;}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	memset(G, 63, sizeof(G));
	cin>>n>>m;
	while (m--){
		cin>>u>>v>>x;
		G[u][v]=min(G[u][v], x);
	}
	for (int i=0; i<n; i++){
		memset(D, 63, sizeof(D));
		memset(mark, 0, sizeof(mark));
		for (int v=0; v<n; v++) upd(D[v], G[i][v]);
		while (1){
			int v=-1;
			for (int x=0; x<n; x++) if (!mark[x]){
				if (v==-1 || D[v]>D[x]) v=x;
			}
			if (v==-1) break ;
			mark[v]=1;
			upd(D[(v+1)%n], D[v]+1);
			for (int u=0; u<n; u++)
				upd(D[(u+D[v])%n], D[v]+G[v][u]);
			
		}
		for (int j=0; j<n; j++){
			if (i==j) cout<<"0 ";
			else cout<<D[j]<<" ";
		}
		cout<<"n";
	}
	
	return 0;
}
```
 **a different O(n^3) solution: Atreus**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn = 600 + 5;
 
int n;
int dp[maxn];
bool mark[maxn];
vector<pair<int,int>> g[maxn];
int go[maxn];
 
int dis(int s, int t) {
	if (s <= t)
		return t - s;
	return n - (s - t);
}
 
void dijkstra(int src) {
	memset(dp, 63, sizeof dp);
	memset(mark, 0, sizeof mark);
	dp[src] = 0;
	set<int> S;
	for (int i = 0; i < n; i++)
		S.insert(i);
	for (int i = 0; i < n - 1; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (mark[j])
				continue;
			if (v == -1 or dp[v] > dp[j])
				v = j;
		}
		S.erase(v);
		mark[v] = 1;
		if (v != src) {
			auto it = S.lower_bound(v);
			if (it == S.end())
				it = S.lower_bound(0);
			int nex = *it;
			dp[nex] = min(dp[nex], dp[v] + dis(v, nex));
		}
		for (int i = 2 * n - 1; i >= 0; i--) {
			int v = i % n;
			if (!mark[v])
				go[v] = v;
			else
				go[v] = go[(v + 1) % n];
		}
		for (auto [u, w] : g[v]) {
			int nex = go[(u + dp[v]) % n];
			dp[nex] = min(dp[nex], dp[v] + w + dis((u + dp[v]) % n, nex));
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) { 
		int v, u, w;
		cin >> v >> u >> w;
		g[v].push_back({u, w});
	}
	for (int i = 0; i < n; i++) {
		dijkstra(i);
		for (int j = 0; j < n; j++)
			cout << dp[j] << " n"[j == n-1];
	}
}
```
[1528E - Mashtali and Hagh Trees](https://codeforces.com/contest/1528/problem/E "Codeforces Round 722 (Div. 1)")

problem idea and solution: [AliShahali1382](https://codeforces.com/profile/AliShahali1382 "International Grandmaster AliShahali1382")

Thanks to [Kininarimasu](https://codeforces.com/profile/Kininarimasu "Master Kininarimasu") for the editorial.

 **editorial**
### [1528E - Mashtali and Hagh Trees](https://codeforces.com/contest/1528/problem/E "Codeforces Round 722 (Div. 1)")

Let $dp_i$ be the answer for all trees such that there exists a root and all edges are directed in the same direction from root and the root has at most $2$ children. We transition:

$dp_i = dp_{i−1}+dp_{i−1} \cdot pdp_{i−2}+\frac{dp_{i−1} \cdot (dp_{i−1}+1)}{2}$ where $pdp_i = \sum_{j = 0}^{i}{dp_j}$.

Then let $dp2_i$ be the same as $dp_i$ except the root must have exactly $2$ children. So $dp2_i = dp_i−dp_{i−1}$.

The answer for these cases is:

$2 \cdot (dp_n+\frac{ dp_{n−1} \cdot pdp_{n−2} \cdot (pdp_{n−2}+1)}{2}+\frac{pdp_{n−2} \cdot dp_{n−1} \cdot (dp_{n−1}+1)}{2}+ \frac{dp_{n−1} \cdot (dp_{n−1}+1) \cdot (dp_{n−1}+2)}{6})−1$.

This is because $dp_n$ holds the answer for at most $2$ children and the other section accounts for the rest. We multiply by $2$ to account for both edges directions, and subtract $1$ because a single path is isomorphic.

This obviously doesn't handle all cases, but all other cases can be found in the following form. Let $t_{up,k}$ be a tree where the root has $2$ children and the edges are directed up and the longest path is $k$, and let $t_{down,k}$ be a tree where the root has $2$ children and the edges are directed down and the longest path is $k$. Then all other cases are $t_{up,k}$ which exists on some path of length $l$ to and connects to $t_{down,n−k−l}$.

We can count every other case as $\sum_{i=0}^{n-1}{(dp_{i}-1) \cdot dp2_{n−1−i}}$

This works because we pretend the path is always length $1$, then if we do $dp_i \cdot dp2_{n−1−i}$ we handle all cases except for when the $t_{up,k}$ is empty, and that only happens once.

 **official solution**
```cpp
#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'n', 0;
 
const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=998244353, inv6=166374059;
const int MAXN=1000010, LOG=20;
 
ll n, m, k, u, v, x, y, t, a, b, ans;
ll dp[MAXN], ps[MAXN];
ll pd[MAXN], sp[MAXN];
 
ll C3(ll x){
	return x*(x-1)%mod*(x-2)%mod*inv6%mod;
}
ll C2(ll x){
	return x*(x-1)/2%mod;
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	dp[0]=ps[0]=1;
	pd[0]=sp[0]=1;
	for (int i=1; i<=n; i++){
		ps[i]=(1 + ps[i-1] + ps[i-1]*(ps[i-1]+1)/2)%mod;
		dp[i]=ps[i]-ps[i-1];
		pd[i]=dp[i]-dp[i-1];
		sp[i]=(sp[i-1]+pd[i])%mod;
	}
	for (int i=0; i<n; i++) ans=(ans + pd[i]*sp[n-1-i])%mod;
	
	ans=(ans + 2*C3(ps[n-1]+2))%mod;
	if (n>=2) ans=(ans - 2*C3(ps[n-2]+2))%mod;
	
	ans=(ans + 2*C2(ps[n-1]+1))%mod;
	if (n>=2) ans=(ans - 2*C2(ps[n-2]+1))%mod;
	
	if (ans<0) ans+=mod;
	cout<<ans<<"n";
	
	return 0;
}
```
[1528F - AmShZ Farm](https://codeforces.com/contest/1528/problem/F "Codeforces Round 722 (Div. 1)")

problem idea and solution: [AmShZ](https://codeforces.com/profile/AmShZ "Grandmaster AmShZ"), [AliShahali1382](https://codeforces.com/profile/AliShahali1382 "International Grandmaster AliShahali1382")

 **editorial**
### [1528F - AmShZ Farm](https://codeforces.com/contest/1528/problem/F "Codeforces Round 722 (Div. 1)")

Consider the following problem: $n$ cars want to enter a parking lot one by one. The parking lot has $n$ slots numbered $1, 2 , \ldots , n$, the $i$-th of the $n$ cars wants to park in the $a_i$-th slot.

When the $i$-th car drives in, it will park in the first empty slot $s$ such that $s \ge a_i$.

An array $a$ is Good if all of the cars are parked in some slot after the end of the procedure.

Good arrays can be mapped to more-equal arrays, because it can be proved that in any sorted Good array $a_i \le i$, same goes for the more-equal arrays.

Now let's modify the above problem a bit, consider a circular parking lot with $n + 1$ free slots. $n$ cars want to park in it, $i$-th of which wants to park in the $a_i$-th slot $(1 \le a_i \le n + 1)$.

When the $i$-th car drives in, it will park in the first empty slot $s$ such that $s$ is the first empty slot after (including) $a_i$ in the clockwise direction.

It's obvious that one slot will be empty after the end of the procedure, let's call this slot $x$.

Arrays in which $x = n+1$ can also be mapped to more-equal arrays, let them be good arrays. let the other arrays be called bad arrays (arrays in which $x \neq n+1$).

Every good can mapped to $n$ bad arrays, just add $x$ $(1 \le x \le n)$ to all of elements of $a$, formally speaking for each $i$ $(1 \le i \le n)$, $a_i = ((a_i + x )\mod_{n + 1} + 1)$. This can also be viewed as a circular shift of the elements/final positions.

Note that the number of arrays compatible with $a$ stays the same in this proccess.

Thus the number of bad arrays is equal to $\frac{n}{n+1}$ of all the possible $(n + 1)^n$ arrays.

We know that $a_{b_1} = a_{b_2} = \ldots = a_{b_k}$, assume $a_{b_1} = x$, let's fix $x$ $(1 \le x \le n+1)$, let $CNT$ be the number of occurrences of $x$ in $a$. The number of compatible arrays $b$ such that $a_{b_j} = x$ $(1 \le j \le k)$ is equal to $CNT^k$.

So the number of pairs of arrays $a$ and $b$ where $b$ is a compatible array with the more-equal array $a$ is equal to $\sum_{CNT = 0}^{n}{{n}\choose{CNT}} \cdot n^{n-CNT} \cdot CNT^k$.

There are $n+1$ ways to choose $x$, also we had to divide the result by $n + 1$ because we were previously counting bad arrays as well, so we can simplify both of this terms with each other.

The sum $\sum_{CNT = 0}^{n}{{n}\choose{CNT}} \cdot n^{n-CNT} \cdot CNT^k$ mentioned above is equal to $\sum_{i = 1}^{k}{S(k , i) \cdot i! \cdot {{n}\choose{i}} \cdot (n+1)^{(n-i)}}$, where $S$ refers to Stirling numbers of the second kind. 

All of $S(k , i)$ can be found in $\mathcal{O}(k\log k)$ using FFT.

So overall we can solve the task in $\mathcal{O}(k\log k)$.

 **official solution**
```cpp
# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;
 
# define A                                               first

# define B                                               second

# define endl                                            'n'

# define sep                                             ' '

# define all(x)                                          x.begin(), x.end()

# define kill(x)                                         return cout << x << endl, 0

# define SZ(x)                                           int(x.size())

# define lc                                              id << 1

# define rc                                              id << 1 | 1

# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e5 + 10;
const int xm = 18;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
 
int n, k, C[xn], ans, A[xn], B[xn], rev[xn];
int fact[xn], ifact[xn];
 
void NTT(int *A, bool inv){
	int n = (1 << xm);
	for (int i = 0; i < (1 << xm); ++ i)
		if (rev[i] < i)
			swap(A[i], A[rev[i]]);
	for (int ln = 1; ln < n; ln <<= 1){
		int w = power(3, mod / 2 / ln, mod);
		if (inv)
			w = power(w, mod - 2, mod);
		for (int i = 0; i < n; i += ln + ln){
			int wn = 1;
			for (int j = i; j < i + ln; ++ j){
				int x = A[j], y = 1ll * A[j + ln] * wn % mod;
				A[j] = (x + y) % mod;
				A[j + ln] = (x - y + mod) % mod;
				wn = 1ll * wn * w % mod;
			}
		}
	}
	if (inv){
		int invn = power(1 << xm, mod - 2, mod);
		for (int i = 0; i < n; ++ i)
			A[i] = 1ll * A[i] * invn % mod;
	}
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> k;
	C[0] = fact[0] = 1;
	for (int i = 1; i < xn; ++ i){
		C[i] = 1ll * C[i - 1] * (n - i + 1) % mod * power(i, mod - 2, mod) % mod;
		fact[i] = 1ll * fact[i - 1] * i % mod;
	}
	ifact[xn - 1] = power(fact[xn - 1], mod - 2, mod);
	for (int i = xn - 2; i >= 0; -- i)
		ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
	for (int i = 1; i < (1 << xm); ++ i)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (xm - 1));
	for (int i = 0; i <= k; ++ i){
		A[i] = 1ll * power(i, k, mod) * ifact[i] % mod;
		B[i] = ifact[i];
		if (i % 2)
			B[i] = (mod - B[i]) % mod;
	}
	NTT(A, 0), NTT(B, 0);
	for (int i = 0; i < xn; ++ i)
		A[i] = 1ll * A[i] * B[i] % mod;
	NTT(A, 1);
	for (int i = 1; i <= k; ++ i)
		ans = (ans + 1LL * A[i] * C[i] % mod * power(n + 1, n - i, mod) % mod * fact[i] % mod) % mod;
	cout << ans << endl;
 
	return 0;
}
```
