# Tutorial_2

[1989A - Catch the Coin](../problems/A._Catch_the_Coin.md "Educational Codeforces Round 167 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1989A - Catch the Coin](../problems/A._Catch_the_Coin.md "Educational Codeforces Round 167 (Rated for Div. 2)")

At first glance, it's not very convenient that the move consists of two parts: first the character moves, then the coin. Let's try to combine these steps. Since the coin moves down by 1 each time, we can add this change in the y coordinate to the change in the character's y coordinate. That is, the character can now change its y coordinate not by −1,0, or 1, but by 0,1, or 2. And the coins will always be in their initial positions.

Now it is easy to see that all coins with y≥0 can be picked up. For example, you can first align with the coin in terms of the x coordinate, and then move up to it.

However, in the example, it can be seen that Monocarp can pick up the coin (−2,−1). This happens because the move still consists of two parts. Since the character moves first, and then the coin, we can align with the x coordinate again, and then have the time to move down to it.

Thus, all coins with y≥−1 can be picked up.

Overall complexity: O(n).

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	x, y = map(int, input().split())
	print("YES" if y >= -1 else "NO")
```
[1989B - Substring and Subsequence](../problems/B._Substring_and_Subsequence.md "Educational Codeforces Round 167 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1989B - Substring and Subsequence](../problems/B._Substring_and_Subsequence.md "Educational Codeforces Round 167 (Rated for Div. 2)")

Since the string a is a substring of the answer, the answer can be represented as follows — x+a+y, where + denotes string concatenation, and x and y are some, possibly empty, strings.

Now, we have to ensure that the string x+a+y contains the string b as a subsequence. Notice that to minimize the length of the answer, it is optimal to choose the strings x and y in such a way that x is a prefix of b, and y is a suffix of b. This means that we can represent the string b as x+c+y. Then, in order for the entire string x+c+y to be a subsequence of the answer x+a+y, the string c must be a subsequence of the string a.

Using the above facts, we can solve the problem as follows: iterate over the length of x, iterate over the length of y, and then check that the remaining part c is a subsequence of the string a. If this is the case, update the answer with the value |x|+|a|+|y|.

Unfortunately, this solution is too slow, but it can be easily optimized. Since we need to minimize the length of the answer, it is sufficient to iterate over the length of x, and consequently the position of the start of the string c, and then find the minimum possible length of y. To do this, greedily find how many of the following characters in the string b will be a subsequence of the string a: we can go through the string a from left to right, and if the current character of the string a matches the next character in the string b that we need, increase the number of found characters in the string b by 1. All the remaining characters in the string b will form the string y.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int ans = n + m;
    for (int i = 0; i < m; ++i) {
      int j = i;
      for (auto c : a) {
        if (j < m && c == b[j]) ++j;
      }
      ans = min(ans, n + m - (j - i));
    }
    cout << ans << 'n';
  }
}
```
[1989C - Two Movies](../problems/C._Two_Movies.md "Educational Codeforces Round 167 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1989C - Two Movies](../problems/C._Two_Movies.md "Educational Codeforces Round 167 (Rated for Div. 2)")

Let's notice an important fact: if ai≠bi, it is always optimal to choose a review for the movie with the better rating: taking the worse option doesn't increase the rating of any movie.

Using this fact, let's calculate several values: 

* x — the rating of the first movie among people who liked the first movie more than the second one (ai>bi);
* y — the rating of the second movie among people who liked the second movie more than the first one (bi>ai);
* neg — the number of people who didn't like either movie;
* pos — the number of people who liked both movies.

Now we have to distribute the reviews of the viewers having ai=bi. To do this, we can iterate the contribution of such viewers to the rating of the first movie (denoted as i) from −neg to pos. Then, the final rating of the first movie is x+i, and the final rating of the second movie is y+(pos−neg−i). Among all the options, choose the one where the minimum of these two values is maximized.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int x = 0, y = 0, neg = 0, pos = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] > b[i]) {
        x += a[i];
      } else if (a[i] < b[i]) {
        y += b[i];
      } else {
        neg += (a[i] < 0);
        pos += (a[i] > 0);
      }
    }
    int ans = -1e9;
    for (int i = -neg; i <= pos; ++i)
      ans = max(ans, min(x + i, y + (pos - neg - i)));
    cout << ans << 'n';
  }
}
```
[1989D - Smithing Skill](../problems/D._Smithing_Skill.md "Educational Codeforces Round 167 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1989D - Smithing Skill](../problems/D._Smithing_Skill.md "Educational Codeforces Round 167 (Rated for Div. 2)")

It's quite obvious that we should melt every weapon we forge, and we can do it as soon as we forge it. So, let's do these actions in pairs: forge a weapon, then instantly melt it.

Since you can't use two types of metal while forging one weapon, we can solve our task independently for each metal type. Suppose you have x ingots of the chosen metal.

You can act greedily: you can forge only weapons of classes with ai≤x, but among them, it's optimal to chose one that makes us lose the minimum number of ingots by forging it and melting it; so, we need to minimize the value of ai−bi. However, this greedy solution is too slow when implemented naively.

Let's define A=maxai and look at two cases: x≤A or x>A. If x≤A, let's just precalculate answers ans[x] for all x from 0 to A. To do so, let's precalculate another value best[x] as "the minimum ai−bi among all classes i where ai≤x". In other words, best[x] will be equal to the minimum amount of ingots you'll lose if you have x ingots, and you need to forge-melt one weapon.

We can precalculate best[x] in two steps: 

1. for each class i, we can set best[ai]=min(best[ai],ai−bi);
2. using approach similar to prefix minima or dynamic programming, we can also update best[x]=min(best[x],best[x−1]) for all x from 1 to A.

 Using the array best, we can calculate ans easily with dynamic programming: ans[x]=2+ans[x−best[x]] for all x from 1 to A.In case x>A, we can forge-melt a weapon with minimum ai−bi as many times as we can until x≤A. Once x becomes less or equal to A, we can take the value ans[x] and finish processing that metal type.

Knowing that the minimum ai−bi is just best[A], we can reformulate our first step as finding minimum k such that x−k⋅best[A]≤A or k≥x−Abest[A]. In other words, we'll make the first step exactly k=⌈x−Abest[A]⌉ times. So we can calculate the final answer as 2k+ans[x−k⋅best[A]].

As a result, we run precalculating in O(n+A) time and process each metal type in O(1) time. The total complexity is O(n+m+A) time and space.

 **Solution (adedalic)**
```cpp
fun main() {
    val (n, m) = readln().split(" ").map { it.toInt() }
    val a = readln().split(" ").map { it.toInt() }
    val b = readln().split(" ").map { it.toInt() }
    val c = readln().split(" ").map { it.toInt() }

    val mx = a.maxOrNull()!! + 1

    val best = IntArray(mx) { 1e9.toInt() }
    val calc = IntArray(mx) { 0 }

    for (i in a.indices)
        best[a[i]] = minOf(best[a[i]], a[i] - b[i])
    for (v in 1 until mx)
        best[v] = minOf(best[v], best[v - 1])

    for (v in 1 until mx)
        if (v >= best[v])
            calc[v] = 2 + calc[v - best[v]]

    var ans = 0L
    for (v in c) {
        var cur = v
        if (cur >= mx) {
            val k = (cur - mx + 1 + best[mx - 1]) / best[mx - 1]
            ans += 2L * k
            cur -= k * best[mx - 1]
        }
        ans += calc[cur]
    }
    println(ans)
}
```
[1989E - Distance to Different](../problems/E._Distance_to_Different.md "Educational Codeforces Round 167 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1989E - Distance to Different](../problems/E._Distance_to_Different.md "Educational Codeforces Round 167 (Rated for Div. 2)")

Consider a block of equal elements in a. If we split a into such blocks, we can consider each block separately — for each element, we need only the distance to the closest border of the block (except for the first and the last block, where we consider only one border). It's quite easy to see that if the length of the block is even (let's say it's 2x), then the distances for the elements in this block are [1,2,3,…,x−1,x,x,x−1,…,3,2,1]. And if the length of the block is odd (let's say it's 2x−1), the distances are [1,2,3,…,x−1,x,x−1,…,3,2,1]. Now we don't need the actual values in a, we only need the information about the blocks of equal elements.

We need at least k blocks of equal elements in a, since if the number of blocks is less than k, it's impossible for the array a to have k different values (and if there are at least k blocks, it's possible to assign each block a value so that every integer from 1 to k appears). So, it looks like we need to calculate the number of ways to split the array into at least k blocks.

However, this only works if there is a bijection between the ways to split the array and the resulting arrays b. Unfortunately, some ways to split the array might result in the same distance array: for example, the distance array [1,1,1,1] can be obtained either by splitting into four blocks of size 1, or into three blocks, the middle of which has size 2. So, if there is a block of size 2, and it is not the first or the last block in the split, it can be replaced with two blocks of size 1, and nothing changes (except for the number of blocks, which goes up).

Thankfully, this is the only such situation we need to handle: any block longer than 2 can be uniquely determined by the values in the middle of it (if there is a value x which is greater than both its neighbors, it is the middle of a block of size 2x−1; and if there is a pair of values x which are greater than both the value to the left and the value to the right, it is the middle of a block of size 2x).

So, we need to count the number of ways to split the array of size n into at least k blocks so that only the first and the last block can have size 2. This can be done with the following dynamic programming: let dpi,j be the number of ways to split the first i elements into j blocks.

This looks like it works in O(n3), but we can use two improvements to speed this up:

* the values j>k are treated identically to the values j=k, so we can limit the value of j to k and say that dpi,j is the number of ways to split the first i elements into at least j blocks if j=k;
* we can do transitions in O(1) instead of O(n) by using partial sums.

Combining these two optimizations, we get a solution in O(nk).

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

int mul(int x, int y)
{
 	return (x * 1ll * y) % MOD;
}

int main()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
	dp[0][0] = 1;
	vector<int> sum(k + 1);
	sum[0] = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			int& d = dp[i + 1][min(j + 1, k)];
		 	d = add(d, sum[j]);
		 	if(i >= 2 && i != n - 1)
		 		d = add(d, -dp[i - 1][j]); 
		}
		for(int j = 0; j <= k; j++)
			sum[j] = add(sum[j], dp[i + 1][j]);
	}
	cout << dp[n][k] << endl;
}
```
[1989F - Simultaneous Coloring](../problems/F._Simultaneous_Coloring.md "Educational Codeforces Round 167 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1989F - Simultaneous Coloring](../problems/F._Simultaneous_Coloring.md "Educational Codeforces Round 167 (Rated for Div. 2)")

The main idea is as follows. Consider any constraint on a cell. If the cell must be red, then the last action on this cell must be coloring the row; otherwise, it should be the column. That is, if the operation is applied to both the row and the column of this cell, then there is a certain order of performing these operations. It is also worth noting that it does not make sense to apply the same operation twice, because the second application of the operation will recolor all the cells.

The word "order" should immediately bring to mind thoughts of directed graphs and topological sorting. Let's try to build a graph of operation execution. Create a graph with n+m vertices — one vertex for each row and column. If the cell must be red, then draw a directed edge from its column to its row. Otherwise, draw an edge from its row to its column.

Now we would like to perform operations simply in the order of topological sorting. If this is possible (i.e., there are no cycles in the graph), then the answer is just 0. This means that operations can always be applied one by one. It is also worth noting that we apply the operations that do not color any cells with constraints. Their cost is always 0, so they do not change the answer.

Otherwise, there are some strongly connected components in the graph with size greater than 1. In these components, we will always have to perform some operations at the same time. Of course, operations can be applied to the entire component at once. The cost will then be equal to the square of the component's size. Doesn't sound optimal but that's one way to satisfy the constraints.

Let's show that it is not possible to do it cheaper. Consider the last set of actions on this component. If they do not affect the entire component, then within the affected subset, there will be a vertex with an outgoing edge outside the subset, but inside the component (otherwise it would be two different components). This means that there must be at least one more operation performed on the vertex to which this edge leads. Therefore, the set of actions considered will not be the last one.

Then the solution is as follows. After adding each constraint, add the previously described edges and find the condensation of the graph. The answer will be the sum of the squares of the sizes of strongly connected components with size greater than 1. This solution works in O(q⋅(n+m+q)).

To optimize this solution, you can use the technique of incremental condensation. You can read about it in the [blog](https://codeforces.com/blog/entry/91608) by Radewoosh. Since DSU is used in it, you can maintain the sum of the squares of the component sizes on the fly.

The blog describes a solution with a logarithmic time complexity, but the problem did not require an implementation faster than log2. Solutions with a logarithmic memory complexity with a large constant might not pass (the author's solution consumes O(qlogq) memory and fits into 50 megabytes).

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct edge{
	int v, u;
};

vector<vector<int>> g, tg;
vector<int> ord;
vector<char> used;
vector<int> clr;

void ts(int v){
	used[v] = true;
	for (int u : g[v]) if (!used[u])
		ts(u);
	ord.push_back(v);
}

void dfs(int v, int k){
	clr[v] = k;
	for (int u : tg[v]) if (clr[u] == -1)
		dfs(u, k);
}

vector<long long> rk, p;
long long sum;
vector<long long*> where;
vector<long long> val;

long long cost(int x){
	return x == 1 ? 0ll : x * 1ll * x;
}

int getp(int a){
	return a == p[a] ? a : getp(p[a]);
}

void unite(int a, int b){
	a = getp(a), b = getp(b);
	if (a == b) return;
	if (clr[a] != clr[b]) return;
	if (rk[a] < rk[b]) swap(a, b);
	where.push_back(&sum);
	val.push_back(sum);
	sum -= cost(rk[a]);
	sum -= cost(rk[b]);
	sum += cost(rk[a] + rk[b]);
	where.push_back(&rk[a]);
	val.push_back(rk[a]);
	rk[a] += rk[b];
	where.push_back(&p[b]);
	val.push_back(p[b]);
	p[b] = a;
}

vector<edge> e;
vector<long long> ans;

void calc(int l, int r, const vector<int> &cur){
	if (l == r - 1){
		ans.push_back(sum);
		return;
	}
	int m = (l + r) / 2;
	for (int i : cur) if (i < m){
		int v = getp(e[i].v), u = getp(e[i].u);
		for (int w : {v, u}) if (used[w]){
			g[w].clear();
			tg[w].clear();
			clr[w] = -1;
			used[w] = false;
		}
		g[v].push_back(u);
		tg[u].push_back(v);
	}
	ord.clear();
	for (int i : cur) if (i < m){
		for (int v : {getp(e[i].v), getp(e[i].u)}) if (!used[v]){
			ts(v);
		}
	}
	reverse(ord.begin(), ord.end());
	int k = 0;
	for (int v : ord) if (clr[v] == -1){
		dfs(v, k);
		++k;
	}
	int tim = val.size();
	for (int i : cur) if (i < m) unite(e[i].v, e[i].u);
	vector<int> tol, tor;
	for (int i : cur){
		if (i >= m)
			tor.push_back(i);
		else if (getp(e[i].v) == getp(e[i].u))
			tol.push_back(i);
		else
			tor.push_back(i);
	}
	calc(m, r, tor);
	while (int(val.size()) > tim){
		*where.back() = val.back();
		where.pop_back();
		val.pop_back();
	}
	calc(l, m, tol);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	e.resize(q);
	forn(i, q){
		int x, y;
		char c;
		cin >> x >> y >> c;
		--x, --y;
		if (c == 'R')
			e[i] = {y + n, x};
		else
			e[i] = {x, y + n};
	}
	rk.resize(n + m, 1);
	p.resize(n + m);
	iota(p.begin(), p.end(), 0);
	used.resize(n + m, 0);
	clr.resize(n + m, -1);
	g.resize(n + m);
	tg.resize(n + m);
	vector<int> cur(q);
	iota(cur.begin(), cur.end(), 0);
	calc(0, q + 1, cur);
	ans.pop_back();
	reverse(ans.begin(), ans.end());
	for (long long x : ans) cout << x << 'n';
	return 0;
}
```
