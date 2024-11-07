# Tutorial_1

[1418A - Buying Torches](../problems/A._Buying_Torches.md "Educational Codeforces Round 95 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1418A - Buying Torches](../problems/A._Buying_Torches.md "Educational Codeforces Round 95 (Rated for Div. 2)")

You need $s = yk + k - 1$ additional sticks to get $k$ torches ($yk$ sticks for $y$ units of coal and also $k$ sticks required to craft torches) and you get $x-1$ sticks per one trade. To buy this number of sticks, you need $\left\lceil\frac{s}{x-1}\right\rceil$ trades. And also, you need $k$ additional trades to turn some sticks into coals. And the final answer is $\left\lceil\frac{s}{x-1}\right\rceil + k$.

 **Solution (vovuh)**
```cpp
for i in range(int(input())):
    x, y, k = map(int, input().split())
    print(((y + 1) * k - 1 + x - 2) // (x - 1) + k)
```
[1418B - Negative Prefixes](../problems/B._Negative_Prefixes.md "Educational Codeforces Round 95 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1418B - Negative Prefixes](../problems/B._Negative_Prefixes.md "Educational Codeforces Round 95 (Rated for Div. 2)")

Let's collect the prefix sums of the initial array $a$. How do they change if you swap two values in the array? Let's swap values on positions $l$ and $r$ ($l < r$). Prefix sums from $1$ to $l-1$ aren't changed. Prefix sums from $l$ to $r-1$ are increased by $a_r-a_l$ (note that if $a_l>a_r$ then these sums become smaller). Finally, prefix sums from $r$ to $n$ aren't changed as well.

Thus, swapping two values $a_l<a_r$ will only increase some prefix sums but never decrease any of them.

That helps us see that the array such that all values on the unlocked positions are sorted in a non-increasing order is the most optimal one. 

Overall complexity: $O(n \log n)$ per testcase.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c;
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    forn(i, n) if (!b[i])
        c.push_back(a[i]);
    sort(c.rbegin(), c.rend());
    int j = 0;
    forn(i, n) {
        if (b[i]) cout << a[i] << ' ';
        else cout << c[j++] << ' ';
    }
    cout << 'n';
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
```
[1418C - Mortal Kombat Tower](../problems/C._Mortal_Kombat_Tower.md "Educational Codeforces Round 95 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1418C - Mortal Kombat Tower](../problems/C._Mortal_Kombat_Tower.md "Educational Codeforces Round 95 (Rated for Div. 2)")

If $a_1 = 1$ then our friend always needs one skip point because he always has to kill the first boss. Let's just remove this boss from our consideration and increase the answer if needed.

What about other skip points? Firstly, let's understand that we can always do our moves in such a way that the first hard boss will always be killed by us (except the first one). So, if it's our friend turn now and there is only one easy boss before the hard, our friend just kills this easy boss. If there are two easy bosses, he kills both. If there are three, friend kills the first, we kill the second, and he kills the third. And so on. So we can always assume that each segment of hard bosses starts with our move.

We can kill each such segment greedily: we kill two bosses and our friend kills one. If there are less than three bosses in the segment, we just kill remaining and proceed. So if the length of the current segment of hard bosses is $k$ then we need $\left\lfloor\frac{k}{3}\right\rfloor$ skip points. Summing up these values over all segments we get the answer (and don't forget that the first boss should be handled separately). Segments of ones can be extracted using two pointers.

There are also dynamic programming solution but I found this one more clever.

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it : a) cin >> it;
        int ans = 0;
        ans += a[0] == 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] == 0) {
                continue;
            }
            int j = i;
            while (j < n && a[j] == 1) {
                ++j;
            }
            ans += (j - i) / 3;
            i = j - 1;
        }
        cout << ans << endl;
    }
    
    return 0;
}
```
[1418D - Trash Problem](../problems/D._Trash_Problem.md "Educational Codeforces Round 95 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1418D - Trash Problem](../problems/D._Trash_Problem.md "Educational Codeforces Round 95 (Rated for Div. 2)")

First, let's understand that if we choose some subset of points $x_1, x_2, \dots, x_k$, then it does not matter to which point we move it (inside the segment [$\min(x_1, x_2, \dots, x_k); \max(x_1, x_2, \dots, x_k)]$) because the minimum number of moves will always be the same and it is equal to $\max(x_1, x_2, \dots, x_k) - \min(x_1, x_2, \dots, x_k)$.

Okay, we need to split all points into two subsets and collect all points of the first subset in some point inside it and the same with the second subset. What can we notice? If we sort the points, it's always optimal to choose these subsets as segments. I.e. if the maximum point of the first subset is $x_r$, the minimum point of the second subset is $x_l$ and $x_l < x_r$, we can swap them and decrease answers for both subsets.

So, we need to cover all the points with two segments with the minimum total length. What is this length? It is $x_n - x_1 - maxGap$. $MaxGap$ is the maximum distance between two consecutive points (i.e. $max(x_2 - x_1, x_3 - x_2, \dots, x_n - x_{n-1})$. So, we can solve the problem in $O(n \log{n})$ without queries. But how to deal with queries?

Let's maintain the set which contains all points $x_i$ and the multiset (set with repetitions) that maintains all gaps between two adjacent points. So, the answer is maximum in the set of points minus minimum in the set of points minus maximum in the multiset of lengths. How do we recalculate these sets between queries?

If some point $x$ is removed, let's find the maximum point less than $x$ (let it be $x_l$) and the minimum point greater than $x$ (let it be $x_r$) in the current set of points. Both these points can be found in a logarithmic time. Then we need to remove $x - x_l$ with $x_r - x$ from the multiset and add $x_r - x_l$ to the multiset (and, of course, remove $x$ from the set). If some point $x$ is added, then we need to remove $x_r - x_l$ from the multiset and add $x - x_l$ with $x_r - x$ to the multiset (and add $x$ to the set).

So, we can process every query in $O(\log{n + q})$ time and the total time complexity is $O((n+q) \log{(n + q)})$.

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int get(const set<int> &x, const multiset<int> &len) {
    if (len.empty()) return 0;
    return *x.rbegin() - *x.begin() - *len.rbegin();
}

void add(int p, set<int> &x, multiset<int> &len) {
    x.insert(p);
    auto it = x.find(p);
    int prv = -1, nxt = -1;
    if (it != x.begin()) {
        --it;
        len.insert(p - *it);
        prv = *it;
        ++it;
    }
    ++it;
    if (it != x.end()) {
        len.insert(*it - p);
        nxt = *it;
    }
    if (prv != -1 && nxt != -1) {
        len.erase(len.find(nxt - prv));
    }
}

void rem(int p, set<int> &x, multiset<int> &len) {
    auto it = x.find(p);
    int prv = -1, nxt = -1;
    if (it != x.begin()) {
        --it;
        len.erase(len.find(p - *it));
        prv = *it;
        ++it;
    }
    ++it;
    if (it != x.end()) {
        len.erase(len.find(*it - p));
        nxt = *it;
    }
    x.erase(p);
    if (prv != -1 && nxt != -1) {
        len.insert(nxt - prv);
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int n, q;
    cin >> n >> q;
    set<int> x;
    multiset<int> len;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        add(p, x, len);
    }
    
    cout << get(x, len) << endl;
    for (int i = 0; i < q; ++i) {
        int t, p;
        cin >> t >> p;
        if (t == 0) {
            rem(p, x, len);
        } else {
            add(p, x, len);
        }
        cout << get(x, len) << endl;
    }
    
    return 0;
}
```
[1418E - Expected Damage](../problems/E._Expected_Damage.md "Educational Codeforces Round 95 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1418E - Expected Damage](../problems/E._Expected_Damage.md "Educational Codeforces Round 95 (Rated for Div. 2)")

First of all, let's find a solution in $O(nm)$. We will use the lineriality of expectation: the answer for some shield $j$ is equal to $\sum\limits_{i = 1}^{n} d_i P(i, j)$, where $P(i, j)$ is the probability that the monster $i$ will deal damage if we use the $j$-th shield. Let's see how to calculate $P(i, j)$.

Consider a monster $i$ such that $d_i \ge b_j$. To deal damage, he should be preceded by at least $a_j$ other monsters having $d_i \ge b_j$. We can write a complicated formula with binomial coefficients to calculate the probability of this happening, and then simplify it, but a much easier solution is to consider the order of these "strong" monsters. Suppose there are $k$ of them, then there are $\max(k - a_j, 0)$ strong monsters that will deal damage. Since all orderings are equiprobable, the probability that our fixed monster will deal damage is $\dfrac{\max(k - a_j, 0)}{k}$ — since it is the probability that it will take one of the last places in the order.

Okay, what about "weak" monsters? It turns out that we can use the same approach: to deal damage, a weak monster should be preceded by at least $a_j$ strong monsters. Consider the relative order of $k$ strong monsters and that weak monster we are analyzing. There are $\max(k + 1 - a_j, 0)$ positions where the weak monster will deal damage, so the probability of weak monster dealing damage is $\dfrac{\max(k + 1 - a_j, 0)}{k + 1}$.

Okay, we got a solution in $O(nm)$. How to make it faster? Whenever we consider a shield, all monsters are split into two types: strong and weak, and we may sort the monsters beforehand, so the number of strong monsters (and their total strength) can be found with binary search. Since the probabilities for all strong monsters are the same, we can multiply their total strength by the probability that one fixed strong monster will deal damage (we already described how to calculate it). The same applies for the weak monsters, so the total complexity is $O(n \log n + m (\log n + \log MOD))$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 9;
const int MOD = 998244353;

int mul(int a, int b) {
    return (a * 1LL * b) % MOD;
}

int bp(int a, int n) {
    int res = 1;
    for (; n > 0; n /= 2) {
        if (n & 1) res = mul(res, a);
        a = mul(a, a);
    }
    
    return res;
}

int inv(int a) {
    int ia = bp(a, MOD - 2);
    assert(mul(a, ia) == 1);
    return ia;
}

int n, m;
int d[N];
long long sd[N];

long long sum (int l, int r) {
    return (sd[r] - sd[l]) % MOD;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        scanf("%d", d + i);
    sort(d, d + n);
    for (int i = 0; i < n; ++i)
        sd[i + 1] = sd[i] + d[i];
        
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b); // dur, def
        int cnt = (d + n) - lower_bound(d, d + n, b);
        int res = 0;
        if (cnt >= a) {
            res = mul( mul(cnt - a, inv(cnt)), sum(n - cnt, n) );
            res += mul( mul(cnt - a + 1, inv(cnt + 1)), sum(0, n - cnt) );
            res %= MOD;
        }
        printf("%dn", res);
    }
    
    return 0;
}
```
[1418F - Equal Product](../problems/F._Equal_Product.md "Educational Codeforces Round 95 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1418F - Equal Product](../problems/F._Equal_Product.md "Educational Codeforces Round 95 (Rated for Div. 2)")

Let's look at $x_1 y_1 = x_2 y_2$ where $x_1 < x_2$. It can be proven that there always exists such pair $(a, b)$ ($a \mid x_1$, $b \mid y_1$ and $a < b$) that $x_2 = \frac{x_1}{a} b$ and $y_2 = \frac{y_1}{b} a$.

Brief proof is following: calculate $g = \gcd(x_1, x_2)$, then let $a = \frac{x_1}{g}$ and $b = \frac{x_2}{g}$. Obviously, such $(a, b)$ will make $x_2$ from $x_1$ and $y_2$ from $y_1$ (if $b \mid y_1$). And since $b = \frac{x_2}{g} \Rightarrow$ $b \mid \frac{x_2 y_2}{g} \Rightarrow$ $b \mid \frac{x_1 y_1}{g} \Rightarrow$ $b \mid \frac{x_1}{g} y_1$ and since $\gcd(b, \frac{x_1}{g}) = 1 \Rightarrow$ $b \mid y_1$.

As we can see $a$ divides $x_1$, so if we will iterate over all pairs $(x_1, a)$ where $1 \le x_1 \le n$ there will be $O(n \log n)$ pairs in total.

Let's fix value of $x_1$. Then, from one side, $y_1 \le m$ but, from the other side, since $l \le x_1 y_1 \le r$, then $\left\lceil \frac{l}{x_1} \right\rceil \le y_1 \le \left\lfloor \frac{r}{x_1} \right\rfloor$. Anyway, all valid $y_1$ form a segment (possibly, empty segment). And we need to find any $b > a$ that divides any $y_1$ from the segment and $x_2 = \frac{x_1}{a} b$ doesn't exceed $n$. Obviously, it's optimally to find the minimum possible such $b$ and just check inequality $\frac{x_1}{a} b \le n$.

We can find such $b$ for a fixed $(x_1, a)$ using, for example, built-in upper_bound in a set with all divisors for all valid $y_1$. To maintain this set we can note that $\frac{l}{x_1 + 1} \le \frac{l}{x_1}$ (simillary, $\frac{r}{x_1 + 1} \le \frac{r}{x_1}$). So we can move valid segment's ends as two pointers.

Each pair $(y_1, b)$ will be added and erased from the segment exactly once. That's why the total complexity of maintaining the set of divisors (as well as the total complexity of queries for each $(x_1, a)$) will be equal to $O((n + m) \log^2 (n + m))$.

All pairs $(x_1, a)$ (and $(y_1, b)$) can be precalculated in $O((n + m) \log (n + m))$ using the sieve-like algorithm.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    out << "[";
    fore(i, 0, sz(v)) {
        if(i) out << ", ";
        out << v[i];
    }
    return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);

int n, m;
li l, r;

inline bool read() {
    if(!(cin >> n >> m))
        return false;
    cin >> l >> r;
    return true;
}

const int N = int(2e5) + 555;
vector<int> divs[N];

inline void solve() {
    fore(d, 1, N) {
        for(int pos = d; pos < N; pos += d)
            divs[pos].push_back(d);
    }
    
    li lf = m + 1, rg = m;
    vector<int> cnt(m + 1, 0);
    vector<int> id(m + 1, -1);
    set<int> curDivs;
    
    vector< vector<int> > ans(n + 1);
    
    fore(x1, 1, n + 1) {
        li newlf = (l + x1 - 1) / x1;
        li newrg = r / x1;
        assert(newrg - newlf + 1 >= 0);
        
        while (lf > newlf) {
            lf--;
            for (int d : divs[lf]) {
                if (cnt[d] == 0)
                    curDivs.insert(d);
                cnt[d]++;
                id[d] = (int)lf;
            }
        }
        while (rg > newrg) {
            for (int d : divs[rg]) {
                cnt[d]--;
                if (cnt[d] == 0)
                    curDivs.erase(d);
            }
            rg--;
        }
        
        for (int a : divs[x1]) {
            auto it = curDivs.upper_bound(a);
            if (it == curDivs.end())
                continue;
            
            int b = *it;
            if (x1 / a * 1ll * b <= n) {
                int y1 = id[b];
                
                ans[x1] = {x1, y1, x1 / a * b, y1 / b * a};
            }
        }
    }
    
    fore(i, 1, n + 1) {
        if (ans[i].empty())
            cout << -1 << 'n';
        else {
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << 'n';
        }
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    
    if(read()) {
        solve();
        
#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}
```
[1418G - Three Occurrences](../problems/G._Three_Occurrences.md "Educational Codeforces Round 95 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest") and [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1418G - Three Occurrences](../problems/G._Three_Occurrences.md "Educational Codeforces Round 95 (Rated for Div. 2)")

Let's consider two solutions: a non-deterministic and a deterministic one.

The random solution goes like that.

Let's assign a random integer to each value from $1$ to $n$ (to value, not to a position). Let the value of the subarray be the trit-wise sum of the assigned integers of all values on it. Trit-wise is the analogue of bit-wise sum (xor) but in ternary system. So adding up the same integer three times trit-wise is always equal to zero. Thus, if the value on a subarray is zero then each value appears on it a multiple of three times. How to count the number of such subarrays? Process the array from left to right and store the prefix trit-wise sums in a map. The number of the valid subarrays that end in the current position is the number of occurrences of the current prefix trit-wise sum in a map. The current sum should be added to the map afterwards.

However, that's not what the problem asks us to find. Let's consider another problem: count the number of subarray such that each number appears no more than three times. This can be done with two pointers. Process the array from left to right and for each number store the positions it occurred on. If some number appears at least four times than the left pointer should be moved to the next position after the fourth-to-last position. The number of valid subarrays the end in the current position is the distance to the left pointer.

Let's combine these problems: maintain the pointer to only the valid positions and remove the prefix trit-wise sums from the map as you increase the pointer. That way the map will only store the valid sums, and they can be added to answer as they are.

Assume you use $K$ trits. I guess the probability of the collision is the same as two vectors (out of $n$) colliding in a $K$-dimensional space with their coordinates being from $0$ to $2$. That will be about $\frac{1}{2}$ when $n \approx \sqrt{3^K}$ (according to birthday paradox) — and way less if we increase $K$.

Overall complexity: $O(nK \log n)$.

The deterministic solution (a.k.a. the boring one) goes like that.

Let's again process the array from left to right. Let the current position be the right border of the segment. Each number makes some constraints on where the left border might be. More specifically, it's two possible segments: between its last occurrence and the current position and between its fourth-to-last occurrence and its third-to-last one. Let's actually invert these segments. Bad segments are from the beginning of the array to the fourth-to-last occurrence, then from the second-to-last occurrence to the last one. So the valid left borders are in such positions that are covered by zero bad segments.

Let's keep track of them in a segment tree. Add $1$ on the bad subarrays. Now you have to count the number of $0$ values in a segtree. That's a pretty common problem. As we know that no values can go below $0$, $0$ should be a minimum element on the segment. So we can store a pair of (minimum on segment, number of minimums on segment). At the end the second value is the number of zeros if the first value is zero.

Overall complexity: $O(n \log n)$.

 **Solution 1 (pikmike)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++)

const int N = 60;

typedef array<int, N> num;

num operator ^(const num &a, const num &b){
    num c;
    forn(i, N){
        c[i] = a[i] + b[i];
        if (c[i] >= 3) c[i] -= 3;
    }
    return c;
}

mt19937 rnd(42);

int main(){
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    forn(i, n){
        scanf("%d", &a[i]);
        --a[i];
    }
    
    vector<num> nums(n);
    forn(i, n) forn(j, N) nums[i][j] = rnd() % 3;
    
    vector<vector<int>> pos(n);
    vector<num> pr(1);
    map<num, int> cnt;
    cnt[pr[0]] = 1;
    int cur = 0;
    long long ans = 0;
    forn(i, n){
        pr.push_back(pr.back() ^ nums[a[i]]);
        pos[a[i]].push_back(i);
        if (pos[a[i]].size() >= 4){
            while (cur <= pos[a[i]][int(pos[a[i]].size()) - 4]){
                --cnt[pr[cur]];
                ++cur;
            }
        }
        ans += cnt[pr.back()];
        ++cnt[pr.back()];
    }
    
    printf("%lldn", ans);
}
```
 **Solution 2 (pikmike)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++)

typedef unsigned long long uli;

vector<int> a;
vector<pair<int, int>> t;
vector<int> ps;

pair<int, int> merge(const pair<int, int> &a, const pair<int, int> &b){
    if (a.first != b.first)
        return min(a, b);
    return make_pair(a.first, a.second + b.second);
}

void push(int v){
    if (v * 2 + 1 < int(ps.size())){
        ps[v * 2] += ps[v];
        ps[v * 2 + 1] += ps[v];
    }
    t[v].first += ps[v];
    ps[v] = 0;
}

void build(int v, int l, int r){
    if (l == r - 1){
        t[v] = make_pair(0, 1);
        return;
    }
    int m = (l + r) / 2;
    build(v * 2, l, m);
    build(v * 2 + 1, m, r);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

void upd(int v, int l, int r, int L, int R, int val){
    push(v);
    if (L >= R)
        return;
    if (l == L && r == R){
        ps[v] = val;
        push(v);
        return;
    }
    int m = (l + r) / 2;
    upd(v * 2, l, m, L, min(m, R), val);
    upd(v * 2 + 1, m, r, max(m, L), R, val);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

int main(){
    int n;
    scanf("%d", &n);
    a.resize(n);
    forn(i, n){
        scanf("%d", &a[i]);
        --a[i];
    }
    t.resize(4 * n);
    ps.resize(4 * n);
    build(1, 0, n);
    vector<vector<int>> pos(n, vector<int>(1, -1));
    long long ans = 0;
    forn(i, n){
        int k = pos[a[i]].size();
        if (k >= 1) upd(1, 0, n, pos[a[i]][k - 1] + 1, i + 1, 1);
        if (k >= 3) upd(1, 0, n, pos[a[i]][k - 3] + 1, pos[a[i]][k - 2] + 1, -1);
        if (k >= 4) upd(1, 0, n, pos[a[i]][k - 4] + 1, pos[a[i]][k - 3] + 1, 1);
        pos[a[i]].push_back(i);
        push(1);
        if (t[1].first == 0) ans += t[1].second - (n - i - 1);
    }
    printf("%lldn", ans);
}
```
