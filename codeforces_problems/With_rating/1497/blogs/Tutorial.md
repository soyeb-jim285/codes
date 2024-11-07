# Tutorial

We are really sorry to make the round unrated. Anyway, we hope that you enjoyed the problems!

[1497A - Meximization](../problems/A._Meximization.md "Codeforces Round 708 (Div. 2)")

Idea: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")

 **Tutorial**
### [1497A - Meximization](../problems/A._Meximization.md "Codeforces Round 708 (Div. 2)")

To maximize the sum of $\textbf{MEX}$ on prefixes we will use a greedy algorithm. Firstly we put all unique elements in increasing order to get maximal $\textbf{MEX}$ on each prefix. It is easy to see that replacing any two elements after that makes both $\textbf{MEX}$ and sum of $\textbf{MEX}$ less.

In the end we put all elements that are not used in any order because $\textbf{MEX}$ will not change and will still be maximal.

 **Implementation**
```cpp
// один манул
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> b;
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] != a[i - 1]) {
                b.emplace_back(a[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i > 0 && a[i] == a[i - 1]) {
                b.emplace_back(a[i]);
            }
        }
        for (auto x : b) cout << x << ' ';
        cout << 'n';
    }
    return 0;
    cout << "amogus";
}
```
[1497B - M-arrays](../problems/B._M-arrays.md "Codeforces Round 708 (Div. 2)")

Idea: [Artyom123](https://codeforces.com/profile/Artyom123 "Master Artyom123")

 **Tutorial**
### [1497B - M-arrays](../problems/B._M-arrays.md "Codeforces Round 708 (Div. 2)")

Let's take each number modulo m. Now let cntx be the amount of x in array a.

* If cnt0≠0, then all 0 should be put in a single array, answer increases by 1.
* For each number x≠0 we put it in an array x,m−x,x,m−x,… In this array the amount of x and the amount of m−x should differ not more than by 1, that's why we need to make max(0,|cntx−cntm−x|−1) arrays, containing a single number (x or m−x) that is more common.
 **Implementation**
```cpp
//два манула
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        map<int, int> cnt;
        while (n--) {
            int x;
            cin >> x;
            cnt[x % m]++;
        }
        int ans = 0;
        for (auto &c : cnt) {
            if (c.first == 0) ans++;
            else if (2 * c.first == m) {
                ans++;
            } else if (2 * c.first < m || cnt.find(m - c.first) == cnt.end()) {
                int x = c.second, y = cnt[m - c.first];
                ans += 1 + max(0, abs(x - y) - 1);
            }
        }
        cout << ans << 'n';
    }
    return 0;
}
```
[1497C1 - k-LCM (easy version)](../problems/C1._k-LCM_(easy_version).md "Codeforces Round 708 (Div. 2)")

Idea: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")

 **Tutorial**
### [1497C1 - k-LCM (easy version)](../problems/C1._k-LCM_(easy_version).md "Codeforces Round 708 (Div. 2)")

* If n is odd, then the answer is (1,⌊n2⌋,⌊n2⌋)
* If n is even, but is not a multiple of 4, then the answer is (n2−1,n2−1,2).
* If n is a multiple of 4, then the answer is (n2,n4,n4).
 **Implementation**
```cpp
// три манула
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        int n, k;
        cin >> n >> k;
        if (n % 2) cout << 1 << ' ' << n / 2 << ' ' << n / 2 << 'n';
        else if (n % 2 == 0 && n % 4) cout << 2 << ' ' << n / 2 - 1 << ' ' << n / 2  - 1 << 'n';
        else cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << 'n';
    }
    return 0;
}
```
[1497C2 - k-LCM (hard version)](../problems/C2._k-LCM_(hard_version).md "Codeforces Round 708 (Div. 2)")

Idea: [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27")

 **Tutorial**
### [1497C2 - k-LCM (hard version)](../problems/C2._k-LCM_(hard_version).md "Codeforces Round 708 (Div. 2)")

In this solution we will reuse the solution for k=3.

The answer will be 1,1,…,1 (k−3 times) and the solution a,b,c of the easy version for n−k+3.

(1+1+…+1)+(a+b+c)=(k−3)+(n−k−3)=n. 

Also LCM(1,1,…,1,a,b,c)=LCM(a,b,c)≤n−k+32≤n2.

 **Implementation**
```cpp
// четыре манула
#include <bits/stdc++.h>
using namespace std;

vector<int> solve3(int n) {
    if (n % 2 == 1) return {1, n / 2, n / 2};
    if (n % 4 == 0) return {n / 2, n / 4, n / 4};
    if (n % 2 == 0) return {2, n / 2 - 1, n / 2 - 1};
}

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        int n, k;
        cin >> n >> k;
        vector<int> added = solve3(n - k + 3);
        for (int i = 0; i < k; ++i) {
            cout << (i <3 ? added[i] : 1) << ' '; // <3
        }
        cout << 'n';
    }
    return 0;
}
```
[1497D - Genius](../problems/D._Genius.md "Codeforces Round 708 (Div. 2)")

Idea: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")

 **Tutorial**
### [1497D - Genius](../problems/D._Genius.md "Codeforces Round 708 (Div. 2)")

Let's consider a graph where vertexes are problems and there is an edge {i,j} between vertexes i and j with weight |ci−cj|. Each edge has a unique weight. Let's prove that. Let's assume that weight=|2i−2j| and i>j. Then in binary form weight has its k-th bit set true if and only if j≤k<i. Then for each unique pair {i,j} weight is unique too since the corners of a subsegment with true bits are unique.

Let dpi be the maximal amount of points that may be earned ending with problem i. Initially dpi=0 for each 1≤i≤n. Let's consider all edges in increasing order (because IQ should increase). To do that we can consider j in increasing order from 2 to n and then i in decreasing order from j−1 to 1. It is also explained by the binary form of the weight.

Now let's relax dp values. When we consider an edge {i,j},tagi≠tagj we try to solve problem i after solving dpj problems ending with j, and problem i after solving dpi problems ending with i. It means that dpi=max(dpi,dpj+p),dpj=max(dpj,dpi+p) at the same time, where p=|si−sj|. After considering all edges the answer is the maximal value among all dp values.

 **Implementation**
```cpp
// пять манулов
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        int n;
        cin >> n;
        vector<long long> s(n), tag(n), dp(n, 0);
        for (int i = 0; i < n; ++i) cin >> tag[i];
        for (int i = 0; i < n; ++i) cin >> s[i];
        for (int j = 1; j < n; ++j) {
            for (int i = j - 1; i >= 0; --i) {
                if (tag[i] == tag[j]) continue;
                long long dpi = dp[i], dpj = dp[j], p = abs(s[i] - s[j]);
                dp[i] = max(dp[i], dpj + p);
                dp[j] = max(dp[j], dpi + p);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << 'n';
    }
    return 0;
}
```
[1497E1 - Square-Free Division (easy version)](../problems/E1._Square-Free_Division_(easy_version).md "Codeforces Round 708 (Div. 2)")

Idea: [Artyom123](https://codeforces.com/profile/Artyom123 "Master Artyom123")

 **Tutorial**
### [1497E1 - Square-Free Division (easy version)](../problems/E1._Square-Free_Division_(easy_version).md "Codeforces Round 708 (Div. 2)")

For factorization of x=pq11⋅pq22⋅⋯⋅pqkk let's define mask(x)=pq1mod21⋅pq2mod22⋅⋯⋅pqmmod2m. After that it is easy to see that x⋅y is a perfect square if and only if mask(x)=mask(y).

Now let's say ai=mask(ai) for all 1≤i≤n. The problem we need to solve is: split the array into minimal amount of non-intersecting subsegments so that on each subsegment all numbers are different. Since k=0 we can do that using a greedy idea. If we consider an element that has not been in our current segment, then we add it to the segment. If it's already taken, then we should end our current segment and start a new one.

 **Implementation**
```cpp
// шесть манулов
#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1e7;

vector<int> primes;
int mind[MAXA + 1];

int main() {

    for (int i = 2; i <= MAXA; ++i) {
        if (mind[i] == 0) {
            primes.emplace_back(i);
            mind[i] = i;
        }
        for (auto &x : primes) {
            if (x > mind[i] || x * i > MAXA) break;
            mind[x * i] = x;
        }
    }
    
    int T;
    cin >> T;
    while (T --> 0) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n, 1);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            int cnt = 0, last = 0;
            while (x > 1) {
                int p = mind[x];
                if (last == p) {
                    ++cnt;
                } else {
                    if (cnt % 2 == 1) a[i] *= last;
                    last = p;
                    cnt = 1;
                }
                x /= p;
            }
            if (cnt % 2 == 1) a[i] *= last;
        }
        
        int L = 0, ans = 1;
        map<int, int> last;
        for (int i = 0; i < n; ++i) {
            if (last.find(a[i]) != last.end() && last[a[i]] >= L) {
                ++ans;
                L = i;
            }
            last[a[i]] = i;
        }
        cout << ans << 'n';
    }
    
    return 0;
}
```
[1497E2 - Square-Free Division (hard version)](../problems/E2._Square-Free_Division_(hard_version).md "Codeforces Round 708 (Div. 2)")

Idea: [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27")

 **Tutorial**
### [1497E2 - Square-Free Division (hard version)](../problems/E2._Square-Free_Division_(hard_version).md "Codeforces Round 708 (Div. 2)")

Let's use the same definitions as in tutorial of E1. So after making ai=mask(ai) for all 1≤i≤n we need to split the whole array into minimal amount of contiguous subsegments with all different elements. Also, we can change k elements how we want.

Firstly, for each 1≤i≤n and 0≤j≤k let's find lefti,j  — such minimal index l, so that after making j changes the segment al,al+1,…,ai contains only distinct values. For fixed j if i is increased then lefti,j increases, too, that's why for fixed j we can use the two pointers technique. This allows us to calculate lefti,j in O(n⋅k).

Now for each 1≤i≤n and 0≤j≤k let's calculate dpi,j  — the minimal amount of contiguous subsegments that prefix a1,a2,…,ai is possible to divide into after making j changes. For each j let's consider 0≤x≤j  — the amount of changes on the last subsegment. Let's say that l=lefti,x then dpi,j=min(dpi,j,dpl−1,j−x+1). This is done in O(n⋅k2) so the total complexity of the solution after making ai=mask(ai) is O(n⋅k2).

 **Implementation**
```cpp
// семь манулов
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 1;
const int MAXA = 1e7;
vector<int> primes;
int mind[MAXA + 1];

int main() {
    for (int i = 2; i <= MAXA; ++i) {
        if (mind[i] == 0) {
            primes.emplace_back(i);
            mind[i] = i;
        }
        for (auto &x : primes) {
            if (x > mind[i] || x * i > MAXA) break;
            mind[x * i] = x;
        }
    }
    vector<int> cnt(MAXA + 1);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k; // уже k манулов
        vector<int> a(n, 1);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            int cnt = 0, last = 0;
            while (x > 1) {
                int p = mind[x];
                if (last == p) {
                    ++cnt;
                } else {
                    if (cnt % 2 == 1) a[i] *= last;
                    last = p;
                    cnt = 1;
                }
                x /= p;
            }
            if (cnt % 2 == 1) a[i] *= last;
        }
        vector<vector<int>> mnleft(n, vector<int>(k + 1));
        for (int j = 0; j <= k; j++) {
            int l = n, now = 0;
            for (int i = n - 1; i >= 0; i--) {
                while (l - 1 >= 0 && now + (cnt[a[l - 1]] > 0) <= j) {
                    l--;
                    now += (cnt[a[l]] > 0);
                    cnt[a[l]]++;
                }
                mnleft[i][j] = l;
                if (cnt[a[i]] > 1) now--;
                cnt[a[i]]--;
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        for (auto &c : dp[0]) c = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j > 0) dp[i][j] = dp[i][j - 1];
                for (int lst = 0; lst <= j; lst++) {
                    dp[i][j] = min(dp[i][j], dp[mnleft[i - 1][lst]][j - lst] + 1);
                }
            }
        }
        int ans = INF;
        for (auto &c : dp.back()) ans = min(ans, c);
        cout << ans << "n";
    }
    return 0;
}
```
