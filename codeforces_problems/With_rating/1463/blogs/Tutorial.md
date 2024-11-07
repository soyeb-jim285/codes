# Tutorial

[1463A - Dungeon](../problems/A._Dungeon.md "Educational Codeforces Round 100 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1463A - Dungeon](../problems/A._Dungeon.md "Educational Codeforces Round 100 (Rated for Div. 2)")

Note that for every $7$ shots, we deal a total of $9$ units of damage. Since we want to kill all the monsters with a shot which index is divisible by $7$, let's denote the number of shots as $7k$. In this case, a total of $a+b+c$ units of damage must be dealt, hence $k=\frac{a+b+c}{9}$ (if the result of the division is not an integer, then there is no answer). Since each monster will receive at least $k$ units of damage (with enhanced shots), the health of each monster must be at least $k$. If the two conditions described above are met, then the remaining shots can always be distributed in the desired way.

 **Solution (Ne0n25)**
```cpp
for i in range(int(input())):
	a, b, c = map(int, input().split())
	if (a + b + c) % 9 != 0:
		print("NO")
	else:
	    print("YES" if min(a, b, c) >= (a + b + c) // 9 else "NO")
```
[1463B - Find The Array](../problems/B._Find_The_Array.md "Educational Codeforces Round 100 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1463B - Find The Array](../problems/B._Find_The_Array.md "Educational Codeforces Round 100 (Rated for Div. 2)")

It is enough to consider two possible arrays $b$: ($a_1, 1, a_3, 1, a_5, \dots$) and ($1, a_2, 1, a_4, 1, \dots$). It is not difficult to notice that in these arrays, the condition is met that among two neighboring elements, one divides the other. It remains to show that at least one of these two arrays satisfies the condition $2 \sum \limits_{i = 1}^{n} |a_i - b_i| \le S$. Let's consider $S_{odd}$ — the sum of elements at odd positions and $S_{even}$ — the sum of elements at even positions. Since $S=S_{odd}+S_{even}$, at least one of the values of $S_{odd}$ and $S_{even}$ does not exceed $\frac{S}{2}$ (because otherwise their sum will be strictly greater than $S$). Without losing generality, assume that $S_{odd} \le \frac{S}{2}$. Note that for the second variant of the array $b$, the condition $\sum \limits_{i = 1}^{n} |a_i - b_i| \le S_{odd}$ holds, so $2 \sum \limits_{i = 1}^{n} |a_i - b_i| \le S$.

 **Solution (Ne0n25)**
```cpp
for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	s = sum(a)
	cur = [0, 0]
	for i in range(n):
		cur[i % 2] += a[i] - 1
	for j in range(2):
		if 2 * cur[j] > s:
			continue
		for i in range(n):
			if i % 2 == j:
				a[i] = 1
		break
	print(*a)
```
[1463C - Busy Robot](../problems/C._Busy_Robot.md "Educational Codeforces Round 100 (Rated for Div. 2)")

Idea: [KAN](https://codeforces.com/profile/KAN "Legendary Grandmaster KAN")

 **Tutorial**
### [1463C - Busy Robot](../problems/C._Busy_Robot.md "Educational Codeforces Round 100 (Rated for Div. 2)")

The main idea in the problem is not how to solve it but how to code it neatly. I've come up with the following way.

Let's store three variables: where is the robot now, what direction does it move ($-1$, $0$ or $1$) and how much time is left until it stops moving.

The processing of the commands looks becomes pretty easy. If there is no time left to move then the command is executed, and we tell the robot the direction and the time left for the current command. Then there are two cases: either the robot stops before the next command or after it. However, they can be processed simultaneously.

Let $T$ be the minimum of the time left before the robot stops moving and the time before the next command. We sure know that before the next command the robot will visit exactly the segment of positions between the current position and the current position plus direction multiplied by $T$. If the destination for the current command is in this segment, then that command is successful.

After the command is processed subtract $T$ from the time left and increase the position by direction multiplied by $T$.

Overall complexity: $O(n)$ per testcase.

 **Solution (pikmike)**
```cpp
def inside(l, r, x):
	return min(l, r) <= x <= max(l, r)

def sg(x):
	return -1 if x < 0 else int(x > 0)

for _ in range(int(input())):
	n = int(input())
	qs = []
	for i in range(n):
		qs.append(list(map(int, input().split())))
	qs.append([4*10**9, 0])
	ans = 0
	pos, dr, lft = 0, 0, 0
	for i in range(n):
		t, x = qs[i]
		tn = qs[i + 1][0]
		if lft == 0:
			lft = abs(pos - x)
			dr = sg(x - pos)
		tmp = min(lft, tn - t)
		if inside(pos, pos + dr * tmp, x):
			ans += 1
		pos += dr * tmp
		lft -= tmp
	print(ans)
```
[1463D - Pairs](../problems/D._Pairs.md "Educational Codeforces Round 100 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1463D - Pairs](../problems/D._Pairs.md "Educational Codeforces Round 100 (Rated for Div. 2)")

Let's prove that in the set $b$ $x$ minimum elements will be from $x$ pairs where we'll take minimums and analogically $n - x$ maximums will be from $n - x$ pairs where we'll take maximums. By contradiction, let's look at two pairs $(a, b)$ ($a < b$) and $(c, d)$ ($c < d$), where we will take maximum from $(a, b)$ and minimum from $(c, d)$ and $b < c$, if we swap elements $b$ and $c$ and get pair $(a, c)$, $(b, d)$, the result won't change, but now minimum from pair $(b, d)$ will be less than maximum from $(a, c)$. So we can always make pairs in such a way that the chosen minimum from any pair will be less than the chosen maximum from any other pair.

Let's make set $nb$ as all elements which are not in $b$. In the same way, we can prove that $n - x$ minimums of $nb$ are from pairs where we took maximums and $x$ maximums are from pairs where we took minimums.

Let's say $b$ and $nb$ are sorted. Now we've proven that for a fixed $x$ we should pair $b_1, b_2, \dots, b_x$ with $nb_{n - x + 1}, nb_{n - x + 2}, \dots, nb_{n}$ and $b_{x + 1}, \dots, b_n$ with $nb_1, \dots, nb_{n - x}$. It's not hard to prove that it's optimal to pair $(b_1, nb_{n - x + 1})$, $(b_2, nb_{n - x + 2})$, ..., $(b_x, nb_n)$ and in the same way $(nb_1, b_{x + 1})$, $(nb_2, b_{x + 2})$, ..., $(nb_{n - x}, b_n)$.

For a fixed $x$ we can just check that constructed pairs are valid. But what happens if we move from $x$ to $x + 1$? If for $1 \le i \le n - x$ all $(nb_i, b_{x + i})$ was valid then for $x + 1$ all pairs $(nb_i, b_{x + 1 + i})$ will be valid as well. And on contrary, if at least one pair $(b_i, nb_{n - x + i})$ wasn't valid then for $x + 1$ the pair $(b_i, nb_{n - x - 1 + i})$ won't be valid as well.

Due to monotony we can find the maximum valid $x$ just checking only pairs $(b_i, nb_{n - x + i})$ and in the same way we can find maximum $n - x$ (minimum $x$) such that all pairs $(nb_i, b_{x + i})$ are valid. That's why all valid $x$-s form a segment, and we need to find its borders.

We can find a maximum $x$ (maximum $n - x$) with either binary search or with two pointers and print the length of the segment. Time complexity is either $O(n)$ or $O(n \log{n})$.

 **Solution 1 (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

const int INF = int(1e9);

int n;
vector<int> b;

inline bool read() {
	if(!(cin >> n))
		return false;
	b.resize(n);
	fore (i, 0, n)
		cin >> b[i];
	return true;
}

bool ok(const vector<int> &a, const vector<int> &b, int cnt) {
	fore (i, 0, cnt) {
		if (a[i] >= b[sz(b) - cnt + i])
			return false;
	}
	return true;
}

inline void solve() {
	vector<int> nb;
	fore (i, 1, 2 * n + 1) {
		if (!binary_search(b.begin(), b.end(), i))
			nb.push_back(i);
	}
	
	int mx[2] = {-1, -1};
	fore (k, 0, 2) {
		int lf = 0, rg = n + 1;
		while (rg - lf > 1) {
			int mid = (lf + rg) / 2;
			if (ok(b, nb, mid))
				lf = mid;
			else
				rg = mid;
		}
		mx[k] = lf;
		if (!ok(nb, b, n - lf)) {
			cout << 0 << endl;
			return;
		}
		swap(b, nb);
	}
	
	assert(n - mx[1] <= mx[0]);
	cout << mx[0] - (n - mx[1]) + 1 << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int t; cin >> t;
	while(t--) {
	    read();
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

const int INF = int(1e9);

int n;
vector<int> b;

inline bool read() {
	if(!(cin >> n))
		return false;
	b.resize(n);
	fore (i, 0, n)
		cin >> b[i];
	return true;
}

int getMax(const vector<int> &a, const vector<int> &b) {
	int uk = 0;
	fore (i, 0, sz(a)) {
		while (uk < sz(b) && b[uk] < a[i])
			uk++;
		if (uk >= sz(b))
			return i;
		uk++;
	}
	return sz(a);
}

inline void solve() {
	vector<int> nb;
	fore (i, 1, 2 * n + 1) {
		if (!binary_search(b.begin(), b.end(), i))
			nb.push_back(i);
	}
	
	int mxX = getMax(b, nb);
	int mnX = n - getMax(nb, b);
	
	cout << mxX - mnX + 1 << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int t; cin >> t;
	while(t--) {
	    read();
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
[1463E - Plan of Lectures](../problems/E._Plan_of_Lectures.md "Educational Codeforces Round 100 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1463E - Plan of Lectures](../problems/E._Plan_of_Lectures.md "Educational Codeforces Round 100 (Rated for Div. 2)")

The prerequisites for each lecture form a rooted tree, so let's forget about the legend and learn how to find such an order of vertices of a tree that all conditions work.

Let's introduce some algorithm that produces an ordering of vertices for every possible case. If any valid ordering exists, it should produce a valid one. So we will only have to check if the resulting ordering is fine and output it if it is.

If there were no special pairs, the task would be perfectly solvable with an algorithm of topological sorting. Thus, let's come up with a way to modify the graph, so that topsort could still be a solution.

We know that the vertices that are in the special pairs should follow each other in the ordering. Look at these special pairs as edges as well. Let's first imagine they are undirected. These edges connect some vertices in the tree into components. Each component should be a segment of vertices in a valid answer. So how about we compress them into one vertex first each, find some answer for a compressed version and decompress them back?

Let each of these connected components be a vertex in the new graph. Two components are connected by an edge if there is a edge in the tree between vertices of the corresponding components. Topsort in this graph will tell us the order the components should go.

However, we should also find the order the vertices should go inside each component. Let's topsort the graph of all directed special pairs and sort the vertices in that order in every component. We can sort the entire graph instead of sorting each component separately because the components are totally independent. 

Finally, write down the answer: iterate over the compressed vertices of the first new graph in the order of its topsort, for each one write down all the actual vertices inside it in the order of the topsort of the second new graph. Check if each vertex has its parent earlier than itself in the answer. If all the graphs were topologically sortable and that holds, then the answer exists, and we found it. Otherwise, the answer doesn't exist.

Overall complexity: $O(n \log n)$.

 **Solution (pikmike)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

vector<vector<int>> g, h, ng;

vector<int> rk, p;

int getp(int a){
	return a == p[a] ? a : p[a] = getp(p[a]);
}

void unite(int a, int b){
	a = getp(a), b = getp(b);
	if (a == b) return;
	if (rk[a] < rk[b]) swap(a, b);
	rk[a] += rk[b];
	p[b] = a;
}

vector<vector<int>> comp;

vector<int> ord;
vector<int> used;
bool fl;

void ts(int v, const vector<vector<int>> &g){
	used[v] = 1;
	for (int u : g[v]){
		if (used[u] == 0)
			ts(u, g);
		else if (used[u] == 1)
			fl = false;
		if (!fl) return;
	}
	ord.push_back(v);
	used[v] = 2;
}

bool topsort(const vector<vector<int>> &g){
	int n = g.size();
	used.assign(n, 0);
	ord.clear();
	fl = true;
	forn(i, n) if (!used[i]){
		ts(i, g);
		if (!fl) return false;
	}
	reverse(ord.begin(), ord.end());
	return true;
}

vector<int> pos;

bool dfs(int v){
	for (int u : g[v]){
		if (pos[u] < pos[v])
			return false;
		if (!dfs(u))
			return false;
	}
	return true;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	g.resize(n);
	h.resize(n);
	ng.resize(n);
	int rt = -1;
	forn(i, n){
		int p;
		scanf("%d", &p);
		--p;
		if (p == -1)
			rt = i;
		else
			g[p].push_back(i);
	}
	rk.assign(n, 1);
	p.resize(n);
	iota(p.begin(), p.end(), 0);
	forn(i, m){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		h[v].push_back(u);
		unite(v, u);
	}
	if (!topsort(h)){
		puts("0");
		return 0;
	}
	auto ord1 = ord;
	vector<int> pos1(n);
	forn(i, n) pos1[ord1[i]] = i;
	forn(v, n) for (int u : g[v]) if (getp(v) != getp(u))
		ng[getp(v)].push_back(getp(u));
	if (!topsort(ng)){
		puts("0");
		return 0;
	}
	comp.resize(n);
	forn(i, n) comp[getp(i)].push_back(i);
	vector<int> fin;
	for (int it : ord){
		sort(comp[it].begin(), comp[it].end(), [&](int v, int u){ return pos1[v] < pos1[u]; });
		for (int v : comp[it])
			fin.push_back(v);
	}
	pos.resize(n);
	forn(i, n) pos[fin[i]] = i;
	if (!dfs(rt)){
		puts("0");
		return 0;
	}
	for (int v : fin)
		printf("%d ", v + 1);
	puts("");
}
```
[1463F - Max Correct Set](../problems/F._Max_Correct_Set.md "Educational Codeforces Round 100 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1463F - Max Correct Set](../problems/F._Max_Correct_Set.md "Educational Codeforces Round 100 (Rated for Div. 2)")

The key idea of the task is to prove that there is an optimal answer where the chosen elements in $S$ has a period equal to $p = x + y$. Let's work with $0, 1, \dots, n - 1$ instead of $1, 2, \dots, n$.

Firstly, let's prove that if we've chosen correct set $a_1, \dots, a_k$ in interval $[l, l + p)$ then if we take all $a_i + p$ then set $\{ a_1, \dots, a_k, a_1 + p, \dots a_k + p \}$ will be corect as well. By contradiction: suppose we have $a_i + p - a_j = x$ ($y$), then $a_i - a_j = x - p = x - x - y = -y$ ($-x$) or $|a_i - a_j| = y$ ($x$) — contradiction.

It means that if we take the correct set in interval $[l, l + p)$ we can create a periodic answer by copying this interval several times.

Next, let's prove that there is an optimal periodic answer. Let's look at any optimal answer and its indicator vector (binary vector of length $n$ where $id_i = 1$ iff $i$ is in the set). Let $r = n \bmod p$.

Let's split the vector in $2 \left\lfloor \frac{n}{p} \right\rfloor + 1$ intervals: $[0, r), [r, p), [p, p + r), [p + r, 2p), \dots, [n - r, n)$. The $1$-st, $3$-rd, $5$-th... segments have length $r$ and $2$-nd, $4$-th,... segments have length $p - r$. If we choose any two consecutive segments its total length will be equal to $p$ and we can use it to make periodic answer by replacing all length $r$ segments with the chosen one and $p - r$ segments with the other one.

We can prove that we can always find such two consecutive segments that the induced answer will be greater or equal to the initial one. If we create vector where $v_i$ is equal to the sum of $id_j$ in the $i$-th segment, then the task is equivalent to finding $v_i$ and $v_{i + 1}$ such that replacing all $v_{i \pm 2z}$ by $v_i$ and all $v_{i + 1 \pm 2z}$ by $v_{i + 1}$ won't decrease array $v$ sum. The proof is down below.

Now, since the answer is periodical, taking element $c$ ($0 \le c < p$) is equivalent to taking all elements $d \equiv c \bmod p$, so for each $c$ we can calc $val_c$ — the number of integers with the same remainder. And for each $c$ we either take it or not.

So we can write $dp[p][2^{\max(x, y)}]$, where $dp[i][msk]$ is the maximum sum if we processed $i$ elements and last $\max(x, y)$ elements are described by mask $msk$. We start with $dp[0][0]$ and, when look at the $i$-th element, either take it (if we can) or skip it.

Time complexity is $O((x + y) 2^{\max(x, y)})$.

==========

Let's prove that for any array $v_1, v_2, \dots, v_{2n + 1}$ we can find pair $v_p, v_{p + 1}$ such that replacing all $v_{p \pm 2z}$ with $v_p$ and all $v_{p + 1 \pm 2z}$ with $v_{p + 1}$ won't decrease the total sum.

Let's define $S_o = \sum\limits_{i = 1}^{n + 1}{v_{2i - 1}}$ and $S_e = \sum\limits_{i = 1}^{n}{v_{2i}}$. Let's make array $b_1, \dots, b_{2n + 1}$, where $b_{2i - 1} = (n + 1)v_{2i - 1} - S_o$ and $b_{2i} = n \cdot v_{2i} - S_e$. The meaning behind $b_i$ is how changes the total sum if we replace corresponding elements by $v_i$.

Note, that finding a good pair $v_p, v_{p + 1}$ is equivalent to finding $b_p + b_{p + 1} \ge 0$. Also, note that $\sum\limits_{i = 1}^{n + 1}{b_{2i - 1}} = (n + 1)S_o - (n + 1)S_o = 0$ and analogically, $\sum\limits_{i = 1}^{n}{b_{2i}} = n \cdot S_e - n \cdot S_e = 0$.

Let's prove by contradiction: suppose that for any $i$ $b_i + b_{i + 1} < 0$. Let's look at $\sum\limits_{i = 1}^{2n + 1}{b_i} = \sum\limits_{i = 1}^{n + 1}{b_{2i - 1}} + \sum\limits_{i = 1}^{n}{b_{2i}} = 0$. But from the other side, we know that $b_2 + b_3 < 0$, $b_4 + b_5 < 0$, ..., $b_{2n} + b_{2n + 1} < 0$, so $b_1 > 0$, otherwise $\sum\limits_{i = 1}^{2n + 1}{b_i}$ will be negative.

In the same way, since $b_1 + b_2 < 0$, $b_4 + b_5 < 0$, ..., $b_{2n} + b_{2n + 1} < 0$, then $b_3 > 0$. Analogically we can prove that each $b_{2i - 1} > 0$, but $\sum\limits_{i = 1}^{n + 1}{b_{2i - 1}} = 0$ — contradiction. So, there is always a pair $b_p + b_{p + 1} \ge 0$, i. e. a pair $v_p, v_{p + 1}$. 

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 22;

int dp[2][1 << N];
int val[2 * N];

int main() {
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	
	int k = x + y;
	int m = max(x, y);
	int FULL = (1 << m) - 1;
	
	for (int i = 0; i < k; ++i)
		val[i] = n / k + (i < n % k);
	for (int mask = 0; mask < (1 << m); ++mask)
		dp[0][mask] = -INF;
	dp[0][0] = 0;
	
	for (int i = 0; i < k; ++i) {
		for (int mask = 0; mask < (1 << m); ++mask)
			dp[1][mask] = -INF;
		for (int mask = 0; mask < (1 << m); ++mask) {
			if (dp[0][mask] == -INF)
				continue;
			int nmask = (mask << 1) & FULL;
			dp[1][nmask] = max(dp[1][nmask], dp[0][mask]);
			if (((mask >> (x - 1)) & 1) | ((mask >> (y - 1)) & 1))
				continue;
			nmask |= 1;
			dp[1][nmask] = max(dp[1][nmask], dp[0][mask] + val[i]);
		}
		swap(dp[0], dp[1]);
	}
	
	int ans = 0;
	for (int mask = 0; mask < (1 << m); ++mask) 
		ans = max(ans, dp[0][mask]);
	printf("%dn", ans);
}
```
