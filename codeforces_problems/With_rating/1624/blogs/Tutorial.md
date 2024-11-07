# Tutorial

[1624A - Plus One on the Subset](../problems/A._Plus_One_on_the_Subset.md "Codeforces Round 764 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1624A - Plus One on the Subset](../problems/A._Plus_One_on_the_Subset.md "Codeforces Round 764 (Div. 3)")

Let's sort the numbers in ascending order. It becomes immediately clear that it is not profitable for us to increase the numbers that are equal to the last number (the maximum of the array). It turns out that every time you need to take such a subset of the array, in which all the numbers, except the maximums. And once for each operation, the numbers in the subset are increased by one, then how many times can the operation be performed on the array? Accordingly max(a)−min(a).

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
    int MIN = INT_MAX;
    int MAX = INT_MIN;
    for (int i = 0; i < n; ++i) {
        MIN = min(MIN, a[i]);
        MAX = max(MAX, a[i]);
    }
    cout << MAX - MIN << 'n';
}
int main() {
    int tests;
    cin >> tests;
    forn(tt, tests) {
        solve();
    }
}
```
[1624B - Make AP](../problems/B._Make_AP.md "Codeforces Round 764 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1624B - Make AP](../problems/B._Make_AP.md "Codeforces Round 764 (Div. 3)")

Let's iterate over the number that we want to multiply by m.

How can we check that we can multiply the current number so that an AP is formed?

Note that those 2 numbers that we do not touch should form an AP themselves. For instance, let at the current operation we want somehow multiply the number c. Then a=x1, and b=x2=x1+d.

Note that b−a=x1+d−x1=d. Thus, we know what d is. Also we know that c=x1+2⋅d=a+2⋅d. Let's check if a+2⋅d is divisible by c. If yes, then we have found the answer, if not, then move on to the next number.

We do the same for a and b.

Be careful with non positive numbers, integer divisions and other edge cases.

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

void solveTest() {
    int a, b, c;
    cin >> a >> b >> c;

    int new_a = b - (c - b);
    if(new_a >= a && new_a % a == 0 && new_a != 0) {
        cout << "YESn";
        return;
    }

    int new_b = a + (c - a)/2;
    if(new_b >= b && (c-a)%2 == 0 && new_b % b == 0 && new_b != 0) {
        cout << "YESn";
        return;
    }

    int new_c = a + 2*(b - a);
    if(new_c >= c && new_c % c == 0 && new_c != 0) {
        cout << "YESn";
        return;
    }

    cout << "NOn";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--)
        solveTest();
    return 0;
}
```
[1624C - Division by Two and Permutation](../problems/C._Division_by_Two_and_Permutation.md "Codeforces Round 764 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1624C - Division by Two and Permutation](../problems/C._Division_by_Two_and_Permutation.md "Codeforces Round 764 (Div. 3)")

Let's sort the array a in descending order of the values of its elements. Then let's create a logical array used, where used[i] will have the value true if we already got element i of the permutation we are looking for, and the value false otherwise.

We loop through the elements of the array a and assign x=ai. We'll divide x by 2 as long as it exceeds n or as long as used[x] is true. 

* If it turns out that x=0, then all the numbers that could be obtained from ai have already been obtained before. Since each element of the array a must produce a new value from 1 to n, the answer cannot be constructed — output NO.
* Otherwise, assign used[x] a value of true — this means that the number x, which is an element of the permutation, we will get exactly from the original number ai.

After processing all elements of the array a we can output YES.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int>a(n), used(n + 1, false);
    for(auto &i : a) cin >> i;
    sort(a.begin(), a.end(), [] (int a, int b) {
        return a > b;
    });
    bool ok = true;
    for(auto &i : a){
        int x = i;
        while(x > n or used[x])  x /= 2;
        if(x > 0) used[x] = true;
        else ok = false;
    }
    cout << (ok ? "YES" : "NO") << 'n';

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```
[1624D - Palindromes Coloring](../problems/D._Palindromes_Coloring.md "Codeforces Round 764 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1624D - Palindromes Coloring](../problems/D._Palindromes_Coloring.md "Codeforces Round 764 (Div. 3)")

We will solve the problem greedily. First, we will try to add pairs of identical characters to palindromes. As long as there are at least k pairs, let's add them. After that, it is no longer possible to add a couple of characters, but you can try to add one character in the middle. This can be done if there are at least k characters left. There is no need to paint other characters.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX_N = 2e5;

int main(int argc, char* argv[]) {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> cnt(26);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int cntPairs = 0, cntOdd = 0;
        for (int c : cnt) {
            cntPairs += c / 2;
            cntOdd += c % 2;
        }
        int ans = 2 * (cntPairs / k);
        cntOdd += 2 * (cntPairs % k);
        if (cntOdd >= k) {
            ans++;
        }
        cout << ans << 'n';
    }
}
```
[1624E - Masha-forgetful](../problems/E._Masha-forgetful.md "Codeforces Round 764 (Div. 3)")

Idea: [Aris](https://codeforces.com/profile/Aris "Candidate Master Aris")

 **Tutorial**
### [1624E - Masha-forgetful](../problems/E._Masha-forgetful.md "Codeforces Round 764 (Div. 3)")

The key idea is that any string of length greater than 3 can be obtained by concatenating strings of length 2 or 3. Then when reading the data, remember all occurring substring of length 2 and 3. There are at most 104. 

Now we will count the dynamics on the prefix: dp[i]=true if we can get the prefix of length i of phone s by segments of length 2 and 3 of the known phones Masha. Then for the transition we need to look through the lengths 2 and 3, then take a substring of the corresponding length and find out whether such a string occurred in the phones known to Masha.

Then it will take O(m) or O(mlogm) time to recalculate the dynamics, depending on the implementation. But it will still take more time to read the data, so the final asymptotic will be O(nm) or O(nmlogm).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()

const int N = 1e4;
map<string, bool> have;
map<string, tuple<int,int,int>> pos;

void solve() {
    int n, m; cin >> n >> m;
    vector<bool> dp(m+1, false);
    vector<int> pr(m+1);
    vector<string> cache;
    dp[0] = true;

    forn(i, n) {
        string s; cin >> s;
        forn(j, m) {
            string t;
            t += s[j];
            for(int k = 1; k <= 2; k++) {
                if (k + j >= m) break;
                t += s[j+k];

                if (!have[t]) {
                    have[t] = true;
                    pos[t] = make_tuple(j, j+k, i);
                    cache.push_back(t);
                }
            }
        }
    }

    string s; cin >> s;
    forn(i, m) {
        string t;
        t += s[i];
        for (int k = 1; k <= 2; k++) {
            if (i - k < 0) break;
            t = s[i-k] + t;
            if (have[t] && dp[i-k]) {
                dp[i+1] = true;
                pr[i+1] = i-k;
            }
            if (dp[i+1]) break;
        }
    }
    for (string t : cache) {
        have[t] = false;
    }

    if (!dp[m]) {
        cout << "-1n";
        return;
    }
    vector<tuple<int,int,int>> ans;

    for (int k = m; k > 0; ) {
        int p = pr[k];
        string t = s.substr(p, k - p);
        ans.emplace_back(pos[t]);
        k = p;
    }

    cout << sz(ans) << 'n';
    reverse(ans.begin(), ans.end());
    for (auto [l,r,i] : ans) cout << l+1 << ' ' << r+1 << ' ' << i+1 << 'n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
```
[1624F - Interacdive Problem](../problems/F._Interacdive_Problem.md "Codeforces Round 764 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1624F - Interacdive Problem](../problems/F._Interacdive_Problem.md "Codeforces Round 764 (Div. 3)")

After each query we know the ⌊xn⌋ value, then we need to find xmodn to find the current x value. To find it, we will use a binary search.

Suppose xmodn is in the [l,r) half-interval, in order to understand which half it is in, we will make a query, select the middle m of the half-interval and make a + n−m query. After that, ⌊xn⌋ will either change, which means that xmodn was in the [m,r) half-interval, or not, then it was in the [l,m) half-interval. Now you just need to properly shift the half-interval to accommodate the query change.

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

const int inf = 1e10;
const int M = 998244353;
const ld pi = atan2(0, -1);
const ld eps = 1e-4;

signed main(){
    int n;
    cin >> n;
    int l = 1, r = n;
    int div = 0;
    while(r - l > 1){
        int mid = (r + l) / 2;
        cout << "+ "<< n - mid << endl;
        int d;
        cin >> d;
        if(d > div)l = mid;
        else r = mid;
        l = (l + n - mid) % n;
        r = (r + n - mid) % n;
        if(r == 0) r = n;
        div = d;
    }
    cout << "! " << div * n + l;
    return 0;
}
```
[1624G - MinOr Tree](../problems/G._MinOr_Tree.md "Codeforces Round 764 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1624G - MinOr Tree](../problems/G._MinOr_Tree.md "Codeforces Round 764 (Div. 3)")

We need to minimize the result of the bitwise operation, so for convenience, we represent the answer as a mask. Firstly, let's assume that this mask is composed entirely of ones.

Let's go from the most significant bit to the least significant one and try to reduce the answer. To understand whether it is possible to remove the j-th bit, remove it and check if the graph, in which all the weights are submasks of the current answer, is connected, for this, you can use depth-first search or a disjoint sets union. If the graph is connected, then the bit can obviously be thrown out, and if not it cannot and must be returned.

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

const int inf = 1e9;
const int M = 998244353;
const ld pi = atan2(0, -1);
const ld eps = 1e-4;

int n, cur;
vector<vector<pair<int, int>>> sl;

void dfs(int v, vector<bool> &used){
    used[v] = true;
    for(auto e: sl[v]){
        int u = e.x, w = e.y;
        if(!used[u] && (cur | w) == cur){
            dfs(u, used);
        }
    }
}

void cnt(int pw){
    if(pw < 0) return;
    int d = (ll) 1 << pw;
    cur -= d;
    vector<bool> used(n);
    dfs(0, used);
    for(bool b: used){
        if(!b) {
            cur += d;
            break;
        }
    }
    cnt(pw - 1);
}

void solve() {
    int m;
    cin >> n >> m;
    sl.assign(n, vector<pair<int, int>>(0));
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        sl[u].emplace_back(v, w);
        sl[v].emplace_back(u, w);
    }
    cur = 1;
    int bit = 0;
    for(; cur < inf; bit++){
        cur = 2 * cur + 1;
    }
    cnt(bit);
    cout << cur;
}

bool multi = true;

signed main() {
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
