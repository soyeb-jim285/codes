# T_(en)

Enjoy!

 **A. Balanced Rating Changes**
### [1237A - Balanced Rating Changes](../problems/A._Balanced_Rating_Changes.md "Codeforces Global Round 5")

Let $b_i = \frac{a_i}{2} + \delta_i$. It follows that if $a_i$ is even, then $\delta_i = 0$, and if $a_i$ is odd, then either $\delta_i = \frac{1}{2}$ or $\delta_i = -\frac{1}{2}$.

At the same time, the sum of $b_i$ is equal to the sum of $\delta_i$, as the sum of $a_i$ is $0$. Thus, as the sum of $b_i$ must be equal to $0$, we need to have an equal number of $\delta_i$ equal to $\frac{1}{2}$ and $-\frac{1}{2}$.

In simple words, we have to divide all numbers by $2$, and out of all non-integers, exactly half of them must be rounded up and the other half must be rounded down.

 **Solution by tourist**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int flag = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      cout << x / 2 << 'n';
    } else {
      cout << (x + flag) / 2 << 'n';
      flag *= -1;
    }
  }
  return 0;
}
```
 **B. Balanced Tunnel**
### [1237B - Balanced Tunnel](../problems/B._Balanced_Tunnel.md "Codeforces Global Round 5")

This problem can be approached in several ways, here is one of them.

Let's say that cars exit the tunnel at time moments $1, 2, \ldots, n$, and let $c_i$ be time when car $a_i$ exited the tunnel.

For instance, in the first example we had $a = \langle 3, 5, 2, 1, 4 \rangle$ and $b = \langle 4, 3, 2, 5, 1 \rangle$. Then, $c = \langle 2, 4, 3, 5, 1 \rangle$: car $3$ entered first and exited at time $2$, so $c_1 = 2$; car $5$ entered second and exited and time $4$, so $c_2 = 4$; and so on.

Note that $c$ is a permutation, and not only it can be found in $O(n)$, but also it can be very useful for us. It turns out that we can use $c$ to easily determine if car $a_i$ must be fined.

Specifically, car $a_i$ must be fined if $c_i$ is smaller than $\max(c_1, c_2, \ldots, c_{i-1})$.

Why is that? Recall that car $a_i$ must be fined if there exists a car that entered the tunnel earlier and exited the tunnel later. If a car entered the tunnel earlier, it must be $a_j$ such that $j < i$. If a car exited the tunnel later, it must be that $c_j > c_i$.

Therefore, now we can just go from left to right, keeping the maximum of $c_1, c_2, \ldots, c_{i-1}$ to compare it to $c_i$. The overall complexity is $O(n)$.

 **Solution by tourist**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    --b[i];
  }
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    pos[b[i]] = i;
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    c[i] = pos[a[i]];
  }
  int mx = -1, ans = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] > mx) {
      mx = c[i];
    } else {
      ++ans;
    }
  }
  cout << ans << 'n';
  return 0;
}
```
 **C1. Balanced Removals (Easier)**
### [1237C1 - Balanced Removals (Easier)](../problems/C1._Balanced_Removals_(Easier).md "Codeforces Global Round 5")

Pick any two points $i$ and $j$, let's say that this is our candidate pair $(i, j)$ for removal. Loop over all other points. If some point $k$ lies inside the bounding box of $i$ and $j$, change our candidate pair to $(i, k)$. Note that the bounding box of $i$ and $k$ lies inside the bounding box of $i$ and $j$, so we don't need to recheck points that we have already checked. The candidate pair we get at the end of the loop can surely be removed.

Another look at the situation is that we can pick any point $i$, and then pick point $j$ that is the closest to point $i$, either by Euclidean or Manhattan metric. Pair $(i, j)$ can be removed then, as if any point $k$ lies inside the bounding box of $i$ and $j$, it's strictly closer to $i$ than $j$.

Both of these solutions work in $O(n^2)$.

 **Solution by arsijo**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<pair<int, int>, pair<int, int> > ii;

int main(){
    int n;
    cin >> n;
    
    vector<ii> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].first.first >> v[i].first.second >> v[i].second.first;
        v[i].second.second = i + 1;
    }
    
    while(!v.empty()){
        sort(v.begin(), v.end());
        int x = v.back().first.first;
        int y = v.back().first.second;
        int z = v.back().second.first;
        int pos = v.back().second.second;
        v.pop_back();
        int ind = 0;
        ll d = 1e10;
        for (int i = 0; i < (int) v.size(); i++){
            ll dist = abs(v[i].first.first - x);
            dist += abs(v[i].first.second - y);
            dist += abs(v[i].second.first - z);
            if (dist < d){
                d = dist;
                ind = i;
            }
        }
        cout << pos << " " << v[ind].second.second << endl;
        v.erase(v.begin() + ind);
    }
}
```
 **C2. Balanced Removals (Harder)**
### [1237C2 - Сбалансированные удаления (посложнее)](../problems/C2._Balanced_Removals_(Harder).md "Codeforces Global Round 5")

Consider a one-dimensional version of the problem where $n$ is not necessarily even. We can sort all points by their $x$-coordinate and remove them in pairs. This way, we'll leave at most one point unremoved.

Now, consider a two-dimensional version of the problem where $n$ is not necessarily even. For each $y$, consider all points that have this $y$-coordinate and solve the one-dimensional version on them. After we do this, we'll have at most one point on each $y$ left. Now we can sort the points by $y$ and remove them in pairs in this order. Again, we'll leave at most one point unremoved.

Finally, consider a three-dimensional version of the problem. Again, for each $z$, consider all points that have this $z$-coordinate and solve the two-dimensional version on them. After we do this, we'll have at most one point on each $z$ left. Now we can sort the points by $z$ and remove them in pairs in this order.

We can even generalize this solution to any number of dimensions and solve the problem in $O(dn \log n)$.

 **Solution by tourist**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int D = 3;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> p(n, vector<int>(D));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < D; j++) {
      cin >> p[i][j];
    }
  }
  auto Solve = [&](auto& Self, vector<int> ids, int k) {
    if (k == D) {
      return ids[0];
    }
    map<int, vector<int>> mp;
    for (int x : ids) {
      mp[p[x][k]].push_back(x);
    }
    vector<int> a;
    for (auto& q : mp) {
      int cur = Self(Self, q.second, k + 1);
      if (cur != -1) {
        a.push_back(cur);
      }
    }
    for (int i = 0; i + 1 < (int) a.size(); i += 2) {
      cout << a[i] + 1 << " " << a[i + 1] + 1 << 'n';
    }
    return (a.size() % 2 == 1 ? a.back() : -1);
  };
  vector<int> t(n);
  iota(t.begin(), t.end(), 0);
  Solve(Solve, t, 0);
  return 0;
}
```
 **D. Balanced Playlist**
### [1237D - Balanced Playlist](../problems/D._Balanced_Playlist.md "Codeforces Global Round 5")

This problem allowed a lot of approaches.

First, to determine if the answer is all $-1$, compare half of maximum $x_i$ and minimum $x_i$.

Second, note that during the first $n$ tracks, we'll listen to the track with maximum $x_i$, and during the next $n$ tracks, we'll stop at the track with minimum $x_i$. Thus, to pretend that the cyclic playlist is linear, it's enough to repeat it three times.

For each track $i$, let's find the next track $j$ with coolness more than $x_i$, and the next track $k$ with coolness less than $\frac{x_i}{2}$. Then it's easy to see that if $j < k$, we have $c_i = c_j + j - i$, and if $j > k$, we have $c_i = k - i$.

Thus, all that remains is to find the next track after every track $i$ whose coolness lies in some segment of values. This can be done with binary search over segment tree in $O(n \log^2 n)$, binary search over sparse table in $O(n \log n)$, binary search over stack in $O(n \log n)$ as well... Alternatively, if we go through tracks in increasing/decreasing order of coolness, we can also answer these queries with two pointers and a structure like C++ set or Java TreeSet.

Bonus: solve the problem in $O(n)$.

 **Solution by tourist**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(3 * n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i + n] = a[i + 2 * n] = a[i];
  }
  vector<int> ans(3 * n);
  vector<int> st_max;
  vector<int> st_min;
  for (int i = 3 * n - 1; i >= 0; i--) {
    while (!st_max.empty() && a[st_max.back()] < a[i]) {
      st_max.pop_back();
    }
    while (!st_min.empty() && a[st_min.back()] > a[i]) {
      st_min.pop_back();
    }
    int low = 0, high = (int) st_min.size();
    while (low < high) {
      int mid = (low + high) >> 1;
      if (a[st_min[mid]] * 2 < a[i]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    int nxt = 3 * n;
    if (low > 0) {
      nxt = min(nxt, st_min[low - 1]);
    }
    if (!st_max.empty()) {
      nxt = min(nxt, st_max.back());
    }
    if (nxt < 3 * n && a[nxt] >= a[i]) {
      ans[i] = ans[nxt];
    } else {
      ans[i] = nxt;
    }
    st_min.push_back(i);
    st_max.push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << (ans[i] == 3 * n ? -1 : ans[i] - i);
  }
  cout << 'n';
  return 0;
}
```
 **E. Balanced Binary Search Trees**
### [1237E - Balanced Binary Search Trees](../problems/E._Balanced_Binary_Search_Trees.md "Codeforces Global Round 5")

Consider perfectly balanced striped BSTs of some maximum depth $d$. Note that both the left and the right subtree of the root must be perfectly balanced striped BSTs of maximum depth $d-1$. Also note that the parity of the root must be equal to the parity of $n$, as $n$ lies on the rightmost branch of the tree; thus, the size of the right subtree must be even.

Consider trees of maximum depth $2$: there is one with $n = 4$ and one with $n = 5$. A tree of maximum depth $3$ can have its right subtree of size $4$ only, and its left subtree can have size $4$ or $5$; thus, we have one tree with $n = 9$ and one with $n = 10$.

Using induction, we can prove that for any maximum depth $d$, we have exactly two possible trees, of sizes $x$ and $x + 1$ for some $x$. We can enumerate these trees and check if $n$ belongs to the set of possible sizes in $O(\log n)$.

 **Solution by tourist**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int x = 1;
  while (x <= n) {
    if (n == x || n == x + 1) {
      cout << 1 << 'n';
      return 0;
    }
    if (x % 2 == 0) {
      x = x + 1 + x;
    } else {
      x = (x + 1) + 1 + x;
    }
  }
  cout << 0 << 'n';
  return 0;
}
```
 **F. Balanced Domino Placements**
### [1237F - Balanced Domino Placements](../problems/F._Balanced_Domino_Placements.md "Codeforces Global Round 5")

Suppose we're going to place $d_h$ extra horizontal dominoes and $d_v$ extra vertical ones. Consider all rows of the grid, and mark them with $0$ if it's empty and with $1$ if it already has a covered cell. Do the same for columns.

Now, let's find the number of ways $R$ to pick $d_h$ rows marked with $0$, and also $d_v$ pairs of neighboring rows marked with $0$, so that these sets of rows don't intersect. Similarly, let's find the number of ways $C$ to pick $d_h$ pairs of columns marked with $0$, and also $d_v$ columns marked with $0$. Then, the number of ways to place exactly $d_h$ horizontal dominoes and $d_v$ vertical ones is $R \cdot C \cdot d_h! \cdot d_v!$.

To find $R$, let's use DP: let $f(i, j)$ be the number of ways to pick $j$ pairs of neighboring rows out of the first $i$ rows. Then, $f(i, j) = f(i - 1, j)$ if any of rows $i$ or $i-1$ is marked with $1$, and $f(i, j) = f(i - 1, j) + f(i - 2, j - 1)$ if both are marked with $0$. It follows that $R = f(h, d_v) * \binom{h - 2d_v}{d_h}$. $C$ can be found similarly.

The complexity of this solution is $O((R+C)^2)$.

 **Solution by arsijo**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
const int MAX = 3610;
ll dp1[MAX][MAX], dp2[MAX][MAX];
int has1[MAX], has2[MAX];
ll fac[MAX], c[MAX][MAX];
int n, m, k;

void make(int n){
    dp1[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            dp1[i][j] = dp1[i - 1][j];
            if (j && i >= 2 && has1[i] == 0 && has1[i - 1] == 0){
                dp1[i][j] += dp1[i - 2][j - 1];
            }
            dp1[i][j] %= MOD;
        }
    }
}

int main(){
    cin >> n >> m >> k;
    int t = max(n, m) + 1;
    vector<ll> f(t);
    for (int i = 1; i <= k; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (has1[a] || has1[c] || has2[b] || has2[d]){
            cout << 0 << endl;
            return 0;
        }
        has1[a] = has1[c] = has2[b] = has2[d] = 1;
    }
    int N = n, M = m;
    for (int i = 1; i <= n; i++){
        N -= has1[i];
    }
    for (int i = 1; i <= m; i++){
        M -= has2[i];
    }
    make(n);
    swap(dp1, dp2);
    swap(has1, has2);
    make(m);
    swap(dp1, dp2);
    swap(has1, has2);
    c[0][0] = 1;
    f[0] = 1;
    for (int i = 1; i < t; i++){
        f[i] = (f[i - 1] * i) % MOD;
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++){
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] >= MOD){
                c[i][j] -= MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; (i << 1) <= N; i++){
        for (int j = 0; (j << 1) <= M; j++){
            int have1 = N - 2 * i;
            int have2 = M - 2 * j;
            ll res = dp1[n][i] * dp2[m][j];
            res %= MOD;
            res *= c[have1][j];
            res %= MOD;
            res *= c[have2][i];
            res %= MOD;
            res *= f[i];
            res %= MOD;
            res *= f[j];
            res %= MOD;
            ans += res;
        }
    }
    ans %= MOD;
    cout << ans << endl;
}
```
 **G. Balanced Distribution**
### [1237G - Balanced Distribution](../problems/G._Balanced_Distribution.md "Codeforces Global Round 5")

Let $A$ be the average of $a_i$, and let $p_i$ be the sum of $a_0, a_1, \ldots, a_i$ minus $A$ times $i+1$.

Consider a pair of friends $i$ and $(i+1) \bmod n$ that never attend the same meeting. Then we can make a "cut" between them to transform the circle into a line. Consider some other pair of friends $j$ and $(j+1) \bmod n$ with the same property. Now we can cut our line into two segments. As these segments never interact with each other, we must have $p_i = p_j$ if we want the problem to be solvable. Similarly, for all "cuts" we do, between some pairs $k$ and $(k+1) \bmod n$, the value of $p_k$ must be the same.

Now, considering some value $x$, let's make cuts at all positions $i$ with $p_i = x$. The circle is cut into several segments. For a segment of length $l$, I claim that it can always be balanced in $\lceil \frac{l-1}{k-1} \rceil$ meetings. Let's trust this for a while.

If we carefully look at the formulas, we may note that if a segment has length $l$ such that $l \neq 1 (\bmod (k-1))$, it can be merged to any neighboring segment without increasing the number of meetings.

It follows that we either make just one cut anywhere, or in the sequence of $i \bmod (k-1)$ for $i$ with $p_i = x$, we need to find the longest subsequence of $(0, 1, \ldots, k-2)*$ in cyclic sense. This can be done, for example, with binary lifting. The complexity of this step will be proportional to $O(c \log c)$, where $c$ is the number of positions with $p_i = x$.

Thus, for any value of $x$, we can find the smallest number of meetings we need if we only make cuts at positions with $p_i = x$ in $O(n \log n)$ overall, and we can pick the minimum over these.

It remains to show that we can balance any segment of length $l$ in $\lceil \frac{l-1}{k-1} \rceil$ meetings. Consider the $k$ leftmost positions. If we have at least $(k-1) \cdot A$ stones there, then we can make a meeting on these positions, send whatever remains to the $k$-th leftmost position, and proceed inductively. If we have less than $(k-1) \cdot A$ stones there, let's solve the problem for the rightmost $l-k+1$ positions first, with the goal of sending all the extra stones to the $k$-th leftmost position. This is similar to what we usually want to do, so again we can proceed inductively to reach the goal on the right first, and then conduct a meeting on the $k$ leftmost positions, this time having enough stones to satisfy the demand.

 **Solution by KAN**
```cpp
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 200005;
const int maxk = 19;
const int inf = 1e9;

ll a[2 * maxn];
ll psum[2 * maxn];
pair2<int> go[maxk][2 * maxn];
map<ll, int> lst[maxn];
int id[2 * maxn];
int n, k;
ll need;
vector<pair<int, vector<ll>>> answer;

void perform(int l)
{
    int fn = min(l + k, n);
    assert(psum[fn] >= 0);
    ll wassum = psum[fn];
    vector<ll> exchange = vector<ll>(k, need);
    int start = min(n - k, l);
    for (int i = start; i < l; i++) exchange[i - start] = need + a[i];
    exchange[l - start] += -psum[l];
    exchange.back() += psum[fn];
    answer.pb({start, exchange});
    for (int i = l; i < fn; i++) a[i] = 0;
    a[l] += -psum[l];
    a[fn - 1] += psum[fn];
    for (int i = start; i < start + k; i++) psum[i + 1] = psum[i] + a[i];
    assert(wassum == psum[fn]);
}

void restore(int l)
{
    if (l >= n) return;
    if (a[l] == 0 && psum[l] == 0)
    {
        restore(l + 1);
        return;
    }
    int fn = min(l + k, n);
    if (psum[fn] >= 0)
    {
        perform(l);
        restore(l + k - (psum[fn] > 0));
        return;
    } else
    {
        restore(l + k - 1);
        assert(psum[fn] == 0);
        perform(l);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    need = accumulate(a, a + n, 0LL);
    assert(need % n == 0);
    need /= n;
    for (int i = 0; i < n; i++) a[i] -= need;
    for (int i = 0; i < n; i++) a[i + n] = a[i];
    partial_sum(a, a + 2 * n, psum + 1);
    pair2<int> ans = {inf, -1};
    for (int j = 0; j < maxk; j++) go[j][2 * n] = {2 * n, 0};
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int curid = id[i + 1];
        if (lst[curid].count(psum[i]))
        {
            int to = lst[curid][psum[i]];
            go[0][i] = {to, (to - i - 1) / (k - 1)};
        } else
        {
            int to = 2 * n;
            go[0][i] = {to, (to - i + k - 2) / (k - 1)};
        }
        for (int j = 1; j < maxk; j++) go[j][i] = {go[j - 1][go[j - 1][i].fi].fi, go[j - 1][i].se + go[j - 1][go[j - 1][i].fi].se};
        
        if (i < n)
        {
            int to = n + i;
            int cur = i;
            int curans = 0;
            for (int j = maxk - 1; j >= 0; j--) if (go[j][cur].fi <= to)
            {
                curans += go[j][cur].se;
                cur = go[j][cur].fi;
            }
            if (cur < to) curans += (to - cur - 1 + k - 2) / (k - 1);
            ans = min(ans, {curans, i});
        }
        
        id[i] = (2 * n - i) % (k - 1);
        lst[id[i]][psum[i]] = i;
    }
    
    rotate(a, a + ans.se, a + n);
    partial_sum(a, a + n, psum + 1);
    restore(0);
    
    assert((int)answer.size() == ans.fi);
    printf("%dn", (int)answer.size());
    for (auto &t : answer)
    {
        printf("%d", (t.fi + ans.se) % n);
        for (auto tt : t.se) printf(" %lld", tt);
        printf("n");
    }
    return 0;
}
```
 **H. Balanced Reversals**
### [1237H - Balanced Reversals](../problems/H._Balanced_Reversals.md "Codeforces Global Round 5")

Unfortunately, solutions used by most participant are different from what I expected. Here is the intended solution that works in exactly $n+1$ reversals.

Let's form string $b$ from right to left at the front of string $a$. For each $i = 2, 4, 6, \ldots, n$, we'll make some reversals so that $a[1..i] = b[n-i+1..n]$. For each $i$, we need to move the first $i-2$ characters by two characters to the right, and place some correct pair of characters at the front.

Consider some pair of characters at positions $x$ and $x+1$, where $x \bmod 2 = 1$ and $x > i$. What if we perform two reversals: first, reverse prefix of length $x-1$, then, reverse prefix of length $x+1$? The answer is: characters $x$ and $x+1$ will move to the beginning of $a$ in reverse order, while all the other characters will not change their relative positions.

OK, what if we need to put some pair $00$ or $11$ to the front? Then we can just pick any $00$ or $11$ pair to the right of position $i$ and move it to the front in two steps, that's easy enough.

It becomes harder when we need some pair $01$ or $10$ to get to the front. We might not have a suitable corresponding $10$ or $01$ pair in store, so we might need to use three steps here. Let's call this situation undesirable.

Let's get back to the initial situation. Suppose that the number of $01$ pairs in $a$ matches the number of $10$ pairs in $b$. Then we'll never get into an undesirable situation. Let's call this initial situation handy.

What if these counts don't match? Then we can actually make them match using just one reversal. Specifically, pick a string out of $a$ and $b$ that has higher absolute difference of counts of $01$ and $10$, and it turns out, due to some monotonicity, that we can always find a prefix to reverse to make our initial situation handy. (Note that when I say that we can reverse a prefix in $b$, that's equivalent to reversing the same prefix in $a$ as the last reversal.)

Thus, we can solve the problem in $n+1$ reversals: one reversal to make the initial situation handy, and then $n/2$ times we make at most two reversals each step without ever getting into an undesirable situation.

 **Solution by KAN**
```cpp
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 4005;

vector<int> ss, tt;
char s[maxn], t[maxn];
int n;
vector<int> answer;
int cnt[5];

vector<int> prepare(char *s)
{
    vector<int> ans;
    for (int i = 0; i < 2 * n; i += 2) ans.pb((s[i] - '0') * 2 + (s[i + 1] - '0'));
    return ans;
}

inline void addanswer(int x)
{
    if (x <= 0) return;
    answer.pb(x);
}

void doreverse(vector<int> &v, int l)
{
    reverse(v.begin(), v.begin() + l);
    for (int j = 0; j < l; j++) if (v[j] >= 1 && v[j] <= 2)
    {
        v[j] = 3 - v[j];
    }
}

int main()
{
    int NT;
    scanf("%d", &NT);
    for (int T = 0; T < NT; T++)
    {
        scanf("%s%s", s, t);
        n = strlen(s) / 2;
        ss = prepare(s);
        tt = prepare(t);
        for (auto &t : tt) if (t == 1 || t == 2) t = 3 - t;
        cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
        for (auto t : ss) cnt[t]++;
        for (auto t : tt) cnt[t]--;
        if (cnt[0] != 0 || cnt[3] != 0)
        {
            printf("-1n");
            continue;
        }
        bool found = cnt[1] == 0;
        int before = -1;
        int after = -1;
        for (int i = 1; i <= n && !found; i++)
        {
            cnt[ss[i - 1]]--;
            cnt[3 - ss[i - 1]]++;
            if (cnt[1] == 0)
            {
                before = 2 * i;
                doreverse(ss, i);
                found = true;
            }
        }
        if (!found)
        {
            for (int i = 1; i <= n; i++)
            {
                cnt[ss[i - 1]]++;
                cnt[3 - ss[i - 1]]--;
            }
        }
        for (int i = 1; i <= n && !found; i++)
        {
            cnt[tt[i - 1]]++;
            cnt[3 - tt[i - 1]]--;
            if (cnt[1] == 0)
            {
                after = 2 * i;
                doreverse(tt, i);
                found = true;
            }
        }
        assert(found);
        
        answer.clear();
        addanswer(before);
        for (int i = n - 1; i >= 0; i--)
        {
            int wh = -1;
            for (int j = n - 1 - i; j < n; j++) if (ss[j] == tt[i]) wh = j;
            addanswer(2 * wh);
            doreverse(ss, wh);
            addanswer(2 * wh + 2);
            doreverse(ss, wh + 1);
        }
        addanswer(after);
        
        for (auto t : answer) reverse(s, s + t);
        assert(strcmp(s, t) == 0);
        
        printf("%d ", (int)answer.size());
        for (auto t : answer) printf("%d ", t);
        printf("n");
    }
    return 0;
}
```
