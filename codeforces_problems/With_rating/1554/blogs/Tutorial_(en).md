# Tutorial_(en)

The problem names are based on my favorite characters out there. Yes, [1554E - Вы](../problems/E._You.md "Codeforces Round 735 (Div. 2)") are my most favorite character UwU.

I have tried to make the editorials as interactive as possible. Enjoy.

 
### [1554A - Черешня](../problems/A._Cherry.md "Codeforces Round 735 (Div. 2)")

Do we really need to check all the subarrays?

Consider a subarray (ai,ai+1,…,aj). If we add a new element aj+1, when will the new subarray (ai,ai+1,…,aj,aj+1) give a better result? Pause and think.

The minimum of the new subarray can't get better(the minimum of a smaller subarray ≥ the minimum of a larger subarray). So only when aj+1 is greater than the previous maximum, then it will give a better result. But in that case, do we really need to check the whole subarray to get that result? Can we get the same or a better result from a smaller subarray? Think.

Here the maximum is aj+1. So if the minimum is not ai, then the subarray (ai+1,ai+2,…,aj+1) will give the same result. Otherwise, the minimum of (ai+1,ai+2,…,aj+1) will not be smaller which implies that (ai+1,ai+2,…,aj+1) will give a better result!

So if we add a new element, we don't have to check the whole subarray, checking (ai,ai+1,…,aj) and (ai+1,ai+2,…,aj+1) is enough.

What good this observation just brought to this world? Think.

Yes, we don't have to check subarrays with length >2, because according to the observation, (a1,a2,a3) won't give a better result than (a1,a2) and (a2,a3). And subarrays with length 4 won't give a better result than subarrays with length 3 and subarrays with length 3 won't give a better result than subarrays with length 2. You got the idea, right? 

Another thing to notice here is that the product of maximum and minimum of two integers is just the product of two integers. So the answer to the problem is the maximum of the products of adjacent elements in a.

Time Complexity: O(n) 

 **Code(C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x: a) {
      cin >> x;
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
      ans = max(ans, 1LL * a[i] * a[i - 1]);
    }
    cout << ans << 'n';
  }
  return 0;
}
```
 **Code(Python)**
```cpp
import sys
input = sys.stdin.buffer.readline
t = int(input())
for _ in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  ans = 0
  for i in range(n - 1):
    ans = max(ans, a[i] * a[i + 1])
  print(ans)
```
 
### [1554B - Кобб](../problems/B._Cobb.md "Codeforces Round 735 (Div. 2)")

Let $f(i, j) = i \cdot j - k \cdot (a_i | a_j)$ for $i < j$.

Do we really need to check all pairs?

The value of $k$ is small, which is suspicious. There must be something revolving around it. What can that be?

In the equation, $i \cdot j$ can be $\mathcal{O}(n^2)$, but $k \cdot (a_i | a_j)$ is $\mathcal{O}(n \cdot 100)$. That means the value of $f(i, j)$ must be larger for bigger $i, j$. Can you deduce something from this? 

What is the smallest $i$ which can contribute to the result($f(i, j): i < j$ is the maximum)? Pause and think. Hint: try to maximize $f(i, j)$ and minimize the heaviest pair, that is, $f(n - 1, n)$, and compare them.

Let's find it. What is the maximum possible value of a pair containing $i$?. It's when $i$ pairs with $n$ and $a_i = a_n = 0$. So, $f(i, n) = i \cdot n - k \cdot 0 = i \cdot n$. 

What is the minimum possible value of the heaviest pair $f(n - 1, n)$? It's when $a_{n - 1} | a_n$ is maximum. And, since $0 \le a_i \le n$, the maximum possible of value any $a_i | a_j$ is $\le 2n$. So $f(n - 1, n) = (n - 1) \cdot n - k \cdot 2n = n^2 - 2kn - n$. 

For $i$ to contribute to the result, $f(i, n)$ must be $\gt f(n - 1, n)$. And, when $f(i, n) \gt f(n - 1, n)$, then $i \cdot n \gt n^2 - 2kn - n$, or $i \gt n - 2k -1$. So any of $f(i, j)$ such that $i < n - 2k$ won't generate a value greater than $f(n - 1, n)$!. This indicates us that we just have to check the pairs $f(i, j)$ such that $i, j \ge n - 2k$. And, there are only $\mathcal{O}(k^2)$ such pairs, so we can brute-force. 

We have also allowed $\mathcal{O}(n \cdot k)$ solutions to pass i.e. brute-forcing over all pairs such that $1 \le i \le n $ and $n - 2k \le j \le n$.

Time Complexity: $\mathcal{O}(k^2)$ 

 **Code(C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long ans = -1e12;
    int l = max(1, n - 2 * k);
    for (int i = l; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        ans = max(ans, 1LL * i * j - 1LL * k * (a[i] | a[j]));
      }
    }
    cout << ans << 'n';
  }
  return 0;
}
```
 **Code(Python)**
```cpp
import sys
input = sys.stdin.buffer.readline
t = int(input())
for _ in range(t):
  n, k = map(int, input().split())
  a = list(map(int, input().split()))
  l = max(0, n - 2 * k - 1)
  ans = -1e12
  for i in range(l, n):
    for j in range(i + 1, n):
      ans = max(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]))
  print(ans)
```
 
### [1554C - Микаса](../problems/C._Mikasa.md "Codeforces Round 735 (Div. 2)")

How can we check if $k$ is present in the sequence $n\oplus 0,n\oplus 1,...,n\oplus m$ ? Think.

If $k$ is present in the sequence, then there must be some $x$ such that $0 \le x \le m$ and $n\oplus x = k$, right?

Did you know that $n\oplus k = x$ is equivalent to $n\oplus x = k$ ?

So we can just check if $n\oplus k \le m$ or not! Pretty simple!

So the modified problem is to find the smallest non-negative integer $k$ such that $n\oplus k \ge m+1$. Can you solve it now?

Think using bits.

Let $p = m+1$ and $t_i$ be the $i$-th bit of $t$. We will find the smallest $k$ such that $n\oplus k \ge p$.

Let's build $k$ greedily from the highest bit to the lowest bit. Let's say we will find the $i$-th bit of $k$ and the higher bits have already been generated. Obviously, we will try to make this bit off if possible. When will it be impossible? Think.

If $n_i = p_i$, we can set $k_i = 0$ as $n_i \oplus 0 = n_i \ge p_i$. If $n_i = 1$ and $p_i = 0$, we can break here by setting the remaining bits of $k$ off as no matter what the remaining bits of $n$ are, $n \oplus k$ will always be greater than $p$. Finally, if $n_i = 0$ and $p_i = 1$, we must set $k_i = 1$, as we have no other options.

Check my solution for more clarity.

Time Complexity: $\mathcal{O}(log(n))$ per test case. 

 **Code(C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    ++m;
    int ans = 0;
    for (int k = 30; k >= 0 and n < m; k--) {
      if ((n >> k & 1) == (m >> k & 1)) continue;
      if (m >> k & 1) ans |= 1 << k, n |= 1 << k;
    }
    cout << ans << 'n';
  }
  return 0;
}
```
 **Code(Python)**
```cpp
import sys
input = sys.stdin.buffer.readline
t = int(input())
for _ in range(t):
  n, m = map(int, input().split())
  m += 1
  ans = 0
  for k in range(30, -1, -1):
    if (n >= m): break
    if ((n >> k & 1) == (m >> k & 1)): continue
    if (m >> k & 1):
      ans |= 1 << k
      n |= 1 << k
  print(ans)
```
 
### [1554D - Диана](../problems/D._Diane.md "Codeforces Round 735 (Div. 2)")

Consider the strings of type "$aa \ldots a$". Which substring occurs in which parity? Observe. Play with them.

Consider the string "$aa \ldots a$" ($k$ times '$a$'). WLOG Let $k$ be an odd integer. In this string "$a$" occurs $k$ times, "$aa$" occurs $k - 1$ times and so on. So "$a$", "$aa$", "$aaa$", $\ldots$ occurs odd, even, odd, even, $\ldots$ times, respectively.

Now let's look at the string "$aa \ldots a$" ($k - 1$ times '$a$'). In this string, "$a$", "$aa$", "$aaa$", $\ldots$ occurs even, odd, even, odd, $\ldots$ times, respectively. What can be done now?

Did you know that odd $+$ even $=$ odd?

Pause and think.

Let's merge both strings! If we merge them with "$b$" in-between i.e. "$\underbrace{aaa \ldots aaa}_\text{k times} b \underbrace{aaa\ldots aa}_\text{k - 1 times}$", then each substring will occur an odd number of times. Thats because each of "$a$", "$aa$", "$aaa$", $\ldots$ occurs odd $+$ even $=$ odd times, and each newly created substring occurs exactly once.

What will happen if we set $k = \left \lfloor{\frac{n}{2}}\right \rfloor$?

So here is the solution to the problem: "$\underbrace{aaa \ldots aaa}_\text{k times} + b | bc + \underbrace{aaa\ldots aa}_\text{k- 1 times}$", where $k = \left \lfloor{\frac{n}{2}}\right \rfloor$ and "$b$" when $n$ is even and "$bc$" when $n$ is odd. For example, if $n = 6$, answer is "$aaabaa$" and if $n = 7$, answer is "$aaabcaa$".

Time Complexity: $\mathcal{O}(n)$ 

 **Code(C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (n == 1) {
      cout << "an";
    }
    else {
      cout << string(n / 2, 'a') + (n & 1 ? "bc" : "b") + string(n / 2 - 1, 'a') << 'n';
    }
  }
  return 0;
}
```
 **Code(Python)**
```cpp
t = int(input())
for _ in range(t):
  n = int(input())
  if (n == 1):
    print('a')
  else:
    s = 'a' * (n // 2)
    if (n & 1):
      s += 'bc'
    else:
      s += 'b'
    s += 'a' * (n // 2 - 1)
    print(s)
```
If you are wondering(as you always do ｡^‿^｡) about the checker:

 **Checker**Write a suffix automata and check if every node occurs an odd number of times.

 **Code**
```cpp
#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

// len -> largest string length of the corresponding endpos-equivalent class
// link -> longest suffix that is another endpos-equivalent class.
// firstpos -> 1 indexed end position of the first occurrence of the largest string of that node
// minlen(v) -> smallest string of node v = len(link(v)) + 1
// terminal nodes -> store the suffixes
struct SuffixAutomaton {
  struct node {
    int len, link, firstpos;
    map<char, int> nxt;
  };
  int sz, last;
  vector<node> t;
  vector<int> terminal;
  vector<int> dp;
  vector<vector<int>> g;
  SuffixAutomaton() {}
  SuffixAutomaton(int n) {
    t.resize(2 * n); terminal.resize(2 * n, 0);
    dp.resize(2 * n, -1); sz = 1; last = 0;
    g.resize(2 * n);
    t[0].len = 0; t[0].link = -1; t[0].firstpos = 0;
  }
  void extend(char c) {
    int p = last;
    int cur = sz++;
    t[cur].len = t[last].len + 1;
    t[cur].firstpos = t[cur].len;
    p = last;
    while (p != -1 && !t[p].nxt.count(c)) {
      t[p].nxt[c] = cur;
      p = t[p].link;
    }
    if (p == -1) t[cur].link = 0;
    else {
      int q = t[p].nxt[c];
      if (t[p].len + 1 == t[q].len) t[cur].link = q;
      else {
        int clone = sz++;
        t[clone] = t[q];
        t[clone].len = t[p].len + 1;
        while (p != -1 && t[p].nxt[c] == q) {
          t[p].nxt[c] = clone;
          p = t[p].link;
        }
        t[q].link = t[cur].link = clone;
      }
    }
    last = cur;
  }
  void build_tree() {
    for (int i = 1; i < sz; i++) g[t[i].link].push_back(i);
  }
  void build(string &s) {
    for (auto x: s) {
      extend(x);
      terminal[last] = 1;
    }
    build_tree();
  }
  int cnt(int i) { // number of times i-th node occurs in the string
    if (dp[i] != -1) return dp[i];
    int ret = terminal[i];
    for (auto &x: g[i]) ret += cnt(x);
    return dp[i] = ret;
  }
};
pair<int, int> ok(string s) {
  int n = s.size();
  SuffixAutomaton sa(n);
  sa.build(s);
  for (int i = 1; i < sa.sz; i++) {
    if (sa.cnt(i) % 2 == 0) {
      return {sa.t[i].firstpos - sa.t[i].len, sa.t[i].firstpos - 1};
    }
  }
  return {-1, -1};
}
int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);
  int t = inf.readInt();
  inf.readEoln();
  for (int test = 1; test <= t; test++) {
    setTestCase(test);
    int n = inf.readInt();
    inf.readEoln();
    string s = ouf.readToken();
    if (s.size() != n) {
      quitf(_wa, "the length of s should be exactly %d", n);
    }
    for (int i = 0; i < n; i++) {
      if (!(s[i] >= 'a' and s[i] <= 'z')) {
        quitf(_wa, "s contains %c which is not an English lowercase character", s[i]);
      }
    }
    auto p = ok(s);
    if (p.first != -1) {
      quitf(_wa, "the substring s[%d, %d] (0-indexed) occurs even number of times in s :"(", p.first, p.second);
    }
  }
  quitf(_ok, "you are the best problem solver ever UwU");
  return 0;
}
```
 
### [1554E - Вы](../problems/E._You.md "Codeforces Round 735 (Div. 2)")

Let's find which sequences of $a$ are possible to obtain by performing the mentioned operations exactly $n$ times in some order.

(Critical) Observation 1: Consider all $a_i = 0$ initially. For each edge $(u, v)$, either increase $a_u$ by $1$ (assign $(u, v)$ to $u$) or increase $a_v$ by $1$ ((assign $(u, v)$ to $v$). The final sequences are the only possible sequences that $a$ can possibly be. You can observe it by noticing that when we select a node and delete it, the existing edges adjacent to the node gets assigned to it.

Notice that, the final sequences are unique. So there are $2^{n - 1}$ distinct sequences possible. That's because there are $n - 1$ edges and for each edge $(u, v)$ we have $2$ options — either assign it to $u$ or $v$.

Now for each $k$ from $1$ to $n$, we have to find the number of sequences which has gcd equals to $k$. Instead, let's find the number of sequences such that each of its values is divisible by $k$. Let it be $f_k$.

For $k = 1$, all sequences are valid. So $f_1 = 2^{n - 1}$.

Assume $k > 1$. Let's construct a sequence $a$ such that each $a_i$ is divisible by $k$. First, root the tree at node $1$. We will build the array in a bottom-up manner. Let $g_u$ be the set of childs of $u$ and $p_u$ be the parent of $u$. Assume that we have set the values for each $v \in g_u$. Now we will set the value of $a_u$. For each edge $(u, v)$ such that $v \in g_u$, if we have assigned this edge to $v$, then do nothing, otherwise we must assign it to $u$ i.e increase $a_u$ by $1$. After we are done with all the edges,

* if $a_u$ is divisible by $k$, then we can't assign the edge $(p_u, u)$ to $u$ because $a_u$ will be increased by $1$ and as $a_u$ is divisible by $k$, $(a_u + 1)$ will not be divisible by $k$ because $k > 1$.
* if $a_u$ is not divisible by $k$, then we must assign the edge $(p_u, u)$ to $u$ and thus increasing $a_u$ by $1$. If now $a_u$ is divisible by $k$, then we are done, otherwise we can't make $a_u$ divisible by $k$. So we terminate here.

If we can successfully set the values of $a_i$ for each $i$ from $1$ to $n$, then $f_k$ will be non-zero.

Observation 2: $f_k$ for $k > 1$ is either $0$ or $1$. We can say this by observing the building process of $a_i$ that has been discussed already.

So for each $k$ from $1$ to $n$, we can find the value of $f_k$ in $\mathcal{O}(n)$ by performing a simple dfs. So all $f_k$ can be found in $\mathcal{O}(n^2)$.

Observation 3: If $k$ doesn't divide $n - 1$, then $f_k = 0$. 

Proof: Notice that $\sum\limits_{i = 1}^{n}{a_i} = n - 1$. So for any integer $k$, if each $a_i$ is divisible $k$, then $k$ must divide $n - 1$. Similarly, if $k$ doesn't divide $n - 1$, then each $a_i$ will not be divisible by $k$ and $f_k$ will be $0$.

So we only have to perform a dfs when $k$ divides $n - 1$. So all $f_k$ can be found in $\mathcal{O}(n \cdot \sigma_0 (n - 1))$ where $\sigma_0(x)$ is the number of divisors of $x$. 

Let $h_k$ be the number of sequences which has gcd equals to $k$. We can notice that $h_k = f_k - \sum\limits_{i = 2}^{\left \lfloor{\frac{n}{k}}\right \rfloor}{h_{i \cdot k}}$.

So we can find $h_k$ for each $k$ from $1$ to $n$ in $\mathcal{O}(n \cdot log(n))$.

Time Complexity: $\mathcal{O}(n \cdot \sigma_0 (n - 1) + n \cdot log(n))$ 

 **Code(C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 998244353;

vector<int> g[N];
int dp[N], d, ok, ans[N];
void dfs(int u, int p = 0) {
  if (!ok) return;
  for (auto v: g[u]) {
    if (v ^ p) {
      dfs(v, u);
    }
  }
  if (dp[u] % d != 0) {
    if (p) {
      dp[u]++;
    }
    if (dp[u] % d != 0) {
      ok = 0;
      return;
    }
  }
  else {
    dp[p]++;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
      ans[i] = 0;
    }
    ans[1] = 1;
    for (int k = 1; k <= n - 1; k++) {
      ans[1] = (ans[1] + ans[1]) % mod;
    }
    for (d = 2; d <= n - 1; d++) {
      if ((n - 1) % d == 0) {
        ok = 1;
        dfs(1);
        ans[d] = ok;
        for (int i = 0; i <= n; i++) {
          dp[i] = 0;
        }
      }
    }
    for (int i = n; i >= 1; i--) {
      for (int j = i + i; j <= n; j += i) {
        ans[i] = (ans[i] - ans[j] + mod) % mod;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i > 1) cout << ' ';
      cout << ans[i];
    }
    cout << 'n';
    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
  }
  return 0;
}
```
