# Tutorial_(en)

We know about FST and we are really, really sorry about it. Even though we still hope that you liked the problems.

 **A: Digit Minimization**[1684A - Digit Minimization](../problems/A._Digit_Minimization.md)

 **Editorial**
### [1684A - Digit Minimization](../problems/A._Digit_Minimization.md "Codeforces Round 792 (Div. 1 + Div. 2)")

Let k be the length of n. Let ni be the i-th digit of n (1-indexation from the left).

* k=1The game ends immediately so the answer is n itself.
* k=2Alice should make the first move and she has to swap n1 and n2. After that Bob removes n1 and in the end there is only n2.
* k≥3Alice can make swaps in such way that when there are only two digits left the second digit will be the maximal digit of n. Then she will make a swap and the maximal digit will be on the first position. The other one will be removed by Bob. This way she can always get the maximal digit of n in the end of the game.
 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        string n;
        cin >> n;
        if (n.size() == 2) {
            cout << n[1] << 'n';
        } else {
            cout << *min_element(n.begin(), n.end()) << 'n';
        }
    }
    return 0;
}
```
 **B: Z mod X = C**[1684B - Z mod X = C](../problems/B._Z_mod_X_=_C.md)

 **Editorial**
### [1684B - Z mod X = C](../problems/B._Z_mod_X_=_C.md "Codeforces Round 792 (Div. 1 + Div. 2)")

In this problem it is enough to find a contstruction that works for all $a < b < c$. For example: 

 $x = a + b + c$$y = b + c$

$z = c$ 

In this case 

$x \bmod y = (a + b + c) \bmod (b + c) = a$ since $a < b < b + c$

$y \bmod z = (b + c) \bmod c = b$ since $b < c$

$z \bmod x = c \bmod (a + b + c) = c$ since $c < (a + b + c)$.

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c << " " << b + c << " " << c << "n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```
 **C: Column Swapping**[1684C - Column Swapping](../problems/C._Column_Swapping.md)

 **Editorial**
### [1684C - Column Swapping](../problems/C._Column_Swapping.md "Codeforces Round 792 (Div. 1 + Div. 2)")

At first, let's check wether the given table is good. If it is not then there is a row that has elements that should be replaced.

Let's say that this row is $a$ and $b$ is the sorted row $a$. Then let's find the set of positions $i$ that $a_i \neq b_i$. If there are at least $3$ such positions then the answer is $-1$ because by making a swap we remove at most $2$ such bad positions. If there are no more than $2$ such positions then let's swap the corresponding columns and check whether each row is sorted. If the table is good we found the answer. If it is not then the answer is $-1$ because we can not sort $a$ and get a good table after that.

 **Implementation**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<int> bad;
    for (int i = 0; i < n && bad.empty(); i++) {
        vector<int> b = a[i];
        sort(b.begin(), b.end());
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[j]) bad.push_back(j);
        }
    }
    if ((int)bad.size() == 0) {
    	cout << 1 << " " << 1 << "n";
    	return;
    }
    if ((int)bad.size() > 2) {
    	cout << -1 << "n";
    	return;
    }
    for (int i = 0; i < n; i++) {
        swap(a[i][bad[0]], a[i][bad[1]]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] < a[i][j - 1]) {
            	cout << -1 << "n";
            	return;
           	}
        }
    }
    cout << bad[0] + 1 << " " << bad[1] + 1 << "n";
    return;
}

int main() {
	#ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		solve(a);
	}
	return 0;
}
```
 **D: Traps**[1684D - Traps](../problems/D._Traps.md)

 **Editorial**
### [1684D - Traps](../problems/D._Traps.md "Codeforces Round 792 (Div. 1 + Div. 2)")

Firstly, let's notice that it is always better to use all $k$ jumps. If we jumped over less than $k$ traps then we can jump over the last trap and the total damage will be less.

Secondly, let's say that we immediately get $n - i$ damage if we jump over $i$-th trap. This way the first trap that we jump over will cause $k - 1$ damage more than it should (because of $k - 1$ traps that we jump over next), the second will cause $k - 2$ damage more, ..., the last one will cause $0$ damage more. So the total damage only increases by $\frac{k(k - 1)}{2}$ which does not depend on the traps that we choose. That's why the traps that we have to jump over in this problem are the same.

Now let's consider an array $b: b_i = a_i - (n - i)$. This array denotes the amount of damage we dodge if we jump over $i$-th trap (dodge $a_i$ because we don't take the trap's damage but get $n - i$ because of the immediate damage we take). Here a simple greedy works: let's just chose $k$ maximal values of this array, these will be the traps that we have to jump over so the total damage that we dodge is maximized. These traps will be the answer to the original problem.

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
        a[i] += i + 1;
    }
    sort(all(a));
    reverse(all(a));
    for (int i = 0; i < k; i++) ans -= a[i];
    for (int i = 0; i < k; i++) {
        ans += n;
        ans -= i;
    }
    cout << ans << "n";
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```
 **E: MEX vs DIFF**[1684E - MEX vs DIFF](../problems/E._MEX_vs_DIFF.md)

 **Editorial**
### [1684E - MEX vs DIFF](../problems/E._MEX_vs_DIFF.md "Codeforces Round 792 (Div. 1 + Div. 2)")

Let's consider all possible $\operatorname{MEX}$ after all operations. It is from $0$ to $n$ and we can check them all in the increasing order. Now let's fix some $\operatorname{MEX} = m$. There should be all numbers from $0$ to $m$ in the array, so there are some "holes" in the array that should be covered. The hole is an integer from $0$ to $m$ which is not present in the array. If there is at least one hole in the end it is not possible to obtain $\operatorname{MEX} = m$.

Now let's see how we should cover the holes. We will do it greedily. Firstly, we will need to use integers that are greater than $m$. It is easy to see that they are always not worse to use than the integers which are already from $0$ to $m$. Moreover, we should start from those integers that occur less times in the array. It is because each time we cover a hole we increase $\operatorname{MEX}$ at least by one (we cover the holes in increasing order) and the value of $\operatorname{DIFF}$ increases at most by $1$ and it does not increase when we change the last element of the same value.

After that if we used all integers that are greater than $m$ we should use those integers that are from $0$ to $m$ but only those that occur more than once. By doing these operations we increase $\operatorname{MEX}$ at least by $1$ and increase $\operatorname{DIFF}$ exactly by $1$ (because we cover a hole).

Now let's notice that when considering each $\operatorname{MEX}$ value in the increasing order we can simply maintain some information about the current state of the array: a set that helps us find the elements greater than $m$ which occur less times in the array, the amount of not covered holes, the number of "bonus" elements from $0$ to $m$ (the number of integers from $0$ to $m$ minus $\operatorname{DIFF}$ from those elements that are from $0$ to $m$) and it is easy to see how it is changed when we increase $\operatorname{MEX}$. So in total we can calculate the answer for each $\operatorname{MEX}$ for all $\operatorname{MEX}$ from $0$ to $n$.

 **Implementation**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld double
#define pld pair<ld, ld>
#define pll pair<ll, ll>

const int INF = 1e9 + 1;
const ll INFLL = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    map<int, int> cnt;
    for (auto &c : a) cnt[c]++;
    set<pii> s1, s2;
    int sum1 = 0;
    for (auto &c : cnt) s2.insert(mp(c.se, c.fi));
    int ans = INF;
    int skip = 0;
    for (int x = 0; x <= n; x++) {
        if (s1.find(mp(cnt[x - 1], x - 1)) != s1.end()) {
            sum1 -= cnt[x - 1];
            s1.erase(mp(cnt[x - 1], x - 1));
        }
        if (s2.find(mp(cnt[x - 1], x - 1)) != s2.end()) {
            s2.erase(mp(cnt[x - 1], x - 1));
        }
        while (s2.size() && sum1 + s2.begin()->fi <= k) {
            s1.insert(*s2.begin());
            sum1 += s2.begin()->fi;
            s2.erase(s2.begin());
        }
        if (k < skip) break;
        int now = x + s2.size();
        if (x == 0) {
            now = max(1, (int)s2.size());
        }
        ans = min(ans, now - x);
        if (cnt[x] == 0) skip++;
    }
    cout << ans << "n";
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

```
 **F: Diverse Segments**[1684F - Diverse Segments](../problems/F._Diverse_Segments.md)

 **Editorial**
### [1684F - Diverse Segments](../problems/F._Diverse_Segments.md "Codeforces Round 792 (Div. 1 + Div. 2)")

Let's say the answer is $[L, R]$. Let's consider all given segments. There should be no two equal elements that are in the same given segment and are not in $[L, R]$, i.e. at least one of them should be in the answer. Let's find such segment of minimal length for $L = 1$. To do that let's for each $r$ find such minimal $l$ that on segment $[l, r]$ all elements are distinct. Let's say that $l = f(r)$. This could be done using two pointers, maintaining current set of elements and checking whether the considered element is not in the set. Let's say we are given a segment $[l_j, r_j]$. If $f(r_j) \le l_j$ then this segment is already fine. Else for $L = 1$ this condition holds $R \ge f(r_j) - 1$. Minimal $R$ that meets all the inequalitites will be the answer.

Now let's find out how to find $R$ while increasing $L$ by $1$. If we increase $L$ then $R$ can not decrease. Also if $[L + 1, R]$ can not be the answer then in some of given segments there are two equal elements $a_L$ and $a_j$. If $j < L$ then the left endpoint can not be greater than $L$. Else $j > R$. Then we have to make $R = j$ and this $j$ should be minimal. This $j$ could be found, for example, by binary search in $cnt$ array. To check whether two elements are in the same segments it is possible to use a segment tree or a Fenwick tree. It is possible to store for each $i$ such maximal $r_j$ that there is a given segment $[l_j, r_j]$ and $l_j \le i$.

The final answer will be the minimal length of $[L, R]$ for all $L$.

 **Implementation**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld double
#define pld pair<ld, ld>
#define pll pair<ll, ll>

const int INF = 1e9 + 1;
const ll INFLL = 1e18;

vector<int> f;

void incr(int x, int d) {
    for (; x < (int)f.size(); x |= (x + 1)) f[x] = max(f[x], d);
}

int get(int x) {
    int ans = -1;
    for (; x >= 0; x = (x & (x + 1)) - 1) ans = max(ans, f[x]);
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    map<int, vector<int>> gist;
    for (int i = 0; i < n; i++) gist[a[i]].pb(i);
    vector<pii> seg(m);
    f.assign(n, -1);
    for (auto &c : seg) {
        cin >> c.fi >> c.se; c.fi--; c.se--;
        incr(c.fi, c.se);
    }
    vector<int> mnl(n);
    set<int> s;
    int l = n;
    for (int r = n - 1; r >= 0; r--) {
        while (l - 1 >= 0 && !s.count(a[l - 1])) {
            l--;
            s.insert(a[l]);
        }
        mnl[r] = l;
        s.erase(a[r]);
    }
    int mnr = -1;
    for (auto &c : seg) {
        int l = c.fi, r = c.se;
        if (mnl[r] <= l) continue;
        mnr = max(mnr, mnl[r] - 1);
    }
    if (mnr == -1) {
        cout << 0 << "n";
        return;
    }
    int ans = mnr + 1;
    for (int l = 0; l + 1 < n; l++) {
        if (gist[a[l]][0] != l) {
            int id = lower_bound(all(gist[a[l]]), l) - gist[a[l]].begin() - 1;
            int pr = gist[a[l]][id];
            if (get(pr) >= l) {
                break;
            }
        }
        int id = upper_bound(all(gist[a[l]]), mnr) - gist[a[l]].begin();
        if (id != (int)gist[a[l]].size()) {
            int nxt = gist[a[l]][id];
            if (get(l) >= nxt) {
                mnr = nxt;
            }
        }
        mnr = max(mnr, l + 1);
        ans = min(ans, mnr - l);
    }
    cout << ans << "n";
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

```
 **G: Euclid Guess**[1684G - Euclid Guess](../problems/G._Euclid_Guess.md)

 **Editorial**
### [1684G - Euclid Guess](../problems/G._Euclid_Guess.md "Codeforces Round 792 (Div. 1 + Div. 2)")

Let's consider some pair $(a, b)$ and consider a sequence of remainders that is induced by this pair: $a \bmod b = x_1$, $b \bmod x_1 = x_2$, ..., $x_{p - 2} \bmod x_{p - 1} = x_p$, where $x_p = gcd(a, b)$.

If $x_i \le \frac{m}{3}$ then we can just add a pair $(3x_i, 2x_i)$ and we will get the only remainder $x_i$ so these values will not be a problem.

If $x_1 > \frac{m}{3}$ (if $i > 1$ then $x_i \le \frac{m}{3}$) then $a = b + x_1$ because if $a \ge 2b + x_1$ then $a > m$ which is impossible. $b = x_1 + x_2$ because if $b \ge 2x_1 + x_2$ then $a \ge 3x_1 + x_2 > m$. Then $a = b + x_1 = 2x_1 + x_2 \ge 2x_1 + x_p$ because $x_p < x_{p - 1} < \ldots < x_2 < x_1$.

It means that for each $x_i > \frac{m}{3}$ there should be such $x_j$ that $2x_i + x_j \le m$ and $x_j$ is a divisor of $x_i$. For such values we can consider a bipartite graph where in the left part there are only $x_i > \frac{m}{3}$ and in the right part there are only $x_j \le \frac{m}{3}$ and two integers are connected $\iff$ the integer on the right divies the left one. This graph can be built in $O(n^2)$. After that we just have to find such matching that covers each integer in the left part and add all unused integers from the right part using the method above.

 **Implementation**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld double
#define pld pair<ld, ld>
#define pll pair<ll, ll>
#define int ll

const int INF = 1e9 + 1;
const ll INFLL = 1e18;
 
vector<vector<int>> g;
vector<int> with;
vector<int> usd;
 
int dfs(int v) {
    if (usd[v]) return 0;
    usd[v] = 1;
    for (auto &to : g[v]) {
        if (with[to] == -1) {
            with[to] = v;
            return 1;
        }
    }
    for (auto &to : g[v]) {
        if (dfs(with[to])) {
            with[to] = v;
            return 1;
        }
    }
    return 0;
}

signed main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int n, A;
    cin >> n >> A;
    vector<int> a(n);
    vector<int> l, r;
    for (auto &c : a) {
        cin >> c;
        if (3 * c > A) {
            l.pb(c);
        } else {
            r.pb(c);
        }
    }
    g.resize(l.size());
    with.resize(r.size(), -1);
    for (int i = 0; i < (int)l.size(); i++) {
        for (int j = 0; j < (int)r.size(); j++) {
            if (l[i] % r[j] == 0 && 2 * l[i] + r[j] <= A) {
                g[i].pb(j);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < (int)l.size(); i++) {
        usd.assign(l.size(), 0);
        cnt += dfs(i);
    }
    if (cnt < (int)l.size()) {
        cout << -1;
        return 0;
    }
    vector<pii> ans;
    for (int j = 0; j < (int)r.size(); j++) {
        if (with[j] == -1) {
            ans.pb(3 * r[j], 2 * r[j]);
        } else {
            ans.pb(2 * l[with[j]] + r[j], l[with[j]] + r[j]);
        }
    }
    cout << ans.size() << "n";
    for (auto &c : ans) cout << c.fi << " " << c.se << "n";
    return 0;
}
```
 **H: Hard Cut**[1684H - Hard Cut](../problems/H._Hard_Cut.md)

 **Editorial**
### [1684H - Hard Cut](../problems/H._Hard_Cut.md "Codeforces Round 792 (Div. 1 + Div. 2)")

Let's say that there are $k$ ones in the given string.

We will build the answer for all $k > 0$. $k = 0$ is the only case when the answer does not exist.

$k = 1$, $k = 2$, $k = 4$ — cut into single digits.

$k = 3$ — described later.

Let's consider $k = 5$:

If all ones are in a row, then we should cut them into $1111_2 + 1_2 = 16_{10}$.

Else there will be either $101_2$ or $100_2$ and the other part of the string may be cut into single digits so the sum will be $8_{10}$.

Now let's consider $k > 5$ (here we will also consider $k = 3$):

Let's describe the function $solve(l, r, k, n)$ for cutting the susbtring from $l$ to $r$ with $k$ ones to get the sum $n$.

* Let's use the "divide and conquer" technique: we have a string with $k$ ones and we want to get the sum $n = 2^{\left \lceil \log_2(k)\right \rceil}$, and for big enough $k$ we can just cut the whole string into two substrings with almost equal number of ones, run the algorithm for them and get the sum $2^{\left \lceil \log_2(\left \lfloor k/2 \right \rfloor)\right \rceil} + 2^{\left \lceil \log_2(\left \lceil k/2 \right \rceil)\right \rceil} = 2^{\left \lceil \log_2(k)\right \rceil} = n$. Now let's show how to make such cut for all strings that have from $6$ to $11$ ones and after that for all $k \ge 12$ we will be able to run the method decribed above.
* $k = n$Just cut into single digits.
* $k < n \le \left \lfloor \frac{3k}{2} \right \rfloor$Let's consider the first two ones. If they are consequent then we will cut them into a single substring. It costs us only two ones but it increases the sum by $3$. If these two ones are not consequent then we will cut out the segments $10_2$ and $1_2$. This way we spend two ones again and the sum increases by $3$ as well. Also it is always possible to cut off a single digit so it is easy to see that we can get any sum $n$ from $k$ to $\left \lfloor \frac{3k}{2} \right \rfloor$. This way we got the answer for $k = 6, 7, 8, 11$. Now we only need to show how to make the cut for $k = 9, 10$.
* $k = 9$Let's consider a substring of length $3$ that starts in the leftmost one, there are $4$ possible cases:


	+ $t = 100$, then we need to use $k' = 8$ ones to get the sum $n' = 16_{10} - 100_2 = 12$, which we know how to do.
	+ $t = 101$, then we need to use $k' = 7$ ones to get the sum $n' = 11$, we will show it in the end.
	+ $t = 110$, then we need to use $k'= 7$ ones to get the sum $n' = 10$, which we know how to do.
	+ $t = 111$, then we need to use $k' = 6$ ones to get the sum $n' = 9$, which we know how to do.
* $k = 10$To do that let's cut a substring with $k_1 = 4$ ones from the left and get the sum $n_1 = 8$ and a remaining substring with $k_2 = 6$ ones and get the sum $n_2$. We already know how to get the second sum so now there is only $k_1 = 4$ and $n_1 = 8$ left.
* Let's consider the last two cases for full solution:$k = 4,\, n = 8$:

Let's do the same thing as we did for $k = 9$, cut off a substring of length $3$ that starts from the leftmost one. Then we have two substrings and for both of them we know how to cut them properly.

$k = 7,\, n = 11$:

Let's cut off the first four ones and use the previous technique we will get the sum $8$. The remaining three ones we will use to get the sum $3$.

This shows how to cut the string for any $k > 0$.

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int g[MAXN + 1];
string s;

vector<pair<int, int>> segments; // [l, r]

int get(int k, int i) { // get k-th '1' on [i, |s|)
	--i;
	while (k --> 0) i = s.find('1', i + 1);
	return i;
}

void five() {
	int first = get(1, 0), last = get(5, 0);
	int r = (int)s.size() - 1;
	if (last - first + 1 == 5) { // creating 16: ['001111', '1', '0000']
		segments.emplace_back(0, last - 1);
		segments.emplace_back(last, last);
		if (last < r) segments.emplace_back(last + 1, r);
	} else { // creating 8: cut out '101' or '100' and cut everything in single digits
		int pos = s.find("101");
		if (pos == string::npos) pos = s.find("100");
		for (int i = 0; i < pos; ++i) segments.emplace_back(i, i);
		segments.emplace_back(pos, pos + 2);
		for (int i = pos + 3; i <= r; ++i) segments.emplace_back(i, i);
	}
}

void solve(int l, int r, int k, int n) { // [l; r]
	if (k == n) { // cutting into single digits
		for (int i = l; i <= r; ++i) segments.emplace_back(i, i);

	} else if (k == 2 && n == 3) {
		int pos = get(1, l);
		if (s[pos + 1] == '1') { // ['11', '00...00']
			segments.emplace_back(l, pos + 1);
			if (pos + 2 <= r) segments.emplace_back(pos + 2, r);

		} else { // ['10', '0001', '00000']
			int newpos = get(1, pos + 1);
			segments.emplace_back(l, pos + 1);
			segments.emplace_back(pos + 2, newpos);
			if (newpos + 1 <= r) segments.emplace_back(newpos + 1, r);
		}

	} else if (3 * k / 2 >= n) { // using previous if technique
		int pos = get(2, l);
		solve(l, pos, 2, 3);
		if (k > 2) solve(pos + 1, r, k - 2, n - 3);

	} else if ((k == 4 && n == 8) || (k == 9 && n == 16)) {
		int pos = get(1, l);
		string sub = s.substr(pos, 3);
		segments.emplace_back(l, pos + 2);
		if (sub == "100") solve(pos + 3, r, k - 1, n - 4);
		if (sub == "101") solve(pos + 3, r, k - 2, n - 5);
		if (sub == "110") solve(pos + 3, r, k - 2, n - 6);
		if (sub == "111") solve(pos + 3, r, k - 3, n - 7);

	} else if ((k == 7 && n == 11) || (k == 10 && n == 16)) {
		int mid = get(4, l);
		solve(l, mid, 4, 8);
		solve(mid + 1, r, k - 4, n - 8);

	} else { // common case
		int mid = get(k / 2, l);
		solve(l, mid, k / 2, n / 2);
		solve(mid + 1, r, k - k / 2, n / 2);

	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	g[1] = 1;
	for (int i = 2; i <= MAXN; ++i) g[i] = g[(i + 1) / 2] * 2;
	int T;
	cin >> T;
	while (T --> 0) {
		cin >> s;
		int k = count(s.begin(), s.end(), '1');
		if (!k) {
			cout << -1 << 'n';
			continue;
		}
		segments.clear();
		if (k == 5) five();
		else solve(0, (int)s.size() - 1, k, g[k]);
		cout << segments.size() << 'n';
		for (auto &[l, r] : segments) {
			cout << l + 1 << ' ' << r + 1 << 'n';
		}
	}
	return 0;
}
```
