# Tutorial_(en)

Many thanks to [infinitepro](https://codeforces.com/profile/infinitepro "Expert infinitepro"), [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest") and [alimq](https://codeforces.com/profile/alimq "Candidate Master alimq") for helping me write the editorials.

 
### [1467A - Wizard of Orz](../problems/A._Wizard_of_Orz.md "Codeforces Round 695 (Div. 2)")

If there is only one panel, then pause it when digit $9$ appears on it. You cannot do any better than that.

Otherwise, it is always optimal to pause the second panel from left, when the digit $8$ appears on it. This would give an answer of the form $98901234567890123456\dots$. You can verify that this is the largest number that can be achieved.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

int solveTestCase() {
    int n;
    cin >> n;

    string s = "989";
    if (n <= 3)
        return cout << s.substr(0, n) << "n", 0;

    cout << s;
    for (int i = 3; i < n; i++)
        cout << (i - 3) % 10;
    cout << "n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solveTestCase();

}
```
  


 
### [1467B - Hills And Valleys](../problems/B._Hills_And_Valleys.md "Codeforces Round 695 (Div. 2)")

Changing the value of $a_i$ affects the hill/valley status of only elements $\{a_{i-1}, a_i, a_{i+1}\}$. We claim that it is optimal to change $a_i$ to either $a_{i-1}$ or $a_{i+1}$ for valid $i\space(1<i<n)$.

Let $x$ be a value of $a_i$ such that the number of hills/valleys among elements $\{a_{i-1},a_i,a_{i+1}\}$ is minimised. Now, if $x < \max(a_{i-1}, a_{i+1})$, we can set $x := \min(a_{i-1}, a_{i+1})$ without changing any non-hill/non-valley element to a hill/valley. Similarly, if $x > \min(a_{i-1},a_{i+1})$ we can set $x := \max(a_{i-1},a_{i+1})$. Hence proved.

The final solution is as follows. Precompute the number of hills and valleys in the original array. Then, for every valid index $i$, calculate the change in the number of hills/valleys of the elements $\{a_{i-1},a_i,a_{i+1}\}$ on setting $a_i := a_{i-1}$ and $a_i := a_{i+1}$ and update the minimum answer accordingly.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5;
int a[N], n;

int isValley(int i) {
    return (i > 0 && i < n - 1 && a[i] < a[i - 1] && a[i] < a[i + 1]);
}

int isHill(int i) {
    return (i > 0 && i < n - 1 && a[i] > a[i - 1] && a[i] > a[i + 1]);
}

int solveTestCase() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int is[n] = {};
    int s = 0;
    for (int i = 1; i < n - 1; i++) {
        if (isHill(i) || isValley(i))
            is[i] = 1, s++;
    }

    int ans = s;
    for (int i = 1; i < n - 1; i++) {
        int temp = a[i];
        a[i] = a[i - 1];
        ans = min(ans, s - is[i - 1] - is[i] - is[i + 1] + isHill(i - 1) + isValley(i - 1) + isHill(i) + isValley(i) + isHill(i + 1) + isValley(i + 1));
        a[i] = a[i + 1];
        ans = min(ans, s - is[i - 1] - is[i] - is[i + 1] + isHill(i - 1) + isValley(i - 1) + isHill(i) + isValley(i) + isHill(i + 1) + isValley(i + 1));
        a[i] = temp;
    }

    cout << ans << "n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solveTestCase();
}
```
  
 

### [1467C - Three Bags](../problems/C._Three_Bags.md "Codeforces Round 695 (Div. 2)")

Model the problem as a rooted tree (graph). There are $n_1+n_2+n_3$ nodes, corresponding to the elements from the three bags. Edges between two nodes represent an operation on the two elements and it can be seen that an edge can exist only between nodes of elements from different sets. A directed edge from $b$ to $a$ means that $b$ is removed and $a$ is replaced to $a-b$. All edges are directed towards the root.

In the given rooted tree, operations are applied bottom up, that is, an operation is applied on a leaf node and its parent, and the leaf node is removed. The process is continued until only the root node is remaining.

It is easy to see that the value of the element at the end of all operations is the sum of elements at even depth minus the sum of elements at odd depth (depth is $0$ indexed).

Claim: The constructed rooted tree is valid, if the elements at odd depth are

1. are from at least two different bags, or

2. contain all elements from one bag.

Proof:

Consider a rooted tree with all elements at odd depth from exactly one bag (say $X$) which doesn't fulfil criteria $2$. No remaining elements from bag $X$ can be connected to the nodes at odd depth, making it impossible to construct a tree. This implies that $1$ must hold.

However, if criteria $2$ holds, no elements from bag $X$ remain to be connected, and thus the tree can be constructed.

Hence proved.

Now, we have to minimise either of the two cases, which is the solution to the problem.

For the first case, we can choose the two smallest numbers such that they both appear in different bags to be at odd depth.

For the second case, we can choose all numbers from the bag where the sum of the numbers is minimum to be at odd depth.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5;
vector<vector<int>> a(3, vector<int>());
vector<int> n(3, 0);

int calc() {
    int ans = 0, m1 = a[1][0], m2 = a[2][0], s1 = 0, s2 = 0;
    for (int i : a[0]) ans += i;
    for (int i = 1; i < n[1]; i++) s1 += a[1][i];
    for (int i = 1; i < n[2]; i++) s2 += a[2][i];

    ans += max({s2 - m1 + s1 - m2, m2 + s2 - m1 - s1, m1 + s1 - m2 - s2});
    return ans;
}

int solveTestCase() {
    cin >> n[0] >> n[1] >> n[2];
    a[0].resize(n[0]);
    a[1].resize(n[1]);
    a[2].resize(n[2]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n[i]; j++)
            cin >> a[i][j];
        sort(a[i].begin(), a[i].end());
    }

    int ans = -1e18;
    ans = max(ans, calc());

    swap(a[0], a[1]), swap(n[0], n[1]);
    ans = max(ans, calc());

    swap(a[0], a[2]), swap(n[0], n[2]);
    ans = max(ans, calc());

    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--)
        solveTestCase();
}

```
  
 

### [1467D - Sum of Paths](../problems/D._Sum_of_Paths.md "Codeforces Round 695 (Div. 2)")

The main idea of the problem is to calculate the contribution of each cell to the answer.

Let $cnt_i$ denote the sum of the number of times cell $i$ appears in all good paths of length $k$. Then the answer is equal to $a_1*cnt_1 + a_2*cnt_2 + \dots + a_n*cnt_n$. We shall use dynamic programming to calculate these values.

Let $dp_{{i,j}}$ denote the number of good paths of length $j$ that end at cell $i$. Then, $dp_{{i,0}} = 1$ for all $i$ such that $1 \le i \le n$. Further, for all $i$ such that $1 \le i \le n$ and for all $j$ such that $1 \le j \le k$, $dp_{{i, j}}$ can be calculated as $dp_{{i,j}} = dp_{{{{i-1}},{{j-1}}}} + dp_{{{{i+1}},{{j-1}}}}$ because we can move to cell $i$ from either cell $i-1$ or cell $i+1$. Handle the cases where $i=1$ and $i=n$ separately to avoid out-of-bounds error.

Observe that $dp_{{i,j}}$ is also equal to the number of good paths of length $j$ that start at cell $i$.

Let $a_{{i,j}}$ denote the number of times cell $i$ appears after exactly $j$ moves in all valid paths of length $k$. Well $a_{{i,j}} = dp_{{i,j}} * dp_{{i,k-j}}$ because we can split a path of length $k$ into two paths of length $j$ and length $k-j$, with the first path ending at cell $i$ and the second path starting at cell $i$.

Since $cnt_i$ denotes the sum of the number of times cell $i$ appears in all good path of length $k$, cell $i$ can appear after exactly $0, 1, 2, \dots, k$ moves. This means that $cnt_i = \sum_{{j=0}}^{{k}} a_{{i,j}}$.

Extending the solution to account for updates is easy once we have calculated these values.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5005, mod = 1e9 + 7;
int dp[N][N], cnt[N], a[N], q, n, k;

void pre() {
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
        
    for (int j = 1; j < N; j++) {
        dp[0][j] = dp[1][j - 1];
        for (int i = 1; i < n - 1; i++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i + 1][j - 1]) % mod;
        dp[n - 1][j] = dp[n - 2][j - 1];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++)
            cnt[i] += dp[i][j] * dp[i][k - j], cnt[i] %= mod;
    }
}

void solveTestCase() {
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], ans += a[i] * cnt[i], ans %= mod;
    
    while (q--) {
        int i, x;
        cin >> i >> x;
        i--;
        
        ans -= (a[i] * cnt[i]) % mod, ans += mod, ans %= mod;
        
        a[i] = x;
        ans += (a[i] * cnt[i]), ans %= mod;
        cout << ans << "n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k >> q;
    pre();
    
    int t = 1;
    //cin >> t;
    while (t--)
        solveTestCase();
}

```
  
 

### [1467E - Distinctive Roots in a Tree](../problems/E._Distinctive_Roots_in_a_Tree.md "Codeforces Round 695 (Div. 2)")

Root the tree arbitrarily. Consider any node $v$. Let us remove $v$ from the tree and examine the trees that will be created in the resultant forest.

Let's say that a particular tree was attached to $v$ through node $u$. Further, let's say that this tree has some node $x$ satisfying $a_v = a_x$. Then clearly, if any distinctive root exists, it must be in this component, because if it were in any other component, then, when you root the tree at that node, you will get a path from the root containing both $v$ and $x$. Let us add a directed edge from $v$ to $u$, signifying that all distinctive roots must be in this particular component.

Once we have repeated this for all nodes, we now have a set of directed edges. All distinctive roots must have each of these edges pointing to it. We can check this for all nodes using the rerooting technique. Link cut tree or difference array works as well.

Note: In order to check the number of nodes $x$ which occur in a subtree, do a pre-order traversal of the tree. Create a map which maps a value $b$ to the dfs-in times of all nodes $i$ that satisfy $a_i = b$. Now, two lower-bounds on this shall tell us the number of occurrences in the subtree in logarithmic time. Also, with this information, you can also calculate the number of times $x$ occurs in the tree attached to $v$'s parent.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5;
vector<int> adj[N];
int a[N], par[N], n;

map<int, vector<int>> v, times;
int euler[N * 2 - 1], tin[N], tout[N], c = 0;

set<pair<int, int>> g;
int dp[N], ans;

void dfs(int v, int p = -1) {
    par[v] = p;
    tin[v] = c;
    euler[c++] = v;

    for (int i : adj[v]) {
        if (i == p)
            continue;
        dfs(i, v);
        euler[c++] = v;
    }

    tout[v] = c - 1;
}

void examine(int v) {
    int sum = 0;

    for (int i : adj[v]) {
        if (i == par[v])
            continue;

        int count = upper_bound(times[a[v]].begin(), times[a[v]].end(), tout[i]) - lower_bound(times[a[v]].begin(), times[a[v]].end(), tin[i]);
        if (count > 0)
            g.insert({v, i});
        sum += count;
    }

    sum = times[a[v]].size() - sum - 1;
    if (sum)
        g.insert({v, par[v]});
}

int setup(int v) {
    for (int i : adj[v]) {
        if (i != par[v])
            dp[v] += setup(i);
    }
    return dp[v] + g.count({v, par[v]});
}

void reroot(int v) {
    if (dp[v] == g.size())
        ans++;

    for (int i : adj[v]) {
        if (i == par[v])
            continue;

        dp[v] -= dp[i];
        dp[v] -= g.count({i, v});
        dp[i] += dp[v];
        dp[i] += g.count({v, i});

        reroot(i);

        dp[i] -= g.count({v, i});
        dp[i] -= dp[v];
        dp[v] += g.count({i, v});
        dp[v] += dp[i];
    }
}

int solveTestCase() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);
    for (int i = 0; i < n; i++)
        v[a[i]].push_back(i);

    for (auto i : v) {
        if (i.second.size() == 1)
            continue;

        for (int j : i.second)
            times[i.first].push_back(tin[j]);
        sort(times[i.first].begin(), times[i.first].end());
        for (int j : i.second)
            examine(j);
    }

    setup(0);
    reroot(0);

    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--)
        solveTestCase();
}
```
  
 UPD: Also, have a look at [this](Tutorial_(en).md?#comment-746573) comment for an explanation of the sample test case of C.

