# Tutorial

[1923A - Moving Chips](../problems/A._Moving_Chips.md "Educational Codeforces Round 162 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1923A - Moving Chips](../problems/A._Moving_Chips.md "Educational Codeforces Round 162 (Rated for Div. 2)")

Denote the position of the leftmost chip as $l$, the position of the rightmost chip as $r$, and the number of chips as $c$.

Having all chips in one block without free spaces means that we need to reach the situation when $r - l = c - 1$. Since $r - l \ge c - 1$ is always met (the situation when $r-l = c-1$ is when the chips are packed as close as possible), we need to decrease the value of $r-l$ as fast as possible.

There are two approaches to do it. One is to try decreasing $r$ every time; i. e. let's code a greedy solution that always applies an operation to the current rightmost chip. This is actually one of the correct solutions to the problem.

But if we prove it, we can design an easier solution. Whenever we apply an operation on any chip other than the rightmost chip, the value of $r-l$ does not decrease (we either don't change $l$ and $r$ at all, or decrease $l$). But whenever we apply an operation on the rightmost chip, $r$ decreases by exactly $1$ (the new rightmost chip will be in position $r-1$ — either it is present there before the operation, or it will be moved there from $r$). So, only applying the operations to the rightmost chip decreases $r-l$, and it always decreases $r-l$ by exactly $1$ no matter what. So, the answer to the problem is actually $(r-l) - (c-1)$.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    l, r = a.index(1), n - a[::-1].index(1) - 1
    c = a.count(1)
    print(r - l - c + 1)
```
[1923B - Monsters Attack!](../problems/B._Monsters_Attack!.md "Educational Codeforces Round 162 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), x(n);
    for (auto& it : a) cin >> it;
    for (auto& it : x) cin >> it;
    vector<long long> s(n + 1);
    for (int i = 0; i < n; ++i) s[abs(x[i])] += a[i];
    bool ok = true;
    long long lft = 0;
    for (int i = 1; i <= n; ++i) {
      lft += k - s[i];
      ok &= (lft >= 0);
    }
    cout << (ok ? "YES" : "NO") << 'n';
  }
}
```
[1923C - Find B](../problems/C._Find_B.md "Educational Codeforces Round 162 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**Tutorial is loading... **Solution (Roms)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 300043;
 
int t;
int n, m;
int a[N];
long long sum[N];
int cnt1[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        cin >> n >> m;
        memset(sum, 0, sizeof(sum[0]) * (n + 5));
        memset(cnt1, 0, sizeof(cnt1[0]) * (n + 5));
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum[i + 1] = sum[i] + a[i];
            cnt1[i + 1] = cnt1[i] + (a[i] == 1);
        }
        
        for (int i = 0; i < m; ++i) {
            int l, r;
            cin >> l >> r;
            --l;
            int cur_cnt1 = cnt1[r] - cnt1[l];
            long long cur_sum = sum[r] - sum[l];
            
            if((r - l) + cur_cnt1 <= cur_sum && r - l > 1)
                cout << "YESn";
            else
                cout << "NOn";
        }
    }
    return 0;
}
```
[1923D - Slimes](../problems/D._Slimes.md "Educational Codeforces Round 162 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1923D - Slimes](../problems/D._Slimes.md "Educational Codeforces Round 162 (Rated for Div. 2)")

Let's solve the problem independently for each slime (denote it as $i$).

After any number of seconds, the size of each slime is equal to the sum of some subarray. In order to eat the $i$-th slime, the "eater" should be its neighbor. So the eater size is equal to the sum of subarray $[j, i-1]$ for some $j < i$ or $[i + 1, j$] for some $j > i$. It remains to understand which $j$ can be the answer. First of all, the sum of subarray should be strictly greater than $a_i$. And also, there should be a sequence of operations that can combine the selected segment of slimes into one slime. Such a sequence exists in two cases: 

* the length of subarray is $1$;
* there are at least two distinct values in subarray.

It is not difficult to prove that these are the only conditions. If the length is $1$, then the subarray is already just only one slime. If all the slimes have the same size, then none of the neighboring pairs can be combined, which means that it is impossible to combine all slimes into one. If there are at least two distinct values, there exist a pair of adjacent slimes of the form (maximum, not maximum). After combining such a pair, the result is the only maximum of the subarray, which means that it can eat all the other slimes in the subarray.

It remains to understand how to find such $j$ that satisfies the aforementioned conditions and is as close to $i$ as possible (because the number of required operations is $|i-j|$) faster than iterating over all values of $j$. We can notice that, if the subarray $[j, i-1]$ is good, then the subarray $[j-1, i-1]$ is also good. This leads us to the fact that we can use binary search. It is enough to pre-calculate two arrays: an array of prefix sums that used to find the sum of the subarray and an array $p$, where $p_i$ is the position of the nearest element that different to $a_i$ — to determine whether there are two different elements.

So we can find the answer for one slime in $O(\log{n})$. And the total running time is $O(n\log{n})$.

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
    vector<int> ans(n, n);
    for (int z = 0; z < 2; ++z) {
      vector<long long> s(n + 1);
      for (int i = 0; i < n; ++i) s[i + 1] = s[i] + a[i];
      vector<int> p(n, -1);
      for (int i = 1; i < n; ++i) {
        int j = (z ? n - i - 1 : i);
        int l = 1, r = i;
        while (l <= r) {
          int m = (l + r) / 2;
          if (s[i] - s[i - m] > a[i] && p[i - 1] >= i - m) {
            ans[j] = min(ans[j], m);
            r = m - 1;
          } else {
            l = m + 1;
          }
        }
        if (a[i - 1] > a[i]) ans[j] = 1;
        p[i] = (a[i] == a[i - 1] ? p[i - 1] : i - 1);
      }
      reverse(a.begin(), a.end());
    }
    for (int i = 0; i < n; ++i)
      cout << (ans[i] == n ? -1 : ans[i]) << ' ';
    cout << 'n';
  }
}
```
[1923E - Count Paths](../problems/E._Count_Paths.md "Educational Codeforces Round 162 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1923E - Count Paths](../problems/E._Count_Paths.md "Educational Codeforces Round 162 (Rated for Div. 2)")

Let's consider what the paths passing through some vertex $v$ look like. First, root the tree arbitrarily. Let $u_1, u_2, \dots, u_k$ be the children of $v$. Then, for some color $x$, there are $\mathit{cnt}[u_1][x], \mathit{cnt}[u_2][x], \dots, \mathit{cnt}[u_k][x]$ top-level vertices in their subtrees. Top-level here means that there are no vertices of color $x$ on the path from them to $u_i$.

If the color of $v$ is not $x$, then you can combine all $\mathit{cnt}$ top-level vertices from every pair of children into paths. If the color $v$ is $x$, then all $\mathit{cnt}$ top-level vertices can only be paired with $v$. Moreover, the top-level vertices of color $x$ in subtree of $v$ is only $v$ itself now.

With these ideas, some small-to-large can be implemented. Store $\mathit{cnt}[v][x]$ for all colors $x$ such that there exist top-level vertices of this color.

In order to recalculate $\mathit{cnt}[v]$ from the values of its children, you can first calculate the sum of $\mathit{cnt}$ for each $x$, then replace $\mathit{cnt}[v][c_v]$ with $1$ (regardless of if it appeared in children or not). So that can be done by adding all values to the values of the largest child of $v$ (largest by its size of $\mathit{cnt}$, for example). During this process, you can calculate the number of paths as well.

The complexity will be $O(n \log^2 n)$ for each testcase, and that should pass freely.

There's also an idea for a faster solution. Two words: virtual trees. Basically, you can build a virtual tree of all vertices of each color. Now, there are vertices colored $x$ in it and some auxiliary vertices. The answer for that color can be calculated with some sort of dynamic programming. Similar to the first solution, for each vertex, store the number of top-level vertices of color $x$ in its subtree. All the calculations are exactly the same.

You can build all virtual trees in $O(n \log n)$ in total.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
int n;
vector<int> a;
vector<vector<int>> g;
 
long long ans;
vector<map<int, int>> cnt;
 
void dfs(int v, int p = -1){
    int bst = -1;
    for (int u : g[v]) if (u != p){
        dfs(u, v);
        if (bst == -1 || cnt[bst].size() < cnt[u].size())
            bst = u;
    }
    for (int u : g[v]) if (u != p && u != bst){
        for (auto it : cnt[u]){
            int x = it.first, y = it.second;
            if (x != a[v]) ans += cnt[bst][x] * 1ll * y;
            cnt[bst][x] += y;
        }
    }
    if (bst != -1) swap(cnt[bst], cnt[v]);
    ans += cnt[v][a[v]];
    cnt[v][a[v]] = 1;
}
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        a.resize(n);
        forn(i, n) cin >> a[i];
        g.assign(n, {});
        forn(_, n - 1){
            int v, u;
            cin >> v >> u;
            --v, --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        ans = 0;
        cnt.assign(n, {});
        dfs(0);
        cout << ans << 'n';
    }
    return 0;
}
```
[1923F - Shrink-Reverse](../problems/F._Shrink-Reverse.md "Educational Codeforces Round 162 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1923F - Shrink-Reverse](../problems/F._Shrink-Reverse.md "Educational Codeforces Round 162 (Rated for Div. 2)")

In order to solve a task, let's observe and prove several facts:

Fact 0: Suppose, you have two strings $s_1$ and $s_2$ without leading zeroes. Value of $s_1$ is lower than value of $s_2$ if either $|s_1| < |s_2|$ or $|s_1| = |s_2|$ and $s_1 < s_2$ lexicographically.

Fact 1: There is a strategy, where you, firstly, perform all swaps, and only after that perform reverses. Proof: let's take some optimal strategy and split all its operations in blocks by reverse operation. Let's look at the last block of swaps: if there is no reverse before it — we found strategy. Otherwise, we can "push" all swaps from this block into the previous block (of course, with fixed indices), since all positions that exist at the current moment, existed earlier. Answer won't increase after this "push". So we can transform any optimal strategy into one we need.

Fact 2: There is no need to make more than $2$ reverses. Since, we, firstly, swap and then reverse — making $3$ reverses is equivalent to making $1$ reverse. Analogically, making $4$ reverses is equivalent to making $2$ reverses.

Fact 3: There is no need to make more than $1$ reverse. If, after the first reverse, we grouped all $1$-s into one segment, then the second reverse won't change anything. Otherwise, instead of the second reverse, we could make one more swap and "group $1$-s tighter" thus lowering the value of $s$.

Fact 4: Suppose, you have two binary strings $s_1$ and $s_2$ with equal length, equal number of $1$-s, and you'll replace last $k - 1$ zeroes in both of them thus getting strings $s'_1$ and $s'_2$. If $s_1 \le s_2$ then $s'_1 \le s'_2$ (lexicographically). Proof: if $s_1 = s_2$ then $s'_1 = s'_2$. Otherwise, there is the first position $p$ where $s_1[p] = 0$ and $s_2[p] = 1$. After replacing last $k - 1$ zeroes with ones, if $s_1[p]$ was replaced, then $s'_1 = s'_2$. Otherwise, $s'_1 < s'_2$ since $s'_1[p] = 0$ and $s'_2[p] = 1$.

Using facts above, we can finally solve the problem. Let's check $2$ cases: $0$ reverses or $1$ reverse.

$0$ reverses: it's optimal to be greedy. Let's take the leftmost $1$ and swap it with the rightmost $0$ as many times as we can.

$1$ reverse: leading zeroes will be deleted; trailing zeroes will become leading, so they won't affect the value of the resulting string. That's why the answer will depend only on positions of leftmost and rightmost $1$-s.

For convenience, let's reverse $s$. Then, let's iterate over all possible positions $i$ of now leftmost one. For each left position, let's find the minimum possible position $u$ of the rightmost one. Minimizing $u$ will minimize the value of the answer, so it's optimal.

There are two conditions that should be satisfied: 

1. the interval $[i, u)$ should be long enough to contain all $1$-s from the whole string $s$;
2. the number of $1$-s outside the interval should be at most $k - 1$.

 It's easy to see that you can use two-pointers technique for finding $u$ for each $i$ efficiently.Last step is to choose the minimum interval among all of them. Due to fact 0, we should, firstly, choose the shortest interval. Then (due to fact 4) it's enough to choose the lexicographically smallest one among them.

In order to compare two intervals of reversed string $s$ it's enough to use their "class" values from Suffix Array built on reversed $s$.

The complexity is $O(n \log{n})$ or $O(n \log^2{n})$ for building Suffix Array + $O(n)$ for checking each case and comparing answers from both cases.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
 
typedef long long li;
typedef pair<int, int> pt;
 
const int INF = int(1e9);
const int MOD = int(1e9) + 7;
 
int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
int mul(int a, int b) {
    return int(a * 1ll * b % MOD);
}
 
namespace SuffixArray {
    string s;
    vector< array<int, 2> > classes;
    
    vector<int> build(const string &bs) {
        s = bs;
        s += '$';
        
        vector<int> c(all(s)), ord(sz(s));
        iota(all(ord), 0);
        classes.resize(sz(s));
 
        for (int len = 1; len < 2 * sz(s); len <<= 1) {
            int half = len >> 1;
            fore (i, 0, sz(s))
                classes[i] = {c[i], c[(i + half) % sz(s)]};
            
            sort(all(ord), [&](int i, int j) {
                return classes[i] < classes[j];
            });
            c[ord[0]] = 0;
            fore (i, 1, sz(ord))
                c[ord[i]] = c[ord[i - 1]] + (classes[ord[i - 1]] != classes[ord[i]]);
        }
        
        c.pop_back();
        for (int &cc : c)
            cc--;
        return c;
    }
};
 
int n, k;
string s;
 
inline bool read() {
    if(!(cin >> n >> k))
        return false;
    cin >> s;
    return true;
}
 
string calcZero(string s) {
    int rem = k;
    int pos = 0;
    for (int i = sz(s) - 1; rem > 0 && i >= 0; i--) {
        if (s[i] == '1')
            continue;
        
        while (pos < sz(s) && s[pos] == '0')
            pos++;
        if (pos >= i)
            break;
        
        swap(s[pos], s[i]);
        rem--;
    }
    return s.substr(s.find('1'));
}
 
string calcOne(string s) {
    reverse(all(s));
    
    auto c = SuffixArray::build(s);
    int cntOnes = count(all(s), '1');
    
    array<int, 3> mn = { 2 * sz(s), INF, -1 };
        
    int u = 0, curOnes = 0;
    fore (i, 0, n) {
        while (u < sz(s) && (u - i < cntOnes || cntOnes - curOnes > k - 1)) {
            curOnes += s[u] == '1';
            u++;
        }
        if (u - i < cntOnes || cntOnes - curOnes > k - 1)
            break;
        
        array<int, 3> curAns = { u - i, c[i], i };
        mn = min(mn, curAns);
        
        curOnes -= s[i] == '1';
    }
    assert(mn[2] >= 0);
    
    string res = s.substr(mn[2], mn[0]);
    int toAdd = cntOnes - count(all(res), '1');
    for (int i = sz(res) - 1; toAdd > 0 && i >= 0; i--) {
        if (res[i] == '0') {
            res[i] = '1';
            toAdd--;
        }
    }
    return res;
}
 
inline void solve() {
    auto s1 = calcZero(s);
    auto s2 = calcOne(s);
 
    if (sz(s1) > sz(s2) || (sz(s1) == sz(s2) && s1 > s2))
        swap(s1, s2);
    
    int res = 0;
    for (char c : s1)
        res = add(mul(res, 2), c - '0');
    cout << res << endl;
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    
    if(read()) {
        solve();
        
#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}
```
