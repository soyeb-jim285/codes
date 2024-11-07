# Tutorial

[1651A - Playoff](../problems/A._Playoff.md "Educational Codeforces Round 124 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1651A - Playoff](../problems/A._Playoff.md "Educational Codeforces Round 124 (Rated for Div. 2)")

During the first stage, every player with an even index competes against a player with an odd index, so in each match during the first stage, the player whose index is smaller wins. The pairs are formed in such a way that, in each pair, the player with an odd index has smaller index, so all players with even indices get eliminated, and all players with odd indices advance to the next stage.

All of the remaining matches are between players with odd indices, so the winner of each match is the player with the larger index. So, the overall winner of the tournament is the player with the greatest odd index, which is $2^n-1$.

Note: in some languages (for example, C++), standard power functions work with floating-point numbers instead of integers, so they will produce the answer as a floating-point number (which may lead to wrong formatting of the output and/or calculation errors). You might have to implement your own power function that works with integers, or compute $2^n$ using a loop.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    n = int(input())
    print(2 ** n - 1)
```
[1651B - Prove Him Wrong](../problems/B._Prove_Him_Wrong.md "Educational Codeforces Round 124 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1651B - Prove Him Wrong](../problems/B._Prove_Him_Wrong.md "Educational Codeforces Round 124 (Rated for Div. 2)")

Suppose the initial sum of $a$ is equal to $S$. If we perform the operation, the new sum will be equal to $S' = S - (a_i + a_j) + 2 |a_i - a_j|$. We want the sum not to decrease, or $S' \ge S$. If $a_i \ge a_j$, we will get: $$S' \ge S,$$ $$S - (a_i + a_j) + 2 (a_i - a_j) \ge S,$$ $$a_i - 3 a_j \ge 0,$$ $$a_i \ge 3 a_j.$$ If $a_i \le a_j$ we'll get $3 a_i \le a_j$ analogically.

In other words, array $a$ you need (if sorted) will have $a_2 \ge 3 a_1$, $a_3 \ge 3 a_2$ and so on. And one of the variants (and, obviously, an optimal one) is just $[1, 3, 9, 27, \dots, 3^{n - 1}]$.

As a result, since $a_i \le 10^9$, we just need to check: if $3^{n - 1} \le 10^9$ then we found an answer, otherwise there is no counterexample.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	if 3**(n-1) > 10**9:
		print("NO")
	else:
		print("YES")
		print(*[3**x for x in range(n)])
```
[1651C - Fault-tolerant Network](../problems/C._Fault-tolerant_Network.md "Educational Codeforces Round 124 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1651C - Fault-tolerant Network](../problems/C._Fault-tolerant_Network.md "Educational Codeforces Round 124 (Rated for Div. 2)")

There is a criterion when the given network becomes fault-tolerant: the network becomes fault-tolerant if and only if each of corner computers (let's name them $A_1$, $A_n$, $B_1$ and $B_n$) is connected to the other row.

From the one side: if, WLOG, $A_1$ is not connected to other row then if $A_2$ is broken — $A_1$ loses connection to the other network (since $A_1$ is connected only with $A_2$).

From the other side: suppose, WLOG, $A_i$ is broken, then the row $A$ is falling in at most two parts: $A_1 - \dots - A_{i - 1}$ and $A_{i + 1} - \dots - A_n$. But since both $A_1$ and $A_n$ are connected to row $B$ and $B$ is still connected, then the resulting network is still connected.

Now the question is: how to connect all corner computers? Because sometimes it's optimal not to connect corners directly. One of the approaches is described below.

Let's look at $A_1$. Essentially, there are three ways to connect it to row $B$: to $B_1$, $B_n$ or $\mathrm{best}_B(A_1)$ (where $\mathrm{best}_B(A_1)$ is $B_j$ with minimum possible $|a_i - b_j|$). The same applies to $A_n$.

So, let's just iterate over all these $3 \times 3$ variants. For each of these variants, 

* if we didn't cover $B_1$ then we should also add one more connection between $B_1$ and $\mathrm{best}_A(B_1)$;
* if we didn't cover $B_n$ then we should also add one more connection between $B_n$ and $\mathrm{best}_A(B_n)$;

As a result, we choose the best variant.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;

const int INF = int(1e9);

int n;
vector<int> a, b;

inline bool read() {
	if(!(cin >> n))
		return false;
	a.resize(n);
	fore (i, 0, n)
		cin >> a[i];
	b.resize(n);
	fore (i, 0, n)
		cin >> b[i];
	return true;
}

int bestCandidate(const vector<int> &vals, int cur) {
	int bst = INF + 10, pos = -1;
	fore (i, 0, n) {
		if (bst > abs(cur - vals[i])) {
			bst = abs(cur - vals[i]);
			pos = i;
		}
	}
	return pos;
}

inline void solve() {
	li bst = 10ll * INF;
	
	vector<int> cds1 = {0, bestCandidate(b, a[0]), n - 1};
	vector<int> cds2 = {0, bestCandidate(b, a[n - 1]), n - 1};
	
	for (int var1 : cds1) {
		for (int var2 : cds2) {
			li ans = (li)abs(a[0] - b[var1]) + abs(a[n - 1] - b[var2]);
			
			if (var1 > 0 && var2 > 0)
				ans += abs(b[0] - a[bestCandidate(a, b[0])]);
			if (var1 < n - 1 && var2 < n - 1)
				ans += abs(b[n - 1] - a[bestCandidate(a, b[n - 1])]);
			
			bst = min(bst, ans);
		}
	}
	cout << bst << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while (t--) {
		read();
		solve();
	}
	return 0;
}
```
[1651D - Nearest Excluded Points](../problems/D._Nearest_Excluded_Points.md "Educational Codeforces Round 124 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1651D - Nearest Excluded Points](../problems/D._Nearest_Excluded_Points.md "Educational Codeforces Round 124 (Rated for Div. 2)")

Firstly, we can find answers for all points that are adjacent to at least one point not from the set. The distance for such points is obviously $1$ (and this is the smallest possible answer we can get). On the next iteration, we can set answers for all points that are adjacent to points with found answers (because they don't have neighbors not from the set, the distance for them is at least $2$). It doesn't matter which point we will take, so if the point $i$ is adjacent to some point $j$ that have the answer $1$, we can set the answer for the point $i$ as the answer for the point $j$. We can repeat this process until we find answers for all points. In terms of the code, this can be done by breadth first search (BFS). In other words, we set answers for the points that have the distance $1$ and then push these answers to all adjacent points from the set in order of the increasing distance until we find all the answers.

Time complexity: $O(n \log{n})$.

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a(n);
    for (auto &[x, y] : a) scanf("%d %d", &x, &y);
    
    set<pair<int, int>> st(a.begin(), a.end());
    map<pair<int, int>, pair<int, int>> ans;
    queue<pair<int, int>> q;
    for (auto [x, y] : a) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (st.count({nx, ny})) {
                continue;
            }
            ans[{x, y}] = {nx, ny};
            q.push({x, y});
            break;
        }
    }
    
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!st.count({nx, ny}) || ans.count({nx, ny})) {
                continue;
            }
            ans[{nx, ny}] = ans[{x, y}];
            q.push({nx, ny});
        }
    }
    
    for (auto [x, y] : a) {
        auto it = ans[{x, y}];
        printf("%d %dn", it.first, it.second);
    }
    
    return 0;
}
```
[1651E - Sum of Matchings](../problems/E._Sum_of_Matchings.md "Educational Codeforces Round 124 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1651E - Sum of Matchings](../problems/E._Sum_of_Matchings.md "Educational Codeforces Round 124 (Rated for Div. 2)")

Instead of counting the edges belonging to the maximum matching, it is easier to count the vertices. So, we will calculate the total number of vertices saturated by the maximum matching over all possible tuples $(l, r, L, R)$, and then divide the answer by $2$. Furthermore, it's easier to calculate the number of unsaturated vertices than the number of saturated vertices, so we can subtract it from the total number of vertices in all graphs we consider and obtain the answer.

Let's analyze how to calculate the total number of unsaturated vertices. Each graph $G'(l, r, L, R)$ is a subgraph of the given graph, so it is still bipartite, and the degree of each vertex is still not greater than $2$. A bipartite graph where the degree of each vertex is at most $2$ can be represented as a set of cycles and paths, and the maximum matching over each of these cycles/paths can be considered independently. Each cycle has an even number of vertices (since otherwise the graph would not be bipartite), so we can saturate all vertices on a cycle with the matching. For a path, the number of unsaturated vertices depends on its length: if the number of vertices in a path is even, we can match all vertices on it; otherwise, one vertex will be unsaturated. So the problem reduces to counting paths with odd number of vertices in all possible graphs $G'(l, r, L, R)$.

Every path with an odd number of vertices has a center (the vertex which is exactly in the middle of the path). Let's iterate on the center of the path and its length, and calculate the number of times this path occurs in all graphs we consider. Suppose the center of the path is the vertex $x$, and the number of vertices in it is $2k+1$. Then, for this path to exist, two conditions must hold:

* every vertex $y$ such that the distance from $x$ to $y$ is not greater than $k$ should be present in the graph;
* every vertex $z$ such that the distance from $x$ to $z$ is exactly $k+1$ should be excluded from the graph.

It means that, for each of the two parts of the graph, there are several vertices that should be present in the graph, and zero or two vertices that should be excluded from the graph. It's easy to see that among the vertices we have to include, we are only interested in the minimum one and the maximum one (all vertices between them will be included as well if these two are included). So, we need to implement some kind of function that allows us to calculate the number of segments that cover the minimum and the maximum vertex we need, and don't cover any of the vertices that we have to exclude — this can be easily done in $O(1)$. Note that the segments should be considered independently for both parts of the graph.

Overall, for each vertex we have to consider at most $O(n)$ different lengths of odd paths with the center in this vertex. The minimum/maximum indices of vertices in both parts we have to include in the graph can be maintained while we increase the length of the path, so the whole solution works in $O(n^2)$.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 3043;

vector<int> g[2 * N];
int n;
int used[2 * N];

int choose2(int n)
{
    return n * (n + 1) / 2;
}

int count_ways(int L, int R, const vector<int>& forbidden)
{
    if(L > R)
    {
        int ml = *min_element(forbidden.begin(), forbidden.end());
        int mr = *max_element(forbidden.begin(), forbidden.end());
        return choose2(ml) + choose2(mr - ml - 1) + choose2(n - 1 - mr);
    }
    int minl = 0;
    int maxl = L;
    int minr = R;
    int maxr = n - 1;
    for(auto x : forbidden)
    {
        if(L <= x && x <= R)
            return 0;
        else if(x < L) minl = max(minl, x + 1);
        else maxr = min(maxr, x - 1);
    }                            
    return (maxl - minl + 1) * (maxr - minr + 1);
}

vector<int> cur;

void dfs(int x)
{
    if(used[x] == 1) return;
    used[x] = 1;
    cur.push_back(x);
    for(auto y : g[x]) dfs(y);
}

long long calc(const vector<int>& cycle)
{
    int m = cycle.size();
    int k = m / 2;
    long long ans = 0;
    for(int i = 0; i < m; i++)
    {
        int z = cycle[i];
        if(z >= n) z -= n;
        ans += choose2(n) * 1ll * (choose2(z) + 0ll + choose2(n - z - 1));
        int l = n - 1, r = 0, L = n - 1, R = 0;
        int pl = i, pr = i;
        for(int j = 0; j < k; j++)
        {
            for(auto x : vector<int>({cycle[pl], cycle[pr]}))
            {
                if(x < n)
                {
                    l = min(l, x);
                    r = max(r, x);
                }
                else
                {
                    L = min(L, x - n);
                    R = max(R, x - n);
                }
            }
            vector<int> f, F;
            pl--;
            if(pl < 0) pl += m;
            pr++;
            if(pr >= m) pr -= m;
            for(auto x : vector<int>({cycle[pl], cycle[pr]}))
            {                     
                if(x < n) f.push_back(x);
                else F.push_back(x - n);
            }
            long long add = count_ways(l, r, f) * 1ll * count_ways(L, R, F);
            ans += add;
        }
    }
    return ans;       
}

int main()
{
    cin >> n;
    for(int i = 0; i < 2 * n; i++)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    long long ans = n * 1ll * choose2(n) * 1ll * choose2(n) * 2ll;
    for(int i = 0; i < n; i++)
    {
        if(used[i]) continue;
        dfs(i);
        vector<int> cycle = cur;
        ans -= calc(cycle);
        cur = vector<int>();
    }
    cout << ans / 2 << endl;
}
```
[1651F - Tower Defense](../problems/F._Tower_Defense.md "Educational Codeforces Round 124 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1651F - Tower Defense](../problems/F._Tower_Defense.md "Educational Codeforces Round 124 (Rated for Div. 2)")

Let's start thinking about the problem from the easy cases.

How to solve the problem fast if all towers have full mana? We can store prefix sums of their capacities and find the first tower that doesn't get drained completely with a binary search.

Let's try the opposite. How to solve the problem fast if all towers were drained completely in the previous second? It's the same but the prefix sums are calculated over regeneration rates.

What if all towers were drained at the same second, earlier than the previous second, and no tower is fully restored yet? It's also the same but the regeneration rates are multiplied by the time passed since the drain.

What if we drop the condition about the towers not being fully restored? How would a data structure that can answer prefix sum queries work? It should store the total mana capacity of all towers that are full. Then mana regeneration rates for all towers that aren't. If these are kept separately, then it's easy to obtain the prefix sum by providing the time passed. This will be total capacity plus total regeneration rate, multiplied by the time passed.

How to determine if the tower is fully restored since the drain or not? That's easy. For each tower, we can calculate the number of seconds it takes it to get restored from zero. That is $\lceil \frac{c}{r} \rceil$. Thus, all towers that have this value smaller than the time passed won't get restored. All the rest will.

Unfortunately, in the actual problem, not all towers were last drained at the same time. However, it's possible to reduce the problem to that. Store the segments of towers that were drained at same time. There are also towers that weren't drained completely, but they can be stored as segments of length $1$ too. When a monster comes, it drains some prefix of the towers completely and possibly one more tower partially. In terms of segments, it removes some prefix of the them and possibly cuts one. Then it creates a segment that covers the prefix and possibly a segment of length $1$ (with a partially drained tower). So each monster creates $O(1)$ segments and removes no more segments than were created. Thus, if we were to process each creation and removal in some $O(T)$, then the complexity will be $O(qT)$.

All towers on each segment have the same time passed since the drain. We want to query the sum on the entire segment. If it is greater than the remaining health of the monster, we want to find the largest prefix of this segment that has a smaller or equal sum than the monster health.

Given time passed, let's learn to query the range sum. If we knew the queries beforehand, it would be easy. Initialize a segment tree as if all towers are completely restored. Then make events of two kinds: a tower with restore time $\lceil \frac{c}{r} \rceil$ and a query with time $t$. Sort them in the decreasing order and start processing one by one. When a tower event happens, update a single position in the segment tree from capacity to regeneration rate. When a query event happens, find the sum.

Since the queries are not known beforehand, make that segment tree persistent and ask specific versions of it. If a segment of towers was last drained at time $t_{\mathit{lst}}$, and the query is at time $t$, then you should query the segment tree in version $t - t_{\mathit{lst}}$. Obviously, you can store not all versions but only ones that have some tower change. Moreover, it's more convenient to make one version responsible for one tower update. Then you can lower_bound the array of sorted $\lceil \frac{c}{r} \rceil$ to find the version you want to ask at.

To determine the largest prefix of this segment that has a smaller or equal sum than the monster health, you can either binary search for $O(\log^2 n)$ or traverse the segment tree for $O(\log n)$. The time limit might be a little tight for the first approach, but it can still pass.

Overall complexity: $O((n + q) \log n)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct node{
	node *l, *r;
	long long sumc, sumr;
	node() : l(NULL), r(NULL), sumc(0), sumr(0) {}
	node(node* l, node* r, long long sumc, long long sumr) : l(l), r(r), sumc(sumc), sumr(sumr) {}
};

node* build(int l, int r, vector<int> &c){
	if (l == r - 1)
		return new node(NULL, NULL, c[l], 0);
	int m = (l + r) / 2;
	node* nw = new node();
	nw->l = build(l, m, c);
	nw->r = build(m, r, c);
	nw->sumc = nw->l->sumc + nw->r->sumc;
	return nw;
}

node* upd(node* v, int l, int r, int pos, int val){
	if (l == r - 1)
		return new node(NULL, NULL, 0, val);
	int m = (l + r) / 2;
	node* nw = new node(v->l, v->r, 0, 0);
	if (pos < m)
		nw->l = upd(v->l, l, m, pos, val);
	else
		nw->r = upd(v->r, m, r, pos, val);
	nw->sumc = nw->l->sumc + nw->r->sumc;
	nw->sumr = nw->l->sumr + nw->r->sumr;
	return nw;
}

long long getsum(node *v, int mult){
	return v->sumc + v->sumr * mult;
}

int trav(node *v, int l, int r, int L, int R, long long &lft, int mult){
	if (L >= R){
		return 0;
	}
	if (l == L && r == R && lft - getsum(v, mult) >= 0){
		lft -= getsum(v, mult);
		return r - l;
	}
	if (l == r - 1){
		return 0;
	}
	int m = (l + r) / 2;
	int cnt = trav(v->l, l, m, L, min(m, R), lft, mult);
	if (cnt == max(0, min(m, R) - L))
		cnt += trav(v->r, m, r, max(m, L), R, lft, mult);
	return cnt;
}

struct seg{
	int l, r, lst, cur;
};

int main() {
	int n;
	scanf("%d", &n);
	vector<int> c(n), r(n);
	forn(i, n) scanf("%d%d", &c[i], &r[i]);
	
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int x, int y){
		return c[x] / r[x] > c[y] / r[y];
	});
	vector<int> vals;
	for (int i : ord) vals.push_back(c[i] / r[i]);
	
	vector<node*> root(1, build(0, n, c));
	for (int i : ord)
		root.push_back(upd(root.back(), 0, n, i, r[i]));
	
	vector<seg> st;
	for (int i = n - 1; i >= 0; --i)
		st.push_back({i, i + 1, 0, c[i]});
	
	long long ans = 0;
	int q;
	scanf("%d", &q);
	forn(_, q){
		int t;
		long long h;
		scanf("%d%lld", &t, &h);
		while (!st.empty()){
			auto it = st.back();
			st.pop_back();
			if (it.r - it.l == 1){
				it.cur = min((long long)c[it.l], it.cur + (t - it.lst) * 1ll * r[it.l]);
				if (it.cur <= h){
					h -= it.cur;
				}
				else{
					st.push_back({it.l, it.r, t, int(it.cur - h)});
					h = 0;
				}
			}
			else{
				int mx = vals.rend() - lower_bound(vals.rbegin(), vals.rend(), t - it.lst);
				int res = it.l + trav(root[mx], 0, n, it.l, it.r, h, t - it.lst);
				assert(res <= it.r);
				if (res != it.r){
					if (it.r - res > 1)
						st.push_back({res + 1, it.r, it.lst, 0});
					int nw = min((long long)c[res], r[res] * 1ll * (t - it.lst));
					assert(nw - h > 0);
					st.push_back({res, res + 1, t, int(nw - h)});
					h = 0;
				}
			}
			if (h == 0){
				break;
			}
		}
		if (st.empty()){
			st.push_back({0, n, t, 0});
		}
		else if (st.back().l != 0){
			st.push_back({0, st.back().l, t, 0});
		}
		ans += h;
	}
	
	printf("%lldn", ans);
	return 0;
}
```
