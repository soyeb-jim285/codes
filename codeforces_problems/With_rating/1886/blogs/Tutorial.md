# Tutorial

[1886A - Sum of Three](../problems/A._Sum_of_Three.md "Educational Codeforces Round 156 (Rated for Div. 2)")

Idea: [fcspartakm](https://codeforces.com/profile/fcspartakm "Candidate Master fcspartakm")

 **Tutorial**
### [1886A - Sum of Three](../problems/A._Sum_of_Three.md "Educational Codeforces Round 156 (Rated for Div. 2)")

You can solve this problem with some case analysis, but I'll describe another solution.

Suppose we want to iterate on every $x$, and then on every $y$, and then calculate $z$ and check that everything's OK. Obviously, this is too slow.

But we can speed this up: we don't have to iterate on all possible values of $x$ and $y$. Suppose $x < y < z$; then, if $x \ge 4$, we can decrease $x$ by $3$ and increase $z$ by $3$, until $x$ becomes either $1$ or $2$. The same goes for $y$: if $y \ge 7$, we can decrease it by $3$ and increase $z$ by $3$, until $y < 7$. So, we only have to iterate on $x$ up to $2$, and on $y$ up to $5$. This yields a solution in $O(1)$.

You don't have to iterate on $x$ up to exactly $2$ and on $y$ up to exactly $5$, just use an upper bound for which you don't check too many possible triples of $x$, $y$ and $z$.

 **Solution (fcspartakm)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n;

inline void read() {
	cin >> n;
}

inline void solve() {
	for (int x = 1; x <= 20; x++) {
	    for (int y = 1; y <= 20; y++) {
	        if (x + y >= n || x == y) continue;
	        int z = n - x - y;
	        if (z == x || z == y) continue;
	        if (x % 3 == 0 || y % 3 == 0 || z % 3 == 0) {
	            continue;
	        }
	        puts("YES");
	        cout << x << ' ' << y << ' ' << z << endl;
	        return;
	    }
	}
	puts("NO");
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
[1886B - Fear of the Dark](../problems/B._Fear_of_the_Dark.md "Educational Codeforces Round 156 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1886B - Fear of the Dark](../problems/B._Fear_of_the_Dark.md "Educational Codeforces Round 156 (Rated for Div. 2)")

There are only two major cases: both points $O$ and $P$ lie inside the same circle, or the point $O$ lies inside one of the circles and $P$ lies inside the other circle.

Let's denote the distance between the points $P$ and $Q$ as $d(P, Q)$.

Let's look at the first case, when the points $O$ and $P$ lie inside the circle centered at $A$. In that case, inequalities $d(O, A) \le R$ and $d(P, A) \le R$ must be satisfied. Therefore, the minimum possible radius for that case is equal to $\max(d(O, A), d(P, A))$. Similarly, for the circle centered at $B$, the minimum possible radius for that case is equal to $\max(d(O, B), d(P, B))$.

Let's look at the second case, when the point $O$ lies inside the circle centered at $A$ and the point $P$ lies inside the circle centered at $B$. In that case, inequalities $d(O, A) \le R$ and $d(P, B) \le R$ must be satisfied. But there is one extra constraint: the circles must intersect, because there is should an illuminated path from one circle to another. This adds one more inequality — $d(A, B) \le 2R$. Therefore, the minimum possible radius for that case is equal to $\max\left(d(O, A), d(P, B), \frac{d(A, B)}{2}\right)$. Similarly, when $O$ lies inside the circle centered at $B$ and $P$ lies inside the circle centered at $A$, the minimum possible radius for that case is equal to $\max\left(d(O, B), d(P, A), \frac{d(A, B)}{2}\right)$.

So the answer to the problem is the minimum among aforementioned cases.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  auto dist = [](int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  };
 
  int t;
  cin >> t;
  while (t--) {
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    double pa = dist(px, py, ax, ay), pb = dist(px, py, bx, by);
    double oa = dist(0, 0, ax, ay), ob = dist(0, 0, bx, by);
    double ab = dist(ax, ay, bx, by);
    double ans = 1e9;
    ans = min(ans, max(pa, oa));
    ans = min(ans, max(pb, ob));
    ans = min(ans, max({ab / 2, pa, ob}));
    ans = min(ans, max({ab / 2, pb, oa}));
    cout << setprecision(10) << fixed << ans << 'n';
  }
}
```
[1886C - Decreasing String](../problems/C._Decreasing_String.md "Educational Codeforces Round 156 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1886C - Decreasing String](../problems/C._Decreasing_String.md "Educational Codeforces Round 156 (Rated for Div. 2)")

Let's analyze in which order the characters should be removed from the given string. Suppose we want to remove a character so that the resulting string is lexicographically smallest. We can show that the best option is to find the leftmost pair of adjacent characters $S_i, S_{i+1}$ such that $S_i > S_{i+1}$: removing $S_i$ will decrease the character on that position; if you remove some character to the right of $S_i$, the $i$-th character won't decrease; and if you remove some character to the left of $S_i$, you might accidentally increase some character before the $i$-th position (we chose the leftmost such pair, so the prefix until the $i$-th character is non-decreasing). If there is no such pair of adjacent characters, you should remove the last character of the string. Unfortunately, implementing it naively is too slow (the solution will work in $O(n^2)$). Thankfully, there is a way to determine in which all characters are removed in $O(n)$.

Maintain a stack of characters (initially empty) and iterate over the string from left to right. When you encounter a character, if the stack is empty or the character on top of the stack is not greater than the current one, you don't have to remove anything, just push the new character into the stack. But if the character on top of the stack is greater than the new one, then we have found a pair of adjacent characters which meets the condition; so, the character on top of the stack is the next to remove. Pop the topmost element of the stack. Note that we don't push the new character into the stack yet, because the next element on top of the stack might still be greater — in that case, this is the next character to remove (and we pop it), and so on. In the end, the character in the stack will be non-descending from the bottom of the stack to the top, and we should remove them from top to bottom. That's how we can find in which order characters are removed.

The rest is quite easy: locate in which of the strings $s_1, s_2, \dots, s_n$ the position $pos$ occurs, remove the required number of characters, and print the corresponding character of the resulting string.

Minor detail which can make the implementation easier: if you append some character which is less than a to the end of the given string, you don't have to consider the case when there's no pair of adjacent characters $S_i > S_{i+1}$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 200000;

int t;

int main() {
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        string s;
        long long pos;
        cin >> s >> pos;
        --pos;
        
        int curLen = s.size();
        vector <char> st;
        bool ok = pos < curLen;
        s += '$';
        
        for (auto c : s) {
            while (!ok && st.size() > 0 && st.back() > c) {
                pos -= curLen;
                --curLen;
                st.pop_back();
                
                if(pos < curLen) 
                    ok = true;
            }
            st.push_back(c);
        }
        
        cout << st[pos];
    }
    return 0;
}
```
[1886D - Monocarp and the Set](../problems/D._Monocarp_and_the_Set.md "Educational Codeforces Round 156 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1886D - Monocarp and the Set](../problems/D._Monocarp_and_the_Set.md "Educational Codeforces Round 156 (Rated for Div. 2)")

The key observation to this problem is that it's much easier to consider the process in reverse. Suppose Monocarp has a set of integers $1, 2, \dots, n$, and starts removing elements from it one by one. During the $i$-th deletion, if $s_{n-i}$ is <, he removes the minimum element; if $s_{n-i}$ is >, he removes the maximum element; and if $s_{n-i}$ is ?, he removes any element which is neither the minimum nor the maximum.

If you consider the process backwards, it's quite easy to see that it doesn't actually matter which numbers are present in the set; we are interested only in their quantity. So, for each action, we can choose an element to remove independently: if $s_{n-i}$ is < or >, there is only one way, otherwise, there are $k-2$ ways, where $k$ is the number of elements in the set (for the $i$-th deletion operation, it is $n-i+1$).

So, the answer to the problem is the product of $j-1$ for every character $s_j$ that is equal to ?.

To recalculate the answer efficiently when you change a character, you can use one of the following options:

* build a segment tree with operation "product on segment modulo $998244353$";
* or use modular inverse to maintain division operations. Note that sometimes you have to "divide by zero", i. e. remove the zero from the product (when $s_1$ changes from ? to another character); to handle it, you can store the product for every $s_i$ from $2$ to $n-1$, and explicitly multiply it by $0$ before printing when $s_1$ is ?.
 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

const int N = 300009;

int bp(int a, int n) {
    int res = 1;
    while(n > 0) {
        if (n & 1)
            res = (res * 1LL * a) % MOD;
        a = (a * 1LL * a) % MOD;
        n >>= 1;
    }
    return res;
}

int n, m;
string s;
int inv[N];

void upd(int &res, int x) {
    res = (res * 1LL * x) % MOD;
}

int main() {
    inv[1] = 1;
    for (int i = 2; i < N; ++i){
	    inv[i] = bp(i, MOD - 2);
    }
    
    cin >> n >> m >> s;
    
    int res = 1, k = n;
    bool isZero = false;
    for (int i = 0; i < s.size(); ++i) 
        if (s[i] == '?') {
            if (i == 0) {
                isZero = true;
            } else {
                upd(res, i);
            }
        }
    
    cout << (isZero? 0 : res) << endl;
    
    for(int i = 0; i < m; ++i) {
        int pos;
        char c;
        cin >> pos >> c;
        --pos;
        
        if (s[pos] == '?' && (c == '<' || c == '>')) {
            if (pos == 0)
                isZero = false;
            else
                upd(res, inv[pos]);
        } else if ((s[pos] == '<' || s[pos] == '>') && c == '?') {
            if (pos == 0)
                isZero = true;
            else
                upd(res, pos);
        }
        
        s[pos] = c;
        cout << (isZero? 0 : res) << endl;
    }
    return 0;
}
```
[1886E - I Wanna be the Team Leader](../problems/E._I_Wanna_be_the_Team_Leader.md "Educational Codeforces Round 156 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1886E - I Wanna be the Team Leader](../problems/E._I_Wanna_be_the_Team_Leader.md "Educational Codeforces Round 156 (Rated for Div. 2)")

Let's start by arranging the programmers in the increasing order of their stress tolerance level. Not obvious what it achieves at first, but it always helps to sort, doesn't it?

Now, consider some assignment of the programmers to the projects. Notice how it's always optimal to take the suffix of the programmers. If there is a valid answer which is not a suffix, then you can always take drop the weakest programmer and replace him with the strongest non-taken one, and the answer will still be valid.

We can actually propagate the argument further. It's also always optimal for each project to have assigned a segment of programmers. Look at the weakest taken programmer again and think about the project he's assigned to. All that matters for the project is the number of other programmers assigned to it. So, you can safely replace the current assigned programmers with the same count of the next weakest ones. You can do it by swapping the assigned projects of the adjacent programmers. This way, every swap can only make any other project's weakest programmer stronger.

Thus, we can actually build the answer the following way. Choose a project and assign the shortest possible suffix of non-taken programmers to it. We just have to determine the order of the projects to take.

Well, let's use dynamic programming for that. Let $\mathit{dp}[\mathit{mask}]$ be the shortest suffix of the programmers that can be assigned to the projects from $\mathit{mask}$. For a transition, just choose one of the projects that isn't in $\mathit{mask}$ and find the shortest segment of programmers starting from $\mathit{dp}[\mathit{mask}]$.

How to find this shortest suffix fast enough? You can precompute it before calculating the dynamic programming. For each project and each starting index, you can calculate the shortest suffix with two pointers.

Overall complexity: $O(nm + m2^m)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> a(n), b(m);
	forn(i, n) scanf("%d", &a[i]);
	forn(i, m) scanf("%d", &b[i]);
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&a](int i, int j){
		return a[i] > a[j];
	});
	vector<vector<int>> mn(m, vector<int>(n + 2));
	forn(i, m){
		int r = 0;
		forn(l, n + 2){
			r = min(n + 1, max(r, l + 1));
			while (r <= n && a[ord[r - 1]] * (r - l) < b[i]) ++r;
			mn[i][l] = r;
		}
	}
	vector<int> dp(1 << m, n + 1);
	dp[0] = 0;
	vector<int> p(1 << m, -1);
	forn(mask, 1 << m) forn(i, m) if (!((mask >> i) & 1) && dp[mask | (1 << i)] > mn[i][dp[mask]]){
		dp[mask | (1 << i)] = mn[i][dp[mask]];
		p[mask | (1 << i)] = mask;
	}
	int mask = (1 << m) - 1;
	if (dp[mask] > n){
		puts("NO");
		return 0;
	}
	puts("YES");
	vector<vector<int>> ans(n);
	forn(_, m){
		int i = __builtin_ctz(mask ^ p[mask]);
		for (int j = dp[p[mask]]; j < dp[mask]; ++j)
			ans[i].push_back(ord[j]);
		mask = p[mask];
	}
	forn(i, m){
		printf("%d", int(ans[i].size()));
		for (int x : ans[i]) printf(" %d", x + 1);
		puts("");
	}
	return 0;
}
```
[1886F - Diamond Theft](../problems/F._Diamond_Theft.md "Educational Codeforces Round 156 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1886F - Diamond Theft](../problems/F._Diamond_Theft.md "Educational Codeforces Round 156 (Rated for Div. 2)")

In this editorial, we will denote the number of cameras of type $i$ as $k_i$.

Without loss of generality, we can assume that our sequence of actions will look as follows:

* hack all cameras of type $1$, some cameras of type $2$ and all cameras of type $3$ in some order (let's call it the first block of actions);
* steal the first diamond;
* hack the remaining cameras of type $2$ and some cameras of type $3$ (the second block of actions);
* steal the second diamond.

Note that we don't hack the same camera of type $1$ or $2$ twice (this is just suboptimal), but some cameras of type $3$ will be hacked twice. We have to minimize the number of cameras of type $3$ which will be hacked twice.

Let's iterate on the number of actions we make after stealing the first diamond (denote it by $len$), and then iterate on the number of cameras of type $2$ in the first block (denote it by $i$). Then, the number of cameras of type $2$ we hack in the second block will be $k_2 - i$, and the number of cameras of type $3$ we hack in the second block is $len - (k_2 - i) - 1$. Since this is also the number of cameras of type $3$ we hack twice, we have to minimize this number. Note that the length of the first block is also fixed: it should be $k_1 + k_3 + i$.

Suppose we fixed which cameras of type $2$ and $3$ go to the second block, and which don't. For each block, we will store a special data structure that, for every $x$ from $0$ to the length of the block, calculates the value of $d_x - x$, where $d_x$ is the number of cameras which have to be hacked during the last $x$ actions in the block. Using something like Hall's theorem, we can prove that if every value of $d_x - x$ for every block is non-positive, there exists a way to hack all cameras in time. This can be efficiently modeled with a segment tree.

All cameras of type $1$ should be inserted into the data structure for the first block. For the cameras of type $2$, we either insert them into the second block, or insert them into the first block while subtracting $len$ from their values of $s_j$. For the cameras of type $3$, we either insert them into both blocks, or insert them into the first block while subtracting $len$ from their values of $s_j$.

Among all cameras of type $2$, which ones should belong to the first block, and which ones — to the second block? It's quite easy to see that the "longest" cameras of type $2$ should be in the first block. Unfortunately, with cameras of type $3$, it's a bit more tricky.

First, let's insert all cameras of type $1$ into the first block and all cameras of type $2$ into the blocks chosen for them. Then sort all cameras of type $3$ (in ascending order of their $s_j$ values) and use the following greedy approach: if a camera can be inserted into the first block after we subtract $len$ from its $s_j$, we insert it there; otherwise, we insert it into both blocks without subtraction. This greedy approach can be proved using something like exchange argument: if we skipped some camera which could be inserted into the first block, and chose some other camera for the same slot, they can be "swapped". So, all cameras of type $3$ are partitioned into two types.

After you've done inserting cameras into the respective blocks, check that everything's fine. This works in something like $O(n^3 \log n)$. Unfortunately, it is too slow.

To speed this up, let's use the following strategy: iterate on the value of $len$, then try solving the problem for $i=0$ (i. e. all cameras of type $2$ are initially in the second block). If it fails, we can try increasing $i$, shifting a camera of type $2$ from the second block to the first block and rebuilding the partition of cameras of type $3$, instead of starting it from scratch.

But how do we rebuild the partition of cameras of type $3$? We can use the following strategy. Store a set of cameras of type $3$ (sorted by their $s_j$) which are inserted only into the first block. While the first block is not OK (i. e. there exists some value of $x$ such that $d_x - x$ is positive), we will find the minimum $x$ such that $d_x - x$ is positive, and try to decrease it as follows: search for the camera of type $3$ which belongs only to the first block, has $s_j - len \le x$, and has the maximum $s_j$ among all such cameras. This is the camera which should be moved in the partition (i. e. instead of storing it in the first block, we store it in both blocks). Note that you might need to repeat this process (i. e. when you move a camera of type $2$ to the first block, it can force multiple cameras of type $3$ into the second block). Thus, our solution now works in $O(n^2 \log n)$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 3003;
 
int n;
int k[4];
vector<int> a[4];
 
struct segtree {
  int sz;
  int tot;
  vector<int> t, p;
  
  segtree(int sz) : sz(sz) {
    tot = 0;
    t = vector<int>(4 * sz);
    p = vector<int>(4 * sz);
    build(0, 0, sz);
  }
  
  void build(int v, int l, int r) {
    if (l + 1 == r) {
      t[v] = -l;
      return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
  }
  
  void push(int v) {
    if (p[v] == 0) return;
    if (v + 1 < 2 * sz) {
      t[v * 2 + 1] += p[v];
      p[v * 2 + 1] += p[v];
      t[v * 2 + 2] += p[v];
      p[v * 2 + 2] += p[v];
      p[v] = 0;
    }
  } 
  
  void upd(int v, int l, int r, int L, int R, int x) {
    if (L >= R) return;
    if (l == L && r == R) {
      t[v] += x;
      p[v] += x;
      return;
    }
    push(v);
    int m = (l + r) / 2;
    upd(v * 2 + 1, l, m, L, min(m, R), x);
    upd(v * 2 + 2, m, r, max(L, m), R, x);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
  }
  
  void upd(int pos, int x) { 
    tot += x;
    upd(0, 0, sz, max(0, pos), sz, x);
  }
  
  int get(int v, int l, int r, int L, int R) {
    if (L >= R) return -1e9;
    if (l == L && r == R) return t[v];
    push(v);
    int m = (l + r) / 2;
    return max(
      get(v * 2 + 1, l, m, L, min(m, R)),
      get(v * 2 + 2, m, r, max(L, m), R)
    );
  }
  
  int get(int L) {
    return get(0, 0, sz, max(0, L), sz);
  }
  
  int getBad(int v, int l, int r) {
    if (t[v] <= 0) return -1;
    if (l + 1 == r) return l;
    push(v);
    int m = (l + r) / 2;
    if (t[v * 2 + 1] > 0) {
      return getBad(v * 2 + 1, l, m);
    } else {
      return getBad(v * 2 + 2, m, r);
    }
  }
  
  int getBad() {
    return getBad(0, 0, sz);
  }
};  
 
int main() {
  cin >> n;
  int sz = 1;
  for (int i = 0; i < n; ++i) {
    int t, s;
    cin >> t >> s;
    a[t].push_back(s);
    sz = max(sz, s + 1);
  }
  for (int t = 1; t < 4; ++t) {
    sort(a[t].begin(), a[t].end());
    k[t] = a[t].size();
  }
  reverse(a[2].begin(), a[2].end());
  int ans = 1e4;
  for (int len = 1; len <= k[2] + k[3] + 1; ++len) {
    segtree L(sz), R(sz);
    multiset<int> used;
    for (int x : a[1]) L.upd(x, +1);
    for (int x : a[2]) R.upd(x, +1);
    for (int x : a[3]) {
      L.upd(x - len, +1);
      if (L.t[0] <= 0) {
        used.insert(x - len);
      } else {
        L.upd(x - len, -1);
        L.upd(x, +1);
        R.upd(x, +1);
      }
    }
    for (int i = 0; i <= k[2]; ++i) {
      if (L.t[0] <= 0 && R.t[0] <= 0 && R.tot + 1 <= len)
        ans = min(ans, n + (k[3] - (int)used.size()) + 2); 
      if (i == k[2]) break;
      R.upd(a[2][i], -1);
      L.upd(a[2][i] - len, +1);
      int pos;
      while ((pos = L.getBad()) != -1) {
        auto it = used.upper_bound(pos);
        if (it == used.begin()) break;
        --it;
        L.upd(*it, -1);
        L.upd(*it + len, +1);
        R.upd(*it + len, +1);
        used.erase(it);
      }
    }
  }
  if (ans == 1e4) ans = -1;
  cout << ans << 'n';
}
```
