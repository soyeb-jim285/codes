# Tutorial

[1795A - Two Towers](../problems/A._Two_Towers.md "Educational Codeforces Round 143 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (Neon) 1**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  auto ok = [](string s) {
    for (int i = 1; i < (int)s.size(); ++i)
      if (s[i - 1] == s[i]) return false;
    return true;    
  };
  
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    bool f = false;
    for (int x = 0; x < 2; ++x) {
      string cs = s, ct = t;
      for (int i = 0; i < n; ++i) {
        f |= ok(cs) && ok(ct);
        ct.push_back(cs.back());
        cs.pop_back();
      }
      swap(n, m);
      swap(s, t);   
    }
    cout << (f ? "YESn" : "NOn");
  }
}
```
 **Solution (Neon) 2**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    reverse(t.begin(), t.end());
    s += t;
    int cnt = 0;
    for (int i = 1; i < n + m; ++i) cnt += s[i - 1] == s[i];
    cout << (cnt <= 1 ? "YESn" : "NOn");
  }
}
```
[1795B - Ideal Point](../problems/B._Ideal_Point.md "Educational Codeforces Round 143 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1795B - Ideal Point](../problems/B._Ideal_Point.md "Educational Codeforces Round 143 (Rated for Div. 2)")

First of all, let's delete all segments that do not cover the point $k$ (because they increase the value of the function $f$ at points other than $k$). If there are no segments left, then the answer is NO. Otherwise, all segments cover the point $k$. And it remains to check whether the point $k$ is the only point which is covered by all segments. Note that it does not make sense to delete any of the remaining segments, because if there are several points with maximum value of $f$, then deleting segments can only increase their number.

To check the number of points with the maximum value of $f$, you can iterate over $x$ from $1$ to $50$ and calculate $f(x)$, because of the small number of segments in the problem. A faster way is to check the size of the intersection of all segments. The left boundary of the intersection is $L = \max\limits_{i=1}^{n}{l_i}$, and the right boundary is $R = \min\limits_{i=1}^{n}{r_i}$; if $L = R$, then the point $k$ is ideal, otherwise it is not.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int L = 0, R = 55;
    while (n--) {
      int l, r;
      cin >> l >> r;
      if (l <= k && k <= r)
        L = max(L, l), R = min(R, r);
    }
    cout << (L == R ? "YESn" : "NOn");
  }
}
```
[1795C - Tea Tasting](../problems/C._Tea_Tasting.md "Educational Codeforces Round 143 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1795C - Tea Tasting](../problems/C._Tea_Tasting.md "Educational Codeforces Round 143 (Rated for Div. 2)")

Consider how each sort of tea affects the tasters.

The $i$-th sort makes testers $i, i + 1, \dots, j - 1$, for some $j$, drink to their limit $b_i, b_{i + 1}, \dots, b_{j - 1}$, and the $j$-th taster drink the remaining tea. Sometimes there is no such $j$-th taster, but we'll explore the general case.

Let's add the remaining tea straight to the $j$-th taster answer $\mathit{add}_j$. And for each taster $k$ from $i$ to $j-1$ we'll add $1$ into the value $\mathit{cnt}_k$ denoting how many times they drank at their limit $b_k$.

If we have these calculated, we can obtain the answer by adding $\mathit{add}_i$ and $\mathit{cnt}_i \cdot b_i$.

In order to find $j$, we can use prefix sums. Build $\mathit{pref}$ over the sequence $b$. Now you want to find the largest $j$ such that $\mathit{pref}_{j} - \mathit{pref}_i \le a_i$. Rewrite it as $\mathit{pref}_{j} \le a_i + \mathit{pref}_i$. You can do this with a binary search. In particular, with an upper_bound call. The amount of the remaining tea can also be calculated from prefix sums.

To add $1$ on a range $[i, j-1]$, you can use a technique called delta encoding. Add $1$ to $\mathit{cnt}_i$. Subtract $1$ from $\mathit{cnt}_j$. After everything is added, propagate this values via a prefix sum. This way, if both $+1$ and $-1$ happened non-strictly to the left or strictly to the right of $i$, it doesn't affect $i$ at all (the segment either closes before $i$ or opens after $i$). Otherwise, it adds exactly $1$ to $\mathit{cnt}_i$.

Overall complexity: $O(n \log n)$ per testcase.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<li> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    vector<li> sum(n + 1);
    for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + b[i];
    vector<li> cnt(n + 1), add(n + 1);
    for (int i = 0; i < n; ++i) {
      int j = upper_bound(sum.begin(), sum.end(), a[i] + sum[i]) - sum.begin() - 1;
      cnt[i] += 1;
      cnt[j] -= 1;
      add[j] += a[i] - sum[j] + sum[i];
    }
    for (int i = 0; i < n; ++i) {
      cout << cnt[i] * b[i] + add[i] << ' ';
      cnt[i + 1] += cnt[i];   
    }
    cout << 'n';
  }
}
```
[1795D - Triangle Coloring](../problems/D._Triangle_Coloring.md "Educational Codeforces Round 143 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1795D - Triangle Coloring](../problems/D._Triangle_Coloring.md "Educational Codeforces Round 143 (Rated for Div. 2)")

Let's ignore the constraint on the number of red/blue vertices for a moment. What is the maximum possible weight of a coloring? From any triple, we can have any two edges connect vertices of different colors. So, the maximum possible weight of a coloring (not necessarily a valid one) is the sum of all edge weights except for the minimum weight in each triple.

Let's show that it is always possible to choose a valid coloring to achieve this weight. In each triple, we should make sure that the two maximum edges connect vertices with different colors; to do this, we can color the vertex incident to both of these edges in one color, and the two other vertices will be painted in the other color. So, for each triple of vertices, there will be either one red vertex and two blue ones, or two red ones and one blue. Let's suppose the first $\frac{n}{6}$ triples have one red vertex and two blue vertices each, and the other $\frac{n}{6}$ triples have one blue vertex and two red vertices each. That way, we obtain a valid coloring with maximum possible weight.

Okay, now let's try to find out how do we calculate the number of valid colorings with the maximum possible weight. Each triple of vertices will be either "red" (two red vertices, one blue), or "blue" (the other way around). Since exactly half of the vertices should be red, then exactly half of the triples should be red, so the number of ways to choose a "color" for all triples is ${n/3}\choose{n/6}$.

After choosing the color of each triple, let's choose how we actually color them. The triples are independent, so for each triple, we can introduce the coefficient $c_i$, which is the number of ways to color it so that its weight is maximized, and the triple has some specific type (either red or blue, doesn't matter since these are symmetric). Choosing the vertex which will be different from its neighbors is equivalent to choosing the edge which will not be included in the weight of the coloring (this is the edge which is not incident to the chosen vertex). So, $c_i$ is equal to the number of ways to choose that vertex in the $i$-th triple so that the weight is maximized; i. e. the weight of the edge not incident to the chosen vertex should be minimized. Thus, $c_i$ is just the number of minimum edge weights in the $i$-th triple.

The formula for the final answer is ${{n/3}\choose{n/6}} \prod\limits_{i=1}^{n/3} c_i$.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
    return ((x + y) % MOD + MOD) % MOD;
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;   
}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int inv(int x)
{
    return binpow(x, MOD - 2);    
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

int main()
{
    int n;
    cin >> n;
    int ans = 1;
    for(int i = 1; i <= n / 6; i++)
        ans = mul(ans, divide(i + n / 6, i));
    for(int i = 0; i < n / 3; i++)
    {
        vector<int> a(3);
        for(int j = 0; j < 3; j++)
            cin >> a[j];
        int mn = *min_element(a.begin(), a.end());
        int cnt_min = count(a.begin(), a.end(), mn);
        ans = mul(ans, cnt_min);
    }
    cout << ans << endl;
}
```
[1795E - Explosions?](../problems/E._Explosions_.md "Educational Codeforces Round 143 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (adedalic)**
```cpp
import java.util.*

fun main() {
    repeat(readln().toInt()) {
        val n = readln().toInt()
        var h = readln().split(' ').map { it.toInt() }

        val d = Array(2) { LongArray(n) { 0 } }
        for (tp in 0..1) {
            val s = Stack<Pair<Int, Int>>()

            for (i in h.indices) {
                while (s.isNotEmpty() && s.peek().first > h[i] - i)
                    s.pop()
                var j = maxOf(-1, i - h[i])
                if (s.isNotEmpty())
                    j = maxOf(j, s.peek().second)

                val len = (i - j).toLong()
                d[tp][i] = len * h[i] - len * (len - 1) / 2
                if (j >= 0 && len < h[i])
                    d[tp][i] += d[tp][j]

                s.push(Pair(h[i] - i, i))
            }
            h = h.reversed()
        }
        d[1] = d[1].reversedArray()

        var ans = 1e18.toLong()
        val sum = h.fold(0L) { total, it -> total + it }
        for (i in h.indices) {
            val cur = sum - d[0][i] - d[1][i] + 2 * h[i]
            ans = minOf(ans, cur)
        }
        println(ans)
    }
}
```
[1795F - Blocking Chips](../problems/F._Blocking_Chips.md "Educational Codeforces Round 143 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1795F - Blocking Chips](../problems/F._Blocking_Chips.md "Educational Codeforces Round 143 (Rated for Div. 2)")

The constraints tell us that the solution should be linear or pretty close to it. Well, in particular, that implies that the solution almost certainly isn't dynamic programming, since we have both $n$ and $k$ to care about. Thus, we'll think about something greedy.

When we know the number of move the game will last, we can tell how many steps each chip should make. Well, since the more moves the game last, the more steps each ship makes, the answer is a monotonic function. Let's apply binary search and think if we can check if each chip can make some known number of steps.

A common idea in the problems where you have to do something greedily on a tree is to root the tree arbitrarily and process everything bottom up.

Consider the bottommost chip. If it can move its number of moves downwards, it's always optimal to do that. Since it's the bottommost chip, it can only make things worse for chips above it. And any of them can't pass through the initial vertex of this chip anyway.

If it can't, it has to move to its parent vertex. Let's move it there and deal with this chip later — when it becomes the bottommost again.

If it can't move to its parent, it can't move at all. Thus, the game can't last for this many steps.

Since we only apply either the move which is guaranteed to not interrupt any other moves or the move which is forced, the greedy strategy is correct.

As for implementation details, it's not too tricky. Basically, for each vertex, we should maintain these values: 

* if this vertex has been visited;
* the number of steps the chip in this vertex still has to make (if any chip is in this vertex);
* the longest path downwards from this vertex via non-visited vertices.

The second value can be initialized beforehand and pushed to the parent when needed. The rest of them are easily maintained with a single dfs.

Overall complexity: $O(n \log n)$ per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); i++) 

vector<vector<int>> g;
vector<int> req;
vector<char> used;

vector<int> d;

bool dfs(int v, int p = -1){
    d[v] = 0;
    for (int u : g[v]) if (u != p){
        if (!dfs(u, v)) return false;
        if (!used[u]) d[v] = max(d[v], d[u] + 1);
    }
    if (req[v] == 0 || d[v] >= req[v]) return true;
    if (p == -1 || used[p]) return false;
    used[p] = true;
    req[p] = req[v] - 1;
    return true;
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        int n;
        scanf("%d", &n);
        g.assign(n, {});
        d.resize(n);
        forn(i, n - 1){
            int v, u;
            scanf("%d%d", &v, &u);
            --v, --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        int k;
        scanf("%d", &k);
        vector<int> a(k);
        forn(i, k){
            scanf("%d", &a[i]);
            --a[i];
        }
        int l = 1, r = n;
        int res = 0;
        while (l <= r){
            int m = (l + r) / 2;
            used.assign(n, 0);
            req.assign(n, 0);
            forn(i, k){
                used[a[i]] = true;
                req[a[i]] = m / k + (i < m % k);
            }
            if (dfs(0)){
                res = m;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        printf("%dn", res);
    }
}
```
[1795G - Removal Sequences](../problems/G._Removal_Sequences.md "Educational Codeforces Round 143 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (awoo)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); i++) 

typedef unsigned long long uli;

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> a(n);
        forn(i, n) scanf("%d", &a[i]);
        vector<vector<int>> g(n);
        forn(i, m){
            int v, u;
            scanf("%d%d", &v, &u);
            --v, --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        vector<char> rem(n);
        vector<int> d(n);
        forn(i, n) d[i] = g[i].size();
        queue<int> q;
        forn(i, n) if (a[i] == d[i]) q.push(i);
        vector<pair<int, int>> ord;
        while (!q.empty()){
            int v = q.front();
            q.pop();
            rem[v] = true;
            for (int u : g[v]) if (!rem[u]){
                --d[u];
                ord.push_back({v, u});
                if (d[u] == a[u])
                    q.push(u);
            }
        }
        reverse(ord.begin(), ord.end());
        vector<uli> mask(n);
        long long ans = n * 1ll * (n + 1) / 2;
        for (int l = 0; l < n; l += 64){
            int r = min(n, l + 64);
            for (int i = l; i < r; ++i)
                mask[i] = 1ull << (i - l);
            for (const pair<int, int> &it : ord)
                mask[it.first] |= mask[it.second];
            forn(i, n){
                ans -= __builtin_popcountll(mask[i]);
                mask[i] = 0;
            }
        }
        printf("%lldn", ans);
    }
}
```
