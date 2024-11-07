# Tutorial_(en)

We hope you liked our problems!

[1858A - Buttons](../problems/A._Buttons.md "Codeforces Round 893 (Div. 2)")

 **Tutorial**
### [1858A - Buttons](../problems/A._Buttons.md "Codeforces Round 893 (Div. 2)")

On each turn, the current player gets rid of one of the buttons available to them. At the same time, if you press the "common" button, the enemy will not be able to press it as well. Since each player wants to leave their opponent without buttons to press before they run out of those themselves, they will click on the "common" buttons as long as there is at least one available.

The number of the player who clicks on their (not the general) button first depends on c. It can be noticed that this player will win if and only if they have strictly more buttons than their opponent.

 **Code**
```cpp
t = int(input())
for i in range(t):
    a, b, c = map(int, input().split())
    if c % 2 == 0:
        if a > b:
            print("First")
        else:
            print("Second")
    else:
        if b > a:
            print("Second")
        else:
            print("First")
```
[1858B - The Walkway](../problems/B._The_Walkway.md "Codeforces Round 893 (Div. 2)")

 **Tutorial**
### [1858B - The Walkway](../problems/B._The_Walkway.md "Codeforces Round 893 (Div. 2)")

First, let's calculate how many cookies Petya will eat if we don't remove the cookie sellers at all (we will later refer to this value as res). Note that since the cookie sellers reset the time elapsed since the last eaten cookie, the number of cookies eaten on all segments between adjacent cookie sellers are counted independently. Therefore, we can easily calculate res: let's iterate through the cookie sellers from 1 to m−1. For each of them, we should add the number (⌊si+1−si−1d⌋+1) to res. We should also carefully take into account the cookies that Petya will eat on the segments [1;s1−1] and [sm,n] (it might help to assume that there are two more cookie sellers at positions 1−d and n+1). 

In order to find the minimum possible number of cookies eaten by Petya, we will fix the cookie seller that we remove. Let it be the cookie seller i. Then the number of cookies eaten by Petya will be res−⌊si−si−1−1d⌋−⌊si+1−si−1d⌋+⌊si+1−si−1−1d⌋−1 (for the first and last cookie sellers, the formulas may differ slightly). Thus, we can find the number of cookies that Petya will eat if a certain cookie seller is removed in O(1). After going through all m options, we will be able to find the answer to the problem.

The final complexity of the solution is O(m) (because array s is sorted in the input).

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

int solve(int d, vector<int> x)
{
    int ans = 0;
    for (int i = 1; i < x.size(); i++)
    {
        ans += (x[i] - x[i - 1] - 1) / d;
    }
    ans += int(x.size()) - 2;
    return ans;
}

void solve()
{
    #define tests

    int n, m, d;
    cin >> n >> m >> d;
    vector<int> r(m);
    for (int i = 0; i < m; i++) cin >> r[i];
    r.insert(r.begin(), 1 - d);
    r.push_back(n + 1);

    int ans = 2e9;
    vector<int> res;
    for (int i = 1; i <= m; i++)
    {
        int A = r[i] - r[i - 1] - 1;
        int B = r[i + 1] - r[i] - 1;
        int C = r[i + 1] - r[i - 1] - 1;
        int D = C / d - (A / d + B / d);
        if (D < ans)
        {
            ans = D;
            res.clear();
        }
        if (D == ans)
        {
            res.push_back(r[i]);
        }
    }
    cout << ans + solve(d, r) - 1 << ' ' << res.size() << endl;
}

int main()
{
    int t = 1;
    #ifdef tests
    cin >> t;
    #endif
    while (t--)
    {
        solve();
    }
}
```
[1858C - Yet Another Permutation Problem](../problems/C._Yet_Another_Permutation_Problem.md "Codeforces Round 893 (Div. 2)")

 **Tutorial**
### [1858C - Yet Another Permutation Problem](../problems/C._Yet_Another_Permutation_Problem.md "Codeforces Round 893 (Div. 2)")

It is impossible to get di=gcd(ai,a(imodn)+1)>⌊n2⌋: otherwise, at least one of the numbers in a would be divisible by di and would be greater than di at the same time, so it would be at least 2⋅di, which is greater than n. Therefore, the maximum possible score is no more than ⌊n2⌋. Actually, we can always get a score equal to ⌊n2⌋.

How do we get such score? Let's set a1=1. After that, we put the powers of 2 less or equal n sequentially. Then we put 3 and powers of 2 multiplied by 3, then 5 and so on (for example, for n=12, we will get an array a=[1,2,4,8,3,6,12,5,10,7,9,11]). Then, for each number ai=x≤⌊n2⌋, the next number will be a(imodn)+1=x⋅2≤n. Their gcd will be exactly x, so there will be a pair of adjacent elements of a with greatest common divisor equal to x for all 1≤x≤⌊n2⌋.

 **Code**
```cpp
#include<iostream>
#include<vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int cur = 0;
        for (int i = 1; i <= n; i += 2) {
            for (int j = i; j <= n; j *= 2) {
                a[cur++] = j;
            }
        }
        for (int i = 0; i<n; ++i) {
            cout << a[i] << " ";
        }
        cout << 'n';
    }
    return 0;
}
```
[1858D - Trees and Segments](../problems/D._Trees_and_Segments.md "Codeforces Round 893 (Div. 2)")

 **Tutorial**
### [1858D - Trees and Segments](../problems/D._Trees_and_Segments.md "Codeforces Round 893 (Div. 2)")

There are many various dynamic programming solutions of this problem. We will describe one of them. Let's calculate the dynamics prefi, j = the length of the longest subsegment of zeros that can be obtained on the prefix up to i, which ends at index i and costs exactly j operations. Similarly, sufi, j is the length of the longest subsegment of zeros on the suffix starting at i, which starts at index i and costs exactly j operations. Such dynamics can be easily computed: prefi, j={prefi−1, j+1ifsi=0prefi−1, j−1+1ifsi=1andj>00otherwise In the first case, we simply prolong the existing subsegment of zeros, in the second case, we change the current 1 to 0, spending one operation on it (so if have 0 operations left (j=0), we cannot do anything and the value of the dynamics is 0, meaning the segment has ended). sufi,j can be calculated similarly. Let's update both dynamics in such a way that prefi,j will mean the maximum length of a subsegment of zeros that ends no later than i and costs no more than j operations. This can be easily done by updating prefi,j with the value of prefi−1,j, and then with prefi,j−1. Similarly, we update the second dynamics. 

Now let's consider a subsegment [l, r] that we want to convert into a segment of ones. We can easily calculate the number of operations x that we will need (we'll just need to calculate the number of zeros in such a segment). Now, calculate the new dynamics dplen for the length len=r−l+1 of the segment of ones, which equals the maximum length of a subsegment of zeros that we can obtain. Update this value with max(prefl−1,k−x,sufr+1,k−x). 

Then, to answer the question for a fixed number a, we can iterate over the length len of the segment of ones that will be in our answer and update the answer with the value a⋅dplen+len, if there exists a value for len in the dynamics dp. 

The complexity is O(nk+n2). Solutions with complexity O(nklogn) and O(nk) using various optimizations of the dynamics (convex hull trick, D&C) also exist.

 **Code**
```cpp
#include <bits/stdc++.h>

#define int long long

using namespace std;
using ll = long long;

void solve();

template<typename ...Args>
void println(Args... args) {
    apply([](auto &&... args) { ((cout << args << ' '), ...); }, tuple(args...));
    cout << 'n';
}

int32_t main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        solve();
    }
    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> max0by1(n + 1, -1e9);
    vector<vector<int>> max0pref(n + 1, vector<int>(n + 1));
    vector<vector<int>> max0suf(n + 1, vector<int>(n + 1));
    for (int l = 0; l < n; ++l) {
        int cnt1 = 0;
        for (int r = l + 1; r <= n; ++r) {
            cnt1 += s[r - 1] == '1';
            max0pref[r][cnt1] = max(max0pref[r][cnt1], r - l);
            max0suf[l][cnt1] = max(max0suf[l][cnt1], r - l);
        }
    }
    for (int r = 0; r <= n; ++r) {
        for (int cnt = 0; cnt <= n; ++cnt) {
            if (r) max0pref[r][cnt] = max(max0pref[r][cnt], max0pref[r - 1][cnt]);
            if (cnt) max0pref[r][cnt] = max(max0pref[r][cnt], max0pref[r][cnt - 1]);
        }
    }
    for (int l = n; l >= 0; --l) {
        for (int cnt = 0; cnt <= n; ++cnt) {
            if (l + 1 <= n) max0suf[l][cnt] = max(max0suf[l][cnt], max0suf[l + 1][cnt]);
            if (cnt) max0suf[l][cnt] = max(max0suf[l][cnt], max0suf[l][cnt - 1]);
        }
    }
    vector<int> ans(n + 1, -1e9);
    for (int l = 0; l < n; ++l) {
        int cnt0 = 0;
        for (int r = l; r <= n; ++r) {
            if (r > l) cnt0 += s[r - 1] == '0';
            if (cnt0 > k) break;
            max0by1[r - l] = max(max0by1[r - l], max0pref[l][k - cnt0]);
            max0by1[r - l] = max(max0by1[r - l], max0suf[r][k - cnt0]);
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int a = 1; a <= n; ++a) ans[a] = max(ans[a], i + max0by1[i] * a);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << 'n';
}
```
[1858E2 - Rollbacks (Hard Version)](../problems/E2._Rollbacks_(Hard_Version).md "Codeforces Round 893 (Div. 2)")

 **Tutorial**
### [1858E2 - Rollbacks (Hard Version)](../problems/E2._Rollbacks_(Hard_Version).md "Codeforces Round 893 (Div. 2)")

First, let's learn how to solve the problem without rollbacks. Let b be an array of the same length as a, where bi=1 if i is the minimum position at which the number ai is in the array a, and bi=0 otherwise. Then the number of different numbers in the array a is equal to the sum of all the elements of the array b.

The b array can be maintained using a Fenwick tree, a segment tree, or any other data structure that supports point updates and range sum queries. The author's solution uses the Fenwick tree. 

Let's use the method that is often used when implementing a stack or a deque: we create a large array A and at each moment we store the index of the last "existing" element r (this is just the size of the array a at this moment). The array a itself will be a prefix of A, that is, ai=Ai for i≤len(a). Also, for each value val we maintain std::set of indexes on which the val value is located in the A array (in A, not in a).

Then for the operation of removing k elements from the end of the array a, it is enough to reduce the value of the index r by k. This operation works in O(1).

When adding one element x to the end of the array, we need to check if it has been encountered before, and change one element in the Fenwick tree accordingly. This can be done in O(logq) using std::set for the corresponding value. You also need to increase r by 1, assign Ar=x after that, and update the corresponding std::set. This operation works for O(logq).

In order to find the number of different numbers in a, we need to find the sum in the Fenwick tree on the prefix of length r in the array b. This operation works in O(logq).

Now, we need to learn how to roll back operations. Note that we perform the deletion operation in O(1), and the addition operation in O(logq), so we can roll back these operations with the same asymptotics. We can just store a stack of all changes, and remember everything that we changed during the operations.

The final asymptotics is O(qlogq).

 **Code**
```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

const int maxn = 1e6 + 1;

int f[maxn];

int get(int i) {
    int ans = 0;
    while (i >= 0) {
        ans += f[i];
        i = (i & (i + 1)) - 1;
    }
    return ans;
}

void upd(int i, int x) {
    while (i < maxn) {
        f[i] += x;
        i = i | (i + 1);
    }
}

int a[maxn];
int rev[maxn];
set<int> ids[maxn];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill(rev, rev + maxn, -1);
    fill(a, a + maxn, -1);
    int q;
    cin >> q;
    int ptr = -1;
    vector<pair<pair<int, int>, int>> changes;
    while (q--) {
        char t;
        cin >> t;
        if (t == '?') {
            cout << get(ptr) << endl;
        } else if (t == '+') {
            int x;
            cin >> x;
            int mem = a[ptr + 1];
            if (a[ptr + 1] != -1) {
                if (ids[a[ptr + 1]].size()) {
                    upd(*ids[a[ptr + 1]].begin(), -1);
                    ids[a[ptr + 1]].erase(ptr + 1);
                }
                if (ids[a[ptr + 1]].size()) {
                    upd(*ids[a[ptr + 1]].begin(), 1);
                }
            }
            a[ptr + 1] = x;
            if (a[ptr + 1] != -1) {
                if (ids[a[ptr + 1]].size()) {
                    upd(*ids[a[ptr + 1]].begin(), -1);
                }
                ids[x].insert(ptr + 1);
                if (ids[a[ptr + 1]].size()) {
                    upd(*ids[a[ptr + 1]].begin(), 1);
                }
            }
            ++ptr;
            changes.push_back({ { 1, mem }, -1 });
        } else if (t == '-') {
            int k;
            cin >> k;
            ptr -= k;
            changes.push_back({ { -1, k }, -1 });
        } else {
            if (changes.back().first.first == 1) {
                if (a[ptr] != -1) {
                    if (ids[a[ptr]].size()) {
                        upd(*ids[a[ptr]].begin(), -1);
                        ids[a[ptr]].erase(ptr);
                    }
                    if (ids[a[ptr]].size()) {
                        upd(*ids[a[ptr]].begin(), 1);
                    }
                }
                a[ptr] = changes.back().first.second;
                --ptr;
                if (a[ptr + 1] != -1) {
                    if (ids[a[ptr + 1]].size()) {
                        upd(*ids[a[ptr + 1]].begin(), -1);
                    }
                    ids[a[ptr + 1]].insert(ptr + 1);
                    if (ids[a[ptr + 1]].size()) {
                        upd(*ids[a[ptr + 1]].begin(), 1);
                    }
                }
            } else {
                ptr += changes.back().first.second;
            }
            changes.pop_back();
        }
    }
}
```
**Note:** At about 20 minutes into the round one of our testers ([SomethingNew](https://codeforces.com/profile/SomethingNew "Grandmaster SomethingNew")) came up with a linear solution for problem E2, and [jiangly](https://codeforces.com/profile/jiangly "Legendary Grandmaster jiangly") implemented the same solution shortly after the contest! For further details, see [219001999](https://codeforces.com/contest/1858/submission/219001999 "Submission 219001999 by jiangly"). The main idea (as [jiangly](https://codeforces.com/profile/jiangly "Legendary Grandmaster jiangly") pointed out in the comments) is that we can use prefix sums instead of the Fenwick tree.

