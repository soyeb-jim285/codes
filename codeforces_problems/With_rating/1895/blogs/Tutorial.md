# Tutorial

[1895A - Treasure Chest](../problems/A._Treasure_Chest.md "Educational Codeforces Round 157 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1895A - Treasure Chest](../problems/A._Treasure_Chest.md "Educational Codeforces Round 157 (Rated for Div. 2)")

Let's consider two cases:

If y<x, then the answer is x, because we need to reach the chest and we can take the key on the way.

If y>x, then the optimal option would be to bring the chest directly to the key. However, this is not always possible due to the value of k. If y−x≤k, then we can do it and the answer is y. Otherwise, the answer is y+y−(x+d), where d is the time we carried the chest, and y−(x+d) is the time to return from the key to the chest back. From here, we can see that this value is minimum when d=k. Thus, the answer is y+y−(x+k).

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
    x, y, k = map(int, input().split())
    if y < x:
      print(x)
    else:
      print(y + max(0, y - x - k))
```
[1895B - Points and Minimum Distance](../problems/B._Points_and_Minimum_Distance.md "Educational Codeforces Round 157 (Rated for Div. 2)")

Idea: [fcspartakm](https://codeforces.com/profile/fcspartakm "Candidate Master fcspartakm")

 **Tutorial**
### [1895B - Points and Minimum Distance](../problems/B._Points_and_Minimum_Distance.md "Educational Codeforces Round 157 (Rated for Div. 2)")

Since the order of ai does not matter, let's sort them for convenience.

Let's treat the resulting path as two one-dimensional paths: one path x1→x2→⋯→xn and one path y1→y2→⋯→yn. The length of the path s is equal to the sum of lengths of these two paths.

If we fix which integers are x-coordinates and which integers are y-coordinates, it's quite easy to see that it is optimal to place both [x1,x2,…,xn] and [y1,y2,…,yn] in sorted order: the length of the path visiting both minxi and maxxi should be at least maxxi−minxi, and sorting gives exactly that result; the same with y-coordinates.

Okay, then, how do we choose which integers are x-coordinates and which integers are y-coordinates? The total length of the path s will be equal to maxxi−minxi+maxyi−minyi; one of the minimums will be equal to the value of a1; one of the maximums will be equal to the value of a2n; so we need to consider the remaining minimum and maximum.

The minimum coordinate of any type should be less than or equal to at least n−1 elements. Similarly, the maximum coordinate should be greater than or equal to at least n−1 elements. So, the second minimum (the minimum which is not a1) is at most an+1, the second maximum is at least an, and the length of the path is at least a2n−a1+an−an+1. And it is possible to reach this bound: take the first n values in a as x-coordinates, and the last n values as y-coordinates.

 **Solution (fcspartakm)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

inline void read() {
  cin >> n;
  a.clear();
  for (int i = 0; i < 2 * n; i++) {
      int x;
      cin >> x;
      a.pb(x);
  }
}
inline void solve() {
    sort(all(a));
    vector<pair<int, int> > pts;
    for (int i = 0; i < n; i++) {
        pts.pb(mp(a[i], a[i + n]));
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += abs(pts[i].ft - pts[i - 1].ft) + abs(pts[i].sc - pts[i - 1].sc);
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << pts[i].ft << ' ' << pts[i].sc << endl;
    }
}
 
int main () {
    int t;
    cin >> t;
    while (t--){
        read();
        solve();
    }
}
```
[1895C - Torn Lucky Ticket](../problems/C._Torn_Lucky_Ticket.md "Educational Codeforces Round 157 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1895C - Torn Lucky Ticket](../problems/C._Torn_Lucky_Ticket.md "Educational Codeforces Round 157 (Rated for Div. 2)")

There is an obvious $O(n^2)$ approach: iterate over the first part, the second part and check the sum. In order to improve it, let's try to get rid of the second iteration.

Consider the case where the first part is longer or equal than the second part. So, we still iterate over the first part in $O(n)$. However, instead of iterating over the exact second part, let's just iterate over its length. Now, we know the total length of the parts, but not their sums of digits. Hmm, not exactly. By fixing the longer part, we actually know what the required sum of each half should be. It's fully inside the first part. However, this first part also contains some digits that belong to the second half. So, if the sum of the second part was $s$, the total sum of the second half would be these digits plus $s$.

Let $l$ be the total length of the ticket: the length of the fixed first part plus the fixed length of the second part. Let $\mathit{sum}_l$ be the sum of the first $\frac{l}{2}$ digits of the first part, and $\mathit{sum}_r$ be the sum of its remaining digits. Then $\mathit{sum}_l = \mathit{sum}_r + s$. Rewrite into $\mathit{sum}_l - \mathit{sum}_r = s$. Thus, we just know what should be the sum of the second half. And every ticket part that is exactly of the fixed length and has sum exactly $\mathit{sum}_l - \mathit{sum}_r$ will form a lucky ticket with the fixed part.

So, we have to precalculate $\mathit{cnt}[l][s]$, which is the number of ticket parts that have length $l$ and sum $s$, and use that structure to speed up the solution.

The mirror case, where the second part is strictly longer than the first part, can be handled similarly.

Overall complexity: $O(n)$.

 **Solution (awoo)**
```cpp
n = int(input())
s = input().split()
ans = 0
cnt = [[0 for k in range(46)] for k in range(6)]
for y in s:
    cnt[len(y)][sum([int(c) for c in y])] += 1
for L in s:
    for lenr in range(len(L) % 2, len(L) + 1, 2):
        l = len(L) + lenr
        suml = sum([int(c) for c in L[:l // 2]])
        sumr = sum([int(c) for c in L[l // 2:]])
        if suml - sumr >= 0:
            ans += cnt[lenr][suml - sumr]
for R in s:
    for lenl in range(len(R) % 2, len(R), 2):
        l = len(R) + lenl
        suml = sum([int(c) for c in R[-l // 2:]])
        sumr = sum([int(c) for c in R[:-l // 2]])
        if suml - sumr >= 0:
            ans += cnt[lenl][suml - sumr]
print(ans)
```
[1895D - XOR Construction](../problems/D._XOR_Construction.md "Educational Codeforces Round 157 (Rated for Div. 2)")

Idea: [AcidWrongGod](https://codeforces.com/profile/AcidWrongGod "International Master AcidWrongGod")

 **Tutorial**
### [1895D - XOR Construction](../problems/D._XOR_Construction.md "Educational Codeforces Round 157 (Rated for Div. 2)")

We can see that the first element of the array b determines all other values, bi+1=b1⊕a1⋯⊕ai.

So let's iterate over the value of b1. For every value of b1, we need to check whether it produces correct permutation or not (i. e. all bi<n). To do it in a fast way, we can generate an array c, where ci is the XOR of the first i element of the array a (i.e. ci=a1⊕a2⊕⋯⊕ai and c0=0). We can see that bi+1=b1⊕ci. Let's store all values of ci in a binary trie. To check that b1 produces an array where all elements are less than n, we can calculate the maximum value of b1⊕ci using descending on the trie. If the maximum is less than n, then it's a valid first element of the permutation.

Note that we don't actually need to check that the minimum is exactly 0 and all elements are distinct: we are guaranteed that the answer exists, so all values [0,c1,c2,c3,…,cn−1] are pairwise distinct, and no matter which b1 we choose, all bi will also be pairwise distinct.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

const int LOG = 20;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }
  vector<array<int, 2>> t({{-1, -1}});
  auto add = [&](int x) {
    int v = 0;
    for (int i = LOG - 1; i >= 0; --i) {
      int j = (x >> i) & 1;
      if (t[v][j] == -1) {
        t[v][j] = t.size();
        t.push_back({-1, -1});
      }
      v = t[v][j];
    }
  };  
  for (int x : a) add(x);
  auto get = [&](int x) {
    int v = 0;
    for (int i = LOG - 1; i >= 0; --i) {
      int j = (x >> i) & 1;
      if (t[v][j ^ 1] != -1) j ^= 1;
      x ^= j << i;
      v = t[v][j];
    }
    return x;
  };
  for (int x = 0; x < n; ++x) {
    if (get(x) == n - 1) {
      for (int i : a) cout << (x ^ i) << ' ';
      break;
    }
  }
}
```
[1895E - Infinite Card Game](../problems/E._Infinite_Card_Game.md "Educational Codeforces Round 157 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1895E - Infinite Card Game](../problems/E._Infinite_Card_Game.md "Educational Codeforces Round 157 (Rated for Div. 2)")

Let's restate the game in game theory terms. The state of the game can be just the card that is currently on top, since none of the previously played cards matter. A move is still a card beating another card, so these are the edges of the game graph.

Now we can solve this as a general game. Mark all trivial winning and losing states and determine the outcome for all other states with a DFS/BFS on a transposed game graph. 

Unfortunately, there are O(n2) edges in the graph, so we can't quite do it as is. There are multiple ways to optimize that, I'll describe the smartest one, in my opinion.

Notice that, after a card beats another card, its attack doesn't matter at all. It's only health that's relevant. And the larger the health is, the fewer responses the opponent has. In particular, we use the fact that the sets of the responses can either coincide or be included one into another.

So, there is always the best response for each card (or multiple equally good ones). That is just the card with the largest health among the ones that beat the current one. To find this card, you can sort them by their attack value and find a prefix/suffix health maximum.

This massively reduces the number of edges. Now, each state has at most one outgoing edge. Zero edges mean that the card is winning, since there is no card to beat it. For these states, we can tell the winner. The rest of the states either reach these marked ones, thus, can be deduced, or form a closed loop among each other, making the outcome a draw (since there is always a response for each move).

Overall complexity: O(nlogn) per testcase.

 **Solution (awoo)**
```cpp
//

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct card{
  int x, y;
  card() {}
  card(int x, int y) : x(x), y(y) {}
};

void dfs(int v, const vector<int> &g, vector<int> &res, vector<char> &used){
  if (used[v]) return;
  used[v] = true;
  dfs(g[v], g, res, used);
  res[v] = -res[g[v]];
}

void solve(){
  vector<vector<card>> a(2);
  vector<vector<int>> prpos(2);
  forn(z, 2){
    int n;
    scanf("%d", &n);
    a[z].resize(n);
    forn(i, n) scanf("%d", &a[z][i].x);
    forn(i, n) scanf("%d", &a[z][i].y);
    sort(a[z].begin(), a[z].end(), [](const card &a, const card &b){
      return a.x > b.x;
    });
    prpos[z].resize(n + 1, -1);
    forn(i, n){
      if (prpos[z][i] == -1 || a[z][i].y > a[z][prpos[z][i]].y)
        prpos[z][i + 1] = i;
      else
        prpos[z][i + 1] = prpos[z][i];
    }
  }
  int n = a[0].size();
  vector<int> g(n + a[1].size());
  forn(z, 2) forn(i, a[z].size()){
    int cnt = lower_bound(a[z ^ 1].begin(), a[z ^ 1].end(), card(a[z][i].y, -1), [](const card &a, const card &b){
      return a.x > b.x;
    }) - a[z ^ 1].begin();
    g[i + z * n] = prpos[z ^ 1][cnt] == -1 ? -1 : prpos[z ^ 1][cnt] + (z ^ 1) * n;
  }
  vector<int> res(g.size());
  vector<char> used(g.size());
  forn(i, g.size()) if (g[i] == -1) res[i] = 1, used[i] = true;
  int w = 0, l = 0;
  forn(i, n){
    if (!used[i]) dfs(i, g, res, used);
    w += res[i] == 1;
    l += res[i] == -1;
  }
  printf("%d %d %dn", w, n - l - w, l);
}

int main(){
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
```
[1895F - Fancy Arrays](../problems/F._Fancy_Arrays.md "Educational Codeforces Round 157 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1895F - Fancy Arrays](../problems/F._Fancy_Arrays.md "Educational Codeforces Round 157 (Rated for Div. 2)")

It is difficult to directly calculate the number of arrays that satisfy both conditions. So let's calculate the opposite value — the number of arrays, where only the second condition is holds, and the first is necessarily violated. 

Using the fact that the array can contain integers from two sets $[0, x)$ and $[x + k, \infty)$. We can notice that the array can consist of elements from only one set, but not both (because the difference between elements from different sets is at least $k+1$ which violates the second condition). So the answer to the problem is $f(0, M) - f(0, x-1) - f(x+k, M)$, where $f(l, r)$ is the number of arrays of length $n$ that satisfy the second condition and elements in range from $l$ to $r$, and $M$ is some big constant (let it be equal to $10^{100}$).

Let's take a closer look at the function $f(l, r)$. We can represent the required array $a$ as integer $a_1$ and an array of $n-1$ differences $\Delta_i=a_{i+1}-a_1$. There are $(2k+1)^{n-1}$ differences arrays in total, because of the second condition. Let $cnt(l, r, \Delta)$ be the number of valid $a_1$ for the given array $\Delta$ ($a_1$ is valid if it's produces array $a$, where all elements from $l$ to $r$). Using such a representation we can see that $f(l, r) = \sum\limits_{\Delta} cnt(l, r, \Delta)$. Moreover, let $mn$ be the minimum value in $\Delta$ and $mx$ be the maximum value in $\Delta$, then $cnt(l, r, \Delta)$ is equal to $\max(0, (r - l) - (mx - mn))$.

It is difficult to calculate the values of $f(0, M)$ and $f(x+k, M)$ independently, because we can't iterate over all arrays $\Delta$. Luckily, our goal is to calculate their difference. Since the value of $M$ is big enough, we can say that $cnt$ of any $\Delta$ is positive. So we can represent $f(0, M) - f(x+k, M)$ as $$\sum\limits_{\Delta} cnt(0, M, \Delta) - \sum\limits_{\Delta} cnt(x+k, M, \Delta)$$ or $$\sum\limits_{\Delta} (M - 0) - (mx - mn) - \sum\limits_{\Delta} (M - (x+k)) - (mx - mn))$$ Since the $\Delta$ arrays are the same in both cases, we can combine the sums $$\sum\limits_{\Delta} ((M - 0) - (mx - mn)) - ((M - (x + k)) - (mx - mn))$$ Let's expand the brackets, and we get the final value $$f(0, M) - f(x+k, M) = \sum\limits_{\Delta} x+k$$ We can see that each $\Delta$ array adds $x+k$ to the difference between two values. So this part of the answer is equal to the $(x+k)(2k+1)^{n-1}$.

It remains us to calculate the value of $f(0, x-1)$. We can do it using simple dynamic programming $dp_{i, j}$ — the number of arrays of length $i$ if the last element is $j$. The transition from $(i, y)$ to $(i + 1, z)$ can be made if $|y - z| \le k$. And the answer is equal to the sum of $dp_{n, j}$ for each $j \in [0, x)$ Such dynamic programming works in $O(nx)$, but $n$ is too big for this solution. However, thanks to fairly simple transitions, we can represent it as matrix multiplication. Using fast matrix exponentiation, we can calculate it in $O(x^3\log(n))$.

The total answer is $(x+k)(2k+1)^{n-1} - f(0, x - 1)$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int MOD = 1e9 + 7;
const int N = 40;

using mat = array<array<int, N>, N>;

int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  if (x < 0) x += MOD;
  return x;
}

int mul(int x, int y) {
  return x * 1LL * y % MOD;
}

mat mul(mat x, mat y) {
  mat res;
  forn(i, N) forn(j, N) res[i][j] = 0;
  forn(i, N) forn(j, N) forn(k, N)
    res[i][j] = add(res[i][j], mul(x[i][k], y[k][j]));
  return res;
}

template<class T>
T binpow(T x, int y, T e) {
  T res = e;
  while (y) {
    if (y & 1) res = mul(res, x);
    x = mul(x, x);
    y >>= 1;
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, k;
    cin >> n >> x >> k;
    mat a, e;
    forn(i, N) forn(j, N) a[i][j] = (i < x && abs(i - j) <= k);
    forn(i, N) forn(j, N) e[i][j] = (i == j);
    mat b = binpow(a, n - 1, e);
    int ans = mul(x + k, binpow(2 * k + 1, n - 1, 1));
    forn(i, x) forn(j, x) ans = add(ans, -b[i][j]);
    cout << ans << 'n';
  }
}
```
[1895G - Two Characters, Two Colors](../problems/G._Two_Characters,_Two_Colors.md "Educational Codeforces Round 157 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1895G - Два символа, два цвета](../problems/G._Two_Characters,_Two_Colors.md "Educational Codeforces Round 157 (Rated for Div. 2)")

This problem requires partitioning some object into two parts, and imposes different costs depending on how we perform the partition. Let's try to model it with minimum cuts.

Create a flow network with $n+2$ vertices: a vertex for every character of the string, a source and a sink. Using the edges of the network, we will try to model the following:

* if we paint the $i$-th character red, we lose $b_i$ coins (we can treat it as always gaining $r_i + b_i$ coins no matter what, and then losing coins instead of earning them for coloring the characters);
* if we paint the $i$-th character blue, we lose $r_i$ coins (the same applies here);
* if $i < j$, $s_i = 1$, $s_j = 0$ and both $s_i$ and $s_j$ are red, we lose $1$ coin.

To model the third constraint, let's say that the vertices representing $1$'s are red if they belong to the set $S$ in the cut, or blue if they belong to $T$. For the vertices representing $0$'s, this will be the opposite: they will be red if they belong to the set $T$, or blue if they belong to the set $S$. So, if we add a directed edge with capacity $1$ from $i$ to $j$ when $s_i = 1$, $s_j = 0$ and $i < j$, this edge will be cut exactly when both $s_i$ and $s_j$ are red, and they create an inversion.

To model the second constraint, for vertices representing $1$'s, add an incoming edge from the source with capacity $r_i$, and an outgoing edge to the sink with capacity $b_i$. For vertices representing $0$'s, this will be vice versa (since red vertices representing $0$'s belong to $T$, the edge from the source to that vertex should have capacity $b_i$, not $r_i$).

Now we got ourselves a flow network. The answer to the problem will be $\sum\limits_{i=1}^{n} (r_i + b_i) - mincut$, where $mincut$ is the minimum cut in this network. But instead of searching for the minimum cut, we will try to calculate the maximum flow.

We are going to do it greedily. Let's process the vertices of the network, from the vertex representing the $1$-st character to the vertex representing the $n$-th character. Every time, we will try to push as much flow as possible through the current vertex.

When processing a vertex, first of all, let's try to push $\min(r_i, b_i)$ flow through the edges connecting the source and the sink with it. Then, if it is a vertex with a character of type $1$, let's remember that we can push $r_i - \min(r_i, b_i)$ flow through it to successive vertices of type $0$ (let's call this excess flow for that vertex). And if it is a vertex representing a character of type $0$, let's try to push at most $r_i - \min(r_i, b_i)$ flow into it from the vertices of type $1$ we processed earlier (but no more than $1$ unit of flow from each vertex). 

But when we process a vertex of type $0$, how do we choose from which vertices of type $1$ we take the flow? It can be shown that we can take $1$ unit of flow from the vertices with the maximum amount of excess flow (the formal proof is kinda long, but the main idea is that every optimal flow assignment can be transformed into the one working in this greedy way without breaking anything).

So, to recap, when we process a vertex of type $1$, we remember that it has some excess flow. And when we process a vertex of type $0$, we take $1$ unit of excess flow from several vertices with the maximum amount of excess flow. So, we need a data structure that allows us to process the following queries:

* add an integer;
* calculate the number of positive integers in the structure;
* subtract $1$ from $k$ maximum integers in the structure.

Model implementation of this data structure is kinda long (there are easier ways to do it), but I will describe it nevertheless. We will use an explicit-key treap which stores two values in each vertex — an integer belonging to the structure and the quantity of that integer in the structure (so, it's kinda like a map which counts the number of occurrences of each integer). This treap has to support adding $-1$ to all values in some subtree (with lazy propagation). Most operations with it are fairly straightforward, but how do we actually subtract $1$ from $k$ maximum values in the tree? We will do it in the following way:

* split the treap to extract $k$ maximum elements (let's denote the first treap as the part without $k$ maximums, and the second treap as the part with those $k$ maximums);
* add $-1$ to the values in the second treap;
* while the minimum element in the second treap is not greater than the maximum element in the first treap, remove the minimum from the second treap and insert it into the first treap;
* merge the treaps.

It's quite easy to see that if you store the pairs of the form "element, the number of its occurrences" in the treap, the third step will require moving at most $2$ elements. And the resulting complexity of every operation with this data structure becomes $O(\log n)$, so the whole solution works in $O(n \log n)$.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(42);

struct node
{
  long long x;
  int y;
  int cnt;
  int sum;
  int push;
  node* l;
  node* r;
  node() {};
  node(long long x, int y, int cnt, int sum, int push, node* l, node* r) : x(x), y(y), cnt(cnt), sum(sum), push(push), l(l), r(r) {};
};

typedef node* treap;
typedef pair<treap, treap> ptt;

int getSum(treap t)
{
  return (t ? t->sum : 0);
}

int getCnt(treap t)
{
  return (t ? t->cnt : 0);
}

treap fix(treap t)
{
  if(!t) return t;
  int p = t->push;
  if(p != 0)
  {
    if(t->l) t->l->push += p;
    if(t->r) t->r->push += p;
    t->x += p;
    t->push = 0;
  }
  t->sum = getSum(t->l) + t->cnt + getSum(t->r);
  return t;
}

treap merge(treap a, treap b)
{
  a = fix(a);
  b = fix(b);
  if(!a) return b;
  if(!b) return a;
  if(a->y > b->y)
  {
    a->r = merge(a->r, b);
    return fix(a);
  }
  else
  {
    b->l = merge(a, b->l);
    return fix(b);
  }
}

bool hasKey(treap t, long long x)
{
  t = fix(t);
  if(!t) return false;
  if(t->x == x) return true;
  if(t->x < x) return hasKey(t->r, x);
  return hasKey(t->l, x);
}

ptt splitKey(treap t, long long x)
{
  t = fix(t);
  if(!t) return make_pair(t, t);
  if(t->x < x)
  {
    ptt p = splitKey(t->r, x);
    t->r = p.first;
    return make_pair(fix(t), p.second);
  }
  else
  {
    ptt p = splitKey(t->l, x);
    t->l = p.second;
    return make_pair(p.first, fix(t));
  }
}

long long kthMax(treap t, int k)
{
  t = fix(t);
  if(!t) return -1;
  int sumR = getSum(t->r);
  if(sumR >= k) return kthMax(t->r, k);
  if(sumR + t->cnt >= k) return t->x;
  return kthMax(t->l, k - sumR - t->cnt);
}

int getCntByKey(treap t, long long x)
{
  t = fix(t);
  if(!t) return 0;
  if(t->x == x) return t->cnt;
  if(t->x > x) return getCntByKey(t->l, x);
  return getCntByKey(t->r, x);
}

treap increaseKey(treap t, long long x, int cnt)
{
  t = fix(t);
  if(!t) return t;
  if(t->x == x)
  {
    t->cnt += cnt;
  }
  else if(t->x > x)
  {
    t->l = increaseKey(t->l, x, cnt);
  }
  else
  {
    t->r = increaseKey(t->r, x, cnt);
  }
  return fix(t);
}

treap insert(treap t, long long x, int y, int cnt)
{
  t = fix(t);
  if(!t || t->y < y)
  {
    ptt p = splitKey(t, x);
    treap res = new node(x, y, cnt, cnt, 0, p.first, p.second);
    return fix(res);
  }
  if(t->x > x)
    t->l = insert(t->l, x, y, cnt);
  else
    t->r = insert(t->r, x, y, cnt);
  return fix(t);
}

treap insertMain(treap t, long long x, int cnt)
{
  if(hasKey(t, x))
    return increaseKey(t, x, cnt);
  else
    return insert(t, x, rnd(), cnt);
}

treap eraseKey(treap t, long long x)
{
  t = fix(t);
  if(!t) return NULL;
  if(t->x > x)
  {
    t->l = eraseKey(t->l, x);
    return fix(t);
  }
  if(t->x < x)
  {
    t->r = eraseKey(t->r, x);
    return fix(t);
  }
  treap tnew = merge(t->l, t->r);
  delete t;
  return tnew;
}

ptt splitSum(treap t, int k)
{
  t = fix(t);
  if(!t) return make_pair(t, t);
  if(k == 0) return make_pair(t, treap(NULL));
  long long x = kthMax(t, k);
  int cnt = getCntByKey(t, x);
  t = eraseKey(t, x);
  ptt p = splitKey(t, x);
  k -= getSum(p.second);
  if(k > 0) p.second = merge(new node(x, rnd(), k, k, 0, NULL, NULL), p.second);
  if(k < cnt) p.first = merge(p.first, new node(x, rnd(), cnt - k, cnt - k, 0, NULL, NULL));
  return p;
}

long long minKey(treap t)
{
  t = fix(t);
  if(!t) return 1e18;
  if(t->l) return minKey(t->l);
  return t->x;
}

treap decreaseUpToKLargest(treap t, int k, int& res)
{
  if(!k) return t;
  t = fix(t);
  k = min(k, getSum(t));
  res = k;
  ptt p = splitSum(t, k);
  if(p.second)
  {
    p.second->push--;
    for(int i = 0; i < 2; i++)
    {
        long long x = minKey(p.second);
        int cntMin = getCntByKey(p.second, x);
        p.second = eraseKey(p.second, x);
        if(x != 0 && cntMin != 0)
          p.first = insertMain(p.first, x, cntMin);
    }
  }
  return merge(p.first, p.second);
}

void destroy(treap t)
{
  if(!t) return;
  if(t->l) destroy(t->l);
  if(t->r) destroy(t->r);
  delete t;
}

void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<long long> r(n), b(n);
  for(int i = 0; i < n; i++) cin >> r[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  long long sum = 0;
  for(int i = 0; i < n; i++) sum += r[i] + b[i];
  long long flow = 0;
  treap t = NULL;
  for(int i = 0; i < n; i++)
  {
    long long d = min(r[i], b[i]);
    flow += d;
    r[i] -= d;
    b[i] -= d;
    if(s[i] == '0')
    {
      int add = 0;
      if(r[i] > 1e9) r[i] = 1e9;
      t = decreaseUpToKLargest(t, r[i], add);
      flow += add;
    }
    else
    {
      if(r[i] != 0) t = insertMain(t, r[i], 1);
    }
  }
  cout << sum - flow << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) solve();
}
```
