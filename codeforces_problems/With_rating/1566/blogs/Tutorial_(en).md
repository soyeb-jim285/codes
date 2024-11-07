# Tutorial_(en)

We hope that you enjoyed the contest. Let's get right into the editorial:

 **A: Median Maximization**[1566A - Median Maximization](../problems/A._Median_Maximization.md "Codeforces Global Round 16")

 **First solution****Hint 1**Which numbers smaller than the median should be taken?

 **Hint 2**Which numbers bigger than the median should be taken?

 **Hint 3**Greedy algorithm.

 **Editorial**Let's consider the array of n elements in non-decreasing order. We can make numbers before the median equal to zero, after that we have m=⌊n2⌋+1 numbers, which sum should be n and the minimal of them (i.e. median value) should be maximized.

To do so, it is enough to make all these numbers equal ⌊sm⌋, and then add what's left to the last number (smodm). It's easy to see that such array matches all the conditions and it is impossible to make median greater.

 **Implementation (C++, shishin)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        int n, s;
        cin >> n >> s;
        int m = n / 2 + 1;
        cout << s / m << 'n';
    }
    return 0;
}
```
 **Implementation (Python 3, shishin)**
```cpp
t = int(input())
for test in range(t):
    n, s = map(int, input().split())
    m = n // 2 + 1
    print(s // m)

```
 **Second solution****Hint 1**If it's possible to make the median element m>1 then you can make it m−1.

 **Hint 2**It is possible to make the median element any number from 0 to some M.

 **Hint 3**We can use the binary search for the answer.

 **Editorial**Let's run a binary search for the answer. This will work because if the answer M then we can decrease the median element by d and add d to the max element, so we can get any median element from 1 to M, but we can't get more than M. In the binary search we will use the greedy technique. All numbers less than the median can be 0 and all numbers from the median should be at least M. So there are m=⌊n2⌋+1 numbers and each of them should be at least M and we find the M using the binary search. Number M is reachable if M⋅m≤s because we can add s−M⋅m to the maximal number and the median will be M. Otherwise, the median element can not be M.

 **Implementation (C++, shishin)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        long long n, s;
        cin >> n >> s;
        long long L = 0, R = s + 1;
        while (R - L > 1) {
            long long M = (L + R) / 2;
            long long m = n / 2 + 1;
            if (m * M <= s) {
                L = M;
            } else {
                R = M;
            }
        }
        cout << L << 'n';
    }
    return 0;
}
```
 **Implementation (Python, shishin)**
```cpp
t = int(input())
for test in range(t):
    n, s = map(int, input().split())
    L = 0
    R = 10**10
    while R - L > 1:
        M = (L + R) // 2
        m = n // 2 + 1
        if m * M <= s:
            L = M
        else:
            R = M
    print(L)

```
 **B: MIN-MEX Cut**[1566B - MIN-MEX Cut](../problems/B._MIN-MEX_Cut.md "Codeforces Global Round 16")

 **Hint 1**The answer is never greater than 2.

 **Hint 2**If a string consists only of 1, then the answer is 0.

 **Hint 3**If all zeroes are consequent, then the answer is 1.

 **Editorial**The answer is never greater than 2, because MEX of the whole string is not greater than 2.

The answer is 0 only if there are no zeroes in the string.

Now we need to understand, when the answer is 1 or when it is 2. The sum of MEX is 1 only if all zeroes create a single segment without ones. Then we can cut this segment out, its MEX is 1, everything else is ones, their total MEX is 0.

If the zeroes do not create a single segment without ones, the there are two such zeroes that there is a 1 between them. Then either these zeroes are in a single segment with the 1, so total MEX is not less than 2 or these zeroes are in different segments and the answer is still not less then 2.

 **Implementation (C++, shishin)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        string s;
        cin >> s;
        int zeroes = count(s.begin(), s.end(), '0');
        if (zeroes == 0) {
            cout << 0 << 'n';
            continue;
        }
        int first = s.find('0');
        int last = s.rfind('0');
        if (last - first + 1 == zeroes) {
            cout << 1 << 'n';
        } else {
            cout << 2 << 'n';
        }
    }
    return 0;
}
```
 **Implementation (Python, shishin)**
```cpp
t = int(input())
for test in range(t):
    s = input()
    zeroes = s.count('0')
    if zeroes == 0:
        print(0)
        continue

    first = s.find('0')
    last = s.rfind('0')
    if last - first + 1 == zeroes:
        print(1)
    else:
        print(2)

```
 **C: MAX-MEX Cut**[1566C - MAX-MEX Cut](../problems/C._MAX-MEX_Cut.md "Codeforces Global Round 16")

 **First solution****Hint 1**You can cut out the columns with both 0 and 1.

 **Hint 2**Now in each column there are only 0 or only 1. We only need to solve the problem for a string because the columns can be replaced by one digit (they consist of equal elements).

 **Hint 3**Let's be greedy, to each zero we will "join" not more than one 1.

 **Editorial**Let's solve the same problem but for a string:

It's needed to cut a binary string into segments so that each its element is in exactly one segment and the sum of MEX for all segments is maximal.

Initially we will say that the string is cut into segments of length 1. Then the answer is the number of zeroes in the string. After that the answer is increased every time we merge a segment of 0 with a segment of 1. Each such merge increases the answer by 1. Let's make the merges greedily, maximizing the number of merges. Let's consider the first zero. If the previous element is a 1, let's merge them and consider the next zero. Else, if the next element is a 1, let's merge them and consider the next zero. Else, the next element is a zero and we should consider it instead of the current zero the same way. By doing so we get the answer as the number of zeroes + the number of merges.

Now let's solve the initial problem. We can cut out the columns that contain both 0 and 1, because their MEX is already maximized and the answer will not become worse.

Now we solve the problem for all remaining bi-tables independently. Each their column consists either only of 0 or only of 1 so both rows are equal. We will solve the problem for one row of each remaining bi-table as mentioned before and then sum up the values to get the answer.

 **Implementation (C++, shishin)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
    int ans = count(s.begin(), s.end(), '0');
    int n = s.size();
    bool a = false, b = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') a = true;
        if (s[i] == '1') b = true;
        if (a && b) {
            ++ans;
            a = b = false;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T --> 0) {
        int n, ans = 0;
        string a, b;
        cin >> n >> a >> b;
        string s = "";
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                ans += 2 + solve(s);
                s = "";
            } else {
                s += a[i];
            }
        }
        cout << ans + solve(s) << 'n';
    }
    return 0;
}
```
 **Second solution (two similar solutions)**This problem could be solved in many ways using the dp. We will consider these solutions in short.

Let's say that dpi — is the answer for a prefix until i. Then there are different approaches:

We can calculate the dp values, iterating through all possible MEX values on the last segment. For example, if we want to make MEX equal 2 on the last segment, then we need to find the closest 0 and the closest 1 to position i. Let it be last0 and last1. Then we should recalc the dp like this dpi=max(dpi,dpj−1+2), where j=min(last0,last1), because we take the shortest segment ending in i which has both 0 and 1 and after that we add the answer for this segment and for prefix that ends in j−1.

 **Implementation(C++, kpw29)**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
typedef vector<int> vi;

//Did you REAALLY consider sample tests?
void solve(int tc) {
    string s[2];
    int n;
    cin >> n;
    cin >> s[0] >> s[1];
    vi dp(n + 1, 0);
    vi last(2, -1);
    
    auto take = [&](int i, bool take0, bool take1) {
        int MEX = 0;
        if (take0) {
            if (take1) MEX = 2;
            else MEX = 1;
        }
        
        int index = i;
        if (take0) index = min(index, last[0]);
        if (take1) index = min(index, last[1]);
        
        if (index != -1) return MEX + dp[index - 1];
        return -100000;
    };
    
    FOR(i, 1, n) {
        vi val(2);
        rep(j, 0, 2) last[s[j][i-1] - '0'] = i;
        dp[i] = dp[i-1];
        dp[i] = max(dp[i], take(i, 1, 0));
        dp[i] = max(dp[i], take(i, 0, 1));
        dp[i] = max(dp[i], take(i, 1, 1));
    }
    
    cout << dp[n] << "n";
}
 
int main() {
    int tests;
    cin >> tests;
    FOR(test, 1, tests) {
        solve(test);
    }
}
```
Another possible solution with dp is based on the fact that we should not take any segments with length more than x, where x is some small number. We can just take some random big enough x and not prove anything. There exists a solution which does not consider segments with length bigger than 5.

 **Implementation (C++, physics0523)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
int mex(string s){
  int fl=0;
  for(auto &nx : s){
    if(nx=='0'){fl|=1;}
    else if(nx=='1'){fl|=2;}
  }
  if(fl==3){return 2;}
  if(fl==1){return 1;}
  return 0;
}
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    string s1,s2;
    cin >> n >> s1 >> s2;
    vector<int> dp(n+1,0);
    for(int i=0;i<n;i++){
      string s;
      for(int j=0;j<5;j++){
        if(i+j>=n){break;}
        s.push_back(s1[i+j]);
        s.push_back(s2[i+j]);
        dp[i+j+1]=max(dp[i+j+1],dp[i]+mex(s));
      }
    }
    cout << dp[n] << 'n';
  }
  return 0;
}
```
 **D: Seating Arrangements**[1566D2 - Seating Arrangements (hard version)](../problems/D2._Seating_Arrangements_(hard_version)_.md "Codeforces Global Round 16") 

 **Hint 1**Each person can be seated on some subsegment of places with people with the same level of sight.

 **Hint 2**If n=1 we should seat people on the maximal possible place.

 **Hint 3**The places available for some person may be a subsegment of a row or a suffix of a row + some full rows + a prefix of a row.

 **Editorial**Let's consider all seats in increasing order of their indices. For each seat we can consider the level of sight of a person that takes that seat. The considered sequence is non-decreasing. This means that people with the same level of sight should take consequent seats and for each level of sight x we can determine which seats will be taken by people with level of sight x.

Now we should find out how do people with level of sight x sit in the cinema. For that x we know that people with that level of sight should take places with indices from l to r.

Let's seat people with the same level of sight greedily. If all places from l to r are in the same row, then we should seat people in decreasing order of seat indices. Otherwise, these seats form a suffix of some row (maybe empty), some full rows (maybe zero), a prefix of some row (maybe empty). Firstly we need to seat people on the suffix in decreasing order of seat indices. This is not worse than other seatings, because the seats before that suffix may be taken in future and total inconvenience will increase. Seats on the prefix should be taken last of all in decreasing order of seat indices. This is not worse than other seatings, because if some people sit on that prefix then they will bother people on the right, increasing the total inconvenience. Full rows should be taken in decreasing order of seat indices, this does not increase the total inconvenience at all. So we should start by seating poeple on the suffix, then we should cover full rows and finally we should cover the prefix. In each case places should be taken in decreasing order of seat indices.

The constraints for m are low, so each time we want to seat someone we can consider all places in the row and find how many people increase our inconvenience.

 **Implementation (C++, pashka)**
```cpp
#include <bits/stdc++.h>
#define long long long int
using namespace std;
 
// @author: pashka
 
void solve_test() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n * m);
    for (int i = 0; i < n * m; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n * m; i++) {
        a[i].second = -a[i].second;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        sort(a.begin() + (m * i), a.begin() + (m * i + m));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < j; k++) {
                if (a[i * m + k].second > a[i * m + j].second) res++;
            }
        }
    }
    cout <<res << "n";
}
 
int main() {
    ios::sync_with_stdio(false);
 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }
 
    return 0;
}
```
 **E: Buds Re-hanging**[1566E - Buds Re-hanging](../problems/E._Buds_Re-hanging.md "Codeforces Global Round 16")

 **Hint 1**Re-hanging a bud to a leaf decreases the total amount of leaves by 1.

 **Hint 2**Buds can be re-hanged that way so in the end there is only a root, buds that are connected to the root and leaves connected to the root or to the buds.

 **Hint 3**Now the answer depends only on the total amount of vertices, on the amount of buds and on the fact whether there is a leaf connected to the root or not.

 **Editorial**If we re-hang a bud from its parent to the root, the amount of leaves either doesn't change (if the parent has other children), or increases by 1. By doing that we don't make the answer worse, because if there are leaves except for bud's leaves, then we can re-hang the bud to some leaf, decreasing the amount of leaves by 1. So let's re-hang all buds to the root, until there are no free buds left.

Now we will assume that all buds are hung to the root, and their amount is k. The answer is either n−2⋅k if there is no leaf, hung to the root, or n−2⋅k−1 if there is a leaf, hung to the root. Why is it so? Initially, there are n−k−1 leaves (total amount of nodes — the amount of buds — root). If there is a leaf, hung to the root, then we can hang a bud to it, then hang a bud to the previous bud's leaf, and keep doing so until we use all k buds. Then there are k re-hangs, each of them decreases the answer by 1. So the final answer is n−k−1−k=n−2⋅k−1. If there is no leaves hung to the root, then we can hang a bud to another bud's leaf, then a bud to the previous bud's leaf, and so on until we use k−1 buds. The final answer in this case is n−k−1−(k−1)=n−2⋅k. It is not possible to make the answer less, because each re-hang decreases the answer by \le 1 and each re-hang we make decreases it exactly by 1 and we use all re-hangs.

 **Implementation (C++, shishin)**
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> type; // -1  -- default, 0 -- root, 1 -- leaf, 2 -- bud

void dfs(int v, int p) {
    bool leaves = false;
    for (auto to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        if (type[to] == 1) leaves = true;
    }
    if (v != p) {
        if (!leaves) type[v] = 1;
        else type[v] = 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T --> 0) {
        int n;
        cin >> n;
        g.assign(n, vector<int>());
        type.assign(n, -1);
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        type[0] = 0;
        dfs(0, 0);
        bool root_leaf = false;
        for (auto v : g[0]) {
            if (type[v] == 1) {
                root_leaf = true;
            }
        }
        int k = 0;
        for (int i = 0; i < n; ++i) {
            k += (type[i] == 2);
        }
        cout << n - 2 * k - root_leaf << 'n';
    }
    return 0;
}
```
 **F: Points Movement**[1566F - Points Movement](../problems/F._Points_Movement.md "Codeforces Global Round 16")

 **Hint 1**If a segment already contains a point then it can be thrown out of the consideration.

 **Hint 2**If there is a segment that contains some segment, we can save only the smaller one.

 **Hint 3**If you already know which segments will be visited by some point, how you should calculate the answer for this point?

 **Hint 4**For some segment, which points should visit it?

 **Editorial**Firstly, if a point has initially visited some segment, then we can throw it out of consideration. It means that all segments that cover at least one point can be thrown out. This can be done using the binary search for each segment separately.

Secondly, if a segment A is contained in a segment B (i.e. lB≤lA≤rA≤rB), then a point that visited A will visit B, too. It means that we should save only those segments that do not contain any other segments.

This can be done using a Fenwick tree. Initially, all values in the tree are zeroes. We will consider the segments in decreasing order of l. Let's assume we are considering segment i. If there is an already considered segment j (rj≤ri), then segment j is in segment i. It is so because li≤lj because of the considering order, so li≤lj≤rj≤ri. To find the amount of such j it is enough to find the amount of 1 on a prefix until ri in the Fenwick tree. Now when we considered the segment i we set 1 in the Fenwick tree on position ri.

After that there are only segments that do not contain any other segments and they are not initially visited by any point. We will consider only these segments.

Let's say that a segment is assigned to a point if that point visits this segment. Let's find out how to calculate the answer for one point if we already know the set of segments that are assigned to it. Let's consider the segments that are on the left to the point and say that the maximal distance from the point to these segments is a. In the same way let b be the maximal distance from the point to the segments on the right. Then the answer for the point is 2⋅min(a,b)+max(a,b).

Now if a segment is between two neighbouring points, then it should be assigned to one of these points. (If a segment is to the left from the leftmost point or to the right from the rightmost point then it should be assigned to the leftmost point or to the rightmost point respectively). Now let's consider the segments between two neighbouring points. These segments are ordered by the left ends and by the right ends at the same time. Some prefix of these segments should be assigned to the left point, other segments (suffix) should be assigned to the right point.

Now let's solve the problem using the dynamic programming. Let dp[i][j] be the answer if we assigned the segments for first i points and there are j segments assigned to the i-th point that are to the right from it. There is a linear amount of dp states. Let's learn to calculate the dp. We will consider the dp states in increasing order of i and, after that, j. Let b be the distance from i-th point to j segment after it. Then dp[i][j]=min0≤k≤x(dp[i−1][k]+2⋅min(b,ai,k)+max(b,ai,k)), where ai,k — is the distance from i-th point to (k+1)-th segment after (i−1)-th point and x is the amount of segments between points i and (i+1). But this is a quadratic dp. Now we can find out that for some prefix of segments after (i−1)-th point ai,k is greater than b and for some suffix it is less than b. The length of that prefix may be found using the binary search or two pointers. For k on that prefix the dp will be dp[i−1][k]+xi−rk+1+2⋅b, and for k on the suffix — dp[i−1][k]+2⋅(xi−rk+1)+b. In these formulas everything except b depends on i and k. It means that we can calculate dp quickly using prefix and suffix minimums.

The answer is dp[n][x], where x is the amount of segments to the right of the rightmost point.

 **Implementation (C++, Artyom123)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define ll long long 

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

struct segment_tree {
    vector<int> t;

    segment_tree(int n) {
        t.assign(4 * n, INF);
    }

    void mod(int v, int vl, int vr, int id, int val) {
        if (vr - vl == 1) {
            t[v] = min(t[v], val);
            return;
        }
        int vm = (vl + vr) / 2;
        if (id < vm) mod(2 * v + 1, vl, vm, id, val);
        else mod(2 * v + 2, vm, vr, id, val);
        t[v] = min(t[v], val);
    }

    int get(int v, int vl, int vr, int l, int r) {
        if (vl >= l && vr <= r) return t[v];
        if (r <= vl || l >= vr) return INF;
        int vm = (vl + vr) / 2;
        return min(get(2 * v + 1, vl, vm, l, r), get(2 * v + 2, vm, vr, l, r));
    }
};

bool cmp(const pii &a, const pii &b) {
    return a.se - a.fi < b.se - b.fi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (auto &c : a) cin >> c;
        sort(all(a));
        vector<pii> seg1(m);
        vector<int> dl;
        for (auto &c : seg1) {
            cin >> c.fi >> c.se;
            dl.pb(c.fi);
        }
        sort(all(dl));
        dl.resize(unique(all(dl)) - dl.begin());
        sort(all(seg1), cmp);
        map<int, int> ma;
        for (int i = 0; i < (int)dl.size(); i++) ma[dl[i]] = i;
        segment_tree tr((int)dl.size());
        vector<pii> seg;
        for (auto &c : seg1) {
            int id = lower_bound(all(a), c.fi) - a.begin();
            if (id < (int)a.size() && a[id] <= c.se) continue;
            if (tr.get(0, 0, dl.size(), ma[c.fi], dl.size()) <= c.se) continue;
            tr.mod(0, 0, dl.size(), ma[c.fi], c.se);
            seg.pb(c.fi, c.se);
        }
        m = seg.size();
        sort(all(seg));
        vector<vector<pii>> g(n + 1);
        int L = -1, R = m;
        while (R - L > 1) {
            int M = (L + R) / 2;
            if (seg[M].se < a[0]) L = M;
            else R = M;
        }
        for (int i = 0; i <= L; i++) g[0].pb(seg[i]);
        for (int i = 0; i < n; i++) {
            int RIGHT = INF;
            if (i + 1 < n) RIGHT = a[i + 1];
            int id = upper_bound(all(seg), make_pair((int)a[i], (int)a[i])) - seg.begin();
            if (id == m) continue;
            int L = id - 1, R = m;
            while (R - L > 1) {
                int M = (L + R) / 2;
                if (seg[M].se < RIGHT) L = M;
                else R = M;
            }
            for (int j = id; j <= L; j++) g[i + 1].pb(seg[j]);
        }
        vector<vector<ll>> dp(n), pr(n), suff(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(g[i + 1].size() + 1, INFLL);
            pr[i].resize(g[i + 1].size() + 1, INFLL);
            suff[i].resize(g[i + 1].size() + 1, INFLL);
        }
        for (int j = 0; j <= (int)g[1].size(); j++) {
            ll x = 0;
            if (g[0].size()) x = a[0] - g[0][0].se;
            ll y = 0;
            if (j) y = g[1][j - 1].fi - a[0];
            dp[0][j] = 2 * min(x, y) + max(x, y);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= (int)g[i].size(); j++) {
                if (j > 0) pr[i - 1][j] = pr[i - 1][j - 1];
                pr[i - 1][j] = min(pr[i - 1][j], dp[i - 1][j] - (j == (int)g[i].size() ? a[i] : g[i][j].se));
            }
            for (int j = (int)g[i].size(); j >= 0; j--) {
                if (j + 1 <= (int)g[i].size()) suff[i - 1][j] = suff[i - 1][j + 1];
                suff[i - 1][j] = min(suff[i - 1][j], dp[i - 1][j] - 2 * (j == (int)g[i].size() ? a[i] : g[i][j].se));
            }
            int L = (int)g[i].size();
            for (int j = 0; j <= (int)g[i + 1].size(); j++) {
                ll y = 0;
                if (j) y = g[i + 1][j - 1].fi - a[i];
                while (L > 0 && a[i] - g[i][L - 1].se <= y) L--;
                if (L > 0) dp[i][j] = min(dp[i][j], 2 * y + a[i] + pr[i - 1][L - 1]);
                dp[i][j] = min(dp[i][j], y + 2 * a[i] + suff[i - 1][L]);
            }
        }
        cout << dp[n - 1].back() << "n";
    }
    return 0;
}
```
 **G: Four Vertices**[1566G - Four Vertices](../problems/G._Four_Vertices.md "Codeforces Global Round 16")

 **Hint 1**The answer always consists either of three edges with common end or of two edges that don't have any common ends.

 **Hint 2**To find the answer of the second type you can leave in the graph only those edges that are in the list of three smallest edges for both ends.

 **Hint 3**Let's consider those cases when the minimal edge is in the answer or not in the answer.

 **Editorial**Observation: the answer always consists either of three edges that have one common end or of two edges that do not have any common ends.

To find the answer of the first type it is enough to maintain three minimal edges for each vertex. 

To find the answer of the second type we will use this observation: we can leave in the graph only those edges that are in the set of three minimal edges for each their end. Let's prove that. Let's assume that the answer consists of two edges (a,b) and (c,d) and there are at least three edges (a,a1), (a,a2), (a,a3) less than (a,b). Then the edge (a,b) can be swapped by one of these edges because at least one of te integers a1, a2, a3 is not equal to c and d. Then we will maintain the set of all these edges.

Now let's consider two cases. Let (a,b) be the minimal edge. If it is in the answer then we need to find the minimal edge, that does not have any common vertices with (a,b). In this case there are at most 6 ``bad'' edges because the degrees of each vertex in the graph that consists only of remaining edges do not exceed 3. It means that we have to consider O(1) variants. If (a,b) is not in the answer, then there are two edges in the answer that have vertices a and b as one of their ends. But there are at most 9 such pairs of edges, so we have to consider only O(1) variants.

So the final answer is the minimum of answers of both types.

 **Implementation (C++, Kirill22)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define sz(a) (int) (a).size()

const int N = 1e5;
vector<pair<int, int>> g[N];
map<pair<int, int>, int> cost;
set<pair<int, int>> a[N], b[N];
multiset<long long> dp;
set<pair<int, pair<int, int>>> dp2;

void solve() {
    auto minr = *dp2.begin();
    long long ans = 1e18;
    if (sz(dp)) {
        ans = min(ans, *dp.begin());
    }
    int v = minr.second.first, u = minr.second.second;
    auto it = dp2.begin();
    for (int i = 0; i < 6 && it != dp2.end(); i++, it = next(it)) {
        auto res = *it;
        int v2 = res.second.first, u2 = res.second.second;
        if (v2 != v && v2 != u && u2 != v && u2 != u) {
            ans = min(ans, (long long) res.first + minr.first);
        }
    }
    for (auto [w, v2] : a[v]) {
        for (auto [w2, u2] : a[u]) {
            if (v2 != u2 && v2 != u && u2 != v) {
                ans = min(ans, (long long) w + w2);
            }
        }
    }
    cout << ans << 'n';
}

void del(int v) {
    if (sz(a[v]) >= 3) {
        long long res = 0;
        for (auto [w, to] : a[v]) {
            res += w;
        }
        dp.erase(dp.find(res));
    }
    for (auto [w, to] : a[v]) {
        if (dp2.find({w, {min(v, to), max(v, to)}}) != dp2.end()) {
            dp2.erase({w, {min(v, to), max(v, to)}});   
        }
    }
}

void upd(int v) {
    if (sz(a[v]) >= 3) {
        long long res = 0;
        for (auto [w, to] : a[v]) {
            res += w;
        }
        dp.insert(res);
    }
    for (auto [w, to] : a[v]) {
        if (a[to].find({w, v}) != a[to].end()) {
            dp2.insert({w, {min(v, to), max(v, to)}});  
        } 
    }
}

void relax(int v) {
    while (sz(a[v]) && sz(b[v])) {
        auto A = *a[v].rbegin(), B = *b[v].begin();
        if (A.first <= B.first) break;
        a[v].erase(A);
        b[v].erase(B);
        a[v].insert(B);
        b[v].insert(A);
    }
    while (sz(a[v]) < 3 && sz(b[v])) {
        auto B = *b[v].begin();
        b[v].erase(B);
        a[v].insert(B);
    }
}

void erase(int v, int u, int w) {
    del(v);
    del(u);
    if (a[v].find({w, u}) != a[v].end()) {
        a[v].erase({w, u});
    }
    else {
        b[v].erase({w, u});
    }
    if (a[u].find({w, v}) != a[u].end()) {
        a[u].erase({w, v});
    }
    else {
        b[u].erase({w, v});
    }
    relax(v);
    relax(u);
    upd(v);
    upd(u);
}

void add(int v, int u, int w) {
    del(v);
    del(u);
    b[v].insert({w, u});
    b[u].insert({w, v});
    relax(v);
    relax(u);
    upd(v);
    upd(u);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        if (x > y) swap(x, y);
        cost[{x, y}] = w;
        g[x].push_back({w, y});
        g[y].push_back({w, x});
    }
    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end());
        for (int j = 0; j < sz(g[i]); j++) {
            if (j <= 2) {
                a[i].insert(g[i][j]);
            }
            else {
                b[i].insert(g[i][j]);
            }
        }
        if (sz(a[i]) >= 3) {
            long long res = 0;
            for (auto [w, to] : a[i]) {
                res += w;
            }
            dp.insert(res);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(g[i]); j++) {
            int v = g[i][j].second;
            if (j <= 2) {
                if (a[v].find({g[i][j].first, i}) != a[v].end()) {
                    dp2.insert({g[i][j].first, {min(i, v), max(i, v)}});
                }
            }
        }
    }
    int q;
    cin >> q;
    solve();
    while (q--) {
        int t, v, u;
        cin >> t >> v >> u;
        v--, u--;
        if (v > u) swap(v, u);
        if (t == 0) {
            int w = cost[{v, u}];
            erase(v, u, w);
        }
        else {
            int w;
            cin >> w;
            cost[{v, u}] = w;
            add(v, u, w);
        }
        solve();
    }
}

```
 **H: Xor-quiz**[1566H - Xor-quiz](../problems/H._Xor-quiz.md "Codeforces Global Round 16")

 **Hint 1**Numbers with the same set of prime divisors may be considered as the same numbers.

 **Hint 2**The amount of distinct sets of prime divisors which multiplication does not exceed C for such constraints does not exceed ⌈0.65⋅C⌉.

 **Hint 3**How you should find the xor of all numbers that have the same set of prime divisors?

 **Hint 4**If you know the xor of all numbers with the same set of prime divisors you can recover these numbers randomly.

 **Editorial**Let f(x) be the multiplication of all prime divisors of x. Then let's make queries for all such y that there is at least one such x, 1≤x≤C and f(x)=y. For such constraints there will be at most ⌈0.65⋅C⌉ queries.

Let's group all numbers by f(x). All numbers in one group in any query will be considered together. Let ans(x) be the answer for the query with number x and g(x) be the xor of all number that are not coprime with x. Then g(x)=ans(x)⊕ans(1). Now let's find out how to calculate the xor of all such x that f(x) is divisible by an arbitrary y. Let's take xor of all g(k) where k is a divisor of y greater than 1. Let's prove that by doing that we will get the needed value. If f(x) is divisible by y then such x will be considered 2l−1 times, where l is the amount of prime divisors of y. It means that x will be contained in the final value. Now let's prove that there will be no unintended x values. Let f(x) be not divisible by y. It means that there is suche prime p that y is divisible by p and x is not divisible by p. Then for each divisor a of y that is divisible by p we will assign b=a/p. Then such x will be considered either for both a and b or for none of them. It means that it will be considered an even amount of times. Now to find the xor of all numbers with an arbitrary f(x) we need to consider all x from C to 1 and make f(x)=f(x)⊕f(2x)⊕f(3x)⊕….

Now we only need to find n distinct numbers from 1 to C such that xor of numbers in each group is equal to a specific number. For each group of numbers with given f(x) we will start the Gaussian elimination. Let k be the size of a group and after the Gaussian elimination there are b non-zero numbers. Then if b=k there is a single way to obtain the needed xor. Else there are 2k−b ways to obtain the needed xor. Now let's take some random sets of numbers with the needed xor and calculate dp on these numbers to get take exactly n numbers. If there are several ways we can choose any of them.

 **Implementation (C++, Artyom123)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define ll long long 
#define ld long double

const long long INFLL = 1e18;
const int INF = 1e9 + 1;
const int MAXC = 1e6;
mt19937 gen(time(0));

vector<int> e(MAXC + 5);

void precalc() {
    vector<int> p;
    for (int i = 2; i <= MAXC; i++) {
        if (e[i] == 0) {
            e[i] = i;
            p.pb(i);
        }
        for (int j = 0; j < (int)p.size() && p[j] * i <= MAXC && p[j] <= e[i]; j++) {
            e[p[j] * i] = p[j];
        }
    }
}

int f(int x) {
    int ans = 1;
    vector<int> p;
    while (x > 1) {
        p.pb(e[x]);
        x /= e[x];
    }
    for (int i = 0; i < (int)p.size(); i++) {
        if (i + 1 == (int)p.size() || p[i + 1] != p[i]) ans *= p[i];
    }
    return ans;
}

void gauss(int need, vector<int> &lst, vector<int> &ans, vector<vector<int>> &sz, vector<vector<vector<int>>> &v) {
    int n = lst.size();
    vector<bitset<20>> a(n);
    for (int i = 0; i < n; i++) a[i] = lst[i];
    bitset<20> b = need;
    vector<bitset<260>> l(n);
    for (int i = 0; i < n; i++) l[i][i] = 1;
    int i = 0;
    vector<int> col(20, -1);
    int bas_sz = 0;
    for (int j = 0; j < 20 && i < n; j++) {
        int i1 = i;
        while (i1 < n && a[i1][j] == 0) i1++;
        if (i1 == n) continue;
        swap(a[i], a[i1]);
        swap(l[i], l[i1]);
        bas_sz++;
        col[j] = i;
        for (int i2 = i + 1; i2 < n; i2++) {
            if (a[i2][j]) {
                a[i2] ^= a[i];
                l[i2] ^= l[i];
            }
        }
        i++;
    }
    bitset<20> res;
    bitset<260> path;
    for (int j = 0; j < 20; j++) {
        if (res[j] != b[j] && col[j] == -1) {
            exit(0);
        }
        if (res[j] == b[j]) continue;
        res ^= a[col[j]];
        path ^= l[col[j]];
    }
    if (a.back().count() != 0) {
        for (int i = 0; i < n; i++) {
            if (path[i]) ans.pb(lst[i]);
        }
        return;
    } 
    vector<int> diff_sz(300);
    sz.pb();
    v.pb();
    for (int it = 0; it < 100; it++) {
        bitset<260> now = path;
        for (int i = 0; i < n - bas_sz; i++) {
            if (gen() % 2) now ^= l[bas_sz + i];
        }
        int now_sz = now.count();
        if (diff_sz[now_sz]) continue;
        v.back().pb();
        for (int i = 0; i < n; i++) {
            if (now[i]) v.back().back().pb(lst[i]);
        }
        diff_sz[now_sz] = 1;
        sz.back().pb(now_sz);
    }
}

vector<int> mem(2 * MAXC + 5, -1);

int query(int x) {
    return mem[x];
}

void solve(int n, int c) {
    vector<int> calc(c + 1);
    vector<vector<int>> total(c + 1);
    for (int x = 1; x <= c; x++) total[f(x)].pb(x);
    vector<int> need;
    for (int x = 1; x <= c; x++) {
        if (total[x].size()) need.pb(x);
    }
    cout << need.size() << " ";
    for (auto &c : need) cout << c << " ";
    cout << endl;
    for (auto &c : need) {
        int x;
        cin >> x;
        mem[c] = x;
    }
    int total_xor = query(1);
    for (int x = 1; x <= c; x++) {
        if (total[x].empty()) continue;
        for (int y = x; y <= c; y += x) calc[y] ^= (query(x) ^ total_xor);
    }
    calc[1] = total_xor;
    for (int x = c; x >= 1; x--) {
        if (total[x].empty()) continue;
        for (int y = 2 * x; y <= c; y += x) {
            if (total[y].size()) calc[x] ^= calc[y];
        }
    }
    vector<int> ans;
    vector<vector<int>> sz;
    vector<vector<vector<int>>> v;
    for (int x = 1; x <= c; x++) {
        if (total[x].empty()) continue;
        gauss(calc[x], total[x], ans, sz, v);
    }
    vector<bitset<40000>> bag(sz.size() + 1);
    bag[0][0] = 1;
    for (int i = 1; i <= (int)sz.size(); i++) {
        for (auto &x : sz[i - 1]) {
            bag[i] |= (bag[i - 1] << x);
        }
    }
    int now = n - ans.size();
    for (int i = (int)sz.size(); i >= 1; i--) {
        for (int j = 0; j < (int)sz[i - 1].size(); j++) {
            int x = sz[i - 1][j];
            if (now - x >= 0 && bag[i - 1][now - x]) {
                now -= x;
                for (auto &y : v[i - 1][j]) ans.pb(y);
                break;
            }
        }
    }
    sort(all(ans));
    for (auto &c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    precalc();
    int c, n;
    cin >> c >> n;
    solve(n, c);
    return 0;
}
```
 **Who did what?*** Problem A
	+ Idea: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
	+ Polygon: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
	+ Editorial: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
* Problem B
	+ Idea: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
	+ Polygon: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
	+ Editorial: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
* Problem C
	+ Idea: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
	+ Polygon: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
	+ Editorial: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
* Problem D
	+ Idea: [Artyom123](https://codeforces.com/profile/Artyom123 "International Master Artyom123")
	+ Polygon: [Artyom123](https://codeforces.com/profile/Artyom123 "International Master Artyom123")
	+ Editorial: [Artyom123](https://codeforces.com/profile/Artyom123 "International Master Artyom123")
* Problem E
	+ Idea: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
	+ Polygon: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
	+ Editorial: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
* Problem F
	+ Idea: [Artyom123](https://codeforces.com/profile/Artyom123 "International Master Artyom123")
	+ Polygon: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
	+ Editorial: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando") + [Artyom123](https://codeforces.com/profile/Artyom123 "International Master Artyom123")
* Problem G
	+ Idea: [Artyom123](https://codeforces.com/profile/Artyom123 "International Master Artyom123") + [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27")
	+ Polygon: tests: [Artyom123](https://codeforces.com/profile/Artyom123 "International Master Artyom123") + other: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
	+ Editorial: [Artyom123](https://codeforces.com/profile/Artyom123 "International Master Artyom123")
* Problem H
	+ Idea: [Artyom123](https://codeforces.com/profile/Artyom123 "International Master Artyom123") + [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27")
	+ Polygon: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando") + [Artyom123](https://codeforces.com/profile/Artyom123 "International Master Artyom123")
	+ Editorial: [Artyom123](https://codeforces.com/profile/Artyom123 "International Master Artyom123")
* English translation: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
* Edits on Polygon, common enhancements: [KAN](https://codeforces.com/profile/KAN "Legendary Grandmaster KAN"), [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27"), [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")
