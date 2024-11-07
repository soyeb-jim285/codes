# Tutorial

[1814A - Coins](../problems/A._Coins.md "Educational Codeforces Round 146 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1814A - Coins](../problems/A._Coins.md "Educational Codeforces Round 146 (Rated for Div. 2)")

Note that $2$ coins with denomination $k$ can be replaced with $k$ coins with denomination $2$. So, if the answer exists, then there is also such a set of coins, where there is no more than one coin with denomination $k$. Therefore, it is enough to iterate through the number of coins with denomination $k$ (from $0$ to $1$) and check that the remaining number is non-negative and even (i. e. it can be represented as some number of coins with denomination $2$).

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n, k = map(int, input().split())
	for x in range(2):
		if n - x * k >= 0 and (n - x * k) % 2 == 0:
			print("YES")
			break
	else:
		print("NO")
```
[1814B - Long Legs](../problems/B._Long_Legs.md "Educational Codeforces Round 146 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1814B - Long Legs](../problems/B._Long_Legs.md "Educational Codeforces Round 146 (Rated for Div. 2)")

Let's fix the number of leg length increases we do. Let the final length be $k$. Notice that for all $i$ from $1$ to $k$ there is some time when the length is exactly $i$. Thus, we can perform jumps of form $(x, y) \rightarrow (x + i, y)$ or $(x, y) \rightarrow (x, y + i)$.

What's the jumping strategy, then? Obviously, we can solve the problem independently for $a$ and $b$. Consider $a$. We would love to just make jumps of length $k$ as that's the maximum possible length. Unfortunately, that only works when $a$ is divisible by $k$. Otherwise, we are left with some remainder which is smaller than $k$. But we have already figured out how to jump to any value from $1$ to $k$. So, that only adds another jump. You can say that the total number of jumps is $\lceil \frac a k \rceil$.

Same for $b$. Finally, for a fixed $k$, the answer is $\lceil \frac a k \rceil + \lceil \frac b k \rceil + (k - 1)$.

The constraints tell us that we are not allowed to iterate over all $k$ from $1$ to $\max(a, b)$. It feels like huge $k$ will never be optimal, but let's try to base our intuition on something.

Try to limit the options by studying the formula. Let's simplify. Assume $a = b$ and also get rid of the ceil. Not like that changes the formula a lot. Now it becomes $2 \frac a k + (k - 1)$. We can see that when we increase $k$, $2 \frac a k$ becomes smaller and $(k - 1)$ becomes larger. However, we care more about how fast they become smaller and larger. You can just guess or write down the derivative explicitly and figure out that the first term shrinks faster than the second term grows until around $\sqrt a \cdot c$ for some constant $c$ (apparently, $c = \sqrt 2$). Thus, their sum decreases until then, then increases.

Thus, you can search for the best $k$ around $\sqrt a$ or $\sqrt b$ or $\sqrt{\max(a, b)}$. It doesn't really matter, since, for implementation, you can basically try all $k$ until around $10^5$, which is safely enough.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	a, b = map(int, input().split())
	ans = a + b
	for m in range(1, 100000):
		ans = min(ans, (a + m - 1) // m + (b + m - 1) // m + (m - 1))
	print(ans)
```
[1814C - Search in Parallel](../problems/C._Search_in_Parallel.md "Educational Codeforces Round 146 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1814C - Search in Parallel](../problems/C._Search_in_Parallel.md "Educational Codeforces Round 146 (Rated for Div. 2)")

If the ball of color $x$ is present in the first list on position $i$, then it takes $i \cdot t_1$ seconds to find it. The same for the second list: if color $x$ is on position $j$, it takes $j \cdot t_2$ seconds to find it. So, for each position, we have a coefficient which will be multiplied by the number of times it is requested, and the total search time is the sum of these products for all positions.

There is a classical problem of the form "you are given two arrays $a_i$ and $b_i$, both of length $m$, consisting of non-negative integers; permute the elements of $a$ in such a way that $\sum\limits_{i=1}^{m} a_i \cdot b_i$ is the minimum possible". To solve this problem, you have to pair the maximum element of $a$ with the minimum element of $b$, the second maximum of $a$ with the second minimum element of $b$, and so on.

We can reduce our problem to this one. For each of $2n$ positions in the lists, there is a coefficient; you have to assign the boxes from $1$ to $n$ to the positions so that the sum of $r_i$ multiplied by the coefficients for the positions is the minimum possible. This looks similar, but there are $2n$ positions and only $n$ boxes.

To resolve this issue, we can try a lot of different approaches. I believe the easiest one is the following: initially, both lists are empty, and when want to add an element to one of these two lists, we choose the list such that the coefficient for the new position (which is $s_i \cdot (1 + cnt_i)$, where $cnt_i$ is the number of elements we already added to the $i$-th list) is smaller. If for both lists, adding a new element has the same coefficient — it doesn't matter which one we choose.

This greedy approach works because every time we add an element to the list, next time we'll add another one into the same list, the coefficient for that element will be greater.

So, the problem can be solved in $O(n \log n)$: first, we sort the boxes by the number of times they are requested (in non-ascending order), and then we put them into the two lists greedily, every time choosing the list such that the coefficient for the next element is smaller.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		vector<int> s(2);
		for(int j = 0; j < 2; j++)
			scanf("%d", &s[j]);
		vector<pair<int, int>> a(n);
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &a[j].first);
			a[j].second = j + 1;
		}
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		vector<vector<int>> lists(2);
		for(int j = 0; j < n; j++)
		{
			int cost1 = s[0] * (lists[0].size() + 1);
			int cost2 = s[1] * (lists[1].size() + 1);
			if(cost1 < cost2)
				lists[0].push_back(a[j].second);
			else
				lists[1].push_back(a[j].second);
		}
		for(int j = 0; j < 2; j++)
		{
		    cout << lists[j].size();
		    for(auto x : lists[j]) cout << " " << x;
		    cout << endl;
		}
	}
}
```
[1814D - Balancing Weapons](../problems/D._Balancing_Weapons.md "Educational Codeforces Round 146 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1814D - Balancing Weapons](../problems/D._Balancing_Weapons.md "Educational Codeforces Round 146 (Rated for Div. 2)")

Note that the answer $n$ is always possible: for example, we can set $d_i = \frac{\prod{f_j}}{f_i}$, then $p_1 = \dots = p_n = \prod{f_j}$ and $\max{p_i} - \min{p_i} = 0$.

If the answer is less than $n$ then there is at least one gun $id$ we won't change. It means that all other guns' firepower should be "around" $p_{id}$, i. e. $|p_i - p_{id}| \le k$. So we can look at segment $[p_{id} - k, p_{id} + k]$ and, for each gun $i$, find what values $d'_i$ we should set to get into this segment. After that we can rephrase our task into the next one: we should choose segment $[l, l + k] \subset [p_{id} - k, p_{id} + k]$ such that each gun occurs in $[l, l + k]$ at least once and the number of corresponding $d'_i$ that are equal to $d_i$ is maximum possible.

It can be solved with two pointers technique. Note that there are at most three interesting values $d'_i$ we should consider: $v_1 = \left\lfloor \frac{p_{id}}{f_i} \right\rfloor$, $v_2 = v_1 + 1$ and $v_3 = d_i$. For each unique value $v_j$ such that $v_j \cdot f_i \in [p_{id} - k, p_{id} + k]$ we can add an event $(i, c_j)$ in position $v_j f_i$, where $c_j$ is $1$ if $v_j = d_i$ or $0$ otherwise.

Now, with two pointers technique, we can iterate over all subsegments of length $k + 1$ of segment $[p_{id} - k, p_{id} + k]$. To get the desired answer we should maintain the number of unique $i$ from events that are present in the subsegment and the sum $s$ of $c_j$ from that events. Since there is only one $c_j = 1$ for each gun $i$ then the sum $s$ of $c_j$ we have is equal exactly to the number of guns we shouldn't change. Then we take the maximum $mx$ over sums $s$ of all subsegments where all guns occur, and the answer for a fixed $p_{id}$ is $n - mx$.

Let's iterate over all "fixed" $id$ and take the minimum from all $n - mx$: that will be the answer for the initial task.

Checking answer for a fixed $id$ involves creating $3 n$ events and two pointers over segment $[p_{id} - k, p_{id} + k]$, so it takes $O(n + k)$ time and $O(n + k)$ space. So, the total complexity is $O(n^2 + n k)$ time and $O(n + k)$ space.

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readln().toInt()) {
        val (n, k) = readln().split(' ').map { it.toInt() }
        val f = readln().split(' ').map { it.toLong() }
        val d = readln().split(' ').map { it.toLong() }

        fun checkAround(pos : Long) : Int {
            val qs = Array(2 * k + 1) { MutableList(0) { 0 } }

            fun inside(x : Long, pos: Long) = (pos - k <= x) && (x <= pos + k)
            for (i in f.indices) {
                var newD = maxOf(1L, pos / f[i])
                if (newD != d[i] && newD + 1 != d[i] && inside(d[i] * f[i], pos)) {
                    val id = (i + 1)
                    qs[(d[i] * f[i] - pos + k).toInt()].add(id)
                }
                repeat(2) {
                    if (inside(newD * f[i], pos)) {
                        val id = if (newD == d[i]) (i + 1) else -(i + 1)
                        qs[(newD * f[i] - pos + k).toInt()].add(id)
                    }
                    newD++
                }
                
            }

            val cntPerId = IntArray(n) { 0 }
            var cntDistinct = 0
            var cntGood = 0

            fun addToSeg(cid : Int) {
                val id = -1 + if (cid > 0) cid else -cid
                val c = if (cid > 0) 1 else 0

                if (cntPerId[id] == 0)
                    cntDistinct++
                cntPerId[id]++

                cntGood += c
            }
            fun eraseFromSeg(cid : Int) {
                val id = -1 + if (cid > 0) cid else -cid
                val c = if (cid > 0) 1 else 0

                cntPerId[id]--
                if (cntPerId[id] == 0)
                    cntDistinct--

                cntGood -= c
            }
            var ans = 0
            for (p in 0 until k)
                qs[p].forEach { addToSeg(it) }
            for (p in 0..k) {
                qs[p + k].forEach { addToSeg(it) }
                if (cntDistinct == n)
                    ans = maxOf(ans, cntGood)
                qs[p].forEach { eraseFromSeg(it) }
            }
            return n - ans
        }

        var ans = n
        for (i in f.indices) {
            ans = minOf(ans, checkAround(d[i] * f[i]))
        }
        println(ans)
    }
}
```
[1814E - Chain Chips](../problems/E._Chain_Chips.md "Educational Codeforces Round 146 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1814E - Chain Chips](../problems/E._Chain_Chips.md "Educational Codeforces Round 146 (Rated for Div. 2)")

Let's try to analyze how many times we traverse each edge, in the style of "Contribution to the Sum" technique. For each edge, the number of times it is traversed must be even, since for every chip that goes from the part of the graph $[1..i]$ to the part $[i+1..n]$, there should be a chip that goes in the opposite direction (the number of chips on vertices $[1..n]$ should be unchanged).

For each vertex, at least one incident edge should be traversed at least twice — otherwise, the chip from this vertex cannot be moved to any other vertex.

We would also like to traverse the edges as rarely as possible. Is it possible to find an answer where, if we traverse any edge, we traverse it only twice? It turns out it is possible. Let's "split" the graph into several parts by removing the edges we don't traverse. If we don't break the constraint that each vertex has at least one incident edge which is traversed by some chip, then each part of the graph will contain at least two vertices. And in each part, we can make sure that each edge is traversed only twice as follows: let the part represent the segment $[l, r]$ of vertices; if we move the chip $r$ to the vertex $l$, the chip $l$ to the vertex $l+1$, the chip $l+1$ to the vertex $l+2$, ..., the chip $r-1$ to the vertex $r$, then every edge in that part will be traversed exactly twice.

So, we have shown that if we pick a subset of edges which we traverse that meets the constraint on each vertex having an incident traversed edge, then it is enough to traverse each chosen edge only twice. Now the problem becomes the following: choose a subset of edges in such a way that every vertex has at least one incident chosen edge, minimize the total weight of this subset, and print the integer which is double that total weight.

Since the structure of the graph is specific, we can run dynamic programming of the form $dp_{i,f}$ — the minimum total weight of the subset, if we considered the first $i$ edges, and $f$ is $0$ if we haven't taken the last edge, or $1$ if we have. Obviously, this dynamic programming works in $O(n)$, which is too slow because we have to process queries. We will employ a classical technique of storing the dynamic programming in segment tree: build a segment tree on $n-1$ leaves; in every vertex of the segment tree, we store a $2 \times 2$ matrix $d$; if the segment represented by the node of the segment tree is $[l..r]$, then the value of $d[f_1][f_2]$ is the minimum total weight of the subset of edges between $l$ and $r$ such that among every pair of adjacent edges, at least one is chosen; $f_1$ and $f_2$ represent the status of the first/last edge on the segment, respectively. And when some element changes, we need to recalculate only $O(\log n)$ nodes of the segment tree, so this solution works in $O(n \log n + q \log n)$, albeit with a very big constant factor.

Implementation note: don't use dynamic-size arrays (like std::vector in C++) to store the values in the matrices, it might slow your solution very seriously. Instead, use static-size arrays.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long li;

const li INF = (li)(1e18);
const int N = 200043;

struct data
{
	array<array<long long, 2>, 2> d;
	data() {
	    for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				d[i][j] = INF;
	};
	data(li x)
	{
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				d[i][j] = INF;
		d[0][0] = 0;
		d[1][1] = x;
	};
	data(data l, data r)
	{
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				d[i][j] = INF;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				for(int k = 0; k < 2; k++)
					for(int x = 0; x < 2; x++)
					{
						if(j == 0 && k == 0) continue;
						d[i][x] = min(d[i][x], l.d[i][j] + r.d[k][x]);
					}
	};
};

data T[4 * N];
li a[N];

void recalc(int v)
{
	T[v] = data(T[v * 2 + 1], T[v * 2 + 2]);
}

void build(int v, int l, int r)
{
	if(l == r - 1) T[v] = data(a[l]);
	else
	{
		int m = (l + r) / 2;
		build(v * 2 + 1, l, m);
		build(v * 2 + 2, m, r);
		recalc(v);
	}
}

void upd(int v, int l, int r, int pos, li val)
{
	if(l == r - 1)
	{
		a[l] = val;
		T[v] = data(a[l]);
	}
	else
	{
		int m = (l + r) / 2;
		if(pos < m)
			upd(v * 2 + 1, l, m, pos, val);
		else
			upd(v * 2 + 2, m, r, pos, val);
		recalc(v);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++)
	{
		scanf("%lld", &a[i]);
	}
	build(0, 0, n - 1);
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		int x;
		li k;
		scanf("%d %lld", &x, &k);
		upd(0, 0, n - 1, x - 1, k);
		printf("%lldn", T[0].d[1][1] * 2);
	}
}
```
[1814F - Communication Towers](../problems/F._Communication_Towers.md "Educational Codeforces Round 146 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1814F - Communication Towers](../problems/F._Communication_Towers.md "Educational Codeforces Round 146 (Rated for Div. 2)")

Let's consider the sweep line approach by the value of the variable $x$; the vertex $i$ is active from the moment $l_i$ to the moment $r_i$. And we have to find vertices that are reachable in the graph of active vertices from the vertex $1$. So, we rephrased the problem as follows: there are vertices that are active at some moments, and we want to get some information about connectivity during each moment of time. This is a standard offline dynamic connectivity problem which can be solved with a divide-and-conquer approach described [here](https://codeforces.com/blog/entry/15296).

Now we are able to find the connectivity component of the $1$-th vertex for each value of $x$. It remains to understand how to combine answers for all values of $x$ fast enough. Let's try to visualize the components as vertices of a directed graph. We assign a vertex to each component, and when two components merge, we add two directed edges from the new vertex to the vertices corresponding to the components; and now we can use the reachability information in this graph. Each vertex of the original graph corresponds to one of the sinks in this graph; and sinks that correspond to the vertices of some component are reachable from the vertex corresponding to that component. To restore all the vertex indices later, we will mark all components containing the vertex $1$ while we run our dynamic connectivity approach. Then the vertex $v$ (of the original graph) is included in the answer if the vertex representing the component containing only the vertex $v$ is reachable from any of the marked vertices. Now, all you need to do is run DFS or BFS from all the marked vertices in the component graph.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size())

const int N = 200002;
const int V = 50 * N;

using pt = pair<int, int>;

int n, m;
pt a[N];
vector<pt> t[4 * N];
int p[N], rk[N], vs[N];
int cntV;
pt g[V];
bool ans[V];

void upd(int v, int l, int r, int L, int R, pt e) {
  if (L >= R) return;
  if (l == L && r == R) {
    t[v].push_back(e);
    return;
  }
  int m = (l + r) / 2;
  upd(v * 2 + 1, l, m, L, min(m, R), e);
  upd(v * 2 + 2, m, r, max(m, L), R, e);
}

int k;
int* ptr[V];
int val[V];

void upd(int &a, int b) {
  ptr[k] = &a;
  val[k] = a;
  k += 1;
  a = b;
}

int getp(int v) {
  return p[v] == v ? v : getp(p[v]);
}

void unite(int v, int u) {
  v = getp(v), u = getp(u);
  if (v == u) return;
  if (rk[v] > rk[u]) swap(v, u);
  upd(p[v], u);
  g[cntV] = {vs[v], vs[u]};
  upd(vs[u], cntV++);
  if (rk[v] == rk[u])
    upd(rk[u], rk[u] + 1);
}

void solve(int v, int l, int r) {
  int cur = k;
  for (auto& [v, u] : t[v]) 
    unite(v, u);
  if (l + 1 == r) {
    ans[vs[getp(0)]] = 1;
  } else {
    int m = (l + r) / 2;
    solve(v * 2 + 1, l, m);
    solve(v * 2 + 2, m, r);
  }
  while (k > cur) {
    k -= 1;
    (*ptr[k]) = val[k];
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> a[i].first >> a[i].second;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    int L = max(a[x].first, a[y].first);
    int R = min(a[x].second, a[y].second);
    upd(0, 0, N, L, R + 1, {x, y});
  }
  
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    rk[i] = 1;
    vs[i] = i;
    g[i] = {-1, -1};
  }
  
  cntV = n;
  solve(0, 0, N);
  
  queue<int> q;
  for (int i = 0; i < cntV; ++i) if (ans[i]) 
    q.push(i);
  
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int u : {g[v].first, g[v].second}) {
      if (u != -1 && !ans[u]) {
        ans[u] = true;
        q.push(u);
      }
    }
  }
  
  for (int i = 0; i < n; ++i) if (ans[i])
    cout << i + 1 << ' ';
}
```
