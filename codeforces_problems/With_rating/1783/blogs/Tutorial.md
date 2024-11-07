# Tutorial

[1783A - Make it Beautiful](../problems/A._Make_it_Beautiful.md "Educational Codeforces Round 141 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1783A - Make it Beautiful](../problems/A._Make_it_Beautiful.md "Educational Codeforces Round 141 (Rated for Div. 2)")

If we put the maximum in the array on the first position, then for every element, starting from the third one, the sum of elements before it will be greater than it (since that sum is greater than the maximum value in the array). So, the only element that can make our array ugly is the second element. We need to make sure that it is not equal to the first element.

Let's put the maximum element on the first position, the minimum element on the second position, and then fill the rest of the array arbitrarily. The only case when it fails is when the maximum element is equal to the minimum element — and it's easy to see that if the maximum is equal to the minimum, then the first element of the array will be equal to the second element no matter what, and the array cannot become beautiful.

So, the solution is to check if the maximum is different from the minimum, and if it is so, put them on the first two positions, and the order of remaining elements does not matter. Note that the given array is sorted, so the minimum is the first element, the maximum is the last element.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if a[0] == a[n - 1]:
        print('NO')
    else:
        print('YES')
        print(a[n - 1], end = ' ')
        print(*(a[0:n-1]))
```
[1783B - Matrix of Differences](../problems/B._Matrix_of_Differences.md "Educational Codeforces Round 141 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1783B - Matrix of Differences](../problems/B._Matrix_of_Differences.md "Educational Codeforces Round 141 (Rated for Div. 2)")

The first step is to notice that beauty doesn't exceed n2−1, because the minimum difference between two elements is at least 1, and the maximum difference does not exceed n2−1 (the difference between the maximum element n2 and the minimum element 1).

At first, finding a matrix with maximum beauty seems to be a quite difficult task. So let's try to find an array of n2 elements of maximum beauty. In this case, it is not difficult to come up with an array of the form [n2,1,n2−1,2,n2−2,3,…]. In such an array, there are all possible differences from 1 to n2−1. So we found an array with the maximum possible beauty.

It remains to find a way to "convert" the array to the matrix, i.e. to find such a sequence of matrix cells that each two adjacent cells in it are side-adjacent. One of the ways is the following: traverse the first row of the matrix from left to right, go down to the second row, traverse it from right to left, go down to the third row, traverse it from left to right, and so on.

Thus, we constructed a matrix with the maximum possible beauty n2−1.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int l = 1, r = n * n, t = 0;
    forn(i, n) {
      forn(j, n) {
        if (t) a[i][j] = l++;
        else a[i][j] = r--;
        t ^= 1;
      }
      if (i & 1) reverse(a[i].begin(), a[i].end());
    }
    forn(i, n) forn(j, n) cout << a[i][j] << " n"[j == n - 1];
  }
}
```
[1783C - Yet Another Tournament](../problems/C._Yet_Another_Tournament.md "Educational Codeforces Round 141 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1783C - Yet Another Tournament](../problems/C._Yet_Another_Tournament.md "Educational Codeforces Round 141 (Rated for Div. 2)")

Suppose, at the end, you won x matches, what can be your final place? Look at each opponent i with i<x (0-indexed). Since the i-th opponent (0-indexed) won i games against the other opponents, even if they win against you, they'll gain i+1≤x wins in total and can't affect your place (since your place is decided by only opponents who won strictly more matches than you).

From the other side, let's look at each opponent i with i>x (0-indexed). Even if they lose to you, they still have i>x wins (you have only x), so all of them have strictly more wins than you. 

As a result, there is only one opponent i=x, whose match against you can affect your final place: if you won against them, your place will be n−x, otherwise your place will be n−x+1.

Now, let's compare your possible places if you win x games with places for winning only x−1 games: x wins gives you places n−x or n−x+1, while winning x−1 leads you to places n−x+1 or n−x+2 that objectively worse.

In other words, it's always optimal to win as many matches as possible.

How to win the most number of games? It's to choose the easiest opponents. Let's sort array a and find the maximum prefix [0,x) with a0+a1+⋯+ax−1≤m. So, we found maximum number of games x we can win. The last is to check: can we get place n−x, or only n−x+1.

If ax contains among x smallest values, then we'll take place n−x. Otherwise, let's try to "insert" ax in this set, i. e. let's erase the biggest among them and insert ax. If the sum is still lower or equal to m, it's success and we get place n−x. Otherwise, our place is n−x+1.

The total complexity is O(nlogn) because of sorting.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    auto b = a;
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n && b[i] <= m; ++i) {
      m -= b[i];
      ++ans;
    }
    if (ans != 0 && ans != n && m + b[ans - 1] >= a[ans]) ++ans;
    cout << n + 1 - ans << 'n';
  }
}
```
[1783D - Different Arrays](../problems/D._Different_Arrays.md "Educational Codeforces Round 141 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1783D - Different Arrays](../problems/D._Different_Arrays.md "Educational Codeforces Round 141 (Rated for Div. 2)")

One of the key observations to this problem is that, after the first i operations, the first i elements of the array are fixed and cannot be changed afterwards. Also, after the i-th operation, the elements on positions from i+3 to n are the same as they were before applying the operations.

This allows us to write the following dynamic programming: dpi,x,y — the number of different prefixes our array can have, if we have performed i operations, the (i+1)-th element is x, and the (i+2)-th element is y. The elements after i+2 are the same as in the original array, and the elements before i+1 won't be changed anymore, so we are interested only in these two elements.

Let's analyze the transitions in this dynamic programming. We apply the operation i+1 to the elements ai+1, ai+2 and ai+3. If we add ai+2 to ai+1, then we subtract it from ai+3, so we transition into state dpi+1,y,ai+3−y. Otherwise, we transition into state dpi+1,y,ai+3+y. The element we leave behind is either x−y or x+y, and if y≠0, these two transitions give us different prefixes. But if y=0, we need to make only one of these transitions, because adding or subtracting 0 actually makes no difference.

Okay, now we've got a solution with dynamic programming in O(n3A2), where n is up to 300 and A is up to 300. This is too slow. But we can notice that the value of ai+1 actually does not affect our transitions at all; we can just discard it, so our dynamic programming becomes O(n2A), which easily fits into TL.

Small implementation note: elements can become negative, and in order to store dynamic programming with negative states in an array, we need to do something about that. I don't recommend using maps (neither ordered nor unordered): you either get an extra log factor, or make your solution susceptible to hacking. Instead, let's say that the value of dpi,y, where y can be a negative number, will be stored as dp[i][y+M] in the array, where M is some constant which is greater than the maximum possible |y| (for example, 105 in this problem). That way, all array indices will be non-negative.

Solution complexity: O(n2A).

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

const int ZERO = 100000;

int dp[2][ZERO * 2];

void recalc(int x)
{
    for(int i = 0; i < ZERO * 2; i++)
        dp[1][i] = 0;

    for(int i = 0; i < ZERO * 2; i++)
    {
        if(dp[0][i] == 0) continue;
        int nx = x + i;
        dp[1][nx] = add(dp[1][nx], dp[0][i]);
        if(nx != ZERO)
            dp[1][2 * ZERO - nx] = add(dp[1][2 * ZERO - nx], dp[0][i]);
    }

    for(int i = 0; i < ZERO * 2; i++)
        dp[0][i] = dp[1][i];
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    dp[0][ZERO] = 1;
    for(int i = 1; i + 1 < n; i++)
        recalc(a[i]);
    int ans = 0;
    for(int i = 0; i < ZERO * 2; i++)
        ans = add(ans, dp[0][i]);
    cout << ans << endl;
}
```
[1783E - Game of the Year](../problems/E._Game_of_the_Year.md "Educational Codeforces Round 141 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1783E - Game of the Year](../problems/E._Game_of_the_Year.md "Educational Codeforces Round 141 (Rated for Div. 2)")

Consider some value of k. When is it included in the answer? When Monocarp spends a lower or an equal amount of "blocks" of attempts than Polycarp for killing every boss.

Formally, ⌈aik⌉≤⌈bik⌉ for all i from 1 to n.

Let's reverse this condition. k is not in the answer if there exists such i from 1 to n that ⌈bik⌉<⌈aik⌉. So, there exists at least one value between ⌈bik⌉ and ⌈aik⌉. Let's call it x. Now it's ⌈bik⌉<x≤⌈aik⌉. I set the ≤ and < signs arbitrarily, just so that it shows that such a value exists. You can't put both ≤ or both <, because that will accept 0 values or at least 2 values, respectively.

Would be cool if we could multiply everything by k and it still worked. Is it completely impossible, though? Take a look at bi<xk≤ai. What it says is that there exists a multiple of k between bi and ai. A multiple of k is a number that's the last in each "block" of attempts (the block of value that are rounded up the same). Turns out, this is what we are looking for already. Right after the multiple of k, the new block starts. Thus, we are wrong we our signs. It should be bi≤xk<ai — ai is in the block after bi, so it requires more blocks of attempts.

So for k to not be included in the answer, there should exist at least one i such that there exists a multiple of k in the half-interval [bi;ai).

That is pretty easy to implement. For each x, calculate the number of half-intervals that cover x. I think this is called delta-encoding. Iterate over all half-intervals and make two updates for each one: increment by 1 on position bi and decrement by 1 on position ai. Then make a prefix sum over these updates. Now the value in the x-th position tells you the number of half-intervals that cover x.

To check a particular value of k, iterate over all multiples of k and check that none are covered by half-intervals. It's known that the total number of multiples over all numbers from 1 to n is n+n2+n3+⋯+nn=O(nlogn).

Overall complexity: O(nlogn) per testcase.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;


int main() {
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		vector<int> a(n), b(n);
		forn(i, n) scanf("%d", &a[i]);
		forn(i, n) scanf("%d", &b[i]);
		vector<int> dx(n + 1);
		forn(i, n) if (b[i] < a[i]){
			++dx[b[i]];
			--dx[a[i]];
		}
		forn(i, n) dx[i + 1] += dx[i];
		vector<int> ans;
		for (int k = 1; k <= n; ++k){
			bool ok = true;
			for (int nk = k; nk <= n; nk += k)
				ok &= dx[nk] == 0;
			if (ok)
				ans.push_back(k);
		}
		printf("%dn", int(ans.size()));
		for (int k : ans) printf("%d ", k);
		puts("");
	}
	return 0;
}
```
[1783F - Double Sort II](../problems/F._Double_Sort_II.md "Educational Codeforces Round 141 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1783F - Double Sort II](../problems/F._Double_Sort_II.md "Educational Codeforces Round 141 (Rated for Div. 2)")

The solution to this problem uses cyclic decomposition of permutations. A cyclic decomposition of a permutation is formulated as follows: you treat a permutation as a directed graph on n vertices, where each vertex i has an outgoing arc i→pi. This graph consists of several cycles, and the properties of this graph can be helpful when solving permutation-based problems.

First of all, how does the cyclic decomposition of a sorted permutation look? Every vertex belongs to its own cycle formed by a self-loop going from that vertex to itself. We will try to bring the cyclic decompositions of the given permutations to this form.

What does an operation with integer i do to the cyclic decomposition of the permutation? If i is in its own separate cycle, the operation does nothing (pi=i, so we swap an element with itself). 

Otherwise, let's suppose that x is the element before i in the same cycle (px=i), and y is the element after i in the same cycle (pi=y). Note that this can be the same element. When we apply an operation on i, we swap px with pi, so after the operation, pi=i, and px=y. So, i leaves the cycle and forms its separate cycle, and y becomes the next vertex in the cycle after x. So, using the operation, we exclude the vertex i from the cycle.

Suppose we want to sort one permutation. Then each cycle having length ≥2 must be broken down: for a cycle of length c, we need to exclude c−1 vertices from it to break it down. The vertex we don't touch can be any vertex from the cycle, and all other vertices from the cycle will be extracted using one operation directed at them. It's easy to see now that if we want to sort a permutation, we don't need to apply the same operation twice, and the order of operations does not matter.

Okay, then what about sorting two permutations in parallel? Let's change the problem a bit: instead of calculating the minimum number of operations, we will try to maximize the number of integers i such that we don't perform operations with them. So, an integer i can be left untouched if it is the only untouched vertex in its cycles in both permutations... Can you see where this is going?

Suppose we want to leave the vertex i untouched. It means that in its cycles in both permutations, every other vertex has to be extracted with an operation. So, if two cycles from different permutations have a vertex in common, we can leave this vertex untouched, as long as there are no other vertices left untouched in both of these cycles. Let's build a bipartite graph, where each vertex in the left part represents a cycle in the first permutation, and each vertex in the right part represents a cycle in the second permutation. We will treat each integer i as an edge between two respective vertices in the bipartite graph. If the edge corresponding to i is "used" (i is left untouched), we cannot "use" any edges incident to the same vertex in left or right part. So, maximizing the number of untouched numbers is actually the same as finding the maximum matching in this bipartite graph.

After you find the maximum matching, restoring the actual answer is easy. Remember that the edges saturated by the matching correspond to the integers we don't touch with our operations, the order of operations does not matter, and each integer has to be used in an operation only once. So, the actual answer is the set of all integers without those which correspond to the edges from the matching.

This solution runs in O(n2) even with a straightforward implementation of bipartite matching, since the bipartite graph has at most O(n) vertices and O(n) edges.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 5043;

vector<int> g[N];
int mt[N];
int u[N];
vector<vector<int>> cycle[2];
vector<int> a[2];
int n;
int vs[2];
vector<vector<int>> inter;

bool kuhn(int x)
{
    if(u[x]) return false;
    u[x] = true;
    for(auto y : g[x])
    {
        if(mt[y] == x) continue;
        if(mt[y] == -1 || kuhn(mt[y]))
        {
            mt[y] = x;
            return true;
        }
    }
    return false;
}

int find_intersection(const vector<int>& x, const vector<int>& y)
{
    for(auto i : x)
        for(auto j : y)
            if(i == j)
                return i;
    return -1;
}

int main()
{
    scanf("%d", &n);
    for(int k = 0; k < 2; k++)
    {
        a[k].resize(n);
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[k][j]);
            a[k][j]--;
        }    
    }

    for(int k = 0; k < 2; k++)
    {
        vector<bool> used(n);
        for(int i = 0; i < n; i++)
        {
            if(used[i]) continue;
            vector<int> cur;
            int j = i;
            while(!used[j])
            {
                cur.push_back(j);
                used[j] = true;
                j = a[k][j];            
            }
            cycle[k].push_back(cur);
        }
        vs[k] = cycle[k].size();
    }

    inter.resize(vs[0], vector<int>(vs[1]));

    for(int i = 0; i < vs[0]; i++)
        for(int j = 0; j < vs[1]; j++)
        {
            inter[i][j] = find_intersection(cycle[0][i], cycle[1][j]);
            if(inter[i][j] != -1)
                g[i].push_back(j);
        }

    for(int i = 0; i < vs[1]; i++)
        mt[i] = -1;
    for(int i = 0; i < vs[0]; i++)
    {
        for(int j = 0; j < vs[0]; j++)
            u[j] = false;
        kuhn(i);
    }
    
    set<int> res;
    for(int i = 0; i < n; i++) res.insert(i);
    for(int i = 0; i < vs[1]; i++)
        if(mt[i] != -1)
            res.erase(inter[mt[i]][i]);

    printf("%dn", res.size());
    for(auto x : res) printf("%d ", x + 1);
    puts("");
}
```
[1783G - Weighed Tree Radius](../problems/G._Weighed_Tree_Radius.md "Educational Codeforces Round 141 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1783G - Weighed Tree Radius](../problems/G._Weighed_Tree_Radius.md "Educational Codeforces Round 141 (Rated for Div. 2)")

Firstly, let's define the weight of path (u,v) as wp(u,v)=au+du(v)+av. On contrary to weighted distances, wp(u,v)=wp(v,u) and also wp(v,v)=2av.

Now, let's define the diameter of a tree as path (u,v) with maximum wp(u,v). It's okay if diameter may be explicit case (v,v). The useful part of such definition is next: our diameter still holds most properties of the usual diameter. Let's look at two of them: 

* There is a vertex on diameter path (x,y) with wv(x)=⌈wp(x,y)2⌉ and wv(y)=wp(x,y)−wv(x). It's easy to prove after noting the fact that ax≤dx(y)+ay and ay≤dy(x)+ax (otherwise, you could choose diameter (x,x) or (y,y)).
* For any vertex v eccentricity e(v)=max(wv(x),wv(y)). In other words, either x or y has the maximum distance from v. (You can also prove it by contradiction). It also means that e(v)≥⌈wp(x,y)2⌉.

 The two properties above give us an easy way to calculate the radius: just maintain diameter (x,y), and the answer is a half of it.Now let's look how the diameter changes when we change the weight av. If av is increasing it's quite easy. The only paths that change weights are the paths ending at v. Denote such path as (v,u) and note that either v=u or wp(v,u)=av+wv(u)≤av+e(v) = av+max(wv(x),wv(y)). In other words, there will be only three candidates for a new diameter: 

1. path (v,v) with wp(v,v)=2av;
2. path (v,x) with wp(v,x)=av+dv(x)+ax;
3. path (v,y) with wp(v,y)=av+dv(y)+ay.

The only thing you need to calculate fast enough is the two distances dv(x) and dv(y). And since dv(x)=depth(v)+depth(x)−2⋅depth(lca(v,x)), your task is to calculate lca.

Finally, how to handle decreasing av's? Let's get rid of them using DCP (dynamic connectivity problem) technique. Keep track of each value av: each possible value av for some vertex v will be "active" on some segment of queries [l,r)∈[0,m). Since there are only m queries, there will be exactly n+m such segments for all vertices v in total.

Now, all queries becomes "assign av=x on some segment of queries [l,r)". Note that in that case, the previous value of av was 0, so you are dealing with only "increasing value" queries.

Finally, to handle all range queries efficiently, you build a Segment Tree on queries, set all queries and then traverse your Segment Tree while maintaining the current diameter in order to calculate answers for all queries.

Each of n+m queries transforms in O(logm) queries to segment tree vertices, and preforming each query asks you to calculate lca two times.

If you use the usual binary lifting, then your complexity becomes O((n+m)logmlogn) what is okay. But if you use Sparse Table on Euler tour, you can take lca in O(1) and your complexity will be O(nlogn+(n+m)logm).

 **Solution 1 (adedalic)**
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
	fore(i, 0, sz(v)) {
		if(i) out << " ";
		out << v[i];
	}
	return out;
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

const int LOG = 18;
const int N = int(2e5) + 55;

int n;
vector<int> a;
vector<int> g[N];

inline bool read() {
	if(!(cin >> n))
		return false;
	a.resize(n);
	fore (i, 0, n)
		cin >> a[i];
	fore (i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	return true;
}

int p[LOG][N];
int h[N], tin[N], tout[N], T = 0;

void precalcLca(int v, int pr) {
	tin[v] = T++;
	h[v] = 0;
	if (pr != v)
		h[v] = h[pr] + 1;
	p[0][v] = pr;
	fore (pw, 0, LOG - 1)
		p[pw + 1][v] = p[pw][p[pw][v]];

	for (int to : g[v]) {
		if (to == pr)
			continue;
		precalcLca(to, v);
	}
	tout[v] = T;
}

bool isParent(int l, int v) {
	return tin[l] <= tin[v] && tout[v] <= tout[l];
}

int lca(int u, int v) {
	if (isParent(u, v))
		return u;
	if (isParent(v, u))
		return v;
	
	for (int pw = LOG - 1; pw >= 0; pw--) 
		if (!isParent(p[pw][v], u))
			v = p[pw][v];
	assert(!isParent(v, u));
	assert(isParent(p[0][v], u));
	return p[0][v];
}

int getFarthest(int s) {
	vector<int> used(n, 0);
	queue<int> q;

	used[s] = 1;
	q.push(s);
	int v;
	while (!q.empty()) {
		v = q.front(); 
		q.pop();
		for (int to : g[v]) {
			if (used[to])
				continue;
			used[to] = 1;
			q.push(to);
		}
	}
	return v;
}

int getDist(int u, int v) {
	return h[u] + h[v] - 2 * h[lca(u, v)];
}

const int M = int(2e5);
vector<pt> ops[4 * M];

void setOp(int v, int l, int r, int lf, int rg, const pt &op) {
	if (l >= r || lf >= rg) return;
	if (l == lf && r == rg) {
		ops[v].push_back(op);
		return;
	}
	int mid = (l + r) / 2;
	if (lf < mid)
		setOp(2 * v + 1, l, mid, lf, min(mid, rg), op);
	if (rg > mid)
		setOp(2 * v + 2, mid, r, max(lf, mid), rg, op);
}

void updDiam(int &s, int &t, int &curD, const pt &op) {
	int v = op.x;
	a[v] = op.y;

	int ns = s, nt = t, nD = curD;

	vector<pt> cds = {{s, v}, {v, t}, {v, v}};
	for (auto &c : cds) {
		int d1 = getDist(c.x, c.y);
		if (nD < a[c.x] + d1 + a[c.y]) {
			nD = a[c.x] + d1 + a[c.y];
			ns = c.x, nt = c.y;
		}
	}
	s = ns;
	t = nt;
	curD = nD;
}

vector<int> ans;

void calcDiams(int v, int l, int r, int s, int t, int curD) {
	for (auto &op : ops[v])
		updDiam(s, t, curD, op);
	if (r - l > 1) {
		int mid = (l + r) / 2;
		calcDiams(2 * v + 1, l, mid, s, t, curD);
		calcDiams(2 * v + 2, mid, r, s, t, curD);
	}
	else
		ans[l] = (curD + 1) / 2;
	
	for (auto &op : ops[v])
		a[op.first] = 0;
}

inline void solve() {
	precalcLca(0, 0);
	int s = getFarthest(0);
	int t = getFarthest(s);

	int m;
	cin >> m;
	vector<int> lst(n, 0);
	fore (i, 0, m) {
		int v, x;
		cin >> v >> x;
		v--;

		setOp(0, 0, m, lst[v], i, {v, a[v]});
		lst[v] = i;
		a[v] = x;
	}
	fore (v, 0, n)
		setOp(0, 0, m, lst[v], m, {v, a[v]});

	ans.resize(m, -1);
	a.assign(n, 0);
	calcDiams(0, 0, m, s, t, getDist(s, t));

	fore (i, 0, m)
		cout << ans[i] << 'n';
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
 **Solution 2 (adedalic)**
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
	fore(i, 0, sz(v)) {
		if(i) out << " ";
		out << v[i];
	}
	return out;
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

const int LOG = 18;
const int N = int(2e5) + 55;

int n;
vector<int> a;
vector<int> g[N];

inline bool read() {
	if(!(cin >> n))
		return false;
	a.resize(n);
	fore (i, 0, n)
		cin >> a[i];
	fore (i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	return true;
}

struct Lca {
	vector<int> log2, tin;
	vector< vector<int> > hs;
	int T = 0;

	void dfs(int v, int p, int cdepth) {
		tin[v] = T++;
		hs[0][tin[v]] = cdepth;
		for (int to : g[v]) {
			if (to == p)
				continue;
			dfs(to, v, cdepth + 1);
			hs[0][T++] = cdepth;
		}
	}

	void init() {
		log2.assign(2 * n, 0);
		fore (i, 2, sz(log2))
			log2[i] = log2[i / 2] + 1;
		hs.assign(log2.back() + 1, vector<int>(2 * n, INF));

		tin.assign(n, 0);
		T = 0;

		dfs(0, -1, 0);
		assert(T < 2 * n);

		fore (pw, 0, sz(hs) - 1) {
			fore (i, 0, T - (1 << pw))
				hs[pw + 1][i] = min(hs[pw][i], hs[pw][i + (1 << pw)]);
		}
	}

	int getMin(int u, int v) {
		if (tin[u] > tin[v])
			swap(u, v);
		int len = log2[tin[v] + 1 - tin[u]];
		int d = min(hs[len][tin[u]], hs[len][tin[v] + 1 - (1 << len)]);
//		cerr << u << " " << v << ": " << d << endl;
		return d;
	}
	inline int getH(int v) {
		return hs[0][tin[v]];
	}
} lcaST;

int getFarthest(int s) {
	vector<int> used(n, 0);
	queue<int> q;

	used[s] = 1;
	q.push(s);
	int v;
	while (!q.empty()) {
		v = q.front(); 
		q.pop();
		for (int to : g[v]) {
			if (used[to])
				continue;
			used[to] = 1;
			q.push(to);
		}
	}
	return v;
}

int getDist(int u, int v) {
	return lcaST.getH(u) + lcaST.getH(v) - 2 * lcaST.getMin(u, v);
}

const int M = int(2e5);
vector<pt> ops[4 * M];

void setOp(int v, int l, int r, int lf, int rg, const pt &op) {
	if (l >= r || lf >= rg) return;
	if (l == lf && r == rg) {
		ops[v].push_back(op);
		return;
	}
	int mid = (l + r) / 2;
	if (lf < mid)
		setOp(2 * v + 1, l, mid, lf, min(mid, rg), op);
	if (rg > mid)
		setOp(2 * v + 2, mid, r, max(lf, mid), rg, op);
}

void updDiam(int &s, int &t, int &curD, const pt &op) {
	int v = op.x;
	a[v] = op.y;

	int ns = s, nt = t, nD = curD;

	vector<pt> cds = {{s, v}, {v, t}, {v, v}};
	for (auto &c : cds) {
		int d1 = getDist(c.x, c.y);
		if (nD < a[c.x] + d1 + a[c.y]) {
			nD = a[c.x] + d1 + a[c.y];
			ns = c.x, nt = c.y;
		}
	}
	s = ns;
	t = nt;
	curD = nD;
}

vector<int> ans;

void calcDiams(int v, int l, int r, int s, int t, int curD) {
	for (auto &op : ops[v])
		updDiam(s, t, curD, op);
	if (r - l > 1) {
		int mid = (l + r) / 2;
		calcDiams(2 * v + 1, l, mid, s, t, curD);
		calcDiams(2 * v + 2, mid, r, s, t, curD);
	}
	else
		ans[l] = (curD + 1) / 2;
	
	for (auto &op : ops[v])
		a[op.first] = 0;
}

inline void solve() {
	lcaST.init();
	int s = getFarthest(0);
	int t = getFarthest(s);

	int m;
	cin >> m;
	vector<int> lst(n, 0);
	fore (i, 0, m) {
		int v, x;
		cin >> v >> x;
		v--;

		setOp(0, 0, m, lst[v], i, {v, a[v]});
		lst[v] = i;
		a[v] = x;
	}
	fore (v, 0, n)
		setOp(0, 0, m, lst[v], m, {v, a[v]});

	ans.resize(m, -1);
	a.assign(n, 0);
	calcDiams(0, 0, m, s, t, getDist(s, t));

	fore (i, 0, m)
		cout << ans[i] << 'n';
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
