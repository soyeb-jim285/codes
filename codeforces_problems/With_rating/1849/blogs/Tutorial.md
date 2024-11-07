# Tutorial

[1849A - Morning Sandwich](../problems/A._Morning_Sandwich.md "Educational Codeforces Round 152 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1849A - Morning Sandwich](../problems/A._Morning_Sandwich.md "Educational Codeforces Round 152 (Rated for Div. 2)")

Notice that the type of filling doesn't matter. We can treat both cheese and ham together as one filling, with quantity $c + h$.

Then let's start building a sandwich layer by layer. Put a piece of bread. Then put a layer of filling and a piece of bread. Then another layer of filling and a piece of bread. Observe that you can add one layer of filling and one piece of bread until one of them runs out. After you've done that $k$ times, you placed $k + 1$ layers of bread and $k$ layers of filling.

Thus, there are two general cases. If bread runs out first, then $k = b - 1$. Otherwise, $k = c + h$. The one that runs out first is the smaller of these two values. So the answer is $min(b - 1, c + h)$.

Overall complexity: $O(1)$ per testcase.

 **Solution (awoo)**
```cpp
  
fun main() = repeat(readLine()!!.toInt()) {
	val (b, c, h) = readLine()!!.split(' ').map { it.toInt() }
	println(minOf(b - 1, c + h) * 2 + 1)
}

```
[1849B - Monsters](../problems/B._Monsters.md "Educational Codeforces Round 152 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1849B - Monsters](../problems/B._Monsters.md "Educational Codeforces Round 152 (Rated for Div. 2)")

Let's simulate the game process until the number of health points of each monster becomes $k$ or less. Then we can consider that the $i$-th monster has $a_i \bmod k$ health instead of $a_i$ (except for the case when $a_i$ is divisible by $k$, then the remaining health is $k$, not $0$).

Now, the health points of all monsters are from $1$ to $k$, so each time we damage a monster, we kill it. Therefore, monsters with $k$ health points will die first, then the ones with $k-1$ health points, and so on. So, let's sort the monsters by their remaining health points in descending order (don't forget that, if two monsters have the same health, then they should be compared by index). And the order you get after sorting is the answer to the problem.

 **Solution (Neon)**
```cpp
  
#include <bits/stdc++.h>
 
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
      x %= k;
      if (!x) x = k;
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    stable_sort(ord.begin(), ord.end(), [&](int i, int j) {
      return a[i] > a[j];
    });
    for (auto &x : ord) cout << x + 1 << ' ';
    cout << endl;
  }
}

```
[1849C - Binary String Copying](../problems/C._Binary_String_Copying.md "Educational Codeforces Round 152 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1849C - Binary String Copying](../problems/C._Binary_String_Copying.md "Educational Codeforces Round 152 (Rated for Div. 2)")

We can see that each modified copy is determined by only two integers $lb$ and $rb$ — the first position at which the character has changed and the last such position. If we can find such numbers for each of the copies, the number of different pairs will be the answer to the problem.

Let $lf_i$ be the position of the nearest character 0 at the position $i$ or to the left of it, and $rg_i$ be the position of the nearest character 1 at the position $i$ or to the right of it. If the first character of the string $s$ is 1 then $lf_0 = -1$, otherwise $lf_0 = 0$. And if the last character of the string $s$ is 0, then $rg_{n - 1} = n$, otherwise $rg_{n - 1} = n - 1$. The values $lf$ and $rg$ can be calculated using simple dynamic programming, $lf$ is calculated from left to right, and $rg$ — from right to left. Then the numbers $lb$ and $rb$ we need are equal to $rg_l$ and $lf_r$, respectively. If $rg_l > lf_r$, then the changed segment is degenerate (and this means that the string does not change at all). We can define some special segment for this type of strings, for example, $(-1, -1)$. Otherwise, the segment $(rg_l, lf_r)$ of the string will change.

Time complexity: $O(n \log{n})$.

 **Solution (vovuh)**
```cpp
  
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    
    vector<int> lf(n), rg(n);
    lf[0] = -1;
    for (int i = 0; i < n; ++i) {
        if (i > 0) lf[i] = lf[i - 1];
        if (s[i] == '0') lf[i] = i;
    }
    rg[n - 1] = n;
    for (int i = n - 1; i >= 0; --i) {
        if (i + 1 < n) rg[i] = rg[i + 1];
        if (s[i] == '1') rg[i] = i;
    }
    
    set<pair<int, int>> st;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        int ll = rg[l - 1], rr = lf[r - 1];
        if (ll > rr) {
            st.insert({-1, -1});
        } else {
            st.insert({ll, rr});
        }
    }
    
    cout << st.size() << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif   
    int t;
    cin >> t;
    while (t--) solve();
}

```
[1849D - Array Painting](../problems/D._Array_Painting.md "Educational Codeforces Round 152 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1849D - Array Painting](../problems/D._Array_Painting.md "Educational Codeforces Round 152 (Rated for Div. 2)")

Suppose we used a second operation as follows: we decreased a red element $x$, and painted another element $y$ red. Let's then say that $x$ is the parent of $y$.

Furthermore, let's say that the element $x$ controls the element $y$ if one of the two conditions applies:

* $x$ is the parent of $y$;
* $x$ controls the parent of $y$.

Now, suppose we used coins to paint some elements red. For each of those elements, there exists a segment of red elements which it controls. So, the problem can actually be reformulated as follows: we want to split the given array into the minimum number of segments so that each segment can be painted using one coin. Let's call a segment of the array good if it can be painted using only one coin.

To continue with our solution, we need the following property: if a segment is good, then its every subsegment is also good. This is kinda intuitive, but if you are interested in a formal proof, you can read the following paragraph.

Formal proof: there are two main cases we need to consider: either the element that controls the main segment belongs to the subsegment we analyze, or it does not. In the first case, the proof is simple: we can paint all elements of the subsegment red using just one coin in the same way as we painted the whole segment, by starting from the element that controls it. In the second case, it is a bit more difficult, but instead of the element controlling the main segment, we can either start from the leftmost element of the subsegment, or from the rightmost element of the subsegment — depending on whether this subsegment is to the right or to the left of the element controlling the whole segment. This starting element will be painted red by spending a coin, and every other element of the subsegment can be painted red in the same way we painted the whole segment.

Since if a segment is good, its every subsegment is also good, we can use the following greedy approach to solve the problem: start with the segment which contains only the first element of the array, and expand it to the right until it becomes bad. When the segment is no longer good, we need to start a new segment, which we will again expand to the right until it becomes bad, and so on. Then each element of the array will be considered only once. If we design a way to determine if the segment is still good when we add a new element to it in $O(1)$, our solution will work in $O(n)$.

All that's left is to analyze how to check if the segment is good. There are multiple ways to do this. The way used in the model solution employs the following ideas:

* there cannot be any zeroes in the middle of the segment, since if we start painting red from the left of that zero, we cannot reach the elements to the right of that zero, and vice versa;
* if there are no zeroes in the middle, and at least one of the endpoints is not zero, the segment is good because we can just start from that endpoint and expand to the other endpoint;
* if there are no zeroes in the middle, and there is at least one element equal to $2$, we can start by painting that element red and expand to the left and to the right of it until we arrive at the borders of the segment;
* and if there are zeroes at both endpoints, but all other elements are $1$'s, it's easy to see that paining the whole segment using only one coin is impossible: the sum of elements on the segment is $k-2$, where $k$ is the length of the segment, but we need to paint at least $k-1$ elements red without spending coins.

All of these ideas allow us to verify that the segment is good using just a couple if-statements.

Solution complexity: $O(n)$.

 **Solution (BledDest)**
```cpp
  
n = int(input())
a = list(map(int, input().split()))

ans = 0
l = 0
while l < n:
    r = l + 1
    hasTwo = (a[l] == 2)
    hasMiddleZero = False
    while r < n:
        if r - 1 > l and a[r - 1] == 0:
            hasMiddleZero = True
        if a[r] == 2:
            hasTwo = True
        good = (not hasMiddleZero) and (hasTwo or a[l] != 0 or a[r] != 0)
        if not good:
            break
        r += 1
    l = r
    ans += 1
    
print(ans)

```
[1849E - Max to the Right of Min](../problems/E._Max_to_the_Right_of_Min.md "Educational Codeforces Round 152 (Rated for Div. 2)")

Idea: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo")

 **Tutorial**
### [1849E - Max to the Right of Min](../problems/E._Max_to_the_Right_of_Min.md "Educational Codeforces Round 152 (Rated for Div. 2)")

The problem was originally prepared as part of the lecture on a monotonic stack. Thus, I will omit its explanation.

First, recall a common technique of counting all segments satisfying some property. You can count the segments that have the same right border at the same time.

Consider all segments $[l, r]$ with a fixed $r$. How do the minimums and the maximums on them change from each other? If you look at the segments in the order of decreasing $l$, we can write down the sequence of the following events: the minimum becomes smaller or the maximum becomes larger. In fact, we can maintain both of these types with two monotonic stacks.

Now, which $l$ correspond to good segments with regard to the events? Consider two adjacent events $(i_1, t_1)$ and $(i_2, t_2)$, where $i_j$ is the index of the event and $t_j$ is the type ($0$ for min, $1$ for max). It's easy to see that if $t_2 = 0$, then all segments that have $l$ from $i_1 + 1$ to $i_2$ are good. It means that, while going from right to left, the last event we encountered was the minimum getting smaller. Thus, the index of the minimum becomes to the left from the index of the maximum.

As for the implementation, we will maintain these events in a set of pairs: (index of the event, type of the event). This way, it's not that hard to maintain the sum of distances from each event of type $0$ to the left to the previous event.

When you erase an event, only a few distances can be affected: the distance from the next one to the current one, from the current one to the previous one and the newly created distance from the next one to the previous one. Just check for the types. When you add an event, you only add it to the very end of the set, so it's trivial to recalculate.

That will be $O(n \log n)$ just from the set, the monotonic stacks by themselves are linear.

You can optimize this solution to $O(n)$ by using a doubly-linked list, but it really was not necessary for the problem.

There's also a different solution for which you can maintain the intervals of good values $l$ explicitly. First, compress them in such a way that the segments don't touch at borders. Now, you can notice that by going from $r$ to $r+1$ we can only affect the rightmost ones of them: possibly remove some, then change the last one and add a new one. So we can actually simulate this behavior with another stack. The details are left as an exercise to a reader. With the correct implementation, this solution will be $O(n)$.

 **Solution (awoo)**
```cpp
  
#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> stmn, stmx;
    stmn.push_back({-1, -1});
    stmx.push_back({n, -1});
    long long ans = 0;
    int len = 0;
    set<pair<int, int>> cur;
    cur.insert({-1, 0});
    cur.insert({-1, 1});
    for (int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        --x;
        
        while (stmn.back().first > x){
            auto it = cur.lower_bound({stmn.back().second, 0});
            auto me = it;
            auto prv = it; --prv;
            ++it;
            len -= me->first - prv->first;
            if (it != cur.end() && it->second == 0)
                len += it->first - prv->first;
            cur.erase(me);
            stmn.pop_back();
        }
        len += i - cur.rbegin()->first;
        cur.insert({i, 0});
        stmn.push_back({x, i});
        
        while (stmx.back().first < x){
            auto it = cur.lower_bound({stmx.back().second, 1});
            auto me = it;
            auto prv = it; --prv;
            ++it;
            if (it != cur.end() && it->second == 0)
                len += me->first - prv->first;
            cur.erase(me);
            stmx.pop_back();
        }
        cur.insert({i, 1});
        stmx.push_back({x, i});
        
        ans += len;
    }
    printf("%lldn", ans - n);
}

```
[1849F - XOR Partition](../problems/F._XOR_Partition.md "Educational Codeforces Round 152 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1849F - XOR Partition](../problems/F._XOR_Partition.md "Educational Codeforces Round 152 (Rated for Div. 2)")

Disclaimer: the model solution to this problem is a bit more complicated than most of the solutions written by participants, but I will still use it for the editorial so that I can explain some of the classical techniques appearing in it.

Suppose we have built a graph on $n$ vertices, where each pair of vertices is connected by an edge, and the weight of the edge connecting $i$ with $j$ is $a_i \oplus a_j$. If we treat the partition of the set as a coloring of this graph, then the cost of the partition is equal to the minimum weight of an edge connecting two vertices of the same color. So, suppose we want to check that the answer is at least $x$. It means that every edge with weight less than $x$ should connect two vertices of different colors; so, the graph where we erase all edges with weight greater than or equal to $x$ should be bipartite. This allows us to write a binary search solution if we somehow understand how to construct the graph and check that it is bipartite implicitly, but this is not the way the model solution goes.

Instead, suppose we do the following greedy. Initially, let the graph be empty. Then, we add all edges with weight $1$, and check if it is bipartite. Then, we add all edges with weight $2$, and check if it is bipartite. And so on, until the graph is no longer bipartite.

Of course, there are $O(n^2)$ edges, so this is too slow. But in fact, we don't need all the edges for this graph. Some of the edges we added didn't really affect the coloring of the graph: if, in this process, we add an edge which connects two vertices from the same component, one of the following two things happens:

* if it connects two vertices of the same color, then the graph is no longer bipartite;
* otherwise, this edge actually does not change anything in the coloring.

Now, suppose we stop before making the graph non-bipartite. It means if an edge we added was connecting two vertices from the same component, that edge was actually redundant.

Let's take a look again at what we're actually doing. Initially, the graph is empty. Then, we consider all possible edges in ascending order of their weights; if an edge connects two vertices in different components, it should be added to the graph (and it affects the coloring), otherwise, it does not matter (unless it makes us stop the algorithm, since the graph is no longer bipartite). Doesn't it sound familiar? Yup, it is almost like Kruskal's algorithm.

And in fact, the problem can be solved as follows: build any MST of this graph, and use it to form the two-coloring (paint the vertices in such a way that every edge from MST connects two vertices of different colors). The paragraph below contains the formal proof that this coloring is optimal; feel free to skip it if you're not interested in the strict proof.

Formal proof: suppose that, if we color the vertices using the MST, we get an answer equal to $x$. This means that there are two vertices $i$ and $j$ such that their colors are the same, and $a_i \oplus a_j = x$. Let us consider the cycle formed by the edge from $i$ to $j$ and the path from $j$ to $i$ in the MST. Since these two vertices have the same colors, this cycle contains an odd number of edges — so, at least one edge on this cycle will connect vertices of the same color no matter how we paint the graph. And there are no edges on this cycle with weight greater than $x$ — otherwise, that edge would be replaced by the edge $(i,j)$ in the MST. So, at least one edge with weight $\le x$ will be connecting two vertices of the same color, and thus the answer cannot be greater than $x$.

Okay, now we have to actually build the MST in this graph. XOR-MST is a fairly classical problem (it was even used in one of the previous Educational Rounds several years ago). I know two different solutions to it: the one based on Boruvka's algorithm and the D&C + trie merging method. I will describe the former one.

The classical Boruvka's algorithm is one of the algorithms of finding a minimum spanning tree. It begins with a graph containing no edges, and performs several iterations until it becomes connected. On each iteration, the algorithm considers each component of the graph and adds the minimum edge connecting any vertex from this component with any vertex outside this component (these edges are added at the same time for all components of the graph, so be careful about creating a cycle or adding the same edge twice; different methods can be used to prevent this — in the model solution, I memorize the edges I want to add on each iteration, then use a DSU to actually check which ones should be added without causing a cycle to appear).

During each iteration of the algorithm, the number of components decreases to at least half of the original number, so the algorithm works in $O(I \log n)$, where $I$ is the complexity of one iteration. Usually, $I$ is $O(m)$ since we need to consider each edge of the graph twice; but in this problem, we can perform one iteration of Boruvka's algorithm much faster, in $O(n \log A)$, where $A$ is the constraint on the numbers in the input.

It can be done as follows: maintain a trie data structure which stores all values of $a_i$ and allows processing a query "given an integer $x$, find the value $y$ in the data structure such that $x \oplus y$ is the minimum possible" (this can be done with a trie descent). When we consider a component and try to find the minimum edge leading outside of it, we first delete all vertices belonging to this component from the data structure; then, for each vertex from the component, find the best vertex in the data structure; and then, insert all vertices back. That way, a component of size $V$ will be processed in $O(V \log A)$, and the total time for one iteration is $O(n \log A)$.

All of this results in a solution with complexity $O(n \log n \log A)$.

 **Solution (BledDest)**
```cpp
  
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int N = 200000;
const int NODES = 32 * N;
const int INF = int(2e9);

int n;
int a[N];
int nx[NODES][2], cnt[NODES], fn[NODES];
int nodeCount = 1;

void addInt(int x, int pos) {
    int ind = 0;
    for (int i = 29; i >= 0; --i) {
        int bit = (x >> i) & 1;
        if (nx[ind][bit] == 0) {
            nx[ind][bit] = nodeCount++;
        }
        ind = nx[ind][bit];
        ++cnt[ind];
    }
    fn[ind] = pos;
}

void addInt(int x) {
    int ind = 0;
    for (int i = 29; i >= 0; --i) {
        int bit = (x >> i) & 1;
        ind = nx[ind][bit];
        ++cnt[ind];
    }
}

void removeInt(int x) {
    int ind = 0;
    for (int i = 29; i >= 0; --i) {
        int bit = (x >> i) & 1;
        ind = nx[ind][bit];
        --cnt[ind];
    }
}

PII findXor(int x) {
    int ind = 0, res = 0;
    for (int i = 29; i >= 0; --i) {
        int bit = (x >> i) & 1;
        if (cnt[nx[ind][bit]]) {
            ind = nx[ind][bit];
        } else {
            ind = nx[ind][bit ^ 1];
            res |= 1 << i;
        }
    }
    return mp(res, fn[ind]);
}

int par[200000], ra[200000];

void dsuInit() {
    forn(i, n) par[i] = i, ra[i] = 1;
}

int dsuParent(int v) {
    if (v == par[v]) return v;
    return par[v] = dsuParent(par[v]);
}

int dsuMerge(int u, int v) {
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) return 0;
    if (ra[u] < ra[v]) swap(u, v);
    par[v] = u;
    ra[u] += ra[v];
    return 1;
}

vector<int> v[200000];
vector<pair<int, PII> > toMerge;
vector<int> g[200000];
int color[200000];

void coloring(int x, int c){
	if(color[x] != -1) return;
	color[x] = c;
	for(auto y : g[x]) coloring(y, c ^ 1);
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) addInt(a[i], i);
    dsuInit();
    for (int merges = 0; merges < n - 1; ) {
        forn(i, n) v[i].clear();
        forn(i, n) v[dsuParent(i)].pb(i);
        toMerge.clear();
        forn(i, n) if (!v[i].empty()) {
            for (int x : v[i]) {
                removeInt(a[x]);
            }
            pair<pair<int, int>, int> res = mp(mp(INF, INF), INF);
            for (int x : v[i]) {
                res = min(res, mp(findXor(a[x]), x));
            }
            toMerge.pb(mp(res.first.first, mp(res.second, res.first.second)));
            for (int x : v[i]) {
                addInt(a[x]);
            }
        }
        for (auto p : toMerge) {
            if (dsuMerge(p.second.first, p.second.second)) {
                ++merges;
				g[p.second.first].pb(p.second.second);
				g[p.second.second].pb(p.second.first);
            }
        }
    }
	forn(i, n) color[i] = -1;
	coloring(0, 1);
	forn(i, n) printf("%d", color[i]);
	puts("");
    return 0;
}

```
