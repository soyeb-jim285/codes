# Tutorial_(en)

[1650A - Deletions of Two Adjacent Letters](../problems/A._Deletions_of_Two_Adjacent_Letters.md "Codeforces Round 776 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1650A - Deletions of Two Adjacent Letters](../problems/A._Deletions_of_Two_Adjacent_Letters.md "Codeforces Round 776 (Div. 3)")

There will be one character left in the end, so we have to delete all the characters going before and after it. That is, delete some prefix and suffix. Since we always delete some substring of length $2$, we can only delete the prefix and suffix of even length, it means the answer is YES in the case when there is an odd position in $s$ with the character $c$ and NO otherwise.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        string s, t;
        cin >> s >> t;
        bool yes = false;
        forn(i, s.length())
            if (s[i] == t[0] && i % 2 == 0)
                yes = true;
        cout << (yes ? "YES" : "NO") << endl;
    }
}
```
[1650B - DIV + MOD](../problems/B._DIV_+_MOD.md "Codeforces Round 776 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1650B - DIV + MOD](../problems/B._DIV_+_MOD.md "Codeforces Round 776 (Div. 3)")

Consider $f_a(r)$. Note that $\left\lfloor\frac{r}{a}\right\rfloor$ is maximal over the entire segment from $l$ to $r$, so if there is $x$ in which $f_a$ gives a greater result, then $x \bmod a > r\bmod a$.

Note that numbers from $r - r \bmod a$ to $r$ that have an incomplete quotient when divided by $a$ equal to $\left\lfloor\frac{r}{a}\right\rfloor$ do not fit this condition (and are guaranteed to have a value $f_a$ less than $f_a(r)$). And the number $x = r - r \bmod a - 1$:

* Has the maximum possible remainder $x \bmod a = a - 1$;
* Has the maximum possible $\left\lfloor\frac{r}{a}\right\rfloor$ among numbers less than $r - r\bmod a$.

So there are two candidates for the answer — these are $r$ and $r - r \bmod a - 1$. The second candidate is suitable only if it is at least $l$. It remains only to compare the values of $f_a$ and select the maximum.

 **Solution**
```cpp
#include <bits/stdc++.h>

//#define int long long
#define mp make_pair
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")

typedef long double ld;
typedef long long ll;

using namespace std;

mt19937 rnd(143);

const ll inf = 1e9;
const ll M = 1e9;
const ld pi = atan2(0, -1);
const ld eps = 1e-4;

void solve() {
    int l, r, x;
    cin >> l >> r >> x;
    int ans = r / x + r % x;
    int m = r / x * x - 1;
    if(m >= l)ans = max(ans, m / x + m % x);
    cout << ans;
}

bool multi = true;

signed main() {
    //freopen("in.txt", "r", stdin);
    //freopen("in.txt", "w", stdout);
    int t = 1;
    if (multi) {
        cin >> t;
    }
    for (; t != 0; --t) {
        solve();
        cout << "n";
    }
    return 0;
}
```
[1650C - Weight of the System of Nested Segments](../problems/C._Weight_of_the_System_of_Nested_Segments.md "Codeforces Round 776 (Div. 3)")

Idea: [myav](https://codeforces.com/profile/myav "Pupil myav")

 **Tutorial**
### [1650C - Weight of the System of Nested Segments](../problems/C._Weight_of_the_System_of_Nested_Segments.md "Codeforces Round 776 (Div. 3)")

We create a structure that stores for each point its coordinate, weight, and index in the input data. Sort the $points$ array by increasing weight. The sum of weights of the first $2 \cdot n$ points will be minimal, so we use them to construct a system of $n$ nested segments. We save the weights of the first $2 \cdot n$ points in the variable $sum$ and remove the remaining $m - 2 \cdot n$ points from the array. 

Now sort the points in ascending order of coordinates and form a system of nested segments such that the endpoints of $i$th segment are $points[i]$ and $points[2 \cdot n - i + 1]$ for $(1 \le i \le 2 \cdot n)$. Thus, the endpoints of the first segment are $points[1]$ and $points[2 \cdot n]$, the endpoints of the $n$th segment are $points[n]$ and $points[n + 1]$.

For each test case we first output $sum$, then — $n$ pairs of numbers $i$, $j$ ($1 \le i, j \le m$) — the indices under which the endpoints of the current segment were written in the input data.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define forn(i, n) for (int i = 0; i < int(n); i++)

struct point{
    int weight, position, id;
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<point>points(m);

    forn(i, m) {
        cin >>  points[i].position >> points[i].weight;
        points[i].id = i + 1;
    }

    sort(points.begin(), points.end(), [] (point a, point b){
        return a.weight < b.weight;
    });

    int sum = 0;
    forn(i, m){
        if(i < 2 * n) sum += points[i].weight;
        else points.pop_back();
    }

    sort(points.begin(), points.end(), [] (point a, point b){
        return a.position < b.position;
    });

    cout << sum << endl;
    forn(i, n){
        cout << points[i].id << ' ' << points[2 * n - i - 1].id << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```
[1650D - Twist the Permutation](../problems/D._Twist_the_Permutation.md "Codeforces Round 776 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1650D - Twist the Permutation](../problems/D._Twist_the_Permutation.md "Codeforces Round 776 (Div. 3)")

The first thing to notice — the answer always exists. For $n$ numbers $1\cdot2\cdot3 \dots n = n!$ answer choices, as well as $n!$ permutation combinations. It remains only to restore the answer from this permutation.

We will restore by performing reverse operations. On the $i$-th ($i = n,~n - 1, ~\dots, ~2, ~1$) operation will be selectd the first $i$ elements of the array and rotate them $d[i]$ times to the left ( elements with numbers $i+1$ and more remain in their places).

Where $d[i]$ is equal to $0$ if $i = 1$, otherwise $d[i] = (index + 1) \bmod i$, and $index$ – is the index of the number $i$.

Thus, for each $i$ from right to left, performing a left cyclic shift operation, we move the number $i$ at index $i$.

As a result, we move $O(n)$ numbers $n$ times. The time complexity $O(n^2)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i = 0; i < int(n); i++)


void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans[n];
    for (int i = n; i > 0; --i) {
        int ind = 0;
        for (int j = 0; j < i; ++j) {
            ind = a[j] == i ? j : ind;
        }
        int b[i];
        for (int j = 0; j < i; ++j) {
            b[(i - 1 - ind + j) % i] = a[j];
        }
        for (int j = 0; j < i; ++j) {
            a[j] = b[j];
        }
        ans[i - 1] = i != 1 ? (ind + 1) % i : 0;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << 'n';
}
int main() {
    int tests;
    cin >> tests;
    forn(tt, tests) {
        solve();
    }
}
```
[1650E - Rescheduling the Exam](../problems/E._Rescheduling_the_Exam.md "Codeforces Round 776 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1650E - Rescheduling the Exam](../problems/E._Rescheduling_the_Exam.md "Codeforces Round 776 (Div. 3)")

To begin with, we will learn how to find the optimal place for the exam that we want to move. Let's imagine that it is not in the schedule, in this case we have two options:

* Put the exam at the end of the session so that there are $d - a_n - 1$ days before it.
* Put it in the middle of the largest break between exams ((let its length be $mx$), so that between it and the nearest one there is $\left\lfloor \frac{mx - 1}{2} \right\rfloor$, because this is no worse than putting it in any part of any other break.

That is, the answer for such an arrangement is  — the minimum of the larger of these options and the minimum break, in schedule without the moved exam.

Now note that the minimum break in most variants is the same — minimum in the initial schedule. So in order to reduce $\mu$, you need to move exactly one of the two exams that form it and you need to check which of the two options is better.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define int long long
#define mp make_pair
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long double ld;
typedef long long ll;

using namespace std;

mt19937 rnd(143);

const ll inf = 1e9;
const ll M = 998'244'353;
const ld pi = atan2(0, -1);
const ld eps = 1e-4;

int n, d;

int cnt(vector<int> &schedule){
    int mx = 0, mn = inf;
    for(int i = 1; i < n; ++i){
        mx = max(mx, schedule[i] - schedule[i - 1] - 1);
        mn = min(mn, schedule[i] - schedule[i - 1] - 1);
    }
    return min(mn, max(d - schedule.back() - 1, (mx - 1) / 2));
}

void solve(int test_case) {
    cin >> n >> d;
    vector<int> a(n + 1);
    int mn = d, min_pos = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(a[i] - a[i - 1] - 1 < mn){
            mn = a[i] - a[i - 1] - 1;
            min_pos = i;
        }
    }
    vector<int> schedule;
    for(int i = 0; i <= n; ++i){
        if(i != min_pos){
            schedule.push_back(a[i]);
        }
    }
    int ans = cnt(schedule);
    if(min_pos > 1){
        schedule[min_pos - 1] = a[min_pos];
    }
    ans = max(ans, cnt(schedule));
    cout << ans;
}

bool multi = true;

signed main() {
    //freopen("in.txt", "r", stdin);
    //freopen("in.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    if (multi) {
        cin >> t;
    }
    for (int i = 1; i <= t; ++i) {
        solve(i);
        cout << "n";
    }
    return 0;
}
```
[1650F - Vitaly and Advanced Useless Algorithms](../problems/F._Vitaly_and_Advanced_Useless_Algorithms.md "Codeforces Round 776 (Div. 3)")

Idea: [Aris](https://codeforces.com/profile/Aris "Candidate Master Aris")

 **Tutorial**
### [1650F - Vitaly and Advanced Useless Algorithms](../problems/F._Vitaly_and_Advanced_Useless_Algorithms.md "Codeforces Round 776 (Div. 3)")

Note that it is always advantageous for us to complete the task that has an earlier deadline first. Only then will we proceed to the next task. Then we can solve each problem independently for each exam. Then it remains to score $100$ percent on the task on the available options. This is a typical knapsack problem with an answer recovery.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

template<class T> bool ckmin(T &a, T b) {return a > b ? a=b, true : false;}

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()

struct option {
    int t, p, id;
    option(int _t,int _p, int _id) : t(_t), p(_p), id(_id) {
    }
};

const int INF = INT_MAX >> 1;

vector<int> get_ans(vector<option> &v) {
    int n = sz(v);
    vector<vector<int>> dp(101, vector<int>(n+1, INF));
    dp[0][0] = 0;
    for (int k = 1; k <= n; k++) {
        auto [t,p,id] = v[k-1];
        dp[0][k] = 0;
        for (int i = 100; i > 0; i--) {
            int prev = max(0,i - p);
            dp[i][k] = dp[i][k-1];
            ckmin(dp[i][k], dp[prev][k-1] + t);
        }
    }
    vector<int> ans;
    int t = dp[100][n];

    if (t == INF) return {-1};
    for (int i = 100, k = n; k >= 1; k--) {
        if (dp[i][k] == dp[i][k-1]) {
            continue;
        }
        ans.emplace_back(v[k-1].id);
        i = max(0, i - v[k-1].p);
    }

    reverse(all(ans));
    ans.emplace_back(t);
    return ans;
}

void solve(bool flag=true) {


    int n,m; cin >> n >> m;
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }
    for (int i = n-1; i > 0; i--) {
        a[i] -= a[i-1];
    }

    vector<vector<option>> v(n);
    forn(j, m) {
        int e,t,p; cin >> e >> t >> p, e--;
        v[e].emplace_back(t, p, j+1);
    }
    vector<int> ans;
    forn(i, n) {
        vector<int> cur = get_ans(v[i]);
        if (sz(cur) == 1 && cur[0] == -1) {
            cout << "-1n";
            return;
        }
        int t = cur.back();
        if (t > a[i]) {
            cout << "-1n";
            return;
        }
        cur.pop_back();
        if (i+1 < n) a[i+1] += a[i] - t;

        ans.insert(ans.end(), all(cur));
    }


    cout << sz(ans) << 'n';
    for (auto e:ans) cout << e << ' ';
    cout << 'n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
```
[1650G - Counting Shortcuts](../problems/G._Counting_Shortcuts.md "Codeforces Round 776 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1650G - Counting Shortcuts](../problems/G._Counting_Shortcuts.md "Codeforces Round 776 (Div. 3)")

Note that in any shortest path, we cannot return to the previous vertex. Since if the current vertex $v$, the previous $u$. The current distance $d_v = d_u + 1$ (the shortest distance to vertex $v$), the shortest distance to vertex $t$ — $d_t$. Then, if we return to the vertex $u$, the shortest distance from it to $t$ is $d_t - d_u = d_t - d_v + 1$. If we add to the current distance, we get: $(d_v + 1) + (d_t - d_v + 1) = d_t + 2$. Thus, we get a path at least $2$ longer than the shortest one. Thus, our answer consists of only simple paths.

If the answer consists only of simple paths, then we will simply add vertices to the queue when traversing bfs twice (on the first visit, and on the next visit, when the distance to the vertex is equal to the shortest $+1$). And we will also count the number of ways to get to that vertex. Then we can output the answer as soon as we get to the vertex $t$ the second time for processing. After that we can terminate the loop. The asymptotic will be $O(n + m)$ since we only need bfs.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define eb emplace_back
#define mt make_tuple

const int INF = INT_MAX >> 1;
const int mod = 1e9 + 7;

void csum(int &a,int b) {
    a = (a + b) % mod;
}

int s, t;
vector<int> us;
vector<int> dist;
vector<int> dp[2];
int bfs(vector<vector<int>> &g) {
    queue<tuple<int,int,int>> q;
    q.push(mt(s, 0, 0)); //[v, dist, count]

    int ans = 0, mnd = INF;
    us[s] = 1;
    dp[0][s] = 1;
    dist[s] = 0;
    while(!q.empty()) {
        auto [v,d, x] = q.front(); q.pop();
        // cerr << v << ' ' << d << ' ' << dp[x][v] << endl;
        if (v == t) {
            if (mnd == INF) {
                mnd = d;
            }
            csum(ans, dp[x][v]);
        }
        if (d == mnd + 1) continue;
        for (int to : g[v]) if(d <= dist[to]) {
            dist[to] = min(dist[to], d+1);
            csum(dp[d - dist[to] + 1][to], dp[x][v]);
            // cerr << "TO: " <<  to << ' ' << dist[to] << ' ' << d << endl;
            if(us[to] == 0 || (us[to] == 1 && dist[to] == d)) q.push(mt(to, d+1, us[to]++));
        }
    }
    return ans;
}


void solve() {
    int n,m; cin >> n >> m;
    cin >> s >> t;
    us.resize(n+1);
    dp[0].resize(n+1);
    dp[1].resize(n+1);
    dist.resize(n+1);
    forn(i, n+1) {
        us[i] = dp[0][i] = dp[1][i] = 0;
        dist[i] = INF;
    }

    vector<vector<int>> g(n+1);
    forn(i, m) {
        int a,b; cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    cout << bfs(g) << 'n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
```
