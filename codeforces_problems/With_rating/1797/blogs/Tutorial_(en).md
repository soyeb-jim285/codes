# Tutorial_(en)

[1797A - Li Hua and Maze](../problems/A._Li_Hua_and_Maze.md "Codeforces Round 864 (Div. 2)")

 **Tutorial**
### [1797A - Li Hua and Maze](../problems/A._Li_Hua_and_Maze.md "Codeforces Round 864 (Div. 2)")

We can put obstacles around (x1,y1) or (x2,y2) and the better one is the answer. More formally, let's define a function f:

f(x,y)={2,(x,y) is on the corner3,(x,y) is on the border4,(x,y) is in the middle

Then the answer is min{f(x1,y1),f(x2,y2)}.

Without loss of generality, assume that f(x1,y1)≤f(x2,y2). As the method is already given, the answer is at most f(x1,y1). Let's prove that the answer is at least f(x1,y1).

If (x1,y1) is on the corner, we can always find two paths from (x1,y1) to (x2,y2) without passing the same cell (except (x1,y1) and (x2,y2)).

 

|  |
| --- |

 Similarly, we can always find three or four paths respectively if (x1,y1) is on the border or in the middle.

 

|  |
| --- |

 As the paths have no common cell, we need to put an obstacle on each path, so the answer is at least f(x1,y1).

In conclusion, the answer is exactly f(x1,y1). As we assumed that f(x1,y1)≤f(x2,y2), the answer to the original problem is min{f(x1,y1),f(x2,y2)}.

Time complexity: O(1).

 **Solution (rui_er)**
```cpp
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
 
#define y1 y114514
int T, n, m, x1, y1, x2, y2;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int f(int x, int y) {
	if((x == 1 || x == n) && (y == 1 || y == m)) return 2;
	if(x == 1 || x == n || y == 1 || y == m) return 3;
	return 4;
}
 
int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2);
		printf("%dn", min(f(x1, y1), f(x2, y2)));
	}
	return 0;
}
```
[1797B - Li Hua and Pattern](../problems/B._Li_Hua_and_Pattern.md "Codeforces Round 864 (Div. 2)")

 **Tutorial**
### [1797B - Li Hua and Pattern](../problems/B._Li_Hua_and_Pattern.md "Codeforces Round 864 (Div. 2)")

We can calculate the minimum needed operations kmin easily by enumerating through the cells and performing an operation if the color of the cell is different from the targeted cell. Obviously, if k<kmin, the problem has no solution.

Otherwise, there are two cases:

* If 2∣n, the solution exists if and only if 2∣(k−kmin), as we must perform two operations each time to meet the requirement.
* If 2∤n, the solution always exists, as we can perform the remaining operations at the center of the pattern.

Time complexity: O(n2).

 **Solution (rui_er)**
```cpp
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e3+5;
 
int T, n, k, a[N][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
 
int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &k);
		rep(i, 1, n) rep(j, 1, n) scanf("%d", &a[i][j]);
		int diff = 0;
		rep(i, 1, n) rep(j, 1, n) if(a[i][j] != a[n+1-i][n+1-j]) ++diff;
		diff /= 2;
		if(diff > k) puts("NO");
		else {
			k -= diff;
			if(n & 1) puts("YES");
			else if(k & 1) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}
```
[1797C - Li Hua and Chess](../problems/C._Li_Hua_and_Chess.md "Codeforces Round 864 (Div. 2)")

 **Tutorial**
### [1797C - Li Hua and Chess](../problems/C._Li_Hua_and_Chess.md "Codeforces Round 864 (Div. 2)")

We can first ask (1,1) and get the result k. Obviously, the king must be on the following two segments: 

* from (1,k+1) to (k+1,k+1).
* from (k+1,1) to (k+1,k+1).

Then, we can ask (1,k+1) and (k+1,1) and get the results p,q. There are three cases:

* If p=q=k, the king is at (k+1,k+1).
* If p<k, the king is at (p+1,k+1).
* If q<k, the king is at (k+1,q+1).
 **Solution (rui_er)**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int T, n, m;
 
int ask(int x, int y) {
	printf("? %d %dn", x, y);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
 
void give(int x, int y) {
	printf("! %d %dn", x, y);
	fflush(stdout);
}
 
int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &m);
		int T1 = ask(1, 1);
		if(T1 >= n) {
			int T2 = ask(1, T1+1);
			give(T2+1, T1+1);
		}
		else if(T1 >= m) {
			int T2 = ask(T1+1, 1);
			give(T1+1, T2+1);
		}
		else {
			int T2 = ask(T1+1, 1);
			int T3 = ask(1, T1+1);
			if(T2 == T1 && T3 == T1) give(T1+1, T1+1);
			else if(T3 == T1) give(T1+1, T2+1);
			else give(T3+1, T1+1);
		}
	}
	return 0;
}
```
[1797D - Li Hua and Tree](../problems/D._Li_Hua_and_Tree.md "Codeforces Round 864 (Div. 2)")

 **Tutorial**
### [1797D - Li Hua and Tree](../problems/D._Li_Hua_and_Tree.md "Codeforces Round 864 (Div. 2)")

Denote Tx as the subtree of x.

The "rotate" operation doesn't change the tree much. More specifically, only the importance of Tfax,Tx,Tsonx changes. We can use the brute force method to maintain useful information about each vertex when the operations are performed.

What we need to do next is to find the heavy son of a vertex in a reasonable time. We can use a set to maintain the size and index of all the sons of each vertex.

Time complexity: O((n+m)logn).

 **Solution (rui_er)**
```cpp
//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e5+5; 
 
ll n, m, a[N], sz[N], son[N], fa[N], sum[N];
vector<ll> e[N];
set<tuple<ll, ll> > sons[N]; 
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(ll u, ll f) {
	sz[u] = 1;
	sum[u] = a[u];
	fa[u] = f;
	for(auto v : e[u]) {
		if(v == f) continue;
		dfs(v, u);
		sz[u] += sz[v];
		sum[u] += sum[v];
		sons[u].insert(make_tuple(-sz[v], v));
		if(sz[v] > sz[son[u]] || sz[v] == sz[son[u]] && v < son[u]) son[u] = v;
	}
}
 
int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n-1) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	while(m --> 0) {
		ll op, u;
		scanf("%lld%lld", &op, &u);
		if(op == 1) printf("%lldn", sum[u]);
		else {
			ll v = son[u];
			if(!v) continue;
			ll p = fa[u];
			sz[u] -= sz[v];
			sum[u] -= sum[v];
			sons[u].erase(make_tuple(-sz[v], v));
			son[u] = sons[u].empty() ? 0 : get<1>(*sons[u].begin());
			fa[u] = v;
			sz[v] += sz[u];
			sum[v] += sum[u];
			sons[v].insert(make_tuple(-sz[u], u));
			son[v] = get<1>(*sons[v].begin());
			fa[v] = p;
			sons[p].erase(make_tuple(-sz[v], u));
			sons[p].insert(make_tuple(-sz[v], v));
			son[p] = get<1>(*sons[p].begin());
		}
	}
	return 0;
}
```
[1797E - Li Hua and Array](../problems/E._Li_Hua_and_Array.md "Codeforces Round 864 (Div. 2)")

 **Tutorial**
### [1797E - Li Hua and Array](../problems/E._Li_Hua_and_Array.md "Codeforces Round 864 (Div. 2)")

Denote w=nmaxi=1{ai}. Also denote φk(x)={x,k=0φ(φk−1(x)),k∈N∗.

It can be proven that after O(logw) operations, any ai will become 1 and more operations are useless. In other words, φlog2w+1(ai)=1.

Let's construct a tree of size w, where 1 is the root and the father of k is φ(k). The height of the tree is O(logw). After some precalculating, we can find the LCA of two vertices within O(loglogw).

We can use a dsu to maintain the next not-1 element of each ai and use a segment tree to maintain the LCA, minimal depth, and answer in the range. We can brute force the changes using the dsu and meanwhile do point update on the segment tree. The queries can be solved using a range query on the segment tree.

With the potential method, we denote Φ(ai) as the minimum integer k which satisfies φk(ai)=1. Since each successful operation on ai will decrease Φ(ai) by 1, the maximum number of successful operations we can perform on ai is Φ(ai). Therefore, the maximum number of successful operations is n∑i=1Φ(ai)=O(nlogw).

For each successful operation, we visit O(logn) nodes on the segment tree and merge the information of two subtrees for O(logn) times. Because of the time complexity of calculating LCA, We need O(loglogw) time to merge the information. So all the operations will take up O(nlognlogwloglogw) time. We need to initialize φ within O(w) time and binary lifting the ancestors on the tree within O(wloglogw) time. We also need O(lognloglogw) for each query.

In conclusion, the time complexity is O(wloglogw+nlognlogwloglogw+mlognloglogw).

The above algorithm is enough to pass this problem. However, it has a mass number of information merging operations, so it runs quite slowly.

We use the segment tree not only to maintain the LCA, minimal depth, and answer of the ranges, but also whether Φ(lu;ru)=∑i∈[lu,ru]Φ(ai)=0. If we enter a node whose Φ(lu;ru)=0, we can just ignore it. Otherwise, we recursively work on the segment tree until leaf and brute force update its information.

Time complexity is the same but it's much more efficient.

Bonus: Can you solve this problem within O(mlogn)?

 **Solution (rui_er)**
```cpp
//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5 + 5, P = 4e5 + 5, K = 5e6 + 5, W = 5e6; 
 
int n, m, a[N], tab[K], phi[K], p[P], pcnt, dis[K], fa[K][6];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void sieve(int lim) {
	phi[1] = 1;
	rep(i, 2, lim) {
		if(!tab[i]) {
			p[++pcnt] = i;
			phi[i] = i - 1;
		}
		for(int j=1;j<=pcnt&&1LL*i*p[j]<=lim;j++) {
			tab[i*p[j]] = 1;
			if(i % p[j]) phi[i*p[j]] = phi[i] * phi[p[j]];
			else {
				phi[i*p[j]] = phi[i] * p[j];
				break;
			}
		}
	}
}
void initTree(int lim) {
	dis[1] = 1;
	rep(j, 0, 5) fa[1][j] = 1;
	rep(i, 2, lim) {
		dis[i] = dis[phi[i]] + 1;
		fa[i][0] = phi[i];
		rep(j, 1, 5) fa[i][j] = fa[fa[i][j-1]][j-1];
	}
}
int LCA(int u, int v) {
	if(dis[u] < dis[v]) swap(u, v);
	per(i, 5, 0) if(dis[fa[u][i]] >= dis[v]) u = fa[u][i];
	if(u == v) return u;
	per(i, 5, 0) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
struct Node {
	int lca, ans, mndis, allrt;
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void pushup(int u, int l, int r) {
		int mid = (l + r) >> 1;
		t[u].lca = LCA(t[lc(u)].lca, t[rc(u)].lca);
		t[u].ans = t[lc(u)].ans + t[rc(u)].ans
				 + (mid - l + 1) * (dis[t[lc(u)].lca] - dis[t[u].lca])
				 + (r - mid) * (dis[t[rc(u)].lca] - dis[t[u].lca]);
		t[u].mndis = min(t[lc(u)].mndis, t[rc(u)].mndis);
		t[u].allrt = t[lc(u)].allrt && t[rc(u)].allrt;
	}
	void build(int u, int l, int r) {
		if(l == r) {
			t[u].lca = a[l];
			t[u].ans = 0;
			t[u].mndis = dis[a[l]];
			t[u].allrt = a[l] == 1;
			return;
		}
		int mid = (l + r) >> 1;
		build(lc(u), l, mid);
		build(rc(u), mid+1, r);
		pushup(u, l, r);
	}
	void modify(int u, int l, int r, int ql, int qr) {
		if(t[u].allrt) return;
		if(l == r) {
			t[u].lca = fa[t[u].lca][0];
			--t[u].mndis;
			t[u].allrt = t[u].lca == 1;
			return;
		}
		int mid = (l + r) >> 1;
		if(ql <= mid) modify(lc(u), l, mid, ql, qr);
		if(qr > mid) modify(rc(u), mid+1, r, ql, qr);
		pushup(u, l, r);
	}
	int queryLCA(int u, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr) return t[u].lca;
		int mid = (l + r) >> 1;
		if(qr <= mid) return queryLCA(lc(u), l, mid, ql, qr);
		if(ql > mid) return queryLCA(rc(u), mid+1, r, ql, qr);
		int ans = queryLCA(lc(u), l, mid, ql, qr);
		if(ans == 1) return 1;
		return LCA(ans, queryLCA(rc(u), mid+1, r, ql, qr));
	}
	int queryAns(int u, int l, int r, int ql, int qr, int lca) {
		if(ql <= l && r <= qr) {
			return t[u].ans + (r - l + 1) * (dis[t[u].lca] - dis[lca]);
		}
		int mid = (l + r) >> 1, ans = 0;
		if(ql <= mid) ans += queryAns(lc(u), l, mid, ql, qr, lca);
		if(qr > mid) ans += queryAns(rc(u), mid+1, r, ql, qr, lca);
		return ans;
	}
	#undef lc
	#undef rc
}sgt;
 
int main() {
	sieve(W);
	initTree(W);
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]);
	sgt.build(1, 1, n);
	while(m --> 0) {
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if(op == 1) sgt.modify(1, 1, n, l, r);
		else {
			int lca = sgt.queryLCA(1, 1, n, l, r);
			printf("%dn", sgt.queryAns(1, 1, n, l, r, lca));
		}
	}
	return 0;
}
```
[1797F - Li Hua and Path](../problems/F._Li_Hua_and_Path.md "Codeforces Round 864 (Div. 2)")

 **Tutorial**
### [1797F - Li Hua and Path](../problems/F._Li_Hua_and_Path.md "Codeforces Round 864 (Div. 2)")

There exists an acceptable O(nlog2n+m) solution using centroid decomposition, but there is a better O(nlogn+m) solution using reconstruction trees.

The initial tree is shown in the following picture:

 

|  |
| --- |

 Consider the following reconstruction trees. We will define two reconstruction trees called min-RT and max-RT where "RT" means reconstruction tree.

For the max-RT, we enumerate vertices in increasing order. We create a new vertex u in the max-RT, then find each vertex v such that v<u and v is adjacent to u in the original tree, make u become the father of the root of v on the max-RT. We can use a dsu to build the max-RT.

The max-RT is shown in the following picture:

 

|  |
| --- |

 The property that LCA(u,v) on the max-RT is the maximum index on the path between (u,v) on the original tree is satisfied.

The min-RT is similar to the max-RT.

The min-RT is shown in the following picture:

 

|  |
| --- |

 After designing the reconstruction trees, I found out that the reconstruction trees are related to Kruskal reconstruction trees (KRT) to a certain extent. Here is another way to understand the two reconstruction trees. For the max-RT, since we want to calculate the maximum index on the path, we define the weight of an edge (u,v) as max{u,v}. We build a (minimum spanning) KRT of the original tree and merge the vertices with the same weight into one vertex. For the min-RT, define the weight of an edge (u,v) as min{u,v} and use the (maximum spanning) KRT.

The max-RT and the (minimum spanning) KRT: (left: maximum valued graph; middle: KRT; right: max-RT)

 

|  |
| --- |

 The min-RT and the (maximum spanning) KRT: (left: minimum valued graph; middle: KRT; right: min-RT)

 

|  |
| --- |

 We will solve the problem using the two reconstruction trees. Let's call the two restrictions in the statement I and II.

Denote K as the number of pairs satisfying exactly one of I and II (which is the answer), A as the number of pairs satisfying I, B as the number of pairs satisfying II and C as the number of pairs satisfying both I and II. It's obvious that K=A+B−2C.

We can easily calculate A and B using the depth of each vertex on two reconstruction trees. Due to the property mentioned above, C is the number of pairs (u,v) satisfying the condition that u is an ancestor of v on min-RT and v is an ancestor of u on max-RT, which can be solved using dfs order and Fenwick tree.

Finally, we calculated the original answer. If we add a vertex with the largest index as a leaf, paths ending with this vertex will satisfy II, so we can use min-RT to calculate the paths ending with this vertex not satisfying I and update the answer.

Time complexity: O(nlogn+m).

 **Solution (Celtic, centroid decomposition)**
```cpp
// Celtic
#include<bits/stdc++.h> 
#define N 501001
#define MAX 2005
using namespace std;
typedef long long ll;
typedef long double db;
const ll inf=1e18,mod=998244353,inv3=(mod+1)/3;
inline void read(ll &ret)
{
	ret=0;char c=getchar();bool pd=false;
	while(!isdigit(c)){pd|=c=='-';c=getchar();}
	while(isdigit(c)){ret=(ret<<1)+(ret<<3)+(c&15);c=getchar();}
	ret=pd?-ret:ret;
	return;
}
ll n,m,x,y,siz[N],son[N],minn=inf,num=0,f[N],sum,root;
vector<ll>v[N];
bool vis[N];
inline void find(ll ver,ll fa)
{
	siz[ver]=1;
	ll maxn=0;
	for(int i=0;i<v[ver].size();i++)
	{
		ll to=v[ver][i];
		if(to==fa||vis[to])
			continue;
		find(to,ver);
		siz[ver]+=siz[to];
		maxn=max(maxn,siz[to]);
	}
	maxn=max(maxn,num-siz[ver]);
	if(maxn<minn)
	{
		minn=maxn;
		root=ver;
	}
	return;
}
ll valmx[N],valmn[N],sz[N],now,fat[N];
struct node
{
	ll x,y,ver;
}a[N];
inline bool cmp1(node a,node b)
{
	return a.x<b.x;
}
inline bool cmp2(node a,node b)
{
	return a.y<b.y;
}
ll cnt;
vector<ll>g[N];
inline void dfs(ll ver,ll fa,ll d)
{
	valmx[ver]=max(valmx[fa],ver);
	valmn[ver]=min(valmn[fa],ver);
	if(ver!=now)
	{
		if(valmx[ver]==ver||valmx[ver]==now)
			sum++;
		if(valmn[ver]==ver||valmn[ver]==now)
			sum++;
		if(valmx[ver]==ver&&valmn[ver]==now)
			sum-=2;
		if(valmx[ver]==now&&valmn[ver]==ver)
			sum-=2;
		if(valmn[ver]==ver)
			f[now]++;
		if(valmn[ver]==now)
			f[ver]++;
		g[d].push_back(ver);
		a[++cnt]=node{valmx[ver],valmn[ver],ver};
	}
	sz[ver]=1;
	fat[ver]=d;
//	cout<<"dfs"<<ver<<" "<<fa<<" "<<d<<endl;
	for(int i=0;i<v[ver].size();i++)
	{
		ll to=v[ver][i];
		if(to==fa||vis[to])
			continue;
		if(ver==now)
			dfs(to,ver,to);
		else
			dfs(to,ver,d);
		sz[ver]+=sz[to];
	}
	return;
}
ll tree[N];
inline void update(ll pos,ll num)
{
	pos++;
	while(pos<N)
	{
		tree[pos]+=num;
		pos+=pos&-pos;
	}
	return;
}
inline ll query(ll pos)
{
	pos++;
	ll ret=0;
	while(pos)
	{
		ret+=tree[pos];
		pos-=pos&-pos; 
	}
	return ret;
}
inline void calc()
{
	sort(a+1,a+cnt+1,cmp1);
	for(int i=1;i<=cnt;i++)
	{
		ll j=i;
		for(;j<=cnt&&a[j].x==a[i].x;j++);
		j--;
		for(int k=i;k<=j;k++)
		{
			if(a[k].x==a[k].ver)
				sum+=i-1,sum-=2*query(a[k].y)/*,cout<<"del "<<a[k].ver<<" "<<i-1<<" "<<query(a[k].y)<<endl*/;
		}
		for(int k=i;k<=j;k++)
		{
			if(a[k].y==a[k].ver)
				update(a[k].y,1);
		}
		i=j;
	}
	for(int i=1;i<=cnt;i++)
	{
		ll j=i;
		for(;j<=cnt&&a[j].x==a[i].x;j++);
		j--;
		for(int k=i;k<=j;k++)
		{
			if(a[k].y==a[k].ver)
				update(a[k].y,-1);
		}
		i=j;
	}
	sort(a+1,a+cnt+1,cmp2);
	for(int i=cnt;i;i--)
	{
		ll j=i;
		for(;j&&a[j].y==a[i].y;j--);
		j++;
		for(int k=j;k<=i;k++)
		{
			if(a[k].y==a[k].ver)
				sum+=cnt-i;
		}
		i=j;
	}
	ll tmp=0;
	for(int i=1;i<=cnt;i++)
	{
		ll j=i;
		for(;j<=cnt&&a[j].y==a[i].y;j++);
		j--;
		for(int k=i;k<=j;k++)
			f[a[k].ver]+=tmp;
		for(int k=i;k<=j;k++)
			if(a[k].ver==a[k].y)
				tmp++;
		i=j;
	}
	return;
}
inline void decalc()
{
	sort(a+1,a+cnt+1,cmp1);
	for(int i=1;i<=cnt;i++)
	{
		ll j=i;
		for(;j<=cnt&&a[j].x==a[i].x;j++);
		j--;
		for(int k=i;k<=j;k++)
		{
			if(a[k].x==a[k].ver)
				sum-=i-1,sum+=2*query(a[k].y)/*,cout<<"back"<<a[k].ver<<" "<<i-1<<" "<<query(a[k].y)<<endl*/;
		}
		for(int k=i;k<=j;k++)
		{
			if(a[k].y==a[k].ver)
				update(a[k].y,1);
		}
		i=j;
	}
	for(int i=1;i<=cnt;i++)
	{
		ll j=i;
		for(;j<=cnt&&a[j].x==a[i].x;j++);
		j--;
		for(int k=i;k<=j;k++)
		{
			if(a[k].y==a[k].ver)
				update(a[k].y,-1);
		}
		i=j;
	}
	sort(a+1,a+cnt+1,cmp2);
	for(int i=cnt;i;i--)
	{
		ll j=i;
		for(;j&&a[j].y==a[i].y;j--);
		j++;
		for(int k=j;k<=i;k++)
		{
			if(a[k].y==a[k].ver)
				sum-=cnt-i;
		}
		i=j;
	}
	ll tmp=0;
	for(int i=1;i<=cnt;i++)
	{
		ll j=i;
		for(;j<=cnt&&a[j].y==a[i].y;j++);
		j--;
		for(int k=i;k<=j;k++)
			f[a[k].ver]-=tmp;
		for(int k=i;k<=j;k++)
			if(a[k].ver==a[k].y)
				tmp++;
		i=j;
	}
	return;
}
inline void divide(ll ver)
{
	vis[ver]=true;
	now=ver;
	cnt=0;
	valmn[0]=inf;
	dfs(ver,0,0);
//	cout<<"??"<<ver<<" "<<sum<<endl;
/*	cout<<ver<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<a[i].x<<" "<<a[i].y<<endl;*/
	calc();
//	cout<<ver<<" "<<cnt<<endl;
	for(int i=0;i<v[ver].size();i++)
	{
		ll to=v[ver][i];
		if(vis[to])
			continue;
		cnt=0;
		for(auto x:g[to])
			a[++cnt]=node{valmx[x],valmn[x],x}/*,cout<<ver<<" "<<to<<" "<<x<<endl*/;
		g[to].clear();
	//	cout<<ver<<" "<<to<<" "<<cnt<<endl;
		decalc();
	}
//	cout<<"result::"<<ver<<" "<<sum<<endl;
	for(int i=0;i<v[ver].size();i++)
	{
		ll to=v[ver][i];
		if(vis[to])
			continue;
		num=siz[to];
		minn=inf;
		find(to,ver);
	//	cout<<ver<<" "<<to<<" "<<root<<endl;
		divide(root);
	}
	return;
}
signed main()
{
	read(n);
	for(int i=1;i<n;i++)
	{
		read(x);
		read(y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	num=n;
	find(1,0);
	divide(root);
	printf("%lldn",sum);
/*	for(int i=1;i<=n;i++)
		cout<<f[i]<<" ";
	cout<<endl;*/
	read(m);
	for(int i=1;i<=m;i++)
	{
		ll x;
		read(x);
		n++;
		f[n]=f[x]+1;
		sum+=(n-1)-f[n];
		printf("%lldn",sum);
	}
	exit(0);
}
```
 **Solution (rui_er, reconstruction trees)**
```cpp
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 4e5+5;
 
ll n, m, k, faMx[N], faMn[N], disMx[N], disMn[N], dfn[N], sz[N], tms;
ll A, B, C, ans;
vector<ll> eMx[N], eMn[N], reMx[N], reMn[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Dsu {
	ll fa[N];
	void init(ll x) {rep(i, 1, x) fa[i] = i;}
	ll find(ll x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	bool merge(ll x, ll y) {
		ll u = find(x), v = find(y);
		if(u == v) return 0;
		fa[u] = v;
		return 1;
	}
}dsu;
struct BIT {
	ll c[N], sz;
	void init(ll x) {sz = x; rep(i, 1, x) c[i] = 0;}
	ll lowbit(ll x) {return x & (-x);}
	void add(ll x, ll k) {for(; x <= sz; x += lowbit(x)) c[x] += k;}
	ll ask(ll x) {ll k = 0; for(; x; x -= lowbit(x)) k += c[x]; return k;}
	ll Ask(ll x, ll y) {return ask(y) - ask(x - 1);}
}bit;
void dfs1(ll u) {
	dfn[u] = ++tms;
	sz[u] = 1;
	disMx[u] = disMx[faMx[u]] + 1;
	B += disMx[u] - 1;
	for(ll v : reMx[u]) {
		dfs1(v);
		sz[u] += sz[v];
	}
}
void dfs2(ll u) {
	disMn[u] = disMn[faMn[u]] + 1;
	A += disMn[u] - 1;
	C += bit.Ask(dfn[u], dfn[u] + sz[u] - 1);
	bit.add(dfn[u], 1);
	for(ll v : reMn[u]) dfs2(v);
	bit.add(dfn[u], -1);
}
 
int main() {
	scanf("%lld", &n);
	rep(i, 1, n-1) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		if(u < v) swap(u, v);
		eMx[u].push_back(v);
		eMn[v].push_back(u);
	}
	dsu.init(n);
	rep(i, 1, n) {
		for(ll j : eMx[i]) {
			j = dsu.find(j);
			dsu.merge(j, i);
			faMx[j] = i;
			reMx[i].push_back(j);
		}
	}
	dsu.init(n);
	per(i, n, 1) {
		for(ll j : eMn[i]) {
			j = dsu.find(j);
			dsu.merge(j, i);
			faMn[j] = i;
			reMn[i].push_back(j);
		}
	}
	bit.init(n);
	dfs1(n);
	dfs2(1);
	ans = A + B - 2 * C;
	// printf("%lld + %lld - 2 * %lld = %lldn", A, B, C, ans);
	printf("%lldn", ans);
	for(scanf("%lld", &m); m; m--) {
		scanf("%lld", &k);
		disMn[++n] = disMn[k] + 1;
		ans += n - disMn[n];
		printf("%lldn", ans);
	}
	return 0;
}
```
