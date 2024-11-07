# Tutorial_1_(en)

We hope you liked the problems.

Task A was invented and prepared by [induk_v_tsiane](https://codeforces.com/profile/induk_v_tsiane "Master induk_v_tsiane").

Task B was invented by [induk_v_tsiane](https://codeforces.com/profile/induk_v_tsiane "Master induk_v_tsiane"), and prepared by [i_love_penguins](https://codeforces.com/profile/i_love_penguins "Specialist i_love_penguins").

Task C was invented and prepared by [induk_v_tsiane](https://codeforces.com/profile/induk_v_tsiane "Master induk_v_tsiane").

Task D was invented by [i_love_penguins](https://codeforces.com/profile/i_love_penguins "Specialist i_love_penguins") and [efimovpaul](https://codeforces.com/profile/efimovpaul "Candidate Master efimovpaul"), and prepared by [i_love_penguins](https://codeforces.com/profile/i_love_penguins "Specialist i_love_penguins").

Task E was invented by [induk_v_tsiane](https://codeforces.com/profile/induk_v_tsiane "Master induk_v_tsiane") and [kristevalex](https://codeforces.com/profile/kristevalex "Grandmaster kristevalex"), and prepared by [induk_v_tsiane](https://codeforces.com/profile/induk_v_tsiane "Master induk_v_tsiane").

Task F was invented by [induk_v_tsiane](https://codeforces.com/profile/induk_v_tsiane "Master induk_v_tsiane") and [Artyom123](https://codeforces.com/profile/Artyom123 "Grandmaster Artyom123"), and prepared by [induk_v_tsiane](https://codeforces.com/profile/induk_v_tsiane "Master induk_v_tsiane").

[1859A - United We Stand](../problems/A._United_We_Stand.md "Codeforces Round 892 (Div. 2)")

 **Hints****Hint 1**What does it mean that A divides B?

 **Tutorial**First, if all numbers are equal, then there is no answer (since a is divisible by a, if both arrays are non-empty, then c1 is a divisor of b1).

Second, if a is divisible by b and they are both natural numbers, then the following equality holds: b≤a (by definition, if a is divisible by b, then a can be represented as k˙b, where k is a natural number).

Now we can place all instances of the smallest number into b, and all other numbers into c. It can be seen that such a construction always gives a valid answer.

 **Author's code**
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
void solve() {
	int n = 0; cin >> n; 
	vector<int> inp; inp.assign(n, 0);
	for (auto& x : inp) cin >> x;
	sort(inp.begin(), inp.end());
	if (inp.back() == inp[0]) {
		cout << "-1n";
		return;
	}
	else {
		int it = 0;
		while (inp[it] == inp[0]) it++;
		cout << it << " " << n - it << "n";
		for (int j = 0; j < it; ++j) cout << inp[j] << " ";
		for (int j = it; j < n; ++j) cout << inp[j] << " ";
	}
}
 
int main() {
	int t = 0; cin >> t;
	while (t--) solve();
	return 0;
}
```
[1859B - Olya and Game with Arrays](../problems/B._Olya_and_Game_with_Arrays.md "Codeforces Round 892 (Div. 2)")

 **Hints****Hint 1**Do all numbers in a single array really matter?

 **Hint 2**If only the first minimum and the second minimum matter, what is the only way to increase a single array's beauty?

 **Hint 3**What can we say about the array which will have the smallest number in the end?

 **Tutorial**To increase the answer for each array separately, it is necessary to move the minimum to another array. Then, notice that it is optimal to move all the minimums to one array. Let's figure out which array. After moving the minimum from an array, the second minimum in the original array becomes the new minimum. Then, it is easy to notice that it is optimal to move all the minimums to the array with the smallest second minimum. After all the movements, we will have one array where the minimum element is the smallest number among all the arrays, and n−1 arrays where the minimum element is the second minimum in the original array.

Therefore, the answer to the problem will be M+K−S, where M is the minimum element among all the arrays, K is the sum of all the second minimums, and S is the smallest second minimum.

 **Author's code**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
 
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
const int INF = 1e9 + 7;
 
void solve() {
    int n;
    cin >> n;
 
    int minn = INF;
    vector<int> min2;
    for (int i = 0 ; i < n ; i++) {
        int m;
        cin >> m;
        vector<int> v(m);
        for (auto &el : v) cin >> el;
 
        int minel = *min_element(all(v));
        minn = min(minn, minel);
        v.erase(find(all(v), minel));
        min2.push_back(*min_element(all(v)));
    }
    cout << minn + (ll) accumulate(all(min2), 0ll) - *min_element(all(min2)) << "n";
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
 
    int t = 1;
    cin >> t;
    while (t--)
        solve();
 
    return 0;
}

```
[1859C - Another Permutation Problem](../problems/C._Another_Permutation_Problem.md "Codeforces Round 892 (Div. 2)")

 **Hints****Hint 1**What if we fix the maximum element in the resulting array?

 **Hint 2**Try using greedy.

 **Hint 3**Optimize the log factor away by noticing a certain fact.

 **Tutorial**Let's fix the maximum element in an array — let it be M. Now, let's iterate from n to 1. Let the current chosen number be i. I claim that if we maintain the remaining available numbers to multiply by, then it is optimal to take the maximum such number x that x∗i≤M. 

Proof: let's say that this is not correct. Then, let's say that we pair i with another number x1, and x gets paired with some other number i1. Then, i1<i, because it was chosen later, and x1<x (otherwise i∗x1>M). Now let's swap x with x1. The sum is increased by i∗x−i∗x1−i1∗x+i1∗x1=(i−i1)(x−x1)>0, and all of the numbers are less or equal to M.

Now the task can be solved in O(N3logN) by simply iterating on the maximum from N2 to 1, while maintaining the remaining numbers with a set. In order to squeeze it in the TL, you can only consider such maximums that they can be represented as i∗j,1≤i,j≤n.

In order to optimize it to O(N3), let's notice that for each number x, it can be paired with any number from 1 to Mx. Now just maintain a stack of all available elements at the current moment, add all numbers that possible, and pop the maximum number for all i from 1 to N.

 **Author's code**
```cpp
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <vector>
using namespace std;
void solve() {
	int N = 0; cin >> N;
	int ans = 0;
	vector<int> pr;
	pr.assign(N * N, -1);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			pr[i * j - 1] = 1;
		}
	}
	for (int mx = N * N; mx >= 1; --mx) {
		if (pr[mx - 1] == -1) continue;
		vector<vector<int>> a;
		int curans = -mx;
		bool br = false;
		a.assign(N, vector<int>());
		for (int j = N; j >= 1; --j) {
			int num = min(mx / j, N);
			if (num < 1) {
				br = true;
				break;
			}
			a[num - 1].push_back(j);
		}
		if (br) break;
		stack<int> s;
		for (int i = 0; i < N; ++i) {
			s.push(i + 1);
			bool brk = false;
			for (auto x : a[i]) {
				if (s.empty()) {
					brk = true; break;
				}
				curans += s.top() * x;
				s.pop();
			}
			if (brk) break;
		}
		ans = max(ans, curans);
	}
	cout << ans << "n";
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 0; cin >> t;
	while (t--) solve();
	return 0;
}

```
[1859D - Andrey and Escape from Capygrad](../problems/D._Andrey_and_Escape_from_Capygrad.md "Codeforces Round 892 (Div. 2)")

 **Hints****Hint 1**What if we use greedy a bit?

 **Hint 2**Where it is always beneficial to teleport?

 **Hint 3**Use scanline

 **Tutorial**Statement: It is always beneficial to teleport to point bi.

Proof: Let's assume that we were able to teleport from point X to the right of bi, but not from bi. Then we used some segment A that covers point X, but does not cover point b, and ends to the right of b. This is a contradiction.

Let ansi be the maximum coordinate we can reach while being on segment i, and let pj be the answer to the j-th query. Then we notice that the answer to query pj=max(xj,maxni=1ansi|li≤xj≤ri).

We will use the scanline method from the end. Events: li, bi, ri, xj.

We notice that events of type ri are not important to us when scanning from the end (according to statement number 1). It is important for us that we process events of type bi first, then events of type xj, and then events of type li (closing the segment in the scanline).

We will go through the events of the scanline, processing them in the order of bi, then events of type xj, and then events of type li.

We assume that there is a data structure that allows us to add elements, remove elements, and quickly output the maximum.

 * For each event of type bi, update the value of ansi — take the maximum value of ans of all open segments from the structure.
* For each event of type xj, update the value of pj — take the maximum value of ans of all open segments from the structure, as well as xj.
* For each event of type li, remove ansi from the structure.

We notice that to solve this problem, we can use the std::multiset} container, which automatically sorts elements in ascending order. We can store in multiset ansi of all open segments. And then, when processing events, extract the maximum from multiset, all operations are performed in O(logn). This allows us to solve the problem in O((n+q)logn) time and O(n) memory.

 **Author's code**
```cpp
#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <unordered_map>
#include <bitset>
#include <random>
#include <unordered_set>
#include <chrono>
 
using namespace std;
 
#define all(a) a.begin(), a.end()
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> ans(n);
    vector<tuple<int, int, int>> events;
    for (int i = 0 ; i < n ; i++) {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        ans[i] = b;
        events.emplace_back(b, 1, i);
        events.emplace_back(l, -1, i);
    }
    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0 ; i < q ; i++) {
        int x;
        cin >> x;
        queries[i] = x;
        events.emplace_back(x, 0, i);
    }
 
    sort(all(events));
    reverse(all(events));
    multiset<int> s;
    for (auto [x, type, ind] : events) {
        if (type == 1) {
            if (!s.empty()) {
                ans[ind] = *s.rbegin();
            }
            s.insert(ans[ind]);
        } else if (type == 0) {
            if (!s.empty()) {
                queries[ind] = max(queries[ind], *s.rbegin());
            }
        } else {
            s.extract(ans[ind]);
        }
    }
 
    for (auto el : queries)
        cout << el << " ";
    cout << "n";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    cin >> t;
    while (t--)
        solve();
 
    return 0;
}

```
[1859E - Maximum Monogonosity](../problems/E._Maximum_Monogonosity.md "Codeforces Round 892 (Div. 2)")

 **Hints****Hint 1**Maybe we can relax some conditions?

 **Hint 2**Do we really need to always correctly calculate all sums?

 **Hint 3**Optimize the obvious dp.

 **Tutorial**Let's call the value of a segment [l;r] f(l,r)=abs(al−br)+abs(ar−bl).

Let's write dp[n1][k1] — maximum value of segments of total length k1 that end before n1.

The obvious way to recalc is the following:

dp[n1][k1]=max(dp[n1−1][k1],dp[n1−l][k1−l]+f(n1−l+1,n1),1≤l≤k1).

This works in O(NK2) and is too slow.

Now let's consider the following: instead of getting the absolute value of segment [l;r], we consider the maximum of the following four combinations: bl−ar+br−al, bl−ar−br+al, −bl+ar+br−al, −bl+ar−br+al. We can see that this always gives us the correct answer to the absolute value, since we check all of the possibilities.

Now we can look at out dp states as a table, and notice that we recalc over the diagonal (we recalc over all states that have the same value of n1 — k1). 

Now, for each "diagonal", we maintain four maximum combinations: dp[n1][k1]+bk1+ak1,dp[n1][k1]−bk1+ak1,dp[n1][k1]+bk1−ak1,dp[n1][k1]−bk1−ak1, and when we want to recalc state dp[n2][k2], we just consider all of the four possibilities.

 **Author's code**
```cpp
#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1e18;
#define int long long
 
void solve() {
	int N = 0, K = 0; cin >> N >> K;
	vector<int> a;
	vector<int> b;
	a.assign(N, 0);
	b.assign(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> b[i];
	}
	vector<long long> mx1; // max of (b_l + a_l) + corresponding dp
	vector<long long> mx2; // max of (b_l - a_l) + corresponding dp
	vector<long long> mn1; // min of (b_l + a_l) + corresponding dp
	vector<long long> mn2; // min of (b_l - a_l) + corresponding dp
	vector<vector<long long>> dp;
	mx1.assign(N + 1, -INF); mx2.assign(N + 1, -INF);
	mn1.assign(N + 1, INF); mn2.assign(N + 1, INF);
	dp.assign(N + 1, vector<long long>(K + 1, 0));
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= min(i, K); ++j) {
			if (i != 0) dp[i][j] = dp[i - 1][j];
			int diag_val = i - j;
			if (i != 0) {
				dp[i][j] = max(dp[i][j], b[i - 1] + a[i - 1] - mn1[diag_val]);
				dp[i][j] = max(dp[i][j], -b[i - 1] - a[i - 1] + mx1[diag_val]);
				dp[i][j] = max(dp[i][j], a[i - 1] - b[i - 1] - mn2[diag_val]);
				dp[i][j] = max(dp[i][j], b[i - 1] - a[i - 1] + mx2[diag_val]);
			}
			if (i != N) {
				mn1[diag_val] = min(mn1[diag_val], b[i] + a[i] - dp[i][j]);
				mx1[diag_val] = max(mx1[diag_val], b[i] + a[i] + dp[i][j]);
				mn2[diag_val] = min(mn2[diag_val], b[i] - a[i] - dp[i][j]);
				mx2[diag_val] = max(mx2[diag_val], b[i] - a[i] + dp[i][j]);
			}
		}
	}
	cout << dp[N][K] << "n";
}
 
 
signed main() {
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
}
 

```
[1859F - Teleportation in Byteland](../problems/F._Teleportation_in_Byteland.md "Codeforces Round 892 (Div. 2)")

 **Hints****Hint 1**How many times do we really need to take driving courses?

 **Hint 2**Can you think how would an optimal answer path look like?

 **Hint 3**Can you recalculate the distances required to get to a city from every vertex?

 **Tutorial**Root the tree arbitrarily.

First, we can notice that there is no need to take driving courses more than logmaxW times.

Now, let's iterate for the number of driving courses we take from 0 to 20 (220>1000000). For each number we solve separately.

Let us fix the number of taken as q. Now the path looks like the following: we go over the simple path, then we veer off to take courses in some town, then we come back to the path and finish it. Let's call d[x] the minimum distance required to get from x to a town which offers driving courses and then come back to the same town. We can recalculate d[x] with multi-source BFS.

Now, let's look at the vertex v1 on the path, from which we will start going off the path. Then, the cost of the path is d[v1] + distance from a to v1 on the original edges (with c=1) + distance from v1 to b on the modified edges(with c=2q).

Now let's look at some cases, let LCA be the LCA of a and b, h1[x] — the sum of all original edges from the root downwards to x, h2[x] — the sum of all modified edges from the root downwards to x.

If v1 is between LCA and a, the cost is h1[a]−h1[v1]+d1[v1]−h2[LCA]+h2[v1]+h2[b]−h2[LCA]. If v1 is between LCA and a, the cost is h1[a]−h1[LCA]+h1[v1]−h1[LCA]+d1[v1]+h2[b]−h2[v1]. Now we simply need to consider the terms which depend only on v1, and then we need to take the maximum value on a path. For that we can use binary lifting, and for LCA as well.

 **Author's code**
```cpp
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <deque>
#include <string>
#include <ctime>
#include <bitset>
#include <queue>
#include <cassert>
#include<unordered_set>
#include<unordered_map>
#include<string.h>
#include <random>
#include <chrono>
#include <math.h>
using namespace std;
#define pi pair<int, int>
#define ll long long
#define pll pair<ll, ll>
const ll INF = 1e18;
vector<vector<pi>> g;
vector<int> is_special;
vector<vector<int>> bin_lift;
vector<vector<pi>> new_g;
vector<int> tin;
vector<int> tout;
vector<ll> ans;
vector<pi> req;
vector<ll> h_orig;
vector<ll> h_new;
vector<ll> d;
vector<bool> used_bfs;
vector<vector<pll>> bin_lift_2;
vector<int> lc;
vector<int> top_order;
vector<pair<int, int>> pr;
int TIMER = 0;
void DFS(int v, int p) {
    top_order.push_back(v);
    tin[v] = TIMER++;
    bin_lift[v][0] = p;
    for (int i = 1; i < 17; ++i) {
        if (bin_lift[v][i - 1] == -1) break;
        bin_lift[v][i] = bin_lift[bin_lift[v][i - 1]][i - 1];
    }
    for (auto& x : g[v]) {
        if (x.first == p) {
            pr.push_back(x);
            continue;
        }
    }
    for (auto& x : g[v]) {
        if (x.first == p) continue;
        h_orig[x.first] = h_orig[v] + x.second;
        DFS(x.first, v);
    }
    tout[v] = TIMER;
}
void BFS(int N) {
    priority_queue<pll> q;
    for (int i = 0; i < N; ++i) {
        if (is_special[i]) {
            q.push({ -0, i });
            d[i] = 0;
        }
    }
    while (!q.empty()) {
        int v = q.top().second; q.pop();
        if (used_bfs[v]) continue;
        used_bfs[v] = true;
        for (auto& x : new_g[v]) {
            if (d[x.first] > d[v] + x.second) {
                d[x.first] = d[v] + x.second;
                q.push({ -d[x.first], x.first });
            }
        }
    }
}
inline bool isIn(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int gLCA(int a, int b) {
    if (isIn(a, b)) return a;
    if (isIn(b, a)) return b;
    int cB = b;
    for (int i = 16; i >= 0; --i) {
        if (bin_lift[cB][i] == -1) continue;
        if (!isIn(bin_lift[cB][i], a)) cB = bin_lift[cB][i];
    }
    return bin_lift[cB][0];
}
ll g1(int a, int LCA) {
    ll mn = d[a] + h_new[a] - h_orig[a];
    int cK = a;
    for (int i = 16; i >= 0; --i) {
        if (bin_lift[cK][i] == -1) continue;
        if (!isIn(LCA, bin_lift[cK][i])) continue;
        mn = min(mn, bin_lift_2[cK][i].first);
        cK = bin_lift[cK][i];
    }
    return mn;
}
ll g2(int a, int LCA) {
    ll mn = d[a] + h_orig[a] - h_new[a];
    int cK = a;
    for (int i = 16; i >= 0; --i) {
        if (bin_lift[cK][i] == -1) continue;
        if (!isIn(LCA, bin_lift[cK][i])) continue;
        mn = min(mn, bin_lift_2[cK][i].second);
        cK = bin_lift[cK][i];
    }
    return mn;
}
void solve() {
    top_order.clear();
    pr.clear();
    int N = 0, T = 0; cin >> N >> T;
    g.assign(N, vector<pi>());
    for (int j = 0; j < N - 1; ++j) {
        int u = 0, v = 0, w = 0; cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({ v, w }); g[v].push_back({ u, w });
    }
    is_special.assign(N, 0);
    string s = ""; cin >> s;
    for (int i = 0; i < N; ++i) is_special[i] = s[i] - '0';
    tin.assign(N, 0); tout.assign(N, 0);
    bin_lift.assign(N, vector<int>(17, -1));
    TIMER = 0;
    h_orig.assign(N, 0);
    DFS(0, -1);
    int Q = 0; cin >> Q;
    ans.assign(Q, INF);
    req.clear();
    lc.clear();
    for (int j = 0; j < Q; ++j) {
        int u = 0, v = 0; cin >> u >> v;
        u--; v--;
        req.push_back({ u, v });
        lc.push_back(gLCA(u, v));
    }
    bin_lift_2.assign(N, vector<pll>(17, pll(INF, INF)));
    h_new.assign(N, 0);
    for (ll level = 1; level <= 20; ++level) {
        const int w = (1ll << level);
        new_g.assign(N, vector<pi>());
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                new_g[i].push_back({ g[i][j].first, g[i][j].second + ((g[i][j].second + w - 1) / w) });
            }
        }
        d.assign(N, INF);
        used_bfs.assign(N, false);
        BFS(N);
        h_new[0] = 0;
        for (int n = 1; n < N; ++n) {
            h_new[top_order[n]] = h_new[pr[n - 1].first] + (pr[n - 1].second + w - 1) / w;
            int p = pr[n - 1].first;
            int v = top_order[n];
            bin_lift_2[v][0] = { d[p] + h_new[p] - h_orig[p], d[p] + h_orig[p] - h_new[p] };
            for (int i = 1; i < 17; ++i) {
                if (bin_lift[v][i] == -1) break;
                bin_lift_2[v][i].first = min(bin_lift_2[v][i - 1].first, bin_lift_2[bin_lift[v][i - 1]][i - 1].first);
                bin_lift_2[v][i].second = min(bin_lift_2[v][i - 1].second, bin_lift_2[bin_lift[v][i - 1]][i - 1].second);
            }
        }
        for (int j = 0; j < Q; ++j) {
            int a1 = req[j].first; int b1 = req[j].second;
            int LCA = lc[j];
            ans[j] = min(ans[j], g1(a1, LCA) + h_orig[a1] - h_new[LCA] + h_new[b1] - h_new[LCA] + level * T);
            ans[j] = min(ans[j], g2(b1, LCA) + h_orig[a1] - h_orig[LCA] - h_orig[LCA] + h_new[b1] + level * T);
        }
    }
    for (int i = 0; i < Q; ++i) {
        ans[i] = min(ans[i], h_orig[req[i].first] + h_orig[req[i].second] - 2 * h_orig[lc[i]]);
        cout << ans[i] << "n";
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

```
Some notes/challenges:

 * We know about the O(N2)O(N2) solution in C, but we did not find a good suitable proof for it (and, using the method, we could achieve faster solutions).
* You can solve DD without the constraint that the segments are contained, but that is harder. It is solvable in (ONlogN)(ONlogN).
* Thank you all for participating! If you have any complaints/suggestions/advice for future rounds, feel free to share in the comments!
