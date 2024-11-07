# Tutorial_(en)

Sorry for the weak pretests on A :(. We hope you enjoyed the round nonetheless.

[1904A - Вилка!](../problems/A._Forked!.md "Codeforces Round 914 (Div. 2)")

Idea: [Apple_Method](https://codeforces.com/profile/Apple_Method "Мастер Apple_Method")   
 Preparation: [Apple_Method](https://codeforces.com/profile/Apple_Method "Мастер Apple_Method")/[oursaco](https://codeforces.com/profile/oursaco "Международный мастер oursaco")   
 Analysis: [lunchbox](https://codeforces.com/profile/lunchbox "Мастер lunchbox")

 **Solution**There are at most 8 positions of the knight that can attack a single cell. Therefore, we can find all 8 positions that attack the king and the 8 positions that attack the queen and count the number of positions that appear in both of these lists.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};
 
int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int a, b; cin >> a >> b;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        set<pair<int, int>> st1, st2;
        for(int j = 0; j < 4; j++){
            st1.insert({x1+dx[j]*a, y1+dy[j]*b});
            st2.insert({x2+dx[j]*a, y2+dy[j]*b});
            st1.insert({x1+dx[j]*b, y1+dy[j]*a});
            st2.insert({x2+dx[j]*b, y2+dy[j]*a});
        }
        int ans = 0;
        for(auto x : st1)
            if(st2.find(x) != st2.end())
                ans++;
        cout << ans << 'n';
    }
} 
```
[1904B - Игра в коллекционирование](../problems/B._Collecting_Game.md "Codeforces Round 914 (Div. 2)")

Idea: [oursaco](https://codeforces.com/profile/oursaco "Международный мастер oursaco")   
 Preparation: [oursaco](https://codeforces.com/profile/oursaco "Международный мастер oursaco")   
 Analysis: [lunchbox](https://codeforces.com/profile/lunchbox "Мастер lunchbox")

 **Solution**Let's sort array a. The answer for the largest element is n−1 because the score, which is an, cannot be smaller than any of the other elements. Now, consider the second largest element. The answer is at least n−2 because every element that is not greater than an−1 can be taken. Then, we check if the score is at least an. This inspires the following solution: first, we find the prefix sum p of array a. We calculate the answer in decreasing order of ai. To calculate the answer for an ai, we find the largest j such that pi≥aj and set the answer for i equal to the answer of j.

 **Code**
```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;

template<class K> using sset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

inline ll ceil0(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}

void setIO() {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

int main(){
    setIO();
    int T;
    cin >> T;
    for(int tt = 1; tt <= T; tt++){
        int n;
        cin >> n;
        pii arr[n + 1];
        for(int i = 1; i <= n; i++) cin >> arr[i].ff, arr[i].ss = i;
        sort(arr + 1, arr + n + 1);
        int nxt[n + 1];
        ll sum[n + 1];
        int ans[n + 1];
        nxt[0] = sum[0] = 0;
        for(int i = 1; i <= n; i++){
            if(nxt[i - 1] >= i){
                nxt[i] = nxt[i - 1];
                sum[i] = sum[i - 1];
            } else {
                sum[i] = sum[i - 1] + arr[i].ff;
                nxt[i] = i;
                while(nxt[i] + 1 <= n && sum[i] >= arr[nxt[i] + 1].ff){
                    nxt[i]++;
                    sum[i] += arr[nxt[i]].ff;
                }
            }
            ans[arr[i].ss] = nxt[i];
        }
        for(int i = 1; i <= n; i++) cout << ans[i] - 1 << " ";
        cout << endl;
    }
}
```
[1904C - Игра с массивом](../problems/C._Array_Game.md "Codeforces Round 914 (Div. 2)")

Idea: [lunchbox](https://codeforces.com/profile/lunchbox "Мастер lunchbox")   
 Preparation: [lunchbox](https://codeforces.com/profile/lunchbox "Мастер lunchbox")   
 Analysis: [lunchbox](https://codeforces.com/profile/lunchbox "Мастер lunchbox")

 **Solution**If k≥3, the answer is equal to 0 since after performing an operation on the same pair (i,j) twice, performing an operation on the two new values (which are the same) results in 0.

Therefore, let's consider the case for 1≤k≤2.

For k=1, it is sufficient to sort the array and output the minimum between ai and ai+1−ai.

For k=2, let's brute force the first operation. If the newly created value is v, then it is sufficient to find the smallest ai satisfying ai≥v and greatest ai satisfying ai≤v and relax the answer on |ai−v|. Also, remember to consider the cases of performing no operation or one operation. This runs in O(N2logN). There also exists a solution in O(N2) using a two pointers approach.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
 
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (k >= 3) {
            cout << 0 << endl;
            continue;
        }
        sort(begin(a), end(a));
        int d = a[0];
        for (int i = 0; i < n - 1; i++) d = min(d, a[i + 1] - a[i]);
        if (k == 1) {
            cout << d << endl;
            continue;
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) {
            int v = a[i] - a[j];
            int p = lower_bound(begin(a), end(a), v) - begin(a);
            if (p < n) d = min(d, a[p] - v);
            if (p > 0) d = min(d, v - a[p - 1]);
        }
        cout << d << endl;
    }
}
```
[1904D1 - Присвоить максимум (простая версия)](../problems/D1._Set_To_Max_(Easy_Version).md "Codeforces Round 914 (Div. 2)") / [1904D2 - Присвоить максимум (сложная версия)](../problems/D2._Set_To_Max_(Hard_Version).md "Codeforces Round 914 (Div. 2)")

Idea: [oursaco](https://codeforces.com/profile/oursaco "Международный мастер oursaco")   
 Preparation: [oursaco](https://codeforces.com/profile/oursaco "Международный мастер oursaco")   
 Analysis: [oursaco](https://codeforces.com/profile/oursaco "Международный мастер oursaco")

 **Hint 1**Can we reduce the number of intervals we want to apply an operation on?

 **Hint 2**What is the necessary condition to perform an operation on an interval

 **Solution**If bi<ai for any i, then it is clearly impossible.

In order for ai to become bi, i must be contained by an interval that also contains a j where aj=bi. Note that if there is a triple i≤j<k where aj=ak=bi, then it is never optimal to apply the operation on interval [i,k], since applying the operation on interval [i,j] will be sufficient. Thus, for i we only need to consider the closest aj=bi to the right or left of i. 

Lets find the necessary conditions for us to apply an operation on the interval [i,j]. First of all, ak≤bi for i≤k≤j. Second, bk≥bi for all i≤k≤j. Turns out, these conditions are also sufficient, since we can apply these operations in increasing order of bi without them interfering with each other. If we check for every i there exists an interval [i,j] or [j,i] that satisfies the necessary conditions, then there will exist a sequence of operations to transform a into b. Checking for the conditions can be done with brute force for D1 or using monotonic stacks or segment trees for D2.

 **Code**
```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;

template<class K> using sset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

inline ll ceil0(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}

void setIO() {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

int main(){
    setIO();
    int T;
    cin >> T;
    for(int tt = 1; tt <= T; tt++){
        int n;
        cin >> n;
        int a[n + 1], b[n + 1];
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        bool val[n + 1];
        memset(val, false, sizeof(val));
        for(int t = 0; t < 2; t++){
            int prvb[n + 1]; //prev smaller
            int nxta[n + 1]; //next greater
            stack<pii> s;
            s.push({INF, n + 1});
            for(int i = n; i >= 1; i--){
                while(s.top().ff <= a[i]) s.pop();
                nxta[i] = s.top().ss;
                s.push({a[i], i});
            }
            while(!s.empty()) s.pop();
            s.push({0, 0});
            for(int i = 1; i <= n; i++){
                while(s.top().ff >= b[i]) s.pop();
                prvb[i] = s.top().ss;
                s.push({b[i], i});
            }
            int m[n + 1];
            memset(m, 0, sizeof(m));
            for(int i = 1; i <= n; i++){
                m[a[i]] = i;
                if(a[i] <= b[i] && m[b[i]]) val[i] |= prvb[i] < m[b[i]] && nxta[m[b[i]]] > i;
            }
            reverse(a + 1, a + n + 1);
            reverse(b + 1, b + n + 1);
            reverse(val + 1, val + n + 1);
        }
        bool ans = true;
        for(int i = 1; i <= n; i++) ans &= val[i];
        cout << (ans ? "YES" : "NO") << endl;
    }
}
```
[1904E - Запросы на дереве](../problems/E._Tree_Queries.md "Codeforces Round 914 (Div. 2)")

Idea: [Apple_Method](https://codeforces.com/profile/Apple_Method "Мастер Apple_Method")   
 Preparation: [oursaco](https://codeforces.com/profile/oursaco "Международный мастер oursaco")

Editorial 1:   
 Analysis: [oursaco](https://codeforces.com/profile/oursaco "Международный мастер oursaco")

Thanks to [errorgorn](https://codeforces.com/profile/errorgorn "Международный гроссмейстер errorgorn") for the solution!

 **Hint 1**The solution doesn't involve virtual tree

 **Hint 2**What is an easy way to represent the tree?

 **Solution**Consider the Euler tour of the tree where in[u] is the entry time of each node and out[u] is the exit time. The interval [in[u],out[u]] corresponds to the subtree of u. 

Removing a node is equivalent to blocking some intervals on the Euler tour. There are two cases when a is blocked with respect to query node x. If a is an ancestor of x, then the set of reachable nodes is reduced to the interval [in[nxta],out[nxta]], where nxta is the first node on the path from a to x. This is equivalent to blocking the intervals [0,in[nxta]) and (out[nxta],n−1]. If a is not an ancestor, then the interval [in[a],out[a]] is blocked.

Lets build a lazy segment tree on the Euler tour of the tree. Each leaf node will correspond to the depth of a node on the tree. We can re-root the tree from a to b by subtracting one from all nodes the range [in[b],out[b]] and adding one to all other nodes. Thus, we can traverse the tree while re-rooting and process our queries offline. When the query node x is the root, block all the necessary intervals and then find the maximum value in the segment tree.

 **Code**
```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;

template<class K> using sset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

inline ll ceil0(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}

void setIO() {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

const int MAXN = 2e5;
const int MAXQ = 2e5;

int seg[4*MAXN + 5];
int tag[4*MAXN + 5];
int tim;
vector<int> g[MAXN + 5];
int in[MAXN + 5], out[MAXN + 5];

void push_down(int cur){
    if(!tag[cur]) return;
    for(int i = cur*2 + 1; i <= cur*2 + 2; i++){
        seg[i] += tag[cur];
        tag[i] += tag[cur];
    }
    tag[cur] = 0;
}

void update(int l, int r, int v, int ul = 0, int ur = tim - 1, int cur = 0){
    if(l <= ul && ur <= r){
        seg[cur] += v;
        tag[cur] += v;
        return;
    }
    push_down(cur);
    int mid = (ul + ur)/2;
    if(l <= mid) update(l, r, v, ul, mid, cur*2 + 1);
    if(r > mid) update(l, r, v, mid + 1, ur, cur*2 + 2);
    seg[cur] = max(seg[cur*2 + 1], seg[cur*2 + 2]);
}

int query(int l, int r, int ul = 0, int ur = tim - 1, int cur = 0){
    if(l <= ul && ur <= r) return seg[cur];
    push_down(cur);
    int mid = (ul + ur)/2;
    if(r <= mid) return query(l, r, ul, mid, cur*2 + 1);
    if(l > mid) return query(l, r, mid + 1, ur, cur*2 + 2);
    return max(query(l, r, ul, mid, cur*2 + 1), query(l, r, mid + 1, ur, cur*2 + 2));
}

void dfs1(int x, int p = 0){
    in[x] = tim++;
    for(int i : g[x]){
        if(i == p) continue;
        dfs1(i, x);
    }
    out[x] = tim - 1;
}

vector<pair<int, vector<int>>> que[MAXN + 5];
int nxt[MAXN + 5];
int ans[MAXQ + 5];
int n, q;

void dfs2(int x, int p = 0){
    for(auto &i : que[x]){
        vector<pii> skip;
        bool found = false;
        for(int j : i.ss){
            if(j == x){
                found = true;
                break;
            }
            if(in[j] <= in[x] && in[x] <= out[j]){
                skip.pb({0, in[nxt[j]] - 1});
                skip.pb({out[nxt[j]] + 1, tim - 1});
            } else {
                skip.pb({in[j], out[j]});
            }
        }
        if(found) continue;
        sort(skip.begin(), skip.end());
        int prv = 0;
        for(pii j : skip){
            if(prv < j.ff) ans[i.ff] = max(ans[i.ff], query(prv, j.ff - 1));
            prv = max(prv, j.ss + 1);
        }
        if(prv <= tim - 1) ans[i.ff] = max(ans[i.ff], query(prv, tim - 1));
    }
    update(0, tim - 1, 1);
    for(int i : g[x]){
        if(i == p) continue;
        update(in[i], out[i], -2);
        nxt[x] = i;
        dfs2(i, x);
        update(in[i], out[i], 2);
    }
    update(0, tim - 1, -1);
}

int main(){
    setIO();
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    tim = 0;
    dfs1(1);
    for(int i = 0; i < q; i++){
        int x, k;
        cin >> x >> k;
        vector<int> v(k);
        for(int j = 0; j < k; j++) cin >> v[j];
        que[x].pb({i, v});
    }
    for(int i = 2; i <= n; i++) update(in[i], out[i], 1);
    dfs2(1);
    for(int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
}
```
Editorial 2:   
 Analysis: [willy108](https://codeforces.com/profile/willy108 "Мастер willy108")

 **Hint 1**In a tree, one of the farthest nodes from some node x is one of the two endpoints of the diameter.

 **Hint 2**Let's try to find the diameter of the connected subgraph node x is in after the nodes a1…n are removed.

 **Hint 3**Consider an euler tour of the tree and order the nodes by their inorder traversal. When k nodes are removed, the remaining nodes form O(k) contiguous intervals in the tour.

 **Solution**Let's build a segtree/sparse table where each node stores the diameter (as a pair of nodes) for the nodes with in values in the range [l,r]. To merge two diameters, we can enumerate all (42) ways to pick the new diameter and take the best one. 

To answer a query, we can first generate a list of banned intervals (just like solution 1) and use that list to generate the list of unbanned intervals. Then we can query our segtree for the diameter of each of ranges. Finally, we can combine the answers of the seperate queries to obtain the diameter of the connected subgraph. We know the farthest node from node x is one of the two endpoints, so it suffices to just manually check the distance of those two nodes.

Final complexity is O(nlog2n+∑klogn).

 **Code**
```cpp
#include <bits/stdc++.h>

#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()
#define pb push_back
#define eb emplace_back

const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;

//lca template start
vector<int> dep, sz, par, head, tin, tout, tour;
vector<vector<int>> adj;
int n, ind, q;
void dfs(int x, int p){
	sz[x] = 1;
	dep[x] = dep[p] + 1;
	par[x] = p;
	for(auto &i : adj[x]){
		if(i == p) continue;
		dfs(i, x);
		sz[x] += sz[i];
		if(adj[x][0] == p || sz[i] > sz[adj[x][0]]) swap(adj[x][0], i);
	}
	if(p != 0) adj[x].erase(find(all(adj[x]), p));
}
void dfs2(int x, int p){
	tour[ind] = x;
	tin[x] = ind++;
	for(auto &i : adj[x]){
		if(i == p) continue;
		head[i] = (i == adj[x][0] ? head[x] : i);
		dfs2(i, x);
	}
	tout[x] = ind;
}

int k_up(int u, int k){
	if(dep[u] <= k) return -1;
	while(k > dep[u] - dep[head[u]]){
		k -= dep[u] - dep[head[u]] + 1;
		u = par[head[u]];
	}
	return tour[tin[u] - k];
}

int lca(int a, int b){
	while(head[a] != head[b]){
		if(dep[head[a]] > dep[head[b]]) swap(a, b);
		b = par[head[b]];
	}
	if(dep[a] > dep[b]) swap(a, b);
	return a;
}

int dist(int a, int b){
	return dep[a] + dep[b] - 2*dep[lca(a, b)];
}
//lca template end
//segtree template start
#define ff first
#define ss second
int dist(pair<int, int> a){
	return dist(a.ff, a.ss);
}
pair<int, int> merge(pair<int, int> a, pair<int, int> b){
	auto p = max(pair(dist(a), a), pair(dist(b), b));
	for(auto x : {a.ff, a.ss}){
		for(auto y : {b.ff, b.ss}){
			if(x == 0 || y == 0) continue;
			p = max(p, pair(dist(pair(x, y)), pair(x, y)));
		}
	}
	return p.ss;
}

pair<int, int> mx[MX*4];
#define LC(k) (2*k)
#define RC(k) (2*k +1)
void update(int p, int v, int k, int L, int R){
	if(L + 1 == R){
		mx[k] = {tour[p], tour[p]};
		return ;
	}
	int mid = (L + R)/2;
	if(p < mid) update(p, v, LC(k), L, mid);
	else update(p, v, RC(k), mid, R);
	mx[k] = merge(mx[LC(k)], mx[RC(k)]);
}

void query(int qL, int qR, vector<pair<int, int>>& ret, int k, int L, int R){
	if(qR <= L || R <= qL) return ;
	if(qL <= L && R <= qR){
		ret.push_back(mx[k]);
		return ;
	}
	int mid = (L + R)/2;
	query(qL, qR, ret, LC(k), L, mid);
	query(qL, qR, ret, RC(k), mid, R);
}

//segtree template end

int query(vector<int> arr, int x){
	vector<pair<int, int>> banned, ret;
	for(int u : arr){
		if(lca(u, x) == u){
			u = k_up(x, dep[x] - dep[u] - 1);
			banned.push_back({0, tin[u]});
			banned.push_back({tout[u], n});
		}else{
			banned.push_back({tin[u], tout[u]});
		}
	}
	sort(all(banned), [&](pair<int, int> a, pair<int, int> b){
		return (a.ff < b.ff) || (a.ff == b.ff && a.ss > b.ss);
			});
	vector<pair<int, int>> tbanned; //remove nested intervals
	int mx = 0;
	for(auto [a, b] : banned){
		if(b <= mx) continue;
		else if(a != b){
			tbanned.pb({a, b});
			mx = b;
		}
	}

	banned = tbanned;
	int tim = 0;
	for(auto [a, b] : banned){
		if(tim < a) 
			query(tim, a, ret, 1, 0, n);
		tim = b;
	}

	if(tim < n) 
		query(tim, n, ret, 1, 0, n);
	pair<int, int> dia = pair(x, x);
	for(auto p : ret) dia = merge(dia, p);
	int ans = max(dist(x, dia.ff), dist(x, dia.ss));
	return ans;
}

void solve(){
	cin >> n >> q;
	dep = sz = par = head = tin = tout = tour = vector<int>(n+1, 0);
	adj = vector<vector<int>>(n+1);
	for(int i = 1; i<n; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(1, 0);
	head[1] = 1;
	dfs2(1, 0);
	for(int i = 1; i<=n; i++){
		update(tin[i], dep[i], 1, 0, n);
	}
	for(int i = 1; i<=q; i++){
		int x, k;
		cin >> x >> k;
		vector<int> arr(k);
		for(int& y : arr) cin >> y;		
		cout << query(arr, x) << "n";
	}
}

signed main(){
  cin.tie(0) -> sync_with_stdio(0);

  int T = 1;
  //cin >> T;
  for(int i = 1; i<=T; i++){
		//cout << "Case #" << i << ": ";
		solve();
	}
  return 0;
}
```
[1904F - Прекрасное дерево](../problems/F._Beautiful_Tree.md "Codeforces Round 914 (Div. 2)")

Idea: [Apple_Method](https://codeforces.com/profile/Apple_Method "Мастер Apple_Method")   
 Preparation: [oursaco](https://codeforces.com/profile/oursaco "Международный мастер oursaco")   
 Analysis: [Apple_Method](https://codeforces.com/profile/Apple_Method "Мастер Apple_Method")

 **Hint**Can we represent the conditions as a graph?

 **Solution**Lets rewrite the condition that node a must be smaller than node b as a directed edge from a to b. Then, we can assign each node a value based on the topological sort of this new directed graph. If this directed graph had a cycle, it is clear that there is no way to order the nodes. 

With this in mind, we can try to construct a graph that would have these properties. Once we have the graph, we can topological sort to find the answer. 

For now, let's consider the problem if it only had type 1 requirements (type 2 requirements can be done very similarly). 

Thus, the problem reduces to "given a path and a node, add a directed edge from the node to every node in that path." To do this, we can use binary lifting. For each node, create k dummy nodes, the ith of which represents the minimum number from the path between node a and the 2ith parent of a. Now, we can draw a directed edge from the the ith dummy node of a to the i−1th dummy node of a and the i−1th dummy node of the 2i−1th parent of a. 

Now, to add an edge from any node to a vertical path of the tree, we can repeatedly add an edge from that node to the largest node we can. This will add O(logn) edges per requirement. 

The final complexity is O((n+m)logn) time and O((n+m)logn). 

 **Code**
```cpp
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;

template<class K> using sset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

inline ll ceil0(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}

void setIO() {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

const int MAXN = 200'000;
const int LG = 18;
const int MAXM = 200'000;

vector<int> g[MAXN + 5];
int sz[MAXN + 5], in[MAXN + 5], par[MAXN + 5], depth[MAXN + 5], head[MAXN + 5], tim;
int n, m;

void dfs1(int x, int p){
    sz[x] = 1;
    for(int &i : g[x]){
        if(i == p) continue;
        dfs1(i, x);
        sz[x] += sz[i];
        if(g[x][0] == p || sz[i] > sz[g[x][0]]) swap(g[x][0], i);
    }
}
 
void dfs2(int x, int p){
    in[x] = tim++;
    par[x] = p;
    depth[x] = depth[p] + 1;
    for(int i : g[x]){
        if(i == p) continue;
        head[i] = (i == g[x][0] ? head[x] : i);
        dfs2(i, x);
    }
}

const int MAXSZ = MAXN + 2*MAXN*LG;
int down[LG][MAXN + 5];
int up[LG][MAXN + 5];
vector<int> dag[MAXSZ+ 5];
int lg[MAXN + 5];

void upd(int l, int r, int x, int t){
    if(l <= in[x] && in[x] <= r){
        if(l < in[x]) upd(l, in[x] - 1, x, t);
        if(in[x] < r) upd(in[x] + 1, r, x, t);
    } else {
        int sz = lg[r - l + 1];
        if(t == 2){
            dag[up[sz][l]].pb(x);
            dag[up[sz][r - (1 << sz) + 1]].pb(x);
        } else {
            dag[x].pb(down[sz][l]);
            dag[x].pb(down[sz][r - (1 << sz) + 1]);
        }
    }
}

//1 is down, 2 is up
void draw(int a, int b, int c, int t){
    while(head[a] != head[b]){
        if(depth[head[a]] > depth[head[b]]) swap(a, b);
        upd(in[head[b]], in[b], c, t);
        b = par[head[b]];
    }
    if(depth[a] > depth[b]) swap(a, b);
    upd(in[a], in[b], c, t);
}

bool vis[MAXSZ + 5], stk[MAXSZ + 5];
vector<int> ord;
bool fail;
int ind;

void dfs3(int x){
    if(fail) return;
    vis[x] = stk[x] = true;
    for(int i : dag[x]){
        if(i == x) continue;
        if(!vis[i]){
            dfs3(i);
        } else if(stk[i]){
            fail = true;
            break;
        }
    }
    stk[x] = false;
    if(x <= n) ord.pb(x);
}

int main(){
    setIO();
    cin >> n >> m;
    lg[1] = 0;
    for(int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    tim = 0;
    dfs1(1, 1);
    head[1] = 1;
    dfs2(1, 1);
    for(int i = 1; i <= n; i++) down[0][in[i]] = up[0][in[i]] = i;
    ind = n + 1;
    for(int i = 1; i < LG; i++){
        for(int j = 0; j + (1 << i) <= n; j++){
            down[i][j] = ind++;
            up[i][j] = ind++;

            dag[down[i][j]].pb(down[i - 1][j]);
            dag[down[i][j]].pb(down[i - 1][j + (1 << (i - 1))]);

            dag[up[i - 1][j]].pb(up[i][j]);
            dag[up[i - 1][j + (1 << (i - 1))]].pb(up[i][j]);
        }
    }
    for(int i = 0; i < m; i++){
        int t, a, b, c;
        cin >> t >> a >> b >> c;
        draw(a, b, c, t);
    }
    fail = false;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs3(i);
            if(fail) break;
        }
    }
    if(fail){
        cout << -1 << endl;
        return 0;
    }
    reverse(ord.begin(), ord.end());
    int ans[n + 1];
    for(int i = 0; i < ord.size(); i++){
        ans[ord[i]] = i + 1;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}
```
