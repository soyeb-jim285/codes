# Tutorial_(en)

We hoped you find our problems interesting. We apologize for the late editorial. Hopefully you were still able to enjoy our contest. 

Anyway, here are the tutorials for each of the problems:

### [1397A - Juggling Letters](https://codeforces.com/contest/1397/problem/A "Codeforces Round 666 (Div. 2)")

If the total number of occurrences of some character cc is not a multiple of nn, then it is impossible to make all nn strings equal — because then it is impossible for all nn strings to have the same number of cc.

On the other hand, if the total number of occurrences of every character cc is a multiple of nn, then it is always possible to make all nn strings equal. To achieve this, for every character cc we move exactly ((the total number of occurrences of cc) // nn) characters cc to the end of each string, and by the end we will have all nn strings equal each other.

We can easily check if the condition satisfies by counting the total number of occurrences of each character cc and check its divisibility by nn. The final complexity is O(S⋅26)O(S⋅26) or O(S)O(S) where SS is the sum of lengths of all strings.

 **C++ solution**
```cpp
  
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;

		vector<int> cnt(26);
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			for (char ch : s) {
				++cnt[ch - 'a'];
			}
		}

		bool ans = true;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i] % n != 0) {
				ans = false;
				break;
			}
		}

		cout << (ans ? "YES" : "NO") << endl;
	}
}
```
 **Python solution**
```cpp
numTests = int(input())
for testNo in range(numTests):
	n = int(input())
	cnt = [0 for i in range(26)]
	for _ in range(n):
	    s = input()
	    for i in s:
	        cnt[ord(i) - 97] += 1

	ans = True
	for i in range(26):
	    if cnt[i] % n != 0:
	        ans = False
	        break

	if ans:
	    print('YES')
	else:
	    print('NO')
```
### [1397B - Power Sequence](https://codeforces.com/contest/1397/problem/B "Codeforces Round 666 (Div. 2)")

First of all, the optimal way to reorder is to sort aa in non-decreasing order.

 **Proof**Note that the cost the transform ai to ci is |ai−ci|. While there is a pair (ai,aj) such that i<j and ai>aj, swap ai and aj. Since |x|+|y|=max{|x+y|,|x−y|}, we have 

|ai−ci|+|aj−cj| 

=max{|(ai+aj)−(ci+cj)|,|(ai−aj)−(ci−cj)|} 

≥max{|(aj+ai)−(ci+cj)|,|(aj−ai)−(ci−cj)|}

=|aj−ci|+|ai−cj|

when ai>aj and ci≤cj, so the total cost does not increase. Hence, it is best to have a0≤a1≤⋯≤an−1.

From now on, we assume aa is sorted in non-decreasing order.

Denote amax=an−1amax=an−1 as the maximum value in aa, f(x)=∑|ai−xi|f(x)=∑|ai−xi| as the minimum cost to transform aa into x0,x1,⋯,xn−1x0,x1,⋯,xn−1, and cc as the value where f(c)f(c) is minimum.

Note that cn−1−amax≤f(c)≤f(1)cn−1−amax≤f(c)≤f(1), which implies cn−1≤f(1)+amaxcn−1≤f(1)+amax.

We enumerate xx from 1,2,3,…1,2,3,… until xn−1xn−1 exceeds f(1)+amaxf(1)+amax, calculate f(x)f(x) in O(n)O(n), and the final answer is the minimum among all calculated values. The final complexity is O(n⋅max(x))O(n⋅max(x)).

But why doesn't this get TLE? Because f(1)=∑(ai−1)<amax⋅n≤109⋅nf(1)=∑(ai−1)<amax⋅n≤109⋅n, thus xn−1≤f(1)+amax≤109⋅(n+1)xn−1≤f(1)+amax≤109⋅(n+1). When n=3,4,5,6n=3,4,5,6, max(x)max(x) does not exceed 63245,1709,278,9363245,1709,278,93 respectively; so we can see that O(n⋅max(x))O(n⋅max(x)) comfortably fits in the time limit.

 **C++ solution**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int64_t INF = 1e17;
inline int64_t mul(int64_t a, int64_t b)
{
	return (INF / a > b ? a * b : INF);
}

inline int64_t add(int64_t a, int64_t b)
{
	return (a + b >= INF ? INF : a + b);
}

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int &x : a) cin >> x;
	sort(a.begin(), a.end());

	if (n <= 2) {
		cout << a[0] - 1 << endl;
	} else {
		int64_t ans = accumulate(a.begin(), a.end(), 0ll) - n;

		for (int x = 1; ; ++x) {
			int64_t curPow = 1, curCost = 0;
			for (int i = 0; i < n; ++i) {
				curCost = add(curCost, abs(a[i] - curPow));
				curPow = mul(curPow, x);
			}

			if (curPow == INF || curPow / x > ans + a[n - 1]) break;
			ans = min(ans, curCost);
		}

		cout << ans << endl;
	}
}
```
 **Python solution**
```cpp
n = int(input())
a = [int(x) for x in input().split()]
a.sort()
inf = 10**18

if n <= 2:
    print(a[0] - 1)
else:
    ans = sum(a) - n

    for x in range(1, 10**9):
        curPow = 1
        curCost = 0
        for i in range(n):
            curCost += abs(a[i] - curPow)
            curPow *= x
            if curPow > inf:
                break

        if curPow > inf:
            break
        if curPow / x > ans + a[n - 1]:
            break

        ans = min(ans, curCost)

    print(ans)
```
### [1396A - Multiples of Length](../problems/A._Multiples_of_Length.md "Codeforces Round 666 (Div. 1)")

In this problem, the answer is rather simple. Here is one possible solution to this task.

 **Solution for n = 1**1  1  
0  
1  1  
0  
1  1  
−a1

 **Solution for n != 1**1  1  
−a1  
1  n  
0, −n⋅a2, −n⋅a3, …, −n⋅an  
2  n  
(n−1)⋅a2, (n−1)⋅a3, …, (n−1)⋅an

 **C++ solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N;
   cin >> N;
   vector<ll> A(N);
   for (int i = 0; i < N; ++i) cin >> A[i];
   if (N == 1) {
      for (int z = 0; z < 3; ++z) {
         cout << "1 1n";
         cout << -A[0] << "n";
         A[0] = 0;
      }
      return 0;
   }
   cout << "1 " << N << "n";
   for (int i = 0; i + 1 < N; ++i) cout << -A[i] * N << " "; cout << "0n";
   cout << "1 " << N - 1 << "n";
   for (int i = 0; i + 1 < N; ++i) cout << A[i] * (N - 1) << " "; cout << "n";
   cout << N << " " << N << "n";
   cout << -A[N - 1] << "n";
   return 0;
}
```
 **Python solution**
```cpp
n = int(input())
a = list(map(int, input().split()))

if n == 1:
    print('1 1', -a[0], '1 1', '0', '1 1', '0', sep='n')
    exit(0)

print(1, n)
for i in range(n):
    print(-a[i] * n, end = ' ')
    a[i] -= a[i] * n
print()

print(1, n - 1)
for i in range(n - 1):
    print(-a[i], end = ' ')
    a[i] = 0
print()

print(2, n)
for i in range(1, n):
    print(-a[i], end = ' ')
    a[i] = 0
print()
```
### [1396B - Stoned Game](../problems/B._Stoned_Game.md "Codeforces Round 666 (Div. 1)")

Let us denote SS as the current total number of stones. 

Consider the following cases:

**Case A: There is a pile that has more than ⌊S2⌋⌊S2⌋ stones.**

The first player (T) can always choose from this pile, thus he (T) is the winner.

**Case B: Every pile has at most ⌊S2⌋⌊S2⌋ stones, and SS is even.**

It can be proven that the second player (HL) always wins.

 **Proof 1**Let us prove by induction:

When S=0, the second player obviously wins. 

When S≥2, consider the game state after the first player moves. If there is a pile that now has more than ⌊S2⌋ stones, then we arrive back at *case A* where the next player to move wins. Otherwise, the second player can choose from any valid pile (note that the case condition implies that there are at least two non-empty piles before the first player's move). Now S has been reduced by 2, and every pile still has at most ⌊S2⌋ stones.

 **Proof 2**The condition allows us to assign a perfect matching of stones, where one stone is matched with exactly one stone from a different pile. 

A greedy way to create such a matching: Give each label 0,1,…,S−1 to a different stone so that for every pair of stones with labels l<r that are from the same pile, stones l+1,l+2,…,r−1 are also from that pile; then match stones i with i+S2 for all 0≤i<S2.

For every stone that the first player removes, the second player can always remove its matching stone, until the first player can no longer make a move and loses.

**Case C: Every pile has at most ⌊S2⌋⌊S2⌋ stones, and SS is odd.**

The first player (T) can choose from any pile, and we arrive back at *case B* where the next player to move loses. 

So the first player (T) wins if and only if there is a pile that has more than ⌊S2⌋⌊S2⌋ stones or SS is odd. This can be easily checked in O(n)O(n).

 **C++ solution**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int &x : a) cin >> x;

		int maxPile = *max_element(a.begin(), a.end());
		int numStones = accumulate(a.begin(), a.end(), 0);

		if (maxPile * 2 > numStones || (numStones & 1)) cout << "T" << endl;
		else cout << "HL" << endl;
	}
}
```
 **Python solution**
```cpp
t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]

    maxPile = max(a)
    numStones = sum(a)

    if maxPile * 2 > numStones or (numStones & 1):
        print('T')
    else:
        print('HL')
```
### [1396C - Monster Invaders](../problems/C._Monster_Invaders.md "Codeforces Round 666 (Div. 1)")

In this problem, it is useful to note that when the boss only has 11 hp left, just use the pistol because it has the least reloading time. So there are 3 strategies we will use when playing at stage ii (1≤i≤n)(1≤i≤n):

 * Take aiai pistol shots to kill first aiai monsters and shoot the boss with the AWP.
* Take ai+1ai+1 pistol shots and move back to this stage later to take another pistol shot to finish the boss.
* Use the laser gun and move back to this stage later to kill the boss with a pistol shot.

**Observation:** We will always finish the game at stage nn or n−1n−1. Considering we are at stage ii (i≤n−1)(i≤n−1) and the boss at both stage ii stage i−1i−1 has 11 hp left, we can spend 2∗d2∗d time to finish both these stages instead of going back later, which costs us exactly the same.

Therefore, we will calculate dp(i,0/1)dp(i,0/1) as the minimum time to finish first i−1i−1 stages and 0/1 is the remaining hp of the boss at stage ii. The transitions are easy to figure out by using 3 strategies as above. The only thing we should note is that we can actually finish the game at stage n−1n−1 by instantly kill the boss at stage nn with the AWP so we don't have to go back to this level later.

Answer to the problem is dp(n,0)dp(n,0). Time complexity: O(n)O(n).

 **C++ solution**
```cpp
/*input
4 2 4 4 1
4 5 1 2
*/
#include <bits/stdc++.h>
using namespace std;

int read() {
	int x = 0, c = getchar();
	for(; !(c > 47 && c < 58); c = getchar());
	for(; (c > 47 && c < 58); c = getchar()) x = x * 10 + c - 48;
	return x;
}

void upd(long long &a, long long b) {
	a = (a < b) ? a : b;
}

const int N = 1e6 + 5;

long long f[N][2];
int n, r1, r2, r3, d, a[N];

int main(){ 
	n = read(), r1 = read(), r2 = read(), r3 = read(), d = read();
	for(int i = 1; i <= n; a[i ++] = read());

	for(int i = 2; i <= n; ++ i) f[i][0] = f[i][1] = 1e18;

	f[1][0] = 1ll * r1 * a[1] + r3;
	f[1][1] = min(0ll + r2, 1ll * r1 * a[1] + r1);
	for(int i = 1; i < n; ++ i) {
		// 0 -> 0
		// so we clear this one and the next one as well
		upd(f[i + 1][0], f[i][0] + d + 1ll * r1 * a[i + 1] + r3);

		// 0 -> 1
		// this one is cleared, but next one isnt
		upd(f[i + 1][1], f[i][0] + d + min(0ll + r2, 1ll * r1 * a[i + 1] + r1));
		
		// 1 -> 0
		upd(f[i + 1][0], f[i][1] + d + 1ll * r1 * a[i + 1] + r3 + 2 * d + r1);
		upd(f[i + 1][0], f[i][1] + d + 1ll * r1 * a[i + 1] + r1 + d + r1 + d + r1);
		upd(f[i + 1][0], f[i][1] + d + r2 + d + r1 + d + r1);

		// 1 -> 1
		upd(f[i + 1][1], f[i][1] + d + r2 + d + r1 + d);
		upd(f[i + 1][1], f[i][1] + d + 1ll * r1 * a[i + 1] + r1 + d + r1 + d);

		if(i == n - 1) {
			upd(f[i + 1][0], f[i][1] + d + 1ll * r1 * a[i + 1] + r3 + d + r1);
		}
	}
	cout << f[n][0] << endl;
}
```
 
### [1396D - Rainbow Rectangles](../problems/D._Rainbow_Rectangles.md "Codeforces Round 666 (Div. 1)")

Let $xl, xr, yd, yu$ denote a rectangle with opposite corners $(xl, yd)$ and $(xr, yu)$. For convenience, assume $(xl \le xr)$ and $(yd \le yu)$.

Let's try solving the problem if coordinates are in range $[1, n]$. We could easily do this by coordinates compression.

First, let's look at the problem with $(yd, yu)$ fixed. We define $f_x$ to be the smallest integer such that $x \le f_x$ and $(x, yd), (f_x, yu)$ is a $\textbf{good}$ rectangle (If there is no such integer, let $f_x = inf$). It can be proven that $f_x$ is non-decreasing, i.e. if $x < y$, then $f_x \le f_y$.

Now, let's see how $f_x$ changes when we iterate $yd$ over a fixed $yu$. It is hard to add points to the set, so we will try to support deleting points operation. For point $i$, we have the following definitions:

Let set $S = \{ j | c_j = c_i, y_i < y_j \le yu, x_j \le x_i \}$. Let $prv_i = j \in S$ with the largest $x_j$.

Let set $S' = \{ j | c_j = c_i, y_i < y_j \le yu, x_j \ge x_i \}$. Let $nxt_i = j \in S'$ with the smallest $x_j$.

(Note that $S$ or $S'$ might represent empty set).

With these two functions, we could see how $f_x$ changes after we delete point $i$. It looks something like this: For every $xl \in (x_{prv_i}, x_i]$ such that $f_{xl} \ge x_i, f_{xl} = max(f_{xl}, x_{nxt_i})$;

We could support this operation using segment tree with lazy propagation. The total time complexity is $O(n^2 \cdot log_n)$.

 **C++ solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MOD = 1000000007;

int L;
ll sum[8040];
int len[8040];
int last[8040];
int lazy[8040];

void init(int v, int l, int r, const vector<int> &xs) {
   len[v] = xs[r] - xs[l - 1];
   if (l < r) {
      int md = (l + r) >> 1;
      init(v << 1, l, md, xs);
      init(v << 1 | 1, md + 1, r, xs);
   }
}

void reset(int v, int l, int r, const vector<int> &go) {
   lazy[v] = -1;
   if (l == r) {
      sum[v] = ll(len[v]) * (L - go[l]);
      last[v] = go[l];
      return;
   }
   int md = (l + r) >> 1;
   reset(v << 1, l, md, go);
   reset(v << 1 | 1, md + 1, r, go);
   sum[v] = sum[v << 1] + sum[v << 1 | 1];
   last[v] = last[v << 1 | 1];
}

void push(int v, int l, int r) {
   if (lazy[v] != -1) {
      last[v] = lazy[v];
      sum[v] = ll(len[v]) * (L - lazy[v]);
      if (l < r) {
         lazy[v << 1] = lazy[v];
         lazy[v << 1 | 1] = lazy[v];
      }
      lazy[v] = -1;
   }
}

void modify(int v, int l, int r, int L, int R, int qv) {
   push(v, l, r);
   if (L > r || R < l) return;
   if (L <= l && r <= R) {
      lazy[v] = qv;
      push(v, l, r);
      return;
   }
   int md = (l + r) >> 1;
   modify(v << 1, l, md, L, R, qv);
   modify(v << 1 | 1, md + 1, r, L, R, qv);
   sum[v] = sum[v << 1] + sum[v << 1 | 1];
   last[v] = last[v << 1 | 1];
}

int walk(int v, int l, int r, int qv) {
   push(v, l, r);
   if (last[v] <= qv) return -1;
   if (l == r) return l;
   int md = (l + r) >> 1;
   int ans = walk(v << 1, l, md, qv);
   if (ans == -1) ans = walk(v << 1 | 1, md + 1, r, qv);
   return ans;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, K; cin >> N >> K >> L;
   vector<int> X(N), Y(N), C(N);
   vector<int> xs = {-1, L};
   vector<int> ys = {-1, L};
   for (int i = 0; i < N; ++i) {
      cin >> X[i] >> Y[i] >> C[i];
      --C[i];
      xs.emplace_back(X[i]);
      ys.emplace_back(Y[i]);
   }
   sort(xs.begin(), xs.end());
   xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
   sort(ys.begin(), ys.end());
   ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
   int NX = xs.size();
   int NY = ys.size();
   {
      vector<int> order(N);
      iota(order.begin(), order.end(), 0);
      sort(order.begin(), order.end(), [&](int i, int j) {
         return make_pair(Y[i], -X[i]) > make_pair(Y[j], -X[j]);
      });
      vector<int> newX(N), newY(N), newC(N);
      for (int i = 0; i < N; ++i) {
         newX[i] = X[order[i]];
         newY[i] = Y[order[i]];
         newC[i] = C[order[i]];
      }
      X.swap(newX), Y.swap(newY), C.swap(newC);
   }
   init(1, 1, NX - 2, xs);
   int ans = 0;
   for (int yr = 1; yr + 1 < NY; ++yr) {
      vector<vector<int>> addAt(NX);
      for (int i = 0; i < N; ++i) {
         if (Y[i] <= ys[yr]) {
            int xi = lower_bound(xs.begin(), xs.end(), X[i]) - xs.begin();
            addAt[xi].emplace_back(C[i]);
         }
      }
      int bad = K;
      vector<int> cnts(K);
      auto inc = [&](int z) {
         if (++cnts[z] == 1) --bad;
      };
      auto dec = [&](int z) {
         if (--cnts[z] == 0) ++bad;
      };
      vector<int> go(NX);
      int ptr = 0;
      for (int i = 1; i + 1 < NX; ++i) {
         while (bad && ptr + 2 < NX) {
            ptr++;
            for (int z : addAt[ptr]) inc(z);
         }
         if (bad) go[i] = L;
         else go[i] = xs[ptr];
         for (int z : addAt[i]) dec(z);
      }
      reset(1, 1, NX - 2, go);
      vector<int> prv(N);
      vector<int> nxt(N);
      vector<map<int, int>> mp(K);
      for (int i = 0; i < N; ++i) {
         if (Y[i] <= ys[yr]) {
            auto it = mp[C[i]].lower_bound(X[i]);
            if (it == mp[C[i]].end()) {
               nxt[i] = -1;
            } else {
               nxt[i] = it->second;
            }
            it = mp[C[i]].upper_bound(X[i]);
            if (it == mp[C[i]].begin()) {
               prv[i] = -1;
            } else {
               prv[i] = prev(it)->second;
            }
            mp[C[i]][X[i]] = i;
         }
      }
      auto remove = [&](int i) {
         int xprv = (prv[i] == -1 ? -1 : X[prv[i]]);
         int xcur = X[i];
         int xnxt = (nxt[i] == -1 ? L : X[nxt[i]]);
         int l =  lower_bound(xs.begin(), xs.end(), xprv) - xs.begin() + 1;
         int r = walk(1, 1, NX - 2, xnxt);
         if (r == -1) r = NX - 1; --r;
         r = min(r, int(lower_bound(xs.begin(), xs.end(), xcur) - xs.begin()));
         if (l <= r) modify(1, 1, NX - 2, l, r, xnxt);
      };
      ptr = N - 1;
      for (int yl = 1; yl <= yr; ++yl) {
         ll add = sum[1] % MOD * (ys[yr + 1] - ys[yr]) % MOD * (ys[yl] - ys[yl - 1]) % MOD;
         ans = (ans + add) % MOD;
         while (ptr >= 0 && Y[ptr] == ys[yl]) remove(ptr--);
      }
      assert(sum[1] == 0);
   }
   cout << ans << "n";
   return 0;
}
```
 
### [1396E - Distance Matching](../problems/E._Distance_Matching.md "Codeforces Round 666 (Div. 1)")

Root the tree at centroid $c$.

First, determine if there is any matching that satisfies the requirement. Consider an edge $e$ that splits the tree into $2$ subtrees with sizes $x$ and $N - x$ respectively, let $z$ be the number of paths passing through $e$, then we have $z$ has the same parity as $x$ and $x \% 2 \le z \le min(x, N - x)$. Thus the necessary condition for a matching is $\sum (sub(v) \% 2) \le K \le \sum sub(v)$ and $K$ has the same parity as $\sum sub(v)$, where $v \ne c$ and $sub(v)$ is the size of the subtree rooted at $v$. We prove that this is also the sufficient condition by its construction:

Consider the matching with maximum $K$, note that $c$ lies on all the paths in the matching.

We can see that if we remove two vertices from the largest subtree, rooted at $w \ne c$, then $c$ is still the centroid. Also, if we match two vertices $v$ and $u$ in the subtree rooted at $w$, the answer decreases by $2 \cdot dist(c, lca(u, v))$. Based on this, we can achieve the target $K$ by repeating the following operation ($currentK$ is the current maximum possible $K$, initially $\sum sub(v)$):

* Let $z$ be a non-leaf vertex in the largest subtree such that $dist(c, z) \le \frac{currentK - targetK}{2}$ (if there are many $z$, take any $z$ with maximum $dist(c, z)$). Match two vertices $v$ and $u$ whose LCA is $z$, then remove $v$ and $u$ from the tree.

After some time $currentK = targetK$, so we just need to greedily match the remaining vertices to create the final matching.

The final complexity is $O(N log N)$.

 **C++ solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N; ll K;
   cin >> N >> K;
   vector<vector<int>> adj(N);
   for (int i = 0; i < N - 1; ++i) {
      int v, u;
      cin >> v >> u;
      adj[--v].emplace_back(--u);
      adj[u].emplace_back(v);
   }
   vector<int> sz(N);
   function<void(int, int)> dfs1 = [&](int v, int p) {
      sz[v] = 1;
      for (int u : adj[v]) if (u != p) {
         dfs1(u, v);
         sz[v] += sz[u];
      }
   };
   dfs1(0, -1);
   int root = 0;
   for (int i = 1; i < N; ++i) {
      if (sz[i] >= N / 2 && sz[i] < sz[root]) root = i;
   }
   vector<int> dist(N);
   vector<int> top(N, -1);
   vector<int> par(N, -1);
   ll low = 0, high = 0;
   function<void(int, int, int)> dfs2 = [&](int v, int p, int r) {
      dist[v] = dist[p] + 1;
      top[v] = r;
      par[v] = p;
      {
         auto it = find(adj[v].begin(), adj[v].end(), p);
         assert(it != adj[v].end());
         adj[v].erase(it);
      }
      sz[v] = 1;
      for (int u : adj[v]) {
         dfs2(u, v, r);
         sz[v] += sz[u];
      }
      low += (sz[v] & 1);
      high += sz[v];
   };
   for (int v : adj[root]) {
      dfs2(v, root, v);
   }
   if (low > K || high < K || (high - K) % 2) {
      cout << "NOn";
      return 0;
   }
   set<pair<int, int>> sizes;
   for (int v : adj[root]) {
      sizes.emplace(sz[v], v);
   }
   vector<set<pair<int, int>>> lcas(N);
   vector<int> deg(N);
   for (int v = 0; v < N; ++v) deg[v] = adj[v].size();
   for (int v = 0; v < N; ++v) if (v != root) {
      if (deg[v] == 0) {
      } else {
         lcas[top[v]].emplace(dist[v], v);
      }
   }
   vector<bool> matched(N);
   function<void(int)> kill = [&](int v) {
      assert(deg[v] == 0);
      if (--deg[par[v]] == 0) {
         v = par[v];
         lcas[top[v]].erase(pair<int, int>(dist[v], v));
      }
   };
   cout << "YESn";
   while (high > K) {
      assert(sizes.size());
      int v = (--sizes.end())->second;
      sizes.erase(pair<int, int>(sz[v], v));
      assert(lcas[v].size());
      int mdist = (--lcas[v].end())->first;
      if (high - 2 * mdist <= K) {
         int x = lcas[v].lower_bound(pair<int, int>((high - K) / 2, -1))->second;
         int y = -1;
         for (int z : adj[x]) if (!matched[z]) {
            y = z;
            break;
         }
         high = K;
         cout << x + 1 << " " << y + 1 << "n";
         matched[x] = true;
         matched[y] = true;
         break;
      } else {
         high -= 2 * mdist;
         assert(lcas[v].size());
         int u = (--lcas[v].end())->second;
         vector<int> nxts;
         while (nxts.size() < 2 && adj[u].size()) {
            int w = adj[u].back();
            adj[u].pop_back();
            if (!matched[w]) {
               nxts.emplace_back(w);
            }
         }
         if (nxts.size() < 2) nxts.emplace_back(u);
         assert(nxts.size() == 2);
         cout << nxts[0] + 1 << " " << nxts[1] + 1 << "n";
         matched[nxts[0]] = true;
         matched[nxts[1]] = true;
         kill(nxts[0]);
         kill(nxts[1]);
         sz[v] -= 2;
         if (sz[v]) sizes.emplace(sz[v], v);
      }
   }
   vector<int> seq;
   function<void(int)> dfs3 = [&](int v) {
      if (!matched[v]) seq.emplace_back(v);
      for (int u : adj[v]) dfs3(u);
   };
   dfs3(root);
   int h = seq.size() / 2;
   for (int i = 0; i < h; ++i) {
      cout << seq[i] + 1 << " " << seq[i + h] + 1 << "n";
   }
}
```
