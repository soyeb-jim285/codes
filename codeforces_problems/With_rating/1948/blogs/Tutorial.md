# Tutorial

[1948A - Special Characters](../problems/A._Special_Characters.md "Educational Codeforces Round 163 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1948A - Special Characters](../problems/A._Special_Characters.md "Educational Codeforces Round 163 (Rated for Div. 2)")

Let's look at the blocks of consecutive equal characters (such that it cannot be extended to the left or to the right): 

* if its length is 1, then this block has 0 special characters;
* if its length is 2, then this block has 2 special characters;
* if its length is at least 3, then this block has 2 special characters (only the leftmost and the rightmost elements);

We can see that there is no way to obtain an odd number of special characters. So the answer is NO for all odd values of n. And we can easily build the string for all even values of n. The answer for an even n may look like this: AABBAABB... with n2 blocks of length 2 alternating between two different letters.

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
    if (n % 2 == 1) {
      cout << "NO" << 'n';
      continue;
    }
    cout << "YES" << 'n';
    for (int i = 0; i < n / 2; ++i)
      for (int j = 0; j < 2; ++j)
        cout << "AB"[i & 1];
    cout << 'n';
  }
}
```
[1948B - Array Fix](../problems/B._Array_Fix.md "Educational Codeforces Round 163 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1948B - Array Fix](../problems/B._Array_Fix.md "Educational Codeforces Round 163 (Rated for Div. 2)")

The key to solving the problem is the following observation: if ai>ai+1, then the i-th element should always be split (since it is the only way to decrease the element compared with ai+1).

This observation allows us to solve the problem greedily as follows: iterate on the array a from right to left, keeping track of the list of elements we processed; if the current element is greater than the last element in our list, we have to split it (and add the digits it consists of to the list); otherwise, we don't have to split it (because it might forbid some of the next elements and force them to split as well).

After that, we have to make sure we obtained a sorted array (because, for example, a number like 98 will break the sorted order if we split it, and we didn't check that). But since we maintained the list of elements we processed, that's quite easy, because that list is the resulting array a in reversed order.

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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> b({a[n - 1]});
    for (int i = n - 2; i >= 0; --i) {
      if (a[i] > b.back()) {
        b.push_back(a[i] % 10);
        b.push_back(a[i] / 10);
      } else {
        b.push_back(a[i]);
      }
    }
    cout << (is_sorted(b.rbegin(), b.rend()) ? "YES" : "NO") << 'n';
  }
}
```
[1948C - Arrow Path](../problems/C._Arrow_Path.md "Educational Codeforces Round 163 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1948C - Arrow Path](../problems/C._Arrow_Path.md "Educational Codeforces Round 163 (Rated for Div. 2)")

There are multiple different approaches to this problem. We will describe a couple of them.

The key observation for this problem that works for all these approaches is that, since we never skip a move and never try to move outside the grid, we can split the cells into two groups:

* if the sum of coordinates of the cell is even (we will call it "even cell"), we can end up in such a cell only after moving along the arrow (only after the second action during each second);
* otherwise, if the sum of coordinates of the cell is odd (we will call it "odd cell"), we can end up in such a cell only after making a move on our own (only after the first action during each second).

Each movement leads us from one of these groups to the other group, that's why we always visit even cells after the second action and odd cells after the first action during each second.

Solution 1 (graph-based). Create a graph where each cell is represented by a vertex; if this is an even cell, then the robot can choose any direction from it, so we add directed arcs from it into all adjacent cells. If this is an odd cell, then the robot will be forced to move along the arrow in that cell, so we add only one directed arc from the corresponding vertex. Then we check if the vertex representing (2,n) is reachable from the vertex representing (1,1) via DFS or BFS.

Solution 2 (observation-based). We can try searching for a pattern that "blocks" our robot, i. e. does not let it advance further. If there are two adjacent by angle odd cells, which both have arrows leading to the left, then every path of the robot will pass through at least one of them; and every time it goes through one of them, it will be forced to the left. So any pair of odd <-type cells which share an angle (i. e. are on the same diagonal) means that the answer is NO. Otherwise, we can show that the answer is yes; the proof is based on the fact that for every even cell, either the cell in the same column or the cell to the right will contain an arrow leading to the right, so we can always go forward.

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
    vector<char> ok1(n / 2), ok2(n / 2);
    for (int i = 0; i < 2; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < n; ++j) if ((i + j) & 1) {
        ok1[(i + j) / 2] |= (s[j] == '>');
        ok2[(j - i + 1) / 2] |= (s[j] == '>');
      }
    }
    bool ans = true;
    for (int i = 0; i < n / 2; ++i) ans &= ok1[i] && ok2[i];
    cout << (ans ? "YES" : "NO") << 'n';
  }
}
```
[1948D - Tandem Repeats?](../problems/D._Tandem_Repeats_.md "Educational Codeforces Round 163 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1948D - Tandem Repeats?](../problems/D._Tandem_Repeats_.md "Educational Codeforces Round 163 (Rated for Div. 2)")

The key idea of the problem is to believe that no algorithms are required to solve the problem. Now, we can start looking for ways to iterate over all substrings so that it doesn't degenerate into O(n3).

One of the ways is the following. How to check if the substring [l;r) is a tandem repeat? Let d=r−l2. Then si should match (either be equal or one of them should be a question mark) si+d for all i from l to l+d exclusive.

If you iterate over the left border, then the right border of the substring, a lot of these checks change. However, if you iterate over the length d first, then over the left border, it becomes much easier. What changes when you go from checking [l;r) to checking [l+1;r+1)? One check is removed: sl matches sl+d is now irrelevant, since l doesn't belong to the substring anymore. One check is added: sl+d matches sr is required, since r belongs to the substring now.

So, the solution can be as follows: maintain the number of successful checks for the current substring [l;r). If that value is equal to d, then the substring is a tandem repeat, and you can update the answer with its length. Otherwise, subtract the contribution of the check (1 if it's successful, and 0 otherwise) for l and l+d, add the contribution for l+d and r and proceed to [l+1;r+1).

Overall complexity: O(n2) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
    s = input()
    n = len(s)
    ans = 0
    for d in range(1, n // 2 + 1):
        cnt = 0
        for i in range(n - d):
            cnt += s[i] == s[i + d] or s[i] == '?' or s[i + d] == '?'
            if i - d >= 0:
                cnt -= s[i - d] == s[i] or s[i - d] == '?' or s[i] == '?'
            if i - d >= -1 and cnt == d:
                ans = 2 * d
    print(ans)
```
[1948E - Clique Partition](../problems/E._Clique_Partition.md "Educational Codeforces Round 163 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1948E - Clique Partition](../problems/E._Clique_Partition.md "Educational Codeforces Round 163 (Rated for Div. 2)")

There are two main steps to solve the problem:

* analyzing the maximum size of a clique;
* showing a construction that always allows us to get a clique of the maximum possible size.

Firstly, the maximum size of a clique cannot exceed k. If there are at least k+1 vertices in the same clique, then at least two of them (call them i and j) have |i−j|≥k. And since ai≠aj, then |ai−aj|≥1. So, |i−j|+|ai−aj| is at least k+1, so these two vertices won't have an edge connecting them (and cannot belong to the same clique).

Secondly, let's try to find a construction that always allows us to get cliques of size k. To do this, try to solve the problem when k=n; and if n>k, we can split all vertices into ⌈nk⌉ cliques as follows: for each clique, we assign a consecutive block of vertices and numbers that will be assigned to them (for example, vertices from 1 to k and numbers from 1 to k belong to the first clique, vertices from k+1 to 2k and numbers from k+1 to 2kn belong to the second clique), and then use the solution for n=k on each of these blocks.

To obtain a solution for n=k, you can either try bruteforcing it locally on, say, n≤10 and analyzing the results. One of the possible constructions is as follows: let m=⌈k2⌉; split all vertices and numbers from 1 to k into two blocks: [1,m] and [m+1,k]; and then, in each block, the greater the index of the vertex, the less the integer it gets. So it looks as follows: a1=m,a2=m−1,…,am=1,am+1=n,am+2=n−1,…,an=m+1. We can show that the "distance" between any two vertices in different halves is exactly k, and the distance between any two vertices in the same half is at most 2(m−1), which never exceeds k.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), c(n);
    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        c[i] = i / k + 1;
    }
    int q = *max_element(c.begin(), c.end());
    for(int i = 1; i <= q; i++)
    {
        int l = find(c.begin(), c.end(), i) - c.begin();
        int r = c.rend() - find(c.rbegin(), c.rend(), i);
        int m = (l + r) / 2;
        reverse(a.begin() + l, a.begin() + m);
        reverse(a.begin() + m, a.begin() + r);
    }
    for(int i = 0; i < n; i++)
        cout << a[i] << " n"[i == n - 1];
    cout << q << "n";
    for(int i = 0; i < n; i++)
        cout << c[i] << " n"[i == n - 1];
}
 
int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
}
```
[1948F - Rare Coins](../problems/F._Rare_Coins.md "Educational Codeforces Round 163 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1948F - Rare Coins](../problems/F._Rare_Coins.md "Educational Codeforces Round 163 (Rated for Div. 2)")

To calculate the probability, we will calculate the number of ways to assign values to silver coins in such a way that the total value inside the segment is greater than the total value outside.

Let define x as the number of silver coins with value 1 inside the segment, y as the number of silver coins with value 1 outside, k as the difference between golden coins inside and outside the segment. Then the way to assign values to the coins is considered good if condition x−y+k>0 is met. 

We have an issue here: coins in the segment and coins outside the segment affect the inequality in different directions (that is, one of them increases the difference with a probability of 12, while others decrease with a probability of 12). It is not convenient for us.

So let's fix it, we can say that the coins inside the segment have value 1 by default, and with a probability of 12 are 0. And the coins outside the segment have value of 0 by default, and with a probability of 12 are 1. Then each of them, with a probability of 12, reduces the difference "total in the segment minus total outside the segment" by 1.

Thus, we have some starting value that decreases by 1 with a probability of 12 m times (where m is the total number of silver coins). And it is left to calculate the number of ways when the number of decreases is not big enough to break the inequality.

Let cur be the number of silver coins inside the segment. Then the starting value is st=k+cur and the number of ways to not break the inequality is equal to sum=st−1∑i=0(mi). And the answer to the problem is equal to sum2m.

Now we only need to consider how to answer queries faster than iterating from 0 to st. But thanks to the fact that the value of m is always the same, we can precalculate the prefix sums on these binomial coefficients.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 998244353;

int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

int mul(int x, int y) {
  return x * 1LL * y % MOD;
}

int binpow(int x, int y) {
  int z = 1;
  while (y) {
    if (y & 1) z = mul(z, x);
    x = mul(x, x);
    y >>= 1;
  }
  return z;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n), b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  vector<int> suma(n + 1), sumb(n + 1);
  for (int i = 0; i < n; ++i) {
    suma[i + 1] = suma[i] + a[i];
    sumb[i + 1] = sumb[i] + b[i];
  }
  int m = sumb[n];
  vector<int> f(m + 1), invf(m + 1);
  f[0] = 1;
  for (int i = 1; i <= m; ++i) f[i] = mul(f[i - 1], i);
  invf[m] = binpow(f[m], MOD - 2);
  for (int i = m; i > 0; --i) invf[i - 1] = mul(invf[i], i);
  vector<int> sumc(m + 2);
  for (int i = 0; i <= m; ++i)
    sumc[i + 1] = add(sumc[i], mul(f[m], mul(invf[i], invf[m - i])));
  int pw2 = binpow(binpow(2, MOD - 2), m);
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    int k = 2 * (suma[r] - suma[l]) - suma[n];
    int cur = sumb[r] - sumb[l];
    int mx = max(0, min(k + cur, m + 1));
    int cnt = sumc[mx];
    cout << mul(cnt, pw2) << ' ';
  }
}
```
[1948G - MST with Matching](../problems/G._MST_with_Matching.md "Educational Codeforces Round 163 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1948G - MST with Matching](../problems/G._MST_with_Matching.md "Educational Codeforces Round 163 (Rated for Div. 2)")

The key to solving this problem is applying Kőnig's theorem: in a bipartite graph, the size of the maximum matching is equal to the size of the minimum vertex cover. At the first glance it shouldn't work here, because our graph is not bipartite; however, when we leave only the edges belonging to the spanning tree we chose, it becomes bipartite. So instead of adding c to the cost of the tree for each edge in its maximum matching, we can add c to the cost of the tree for each vertex in its minimum vertex cover.

This allows us to try iterating on that vertex cover. Let's fix a set of vertices S, say that this is the minimum vertex cover, and the second part of the cost is equal to c⋅|S|. How to build a minimum-cost spanning tree which has S as its minimum vertex cover? Well, that's not really easy to do; but instead, we can build a minimum-cost spanning tree which has S as one of its vertex covers (not necessarily minimum). The fact that there might be some other vertex cover of smaller size for the tree doesn't really matter, because we can generate this tree again using a smaller set of vertices as its vertex cover.

So, how do we build a minimum spanning tree such that S is its vertex cover? This is actually easy: we forbid all edges such that none of their endpoints are in S (because they can't be covered), and use any regular MST algorithm on all edges we have not forbidden. If we use Prim's algorithm, we get a solution in O(2n⋅n2), which is fast enough to pass the time limit. Kruskal's algorithm with DSU might be a bit slower, but can also get accepted.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int n, c;
int g[21][21];

const int INF = int(1e9);

int primMST(int vertex_cover_mask)
{
    vector<int> d(n, INF);
    vector<bool> used(n, false);
    d[0] = 0;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int idx = -1;
        for(int j = 0; j < n; j++)
        {
            if(!used[j] && d[j] < INF && (idx == -1 || d[j] < d[idx]))
                idx = j;
        }
        if(idx == -1) return INF;
        used[idx] = true;
        ans += d[idx];
        for(int k = 0; k < n; k++)
        {
            if(used[k]) 
                continue;
            if((vertex_cover_mask & (1 << idx)) == 0 && (vertex_cover_mask & (1 << k)) == 0)
                continue;
            d[k] = min(d[k], g[idx][k]);
        }
    }
    return ans;
}

int main()
{
    cin >> n >> c;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> g[i][j];
            if(g[i][j] == 0) g[i][j] = INF;
        }
    }
    int ans = INF;
    for(int mask = 0; mask < (1 << n); mask++)
    {
        int cur = primMST(mask);
        if(cur != INF) ans = min(ans, cur + c * __builtin_popcount(mask));
    }
    cout << ans << endl;
}
```
