# Tutorial

[1657A - Integer Moves](../problems/A._Integer_Moves.md "Educational Codeforces Round 125 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1657A - Integer Moves](../problems/A._Integer_Moves.md "Educational Codeforces Round 125 (Rated for Div. 2)")

Note that the answer does not exceed $2$, because the chip can be moved as follows: $(0, 0) \rightarrow (x, 0) \rightarrow (x, y)$. Obviously, in this case, both operation are valid. It remains to check the cases when the answer is $0$ or $1$. The answer is $0$ only if the destination point is $(0, 0)$, and the answer is $1$ if $\sqrt{x^2+y^2}$ is integer.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    int d = x * x + y * y;
    int r = 0;
    while (r * r < d) ++r;
    int ans = 2;
    if (r * r == d) ans = 1;
    if (x == 0 && y == 0) ans = 0; 
    cout << ans << 'n';
  }
}
```
[1657B - XY Sequence](../problems/B._XY_Sequence.md "Educational Codeforces Round 125 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1657B - XY Sequence](../problems/B._XY_Sequence.md "Educational Codeforces Round 125 (Rated for Div. 2)")

Strategy is quite easy: we go from $a_1$ to $a_n$ and if $a_{i - 1} + x \le B$ we take this variant (we set $a_i = a_{i - 1} + x$); otherwise we set $a_i = a_{i - 1} - y$. Note that all $a_i$ are in range $[-(x + y), B]$ so there won't be any overflow/underflow.

It's also not hard to prove that this strategy maximizes the sum. By contradiction: suppose the optimal answer has some index $i$ where $a_{i - 1} + x \le B$ but $a_i = a_{i - 1} - y$. Let's find first position $j \ge i$ where $a_j = a_{j - 1} + x$ and swap operations between $i$ and $j$. As a result, $B \ge a_i > a_{i + 1} > \dots > a_{j}$, all $a_i$ from $[i, j - 1]$ were increased while $a_j$ remained the same, i. e. there is no violation of the rules and the total sum increased — contradiction.

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, B, x, y) = readLine()!!.split(' ').map { it.toInt() }
        var cur = 0L
        var ans = 0L
        for (i in 1..n) {
            cur += if (cur + x <= B) x else -y
            ans += cur
        }
        println(ans)
    }
}
```
[1657C - Bracket Sequence Deletion](../problems/C._Bracket_Sequence_Deletion.md "Educational Codeforces Round 125 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1657C - Bracket Sequence Deletion](../problems/C._Bracket_Sequence_Deletion.md "Educational Codeforces Round 125 (Rated for Div. 2)")

Consider the first character of the string. If it is '(', then we can remove the first two characters of the string and continue (because the prefix of length $2$ will be either a palindrome or a regular bracket sequence). If the first character of the string is ')' then this is a bad case. Of course, the regular bracket sequence can't start with '(', so this prefix should be a palindrome. And what is the shortest palindrome we can get with the first character ')'? It is the closing bracket ')', then some (possibly, zero) amount of opening brackets '(', and another one closing bracket. We can see that we can't find a palindrome shorter than this one because we have to find a pair for the first character. So, if the first character of the string is ')', then we just remove anything until the next character ')' inclusive. To not remove any characters explicitly, we can just use pointers instead. And the last thing is to carefully handle cases when we can't do any operations.

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int l = 0;
        int cnt = 0;
        while (l + 1 < n) {
            if (s[l] == '(' || (s[l] == ')' && s[l + 1] == ')')) {
                l += 2;
            } else {
                int r = l + 1;
                while (r < n && s[r] != ')') {
                    ++r;
                }
                if (r == n) {
                    break;
                }
                l = r + 1;
            }
            ++cnt;
        }
        cout << cnt << ' ' << n - l << 'n';
    }
    
    return 0;
}
```
[1657D - For Gamers. By Gamers.](../problems/D._For_Gamers._By_Gamers..md "Educational Codeforces Round 125 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1657D - For Gamers. By Gamers.](../problems/D._For_Gamers._By_Gamers..md "Educational Codeforces Round 125 (Rated for Div. 2)")

Imagine you are fighting the $j$-th monster, and you fixed the type of units $i$ and their amount $x$.

What's the win condition? $\frac{H_j}{d_i \cdot x} < \frac{h_i}{D_j}$. Rewrite it as $H_j \cdot D_j < d_i \cdot x \cdot h_i$. Notice how we only care about $d \cdot h$ for both the units and the monster, but not about $d$ and $h$ on their own.

Let's call $d \cdot h \cdot x$ and $D \cdot H$ the power of the squad and the monster.

You can see that for each cost $c$ we can only leave one unit type of that price that has the largest value of $d \cdot h$. Let's call it $\mathit{bst}_c$. 

Now let's learn to determine the maximum power we can obtain for cost exactly $c$. We can iterate over the cost $c$ of one unit and the count $x$ of units in the squad. Since $c \cdot x$ should not exceed $C$, that will take $\frac{C}{1} + \frac{C}{2} + \dots + \frac{C}{C} = O(C \log C)$. Propagate $\mathit{bst}_c$ to be the maximum power for cost exactly $c$.

We have the knowledge about cost exactly $c$, but we actually want no more than $c$. Calculate prefix maximums over $\mathit{bst}$ — that will be the maximum power we can obtain with no more than $c$ coins.

For each monster, we just have to find the smallest $c$ such that $\mathit{bst}_c > D \cdot H$. Since the array is monotone, we can use binary search.

Overall complexity: $O(n + (C + m) \log C)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

int main(){
	int n, C;
	scanf("%d%d", &n, &C);
	vector<long long> bst(C + 1);
	forn(i, n){
		int c, d, h;
		scanf("%d%d%d", &c, &d, &h);
		bst[c] = max(bst[c], d * 1ll * h);
	}
	for (int c = 1; c <= C; ++c) for (int xc = c; xc <= C; xc += c)
		bst[xc] = max(bst[xc], bst[c] * (xc / c));
	forn(c, C)
		bst[c + 1] = max(bst[c + 1], bst[c]);
	int m;
	scanf("%d", &m);
	forn(j, m){
		int D;
		long long H;
		scanf("%d%lld", &D, &H);
		int mn = upper_bound(bst.begin(), bst.end(), D * H) - bst.begin();
		if (mn > C) mn = -1;
		printf("%d ", mn);
	}
	puts("");
}
```
[1657E - Star MST](../problems/E._Star_MST.md "Educational Codeforces Round 125 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1657E - Star MST](../problems/E._Star_MST.md "Educational Codeforces Round 125 (Rated for Div. 2)")

Let the weight of the edge between the vertex $x$ to the vertex $y$ be $w_{x,y}$.

Suppose there exists a pair of vertices $x$ and $y$ (with indices greater than $2$) such that $w_{x,y} < w_{1,x}$ or $w_{x,y} < w_{1,y}$. Then, if we choose the spanning tree with all vertices connected to $1$, it won't be an MST: we can remove either the edge $(1,x)$ or the edge $(1,y)$, add the edge $(x,y)$ instead, and the cost of the spanning tree will decrease. So, we should have $w_{x,y} \ge \max(w_{1,x}, w_{1,y})$ for every pair $(x, y)$.

It can be shown that this condition is not only necessary, but sufficient as well: if for every pair $(x, y)$ the condition $w_{x,y} \ge \max(w_{1,x}, w_{1,y})$ holds, the MST can't have the weight less than $\sum \limits_{i=2}^{n} w_{1,i}$. We can prove this by induction (suppose that $w_{1,2} \le w_{1,3} \le \ldots \le w_{1,n}$ for simplicity):

* in the spanning tree, there should be at least one edge incident to vertex $n$, and its weight is at least $w_{1,n}$;
* there should be at least two edges incident to vertices $n$ and $n-1$, and their weights are at least $w_{1,n-1} + w_{1,n}$;
* ...;
* there should be at least $n-1$ edges incident to vertices from $2$ to $n$, and their weights are at least $\sum \limits_{i=2}^{n} w_{1,i}$.

Okay, now let's show how to calculate the number of such graphs. We can run the following dynamic programming: let $dp_{i,j}$ be the number of graphs where we have already connected $i$ vertices to the vertex $1$, and the maximum weight we have used is $j$. We start with $dp_{0,0}$, and for each transition from $dp_{i,j}$, we will iterate on the number of vertices we connect to the vertex $1$ with edges with weight $(j+1)$ (let the number of those vertices be $t$), choose them with a binomial coefficient $\frac{(n-1-i)!}{t!(n-1-i-t)!}$, and also choose the weights for the edges that connect one of the chosen vertices with one of the vertices already connected to $1$ (since for each of those edges, we know that their weights should be in $[j+1,k]$) — so, we need to multiply the value in transition by $(k-j)^e$, where $e$ is the number of such edges.

Implementing this dynamic programming can be done in $O(n^2k)$ or $O(n^2 k \log n)$, both are sufficient.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int MOD = 998244353;

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int mul(int a, int b){
	return a * 1ll * b % MOD;
}

int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	--n;
	vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
	vector<vector<int>> C(n + 1);
	forn(i, n + 1){
		C[i].resize(i + 1);
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
	}
	dp[0][0] = 1;
	forn(i, k) forn(t, n + 1) {
		int pw = binpow(k - i, t * (t - 1) / 2);
		int step = binpow(k - i, t);
		forn(j, n - t + 1){
			dp[i + 1][j + t] = add(dp[i + 1][j + t], mul(dp[i][j], mul(C[n - j][t], pw)));
			pw = mul(pw, step);
		}
	}
	printf("%dn", dp[k][n]);
}
```
[1657F - Words on Tree](../problems/F._Words_on_Tree.md "Educational Codeforces Round 125 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1657F - Words on Tree](../problems/F._Words_on_Tree.md "Educational Codeforces Round 125 (Rated for Div. 2)")

Let's design a naive solution first. For each of the given triples, we have two options: either write the string on the tree in the order from $x_i$ to $y_i$, or in reverse order. Some options conflict with each other. So, we can treat this problem as an instance of 2-SAT: create a variable for each of the given strings, which is true if the string is not reversed, and false if it is reversed; find all conflicting pairs of options and then run the usual algorithm for solving 2-SAT.

Unfortunately, the number of conflicting pairs can be up to $O(n^2)$, so we need to improve this solution. Let's introduce a variable for each vertex of the tree which will define the character we write on it. At first, it looks like we can't use these variables in 2-SAT, since the number of possible characters is $26$, not $2$. But if a vertex is covered by at least one path in a triple, then there are only two possible characters we can write in this vertex: either the character which will land on this position if we write the string from $x_i$ to $y_i$, or the character on the opposite position in the string $s_i$. And, obviously, if a vertex is not covered by any triple, we can write any character on it.

Okay, now for each vertex $i$, we have two options for a character: $c_{i,1}$ and $c_{i,2}$. Let the variable $p_i$ be true if we write $c_{i,1}$ on vertex $i$, and false if we write $c_{i,2}$. Also, for each triple $j$, let's introduce a variable $w_j$ which is true if the string $s_j$ is written from $x_j$ to $y_j$, and false if it is written in reversed order. If the vertex $i$ is the $k$-th one on the path from $x_j$ to $y_j$, then we should add the following constraints in our 2-SAT:

* if $s_{j,k} \ne c_{i,1}$, we need a constraint "NOT $p_i$ OR NOT $w_j$";
* if $s_{j,k} \ne c_{i,2}$, we need a constraint "$p_i$ OR NOT $w_j$";
* if $s_{j,|s_j|-k+1} \ne c_{i,1}$, we need a constraint "NOT $p_i$ OR $w_j$";
* if $s_{j,|s_j|-k+1} \ne c_{i,2}$, we need a constraint "$p_i$ OR $w_j$".

Thus, we add at most $16 \cdot 10^5$ constraints in our 2-SAT. The only thing we haven't discussed is how to actually restore each path from $x_j$ to $y_j$; this can be done either with any fast algorithm that finds LCA, or by searching for LCA "naively" by ascending from one of those vertices until we arrive at the ancestor of another vertex; this approach will visit at most $\sum \limits_{j=1}^{q} |s_j|$ vertices.

Overall, this solution runs in $O(n + q + \sum \limits_{j=1}^{q} |s_j|)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); ++i)
 
vector<vector<int>> t;
vector<int> p, h;
 
void init(int v){
	for (int u : t[v]) if (u != p[v]){
		p[u] = v;
		h[u] = h[v] + 1;
		init(u);
	}
}
 
vector<int> get_path(int v, int u){
	vector<int> l, r;
	while (v != u){
		if (h[v] > h[u]){
			l.push_back(v);
			v = p[v];
		}
		else{
			r.push_back(u);
			u = p[u];
		}
	}
	l.push_back(v);
	while (!r.empty()){
		l.push_back(r.back());
		r.pop_back();
	}
	return l;
}
 
vector<vector<int>> g, tg;
 
void add_edge(int v, bool vx, int u, bool vy){
	// (val[v] == vx) -> (val[u] == vy)
	g[v * 2 + vx].push_back(u * 2 + vy);
	tg[u * 2 + vy].push_back(v * 2 + vx);
	g[u * 2 + !vy].push_back(v * 2 + !vx);
	tg[v * 2 + !vx].push_back(u * 2 + !vy);
}
 
vector<int> ord;
vector<char> used;
 
void ts(int v){
	used[v] = true;
	for (int u : g[v]) if (!used[u])
		ts(u);
	ord.push_back(v);
}
 
vector<int> clr;
int k;
 
void dfs(int v){
	clr[v] = k;
	for (int u : tg[v]) if (clr[u] == -1)
		dfs(u);
}
 
int main(){
	cin.tie(0);
	iostream::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	t.resize(n);
	p.resize(n);
	h.resize(n);
	p[0] = -1;
	forn(i, n - 1){
		int v, u;
		cin >> v >> u;
		--v, --u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	init(0);
	
	vector<vector<int>> paths(m);
	vector<string> s(m);
	
	vector<pair<char, char>> opts(n, make_pair(-1, -1));
	forn(i, m){
		int v, u;
		cin >> v >> u >> s[i];
		--v, --u;
		paths[i] = get_path(v, u);
		int k = s[i].size();
		assert(int(paths[i].size()) == k);
		forn(j, k) opts[paths[i][j]] = {s[i][j], s[i][k - j - 1]};
	}
	
	int nm = (n + m) * 2;
	g.resize(nm);
	tg.resize(nm);
	forn(i, m){
		int k = s[i].size();
		forn(j, k){
			int v = paths[i][j];
			char c = s[i][j], rc = s[i][k - j - 1];
			char d = opts[v].first, rd = opts[v].second;
			if (d != c) add_edge(v, false, n + i, true);
			if (d != rc) add_edge(v, false, n + i, false);
			if (rd != c) add_edge(v, true, n + i, true);
			if (rd != rc) add_edge(v, true, n + i, false);
		}
	}
	
	used.resize(nm);
	forn(i, nm) if (!used[i]) ts(i);
	clr.resize(nm, -1);
	reverse(ord.begin(), ord.end());
	for (int v : ord) if (clr[v] == -1){
		dfs(v);
		++k;
	}
	forn(i, nm) if (clr[i] == clr[i ^ 1]){
		cout << "NOn";
		return 0;
	}
	
	cout << "YESn";
	for (int i = 0; i < 2 * n; i += 2){
		if (opts[i / 2].first == -1)
			cout << 'a';
		else if (clr[i] > clr[i ^ 1])
			cout << opts[i / 2].first;
		else
			cout << opts[i / 2].second;
	}
	cout << "n";
}
```
