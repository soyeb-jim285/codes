# Tutorial

[1681A - Game with Cards](../problems/A._Game_with_Cards.md "Educational Codeforces Round 129 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1681A - Game with Cards](../problems/A._Game_with_Cards.md "Educational Codeforces Round 129 (Rated for Div. 2)")

Let the maximum card among all n+m cards be x.

If only one player has a card of value of x, then he/she can win by playing it on the first turn or on the second turn; the opponent won't be able to respond with any of their cards.

Otherwise (if both players have a card with value x), the player who plays this card earlier wins the game. So, in this case, the winner is the player who makes the first turn.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    b = list(map(int, input().split()))
    
    print('Alice' if max(a) >= max(b) else 'Bob')
    print('Alice' if max(a) > max(b) else 'Bob')
```
[1681B - Card Trick](../problems/B._Card_Trick.md "Educational Codeforces Round 129 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1681B - Card Trick](../problems/B._Card_Trick.md "Educational Codeforces Round 129 (Rated for Div. 2)")

The easiest way to solve to problem is probably to see the resemblense of a shuffle operation to an std::rotate function. So you can obtain the final deck by applying cyclic shifts of the deck by b1, then b2 and so on.

Since the shifts are cyclic, it doesn't matter if you shift by x or by x+n or by x+k⋅x for any non-negative k. The result will be the same. Thus, you can calculate the sum of rotations you apply, and subtract n, until it becomes less than n. That is taking it modulo n.

Finally, after rotating a sequence by some x, the x-th element of it (0-indexed) becomes the first one. Thus, you just want to print the (summodn)-th element of a.

Overall complexity: O(n+m) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	m = int(input())
	print(a[sum(map(int, input().split())) % n])
```
[1681C - Double Sort](../problems/C._Double_Sort.md "Educational Codeforces Round 129 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1681C - Double Sort](../problems/C._Double_Sort.md "Educational Codeforces Round 129 (Rated for Div. 2)")

Imagine that all elements of a are distinct. This way, sorting a in increasing order will fix the order of b.

If b turns out sorted in a non-decreasing order, then the answer exists. Otherwise, it doesn't. To obtain the sequence of swaps, you can sort a with any comparison-based sorting algorithm you want: even bubble sort will not exceed the allowed number of swaps.

What changes if a has repeated elements? Distinct elements are still ordered among themselves, but now there are also blocks of equal elements. For each block, look into the corresponding values in b. Obviously, these have to be sorted in a non-decreasing order. Rearrange them as they should be.

In fact, this is exactly the same as sorting the sequence of pairs (ai,bi) with a default comparator — first by ai, then by bi.

Since we fixed the wanted order, we can proceed with the same steps we made in a distinct case.

Overall complexity: O(nlogn) or O(n2) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	tmp = [i for i in range(n)]
	tmp.sort(key=lambda i: [a[i], b[i]])
	for i in range(n - 1):
		if a[tmp[i]] > a[tmp[i + 1]] or b[tmp[i]] > b[tmp[i + 1]]:
			print("-1")
			break
	else:
		ans = []
		for i in range(n - 1):
			for j in range(n - 1):
				if a[j] > a[j + 1] or b[j] > b[j + 1]:
					a[j], a[j + 1] = a[j + 1], a[j]
					b[j], b[j + 1] = b[j + 1], b[j]
					ans.append([j + 1, j + 2])
		print(len(ans))
		for it in ans:
			print(*it)
```
[1681D - Required Length](../problems/D._Required_Length.md "Educational Codeforces Round 129 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1681D - Required Length](../problems/D._Required_Length.md "Educational Codeforces Round 129 (Rated for Div. 2)")

One of the possible approaches to this problem is to try multiplying x only by the largest digit in it. Unfortunately, this doesn't work quite well, since it gives WA on one of the examples. That example is too big to consider, but a smaller version of it can prove that this is an incorrect solution: let n=5, x=403. If we multiply 403 by 4, we get 1612, and there's no way to obtain a number with 5 digits using the next action. But, if we multiply 403 by 3, we get 1209, which can then be multiplied by 9 to obtain a 5-digit number. So, considering only the largest digit is not enough.

This implies that we somehow need to consider the options that are not optimal locally, but optimal globally (i. e. choose a lower digit right now to obtain a higher digit in the future). 

Let's try to estimate the number of possible integers that can be obtained using these operations to see if we can consider all possible options. The key observation is that each integer we obtain will have the form x⋅2a⋅3b⋅5c⋅7d, since only one-digit primes can be added to the factorization. Since we consider only numbers less than 1019, a is not greater than 63, b is not greater than 39, c is not greater than 27, and d is not greater than 22, and the number of reachable integers is about 1.5 million (note that this is a very generous bound since not all combinations of (a,b,c,d) yield an integer less than 1019, and not all such integers can be reached with the operations).

This allows us to use BFS or dynamic programming to calculate the answer.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{   
    int n;
    cin >> n;
    long long v;
    cin >> v;
    queue<long long> q;
    map<long long, int> dist;
    dist[v] = 0;
    q.push(v);
    while(!q.empty())
    {
        long long k = q.front();
        q.pop();
        string s = to_string(k);
        if(s.size() == n)
        {
            cout << dist[k] << endl;
            return 0;
        }
        for(auto x : s)
        {
            if(x == '0') continue;
            long long w = k * int(x - '0');
            if(!dist.count(w))
            {
                dist[w] = dist[k] + 1;
                q.push(w);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
```
[1681E - Labyrinth Adventures](../problems/E._Labyrinth_Adventures.md "Educational Codeforces Round 129 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1681E - Labyrinth Adventures](../problems/E._Labyrinth_Adventures.md "Educational Codeforces Round 129 (Rated for Div. 2)")

WLOG, assume all queries ask to move from a lower layer to a higher layer. The first thing to notice in the problem is that it is always optimal to never go down a layer. 

You have an optimal path that is going down some layers, and then returning to the same layer. So it leaves a layer in some its cell and returns to it in some other cell (or the same one). The best distance it can achieve is the Manhattan distance between these two cells. However, we can also achieve the Manhattan distance by just going along this layer, and the answer will be at least as optimal.

If the query asks about the cells of the same layer, just answer with the Manhattan distance. Otherwise, we can describe the path as follows: go from the first cell to some door on its layer, enter the door and go to another door on the next layer, so on until the layer of the second cell, where you go from a door to the second cell.

Thus, we could potentially write dpi,j — the shortest distance from the start to the j-th door of the i-th layer. Initialize both doors of the first layer, take the best answer from the both doors of the last layer. That would be O(n) per query, which is too slow.

Let's optimize it with some precalculations. In particular, we want to know the shortest distance between one door of some layer and one door of another layer.

We can use the technique similar to binary lifting. Calculate the distance between a pair of doors on layers which are 2x apart for all x up to logn. Let dpi,x,d1,d2 be the distance from door d1 of layer i to door d2 of layer i+2x. dpi,0,d1,d2 can be initialized straightforwardly. Then, to calculate dpi,x,d1,d2, we can use the values for x−1: dpi,x−1,d1,t and dpi+2x−1,x−1,t,d2 for some intermediate door t on layer i+2x−1.

To obtain the answer, use O(logn) jumps to reach the layer one before the last one. Then iterate over the last door.

Alternatively, you could pack this dynamic programming into a segment tree, use divide and conquer on queries or do square root decomposition.

Overall complexity: O((n+m)logn).

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const long long INF64 = 1e18;

typedef pair<int, int> pt;
#define x first
#define y second

int main() {
	int n;
	scanf("%d", &n);
	vector<vector<pt>> d(n - 1, vector<pt>(2));
	forn(i, n - 1) forn(j, 2){
		scanf("%d%d", &d[i][j].x, &d[i][j].y);
		--d[i][j].x, --d[i][j].y;
	}
	int lg = 1;
	while ((1 << lg) < n - 1) ++lg;
	vector<vector<vector<vector<long long>>>> dp(n - 2, vector<vector<vector<long long>>>(lg, vector<vector<long long>>(2, vector<long long>(2, INF64))));
	forn(i, n - 2) forn(k, 2){
		dp[i][0][0][k] = abs(d[i][0].x + 1 - d[i + 1][k].x) + abs(d[i][0].y - d[i + 1][k].y) + 1;
		dp[i][0][1][k] = abs(d[i][1].x - d[i + 1][k].x) + abs(d[i][1].y + 1 - d[i + 1][k].y) + 1;
	}
	for (int l = 1; l < lg; ++l) forn(i, n - 2) forn(j, 2) forn(k, 2) forn(t, 2) if (i + (1 << (l - 1)) < n - 2){
		dp[i][l][j][k] = min(dp[i][l][j][k], dp[i][l - 1][j][t] + dp[i + (1 << (l - 1))][l - 1][t][k]);
	}
	int m;
	scanf("%d", &m);
	forn(_, m){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		--x1, --y1, --x2, --y2;
		int l1 = max(x1, y1), l2 = max(x2, y2);
		if (l1 > l2){
			swap(l1, l2);
			swap(x1, x2);
			swap(y1, y2);
		}
		if (l1 == l2){
			printf("%dn", abs(x1 - x2) + abs(y1 - y2));
			continue;
		}
		vector<long long> ndp(2);
		ndp[0] = abs(x1 - d[l1][0].x) + abs(y1 - d[l1][0].y);
		ndp[1] = abs(x1 - d[l1][1].x) + abs(y1 - d[l1][1].y);
		for (int i = lg - 1; i >= 0; --i) if (l1 + (1 << i) < l2){
			vector<long long> tmp(2, INF64);
			forn(j, 2) forn(k, 2)
				tmp[k] = min(tmp[k], ndp[j] + dp[l1][i][j][k]);
			ndp = tmp;
			l1 += (1 << i);
		}
		long long ans = INF64;
		ans = min(ans, ndp[0] + abs(d[l1][0].x + 1 - x2) + abs(d[l1][0].y - y2) + 1);
		ans = min(ans, ndp[1] + abs(d[l1][1].x - x2) + abs(d[l1][1].y + 1 - y2) + 1);
		printf("%lldn", ans);
	}
	return 0;
}
```
[1681F - Unique Occurrences](../problems/F._Unique_Occurrences.md "Educational Codeforces Round 129 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1681F - Unique Occurrences](../problems/F._Unique_Occurrences.md "Educational Codeforces Round 129 (Rated for Div. 2)")

Let's use contribution to the sum technique to simplify the problem. Instead of counting the number of colors that occure only once for each path, let's, for each color, count the number of paths that contain this color exactly once. Now we can solve the problem independently for each color, and sum up the answers.

The first intended solution was the following. So we want to calculate the answer for some color c. Mark all edges of color c as good, the rest are bad. Then we can calculate dpv,i — the number of paths up to vertex v such that they contain either 0 or 1 good edges. The transitions should be pretty easy, and the answer should be updated when you consider gluing up paths from different children in each vertex. Obviously, this is O(n) per color, so O(n2) overall.

However, we can only calculate this dynamic programming as easily on a virtual tree of vertices adjacent to all good edges. How to calculate the dp for some vertex v? First, push the paths from all virtual children to v. That was enough in the dp for the entire tree but now there are also removed vertices that could also have paths starting in them. All these paths contain 0 good edges (otherwise, they would have had virtual vertices on them). Their amount is the following: the size of the real subtree of v minus the sizes of real subtrees of all its virtual children. The rest is exactly the same as in the dp on the real tree.

A little fun trick. Usually, you want to add lca of adjacent vertices to the virtual tree. But that's actually not needed here: you can just add the root of the tree and link the vertices without a parent to them. That won't change the result of the dp.

That solution works in O(nlogn) or O(n).

The second intended solution is slower complexity-wise but not time-wise. In the first solution we wanted to leave only the good edges in the tree. Here, we want to remove only them. Consider the resulting connected components. What's the number of paths that contain only one of the good edges? It's actually the product of sizes of the connected components this edge connects.

So we want to remove edges, add edges and maintain the sizes of the connected components of the tree. That's basically the same problem as dynamic connectivity. The O(nlog2n) implementation works well enough.

 **Solution 1 (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct edge{
	int u, w;
};

int n;
vector<vector<edge>> g;
vector<vector<int>> ng;
vector<int> tin, tout, siz, ord;
int T;

vector<int> pw;

void init(int v, int p = -1){
	tin[v] = T++;
	ord.push_back(v);
	siz[v] = 1;
	for (const auto &it : g[v]){
		int u = it.u, w = it.w;
		if (u == p) continue;
		pw[u] = w;
		init(u, v);
		siz[v] += siz[u];
	}
	tout[v] = T;
}

int isp(int v, int u){
	return tin[v] <= tin[u] && tout[v] >= tout[u];
}

vector<int> nsiz;
vector<vector<int>> dp;

long long dfs(int v, int x){
	long long res = 0;
	for (int u : ng[v])
		res += dfs(u, x);
	dp[v][0] = siz[v];
	dp[v][1] = 0;
	for (int u : ng[v]) dp[v][0] -= siz[u];
	for (int u : ng[v]){
		if (pw[u] == x){
			res += dp[u][0] * 1ll * dp[v][0];
			dp[v][1] += dp[u][0];
		}
		else{
			res += dp[u][0] * 1ll * dp[v][1];
			res += dp[u][1] * 1ll * dp[v][0];
			dp[v][0] += dp[u][0];
			dp[v][1] += dp[u][1];
		}
	}
	return res;
}

int main() {
	scanf("%d", &n);
	
	g.resize(n);
	forn(i, n - 1){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		--v, --u, --w;
		g[v].push_back({u, w});
		g[u].push_back({v, w});
	}
	
	T = 0;
	tin.resize(n);
	tout.resize(n);
	siz.resize(n);
	pw.resize(n, -1);
	init(0);
	
	vector<vector<int>> sv(n, vector<int>(1, 0));
	for (int v : ord) for (auto it : g[v])
		sv[it.w].push_back(v);
	
	ng.resize(n);
	nsiz.resize(n);
	dp.resize(n, vector<int>(2));
	long long ans = 0;
	forn(i, n) if (!sv[i].empty()){
		sv[i].resize(unique(sv[i].begin(), sv[i].end()) - sv[i].begin());
		vector<int> st;
		for (int v : sv[i]){
			while (!st.empty() && !isp(st.back(), v))
				st.pop_back();
			if (!st.empty())
				ng[st.back()].push_back(v);
			st.push_back(v);
		}
		ans += dfs(0, i);
		
		for (int v : sv[i]) ng[v].clear();
	}
	
	printf("%lldn", ans);
	return 0;
}
```
 **Solution 2 (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct edge{
	int v, u, w;
};

vector<vector<edge>> t;

void add(int v, int l, int r, int L, int R, const edge &e){
	if (L >= R)
		return;
	if (l == L && r == R){
		t[v].push_back(e);
		return;
	}
	int m = (l + r) / 2;
	add(v * 2, l, m, L, min(m, R), e);
	add(v * 2 + 1, m, r, max(m, L), R, e);
}

vector<int> rk, p;
vector<int*> where;
vector<int> val;

int getp(int a){
	return a == p[a] ? a : getp(p[a]);
}

void unite(int a, int b){
	a = getp(a), b = getp(b);
	if (a == b) return;
	if (rk[a] < rk[b]) swap(a, b);
	where.push_back(&rk[a]);
	val.push_back(rk[a]);
	rk[a] += rk[b];
	where.push_back(&p[b]);
	val.push_back(p[b]);
	p[b] = a;
}

void rollback(){
	*where.back() = val.back();
	where.pop_back();
	val.pop_back();
}

long long trav(int v, int l, int r){
	int sv = where.size();
	for (auto it : t[v]) if (it.w == 0)
		unite(it.v, it.u);
	long long res = 0;
	if (l == r - 1){
		for (auto it : t[v]) if (it.w == 1)
			res += rk[getp(it.v)] * 1ll * rk[getp(it.u)];
	}
	else{
		int m = (l + r) / 2;
		res += trav(v * 2, l, m);
		res += trav(v * 2 + 1, m, r);
	}
	while (int(where.size()) > sv) rollback();
	return res;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<edge> e(n - 1);
	forn(i, n - 1){
		scanf("%d%d%d", &e[i].v, &e[i].u, &e[i].w);
		--e[i].v, --e[i].u, --e[i].w;
	}
	sort(e.begin(), e.end(), [](const edge &a, const edge &b){
		return a.w < b.w;
	});
	t.resize(4 * n);
	forn(i, n - 1){
		int pos = lower_bound(e.begin(), e.end(), e[i], [](const edge &a, const edge &b){
			return a.w < b.w;
		}) - e.begin();
		add(1, 0, n, 0, pos, {e[i].v, e[i].u, 0});
		add(1, 0, n, pos, pos + 1, {e[i].v, e[i].u, 1});
		add(1, 0, n, pos + 1, n, {e[i].v, e[i].u, 0});
	}
	rk.resize(n, 1);
	p.resize(n);
	iota(p.begin(), p.end(), 0);
	printf("%lldn", trav(1, 0, n));
	return 0;
}
```
