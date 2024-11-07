# Tutorial

[1494A - ABC String](../problems/A._ABC_String.md "Educational Codeforces Round 105 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1494A - ABC String](../problems/A._ABC_String.md "Educational Codeforces Round 105 (Rated for Div. 2)")

There are two key observations.

First, a regular bracket sequence always starts with an opening bracket and ends with a closing one. Thus, the first letter of $a$ corresponds to an opening bracket and the last letter corresponds to a closing bracket. If they are the same, then the answer is "NO".

Second, a regular bracket sequence has exactly $\frac n 2$ opening and $\frac n 2$ closing brackets. Thus, we can check if the counts of the remaining letter and the first letter of the string or the remaining letter and the last letter of the string make it $\frac n 2$ in total. If neither of them do, then the answer is "NO". If both do, then that means that there are $0$ occurrences of the remaining letter, so it doesn't matter what bracket it is assigned to.

Finally, after the assignment is complete, check if the resulting string is a regular bracket sequence. For that you have to check if on any prefix the number of opening brackets is greater or equal to the number of closing brackets. And also if the total number of opening and closing brackets is the same.

Overall complexity: $O(n)$ per testcase.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

bool solve() {
  string s;
  cin >> s;
  vector<int> d(3);
  int x = s[0] - 'A';
  int y = s.back() - 'A';
  if (x == y)
    return false;
  d[x] = 1; d[y] = -1;
  if (count(s.begin(), s.end(), 'A' + x) == s.length() / 2)
    d[3 ^ x ^ y] = -1;
  else
    d[3 ^ x ^ y] = 1;
  int bal = 0;
  for (char c : s) {
    bal += d[c - 'A'];
    if (bal < 0) return false;
  }
  return bal == 0;
}

int main() {
  int t; cin >> t;
  while (t--) {
    cout << (solve() ? "YESn" : "NOn");
  }
}
```
[1494B - Berland Crossword](../problems/B._Berland_Crossword.md "Educational Codeforces Round 105 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1494B - Berland Crossword](../problems/B._Berland_Crossword.md "Educational Codeforces Round 105 (Rated for Div. 2)")

Consider some corner of the picture. If it's colored black, then it contributes to counts to both of the adjacent sides. Otherwise, it contributes to none. All the remaining cells can contribute only to the side they are on. There are $n-2$ of such cells on each side.

So let's try all $2^4$ options of coloring the corners. After fixing the colors of the corners, we can calculate the number of cells that have to be colored on each side. That is calculated by taking the initial requirement and subtracting the adjacent colored corners from it. If any of the numbers is below $0$ or above $n-2$ then that corner coloring doesn't work. Otherwise, you can always color the cells in some way.

Overall complexity: $O(1)$ per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
    n, U, R, D, L = map(int, input().split())
    for mask in range(16):
        rU, rR, rD, rL = U, R, D, L
        if mask & 1:
            rU -= 1
            rL -= 1
        if mask & 2:
            rL -= 1
            rD -= 1
        if mask & 4:
            rD -= 1
            rR -= 1
        if mask & 8:
            rR -= 1
            rU -= 1
        if min(rU, rR, rD, rL) >= 0 and max(rU, rR, rD, rL) <= n - 2:
            print("YES")
            break
    else:
        print("NO")
```
[1494C - 1D Sokoban](../problems/C._1D_Sokoban.md "Educational Codeforces Round 105 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1494C - 1D Sokoban](../problems/C._1D_Sokoban.md "Educational Codeforces Round 105 (Rated for Div. 2)")

Since you can only push boxes, you can't bring boxes from negative positions to positive ones and vice versa. Thus, negative boxes/special positions and positive boxes/special positions are two separate tasks. You can solve them independently with the same algorithm and add up the answers.

So, we will only consider the positive boxes/special positions case. Notice that it never makes sense to move left. Thus, the only thing that determines the answer is the maximum position to the right you reach.

For a naive algorithm, we could iterate over that position, push all boxes that we have encountered on our way ahead of us and calculate the number of boxes that are on special positions. That works in $O((n + m) \cdot MAXC)$, where $MAXC$ is maximum coordinate.

To improve that solution we can notice that the positions that are the most optimal are actually the ones such that the first box is pushed to some special position.

Consider the case the first box isn't on a special position, and there is a special position somewhere to the right of it. There are two types of boxes: the ones that are in the pile you would push if you move right and the remaining suffix.

What happens if you move one step to the right? The number of boxes from the suffix on special positions doesn't change. The number of boxes from the pile on special positions doesn't decrease. This number changes depending on if there is a special position immediately to the right of the pile and underneath the first box. Since we considered the case where there is no special position underneath the first box, the number can't decrease.

So we managed to improve the solution to $O((n + m) \cdot m)$. Still slow. Let's now learn to maintain the answer while moving the boxes. Precalculate $su_i$ — the number of boxes from the $i$-th to the last one that are already on special positions. That can be done with two pointers. Now iterate over the special position under the first box in the increasing order. Maintain the size of the pile and the number of special positions under the pile. The first value is just the index of the first box not in a pile. The second value is easier to obtain if you keep the index of the first special position after the pile (or $m$ if there are none). Also achievable with two pointers. The answer is the number of special positions under the pile plus the suffix answer for the boxes after the pile. Take the maximum of all options.

The constraints are pretty free, so you could replace two pointers with binary searches if you wanted to.

Overall complexity: $O(n + m)$ per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int calc(const vector<int> &a, const vector<int> &b){
    int n = a.size();
    int m = b.size();
    vector<int> su(n + 1);
    int r = m - 1;
    for (int i = n - 1; i >= 0; --i){
        su[i] = su[i + 1];
        while (r >= 0 && b[r] > a[i]) --r;
        if (r >= 0 && b[r] == a[i]) ++su[i];
    }
    int ans = 0;
    int j = 0;
    r = 0;
    forn(l, m){
        while (j < n && a[j] <= b[l] + j) ++j;
        while (r < m && b[r] - b[l] < j) ++r;
        ans = max(ans, r - l + su[j]);
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    forn(_, t){
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> a(n), b(m);
        forn(i, n) scanf("%d", &a[i]);
        forn(i, m) scanf("%d", &b[i]);
        vector<int> al, bl, ar, br;
        forn(i, n){
            if (a[i] < 0) al.push_back(-a[i]);
            else ar.push_back(a[i]);
        }
        forn(i, m){
            if (b[i] < 0) bl.push_back(-b[i]);
            else br.push_back(b[i]);
        }
        reverse(al.begin(), al.end());
        reverse(bl.begin(), bl.end());
        printf("%dn", calc(al, bl) + calc(ar, br));
    }
    return 0;
}
```
[1494D - Dogeforces](../problems/D._Dogeforces.md "Educational Codeforces Round 105 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1494D - Dogeforces](../problems/D._Dogeforces.md "Educational Codeforces Round 105 (Rated for Div. 2)")

We can solve the problem recursively from the root to the leaves. Let's maintain a list of leaf indices for the current subtree. If the list size is equal to $1$, then we can stop our recursion. Otherwise, we have to find the value of the root of the current subtree and split all leaves between child nodes. The root value is the maximum value of $a_{v,u}$ among all pairs $v, u$ belonging to a subtree (since the current root has at least $2$ child nodes, there is a pair of leaves for which the current root is the least common ancestor). If the value of the least common ancestor of the leaves $v$ and $u$ ($a_{v, u}$) is less than the value of the current root then $v$ and $u$ belong to the same child of the root. Using this fact, we can split all the leaves between the child nodes and then restore the subtrees for them recursively.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size())

const int N = 505;

int n;
int a[N][N];
int c[2 * N];
vector<pair<int, int>> e;

int calc(vector<int> ls) {
  if (sz(ls) == 1)
    return ls[0];
  
  int res = -1;
  for (int u : ls)
    res = max(res, a[ls[0]][u]);
  
  vector<vector<int>> ch;
  ch.push_back({ls[0]});
  for (int i = 1; i < sz(ls); ++i) {
    int v = ls[i];
    int group = -1;
    for (int j = 0; j < sz(ch); ++j) {
      if (a[v][ch[j][0]] != res) {
        group = j;
        break;
      }
    }
    if (group == -1) {
      group = sz(ch);
      ch.push_back({});
    }
    ch[group].push_back(v);
  }
  
  int v = n++;
  c[v] = res;
  for (int i = 0; i < sz(ch); ++i) {
    int u = calc(ch[i]);
    e.emplace_back(u, v);
  }
  return v;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> a[i][j];
  for (int i = 0; i < n; ++i)
    c[i] = a[i][i];
  vector<int> ls(n);
  iota(ls.begin(), ls.end(), 0);
  int root = calc(ls);
  cout << n << 'n';
  for (int i = 0; i < n; ++i)
    cout << c[i] << ' ';
  cout << 'n' << root + 1 << 'n';
  for (auto it : e)
    cout << it.first + 1 << ' ' << it.second + 1 << 'n';
}
```
[1494E - A-Z Graph](../problems/E._A-Z_Graph.md "Educational Codeforces Round 105 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1494E - A-Z Graph](../problems/E._A-Z_Graph.md "Educational Codeforces Round 105 (Rated for Div. 2)")

At first, if there should be both routes $v_1, v_2, \dots, v_k$ and $v_k, v_{k - 1}, \dots, v_1$ then there are both arcs $(v_1, v_2)$ and $(v_2, v_1)$, i. e. there should exist at least one pair $\{u, v\}$ that both arcs $(u, v)$ and $(v, u)$ are present in the graph.

Now, if $k$ is odd, and we have at least one pair $\{u, v\}$ then we can simply create sequence $u, v, u, v, \dots, v, u$. This sequence is a palindrome so, obviously, both routes generate the same string.

If $k$ is even (or $k = 2x$), we can note that in the sequence $v_1, v_2, \dots, v_{2x}$ there is a middle arc $(v_x, v_{x + 1})$ and it should have the same character as arc $(v_{x + 1}, v_x)$ (since it's a middle arc in reverse route $v_k, \dots, v_1$), i. e. there should exist at least one pair $\{u, v\}$ that both arcs $(u, v)$ and $(v, u)$ are present in the graph and have the same label.

Now, if we have at least one such pair $\{u, v\}$ then routes $u, v, \dots, u, v$ and $v, u, \dots, v, u$ generate the same one-letter strings.

Since each arc $(u, v)$ is a part of at most one pair $\{u, v\}$, we can just maintain two sets with pairs $\{u, v\}$: one for pairs with different labels and the other one for pairs with equal labels. If $k$ is odd, we check that at least one of the sets is not empty. If $k$ is even, we check that the second set is not empty.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef pair<int, int> pt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    map<pt, int> allEdges;
    set<pt> difPairs, eqPairs;
    
    fore (q, 0, m) {
        char tp; cin >> tp;
        if (tp == '+') {
            int u, v;
            char c;
            cin >> u >> v >> c;
            
            if (allEdges.count({v, u})) {
                if (allEdges[{v, u}] == c)
                    eqPairs.emplace(min(u, v), max(u, v));
                else
                    difPairs.emplace(min(u, v), max(u, v));
            }
            allEdges[{u, v}] = c;
            
        } else if (tp == '-') {
            int u, v;
            cin >> u >> v;
            if (eqPairs.count({min(u, v), max(u, v)}))
                eqPairs.erase({min(u, v), max(u, v)});
            if (difPairs.count({min(u, v), max(u, v)}))
                difPairs.erase({min(u, v), max(u, v)});
            
            allEdges.erase({u, v});
        } else {
            int k;
            cin >> k;
            
            bool hasAns = !eqPairs.empty();
            if (k & 1)
                hasAns |= !difPairs.empty();
            cout << (hasAns ? "YES" : "NO") << 'n';
        }
    }
    
    return 0;
}
```
[1494F - Delete The Edges](../problems/F._Delete_The_Edges.md "Educational Codeforces Round 105 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1494F - Delete The Edges](../problems/F._Delete_The_Edges.md "Educational Codeforces Round 105 (Rated for Div. 2)")

Let's suppose our graph is split into two graphs $G_1$ and $G_2$, the first graph contains the edges we delete before the mode shift, the second graph contains the edges we delete after the mode shift.

It's quite obvious that the graph $G_1$ has an eulerian path. The structure of $G_2$ is a bit harder to analyze, but we can prove that it is always a star graph (a vertex and some other vertices connected directly to it), and the center of the star coincides with the last vertex in the eulerian path in $G_1$. To prove that $G_2$ is a star graph, we can consider the second part of the path (after the mode shift) backward: the last edge we traversed was deleted, and the previous-to-last move could have been only along that edge. The third-last and the fourth-last moves should have been along another edge connecting some vertex to the center of the star, and so on.

Okay, how do we find a way to split the graph into $G_1$ and $G_2$? Iterate on the center of the star (let it be $c$). For the graph $G_1$ to contain an eulerian path, it should have at most $2$ vertices with an odd degree. Let's construct $G_2$ in such a way that we minimize the number of odd vertices in $G_1$ — for each edge incident to $c$, we either move it to $G_1$ or $G_2$ in such a way that the resulting degree of the other vertex is even. All other edges belong to $G_1$.

If there is an eulerian path in $G_1$ that ends in $c$, we are done. Otherwise, we should iterate on some edge adjacent to $c$ and change its status (in order to check if $G_1$ can have an eulerian path after that). We can't "flip" two edges because flipping two edges increases the number of odd vertices in $G_1$ at least by $2$ (if it is already $2$ or greater, the eulerian path won't exist, and if it's $0$, then flipping two edges creates two odd vertices, none of which is $c$, so eulerian path can't end in $c$). After flipping each edge, we try to find an eulerian path in $G_1$ once again and flip the edge back. After checking the vertex $c$ as the center of the star, we return all adjacent edges to $G_1$ and move to the next vertex.

The whole algorithm requires checking for the existence of the eulerian path $O(n + m)$ times, so it should work in $O((n+m)^2)$ or $O((n+m)^2 \log n)$ depending on the implementation.

Fun fact: initially I wanted to give a harder version of a problem with $n, m \le 2 \cdot 10^5$ that would require some sort of dynamic connectivity to check for an eulerian path fast, but when I started coding it, I realized that implementation there was a bit painful, so I've decided to drop the constraints to allow quadratic solutions.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 300043;

int n, m;
set<int> g[N];
set<int> g2[N];

vector<int> res;

void euler(int x)
{
    while(!g2[x].empty())
    {
        int y = *g2[x].begin();
        g2[x].erase(y);
        g2[y].erase(x);
        euler(y);
    }
    res.push_back(x);
}

bool check(int c)
{
    for(int i = 1; i <= n; i++)
        g2[i] = g[i];
    res = vector<int>();
    euler(c);
    int curm = 0;
    for(int i = 1; i <= n; i++)
        curm += g[i].size();
    for(int i = 1; i <= n; i++)
        g2[i] = g[i];
    for(int i = 1; i < res.size(); i++)
    {
        int x = res[i - 1];
        int y = res[i];
        if(g2[x].count(y) != 1)
            return false;
        g2[x].erase(y);
        g2[y].erase(x);
    }
    return curm / 2 + 1 == res.size();    
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].insert(y);
        g[y].insert(x);
    }
    for(int i = 1; i <= n; i++)
    {
        set<int> pr = g[i];
        set<int> diff;
        for(auto x : pr)
            if(g[x].size() % 2 == 1)
            {
                g[i].erase(x);
                g[x].erase(i);
                diff.insert(x);
            }
        if(check(i))
        {
            res.push_back(-1);
            for(auto x : diff)
            {
                res.push_back(x);
                res.push_back(i);
            }
            printf("%dn", res.size());
            for(auto x : res) printf("%d ", x);
            puts("");
            exit(0);
        }
        for(auto x : pr)
        {
            if(g[i].count(x))
            {
                g[i].erase(x);
                g[x].erase(i);
                diff.insert(x);
            }
            else
            {
                g[i].insert(x);
                g[x].insert(i);
                diff.erase(x);
            }
            if(check(i))
            {
                res.push_back(-1);
                for(auto x : diff)
                {
                    res.push_back(x);
                    res.push_back(i);
                }
                printf("%dn", res.size());
                for(auto x : res) printf("%d ", x);
                puts("");
                exit(0);
            }
            if(g[i].count(x))
            {
                g[i].erase(x);
                g[x].erase(i);
                diff.insert(x);
            }
            else
            {
                g[i].insert(x);
                g[x].insert(i);
                diff.erase(x);
            }
        }
        for(auto x : diff)
        {
            g[i].insert(x);
            g[x].insert(i);
        }
    }
    puts("0");
}
```
