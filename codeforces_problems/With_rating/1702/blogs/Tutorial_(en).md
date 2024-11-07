# Tutorial_(en)

[1702A - Round Down the Price](../problems/A._Round_Down_the_Price.md "Codeforces Round 805 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1702A - Round Down the Price](../problems/A._Round_Down_the_Price.md "Codeforces Round 805 (Div. 3)")

Note that the number $m$ and the nearest round number not exceeding $m$ have the same size (consist of the same number of digits in the record). Denote the size of $m$ by $len$. Then we can construct the nearest round number. It will consist of one and $len - 1$ zeros. 

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back



void solve() {
    int m; cin >> m;
    string t = to_string(m);
    string s = "1";
    for (int i = 1; i < sz(t); i++) {
        s += '0';
    }
    int k = stoi(s);
    cout << m - k << 'n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
```
[1702B - Polycarp Writes a String from Memory](../problems/B._Polycarp_Writes_a_String_from_Memory.md "Codeforces Round 805 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1702B - Polycarp Writes a String from Memory](../problems/B._Polycarp_Writes_a_String_from_Memory.md "Codeforces Round 805 (Div. 3)")

Let us simulate the process. We store a set $v$ consisting of letters that Polycarp memorizes on one day. Gradually dial the set $s$. If the size of $v$ exceeds $3$, we add $1$ to the day counter $ans$ and clear $v$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back



void solve() {
    string s; cin >> s;
    set<char> v;
    int ans = 0;
    for (int i = 0; i < sz(s); i++) {
        v.insert(s[i]);
        if (sz(v) > 3) {
            ans++;
            v.clear();
            v.insert(s[i]);
        }
    }
    if (!v.empty()) ans++;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
```
[1702C - Train and Queries](../problems/C._Train_and_Queries.md "Codeforces Round 805 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1702C - Train and Queries](../problems/C._Train_and_Queries.md "Codeforces Round 805 (Div. 3)")

To solve the problem, we will use the dictionary. Each station will be matched with a pair of integers — the indices of its first and last entries in the route. Then we will sequentially process queries. If at least one of the stations $a_j$ or $b_j$ is missing in the dictionary — the answer is NO. Otherwise, check: 

* If the index of the first entry of station $a_j$ in the route is strictly less than the index of the last entry of station $b_j$ in the route — the answer is YES.
* Otherwise, the answer is NO.
 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)


void solve(){
    int n, k;
    cin >> n >> k;
    map<int, pair<int, int>>m;
    forn(i, n){
        int u;
        cin >> u;
        if(!m.count(u)) {
            m[u].first = i;
            m[u].second = i;
        }
        else m[u].second = i;
    }
    forn(i, k){
        int a, b;
        cin >> a >> b;
        if(!m.count(a) or !m.count(b) or m[a].first > m[b].second) {
            cout << "NOn"; //equals = 0 = wrong
        }
        else cout << "YESn";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
```
[1702D - Not a Cheap String](../problems/D._Not_a_Cheap_String.md "Codeforces Round 805 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1702D - Not a Cheap String](../problems/D._Not_a_Cheap_String.md "Codeforces Round 805 (Div. 3)")

The main idea is that it is always better to remove the most expensive symbol. To do this quickly, we will count all the symbols and remove them from the most expensive to the cheapest, counting how many times we have removed each. During the output, we will skip the characters the number of times that we deleted.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        string s;
        cin >> s;
        int p;
        cin >> p;
        string w(s);
        sort(w.rbegin(), w.rend());
        int cost = 0;
        forn(i, s.length())
            cost += s[i] - 'a' + 1;
        map<char,int> del;
        forn(i, w.length())
            if (cost > p) {
                del[w[i]]++;
                cost -= w[i] - 'a' + 1;
            }
        forn(i, s.length()) {
            if (del[s[i]] > 0) {
                del[s[i]]--;
                continue;
            }
            cout << s[i];
        }
        cout << endl;
    }
}
```
[1702E - Split Into Two Sets](../problems/E._Split_Into_Two_Sets.md "Codeforces Round 805 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1702E - Split Into Two Sets](../problems/E._Split_Into_Two_Sets.md "Codeforces Round 805 (Div. 3)")

Polycarp has $n$ dominoes, on each domino there are $2$ numbers — it turns out, there will be $2n$ numbers in total.

We need to divide $2n$ numbers (each number from $1$ to $n$) into two sets so that all numbers in each set are different — each set will consist of $n$ numbers. It turns out that all numbers from $1$ to $n$ must occur exactly $2$ times, no more and no less.

Let's imagine it all as a bipartite graph, where there are vertices from $1$ to $n$, and dominoes are edges. Since each number occurs exactly $2$ times, then we have a lot of cycles. In which the edges of each number must be included in different sets, in other words, the cycles must be of even length.

This can be checked in $O(n)$ by a simple enumeration.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i = 0; i < int(n); i++)

map<int, vector<int>> m;
vector<bool> used;

int go(int v) {
    used[v] = true;
    for (auto now : m[v]) {
        if (!used[now]) {
            return go(now) + 1;
        }
    }
    return 1;
}

void solve() {

    int n, x, y;
    cin >> n;

    m.clear();
    used.clear();
    used.resize(n + 1, false);

    bool fault = false;
    forn(i, n) {
        cin >> x >> y;
        m[x].push_back(y);
        m[y].push_back(x);
        if (x == y || m[x].size() > 2 || m[y].size() > 2) fault = true;
    }

    if (fault) {
        cout << "NOn";
        return;
    }

    forn(i, n) {
        if (!used[i + 1]) {
            if (go(i + 1) % 2) {
                cout << "NOn";
                return;
            }
        }
    }

    cout << "YESn";
}
int main() {
    int tests;
    cin >> tests;
    forn(tt, tests) {
        solve();
    }
}
```
[1702F - Equate Multisets](../problems/F._Equate_Multisets.md "Codeforces Round 805 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1702F - Equate Multisets](../problems/F._Equate_Multisets.md "Codeforces Round 805 (Div. 3)")

We divide each number from the multiset $a$ by $2$ as long as it is divisible without a remainder. Because if we can get a new number from the multiset $a$, we can also increase it to the original number by multiplication by $2$. 

Now notice that it does not make sense to use the first operation (multiplication by $2$), because we get an even number, and only odd numbers remain in the multiset $a$. 

Then we take the largest number from $b$ and if it is in $a$, we remove this number from both multisets. Otherwise, we use the second operation, if the number is greater than $1$. If it is equal to $1$, then it is impossible to equalize the multisets $a$ and $b$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

const int INF = 1e9;

void solve() {
    int n; cin >> n;
    multiset<int> a, b;

    forn(i, n) {
        int x; cin >> x;
        while (x % 2 == 0) {
            x /= 2;
        }
        a.insert(x);
    }

    forn(i, n) {
        int x; cin >> x;
        b.insert(x);
    }
    n = sz(a);

    while (!b.empty()) {
        int x = *b.rbegin();
        // cout << x << endl;
        if (!a.count(x)) {
            if (x == 1) break;
            b.erase(b.find(x));
            b.insert(x / 2);
        } else {
            b.erase(b.find(x));
            a.erase(a.find(x));
        }
    }

    cout << (b.empty() ? "YES" : "NO") << endl;

}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
```
[1702G1 - Passable Paths (easy version)](../problems/G1._Passable_Paths_(easy_version).md "Codeforces Round 805 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1702G1 - Passable Paths (easy version)](../problems/G1._Passable_Paths_(easy_version).md "Codeforces Round 805 (Div. 3)")

If the answer is YES, then we can choose a subset of the tree vertices forming a simple path and containing all the vertices of our set. Let's choose the minimum possible path, its ends — vertices from the set. The constraints allow us to answer the query in $\mathcal{O}(n)$, hang the tree by one of the ends and check if it is true that there is only one selected vertex that does not have any selected ones in the subtree, if there is one such vertex, then it is  — the second end. To make it easier to search for one of the ends, we will hang the tree by any vertex before the queries, calculate their depths and take the deepest of the set.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define int long long
#define pb emplace_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

typedef long double ld;
typedef long long ll;

using namespace std;

mt19937 rnd(143);

const int inf = 1e15;
const int M = 1e9 + 7;
const ld pi = atan2(0, -1);
const ld eps = 1e-6;

void depth(int v, int p, vector<vector<int>> &sl, vector<int> &d){
    if(p >= 0) d[v] = d[p] + 1;
    for(int u: sl[v]){
        if(u == p) continue;
        depth(u, v, sl, d);
    }
}

int dfs(int v, int p, vector<vector<int>> &sl, vector<bool> &chosen){
    int res = 0;
    bool lower = false;
    for(int u: sl[v]){
        if(u == p) continue;
        res += dfs(u, v, sl, chosen);
        lower = lower || chosen[u];
    }
    chosen[v] = chosen[v] || lower;
    if(chosen[v] && !lower) res = 1;
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> sl(n);
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        sl[--u].push_back(--v);
        sl[v].push_back(u);
    }
    vector<int> d(n);
    depth(0, -1, sl, d);
    int q;
    cin >> q;
    for(; q; --q){
        int k;
        cin >> k;
        vector<bool> chosen(n);
        int mx = 0;
        for(int i = 0; i < k; ++i){
            int p;
            cin >> p;
            --p;
            if(d[p] > d[mx]) mx = p;
            chosen[p] = true;
        }
        int leaves = dfs(mx, -1, sl, chosen);
        if(leaves == 1) cout << "YESn";
        else cout << "NOn";
    }
}

bool multi = false;

signed main() {
    int t = 1;
    if (multi)cin >> t;
    for (; t; --t) {
        solve();
        //cout << endl;
    }
    return 0;
}
```
[1702G2 - Passable Paths (hard version)](../problems/G2._Passable_Paths_(hard_version).md "Codeforces Round 805 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1702G2 - Passable Paths (hard version)](../problems/G2._Passable_Paths_(hard_version).md "Codeforces Round 805 (Div. 3)")

Recall that the path in the rooted tree — ascends from one end to the least common ancestor ($lca$) of the ends and descends to the other end (possibly by 0). Then our set is divided into two simple ways.

To check this, you only need to count $lca$.

We will first calculate the depths, as for solving an easy version of the problem. We will go along the vertices according to the non-growth of the depths, if $lca$ of the deepest vertex and the current one is equal to the current one, then it is the ancestor of the deepest one, we will mark it. Next, we will find the deepest unmarked vertex and do the same, if there is no such vertex, then the whole path goes down and the answer is YES.

If there are unmarked vertices, then there are vertices outside of those two ascents and the answer is NO. Now we need to check that the two ascents do not intersect or intersect only at the $lca$ of ends, for this we just make sure that $lca$ is not deeper than the shallowest vertex of the set.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define int long long
#define pb emplace_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

typedef long double ld;
typedef long long ll;

using namespace std;

mt19937 rnd(143);

const int inf = 1e15;
const int M = 1e9 + 7;
const ld pi = atan2(0, -1);
const ld eps = 1e-6;

int n, sz;
vector<vector<int>> sl, up;
vector<int> d;

void precalc(int v, int p){
    d[v] = d[p] + 1;
    up[v][0] = p;
    for(int i = 1; i <= sz; ++i){
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for(int u: sl[v]){
        if(u == p) continue;
        precalc(u, v);
    }
}

int lca(int u, int v){
    if(d[u] < d[v]){
        swap(u, v);
    }
    for(int cur = sz; cur >= 0; --cur){
        if (d[u] - (1 << cur) >= d[v]) {
            u = up[u][cur];
        }
    }
    for(int cur = sz; cur >= 0; --cur){
        if (up[u][cur] != up[v][cur]) {
            u = up[u][cur];
            v = up[v][cur];
        }
    }
    return u == v ? u : up[u][0];
}

void solve(){
    cin >> n;
    sz = 0;
    while ((1 << sz) < n) sz++;
    d.assign(n, -1);
    up.assign(n, vector<int>(sz + 1));
    sl.assign(n, vector<int>(0));
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        sl[--u].push_back(--v);
        sl[v].push_back(u);
    }
    precalc(0, 0);
    int q;
    cin >> q;
    for(; q; --q){
        int k;
        cin >> k;
        vector<int> p(k);
        for(int &e: p) {
            cin >> e;
            --e;
        }
        sort(all(p), [](int a, int b) {
            return d[a] > d[b];
        });
        vector<bool> used(k);
        for(int i = 0; i < k; ++i){
            if(lca(p[0], p[i]) == p[i]) used[i] = true;
        }
        int f = 0;
        while (f < k && used[f]) f++;
        if(f == k){
            cout << "YESn";
            continue;
        }
        bool ans = true;
        for(int i = f; i < k; ++i){
            if(lca(p[f], p[i]) == p[i]) used[i] = true;
        }
        for(bool e: used){
            ans &= e;
        }
        ans &= d[lca(p[0], p[f])] <= d[p.back()];
        if(ans) cout << "YESn";
        else cout << "NOn";
    }
}

bool multi = false;

signed main() {
    int t = 1;
    if (multi)cin >> t;
    for (; t; --t) {
        solve();
        //cout << endl;
    }
    return 0;
}
```
