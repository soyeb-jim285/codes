# Tutorial_(en)

[1619A - Square String?](../problems/A._Square_String_.md "Codeforces Round 762 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1619A - Square String?](../problems/A._Square_String_.md "Codeforces Round 762 (Div. 3)")

If the length of the given string s is odd, then the answer is NO, since adding two strings cannot do that. Otherwise, let n be the length of the string. Let's go through the first half of the string, comparing whether its first and n2+1 characters are equal, its second and n2+2 characters are equal, and so on. If the characters in any pair are not equal, the answer is NO, otherwise — YES.

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
        bool ok = true;
        if (s.length() % 2 == 0) {
            forn(i, s.length() / 2)
                if (s[i] != s[i + s.length() / 2])
                    ok = false;
        } else
            ok = false;
        cout << (ok ? "YES" : "NO") << endl;
    }
}
```
[1619B - Squares and Cubes](../problems/B._Squares_and_Cubes.md "Codeforces Round 762 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1619B - Squares and Cubes](../problems/B._Squares_and_Cubes.md "Codeforces Round 762 (Div. 3)")

We'll search for positive integers not larger than n, and add their squares or cubes to the set if they don't exceed n. If n=109, the maximum number Polycarp will like is 316222=999950884, so the running time will be within the time limit.

The answer to the problem is the length of the resulting set.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        set<int> a;
        for (int i = 1; i * i <= n; i++)
            a.insert(i * i);
        for (int i = 1; i * i * i <= n; i++)
            a.insert(i * i * i);
        cout << a.size() << endl;
    }
}
```
[1619C - Wrong Addition](../problems/C._Wrong_Addition.md "Codeforces Round 762 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1619C - Wrong Addition](../problems/C._Wrong_Addition.md "Codeforces Round 762 (Div. 3)")

Let's compute the answer to the array b, where bk is the digit at the k position in the number we are looking for. Let i be the position of the last digit in number a, j be the position of the last digit in number s. Then denote x=ai, y=sj, and consider the cases: 

* if x≤y, then the sum of ai+bi was exactly si, then bi=y−x.
* if x>y, then the sum ai+bi was greater than 9 and we need to look at the next digit of the number s. If there isn't one, we can't get the answer — we'll output -1. Otherwise we recalculate y=10⋅sj−1+sj and reduce j by one.
* if now y≥10 and y≤18, then bi=y−x. Otherwise, we deduce -1, since we cannot get more than 9+9=18 when adding two digits, and the cases where ai+bi<10 have already been considered before.

 After considering the cases, reduce i and j by one and repeat the checks as long as i>0 or j>0. In the situation where j=0, but i>0, we will still have uncheked digits of number a, so we will also output -1. Otherwise, we output an array with the answer without leading zeros. **Solution**
```cpp
#include<bits/stdc++.h>
#define len(s) (int)s.size()
using namespace std;
using ll = long long;
 
void solve(){
    ll a, s;
    cin >> a >> s;
    vector<int>b;
    while(s){
        int x = a % 10;
        int y = s % 10;
        if(x <= y) b.emplace_back(y - x);
        else{
            s /= 10;
            y += 10 * (s % 10);
            if(x < y && y >= 10 && y <= 19) b.emplace_back(y - x);
            else{
                cout << -1 << 'n';
                return;
            }
        }
        a /= 10;
        s /= 10;
    }
    if(a) cout << -1 << 'n';
    else{
        while (b.back() == 0) b.pop_back();
        for(int i = len(b) - 1; i >= 0; i--) cout << b[i];
        cout << 'n';
    }
}
 
int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t){
        solve();
        t--;
    }
    return 0;
}
```
[1619D - New Year's Problem](../problems/D._New_Year's_Problem.md "Codeforces Round 762 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Specialist Vladosiya")

 **Tutorial**
### [1619D - New Year's Problem](../problems/D._New_Year's_Problem.md "Codeforces Round 762 (Div. 3)")

Note that if we cannot get joy x, then we cannot get x+1, and if we can get at least x, then we can get at least x−1. These facts allow us to use binary search to find the answer.

Now we need to understand how exactly we can recognize whether we can gain joy at least x or not. We can enter at most n−1 shops, so we always need to take two gifts from some store, which means there must be a store in which we can find two or more gifts with pleasure at least x. Also, each friend should receive a gift, which means that we should be able to buy each gift with pleasure at least x. It takes O (nm) to check that both of these conditions are met. The total solution works in O (nm ∗ log (nm)).

 **Solution**
```cpp
//
// Created by Vlad on 17.12.2021.
//
 
#include <bits/stdc++.h>
 
#define int long long
#define mp make_pair
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
*/
typedef long double ld;
typedef long long ll;
 
using namespace std;
 
mt19937 rnd(143);
 
const int inf = 1e10;
const int M = 998244353;
const ld pi = atan2(0, -1);
const ld eps = 1e-4;
 
int n, m;
vector<vector<int>> p;
 
bool check(int x){
    vector<bool> abl(m);
    bool pair = false;
    for(int i = 0; i < n; ++i){
        int c = 0;
        for(int j = 0; j < m; ++j){
            if(p[i][j] >= x){
                abl[j] = true;
                c++;
            }
        }
        if(c > 1) pair = true;
    }
    if(!pair && m > 1) return false;
    bool ans = true;
    for(bool b: abl){
        ans = ans && b;
    }
    return ans;
}
 
void solve() {
    cin >> n >> m;
    p.assign(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> p[i][j];
        }
    }
    int l = 1, r = 2;
    while (check(r)) r *= 2;
    while (r - l > 1){
        int mid = (r + l) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
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
[1619E - MEX and Increments](../problems/E._MEX_and_Increments.md "Codeforces Round 762 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1619E - MEX and Increments](../problems/E._MEX_and_Increments.md "Codeforces Round 762 (Div. 3)")

First, let's sort the array. Then we will consider its elements in non-decreasing order. To make MEX equal to 0, you need to increase all zeros. To make MEX at least n, you first need to make MEX at least n−1, and then, if the number n−1 is missing in the array, you need to get it. If there are no extra values less than n−1, then this and all subsequent MEX values cannot be obtained. Otherwise, you can use the maximum of the extra array values. To do this, you can use a data structure such as a stack. If an element occurs more than once in the array, put its extra occurrences on the stack.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
const int MAX_N = 2e5;
 
int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n;
        cin >> n;
        vector<int> a(n), cnt(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a.begin(), a.end());
        stack<int> st;
        vector<ll> ans(n + 1, -1);
        ll sum = 0;
        for (int i = 0; i <= n; ++i) {
            if (i > 0 && cnt[i - 1] == 0) {
                if (st.empty()) {
                    break;
                }
                int j = st.top();
                st.pop();
                sum += i - j - 1;
            }
            ans[i] = sum + cnt[i];
            while (i > 0 && cnt[i - 1] > 1) {
                cnt[i - 1]--;
                st.push(i - 1);
            }
        }
        for (ll x : ans) {
            cout << x << ' ';
        }
        cout << 'n';
    }
}
```
[1619F - Let's Play the Hat?](../problems/F._Let's_Play_the_Hat_.md "Codeforces Round 762 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1619F - Let's Play the Hat?](../problems/F._Let's_Play_the_Hat_.md "Codeforces Round 762 (Div. 3)")

For each game, we want to seat n people at m tables, nmodm of them will be big and B=⌈nm⌉ will sit at them, and m−nmodm will be small. Each round p=nmodm∗B people will sit at the big tables.

Let's put people with numbers 0,1,2…p−1 at large tables in the first round (for convenience we index from zero), and the rest for small ones, in the second round we will seat people at large tables with numbers pmodn,(p+1)modn…(2p−1)modn and so on.

We cycle through the players from 1 to n in blocks of p. Since p<n, no one person can be ahead of any other by 2 or more large tables.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> p(n);
        forn(i, n)
            p[i] = i;
        if (tt > 0)
            cout << endl;
        forn(round, k) {
            int index = 0;
            forn(table, m) {
                int size = n / m;
                if (table < n % m)
                    size++;
                cout << size;
                forn(j, size)
                    cout << " " << p[index++] + 1;
                cout << endl;                        
            }
            rotate(p.begin(), p.begin() + (n % m) * ((n + m - 1) / m), p.end());
        }
    }
}
```
[1619G - Unusual Minesweeper](../problems/G._Unusual_Minesweeper.md "Codeforces Round 762 (Div. 3)")

Idea: [Gol_D](https://codeforces.com/profile/Gol_D "Candidate Master Gol_D")

 **Tutorial**
### [1619G - Unusual Minesweeper](../problems/G._Unusual_Minesweeper.md "Codeforces Round 762 (Div. 3)")

Our first task is to separate mines into components. We will store in the hashmap $mapx$ at the $x$ coordinate all the $y$ coordinates where there is a mine. Let's do the same with the $mapy$ hashmap. Thus, going through the available arrays in $mapx$ and $mapy$, we connect adjacent elements into one component, if $|mapx[x][i] - mapx[x][i + 1]| <= k$, also with $mapy$.

As a result, we have components, where if you detonate one mine in the $j$'s component, then all the mines belonging to this component will also explode.

Further, we find a mine with a minimum timer in each component. Finding the minimum for each component, we store it conditionally in the array $a$. Now we know at what minimum time some component will explode if it is left unaffected.

To answer, it remains to find in the sorted array $a$ such a minimum index $i$ $(0 \le i \le a.size - 1)$ that $max (a[i], a.size - i - 2)$ is min.

And the general asymptotic behavior is $O(n log (n))$.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
int k;
 
map <int, vector<int>> mx;
map <int, vector<int>> my;
map <pair<int ,int>, bool> used;
map <pair<int, int>, int> time_of;
 
int dfs(int x, int y) {
    used[{x, y}] = true;
    int _min_ = time_of[{x, y}];
 
    auto i = lower_bound(mx[x].begin(), mx[x].end(), y);
    auto j = lower_bound(my[y].begin(), my[y].end(), x);
 
    if (++i != mx[x].end() && !used[{x, *i}] && abs(*i - y) <= k) {
        _min_ = min(_min_, dfs(x, *i));
    }
    --i;
    if (i != mx[x].begin() && !used[{x, *(--i)}] && abs(*i - y) <= k) {
        _min_ = min(_min_, dfs(x, *i));
    }
 
    if (++j != my[y].end() && !used[{*j, y}] && abs(*j - x) <= k) {
        _min_ = min(_min_, dfs(*j, y));
    }
    --j;
    if (j != my[y].begin() && !used[{*(--j), y}] && abs(*j - x) <= k) {
        _min_ = min(_min_, dfs(*j, y));
    }
 
    return _min_;
}
 
void solve() {
    mx.clear();
    my.clear();
    used.clear();
 
    int n;
    cin >> n >> k;
    vector <pair<int, int>> a(n);
    int x, y, timer;
 
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> timer;
        a[i] = {x, y};
        time_of[{x, y}] = timer;
        mx[x].push_back(y);
        my[y].push_back(x);
    }
    vector<int> res;
 
    for (auto now: mx) {
        sort(mx[now.first].begin(), mx[now.first].end());
    }
    for (auto now: my) {
        sort(my[now.first].begin(), my[now.first].end());
    }
 
    for (auto now: a) {
        if (!used[now]) {
            res.push_back(dfs(now.first, now.second));
        }
    }
    sort(res.begin(), res.end());
 
    int ans = res.size() - 1;
    for (int i = 0; i < res.size(); ++i) {
        ans = min(ans, max((int)res.size() - i - 2, res[i]));
    }
    cout << ans << 'n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int tests;
    cin >> tests;
    forn(tt, tests) {
        solve();
    }
}
```
[1619H - Permutation and Queries](../problems/H._Permutation_and_Queries.md "Codeforces Round 762 (Div. 3)")

Idea: [Brovko](https://codeforces.com/profile/Brovko "International Master Brovko")

 **Tutorial**
### [1619H - Permutation and Queries](../problems/H._Permutation_and_Queries.md "Codeforces Round 762 (Div. 3)")

Let's compute an array a of n integers — answers to all possible second-type queries with k=Q, Q≈√n. Now, if we have to perform any second-type query, we can split it into at most n/Q queries with k=Q and at most Q−1 queries with k=1.

Let's also compute an array r of n integers — reverse permutation. If pi=j, then rj=i.

To perform any first-type query, we should recompute p, r and a. We can swap px and py in the array p and rpx and rpy in the array r. No more than 2⋅Q elements will be changed in the array a. These are elements with indexes x,rx,rrx,…(Q elements) and y,ry,rry,…(Q elements). We can recompute ax and then assign arx=rax and x=rx Q−1 times. Similarly for y.

Time complexity: O((n+q)√n).

 **Solution**
```cpp
#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
 
using namespace std;
const int Q = 100;
 
int n, q, p[100005], r[100005], a[100005];
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> q;
 
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }
 
    for(int i = 0; i < n; i++)
        r[p[i]] = i;
 
    for(int i = 0; i < n; i++)
    {
        int x = i;
 
        for(int j = 0; j < Q; j++)
            x = p[x];
 
        a[i] = x;
    }
 
    while(q--)
    {
        int t, x, y;
        cin >> t >> x >> y;
 
        if(t == 2)
        {
            x--;
 
            while(y >= Q)
            {
                y -= Q;
                x = a[x];
            }
 
            while(y--)
                x = p[x];
 
            cout << x + 1 << "n";
        }
        else
        {
            x--;
            y--;
 
            swap(r[p[x]], r[p[y]]);
            swap(p[x], p[y]);
 
            int ax = x;
 
            for(int i = 0; i < Q; i++)
                ax = p[ax];
 
            int x2 = x;
 
            for(int i = 0; i < Q; i++)
            {
                a[x] = ax;
                x = r[x];
                ax = r[ax];
            }
 
            swap(x, y);
 
            ax = x;
 
            for(int i = 0; i < Q; i++)
                ax = p[ax];
 
            x2 = x;
 
            for(int i = 0; i < Q; i++)
            {
                a[x] = ax;
                x = r[x];
                ax = r[ax];
            }
        }
    }
}
```
