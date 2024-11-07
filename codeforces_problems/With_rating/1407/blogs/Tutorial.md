# Tutorial

[1407A — Ahahahahahahahaha](../problems/A._Ahahahahahahahaha.md)

 **Tutorial**
### [1407A - Ahahahahahahahaha](../problems/A._Ahahahahahahahaha.md "Codeforces Round 669 (Div. 2)")

Let $cnt_0$ be the count of zeroes in the array, $cnt_1$ — count of ones. Then if $cnt_1 \leq \frac{n}{2}$, we remove all ones and alternating sum, obliously, equals $0$. Otherwise, $cnt_0 < \frac{n}{2}$, we remove all zeroes and if $cnt_1$ is odd — plus another $1$. In this case, alternating sum equals $1 - 1 + 1 - \ldots - 1 = 0$ (because count of remaining ones if even) and we'll remove not more than $cnt_0 + 1 \leq \frac{n}{2}$.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a(n), ans;
        int cnt0 = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (!a[i]) cnt0++;
        }
        int cnt1 = n - cnt0;
        if (cnt0 >= n / 2) {
            cout << cnt0 << 'n';
            for (int i = 0; i < cnt0; i++) cout << 0 << ' ';
        } else {
            cout << cnt1 - cnt1 % 2 << 'n';
            for (int i = 0; i < cnt1 - cnt1 % 2; i++) {
                cout << 1 << ' ';
            }
        }
        cout << 'n';
    }
    return 0;
}
```
[1407B — Big Vova](../problems/B._Big_Vova.md)

 **Tutorial**
### [1407B - Big Vova](../problems/B._Big_Vova.md "Codeforces Round 669 (Div. 2)")

We'll describe several constructive solutions for this task, differing by the time complexity:

1. $O(n^2log A)$

Let $b$ be an empty sequence in the beginning. We'll consequently transfer elements from $a$ to $b$ in a certain order.

Let's notice that if we've already transfered $(k-1)$ elements then we can always choose to the place of $b_k$ any element $a_j$ left in $a$ such that $c_k=gcd(b_1,\dots,b_{k-1},a_j)$ is maximal. A-priory, if we've fixed the first $(k-1)$ elements of the sequence, lexicographically greater would be the one in which $c_k$ is maximal. The particular value of $b_k$ here doesn't matter: each element $c_i$ divides all the previous ones, so $gcd(b_k, c_j)=gcd(c_k,c_j)$ for any $j>=k$.

So the algorithm is following: let's say that we have auxiliary element of the sequence $c_0=0$, and $gcd(0, k)=k$ for any integer $k\geq1$. Then we make $n$ iterations: during the $i$-th one we choose such $a_j$ (overall elements left in $a$) that the value of $gcd(a_j, c_{i-1})$ is maximal, and make $b_i=a_j$, removing $a_j$ from the sequence $a$. The $i$-th iteration will be passed in $O((n-i)log A)$, where $A$ is the greatest possible value in the original $a$ sequence, $log A$ is the time complexity of the Euclidean algorithm for searching $GCD$. Via summing time complexities overall iterations we get summary $O(n^2log A)$ time complexity of the algorithm.

2. $O(Anlog A)$

The main idea is the same as in the first solution, but the realisation is different: the main array $a$ is contained as an array $cnt$ of size $A$, where $cnt_x$ is the amount of elements in $a$ that are equal to $x$. Searching for the optimal element $b_k$ is $O(Alog A)$ for each of $n$ iterations, so the summary is $O(Anlog A)$.

3. $O(nlog^2 A)$

This solution is based on the following idea: for each $i>1$ either $c_i=c_{i-1}$ or $2c_i\leq c_{i-1}$. That means any possible sequence $c$ contains $O(log A)$ different values.

So we do $O(log A)$ iterations, on each we find the value $x$ among the elements left in $a$ that maximizes $O(c_k, x)$ (where $k$ is the amount of elements already transfered to $b$, and $c_k=gcd(b_1,\dots,b_k)$) and transfer all the elements left in $a$ of the value equal to $x$ to the end of $b$. Each iteration is done in $O(n log A)$ so the total time complexity is $O(n log^2 A)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int mi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mi = (a[i] > a[mi] ? i : mi);
    }
    vector<int> b(n);
    b[0] = a[mi]; a[mi] = 0;
    int cg = b[0];
    for (int i = 1; i < n; i++) {
        int ci = 0, cans = 0;
        for (int j = 0; j < n; j++)
            if (a[j] && __gcd(a[j], cg) > cans) {
                cans = __gcd(a[j], cg);
                ci = j;
            }
        b[i] = a[ci];
        cg = cans;
        a[ci] = 0;
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << 'n';
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


```
[1407C — Chocolate Bunny](../problems/C._Chocolate_Bunny.md)

 **Tutorial**
### [1407C - Chocolate Bunny](../problems/C._Chocolate_Bunny.md "Codeforces Round 669 (Div. 2)")

Observation: $(a \bmod b > b \bmod a) \Leftrightarrow (a < b)$.

Proof: if $a > b$, then $(a \bmod b) < b = (b \bmod a$). If $a = b$, then $(a \bmod b) = (b \bmod a) = 0$.

Let's maintain index $mx$ of maximal number on the reviewed prefix (initially $mx = 1$). Let's consider index $i$. Ask two queries: ? i mx and ? mx i. We'll know the less from both of them and either guess $p_{mx}$ and update $mx = i$ or guess $p_i$. In the end, all numbers will be guessed except $p_{mx}$, that, obviously, equals $n$.

In total, we'll make $2 \cdot n - 2$ queries.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
int ask(int x, int y) {
    cout << "? " << x + 1 << ' ' << y + 1 << endl;
    int z;
    cin >> z;
    return z;
}
int main() {
    int n;
    cin >> n;
    vector<int>ans(n, -1);
    int mx = 0;
    for (int i = 1; i < n; i++) {
        int a = ask(mx, i);
        int b = ask(i, mx);
        if (a > b) {
            ans[mx] = a;
            mx = i;
        } else {
            ans[i] = b;
        }
    }
    ans[mx] = n;
    cout << "! ";
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
```
[1407D — Discrete Centrifugal Jumps](../problems/D._Discrete_Centrifugal_Jumps.md)

 **Tutorial**
### [1407D - Discrete Centrifugal Jumps](../problems/D._Discrete_Centrifugal_Jumps.md "Codeforces Round 669 (Div. 2)")

Consider such a jump, when all of the skyscrapers between are smaller than initial and final (another case is similar). Let's stand on the skyscraper with index $x$. We want to find out whether $y$-th skyscraper satisfies our conditions. We have two cases: 

* $h_x \leq h_y$. Then, obviously, $y$ is the first skyscraper that not lower than $x$ (otherwise we have a building that higher than starter, it's contradiction).
* $h_x > h_y$. Then, it's easy to see, that $x$ is the first skyscraper to the left of $y$, that higher than $y$ for the same reason.

For another case, reasoning is similar, but skyscaper should be lower, not higher. We can see, that amount of pairs $i, j : i < j$ such that we can jump from $i$ to $j$, we can estimate as $O(n)$. 

So, we can find for each skyscraper the nearest bigger (and smaller) one using stack and simply count $dp_i$ — minimal count of jumps that we need to reach $i$-th skyscraper. 

Check the solution for a better understanding.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
const int maxn = 3e5 + 1;
int h[maxn], dp[maxn], lge[maxn], lle[maxn], rge[maxn], rle[maxn];
vector<int>jumps[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        dp[i] = INF;
    }
    dp[0] = 0;
    vector<pair<int, int> >st;
    for (int i = 0; i < n; i++) { // the nearest greater from the left
        while (!st.empty() && st.back().first < h[i]) {
            st.pop_back();
        }
        if (st.empty()) lge[i] = -1;
        else lge[i] = st.back().second;
        st.push_back({h[i], i});
    }
    st.clear();
    for (int i = 0; i < n; i++) { // the nearest less from the left
        while (!st.empty() && st.back().first > h[i]) {
            st.pop_back();
        }
        if (st.empty()) lle[i] = -1;
        else lle[i] = st.back().second;
        st.push_back({h[i], i});
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) { // the nearest greater from the right
        while (!st.empty() && st.back().first < h[i]) {
            st.pop_back();
        }
        if (st.empty()) rge[i] = -1;
        else rge[i] = st.back().second;
        st.push_back({h[i], i});
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) { // the nearest less from the right
        while (!st.empty() && st.back().first > h[i]) {
            st.pop_back();
        }
        if (st.empty()) rle[i] = -1;
        else rle[i] = st.back().second;
        st.push_back({h[i], i});
    }
    st.clear();
    for (int i = 0; i < n; i++) {
        if (rle[i] != -1) jumps[i].push_back(rle[i]);
        if (rge[i] != -1) jumps[i].push_back(rge[i]);
        if (lle[i] != -1) jumps[lle[i]].push_back(i);
        if (lge[i] != -1) jumps[lge[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        for (int to : jumps[i]) {
            dp[to] = min(dp[to], dp[i] + 1);
        }
    }
    cout << dp[n - 1];
    return 0;
}
```
[1407E — Egor in the Republic of Dagestan](../problems/E._Egor_in_the_Republic_of_Dagestan.md)

 **Tutorial**
### [1407E - Egor in the Republic of Dagestan](../problems/E._Egor_in_the_Republic_of_Dagestan.md "Codeforces Round 669 (Div. 2)")

**This task has a simple intuitive proof, but I wanted to describe it formally so it's pretty complicated.**

We'll show a constructive algorithm for this task and proof it's correctness. We also provide a realisation with $O(n+m)$ time complexity. 

 Let's change each edge's direction to the opposite. Then for vertex of color $c$ all incoming edges of color $c$ and only they are safe. We call a schedule optimal for $x$ if the shortest path (from $n$) to $x$ along the safe edges is the longest possible. We call a path (from $n$) to $x$ optimal if it's the shortest path for any optimal schedule for $x$. So we have to find an optimal schedule for $1$ and the length of optimal path for $1$.

Let's make four parameters for each vertex $x$:

$b[x]$ - the length of optimal path to $x$, if $x$ is black,

$w[x]$ - the length of optimal path to $x$, if $x$ is white,

$dp[x]$ - the length of optimal path to $x$ among all possible schedules,

$col[x]$ - the color of $x$. 

 The algorithm is following:

1. Initially $b[n]=w[n]=dp[n]=0$, $b[x]=w[x]=dp[x]=+\infty$ for all $x\neq n$. All vertices are unpainted.
2. If there is no unpainted vertex $x$ such that $dp[x]<+\infty$ (including the case when all vertices are painted) - go to point $6$
3. Among all unpainted vertices choose vertex $u$ with the smallest possible value of $dp[u]$. If $b[u] > w[u]$ set $col[u]=0$.

If $w[u] > b[u]$ set $col[u]=1$.

If $w[u] = b[u]$ then $col[u]$ can be either $0$ or $1$.
4. Watch each edge $(u, v)$ outgoing from $u$. Let an edge's color be $t$.If $t=0$ (black edge) - set $b[v]=min(b[v], dp[u]+1)$.

If $t=1$ (white edge) - set $w[v]=min(w[v], dp[u]+1)$.

Then set $dp[v]=max(b[v], w[v])$.
5. Go to point $2$.
6. For each unpainted vertex set the color just as in point $3$.
7. The value of $dp[1]$ is equal to the desired answer (excluding $dp[1]=\infty$ case: that means there's no way from $n$ to $1$ for the constructed schedule, and the answer is $-1$), and the values of $col$ form the optimal schedule.

Correctness proof

Let $lb[x]$, $lw[x]$ and $l[x]$ be the real optimal values of $b[x]$, $w[x]$ and $dp[x]$. We'll show that the parameters found by the algorithm are optimal. Let's proof some statements:

1. Any optimal path is simple. This statement is obvious, because the shortest path in any graph doesn't contain repeating vertices.

2. For any black edge $(u, v$) $l[u]+1\geq lb[v]$. For any schedule the length of the shortest path from $n$ to $u$ is not greater than $l[u]$, and the color of $v$ is fixed, so the length of the shortest path from $n$ to $v$ is not greater than $l[u]+1$. For white edges and correspondingly $lw[u]$ the analogous statement is correct.

3. $b[x]\geq lb[x]$, $w[x]\geq lw[x]$ for any vertex $x$ at every moment. Before the first iteration the statement $3$ is correct. Let $u$ be selected in the beginning of some iteration, and we update the parameters of $v$ for a black edge $(u, v)$. Let the statement $3$ be correct before the update. Then due to the statement $2$ $l[u]+1\geq lb[v]$. $b[u]\geq lb[u]$ and $w[u]\geq lw[u]$, so $dp[u]=max(b[u],w[u])\geq l[u]=max(lb[u],lw[u])$, and $dp[u]+1\geq l[u]+1\geq lb[v]$. After the update the value of $b[v]$ can stay the same or be changed to $dp[u]+1$, but since as $b[v]\geq l[v]$, the final value of $b[v]$ is not less than $l[v]$, so the statement $3$ remains correct after the update. Analogously we can show that for white edges it's correct, too. By induction we have that the statement $3$ is invariant, i.e. it's always correct.

We can notice that for each painted vertex $x$ it's value of $dp[x]$ is not smaller than the value of $dp[y]$ for any vertex $y$ painted before the $x$. Also, the values of $dp[x]$, $b[x]$ and $w[x]$ remain constant after the iteration when $x$ is painted. These facts are easy-to-proof, but for shortness we won't do it here.

Lemma:  in the end of the $k$-th iteration for each vertex $x$ the values of $b[x]$, $w[x]$ and $dp[x]$ correspond to the shortest (for the current schedule) paths passing through the painted vertices only (excluding $x$).

Proof: we'll show it by induction on the number of iterations. 

It's easy to see that after the first iteration the Lemma remains correct.

Let the Lemma be correct after the first $k$ iterations. Let $x$ be painted during the $(k+1)$-th iteration. Then $b[x]$ and $w[x]$ are already equal to the lengths of shortest paths to $x$, passing through painted vertices only and ending by black and white edges, correspondingly (it's obvious, proof it yourself if you don't believe). The length of the shortest path for already painted vertices won't change, because $dp[x]$ is not smaller than the values of $dp$ of previously painted vertices.

Thus, at the end of the algorithm we get the desired schedule, where $dp[x]$ for each $x$ is equal to the length of the shortest path to $x$, and $dp[x]\geq l[x]$; then from these two statements follows the fact that $dp[x]=l[x]$ for all vertices $x$, what means that the constructed schedule is optimal. 

 Realisation

This algorithm can be realised as a modified BFS, where the vertex is added to the queue just as it's value becomes smaller than infinity (in the code the value of «infinity» can be just $n$). It's easy to proof that such realisation is equivalent to the algorithm.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 1;

vector<int> bg[maxn], rg[maxn];
int b[maxn], r[maxn], d[maxn], col[maxn];
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        --u; --v;
        if (!t) bg[v].push_back(u);
        else rg[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        d[i] = b[i] = r[i] = n;
    queue<int> q;
    q.push(n - 1);
    d[n - 1] = r[n - 1] = b[n - 1] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto to : bg[x]) {
            if (b[to] < n) continue;
            b[to] = d[x] + 1;
            if (max(b[to], r[to]) < n) {
                q.push(to);
                d[to] = max(b[to], r[to]);
            }
        }
        for (auto to : rg[x]) {
            if (r[to] < n) continue;
            r[to] = d[x] + 1;
            if (max(b[to], r[to]) < n) {
                q.push(to);
                d[to] = max(b[to], r[to]);
            }
        }
    }
    if (d[0] == n) cout << "-1n";
    else cout << d[0] << 'n';
    for (int i = 0; i < n; i++) {
        if (b[i] > r[i]) col[i] = 0;
        else col[i] = 1;
        cout << col[i];
    }
    return 0;
}

```
