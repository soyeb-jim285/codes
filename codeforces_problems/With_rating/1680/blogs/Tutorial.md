# Tutorial

[1680A - Минимумы и максимумы](../problems/A._Minimums_and_Maximums.md "Educational Codeforces Round 128 (рейтинговый для Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Международный гроссмейстер BledDest")

 **Tutorial**
### [1680A - Minimums and Maximums](../problems/A._Minimums_and_Maximums.md "Educational Codeforces Round 128 (Rated for Div. 2)")

Firstly, since we are interested in minimum possible size of the array, we don't need any elements other than minimums and maximums. So, the array has at most $2$ distinct elements.

Now there are many possible solutions. The simplest one is to iterate on the number of minimums (let this be $i$) and maximums (let this be $j$). If the number of minimums is equal to the number of maximums, then the array should have all elements as both its minimums and maximums, so its length should be $i$; otherwise, it should be $i + j$. We can iterate on all possible pairs $(i, j)$ and find the best result over all of them.

A solution in $O(1)$ is possible if you see that you only have to consider $l_1$ and $l_2$ as the number of minimums/maximums, or check if the segments $[l_1, r_1]$ and $[l_2, r_2]$ intersect in $O(1)$.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    l1, r1, l2, r2 = map(int, input().split())
    if max(l1, l2) <= min(r1, r2):
        print(max(l1, l2))
    else:
        print(l1 + l2)
```
[1680B - Роботы](../problems/B._Robots.md "Educational Codeforces Round 128 (рейтинговый для Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Международный гроссмейстер BledDest")

 **Tutorial**
### [1680B - Robots](../problems/B._Robots.md "Educational Codeforces Round 128 (Rated for Div. 2)")

Let's assume that the rows are numbered from $0$ to $n-1$ from top to bottom, and columns are numbered from $0$ to $m-1$ from left to right. 

If there is no robot in the cell $(0, 0)$ initially, we have to perform several moves up and/or left. If the first row with at least one robot is the $i$-th row, then we can make at most $i$ steps up (and we should do at least $i$ steps up, since otherwise there will me no robot in the upper row). Similarly, if the first column with at least one robot is the $j$-th column, then we can make at most $j$ steps to the left (and we should do at least $j$ steps to the left, since otherwise there will me no robot in the leftmost column).

Now there are two possible solutions, both starting with finding $i$ and $j$: we afterwards either simulate $i$ moves up and $j$ moves to the left and check that everything is fine, or just check that there is a robot in the cell $(i, j)$ (since only this robot can end up in $(0, 0)$).

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    s = []
    for j in range(n):
        s.append(input())
    minx = 10 ** 9
    miny = 10 ** 9
    for x in range(n):
        for y in range(m):
            if s[x][y] == 'R':
                minx = min(minx, x)
                miny = min(miny, y)
    print('YES' if s[minx][miny] == 'R' else 'NO')
```
[1680C - Двоичная строка](../problems/C._Binary_String.md "Educational Codeforces Round 128 (рейтинговый для Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Международный гроссмейстер BledDest")

 **Tutorial**
### [1680C - Binary String](../problems/C._Binary_String.md "Educational Codeforces Round 128 (Rated for Div. 2)")

There are many different approaches to this problem: dynamic programming, binary search, greedy, two pointers, anything you want. The model solution uses an approach based on binary search, so I'll describe it.

First of all, why does binary search work? Let's say that the number of 1's is $c$. If the cost of deletion is $k$, then we have deleted at most $k$ characters 1, and have left at most $k$ characters 0. Let's increase the number of characters we delete from the prefix of the string until the number of deleted 1's becomes $k+1$: if $c \ge k+1$, it's always possible. So, if we consider the segment of values $[0, c]$, the fact that we can get cost $k$ implies that we can get cost $k+1$, so we can use binary search on segment $[0, c]$ to find the minimum achievable cost.

Now, how to check if we can obtain the cost of deletion equal to $k$? One possible way to do this is to form an array $pos$, where $pos_i$ is the position of the $i$-th character 1 in the string, and find the minimum value of $pos_{i+c-k-1} - pos_i$ in this array: the string that should remain has to contain at least $c-k$ characters 1, and the minimum value of $pos_{i+c-k-1} - pos_i$ is the minimum possible length of such string. Then we can find the number of 0's in this string and check if it is greater than $k$ or not.

 **Solution (BledDest)**
```cpp
def can(pos, m):
    k = len(pos) 
    x = k - m
    for i in range(m + 1):
        l = pos[i]
        r = pos[i + x - 1]
        if r - l + 1 - x <= m:
            return True
    return False    

t = int(input())
for i in range(t):
    s = input()
    pos = []
    n = len(s)
    for i in range(n):
        if s[i] == '1':
            pos.append(i)
    lf = 0
    rg = len(pos)
    while rg - lf > 1:
        mid = (lf + rg) // 2
        if can(pos, mid):
            rg = mid
        else:
            lf = mid
    if len(pos) == 0 or pos[-1] - pos[0] == len(pos) - 1:
        print(0)
    else:
        print(rg)
```
[1680D - Прогулка с собакой](../problems/D._Dog_Walking.md "Educational Codeforces Round 128 (рейтинговый для Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Мастер vovuh") and [BledDest](https://codeforces.com/profile/BledDest "Международный гроссмейстер BledDest")

 **Tutorial**
### [1680D - Dog Walking](../problems/D._Dog_Walking.md "Educational Codeforces Round 128 (Rated for Div. 2)")

Consider every cyclic shift of the array $a$. Suppose that now the array $a$ starts from the position $i$ (the first element is $a[i]$ and the last element is $a[(i + n - 1) \% n]$). Assume that before the position $i$ our dog reached her minimum possible position and now the minimum position will not change. So our problem is to fill all zeros in the array $a$ in such a way that the maximum prefix sum of $a$ is the maximum possible and the total sum of $a$ is zero.

For simplicity, consider the array $b$ which is the $i$-th cyclic shift of $a$ (i. e. the first element $b[0]$ is $a[i]$, the second element $b[1]$ is $a[(i + 1) \% n]$, and so on). Let's iterate from left to right and maintain the current sum of the array $b$. Let this variable be $s$. Now, when we meet $b_j = 0$, we should replace it with the maximum possible value we can (because in such a way we will increase the maximum number of prefix sums). Let $x$ be the number of zeros in $b$ starting from the position $j + 1$. This value can be calculated in advance in $O(n)$ for every cyclic shift using suffix sums. Then the segment of positions we can have at the end is $[s - xk; s + xk]$ and we want to place the maximum possible value in $b[j]$ in such a way that this remaining segment (with addition of our current element) will cover $0$. This maximum value equals $b[j] = min(k, xk - s)$. If $b[j]$ becomes less than $-k$ then this cyclic shift is invalid, and we should skip it. Otherwise, let's add $b[j]$ to $s$ and proceed. If there are no values $b[j] < -k$, then we placed anything correctly.

Now can just simulate the movements of our dog to find the answer for the current cyclic shift. But there are cases when $a$ do not contain zeros, so these cases should be handled somehow (I just checked that after simulation we returned to $0$). If we returned to $0$, we can update the answer as the difference between the maximum and the minimum positions plus one. If there is no valid cyclic shift, then the answer is -1.

Time complexity: $O(n^2)$.

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &it : a) {
        cin >> it;
    }
    
    long long ans = 0;
    for (int it = 0; it < n; ++it) {
        vector<int> cnt(n);
        for (int i = n - 1; i >= 0; --i) {
            cnt[i] = (a[i] == 0);
            if (i + 1 < n) {
                cnt[i] += cnt[i + 1];
            }
        }
        vector<long long> b = a;
        long long s = accumulate(b.begin(), b.end(), 0ll);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 0) {
                long long x = (i + 1 < n ? cnt[i + 1] : 0);
                b[i] = min(k, x * k - s);
                if (b[i] < -k) {
                    ok = false;
                }
                s += b[i];
            }
        }
        if (ok) {
            long long pos = 0, mn = 0, mx = 0;
            for (int i = 0; i < n; ++i) {
                pos += b[i];
                mn = min(mn, pos);
                mx = max(mx, pos);
            }
            if (pos == 0) {
                ans = max(ans, mx - mn + 1);
            }
        }
        rotate(a.begin(), a.begin() + 1, a.end());
    }
    
    if (ans == 0) {
        ans = -1;
    }
    
    cout << ans << endl;
    
    return 0;
}
```
[1680E - Двигающиеся фигуры](../problems/E._Moving_Chips.md "Educational Codeforces Round 128 (рейтинговый для Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Мастер vovuh")

 **Tutorial**
### [1680E - Moving Chips](../problems/E._Moving_Chips.md "Educational Codeforces Round 128 (Rated for Div. 2)")

Firstly, I want to say a few words about the difficulty of this problem. Till the last moment, we didn't know easy to prove (and easy to write) solutions, so we decided that this is a good problem E. But now we realized it is a lot easier than we expected.

Now, let's talk about the solution. At the beginning, let's remove redundant columns from the beginning and from the end (i. e. columns without chips) and change the value $n$ correspondingly. Now, let $cost_{i, j}$ be $1$ if $s_{j, i}$ is '*', and $0$ otherwise. This array needed to make the implementation easier.

Let's calculate the dynamic programming $dp_{i, j}$, where $i$ is the index of the last processed column and $j$ is the number of the row where our chip is standing. This seems a bit suspicious why we can calculate such a dynamic programming, so let's explain some things about it.

* It can be shown that in the optimal answer there will be some column where the last move happens. And if the number of this column is $j$ then all chips to the left of $j$ will move only to the right and all chips to the right of $j$ will move only to the left.
* Actually, we can always consider that $j$ is the last column. Consider paths of two chips that will survive till the last move. The first chip is to the left of $j$ and will move only to the right, and the second one is to the right of $j$ and will move only to the left. Then we can replicate the path of the second chip in the reverse order using the first chip. So the second chip can stay still until the last move.
* In the optimal answer, it is always better to have exactly one chip in the current column, because moving two chips to the right is always worse than just eat one of them and move the remaining one.

Initial states of $dp$ are $+\infty$ except the values of the first column. For the first column, $dp_{0, 0} = cost_{0, 1}$ and $dp_{0, 1} = cost_{0, 0}$. The answer will be $min(dp_{n - 1, 0}, dp_{n - 1, 1})$.

Okay, how to make transitions from $dp_{i, j}$? For all $i$ from $0$ to $n-2$, let's consider four cases:

* $dp_{i, 0} \rightarrow dp_{i + 1, 0}$ — here we need one move to go to the next column and, probably, one more move to delete the figure in the second row in the column $i + 1$. So the transition seems like $dp_{i + 1, 0} = min(dp_{i + 1, 0}, dp_{i, 0} + 1 + cost_{i + 1, 1})$;
* $dp_{i, 1} \rightarrow dp_{i + 1, 1}$ — same as the previous transition, $dp_{i + 1, 1} = min(dp_{i + 1, 1}, dp_{i, 1} + 1 + cost_{i + 1, 0})$;
* $dp_{i, 0} \rightarrow dp_{i + 1, 1}$ — because the cost of this transition is always $2$ (the distance between these cells is $2$), we just go firstly to the right and then down (to ensure that we eat the figure in the first row). So the transition is $dp_{i + 1, 1} = min(dp_{i + 1, 1}, dp_{i, 0} + 2)$;
* $dp_{i, 1} \rightarrow dp_{i + 1, 1}$ — same as the previous transition, $dp_{i + 1, 0} = min(dp_{i + 1, 0}, dp_{i, 1} + 2)$.

Time complexity: $O(n)$.

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string s[2];
        cin >> n >> s[0] >> s[1];
        
        for (int it = 0; it < 2; ++it) {
            while (s[0].back() == '.' && s[1].back() == '.') {
                s[0].pop_back();
                s[1].pop_back();
            }
            reverse(s[0].begin(), s[0].end());
            reverse(s[1].begin(), s[1].end());
        }
        n = s[0].size();
        
        vector<vector<int>> cost(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                cost[i][j] = (s[j][i] == '*');
            }
        }
        
        vector<vector<int>> dp(n, vector<int>(2, INF));
        dp[0][0] = cost[0][1];
        dp[0][1] = cost[0][0];
        for (int i = 0; i + 1 < n; ++i) {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + 1 + cost[i + 1][1]);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 2);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + 1 + cost[i + 1][0]);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 2);
        }
        
        cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
        
    return 0;
}
```
[1680F - Свободное вершинное покрытие](../problems/F._Lenient_Vertex_Cover.md "Educational Codeforces Round 128 (рейтинговый для Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Международный гроссмейстер BledDest")

 **Tutorial**
### [1680F - Lenient Vertex Cover](../problems/F._Lenient_Vertex_Cover.md "Educational Codeforces Round 128 (Rated for Div. 2)")

Let's think about why we can't always make a perfect vertex cover — such a vertex cover that each edge has exactly one endpoint in it. Or why the answer can not exist at all.

Consider a bamboo. It's always possible to find a perfect vertex cover. Just choose every other vertex in it and account for parity.

Make a bamboo into a loop. Now you can see that an even length loop has a perfect vertex cover. An odd length doesn't.

That tells us that each odd length loop in a graph will have a bad edge on it. Odd length loops should instantly make you think about bipartite colorings.

So we can see that a bipartite graph always has a perfect vertex cover. Just choose one of the parts into a cover, and each edge will have exactly one endpoint in it. At the same time, a non-bipartite graph never has a perfect cover.

So our general goal is to remove (basically, mark as bad) at most one edge in such a way that the remaining graph is bipartite.

Consider a dfs tree of the graph, colored bipartitely. Every edge in the tree is good (has endpoints in different parts). Every edge outside the tree can be either good or bad. What happens to the tree if we remove an edge?

If we remove an edge outside the dfs tree, then nothing happens to it. So if there is no more than one bad edge outside the tree, then we found the answer. That was the easy part.

Now what happens if we remove an edge from the tree? The back edges from the subtree of the edge can force the subtree to either remain colored the same or flip all its colors. We don't really care if it remains the same, because we already took care of it in the first part. So let's pretend it always flips the colors.

Thus, all edges that go from the subtree upwards above the removed edge, have only one of their endpoints colors changed. Good edges turn bad, bad edges turn good.

All other edges don't change.

So you should choose such an edge to remove that all bad edges in the graph go from its subtree upwards above that edge and no good edges go from its subtree upwards above that edge.

That can be calculated with a dfs. Since all non-tree edges in the dfs tree are back edges, you can simply increment a counter on the bottom vertex, decrement the counter on the top vertex and collect sums from the bottom. The sum in the vertex will tell you the number of edges that start below or in the vertex and end above the vertex.

Do this for both kinds of edge and check the conditions for all vertices. Finally, choose such a part to be a vertex cover that the removed edge has both ends in it (if you choose the other part, that edge won't be covered at all).

The solution is linear, but the problem still requires a massive time and memory limit only because of recursion in the dfs.

Overall complexity: $O(n + m)$ per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

vector<vector<int>> g, h;
vector<int> tin, tout, clr;
vector<vector<int>> sum(2);
int T;

int flip;
int cnt;

bool isp(int v, int u){
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

void init(int v){
    tin[v] = T++;
    for (int u : g[v]){
        if (clr[u] == -1){
            clr[u] = clr[v] ^ 1;
            h[v].push_back(u);
            init(u);
        }
        else if (tin[u] < tin[v]){
            int dif = clr[v] ^ clr[u];
            if (!dif){
                flip = clr[v] ^ 1;
                ++cnt;
            }
            --sum[dif][u];
            ++sum[dif][v]; 
        }
    }
    tout[v] = T;
}

int sv;

void dfs(int v){
    for (int u : h[v]){
        dfs(u);
        if (sum[0][u] == cnt && sum[1][u] == 1){
            sv = u;
            flip = clr[v] ^ 1;
        }
        forn(i, 2) sum[i][v] += sum[i][u];
    }
}

int main() {
    cin.tie(0);
    iostream::sync_with_stdio(false);
    int t;
    cin >> t;
    forn(_, t){
        int n, m;
        cin >> n >> m;
        g.assign(n, vector<int>());
        h.assign(n, vector<int>());
        forn(i, m){
            int v, u;
            cin >> v >> u;
            --v, --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        tin.resize(n);
        tout.resize(n);
        forn(i, 2) sum[i].assign(n, 0);
        clr.assign(n, -1);
        cnt = 0;
        T = 0;
        clr[0] = 0;
        init(0);
        if (cnt <= 1){
            cout << "YESn";
            forn(v, n) cout << (clr[v] ^ flip);
            cout << "n";
            continue;
        }
        sv = -1;
        dfs(0);
        if (sv == -1){
            cout << "NOn";
        }
        else{
            cout << "YESn";
            forn(v, n) cout << (clr[v] ^ isp(sv, v) ^ flip);
            cout << "n";
        }
    }
    return 0;
}
```
