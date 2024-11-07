# Editorial_(en)

Thanks for participation!

[1994A - Diverse Game](https://codeforces.com/contest/1994/problem/A)

 **Editorial**
### [1994A - Diverse Game](https://codeforces.com/contest/1994/problem/A "Codeforces Round 959 sponsored by NEAR (Div. 1 + Div. 2)")

If n=m=1, then there is only one possible matrix, so the answer is −1. Otherwise, at least one of the numbers n,m is greater than 1, then one of the solutions is, for example, a matrix a with cyclically shifted rows (if m>1) or columns (if n>1).

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (auto &i: a) {
            for (auto &j: i) cin >> j;
        }
        if (n * m == 1) cout << "-1n";
        else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << a[(i + 1) % n][(j + 1) % m] << ' ';
                }
                cout << 'n';
            }
        }
    }
}
```
[1994B - Fun Game](https://codeforces.com/contest/1994/problem/B)

 **Editorial**
### [1994B - Fun Game](https://codeforces.com/contest/1994/problem/B "Codeforces Round 959 sponsored by NEAR (Div. 1 + Div. 2)")

If the string s consists entirely of 0, then obviously no other string can be obtained from it, so the answer is "Yes" only if s=t.

Otherwise, let i — the index of the first 1 in s. Note that if there is at least one 1 in t at positions [1;i), then the answer is "No", since s has 0 at these positions, so some of them must be changed to 1. However, when applying the operation the first 1 from position i can change bits only at positions greater than or equal to i, i.e. it will not be possible to change 0 at positions before i.

If there is only 0 at positions [1;i) in t, then it is possible to change any bit on the segment [i;n] in s to any other bit by choosing segments of length i and acting from the end, i.e. the answer is "Yes".

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size() && s[i] == '0'; ++i) {
        if (t[i] != '0') {
            cout << "NOn";
            return;
        }
    }
    cout << "YESn";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
```
[1994C - Hungry Games](https://codeforces.com/contest/1994/problem/C)

 **Editorial**
### [1994C - Hungry Games](https://codeforces.com/contest/1994/problem/C "Codeforces Round 959 sponsored by NEAR (Div. 1 + Div. 2)")

We'll solve the problem by dynamic programming. Let dp[i] — the number of good subsegments with left boundary at i. We will count dp from the end, for each i we will find such a minimum j that the sum on the subsegment [i;j] is greater than x. If there is no such j, then all right bounds are good, otherwise dp[i]=dp[j+1]+j−i. To search for j, we can use a binary search on prefix sums. The answer will be the sum of all dp.

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        partial_sum(a.begin() + 1, a.end(), a.begin() + 1);
        vector<int> dp(n + 2);
        for (int i = n - 1; i >= 0; --i) {
            int q = upper_bound(a.begin(), a.end(), a[i] + x) - a.begin();
            dp[i] = dp[q] + q - i - 1;
        }
        cout << accumulate(dp.begin(), dp.end(), 0ll) << 'n';
    }
}
```
[1994D - Funny Game](https://codeforces.com/contest/1994/problem/D)

 **Hint**Pigeonhole principle

 **Editorial**Tutorial is loading... **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& i : a) cin >> i;
        vector<int> pos(n);
        iota(pos.begin(), pos.end(), 0);
        vector<pair<int, int>> ans;
        for (int i = n - 1; i; --i) {
            vector<int> occ(i, -1);
            for (auto j : pos) {
                if (occ[a[j] % i] != -1) {
                    ans.emplace_back(j, occ[a[j] % i]);
                    pos.erase(find(pos.begin(), pos.end(), j));
                    break;
                }
                occ[a[j] % i] = j;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << "YESn";
        for (auto [x, y] : ans) cout << x + 1 << ' ' << y + 1 << 'n';
    }
}
```
[1994E - Wooden Game](https://codeforces.com/contest/1994/problem/E)

 **Hint**Solve for one tree

 **Hint.answer**Answer is size of tree

 **Hint.proof**Let sizes of deleted subtrees be a1,a2,…am. We know that a1+a2+…+am=n. Then we know that a1|a2…am≤n. To proof that lets see bits separately. It will add 1 to result, if one of bits is 1, 0 otherwise, but this is not more than their sum.

 **Editorial**
### [1994E - Wooden Game](https://codeforces.com/contest/1994/problem/E "Codeforces Round 959 sponsored by NEAR (Div. 1 + Div. 2)")

We know that the maximal result from one tree is the size of this tree (see hints), but we can make every number from 1 to the size of the tree. To do that, we can delete leaves until we have the needed value.

So the remaining problem is to find the maximal OR if we can choose numbers from 1 to ai. For every bit, let's count the number of ai, where this bit is set. Find the highest bit which is set in more than one number. Obviously, we can make a suffix of 1-s from this position. Before this position we need to set bits that are set in one of ai.

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int k;
    cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        for (int j = 0; j < a[i] - 1; ++j) {
            int trash;
            cin >> trash;
        }
    }
    sort(a.begin(), a.end(), greater<>());
    int ans = 0;
    for (auto x : a) {
        for (int h = 23; h >= 0; --h) {
            int ca = ans >> h & 1, cx = x >> h & 1;
            if (cx == 0) continue;
            if (ca == 0) ans |= 1 << h;
            else {
                ans |= (1 << h) - 1;
                break;
            }
        }
    }
    cout << ans << 'n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
```
[1994F - Stardew Valley](https://codeforces.com/contest/1994/problem/F)

 **Editorial**Tutorial is loading... **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> black(n);
        vector<int> edg(m);
        vector<vector<int>> g(n);
        for (int i = 0; i < m; ++i) {
            int x, y, c;
            cin >> x >> y >> c;
            --x, --y;
            edg[i] = x ^ y;
            g[x].push_back(i);
            g[y].push_back(i);
            if (c == 0) {
                black[x].push_back(i);
                black[y].push_back(i);
            }
        }
        vector<int> deg(n);
        for (int i = 0; i < n; ++i) deg[i] = g[i].size() & 1;
        vector<bool> del(m, false), used(n, false);
        auto dfs = [&](auto dfs, int u) -> void {
            used[u] = true;
            for (auto id : black[u]) {
                int to = edg[id] ^ u;
                if (used[to]) continue;
                dfs(dfs, to);
                if (deg[to]) {
                    del[id] = true;
                    deg[to] ^= 1;
                    deg[u] ^= 1;
                }
            }
        };
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            dfs(dfs, i);
            ok &= !deg[i];
        }
        if (!ok) {
            cout << "NOn";
            continue;
        }
        auto euler = [&](auto euler, int u) -> void {
            while (!g[u].empty()) {
                int id = g[u].back();
                g[u].pop_back();
                int to = edg[id] ^ u;
                if (del[id]) continue;
                del[id] = true;
                euler(euler, to);
            }
            cout << u + 1 << ' ';
        };
        cout << "YESn";
        cout << m - accumulate(del.begin(), del.end(), 0) << 'n';
        euler(euler, 0);
        cout << 'n';
    }
}
```
[1994G - Minecraft](https://codeforces.com/contest/1994/problem/G)

 **Hint 1**Think of the most stupid solution you can do

 **Hint 2**Do memorization and some cuts

 **Hint 3**Done!

 **Editorial**
### [1994G - Minecraft](https://codeforces.com/contest/1994/problem/G "Codeforces Round 959 sponsored by NEAR (Div. 1 + Div. 2)")

We will do recursion. Let's go from the lower bits to the significant bits. 

rec(i,sum) means that the first i bits are selected, the sum of them divided by 2i equals sum, and the first i bits match the ones we need. Let cnti — the number of ones in the numbers in the i-th bit. Then we can go from state (i,sum) to (i+1,⌊sum+cnti2⌋) and (i+1,⌊sum+n−cnti2⌋) if the lowest bit matches the i-th bit in s. There are at most nk states in such a recursion (proof below). Thus, if we do the memoization, the solution will run O(nk).

Proof:

sum is always at most n. At the beginning of the recursion, sum=0, so the inequality is satisfied. When we go to the next step sum+cnti2, sum+n−cnti2≤n+n2=n, which was required to prove.

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<vector<bool>> memo;
string res;
vector<int> cnt;
string s;

bool rec(int i, int cur) {
    if (i == k) {
        if (cur == 0) {
            return true;
        }
        return false;
    }
    if (memo[i][cur]) return false;
    memo[i][cur] = true;
    for (int c = 0; c < 2; ++c) {
        int q = cur;
        if (c == 0) q += cnt[i];
        else q += n - cnt[i];
        if ((q & 1) == s[i] - '0') {
            if (rec(i + 1, q / 2)) {
                res += char(c + '0');
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    while (tests--) {
        cin >> n >> k;
        cin >> s;
        reverse(s.begin(), s.end());
        cnt = vector<int>(k);
        for (int i = 0; i < n; ++i) {
            string t;
            cin >> t;
            reverse(t.begin(), t.end());
            for (int j = 0; j < k; ++j) cnt[j] += t[j] - '0';
        }
        memo = vector<vector<bool>>(k, vector<bool>(n, false));
        res = "";
        rec(0, 0);
        if (res.empty()) cout << "-1n";
        else cout << res << 'n';
    }
}
```
[1994H - Fortnite](https://codeforces.com/contest/1994/problem/H)

 **Editorial**
### [1994H - Fortnite](https://codeforces.com/contest/1994/problem/H "Codeforces Round 959 sponsored by NEAR (Div. 1 + Div. 2)")

The first query is aa, it can be used to find out p. 

The second query is zzzzzzzzzz, let's calculate its hash without modulus, denote h_1, hash with modulus denote a1. Suppose we get a string with hash without modulus from h1−a1−m to h1−a1−1, then if we query it, we can easily find out the modulus. 

Let's find such a string. To do this, let's write h1 in p-ary number system, we get 26,26,....26, and also write (a1+1) in p-ary notation. Subtract the second one from the first one without transfers, take the leftmost position, where we get <1, and put there and in all the left 26, as long as the number on the left is 1, put 26 in it and stand in it, when the number on the left is not 1, we just subtract 1 from it. After that we translate it all back into a string.

 It is claimed that this string fits, let's prove it. Its hash without modulus is obviously not greater than h1−a1−1. Let's consider 2 digits, the one in which we made −1 and 1 to the left, let the number of the left digit i, then a1+1≥25∗pi, and we subtracted less than pi+1−25∗pi, less because either in i that digit was 0, or 0 was somewhere to the left, so there could be no equality, p≤50 by convention, ≥pi+1−25∗pi≤50∗pi−25∗pi=25∗pi≤a1+1 => we subtracted less than a1+1 => not more than a1 => less than m. Let's denote what we subtracted by x, then our hash is h1−a1−1−x=h1−a1−(x+1). x<m => x+1≤m => hash≥h1−a1−m, which is what we needed to prove. 

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    cout << "? aa" << endl;
    int p, v[10];
    cin >> p; p--;
    cout << "? zzzzzzzzzz" << endl;
    int hsh, hsho;
    ll nom = 0, cnt = 1;
    cin >> hsh;
    hsho = hsh;
    hsh++;
    for (int i = 0; i < 10; i++) {
        nom += 26 * cnt;
        cnt *= p;
        v[i] = 26 - (hsh % p);
        hsh /= p;
    }
    string s;
    cnt = 1;
    ll ch = 0;
    for (int i = 0; i < 10; i++) {
        if (v[i] < 1) {
            v[i] = 26;
            v[i + 1]--;
        }
        ch += cnt * v[i];
        cnt *= p;
        s += 'a' + (v[i] - 1);
    }
    cout << "? " << s << endl;
    int ans;
    cin >> ans;
    cout << "! " << p << ' ' << ans + nom - ch - hsho << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
