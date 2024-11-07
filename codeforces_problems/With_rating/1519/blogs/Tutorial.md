# Tutorial

[1519A - Red and Blue Beans](../problems/A._Red_and_Blue_Beans.md "Educational Codeforces Round 108 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1519A - Red and Blue Beans](../problems/A._Red_and_Blue_Beans.md "Educational Codeforces Round 108 (Rated for Div. 2)")

Without loss of generality, let's say $r \le b$ (otherwise, we can swap them). Note that you can't use more than $r$ packets (at least one red bean in each packet), so $b$ can't exceed $r \cdot (d + 1)$ (at most $d + 1$ blue beans in each packet).

So, if $b > r \cdot (d + 1)$ then asnwer is NO. Otherwise, we can form exactly $r$ packets.

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (r, b, d) = readLine()!!.split(' ').map { it.toInt() }
        println(if (minOf(r, b) * (d + 1).toLong() >= maxOf(r, b)) "YES" else "NO")
    }
}
```
[1519B - The Cake Is a Lie](../problems/B._The_Cake_Is_a_Lie.md "Educational Codeforces Round 108 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1519B - The Cake Is a Lie](../problems/B._The_Cake_Is_a_Lie.md "Educational Codeforces Round 108 (Rated for Div. 2)")

Note that whichever path you choose, the total cost will be the same. If you know that the cost is the same, then it's not hard to calculate it. It's equal to $n \cdot m - 1$. So the task is to check: is $k$ equal to $n \cdot m - 1$ or not.

The constant cost may be proved by induction on $n + m$: for $n = m = 1$ cost is $1 \cdot 1 - 1 = 0$. For a fixed $(n, m)$, there are only two last steps you can make: 

* either from $(n, m - 1)$ with cost $n$: the total cost is $n \cdot (m - 1) - 1 + n$ $=$ $n \cdot m - 1$
* or from $(n - 1, m)$ with cost $m$: the total cost is $(n - 1) \cdot m - 1 + m$ $=$ $n \cdot m - 1$.

So, whichever path you choose, the total cost is the same.

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m, k) = readLine()!!.split(' ').map { it.toInt() }
        println(if (n * m - 1 == k) "YES" else "NO")
    }
}
```
[1519C - Berland Regional](../problems/C._Berland_Regional.md "Educational Codeforces Round 108 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1519C - Berland Regional](../problems/C._Berland_Regional.md "Educational Codeforces Round 108 (Rated for Div. 2)")

There are two important observations to make.

The first one is that you can calculate the answers for each university independently of each other and sum them up to obtain the true answer.

The second one is that if there are $x$ students in an university, then that university can only contribute to answers for $k$ from $1$ to $x$.

So if we learn to calculate the contribution of the $i$-th university for some fixed $k$ in $O(1)$, then we will be able to iterate over all possible $k$ for each university and get the solution in $O(\sum \limits_{i=1}^{n} x_i) = O(n)$, where $x_i$ is the number of students in the $i$-th university.

To achieve it, you have to gather the sum of the maximum number of students that can form full teams of size $k$. That must be the highest number less than or equal to $x_i$ that is divisible by $k$, so $\lfloor \frac{x_i}{k} \rfloor \cdot k$. Sort the students of each university, precalculate partial sums, and now you are free to add the prefix sum of that number of students to the answer for $k$.

Overall complexity: $O(n \log n)$ per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;


int main() {
    int t;
    scanf("%d", &t);
    forn(_, t){
        int n;
        scanf("%d", &n);
        vector<int> s(n), u(n);
        forn(i, n){
            scanf("%d", &s[i]);
            --s[i];
        }
        forn(i, n){
            scanf("%d", &u[i]);
        }
        vector<vector<int>> bst(n);
        forn(i, n) bst[s[i]].push_back(u[i]);
        forn(i, n) sort(bst[i].begin(), bst[i].end(), greater<int>());
        vector<vector<long long>> pr(n, vector<long long>(1, 0));
        forn(i, n) for (int x : bst[i]) pr[i].push_back(pr[i].back() + x);
        vector<long long> ans(n);
        forn(i, n) for (int k = 1; k <= int(bst[i].size()); ++k)
            ans[k - 1] += pr[i][bst[i].size() / k * k];
        forn(i, n)
            printf("%lld ", ans[i]);
        puts("");
    }
    return 0;
}
```
[1519D - Maximum Sum of Products](../problems/D._Maximum_Sum_of_Products.md "Educational Codeforces Round 108 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1519D - Maximum Sum of Products](../problems/D._Maximum_Sum_of_Products.md "Educational Codeforces Round 108 (Rated for Div. 2)")

The naive approach is to iterate over $l$ and $r$, reverse the subsegment of the array $[l, r]$ and calculate the answer. But this solution is too slow and works in $O(n^3)$.

Instead, we can iterate over the center of the reversed segment and its length. If the current segment is $[l, r]$, and we want to go to $[l - 1, r + 1]$, then the answer for the subsegment will increase by $a_{l-1}* b_{r + 1} + a_{r + 1} * b_{l-1}$. It remains to add the answer for $[1, l)$ and $(r, n]$, but without reversion, this is easy to do if you pre-calculate the prefix sums of the values $a_i * b_i$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main() {
  int n;
  cin >> n;
  vector<li> a(n), b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  vector<li> pr(n + 1, 0);
  for (int i = 0; i < n; ++i)
    pr[i + 1] = pr[i] + a[i] * b[i];
  li ans = pr[n];
  for (int c = 0; c < n; ++c) {
    li cur = a[c] * b[c];
    for (int l = c - 1, r = c + 1; l >= 0 && r < n; --l, ++r) {
      cur += a[l] * b[r];
      cur += a[r] * b[l];
      ans = max(ans, cur + pr[l] + (pr[n] - pr[r + 1]));
    }
    cur = 0;
    for (int l = c, r = c + 1; l >= 0 && r < n; --l, ++r) {
      cur += a[l] * b[r];
      cur += a[r] * b[l];
      ans = max(ans, cur + pr[l] + (pr[n] - pr[r + 1]));
    }
  }
  cout << ans << endl;
}
```
[1519E - Off by One](../problems/E._Off_by_One.md "Educational Codeforces Round 108 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1519E - Off by One](../problems/E._Off_by_One.md "Educational Codeforces Round 108 (Rated for Div. 2)")

At first the problem sounds like some sort of matching. However, it seems like you first want to match each point with either of its moves and then some pairs of points to each other. That doesn't sound viable but since the matchings are often connected with graphs, the graph idea might come handy.

Let's first consider a pair of matched points. What does it actually mean that there exists a line through their new coordinates and $(0, 0)$? It's the same as: the angles of a line through the new coordinates of $a$ and $(0, 0)$ and a line through the new coordinates of $b$ and $(0, 0)$ are the same. Angles are the same means that their tangents are the same (and vice versa since we only consider the first quadrant of the plane). So we can conclude that $\frac{y}{x+1}$ or $\frac{y+1}{x}$ of the first point should be equal to any of these of the second point.

Now consider the following graph. Various values of tangents of the lines are the nodes. Each point produces an edge between their $\frac{y}{x+1}$ and $\frac{y+1}{x}$. What are the matched pairs of points in this graph? It's such a pair of edges that they share at least one endpoint.

Building a graph is the slowest part of the solution since you have to use some data structure (or at least a sort and a binary search). $O(n)$ is possible with some sort of hashmap but $O(n \log n)$ should be perfectly fine as well.

So we reduced the problem to a more well-known one: given an arbitrary undirected graph, find the maximum number of pairs of edges such that each pair shares at least one endpoint and each edge is included in no more than one pair.

The upper bound on the answer is the following. Let $m_i$ be the number of edges in the $i$-th connected component. Best case we can make $\lfloor \frac{m_i}{2} \rfloor$ pairs from it. Let's come up with an algorithm to achieve this bound.

Consider a dfs tree of a component. It's known that a dfs tree of an undirected graph contains no cross edges. So if we direct all the edges of a dfs tree downwards (convert all back edges to forward edges), each edge will connect some vertex to its descendant. 

Imagine we came up with a dfs such that $dfs(v)$ matches all the edges that have their upper node in the subtree of $v$ to each other (except one edge in case there is an odd number of them). $dfs(root)$ will solve the task exactly then.

How should that dfs work exactly?

What if there were no forward edges at all? That case is easy since all edges are tree edges. We'll try to maintain an invariant that the only unmatched edge is an edge that has $v$ as one of its endpoints. If $v$ is a leaf, then there's nothing to match. Otherwise, we go into some child $u$. If it can't match all its edges, then match its remaining edge to an edge $(v, u)$. If it can then remember that we have an edge $(v, u)$ unmatched so far. Go into another child $w$. Same, match our edge with its edge if it has one unmatched. However, if $(v, w)$ turned out to get unmatched and $(v, u)$ turned out to be unmatched, then you can match them to each other. This way you will be left with at most one unmatched edge after you process all the children, and that edge has its endpoint at $v$.

Add the forward edges back. Did anything change? Look at the forward edge that has its upper vertex the lowest. We can see that it points to a vertex $u$ that has its subtree fully matches. So why don't we treat this forward edge the same as an edge to a leaf? Forget that $u$ has some subtree of its own and just believe that you can't match the edge $(v, u)$ so far. Proceed the same as the easy case.

Since we mark exactly which edges you pair up with which, it's trivial to retrieve the answer.

Overall complexity: $O(n)/O(n \log n)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define x first
#define y second

using namespace std;

struct point{
    int a, b, c, d;
};

typedef pair<long long, long long> frac;
typedef pair<int, int> pt;

int n;
vector<point> a;
map<frac, int> sv;

frac norm(long long x, long long y){
    long long g = __gcd(x, y);
    return {x / g, y / g};
}

vector<vector<pt>> g;
vector<int> used;
vector<pt> ans;

int dfs(int v){
    used[v] = 1;
    int cur = -1;
    for (auto it : g[v]){
        int u = it.x;
        int i = it.y;
        if (used[u] == 1) continue;
        int nw = i;
        if (!used[u]){
            int tmp = dfs(u);
            if (tmp != -1){
                ans.push_back({nw, tmp});
                nw = -1;
            }
        }
        if (nw != -1){
            if (cur != -1){
                ans.push_back({cur, nw});
                cur = -1;
            }
            else{
                cur = nw;
            }
        }
    }
    used[v] = 2;
    return cur;
}

int main() {
    scanf("%d", &n);
    a.resize(n);
    forn(i, n) scanf("%d%d%d%d", &a[i].a, &a[i].b, &a[i].c, &a[i].d);
    g.resize(2 * n);
    forn(i, n){
        frac f1 = norm((a[i].a + a[i].b) * 1ll * a[i].d, a[i].b * 1ll * a[i].c);
        frac f2 = norm(a[i].a * 1ll * a[i].d, a[i].b * 1ll * (a[i].c + a[i].d));
        if (!sv.count(f1)){
            int k = sv.size();
            sv[f1] = k;
        }
        if (!sv.count(f2)){
            int k = sv.size();
            sv[f2] = k;
        }
        g[sv[f1]].push_back({sv[f2], i});
        g[sv[f2]].push_back({sv[f1], i});
    }
    used.resize(sv.size());
    forn(i, sv.size()) if (!used[i])
        dfs(i);
    printf("%dn", int(ans.size()));
    for (auto it : ans) printf("%d %dn", it.x + 1, it.y + 1);
}
```
[1519F - Chests and Keys](../problems/F._Chests_and_Keys.md "Educational Codeforces Round 108 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1519F - Chests and Keys](../problems/F._Chests_and_Keys.md "Educational Codeforces Round 108 (Rated for Div. 2)")

Firstly, let's try to find some naive solution for this problem. Let's iterate on the subset of locks Alice puts on the chests. After choosing the subset of locks, how to check whether Bob can gain positive profit? We can iterate on the subset of keys he can buy as well, but in fact, this problem has a polynomial solution. 

Construct a flow network as follows: each chest and each key represents a vertex; there are $n$ arcs from the source to the vertices representing the chests (each having capacity $a_i$), $m$ arcs from the vertices representing the keys to the sink (each having capacity $b_j$), and for each chosen lock, an arc from the respective chest-vertex to the respective key-vertex with infinite capacity. If we find the minimum cut from the source to the sink, then Bob's profit is $(\sum_{i = 1}^{n} a_i) - mincut$. The reasoning behind this solution is the following one: if Bob takes all the chests and all the keys belonging to the first part of the cut, his profit is equal to the total cost of all chests he has taken, minus the total cost of all keys he has taken, minus infinity if he takes a chest he can't open. And the value of the cut is equal to the total cost of chests he doesn't take, plus the total cost of keys he takes, plus infinity if he can't open some chest he takes (since the arc from this chest-vertex to one of the key-vertices belongs to the cut). So, Bob's profit is $(\sum_{i = 1}^{n} a_i) - cut$, and by minimizing the cut value, we maximize his profit. A minimum cut can be easily found using any maxflow algorithm.

Unfortunately, even iterating through all subsets of locks is too slow. To improve this solution, we should look at the minimum cut and its usage a bit more in detail. Notice that Bob can always take no keys and open no chests to get a profit of zero, so Alice's goal is to ensure that it is the best Bob's option. If Bob takes no chests and no keys, it means that the cut divides the network into two parts: the source and all other vertices. And, in terms of flows, it means that the maximum flow in this network should saturate all arcs going from the source (I highlighted it because it is the key idea of the solution).

Here the constraints on $a_i$, $n$ and $m$ come in handy. We can use a dynamic programming with the flow over all arcs going from the source as one of the states. One of the ways to implement it is to have $(f_1, f_2, \dots, f_n, i, j, r)$ as the state, where $f_1$ through $f_n$ are the values of the flow going from the arcs from the source, $i$ is the current vertex in the left part we consider, $j$ is the current vertex in the right part we consider, and $r$ is the flow we already pushed through the arc connecting vertex $j$ of the right part to the sink (and the value we store for this state is the minimum cost Alice has pay to reach this state). There are two basic types of transitions in this dynamic programming: we either skip the arc from $i$ to $j$, or pick it and transfer some flow through it; and no matter what we've chosen, we move to the next vertex of the left part (or to $1$ and increase $j$ by $1$ if we are already considering the $n$-th vertex of the left part). The constraints were loose enough to implement this dp basically in any form (there was no need to compress the states into single integers, for example, which was what the most participants of the round did).

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 6;
const int M = 400;
const int INF = int(1e9);

int a[N];
int b[N];
int c[N][N];
int n, m;

struct state
{
    vector<int> need;
    int v2;
    int v1;
    int rem;
    state() {};
    state(vector<int> need, int v1, int v2, int rem) : need(need), v1(v1), v2(v2), rem(rem) {};
};

int get_code(const vector<int>& v)
{
    int ans = 0;
    for(int i = 0; i < v.size(); i++)
        ans = ans * 5 + v[i];
    return ans;
}

int get_code(const state& s)
{
    int code = get_code(s.need);
    code = code * 6 + s.v2;
    code = code * 6 + s.v1;
    code = code * 5 + s.rem;
    return code; 
}

vector<int> get_vector(int code, int n)
{
    vector<int> res(n);
    for(int i = n - 1; i >= 0; i--)
    {
        res[i] = code % 5;
        code /= 5;
    }
    return res;
}

state get_state(int code)
{
    int rem = code % 5;
    code /= 5;
    int v1 = code % 6;
    code /= 6;
    int v2 = code % 6;
    code /= 6;
    vector<int> need = get_vector(code, n);
    return state(need, v1, v2, rem);
}

const int Z = 40 * int(1e6);
int dp[Z];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> c[i][j];
    for(int i = 0; i < Z; i++)
        dp[i] = INF;
    state start(vector<int>(n, 0), 0, 0, 0);
    int ans = INF;
    dp[get_code(start)] = 0;
    for(int i = 0; i < Z; i++)
    {
        if(dp[i] == INF) continue;
        state s = get_state(i);
        for(int f = 0; f <= 4; f++)
        {
            if(s.need[s.v1] + f > a[s.v1] || s.rem + f > b[s.v2])
                continue;
            int add = (f == 0 ? 0 : c[s.v1][s.v2]);
            state nw = s;
            nw.need[s.v1] += f;
            nw.rem += f;
            if(s.v1 == n - 1)
            {
                nw.v1 = 0;
                nw.v2 = s.v2 + 1;
                nw.rem = 0;
            }
            else
            {
                nw.v1 = s.v1 + 1;
            }
            if(nw.need == vector<int>(a, a + n))
                ans = min(ans, dp[i] + add);
            if(nw.v2 < m)
            {
                int code = get_code(nw);
                dp[code] = min(dp[code], dp[i] + add);
            }
        }
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;

}
```
