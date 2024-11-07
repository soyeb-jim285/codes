# Tutorial

[1473A - Replacing Elements](../problems/A._Replacing_Elements.md "Educational Codeforces Round 102 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1473A - Replacing Elements](../problems/A._Replacing_Elements.md "Educational Codeforces Round 102 (Rated for Div. 2)")

Let's note that since all ai are positive, any ai+aj>max(ai,aj). It means that we can't make the first and second minimums lower than they already are: suppose the first and second minimums are mn1 and mn2, if we choose any other element to replace, we can't make it less than mn1+mn2 and if we choose to replace mn1 or mn2 we will only make them bigger.

As a result, it means that we can choose for each element either not to change it or make it equal to mn1+mn2. So, to be able to make all elements ≤d we need just check that either mn1+mn2≤d or maximum ai≤d.

We can do it, for example, by sorting our array a in increasing order and checking that either a1+a2≤d or an≤d.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    cout << (a.back() <= d || a[0] + a[1] <= d ? "YES" : "NO") << endl;
  }
}
```
[1473B - String LCM](../problems/B._String_LCM.md "Educational Codeforces Round 102 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1473B - String LCM](../problems/B._String_LCM.md "Educational Codeforces Round 102 (Rated for Div. 2)")

We should notice that if some string x is a multiple of string y, then |x| is a multiple of |y|. This fact leads us to the conclusion that |LCM(s,t)| should be a common multiple of |s| and |t|. Since we want to minimize the length of the string LCM(s,t), then its length is LCM(|s|,|t|).

So we have to check that LCM(|s|,|t|)|s| copies of the string s equal to LCM(|s|,|t|)|t| copies of the string t. If such strings are equal, print them, otherwise, there is no solution.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  auto mul = [](string s, int k) -> string {
    string res = "";
    while (k--) res += s;
    return res;
  };
  
  int tc;
  cin >> tc;
  while (tc--) {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    int g = __gcd(n, m);
    if (mul(s, m / g) == mul(t, n / g))
      cout << mul(s, m / g) << endl;
    else
      cout << "-1" << endl;
  }
}
```
[1473C - No More Inversions](../problems/C._No_More_Inversions.md "Educational Codeforces Round 102 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1473C - No More Inversions](../problems/C._No_More_Inversions.md "Educational Codeforces Round 102 (Rated for Div. 2)")

At first, let's look at sequence s: s1,s2,…,sp−1,sp,sp−1,…s2,s1. Let's prove that the number of inversions in s is the same regardless of what si are (the only condition is that si should be distinct).

Let's group all elements si by their value — there will be 1 or 2 elements in each group. Then we can take any two groups with values x and y and calculate the number of inversions between elements in these groups. It's easy to note that construction will always be like …x,…,y,…,y,…,x… (or …x,…,y,…,x…) and regardless of x>y or x<y in both cases there will be exactly two inversions between groups equal to x and to y (or one inversion in the second case). So the total number of inversion will be equal to 2(p−1)(p−2)2+(p−1)=(p−1)2.

Now we can split sequences a and b into two parts. Let m=n−k, then the first part is elements from segment [1,k−m−1] and the second is from [k−m,k+m]. Note that the second parts both in a and b are exactly the sequence s described above.

The total number of inversions is equal to the sum of inversions in the first part, in the second part, and the inversions with elements from both parts. Note that in a the first and the third components are equal to 0 and the second component is constant, so in b we must also have 0 inversions in the first part and 0 inversion between parts.

It means that b must start from 1,2,…,(k−m−1). But since the number of inversions in the second part is constant we can set the remaining elements the way we want. And since we want to build lexicographically maximum b, we should make the second part as k,k−1,…,(k−m+1),(k−m),(k−m+1),…,k.

In the end, optimal b is 1,2,…,(k−m−1),k,(k−1),…,(k−m+1),(k−m),(k−m+1),…,k. The permutation p to make such b is equal to 1,2,…,(k−m−1),k,(k−1),…,(k−m).

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }

        for (i in 1 until (k - (n - k)))
            print("$i ")
        for (i in k downTo (k - (n - k)))
            print("$i ")
        println("")
    }
}
```
[1473D - Program](../problems/D._Program.md "Educational Codeforces Round 102 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1473D - Program](../problems/D._Program.md "Educational Codeforces Round 102 (Rated for Div. 2)")

The value of x always changes by 1, thus, the set of values of x is always some contiguous segment. The length of such segment can be determined by just its minimum and maximum values.

So we have to solve two separate tasks for each query: find the minimum and the maximum value x gets assigned to. I'll describe only the minimum one.

This task, however, can as well be split into two parts: minimum value on a prefix before l and on a suffix after r. The prefix is easy — it doesn't get changed by a query, so it can be precalculated beforehand. Minimum value on a prefix of length i is minimum of a minimum value on a prefix of length i−1 and the current value.

The suffix minimum is not that trivial. First, in order to precalculate the minimum value on a suffix of length i, we have to learn to prepend an instruction to the suffix of length i+1. Consider the graph of values of x over time. What happens to it if the initial value of x is not 0 but 1, for example? It just gets shifted by 1 upwards. That move is actually the same as prepending a '+' instruction. So the minimum value for a suffix of length i is a minimum of a minimum value for a suffix of length i−1, increased by the current instruction, and 0 (the start of the graph).

So now we have a minimum value on a suffix after r. However, it can't be taken into the answer as it is, because it considers the graph for the suffix to be starting from 0. And that's not the case. The graph for the suffix starts from the value the prefix ends on. So we can shift the answer for the suffix by the value of x after the prefix. The overall minimum value is just the minimum on a prefix and on a suffix, then.

Overall complexity: O(n+m) per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	forn(_, t){
		int n, m;
		string s;
		cin >> n >> m;
		cin >> s;
		vector<int> sul(1, 0), sur(1, 0);
		for (int i = n - 1; i >= 0; --i){
			int d = s[i] == '+' ? 1 : -1;
			sul.push_back(min(0, sul.back() + d));
			sur.push_back(max(0, sur.back() + d));
		}
		reverse(sul.begin(), sul.end());
		reverse(sur.begin(), sur.end());
		vector<int> prl(1, 0), prr(1, 0), pr(1, 0);
		forn(i, n){
			int d = s[i] == '+' ? 1 : -1;
			pr.push_back(pr.back() + d);
			prl.push_back(min(prl.back(), pr.back()));
			prr.push_back(max(prr.back(), pr.back()));
		}
		forn(i, m){
			int l, r;
			cin >> l >> r;
			--l;
			int l1 = prl[l], r1 = prr[l];
			int l2 = sul[r] + pr[l], r2 = sur[r] + pr[l];
			printf("%dn", max(r1, r2) - min(l1, l2) + 1);
		}
	}
	return 0;
}
```
[1473E - Minimum Path](../problems/E._Minimum_Path.md "Educational Codeforces Round 102 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1473E - Minimum Path](../problems/E._Minimum_Path.md "Educational Codeforces Round 102 (Rated for Div. 2)")

Let's consider a problem where you can subtract the weight of any edge (not only the maximum one) that belong to the current path and similarly add the weight of any edge (not only the minimum one) that belong to the current path.

To solve that problem we can build a new graph where the node can be represented as the following triple (node from the initial graph, flag that some edge has been subtracted, flag that some edge has been added). Now we can run Dijkstra's algorithm to find the length of the shortest paths in such a graph.

We can notice that on the shortest path, the maximum weight edge was subtracted and the minimum weight edge was added. Let's assume that this is not the case, and an edge of non-maximum weight was subtracted from the path, then we can reduce the length of the path by choosing an edge of maximum weight. But this is not possible, because we considered the shortest path. Similarly, it is proved that the added edge was of minimal weight.

Using this fact, it is not difficult to notice that by solving the modified problem, we have solved the original one.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 13;

int n, m;
vector<pair<int, int>> g[N];
long long d[N][2][2];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    --v; --u;
    g[v].emplace_back(u, w);
    g[u].emplace_back(v, w);
  }
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        d[i][j][k] = (long long)1e18;

  d[0][0][0] = 0;
  set<pair<long long, array<int, 3>>> q;
  q.insert({0, {0, 0, 0}});

  while (!q.empty()) {
    auto [v, mx, mn] = q.begin()->second;
    q.erase(q.begin());
    for (auto [u, w] : g[v]) {
      for (int i = 0; i <= 1 - mx; i++) {
        for (int j = 0; j <= 1 - mn; j++) {
          if (d[u][mx | i][mn | j] > d[v][mx][mn] + (1 - i + j) * w) {
            auto it = q.find({d[u][mx | i][mn | j], {u, mx | i, mn | j}});
            if (it != q.end())
              q.erase(it);
            d[u][mx | i][mn | j] = d[v][mx][mn] + (1 - i + j) * w;
            q.insert({d[u][mx | i][mn | j], {u, mx | i, mn | j}});
          }
        }
      }
    }
  }

  for (int i = 1; i < n; i++) {
    printf("%lld ", d[i][1][1]);
  }
  puts("");
}
```
[1473F - Strange Set](../problems/F._Strange_Set.md "Educational Codeforces Round 102 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1473F - Strange Set](../problems/F._Strange_Set.md "Educational Codeforces Round 102 (Rated for Div. 2)")

We will model the problem as the minimum cut in a flow network.

Build a network as follows: create a source node $s$, a sink node $t$, and a vertex for every number from $1$ to $n$. Let's say that we are going to find the minimum $s$-$t$ cut in this network, and the vertices belonging to the same cut part with $s$ represent the numbers that are taken into the answer.

Using the edges of the network, we should model these constraints:

1. taking an element $i$ that depends on another element $j$ should force us to take $j$ as well;
2. taking an element $i$ with $b_i > 0$ should add $b_i$ to our score;
3. taking an element $i$ with $b_i < 0$ should subtract $|b_i|$ from our score.

Constraint $1$ can be modeled in the following way: for every pair $(i, j)$ such that element $i$ depends on element $j$ ($i > j$ and $a_i \bmod a_j = 0$), add a directed edge with infinite capacity from $i$ to $j$. That way, if $i$ is taken and $j$ is not, the value of the cut will be infinite because of this edge, and this cut cannot be minimum.

Constraint $2$ is modeled in the following way: for every $i$ such that $b_i > 0$, add a directed edge with capacity $b_i$ from $s$ to $i$. That way, if we don't take some element $i$ with $b_i > 0$ into the answer, $b_i$ is added to the value of the cut.

And for constraint $3$, for every $i$ such that $b_i < 0$, add a directed edge with capacity $|b_i|$ from $i$ to $t$. That way, if we take some element $i$ with $b_i < 0$, $|b_i|$ is added to the value of the cut.

It's now easy to see that the answer is $\sum\limits_{i = 1}^{n} \max(b_i, 0) - mincut$, since it is exactly the sum of elements that were taken (for positive elements, we add them all up and then subtract the ones that don't belong to the answer; for negative ones, we just subtract those which belong to the answer). To find a minimum cut, just run maximum flow in this network.

There's one caveat though. If, for example, all $a_i$ are equal (or many $a_i$ are divisible by many other values in $a$), this network can contain $O(n^2)$ edges. To reduce the number of edges, let's see that if for some index $i$ there exist two equal divisors of $a_i$ to the left of it (let's say that these divisors are $j$ and $k$: $j < k < i$; $a_i \bmod a_j = 0$; $a_j = a_k$), then we only need to add an edge from $i$ to $k$, because taking $k$ also should force taking $j$ into the answer. So, for every divisor of $a_i$, we are interested in only one closest occurrence of this divisor to the left, and we need to add a directed edge only to this occurrence, and ignore all other occurrences. That way, for every vertex $i$, we add at most $D(a_i)$ edges to other vertices (where $D(a_i)$ is the number of divisors of $a_i$).

It can be proven that any maximum flow algorithm that relies on augmenting paths will finish after $O(V)$ iterations in this network, so it won't work longer than $O(VE)$, and both $V$ and $E$ are proportional to $n$, so any maximum flow solution will run in $O(n^2)$.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

template<typename T>
struct dinic {
    struct edge {
        int u, rev;
        T cap, flow;
    };
    
    int n, s, t;
    T flow;
    vector<int> lst;
    vector<int> d;
    vector<vector<edge>> g;
    
    T scaling_lim;
    bool scaling;
    
    dinic() {}
    
    dinic(int n, int s, int t, bool scaling = false) : n(n), s(s), t(t), scaling(scaling) {
        g.resize(n);
        d.resize(n);
        lst.resize(n);
        flow = 0;
    }

    void add_edge(int v, int u, T cap, bool directed = true) {
        g[v].push_back({u, g[u].size(), cap, 0});
        g[u].push_back({v, int(g[v].size()) - 1, directed ? 0 : cap, 0});
    }

    T dfs(int v, T flow) {
        if (v == t)
            return flow;
        if (flow == 0)
            return 0;
        T result = 0;
        for (; lst[v] < g[v].size(); ++lst[v]) {
            edge& e = g[v][lst[v]];
            if (d[e.u] != d[v] + 1)
                continue;
            T add = dfs(e.u, min(flow, e.cap - e.flow));
            if (add > 0) {
                result += add;
                flow -= add;
                e.flow += add;
                g[e.u][e.rev].flow -= add;
            }
            if (flow == 0)
                break;
        }
        return result;
    }

    bool bfs() {
        fill(d.begin(), d.end(), -1);
        queue<int> q({s});
        d[s] = 0;
        while (!q.empty() && d[t] == -1) {
            int v = q.front(); q.pop();
            for (auto& e : g[v]) {
                if (d[e.u] == -1 && e.cap - e.flow >= scaling_lim) {
                    q.push(e.u);
                    d[e.u] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    T calc() {
        T max_lim = numeric_limits<T>::max() / 2 + 1;
        for (scaling_lim = scaling ? max_lim : 1; scaling_lim > 0; scaling_lim >>= 1) {
            while (bfs()) {
                fill(lst.begin(), lst.end(), 0);
                T add;
                while((add = dfs(s, numeric_limits<T>::max())) > 0)
                flow += add;
            }
        }   
        return flow;
    }
    
    vector<bool> min_cut() {
        vector<bool> res(n);
        for(int i = 0; i < n; i++) 
            res[i] = (d[i] != -1);
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    int s = n;
    int t = n + 1;
    dinic<int> d(n + 2, s, t, true);
    vector<int> last(101, -1);
    for(int i = 0; i < n; i++){
        if(b[i] > 0)
            d.add_edge(s, i, b[i]);
        if(b[i] < 0)
            d.add_edge(i, t, -b[i]);
        for(int k = 1; k <= 100; k++)
            if(last[k] != -1 && a[i] % k == 0)
                d.add_edge(i, last[k], int(1e9));
        last[a[i]] = i;    
    }   
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += max(0, b[i]);
    cout << sum - d.calc() << endl;
}
```
[1473G - Tiles](../problems/G._Tiles.md "Educational Codeforces Round 102 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1473G - Tiles](../problems/G._Tiles.md "Educational Codeforces Round 102 (Rated for Div. 2)")

The group of the rows where the number of rectangular tiles increases $a$ times and then decreases $b$ times can be represented as a rectangular table, with $a+b+1$ diagonals, where the size of the first diagonal is equal to the number of rectangular tiles before the operations are applied (let their number be $m$), and the size of the last diagonal is $m+a-b$. 

In such a rectangular table, one can move from the cell $(i, j)$ to the cells $(i+1, j)$ and $(i, j+1)$ (if they exist), which lie on the next diagonal (next row in terms of the original problem). It's a well-known fact that the number of different paths from one cell to another is some binomial coefficient.

Let's define $ans_{i,j}$ as the number of paths from the $1$-st row to the $j$-th tile in the ($\sum\limits_{k=1}^{i} (a_i+b_i)$)-th row (i.e. row after the $i$-th group of operations).

Now we want to find the values of $ans_{i}$ using the values of $ans_{i-1}$ (let its size be $m$). Using the fact described in the first paragraphs we know that $ans_{i, j}$ depends on $ans_{i-1, k}$ with some binomial coefficient. In fact $ans_{i, j} = \sum\limits_{k=1}^{m} \binom{a_i+b_i}{b_i-k+j} ans_{i-1,k}$ for $1 \le j \le m + a_i - b_i$. But this solution is too slow. To speed up this solution we have to notice that the given formula is a convolution of $ans_{i-1}$ and some binomial coefficients. So we can use NTT to multiply them in $O(n\log n)$ instead of $O(n^2)$ time.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)
#define sz(a) int((a).size())

template<const int &MOD>
struct _m_int {
  int val;
 
  _m_int(int64_t v = 0) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    val = int(v);
  }
 
  _m_int(uint64_t v) {
    if (v >= MOD) v %= MOD;
    val = int(v);
  }
 
  _m_int(int v) : _m_int(int64_t(v)) {}
  _m_int(unsigned v) : _m_int(uint64_t(v)) {}
 
  static int inv_mod(int a, int m = MOD) {
    int g = m, r = a, x = 0, y = 1;
 
    while (r != 0) {
      int q = g / r;
      g %= r; swap(g, r);
      x -= q * y; swap(x, y);
    }
 
    return x < 0 ? x + m : x;
  }
 
  explicit operator int() const { return val; }
  explicit operator unsigned() const { return val; }
  explicit operator int64_t() const { return val; }
  explicit operator uint64_t() const { return val; }
  explicit operator double() const { return val; }
  explicit operator long double() const { return val; }
 
  _m_int& operator+=(const _m_int &other) {
    val -= MOD - other.val;
    if (val < 0) val += MOD;
    return *this;
  }
 
  _m_int& operator-=(const _m_int &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }
 
  static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
    return unsigned(x % m);
#endif
    // Optimized mod for Codeforces 32-bit machines.
    // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
    unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
    unsigned quot, rem;
    asm("divl %4n"
      : "=a" (quot), "=d" (rem)
      : "d" (x_high), "a" (x_low), "r" (m));
    return rem;
  }
 
  _m_int& operator*=(const _m_int &other) {
    val = fast_mod(uint64_t(val) * other.val);
    return *this;
  }
 
  _m_int& operator/=(const _m_int &other) {
    return *this *= other.inv();
  }
 
  friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
  friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
  friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
  friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }
 
  _m_int& operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
 
  _m_int& operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
 
  _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
  _m_int operator--(int) { _m_int before = *this; --*this; return before; }
 
  _m_int operator-() const {
    return val == 0 ? 0 : MOD - val;
  }
 
  friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
  friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
  friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
  friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
  friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
  friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }
 
  _m_int inv() const {
    return inv_mod(val);
  }
 
  _m_int pow(int64_t p) const {
    if (p < 0)
      return inv().pow(-p);
 
    _m_int a = *this, result = 1;
 
    while (p > 0) {
      if (p & 1)
        result *= a;
      a *= a;
      p >>= 1;
    }
 
    return result;
  }
  
  friend string to_string(_m_int<MOD> x) {
    return to_string(x.val);
  }
 
  friend ostream& operator<<(ostream &os, const _m_int &m) {
    return os << m.val;
  }
};

extern const int MOD = 998244353;
using Mint = _m_int<MOD>;

const int g = 3;
const int LOGN = 15;

vector<Mint> w[LOGN];
vector<int> rv[LOGN];

void prepare() {
  Mint wb = Mint(g).pow((MOD - 1) / (1 << LOGN));
  forn(st, LOGN - 1) {
    w[st].assign(1 << st, 1);
    Mint bw = wb.pow(1 << (LOGN - st - 1));
    Mint cw = 1;
    forn(k, 1 << st) {
      w[st][k] = cw;
      cw *= bw;
    }
  }
  forn(st, LOGN) {
    rv[st].assign(1 << st, 0);
    if (st == 0) {
      rv[st][0] = 0;
      continue;
    }
    int h = (1 << (st - 1));
    forn(k, 1 << st)
      rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
  }
}

void ntt(vector<Mint> &a, bool inv) {
  int n = sz(a);
  int ln = __builtin_ctz(n);
  forn(i, n) {
    int ni = rv[ln][i];
    if (i < ni) swap(a[i], a[ni]);
  }
  forn(st, ln) {
    int len = 1 << st;
    for (int k = 0; k < n; k += (len << 1)) {
      fore(pos, k, k + len){
        Mint l = a[pos];
        Mint r = a[pos + len] * w[st][pos - k];
        a[pos] = l + r;
        a[pos + len] = l - r;
      }
    }
  }
  if (inv) {
    Mint rn = Mint(n).inv();
    forn(i, n) a[i] *= rn;
    reverse(a.begin() + 1, a.end());
  }
}

vector<Mint> mul(vector<Mint> a, vector<Mint> b) {
  int cnt = 1 << (32 - __builtin_clz(sz(a) + sz(b) - 1));
  a.resize(cnt);
  b.resize(cnt);
  ntt(a, false);
  ntt(b, false);
  vector<Mint> c(cnt);
  forn(i, cnt) c[i] = a[i] * b[i];
  ntt(c, true);
  return c;
}

int main() {
  prepare();
  
  vector<Mint> fact(1, 1), ifact(1, 1);
  auto C = [&](int n, int k) -> Mint {
    if (k < 0 || k > n) return 0;
    while (sz(fact) <= n) {
      fact.push_back(fact.back() * sz(fact));
      ifact.push_back(fact.back().inv());
    }
    return fact[n] * ifact[k] * ifact[n - k];
  };
  
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  forn(i, n) cin >> a[i] >> b[i];
  
  vector<Mint> ans(1, 1);
  forn(i, n) {
    vector<Mint> Cs;
    for (int j = b[i] - sz(ans) + 1; j < sz(ans) + a[i]; ++j)
      Cs.push_back(C(a[i] + b[i], j));
    auto res = mul(ans, Cs);
    int cnt = sz(ans);
    ans.resize(cnt + a[i] - b[i]);
    forn(j, sz(ans)) ans[j] = res[cnt + j - 1];
  }
  
  cout << accumulate(ans.begin(), ans.end(), Mint(0)) << endl;
}
```
