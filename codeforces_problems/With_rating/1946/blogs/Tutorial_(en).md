# Tutorial_(en)

author: [exhausted](https://codeforces.com/profile/exhausted "Master exhausted"), developer: [exhausted](https://codeforces.com/profile/exhausted "Master exhausted")

[1946A - Median of an Array](../problems/A._Median_of_an_Array.md "Codeforces Round 936 (Div. 2)")

 **Editorial**
### [1946A - Median of an Array](../problems/A._Median_of_an_Array.md "Codeforces Round 936 (Div. 2)")

The median is defined as the number at index ⌈n2⌉ in the sorted array, so we can sort the array and work with it.

So, let's start by sorting the array and finding the median in it, namely the number a⌈n2⌉, let it be equal to x. In order for the median to increase, that is, to become at least x+1, it is necessary that there are at least n−⌈n2⌉+1 numbers in the array greater than or equal to x+1.

Now let's find the maximum index t such that at equals x. Then we know that there are currently n−t numbers that are greater than or equal to x+1 (all such ai that i>t), which means that at least (n−⌈n2⌉+1)−(n−t)=t−⌈n2⌉+1 operations will be required. I claim that this estimate is always achievable, it is enough to apply one operation to each index from ⌈n2⌉ to t, because all the numbers under these indices are equal to x, so after applying the operations they will become equal to x+1. And in the end, the number of numbers greater than or equal to x+1 will become equal to (n−t)+(t−⌈n2⌉+1)=n−⌈n2⌉+1, which is what we need.

 **Solution**
```cpp
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int p = (n + 1) / 2 - 1;
    int res = std::count(a.begin() + p, a.end(), a[p]);
    std::cout << res << "n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }
}
```
author: [max0000561](https://codeforces.com/profile/max0000561 "Master max0000561"), developer: [yunetive29](https://codeforces.com/profile/yunetive29 "Candidate Master yunetive29")

[1946B - Maximum Sum](../problems/B._Maximum_Sum.md "Codeforces Round 936 (Div. 2)")

 **Editorial**
### [1946B - Maximum Sum](../problems/B._Maximum_Sum.md "Codeforces Round 936 (Div. 2)")

Let's denote s as the sum of the original array and x as the sum of the subarray with the maximum sum from the original array.

We solve the problem when k equals 1. In this case, we need to find the subarray of the array with the maximum sum and insert this sum anywhere in the array, so the answer is s+x. Now, let k be 2. In this case, there is already a value where we insert the sum of the subarray with the maximum sum. Then we can increase the sum of the subarray with the maximum sum by no more than x (we can increase it by x simply by inserting it into the subarray with the maximum sum), and obtain the sum of the subarray with the maximum sum 2⋅x. Then insert it anywhere in the array, thus obtaining the sum of the final array equal to s+x+2⋅x. Similarly, for any k, the sum of the subarray with the maximum sum is initially x, then 2⋅x, then 4⋅x, …, 2k−1⋅x, then the answer is equal to s+x+2⋅x+⋯+2k−1⋅x=s+2k⋅x−x.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int P = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int S = 0, sum = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        cur += a[i];
        cur = max(cur, 0LL);
        S = max(S, cur);
    }
    sum = (sum % P + P) % P;
    S = S % P;
    int t = 1;
    for (int i = 0; i < k; i++) {
        t = t * 2 % P;
    }
    int ans = (sum + S * t - S + P) % P;
    cout << ans << 'n';
}


signed main() {
    //cout << fixed << setprecision(20);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1, G = 1;
    //cin >> G;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
```
author: [exhausted](https://codeforces.com/profile/exhausted "Master exhausted"), developer: [exhausted](https://codeforces.com/profile/exhausted "Master exhausted")

[1946C - Tree Cutting](../problems/C._Tree_Cutting.md "Codeforces Round 936 (Div. 2)")

 **Editorial**
### [1946C - Tree Cutting](../problems/C._Tree_Cutting.md "Codeforces Round 936 (Div. 2)")

Let's hang the tree from an arbitrary vertex, for definiteness let's hang the tree from vertex 1 (proof is given below). First of all, notice that if we can obtain some answer x, then we can also obtain the answer x−1 (exactly the same way as for x), so we can do a binary search for x.

To check the condition for a fixed x, we will use a greedy algorithm. We will find the maximum number of connected components into which we can cut our tree so that each component has at least x vertices. We will start a dfs from vertex 1, let's say we are currently at vertex v and the number of vertices in its subtree is greater than or equal to x, then it is advantageous for us to remove the edge from vertex v to its parent. If after this process there are at least k+1 connected components, then the condition is satisfied for this x, otherwise it is not.

Proof that it doesn't matter which vertex to hang the tree from:

We need to prove that the greedy algorithm will obtain the same number of cuts for all roots. We will prove this in the order of depth-first search. It is also important to note that it doesn't matter in which order to run the greedy algorithm from the children. Let the initial root be 1, and we want to prove it for its child 2. Then let's see how the greedy algorithm will act in the first case: it will start from vertex 2, and then from all its adjacent vertices except 1, and remove some edges. When we run the greedy algorithm in the second case, we can reorder the vertices, and first run it from all adjacent vertices except 1, and there will be the same removals. Then we will run the greedy algorithm from vertex 1, it will perform the same removals as in the first case, if we made vertex 2 the last one. So the only edge that may not coincide in these removals is 1−2. If this edge did not participate in the removals the first time, then the size of the remaining part of vertex 2<x, so we cannot remove it now. If the edge 1−2 was removed in the first variant, then the size of the component 1 was ≥x, and there were no vertices of subtree 2 in it. Then when running the greedy algorithm from the second vertex, it will cut the edge 1−2, because the size of this part became ≥x, so the set of edges coincides.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        std::cin >> v >> u;
        --v, --u;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    auto check = [&](int x) {
        int res = 0;
        auto dfs = [&](auto self, int v, int f) -> int {
            int sz = 1;
            for (int u : adj[v]) {
                if (u == f) {
                    continue;
                }
                sz += self(self, u, v);
            }
            if (sz >= x && f != v) {
                ++res, sz = 0;
            }
            return sz;
        };
        int t = dfs(dfs, 0, 0);
        return (res > k || (t >= x && res == k) ? true : false);
    };
    int low = 1, high = n / (k + 1) + 1;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    std::cout << low << "n";
}
 
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    std::cin >> t;
 
    while (t--) {
        solve();
    }
}
```
author: [azureglow](https://codeforces.com/profile/azureglow "Master azureglow"), developer: [azureglow](https://codeforces.com/profile/azureglow "Master azureglow")

[1946D - Birthday Gift](../problems/D._Birthday_Gift.md "Codeforces Round 936 (Div. 2)")

 **Editorial**
### [1946D - Birthday Gift](../problems/D._Birthday_Gift.md "Codeforces Round 936 (Div. 2)")

For convenience, let's increase x by 1, and then iterate through the bit in which the final number is less than x. We will iterate from the most significant bit to the least significant bit, denoting it as i. The initial bit will be 30. Let's look at all the numbers a in which this bit is 1.

If there is an odd number of such numbers, then the ⊕ of some subsegment will be odd, and therefore the final | will also be odd. If at the same time the bit i in x is 0, then the process needs to be terminated, because in all the other bits it will no longer be possible to decrease the final number. If, however, in x this bit is also 1, then we need to move on to the less significant bits, since in both numbers this bit will always be 1.

If the number of numbers with 1 in bit i is even, then in order to make this bit 0 in the final number, each segment must contain an even number of such numbers, and since we want to maximize the number of segments, each segment must contain exactly 2 such numbers. For this, for every two indices l and r, such that al and ar in bit i contain 1, and all numbers from al+1 to ar−1 contain 0, replace the subsegment [l,r] with al⊕al+1⊕…⊕ar. After this, if there is a 1 in x in this bit, update the answer and return the array to its original state. Then move on to the less significant bits.

There is also an alternative solution that also iterates through the bits from the most significant to the least significant, but instead of compressing subsegments into one number, it uses a greedy algorithm.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
#define int ll
#define all(a) a.begin(), a.end()
 
void solve() {
    int n, x;
    cin >> n >> x;
    ++x;
    vector<int> a(n);
    for (int &i: a)
        cin >> i;
    int res = -1;
    for (int i = 30; i >= 0; --i) {
        vector<int> b;
        bool open = false;
        for (int j = 0; j < a.size(); ++j) {
            if (!open)
                b.push_back(a[j]);
            else
                b.back() ^= a[j];
            if (a[j] & (1 << i))
                open = !open;
        }
        if (!(x & (1 << i))) {
            if (open) {
                cout << res << 'n';
                return;
            }
            a = b;
        } else {
            if (!open)
                res = max(res, (int) b.size());
        }
    }
    cout << res << 'n';
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
```
 **Solution (74TrAkToR)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
int const maxn = 1e5 + 5;
int a[maxn];
 
int solve(int n, int x) {
    int res = 0, curr = 0;
    for (int i = 1; i <= n; i++) {
        curr ^= a[i];
        if ((curr|x) == x) curr = 0, res++;
        else {
            if (i == n) return -1;
        }
    }
    return res;
}
 
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ans = -1;
        ans = max(ans, solve(n, x));
        for (int b = 29; b >= 0; b--) {
            if ((x>>b)&1) {
                int y = (x^(1 << b));
                for (int c = b - 1; c >= 0; c--) {
                    if (((y>>c)&1) == 0) y ^= (1 << c);
                }
                ans = max(ans, solve(n, y));
            }
        }
        cout << ans << 'n';
    }
    return 0;
}
```
author: [yunetive29](https://codeforces.com/profile/yunetive29 "Candidate Master yunetive29"), developer: [yunetive29](https://codeforces.com/profile/yunetive29 "Candidate Master yunetive29")

[1946E - Girl Permutation](../problems/E._Girl_Permutation.md "Codeforces Round 936 (Div. 2)")

 **Editorial**
### [1946E - Girl Permutation](../problems/E._Girl_Permutation.md "Codeforces Round 936 (Div. 2)")

First, if p1 is not equal to 1, or sm2 is not equal to n, or pm1 is not equal to s1, then the answer is 0 for obvious reasons. Otherwise, we know exactly where the number n is located, at position s1. Next, we have (n−1s1−1) ways to divide the numbers from 1 to n−1 into two sets — the numbers that will be in the left part and the numbers that will be in the right part (the left part — all indices <s1, the right part — all indices >s1). We solve for the left part, and similarly for the right part. For the left part, the position of the maximum (pm1−1) is again defined, and the maximum itself is also unique in the set of numbers for the left part, so we can again divide the left part into two, with (pm1−2pm1−1−1) ways to do so, but we can also arrange the numbers between indices pm1−1 and pm1 (non-inclusive) in any order, i.e., (pm1−pm1−1−1)! ways. Then we solve similarly for the left set (i.e., for indices less than pm1−1).

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using i64 = long long;
 
template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
 
template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % P)} {}
    
    constexpr int norm(int x) const {
        if (x < 0) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(P - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    constexpr MInt &operator*=(MInt rhs) {
        x = 1LL * x * rhs.x % P;
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};
 
constexpr int MOD = 1e9 + 7;
using Z = MInt<MOD>;
 
namespace comb {
    int n = 0;
    std::vector<Z> _fac = {1};
    std::vector<Z> _invfac = {1};
    std::vector<Z> _inv = {0};
    
    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }
    
    Z fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    Z invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    Z inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    Z binom(int m, int k) {
        if (m < k || k < 0) return 0;
        return fac(m) * invfac(k) * invfac(m - k);
    }
} // namespace comb
 
void solve() {
    int n, m1, m2;
    std::cin >> n >> m1 >> m2;
    std::vector<int> p(m1), s(m2);
    for (int i = 0; i < m1; i++) {
        std::cin >> p[i];
    }
    for (int i = 0; i < m2; i++) {
        std::cin >> s[i];
    }
    if (p[0] != 1 || s[0] != p[m1 - 1] || s[m2 - 1] != n) {
        std::cout << "0n";
        return;
    }
    Z res = comb::binom(n - 1, s[0] - 1);
    for (int i = m1 - 2; i > -1; i--) {
        res *= comb::binom(p[i + 1] - 2, p[i + 1] - p[i] - 1) * comb::fac(p[i + 1] - p[i] - 1);
    }
    for (int i = 1; i < m2; i++) {
        res *= comb::binom(n - s[i - 1] - 1, s[i] - s[i - 1] - 1) * comb::fac(s[i] - s[i - 1] - 1);
    }
    std::cout << res << "n";
}
 
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    #ifndef ONLINE_JUDGE
        freopen("/home/q1n/coding/input.txt", "r", stdin);
        freopen("/home/q1n/coding/output.txt", "w", stdout);
    #else
        // online submission
    #endif
 
    int t = 1;
    std::cin >> t;
 
    while (t--) {
        solve();
    }
}
```
author: [exhausted](https://codeforces.com/profile/exhausted "Master exhausted"), [yunetive29](https://codeforces.com/profile/yunetive29 "Candidate Master yunetive29"), developer: [exhausted](https://codeforces.com/profile/exhausted "Master exhausted"), [yunetive29](https://codeforces.com/profile/yunetive29 "Candidate Master yunetive29")

[1946F - Nobody is needed](../problems/F._Nobody_is_needed.md "Codeforces Round 936 (Div. 2)")

 **Editorial**
### [1946F - Nobody is needed](../problems/F._Nobody_is_needed.md "Codeforces Round 936 (Div. 2)")

Let's iterate the left boundary of our queries L from n to 1 and maintain the Fenwick tree F, where Fi = the number of sought sets of indices in which tk=i, and t1≥L. Then the answer to the query with the left boundary at L will be the sum over the interval [li;ri] in our Fenwick tree. Now we just need to learn how to update our tree when transitioning from L to L−1. Some new sets of indices may have been added, starting at L−1. Let's denote posi as the position of the number i in the permutation. We'll create an auxiliary array dp. We'll learn to calculate the dynamics dpi= the number of sought sets of indices where t1=L−1, tk=i. The base case will be dpL−1=1. Suppose we know the value of dpposx. Then we can update dpposy=dpposy+dpposx, if y is divisible by x and y≠x, posai≤posx≤posy. We can calculate this dynamics straightforwardly, iterating over x and y (y is divisible by x and x is divisible by ai). Notice that this will work in total for O(n⋅logn⋅logn) for the permutation. Now we can iterate over all numbers again that are multiples of ai, update the Fenwick tree, and clear the dp array to reuse it in the future.

 **Solution**
```cpp
#include <bits/stdc++.h>

using i64 = long long;

template<class Info>
struct Fenwick {
    std::vector<Info> t;
    int n;
    
    Fenwick(int n = 0) : n(n) {
        t.resize(n);
    }
    
    void add(int x, const Info &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            t[i - 1] = t[i - 1] + v;
        }
    }
    
    Info sum(int x) {
        x++;
        Info res = Info();
        for (int i = x; i > 0; i -= i & -i) {
            res = res + t[i - 1];
        }
        return res;
    }
    
    Info rangeSum(int l, int r) {
        Info res = sum(r) - sum(l - 1);
        return res;
    }
};

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n), pos(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        pos[a[i]] = i;
    }
    constexpr int K = 19;
    std::vector<i64> res(q);
    std::vector<std::vector<std::pair<int, int>>> qry(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        std::swap(l, r);
        l = n - l - 1;
        r = n - r - 1;
        qry[r].emplace_back(l, i);
    }
    std::vector<i64> dp(n + 1);
    Fenwick<i64> f(n);
    for (int r = 0; r < n; r++) {
        int x = a[r];
        dp[x] = 1;
        // n * log(n) * log(n)
        for (int y = x; y <= n; y += x) {
            if (pos[y] > pos[x]) {
                continue;
            }
            for (int z = 2 * y; z <= n; z += y) {
                if (pos[z] > pos[y]) {
                    continue;
                }
                dp[z] += dp[y];
            }
        }
        // n * log(n) * log(n)
        for (int y = x; y <= n; y += x) {
            f.add(pos[y], dp[y]);
            dp[y] = 0;
        }
        // q * log(n)
        for (auto [l, i] : qry[r]) {
            res[i] += f.rangeSum(l, r);
        }
    }
    for (int i = 0; i < q; i++) {
        std::cout << res[i] << " n"[i == q - 1];
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }
}
```
