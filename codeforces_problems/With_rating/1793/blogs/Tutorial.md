# Tutorial

[1793A - Yet Another Promotion](../problems/A._Yet_Another_Promotion.md "Codeforces Round 852 (Div. 2)") was authored and prepared by [Ormlis](https://codeforces.com/profile/Ormlis "Legendary Grandmaster Ormlis")

[1793B - Fedya and Array](../problems/B._Fedya_and_Array.md "Codeforces Round 852 (Div. 2)") was authored and prepared by [TheEvilBird](https://codeforces.com/profile/TheEvilBird "Expert TheEvilBird")

[1793C - Dora and Search](../problems/C._Dora_and_Search.md "Codeforces Round 852 (Div. 2)") was authored by [fedoseev.timofey](https://codeforces.com/profile/fedoseev.timofey "International Grandmaster fedoseev.timofey") and prepared by [vaaven](https://codeforces.com/profile/vaaven "Candidate Master vaaven")

[1793D - Moscow Gorillas](../problems/D._Moscow_Gorillas.md "Codeforces Round 852 (Div. 2)") was authored and prepared by [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

[1793E - Velepin and Marketing](../problems/E._Velepin_and_Marketing.md "Codeforces Round 852 (Div. 2)") was authored and prepared by [Tikhon228](https://codeforces.com/profile/Tikhon228 "Master Tikhon228")

[1793F - Rebrending](../problems/F._Rebrending.md "Codeforces Round 852 (Div. 2)") was authored by [Tikhon228](https://codeforces.com/profile/Tikhon228 "Master Tikhon228") and prepared by [vaaven](https://codeforces.com/profile/vaaven "Candidate Master vaaven")

[1793A - Yet Another Promotion](../problems/A._Yet_Another_Promotion.md "Codeforces Round 852 (Div. 2)")
---------------------------------------------------------------------------------------------------------------

Let n=(m+1)⋅q+rn=(m+1)⋅q+r.

Note that you need to use a promotion if a⋅m≤b⋅(m+1)a⋅m≤b⋅(m+1). In this case, we will buy potatoes qq times for the promotion. The remaining potatoes (or all if the promotion is unprofitable) can be bought at min(a,b)min(a,b) per kilogram.

Then the answer is: 

 q⋅min(a⋅m,b⋅(m+1))+r⋅min(a,b)q⋅min(a⋅m,b⋅(m+1))+r⋅min(a,b)Thus this solution works in O(1)O(1)

 **Code**
```cpp
t = int(input())

for i in range(t):
    a, b = map(int, input().split(" "))
    n, m = map(int, input().split(" "))

    q = n // (m + 1)
    r = n - q * (m + 1)
    print(q * min(a * m, b * (m + 1))+ r*min(a,b))
```
[1793B - Fedya and Array](../problems/B._Fedya_and_Array.md "Codeforces Round 852 (Div. 2)")
---------------------------------------------------------------------------------------------------------

Note that the local minimums and maximums will alternate, and there will be the same number of them kk. Let's call the ii-th local maximum by aiai, the ii-th local minimum by bibi. Without loss of generality, consider that aiai goes before bibi. To get bibi from aiai we need to write out ai−biai−bi numbers, to get a(i+1)modka(i+1)modk from bibi we need to write out a(i+1)modk−bia(i+1)modk−bi numbers. 

Thus, (a1−b1)+(a2−b1)+(a2−b2)+…+(ak−bk)+(a1−bk)=(a1−b1)+(a2−b1)+(a2−b2)+…+(ak−bk)+(a1−bk)= 

=2⋅(a1+a2+…+ak)−2⋅(b1+b2+…+bk)=2⋅(A−B)=n=2⋅(a1+a2+…+ak)−2⋅(b1+b2+…+bk)=2⋅(A−B)=n

The array [y,y+1,y+2,…,x−1,x,x−1,x−2,…,y+1][y,y+1,y+2,…,x−1,x,x−1,x−2,…,y+1] will satisfy the condition.

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll a, b;
    cin >> a >> b;
    ll n = 2 * (a - b);
    cout << n << 'n';
    vector<ll> arr(n);
    int ptr = 0;
    for (ll c = b; c <= a; ++c) {
        arr[ptr++] = c;
    }
    for (ll c = a - 1; c > b; --c) {
        arr[ptr++] = c;
    }
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " n"[i == n - 1];
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```
[1793C - Dora and Search](../problems/C._Dora_and_Search.md "Codeforces Round 852 (Div. 2)")
---------------------------------------------------------------------------------------------------------

Suppose we want to check whether the entire array satisfies the claim. If this is the case, then we can output the entire array as an answer. Otherwise, one of the two extreme elements does not meet our requirements. From this we can conclude that all segments containing an element that does not meet our requirements will also be incorrect, because this extreme element will remain the minimum/maximum.

The algorithm follows from the fact above: let's look at the sub-section [l;r][l;r], which is initially equal to [1;n][1;n]. If al=min(al,al+1,…,ar)al=min(al,al+1,…,ar) or al=max(al,al+1,…,ar)al=max(al,al+1,…,ar), then we proceed to the segment [l+1;r][l+1;r]. A similar reasoning is also needed for arar. Thus, either after some iterations we will get the required sub-section, or we will get l==rl==r and the answer will be −1−1.

Final asymptotics: O(nlogn)O(nlogn) or O(n)O(n) depending on the implementation.

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int &i: a)
        cin >> i;
    int l = 0, r = n - 1;
    int mn = 1, mx = n;
    while (l <= r) {
        if (a[l] == mn) {
            l++;
            mn++;
        } else if (a[l] == mx) {
            l++;
            mx--;
        } else if (a[r] == mn) {
            r--;
            mn++;
        } else if (a[r] == mx) {
            r--;
            mx--;
        } else {
            break;
        }
    }
    if(l <= r){
        cout << l + 1 << " " << r + 1 << endl;
    } else{
        cout << -1 << endl;
    }
}

signed main() {
    int q = 1;
    cin >> q;
    while (q--)
        solve();
    return 0;
}
```
[1793D - Moscow Gorillas](../problems/D._Moscow_Gorillas.md "Codeforces Round 852 (Div. 2)")
---------------------------------------------------------------------------------------------------------

Denote by posxposx the index of the number xx in the permutation. Subsegments with MEX>1MEX>1 are as follows 1≤l≤pos1≤r≤n1≤l≤pos1≤r≤n.

Denote by: lx=min[pos1,pos2,…,posx]lx=min[pos1,pos2,…,posx], rx=max[pos1,pos2,…,osx]rx=max[pos1,pos2,…,osx].

Subsegments with MEX>xMEX>x are as follows 1≤l≤lx≤rx≤r≤n1≤l≤lx≤rx≤r≤n. Let's find all subsegments with MEX=xMEX=x.

If posx+1<lxposx+1<lx, then the subsegments with MEX=x+1MEX=x+1 are as follows posx+1<l≤lx≤rx≤r≤nposx+1<l≤lx≤rx≤r≤n

If lx≤posx+1≤rxlx≤posx+1≤rx, then there is no subsegment with MEX=x+1MEX=x+1

If rx<posx+1rx<posx+1, then the subsegments with MEX=x+1MEX=x+1 are as follows 1≤l≤lx≤rx≤r<posx+11≤l≤lx≤rx≤r<posx+1

It remains only to intersect the sets of such subsegments for pp and qq, which is done trivially.

 **Code**
```cpp
#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> pos_a(n + 1);
    vector<int> pos_b(n + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pos_a[a] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        pos_b[b] = i + 1;
    }
    int la = n, ra = 1, lb = n, rb = 1, ans = 0;
    for (int i = 1; i + 1 <= n; i++) {
        la = min(la, pos_a[i]);
        ra = max(ra, pos_a[i]);
        lb = min(lb, pos_b[i]);
        rb = max(rb, pos_b[i]);
        int min_la, max_ra, min_lb, max_rb;
        if (pos_a[i + 1] < la) {
            min_la = pos_a[i + 1] + 1;
            max_ra = n;
        } else {
            min_la = 1;
            max_ra = pos_a[i + 1] - 1;
        }
        if (pos_b[i + 1] < lb) {
            min_lb = pos_b[i + 1] + 1;
            max_rb = n;
        } else {
            min_lb = 1;
            max_rb = pos_b[i + 1] - 1;
        }
        ans += max(min(la, lb) - max(min_la, min_lb) + 1, 0ll) * max(min(max_ra, max_rb) - max(ra, rb) + 1, 0ll);
    }
    ans += min(pos_a[1], pos_b[1]) * (min(pos_a[1], pos_b[1]) - 1) / 2;
    ans += (n - max(pos_a[1], pos_b[1])) * (n - max(pos_a[1], pos_b[1]) + 1) / 2;
    ans += abs(pos_a[1] - pos_b[1]) * (abs(pos_a[1] - pos_b[1]) - 1) / 2;
    ans++;
    cout << ans << endl;
}

signed main() {
    int q = 1;
    while (q--)
        solve();
    return 0;
}
```
[1793E - Velepin and Marketing](../problems/E._Velepin_and_Marketing.md "Codeforces Round 852 (Div. 2)")
---------------------------------------------------------------------------------------------------------------

Let's sort people by their group size requirement. Suppose we have such a person ii that he is not satisfied, and we have a person j>ij>i who is satisfied. Then we can replace person jj in his group with ii and the answer for us will not be worse. It follows that for a particular kk the answer is some prefix of the people we can make satisfied.

Let us also prove that there exists some arrangement of groups that covers the same prefix, and that each group is a continuous segment. Let's take some correct partitioning into groups. Then each group will be a set of unconnected segments. Let's take the leftmost such segment. Note that we can swap it to the nearest segment of the same group to the right without breaking anything.

Thus we obtained that we can look for a solution in the form of partitioning each prefix into valid groups, which are segments. We will solve this problem using dynamic programming. 

Let dp[i]dp[i] -- the maximum number of groups into which iith prefix can be partitioned, so that everyone is satisfied (and no elements beyond the prefix can be used). Dynamics base: dp[0]=0dp[0]=0 (empty prefix maximum can be divided into 0 groups). Transition: for iith person his group must have size at least a[i]a[i], so the transition looks like this dp[i]=max0⩽j⩽i−a[i]dp[j]+1. But what if a[i]>i? Then we can't dial the ith prefix. Then we put dp[i]=−∞. This dynamics can be calculated using prefix maximums. This part of the solution works for O(n).

Earlier we said that the answer would be some prefix of people who would be satisfied. If we can partition the prefix into some number of groups, then that answer can be the prefix for all k⩽dp[i]+n−i. (we partition our prefix into dp, and the rest of the people one by one into the group)

If we can't make the whole prefix satisfied (dp[i]=−∞), then we need to add people from outside. Thus, the maximum number of groups we can split into if ith prefix is completely satisfied is n−a[i]+1.

Note that if by some prefix we can score k, then we can also score k−1 (combining two groups into one). Then we need to find the largest prefix that fits the given k in the query. This can be done by an array of suffix maximums over O(q) total. The final asymptotic of the solution is O(nlogn+q).

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()

const int inf = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];
    sort(all(c));
    vector<int> ans(n + 1); 
    vector<int> dp(n + 1, -inf);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        if (c[i-1] <= i) {
            dp[i] = dp[i - c[i-1]] + 1;
            ans[dp[i] + n - i] = max(ans[dp[i] + n - i], i);
        } else {
            if (c[i-1] <= n) {
                ans[1 + n - c[i-1]] = max(ans[1 + n - c[i-1]], i);
            }
        }
        dp[i] = max(dp[i], dp[i-1]);
    }

    for (int i = n - 1; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        cout << ans[x] << 'n';
    }

    return 0;
}
```
[1793F - Rebrending](../problems/F._Rebrending.md "Codeforces Round 852 (Div. 2)")
----------------------------------------------------------------------------------------------------

Let's go through all the elements from left to right. The main task will be to support the current version of dp[i] -- the minimum difference of ai with the elements to the right of it that we managed to consider. Let us correctly calculate dp for the first r elements. Let's move on to r+1. Let's show how to update the answer for all j<i, such that a[j]>a[i]. For j<i, such that a[j]<a[i] is solved similarly.

Let's take the first element a[j] to the left of i, such that a[j]>a[i]. Note that if there is l<j<i such that a[l]>a[j]>a[i], then we will not update dp[l] for it, because |a[l]−a[j]|<|a[l]−a[i]|. Also, we will not update the answer for l such that |a[l]−a[j]|<|a[l]−a[i]|, that is, if a[l]>a[i]+a[j]−a[i]2. Therefore, further we will be interested only in the numbers from the segment [a[i],a[i]+a[j]−a[i]2].

Let's note that we have reduced the length of the segment by 2 times. That is, there will be no more such iterations than O(logn). You can find the rightmost number belonging to a segment using the segment tree. The answer for the segment li,ri will be minli⩽j<rdp[l] at the moment ri. This can also be efficiently found using the segment tree. The final asymptotics of the solution is O(nlog2n+qlogn).

There is also a solution for O(n√n+qlogq) that passes all the tests.

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 228;

template<class T, class Fun = function<T(const T &, const T &)>>
struct SegTree {
    Fun f;
    vector<T> t;
    int n;

    SegTree(int sz, const Fun &g, T default_value = T()) : f(g) {
        n = 1;
        while (n < sz) n <<= 1;
        t.resize(n * 2, default_value);
    }

    SegTree(vector<T> &a, const Fun &g, T default_value = T()) : SegTree(a.size(), g, default_value) {
        for (int i = 0; i < n; ++i) t[i + n] = a[i];
        for (int i = n - 1; i >= 1; --i) t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    void upd(int i, T x) {
        i += n;
        t[i] = f(t[i], x);
        for (i >>= 1; i > 1; i >>= 1) t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    T get(int l, int r) {
        T resL = t[0], resR = t[0];
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resL = f(resL, t[l++]);
            if (r & 1) resR = f(t[--r], resR);
        }
        return f(resL, resR);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> posts(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        posts[r].push_back({l, i});
    }
    SegTree<int> ind(n + 1, [](int x, int y) { return max(x, y); }, -1);
    SegTree<int> dp(n + 1, [](int x, int y) { return min(x, y); }, inf);
    vector<int> answer(q);
    for (int i = 0; i < n; i++) {
        {
            int limit = n + 1;
            while (true) {
                int j = ind.get(a[i], limit);
                if (j == -1)
                    break;
                dp.upd(j, abs(a[j] - a[i]));
                limit = a[i] + (a[j] - a[i] + 1) / 2;
            }
        }
        {
            int limit = 0;
            while (true) {
                int j = ind.get(limit, a[i]);
                if (j == -1)
                    break;
                dp.upd(j, abs(a[j] - a[i]));
                limit = a[i] - (a[i] - a[j] + 1) / 2 + 1;
            }
        }
        ind.upd(a[i], i);
        for (pair<int, int> j: posts[i]) {
            answer[j.second] = dp.get(j.first, i);
        }
    }
    for (int i: answer) {
        cout << i << "n";
    }

    return 0;
}

```
