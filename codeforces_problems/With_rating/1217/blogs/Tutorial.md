# Tutorial

[1217A - Creating a Character](../problems/A._Creating_a_Character.md "Educational Codeforces Round 72 (Rated for Div. 2)")

 **Tutorial**
### [1217A - Creating a Character](../problems/A._Creating_a_Character.md "Educational Codeforces Round 72 (Rated for Div. 2)")

Let $addS$ and $addI$ be number of free points that we invest in the strength and intelligence respectively. It's obvious that $addS + addI = exp$ since we must spend all free points. From the other side we must make $str + addS > int + addI$.

Now we can expess $addI = exp - addS$ and put it in the inequality: $$str + addS > int + (exp - addS)$$ $$2addS > exp + int - str$$ $$2addS \ge exp + int - str + 1$$ $$addS \ge \left \lceil \frac{exp + int - str + 1}{2} \right \rceil$$

Since $addS$ must be non negative we can get $$addS \ge \max(0, \left \lceil \frac{exp + int - str + 1}{2} \right \rceil)$$

We can use or write the correct ceiling function that works with negative numerator or use one hack and magic and get $$addS \ge \max(0, \frac{exp + int - str + 2}{2})$$ with usual integer division. Let's denote this value as $minAddS$.

Since all integer values $addS$ from $[minAddS, exp]$ are good for us, so the number of pairs is equal to $\max(0, exp - minAddS + 1)$.

P.S.: Let me explain how to prove that $k \cdot x > y$ is equal to $x \ge \left \lfloor \frac{y + k}{k} \right \rfloor$. 

$k \cdot x > y \Leftrightarrow k \cdot x \ge y + 1 \Leftrightarrow x \ge \left \lceil \frac{y + 1}{k} \right \rceil \Leftrightarrow x \ge \left \lfloor \frac{y + 1 + k - 1}{k} \right \rfloor \Leftrightarrow x \ge \left \lfloor \frac{y + k}{k} \right \rfloor$

P.P.S.: Interesting fact: the formula above works for all positive $k$ and $y \in [-k, +\infty)$ thats why it works in our case even though $exp + int - str$ can be negative.

 **Solution (adedalic)**
```cpp
fun main() {
    val t = readLine()!!.toInt()
    for (ct in 1..t) {
        val (str, int, exp) = readLine()!!.split(' ').map { it.toInt() }
        val minAddStr = maxOf(0, (exp + int - str + 2) / 2)
        println(maxOf(exp - minAddStr + 1, 0))
    }
}
```
[1217B - Zmei Gorynich](../problems/B._Zmei_Gorynich.md "Educational Codeforces Round 72 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1217B - Zmei Gorynich](../problems/B._Zmei_Gorynich.md "Educational Codeforces Round 72 (Rated for Div. 2)")

Lets divide all dealing blows into two parts: the last blow and others blows. 

The last hit should be with maximum value of $d$.

The others blows should be with the maximum value of $d - h$.

So, lets denote $\max\limits_{1 \le i \le n} d_i$ as $maxD$ and $\max\limits_{1 \le i \le n} (d_i - h_i)$ as $maxDH$.

Then if $x \le maxD$ the we can beat Zmei Gorynich with one blow. Otherwise, if $maxDH \le 0$, then we cannot defeat Zmei Gorynich. 

Otherwise (if $x > maxD$ and $maxDH > 0$) the answer is $\lceil \frac{x - maxD}{maxDH} \rceil$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int t;
int n, m;
int d[N], h[N];

int main() {
	cin >> t;
	for(int tc = 0; tc < t; ++tc){
		cin >> n >> m;
		int maxDH = -2e9;
		for(int i = 0; i < n; ++i){
			cin >> d[i] >> h[i];
			maxDH = max(maxDH, d[i] - h[i]);
		}

		int res = 1;	
		int maxD = *max_element(d, d + n);
		m -= maxD;
		if(m > 0){
			if(maxDH <= 0) res = -1;
			else res += (m + maxDH - 1) / maxDH; 	
		}	
		cout << res << endl;
	}
	
	return 0;
}
```
[1217C - The Number Of Good Substrings](../problems/C._The_Number_Of_Good_Substrings.md "Educational Codeforces Round 72 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1217C - The Number Of Good Substrings](../problems/C._The_Number_Of_Good_Substrings.md "Educational Codeforces Round 72 (Rated for Div. 2)")

At first, lets precalc the array $nxt_1, nxt_2, \dots , nxt_n$. The value of $nxt_i$ if equal the maximum position $j$ in range $1 \dots i$ such that $s_j = 1$. 

After that lets iterate over the right boundary of substring and high $1$-bit position (denote it as $r$ and $l$ respectively).

Note that if $r - l > 18$ then $f(l, r) > 2 \cdot 10^5$.

So we iterate over such pair $(l, r)$ that $1 \le l \le r \le n$ and $r - l \le 18$.

Lets look at value $f(l, r)$. If $f(l, r) > r - l + 1$, then we have to increase the length of substring without increasing the value of $f(l, r)$. So we need to check if there exists a position $nl$ such that $f(nl, r) = f(l, r)$ and $r - nl + 1 = f(nl, r)$. This position exists if the condition $f(l, r) \le r - nxt_{l - 1}$ is met ($nxt_0$ is equal to -1). 

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

int t;
string s;
int nxt[N];

int main() {
	cin >> t;
	for(int tc = 0; tc < t; ++tc){
		cin >> s;
		for(int i = 0; i < s.size(); ++i)
			if(s[i] == '1') nxt[i] = i;
			else nxt[i] = (i == 0? -1 : nxt[i - 1]);		
		int res = 0;
		for(int r = 0; r < s.size(); ++r){
			int sum = 0;
			for(int l = r; l >= 0 && r - l < 20; --l){
				if(s[l] == '0') continue;
				sum += 1 << (r - l);
				if(sum <= r - (l == 0? -1 : nxt[l - 1]))
					++res;
			}
		}
		cout << res << endl;
	}	

	return 0;
}
```
[1217D - Coloring Edges](../problems/D._Coloring_Edges.md "Educational Codeforces Round 72 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1217D - Coloring Edges](../problems/D._Coloring_Edges.md "Educational Codeforces Round 72 (Rated for Div. 2)")

Let's run dfs on the graph and color all "back edges" ($(u, v)$ is back edge if there is a path from $v$ to $u$ by edges from dfs tree) in black and all other edges in white. 

It can be proven that any cycle will have at least one white edge and at least black edge. Moreover each back edge connected with at least one cycle (path from $v$ to $u$ and $(u, v)$ back edge). So the coloring we got is exactly the answer.

How to prove that any cycle have at least one edge of both colors? Let's look only at edges from dfs trees. We can always renumerate vertices in such way that index of parent $id(p)$ is bigger than the index of any its child $id(c)$. We can process and assign $id(p)$ with minimal free number after we processed all its children.

Now we can note that for any white edge $(u, v)$ (not only tree edge) condition $id(u) > id(v)$ holds (because of properties of dfs: forward edges are obvious; cross edge $(u, v)$ becomes cross because dfs at first processed vertex $v$ and $u$ after that, so $id(v) < id(u)$). And for each back edge $(u, v)$ it's true that $id(u) < id(v)$. 

Since any cycle have both $id(u) > id(v)$ and $id(u) < id(v)$ situations, profit!

 **Solution (Roms)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 55;

int n, m;
vector <pair<int, int> > g[N];
int col[N];
bool cyc;
int res[N];

void dfs(int v){
	col[v] = 1;
	for(auto p : g[v]){
		int to = p.first, id = p.second;
		if(col[to] == 0){
			dfs(to);
			res[id] = 1;
		}
		else if(col[to] == 2)
			res[id] = 1;
		else{
			res[id] = 2;
			cyc = true;
		}
	}
	col[v] = 2;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(make_pair(v, i));
	}
	
	for(int i = 0; i < n; ++i)
			if(col[i] == 0)
				dfs(i);
			
	cout << (cyc? 2 : 1) << endl;
	for(int i = 0; i < m; ++i) cout << res[i] << ' ';
	cout << endl;
	return 0;
}
```
[1217E - Sum Queries?](../problems/E._Sum_Queries_.md "Educational Codeforces Round 72 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1217E - Sum Queries?](../problems/E._Sum_Queries_.md "Educational Codeforces Round 72 (Rated for Div. 2)")

We are given the definition of the balanced multiset but let's instead fix the criteria to determine if the multiset is unbalanced.

Take an empty multiset and start adding numbers to it until it becomes unbalanced. Empty set to the set of one number is trivial. Now for the second number. If there is some position such that both numbers have non-zero digits in it, then the multiset becomes unbalanced (let these be non-zero digits $d_1$ and $d_2$, then $d_1 + d_2$ can be neither $d_1$, nor $d_2$).

After that let's prove that you can never make an unbalanced multiset balanced again by adding numbers to it. Let there be such multisets $a$ and $b$ such $a$ is unbalanced, $b$ is balanced and $a \subset b$. Take a look at the lowest position which has non-zero digits in several numbers from $b$. The sum of these digits should be equal to at least one of them modulo $10$ (to satisfy the condition of balance). That can only mean their sum is greater or equal to $10$, thus is make a carry to the next position. The sum of digits on the next position plus carry should also be equal to some digit of them, thus pushing some other carry value to the next one. And so on until the carry makes it to the position greater than any position in any of the numbers. But the carry is non-zero and there is no number with any non-zero digit in this position. That makes our assumption incorrect.

After all, it implies that any unbalanced multiset of size greater than two has an unbalanced multiset of size two.

The problem now got reduced to: find a pair of numbers $a_i$ and $a_j$ such that $l \le i < j \le r$, there is at least one position such that both $a_i$ and $a_j$ have non-zero digits on it and $a_i + a_j$ is minimal possible.

That can be easily maintained in a segment tree. Let a node corresponding to the interval $[l; r)$ keep the best answer on an interval (the sum of such a pair) and an array $min\\_by\\_digit[i]$ — the smallest number on an interval $[l; r)$ which has a non-zero digit at position $i$ or $\infty$ if none exists.

The update is easy. Iterate over the digits of a new number and update the values in the array $min\\_by\\_digit$ in the corresponding nodes.

The merge is done the following way: push the best answers from children to the parent and then iterate over the positions and try to combine the smallest numbers at each one from the left child and the right child.

Idea-wise this is the same as storing a segtree and calculating the answer by each position separately.

However, these approaches differ by a huge constant factor performance-wise. The former one accesses the memory in a much more cache-friendly way. You might want to take that as a general advice on implementing multiple segtrees.

Overall complexity: $O((n + m) \cdot \log n \cdot \log_{10} MAXN)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;
const int INF = 2e9;
const int LOGN = 9;

struct node{
	int best;
	int mn[LOGN];
	node(){
		best = INF;
		forn(i, LOGN)
			mn[i] = INF;
	}
	int& operator [](int x){
		return mn[x];
	}
};

int a[N];
node t[4 * N];

void upd(node &t, int val){
	int x = val;
	forn(i, LOGN){
		if (x % 10 != 0)
			t[i] = min(t[i], val);
		x /= 10;
	}
}

node merge(node &a, node &b){
	node c;
	c.best = min(a.best, b.best);
	forn(i, LOGN){
		c[i] = min(a[i], b[i]);
		if (a[i] < INF && b[i] < INF)
			c.best = min(c.best, a[i] + b[i]);
	}
	return c;
}

void build(int v, int l, int r){
	if (l == r - 1){
		t[v] = node();
		upd(t[v], a[l]);
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

void upd(int v, int l, int r, int pos, int val){
	if (l == r - 1){
		t[v] = node();
		upd(t[v], val);
		return;
	}
	int m = (l + r) / 2;
	if (pos < m)
		upd(v * 2, l, m, pos, val);
	else
		upd(v * 2 + 1, m, r, pos, val);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

node get(int v, int l, int r, int L, int R){
	if (l == L && r == R)
		return t[v];
	int m = (l + r) / 2;
	if (R <= m)
		return get(v * 2, l, m, L, R);
	if (L >= m)
		return get(v * 2 + 1, m, r, L, R);
	node ln = get(v * 2, l, m, L, m);
	node rn = get(v * 2 + 1, m, r, m, R);
	return merge(ln, rn);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	forn(i, n)
		scanf("%d", &a[i]);
	build(1, 0, n);
	forn(i, m){
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		--x;
		if (t == 1)
			upd(1, 0, n, x, y);
		else{
			node res = get(1, 0, n, x, y);
			printf("%dn", res.best == INF ? -1 : res.best);
		}
	}
	return 0;
}
```
[1217F - Forced Online Queries Problem](../problems/F._Forced_Online_Queries_Problem.md "Educational Codeforces Round 72 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1217F - Forced Online Queries Problem](../problems/F._Forced_Online_Queries_Problem.md "Educational Codeforces Round 72 (Rated for Div. 2)")

The problem directly tells you do solve some kind of Dynamic Connectivity Problem. 

You could use the online approach with Link-Cut Tree if you'd had its implementation beforehand. There is also a nice modification to the $log^2$ solution of the offline version of DCP (check out the [comment](Announcement.md?#comment-540932)).

I'd tell the solution which is probably the easiest to come up with and to code.

Let's recall the sqrt-optimization method of solving DCP. Process blocks of queries of size $P$ one at a time. Split the edges into two groups: 

1. The edges which were added on queries before the block and aren't touched by the queries in the block;
2. the edges modified by the queries in the block.

The first type of edges can be added to the graph before the block processing starts. You can use DSU for that. The second type contains no more than $P$ edges. Maintain the list of those of them which exist in the graph. On each ask query add them to graph, then delete them. This can be done explicitly by doing DFS only over these edges and the vertices which correspond to the connected components on the edges of the first type. Implicitly doing DSU merges for these edges and rolling them back is a viable option as well (costs extra log factor but has lower constant).

It's easy to see that it isn't hard to modify this solution to our problem. Let's define the edges of the first type more generally: the edges which were added on queries before the block and could not be touched by the queries in the block. So neither $(v, u)$ from the add query, nor $(v~mod~n + 1, u~mod~n + 1)$ could be of the first type. Now there might be $2P$ edges of the second type in the list. However, that doesn't make the complexity any worse.

Process block the same way, rebuild the DSU with the edges of the first type every $P$ queries.

The overall complexity can be $O((n + m) \sqrt{m})$ if you use DFS or $O((n + m) \sqrt{m \log n})$ if you use DSU (notice how the rebuild is $P \cdot O(n + m)$ and the query is $m \cdot O(\frac{m}{P} \cdot \log n)$ and set the size of the block so that these parts are about the same).

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int BUF = 10 * 1000 * 1000 + 13;
const int N = 300 * 1000 + 13;
const int M = 300 * 1000 + 13;
const int P = 400;

struct query{
	int t, x, y;
	int e0, e1;
};

int n, m;
query q[M];

int p[N], rk[N];

int cnt;
int* where[BUF];
int val[BUF];

void rollback(){
	while (cnt > 0){
		*where[cnt - 1] = val[cnt - 1];
		--cnt;
	}
}

int getp(int a){
	return (a == p[a] ? a : getp(p[a]));
}

void unite(int a, int b){
	a = getp(a), b = getp(b);
	if (a == b) return;
	if (rk[a] < rk[b]) swap(a, b);
	where[cnt] = &rk[a];
	val[cnt++] = rk[a];
	where[cnt] = &p[b];
	val[cnt++] = p[b];
	assert(cnt <= BUF);
	rk[a] += rk[b];
	p[b] = a;
}

int getpFast(int a){
	return (a == p[a] ? a : p[a] = getpFast(p[a]));
}

void uniteFast(int a, int b){
	a = getpFast(a), b = getpFast(b);
	if (a == b) return;
	if (rk[a] < rk[b]) swap(a, b);
	rk[a] += rk[b];
	p[b] = a;
}

struct edge{
	int v, u;
};

bool operator <(const edge &a, const edge &b){
	if (a.v != b.v)
		return a.v < b.v;
	return a.u < b.u;
}

edge edges[2 * M];
map<edge, int> rev;

bool used[2 * M];
bool state[2 * M];
int ans[M];
vector<int> cur;

void rebuild(int l){
	int r = min(m, l + P);
	forn(i, n) p[i] = i, rk[i] = 1;
	memset(used, 0, sizeof(used));
	memset(state, 0, sizeof(state));

	forn(i, l) if (q[i].t == 1){
		int e = (ans[i] ? q[i].e1 : q[i].e0);
		used[e] = true;
		state[e] ^= 1;
	}
	
	for (int i = l; i < r; ++i) if (q[i].t == 1)
		used[q[i].e0] = used[q[i].e1] = false;
	
	cur.clear();
	cnt = 0;
	forn(i, l) if (q[i].t == 1){
		int e = (ans[i] ? q[i].e1 : q[i].e0);
		if (used[e] && state[e]){
			state[e] = false;
			uniteFast(edges[e].v, edges[e].u);
		}
		else if (!used[e] && state[e]){
			state[e] = false;
			cur.push_back(e);
		}
	}
}

int get_edge(edge e){
	if (!rev.count(e)){
		int k = rev.size();
		edges[k] = e;
		rev[e] = k;
	}
	return rev[e];
}

int main(){
	scanf("%d%d", &n, &m);
	forn(i, m){
		scanf("%d%d%d", &q[i].t, &q[i].x, &q[i].y);
		--q[i].x, --q[i].y;
		if (q[i].t == 1){
			edge e({q[i].x, q[i].y});
			if (e.v > e.u) swap(e.v, e.u);
			q[i].e0 = get_edge(e);
			e.v = (e.v + 1) % n, e.u = (e.u + 1) % n;
			if (e.v > e.u) swap(e.v, e.u);
			q[i].e1 = get_edge(e);
		}
	}
	
	string res = "";
	ans[0] = 0;
	forn(i, m){
		if (i % P == 0)
			rebuild(i);
		
		int x = (q[i].x + ans[i]) % n;
		int y = (q[i].y + ans[i]) % n;
		if (x > y) swap(x, y);
		
		if (q[i].t == 1){
			rollback();
			int e = get_edge({x, y});
			auto it = find(cur.begin(), cur.end(), e);
			if (it == cur.end())
				cur.push_back(e);
			else
				cur.erase(it);
			ans[i + 1] = ans[i];
		}
		else{
			for (auto e : cur)
				unite(edges[e].v, edges[e].u);
			bool rc = (getp(x) == getp(y));
			ans[i + 1] = rc;
			res += ('0' + rc);
		}
	}
	
	puts(res.c_str());
	return 0;
}
```
