# Tutorial_(en)

We want to mention [BamiTorabi](https://codeforces.com/profile/BamiTorabi "Expert BamiTorabi") who we thank for helping us with translating the problems and writing the tutorials, and also we apologize for div1 A2 and B hopefully you will forgive us :( .

 
### [1440A - Buy the String](../problems/A._Buy_the_String.md "Codeforces Round 684 (Div. 2)")

We will consider each character seperately. Look at the $i$-th character; if it is originally a $1$, we can either change it to a $0$ and pay $h + c_0$ coins for this specific character, or we can not change it and pay $c_1$ coins for it. Since we want to pay as little as possible, we take the minimum of these two. So if the $i$th character is a $1$, we will have to pay $min(c_1, h + c_0)$ coins for it. A similar logic can be used for the zeroes; if the $i$th character is a $0$ we will have to pay $min(c_0, h + c_1)$ coins. So we iterate over $s$, and for each character we add the required minimum to the sum, depending on whether it's a $0$ or $1$.

Time complexity: $O(n)$

Prepared by [Mohammad.H915](https://codeforces.com/profile/Mohammad.H915 "Master Mohammad.H915") Editorial by [Mehrdad_Sohrabi](https://codeforces.com/profile/Mehrdad_Sohrabi "Grandmaster Mehrdad_Sohrabi")

 **official solution**
```cpp
//                                In The Name Of Allah
#include <bits/stdc++.h>
#define	ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) return cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
#define ll long long
#define ld long double
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std; 

const int N = 3e5 + 100, OO = 1e9 + 7, T = 50, M = 1e9 + 7, P = 6151, SQ = 280, lg = 20;
typedef pair <int, int> pii;

void solve() {
	int n, c0, c1, t;
	string s;
	cin >> n >> c0 >> c1 >> t >> s;
	int ans = 0;
	for(auto u : s) {
		if(u == '0') 
			ans += min(c0, c1 + t);
		else 
			ans += min(c1, c0 + t);
	}
	cout << ans << endl;
}

int32_t main() {
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
```
 
### [1440B - Sum of Medians](../problems/B._Sum_of_Medians.md "Codeforces Round 684 (Div. 2)")

We will consider a greedy approach. We take the $\lceil {\frac{n}{2}} \rceil$ biggest numbers from the end of the array and the $\lfloor {\frac{n}{2}} \rfloor$ smallest numbers from the beginning. We take these elements as one group, erase them from our array and then continue the same procedure on the remaining array. This can be done in a loop of $O(k)$, by taking every $\lceil {\frac{n}{2}} \rceil$th character. We can also prove this claim. Imagine we have marked $k$ elements to be the medians of these arrays. Each one of these elements need at least $\lceil {\frac{n}{2}} \rceil - 1$ elements bigger than them and at least $\lfloor {\frac{n}{2}} \rfloor$ elements smaller than them to form a group in which it they are the median. So we can always push the biggest of these $k$ numbers forward until we have exactly $\lceil {\frac{n}{2}} \rceil - 1$ elements bigger than them, and by pushing forward the sum of medians either doesn't change or gets larger. So our algorithm will always give the biggest possible answer.

Time complexity: $O(nk)$ for each testcase

Prepared by [Mohammad.H915](https://codeforces.com/profile/Mohammad.H915 "Master Mohammad.H915") Editorial by [Mehrdad_Sohrabi](https://codeforces.com/profile/Mehrdad_Sohrabi "Grandmaster Mehrdad_Sohrabi")

 **official solution**
```cpp
#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl 'n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'n', 0;
using namespace std;
const int N=2e5+100;
ll a[N];
int Main(){
    ll n, k;
    cin >> k >> n;
    for (int i=1;i<=n*k;i++){
        cin >> a[i];
    }
    ll x=(k+1)/2 - 1;
    x = k - x;
    ll z=n*k+1;
    ll ans=0;
    while(n--){
        z-=x;
        if (z<=0) break;
        ans+=a[z];
    }
    cout << ans << endl;
}
int32_t main(){
    ll t;
    cin >> t;
    while(t--){
        Main();
    }
}
```
 
### [1439A2 - Binary Table (Hard Version)](https://codeforces.com/contest/1439/problem/A2 "Codeforces Round 684 (Div. 1)")

Consider two cases: If $n = 2$ and $m = 2$, there are only $4$ possible operations, and we can use up to $4$ operations. So, one can check all the $2^4$ possible ways of choosing these operations, and seeing which combination of these operation will result in a full $0$ grid.

Otherwise, at least one of $n$ and $m$ is bigger than $2$. Without loss of generality imagine $n > 2$. Take the $n$th row. For each cell within that row, we can use one operation on it, its left neighbour and the two cells above to fix this cell. We can do this for the first $n - 2$ cells in the row, and fix the last two with one operation on them. We will make at most $n - 1$ operations and reach a situation with one empty row. We can take the last row away and apply this procedure for the remaining $(n - 1) \times m$ grid. If we say inductively that we will have at most $(n - 1)m$ operations for the remaining grid, we will have done at most $(n - 1)m + n - 1 = nm - 1 < nm$ operations in total. When $n = 2$, we can do the same with the columns, and when $n = m = 2$, we can fix the remaining $2 \times 2$ grid as we discussed above.

Time complexity: $O(nm)$ for each case.

Prepared by [Mohammad.H915](https://codeforces.com/profile/Mohammad.H915 "Master Mohammad.H915") Editorial by [Mehrdad_Sohrabi](https://codeforces.com/profile/Mehrdad_Sohrabi "Grandmaster Mehrdad_Sohrabi")

 **official solution**
```cpp
//                             In The Name Of Allah
#include <bits/stdc++.h>
#define	ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) return cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
#define ll long long
#define ld long double
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std; 

const int N = 200, OO = 1e9 + 7, T = 50, M = 1e9 + 7, P = 6151, SQ = 280, lg = 20;
typedef pair <int, int> pii;
char c[N][N];
bool cnt[N][N];

struct node {int x1, y1, x2, y2, x3, y3;} p[5];
vector <node> v;

void upd(int x, int y, int tp, bool is) {
    if(is)
        v.pb({x + p[tp].x1, y + p[tp].y1, x + p[tp].x2, y + p[tp].y2, x + p[tp].x3, y + p[tp].y3});
    else 
        cnt[x + p[tp].x1][y + p[tp].y1] ^= 1, cnt[x + p[tp].x2][y + p[tp].y2] ^= 1, cnt[x + p[tp].x3][y + p[tp].y3] ^= 1;
}

void solve() {
	int n, m, od = 0;
	v.clear();
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> c[i][j];
			if(c[i][j] == '1')
				od++, cnt[i][j] = true;
			else
			    cnt[i][j] = false;
		}
	}
	if(od == 0) {
		cout << 0 << endl;
		return;
	}
	if(n == 1 || m == 1) {
		cout << -1 << endl;
		return;
	}
    for(int i = 1; i <= n - 2; i++) {
		for(int j = 1; j <= m; j++) {
			if(cnt[i][j]) {
			    if(j != m) {
			        v.pb({i, j, i + 1, j, i + 1, j + 1});
			        cnt[i][j] ^= 1, cnt[i + 1][j] ^= 1, cnt[i + 1][j + 1] ^= 1;
			    } 
			    else {
			        v.pb({i, j, i + 1, j, i + 1, j - 1});
			        cnt[i][j] ^= 1, cnt[i + 1][j] ^= 1, cnt[i + 1][j - 1] ^= 1;
			    }
			}
		}
	}
	for(int i = 1; i <= m - 2; i++) {
	    if(cnt[n - 1][i]) {
	        v.pb({n - 1, i, n - 1, i + 1, n, i + 1});
	        cnt[n - 1][i] ^= 1, cnt[n - 1][i + 1] ^= 1, cnt[n][i + 1] ^= 1; 
	    }
	    if(cnt[n][i]) {
	        v.pb({n, i, n - 1, i + 1, n, i + 1});
	        cnt[n][i] ^= 1, cnt[n - 1][i + 1] ^= 1, cnt[n][i + 1] ^= 1; 
	    }
	}
	for(int msk = 0; msk < (1 << 4); msk++) {
	    for(int j = 0; j < 4; j++) 
	       if(msk & (1 << j))
	           upd(n - 1, m - 1, j, 0);
	    if(!cnt[n - 1][m - 1] && !cnt[n - 1][m] && !cnt[n][m - 1] && !cnt[n][m]) {
	        for(int j = 0; j < 4; j++) 
	            if(msk & (1 << j))
	                upd(n - 1, m - 1, j, 1);
	        break;
	    }
	    for(int j = 0; j < 4; j++)
	        if(msk & (1 << j))
	            upd(n - 1, m - 1, j, 0);
	}
	cout << (int)v.size() << endl;
	for(auto u : v)
        cout << u.x1 << " " << u.y1 << " " << u.x2 << " " << u.y2 << " " << u.x3 << " " << u.y3 << endl;
}

int32_t main(){
	use_fast;
    p[0] = {0, 0, 0, 1, 1, 0}, p[1] = {0, 1, 0, 0, 1, 1}, p[2] = {1, 0, 1, 1, 0, 0}, p[3] = {1, 1, 0, 1, 1, 0};
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
```
 
### [1439B - Graph Subset Problem](https://codeforces.com/contest/1439/problem/B "Codeforces Round 684 (Div. 1)")

div1 B :

It is easy to see that if $k > \sqrt{2m}$ the answer is $-1$; because if $k > \sqrt{2m}$, no matter whether we have a clique of size $k$ or a subset of the graph with $\delta \geq k$, we will have more than $m$ edges in total.

Now, the main idea is to suppose $u$ is the vertex with minimum degree; if $d(u) < k - 1$ we should delete $u$ becuase $u$ can not be in clique or the subset of vertices such that each vertex of this subset has at least $k$ neighbors in the subset; so we have to erase $u$ and all edges attached to it.

If $d(u) > k$, remaining vertices will form a subset that every vertex have at least $k$ neighbors in the subset, so we'll print this subset as answer.

If $d(u) = k - 1$, we consider $u$ and all neighbors of $u$ as candidate for clique of size $k$. then we erase $u$ and all edges attached to it.

If we erase all vertices and didn't found any good subset, then we should check clique candidates.

for checking clique candidates fast, iterate over vertices and name current vertex $v$. then for neighbors of $v$ set $nei_v$ to $1$ and $0$ otherwise. for each clique candidate that contains $v$ like $C$, we check edge between $v$ and $u \in C$ in $O(1)$ using array $nei$. 

every time we find new clique candidate, we remove at least $k - 1$ edges, so number of clique candidates is at most $\frac{m}{k-1}$. for every candidate we check $\mathcal{O}(k^2)$ edges in overall. so time complexity is $\mathcal{O}(\frac{m}{k}).\mathcal{O}(k^2) \in \mathcal{O}(m.k)$.

Prepared by [AliShahali1382](https://codeforces.com/profile/AliShahali1382 "International Grandmaster AliShahali1382") Editorial by [Amoo_Safar](https://codeforces.com/profile/Amoo_Safar "International Grandmaster Amoo_Safar")

 **official solution**
```cpp
//                             In The Name Of Allah                                           
#include <bits/stdc++.h>
#define	ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
//#define int long long
#define ld long double
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std; 
const int N = 1e5 + 100, OO = 1e9 + 7, T = 22, M = 1e9 + 7, P = 6151, SQ = 1300, lg = 22;
typedef pair <int, int> pii;
int mark[N], deg[N], ct[N];
bool ans[N], can[N];
vector <int> v[N], A;
vector <pii> ch[N];
bool cmp(int x, int y) {
	return mark[x] < mark[y];
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	A.clear();
	for(int i = 0; i <= n; i++)
	    v[i].clear(), ch[i].clear(), mark[i] = deg[i] = ct[i] = 0, ans[i] = can[i] = false;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	if(k > 500) {
	   cout << -1 << endl;
	   return;
	}
	set <pii> st;
	for(int i = 1; i <= n; i++)
		st.insert({deg[i] = (int)v[i].size(), i});
	int cnt = 1;
	while((int)st.size()) {
		pii p = *st.begin();
		if(p.ff >= k) {
			cout << 1 << " " << (int)st.size() << endl;
			for(auto u : st)
				cout << u.ss << " ";
			cout << endl;
			return;
		}
		else {
			st.erase(p);
			mark[p.ss] = cnt;
			for(auto u : v[p.ss])
				if(!mark[u])
					st.erase({deg[u], u}), st.insert({--deg[u], u});
			A.pb(p.ss);
		}
		cnt++;
	}
	for(auto i : A) {
		int nxt = 0;
		for(auto u : v[i]) 
			if(mark[u] > mark[i])
				ct[nxt++] = u, can[u] = true;
		for(auto u : ch[i]) 
			if(!can[u.ff])
				ans[u.ss] = false;
		for(int j = 0; j < nxt; j++)
			can[ct[j]] = false;
		if(nxt != k - 1)
			continue;
		ans[i] = true;
		sort(ct, ct + nxt, cmp);
		for(int j = 0; j < nxt; j++)
			for(int k = j + 1; k < nxt; k++)
				ch[ct[j]].pb({ct[k], i});
	}
	for(auto i : A) {
		if(!ans[i])
			continue;
		cout << 2 << endl;
		cout << i << " ";
		for(auto u : v[i])
			if(mark[u] > mark[i])
				cout << u << " ";
		cout << endl;
		return;
	}
	cout << -1 << endl;
	return;
}

int32_t main() {
	use_fast;
	int t;
    cin >> t;
    while(t--)
        solve();
	return 0;
}
```
 
### [1439C - Greedy Shopping](https://codeforces.com/contest/1439/problem/C "Codeforces Round 684 (Div. 1)")

We can prove that the hungry man will eat at most $log_2(maxY)$ continiuous subsegments, where $maxY$ is the maximum amount of money possible. Why is that so? Suppose the hungry man buys a meal from the $i$ th shop but can't buy a meal from the $(i + 1)$th one after that. Then, the money the hungry man had before buying the $i$th food is at most twice the money he has after buying the $i$th food because $a_i > a_{i+1}$. So every time he breaks the subsegment of shops, his money is cut in at least half, so he will eat atmost $log_2(maxY)$ continuous subsegments.

Now we need a data structure with the following queries: range_max and range_sum. Since our array is non-increasing, a segment tree will suffice. The first type of query is just a range_max query. For the second type of query you can find the first element that is equal to or smaller than the hungry man's money and after that find the segment that he will eat, in which we can use a binary-search on the tree to find these both. After that we can repeat this action untill we reach the end of the array, or until his money runs out.

Time complexity: $O((n + q)log(maxY)log(n))$

prepared by [Mehrdad_Sohrabi](https://codeforces.com/profile/Mehrdad_Sohrabi "Grandmaster Mehrdad_Sohrabi") Editorial by [Mehrdad_Sohrabi](https://codeforces.com/profile/Mehrdad_Sohrabi "Grandmaster Mehrdad_Sohrabi")

 **official solution**
```cpp
#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
ll seg[MAXN<<2], lazy[MAXN<<2];
int Mn[MAXN<<2], Mx[MAXN<<2];

void Build(int id, int tl, int tr){
	if (tr-tl==1){
		Mn[id]=Mx[id]=seg[id]=A[tl];
		return ;
	}
	int mid=(tl+tr)>>1;
	Build(id<<1, tl, mid);
	Build(id<<1 | 1, mid, tr);
	Mn[id]=min(Mn[id<<1], Mn[id<<1 | 1]);
	Mx[id]=max(Mx[id<<1], Mx[id<<1 | 1]);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];	
}
inline void add_lazy(int id, int len, ll val){
	Mn[id]=val;
	Mx[id]=val;
	lazy[id]=val;
	seg[id]=len*val;
}
inline void shift(int id, int tl, int tr){
	if (!lazy[id]) return ;
	int mid=(tl+tr)>>1;
	add_lazy(id<<1, mid-tl, lazy[id]);
	add_lazy(id<<1 | 1, tr-mid, lazy[id]);
	lazy[id]=0;
}
void Maximize(int id, int tl, int tr, int pos, ll val){
	if (pos<=tl || val<=Mn[id]) return ;
	if (tr<=pos && Mx[id]<=val){
		add_lazy(id, tr-tl, val);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	Maximize(id<<1, tl, mid, pos, val);
	Maximize(id<<1 | 1, mid, tr, pos, val);
	Mn[id]=min(Mn[id<<1], Mn[id<<1 | 1]);
	Mx[id]=max(Mx[id<<1], Mx[id<<1 | 1]);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
}
int BS1(int id, int tl, int tr, int pos, ll val){
	if (tr<=pos || val<Mn[id]) return tr;
	if (tr-tl==1) return tl;
	shift(id, tl, tr);
	int mid=(tl+tr)>>1, tmp=BS1(id<<1, tl, mid, pos, val);
	if (tmp==mid) return BS1(id<<1 | 1, mid, tr, pos, val);
	return tmp;
}
int BS2(int id, int tl, int tr, ll val){
	if (seg[id]<=val) return tr;
	if (tr-tl==1) return tl;
	shift(id, tl, tr);
	int mid=(tl+tr)>>1, tmp=BS2(id<<1, tl, mid, val);
	if (tmp<mid) return tmp;
	return BS2(id<<1 | 1, mid, tr, val-seg[id<<1]);
}
ll Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id];
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	return Get(id<<1, tl, mid, l, r) + Get(id<<1 | 1, mid, tr, l, r);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	Build(1, 1, n+1);
	while (m--){
		cin>>t>>x>>y;
		if (t==1) Maximize(1, 1, n+1, x+1, y);
		else{
			ans=0;
			while (1){
				x=BS1(1, 1, n+1, x, y);
				if (x==n+1) break ;
				ll val=y+Get(1, 1, n+1, 1, x);
				int xx=BS2(1, 1, n+1, val);
				// buy [x, xx)
				ans+=xx-x;
				y-=Get(1, 1, n+1, x, xx);
				x=xx;
			}
			cout<<ans<<"n";
		}
	}
	
	return 0;
}
```
 
### [1439D - INOI Final Contests](https://codeforces.com/contest/1439/problem/D "Codeforces Round 684 (Div. 1)")

Suppose $n = m$. Let $dp1_i$ be the number of $(A , B)$ pairs for $i$ participants and $i$ computers so that no one gets upset. For updating this array we can consider the last participant, and where he will sit. Suppose he sits behind the $j$-th computer. If he comes from left to right, there are $i$ choices of computers for him to sit behind, and if he comes from right to left there are $n - i + 1$ choices for him. If the last participant sits behind the $j$-th computer there are $dp1_{j-1} \cdot dp1_{i-j}$ ${i-1}\choose{j-1}$ ways to fill in the rest of the seats because after removing we have two independent subsegments. So $dp1_i = (i+1) \sum_{j=1}^{i} dp1_{j-1} \cdot dp1_{i-j}$ ${i-1}\choose{j-1}$.

Now let $dp2_i$ be the sum of the total madnesses for all cases with $i$ participants and $i$ computers. Imagine the last person sitting on the $j$-th computer. The madness of every participant except the last one is $(i+1) \cdot (dp2_{j-1} \cdot dp1_{i-j} + dp2_{i-j} \cdot dp1_{j-1})$ ${i-1}\choose{j-1}$. However, the madness of the last participant is $($ ${j-1}\choose{2}$ $+$ ${i-j}\choose{2}$ $) \cdot dp1_{j-1}\cdot dp1_{i-j}$ ${i-1}\choose{j-1}$.

Now what if $n > m$? Suppose $dp3_{i ,j}$ is the number of $(A , B)$ pairs for $i$ computers and $j$ participants so that no one gets upset. For updating it we can consider the maximal suffix that all of the computers in that suffix will get occupied by participants. Consider its lenghth is $l$ . If $l = 0$ then we add $dp3_{i-1,j}$ to $dp3_{i,j}$; if not, we add $dp1_l \cdot dp3_{i-l-1,j-l}$ ${j}\choose{l}$ to $dp3_{i, j}$. The update is similar to $dp1$. The update is done correctly because the subsegments are independant.

At last, suppose $dp4_{i, j}$ is the sum of the total madnesses for all cases with $i$ computers and $j$ participants. Consider $l$ to be the lenghth of the maximal suffix that all of the computers in that suffix will get occupied by participants. If $l = 0$ then to $dp4_{i, j}$ we add $dp4_{i - 1, j}$. If $l > 0$ then $(dp4_{i-1-l, j-l} \cdot dp1_l + dp3_{i-1-l,j-l} \cdot dp2_l)$ ${j}\choose{l}$ is added to $dp4_{i, j}$. The answer shall be $dp4_{n, m}$.

Time complexity: $O(n^3)$. Computing $dp1$ and $dp2$ is an $O(n^2)$ task, while computing $dp3$ and $dp4$ has a complexity of $O(n^3)$.

Challenge: Can you find a solution with a better time complexity?

prepared by [Mehrdad_Sohrabi](https://codeforces.com/profile/Mehrdad_Sohrabi "Grandmaster Mehrdad_Sohrabi") Editorial by [Mehrdad_Sohrabi](https://codeforces.com/profile/Mehrdad_Sohrabi "Grandmaster Mehrdad_Sohrabi")

 **official solution**
```cpp
#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int MAXN=505, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, mod;
ll dp1[MAXN], dp2[MAXN];
ll dp3[MAXN][MAXN], dp4[MAXN][MAXN];
ll C[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>mod;
	
	for (int i=0; i<MAXN; i++){
		C[i][0]=C[i][i]=1;
		for (int j=1; j<i; j++) C[i][j]=(C[i-1][j] + C[i-1][j-1])%mod;
	}
	dp1[0]=1;
	for (int n=1; n<MAXN; n++){
		for (int i=1; i<=n; i++) dp1[n]=(dp1[n] + dp1[i-1]*dp1[n-i]%mod*C[n-1][i-1])%mod;
		dp1[n]=(n+1)*dp1[n]%mod;
		for (int i=1; i<=n; i++){
			dp2[n]=(dp2[n] + (n+1)*C[n-1][i-1]%mod*((dp1[i-1]*dp2[n-i] + dp2[i-1]*dp1[n-i])%mod))%mod;
			dp2[n]=(dp2[n] + C[n-1][i-1]*dp1[i-1]%mod*dp1[n-i]%mod*((i*(i-1)/2+(n-i)*(n-i+1)/2)%mod))%mod;
		}
	}
	
	dp3[0][0]=1;
	for (int n=1; n<MAXN; n++){
		for (int m=0; m<n; m++){
			dp3[n][m]=dp3[n-1][m];
			dp4[n][m]=dp4[n-1][m];
			for (int i=1; i<=m; i++){
				dp3[n][m]=(dp3[n][m] + dp3[n-i-1][m-i]*dp1[i]%mod*C[m][i])%mod;
				dp4[n][m]=(dp4[n][m] + dp3[n-i-1][m-i]*dp2[i]%mod*C[m][i])%mod;
				dp4[n][m]=(dp4[n][m] + dp4[n-i-1][m-i]*dp1[i]%mod*C[m][i])%mod;
			}
		}
		dp3[n][n]=dp1[n];
		dp4[n][n]=dp2[n];
	}

	cout<<dp4[n][m]<<"n";	
	
	return 0;
}
```
 **O(n2) solution**
```cpp
// And you curse yourself for things you never done
// Shayan.P  2020-08-29

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 510, inf = 1e9 + 10, mod=1e9+7;

ll n, m;

ll Pow(ll a, ll b){
    b = (b + (mod-1)) % (mod-1); // to handle b == -1
    int ans=1;
    for(; b; b>>=1, a=a*a%mod) if (b&1) ans=ans*a%mod;
    return ans;
}
inline void add(ll &a, ll b){
    a = (a + b) % mod;
}
    
ll fac[maxn], ifac[maxn];

ll C(ll n, ll k){
	if (n<k || k<0) return 0;
	return fac[n]*ifac[k]%mod*ifac[n-k]%mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    fac[0] = 1;
    for(int i = 1; i < maxn; i++) fac[i]=fac[i-1]*i%mod;
    ifac[maxn-1] = Pow(fac[maxn-1], mod-2);
    for(int i = maxn-2; i >= 0; i--) ifac[i]=ifac[i+1]*(i+1)%mod;
    
    cin >> n >> m;
    ++n; //!
    
	int ans = 0;
    for(ll bef = 0; bef < m; bef++){
		for(ll w = 1; w + bef < m; w++){ // corner case : bef == 0
			ll cnt1=Pow(w+1, w-1)*Pow(2, w)%mod;
			ll cnt2=Pow(n-w-1, bef-1)*Pow(2, bef)%mod*(n-w-1-bef)%mod;
			ll cnt=cnt1*cnt2%mod*C(w+bef, bef)%mod;
			ll score=w*(w+1)%mod*n%mod;
			ll after=Pow(n, m-bef-w-1)*Pow(2, m-bef-w-1) % mod;
			ans=(ans + cnt*score%mod*after) % mod;
		}
    }    
    cout << 1ll * (n-m) * ans % mod * Pow(n, -1) % mod << "n";
    return 0;
}

```
 
### [1439E - Cheat and Win](https://codeforces.com/contest/1439/problem/E "Codeforces Round 684 (Div. 1)")

First let's solve the problem on arbitrary trees. Consider the following game: on some vertices of the tree we have some tokens. At each step you remove a token from some vertex and put a token in any subset of its ancestors. The first game can be transformed to this one by putting a token in each black vertex. So now we'll solve the new game.

Obviously the game is independent for different tokens, so we can use Grundy numbers. After working around some examples you can find that the Grundy number for a vertex at height $h$ is $2^h$. it can be easily proved by induction since any number less than it can be built by exactly one subset of it's ancestors.

Consider the binary representation of the grundy for the game(let it be S). Each cheating move means reversing the bits of a prefix of S. So the minimum number of operations needed can be shown as $T = (S[0] \oplus S[1]) + (S[1] \oplus S[2]) + ...$ Since each operation decreases this expression at most once, we will need at least $T$ operations, and there is an obvious way to make $S$ equal zero with that number of operations.

Now to solve the original problem, we need to find a compressed tree of the marked vertices and then represent the black vertices as union of $O(m)$ paths from the root. After this we can finally calculate the compressed form of the total Grundy number and find the answer. For compressing the tree we need to do some operations, like sorting the vertices by starting time(dfs order), finding the LCA of 2 vertices, etc. in $O(H)$ time, where $H = log(10^9)$.

How to do these? Well they can be done with the following observation (the details are left for the reader but they can be found in the model solution):

For some $h$, consider the tree on these 3 set of cells: $$T1: 0 \leq x < 2^h, 0 \leq y < 2^h$$ $$T2: 0 \leq x < 2^h, 2^h \leq y < 2^{h+1}$$ $$T3: 2^h \leq x < 2^{h+1}, 0 \leq y < 2^h$$

One can see (and can prove) that these 3 trees are similar; so this gives us some recursive approach.

Time complexity: $O(mH)$, where $H = log(10^9)$.

Prepared by [AliShahali1382](https://codeforces.com/profile/AliShahali1382 "International Grandmaster AliShahali1382") Editorial by [AliShahali1382](https://codeforces.com/profile/AliShahali1382 "International Grandmaster AliShahali1382")

 **official solution**
```cpp
#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=400010, LOG=30;

int n, m, k, u, v, x, y, t, a, b, root, ans;
pii A[MAXN], V[MAXN];
int par[MAXN], sum[MAXN];
bool is[MAXN];
vector<int> G[MAXN], grundy;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int GetH(pii p){ return p.first+p.second;}
inline pii GetPar(pii p, int k){
	int x=p.first, y=p.second;
	while (k){
		int xx=(x&-x), yy=(y&-y);
		if (!xx) xx=2*inf;
		if (!yy) yy=2*inf;
		int tmp=min(k, min(xx, yy));
		k-=tmp;
		if (xx<yy) x-=tmp;
		else y-=tmp;
	}
	return {x, y};
}
inline int Zone(pii p, int n){
    if (p.first&(1<<(n-1))) return 2;
    if (p.second&(1<<(n-1))) return 1;
    return 0;
}
void dfs_order(vector<pii> &vec, int n=LOG) {
	if (n==0 || vec.size()==0) return ;
	vector<pii> v[3];
	for (pii p:vec) {
		int z=Zone(p, n);
		p.first&=(1<<(n-1))-1;
		p.second&=(1<<(n-1))-1;
		v[z].pb(p);
    }
	vec.clear();
	for (int i:{0, 1, 2}) dfs_order(v[i], n-1);
	for (pii p:v[0]) if (!p.first) vec.pb(p);
    for (pii p:v[1]) vec.pb({p.first, p.second|(1<<(n-1))});
    for (pii p:v[0]) if (p.first) vec.pb(p);
    for (pii p:v[2]) vec.pb({p.first|(1<<(n-1)), p.second});
}
pii Lca(pii u, pii v, int n=LOG) {
	if (n==0) return {0, 0};
	int zu = Zone(u, n), zv = Zone(v, n);
	if (zu > zv) swap(u, v), swap(zu, zv);
	u.first&=(1<<(n-1))-1;
	u.second&=(1<<(n-1))-1;
	v.first&=(1<<(n-1))-1;
	v.second&=(1<<(n-1))-1;
	if (zu == 1 && zv == 2) return {0, 0};
	if (zu == 2 && zv == 2){
		pii A = Lca(u, v, n-1);
		return {A.first+(1<<(n-1)), A.second};
	}
	if (zu == 1 && zv == 1) {
		pii A = Lca(u, v, n-1);
		return {A.first, A.second+(1<<(n-1))};
	}
	if (zv == 1) return Lca(u, {0, (1<<(n-1))-1}, n-1);
	if (zv == 2) return Lca(u, {(1<<(n-1))-1, 0}, n-1);
	return Lca(u, v, n-1);
}
inline int GetId(pii p){
	return lower_bound(V, V+n, p)-V;
}
inline bool IsPar(pii u, pii v){
	if (GetH(u)>GetH(v)) return 0;
	return GetPar(v, GetH(v)-GetH(u))==u;
}
int dfs(int node){
	for (int v:G[node]) sum[node]+=dfs(v);
	return sum[node];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pii> vec;
	cin>>m;
	for (int i=0; i<2*m; i++) cin>>A[i].first>>A[i].second, vec.pb(A[i]);
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	dfs_order(vec);
	for (int i=vec.size()-1; i; i--) vec.pb(Lca(vec[i], vec[i-1]));
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	dfs_order(vec);
	n=vec.size();
	
	debug("sorted")
	
	for (int i=0; i<n; i++) V[i]=vec[i];
	sort(V, V+n);
	vector<int> stk={root=GetId(vec[0])};
	for (int i=1; i<n; i++){
		int v=GetId(vec[i]);
		while (!IsPar(V[stk.back()], V[v])) stk.pop_back();
		par[v]=stk.back();
		G[stk.back()].pb(v);
		stk.pb(v);		
	}
	
	for (int i=0; i<2*m; i+=2){
		int u=GetId(A[i]), v=GetId(A[i+1]), lca=GetId(Lca(A[i], A[i+1]));
		sum[u]++;
		sum[v]++;
		sum[lca]-=2;
		is[lca]=1;
	}
	dfs(root);
	for (int v=0; v<n; v++){
		if (sum[v]){
			grundy.pb(GetH(V[par[v]])+1);
			grundy.pb(GetH(V[v])+1);
		}
		else if (is[v]){
			grundy.pb(GetH(V[v]));
			grundy.pb(GetH(V[v])+1);
		}
	}
	sort(all(grundy));
	vec.clear();
	int last=-1;
	for (int x:grundy){
		if (last==-1){
			if (vec.empty() || vec.back().second<x) last=x;
			else{
				last=vec.back().first;
				vec.pop_back();
			}
		}
		else{
			if (last<x) vec.pb({last, x});
			last=-1;
		}
	}
	ans=2*vec.size();
	if (ans && vec[0].first==0) ans--;
	cout<<ans<<"n";
	
	return 0;
}
```
