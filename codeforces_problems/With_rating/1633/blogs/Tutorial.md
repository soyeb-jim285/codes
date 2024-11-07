# Tutorial

[1633A - Div. 7](../problems/A._Div._7.md "Educational Codeforces Round 122 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1633A - Div. 7](../problems/A._Div._7.md "Educational Codeforces Round 122 (Rated for Div. 2)")

A lot of different solutions can be written in this problem. The model solution relies on the fact that every 7-th integer is divisible by 7, and it means that there is always a way to change the last digit of n (or leave it unchanged) so that the result is divisible by 7. So, if n is already divisible by 7, we just print it, otherwise we change its last digit using some formulas or iteration on its value from 0 to 9.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    n = int(input())
    if n % 7 == 0:
        print(n)
    else:
        ans = -1
        for j in range(10):
            if (n - n % 10 + j) % 7 == 0:
                ans = n - n % 10 + j
        print(ans)
```
[1633B - Minority](../problems/B._Minority.md "Educational Codeforces Round 122 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo") and [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1633B - Minority](../problems/B._Minority.md "Educational Codeforces Round 122 (Rated for Div. 2)")

Let's try to estimate the maximum possible answer. Best case, you will be able to remove either all zeros or all ones from the entire string. Whichever has the least occurrences, can be the answer.

If the amounts of zeros and ones in the string are different, this bound is actually easy to reach: just choose the substring that is the entire string.

If the amounts are the same, the bound is impossible to reach. Choosing the entire string will do nothing, and asking a smaller substring will decrease the answer.

The smallest we can decrease the answer by is 1. If you choose the substring that is the string without the last character, you will decrease one of the amounts by one. That will make the amounts different, and the bound will be reached.

Overall complexity: O(|s|) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
    s = input()
    print(min((len(s) - 1) // 2, s.count('0'), s.count('1')))
```
[1633C - Kill the Monster](../problems/C._Kill_the_Monster.md "Educational Codeforces Round 122 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1633C - Kill the Monster](../problems/C._Kill_the_Monster.md "Educational Codeforces Round 122 (Rated for Div. 2)")

First of all, let's understand how to solve the problem without upgrades. To do this, it is enough to compare two numbers: ⌈hMdC⌉ and ⌈hCdM⌉ — the number of attacks that the character needs to kill the monster and the number of attacks that the monster needs to kill the character, respectively. So, if the first number is not greater than the second number, then the character wins.

Note that the number of coins is not very large, which means we can iterate over the number of coins that we will spend on weapon upgrades, and the remaining coins will be spent on armor upgrades. After that, we can use the formula described above to check whether the character will win.

The complexity of the solution is O(k).

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
    hc, dc = map(int, input().split())
    hm, dm = map(int, input().split())
    k, w, a = map(int, input().split())
    for i in range(k + 1):
        nhc = hc + i * a
        ndc = dc + (k - i) * w
        if (hm + ndc - 1) // ndc <= (nhc + dm - 1) // dm:
            print("YES")
            break
    else:
        print("NO")
```
[1633D - Make Them Equal](../problems/D._Make_Them_Equal.md "Educational Codeforces Round 122 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1633D - Make Them Equal](../problems/D._Make_Them_Equal.md "Educational Codeforces Round 122 (Rated for Div. 2)")

Let's calculate di — the minimum number of operations to get the number i from 1. To do this, it is enough to use BFS or dynamic programming. Edges in the graph (transitions in dynamic programming) have the form (i,i+⌊ix⌋) for all 1≤x≤i.

Now the problem itself can be reduced to a knapsack problem: there are n items, i-th item weighs dbi and costs ci, you have to find a set of items with the total weight of no more than k of the maximum cost. This is a standard problem that can be solved in O(nk), but it is too slow (although some participants passed all the tests with such a solution). However, we can notice that the values of di should not grow too fast, namely, the maximum value of di for 1≤i≤103 does not exceed 12. This means that the maximum possible weight is no more than 12n, and we can limit k to this number (i. e. make k=min(k,12n)).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

int main() {
  vector<int> d(N, N);
  d[1] = 0;
  for (int i = 1; i < N; ++i) {
    for (int x = 1; x <= i; ++x) {
      int j = i + i / x;
      if (j < N) d[j] = min(d[j], d[i] + 1);
    }
  }
  
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> b(n), c(n);
    for (int &x : b) cin >> x;
    for (int &x : c) cin >> x;
    int sum = 0;
    for (int x : b) sum += d[x];
    k = min(k, sum);
    vector<int> dp(k + 1, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = k - d[b[i]]; j >= 0; j--) {
        dp[j + d[b[i]]] = max(dp[j + d[b[i]]], dp[j] + c[i]);
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << 'n';
  }
}
```
[1633E - Spanning Tree Queries](../problems/E._Spanning_Tree_Queries.md "Educational Codeforces Round 122 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo")

 **Tutorial**
### [1633E - Spanning Tree Queries](../problems/E._Spanning_Tree_Queries.md "Educational Codeforces Round 122 (Rated for Div. 2)")

Consider a naive solution using Kruskal's algorithm for finding MST. Given some x, you arrange the edges in the increasing order of |wi−x| and process them one by one. 

Look closely at the arrangements. At x=0 the edges are sorted by wi. How does the arrangement change when x increases? Well, some edges swap places.

Consider a pair of edges with different weights w1 and w2 (w1<w2). Edge 1 will go before edge 2 in the arrangement as long as x is closer to w1 than w2. So for all x up to w1+w22, edge 1 goes before edge 2. And for all x from w1+w22 onwards, edge 2 goes before edge 1.

This tells us that every pair of edge with different weights will swap exactly once. So there will be at most O(m2) swaps. Which is at most O(m2) different arrangements. Each of them corresponds to some range of x's.

We can extract the ranges of x's for all arrangements and calculate MST at the start of each range. We can also find the arrangement that corresponds to some x from a query with a binary search.

However, only knowing the weight of the MST at the start of the range is not enough. The weights of edges change later in the range, and we can't predict how. Some edges have their weight increasing, some decreasing.

First, let's add more ranges. We want each edge to behave the same way on the entire range: either increase all the way or decrease all the way. If we also add x=wi for all i into the MST calculation, this will hold.

Second, let's store another value for each range: the number of edges that have their weight increasing on it. With that, we can easily recalculate the change in the cost of the spanning tree.

The TL should be free enough for you to sort the edges for each MST calculation, resulting in O(m2(mlogm+nlogn)+klogm) solution. You can also optimize the first part to O(m3).

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct edge{
	int v, u, w;
};

vector<int> pr, rk;

int getp(int a){
	return a == pr[a] ? a : pr[a] = getp(pr[a]);
}

bool unite(int a, int b){
	a = getp(a), b = getp(b);
	if (a == b) return false;
	if (rk[a] < rk[b]) swap(a, b);
	rk[a] += rk[b];
	pr[b] = a;
	return true;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	pr.resize(n);
	rk.resize(n);
	vector<edge> es(m);
	forn(i, m){
		scanf("%d%d%d", &es[i].v, &es[i].u, &es[i].w);
		--es[i].v, --es[i].u;
		es[i].w *= 2;
	}
	vector<int> ev(1, 0);
	forn(i, m) forn(j, i + 1) ev.push_back((es[i].w + es[j].w) / 2);
	sort(ev.begin(), ev.end());
	ev.resize(unique(ev.begin(), ev.end()) - ev.begin());
	vector<long long> base;
	vector<int> cnt;
	for (int x : ev){
		sort(es.begin(), es.end(), [&x](const edge &a, const edge &b){
			int wa = abs(a.w - x);
			int wb = abs(b.w - x);
			if (wa != wb) return wa < wb;
			return a.w > b.w;
		});
		forn(i, n) pr[i] = i, rk[i] = 1;
		long long cur_base = 0;
		int cur_cnt = 0;
		for (const auto &e : es) if (unite(e.v, e.u)){
			cur_base += abs(e.w - x);
			cur_cnt += x < e.w;
		}
		base.push_back(cur_base);
		cnt.push_back(cur_cnt);
	}
	int p, k, a, b, c;
	scanf("%d%d%d%d%d", &p, &k, &a, &b, &c);
	int x = 0;
	long long ans = 0;
	forn(q, k){
		if (q < p) scanf("%d", &x);
		else x = (x * 1ll * a + b) % c;
		int y = upper_bound(ev.begin(), ev.end(), 2 * x) - ev.begin() - 1;
		ans ^= (base[y] + (n - 1 - 2 * cnt[y]) * 1ll * (2 * x - ev[y])) / 2;
	}
	printf("%lldn", ans);
	return 0;
}

```
[1633F - Perfect Matching](../problems/F._Perfect_Matching.md "Educational Codeforces Round 122 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1633F - Perfect Matching](../problems/F._Perfect_Matching.md "Educational Codeforces Round 122 (Rated for Div. 2)")

Let's root the tree at vertex 1 and try to analyze when a tree contains a perfect matching. If we want to find the maximum matching in a tree, we can use some greedy approaches like "take a leaf of the tree, match it with its parent and remove both vertices, repeat this process until only isolated vertices remain". If we are interested in a perfect matching, then this process should eliminate all of the vertices.

Let's modify this process a bit by always picking the deepest leaf. If there exists a perfect matching, picking the deepest leaf will ensure that the tree always remains a tree and doesn't fall apart, i. e. there will always be one connected component. It means that when we remove the leaf with its parent, this leaf is the only descendant of its parent.

It's easy to see that whenever we remove a pair of vertices in this process, for each remaining vertex, the number of its descendants is either left unchanged or decreased by 2. It means that if a vertex has an even number of descendants, it will have an even number of descendants until it is removed, and the same for odd number of descendants.

Let's call the vertices with even number of descendants (including the vertex itself) even vertices, and all the other vertices — odd vertices. A vertex cannot change its status in the process of building the perfect matching. Each leaf is and odd vertex, and if its parent has only one child, this parent is an even vertex. So, when we remove a pair of vertices, one of them (the child) is odd, and the other of them (the parent) is even.

This leads us to another way of building the perfect matching: match each odd vertex with its parent, and make sure that everything is correct. Unfortunately, implementing it is O(n) per query, so we need something faster. We can see that each even vertex has at least one odd child (because if all children of a vertex are even, then the number of its descendants, including the vertex itself is odd). In order to find a perfect matching, we have to make sure that:

* each even vertex has exactly one odd child;
* each odd vertex has an even vertex as its parent.

All this means is that the number of even vertices should be equal to the number of odd vertices: it cannot be greater since each even vertex has at least one odd child, and if it is smaller, it's impossible to match the vertices. The perfect matching itself consists of edges that connect odd vertices with their parents.

Okay, now we need some sort of data structure to maintain the status of each vertex (and the sum of edges that lead to an odd vertex if directed from top to bottom). In our problem, we have to add new leaves to the tree (it happens when a vertex is activated), and this increases the number of descendants for every vertex on the path from the root to this new leaf. So, we need some sort of data structure that supports the operations "add a new leaf" and "flip the status of all vertices on a path". One of the structures that allow this is the Link/Cut Tree, but we can use the fact that the whole tree is given in advance to build a Heavy-Light Decomposition on it, which is much easier to code. Operations on segments of paths can be done with a lazy segment tree, and each vertex then will be added in O(log2n).

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

typedef pair<long long, int> val;

#define x first 
#define y second

const int N = 200043;

val operator +(const val& a, const val& b)
{
    return make_pair(a.x + b.x, a.y + b.y);
}

val operator -(const val& a, const val& b)
{
    return make_pair(a.x - b.x, a.y - b.y);
}

val T[4 * N];
val Tfull[4 * N];
int f[4 * N];

val getVal(int v)
{
    if(f[v] == 1)
        return Tfull[v] - T[v];
    return T[v];
}

void push(int v)
{
    if(f[v] == 1)
    {
        f[v] = 0;
        T[v] = Tfull[v] - T[v];
        f[v * 2 + 1] ^= 1;
        f[v * 2 + 2] ^= 1;
    }   
}                

void upd(int v)
{
    Tfull[v] = Tfull[v * 2 + 1] + Tfull[v * 2 + 2];
    T[v] = getVal(v * 2 + 1) + getVal(v * 2 + 2);
}

void setVal(int v, int l, int r, int pos, val cur)
{                                                           
    if(l == r - 1)
    {
        f[v] = 0;
        Tfull[v] = cur;
        T[v] = cur;
    }
    else
    {
        push(v);
        int m = (l + r) / 2;
        if(pos < m)
            setVal(v * 2 + 1, l, m, pos, cur);
        else
            setVal(v * 2 + 2, m, r, pos, cur);
        upd(v);
    }
}

void flipColor(int v, int l, int r, int L, int R)
{
    if(L >= R) return;
    if(l == L && r == R)
        f[v] ^= 1;
    else
    {
        push(v);
        int m = (l + r) / 2;
        flipColor(v * 2 + 1, l, m, L, min(m, R));
        flipColor(v * 2 + 2, m, r, max(L, m), R);
        upd(v);
    }
}

val getVal(int v, int l, int r, int L, int R)
{
    if(L >= R) return make_pair(0ll, 0);
    if(l == L && r == R) return getVal(v);
    int m = (l + r) / 2;
    val ans = make_pair(0ll, 0);
    push(v);
    ans = ans + getVal(v * 2 + 1, l, m, L, min(R, m));
    ans = ans + getVal(v * 2 + 2, m, r, max(L, m), R);
    upd(v);
    return ans;
}

int n;
vector<int> g[N];

int p[N], siz[N], d[N], nxt[N];
int tin[N], timer;
map<pair<int, int>, int> idx;
long long sum;
int cnt;
int active[N];
int active_cnt;

void dfs_sz(int v) 
{
    if (p[v] != -1) 
    {
        auto it = find(g[v].begin(), g[v].end(), p[v]);
        if (it != g[v].end())
            g[v].erase(it);
    }
    siz[v] = 1;
    for (int &u : g[v]) 
    {
        p[u] = v;
        d[u] = d[v] + 1;
        dfs_sz(u);
        siz[v] += siz[u];
        if (siz[u] > siz[g[v][0]])
            swap(u, g[v][0]);
    }
}

void dfs_hld(int v) 
{
    tin[v] = timer++;
    for (int u : g[v]) 
    {
        nxt[u] = (u == g[v][0] ? nxt[v] : u);
        dfs_hld(u);
    }
}

// [l; r] inclusive
void flipSegment(int l, int r) 
{
    flipColor(0, 0, n, l, r + 1);        
}

// [l; r] inclusive
val get(int l, int r) 
{
    return getVal(0, 0, n, l, r + 1);   
}

void flipPath(int v, int u) 
{
    for (; nxt[v] != nxt[u]; u = p[nxt[u]]) 
    {
        if (d[nxt[v]] > d[nxt[u]]) swap(v, u);
        flipSegment(tin[nxt[u]], tin[u]);
    }
    if (d[v] > d[u]) swap(v, u);
    flipSegment(tin[v], tin[u]);
}

val getPath(int v, int u) 
{
    val res = make_pair(0ll, 0);
    for (; nxt[v] != nxt[u]; u = p[nxt[u]]) 
    {
        if (d[nxt[v]] > d[nxt[u]]) swap(v, u);
        // update res with the result of get()
        res = res + get(tin[nxt[u]], tin[u]);
    }
    if (d[v] > d[u]) swap(v, u);
    res = res + get(tin[v], tin[u]);
    return res;
}

void activate_vertex(int x)
{
    int id = 0;
    if(p[x] != -1)
    {                       
        id = idx[make_pair(x, p[x])];
        val v = getPath(0, p[x]);
        flipPath(0, p[x]);
        sum -= v.x;
        cnt -= v.y;
        v = getPath(0, p[x]);
        sum += v.x;
        cnt += v.y;
    }                   
    cnt++;
    sum += id;
    setVal(0, 0, n, tin[x], make_pair((long long)(id), 1));
    active[x] = 1;
    active_cnt++;   
}          

void init_hld(int root = 0) 
{
    d[root] = 0;
    nxt[root] = root;
    p[root] = -1;
    timer = 0;
    dfs_sz(root);
    dfs_hld(root);
}

int currentSize[N];

int dfsSolution(int x, vector<int>& edges)
{
    if(!active[x]) return 0;
    currentSize[x] = 1;
    for(auto y : g[x])
        if(y != p[x])
            currentSize[x] += dfsSolution(y, edges);
    if(currentSize[x] % 2 == 1)
        edges.push_back(idx[make_pair(x, p[x])]);
    return currentSize[x];   
}

void outputSolution()
{
    vector<int> edges;
    if(cnt * 2 == active_cnt)
    {
        dfsSolution(0, edges);
        sort(edges.begin(), edges.end());
    }
    printf("%d", int(edges.size()));
    for(auto x : edges) printf(" %d", x);
    puts("");
    fflush(stdout);
}

void processQuery(int v)
{
    activate_vertex(v);
    if(cnt * 2 == active_cnt)
        printf("%lldn", sum);
    else
        puts("0");
    fflush(stdout);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
        idx[make_pair(x, y)] = i;
        idx[make_pair(y, x)] = i;
    }   
    
    init_hld();         
    activate_vertex(0); 
    while(true)
    {
        int t;
        scanf("%d", &t);       
        if(t == 3)
            break;
        if(t == 2)
            outputSolution();
        if(t == 1)
        {
            int v;          
            scanf("%d", &v);
            --v;
            processQuery(v);
        } 
    }
}
```
