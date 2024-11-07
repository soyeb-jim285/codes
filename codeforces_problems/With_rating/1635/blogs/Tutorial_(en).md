# Tutorial_(en)

[1635A - Min Or Sum](../problems/A._Min_Or_Sum.md "Codeforces Round 772 (Div. 2)")

 **Tutorial**
### [1635A - Min Or Sum](../problems/A._Min_Or_Sum.md "Codeforces Round 772 (Div. 2)")

The answer is a1|a2|⋯|an. Here is the proof:

Let m=a1|a2|⋯|an. After an operation, the value m won't change.

Since, a1|a2|⋯|an≤a1+a2+⋯+an, the sum of the array has a lower bound of m. And this sum can be constructed easily: for all i∈[1,n−1], set ai+1 to ai|ai+1 and ai to 0.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            ans |= x;
        }
        cout << ans << endl;
    }
}
```
[1635B - Avoid Local Maximums](../problems/B._Avoid_Local_Maximums.md "Codeforces Round 772 (Div. 2)")

 **Tutorial**
### [1635B - Avoid Local Maximums](../problems/B._Avoid_Local_Maximums.md "Codeforces Round 772 (Div. 2)")

Let's check all elements in a from the left. 

Once we find that ai is a local maximum, then we should perform an operation to fix it. There are many ways to do this, but the optimal way is to set ai+1 to max(ai,ai+2), because we can avoid ai and ai+2 from being local maximums at the same time.

Proof: Let's take all indices of local maximums in the initial array and append them to an empty array b with their corresponding order. For example, if a=[1,2,1,3,1,1,3,1,4,1,2,1], we obtain b=[2,4,7,9,11]. Then, we devide b into subarrays, such that bi and bi+1 are in the same subarray if and only if bi+1−bi=2. Using the same example above, we will devide b into [2,4],[7,9,11]. To finish our proof, we need two important observations. 

1. Any operation would cancel at most two local maximums.

2. Any operation won't cancel two local maximums whose indices are in different subarrays of b.

So for a fixed subarray, we need at least ⌈length2⌉ operations to cancel all corresponding local maximums, and the lower bound of the answer is the sum of ⌈length2⌉ for all subarrays.

Since the strategy described above could achieve this lower bound, our proof has completed.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i + 1 < n; ++i) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                if (i + 2 < n) {
                    a[i + 1] = max(a[i], a[i + 2]);
                } else {
                    a[i + 1] = a[i];
                }
                ans++;
            }
        }
        cout << ans << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " n"[i == n - 1];
        }
    }
}
```
[1635C - Differential Sorting](../problems/C._Differential_Sorting.md "Codeforces Round 772 (Div. 2)")

 **Tutorial**
### [1635C - Differential Sorting](../problems/C._Differential_Sorting.md "Codeforces Round 772 (Div. 2)")

First of all, if an−1>an, then the answer is −1 since we can't change the last two elements.

If an≥0, there exists a simple solution: perform the operation (i,n−1,n) for each 1≤i≤n−2.

Otherwise, the answer exists if and only if the initial array is sorted. 

Proof: 

Assume that an<0 and we can sort the array after m>0 operations. 

Consider the last operation we performed (xm,ym,zm). Since all elements should be negative after the last operation, so azm<0 should hold before the last operation. But axm=aym−azm>aym after this, so the array isn't sorted in the end. By contradiction, we have proved that we can't perform any operations as long as an<0.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (a[n - 2] > a[n - 1]) {
            cout << -1 << endl;
        } else {
            if (a[n - 1] < 0) {
                if (is_sorted(a.begin(), a.end())) {
                    cout << 0 << endl;
                } else {
                    cout << -1 << endl;
                }
            } else {
                cout << n - 2 << endl;
                for (int i = 1; i <= n - 2; ++i) {
                    cout << i << ' ' << n - 1 << ' ' << n << endl;
                }
            }
        }
    }
}
```
[1635D - Infinite Set](../problems/D._Infinite_Set.md "Codeforces Round 772 (Div. 2)")

 **Tutorial**
### [1635D - Infinite Set](../problems/D._Infinite_Set.md "Codeforces Round 772 (Div. 2)")

First of all, let's discuss the problem where n=1 and a1=1.

For every integer x, there is exactly one integer k satisfying 2k≤x<2k+1. Let's define f(x)=k.

Then, it's quite easy to find out f(2x+1)=f(x)+1 and f(4x)=f(x)+2.

This observation leads to a simple dynamic programming solution: let dpi be the number of integer x where x∈S and f(x)=i. The base case is dp0=1 and the transition is dpi=dpi−1+dpi−2.

After computing the dp array, the final answer will be p−1∑i=0dpi.

For the general version of the problem, in order not to compute the same number two or more times, we need to delete all "useless" numbers. A number ai is called useless if there exists an index j such that aj can generate ai after a series of operations (setting aj to 2aj+1 or 4aj). After the deletion, we can simply do the same thing above, only changing the transition a little bit: dpi=dpi−1+dpi−2+g(i), where g(i) = number of j satisfying f(aj)=i. 

The final problem is how to find all the useless numbers. For every integer x, there are at most O(logx) possible "parents" that can generate it. Also, such "parent" must be smaller than x.

So, let's sort the array in increasing order. Maintain all useful numbers in a set, and for each ai, we will check whether its "parent" exists or not. Once we confirm that its parent doesn't exist, we will append it to the set of useful numbers. This works in O(nlognlogC).

Total Complexity: O(nlognlogC+p).

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    set <int> useful;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        bool flag = false;
        while (x > 0) {
            if (useful.count(x)) {
                flag = true;
            }
            if (x & 1) {
                x >>= 1;
            } else if (x & 3) {
                break;
            } else {
                x >>= 2;
            }
        }
        if (!flag)
            useful.insert(a[i]);
    }
    vector <int> cnt(30, 0), dp(p);
    for (int x : useful) {
        cnt[__lg(x)]++;
    }
    int ans = 0;
    for (int i = 0; i < p; ++i) {
        if (i < 30) {
            dp[i] = cnt[i];
        }
        if (i >= 1) {
            dp[i] += dp[i - 1];
            if (dp[i] >= mod) {
                dp[i] -= mod;
            }
        }
        if (i >= 2) {
            dp[i] += dp[i - 2];
            if (dp[i] >= mod) {
                dp[i] -= mod;
            }
        }
        ans += dp[i];
        if (ans >= mod) {
            ans -= mod;
        }
    }
    cout << ans << endl;
}
```
[1635E - Cars](../problems/E._Cars_.md "Codeforces Round 772 (Div. 2)") 

 **Tutorial**
### [1635E - Cars](../problems/E._Cars_.md "Codeforces Round 772 (Div. 2)")

First of all, let's discuss in what cases will two cars be irrelevant or destined.

If two cars are in the same direction, they can either share the same coordinate at some moment or not, depending on their speed.

 ![](images/f02c577dabf966340494c39d85a92fc96ffcf57e.png) In the picture above, if we set the speed of the blue car to ∞ and the red car to 1, they won't meet each other. But if we set the speed of the blue car to 1 and the red car to ∞, they will meet each other.

If two cars are irrelevant, they must look something like this:

 ![](images/9bc65898152c99890188e9631bf69099ac3f019e.png) If two cars are destined, they must look something like this:

 ![](images/d9cf5926fccd9bf277b473a4e68a6fe2e927305b.png) In conclusion, if there is a relationship between car i and car j, their direction must be different. So let's build a graph: if there is a relationship between car i and car j, we'll add an undirected edge between vertices (i,j). Note that this implies any valid set of relations must form a bipartite graph.

After that, let's run dfs or bfs to make a bipartite coloring. If the graph isn't bipartite, the answer is obviously "NO". Otherwise we can get information about the cars' direction.

The next part is how to know where the cars are located. If car i and car j have a relationship and the orientation of the car i is left, we can know the following restriction:

1. if two cars are irrelevant, xi<xj must be held.

2. if two cars are destined, xj<xi must be held.

Let's build another graph. for every restriction xi<xj, add a directed edge from i to j. After that, if the graph has one or more cycles, the answer is obviously "NO". Otherwise, we can do topological sort and the ordering is one possible solution of x in decreasing order.

Total Complexity: O(n+m).

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

struct edge {
    int type, u, v;
};

vector <int> adj[N];
int col[N], topo[N];

void dfs(int v) {
    for (int u : adj[v]) if (col[u] == -1) {
        col[u] = col[v] ^ 1;
        dfs(u);
    }
}

bool BipartiteColoring(int n) {
    for (int i = 1; i <= n; ++i)
        col[i] = -1;
    for (int i = 1; i <= n; ++i) if (col[i] == -1) {
        col[i] = 0;
        dfs(i);
    }
    for (int i = 1; i <= n; ++i) for (int j : adj[i]) {
        if (col[i] == col[j]) {
            return false;
        }
    }
    return true;
}

bool TopologicalSort(int n) {
    vector <int> in(n + 1, 0);
    for (int i = 1; i <= n; ++i) for (int j : adj[i]) {
        in[j]++;
    }
    queue <int> q;
    for (int i = 1; i <= n; ++i) if (in[i] == 0) {
        q.push(i);
    }
    int ord = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        topo[v] = ord++;
        for (int u : adj[v]) {
            in[u]--;
            if (in[u] == 0) {
                q.push(u);
            }
        }
    }
    return ord == n;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <edge> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].type >> a[i].u >> a[i].v;
        adj[a[i].u].push_back(a[i].v);
        adj[a[i].v].push_back(a[i].u);
    }
    if (!BipartiteColoring(n)) {
        cout << "NO" << endl;
        return 0;
    }
    // col = 0 -> orient left, col = 1 -> orient right
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }
    for (edge e : a) {
        if (col[e.u] == 1)
            swap(e.u, e.v);
        if (e.type == 1) {
            adj[e.u].push_back(e.v);
        } else {
            adj[e.v].push_back(e.u);
        }
    }
    if (!TopologicalSort(n)) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << (col[i] == 0 ? "L " : "R ") << topo[i] << endl;
    }
}
```
[1635F - Closest Pair](../problems/F._Closest_Pair_.md "Codeforces Round 772 (Div. 2)") 

 **Tutorial**
### [1635F - Closest Pair](../problems/F._Closest_Pair_.md "Codeforces Round 772 (Div. 2)")

First of all, let's solve the problem for the whole array.

Define Li as the biggest j satisfying j<i and wj≤wi, and Ri as the smallest j satisfying j>i and wj≤wi. 

Then, we consider 2n pairs of points: (Li,i) and (i,Ri) for each 1≤i≤n. In conclusion, the closest pair (the pair with the minimum weighted distance) must be among them.

Proof: Assume that (a,b) is the closest pair and a<b. If wa≤wb holds, then a=Lb must holds, otherwise (a,Lb) would obviously be a better pair.

Similarly, if wa>wb holds, then b=Ra must holds, otherwise (Ra,b) would obviously be a better pair.

The lemma above also applies to range queries by the exact same proof. So now, we first need to find Li and Ri for each 1≤i≤n, this could be simply done with a stack. Then, imagine we draw lines between the endpoints of each pair, and the problem could be reduced to: given 2n weighted segments, for each query i find the one with the minimum weight that is totally covered by [li,ri]. This is actually a classic problem, which could be solved by sweep line trick + any data structure able to maintain prefix-minimum with single point updates, like BIT or segment tree.

Total Complexity: O((n+q)logn).

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const long long INF = 1ll << 62;

vector <int> useful_pair[N];
vector <pair <int, int>> queries[N];

long long bit[N];

void modify(int p, long long v) {
    for (int i = p; i > 0; i -= i & (-i)) {
        bit[i] = min(bit[i], v);
    }
}

long long query(int p) {
    long long ans = INF;
    for (int i = p; i < N; i += i & (-i)) {
        ans = min(ans, bit[i]);
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector <int> x(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> w[i];
    }
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r, --l;
        queries[r].emplace_back(l, i);
    }
    stack <int> stk;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && w[stk.top()] > w[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            int x = stk.top();
            useful_pair[i].push_back(x);
        }
        stk.push(i);
    }
    while (!stk.empty()) {
        stk.pop();
    }
    for (int i = n - 1; ~i; --i) {
        while (!stk.empty() && w[stk.top()] > w[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            int x = stk.top();
            useful_pair[x].push_back(i);
        }
        stk.push(i);
    }
    fill(bit, bit + N, INF);
    vector <long long> ans(q);
    for (int r = 1; r <= n; ++r) {
        for (int l : useful_pair[r - 1]) {
            long long val = 1ll * (x[r - 1] - x[l]) * (w[l] + w[r - 1]);
            modify(l + 1, val);
        }
        for (auto [l, id] : queries[r]) {
            ans[id] = query(l + 1);
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << endl;
    }
}
```
