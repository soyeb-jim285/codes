# Tutorial_(en)

[1928A - Rectangle Cutting](../problems/A._Rectangle_Cutting.md "Codeforces Round 924 (Div. 2)")
-----------------------------------------------------------------------------------------------------------

 **Solution**Let a≤b. Let's consider several cases:

 * If a is even, then we can cut the rectangle into two rectangles of size a2×b and combine them into a rectangle of size a2×2b, which is definitely different from a×b.
* If b is even and b≠2a, then we can cut the rectangle into two rectangles of size a×b2 and combine them into a rectangle of size 2a×b2. Note that here we use the fact that b≠2a, because if b=2a, then we will get the same rectangle of size b×a.
* If a and b are both odd, or b=2a and a is odd, then the rectangle is not interesting. It is easy to understand that if we cut the rectangle of size a×b into two rectangles of size a×c and a×d, where c≠d, then we can always only combine the original rectangle (similarly if we cut it into rectangles c×b and d×b). And from here it follows that we must divide one of the sides of the rectangle in half, so at least one side must be even.
 **Code**
```cpp
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <cassert>
#include <map>

using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
	    int a, b;
	    cin >> a >> b;
	    if (a > b) {
	        swap(a, b);
	    }
	    if (((a % 2 == 1) && (b % 2 == 1)) || ((a % 2 == 1) && (b == 2 * a))) {
	        cout << "Non";
	    } else {
	        cout << "Yesn";
	    }
	}
	
	return 0;
}

```
[1928B - Equalize](../problems/B._Equalize.md "Codeforces Round 924 (Div. 2)")
--------------------------------------------------------------------------------------------------

 **Solution**Suppose we already know the permutation that needs to be added. Let's consider the elements that will become equal after the addition. Notice that among them there cannot be equal elements, because among the numbers we are adding, there are no duplicates. Thus, only a set of numbers among which there are no equal ones, and the difference between the maximum and minimum does not exceed n−1, can become equal. It is easy to see that any set of numbers satisfying these conditions can be equalized, and any set of numbers that became equal after adding the permutation satisfies these constraints.

So let's sort the array, remove the equal elements from it. After that, we can use two pointers to find the maximum length subarray where the difference between the maximum and minimum does not exceed n−1. The answer will be the length of such a subarray. The complexity of the solution is O(nlogn).

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int pnt = 0, ans = 0;
    for (int i = 0; i < a.size(); i++) {
        while(a[i] - a[pnt] >= n) {
            pnt++;
        }
        ans = max(ans, i - pnt + 1);
    }
    cout << ans << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
```
[1928C - Physical Education Lesson](../problems/C._Physical_Education_Lesson.md "Codeforces Round 924 (Div. 2)")
-------------------------------------------------------------------------------------------------------------------

 **Solution**All numbers repeat every 2k−2 positions. If the boy Vasya's number is calculated to be x, then it can be at positions of the form (2k−2)⋅t+x, or (2k−2)⋅t+k+k−x, for some non-negative t. This is true for all x, except for x=1 and x=k ~--- for these values, there is only one option left.

Let's fix one of the options, the second one will be analogous. We need to find how many different values of k satisfy the equation (2k−2)⋅t+x=n, for some non-negative t. It is not difficult to see that this holds if and only if n−x is divisible by 2k−2. Therefore, it is necessary to find the number of \textbf{even} divisors of the number n−x. To consider the second case, it is necessary to proceed similarly with the number n+x−2. The solution's complexity: O(√n)

 **Code**
```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> solve(int a) {
    unordered_set<int> candidates;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            if (i % 2 == 0) // segment len should be even
                candidates.insert(i);
            if ((a / i) % 2 == 0)
                candidates.insert(a / i);
        }
    }
    unordered_set<int> answer;
    for (int i : candidates) {
        answer.insert(1 + i / 2);
    }
    return answer;
}

int main() {
    int t;
    cin >> t;
    for (int _ = 1; _ <= t; _++) {
        int n, pos;
        cin >> n >> pos;
        unordered_set<int> candidates = solve(n - pos);  // bug2
        for (int i : solve(n + pos - 2)) { // bug1
            candidates.insert(i);
        }
        int answer = 0;
        for (int i : candidates) {
            if (i >= pos) {
                answer++;
            }
        }
        cout << answer << endl;
    }
}
```
[1928D - Lonely Mountain Dungeons](../problems/D._Lonely_Mountain_Dungeons.md "Codeforces Round 924 (Div. 2)")
------------------------------------------------------------------------------------------------------------------

 **Solution**Let's learn how to solve the problem when n=1. Suppose there is only one race and the number of its representatives is c. Notice that for a fixed k, it is advantageous for us to divide the representatives of the race almost evenly into squads.

If c is divisible by k, then it is advantageous for us to take exactly y=ck beings in each squad. Then the total number of pairs of beings in different squads is equal to k(k−1)2⋅y2 (there are a total of k(k−1)2 pairs of squads, and for each pair of squads there are y2 pairs of beings from different squads).

In the general case, when c may not be divisible by k, let's denote y=⌊ck⌋ and y′=⌈ck⌉. Then it is advantageous for us to make squads of size y and y′, where the number of squads of size y′ is equal to cmodk (we essentially make all squads of size y, and then add 1 to some squads from the remaining part). In this case, the total number of pairs of beings in different squads is equal to C2k−cmodk⋅y2+C2cmodk⋅y′2+(k−cmodk)⋅(cmodk)⋅y⋅y′. It remains to notice that it makes no sense to have k>c, so we can simply iterate through k from 1 to c and choose the optimal one.

When n>1, we can notice that for a fixed k, we can solve the problem independently for each race. Let the number of representatives of the i-th race be ci. Then we will iterate through k from 1 to ci for it and add the maximum total strength to the value of cntk (the array cnt is common for all races). Also, notice that for k>ci, we will get the same total strength as for k=ci. Then in the additional array add (again, common for all races), we will add the maximum total strength for k=ci to addci.

We get the following solution: first, calculate the described arrays cnt and add. After that, iterate through k from 1 to the maximum ci. The maximum total strength of the squads for a fixed k will be equal to (cntk+(sum of values addi for i<k))⋅b−(k−1)⋅X. From these values, we need to choose the maximum.

 **Code**
```cpp
  
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll pairs(ll n, ll k){
    if (n == 0 || k == 0){
        return 0;
    }
    ll x = n / k;
    ll l = n % k;
    ll r = k - l;
    ll L = (x + 1) * l, R = x * r;
    return R * L + (R - x) * R / 2 + L * (L - x - 1) / 2;
}

void solve(){
    int m;
    long long c, b;
    cin >> m >> b >> c;

    int n = 0;
    vector<int> cnt(m);
    for (int i = 0; i < m; ++i) {
        cin >> cnt[i];
        n = max(n, cnt[i]);
    }


    vector<long long> pair(n + 1);
    vector<long long> add(n + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= cnt[i]; ++j) {
            pair[j] += pairs(cnt[i], j);
        }
        add[cnt[i]] += pairs(cnt[i], cnt[i]);
    }


    long long ans = 0;
    long long other = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, b * (pair[i] + other) - c * (i - 1));
        other += add[i];
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}

```
[1928E - Modular Sequence](../problems/E._Modular_Sequence.md "Codeforces Round 924 (Div. 2)")
----------------------------------------------------------------------------------------------------------

 **Solution**Let's see what the answer will look like: first, there will be a prefix of the form x,x+y,…,x+k⋅y, and then there will be some number of blocks of the form xmody,xmody+y,…,xmody+k⋅y.

We can subtract the number xmody from all the elements of the sequence, and then divide all the elements by y (all the elements will be divisible by y, since they initially had a remainder of xmody). Let b1=x−xmodyy. Then our sequence will start with b1,b1+1,…,b1+k1, and then there will be blocks of the form 0,1,…,ki.

Let's calculate these values: dpi~--- the minimum length of a sequence of blocks of the form 0,1,…,kj with a sum of i. This value can be calculated for all numbers from 0 to s using dynamic programming. If we have processed all values from 0 to k−1, then for k we have calculated the minimum length, and we can update the value of dp for k+1,k+1+2,…~--- a total of O(√s) values not exceeding s. In this same dp, we can store through which values we were recalculated, for the restoration of the answer.

Now, we can iterate over the length of the first block of the form b1,b1+1,…,b1+k1. Then we know the sum of the remaining blocks, and using the precalculated dp, we can determine whether the desired sequence can be formed or not.

 **Code**
```cpp
#include <cassert>
#include <initializer_list>
#include <numeric>
#include <vector>
#include <iostream>
#include <utility>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb emplace_back

const int INF = 1e9 + 10;
const ll INFLL = 1e18;

void solve() {
    int n, x, y, S;
    cin >> n >> x >> y >> S;
    vector<int> dp(S + 1, INF);
    dp[0] = 0;
    for (int k = 1; k <= S; k++) {
        for (int l = 2; (l * (l - 1)) / 2 <= k; l++) {  // just 0 is never optimal
            dp[k] = min(dp[k], dp[k - (l * (l - 1)) / 2] + l);
        }
        assert(dp[k] <= 2 * k);
    }
    for (ll k = 0; k < n; k++) {
        ll prevSum = (k + 1) * x + (k * (k + 1)) / 2 * y;
        if (prevSum > S) {
            continue;
        }
        ll needSum = S - prevSum;
        needSum -= (n - k - 1) * (x % y);
        if (needSum < 0) {
            continue;
        }
        if (needSum % y != 0) {
            continue;
        }
        needSum /= y;
        assert(needSum <= S);
        if (dp[needSum] <= n - k - 1) {  // we found the answer
            vector<int> a(n);
            a[0] = x;
            for (int i = 1; i <= k; i++) {  // construct prefix
                a[i] = a[i - 1] + y;
            }
            for (int i = k + 1; i <= k + (n - k - 1) - dp[needSum];
                 i++) {  // fill the rest like 0 0 0 ...
                a[i] = x % y;
            }
            int i = k + (n - k - 1) - dp[needSum] + 1;  // first free index
            vector<int> lens;                           // recover lengths of the segments
            while (needSum != 0) {
                for (int l = 2; (l * (l - 1)) / 2 <= needSum; l++) {
                    if (dp[needSum] == dp[needSum - (l * (l - 1)) / 2] + l) {
                        lens.pb(l);
                        needSum -= (l * (l - 1)) / 2;
                        break;
                    }
                }
            }
            for (auto &len : lens) {
                for (int j = 0; j < len; j++) {
                    a[i] = (x % y) + y * j;
                    i++;
                }
            }
            cout << "YESn";
            for (auto &c : a) {
                cout << c << " ";
            }
            cout << "n";
            return;
        }
    }
    cout << "NOn";
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

```
[1928F - Digital Patterns](../problems/F._Digital_Patterns.md "Codeforces Round 924 (Div. 2)")
----------------------------------------------------------------------------------------------------------

 **Solution**Let's assume that ai=ai+1 for some 1≤i<n, then for any 1≤j≤m, the cells (i,j) and (i+1,j) will have the same transparency. A similar statement can be made if there is an index j: bj=bj+1.

Then the positions ai=ai+1 divide the array a into \textit{blocks}, in each of which all neighboring pairs are not equal to each other. It is clear that if there is a square (x,y,d) consisting of cells (i,j) such that x≤i<x+d and y≤j<y+d, then the segment [x,x+d−1] is entirely contained in one of these \textit{blocks} of the array a. Similarly, the array b can also be divided into blocks, and then the segment [y,y+d−1] will also be entirely contained in one of the blocks.

Let's try to solve the problem in O(1) time, if there are no neighboring elements with the same values in the arrays a and b (also assuming that n≤m):

 f(n,m)=n∑k=1(n−k+1)(m−k+1)=∑nk=1(k2+(m−n)k)f(n,m)=n(n+1)(2n+1)6+(m−n)⋅n(n+1)2This formula can be further transformed by introducing a quadruple of numbers for each natural number n: an=1, bn=n, cn=12n(n+1), dn=16n(n+1)(2n+1)−12n2(n+1). Then f(n,m)=dnam+cnbm, if n≤m and f(n,m)=andm+bncm, if n>m.

But if there are neighboring identical elements in the arrays a and b, then this means that they are somehow divided into blocks. If these are blocks of lengths n1,…,nk in the array a and blocks of lengths m1,…,ml in the array b, then the answer to the problem is

 ans=∑ki=1∑lj=1f(ni,mj)Let's learn how to quickly calculate sums of the form f(x,m1)+…+f(x,ml). To do this, we will create 4 segment trees to quickly calculate the sums ∑ay, ∑by, ∑cy, ∑dy over segments of y, taking into account the multiplicity of y in the array m1,…,ml. Now the calculation of f(x,m1)+…+f(x,mk) is reduced to 4 segment tree queries:

 f(x,m1)+…+f(x,ml)=ax⋅∑mi<xdmi+bx⋅∑mi<xcmi+cx⋅∑mi≥xbmi+dx⋅∑mi≥xamiThe sum f(n1,y)+…+f(nk,y) is calculated similarly. Now we just need to put our solution together. We will maintain the blocks of arrays a and b in an online mode. It is very convenient to do this by storing the positions ai=ai+1 in a data structure like std::set, and also by working with the differential array a (i.e., maintaining not the array a itself, but the array of differences between neighboring elements ci=ai+1−ai). To recalculate the answer, we will count the number of squares that are involved in a specific block of the array a or b, using the above result. As a result, we have a solution in O((n+q)(logn+logm)).

P.S. A solution in O(q√n) will not work due to a large constant. I tried very hard to rule it out :D.

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;

struct SegmentTree {
    int n;
    vector<ll> t;

    SegmentTree(int n) : n(n), t(2*n) { }

    void Add(int i, ll x) {
        for (i += n; i != 0; i >>= 1) t[i] += x;
    }

    ll Query(int l, int r) {
        ll ans = 0;

        for (l += n, r += n - 1; l <= r; l >>= 1, r >>= 1) {
            if ((l&1) == 1) ans += t[l++];
            if ((r&1) == 0) ans += t[r--];
        }
        return ans;
    }
};

struct SegmentContainer {
    int side;
    SegmentTree sgt_a, sgt_b, sgt_c, sgt_d;
    int id;
    // sgt_a: sum(1)
    // sgt_b: sum(m)
    // sgt_c: sum(m*(m+1)/2)
    // sgt_d: sum(m*(m-1)*(2*m-1)/6 - m*(m-1)/2*m)

    SegmentContainer(int side) : side(side), sgt_a(side), sgt_b(side), sgt_c(side), sgt_d(side) {
    }

    tuple<ll, ll, ll, ll> GetABCD(ll m) {
        return make_tuple(1, m, m*(m+1)/2, m*(m-1)*(2*m-1)/6 - m*(m-1)/2*m);
    }

    void Insert(int m) {
        auto [a, b, c, d] = GetABCD(m);
        sgt_a.Add(m-1, +a);
        sgt_b.Add(m-1, +b);
        sgt_c.Add(m-1, +c);
        sgt_d.Add(m-1, +d);
    }

    void Erase(int m) {
        auto [a, b, c, d] = GetABCD(m);
        sgt_a.Add(m-1, -a);
        sgt_b.Add(m-1, -b);
        sgt_c.Add(m-1, -c);
        sgt_d.Add(m-1, -d);
    }

    ll SquaresCount(int n) {
        const int mid = min(side, n);
        auto sum_a = sgt_a.Query(mid, side); // m > n
        auto sum_b = sgt_b.Query(mid, side); // m > n
        auto sum_c = sgt_c.Query(0, mid); // m <= n
        auto sum_d = sgt_d.Query(0, mid); // m <= n
        auto [a, b, c, d] = GetABCD(n);

        return d * sum_a + c * sum_b + b * sum_c + a * sum_d;
    }
};

struct SegmentMaintainer {
    SegmentContainer& my;
    SegmentContainer& other;
    ll& ans;

    set<int> pos_zero;
    vector<ll> diff_array;

    SegmentMaintainer(vector<int> a, 
                      SegmentContainer& my,
                      SegmentContainer& other,
                      ll& ans) :
            pos_zero(), diff_array(a.size()), my(my), other(other), ans(ans) {
        pos_zero.insert(0);
        for (int i = 1; i < a.size(); ++i) {
            diff_array[i] = a[i] - a[i-1];
            if (diff_array[i] == 0) pos_zero.insert(i);
        }
        pos_zero.insert(a.size());

        for (auto it = pos_zero.begin(); *it != my.side; ++it) {
            OnSegmentAppear(*next(it) - *it);
        }
    }

    void OnSegmentAppear(int len) {
        my.Insert(len);
        ans += other.SquaresCount(len);
    }

    void OnSegmentDissapear(int len) {
        my.Erase(len);
        ans -= other.SquaresCount(len);
    }

    void ChangeBound(int pos, ll dx) {
        if (pos == 0 || pos == my.side) return; 
            
        bool was_zero = diff_array[pos] == 0;
        diff_array[pos] += dx;
        bool now_zero = diff_array[pos] == 0;

        if (was_zero && !now_zero) {
            auto mid = pos_zero.find(pos);
            auto prv = prev(mid), nxt = next(mid);
            
            OnSegmentDissapear(*mid - *prv);
            OnSegmentDissapear(*nxt - *mid);
            OnSegmentAppear(*nxt - *prv);

            pos_zero.erase(mid);
        }
        
        if (!was_zero && now_zero) {
            auto mid = pos_zero.insert(pos).first;
            auto prv = prev(mid), nxt = next(mid);

            OnSegmentAppear(*mid - *prv);
            OnSegmentAppear(*nxt - *mid);
            OnSegmentDissapear(*nxt - *prv);
        }
    }

    void RangeAdd(int l, int r, int x) {
        ChangeBound(l, +x);
        ChangeBound(r, -x);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;

    vector<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    ll ans = 0;
    SegmentContainer a_segments(n), b_segments(m);

    a_segments.id = 1;
    b_segments.id = 2;

    SegmentMaintainer a_maintainer(a, a_segments, b_segments, ans); 
    SegmentMaintainer b_maintainer(b, b_segments, a_segments, ans);
    
    cout << ans << 'n';
    while (q--) {
        int t, l, r, x; cin >> t >> l >> r >> x; --l;
        if (t == 1) a_maintainer.RangeAdd(l, r, x);
        if (t == 2) b_maintainer.RangeAdd(l, r, x);
        cout << ans << 'n';
    }
}
```
