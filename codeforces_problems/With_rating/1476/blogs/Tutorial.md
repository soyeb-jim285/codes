# Tutorial

[1476A - K-divisible Sum](../problems/A._K-divisible_Sum.md "Educational Codeforces Round 103 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1476A - K-divisible Sum](../problems/A._K-divisible_Sum.md "Educational Codeforces Round 103 (Rated for Div. 2)")

Let's denote $s$ as the sum of array $a$. From one side, since $s$ should be divisible by $k$ then we can say $s = cf \cdot k$. From other side, since all $a_i$ are positive, then $s \ge n$.

It's quite obvious that the smaller $s$ — the smaller maximum $a_i$ so we need to find the smallest $cf$ that $cf \cdot k \ge n$. Then $cf = \left\lceil \frac{n}{k} \right\rceil = \left\lfloor \frac{n + k - 1}{k} \right\rfloor$.

Now we now that $s = cf \cdot k$ and we need to represent it as $a_1 + \dots + a_n$ with maximum $a_i$ minimized. It's easy to prove by contradiction that maximum $a_i \ge \left\lceil \frac{s}{n} \right\rceil$.

Moreover we can always construct such array $a$ that its sum is equal to $s$ and the maximum element is equal to $\left\lceil \frac{s}{n} \right\rceil$.

As a result, the answer is $\left\lceil \frac{s}{n} \right\rceil = \left\lfloor \frac{cf \cdot k + n - 1}{n} \right\rfloor$, where $cf = \left\lfloor \frac{n + k - 1}{k} \right\rfloor$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    long long n, k;
    cin >> n >> k;
    
    long long cf = (n + k - 1) / k;
    k *= cf;
    
    cout << (k + n - 1) / n << endl;
  }
  return 0;
}
```
[1476B - Inflation](../problems/B._Inflation.md "Educational Codeforces Round 103 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1476B - Inflation](../problems/B._Inflation.md "Educational Codeforces Round 103 (Rated for Div. 2)")

Suppose we decided to increase some $p_i$ by $x > 0$. How does it affect all inflation coefficients? Let's the $j$-th inflation coefficient be $cf_j$. We now that $cf_j = \frac{p_j}{p_0 + \dots + p_{j - 1}}$.

If $j < i$, then $cf_j$ doesn't change. If $j > i$ then it's denominator increases by $x$ and $cf_j$ decreases. If $j = i$ then it's numerator increases and $cf_j$ increases as well.

But, if we increase $p_{i - 1}$ instead of $p_i$ then all decreased $cf_j$ will decrease as well and also $cf_i$ will decrease. Finally, if we increase $p_0$ then all $cf_j$ decrease and there is no $cf_j$ that increases — so it's always optimal to increase only $p_0$.

Now we need to calculate what is minimum $x$ we should add to $p_0$. There are two ways: we can either binary search this value $x$ knowing that $x = 100 \cdot 10^9$ is always enough. Then we just need to check that all $cf_j \le \frac{k}{100}$ (that is equivalent to checking that $p_j \cdot 100 \le k \cdot (x + p_0 + \dots + p_{j - 1})$).

Or we can note that each $cf_j = \frac{p_j}{(p_0 + \dots + p_{j - 1}) + x}$ and we need to make $cf_j \le \frac{k}{100}$ or that $100 \cdot p_j - k \cdot (p_0 + \dots + p_{j - 1}) \le k \cdot x$ or $x \ge \left\lceil \frac{100 \cdot p_j - k \cdot (p_0 + \dots + p_{j - 1})}{k} \right\rceil$. Since we should fulfill all conditions then we should take $x$ as maximum over all fractions.

Since $(p_0 + \dots + p_{j - 1})$ is just a prefix sum, we can check condition for each $cf_j$ in $O(1)$. It total, the time complexity is either $O(n)$ or $O(n \log{n})$ per test case.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long li;

const int INF = int(1e9);

int main() {
  int t; cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
      cin >> p[i];
    
    li x = 0;
    li pSum = p[0];
    for (int i = 1; i < n; i++) {
      x = max(x, (100ll * p[i] - k * pSum + k - 1) / k);
      pSum += p[i];
    }
    cout << x << endl;
  }
  return 0;
}
```
[1476C - Longest Simple Cycle](../problems/C._Longest_Simple_Cycle.md "Educational Codeforces Round 103 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1476C - Longest Simple Cycle](../problems/C._Longest_Simple_Cycle.md "Educational Codeforces Round 103 (Rated for Div. 2)")

Suppose, we've built the graph and chosen any simple cycle. Due to the nature of the graph, any simple cycle right part is part of one of the chains. So, let's for each chain calculate the longest simple path with its right part on this chain and denote it as $len_i$.

Obviously, $len_1 = 0$. Now, let's look at chain $i$. If we go along the cycle in both ways, we will step to vertices $a_i$ and $b_i$ of the previous chain. If $a_i = b_i$ then we closed cycle and it's the only possible cycle, so $len_i = c_i + 1$.

Otherwise, we can either go from $a_i$ and $b_i$ and meet each other closing the cycle with part of the $(i - 1)$-th chain between $a_i$-th and $b_i$-th vertices — this part has $|a_i - b_i|$ edges and our cycle will have length $c_i + 1 + |a_i - b_i|$.

But if we decide to go in different ways, then we will meet the first and the last vertices of the $(i - 1)$-th chain. After that, we'll go to the $a_{i - 1}$-th and the $b_{i - 1}$-th vertices of $(i - 2)$-th chain and will make almost the same choice.

But, instead of recurrently solving the same problem, we can note that, in fact, we took a cycle that ends at the $(i - 1)$-th chain, erased the part between vertices $a_i$ and $b_i$, and merged it with our $i$-th chain part, so the length of this merged cycle will be equal to $c_i + 1 + len_{i - 1} - |a_i - b_i|$. Since we maximize $len_i$ we just choose, what part: $|a_i - b_i|$ or $len_{i - 1} - |a_i - b_i|$ is longer and take it.

As a result, we can iterate from left to right, calculate all $len_i$ and print the maximum among them.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

typedef long long li;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> c(n), a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> c[i];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    
    li ans = 0;
    li lstLen = 0;
    for (int i = 1; i < n; i++) {
      li curLen = c[i] + 1ll + abs(a[i] - b[i]);
      if (a[i] != b[i])
        curLen = max(curLen, c[i] + 1ll + lstLen - abs(a[i] - b[i]));
      ans = max(ans, curLen);
      lstLen = curLen;  
    }
    cout << ans << endl;
  }
  return 0;
};
```
[1476D - Journey](../problems/D._Journey.md "Educational Codeforces Round 103 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1476D - Journey](../problems/D._Journey.md "Educational Codeforces Round 103 (Rated for Div. 2)")

There are two key observations to this problem:

* after each pair of moves, the directions go back to the original ones;
* after each move, we can immediately go back (and combining these observations, we can derive that if we go from city $i$ to some other city $j$, we can always go back).

One of the solutions we can write using these observations is to build an undirected graph on $2n+2$ vertices. Each vertex represents a pair $(v, k)$, where $v$ is the city we are currently staying in, and $k$ is the number of moves we made, modulo $2$. Since each move is to a neighboring city, each vertex $(v, 0)$ is unreachable from $(v, 1)$, and vice versa. And since we can always go back, and each pair of steps doesn't change the directions, this graph is actually an undirected one. So, we can find the connected components of this graph using DFS/BFS/DSU, and for each city $v$, print the size of the component the vertex $(v, 0)$ belongs to.

Another solution is to find the leftmost and the rightmost city reachable from each city. For example, finding the leftmost reachable city can be done with the following dynamic programming: let $dp_i$ be the leftmost city reachable from $i$. Then, if we can't go left from $i$, $dp_i = i$; if we can make only one step to the left from $i$, $dp_i = i - 1$; and if we can make two steps, we can take the answer from the city $i - 2$: $dp_i = dp_{i - 2}$. The same approach can be used to calculate the rightmost reachable city.

 **Solution 1 (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

char buf[300043];

int main()
{
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", buf);
        string s = buf;
        vector<vector<int>> g(2 * n + 2);
        for(int i = 0; i < n; i++)
            if(s[i] == 'L')
            {
                g[(i + 1) * 2].push_back(i * 2 + 1);
                g[i * 2 + 1].push_back((i + 1) * 2);
            }
            else
            {
                g[i * 2].push_back((i + 1) * 2 + 1);
                g[(i + 1) * 2 + 1].push_back(i * 2);   
            }
        vector<int> comp(2 * n + 2, -1);
        vector<int> cnt;
        for(int i = 0; i < 2 * n + 2; i++)
        {
            if(comp[i] != -1) continue;
            int c = 1;
            int cc = cnt.size();
            queue<int> q;
            comp[i] = cc;
            q.push(i);
            while(!q.empty())
            {
                int k = q.front();
                q.pop();
                for(auto y : g[k])
                {
                    if(comp[y] == -1)
                    {
                        c++;
                        comp[y] = cc;
                        q.push(y);
                    }
                }
            }
            cnt.push_back(c);
        }
        for(int i = 0; i <= n; i++)
            printf("%d%c", cnt[comp[i * 2]], " n"[i == n]);
    }
}
```
 **Solution 2 (BledDest)**
```cpp
t = int(input())

for _ in range(t):
    n = int(input())
    s = input()
    dpl = [i for i in range(n + 1)]
    dpr = [i for i in range(n + 1)]
    for i in range(n + 1):
        if i == 0 or s[i - 1] == 'R':
            dpl[i] = i
        elif i == 1 or s[i - 2] == 'L':
            dpl[i] = i - 1
        else:
            dpl[i] = dpl[i - 2]
    for i in range(n, -1, -1):
        if i == n or s[i] == 'L':
            dpr[i] = i
        elif i == n - 1 or s[i + 1] == 'R':
            dpr[i] = i + 1
        else:
            dpr[i] = dpr[i + 2]
    ans = [(dpr[i] - dpl[i]) + 1 for i in range(n + 1)]
    print(*ans)
```
[1476E - Pattern Matching](../problems/E._Pattern_Matching.md "Educational Codeforces Round 103 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1476E - Pattern Matching](../problems/E._Pattern_Matching.md "Educational Codeforces Round 103 (Rated for Div. 2)")

Let's write down the indices of the pattern that the $j$-th string matches. If $mt_j$ is not among these, then the answer is NO. Otherwise, all the patterns except $mt_j$ should go in the resulting ordering after $mt_j$.

Consider that as a graph. Let's add an edge from $mt_j$ to each of the matches. If you add the edges for all the strings, then the topological ordering of the graph will give you the valid result. If the graph has any cycles in it (you can't topsort it), then there is no answer.

To find all the patterns we can use the fact that $k$ is rather small. Consider all the $2^k$ binary masks of length $k$. Each mask can correspond to a set of positions in the string that are replaced with wildcards. Now, if there is a pattern that is exactly equal to the string with the fixed set of positions replaced by wildcards, then that pattern is a match.

To search for an exact match, you can either store all patterns in a map beforehand (or in a sorted array) or build a trie of them. The second version is faster by a factor of $\log n$ but both solutions should pass easily.

Overall complexity: $O(nk \log n + mk \cdot 2^k \log n)$ or $O(nk + m \cdot 2^k)$.

 **Solution 1 (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct pattern{
  string s;
  int i;
};

bool operator <(const pattern &a, const pattern &b){
  return a.s < b.s;
}

vector<vector<int>> g;
vector<int> used, ord;
bool cyc;

void ts(int v){
  used[v] = 1;
  for (int u : g[v]){
    if (used[u] == 0)
      ts(u);
    else if (used[u] == 1)
      cyc = true;
    if (cyc)
      return;
  }
  used[v] = 2;
  ord.push_back(v);
}

int main() {
    cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<pattern> p(n);
  g.assign(n, vector<int>());
  forn(i, n){
    cin >> p[i].s;
    p[i].i = i;
  }
  sort(p.begin(), p.end());
  pattern nw;
  nw.s = string(k, '_');
  forn(i, m){
    string cur;
    int mt;
    cin >> cur >> mt;
    --mt;
    bool ok = false;
    forn(mask, 1 << k){
      forn(j, k)
        nw.s[j] = ((mask >> j) & 1 ? cur[j] : '_');
      auto it = lower_bound(p.begin(), p.end(), nw);
      if (it != p.end() && it->s == nw.s){
        if (it->i != mt)
          g[mt].push_back(it->i);
        else
          ok = true;
      }
    }
    if (!ok){
      puts("NO");
      return 0;
    }
  }
  used.assign(n, 0);
  cyc = false;
  ord.clear();
  forn(i, n) if (!used[i]){
    ts(i);
    if (cyc){
      cout << "NOn";
      return 0;
    }
  }
  reverse(ord.begin(), ord.end());
  cout << "YESn";
  forn(i, n)
    cout << ord[i] + 1 << " ";
  cout << "n";
  return 0;
}
```
 **Solution 2 (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct pattern{
  string s;
  int i;
};

bool operator <(const pattern &a, const pattern &b){
  return a.s < b.s;
}

vector<vector<int>> g;
vector<int> used, ord;
bool cyc;

void ts(int v){
  used[v] = 1;
  for (int u : g[v]){
    if (used[u] == 0)
      ts(u);
    else if (used[u] == 1)
      cyc = true;
    if (cyc)
      return;
  }
  used[v] = 2;
  ord.push_back(v);
}

struct node{
  int nxt[28];
  int term;
  node(){
    memset(nxt, -1, sizeof(nxt));
    term = -1;
  }
};

vector<node> trie;

void add(const string &s, int i){
  int cur = 0;
  for (char c : s){
    int x = c - '_';
    if (trie[cur].nxt[x] == -1){
      trie[cur].nxt[x] = trie.size();
      trie.push_back(node());
    }
    cur = trie[cur].nxt[x];
  }
  trie[cur].term = i;
}

bool check(int i, int v, const string &s, int mt){
  if (i == int(s.size())){
    assert(trie[v].term != -1);
    if (trie[v].term != mt)
      g[mt].push_back(trie[v].term);
    else
      return true;
    return false;
  }
  bool res = false;
  if (trie[v].nxt[s[i] - '_'] != -1 && check(i + 1, trie[v].nxt[s[i] - '_'], s, mt))
    res = true;
  if (trie[v].nxt[0] != -1 && check(i + 1, trie[v].nxt[0], s, mt))
    res = true;
  return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  trie = vector<node>(1);
  int n, m, k;
  cin >> n >> m >> k;
  g.assign(n, vector<int>());
  forn(i, n){
    string cur;
    cin >> cur;
    add(cur, i);
  }
  pattern nw;
  nw.s = string(k, '_');
  forn(i, m){
    string cur;
    int mt;
    cin >> cur >> mt;
    if (!check(0, 0, cur, mt - 1)){
      cout << "NOn";
      return 0;
    }
  }
  used.assign(n, 0);
  cyc = false;
  ord.clear();
  forn(i, n) if (!used[i]){
    ts(i);
    if (cyc){
      cout << "NOn";
      return 0;
    }
  }
  reverse(ord.begin(), ord.end());
  cout << "YESn";
  forn(i, n)
    cout << ord[i] + 1 << " ";
  cout << "n";
  return 0;
}
```
[1476F - Lanterns](../problems/F._Lanterns.md "Educational Codeforces Round 103 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1476F - Lanterns](../problems/F._Lanterns.md "Educational Codeforces Round 103 (Rated for Div. 2)")

The main idea of the solution is to calculate the following dynamic programming: $dp_i$ is the maximum prefix we can fully cover with $i$ first lanterns.

Let's look at how can we solve it in $O(n^2)$ with this kind of dynamic programming. First of all, let's write it forward. Which transitions from $dp_i$ do we have?

* iterate on the lantern facing left that will cover the lantern $dp_i + 1$. Let this lantern be $j$. It should cover all lanterns in $[dp_i + 1, j - 1]$, so all lanterns from $[i, j)$ can be turned to the right (and we need a max query to determine the new covered prefix);
* if $dp_i > i$ (lantern $i$ is already covered), we can just extend the prefix by turning the $i$-th lantern to the right. Note that turning it to the right when it is not covered yet will be modeled by the first transition.

It is obviously $O(n^2)$, how can we optimize it? Let's write this dynamic programming backward. The second transition is changed to backward dp easily, what about the first one? Suppose we want to turn some lantern $i$ to the left. Let's iterate on the prefix $j$ that we will "connect" to it; for this prefix, $dp_j$ should be at least $i - p_i - 1$, and we update $dp_i$ with the maximum of $i - 1$ (since it is covered by lantern $i$) and the result of max query on $[j + 1, i - 1]$.

In fact, we need only one such prefix — the one with the minimum $j$ among those which have $dp_j \ge i - p_i - 1$. So, we build a minimum segment tree where each pair $(i, dp_i)$ is interpreted as the value of $i$ in position $dp_i$, and with min query on the suffix from $i - p_i - 1$ we find this optimal prefix, from which we should update (and to update, we can use any DS that allows max queries on segment — in my solution, it's another segment tree).

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

struct segTree
{
    int n;
    bool mx;
    vector<int> t;

    void fix(int v)
    {
        t[v] = (mx ? max(t[v * 2 + 1], t[v * 2 + 2]) : min(t[v * 2 + 1], t[v * 2 + 2]));
    }

    void build(int v, int l, int r)
    {
        if(l == r - 1)
            t[v] = (mx ? -INF : INF);
        else
        {
            int m = (l + r) / 2;
            build(v * 2 + 1, l, m);
            build(v * 2 + 2, m, r);
            fix(v);
        }
    }

    void upd(int v, int l, int r, int pos, int val)
    {
        if(l == r - 1)
            t[v] = (mx ? max(t[v], val) : min(t[v], val));
        else
        {
            int m = (l + r) / 2;
            if(pos < m)
                upd(v * 2 + 1, l, m, pos, val);
            else
                upd(v * 2 + 2, m, r, pos, val);
            fix(v);
        }
    }

    int get(int v, int l, int r, int L, int R)
    {
        if(L >= R)
            return (mx ? -INF : INF);
        if(l == L && r == R)
            return t[v];
        int m = (l + r) / 2;
        int lf = get(v * 2 + 1, l, m, L, min(R, m));
        int rg = get(v * 2 + 2, m, r, max(m, L), R);
        return (mx ? max(lf, rg) : min(lf, rg));
    }

    void upd(int pos, int val)
    {
        upd(0, 0, n, pos, val);
    }

    int get(int L, int R)
    {
        return get(0, 0, n, L, R);
    }

    void build()
    {
        return build(0, 0, n);
    }

    segTree() {};
    segTree(int n, bool mx) : n(n), mx(mx)
    {
        t.resize(4 * n);
    }
};

int main()
{
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++)
    {
        int n;
        scanf("%d", &n);
        vector<int> p(n);
        for(int i = 0; i < n; i++)
            scanf("%d", &p[i]);
        vector<int> dp(n + 1, -INF);
        vector<int> par(n + 1, -2);
        dp[0] = 0;
        par[0] = -1;
        vector<int> lf(n), rg(n);
        for(int i = 0; i < n; i++)
        {
            lf[i] = max(1, i - p[i] + 1);
            rg[i] = min(n, i + p[i] + 1);
        }
        segTree sn(n + 1, false);        
        segTree sx(n, true);
        sn.build();
        sx.build();
        for(int i = 0; i < n; i++)
            sx.upd(i, rg[i]);
        sn.upd(0, 0);
        for(int i = 1; i <= n; i++)
        {
            int j = i - 1;
            int k = lf[j] - 1;
            
            int m = sn.get(k, n + 1);                 
            if(m != INF)
            {
                int nval = max(sx.get(m, i - 1), i - 1);
                if(nval > dp[i])
                {
                    dp[i] = nval;
                    par[i] = m;
                }
            }
            if(dp[j] >= i && max(dp[j], rg[j]) > dp[i])
            {
                dp[i] = max(dp[j], rg[j]);
                par[i] = -1;
            }
            if(dp[j] > dp[i])
            {
                dp[i] = dp[j];
                par[i] = -1;
            }
            sn.upd(dp[i], i);                
        }
        if(dp[n] != n)
            puts("NO");
        else
        {
            puts("YES");
            string ans;
            int cur = n;
            while(cur != 0)
            {
                if(par[cur] == -1)
                {
                    cur--;
                    ans += "R";
                }
                else
                {
                    int pcur = par[cur];
                    int diff = cur - pcur;
                    ans += "L";
                    for(int j = 0; j < diff - 1; j++)
                        ans += "R";
                    cur = pcur;    
                }
            }
            reverse(ans.begin(), ans.end());
            puts(ans.c_str());
        }
    }
}
```
[1476G - Minimum Difference](../problems/G._Minimum_Difference.md "Educational Codeforces Round 103 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1476G - Minimum Difference](../problems/G._Minimum_Difference.md "Educational Codeforces Round 103 (Rated for Div. 2)")

Let's consider a problem without queries of the second type.

Now we can try to solve the problem using Mo's algorithm. Let's maintain array $cnt_i$ — the number of occurrences of $i$ on the current segment and array $ord$ — array $cnt$ sorted in descending order.

Let's take a look at how we should handle adding an element equal to $x$. Surely, we should increase $cnt_x$ by $1$, but now we should erase an element equal to $cnt_x-1$ from the array $ord$ and insert an element $cnt_x$ is such a way that the array is still sorted. Instead, we can increase the leftmost element equal to $cnt_x-1$ by $1$. Similarly, we can handle deleting an element (decrease the rightmost element equal to $cnt_x$ by $1$). In order to quickly find the leftmost (rightmost) element equal to $x$, we can store the left and the right bounds of the array $ord$ where all the numbers are equal to $x$.

To answer the query of type $1$, we should find two elements in the $ord$ array at distance $k$ whose absolute difference is minimal. Since the size of the array $ord$ (without zero elements) is $O(n)$, we can't look at the whole array. But using the fact that there are no more than $O(\sqrt{n})$ different values in the $ord$ array, we can create an auxiliary array of pairs $(value, cnt)$ (the value from the array $ord$ and the number of occurrences of that value). In such an array, we need to find a subarray where the sum of the second elements in the pairs is at least $k$, and the absolute difference between the first elements in the pairs is minimal. That can be solved using standard two pointers method in $O(\sqrt{n})$.

The total complexity of the solution is $O(n\sqrt{n})$.

In fact, we can use Mo's algorithm even with updates. But its complexity is $O(n^{\frac{5}{3}} + m\sqrt{n})$. You can read the editorial of the problem 940F on Codeforces or the following blog to learn about processing updates in Mo: https://codeforces.com/blog/entry/72690

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)

typedef pair<int, int> pt;

const int N = 100 * 1000 + 13;
const int P = 2000;

struct query {
  int t, l, r, k, i;
};

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n);
  forn(i, n) scanf("%d", &a[i]);
  
  vector<query> q;
  vector<array<int, 3>> upd;
  
  forn(i, m) {
    int tp;
    scanf("%d", &tp);
    if (tp == 1) {
      int l, r, k;
      scanf("%d%d%d", &l, &r, &k);
      q.push_back({sz(upd), l - 1, r - 1, k, sz(q)});
    } else {
      int p, x;
      scanf("%d%d", &p, &x); --p;
      upd.push_back({p, a[p], x});
      a[p] = x;
    }
  }
  
  sort(q.begin(), q.end(), [](const query &a, const query &b) {
    if (a.t / P != b.t / P)
      return a.t < b.t;
    if (a.l / P != b.l / P)
      return a.l < b.l;
    if ((a.l / P) & 1)
      return a.r < b.r;
    return a.r > b.r; 
  });
  
  for (int i = sz(upd) - 1; i >= 0; --i)
    a[upd[i][0]] = upd[i][1];
  
  vector<int> cnt(N), ord(N);
  vector<pt> bounds(N, {N, 0});
  bounds[0] = {0, N - 1};
  int L = 0, R = -1, T = 0;
  
  auto add = [&](int x) {
    int c = cnt[x];
    ++ord[bounds[c].x];
    bounds[c + 1].y = bounds[c].x;
    if (bounds[c + 1].x == N)
      bounds[c + 1].x = bounds[c].x;
    if (bounds[c].x == bounds[c].y)
      bounds[c].x = N - 1;
    ++bounds[c].x;
    ++cnt[x];
  };
  
  auto rem = [&](int x) {
    int c = cnt[x];
    --ord[bounds[c].y];
    if (bounds[c - 1].x == N)
      bounds[c - 1].y = bounds[c].y;
    bounds[c - 1].x = bounds[c].y;
    if (bounds[c].x == bounds[c].y)
      bounds[c].x = N;
    --bounds[c].y;
    --cnt[x];
  };
  
  auto apply = [&](int i, int fl) {
    int p = upd[i][0];
    int x = upd[i][fl + 1];
    if (L <= p && p <= R) {
      rem(a[p]);
      add(x);
    }
    a[p] = x;
  };
  
  vector<int> ans(sz(q));
  
  for (auto qr : q) {
    int t = qr.t, l = qr.l, r = qr.r, k = qr.k;
    while (T < t) apply(T++, 1);
    while (T > t) apply(--T, 0);
    while (R < r) add(a[++R]);
    while (L > l) add(a[--L]);
    while (R > r) rem(a[R--]);
    while (L < l) rem(a[L++]);
    
    int res = N;
    for (int i = 0, j = 0, sum = 0; i < N && ord[i] > 0; i = bounds[ord[i]].y + 1) {
      while (j < N && ord[j] > 0 && sum < k) {
        sum += bounds[ord[j]].y - bounds[ord[j]].x + 1;
        j = bounds[ord[j]].y + 1;
      }
      if (sum >= k) res = min(res, ord[i] - ord[j - 1]);
      sum -= bounds[ord[i]].y - bounds[ord[i]].x + 1;
    }
    if (res == N) res = -1;
    ans[qr.i] = res;
  }
  
  for (int x : ans) printf("%dn", x);
}
```
