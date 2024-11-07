# Tutorial_(en)

[1675A - Food for Animals](../problems/A._Food_for_Animals.md "Codeforces Round 787 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1675A - Food for Animals](../problems/A._Food_for_Animals.md "Codeforces Round 787 (Div. 3)")

Obviously, the best way to buy food for every pet is to buy maximum possible food for dogs and cats, then max(0,x−a) dogs and max(0,y−b) cats will not get food. We will buy universal food for these dogs and cats. Then the answer is YES, if max(0,x−a)+max(0,y−b)≤c, and NO else.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        int ax = min(a, x);
        int by = min(b, y);
        a -= ax;
        x -= ax;
        b -= by;
        y -= by;
        if (c >= x + y)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
```
[1675B - Make It Increasing](../problems/B._Make_It_Increasing.md "Codeforces Round 787 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1675B - Make It Increasing](../problems/B._Make_It_Increasing.md "Codeforces Round 787 (Div. 3)")

We will process the elements of the sequence starting from the end of the sequence. Each element ai (1≤i≤n−1) will be divided by 2 until it is less than ai+1. If at some point it turns out that ai+1=0, it is impossible to obtain the desired sequence.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto &i : a) cin >> i;
    int ans = 0;
    for(int i = n - 2; i >= 0; i--){
        while(a[i] >= a[i + 1] && a[i] > 0){
            a[i] /= 2;
            ans++;
        }
        if(a[i] == a[i+1]){
            cout << -1 << 'n';
            return;
        }
    }
    cout << ans << 'n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
```
[1675C - Detective Task](../problems/C._Detective_Task.md "Codeforces Round 787 (Div. 3)")

Idea: [Gol_D](https://codeforces.com/profile/Gol_D "Candidate Master Gol_D")

 **Tutorial**
### [1675C - Detective Task](../problems/C._Detective_Task.md "Codeforces Round 787 (Div. 3)")

First, let's note that we will have a transition from 1 to 0 only once, otherwise it turns out that first the picture disappeared, then it appeared and disappeared back, but we can consider that a friend in the middle, who answered 1 lied to us, but this is not true, because even before him the picture disappeared.

So we need to find this transition. Since we can also meet ?, we find the index of the leftmost 0 (in case of absence, we take n−1) and mark it as r0, and the index of rightmost 1 (in case of absence, we take 0) and mark as l1. Answer – the number of indices between them (inclusive), because only they could lie. r0−l1+1

There could not be a thief to the left of l1, since either the friend under the index l1 lied, or the picture was not stolen before l1. There could not be a thief to the right of r0, since either the painting had already been stolen in the presence of r0's friend, or it was he who lied.

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
        int n = s.length();
        vector<bool> a(n + 1);
        a[0] = true;
        forn(i, n)
            a[i + 1] = a[i] && (s[i] == '1' || s[i] == '?');
        vector<bool> b(n + 1);
        b[0] = true;
        for (int i = n - 1; i >= 0; i--)
            b[n - i] = b[n - i - 1] && (s[i] == '0' || s[i] == '?');
        int result = 0;
        forn(i, n)
            if (a[i] && b[n - i - 1])
                result++;
        cout << result << endl;
    }
}
```
[1675D - Vertical Paths](../problems/D._Vertical_Paths.md "Codeforces Round 787 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1675D - Vertical Paths](../problems/D._Vertical_Paths.md "Codeforces Round 787 (Div. 3)")

Let's find a set of leaves of a given tree. From each leaf we will climb up the tree until we meet a vertex already visited. Having met such a vertex, start a new path from the next leaf. 

The sequence of vertices in the found paths must be deduced in reverse order, because the paths must go from bottom to top. It also follows from this solution that the number of paths will always be equal to the number of leaves in the tree.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int>b(n + 1);
    vector<bool>leaf(n + 1, true);
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        leaf[b[i]] = false;
    }

    if(n == 1){
        cout << "1n1n1nn";
        return;
    }

    vector<int>paths[n + 1];
    vector<bool>used(n + 1, false);
    int color = 0;

    for(int i = 1; i <= n; i++){
        if(!leaf[i]) continue;
        used[i] = true;
        paths[color].emplace_back(i);

        int v = i;
        while (b[v] != v && !used[b[v]]){
            v = b[v];
            used[v] = true;
            paths[color].emplace_back(v);
        }
        color++;
    }

    cout << color << 'n';
    for(auto &path : paths){
        if(path.empty()) continue;
        cout << (int)path.size() << 'n';
        reverse(path.begin(), path.end());
        for(auto &v: path) cout << v << ' ';
        cout << 'n';
    }
    cout << 'n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
```
[1675E - Replace With the Previous, Minimize](../problems/E._Replace_With_the_Previous,_Minimize.md "Codeforces Round 787 (Div. 3)")

Idea: [myav](https://codeforces.com/profile/myav "Pupil myav")

 **Tutorial**
### [1675E - Replace With the Previous, Minimize](../problems/E._Replace_With_the_Previous,_Minimize.md "Codeforces Round 787 (Div. 3)")

Greedy idea. To minimize the string, we will go from left to right and maintain a variable mx = maximal character, from which we will reduce everything to 'a'. Initially it is 'a' and we spend 0 of operations on it. Then, at the next symbol, we can either reduce it to 'a' in no more than k operations, or reduce to 'a' the prefix we have already passed and minimize the next character in the remaining operations. 

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

template <class T> bool ckmax(T &a, T b) {return a<b ? a=b, true : false;}


void solve() {
    int n,k; cin >> n >> k;
    string s; cin >> s;

    char mn = 'a';
    for (int i = 0; i < n; i++) if(s[i] > mn) {
        if (s[i] - 'a' > k) {
            k -= mn - 'a';
            int to = s[i] - k;
            for (char c = s[i]; c > to; c--) {
                for (char &e:s) if (e == c) {
                    e = char(c-1);
                }
            }
            break;
        } else ckmax(mn, s[i]);
    }
    for (char &e:s) if (e <= mn) {
        e = 'a';
    }
    cout << s << endl;
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
```
[1675F - Vlad and Unfinished Business](../problems/F._Vlad_and_Unfinished_Business.md "Codeforces Round 787 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1675F - Vlad and Unfinished Business](../problems/F._Vlad_and_Unfinished_Business.md "Codeforces Round 787 (Div. 3)")

To begin with, we will hang the tree by the vertex x. In fact, we want to go from the root to the top of y, going off this path to do things and coming back. At one vertex of the path, it is advantageous to get off it in all the necessary directions and follow it further. So we will go 1 once for each edge leading to y and 2 times for each edge leading to some of the cases, but not leading to y.

Let's match each vertex with an edge to its ancestor. If the edge of a vertex leads to y, then y is in the subtree of this vertex, similarly with vertices with cases. It is necessary for each vertex to determine whether there is a vertex y in its subtree and whether there is a vertex from the array a, this can be done using a depth-first search, then we will calculate the answer according to the rules described above.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define ll long long
//#define double long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const int MOD = 1e9 + 7;
const int maxN = 5e3 + 1;
const int INF = 2e9;
const int MB = 20;

vector<vector<int>> g;
vector<bool> todo, good;

void dfs(int v, int p = -1) {
    for (int u : g[v]) {
        if (u != p) {
            dfs(u, v);
            if (todo[u]) {
                todo[v] = true;
            }
            if (good[u]) {
                good[v] = true;
            }
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    g.clear();
    g.resize(n);
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    todo.resize(n);
    fill(all(todo), false);
    good.resize(n);
    fill(all(good), false);
    for (int i = 0; i < k; ++i) {
        int v;
        cin >> v;
        --v;
        todo[v] = true;
    }
    good[y] = true;
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(x);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == x) {
            continue;
        }
        if (good[i]) {
            ++ans;
        } else if (todo[i]) {
            ans += 2;
        }
    }
    cout << ans << 'n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //    srand(time(0));
    int t = 1;
    cin >> t;
    while (t--) solve();
}
```
[1675G - Sorting Pancakes](../problems/G._Sorting_Pancakes.md "Codeforces Round 787 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1675G - Sorting Pancakes](../problems/G._Sorting_Pancakes.md "Codeforces Round 787 (Div. 3)")

For convenience, we will calculate the prefix sums on the array a, we will also enter the array b containing the indexes of all pancakes and calculate the prefix sums on it.

Let's use dynamic programming. Let's define dp[i][last][sum] as the required number of operations to correctly lay out the i-th prefix, with the final ai=last, and ∑ij=1aj=sum. Then you can go to dp[i][last][sum] from dp[i−1][last+j][sum−last] (the previous number must be greater, and the sum is fixed). To dp[i−1][last+j][sum−last], it will be necessary to add a certain number of actions necessary to get ai=last, let's call it add (all the terrible prefix sums are needed to count it). Since add depends only on last and sum, we only need to choose the minimum dp[i−1][last+j][sum−last], the choice can be optimized by suffix minima. As a result, the solution works for O(n∗m2), that's how many states need to be processed.

 **Solution**
```cpp
#include <bits/stdc++.h>

//#define int long long
#define mp make_pair
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long double ld;
typedef long long ll;

using namespace std;

mt19937 rnd(143);

const ll inf = 1e9 + 7;
const ll M = 998'244'353;
const ld pi = atan2(0, -1);
const ld eps = 1e-4;

void solve(int test_case) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), pancakes(1);
    for(int &e: a) cin >> e;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < a[i]; ++j){
            pancakes.emplace_back(i);
            int c = pancakes.size();
            pancakes[c - 1] += pancakes[c - 2];
        }
        if(i > 0) a[i] += a[i - 1];
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m + 1, vector<int>(m + 1, inf)));
    for(int j = 0; j <= m; j++){
        if(a[0] >= j) dp[0][j][j] = a[0] - j;//moved right
        else dp[0][j][j] = pancakes[j];//moved from right
    }
    for(int j = m - 1; j >= 0; --j){
        for(int k = j; k <= m; ++k){
            dp[0][j][k] = min(dp[0][j][k], dp[0][j + 1][k]);
        }
    }
    for(int i = 1; i < n; ++i){
        for(int j = 0; j <= m; ++j){
            for(int k = j; k <= m; ++k){
                int add = 0;
                if(a[i] >= k) add = a[i] - k;//moved to i + 1
                else {
                    int lend = min(j, k - a[i]);
                    add = pancakes[k] - pancakes[k - lend] - i * (lend);//moved from greater i
                }
                dp[i][j][k] = dp[i - 1][j][k - j] + add;
            }
        }

        for(int j = m - 1; j >= 0; --j){
            for(int k = (i + 1) * j; k <= m; ++k){
                dp[i][j][k] = min(dp[i][j][k], dp[i][j + 1][k]);
            }
        }
    }
    cout << dp[n-1][0][m];
}

bool multi = false;

signed main() {
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
