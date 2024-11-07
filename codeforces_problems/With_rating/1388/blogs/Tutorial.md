# Tutorial

[1388A - Captain Flint and Crew Recruitment](../problems/A._Captain_Flint_and_Crew_Recruitment.md "Codeforces Round 660 (Div. 2)")

Idea: [Denisov](https://codeforces.com/profile/Denisov "Master Denisov")

 **Tutorial**
### [1388A - Captain Flint and Crew Recruitment](../problems/A._Captain_Flint_and_Crew_Recruitment.md "Codeforces Round 660 (Div. 2)")

Consider the three smallest nearly prime numbers: $6, 10$ and $14$: 

* if $ n \le 30=6+10+14$, then the answer is NO.
* otherwise the answer is YES.

The easiest way is to display $6, 10, 14, n-30$ in cases where $n-30 \neq 6, 10, 14$.

If $ n = 36, 40, 44, $ then we can output $6, 10, 15, n-31$.

In addition, it was possible to generate the first nearly prime numbers and iterate over all their possible triplets.

Complexity: $O(1)$ or more if brute-force is written.

 **Solution (Karavaev1101)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int q;
    cin >> q;

    while(q--){
        int n; cin >> n;
        if(n <= 30){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            if(n == 36 || n == 40 || n == 44){
                cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << n - 31 << endl;
            }
            else{
                cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n - 30 << endl;
            }
        }
    }
}
```
[1388B - Captain Flint and a Long Voyage](../problems/B._Captain_Flint_and_a_Long_Voyage.md "Codeforces Round 660 (Div. 2)")

Idea: [Karavaiev](https://codeforces.com/profile/Karavaiev "Candidate Master Karavaiev")

 **Tutorial**
### [1388B - Captain Flint and a Long Voyage](../problems/B._Captain_Flint_and_a_Long_Voyage.md "Codeforces Round 660 (Div. 2)")

Statement: $x$ consists of digits $8-9$.

This is so, because if $x$ contains digits $0-7$, which in their binary notation are shorter than digits $8-9$, then the number $k$ written on the board, and therefore the number $r$ (obtained by removing the last $n$ digits of the number $k$) will be shorter than if you use only the digits $8$ and $9$, which means it will not be the maximum possible.

Statement: $x$ is $99 \dots 988 \dots 8$.

Obviously, the more $x$, the more $k$ and $r$. Therefore, to maximize $k$, $x$ must be $99 \dots 999$. However, due to the fact that $r$ is $k$ without the last $n$ digits, at the end of the number $x$ it is possible to replace a certain number of $9$ digits with $8$ so that $r$ will still be the maximum possible.

Statement: the number of digits $8$ in the number $x$ of length $n$ is equal to $\left\lceil \frac{n}{4} \right\rceil$.

$8_{10}=1000_2$ and $9_ {10}=1001_2$. We can see that the binary notations of the digits $8$ and $9$ are $4$ long and differ in the last digit.

Suppose the suffix of a number $x$ consists of $p$ digits $8$. Then the maximum $r$ is achieved if at least $4 \cdot p - 3$ digits are removed from the end of $k$. By the condition of the problem, exactly $n$ digits are removed, which means $4 \cdot p - 3 \le n$ and then $p = \left \lfloor \frac {n + 3} {4} \right \rfloor = \left \lceil \frac {n} {4} \right \rceil$.

Complexity: $O(n)$.

 **Solution (Karavaev1101)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        int n; cin >> n;
        int x = (n + 3) / 4;
        for (int i = 0; i < n - x; ++i) {
            cout << 9;
        }
        for (int i = 0; i < x; ++i) {
            cout << 8;
        }
        cout << endl;
    }
}
```
[1388C - Uncle Bogdan and Country Happiness](../problems/C._Uncle_Bogdan_and_Country_Happiness.md "Codeforces Round 660 (Div. 2)")

Idea: [Karavaiev](https://codeforces.com/profile/Karavaiev "Candidate Master Karavaiev")

 **Tutorial**
### [1388C - Uncle Bogdan and Country Happiness](../problems/C._Uncle_Bogdan_and_Country_Happiness.md "Codeforces Round 660 (Div. 2)")

For each city $v$ count $a_v$ — how many people will visit it. Knowing this value and the value of the level of happiness — $h_v$, we can calculate how many people visited the city in a good mood: $g_v=\frac {a_v + h_v} {2}$.

We can single out the $3$ criterions for the correctness of the values of the happiness indices:

1. $a_v + h_v$ is a multiple of $2$. For each $v$, $g_v$ — an integer.
2. $0 \le g_v \le a_v$. In each city $v$ the number of residents who passed this city in a good mood — a non-negative number not exceeding $a_v$.
3. $ g_{to_1} + g_{to_2} + \ldots + g_{to_k} \le g_v,$ where $to_1, $ $to_2,$ $\ldots,$ $to_k$ are the cities where the resident can move out of the city $v$ on the way home. This follows from the fact that the mood of the inhabitants can be deteriorated and cannot be improved.

This is enough, since these conditions guarantee the correctness of the happiness indices by definition, as well as the peculiarities of changes in the mood of residents.

 **Solution (Karavaev1101)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

vector < int > gr[N];

bool access = true;

int p[N], h[N], a[N], g[N];

void dfs(int v, int ancestor = -1) {
    a[v] = p[v];
    int sum_g = 0;
    for (int to : gr[v]) {
        if (to == ancestor) continue;
        dfs(to, v);
        sum_g += g[to];
        a[v] += a[to];
    }
    if ((a[v] + h[v]) % 2 == 0) {} // first
    else access = false;
    g[v] = (a[v] + h[v]) / 2;
    if (g[v] >= 0 && g[v] <= a[v]) {} // second
    else access = false;
    if (sum_g <= g[v]) {} // third
    else access = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> p[i];
        for (int i = 0; i < n; ++i) cin >> h[i];
        for (int i = 0; i < n - 1; ++i) {
            int a, b; cin >> a >> b;
            --a, --b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        dfs(0);
        cout << (access ? "YES" : "NO") << endl;
        access = true;
        for (int i = 0; i < n; ++i) gr[i].clear();
    }
}
```
[1388D - Captain Flint and Treasure](../problems/D._Captain_Flint_and_Treasure.md "Codeforces Round 660 (Div. 2)")

Idea: [Denisov](https://codeforces.com/profile/Denisov "Master Denisov")

 **Tutorial**
### [1388D - Captain Flint and Treasure](../problems/D._Captain_Flint_and_Treasure.md "Codeforces Round 660 (Div. 2)")

Let's construct a graph $G$ with $n$ vertices and directed edges $(i; b_i)$.

Note that it is not profitable to process the vertex $i$ if the vertices $j$, for which $b_j=i$, have not yet been processed, since it is possible to process these vertices $j$ so that they will not decrease $a_i$.

We will do the following operation $n$ times:

Choose a vertex $V$ which does not contain any edge (there is always such a vertex due to an additional condition in the problem). Let's process it as follows: 

* if $a_V> 0$, then apply the operation from the condition to this vertex. This is beneficial because if $b_v \neq -1 $ then we will improve the value of $a_{b_V}$.
* if $a_V \le 0$, then the value of $a_{b_V}$ will not improve, which means that it is profitable to apply the operation to the vertex $V$ after $b_V$ (if $b_V \neq -1$).

 Let's remember when to process the $V$ vertex and then remove it from the graph.Let's store two containers $now$ and $after$. In $now$ we store the order of processing of vertices for which $a_V>0$. In $after$ - for which $a_V \le 0$. Then let's notice that the order $now + reverse (after)$ is appropriate to achieve the maximum answer.

Total $O(n)$ or $O(n \cdot log(n))$ depending on the implementation. 

 **Solution (Denisov)**
```cpp
#include <bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()

using namespace std;

vector <vector <int> > edge;
vector <ll> a;
vector <int> b, used;
vector <int> order[2];
ll ans;
inline void dfs (int v) {
    used[v] = 1;
    for (int to : edge[v]) {
        if (!used[to]) dfs(to);
    }
    ans += a[v];
    if (b[v] != -1 && a[v] > 0) {
        a[b[v]] += a[v];
    }
    if (a[v] > 0) {
        order[0].push_back(v);
    }
    else {
        order[1].push_back(v);
    }
}
inline void solve () {
    for (auto &i : edge) i.clear();
    edge.clear();
    a.clear();
    order[0].clear();
    order[1].clear();
    b.clear();
    used.clear();
    int n, x;
    cin >> n;
    edge.resize(n);
    a.resize(n);
    b.resize(n);
    for (auto &i : a) cin >> i;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != -1) {
            --x;
            edge[x].push_back(i);
        }
        b[i] = x;
    }
    ans = 0;
    used.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    cout << ans << 'n';
    reverse(all(order[1]));
    for (auto &i : order[0]) cout << i + 1 << ' ';
    for (auto &i : order[1]) cout << i + 1 << ' ';
    cout << 'n';
}
main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

```
 **Solution (Karavaev1101)**
```cpp
#include <bits/stdc++.h>

#define Vanya Unstoppable

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    long long a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    set < int > s;
    for (int i = 0; i < n; ++i) {
        s.insert(i);
    }
    
    int b[n];
    vector < int > sz(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i]; --b[i];
        if (b[i] == -2) continue;
        ++sz[b[i]];
        if (sz[b[i]] == 1) {
            s.erase(b[i]);
        }
    }
    
    long long sum = 0;
    vector < int > ans[2];
    
    while (!s.empty()) {
        int v = *s.begin();
        s.erase(s.begin());
        int w = b[v];
        sum += a[v];
        if (a[v] >= 0) {
            if (w >= 0) {
                a[w] += a[v];
            }
            ans[0].push_back(v);
        } else {
            ans[1].push_back(v);
        }
        if (w >= 0) {
            --sz[w];
            if (sz[w] == 0) {
                s.insert(w);
            }
        }
    }
    
    cout << sum << endl;
    for (int to : ans[0]) cout << to + 1 << ' ';
    
    reverse(ans[1].begin(), ans[1].end());
    
    for (int to : ans[1]) cout << to + 1 << ' ';
    cout << endl;
}
```
[1388E - Uncle Bogdan and Projections](../problems/E._Uncle_Bogdan_and_Projections.md "Codeforces Round 660 (Div. 2)")

Idea: [perekopskiy](https://codeforces.com/profile/perekopskiy "International Master perekopskiy")

 **Tutorial**
### [1388E - Uncle Bogdan and Projections](../problems/E._Uncle_Bogdan_and_Projections.md "Codeforces Round 660 (Div. 2)")

It is easy to understand that there is an optimal vector at which the value we need is minimal and at least one pair of projections is touching. Note also that the vector is completely described by the angle between it and the positive direction of the $ OX $ axis. If two line segments are at different heights, then there are two ways to select a vector so that their projections touch. Let's find two angles that describe these vectors. If we project along a vector with an angle that is in the interval that the found two angles form, then the projections will intersect. So, this range of angles is 'forbidden'. Using the scanline method, we can find such angles that they are the boundaries of some 'forbidden' interval and do not fall into any 'forbidden' interval. Then we only need to check these angles.

We also need to quickly find the rightmost and leftmost points for each angle. Let's take two points at different heights. Let them project to one point with a vector with an angle $\alpha$. Then on the interval $(0^\circ;\alpha)$ the upper one will be to the right, and on the interval $ (\alpha; 180^\circ)$ the upper one will be to the left. We will process two types of requests using the scanning line:

1. Check the answer for the current angle;
2. Swap two points. It is necessary to carefully handle the case when, at some angle, several points are swapped.

Alternative way: if you project the point $(x; y)$ along the vector with the angle $\alpha$, you get the point $(x + y * ctg (\ alpha); 0)$. We'll use the Convex Hull Trick to quickly find the rightmost and leftmost points for each angle. We will store CHT for maximums and minimums with lines $ k = y_i, b = x_i $. Queries at $ctg(\alpha)$ will give us the leftmost and rightmost points.

It is a corner case if all points are at the same height. Then the answer is $max(xr_i) - min(xl_i)$.

Complexity of solution - $O(n^2log(n))$.

 **Solution (perekopskiy)**
```cpp
#include <bits/stdc++.h>

#define pb push_back
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
const double eps = 1e-9;

double xl[N], xr[N], y[N], pi = acos(-1), mn_x, mx_x;
int ind_l, ind_r;

double point_pr(double x, double y, double ctg) {
    return x - y * ctg;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    vector<pair<double, int> > q;
    vector<pair<double, pair<int, int> > > events, prom_left, prom_right;
    cin >> n;
    pair<double, double> mx, mn;
    mx = {-1.0, -1.0};
    mn = {2e9, 2e9};
    mn_x = 2e9;
    mx_x = -2e9;
    for(int i = 0; i < n; ++i) {
        cin >> xl[i] >> xr[i] >> y[i];

        if(xl[i] < mn_x) {
            mn_x = xl[i];
        }
        if(xr[i] > mx_x) {
            mx_x = xr[i];
        }

        if(mx.y < y[i]) {
            mx.y = y[i];
            mx.x = xl[i];
            ind_l = i;
        }
        else if(mx.y == y[i] && mx.x > xl[i]) {
            mx.y = y[i];
            mx.x = xl[i];
            ind_l = i;
        }

        if(mn.y > y[i]) {
            mn.y = y[i];
            mn.x = xl[i];
            ind_r = i;
        }
        else if(mn.y == y[i] && mn.x < xl[i]) {
            mn.y = y[i];
            mn.x = xl[i];
            ind_r = i;
        }
    }
    double a1, a2;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(y[i] > y[j]) {
                a1 = (xr[i] - xl[j]) / (y[i] - y[j]);
                a2 = (xl[i] - xr[j]) / (y[i] - y[j]);
                q.pb({a1, 1});
                q.pb({a2, 2});

                a1 = (xl[i] - xl[j]) / (y[i] - y[j]);
                a2 = (xr[i] - xr[j]) / (y[i] - y[j]);
                events.pb({a1, {i, j}});
                events.pb({a2, {-i - 1, j}});
            }
        }
    }

    if(q.empty()) {
        cout << fixed << setprecision(9) << mx_x - mn_x << endl;
        return 0;
    }

    sort(q.rbegin(), q.rend());
    int cnt = 0;
    double last = 0;
    for(auto i : q) {
        if(i.y == 2) {
            --cnt;
            if(!cnt) {
                events.pb({i.x, {-1e9, -1e9}});
            }
        }
        else {
            if(!cnt) {
                events.pb({i.x, {-1e9, -1e9}});
            }
            ++cnt;
        }
    }
    sort(events.rbegin(), events.rend());
    double ans = 1e18, ang;
    last = -1e18;
    for(auto i : events) {
        if(i.y.x == i.y.y) {
            unordered_set<int> s;
            vector<int> to_check;
            for(auto j : prom_left) {
                s.insert(j.y.x);
                if(j.y.x == ind_l) {
                    to_check.pb(j.y.y);
                }
            }
            prom_left.clear();
            for(auto j : to_check) {
                if(!s.count(j)) {
                    ind_l = j;
                    break;
                }
            }
            s.clear();
            to_check.clear();

            for(auto j : prom_right) {
                s.insert(j.y.y);
                if(j.y.y == ind_r) {
                    to_check.pb(-j.y.x - 1);
                }
            }
            prom_right.clear();
            for(auto j : to_check) {
                if(!s.count(j)) {
                    ind_r = j;
                    break;
                }
            }
            s.clear();
            to_check.clear();

            double res = point_pr(xr[ind_r], y[ind_r], i.x) - point_pr(xl[ind_l], y[ind_l], i.x);
            if(ans > res) {
                ans = res;
                ang = i.x;
            }
        }
        else if(i.y.x < 0) {
            if(abs(i.x - last) > eps) {
                unordered_set<int> s;
                vector<int> to_check;
                for(auto j : prom_right) {
                    s.insert(j.y.y);
                    if(j.y.y == ind_r) {
                        to_check.pb(-j.y.x - 1);
                    }
                }
                prom_right.clear();
                for(auto j : to_check) {
                    if(!s.count(j)) {
                        ind_r = j;
                        break;
                    }
                }
                s.clear();
                to_check.clear();
            }
            prom_right.pb(i);
        }
        else {
            if(abs(i.x - last) > eps) {
                unordered_set<int> s;
                vector<int> to_check;
                for(auto j : prom_left) {
                    s.insert(j.y.x);
                    if(j.y.x == ind_l) {
                        to_check.pb(j.y.y);
                    }
                }
                prom_left.clear();
                for(auto j : to_check) {
                    if(!s.count(j)) {
                        ind_l = j;
                        break;
                    }
                }
                s.clear();
                to_check.clear();
            }
            prom_left.pb(i);
        }
        last = i.x;
    }
    cout << fixed << setprecision(9) << ans << endl;
    return 0;
}
```
