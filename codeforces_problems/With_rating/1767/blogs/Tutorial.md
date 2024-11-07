# Tutorial

[1767A - Cut the Triangle](../problems/A._Cut_the_Triangle.md "Educational Codeforces Round 140 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1767A - Cut the Triangle](../problems/A._Cut_the_Triangle.md "Educational Codeforces Round 140 (Rated for Div. 2)")

The line we draw must go through a triangle's vertex; otherwise, two sides of the triangle are split, and one of the resulting parts becomes a quadrilateral.

So we need to check if it is possible to make a horizontal or vertical cut through a vertex. A horizontal cut is possible if all $y$-coordinates are different (we can draw it through a vertex with the median $y$-coordinate); a vertical cut is possible if all $x$-coordinates are different (we can draw it through a vertex with the median $x$-coordinate).

So, all we need to check is the following pair of conditions:

* all $x_i$ are different;
* all $y_i$ are different.
 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    input()
    xs = []
    ys = []
    for j in range(3):
        x, y = map(int, input().split())
        xs.append(x)
        ys.append(y)
    print('YES' if len(set(xs)) == 3 or len(set(ys)) == 3 else 'NO')
```
[1767B - Block Towers](../problems/B._Block_Towers.md "Educational Codeforces Round 140 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1767B - Block Towers](../problems/B._Block_Towers.md "Educational Codeforces Round 140 (Rated for Div. 2)")

Notice that it never makes sense to move blocks between the towers such that neither of them is tower $1$ as that can only decrease the heights. Moreover, it never makes sense to move blocks away from the tower $1$. Thus, all operations will be moving blocks from some towers to tower $1$.

At the start, which towers can move at least one block to tower $1$? Well, only such $i$ that $a_i > a_1$. What happens after you move a block? Tower $1$ becomes higher, some tower becomes lower. Thus, the set of towers that can share a block can't become larger.

Let's order the towers by the number of blocks in them. At the start, the towers that can share a block are at the end (on some suffix) in this order. After one move is made, the towers get reordered, and the suffix can only shrink.

Ok, but if that suffix shrinks, what's the first tower that will become too low? The leftmost one that was available before. So, regardless of what the move is, the first tower that might become unavailable is the leftmost available tower. Thus, let's attempt using it until it's not too late.

The algorithm then is the following. Find the lowest tower that can move the block to tower $1$, move a block, repeat. When there are no more towers higher than tower $1$, the process stops.

However, the constraints don't allow us to do exactly that. We'll have to make at most $10^9$ moves per testcase.

Ok, let's move the blocks in bulk every time. Since the lowest available tower will remain the lowest until you can't use it anymore, make all the moves from it at the same time. If the current number of blocks in tower $1$ is $x$ and the current number of blocks in that tower is $y$, $\lceil\frac{y - x}{2}\rceil$ blocks can be moved.

You can also avoid maintaining the available towers by just iterating over the towers in the increasing order of their height.

Overall complexity: $O(n \log n)$ per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    x = a[0]
    a = sorted(a[1:])
    for y in a:
        if y > x:
            x += (y - x + 1) // 2
    print(x)
```
[1767C - Count Binary Strings](../problems/C._Count_Binary_Strings.md "Educational Codeforces Round 140 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1767C - Count Binary Strings](../problems/C._Count_Binary_Strings.md "Educational Codeforces Round 140 (Rated for Div. 2)")

Suppose we build the string from left to right, and when we place the $i$-th character, we ensure that all substrings ending with the $i$-th character are valid. What do we need to know in order to calculate the number of different characters in the string ending with the $i$-th character?

Suppose the character $s_i$ is 0. Let's try going to the left of it. The string from $i$ to $i$ will have the same characters; but if there is at least one character 1 before the $i$-th position, the string $s_1 s_2 s_3 \dots s_i$ will have two different characters. What about the strings in the middle? The string $s_j s_{j+1} \dots s_i$ will contain different characters if and only if there is at least one 1 in $[j, i)$ (since $s_i$ is 0), so we are actually interested in the position of the last character 1 before $i$.

The same logic applies if the character $s_i$ is 1: we are only interested in the position of the last 0 before $i$, and it is enough to check if all substrings ending with the $i$-th character are violated.

What if when we choose the $i$-th character, we violate some substring that doesn't end in the $i$-th position? Well, you could also check that... or you could just ignore it. Actually, it doesn't matter if this happens because it means that the substring that is violated ends in some position $k > i$; and we will check it when placing the $k$-th character.

So, the solution can be formulated with the following dynamic programming: let $dp_{i,j}$ be the number of ways to choose the first $i$ characters of the string so that the last character different from $s_i$ was $s_j$ (or $j = 0$ if there was no such character), and all the constraints on the substrings ending no later than position $i$ are satisfied. The transitions are simple: you either place the same character as the last one (going from $dp_{i,j}$ to $dp_{i+1,j}$), or a different character (going from $dp_{i,j}$ to $dp_{i+1,i}$); and when you place a character, you check all the constraints on the substrings ending with the $i$-th position. Note that the state $dp_{1,0}$ is actually represented by two strings: 0 and 1.

This solution works in $O(n^3)$, although $O(n^4)$ or $O(n^2)$ implementations are also possible.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

const int N = 143;
int n;

int a[N][N];
int dp[N][N];

bool check(int cnt, int last)
{
    for(int i = 0; i < cnt; i++)
    {
        if(a[i][cnt - 1] == 0) continue;
        if(a[i][cnt - 1] == 1 && last > i) return false;
        if(a[i][cnt - 1] == 2 && last <= i) return false;
    }
    return true;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
            cin >> a[i][j];
    }
    if(a[0][0] != 2) dp[1][0] = 2;
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            for(int k : vector<int>({j, i}))
                if(check(i + 1, k))
                    dp[i + 1][k] = add(dp[i + 1][k], dp[i][j]);
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = add(ans, dp[n][i]);
    cout << ans << endl;
}
```
[1767D - Playoff](../problems/D._Playoff.md "Educational Codeforces Round 140 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1767D - Playoff](../problems/D._Playoff.md "Educational Codeforces Round 140 (Rated for Div. 2)")

Firstly, let's prove that the order of characters in $s$ is interchangeable.

Suppose we have a tournament of four teams with skills $a$, $b$, $c$ and $d$ such that $a < b < c < d$; and this tournament has the form $01$ or $10$. It's easy to see that $a$ and $d$ cannot be winners, since $a$ will be eliminated in the round with type $1$, and $d$ will be eliminated in the round with type $0$. However, it's easy to show that both with $s = 10$ and with $s = 01$, $b$ and $c$ can be winners.

Using this argument to matches that go during phases $i$ and $i+1$ (a group of two matches during phase $i$ and a match during phase $i + 1$ between the winners of those matches can be considered a tournament with $n = 2$), we can show that swapping $s_i$ and $s_{i+1}$ does not affect the possible winners of the tournament.

So, suppose all phases of type $1$ happen before phases of type $0$, there are $x$ phases of type $1$ and $y$ phases of type $0$ ($x + y = n$). $2^{x+y} - 2^y$ teams will be eliminated in the first part (phases of type $1$), and the team with the lowest skill that wasn't eliminated in the first half will win the second half.

It's easy to see that the teams with skills $[1..2^x-1]$ cannot pass through the first part of the tournament, since to pass the first part, a team has to be the strongest in its "subtree" of size $2^x$.

Furthermore, since the minimum of $2^y$ teams passing through the first half wins, the winner should have skill not greater than $2^{x+y}-2^y+1$ — the winner should have lower skill than at least $2^y - 1$ teams, so teams with skills higher than $2^{x+y}-2^y+1$ cannot win.

Okay, now all possible winners belong to the segment $[2^x, 2^n - 2^y + 1]$. Let's show that any integer from this segment can be winning. 

Suppose $k \in [2^x, 2^n - 2^y + 1]$, let's construct the tournament in such a way that only team with skill $k$ and $2^y-1$ teams with the highest skill pass through the first part of the tournament (obviously, then team $k$ wins). There are $2^y$ independent tournaments of size $2^x$ in the first part; let's assign teams with skills from $1$ to $2^x-1$, and also the team $k$ to one of those tournaments; for all other $2^y-1$ tournaments, let's assign the teams in such a way that exactly one team from the $2^y-1$ highest ones competes in each of them. It's easy to see that the team $k$ will win its tournament, and every team from the $2^y-1$ highest ones will win its tournament as well, so the second half will contain only teams with skills $k$ and $[2^n-2^y+2..2^n]$ (and, obviously, $k$ will be the winner of this tournament).

So, the answer to the problem is the segment of integers $[2^x, 2^n - 2^y + 1]$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int k = count(s.begin(), s.end(), '1');
  for (int x = 1 << k; x <= (1 << n) - (1 << (n - k)) + 1; ++x)
    cout << x << ' ';
}
```
[1767E - Algebra Flash](../problems/E._Algebra_Flash.md "Educational Codeforces Round 140 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1767E - Algebra Flash](../problems/E._Algebra_Flash.md "Educational Codeforces Round 140 (Rated for Div. 2)")

Imagine we bought some subset of colors. How to check if there exists a path from $1$ to $n$?

Well, we could write an easy dp. However, it's not immediately obvious where to proceed from that. You can't really implement buying colors inside the dp, because you should somehow know if you bought the current color before, and that's not really viable without storing a lot of information.

Let's find another approach. Let's try to deduce when the subset is bad — the path doesn't exist. Trivial cases: $c_1$ or $c_n$ aren't bought. Now, if there are two consecutive platforms such that their colors aren't bought, the path doesn't exist. Otherwise, if there are no such platforms, you can show that the path always exists.

In particular, that implies that among all pairs of consecutive platforms, at least one color of the pair have to be bought. If the colors of the pair are the same, then it's just that this color have to be bought.

The next step is probably hard to get without prior experience. Notice how the condition is similar to a well-known graph problem called "vertex cover". That problem is about finding a set of vertices in an undirected graph such that all graph edges have at least one of their endpoints in the set. In particular, our problem would be to find a vertex cover of minimum cost.

That problem is known to be NP-hard, thus the constraints. We can't solve it in polynomial time but we'll attempt to it faster than the naive approach in $O(2^m \cdot m^2)$.

Let's start with this approach anyway. We can iterate over a mask of taken vertices and check if that mask is ok. In order to do that, we iterate over edges and check if at least vertex is taken for each of them.

Again, having a bit of prior experience, one could tell from the constraints that the intended solution involves meet-in-the-middle technique.

Let's iterate over the mask of taken vertices among vertices from $1$ to $\frac m 2$. Then over the mask of taken vertices from $\frac m 2 + 1$ to $m$. The conditions on edges split them into three groups: the edges that are completely in $\mathit{mask}_1$, the edges that are completely in $\mathit{mask}_2$ and the edges that have one endpoint in $\mathit{mask}_1$ and another endpoint in $\mathit{mask}_2$.

First two types are easy to check, but how to force the third type to be all good? Consider the vertices that are not taken into $\mathit{mask}_1$. All edges that have them as one of the endpoints will turn out bad if we don't take their other endpoints into $\mathit{mask}_2$. That gives us a minimal set of constraints for each $\mathit{mask}_1$: a mask $\mathit{con}$ that includes all vertices from the second half that have edges to at least one of non-taken vertex in $\mathit{mask}_1$.

Then $\mathit{mask}_2$ is good if it has $\mathit{con}$ as its submask. Thus, we would want to update the answer with the $\mathit{mask}_1$ of the minimum cost such that its $\mathit{con}$ is a submask of $\mathit{mask}_2$.

Finally, let $\mathit{dp}[\mathit{mask}]$ store the minimum cost of some $\mathit{mask}_1$ such that its $\mathit{con}$ is a submask of $\mathit{mask}$. Initialize the $\mathit{dp}$ with the exact $\mathit{con}$ for each $\mathit{mask}_1$. Then push the values of $\mathit{dp}$ up by adding any new non-taken bit to each mask.

When iterating over $\mathit{mask}_2$, check if it's good for edges of the second kind and update the answer with $\mathit{dp}[\mathit{mask}_2]$.

Overall complexity: $O(2^{m/2} \cdot m^2)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> c(n);
    forn(i, n){
        scanf("%d", &c[i]);
        --c[i];
    }
    vector<int> x(m);
    forn(i, m) scanf("%d", &x[i]);
    
    vector<long long> g(m);
    forn(i, n - 1){
        g[c[i]] |= 1ll << c[i + 1];
        g[c[i + 1]] |= 1ll << c[i];
    }
    g[c[0]] |= 1ll << c[0];
    g[c[n - 1]] |= 1ll << c[n - 1];
    
    int mid = m / 2;
    vector<int> dp(1 << mid, 1e9);
    forn(mask, 1 << (m - mid)){
        long long chk = 0;
        int tot = 0;
        forn(i, m - mid){
            if ((mask >> i) & 1)
                tot += x[i + mid];
            else
                chk |= g[i + mid];
        }
        if (((chk >> mid) | mask) != mask)
            continue;
        chk &= (1ll << mid) - 1;
        dp[chk] = min(dp[chk], tot);
    }
    forn(i, mid) forn(mask, 1 << mid) if (!((mask >> i) & 1)){
        dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask]);
    }
    int ans = 1e9;
    forn(mask, 1 << mid){
        long long chk = 0;
        int tot = 0;
        forn(i, mid){
            if ((mask >> i) & 1)
                tot += x[i];
            else
                chk |= g[i];
        }
        chk &= (1ll << mid) - 1;
        if ((chk | mask) != mask)
            continue;
        ans = min(ans, dp[mask] + tot);
    }
    printf("%dn", ans);
    return 0;
}
```
[1767F - Two Subtrees](../problems/F._Two_Subtrees.md "Educational Codeforces Round 140 (Rated for Div. 2)")

Idea: [shnirelman](https://codeforces.com/profile/shnirelman "Grandmaster shnirelman")

 **Tutorial**
### [1767F - Two Subtrees](../problems/F._Two_Subtrees.md "Educational Codeforces Round 140 (Rated for Div. 2)")

Original solution (by shnirelman)

First, let's solve the following problem: we need to maintain a multiset of numbers and process queries of $3$-th types: add a number to the multiset, remove one occurrence of a number from the multiset (it is guaranteed that it exists), calculate the mode on this multiset. To do this, we will maintain the array $cnt_i$ — the frequency of $i$ in the multiset. Now the mode is the position of the leftmost maximum in this array. There are many ways to search for this position, we will use the following: we will build a sqrt-decomposition on the array $cnt$: for a block we will maintain a maximum on this block and an array $c_i$ — the number of positions $j$ in this block, such that $cnt_j = i$. Since in each of the initial requests $cnt_i$ changes by no more than $1$, the maximum in the block also changes by no more than 1 and, using the $c$ array, it is easy to update it after each query. Now, to find the mode (the position of the leftmost maximum in the $cnt$ array), you first need to go through all the blocks to find the value of the maximum and the leftmost block in which this maximum occurs, then iterate over the desired position in this block. Thus, queries to add and remove an element run in $O(1)$, and a mode search query runs in $O(\sqrt{A})$, where $A$ is the number of possible distinct values, in a given problem $A = 2 \cdot 10 ^ 5$.

Now let's get back to the problem itself. Let's build a Preorder traversal of our tree. Let $tin_v$ be the position in the $0$-indexing of the vertex $v$ in the Preorder traversal, $tout_v$ be the size of the Preorder traversal after leaving the vertex $v$. Then the half-interval $[tin_v, tout_v)$ of the Preorder traversal represents the set of vertices of the subtree of the vertex $v$. For the $i$-th query, we will consider $tin_{v_i} \le tin_{u_i}$.

Let $sz_v = tout_v - tin_v$ be the size of the subtree of $v$, $B$ be some integer, then $v$ will be called light if $sz_v < B$, and heavy otherwise. A query $i$ is called light (heavy) if $v_i$ is a light (heavy) vertex. We will solve the problem for light and heavy queries independently.

Light queries. Let's use the small-to-large technique and maintain the multiset described at the beginning of the solution. Let at the moment we have this multiset for the vertex $w$. Let's answer all light queries for which $u_i = w$. To do this, take all the vertices from the subtree of $v_i$ and add the numbers written on them, calculate the mode on the current multiset — this will be the answer to the query, and then delete the newly added vertices. In the standard implementation of small-to-large, you need to maintain several structures at the same time, which in this case is impossible due to the fact that each of them takes up $O(A\sqrt{A})$ of memory. This problem can be avoided, for example, as follows: before constructing the Preorder traversal for each vertex $v$, put its heaviest son at the head of the adjacency list. Then it will be possible to iterate over the vertices in the order of the Preorder traversal, preserving the asymptotics. This part of the solution runs in $O(n\log{n} + qB + q\sqrt{A})$.

Heavy queries. Let's divide all heavy vertices into non-intersecting vertical paths, so that two vertices from the same path have subtrees that differ by no more than $B$ vertices, and the number of the paths themselves is $O(\frac{n}{B})$. To do this, let's take the deepest of the unused heavy vertices and build one of the desired paths, going up to the parent, while the first of these conditions is met. Then we mark all the vertices in this path as used, and start over. We will continue to do this while there are still unused heavy vertices. It is easy to see that the resulting paths are vertical and the subtrees of two vertices from the same path differ by no more than $B$ by construction. Let's prove that there are not very many of these paths. To do this, we will understand in which cases the path breaks: 

1. If the current path contains a root, then since the root has no parent, the path will terminate. Obviously, this path is only $1$.
2. If the parent of the last vertex of the path has only one heavy child (this last vertex itself). From the construction, a break means that the number of vertices in this path plus the number of children outside the heaviest son subtree of the parent of the last vertex and each vertex of the path, except for the initial one, is more than $B$ in total, but each of the counted vertices can be counted in only one of such cases, that is, the number of paths that terminate in this way does not exceed $\frac{n}{B}$.
3. If the parent of the last node has more than one heavy child. Let's leave only heavy vertices in the tree (since the parent of a heavy vertex is a heavy vertex too, it will indeed be a tree (or an empty graph)). This tree contains at most $\frac{n}{B}$ leafs. Calculating the total degree of the vertices of this tree, we can see that there are at most $\frac{n}{B}$ additional sons (all sons of a vertex except one). This means that the number of paths terminating in this way is at most $\frac{n}{B}$.

 We got that the paths are $O(\frac{n}{B})$.Let's divide the heavy queries according to the paths where the $v_i$ is situated. We will answer queries with vertices $v$ from the same path together. We will do it similarly to the case with light queries, with minor differences: at the very beginning, we add to the multiset all the vertices of the subtree of the initial vertex of the path and mentally remove these vertices from the subtrees of $v_i$ vertices. Everything else is preserved. Let's calculate how long it takes: add all vertices from one subtree: $O(n)$, small-to-large: $O(n\log{n})$, to answer one query due to condition on vertices from one path we have to add at most $B$ vertices. Since there are only $O(\frac{n}{B})$ paths, the whole solution will take $O(\frac{n^2\log{n}}{B} + qB + q\sqrt{A })$. We take $B = \sqrt{\frac{n^2\log{n}}{q}}$ and, counting $n \approx q$, we get $B = \sqrt{n\log{n}}$ and total running time $O(n\sqrt{n\log{n}} + n\sqrt{A})$.

Implementation details. As already mentioned, a subtree corresponds to a segment of the Preorder traversal, so $2$ subtrees are $2$ segments. We will maintain the data structure described at the beginning on the sum of $2$ segments. By moving the boundaries of these segments, you can move from one query to another, as in Mo's algorithm. It remains only to sort the queries. Heavy queries are sorted first by path number of $v_i$, then by $tin_{u_i}$. Light queries are sorted only by $tin_{u_i}$, but here you can't just move the segment of the $v$ subtree, you need to rebuild it for each query.

Bonus. Solve this problem for two subtrees and a path connecting the roots of these subtrees.

Alternative solution (by BledDest)

This solution partially intersects with the one described by the problem author. We will use the same data structure for maintaining the mode; and we will also use DFS order of the tree (but before constructing it, we will reorder the children of each vertex so that the heaviest child is the first one).

Let $tin_v$ be the moment we enter the vertex $v$ in DFS, and $tout_v$ be the moment we leave the vertex. As usual, the segment $[tin_v, tout_v]$ represents the subtree of vertex $v$, and we can change the state of the structure from the subtree of the vertex $x$ to the subtree of the vertex $y$ in $|tin_x - tin_y| + |tout_x + tout_y|$ operations. Let this number of operations be $cost(x,y)$.

Let $v_1, v_2, \dots, v_n$ be the DFS order of the tree. We can prove that $cost(v_1, v_2) + cost(v_2, v_3) + \dots + cost(v_{n-1}, v_n)$ is estimated as $O(n \log n)$ if we order the children of each vertex in such a way that the first of them is the heaviest one.

Proof. Let's analyze how many times some vertex $v$ is added when we go in DFS order and maintain the current set of vertices. When some vertex is added to the current subtree, this means that the previous vertex in DFS order was not an ancestor of the current vertex, so the current vertex is not the first son of its parent. So, the size of the subtree of the parent is at least 2x the size of the current vertex. Since the path from $v$ to root can have at most $O(\log n)$ such vertices, then the vertex $v$ is added at most $O(\log n)$ times.

Okay, how do we use it to process queries efficiently? Let's say that the vertex $v_i$ (the $i$-th vertex in DFS order) has coordinate equal to $cost(v_1, v_2) + cost(v_2, v_3) + \dots + cost(v_{i-1}, v_i)$. Let this coordinate be $c_{v_i}$. Then, if we have the data structure for the query $(x_1, y_1)$ and we want to change it so it meets the query $(x_2, y_2)$, we can do it in at most $|c_{x_1} - c_{x_2}| + |c_{y_1} - c_{y_2}|$ operations, which can be treated as the Manhattan distance between points $(c_{x_1}, c_{y_1})$ and $(c_{x_2}, c_{y_2})$.

Do you see where this is going? We can map each query $(x, y)$ to the point $(c_x, c_y)$, and then order them in such a way that the total distance we need to travel between them is not too large. We can use Mo's algorithm to do this. Since the coordinates are up to $O(n \log n)$, but there are only $q$ points, some alternative sorting orders for Mo (like the one that uses Hilbert's curve) may work better than the usual one.

 **Solution (shnirelman)**
```cpp
#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
const int A = 2e5 + 13;

const int N = 2e5 + 13;
const int B = 2000;
const int SQRTA = 500;
const int K = N / B + 113;

int val[N];
vector<int> g[N];
int sz[N];
int gr[N];
int leaf[N], group_root[N];
int par[N];
bool heavy[N];

int tin[N], tout[N], T = 0, mid[N];
int et[N];
int valet[N];


void dfs1(int v, int pr, int depth) {
    par[v] = pr;
    sz[v] = 1;

    int mx = -1;
    for(int i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if(u != pr) {
            dfs1(u, v, depth + 1);
            sz[v] += sz[u];
            if(mx == -1 || sz[g[v][mx]] < sz[u])
                mx = i;
        }
    }

    if(mx != -1)
        swap(g[v][mx], g[v][0]);
}

void dfs2(int v) {
    et[T] = v;
    tin[v] = T++;

    for(int u : g[v]) {
        if(u != par[v])
            dfs2(u);
    }

    tout[v] = T;
}

struct Query {
    int ind;
    int v, u;
    int lv, rv, lu, ru;
    int b;

    Query() {};
};

bool cmp(const Query& a, const Query& b) {
    if(a.b != b.b)
        return a.b < b.b;
    else
        return a.lu < b.lu;
}

int cnt[A];
int block_index[A];
int block_mx[A];
int block_cnt_of_cnt[A / SQRTA + 13][A];

inline void insert(int i) {
    block_cnt_of_cnt[block_index[valet[i]]][cnt[valet[i]]]--;
    cnt[valet[i]]++;
    block_cnt_of_cnt[block_index[valet[i]]][cnt[valet[i]]]++;
    if(cnt[valet[i]] > block_mx[block_index[valet[i]]])
        block_mx[block_index[valet[i]]]++;
}

inline void erase(int i) {
    if(cnt[valet[i]] == block_mx[block_index[valet[i]]] && block_cnt_of_cnt[block_index[valet[i]]][cnt[valet[i]]] == 1)
        block_mx[block_index[valet[i]]]--;
    block_cnt_of_cnt[block_index[valet[i]]][cnt[valet[i]]]--;
    cnt[valet[i]]--;
    block_cnt_of_cnt[block_index[valet[i]]][cnt[valet[i]]]++;
}

int get_mode() {
    int mx = 0;
    for(int i = 0; i < A / SQRTA + 1; i++)
        mx = max(mx, block_mx[i]);
    for(int i = 0; ; i++) {
        if(block_mx[i] == mx) {
            for(int j = i * SQRTA; ; j++) {
                if(cnt[j] == mx)
                    return j;
            }
        }
    }
}

Query queries[N];
int ans[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> val[i];

    for(int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs1(0, -1, 0);

    vector<pii> ord(n);
    for(int i = 0; i < n; i++) {
        ord[i] = {sz[i], i};
        gr[i] = -1;
    }

    sort(ord.begin(), ord.end());

    for(int i = 0; i < n; i++) {
        if(sz[i] >= B)
            heavy[i] = true;
    }

    int cur = 0;
    for(int i = 0; i < n; i++) {
        int v = ord[i].s;
        if(sz[v] < B || gr[v] != -1)
            continue;

        leaf[cur] = v;

        int u = v;
        while(gr[u] == -1 && sz[u] - sz[v] < B) {
            gr[u] = cur;
            group_root[cur] = u;
            u = par[u];
        }

        cur++;
    }

    dfs2(0);

    for(int i = 0; i < n; i++) {
        if(sz[i] < B) {
            gr[i] = cur + tin[i] / B;
        }
    }

    for(int i = 0; i < n; i++)
        valet[i] = val[et[i]];

    for(int i = 0; i < A; i++) {
        block_index[i] = i / SQRTA;
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        queries[i].ind = i;
        cin >> queries[i].v >> queries[i].u;

        queries[i].v--;
        queries[i].u--;

        queries[i].lv = tin[queries[i].v];
        queries[i].rv = tout[queries[i].v];
        queries[i].lu = tin[queries[i].u];
        queries[i].ru = tout[queries[i].u];

        if(queries[i].lv > queries[i].lu) {
            swap(queries[i].v, queries[i].u);
            swap(queries[i].lv, queries[i].lu);
            swap(queries[i].rv, queries[i].ru);
        }

        queries[i].b = gr[queries[i].v];
    }

    sort(queries, queries + q, cmp);

    int lv = 0, rv = 0, lu = 0, ru = 0;
    li fir = 0, sec = 0;

    int hs = 0;
    for(int i = 0; i < q; i++) {
        int qlv = queries[i].lv;
        int qrv = queries[i].rv;
        int qlu = queries[i].lu;
        int qru = queries[i].ru;

        fir += abs(lv - qlv) + abs(rv - qrv);
        sec += abs(lu - qlu) + abs(ru - qru);

        if(queries[i].b < cur) {
            while(rv < qrv)
                insert(rv++);
            while(lv > qlv)
                insert(--lv);
            while(rv > qrv)
                erase(--rv);
            while(lv < qlv)
                erase(lv++);
        } else {
            while(rv > lv)
                erase(--rv);
            lv = qlv;
            rv = lv;
            while(rv < qrv)
                insert(rv++);
        }

        while(ru < qru)
                insert(ru++);
            while(lu > qlu)
                insert(--lu);
            while(ru > qru)
                erase(--ru);
            while(lu < qlu)
                erase(lu++);

        ans[queries[i].ind] = get_mode();
    }

    for(int i = 0; i < q; i++)
        cout << ans[i] << endl;
}

mt19937 rnd(1);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen("input.txt", "r", stdin);

    solve();
}
```
