# Tutorial

[1796A - Typical Interview Problem](../problems/A._Typical_Interview_Problem.md "Educational Codeforces Round 144 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1796A - Typical Interview Problem](../problems/A._Typical_Interview_Problem.md "Educational Codeforces Round 144 (Rated for Div. 2)")

It's easy to see that the FB-string repeats every 8 characters: after processing every 15 numbers, we will get the same remainders modulo 3 and 5 as 15 numbers ago, and when we process 15 consecutive numbers, we get 8 characters. So, fi+8=fi.

This means that if we want to find a substring no longer than 10 characters in the FB-string, we don't need to consider more than 17 first characters of the FB-string: the substring of length 10 starting with the 8-th character ends with the 17-th character, and we don't need to consider substrings starting on positions greater than 8.

So, the solution is to generate at least 17 first characters of the FB-string, and then check if the substring occurs in the generated string using a standard function like find.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    string fb;
    int cur = 1;
    while(fb.size() < 100)
    {
        if(cur % 3 == 0) fb += "F";
        if(cur % 5 == 0) fb += "B";
        cur++;
    }
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        string s;
        cin >> s;
        cout << (fb.find(s) != string::npos ? "YES" : "NO") << endl;
    }
}
```
[1796B - Asterisk-Minor Template](../problems/B._Asterisk-Minor_Template.md "Educational Codeforces Round 144 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1796B - Asterisk-Minor Template](../problems/B._Asterisk-Minor_Template.md "Educational Codeforces Round 144 (Rated for Div. 2)")

What's the reason behind authors specifically asking for templates that have less or equal asterisks than letters? Well, without that the problem would be kind of trivial. A template "*" is matched by every string, so it would always work.

Hmm, let's try to make something similar to that template then. We basically have to find some part of that occurs in both strings that we can use letters on to get some freedom to use asterisks.

There are some easy cases. If the first letters of both strings are the same, then the template can be that letter followed by an asterisk. There's a symmetrical case for the last letter.

By studying the examples, you can also notice the final case: a common substring of both strings of length at least two surrounded by two asterisks. Moreover, since we only use two asterisks, we can find a substring of length exactly two (which always exists if a longer common substring exists).

Turns out, that's it. If a template exists, one of these three kinds also exists.

This is not that hard to show. If the first two kinds don't work, then you have to use asterisks on both sides of the template. In order for the template with asterisks on both sides to work, there have to be adjacent letters in it at least once (otherwise, it's like "*a*a*a*", and there are more asterisks than letters). And since at least one such substring exists, we can just remove everything other than this substring and the asterisks on the sides.

Overall complexity: O(|a|⋅|b|) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
    a = input()
    b = input()
    if a[0] == b[0]:
        print("YES")
        print(a[0] + "*")
        continue
    if a[-1] == b[-1]:
        print("YES")
        print("*" + a[-1])
        continue
    for i in range(len(b) - 1):
        if (b[i] + b[i + 1]) in a:
            print("YES")
            print("*" + b[i] + b[i + 1] + "*")
            break
    else:
        print("NO")
```
[1796C - Maximum Set](../problems/C._Maximum_Set.md "Educational Codeforces Round 144 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1796C - Maximum Set](../problems/C._Maximum_Set.md "Educational Codeforces Round 144 (Rated for Div. 2)")

Every beautiful set can be represented as a sequence of its elements in sorted order. Let these elements for some set be a1,a2,…,am; also, let di=ai+1ai. When the set is beautiful, every di is an integer greater than 1.

It's easy to see that if a1 and am belong to [l,r], the whole set belongs to [l,r]. Since am=a1⋅m−1∏i=1di, in order to maximize m, we need to choose a1 and di as small as possible. So, why don't we choose a1=l and every di=2? This will allow us to calculate the maximum possible size of a beautiful set (let m be this maximum possible size).

Okay, what about counting those sets? The claims a1=l and that every di=2 are no longer true by default. However, there are some constraints on di.

Firstly, every di≤3. If we had some value of di≥4, we could replace it with two values of di=2, and the size of the set would increase.

Secondly, there is at most one di=3. If there are two values di=3, we could replace them with three di=2, and the size of the set would increase as well.

So, the sequence di contains at most one value 3, and the rest of the values are 2.

We will divide the sets we want to count into two categories: the ones with all di=2, and the ones with one value di=3.

To count the sets in the first category, we simply need to count the number of different minimum values in those sets. Those minimum values have to be such that multiplying them by 2m−1 wouldn't make them greater than r, so these are all integers from the segment [l,⌊r2m−1⌋]. For every such integer, there exists exactly one set of the first category.

To count the sets in the second category, we do a similar thing. The minimum value in the set should be from the segment [l,⌊r2m−2⋅3⌋; but for every integer from this segment, there are m−1 different sets of the second category since there are m−1 ways to choose which di is equal to 3.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int l, r;
        cin >> l >> r;
        int max_size = 1;
        while((l << max_size) <= r)
            max_size++;
        int ans2 = (r / (1 << (max_size - 1)) - l + 1);
        if(max_size > 1)
            ans2 += (max_size - 1) * max(0, (r / (1 << (max_size - 2)) / 3 - l + 1));
        cout << max_size << " " << ans2 << endl;
    }
}
```
[1796D - Maximum Subarray](../problems/D._Maximum_Subarray.md "Educational Codeforces Round 144 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1796D - Maximum Subarray](../problems/D._Maximum_Subarray.md "Educational Codeforces Round 144 (Rated for Div. 2)")

There are greedy and dynamic programming solutions. We will describe dynamic programming solution.

The main task is to choose some segment that is the answer to the problem, while choosing k positions to increase by x. To do this, we can use dynamic programming dpi,j,t, where i is the number of positions that have already been considered (from 0 to n), j is the number of elements that have already been increased by x (from 0 to k), t is the flag showing the current state (whether we are before the chosen segment, inside the segment, or after the segment). Transitions in such dynamic programming are quite simple: we have a choice either to increase j by 1, then the value of the i-th element is ai+x, or not to increase, then the value of the i-th element is ai−x; we can also change the state of the flag (note that you can only switch from the current state to the subsequent ones, i.e., for example, you cannot switch from the state "the segment has already ended" to the state "inside the segment"). If the current state of the flag is "inside the segment", then ai+x or ai−x (depending on the selected transition) should be added to the dynamic programming value itself.

So, we got a solution in O(nk).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

using li = long long;

const int N = 222222;
const int K = 22;
const li INF = 1e18;

int n, k, x;
int a[N];
li dp[N][K][3];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= k; ++j) { 
        for (int t = 0; t < 3; ++t) {
          dp[i][j][t] = -INF;
        }
      }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= k; ++j) {
        for (int t = 0; t < 3; ++t) {
          if (dp[i][j][t] == -INF) continue;
          for (int jj = j; jj <= min(k, j + 1); ++jj) {
            li add = a[i] + (j == jj ? -x : x);
            for (int tt = t; tt < 3; ++tt) {
              dp[i + 1][jj][tt] = max(dp[i + 1][jj][tt], dp[i][j][t] + (tt == 1 ? add : 0));
            }
          }
        }
      }
    }
    cout << max(dp[n][k][1], dp[n][k][2]) << 'n';
  }
}
```
[1796E - Colored Subgraphs](../problems/E._Colored_Subgraphs.md "Educational Codeforces Round 144 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1796E - Colored Subgraphs](../problems/E._Colored_Subgraphs.md "Educational Codeforces Round 144 (Rated for Div. 2)")

Let's start by choosing a vertex r naively. Iterate over all vertices and try each of them.

Root the tree by r and observe what the conditions become. dv for each v is just the depth of each vertex. Well, then the only case, when the connected subgraph of vertices of the same color has all values of d distinct, is when they form a vertical path in the tree.

So the problem becomes the following. Split the tree into some vertical paths in such a way that the shortest path is as long as possible.

Let's try greedy, I guess. Start the paths from the leaves and propagate them up. Consider some vertex v with at least two children. All children have some paths leading up to them. We'd love to continue them all with v, but we can't do that. We can only continue one path and cut the rest. Pretty easy to see that the path to continue is the shortest path available. It's at least as optimal as any other path.

Do that from the lowest vertices up, and you got yourself a working greedy. Also don't forget to stop all paths in root, since you can't continue any of them further up.

Let's make this greedy more formal. Every time we update the answer is with a path that is: 

* the shortest in every vertex lower than the current one;
* not the shortest in the current one.

So we want to propagate the shortest child up and update the answer with the remaining children. Updating the answer means just taking the minimum of values. Thus, we can actually ignore all children except the second shortest in each vertex. Just don't forget to treat the root properly.

Now we can actually solve the problem in O(n) for a fixed r. You can just find two minimums in each vertex. 

Well, now that we can solve the problem for a single root, let's try rerooting to solve for all of them. There are solutions in O(n) but I found the solution in O(nlogn) the neatest. The constraints are low enough to allow it.

For each vertex, maintain a multiset of lengths of vertical paths from its children. I chose to store nothing in the leaves — that only makes the implementation cleaner. In order to update the vertex from its child, you can take the minimum element in the child's set and add 1 to it. If it's empty (the child is a leaf), return 1.

Additionally, store a multiset of the second minimums of all vertices that have at least two children.

In order to update the answer with the current root, find the minimum of that multiset and the shortest path from the root.

To achieve O(n), you will probably have to either store prefix and suffix second minimums over children of each vertex or store three shortest paths in it. It is kind of messy but it should still perform better.

Overall complexity: O(nlogn) or O(n) per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); i++) 

vector<vector<int>> g;
vector<multiset<int>> len;
multiset<int> all;

int getlen(int v){
    return len[v].empty() ? 1 : *len[v].begin() + 1;
}

void init(int v, int p = -1){
    for (int u : g[v]) if (u != p){
        init(u, v);
        len[v].insert(getlen(u));
    }
    if (int(len[v].size()) > 1){
        all.insert(*(++len[v].begin()));
    }
}

int ans;

void dfs(int v, int p = -1){
    ans = max(ans, min(*len[v].begin() + 1, *all.begin()));
    
    for (int u : g[v]) if (u != p){
        if (int(len[v].size()) > 1) all.erase(all.find(*(++len[v].begin())));
        len[v].erase(len[v].find(getlen(u)));
        if (int(len[v].size()) > 1) all.insert(*(++len[v].begin()));
        
        if (int(len[u].size()) > 1) all.erase(all.find(*(++len[u].begin())));
        len[u].insert(getlen(v));
        if (int(len[u].size()) > 1) all.insert(*(++len[u].begin()));
        
        dfs(u, v);
        
        if (int(len[u].size()) > 1) all.erase(all.find(*(++len[u].begin())));
        len[u].erase(len[u].find(getlen(v)));
        if (int(len[u].size()) > 1) all.insert(*(++len[u].begin()));
        
        if (int(len[v].size()) > 1) all.erase(all.find(*(++len[v].begin())));
        len[v].insert(getlen(u));
        if (int(len[v].size()) > 1) all.insert(*(++len[v].begin()));
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        int n;
        scanf("%d", &n);
        g.assign(n, {});
        forn(i, n - 1){
            int v, u;
            scanf("%d%d", &v, &u);
            --v, --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        len.assign(n, {});
        all.clear();
        all.insert(n);
        init(0);
        ans = 0;
        dfs(0);
        printf("%dn", ans);
    }
}
```
[1796F - Strange Triples](../problems/F._Strange_Triples.md "Educational Codeforces Round 144 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon") and [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1796F - Strange Triples](../problems/F._Strange_Triples.md "Educational Codeforces Round 144 (Rated for Div. 2)")

Let |n| be the length of number n. Then annb=ab⇔(a⋅10|n|+n)b=a(n⋅10|b|+b) Let g=gcd(a,b) then a=a′g and b=b′g and we get (a⋅10|n|+n)b=a(n⋅10|b|+b)⇔g2a′b′⋅10|n|+gnb′=ga′n⋅10|b|+g2a′b′⇔ ⇔ga′b′⋅10|n|+nb′=a′n⋅10|b|+ga′b′

Note that the right part is divisible by a′, so the left part should as well. Then we can see that n should be divisible by a′, since gcd(b′,a′)=1. Let's say n=n′a′ then divide both sides by a′. We get ga′b′⋅10|n|+n′a′b′=a′n′a′⋅10|b|+ga′b′⇔gb′⋅10|n|+n′b′=a′n′⋅10|b|+gb′

Let's rearrange it and get the following: n′b′=a′n′⋅10|b|−b(10|n|−1) b′=a′⋅10|b|−b(10|n|−1)n′

Since b′ is integer, then b(10|n|−1)n′ should be integer. In other words, we can define n′=k1k2 such that b is divisible by k1 and (10|n|−1) is divisible by k2 and k1 is minimum possible.

Since (10|n|−1) has a very special structure, let's iterate over all lengths |n| (1≤|n|≤9) and all divisors k2 of (10|n|−1) for a fixed |n|. Let's say d=bk1 and r=(10|n|−1)k2. Then b′=a′⋅10|b|−d⋅r

For a fixed |n| and k2 we know r, but don't know d. So, let's just iterate over all possible d (1≤d≤105) and let's also iterate over all |b|, since |b| is small (|d|≤|b|≤5, since d is a divisor of b). Next step is following: let's look at previous equation, but modulo 10|b|: b′≡−d⋅r(mod10|b|)

Since b′≤b<10|b| then there is a unique solution to the previous module equation, or: b′=10|b|−(d⋅r)mod10|b|

Now we know exact value b′ and |b|, so now the time to guess g (let's recall that b=b′g). Since we fixed |b|, then 10|b|−1≤b′g<10|b|, or ⌈10|b|−1b′⌉≤g≤⌊10|b|−1b′⌋ Let's name the left border as lb and right border rb, so inequality earlier is lb≤g≤rb.

But we can make constrains even tighter: note that b=b′g, but lately, we said that d=bk1 or b=dk1. So, b′g=dk1, or g should be divisible by dd=dgcd(d,b′).

In total, we can iterate g in range [⌈lbdd⌉⋅dd,…,⌊rbdd⌋⋅dd] with step dd, since we are interested only in g divisible by dd.

Now we have enough variables to construct a triple: we know b′ and g, so b=b′g. If b is already big (b≥B), we can skip that candidate. Also, we can calculate k1=bd and check that pair (k1,k2) is valid, i. e. k1 is really minimum possible. We can understand it by checking that gcd(k1,r)=1 (otherwise, we can reduce k1 by gcd(k1,r)).

Value a′ can be calculated from one of the formulas above as a′=d⋅r+b′10|b|. After that, we calculate a=a′g and check that a is not too big. Value n can be calculated as n=k1k2a′=bdk2a′.

At last, we should check that the given triple satisfy all remaining assumptions we made: n is not too big, gcd(a′,b′) is really 1 and length of calculated n is exactly |n| we fixed. If it's all fine, then we found a correct triple. It looks like, thanks to all previous checks, the triple we found is unique, but, just for safety, let's push them all in one set to get rid of copies.

Calculating complexity is not trivial, but let's note something: the total number of divisors k2 of 10|n|−1 for all |n| is around 180. For a fixed pair (|n|,k2), we iterate over all d from 1 to B and for each d we iterate |b| from |d| to 5, but it's easy to prove that the total number of pairs (d,|b|) is at most 1.3⋅B. Now the last cycle: iteration of g with step dd where dd=dgcd(d,b′). If we assume that gcd(d,b′) is quite small then dd is proportional to d, and pairs (d,g) are something like harmonic series with O(BlogB) complexity. In total, the complexity is around O(200BlogB).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

#define sz(a) int((a).size())

using li = long long;

const int MAXLEN = 5;

vector<int> divs(int x) {
  vector<int> res;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      res.push_back(i);
      if (i * i != x)
        res.push_back(x / i);
    }
  }
  return res;
}

int main() {
  int A, B, N;
  cin >> A >> B >> N;

  vector<int> pw(10);
  pw[0] = 1;
  for (int i = 1; i < 10; ++i) pw[i] = pw[i - 1] * 10;
  
  int PW = pw[MAXLEN];
  set<array<int, 3>> used;
  
  vector<int> len(PW);
  for (int i = 0; i < PW; ++i)
    len[i] = sz(to_string(i));
  
  for (int lenn = 1; lenn <= 9; ++lenn) {
    int x = pw[lenn] - 1;
    for (int k2 : divs(x)) {
      int r = x / k2;
      for (int d = 1; d < PW; ++d) {
        for (int lenb = len[d]; lenb <= MAXLEN; ++lenb) {
          int bg = pw[lenb] - d * li(r) % pw[lenb];
          int dd = d / __gcd(d, bg);
          int lb = (pw[lenb - 1] + bg - 1) / bg;
          int rb = (pw[lenb] - 1) / bg;
          for (int g = (lb + dd - 1) / dd * dd; g <= rb; g += dd) {
            int b = bg * g;
            assert(b % d == 0);
            if (b >= B || __gcd(b / d, r) != 1) continue;
            int ag = (d * li(r) + bg) / pw[lenb];
            li n = b / d * li(k2) * ag;
            if (n < N && ag * g < A && __gcd(ag, bg) == 1 && sz(to_string(n)) == lenn) 
              used.insert({ag * g, b, n});
          }
        }
      }
    }
  }
  
  int res = 0;
  for (auto it : used) {
    li a = it[0], b = it[1], n = it[2];
    int lenn = sz(to_string(n));
    int lenb = sz(to_string(b));
    res += a * b * pw[lenn] + n * b == a * n * pw[lenb] + a * b;
  }
  
  cout << res << endl;
}

```
