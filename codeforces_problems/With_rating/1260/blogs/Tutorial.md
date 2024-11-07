# Tutorial

[1260A - Heating](../problems/A._Heating.md "Educational Codeforces Round 77 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1260A - Heating](../problems/A._Heating.md "Educational Codeforces Round 77 (Rated for Div. 2)")

Let's denote the number of sections in the i-th radiator as xi. Let's prove that in the optimal answer max(xi)−min(xi)<2. Proof by contradiction: suppose we have x and y≥x+2 in the answer, let's move 1 from y to x and check: (x+1)2+(y−1)2=x2+2x+1+y2−2y+1=(x2+y2)+2(x−y+1)<x2+y2 The answer is not optimal — contradiction.

Finally, there is the only way to take x1+x2+⋯+xc=sum with max(xi)−min(xi)≤1. And it's to take (summodc) elements with value ⌊sumc⌋+1 and c−(summodc) elements with ⌊sumc⌋.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

int c, sum;

inline bool read() {
	if(!(cin >> c >> sum))
		return false;
	return true;
}

inline void solve() {
	int d = sum / c;
	int rem = sum % c;
	cout << rem * (d + 1) * (d + 1) + (c - rem) * d * d << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n; cin >> n;
	while(n--) {
		read();
		solve();
	}
	return 0;
}
```
[1260B - Obtain Two Zeroes](../problems/B._Obtain_Two_Zeroes.md "Educational Codeforces Round 77 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1260B - Obtain Two Zeroes](../problems/B._Obtain_Two_Zeroes.md "Educational Codeforces Round 77 (Rated for Div. 2)")

Let's assume a≤b. Then the answer is YES if two following conditions holds: 

* (a+b)≡0mod3, because after each operation the value (a+b)mod3 does not change;
* a⋅2≥b.
 **Solution (Roms)**
```cpp
for t in range(int(input())):
	a, b = map(int, input().split())
	if a > b:
		a, b = b, a
	print ('YES' if ( ((a + b) % 3) == 0 and a * 2 >= b) else 'NO')
```
[1260C - Infinite Fence](../problems/C._Infinite_Fence.md "Educational Codeforces Round 77 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1260C - Infinite Fence](../problems/C._Infinite_Fence.md "Educational Codeforces Round 77 (Rated for Div. 2)")

At first, suppose that r≤b (if not — swap them). Let's look at the case, where gcd(r,b)=1. We can be sure that there will be a situation where the pos-th plank is painted in blue and pos+1 plank is painted in red. It's true because it's equivalent to the solution of equation r⋅x−b⋅y=1.

And all we need to check that interval (pos,pos+b) contains less than k red planks. Or, in formulas, (k−1)⋅r+1≥b.

The situation with gcd(r,b)>1 is almost the same if we look only at positions, which are divisible by gcd(r,b) — in other words we can just divide r on gcd and b on gcd and check the same condition.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long li;

li a, b, k;

inline bool read() {
	if(!(cin >> a >> b >> k))
		return false;
	return true;
}

inline void solve() {
	li g = __gcd(a, b);
	a /= g;
	b /= g;
	if(a > b)
		swap(a, b);
	if((k - 1) * a + 1 < b)
		cout << "REBEL";
	else
		cout << "OBEY";
	cout << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int tc; cin >> tc;
	while(tc--) {
		read();
		solve();
	}
	return 0;
}
```
[1260D - A Game with Traps](../problems/D._A_Game_with_Traps.md "Educational Codeforces Round 77 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1260D - A Game with Traps](../problems/D._A_Game_with_Traps.md "Educational Codeforces Round 77 (Rated for Div. 2)")

When we fix a set of soldiers, we can determine a set of traps that may affect our squad: these are the traps with danger level greater than the lowest agility value. So we can use binary search on minimum possible agility of a soldier that we can choose.

How should we actually bring our soldiers to the boss? Each trap that can affect our squad can be actually treated as a segment [li,ri] such that our squad cannot move to li until we move to ri and disarm this trap. We should walk through such segments for three times: the first time we walk forwards without our squad to disarm the trap, the second time we walk backwards to return to our squad, and the third time we walk forwards with our squad. So the total time we have to spend can be calculated as n+1+2T, where T is the number of unit segments belonging to at least one trap-segment — and it can be calculated with event processing algorithms or with segment union.

Time complexity is O(nlogn) or O(nlog2n), but it is possible to write a solution in O(nα(n)) without binary search.

 **Solution (BledDest)**
```cpp
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef pair<int, int> pt;

#define x first
#define y second


int m, n, k, t;
vector<int> l, r, d, a;

bool can(int x)
{
	int mn = int(1e9);
	for (int i = 0; i < x; i++)
		mn = min(mn, a[i]);
	vector<pt> segm;
	for (int i = 0; i < k; i++)
		if (d[i] > mn)
			segm.push_back(make_pair(l[i], r[i]));
	int req_time = 0;
	sort(segm.begin(), segm.end());
	int lastr = 0;
	for (auto s : segm)
	{
		if (s.x <= lastr)
		{
			req_time += max(0, s.y - lastr);
			lastr = max(s.y, lastr);
		}
		else
		{
			req_time += s.y - s.x + 1;
			lastr = s.y;
		}
	}
	req_time = 2 * req_time + n + 1;
	return req_time <= t;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d %d %d", &m, &n, &k, &t);
	a.resize(m);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	l.resize(k);
	r.resize(k);
	d.resize(k);
	for (int i = 0; i < k; i++)
		scanf("%d %d %d", &l[i], &r[i], &d[i]);

	int lf = 0;
	int rg = m + 1;
	while (rg - lf > 1)
	{
		int mid = (lf + rg) / 2;
		if (can(mid))
			lf = mid;
		else
			rg = mid;
	}
	printf("%dn", lf);
	return 0;
}
```
[1260E - Tournament](../problems/E._Tournament.md "Educational Codeforces Round 77 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1260E - Tournament](../problems/E._Tournament.md "Educational Codeforces Round 77 (Rated for Div. 2)")

If our friend is the strongest boxer, he wins without any bribing. Otherwise, we have to bribe the strongest boxer — and he can defeat some n2−1 other boxers (directly or indirectly). Suppose we chose the boxers he will defeat, then there is another strongest boxer. If our friend is the strongest now, we don't need to bribe anyone; otherwise we will bribe the strongest remaining boxer again, and he can defeat n4−1 other boxers, and so on.

The only thing that's unclear is which boxers should be defeated by the ones we bribe. We may use dynamic programming to bribe them: dpi,j is the minimum cost to bribe i boxers so that all boxers among j strongest ones are either bribed or defeated by some bribed boxer. For each value of i we know the maximum amount of boxers that are defeated by i bribed boxers, so the transitions in this dynamic programming are the following: if we can't defeat the next boxer "for free" (our bribed boxers have already defeated as many opponents as they could), we have to bribe him; otherwise, we either bribe him or consider him defeated by some other boxer.

Overall complexity is O(nlogn).

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int LOGN = 20;
const int N = (1 << LOGN) + 99;
const long long INF = 1e18;

int n;
int a[N];
long long dp[LOGN+2][N];
int sum[100];

long long calc(int cnt, int pos){
	long long &res = dp[cnt][pos];
	if(res != -1) return res;

	if(a[pos] == -1) return res = 0;
	int rem = sum[cnt] - pos;

	res = INF;
	if(cnt < LOGN)
		res = calc(cnt + 1, pos + 1) + a[pos];
	if(rem > 0)		
		res = min(res, calc(cnt, pos + 1));

	return res;
}

int main() {	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	for(int i = 1, x = n / 2; i < 100; ++i, x /= 2)
		sum[i] = sum[i - 1] + x;
	
	reverse(a, a + n);
	memset(dp, -1, sizeof dp);
	printf("%lld", calc(0, 0));	
	return 0;
}                             	
```
[1260F - Colored Tree](../problems/F._Colored_Tree.md "Educational Codeforces Round 77 (Rated for Div. 2)")

Idea: [RDDCCD](https://codeforces.com/profile/RDDCCD "Master RDDCCD")

 **Tutorial**
### [1260F - Colored Tree](../problems/F._Colored_Tree.md "Educational Codeforces Round 77 (Rated for Div. 2)")

Let's set the root as 1. Define lca(u,v) as the lowest common ancestor of vertices u and v, dep(u) as the depth of vertex u (dep(u)=dis(1,u)). Obviously dis(u,v)=dep(u)+dep(v)−2×dep(lca(u,v)).

The answer we want to calculate is ∑G∑hi=hj,i<jdis(i,j) where G represent all possible colorings of the tree.

We can enumerate the color c. For a fixed color c, we need to calculate ∑li≤c≤ri,lj≤c≤rj[dis(i,j)×∏k≠i,j(rk−lk+1)]

Let P=∏1≤i≤n(ri−li+1),gi=ri−li+1. Also denote V(i) as a predicate which is true iff li≤c≤ri.

∑li≤c≤ri,lj≤c≤rj[dis(i,j)×∏k≠i,j(rk−lk+1)]=∑V(i)∧V(j)dep(i)×Pgi×gj+∑V(i)∧V(j)dep(j)×Pgi×gj−2×∑V(i)∧V(j)dep(lca(i,j))×Pgi×gj=P×(∑V(i)dep(i)gi)×(∑V(i)1gi)−P×∑V(i)dep(i)g2i−2P×∑V(i)∧V(j)dep(lca(i,j))×1gi×gj

Now our problem is how to maintain this formula while enumerating the color c. 

P×(∑V(i)dep(i)gi)×(∑V(i)1gi) can be easily maintained. For ∑V(i)∧V(j)dep(lca(i,j))×1gi×gj, we can add 1gi to all vertices in path i to 1 (for each existing vertex i), and when new vertex is added, just calculate the sum of vertices on path from i to 1, minus the contribution of vertex 1 (because there are dep(u)+1 vertices in the path u to 1), and multiply it 1gi. Similar operation can be used to handle the situation when some vertex disappears. All of this can be done with HLD.

Overall it's O(cmax+nlog2(n)).

 **Solution (RDDCCD)**
```cpp
#include<bits/stdc++.h>
using namespace std;
int n ;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7 ;
vector<int> E[maxn];
vector<int> in[maxn] , out[maxn];
int cm = 0;
int l[maxn] , dfn = 0 , dep[maxn];
int g[maxn];
int siz[maxn] , top[maxn] , h[maxn] , f[maxn];
///-----segment tree
struct seg
{
    int l , r;
    int sum , add ;
}Node[maxn * 4];

void build(int u,int l,int r)
{
    Node[u].l = l , Node[u].r = r;
    Node[u].sum = Node[u].add = 0;
    if(l == r) return ;
    build(u<<1 , l , (l + r >> 1));
    build(u<<1|1 , (l + r >>1) + 1 , r);
    return ;
}
void pd(int u)
{
    Node[u].sum = (1LL*Node[u].add*(Node[u].r - Node[u].l + 1) + Node[u].sum) % mod ;
    if(Node[u].l == Node[u].r) {
        Node[u].add = 0 ;return ;
    }
    (Node[u<<1].add += Node[u].add ) %= mod;
    (Node[u<<1|1].add += Node[u].add ) %= mod;
    Node[u].add = 0 ; return ;
}
void modify(int u,int l,int r,int v)
{
    if(Node[u].l == l && Node[u].r == r) {
        (Node[u].add += v ) %= mod;
        pd(u) ; return ;
        return ;
    }
    pd(u) ;
    if(Node[u<<1].r >= r) {modify(u<<1 , l , r , v) ; pd(u<<1|1);}
    else if(Node[u<<1|1].l <= l) {modify(u<<1|1 , l , r , v) ; pd(u<<1) ;}
    else {
        modify(u<<1 , l , Node[u<<1].r , v) ;
        modify(u<<1|1 , Node[u<<1|1].l , r , v);
    }
    Node[u].sum = (Node[u<<1].sum + Node[u<<1|1].sum) % mod;
    return ;
}
int query(int u,int l,int r)
{
    pd(u) ;
    if(Node[u].l == l && Node[u].r == r) return Node[u].sum ;
    if(Node[u<<1].r >= r) return query(u<<1 , l , r) ;
    else if(Node[u<<1|1].l <= l) return query(u<<1|1 , l , r);
    else return (query(u<<1 , l , Node[u<<1].r) + query(u<<1|1 , Node[u<<1|1].l , r)) % mod;
}
///---segment tree end
void dfs(int fa,int u,int d)
{
    f[u] = fa;
    dep[u] = d;siz[u] = 1;h[u] = -1;
    for(int i = 0;i < E[u].size();i++) {
        if(E[u][i] != fa) {
            dfs(u , E[u][i] , d + 1) ;siz[u] += siz[E[u][i]];
            if(h[u] == -1 || siz[E[u][i]] > siz[E[u][h[u]]]) h[u] = i;
        }
    }
    return ;
}
void dfs2(int fa,int u)
{
    l[u] = ++dfn;
    if(h[u] != -1) {
        top[E[u][h[u]]] = top[u] ;
        dfs2(u , E[u][h[u]]);
    }
    for(int i = 0;i < E[u].size();i++) {
        if(E[u][i] != fa && i != h[u]) {
            top[E[u][i]] = E[u][i] ;
            dfs2(u , E[u][i]) ;
        }
    }
    return ;
}
int fpow(int a,int b)
{
    int ans = 1;
    while(b) {
        if(b & 1) ans = (1LL * ans * a) % mod;
        a = (1LL * a * a) % mod ;b >>= 1;
    }
    return ans;
}
void add(int u,int v)
{
    while(u) {
        modify(1 , l[top[u]] , l[u] , v) ;
        u = f[top[u]] ;
    }
    return ;
}
int cal(int u)
{
    int ans = mod - query(1 , 1 , 1);
    while(u) {
        ans = (ans + query(1 , l[top[u]] , l[u])) % mod;
        u = f[top[u]] ;
    }
    return ans;
}
int main()
{
    scanf("%d",&n) ;
    int P = 1;
    for(int i = 1;i <= n;i++) {
        int l , r;scanf("%d%d",&l,&r) ;
        in[l].push_back(i) ;
        out[r + 1].push_back(i) ; cm = max(cm , r);
        g[i] = fpow(r - l + 1 , mod - 2) ;
        P = 1LL * P * (r - l + 1) % mod;
    }
    for(int i = 1;i < n;i++) {
        int u , v;scanf("%d%d",&u,&v) ;
        E[u].push_back(v) ; E[v].push_back(u) ;
    }
    dfs(0 , 1 , 0) ; top[1] = 1;
    dfs2(0 , 1) ;
    build(1 , 1 , n) ;
    int ans = 0 , cur = 0;
    int d1 = 0 , d2 = 0 , u , d3 = 0;
    for(int i = 1;i <= cm;i++) {
        for(int j = 0;j < out[i].size();j++) {
            u = out[i][j] ;
            d1 = (d1 - 1LL * dep[u] * g[u] % mod + mod) % mod;
            d2 = (d2 - g[u] + mod) % mod ;
            d3 = (d3 - 1LL*dep[u]*g[u] % mod * g[u] % mod + mod) % mod;
            add(u , mod - g[u]) ;
            cur = (cur - 1LL * g[u] * cal(u) % mod + mod) % mod;
        }
        for(int j = 0;j < in[i].size();j++) {
            u = in[i][j] ;
            d1 = (d1 + 1LL * dep[u] * g[u]) % mod;
            d2 = (d2 + g[u]) % mod;
            d3 = (d3 + 1LL*dep[u]*g[u]%mod*g[u]) % mod;
            cur = (cur + 1LL * g[u] * cal(u)) % mod;
            add(u , g[u]) ;
        }
        ans = (ans + 1LL * d1 * d2%mod - 2LL*cur - d3) % mod;
        ans = (ans + mod) % mod;
    }
    ans = 1LL * ans * P % mod;
    printf("%dn",ans);
    return 0;
}
```
